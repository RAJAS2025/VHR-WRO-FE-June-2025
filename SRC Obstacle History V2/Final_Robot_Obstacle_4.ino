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


int rw = 0;
int rh = 0;
int ra = 0;
int gw = 0;
int gh = 0;
int ga = 0;

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
    target = abs(offsetangle) + 73;
    gyro.update();
    yaw = gyro.getYaw();
    motor.run_motor(1, 55);
    while (yaw > (target * -1)) {
      gyro.update();
      yaw = gyro.getYaw();
      myservo.write(45);
    }
    motor.stop_motor();
    camread();
    if (rp == true) {
      target = abs(offsetangle);
      gyro.update();
      yaw = gyro.getYaw();
      motor.run_motor(1, 55);
      while (yaw < target) {
        gyro.update();
        yaw = gyro.getYaw();
        myservo.write(135);
      }
      motor.stop_motor();
    } else {
      myservo.write(95);
      frontdist = front.readDistance1();
      while (frontdist > 300) {
        frontdist = front.readDistance1();
        motor.run_motor(1, 55);
      }
      motor.stop_motor();
      ////
      target = abs(offsetangle);
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

    side = 2;  //right
    myservo.write(150);
    while (i < 400) {
      motor.run_motor(1, 55);
    }
    motor.stop_motor();
    //////forward straighten
    i = 0;
    myservo.write(55);
    while (i < 500) {
      motor.run_motor(1, 55);
    }
    motor.stop_motor();
    myservo.write(95);
    ///////backward
    i = 0;
    while (i < 1500) {
      motor.run_motor(0, 55);
    }
    motor.stop_motor();
    myservo.write(95);
  }
  motor.stop_motor();
}

