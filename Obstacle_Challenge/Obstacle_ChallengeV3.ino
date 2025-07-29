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
int side = 0;  // distance(1:left turn, 2:right turn)
int target = 86;
int pos = 0;
#define enc 17
float yaw = 0;
int angle = 0;


HUSKYLENS huskylens;
HardwareSerial mySerial(2); // Use UART2 (Serial2)

#define HUSKYLENS_RX 4  // Blue wire from HUSKYLENS TX → ESP32 GPIO 4
#define HUSKYLENS_TX 0  // Green wire from HUSKYLENS RX → ESP32 GPIO 0

void printResult(HUSKYLENSResult result);



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

  mySerial.begin(9600, SERIAL_8N1, HUSKYLENS_RX, HUSKYLENS_TX);

    while (!huskylens.begin(mySerial)) {
        Serial.println(F("Begin failed!"));
        Serial.println(F("1. Recheck HUSKYLENS Protocol (should be Serial 9600)"));
        Serial.println(F("2. Recheck wiring: Blue wire to RX, Green wire to TX"));
        delay(1000);
    }

}

void loop() {
  // Husky Integration
  if (!huskylens.request()){
      Serial.println(F("Fail to request data from HUSKYLENS, recheck the connection!"));
  }
  else if (!huskylens.isLearned()){
      Serial.println(F("Nothing learned, press learn button on HUSKYLENS to learn one!"));
  }
  else if (!huskylens.available()){
      myservo.write(90);
      Serial.println(F("No block or arrow appears on the screen!"));
  }
  else {
      //Serial.println(F("###########"));
      while (huskylens.available()) {
          HUSKYLENSResult result = huskylens.read();
          motor.run_motor(0,100);

          if (result.command == COMMAND_RETURN_BLOCK) {

            if (result.ID == 1 && result.yCenter >= 30) { // RED
              
              myservo.write(120);
              Serial.print("Red Detected at X=");
              Serial.print(result.xCenter);
              Serial.print(", Y=");
              Serial.println(result.yCenter);
                
              
            delay(1000);
            }
            else if (result.ID == 2 && result.yCenter >=30) {  // GREEN
             
                //Serial.print("Green Detected at X=");
              myservo.write(70);
              motor.run_motor(0, 100);
              delay(1000);
              motor.run_motor(0, 100);
              myservo.write(88);
              delay(2000);
              motor.run_motor(0, 100);
              myservo.write(100);
              delay(1000);
              myservo.write(88);
              motor.run_motor(0, 0);

              Serial.print(result.xCenter);
              Serial.print(", Y=");
              Serial.println(result.yCenter);
              
              
            delay(1000);
            }
            else if(result.ID == 2 && result.yCenter <= 30) {
              Serial.print("Unknown color ID: ");
              myservo.write(90);
          
              delay(1000);
            }
            else if (result.ID == 1 && result.yCenter <= 30) {
              Serial.print("Unknown color ID: ");
              myservo.write(90);
              
              delay(1000);
            
          }
            else if (result.command == COMMAND_RETURN_ARROW) {
                Serial.println(String() + F("Arrow:xOrigin=") + result.xOrigin + F(", yOrigin=") + result.yOrigin +
                              F(", xTarget=") + result.xTarget + F(", yTarget=") + result.yTarget + F(", ID=") + result.ID);
            }
            // Ignoring other commands silently
        }
    }
  }

//   gyro.update();
//   yaw = gyro.getYaw();
//  forward(yaw);


  // int rightdist = right.readDistance1();  //RIGHT
  // int leftdist = left.readDistance1();    //LEFT
  // int frontdist = front.readDistance();   //FRONT
  // gyro.update();
  // yaw = gyro.getYaw();
  // if (count >= 1 && count < 12) {
  //   forward(yaw);
  // } else if (count >= 12) {
  //     motor.stop_motor();
  //     forward(yaw);
  //     delay(5000);
  //     motor.stop_motor();
  //     delay(1000000000);
  // } else {
  //     forward(yaw);
  // }

  // Serial.print("front--");
  // Serial.println(frontdist);
  // Serial.print("left--");
  // Serial.println(leftdist);
  // Serial.print("right--");
  // Serial.println(rightdist);
  // Serial.println(yaw);

  //logic for turning
  // if (frontdist < 350 && frontdist > 0) {     // start logic at 0 cm
  //   if (rightdist < 500 && leftdist > 500) {  // turn left (counter clockwise)
  //     side = 1;
  //     count += 1;
  //     offsetangle -= 88;
  //     while (yaw > (target * -1)) {
  //       gyro.update();
  //       yaw = gyro.getYaw();
  //       myservo.write(60);
  //     }

  //   } else if (leftdist < 700 && rightdist > 700) {  //turn right
  //     side = 2;
  //     count += 1;
  //     offsetangle += 90;
  //     while (yaw < target) {
  //       gyro.update();
  //       yaw = gyro.getYaw();
  //       myservo.write(120);
  //     }
  //   }
  //   motor.stop_motor();
  //   myservo.write(90);
  //   delay(1000);
  //   target += 88;
  // }

}

void forward(float g) {
  angle = (int)(2 * (g - (offsetangle)));

  int pos = 90 - angle;

  myservo.write(pos);
  motor.run_motor(0, 100);
}

void printResult(HUSKYLENSResult result) {
    if (result.command == COMMAND_RETURN_BLOCK) {
        Serial.println(String() + F("Block:xCenter=") + result.xCenter + F(", yCenter=") + result.yCenter +
                       F(", width=") + result.width + F(", height=") + result.height + F(", ID=") + result.ID);
    } else if (result.command == COMMAND_RETURN_ARROW) {
        Serial.println(String() + F("Arrow:xOrigin=") + result.xOrigin + F(", yOrigin=") + result.yOrigin +
                       F(", xTarget=") + result.xTarget + F(", yTarget=") + result.yTarget + F(", ID=") + result.ID);
    } else {
        Serial.println("Object unknown!");
    }
}

void wheel_pulse() {
  // Optional encoder logic if needed
  if (flag) {
    i++;
  } else {
    i--;
  }
}


//void greenTurn() {
  







