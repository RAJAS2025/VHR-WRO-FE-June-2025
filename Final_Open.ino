#include <SMotor.h>
#include <ESP32Servo.h>
#include <ZebraTOF.h>
#include <ZebraGyro.h>
#include "Wire.h"
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
int side = 0;  // distance(1:left turn, 2:right turn)
int target = 86;
int pos = 0;
#define enc 17
float yaw = 0;
int angle = 0;
void setup() {
  // initialize device
  Serial.begin(115200);
  Wire.begin();
  motor.run_motor(0, 0);
  //initialize everything
  front.begin();
  right.begin();
  left.begin();
  gyro.begin();
  pinMode(enc, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(enc), wheel_pulse, RISING);
  myservo.attach(servoPin, 0, 3000);
  pinMode(2, OUTPUT);
  digitalWrite(2, HIGH);
  // configure LED for output
  int buttonState = digitalRead(buttonPin);
  while (buttonState == 1) {
    buttonState = digitalRead(buttonPin);
  }
  delay(200);
}

void loop() {
  int rightdist = right.readDistance1();  //RIGHT
  int leftdist = left.readDistance1();    //LEFT
  int frontdist = front.readDistance();   //FRONT
  gyro.update();
  yaw = gyro.getYaw();
  if (count >= 1 && count < 12) {
    if (side == 1) {
      rforwardwall(yaw, rightdist);
    } else {
      lforwardwall(yaw, leftdist);
    }
  } else if (count >= 12) {
      motor.stop_motor();
      forward(yaw);
      delay(5000);
      motor.stop_motor();
      delay(1000000000);
  } else {
      forward(yaw);
  }

  // Serial.print("front--");
  // Serial.println(frontdist);
  // Serial.print("left--");
  // Serial.println(leftdist);
  // Serial.print("right--");
  // Serial.println(rightdist);
  // Serial.println(yaw);

  //logic for turning
  if (frontdist < 350 && frontdist > 0) {     // start logic at 0 cm
    if (rightdist < 500 && leftdist > 500) {  // turn left (counter clockwise)
      side = 1;
      count += 1;
      offsetangle -= 88;
      while (yaw > (target * -1)) {
        gyro.update();
        yaw = gyro.getYaw();
        myservo.write(60);
      }

    } else if (leftdist < 700 && rightdist > 700) {  //turn right
      side = 2;
      count += 1;
      offsetangle += 90;
      while (yaw < target) {
        gyro.update();
        yaw = gyro.getYaw();
        myservo.write(120);
      }
    }
    motor.stop_motor();
    myservo.write(90);
    delay(1000);
    target += 88;
  }
}

void forward(float g) {
  angle = (int)(2 * (g - (offsetangle)));

  int pos = 90 - angle;

  myservo.write(pos);
  motor.run_motor(0, 100);
}


void rforwardwall(float g, int d) {
  if (d>300){
     angle = int(2 * (g - (offsetangle + 10)));
  }
  else if (d > 250) {
    angle = int(1.2 * (g - (offsetangle + 4)));
  } else if (d < 210) {
    angle = int(1.2 * (g - (offsetangle - 4)));
  } else {
    angle = int(1.2 * (g - (offsetangle)));
  }
  int pos = 90 - angle;
  myservo.write(pos);
  motor.run_motor(0, 100);
}

void lforwardwall(float g, int d) {
  if (d > 300) {
    angle = int(2 * (g - (offsetangle - 10)));
  } 
  else if (d > 250) {
    angle = int(2 * (g - (offsetangle - 4)));
  } else if (d < 210) {
    angle = int(2 * (g - (offsetangle + 4)));
  } else {
    angle = int(2 * (g - (offsetangle)));
  }
  int pos = 90 - angle;
  myservo.write(pos);
  motor.run_motor(0, 100);
}
void wheel_pulse() {
  // Optional encoder logic if needed
  if (flag) {
    i++;
  } else {
    i--;
  }
}