void loop() {

  //////////////

  camread();
  if (pw) {
    distance = false;
    if (side == 1) {
      pink = 0.003 * (270 - px) * py;
    } else {
      pink = 0.003 * (50 - px) * py;
    }
  } else {
    distance = true;
  }


  if (by > gy && by > ry && side == 1 && bx > rx && bx > gx && (millis() - turned > 5000)) {
    green = 0;
    red = 0;
  } else {
    if (ra > ga) {
      red = 0.007 * (0 - rx) * ry;
      green = 0;
    } else if (ga > ra) {
      green = 0.0045 * (280 - gx) * gy;
      red = 0;
    }
  }

  if (oy > gy && oy > ry && side == 2 && ox > rx && ox > gx) {
    green = 0;
    red = 0;
  } else {
    if (ra > ga) {
      red = 0.004 * (0 - rx) * ry;
      green = 0;
    } else if (ga > ra) {
      green = 0.004 * (280 - gx) * gy;
      red = 0;
    }
  }



  target_x = green + red + pink;


  gyro.update();
  yaw = gyro.getYaw();
  rightdist = constrain(right.readDistance1(), 0, 1200);  //RIGHT
  leftdist = constrain(left.readDistance1(), 0, 1200);    //LEFT

  // if (count >= 12) {
  //   i = 0;
  //   // delay(10);
  //   while (i < 6000) {
  //     if (side == 1) {
  //       rforwardwall(yaw, rightdist);
  //     } else {
  //       lforwardwall(yaw, leftdist);
  //     }
  //   }
  //   motor.stop_motor();
  // } else {
  if (gp == true) {
    rightdist = 1000;
  } else if (rp == true) {
    leftdist = 1000;
  }
  if (rightdist < 100 && pillar == true) {
    myservo.write(80);
    motor.run_motor(1, 56);

  } else if (leftdist < 100 && pillar == true) {
    myservo.write(110);
    motor.run_motor(1, 56);
  } else {
    // gyro.update();
    forward(yaw, target_x, rightdist, leftdist);
  }


  if (bl == true && by > 150 && side == 1 && (millis() - turned > 5000)) {  ////by > 140 && bx > 140
    motor.stop_motor();
    count += 1;
    if (count >= 12) {
      park();
    }
    camread();
    leftdist = constrain(left.readDistance1(), 0, 1200);
    // motor.run_motor(1, 55);
    if (gp == true) {
      // motor.stop_motor();
      // delay(100);
      motor.run_motor(1, 55);
      if (leftdist < 300) {
        target = abs(offsetangle) + 65;
        while (yaw > (target * -1)) {
          gyro.update();
          yaw = gyro.getYaw();
          myservo.write(70);
        }
      } else {
        target = abs(offsetangle) + 65;
        while (yaw > (target * -1)) {
          gyro.update();
          yaw = gyro.getYaw();
          myservo.write(55);
        }
      }
      motor.stop_motor();
    } else if (rp == true) {
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
      motor.stop_motor();
      ////
      motor.run_motor(1, 55);
      target = abs(offsetangle) + 75;
      while (yaw > target * -1) {
        gyro.update();
        yaw = gyro.getYaw();
        myservo.write(55);
      }
      motor.stop_motor();
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
      motor.stop_motor();

      ////
      motor.run_motor(1, 55);
      target = abs(offsetangle) + 75;
      while (yaw > (target * -1)) {
        gyro.update();
        yaw = gyro.getYaw();
        myservo.write(45);
      }
      motor.stop_motor();
      myservo.write(95);
      motor.run_motor(0,55);
      delay(850);
      motor.stop_motor();
    }
    myservo.write(95);
    distance = true;
    // wallval = true;
    i = 0;
    offsetangle -= 88;
    turned = millis();
  }

  if (ol == true && oy > 170 && side == 2 && (millis() - turned > 3500)) {
    motor.stop_motor();
    delay(1000);
    count += 1;
    if (count >= 12) {
      park2();
    }
    camread();
    rightdist = constrain(right.readDistance1(), 0, 1200);  //RIGHT
    if (rp == true) {
      motor.stop_motor();
      delay(100);
      motor.run_motor(1, 55);
      if (rightdist < 250) {
        target = abs(offsetangle) + 80;
        while (yaw < target) {
          gyro.update();
          yaw = gyro.getYaw();
          myservo.write(125);
        }
      } else {
        target = abs(offsetangle) + 80;
        while (yaw < target) {
          gyro.update();
          yaw = gyro.getYaw();
          myservo.write(135);
        }
      }

      motor.stop_motor();
      myservo.write(95);

      distance = true;
      // wallval = true;
      i = 0;
      offsetangle += 88;

    } else if (gp == true) {
      frontdist = constrain(front.readDistance1(), 0, 1200);
      while (frontdist > 300) {
        gyro.update();
        yaw = gyro.getYaw();
        frontdist = constrain(front.readDistance1(), 0, 1200);
        leftdist = 1000;
        rightdist = 1000;
        target_x = 0;
        forward(yaw, target_x, rightdist, leftdist);
      }
      motor.stop_motor();
      ////
      motor.run_motor(1, 55);
      target = abs(offsetangle) + 75;
      while (yaw < target) {
        gyro.update();
        yaw = gyro.getYaw();
        myservo.write(135);
      }
      motor.stop_motor();
      myservo.write(95);
      distance = true;
      // wallval = true;
      i = 0;
      offsetangle += 88;
    } else {
      frontdist = constrain(front.readDistance1(), 0, 1200);
      while (frontdist > 375) {
        gyro.update();
        yaw = gyro.getYaw();
        frontdist = constrain(front.readDistance1(), 0, 1200);
        leftdist = 1000;
        rightdist = 1000;
        target_x = 0;
        forward(yaw, target_x, rightdist, leftdist);
      }
      motor.stop_motor();
      ////
      motor.run_motor(1, 55);
      target = abs(offsetangle) + 75;
      while (yaw < target) {
        gyro.update();
        yaw = gyro.getYaw();
        myservo.write(135);
      }
      motor.stop_motor();
      myservo.write(95);
      motor.run_motor(0, 55);
      delay(200);
      motor.stop_motor();
      distance = true;
      // wallval = true;
      i = 0;
      offsetangle += 88;
    }
    turned = millis();
  }
}

