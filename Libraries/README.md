# Libraries we made

We developed custom libraries for both the gyro and time-of-flight sensors, and tested them on our custom-designed PCB, which was built to support all possible functions required in both the qualifying and obstacle challenge rounds. The remaining libraries, such as ESP32 Servo and HuskyLens, were sourced externally, uploaded to our project folder, and included in our main code.

## ZebraGyro Library

The **ZebraGyro** library provides a simple interface for working with the MPU-6050/MPU-9150 gyroscope/accelerometer when the DMP (Digital Motion Processor) is enabled. It handles initialization, calibration, continuous yaw tracking, and supports I²C multiplexers such as the TCA9548A.

This library is designed for robotics, navigation, and motion tracking applications where accurate heading (yaw) data is important.

### Features

- I²C multiplexer (TCA9548A) support for multiple sensors  
- Initializes and calibrates the MPU with DMP enabled  
- Interrupt-driven FIFO packet handling  
- Continuous yaw tracking without wrapping issues at -180°/+180°  
- Provides yaw in degrees for easier interpretation  
- Reset yaw offset at runtime  

### How It Works

1. `selectPort()` → Selects which I²C multiplexer port is active.  
2. `begin()` → Sets up the MPU, applies offsets, calibrates sensors, and enables the DMP.  
3. `update()` → Reads the latest sensor packet and updates yaw tracking.  
4. `getYaw()` → Returns the current yaw angle in degrees.  
5. `resetYaw()` → Resets the yaw offset so current angle becomes zero.
    
Yaw is tracked continuously by calculating quaternion output from the DMP. This allows full 360°+ rotation accumulation without resetting at ±180°.  

## ZebraTOF Library

The **ZebraTOF** library provides an easy way to interface multiple VL53L0X Time-of-Flight (ToF) distance sensors through an I²C multiplexer such as the TCA9548A. It manages port selection, initialization, and distance averaging to provide stable readings from multiple sensors.

This is useful for robotics, obstacle avoidance, and multi-sensor distance measurement setups.

### Features

- Supports I²C multiplexers (TCA9548A)  
- Initializes and manages **VL53L0X** ToF sensors  
- Provides raw single readings and averaged distance readings  
- Handles invalid measurements gracefully by returning a max distance (8000 mm)  

### How It Works

1. `selectPort()` → Chooses which I²C multiplexer channel is active.  
2. `begin()` → Initializes the VL53L0X sensor on the chosen port. Prints errors if setup fails.  
3. `readDistance1()` → Returns the latest single measurement (in millimeters). If invalid, returns `8000`.  
4. `readDistance()` → Reads multiple samples (default 6) and averages them to reduce noise.  



