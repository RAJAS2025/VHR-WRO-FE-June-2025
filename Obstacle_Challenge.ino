// WRO FE 2025 — Obstacle Challenge
// Commented version of the team's robot code
// Purpose: navigation, wall-following, object detection (HuskyLens), and parking routines
// Keep this file on your competition branch; comments explain sensors, logic and key functions.

#include <SMotor.h>
#include <ESP32Servo.h>
#include <ZebraTOF.h>
#include <ZebraGyro.h>
#include "Wire.h"
#include "HUSKYLENS.h"

// Motor controller (supports 2 motor channels), index 1 used for forward/back
SMotor motor(1);

// General flags
bool flag = false;         // general-purpose flag (unused in many places)

// Servo for steering
Servo myservo;
int servoPin = 27;         // servo PWM pin

// Gyro (for yaw orientation) and time-of-flight sensors for distances
ZebraGyro gyro(7, 12);
ZebraTOF front(5);
ZebraTOF right(4);
ZebraTOF left(3);

// Navigation / vision variables
int target_x = 0;         // combined target offset from vision (red/green/pink)
float offsetangle = 0;    // accumulated orientation offset (used to track robot heading)

const int buttonPin = 15; // start button pin
int i = 0;                // simple loop counter / encoder counter fallback

// Control constants
float kp = 0.8;           // gyro proportional (re-tuned dynamically in code)
bool distance = true;     // whether distance-based correction is active

// Counters / state
int count = 0;            // number of detected pillars/walls passed
int side = 0;             // 1 = left side strategy, 2 = right side strategy
int target = 0;           // temporary yaw target for turns

// Distance readings (cached)
int rightdist = 0;
int leftdist = 0;
int frontdist = 0;

#define enc 17             // encoder pin
float yaw = 0;            // current yaw from gyro
int angle = 0;            // computed steering angle
unsigned long turned = -2000; // timestamp when we last performed a major turn

// wall-following variables
float lwallval = 0;
float rwallval = 0;

// Vision (HuskyLens) variables for different colored markers
float red = 0;
float green = 0;
float pink = 0;
int rx = 0, ry = 0; // red center coords
int gx = 0, gy = 0; // green center coords
int bx = 0, by = 0; // blue center coords
int ox = 0, oy = 0; // orange center coords
int px = 0, py = 0; // pink center coords

// Flags set by camera processing
bool gp = false; // green present
bool rp = false; // red present
bool bl = false; // blue present
bool ol = false; // orange present
bool pw = false; // pink present

bool wallval = true; // whether to use wall-based corrections

// Speed control
int baseSpeed = 70;    // baseline speed
int motorSpeed = 60;   // current motor speed
int curr_y = 0;        // currently used y-value from vision to reduce speed

// HuskyLens display vars (width/height/area)
int rw = 0, rh = 0, ra = 0;
int gw = 0, gh = 0, ga = 0;

HUSKYLENS huskylens;
HardwareSerial mySerial(2);
#define HUSKYLENS_RX 4
#define HUSKYLENS_TX 0

bool pillar = false; // marker: is there a pillar detected?