void forward(float g, float block, int rwd, int lwd) {
  // if (wallval) {
  // if (rwd < 400) {
  //   rwallval = 0.25 * (rwd - 400);
  // } else {
  //   rwallval = 0;
  // }
  // if (lwd < 400) {
  //   lwallval = 0.25 * (lwd - 400);
  // } else {
  //   lwallval = 0;
  // }
  if (rwd < 250) {
    rwallval = 0.2 * (rwd - 250);
  } else {
    rwallval = 0;
  }
  if (lwd < 250) {
    lwallval = 0.2 * (lwd - 250);
  } else {
    lwallval = 0;
  }
  // kp = 0.8;
  if (abs(g - offsetangle) > 35) {
    kp = 0.5;
  } else {
    kp = 0.8;
  }
  /////
  if (millis() - turned < 2500){
    lwallval = 0;
    rwallval = 0;
    kp = 0.2;
  }
  if (distance) {
    angle = (int)(kp * (g - (offsetangle - block + rwallval - lwallval)));
  } else {
    if (side == 1) {
      angle = (int)(kp * (g - (offsetangle - block - lwallval)));
    } else {
      angle = (int)(kp * (g - (offsetangle - block + rwallval)));
    }
  }
  int pos = 95 - angle;
  pos = constrain(pos, 65, 115);
  myservo.write(pos);
  motor.run_motor(1, 56);
}

void rforwardwall(float g, int d) {  // what is r forward? write some comment about it.
  float wallval = 0.3 * (d - 100);
  angle = int(0.8 * (g - (offsetangle + wallval)));
  int pos = 95 - angle;
  myservo.write(pos);
  motor.run_motor(1, 60);
}

void lforwardwall(float g, int d) {
  float wallval = 0.3 * (d - 100);
  angle = int(0.8 * (g - (offsetangle - wallval)));
  int pos = 95 - angle;
  myservo.write(pos);
  motor.run_motor(1, 60);
}

