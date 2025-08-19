
Electrical
====

This directory consists of schematic diagrams demonstrating the connections between different components as well as datasheets for the components. It also consists of the reasoning behind the choice of components.

## Parts Explanation

| Part Name | Explanation | Image | Datasheet |
| ----------- | ----------- | ----------- | ----------- |
| NiMH Battery Packs | We use two 6-volt NiMH (Nickel-Metal Hydride) battery packs to power all our electronics, providing enough current to run the robot for longer periods without performance drops. These rechargeable packs save time and cost by removing the need to replace batteries after every use. Each battery pack measures 7.2 cm × 5 cm × 1.5 cm, making them compact enough to fit neatly inside the robot’s chassis while keeping the weight balanced. | ![image](https://drive.google.com/uc?id=1_7wnMNgIy24hCdx4dEVy9Ar747YReUGw)| [Battery Info] ([https://drive.google.com/file/d/1VK_VsjF3aPhSJzILikrdEzxNDgZSIByU/view?usp=drive_link])|
| | | | |
| | | | |
| | | | |
| | | | |
| | | | |
| | | | |
| | | | |
| | | | |
| MPU-6050 3-Axis Accelerometer & Gyroscope | We use an MPU-6050 3-Axis Accelerometer & Gyroscope to monitor our robot’s orientation, providing real-time data on yaw, pitch, and roll. The robot primarily uses the yaw axis to determine its heading and maintain accurate directional control. To ensure precision, the gyro is calibrated before use, and an offset value is initialized at 0 as the robot’s starting reference angle. Each time the robot needs to turn 90 degrees, we adjust the offset by adding or subtracting 90 depending on whether the turn is to the left or right. This allows the robot to consistently track its orientation relative to its starting position. | ![image](https://drive.google.com/uc?id=1YB_kWYPEaFlx49eQdC9Qf1M95aLCoaWm) | [Gyro Info](https://www.elecrow.com/download/L3G4200_AN3393.pdf) |
| PixyCam Pixy 2.1 Robot Vision Image Sensor | Since the Arduino Nano does not have enough computing power to process images, we are outsourcing the processing to the Pixy 2.1. This camera is able to provide the microcontroller with the necessary information to plan an appropriate path for the robot to take. | ![image](https://drive.google.com/uc?id=1V1Nqks-wj--PqYVI9ksZawQXJftz3UOQ) | [Pixy 2.1 Info](https://docs.pixycam.com/wiki/doku.php?id=wiki:v2:start) |

## Parts Bill Of Materials (BOM)
| Part Name | Quantity |
| ----------| -------- |
| 1.5V Rechargeable Lithium Ion Battery | 4 |
| DC 6V Micro Gear Box Speed Reduction Motor, 300RPM | 2 |
| CJMCU34725 TCS34725 RGB Light Color Sensor | 1 |
| Arduino Nano | 1 |
| ES08MA Metal Analog Servo | 1 |
| GP2Y0A02YK0F IR Range Sensor | 3 |
| GP2Y0A41SK0F IR Range Sensor | 2 |
| HW-201 IR Sensor | 1 |
| L298N Dual H-Bridge Motor Driver | 1 |
| L3G4200D Triple Axis Gyro Angular Velocity Sensor Module | 1 |
| PixyCam Pixy 2.1 Robot Vision Image Sensor | 1 |

