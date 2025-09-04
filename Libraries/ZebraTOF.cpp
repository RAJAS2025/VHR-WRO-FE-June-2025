#include "ZebraTOF.h"

ZebraTOF::ZebraTOF(uint8_t port) {
  _port = port;
}

void ZebraTOF::selectPort() {
  Wire.beginTransmission(0x70); // TCA9548A default address
  Wire.write(1 << _port);
  Wire.endTransmission();
}

void ZebraTOF::begin() {
  selectPort();
  if (!_lox.begin()) {
    Serial.print("Failed to initialize VL53L0X on port ");
    Serial.println(_port);
    while (1);
  }
  Serial.print("VL53L0X initialized on port ");
  Serial.println(_port);
}

int ZebraTOF::readDistance1() {
  selectPort();
  VL53L0X_RangingMeasurementData_t measure;
  _lox.rangingTest(&measure, false);
  if (measure.RangeStatus != 4) {
    return measure.RangeMilliMeter;
  } else {
    return 8000; // Invalid reading
  }
}

int ZebraTOF::readDistance() {
  long sum = 0;
  for (int i = 0; i < 6; i++) {
    sum += readDistance1();
    // delay(1);  
  }
  return sum / 6;
}
