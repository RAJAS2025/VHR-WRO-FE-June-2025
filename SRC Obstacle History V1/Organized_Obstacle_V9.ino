#include <SMotor.h>
#include <ESP32Servo.h>
#include <ZebraTOF.h>
#include <ZebraGyro.h>
#include <Pixy2I2C.h>
#include "Wire.h"
#include "HUSKYLENS.h"

SMotor motor(1);
bool flag = false;
Servo myservo;
int servoPin = 27;
ZebraGyro gyro(7, 12);
ZebraTOF front(1);
ZebraTOF right(2);
ZebraTOF left(3);

float offsetangle = 0;
const int buttonPin = 15;
int i = 0;
int count = 0;
int side = 0;
int target = 86;
int pos = 0;
#define enc 17
float yaw = 0;
int angle = 0;

// Steering constants
const int SERVO_CENTER = 90;
const int CAMERA_CENTER_X = 150;
const float SCALE = 0.1;
int turnAngle = SERVO_CENTER;

HUSKYLENS huskylens;
HardwareSerial mySerial(2);  // Use UART2 (Serial2)

#define HUSKYLENS_RX 4
#define HUSKYLENS_TX 0

void printResult(HUSKYLENSResult result) {
  if (result.command == COMMAND_RETURN_BLOCK) {
    Serial.println(String() + F("Block:xCenter=") + result.xCenter + F(", yCenter=") + result.yCenter + F(", width=") + result.width + F(", height=") + result.height + F(", ID=") + result.ID);
  } else if (result.command == COMMAND_RETURN_ARROW) {
    Serial.println(String() + F("Arrow:xOrigin=") + result.xOrigin + F(", yOrigin=") + result.yOrigin + F(", xTarget=") + result.xTarget + F(", yTarget=") + result.yTarget + F(", ID=") + result.ID);
  } else {
    Serial.println("Object unknown!");
  }
}

//Forward
void forward(float g) {
  angle = (int)(2 * (g - offsetangle));
  int pos = 90 - angle;
  myservo.write(pos);
  motor.run_motor(0, 100);
}

//Wall Follow
void rforwardwall(float g, int d) {
  if (d > 400) {
    angle = int(2 * (g - (offsetangle + 10)));
  } else if (d > 350) {
    angle = int(1.2 * (g - (offsetangle + 6)));
  } else if (d < 310) {
    angle = int(1.2 * (g - (offsetangle - 6)));
  } else {
    angle = int(1.2 * (g - (offsetangle)));
  }
  int pos = 90 - angle;
  myservo.write(pos);
  motor.run_motor(0, 100);
}

void wheel_pulse() {
  if (flag) {
    i++;
  } else {
    i--;
  }
}

//Setup
void setup() {
  Serial.begin(115200);
  Wire.begin();
  motor.run_motor(0, 0);

  front.begin();
  right.begin();
  left.begin();
  gyro.begin();

  pinMode(enc, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(enc), wheel_pulse, RISING);
  myservo.attach(servoPin, 0, 3000);

  pinMode(2, OUTPUT);
  digitalWrite(2, HIGH);

  int buttonState = digitalRead(buttonPin);
  while (buttonState == 1) {
    buttonState = digitalRead(buttonPin);
  }
  delay(200);

  mySerial.begin(9600, SERIAL_8N1, HUSKYLENS_RX, HUSKYLENS_TX);
  while (!huskylens.begin(mySerial)) {
    Serial.println(F("Begin failed!"));
    Serial.println(F("1. Recheck HUSKYLENS Protocol (should be Serial 9600)"));
    Serial.println(F("2. Recheck wiring: Blue wire to RX, Green wire to TX"));
    delay(1000);
  }
}

void loop() {
  int rightdist = right.readDistance1();
  int leftdist = left.readDistance1();
  int frontdist = front.readDistance();
  gyro.update();
  yaw = gyro.getYaw();
  rforwardwall(yaw, rightdist);  //run the forward
  HUSKYLENSResult result = huskylens.read();
  if (result.ID == 1) {  // Red → turn Right
    Serial.print("Red Detected at X=");
    Serial.print(result.xCenter);
    Serial.print(", Y=");
    Serial.println(result.yCenter);
    myservo.write(105);
  } else if (result.ID == 2) {  // Green → turn Left
    Serial.println("Green Detected at X=");
    Serial.print(result.xCenter);
    Serial.print(", Y=");
    Serial.println(result.yCenter);
    myservo.write(75);
  }
  if()

  //turnAngle = constrain(turnAngle, MIN_ANGLE, MAX_ANGLE);

  Serial.print("Turn Angle: ");
  Serial.println(turnAngle);

  //myservo.write(turnAngle);
  //delay(100);                     // time for servo to rotate
  //motor.run_motor(0, 100);        // move while turning
  //delay(1000);                    // <- increase if needed to go around fully
  //motor.run_motor(0, 0);          // stop
  //myservo.write(SERVO_CENTER);    // re-center steering
  //delay(100);                     // brief pause before resuming
}


