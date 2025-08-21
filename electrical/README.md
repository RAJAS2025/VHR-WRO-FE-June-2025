
Electrical
====

This directory consists of schematic diagrams demonstrating the connections between different components as well as datasheets for the components. It also consists of the reasoning behind the choice of components.

## Parts Explanation

| Part Name | Explanation | Image | Datasheet |
| ----------- | ----------- | ----------- | ----------- |
| NiMH Battery Packs | We use two 6-volt NiMH (Nickel-Metal Hydride) battery packs to power all our electronics, providing enough current to run the robot for longer periods without performance drops. These rechargeable packs save time and cost by removing the need to replace batteries after every use. Each battery pack measures 7.2 cm × 5 cm × 1.5 cm, making them compact enough to fit neatly inside the robot’s chassis while keeping the weight balanced. |<img src="https://drive.google.com/uc?id=1_7wnMNgIy24hCdx4dEVy9Ar747YReUGw" width="20000">| [Battery Info]()|
| VL53L0X V2 Distance Sensors | The VL53L0X V2 laser-based time-of-flight distance sensor is used to help our robot maintain a consistent distance from the wall. It works by emitting a laser pulse and measuring the time it takes for the light to reflect back, providing precise distance readings regardless of surface color or reflectivity. In our implementation, if the robot gets too close to the wall, it steers away, and if it moves too far, it steers back toward the wall. This continuous feedback ensures smooth navigation and stable alignment throughout the robot’s movement. |![image](https://drive.google.com/uc?id=1NXoMHVktarTHrdZuAl4HXU65G1BZpMTT) | |
| ESP32 | The ESP32 microcontroller serves as the central processing unit of our robot, coordinating inputs from sensors and executing control logic. Programmed through the Arduino framework, it processes data from the HuskyLens and VL53L0X V2 sensors, interprets the robot’s environment, and adjusts motor outputs accordingly. This allows the robot to make real-time decisions for navigation and task execution with both speed and reliability. |![image](https://drive.google.com/uc?id=16JG7iEVeS1MaPWzfHZvTljShi8YVHX4t) | | |
| 24mm Brushless DC Gear Motor – 6V 175RPM | The 24mm brushless DC gear motor provides the driving force for our robot, offering a balance of speed and torque for reliable movement. Operating at 6V with a rated speed of 175 RPM and a stall torque greater than 1.7 kg·cm, it ensures smooth and efficient motion while maintaining precise control during maneuvers. In our project, these motors are used to drive the wheels, enabling the robot to respond accurately to sensor inputs and execute navigation tasks such as obstacle avoidance and parallel parking. |![image](https://drive.google.com/uc?id=1zPMkLOjHfUfX1sFINI6UgpPYMk2pBiHa)| | Miuzei MG90S 9G Micro Servo Motor (Metal Geared) | The Miuzei MG90S 9G micro servo motor is used as the steering mechanism of our robot, providing precise angular control to adjust wheel direction. Its metal gear construction delivers durability and higher torque compared to plastic gear servos, ensuring reliable performance under continuous operation. In our project, the servo enables accurate steering adjustments based on sensor inputs, allowing the robot to smoothly navigate around obstacles and maintain alignment during tasks such as parallel parking. |![image](https://drive.google.com/ucid=1aYvre_sVUZGKTDKNbWgepDsQf0Z53Tcc) |

| MPU-6050 3-Axis Accelerometer & Gyroscope | We use an MPU-6050 3-Axis Accelerometer & Gyroscope to monitor our robot’s orientation, providing real-time data on yaw, pitch, and roll. The robot primarily uses the yaw axis to determine its heading and maintain accurate directional control. To ensure precision, the gyro is calibrated before use, and an offset value is initialized at 0 as the robot’s starting reference angle. Each time the robot needs to turn 90 degrees, we adjust the offset by adding or subtracting 90 depending on whether the turn is to the left or right. This allows the robot to consistently track its orientation relative to its starting position. | ![image](https://drive.google.com/uc?id=1YB_kWYPEaFlx49eQdC9Qf1M95aLCoaWm) | [Gyro Info](https://www.elecrow.com/download/L3G4200_AN3393.pdf) |
| HuskyLens | The HuskyLens AI vision sensor, powered by a Kendryte K210 processor, is used for color recognition in our project. We train it to detect red and green blocks for obstacle navigation and pink blocks as markers for parallel parking. The sensor provides the x and y coordinates of the detected objects, which we integrate directly into our code to guide the robot’s movements. This allows the robot to not only avoid collisions but also accurately exit and re-enter parallel parking, demonstrating how we leverage color recognition and positional data for reliable navigation and task-specific maneuvers.| ![image](https://drive.google.com/uc?id=1YfXz-XhAxRQu1AgmiXbnKuT8Nj0EGX9x) | [HuskyLens Info](https://docs.pixycam.com/wiki/doku.php?id=wiki:v2:start) |

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

