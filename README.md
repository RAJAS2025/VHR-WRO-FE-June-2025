<center><h1> Team VHR 2025 </center>

This repository contains the documentation for Team VHR robot for the 2025 World Robot Olympiad Future Engineers competition.


## The Team <a class="anchor"></a>

### Harshad Mahajan

<b>Age:</b> 15

<b>High School:</b> John Fraser Secondary School

<b>Description:</b> Hi! I’m Harshad. This is my first season in WRO. Last year I took part in the Zone_01 category, and this year I wanted to challenge myself with something new. I’m interested in coding, building robots, and exploring creative ideas. I also enjoy sports and traveling.

---

### Vishnu Jayakumar

<b>Age:</b> 15

<b>High School:</b> John Fraser Secondary School

<b>Description:</b> Hello! I’m Vishnu. This is my third season in WRO and my first time competing in the Future Engineers category, after two seasons in WRO Junior. I’m passionate about robotics, electronics, and exploring new technologies, but I also enjoy basketball, math, and spending time with friends.

---

### Rajas Salunke

<b>Age:</b> 16

<b>High School:</b> Fletchers Meadows Secondary School

<b>Description:</b> Hello! I’m Rajas Salunke. This is my second season in WRO and my first in the Future Engineers category, after previously competing in WRO Junior. I’m passionate about building circuits and rockets, and I also enjoy hockey and calisthenics.

---

### Team photo
<img src="https://drive.google.com/uc?id=1DvdrtPkqM7Knqy3OlnnTlUUaTfWU8p-L" width="40%"/>  <img src="https://drive.google.com/uc?id=1Naz8VsuH2fz2HpzyK-oHjj93q9z5KsKU" width="40%"/>

## The Challenge <a class="anchor" id="challenge"></a>