// -------------------- setup --------------------
void setup() {
  // Serial for debugging
  Serial.begin(115200);
  Wire.begin();

  // Ensure motors are stopped at startup
  motor.run_motor(0, 0);

  // Initialize sensors
  front.begin();
  right.begin();
  left.begin();
  gyro.begin();

  // Encoder pulse input
  pinMode(enc, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(enc), wheel_pulse, RISING);

  // Servo PWM timers (ESP32)
  ESP32PWM::allocateTimer(0);
  ESP32PWM::allocateTimer(1);
  ESP32PWM::allocateTimer(2);
  ESP32PWM::allocateTimer(3);
  myservo.setPeriodHertz(50);  // standard 50 Hz for hobby servos
  myservo.attach(servoPin, 500, 2500);

  // Power control pin (board LED / enable)
  pinMode(2, OUTPUT);
  digitalWrite(2, HIGH);

  // Start HuskyLens serial and try to connect
  mySerial.begin(9600, SERIAL_8N1, HUSKYLENS_RX, HUSKYLENS_TX);
  while (!huskylens.begin(mySerial)) {
    Serial.println(F("Begin failed!"));
    Serial.println(F("1. Recheck HUSKYLENS Protocol (should be Serial 9600)"));
    Serial.println(F("2. Recheck wiring: Blue wire to RX, Green wire to TX"));
    delay(1000);
  }

  // Wait for user to press the start button (buttonPin is read)
  int buttonState = digitalRead(buttonPin);
  while (buttonState == 1) {
    buttonState = digitalRead(buttonPin);
  }
  delay(200);

  // === initial parallel-exit logic ===
  // Read left and right distances to decide which side (left/right) strategy to use
  rightdist = constrain(right.readDistance1(), 0, 1200);
  leftdist = constrain(left.readDistance1(), 0, 1200);

  if (rightdist < leftdist) {
    // If right side is closer to a wall, choose left-turn-first strategy
    side = 1;  // left
    target = abs(offsetangle) + 75;
    gyro.update();
    yaw = gyro.getYaw();
    motor.run_motor(1, 50);
    while (yaw > (target * -1)) {
      gyro.update();
      yaw = gyro.getYaw();
      myservo.write(45); // steer left while turning
    }
    motor.stop_motor();

    camread(); // check vision after the initial turn
    delay(500);

    if (rp == true && ry > gy) {
      // Red pillar dominant — fine tune with a small gyro-based turn
      target = abs(offsetangle);
      gyro.update();
      yaw = gyro.getYaw();
      motor.run_motor(1, 55);
      while (yaw < target) {
        gyro.update();
        yaw = gyro.getYaw();
        myservo.write(132);
      }
      motor.stop_motor();
    } else {
      // No dominant red — drive forward until front distance drops below threshold
      myservo.write(95); // center servo
      frontdist = front.readDistance1();
      offsetangle -= 90; // record a big heading offset (we turned)
      while (frontdist > 350) {
        frontdist = front.readDistance1();
        gyro.update();
        yaw = gyro.getYaw();
        forward(yaw, 0, 1000, 1000); // use forward wall-following until we get close
      }
      motor.stop_motor();
      offsetangle += 90; // restore offset after approach

      // Then rotate to align with the new direction
      target = abs(offsetangle) - 10;
      gyro.update();
      yaw = gyro.getYaw();
      motor.run_motor(1, 55);
      while (yaw < target) {
        gyro.update();
        yaw = gyro.getYaw();
        myservo.write(135);
      }
      motor.stop_motor();
    }
  } else {
    // Right-side strategy (mirror of above)
    side = 2;  // right
    target = abs(offsetangle) + 50;
    gyro.update();
    yaw = gyro.getYaw();
    motor.run_motor(1, 50);
    while (yaw < target) {
      gyro.update();
      yaw = gyro.getYaw();
      myservo.write(135);
    }
    motor.stop_motor();
    myservo.write(95);
    camread();

    if (rp == true) {
      frontdist = front.readDistance1();
      offsetangle += 90;
      while (frontdist > 250) {
        frontdist = front.readDistance1();
        gyro.update();
        yaw = gyro.getYaw();
        forward(yaw, 0, 1000, 1000);
      }
      motor.stop_motor();
      offsetangle -= 90;
    } else {
      motor.run_motor(1, 60);
      delay(500);
      motor.stop_motor();
    }

    // small correction turn
    target = abs(offsetangle) + 15;
    gyro.update();
    yaw = gyro.getYaw();
    motor.run_motor(1, 60);
    while (yaw > target) {
      gyro.update();
      yaw = gyro.getYaw();
      myservo.write(55);
    }
    motor.stop_motor();
    myservo.write(95);
  }
}

// -------------------- main loop --------------------
void loop() {

  // Read vision each loop to update target_x and color flags
  camread();

  // Convert detected objects into a single x-target and speed scaling
  if (ra > ga) {
    // red dominant
    red = 0.0035 * (20 - rx) * ry;  // heuristic weight for red
    green = 0;
    curr_y = ry;
  } else if (ga > ra) {
    // green dominant
    green = 0.003 * (280 - gx) * gy; // heuristic weight for green
    red = 0;
    curr_y = gy;
  }

  // Pink pillar handling: when present we modify both pink and green weight depending on side
  if (pw) {
    distance = false; // disable distance-based corrections while handling pink
    if (side == 1) {
      if (py > gy) {
        pink = 0.004 * (270 - px) * py;
        green = 0.001 * (280 - gx) * gy;
      } else {
        pink = 0.001 * (270 - px) * py;
        green = 0.003 * (280 - gx) * gy;
      }
    } else {
      if (py > ry) {
        pink = 0.003 * (30 - px) * py;
        red = 0.001 * (20 - rx) * ry;
      } else {
        pink = 0.001 * (30 - px) * py;
        red = 0.003 * (20 - rx) * ry;
      }
    }
  } else {
    distance = true;
  }

  // If blue/ orange are dominant in certain sides clear target influence after a recent turn
  if (by > gy && by > ry && side == 1 && bx > rx && bx > gx && (millis() - turned > 4000)) {
    green = 0;
