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

## Components

| Part Name | Product | Price |
| ----------- | ----------- | ----------- |
| Battery | [`NiMH Battery Packs`](https://www.amazon.ca/melasta-Controller-Transmitter-Batteries-Rechargeable/dp/B08H1VGPTQ/ref=sr_1_7?dib=eyJ2IjoiMSJ9.6jvflqZLSyioPNMTbi8u2oe0zjAEgO0SVPFmtKSFcVizyx8WJCpY7NcH67l6ZsVLjccSUX8HYYjTynHbsuqijKooCKc_3E3V4i9yGfv1DUzkUEpPnH7BWjww65ARWq3aR8I3X-4wDlUcIDOTiW2SNK2GfzKjpEqyjw2gWkhN3qZLF-YHq3X34O7wB6gIdI6kQjp9vD7B4ZKpChUHuOPTyEezkS0Ww22aKja5_yWcUTZewEimsz45EgEAp40r7HhbXSbVoyv8Z3yoRuE6NEykaONUX4CWj9M31CB7GmyHM8U.VH-fCOSL3T6fqm7b1sa9Ko1dU032TcThg869M1KAW-Q&dib_tag=se&gad_source=1&hvadid=249594509029&hvdev=c&hvexpln=0&hvlocphy=9000820&hvnetw=g&hvocijid=14621881054563641559--&hvqmt=e&hvrand=14621881054563641559&hvtargid=kwd-307540910796&hydadcr=29607_10647357&keywords=nimh+battery+packs&mcid=16df915f92a43ecc8818107c43aee59d&qid=1756174155&sr=8-7) | $26.59 |
| Drive Motor | [`24mm Brushless DC Gear Motor – 6V 175RPM`](https://ca.robotshop.com/products/e-s-motor-24mm-brushless-dc-gear-motor-6v-175rpm?qd=f4e8ef762cd02e5a0efc04a59a1c2b2e) | $17.43 | 
| Servo Motor| [`Miuzei MG90S 9G Micro Servo Motor`](https://www.amazon.ca/Miuzei-MG90S-Servo-Helicopter-Arduino/dp/B0BWJ4RKGV/ref=sr_1_1_sspa?dib=eyJ2IjoiMSJ9.SjyQKb523oHkxGq8PZ33pXReP1_e_7FqP-xfnh4b3jZYwBlFnqYn3YfGZIt1VAZFgdQQPbQ28JjAq5Q_OZ9rJM26C2zVBQ2RIiqlaPzHOVu1u_A26R-ppvWzVuxkWyoYrTyqZXVHsXjhdK6FuN1Q89Ya0LATUSz7Ov6aD9w_EueGaBZmUSwLkKOr6cfwBffRFrB5ZC-irsOd57WjfhrXDH5drSJtA5gYU1mBC3Lkb7-G-CraqkPVl18oWgp0ao1i6DB2GteeZjfId37Kl5zk-1BfClGpkLqgh5kT6wC73CE.60P5bf61P-tOKAz1bI-IDdX9t9Z3JUCbb4ZwwRZxXPE&dib_tag=se&keywords=mg90s%2Bservo&qid=1756174433&sr=8-1-spons&sp_csd=d2lkZ2V0TmFtZT1zcF9hdGY&th=1) | $16.99 (Price of 1: $8.49 |
| Distance Sensors | [`VL53L0X V2 Distance Sensors`](https://www.adafruit.com/product/3317?srsltid=AfmBOoo2bXDFNLP4muxH_TJ6E1TMgPw9tgMk8_leCCFIUnABXe_XegRi) | $14.95 (Price of 3: $44.85 |
| Gyro | [`MPU-6050 3-Axis Accelerometer & Gyroscope: LINK NEEDED`](https://carisma-shop.com/products/gt24-alum-motor-mount) | $TBD |
| Camera | [`Huskylens`](https://ca.robotshop.com/products/gravity-huskylens-ai-machine-vision-sensor-w-silicone-case?gad_source=1&gad_campaignid=20151185247&gbraid=0AAAAAD_f_xxytUT8IaTqhSAT_ir4KZ1jB&gclid=CjwKCAjwk7DFBhBAEiwAeYbJsc7MoTx8vF9xUZmZP27axQPZ4kNTacxE1th6vTxau1L4F4zaG-6MnRoCdAcQAvD_BwE) | $83.43 |

**Total Car Cost: $180.79 CAD**


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

## Mechanical Design

### Chassis

Our chassis is a fully custom-designed base, modeled in SolidWorks to create a compact and efficient structure optimized for sharp servo steering. On top of the chassis, we mounted our PCB, which holds the main electronics and three laser distance sensors—one at the front and one on each side—allowing the robot to sense walls and obstacles accurately. The motor is positioned beneath the PCB in a dedicated motor holder and drives a spur gear that connects to a reinforced LEGO differential, forming a robust drivetrain.

The front steering is designed for sharp, precise turns, giving the robot the ability to navigate tight corners and avoid obstacles efficiently. The chassis layout also ensures that the weight of the sensors and electronics is balanced over the drivetrain, improving stability and traction during high-speed maneuvers.

Potential Chassis Improvements
TO BE ADDED

![image](https://drive.google.com/uc?id=1Xr69AL12gRIF-5ft7Ylq5KtJu0QJ6xsf)

### Spur Gear

To transfer power from the 6V motors to the modified LEGO differential, we designed and 3D-printed a 36-tooth spur gear that fits the motor’s 3mm D-shaped shaft and meshes precisely with the LEGO axle system. Using a 36-tooth input gear paired with a 24-tooth output gear, we geared the drivetrain for higher speed while taking advantage of the motor’s high torque and low RPM. This gear ensures smooth and efficient power transfer, providing consistent wheel rotation even under load.

![image](https://drive.google.com/uc?id=15A_ULyuqfeW1OqZAiTphIvPfeZAlDUrT)

### Differential Gear

The LEGO differential was imported from an online CAD model into SolidWorks and slightly reinforced to improve durability. Extra material was added around the mounting holes, and the differential was adapted to fit our custom chassis. These modifications maintain smooth power transfer to the wheels under high-torque operation, while reducing stress on the mounting points and improving overall reliability during obstacle navigation.

![image](https://drive.google.com/uc?id=1qzpYpQRpw_0YeEP1o6rX9YchPsRdpLrL)

### Steering Connecting Bar

The steering connecting bar is a compact, custom-designed link optimized for our sharp servo steering system. Modeled in SolidWorks, it features recessed screw inlets for better grip and durability, ensuring a secure connection between steering components. Its lightweight design minimizes additional load while transferring motion smoothly, allowing the front wheels to respond precisely to steering commands even during tight turns.

![image](https://drive.google.com/uc?id=1eNLU3cQQbzHstJQHPj6PBz5TVGXz-ltt) 

### Distance Sensor Holder

The distance sensor holder combines a custom-made 4M LEGO beam with a secure TinkerCAD-designed mount to keep the TOF sensor rigid and stable. This eliminates vibration or shifting during operation, ensuring accurate and consistent sensor readings. The LEGO integration allows for easy attachment to the chassis while maintaining a locked position, supporting reliable obstacle detection and wall-following maneuvers.

![image](https://drive.google.com/uc?id=1M6zluK-iLSjezei6UIyS69u5_PhCzkHq)

### Motors

### 24mm Brushless DC Gear Motor
The robot's forward and backward propulsion is provided by a 24mm brushless DC gear motor. This motor was chosen for its ideal balance of high speed and torque. The brushless design makes it highly efficient, durable, and provides a smooth, consistent power delivery. This motor is the core of the drivetrain, ensuring reliable and powerful movement throughout the competition.

![image](https://drive.google.com/uc?id=1zPMkLOjHfUfX1sFINI6UgpPYMk2pBiHa)

### Miuzei MG90S 9G Micro Servo Motor
The robot's steering mechanism is controlled by a Miuzei MG90S 9G Micro Servo Motor. A servo is a specialized motor designed for precise angular control rather than continuous rotation. This particular model was chosen for its metal gear construction, which offers greater durability and higher torque than plastic gear versions. The servo's ability to hold a specific angle is what allows the robot to make precise steering adjustments and navigate tight corners effectively.

![image](https://drive.google.com/uc?id=11jJfRISsUBbroW9buTjq_ObbzrjjaPJ)

### Materials 

When creating our robot, we wanted to be able to easily iterate and update the robot in many ways as we tested it. In order to achieve these goals, we decided to use LEGO Technic pieces to construct the majority of our robot. LEGO technic was the perfect choice for us since our robotics centre, Zebra Robotics, focuses on LEGO robotics and competitions related to that, so we have an abundance of LEGO technic pieces. Our team members also have extensive experience in working with LEGO Technic parts and completing challenges with them. In order to attach the electronic components onto our chassis, we 3D printed mounts for the components, as they allowed us to smoothly integrate the non-LEGO parts with the LEGO parts.

---

# Mobility Management <a class="anchor"></a>

## Drivetrain and Steering
Our robot's drivetrain uses a rear-wheel drive with sharp front-wheel servo steering. We chose this configuration to separate the driving and steering systems, which helped us avoid spacing issues and ensured that the drive motors and steering servo operate independently without interference.

The drivetrain is powered by a 24mm brushless DC gear motor, chosen for its balance of high speed and ample torque. To transfer power from the motor to the wheels, we designed and 3D-printed a 36-tooth spur gear that fits securely onto the motor's shaft. This gear meshes directly with a reinforced LEGO differential, which distributes power to both rear wheels. This specific gear ratio gives our robot the speed needed for the challenges while maintaining the high torque required for smooth turns and accelerations. This simple, efficient, and reliable configuration is well-suited for our competition needs, and it provides several advantages:

- **Better torque transfer** through the reinforced LEGO differential.  
- **Greater stability** under load, as the weight of the robot is more evenly distributed over the rear drive wheels.  
- **Improved maneuverability**, since steering and driving forces are separated between the front and rear axles.  
- **Familiar control response**, matching our previous experience with other rear-driven LEGO robots.

This design results in a simple, efficient, and reliable drivetrain well-suited for our competition needs.

| Rear-Wheel Drive | Front Wheel Drive |
| ---------------- | ----------------- |
| ![image](https://drive.google.com/uc?id=1Jf-CvguoRfaVFCoVMNndH-xFYlsa_ZU-) | ![image](https://drive.google.com/uc?id=1VLR8ZvrXIQMaj_SNlWJ1fxSpYCzsmNQD) |


## Steering

Our steering mechanism is a four-bar linkage, with free-spinning wheels mounted on it. This system proved to be the most efficient and easiest to implement for our purposes, as it only required a servo motor and a simple rig to connect it to the wheel axles. The servo motor moves the four-bar, which changes the angle of the wheels and, in turn, the direction of the vehicle.

Steering is managed by a Miuzei MG90S micro servo motor, which provides precise angular control. The rig that connects the servo to the wheel axles was 3D-printed as a single piece along with the servo mount. It features a LEGO axle-shaped cross hole that rotates with the servo, ensuring a secure connection. The lightweight and durable design of this part ensures the front wheels respond quickly and accurately to the servo's commands, allowing our robot to execute the sharp turns necessary for navigating obstacles and completing tasks.

| Four-Bar Steering Mechanism |
| --------------------------- |
| ![image](https://drive.google.com/uc?id=16rHeZFgRDMQf3lHZIuXqODQA6GuB-DN7) |


# Power and Sense Management <a class="anchor"></a>  

## Battery

The robot is powered by two 6-volt NiMH (Nickel-Metal Hydride) battery packs. We chose these batteries for their high current output, which is essential for reliably running all the electronics, including the motors, without performance drops. Their use also ensures the robot has enough capacity for longer operation periods, a key advantage during competition.

As rechargeable batteries, they provide a cost-effective and time-saving solution, as they don't need to be replaced after every use. Their compact size allows them to fit neatly inside the robot's chassis, which helps in maintaining a balanced and low-profile design.

<img src="https://drive.google.com/uc?id=1_7wnMNgIy24hCdx4dEVy9Ar747YReUGw" width="20000">

## Sensing

# VL53L0X Time-of-Flight (ToF) Distance Sensors

The robot uses three VL53L0X Time-of-Flight (ToF) distance sensors to measure the distance to surrounding objects. These sensors work by emitting a laser pulse and calculating the time it takes for the light to reflect back, providing highly accurate and reliable distance measurements in millimeters. The three sensors are strategically placed on the robot to provide multi-directional awareness for obstacle avoidance and maintaining a consistent distance from the walls. They are the primary tool for the robot's navigation on the track.

![image](https://drive.google.com/uc?id=1NXoMHVktarTHrdZuAl4HXU65G1BZpMTT)

# MPU-6050 3-Axis Accelerometer & Gyroscope

The MPU-6050 is used to monitor the robot's orientation and heading. The gyroscope provides real-time data on the robot's yaw, pitch, and roll. The robot primarily uses the yaw axis to track its heading and maintain accurate directional control. Before each use, the gyro is calibrated to ensure precision, and a starting reference angle is set to 0. This allows the robot to consistently track its orientation and make precise turns, such as a 90-degree turn, by adjusting the offset relative to its starting position. This sensor is crucial for ensuring the robot drives in a straight line and turns accurately.

![image](https://drive.google.com/uc?id=11jJfRISsUBbroW9buTjq_ObbzrjjaPJ_)

HuskyLens AI Vision Sensor
The HuskyLens is a powerful AI vision sensor that provides the robot with the ability to "see" and identify objects. It is pre-trained to recognize colors and objects, which is a key part of your strategy for the Obstacle Challenge. The robot uses the HuskyLens for several key functions:

- **Color Recognition:** It is trained to detect specific colors like red and green for identifying traffic blocks, pink for the parallel parking markers, and blue and orange lines to turn.

- **Object Positioning:** The sensor provides the x and y coordinates of the detected objects, which are directly used by the program to guide the robot's movements.
This sensor allows the robot to perform complex tasks like avoiding obstacles and executing precise maneuvers such as parallel parking.

![image](https://drive.google.com/uc?id=1YfXz-XhAxRQu1AgmiXbnKuT8Nj0EGX9x)

# Schematics <a class="anchor"></a>


This schematic provides a clear overview of the robot's electronic design. It shows how a central ESP32 microcontroller manages various sensors and motors, enabling autonomous navigation and obstacle avoidance. The design is modular, with a focus on efficient communication and power management.

# Key Components

![image](https://drive.google.com/uc?id=1aF5MVUdIMGfIHesjWJOWcKdBSu5RwNBk) 

This schematic provides a complete overview of the robot's electronic system. It shows how the NodeMCU-32S microcontroller acts as the central hub, connecting to and controlling every other component.

# Power Management
The robot's power is supplied by a 6V battery pack, which connects at CN1. This power is distributed to all components in two ways. A voltage regulator (U8) steps down the 6V to a stable 3.3V to safely power the NodeMCU-32S and other sensitive electronics. The 6V supply is also used directly to power the motors and servo, as they require higher voltage and current.

# Motors
The Miuzei MG90S 9G Micro Servo Motor (S1) connects to pin D32 on the board for its control signal. The 24mm Brushless DC Gear Motor connects to the board via its motor driver (not explicitly shown) to a GPIO pin for control. Both motors are powered by the external 6V supply

# Sensors

- **VL53L0X ToF Lidar Sensors (U2, U3, U4):** The three VL53L0X Lidar sensors (U2, U3, U4) connect to the board's I2C pins (SDA/SCL) via an I2C Multiplexer (U7).

- **I2C Multiplexer (U7) & I2C Expander (U5):** To manage the three Lidar sensors on a single I2C bus, an I2C Multiplexer is used to allow the microcontroller to communicate with each sensor individually. An I2C Expander is also included to provide additional I2C communication lines for other devices.

- **HuskyLens (UB):** The HuskyLens (UB) connects to the board's serial communication pins (RXD2/TXD2) to send data back and forth.