The **[WRO 2025 Future Engineers](https://wro-association.org/)** challenge is all about building an autonomous car that can adapt to a racetrack which changes every round. Instead of just speed, the focus is on control and problem-solving: the car needs to handle obstacles placed at random and also pull off a precise parallel park. It’s a mix of engineering and strategy, where teams combine sensors, algorithms, and creative design to make their car both smart and reliable.

This challenge emphasizes all aspects of the engineering process, including:
- **Movement:** Designing the vehicle to move efficiently and smoothly.
- **Obstacle Navigation:** Programming the car to detect and handle traffic markers within the rules.les.
- **Documentation:** Recording design decisions, progress, and collaborative work in a public GitHub repository.

Points are awarded based on how well teams perform in the challenge rounds, the thoroughness of their engineering documentation, and the creativity and reliability of their solutions. The aim is to inspire learning in STEM through hands-on robotics, collaborative teamwork, and inventive problem-solving.

To learn more about the challenge, click [here](https://wro-association.org/wp-content/uploads/WRO-2025-Future-Engineers-Self-Driving-Cars-General-Rules.pdf).

---

## Strategy <a class="anchor"></a>

### Open Challenge

In the open challenge, the only modification to the mat is the size of the interior walls. To handle this, we will use distance sensors to measure the robot’s distance from the walls. With multiple sensors positioned around the robot, it can accurately determine its position relative to the surroundings and make adjustments to stay parallel to the walls. A front-facing sensor will help the robot know when to turn—once the distance to the wall falls below a set threshold, it will initiate a turn. We will also track laps by counting each completed turn, allowing the robot to know when the course is finished.

| Straight Movement | Turning |
| ----------------- | ------- |
| ![image](https://drive.google.com/uc?id=1DB79bmORLYsZtvS3ZY7Et7zxQinYhLz2) | ![image](https://drive.google.com/uc?id=10EQ50uIVgxQVyQ04zlm_7qe28uHlypXn) |

| Open Challenge Flowchart |
| ------------------------ |
| ![image](https://drive.google.com/uc?id=1ebbFPcefdsMD9-E0WnutMVh5yYC2ZdSq) |

 ### Obstacle Challenge

In the obstacle challenge, our approach focuses on maintaining precise control while navigating the dynamic course. We plan to use gyro-based line following to keep the robot moving straight along the track, while wall safety distance sensors prevent collisions if the robot gets too close to the walls. When a block is detected, the robot will decelerate to maneuver around it, using an algorithm that continues turning until the obstacle is fully passed and the robot has reached the target x coordinate, then accelerates again once the path is clear. For turns, the robot uses a camera system to detect the blue and orange lines on the mat, allowing accurate and consistent adjustments. This strategy combines speed, precision, and adaptability to handle obstacles effectively while staying on course. Just like the open challenge, we track laps by counting each completed turn, allowing the robot to know when the course is finished.

| 1 Block Movement | 2 Block Movement|
| ----------------- | ------- |
| ![image](https://drive.google.com/uc?id=1o8-S4fOHuvVPILtzNyMyq0V-x_8KhPgD) | ![image](https://drive.google.com/uc?id=1D9FqWyBBqiH5tIUv-c189Mm-1k3GZKxQ) |


<br>

# Hardware <a class="anchor"></a>

| Part Name | Explanation | Image | Datasheet |
| ----------- | ----------- | ----------- | ----------- |
| NiMH Battery Packs | We use two 6-volt NiMH (Nickel-Metal Hydride) battery packs to power all our electronics, providing enough current to run the robot for longer periods without performance drops. These rechargeable packs save time and cost by removing the need to replace batteries after every use. Each battery pack measures 7.2 cm × 5 cm × 1.5 cm, making them compact enough to fit neatly inside the robot’s chassis while keeping the weight balanced. |<img src="https://drive.google.com/uc?id=1_7wnMNgIy24hCdx4dEVy9Ar747YReUGw" width="20000">| [Battery Info](https://drive.google.com/file/d/1VK_VsjF3aPhSJzILikrdEzxNDgZSIByU/view?usp=drive_link)| 
| VL53L0X V2 Distance Sensors | The VL53L0X V2 laser-based time-of-flight distance sensor is used to help our robot maintain a consistent distance from the wall. It works by emitting a laser pulse and measuring the time it takes for the light to reflect back, providing precise distance readings regardless of surface color or reflectivity. In our implementation, if the robot gets too close to the wall, it steers away, and if it moves too far, it steers back toward the wall. This continuous feedback ensures smooth navigation and stable alignment throughout the robot’s movement. |![image](https://drive.google.com/uc?id=1NXoMHVktarTHrdZuAl4HXU65G1BZpMTT) | [Distance Sensors Data Sheet](https://www.st.com/resource/en/datasheet/vl53l0x.pdf) |
| ESP32 | The ESP32 microcontroller serves as the central processing unit of our robot, coordinating inputs from sensors and executing control logic. Programmed through the Arduino framework, it processes data from the HuskyLens and VL53L0X V2 sensors, interprets the robot’s environment, and adjusts motor outputs accordingly. This allows the robot to make real-time decisions for navigation and task execution with both speed and reliability. |![image](https://drive.google.com/uc?id=16JG7iEVeS1MaPWzfHZvTljShi8YVHX4t)|[ESP32 Data Sheet](https://www.espressif.com/sites/default/files/documentation/esp32-wroom-32_datasheet_en.pdf) | 
| 24mm Brushless DC Gear Motor – 6V 175RPM | The 24mm brushless DC gear motor provides the driving force for our robot, offering a balance of speed and torque for reliable movement. Operating at 6V with a rated speed of 175 RPM and a stall torque greater than 1.7 kg·cm, it ensures smooth and efficient motion while maintaining precise control during maneuvers. In our project, these motors are used to drive the wheels, enabling the robot to respond accurately to sensor inputs and execute navigation tasks such as obstacle avoidance and parallel parking. |![image](https://drive.google.com/uc?id=1zPMkLOjHfUfX1sFINI6UgpPYMk2pBiHa)| [DC Motor Specs](https://drive.google.com/file/d/1moiPKcTiO8_0Bga1mJdIX5mgfcUgAj7J/view?usp=drive_link) | 
| Miuzei MG90S 9G Micro Servo Motor | The Miuzei MG90S 9G micro servo motor is used as the steering mechanism of our robot, providing precise angular control to adjust wheel direction. Its metal gear construction delivers durability and higher torque compared to plastic gear servos, ensuring reliable performance under continuous operation. In our project, the servo enables accurate steering adjustments based on sensor inputs, allowing the robot to smoothly navigate around obstacles and maintain alignment during tasks such as parallel parking. | ![image](https://drive.google.com/uc?id=11jJfRISsUBbroW9buTjq_ObbzrjjaPJ_) |[Servo Motor Specs](https://drive.google.com/file/d/1ZQCr9s1xJsN8NOYWgczae_1dq8hoC7bo/view?usp=drive_link)|
| MPU-6050 3-Axis Accelerometer & Gyroscope | We use an MPU-6050 3-Axis Accelerometer & Gyroscope to monitor our robot’s orientation, providing real-time data on yaw, pitch, and roll. The robot primarily uses the yaw axis to determine its heading and maintain accurate directional control. To ensure precision, the gyro is calibrated before use, and an offset value is initialized at 0 as the robot’s starting reference angle. Each time the robot needs to turn 90 degrees, we adjust the offset by adding or subtracting 90 depending on whether the turn is to the left or right. This allows the robot to consistently track its orientation relative to its starting position. | ![image](https://drive.google.com/uc?id=1YB_kWYPEaFlx49eQdC9Qf1M95aLCoaWm) | [Gyro Info](https://invensense.tdk.com/wp-content/uploads/2015/02/MPU-6000-Datasheet1.pdf) |
| HuskyLens | The HuskyLens AI vision sensor, powered by a Kendryte K210 processor, is used for color recognition in our project. We train it to detect red and green blocks for obstacle navigation and pink blocks as markers for parallel parking. The sensor provides the x and y coordinates of the detected objects, which we integrate directly into our code to guide the robot’s movements. This allows the robot to not only avoid collisions but also accurately exit and re-enter parallel parking, demonstrating how we leverage color recognition and positional data for reliable navigation and task-specific maneuvers.| ![image](https://drive.google.com/uc?id=1YfXz-XhAxRQu1AgmiXbnKuT8Nj0EGX9x) | [HuskyLens Info](https://wiki.dfrobot.com/HUSKYLENS_V1.0_SKU_SEN0305_SEN0336) |

## Parts Bill Of Materials (BOM)
| Part Name | Quantity |
| ----------| -------- |
| NiMH Battery Packs | 2 |
| VL53L0X V2 Distance Sensors | 3 |
| ESP32 | 1 |
| 24mm Brushless DC Gear Motor – 6V 175RPM | 1 |
| Miuzei MG90S 9G Micro Servo Motor | 1 |
| MPU-6050 3-Axis Accelerometer & Gyroscope | 1 |
| HuskyLens | 1 |

---

# Mobility Management <a class="anchor"></a>

This directory contains all the custom 3D models used for our robot. The chassis is a fully optimized, super small design with sharp servo steering, while additional sensor mounts were created in Tinkercad. The rear assembly is adapted to work with LEGO wheels, axles, and a reinforced differential. Below is a table of our 3D-printed parts and their functions. (The iterations of the robot, how all the electrical components and 3d models fit with robot and the purpose and optimization of each piece will be described in BUILD)

| Parts Name | Description | Image |
| ----------- | ----------- | ----------- |
| Chassis | The chassis is a fully optimized, custom-designed base modeled in SolidWorks for a compact structure with sharp servo steering. It houses the drivetrain, electronics, and reinforced LEGO differential, forming the core of the robot. For details on iterations, component placement, and assembly, see the build documentation. | ![image](https://drive.google.com/uc?id=1Xr69AL12gRIF-5ft7Ylq5KtJu0QJ6xsf) |
| Spur Gear| To transfer power from the 6V motors to the modified LEGO differential, we designed and 3D-printed a 36-tooth gear that fits the motor’s 3mm D-shaped shaft and meshes with the LEGO axle system. Using a 36-tooth input gear with a 24-tooth output gear, we geared it for higher speed because the motor has a low RPM and high torque. | ![image](https://drive.google.com/uc?id=15A_ULyuqfeW1OqZAiTphIvPfeZAlDUrT) |
| Differential Gear | The LEGO differential was imported from an online CAD model into SolidWorks, then slightly reinforced by adding extra material around the mounting holes and adapted to fit our custom chassis. These modifications improve durability while maintaining smooth power transfer to the wheels under high-torque operation. | ![image](https://drive.google.com/uc?id=1qzpYpQRpw_0YeEP1o6rX9YchPsRdpLrL) |
| Steering Connecting Bar | The steering connecting bar is a compact, custom-designed link optimized for the sharp servo steering system of the WRO Future Engineers self-driving car. Modeled in SolidWorks, it features recessed screw inlets that improve grip and durability, ensuring a secure fit while transferring motion smoothly between steering components. Its minimal, lightweight design makes it both efficient and reliable under high steering loads. | ![image](https://drive.google.com/uc?id=1eNLU3cQQbzHstJQHPj6PBz5TVGXz-ltt) |
| Distance Sensor Holder | A custom-made, imported 4M LEGO beam is combined with a secure holder, modeled in TinkerCAD to keep the TOF sensor rigid and immovable. The holder eliminates any shifting or vibration, ensuring consistent and accurate sensor readings. Its LEGO integration allows for straightforward attachment to the structure while maintaining a locked, stable position. | ![image](https://drive.google.com/uc?id=1M6zluK-iLSjezei6UIyS69u5_PhCzkHq) |

---

# Schematics <a class="anchor"></a>

