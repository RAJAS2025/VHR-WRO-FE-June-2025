#include <SMotor.h>
#include <ESP32Servo.h>
#include <ZebraTOF.h>
#include <ZebraGyro.h>
#include "Wire.h"
#include "HUSKYLENS.h"
SMotor motor(1);
bool flag = false;
Servo myservo;
int servoPin = 27;
ZebraGyro gyro(7, 12);
ZebraTOF front(5);
ZebraTOF right(4);
ZebraTOF left(3);
int target_x = 0;
float offsetangle = 0;
const int buttonPin = 15;
int i = 0;
float kp = 0.4;        // GYRO PROPORTIONAL
bool distance = true;  //DISTANCE PROPORTIONAL BOOLEAN
int count = 0;
int side = 0;  // (1:left turn, 2:right turn)
int target = 0;
int rightdist = 0;
int leftdist = 0;
int frontdist = 0;
#define enc 17
float yaw = 0;
int angle = 0;

unsigned long turned;

float lwallval = 0;
float rwallval = 0;

float red = 0;
float green = 0;
float pink = 0;
int rx = 0;
int ry = 0;
int gx = 0;
int gy = 0;
int by = 0;
int bx = 0;
int ox = 0;
int oy = 0;
int px = 0;
int py = 0;

bool gp = false;
bool rp = false;
bool bl = false;
bool ol = false;
bool pw = false;

bool wallval = true;

HUSKYLENS huskylens;
HardwareSerial mySerial(2);
#define HUSKYLENS_RX 4
#define HUSKYLENS_TX 0
bool pillar = false;
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
  ESP32PWM::allocateTimer(0);
  ESP32PWM::allocateTimer(1);
  ESP32PWM::allocateTimer(2);
  ESP32PWM::allocateTimer(3);
  myservo.setPeriodHertz(50);  // standard 50 hz servo

  myservo.attach(servoPin, 500, 2500);
  pinMode(2, OUTPUT);
  digitalWrite(2, HIGH);

  mySerial.begin(9600, SERIAL_8N1, HUSKYLENS_RX, HUSKYLENS_TX);
  while (!huskylens.begin(mySerial)) {
    Serial.println(F("Begin failed!"));
    Serial.println(F("1. Recheck HUSKYLENS Protocol (should be Serial 9600)"));
    Serial.println(F("2. Recheck wiring: Blue wire to RX, Green wire to TX"));
    delay(1000);
  }
  // configure LED for output
  int buttonState = digitalRead(buttonPin);

  while (buttonState == 1) {
    buttonState = digitalRead(buttonPin);
  }
  delay(200);
  // Parrallel Exit
  rightdist = constrain(right.readDistance1(), 0, 1200);  //RIGHT
  leftdist = constrain(left.readDistance1(), 0, 1200);    //LEFT
  if (rightdist < leftdist) {
    side = 1;  //left
    myservo.write(45);
    while (i < 400) {
      motor.run_motor(1, 55);
    }
    motor.stop_motor();
    //////forward straighten
    i = 0;
    myservo.write(140);
    while (i < 550) {
      motor.run_motor(1, 55);
    }
    motor.stop_motor();
    myservo.write(95);
    //////backward
    i = 0;
    while (i < 1500) {
      motor.run_motor(0, 55);
    }
    motor.stop_motor();
    myservo.write(95);

  } else {
    side = 2;  //right
    myservo.write(150);
    while (i < 400) {
      motor.run_motor(1, 55);
    }
    motor.stop_motor();
    //////forward straighten
    i = 0;
    myservo.write(55);
    while (i < 600) {
      motor.run_motor(1, 55);
    }
    motor.stop_motor();
    myservo.write(95);
    ///////backward
    i = 0;
    while (i < 600) {
      motor.run_motor(0, 55);
    }
    motor.stop_motor();
    myservo.write(95);
  }
  motor.stop_motor();
}

