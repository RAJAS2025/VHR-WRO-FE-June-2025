#ifndef ZebraGyro_h
#define ZebraGyro_h

#include "Arduino.h"
#include "Wire.h"
#include "I2Cdev.h"
#include "MPU6050_6Axis_MotionApps20.h"

class ZebraGyro {
public:
  ZebraGyro(uint8_t port = 0, uint8_t interruptPin = 2); 
  void begin();
  void update();
  float getYaw();       // Returns continuous yaw in degrees
  void resetYaw();      // Resets the yaw reading to zero

private:
  void selectPort();

  uint8_t _port;
  uint8_t _interruptPin;
  bool _dmpReady;
  uint8_t _mpuIntStatus;
  uint8_t _devStatus;
  uint16_t _packetSize;
  uint8_t _fifoBuffer[64];

  float _lastYaw;
  float _continuousYaw;
  float _yawOffset;

  MPU6050 _mpu;
  Quaternion _q;
  VectorFloat _gravity;
  float _ypr[3];

  static volatile bool _mpuInterrupt;
  static void dmpDataReady();
};

#endif
