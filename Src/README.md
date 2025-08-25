Source Code Documentation
==== 

This directory contains all of the software needed to operate our robot. It explains the programming language, tools, organization, and functionality of the code that drives and integrates our sensors, actuators, and control systems.

## Software and Language
Our robot is programmed using the Arduino IDE with code written for the ESP32 microcontroller. The programming is done in C++, with libraries that interface directly with our hardware components. Compiling and uploading the code is a simple process using the Arduino IDE’s Verify and Upload buttons, which automatically compile the code and flash it to the ESP32.

## Libraries Used

The following libraries are utilized to interface with our robot’s electronics:
SMotor.h – Controls the DC motor driver for robot movement.


ESP32Servo.h – Used for steering control through a servo motor.


ZebraTOF.h – Interfaces with the Time-of-Flight (ToF) distance sensors for precise ranging.


ZebraGyro.h – Interfaces with the gyroscope for angular velocity and orientation measurement.


Wire.h – Provides I2C communication for sensor connections.


HUSKYLENS.h – Interfaces with the HuskyLens AI vision sensor for color/obstacle detection.

## Organization of Code

Our code is structured into initialization, setup, and control logic, following Object-Oriented Programming (OOP) conventions wherever possible. Sensors and actuators are abstracted into class instances for modularity.
The program is split into two main sections:
Setup() – Initializes all hardware, calibrates sensors, configures communication protocols, and waits for the start signal via the button.


Loop() – Contains the continuous control logic for navigation, obstacle avoidance, wall following, and object interaction.

## Key Components

Motor Control (SMotor Class)
  Controls the DC driving motor using the run_motor and stop_motor functions.


  Uses PWM signals to regulate motor speed.


  Example: motor.run_motor(1, 55); drives the robot forward at speed 55.

## Servo Steering (ESP32Servo)

A servo motor mounted on the front provides steering.


Controlled via PWM using myservo.write(angle).


Range is approximately 45° (left) to 135° (right) with 95° as straight alignment.


## Distance Sensors (ZebraTOF)

Three Time-of-Flight (ToF) sensors:


Front sensor (collision avoidance, forward distance).


Left sensor (used for wall following).


Right sensor (used for wall following).


Example usage:

` int frontdist = front.readDistance1(); `
`rightdist = constrain(right.readDistance1(), 0, 1200);`
`leftdist = constrain(left.readDistance1(), 0, 1200);'`

## Gyroscope (ZebraGyro)

Provides yaw angle feedback for heading correction.


Used for gyro-based turning and to maintain straight-line movement.


Example:

`gyro.update();`
`yaw = gyro.getYaw();`

## Camera (HuskyLens AI Vision Sensor)

Detects colored objects (red, green, pink, blue, orange).


Communicates over UART (TX/RX pins on ESP32).


Provides bounding box data `(x, y, width, height, area)` for detected objects.


Used for color-based navigation and obstacle identification.

## Navigation and Control Logic
Startup Phase


Robot initializes sensors and waits for the start button press.


Determines initial side (left/right wall) based on ToF distance readings.


Gyro-Based Turning


Uses gyroscope readings to rotate precisely to target angles.


Example:

 `while (yaw > (target * -1)) {
    gyro.update();
    yaw = gyro.getYaw();
    myservo.write(45);
}`


Wall Following


Uses ToF sensors to maintain a safe distance from walls.


Steering corrections are applied proportionally:

 `err = 20.0 - rightdist;
steer = err * -2.0;`


Object Detection & Color Following


The HuskyLens detects color markers (red/green/pink) to guide navigation.


Depending on detected color, the robot adjusts target_x and recalculates steering offset.


Obstacle Avoidance


If front distance is too small, the robot backs up and turns away.


If objects block the side, the robot makes corrective steering maneuvers.


Parking & Completion


After a set number of detections (count >= 12), the robot executes a parking routine using gyro and ToF feedback.


## Global Variables

Some of the key global variables in the code:

| Variable Name | Type | Purpose |
| ------------- | ---- | ------- |
| yaw | float | Stores gyro yaw angle |
| frontdist, leftdist, rightdist | int | Stores ToF distance readings |
| target_X | int | Target x-position of detected object (for steering) |
| count | int | Counts laps based of each 90 degree turn |
| side | int | Defines direction (1 = counter-clockwise, 2 = clockwise) |
| red, green, pink | float | Stores weighted values from HuskyLens detections |
| pillar | bool | Flags pillar detection |  
| distance | bool | Used for proportional distance-based control |  

## Example: Forward Movement with Gyro Correction

`gyro.update();
yaw = gyro.getYaw();
rightdist = constrain(right.readDistance1(), 0, 1200);
leftdist = constrain(left.readDistance1(), 0, 1200);
forward(yaw, target_x, rightdist, leftdist);
`
This ensures that the robot drives forward while correcting its heading using the gyroscope and wall distances.

