void loop() {
  //////////////
  huskylens.request();

  ry = 0;
  rx = 0;
  gx = 0;
  gy = 0;
  bx = 0;
  by = 0;
  ox = 0;
  oy = 0;
  px = 0;
  py = 0;
  bl = false;
  ol = false;
  gp = false;
  rp = false;
  pw = false;
  if (!huskylens.available()) {
    target_x = 0;
    wallval = true;
    pillar = true;
    bl = false;
    ol = false;
    gp = false;
    rp = false;
    pw = false;

  } else {
    while (huskylens.available()) {
      HUSKYLENSResult result = huskylens.read();
      if (result.command == COMMAND_RETURN_BLOCK) {

        if (result.ID == 1) {
          rp = true;
          rx = result.xCenter;
          ry = result.yCenter;  // red → turn left
          // red = 0.018 * (20 - result.xCenter) * result.yCenter;
          pillar = false;
          wallval = false;
        }
        // else {
        //   rp = false;
        //   rx = 0;
        //   ry = 0;
        //   red = 0;
        // }
        else if (result.ID == 2) {
          gp = true;
          gx = result.xCenter;
          gy = result.yCenter;  // green → turn right
          // green = 0.018 * (280 - result.xCenter) * result.yCenter;
          pillar = false;
          // wallval = false;
        } 
        //  else {
        //   gp = false;
        //   gx = 0;
        //   gy = 0;
        //   green = 0;
        // }
        else if (result.ID == 3) {
          ol = true;
          ox = result.xCenter;
          oy = result.yCenter;
        }
        // else {
        //   ox = 0;
        //   oy = 0;
        //   ol = false;
        // }
        else if (result.ID == 4) {
          bl = true;
          bx = result.xCenter;
          by = result.yCenter;
        }
        // else {
        //   bx = 0;
        //   by = 0;
        //   bl = false;
        // }

        else if (result.ID == 5) {
          pw = true;
          px = result.xCenter;
          py = result.yCenter;
        }
        // else {
        //   pw = false;
        //   px = 0;
        //   py = 0;
        //   pink = 0;
        // }
      }
    }
  }

  if (pw) {
    distance = false;
    if (side == 1) {
      pink = 0.002 * (300 - px) * py;
    } else {
      pink = 0.002 * (0 - px) * py;
    }
  } else {
    distance = true;
  }

  if (by > gy && by > ry && side == 1) {
    green = 0;
    red = 0;
  } else {
    if (ry > gy) {
      red = 0.003 * (30 - rx) * ry;
      green = 0;
    } else if (gy > ry) {
      green = 0.003 * (270 - gx) * gy;
      red = 0;
    }
  }

  if (oy > (gy+20) && oy > (ry+20) && side == 2) {
    green = 0;
    red = 0;
  } else {
    if (ry > gy) {
      red = 0.005 * (30 - rx) * ry;
      green = 0;
    } else if (gy > ry) {
      green = 0.005 * (270 - gx) * gy;
      red = 0;
    }
  }


  target_x = green + red + pink;


  gyro.update();
  yaw = gyro.getYaw();
  rightdist = constrain(right.readDistance1(), 0, 1200);  //RIGHT
  leftdist = constrain(left.readDistance1(), 0, 1200);    //LEFT

  if (bl == true && by > 130 && bx > 120 && side == 1 && (millis() - turned > 3500)) {  ////by > 140 && bx > 140
    if (abs(offsetangle - yaw) > 40) {
      motor.stop_motor();
      delay(100);
      offsetangle -= 88;
      count += 1;
      i = 0;
    } else if (rightdist < 300) {
      motor.stop_motor();
      delay(100);
      motor.run_motor(1, 55);
      count += 1;
      offsetangle -= 88;
      target = abs(offsetangle) - 25;

      while (yaw > (target * -1)) {
        gyro.update();
        yaw = gyro.getYaw();
        myservo.write(55);
      }
      motor.stop_motor();
      delay(500);
      myservo.write(95);
      distance = true;
      wallval = true;
      i = 0;
    } else {
      motor.stop_motor();
      delay(100);
      motor.run_motor(1, 55);
      count += 1;
      offsetangle -= 88;
      target = abs(offsetangle) - 60;

      while (yaw > (target * -1)) {
        gyro.update();
        yaw = gyro.getYaw();
        myservo.write(55);
      }
      motor.stop_motor();
      delay(500);
      myservo.write(95);
      distance = true;
      wallval = true;
      i = 0;
    }
    turned = millis();
  }

  if (ol == true && oy > 130 && side == 2 && (millis() - turned > 3500)) {
    motor.stop_motor();
    delay(1000);
    motor.run_motor(1,55);
    if (gp) {
      frontdist = constrain(front.readDistance1(), 0, 1200);
      while (frontdist > 300) {
        gyro.update();
        yaw = gyro.getYaw();
        if (abs(offsetangle - yaw) > 50) {
          kp = 2;
        } else {
          kp = 0.8;
        }
        frontdist = constrain(front.readDistance1(), 0, 1200);
        leftdist = 1000;
        rightdist = 1000;
        target_x = 0;
        forward(yaw, target_x, rightdist, leftdist);
      }
      motor.stop_motor();
      ////
      motor.run_motor(1, 55);
      target = abs(offsetangle) + 70;
      while (yaw < target) {
        gyro.update();
        yaw = gyro.getYaw();
        myservo.write(135);
      }
      motor.stop_motor();
      myservo.write(95);
      motor.run_motor(1, 55);
      delay(900);
      motor.stop_motor();

    } else {
      motor.run_motor(1, 55);
      target = abs(offsetangle) + 55 ;
      while (yaw < target) {
        gyro.update();
        yaw = gyro.getYaw();
        myservo.write(150);
      }
      motor.stop_motor();
    }
    count += 1;
    offsetangle += 88;
    myservo.write(95);
    distance = true;
    wallval = true;
    i = 0;
    turned = millis();
  }


  /////////

  /////////
  if (count >= 12) {
    i = 0;
    // delay(10);
    while (i < 6000) {
      if (side == 1) {
        rforwardwall(yaw, rightdist);
      } else {
        lforwardwall(yaw, leftdist);
      }
    }
    motor.stop_motor();
  } else {
    
    if (gp == true) {
      rightdist = 1000;
    } else if (rp == true) {
      leftdist = 1000;
    }
    // Serial.print(leftdist);
    // Serial.print("-");
    // Serial.println(rightdist);

    // if (rightdist < 200) {
    //   myservo.write(75);
    //   motor.run_motor(1, 65);
    //   digitalWrite(2, LOW);


    // } else if (leftdist < 200) {
    //   myservo.write(115);
    //   motor.run_motor(1, 65);
    //   digitalWrite(2, LOW);
    // } else {
      // gyro.update();
      digitalWrite(2, HIGH);
      forward(yaw, target_x, rightdist, leftdist);
    // }
  }
}