void wheel_pulse() {
  // Optional encoder logic if needed

  i++;
}
void camread() {
  huskylens.request();
  rw = 0;
  rh = 0;
  ra = 0;
  gw = 0;
  gh = 0;
  ga = 0;
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

        if (result.ID == 1 && result.yCenter > 60) {  //result.yCenter > 50
          rp = true;
          rx = result.xCenter;
          ry = result.yCenter;  // red → turn left
          rw = result.width;
          rh = result.height;
          ra = rx * rh;
          // red = 0.018 * (20 - result.xCenter) * result.yCenter;
          // pillar = false;
          // wallval = false;


        }
        // else {
        //   rp = false;
        //   rx = 0;
        //   ry = 0;
        //   red = 0;
        // }
        else if (result.ID == 2 && result.yCenter > 60) {  //
          gp = true;
          gx = result.xCenter;
          gy = result.yCenter;  // green → turn right
          gw = result.width;
          gh = result.height;
          ga = gw * gh;
          // green = 0.018 * (280 - result.xCenter) * result.yCenter;
          // pillar = false;
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
}


void park() {
  frontdist = constrain(front.readDistance1(), 0, 1200);
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
  // delay(1000);
  motor.run_motor(1, 45);
  target = abs(offsetangle) + 80;
  while (yaw > (target * -1)) {
    gyro.update();
    yaw = gyro.getYaw();
    myservo.write(55);
  }
  motor.stop_motor();
  ///
  offsetangle -= 88;
  ///
  gyro.update();
  yaw = gyro.getYaw();
  frontdist = constrain(front.readDistance1(), 0, 1200);
  while (frontdist > 300) {  //&& abs(offsetangle) - yaw < 20
    gyro.update();
    yaw = gyro.getYaw();
    frontdist = constrain(front.readDistance1(), 0, 1200);
    rightdist = constrain(right.readDistance1(), 0, 1200);  //RIGHT
    rforwardwall(yaw, rightdist);
  }
  motor.stop_motor();
  // delay(1000);
  ////
  motor.run_motor(1, 45);
  target = abs(offsetangle) + 45;
  while (yaw > (target * -1)) {
    gyro.update();
    yaw = gyro.getYaw();
    myservo.write(55);
  }
  motor.stop_motor();

  motor.run_motor(1, 45);
  target = abs(offsetangle) + 9;
  while (yaw < (target * -1)) {
    gyro.update();
    yaw = gyro.getYaw();
    myservo.write(125);
  }
  motor.stop_motor();
  myservo.write(95);
  /////
  i = 0;
  rightdist = constrain(right.readDistance1(), 0, 1200);
  while (rightdist > 200) {
    rightdist = constrain(right.readDistance1(), 0, 1200);  //RIGHT
    gyro.update();
    yaw = gyro.getYaw();
    forward(yaw, 0, 1000, 1000);
  }
  motor.stop_motor();
  /////
  motor.run_motor(1, 55);
  delay(250);
  motor.stop_motor();
  delay(1000);
  motor.run_motor(0, 45);
  target = abs(offsetangle) + 80;
  while (yaw > (target * -1)) {
    gyro.update();
    yaw = gyro.getYaw();
    myservo.write(150);
  }
  motor.stop_motor();
  myservo.write(95);
  motor.run_motor(0, 45);
  delay(200);
  motor.stop_motor();
  ////
  motor.run_motor(0, 45);
  target = abs(offsetangle) + 12;
  while (yaw < (target * -1)) {
    gyro.update();
    yaw = gyro.getYaw();
    myservo.write(40);
  }
  motor.stop_motor();
  myservo.write(95);
  delay(100000000000000);
}





//////////
void park2() {
  frontdist = constrain(front.readDistance1(), 0, 1200);
  while (frontdist > 150) {
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
  motor.run_motor(1, 55);
  target = abs(offsetangle) + 80;
  while (yaw < target) {
    gyro.update();
    yaw = gyro.getYaw();
    myservo.write(135);
  }
  motor.stop_motor();
  ///
  offsetangle += 88;
  ///
  gyro.update();
  yaw = gyro.getYaw();
  frontdist = constrain(front.readDistance1(), 0, 1200);
  while (frontdist > 300) {  //&& abs(offsetangle) - yaw < 20
    gyro.update();
    yaw = gyro.getYaw();
    frontdist = constrain(front.readDistance1(), 0, 1200);
    leftdist = constrain(left.readDistance1(), 0, 1200);  //RIGHT
    lforwardwall(yaw, leftdist);
  }
  motor.stop_motor();
  delay(1000);
  ////
  motor.run_motor(1, 55);
  target = abs(offsetangle) + 45;
  while (yaw < target) {
    gyro.update();
    yaw = gyro.getYaw();
    myservo.write(140);
  }
  motor.stop_motor();

  motor.run_motor(1, 55);

  target = abs(offsetangle);
  while (yaw > target) {
    gyro.update();
    yaw = gyro.getYaw();
    myservo.write(65);
  }
  motor.stop_motor();
  myservo.write(95);
  /////
  i = 0;
  leftdist = constrain(left.readDistance1(), 0, 1200);
  while (leftdist > 200) {
    leftdist = constrain(left.readDistance1(), 0, 1200);  //RIGHT
    gyro.update();
    yaw = gyro.getYaw();
    forward(yaw, 0, 1000, 1000);
  }
  motor.stop_motor();
  /////
  motor.run_motor(1, 55);
  delay(300);
  motor.stop_motor();
  delay(1000);
  motor.run_motor(0, 45);
  target = abs(offsetangle) + 80;
  while (yaw < target) {
    gyro.update();
    yaw = gyro.getYaw();
    myservo.write(40);
  }
  motor.stop_motor();
  myservo.write(95);
  motor.run_motor(0, 55);
  delay(200);
  motor.stop_motor();
  ////
  motor.run_motor(0, 45);
  target = abs(offsetangle) - 5;
  while (yaw > target) {
    gyro.update();
    yaw = gyro.getYaw();
    myservo.write(135);
  }
  motor.stop_motor();
  myservo.write(95);
  delay(100000000000000);
}