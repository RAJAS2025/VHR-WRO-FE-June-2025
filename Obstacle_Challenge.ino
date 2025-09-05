#include <SMotor.h>           // Motor driver library to control drive motors
#include <ESP32Servo.h>       // Servo control library for ESP32
#include <ZebraTOF.h>         // Time-of-Flight distance sensor library
#include <ZebraGyro.h>        // Gyroscope sensor library
#include "Wire.h"             // I2C communication library, used by sensors
#include "HUSKYLENS.h"        // HuskyLens AI vision sensor library

// Initialize motor instance on motor channel 1
SMotor motor(1);

bool flag = false;            // Generic flag used later?

Servo myservo;                // Steering servo object
int servoPin = 27;            // Pin connected to servo signal

// Initialize gyro with SDA and SCL pins (7 and 12)
ZebraGyro gyro(7, 12);

// Initialize front, right, and left distance sensors (TOF)
ZebraTOF front(5);
ZebraTOF right(4);
ZebraTOF left(3);

int target_x = 0;             // Target x position for steering corrections
float offsetangle = 0;        // Heading offset for gyro corrections

const int buttonPin = 15;     // Pin connected to start button
int i = 0;                   // Encoder pulse counter

// Proportional gain for gyro PID correction
float kp = 0.8;               

bool distance = true;         // Boolean to switch distance-based proportional control

int count = 0;                // Counts number of obstacles passed

int side = 0;                // Side selected for wall following: 1=left, 2=right

int target = 0;               // Target angle for turning or gyro reference

// Variables to store distance readings from sensors
int rightdist = 0;
int leftdist = 0;
int frontdist = 0;

#define enc 17               // Encoder input pin

float yaw = 0;                // Current yaw angle measured by gyro
int angle = 0;                // Steering angle correction value
unsigned long turned = -2000; // Time tracker for last turn event (initialize negative)

// Variables for wall following values
float lwallval = 0;
float rwallval = 0;

// Variables for detected colored objects from camera
float red = 0;
float green = 0;
float pink = 0;

int rx = 0;                  // Red x center
int ry = 0;                  // Red y center
int gx = 0;                  // Green x center
int gy = 0;                  // Green y center
int by = 0;                  // Blue y center
int bx = 0;                  // Blue x center
int ox = 0;                  // Orange x center
int oy = 0;                  // Orange y center
int px = 0;                  // Pink x center
int py = 0;                  // Pink y center

// Booleans to indicate if particular color objects are detected
bool gp = false;             // Green present
bool rp = false;             // Red present
bool bl = false;             // Blue present
bool ol = false;             // Orange present
bool pw = false;             // Pink present

bool wallval = true;         // Flag related to wall detection?

// Motor speed variables
int baseSpeed = 70;          // Base motor speed
int motorSpeed = 60;         // Current motor speed (may be adjusted)

// Current y coordinate of detected object
int curr_y = 0;

// Additional width, height and area variables for detected objects (used with HuskyLens)
int rw = 0;
int rh = 0;
int ra = 0;
int gw = 0;
int gh = 0;
int ga = 0;

// Create HuskyLens camera object
HUSKYLENS huskylens;

// Define serial communication for HuskyLens using UART2
HardwareSerial mySerial(2);

#define HUSKYLENS_RX 4       // HuskyLens RX pin (to ESP32 TX)
#define HUSKYLENS_TX 0       // HuskyLens TX pin (to ESP32 RX)

bool pillar = false;          // Flag to indicate detected pillar?

