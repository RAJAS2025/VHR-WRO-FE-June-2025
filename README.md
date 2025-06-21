# June-2025-Code
#include <ESP32Servo.h>
#include <SMotor2.h>
#include <ZebraServo.h>
#include <ZebraTOF.h>
#include <ZebraGyro.h>
#include "Wire.h"
MPU6050 mpu;
SMotor2 motor(1);
ZebraServo servo(5);
ZebraGyro gyro(7, 2);
ZebraTOF sensor2(2);
ZebraTOF sensor3(3);
ZebraTOF sensor1(4);
const int buttonPin = 15;
void setup() {
  Serial.begin(115200);
  //initialize everything
  sensor1.begin();
  sensor2.begin();
  sensor3.begin();
  gyro.begin();
  servo.begin();
  motor.begin();
  // NOTE: 8MHz or slower host processors, like the Teensy @ 3.3V or Arduino
  // Pro Mini running at 3.3V, cannot handle this baud rate reliably due to
  // the baud timing being too misaligned with processor ticks. You must use
  // 38400 or slower in these cases, or use some kind of external separate
  // crystal solution for the UART timer.
  ESP32PWM::allocateTimer(0);
  ESP32PWM::allocateTimer(1);
  ESP32PWM::allocateTimer(2);
  ESP32PWM::allocateTimer(3);
  motor.run_motor(0, 0);
  digitalWrite(2, HIGH);
  // configure LED for output
  int buttonState = digitalRead(buttonPin);
  while (buttonState == 1) {
    buttonState = digitalRead(buttonPin);
  }
  delay(200);
  count=0
}

void loop() {
  int d1 = sensor1.readDistance();
  int d2 = sensor2.readDistance();
  int d3 = sensor3.readDistance();
  gyro.update();
  gyro = (gyro.getYaw());
  if (count >= 1) {
    if (left = 1) {
      //wall and gyro straightening with d2
    }
    else {
      //wall and gyro straightening with d3
    }
  else {
    forward(gyro);
  }
  }

  //logic for turning
  if (d1 < 500) { // start logic at 50 cm
    if (d3 > 1000) { // turn left (counter clockwise)
      count += 1;
      target = 2500;
      i = 0;
      left = 1;
      while (target > i) {
        myservo.run_angles(60);
      }
    }
      else if (d2 > 1000) { //turn left
        count+=1;
        target;

      }
  }
  gyro.resetYaw();
  // if (count > 11) {

  //   while (millis() < 2000) {
  //     gyro1 = gyro_angle();
  //     angle = 1 * (target - gyro1 + count);
  //     pos = 93 + angle;
  //     myservo.write(pos);
  //     motor.run_motor(0, 100);
  // }
  //   motor.stop_motor();
  //   delay(100000);
  // }
}


void wheel_pulse() {

  // Read the value for the encoder for the right wheel

  if (flag) {
    i++;
  } else {
    i--;
  }
}

void forward(int g) {
  mpu.update();
 	int angle = 2*(g);
 	pos = 90+angle;
	myservo.run_angles(pos);
  motor.run_motor(0, 100);
}
// void Rforwardwall(int g) {
//   // Read distance from the wall
//   int currentDist = sensor2.readDistance();
//   int targetDist = 295; // Desired distance from the wall in mm
//   // Compute wall error
//   int wallError = currentDist - targetDist;
//   // Wall correction
//   int wallCorrection = wallError * 2; // Adjust this
//   // Gyro angle-based turning
//   int angle = 2 * g;
//   //total angle 
//   int totalAngle = angle + wallCorrection;
//   // Compute and set servo position
//   pos = 90 + totalAngle;
//   myservo.run_angles(pos);

//   // Drive motors forward
//   motor.run_motor(0, 100);
// }

