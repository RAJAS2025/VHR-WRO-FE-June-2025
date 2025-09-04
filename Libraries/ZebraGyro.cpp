#include "ZebraGyro.h"

volatile bool ZebraGyro::_mpuInterrupt = false;

ZebraGyro::ZebraGyro(uint8_t port, uint8_t interruptPin)
  : _port(port), _interruptPin(interruptPin), _dmpReady(false),
    _lastYaw(0), _continuousYaw(0), _yawOffset(0) {}

void ZebraGyro::dmpDataReady() {
  _mpuInterrupt = true;
}

void ZebraGyro::selectPort() {
  Wire.beginTransmission(0x70);
  Wire.write(1 << _port);
  Wire.endTransmission();
}

void ZebraGyro::begin() {
  selectPort();

  Wire.begin();
  Wire.setClock(400000);
  _mpu.initialize();
  pinMode(_interruptPin, INPUT);

  _devStatus = _mpu.dmpInitialize();

  _mpu.setXGyroOffset(220);
  _mpu.setYGyroOffset(76);
  _mpu.setZGyroOffset(-85);
  _mpu.setZAccelOffset(1788);

  if (_devStatus == 0) {
    _mpu.CalibrateAccel(6);
    _mpu.CalibrateGyro(6);
    _mpu.setDMPEnabled(true);

    attachInterrupt(digitalPinToInterrupt(_interruptPin), dmpDataReady, RISING);
    _mpuIntStatus = _mpu.getIntStatus();

    _dmpReady = true;
    _packetSize = _mpu.dmpGetFIFOPacketSize();
  } else {
    Serial.print("DMP init failed. Code: ");
    Serial.println(_devStatus);
  }
}

void ZebraGyro::update() {
  selectPort();

  if (!_dmpReady) return;

  if (_mpu.dmpGetCurrentFIFOPacket(_fifoBuffer)) {
    _mpu.dmpGetQuaternion(&_q, _fifoBuffer);
    _mpu.dmpGetGravity(&_gravity, &_q);
    _mpu.dmpGetYawPitchRoll(_ypr, &_q, &_gravity);

    float currentYaw = _ypr[0];
    float deltaYaw = currentYaw - _lastYaw;

    if (deltaYaw > M_PI) deltaYaw -= 2 * M_PI;
    else if (deltaYaw < -M_PI) deltaYaw += 2 * M_PI;

    _continuousYaw += deltaYaw;
    _lastYaw = currentYaw;
  }
}

float ZebraGyro::getYaw() {
  return (_continuousYaw - _yawOffset) * 180.0 / M_PI;
}

void ZebraGyro::resetYaw() {
  _yawOffset = _continuousYaw;
}