void forward(float g, float block, int rwd, int lwd) {
  if (rwd < 300) {
    rwallval = 0.3 * (rwd - 300);
  } else {
    rwallval = 0;
  }
  if (lwd < 300) {
    lwallval = 0.3 * (lwd - 300);
  } else {
    lwallval = 0;
  }

  kp = 1;
  // angle = (int)(kp * (g - (offsetangle - block)));
  // if (abs(g - offsetangle) > 35) {
  //   kp = 0.4;
  // } else {
  //   kp = 0.9;
  // }

  // if (distance) {
    angle = (int)(kp * (g - (offsetangle - block + rwallval - lwallval)));
  // } else {
  //   if (side == 1) {
  //     angle = (int)(kp * (g - (offsetangle - block - lwallval)));
  //   } else {
  //     angle = (int)(kp * (g - (offsetangle - block + rwallval)));
  //   }
  // }
  int pos = 95 - angle;
  pos = constrain(pos, 65, 125);
  myservo.write(pos);
  motor.run_motor(1, 56);
}

void rforwardwall(float g, int d) {  // what is r forward? write some comment about it.
  float wallval = 0.05 * (d - 400);
  angle = int(1.2 * (g - (offsetangle + wallval)));
  // if (d > 400) {
  //   angle = int(1.2 * (g - (offsetangle + 8)));
  // } else if (d > 350) {
  //   angle = int(1.2 * (g - (offsetangle + 5)));
  // } else if (d < 310) {
  //   angle = int(1.2 * (g - (offsetangle - 5)));
  // } else {
  //   angle = int(1.2 * (g - (offsetangle)));
  // }
  int pos = 95 - angle;
  myservo.write(pos);
  motor.run_motor(1, 100);
}

void lforwardwall(float g, int d) {
  float wallval = 0.05 * (d - 400);
  angle = int(1.2 * (g - (offsetangle - wallval)));
  // if (d > 400) {
  //   angle = int(1.2 * (g - (offsetangle - 8)));
  // } else if (d > 350) {
  //   angle = int(1.2 * (g - (offsetangle - 5)));
  // } else if (d < 310) {
  //   angle = int(1.2 * (g - (offsetangle + 5)));
  // } else {
  //   angle = int(1.2 * (g - (offsetangle)));
  // }
  int pos = 95 - angle;
  myservo.write(pos);
  motor.run_motor(1, 100);
}

void wheel_pulse() {
  // Optional encoder logic if needed

  i++;
}
