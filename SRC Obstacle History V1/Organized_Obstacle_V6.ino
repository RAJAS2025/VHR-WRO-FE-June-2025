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

HUSKYLENS huskylens;
HardwareSerial mySerial(2); // Use UART2 (Serial2)

#define HUSKYLENS_RX 4
#define HUSKYLENS_TX 0

void printResult(HUSKYLENSResult result);
void forward(float g);

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
  gyro.update();
  yaw = gyro.getYaw();
  if (!huskylens.request()) {
    Serial.println(F("Fail to request data from HUSKYLENS, recheck the connection!"));
    forward(yaw);
  }
  else if (!huskylens.isLearned()) {
    Serial.println(F("Nothing learned, press learn button on HUSKYLENS to learn one!"));
    forward(yaw);
  }
  else if (!huskylens.available()) {
    Serial.println(F("No block or arrow appears on the screen!"));
    forward(yaw);
  }
  else {
    HUSKYLENSResult result = huskylens.read();

    if (result.command == COMMAND_RETURN_BLOCK) {
      if (result.ID == 1 && result.yCenter >= 100) { // RED
        myservo.write(110);
        Serial.print("Red Detected");
        Serial.print("Red Detected at X=");
        Serial.print(result.xCenter);
        Serial.print(", Y=");
        Serial.println(result.yCenter);
      }
      else if (result.ID == 2 && result.yCenter >= 100) { // GREEN
        myservo.write(70);
        Serial.print("Green Detected");
        Serial.print("Red Detected at X=");
        Serial.print(result.xCenter);
        Serial.print(", Y=");
        Serial.println(result.yCenter);
      }
      else {
        forward(yaw);
        // delay(600);
        // motor.run_motor(0, 0);
      }
    }
    else if (result.command == COMMAND_RETURN_ARROW) {
      Serial.println(String() + F("Arrow:xOrigin=") + result.xOrigin + F(", yOrigin=") + result.yOrigin +
                     F(", xTarget=") + result.xTarget + F(", yTarget=") + result.yTarget + F(", ID=") + result.ID);
    }
  }
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
  if (flag) {
    i++;
  } else {
    i--;
  }
}
