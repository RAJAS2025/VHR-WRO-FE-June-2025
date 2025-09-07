#ifndef ZebraTOF_h
#define ZebraTOF_h

#include "Arduino.h"
#include "Wire.h"
#include "Adafruit_VL53L0X.h"

class ZebraTOF {
public:
  ZebraTOF(uint8_t port);
  void begin();
  int readDistance1();
  int readDistance();

private:
  void selectPort();
  uint8_t _port;
  Adafruit_VL53L0X _lox;
};

#endif