// Setup function - runs once at startup
void setup() {
  Serial.begin(115200);       // Start serial communication for debug output
  Wire.begin();               // Start I2C bus for sensors

  motor.run_motor(0, 0);      // Ensure motor stopped initially

  // Initialize distance sensors and gyro
  front.begin();
  right.begin();
  left.begin();
  gyro.begin();

  pinMode(enc, INPUT_PULLUP); // Setup encoder pin input with pullup resistor

  // Attach interrupt to encoder pin, call wheel_pulse on rising edge
  attachInterrupt(digitalPinToInterrupt(enc), wheel_pulse, RISING);

  // Allocate PWM timers for 4 channels (for servo control)
  ESP32PWM::allocateTimer(0);
  ESP32PWM::allocateTimer(1);
  ESP32PWM::allocateTimer(2);
  ESP32PWM::allocateTimer(3);

  myservo.setPeriodHertz(50);           // Set servo refresh rate to 50Hz (standard)
  myservo.attach(servoPin, 500, 2500);  // Attach servo with pulse width limits (500-2500us)

  pinMode(2, OUTPUT);                    // Pin 2 output (likely status LED or motor control)
  digitalWrite(2, HIGH);                 // Set pin 2 HIGH

  // Initialize HuskyLens serial communication at 9600 baud
  mySerial.begin(9600, SERIAL_8N1, HUSKYLENS_RX, HUSKYLENS_TX);
  
  // Wait until HuskyLens sensor initializes properly
  while (!huskylens.begin(mySerial)) {
    Serial.println(F("Begin failed!"));
    Serial.println(F("1. Recheck HUSKYLENS Protocol (should be Serial 9600)"));
    Serial.println(F("2. Recheck wiring: Blue wire to RX, Green wire to TX"));
    delay(1000);
  }

  // Initialize button state variable
  int buttonState = digitalRead(buttonPin);

  // Wait for button press (state==0) to start operation
  while (buttonState == 1) {
    buttonState = digitalRead(buttonPin);
  }
  delay(200); // Debounce delay

  // Determine closer wall and decide which side to follow
  rightdist = constrain(right.readDistance1(), 0, 1200);  // Get right distance
  leftdist = constrain(left.readDistance1(), 0, 1200);    // Get left distance

  if (rightdist < leftdist) {  // Closer to right wall
    side = 1;                  // Set side to 1 = left wall follow logic
    target = abs(offsetangle) + 75;

    gyro.update();
    yaw = gyro.getYaw();

    motor.run_motor(1, 50);    // Run motors forward at speed 50

    // Turn left until yaw past target angle on negative scale
    while (yaw > (target * -1)) {
      gyro.update();
      yaw = gyro.getYaw();
      myservo.write(45);       // Set servo to turn wheels left
    }

    motor.stop_motor();        // Stop motors for camera reading

    camread();                 // Read vision sensor to detect objects
    delay(500);

    if (rp == true && ry > gy) {
      // If red object detected and red y > green y, turn right back to initial offset
      target = abs(offsetangle);
      gyro.update();
      yaw = gyro.getYaw();

      motor.run_motor(1, 55);

      while (yaw < target) {
        gyro.update();
        yaw = gyro.getYaw();
        myservo.write(132);     // Steering right
      }

      motor.stop_motor();

    } else {
      // Otherwise move forward until front obstacle detected closer than 350 mm
      myservo.write(95);        // Center steering
      frontdist = front.readDistance1();
      offsetangle -= 90;        // Adjust heading offset left by 90 degrees

      while (frontdist > 350) {
        frontdist = front.readDistance1();
        gyro.update();
        yaw = gyro.getYaw();
        forward(yaw, 0, 1000, 1000);  // Move forward with normal PID
      }

      motor.stop_motor();

      offsetangle += 90;        // Reset offsetangle

      // Turn right slightly to realign
      target = abs(offsetangle) - 10;
      gyro.update();
      yaw = gyro.getYaw();
      motor.run_motor(1, 55);    // Run forward motor

      while (yaw < target) {
        gyro.update();
        yaw = gyro.getYaw();
        myservo.write(135);     // Turn right steering
      }

      motor.stop_motor();
    }

  } else {  // Closer to left wall
    side = 2;                  // Right wall follow logic
    target = abs(offsetangle) + 50;

    gyro.update();
    yaw = gyro.getYaw();

    motor.run_motor(1, 50);    // Run motor forward speed 50

    // Turn right until yaw exceeds target angle
    while (yaw < target) {
      gyro.update();
      yaw = gyro.getYaw();
      myservo.write(135);      // Turn wheels right
    }

    motor.stop_motor();

    myservo.write(95);         // Center steering
    camread();

    if (rp == true) {
      // If red present, move forward until front obstacle closer than 250 mm
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

    target = abs(offsetangle) + 15;
    gyro.update();
    yaw = gyro.getYaw();

    motor.run_motor(1, 60);

    while (yaw > target) {     // Turn wheels left while yaw > target
      gyro.update();
      yaw = gyro.getYaw();
      myservo.write(55);
    }

    motor.stop_motor();
    myservo.write(95);         // Center steering
  }
}

// Main program loop function – runs continuously
void loop() {
  camread();  // Read HuskyLens camera for object detections

  // Calculate color-based steering weights based on detected marker coordinates
  if (ra > ga) {             // Red area bigger – influence left steering
    red = 0.0035 * (20 - rx) * ry;
    green = 0;
    curr_y = ry;
  } else if (ga > ra) {      // Green bigger – influence right steering
    green = 0.003 * (280 - gx) * gy;
    red = 0;
    curr_y = gy;
  }

  if (pw) { // Pink marker detected – special obstacle behavior disables distance proportional
    distance = false;

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
    distance = true;  // Enable distance proportional control if no pink detected
  }

  // Reset steering influence if blue/orange detected with conditions and timer elapsed
  if (by > gy && by > ry && side == 1 && (millis() - turned > 4000)) {
    green = 0;
    red = 0;
    curr_y = 0;
  }

  if (oy > gy && oy > ry && side == 2 && (millis() - turned > 4000)) {
    green = 0;
    red = 0;
    curr_y = 0;
  }

  // Adjust motor speed according to current detection influence
  motorSpeed = baseSpeed - int((0.3 * curr_y));
  if (by > 100 && side == 1) {
    motorSpeed = 50;
  } else if (oy > 100 && side == 2) {
    motorSpeed = 50;
  }
  if (motorSpeed < 50) motorSpeed = 50;

  // Combine all color influence as target_x for steering
  target_x = green + red + pink;

  // Update gyro yaw and distance sensor readings
  gyro.update();
  yaw = gyro.getYaw();

  rightdist = constrain(right.readDistance1(), 0, 1200);
  leftdist = constrain(left.readDistance1(), 0, 1200);

  // Override distances if green or red present (simulate no wall)
  if (gp == true) rightdist = 1000;
  else if (rp == true) leftdist = 1000;

  // Wall avoidance logic based on proximity
  if (rightdist < 150) {
    myservo.write(80);       // Turn steering a bit left
    motor.run_motor(1, motorSpeed);
  } else if (leftdist < 150) {
    myservo.write(112);      // Turn steering a bit right
    motor.run_motor(1, motorSpeed);
  } else {
    forward(yaw, target_x, rightdist, leftdist);  // Normal forward motor control
  }

  // Obstacle and parking behavior triggered by detecting blue marker (side 1)
  if (bl == true && by > 150 && side == 1 && (millis() - turned > 2000)) {
    count += 1;

    if (count >= 13) park();  // Execute parking routine after 13 obstacles
    
    camread();
    leftdist = constrain(left.readDistance1(), 0, 1200);

    if (gp == true && gx < bx) {
      motor.run_motor(1, 45);    // Drive slowly forward

      if (leftdist < 300) {
        target = abs(offsetangle) + 45;

        // Turn left while yaw is greater than negative target
        while (yaw > (target * -1)) {
          gyro.update();
          yaw = gyro.getYaw();
          myservo.write(85);
        }
      } else {
        target = abs(offsetangle) + 45;

        while (yaw > (target * -1)) {
          gyro.update();
          yaw = gyro.getYaw();
          myservo.write(70);
        }
      }
    } else if (rp == true) {
      i = 0;
      while (i < 300) {
        gyro.update();
        yaw = gyro.getYaw();
        frontdist = constrain(front.readDistance1(), 0, 1200);
        leftdist = 1000;
        rightdist = 1000;
        target_x = 0;
        forward(yaw, target_x, rightdist, leftdist);
      }

      frontdist = constrain(front.readDistance1(), 0, 1200);
      while (frontdist > 270) {
        gyro.update();
        yaw = gyro.getYaw();
        frontdist = constrain(front.readDistance1(), 0, 1200);
        leftdist = 1000;
        rightdist = 1000;
        target_x = 0;
        forward(yaw, target_x, rightdist, leftdist);
      }

      motor.run_motor(1, 45);

      target = abs(offsetangle) + 50;

      while (yaw > target * -1) {
        gyro.update();
        yaw = gyro.getYaw();
        myservo.write(55);
      }
    } else {
      frontdist = constrain(front.readDistance1(), 0, 1200);

      while (frontdist > 450) {
        gyro.update();
        yaw = gyro.getYaw();
        frontdist = constrain(front.readDistance1(), 0, 1200);
        leftdist = 1000;
        rightdist = 1000;
        target_x = 0;
        forward(yaw, target_x, rightdist, leftdist);
      }

      motor.run_motor(1, 45);
      target = abs(offsetangle) + 75;

      while (yaw > (target * -1)) {
        gyro.update();
        yaw = gyro.getYaw();
        myservo.write(45);
      }

      motor.stop_motor();
      myservo.write(95);
      motor.run_motor(0, 55);
      delay(750);
      motor.stop_motor();
    }

    myservo.write(95);
    distance = true;
    i = 0;
    offsetangle -= 88;
    turned = millis();
  }

  // Obstacle and parking behavior for orange marker on side 2
  if (ol == true && oy > 170 && side == 2 && (millis() - turned > 4000)) {
    count++;

    if (count >= 13) park2();  // Execute second parking routine after 13 obstacles

    camread();

    rightdist = constrain(right.readDistance1(), 0, 1200);

    if (rp == true) {
      motor.run_motor(1, 45);

      if (rightdist < 300) {
        target = abs(offsetangle) + 40;

        while (yaw < target) {
          gyro.update();
          yaw = gyro.getYaw();
          myservo.write(115);
        }
      } else {
        target = abs(offsetangle) + 38;

        while (yaw < target) {
          gyro.update();
          yaw = gyro.getYaw();
          myservo.write(135);
        }
      }
    } else if (gp == true) {
      i = 0;
      while (i < 450) {
        gyro.update();
        yaw = gyro.getYaw();
        frontdist = constrain(front.readDistance1(), 0, 1200);
        leftdist = 1000;
        rightdist = 1000;
        target_x = 0;
        forward(yaw, target_x, rightdist, leftdist);
      }

      frontdist = constrain(front.readDistance1(), 0, 1200);

      while (frontdist > 350) {
        gyro.update();
        yaw = gyro.getYaw();
        frontdist = constrain(front.readDistance1(), 0, 1200);
        leftdist = 1000;
        rightdist = 1000;
        target_x = 0;
        forward(yaw, target_x, rightdist, leftdist);
      }

      motor.run_motor(1, 45);
      target = abs(offsetangle) + 70;

      while (yaw < target) {
        gyro.update();
        yaw = gyro.getYaw();
        myservo.write(135);
      }
    } else {
      frontdist = constrain(front.readDistance1(), 0, 1200);

      while (frontdist > 450) {
        gyro.update();
        yaw = gyro.getYaw();
        frontdist = constrain(front.readDistance1(), 0, 1200);
        leftdist = 1000;
        rightdist = 1000;
        target_x = 0;
        forward(yaw, target_x, rightdist, leftdist);
      }

      motor.run_motor(1, 45);
      target = abs(offsetangle) + 75;

      while (yaw < target) {
        gyro.update();
        yaw = gyro.getYaw();
        myservo.write(145);
      }

      motor.stop_motor();
      myservo.write(95);
      motor.run_motor(0, 55);
      delay(750);
      motor.stop_motor();
    }

    myservo.write(95);
    distance = true;
    i = 0;
    offsetangle += 90;
    turned = millis();
  }
}

// Drives forward with gyro-based steering control and wall proximity corrections
void forward(float g, float block, int rwd, int lwd) {
  if (rwd < 325) {
    rwallval = 0.035 * (rwd - 325);
  } else {
    rwallval = 0;
  }

  if (lwd < 350) {
    lwallval = 0.035 * (lwd - 300);
  } else {
    lwallval = 0;
  }

  kp = 0.35;  // Adjust proportional gain for forward driving

  if (millis() - turned < 2500) {   // For 2.5 seconds after turning, override wallval and speed
    rwallval = 0.08;
    motorSpeed = 60;
  }

  // Calculate steering angle difference (PID proportional term)
  angle = (int)(kp * (g - (offsetangle - block)));
  int pos = 95 - angle;    // Servo center=95, adjust left or right

  pos = constrain(pos, 65, 115);  // Servo limited range

  myservo.write(pos);      // Set steering servo position
  motor.run_motor(1, motorSpeed); // Run motor forward at computed speed
}

// Right-wall forward following with gyro correction
void rforwardwall(float g, int d) {
  float wallval = 0.2 * (d - 150);  // Distance offset for right wall
  angle = int(0.6 * (g - (offsetangle + wallval)));
  int pos = 95 - angle;
  pos = constrain(pos, 85, 105);
  myservo.write(pos);
  motor.run_motor(1, 60);
}

// Left-wall forward following with gyro correction
void lforwardwall(float g, int d) {
  float wallval = 0.2 * (d - 200);  // Distance offset for left wall
  angle = int(0.8 * (g - (offsetangle - wallval)));
  int pos = 95 - angle;
  pos = constrain(pos, 85, 105);
  myservo.write(pos);
  motor.run_motor(1, 60);
}

// Encoder interrupt function increments pulse count
void wheel_pulse() {
  i++;
}

// Read detected objects from HuskyLens and update flags and coordinates
void camread() {
  huskylens.request();  // Request data from HuskyLens camera

  // Reset detection variables for each loop call
  rw = 0; rh = 0; ra = 0;
  gw = 0; gh = 0; ga = 0;
  ry = 0; rx = 0;
  gx = 0; gy = 0;
  bx = 0; by = 0;
  ox = 0; oy = 0;
  px = 0; py = 0;

  bl = false;
  ol = false;
  gp = false;
  rp = false;
  pw = false;

  if (!huskylens.available()) {
    // No objects detected
    target_x = 0;
    wallval = true;
    pillar = true;
    bl = false;
    ol = false;
    gp = false;
    rp = false;
    pw = false;
  } else {
    // Read all available objects and classify them by ID
    while (huskylens.available()) {
      HUSKYLENSResult result = huskylens.read();
      if (result.command == COMMAND_RETURN_BLOCK) {
        if (result.ID == 1) {     // Red object detected
          rp = true;
          rx = result.xCenter;
          ry = result.yCenter;
          rw = result.width;
          rh = result.height;
          ra = rx * rh;
        } else if (result.ID == 2) {  // Green object detected
          gp = true;
          gx = result.xCenter;
          gy = result.yCenter;
          gw = result.width;
          gh = result.height;
          ga = gw * gh;
        } else if (result.ID == 3) {  // Orange object detected
          ol = true;
          ox = result.xCenter;
          oy = result.yCenter;
        } else if (result.ID == 4) {  // Blue object detected
          bl = true;
          bx = result.xCenter;
          by = result.yCenter;
        } else if (result.ID == 5) {  // Pink object detected
          pw = true;
          px = result.xCenter;
          py = result.yCenter;
        }
      }
    }
  }
}

// Parking routine triggered on side 2 (orange marker)
void park2() {
  motor.run_motor(1, 60);  // Turn left forward speed 60

  target = abs(offsetangle) - 80;

  while (yaw > target) {
    gyro.update();
    yaw = gyro.getYaw();
    myservo.write(45);
  }

  motor.stop_motor();

  myservo.write(95);
  offsetangle -= 88;

  frontdist = constrain(front.readDistance1(), 0, 1200);

  // Move forward until front distance less than 200
  while (frontdist > 200) {
    gyro.update();
    yaw = gyro.getYaw();
    frontdist = constrain(front.readDistance1(), 0, 1200);
    leftdist = 1000;
    rightdist = 1000;
    target_x = 0;
    forward(yaw, target_x, rightdist, leftdist);
  }

  motor.stop_motor();
  myservo.write(95);

  motor.run_motor(1, 60);  // Turn left again
  target = abs(offsetangle) - 80;

  while (yaw > target) {
    gyro.update();
    yaw = gyro.getYaw();
    myservo.write(45);
  }

  motor.stop_motor();

  myservo.write(95);

  offsetangle -= 88;

  gyro.update();
  yaw = gyro.getYaw();

  frontdist = constrain(front.readDistance1(), 0, 1200);

  // Move forward until front less than 300, following right wall
  while (frontdist > 300) {
    gyro.update();
    yaw = gyro.getYaw();
    frontdist = constrain(front.readDistance1(), 0, 1200);
    rightdist = constrain(right.readDistance1(), 0, 1200);
    rforwardwall(yaw, rightdist);
  }

  motor.stop_motor();

  motor.run_motor(1, 60);  // Turn left a bit more
  target = abs(offsetangle) - 45;

  while (yaw > target) {
    gyro.update();
    yaw = gyro.getYaw();
    myservo.write(75);
  }
  motor.stop_motor();

  motor.run_motor(1, 45);  // Straighten up by turning right
  target = abs(offsetangle) + 20;

  while (yaw < target) {
    gyro.update();
    yaw = gyro.getYaw();
    myservo.write(125);
  }

  motor.stop_motor();
  myservo.write(95);
  motor.run_motor(1, 55);
  delay(200);
  motor.stop_motor();

  rightdist = constrain(right.readDistance1(),0,1200);

  // Move forward until right wall less than 150
  while (rightdist > 150) {
    rightdist = constrain(right.readDistance1(), 0, 1200);
    gyro.update();
    yaw = gyro.getYaw();
    forward(yaw, 0, 1000, 1000);
  }

  motor.stop_motor();

  rightdist = constrain(right.readDistance1(), 0, 1200);

  if (rightdist < 300) {
    motor.run_motor(0, 45);  // Left turn backwards

    target = abs(offsetangle) - 80;

    while (yaw > target) {
      gyro.update();
      yaw = gyro.getYaw();
      myservo.write(150);
    }

    motor.stop_motor();
    myservo.write(95);
    motor.run_motor(0, 45);

    target = abs(offsetangle) + 24;

    // Right turn forwards
    while (yaw < target) {
      gyro.update();
      yaw = gyro.getYaw();
      myservo.write(40);
    }

    motor.stop_motor();
    myservo.write(95);

    delay(100000000000000);  // Essentially stop forever

  } else {
    motor.run_motor(0, 45);

    target = abs(offsetangle) - 80;

    while (yaw > target) {
      gyro.update();
      yaw = gyro.getYaw();
      myservo.write(150);
    }

    motor.stop_motor();
    myservo.write(95);
    motor.run_motor(0, 45);
    delay(400);
    motor.stop_motor();

    motor.run_motor(0, 45);  // Right turn forwards

    target = abs(offsetangle) + 24;

    while (yaw < target) {
      gyro.update();
      yaw = gyro.getYaw();
      myservo.write(40);
    }

    motor.stop_motor();
    myservo.write(95);

    delay(100000000000000);  // Stop forever
  }
}

// Parking routine triggered on side 1 (blue marker)
void park() {
  motor.run_motor(1, 60);    // Right turn forward

  target = abs(offsetangle) - 65;

  while (yaw < (target * -1)) {
    gyro.update();
    yaw = gyro.getYaw();
    myservo.write(130);
  }

  motor.stop_motor();

  myservo.write(95);

  motor.run_motor(0, 60);
  delay(1000);

  motor.stop_motor();

  myservo.write(95);

  offsetangle += 88;

  frontdist = constrain(front.readDistance1(), 0, 1200);

  // Move forward until front less than 200
  while (frontdist > 200) {
    gyro.update();
    yaw = gyro.getYaw();
    frontdist = constrain(front.readDistance1(), 0, 1200);
    leftdist = 1000;
    rightdist = 1000;
    target_x = 0;
    forward(yaw, target_x, rightdist, leftdist);
  }

  motor.stop_motor();
  delay(1000);

  motor.run_motor(1, 45);

  target = abs(offsetangle) - 70;

  while (yaw < (target * -1)) {
    gyro.update();
    yaw = gyro.getYaw();
    myservo.write(150);
  }

  motor.stop_motor();

  offsetangle += 89;

  gyro.update();
  yaw = gyro.getYaw();

  frontdist = constrain(front.readDistance1(), 0, 1200);

  // Move forward until front less than 300, following left wall
  while (frontdist > 300) {
    gyro.update();
    yaw = gyro.getYaw();
    frontdist = constrain(front.readDistance1(), 0, 1200);
    leftdist = constrain(left.readDistance1(), 0, 1200);
    lforwardwall(yaw, leftdist);
  }

  motor.stop_motor();

  motor.run_motor(1, 45);

  target = abs(offsetangle) - 55;

  // Turn right little
  while (yaw < (target * -1)) {
    gyro.update();
    yaw = gyro.getYaw();
    myservo.write(125);
  }

  motor.stop_motor();

  motor.run_motor(1, 45);

  target = abs(offsetangle) - 10;

  // Turn left (straighten)
  while (yaw > (target * -1)) {
    gyro.update();
    yaw = gyro.getYaw();
    myservo.write(55);
  }

  motor.stop_motor();

  myservo.write(95);

  // Move forward until pink wall detected
  motorSpeed = 56;
  motor.run_motor(1, 56);
  delay(500);

  motor.stop_motor();

  leftdist = constrain(left.readDistance1(), 0, 1200);

  while (leftdist > 200) {
    leftdist = constrain(left.readDistance1(), 0, 1200);
    gyro.update();
    yaw = gyro.getYaw();
    forward(yaw, 0, 1000, 1000);
  }

  motor.stop_motor();

  leftdist = constrain(left.readDistance1(), 0, 1200);

  if (leftdist < 300) {
    motor.run_motor(0, 58);

    target = abs(offsetangle) - 80;

    while (yaw < (target * -1)) {
      gyro.update();
      yaw = gyro.getYaw();
      myservo.write(60);
    }

    motor.stop_motor();

    myservo.write(95);

    motor.run_motor(1, 56);
    delay(200);
    motor.stop_motor();

    motor.run_motor(0, 45);

    target = abs(offsetangle);

    while (yaw > (target * -1)) {
      gyro.update();
      yaw = gyro.getYaw();
      myservo.write(150);
    }

    motor.stop_motor();

    myservo.write(95);

    delay(100000000000000);

  } else {
    motor.run_motor(0, 58);

    target = abs(offsetangle) + 80;

    while (yaw < (target * -1)) {
      gyro.update();
      yaw = gyro.getYaw();
      myservo.write(60);
    }

    motor.stop_motor();

    myservo.write(95);

    motor.run_motor(1, 56);
    delay(200);
    motor.stop_motor();

    motor.run_motor(0, 55);
    delay(200);
    motor.stop_motor();

    motor.run_motor(0, 45);
    delay(100);
    motor.run_motor(0, 45);

    target = abs(offsetangle) + 10;

    while (yaw > target) {
      gyro.update();
      yaw = gyro.getYaw();
      myservo.write(150);
    }

    motor.stop_motor();

    myservo.write(95);

    delay(100000000000000);
  }
}
