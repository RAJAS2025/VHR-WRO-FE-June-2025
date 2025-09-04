
# The Team <a class="anchor"></a>

### Team photo
<img src="https://drive.google.com/uc?id=1DvdrtPkqM7Knqy3OlnnTlUUaTfWU8p-L" width="40%"/> <img src="https://drive.google.com/uc?id=1Naz8VsuH2fz2HpzyK-oHjj93q9z5KsKU" width="40%"/>
<br>
(Harshad, Vishnu, Rajas)

<br>

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


## The Challenge <a class="anchor" id="challenge"></a>

The **[WRO 2025 Future Engineers](https://wro-association.org/)** challenge is all about building an autonomous car that can adapt to a racetrack which changes every round. Instead of just speed, the focus is on control and problem-solving: the car needs to handle obstacles placed at random and also pull off a precise parallel park. It’s a mix of engineering and strategy, where teams combine sensors, algorithms, and creative design to make their car both smart and reliable.

This challenge emphasizes all aspects of the engineering process, including:
- **Movement:** Designing the vehicle to move efficiently and smoothly.
- **Obstacle Navigation:** Programming the car to detect and handle traffic markers within the rules.les.
- **Documentation:** Recording design decisions, progress, and collaborative work in a public GitHub repository.

Points are awarded based on how well teams perform in the challenge rounds, the thoroughness of their engineering documentation, and the creativity and reliability of their solutions. The aim is to inspire learning in STEM through hands-on robotics, collaborative teamwork, and inventive problem-solving.

To learn more about the challenge, click [here](https://wro-association.org/wp-content/uploads/WRO-2025-Future-Engineers-Self-Driving-Cars-General-Rules.pdf).

---
# Mobility Management <a class="anchor"></a>

### Chassis

Our chassis is a fully custom-designed base, modeled in SolidWorks to create a compact and efficient structure optimized for sharp servo steering. On top of the chassis, we mounted our PCB, which holds the main electronics and three laser distance sensors—one at the front and one on each side—allowing the robot to sense walls and obstacles accurately. The motor is positioned beneath the PCB in a dedicated motor holder and drives a spur gear that connects to a reinforced LEGO differential, forming a robust drivetrain.

The front steering is designed for sharp, precise turns, giving the robot the ability to navigate tight corners and avoid obstacles efficiently. The chassis layout also ensures that the weight of the sensors and electronics is balanced over the drivetrain, improving stability and traction during high-speed maneuvers.

### Potential Chassis Improvements
An improvement we could make to our chassis is lowering the center of gravity even further. A lower center of gravity keeps the car’s weight closer to the ground, which improves stability and allows for quicker, more accurate steering at higher speeds. With reduced body roll, the tires maintain stronger grip on the road, giving the driver greater precision and control. As a result, the car feels more responsive during sharp turns, lane changes, and fast cornering.


<img src="https://drive.google.com/uc?id=1Xr69AL12gRIF-5ft7Ylq5KtJu0QJ6xsf" />

### Spur Gear

To transfer power from the 6V motors to the modified LEGO differential, we designed and 3D-printed a 36-tooth spur gear that fits the motor’s 3mm D-shaped shaft and meshes precisely with the LEGO axle system. Using a 36-tooth input gear paired with a 24-tooth output gear, we geared the drivetrain for higher speed while taking advantage of the motor’s high torque and low RPM. This gear ensures smooth and efficient power transfer, providing consistent wheel rotation even under load.

<img src="https://drive.google.com/uc?id=15A_ULyuqfeW1OqZAiTphIvPfeZAlDUrT" />

### Differential Gear

The LEGO differential was imported from an online CAD model into SolidWorks and slightly reinforced to improve durability. Extra material was added around the mounting holes, and the differential was adapted to fit our custom chassis. These modifications maintain smooth power transfer to the wheels under high-torque operation, while reducing stress on the mounting points and improving overall reliability during obstacle navigation.

<img src="https://drive.google.com/uc?id=1qzpYpQRpw_0YeEP1o6rX9YchPsRdpLrL" />

### Steering Connecting Bar

The steering connecting bar is a compact, custom-designed link optimized for our sharp servo steering system. Modeled in SolidWorks, it features recessed screw inlets for better grip and durability, ensuring a secure connection between steering components. Its lightweight design minimizes additional load while transferring motion smoothly, allowing the front wheels to respond precisely to steering commands even during tight turns.

<img src="https://drive.google.com/uc?id=1eNLU3cQQbzHstJQHPj6PBz5TVGXz-ltt" /> 

### Wheel Holders(Left and Right)
The wheel holder was custom-designed in SolidWorks for our compact steering system. The extended cylinder secures a bearing for smooth tire rotation, while the smaller hole connects to the steering bar and the larger hole mounts to the chassis base.

<img src="https://drive.google.com/uc?id=1as7IMKPgUTItqlqpQ569neKkn1CLuJKQ" /> 

### Distance Sensor Holder

The distance sensor holder combines a custom-made 4M LEGO beam with a secure TinkerCAD-designed mount to keep the TOF sensor rigid and stable. This eliminates vibration or shifting during operation, ensuring accurate and consistent sensor readings. The LEGO integration allows for easy attachment to the chassis while maintaining a locked position, supporting reliable obstacle detection and wall-following maneuvers.

<img src="https://drive.google.com/uc?id=1M6zluK-iLSjezei6UIyS69u5_PhCzkHq" />

## Motors

### 24mm Brushless DC Gear Motor
The robot's forward and backward propulsion is provided by a 24mm brushless DC gear motor. This motor was chosen for its ideal balance of high speed and torque. The brushless design makes it highly efficient, durable, and provides a smooth, consistent power delivery. This motor is the core of the drivetrain, ensuring reliable and powerful movement throughout the competition.

<img src="https://drive.google.com/uc?id=1zPMkLOjHfUfX1sFINI6UgpPYMk2pBiHa" width="20%" />

Here are the specifications: <img src="https://drive.google.com/uc?id=1moiPKcTiO8_0Bga1mJdIX5mgfcUgAj7J" />

### Miuzei MG90S 9G Micro Servo Motor
The robot's steering mechanism is controlled by a Miuzei MG90S 9G Micro Servo Motor. A servo is a specialized motor designed for precise angular control rather than continuous rotation. This particular model was chosen for its metal gear construction, which offers greater durability and higher torque than plastic gear versions. The servo's ability to hold a specific angle is what allows the robot to make precise steering adjustments and navigate tight corners effectively.

<img src="https://drive.google.com/uc?id=11jJfRISsUBbroW9buTjq_ObbzrjjaPJ_" width="20%" />

## New Drivetrain & Chassis Design

Our robot is a four-wheeled vehicle that uses a **rear-wheel drive with sharp front-wheel servo steering**. The chassis was custom-modeled in SolidWorks for a compact, lightweight structure that minimizes complexity while maximizing reliability. By separating the steering system from the drivetrain, we avoided issues with spacing and ensured that the steering servo and the drive motors operate independently without interference. This gave us two possible configurations: front-wheel drive with rear steering or rear-wheel drive with front steering.  

We chose the **rear-wheel drive with front steering** configuration because it provides several advantages:


| Rear-Wheel Drive | Front-Wheel Drive |
| ---------------- | ----------------- |
| ![image](https://drive.google.com/uc?id=1Jf-CvguoRfaVFCoVMNndH-xFYlsa_ZU-) | ![image](https://drive.google.com/uc?id=1VLR8ZvrXIQMaj_SNlWJ1fxSpYCzsmNQD) |
| **Why we chose rear-wheel drive:** <br><br>- **More precise steering**, since the front wheels focus only on steering. <br>- **Balanced handling**, with weight distributed between front and rear. <br>- **No torque steer**, unlike front-wheel drive systems. <br>- **Stronger traction under acceleration**, as weight shifts to the rear drive wheels. <br>- **Better power handling**, making it suitable for higher torque motors. <br>- **Familiar control response**, matching our previous experience with other rear-driven LEGO robots. | **Why we avoided front-wheel drive:** <br><br>- Steering is less precise because the wheels also handle power delivery. <br>- Can cause **torque steer**, pulling the robot off-course under acceleration. <br>- Reduced traction at the rear wheels, especially when weight shifts forward during braking. <br>- Harder to balance power and steering without interference. <br>- Less efficient for handling higher torque loads. |

Overall, the **rear-wheel drive with front steering** configuration gave us the best balance of control, traction, and reliability. It allowed us to maximize precision while keeping the drivetrain simple and effective for competition.

---

The drivetrain works by transferring power from the rear motors into a 36-tooth spur gear that meshes with a 24-tooth gear, creating a 1.5:1 gear ratio. This gearing choice slightly increases speed while still maintaining enough torque to handle obstacles. From there, power flows into the differential gear, which splits torque between the two rear wheels so they can spin at different speeds during turns. This prevents skidding, reduces stress on the drivetrain, and keeps the robot’s motion smooth. The differential outputs directly to the rear wheels, giving strong and reliable traction. Meanwhile, the front wheels are connected to a servo motor that independently controls steering. Because the steering and drivetrain are separate, the robot achieves sharp, responsive turns without being affected by torque from the drive system.

## Old Drivetrain & Chassis Design

Our old robot also used a rear-wheel drive system with the same advantages. However, it was built mostly from LEGO pieces, making it bulkier and less optimized. The drivetrain design placed the motor vertically at the back, which consumed a lot of space.


| Back Photo of Motor | Side Photo of Motor |
| ---------------- | ----------------- |
| ![image](https://drive.google.com/uc?id=14TVYNowK-BndGGxMD3PfKOjJBTohapYJ) | ![image](https://drive.google.com/uc?id=1WCMvpPhPwMwsXJ10z-Ut7Bo1HqB2yM2O) |

## Differences between New and Old Chassis

In our new robot, the motor case is positioned beneath the battery holder, saving significant space and allowing for a more compact design. The gearing layout has also been updated: the new robot uses a side-to-side gearing configuration due to the use of spur gears, whereas the old robot had a downward setup due to the use of bevel gears. The old chassis was designed with space for gearing down to achieve more torque, while the new chassis supports either a 1:1 ratio (30-tooth spur to 30-tooth differential) or our current setup with a 36-tooth spur and 24-tooth differential. Additionally, the steering base in the new chassis is smaller and more compact, in contrast to the old design where the steering width spanned the entire chassis.

| Spur Gear View of Chassis | Differential Gear View of Chassis |
| ---------------- | ----------------- |
| ![image](https://drive.google.com/uc?id=1xcu38yokfdGivFnAiR7ZYKQTt5mwW3h0) | ![image](https://drive.google.com/uc?id=1HChk87Bm6tqbjaCHRuMx-vfJ_bkpE52m) |

## New Robot Steering

Our steering system uses a four-bar linkage with free-spinning wheels on each side. A servo motor with an arm drives the four-bar, changing the wheel angles to steer the vehicle. This setup is lightweight, efficient, and easy to implement with minimal components.

The steering is managed by a Miuzei MG90S micro servo motor, which provides precise angular control. A standard servo arm drives a four-bar linkage, with free-spinning wheels on each side made from a bearing fitted with a tire. Each wheel is secured using a custom attachment that connects directly to the bearing. This lightweight and durable setup ensures quick, precise steering response, enabling the robot to execute sharp turns and navigate obstacles effectively. To save space, our steering is mounted in a reversed configuration: the four-bar sits behind the servo’s output, and the arm operates in the opposite direction.

![ezgif com-speed (1)](https://github.com/user-attachments/assets/40b0c8e9-155e-43ce-810e-4c20fbef25d0)


## Old Robot Steering
In our previous robot, we employed the same steering concept, but the system was configured in a forward layout and was significantly larger and wider. The servo arm and mount were 3D printed as a single piece, featuring a LEGO axle–shaped cross hole that rotated in sync with the servo. Unlike the new design, the four-bar linkage was not 3D printed; it was constructed by connecting two LEGO beams with a LEGO wheel mounted on each side.

| Four-Bar Steering Mechanism |
| --------------------------- |
| <img src="https://drive.google.com/uc?id=16rHeZFgRDMQf3lHZIuXqODQA6GuB-DN7" /> |

## Car Component Placement

The main chassis serves as the foundation of the car, housing most of the core components. On top of this base, additional parts such as VEX pieces, LEGO elements, and custom 3D-printed mounts are integrated to securely attach and support each component. More details about each specific electrical component can be found in power and sense management. 

| Part | Description | Image |
| ----------- | ----------- | ----------- |
| TOF Distance Sensors | We mounted the TOF sensors using a two-beam setup. A double-sided beam is secured with two VEX star-drive screws, with a LEGO beam and frame attached below it. The frame provides multiple connection points, allowing the TOF sensors to be mounted with compatible LEGO beams on their side. This setup makes it easy to adjust the sensor position or quickly fix issues, while still keeping everything stable. | ![image](https://drive.google.com/uc?id=1hOIrTfHFLa0zhwUb6Rqasj7uWyxvHSth) |
| Husky Lens Camera | We mounted the camera on two VEX standoffs, which are fastened to a pair of LEGO beams with VEX star-drive screws. The camera itself is secured to the top LEGO beam using two M3 screws. We chose this setup over a 3D-printed bracket because the standoffs let us quickly adjust the camera height by swapping standoff lengths, and they provide greater rigidity and durability. | ![image](https://drive.google.com/uc?id=1ueXWMVm9pPt3y-N7kD_lzTD1kA_8lwpR) |
| Battery | At the center of the robot, the chassis CAD includes a dedicated slot precisely designed to fit the battery. Positioning the battery here, with the PCB mounted directly above, ensures a short and direct connection while preventing wire tangling. Additionally, a cutout at the front of the slot provides space to integrate the servo motor without interference. | ![image](https://drive.google.com/uc?id=1t9aI2a0_YSJzfXPRAPhALQHHAnrYWMIR) |
| PCB | Above the battery slot, the chassis includes a dedicated space for the PCB. The PCB is designed with ports for each sensor, so both sides of the slot are kept clear to allow ample room for wire management. A hole at the back of the PCB slot also provides easy access to the power button from the rear of the robot. | ![image](https://drive.google.com/uc?id=1Xr69AL12gRIF-5ft7Ylq5KtJu0QJ6xsf) |

## Assembly Of Chassis

![ezgif com-video-to-gif-converter (1)](https://github.com/user-attachments/assets/ab738715-b7e1-4af7-a5c3-a2ef0259da04)



# Power and Sense Management <a class="anchor"></a>  

## Battery

The robot is powered by two 6-volt NiMH (Nickel-Metal Hydride) battery packs. We chose these batteries for their high current output, which is essential for reliably running all the electronics, including the motors, without performance drops. Their use also ensures the robot has enough capacity for longer operation periods, a key advantage during competition.

As rechargeable batteries, they provide a cost-effective and time-saving solution, as they don't need to be replaced after every use. Their compact size allows them to fit neatly inside the robot's chassis, which helps in maintaining a balanced and low-profile design.

<img src="https://drive.google.com/uc?id=1_7wnMNgIy24hCdx4dEVy9Ar747YReUGw" width="20%" alt="An image of a NiMH battery pack"/>

## Sensing

### VL53L0X Time-of-Flight (ToF) Distance Sensors

The robot uses three VL53L0X Time-of-Flight (ToF) distance sensors to measure the distance to surrounding objects. These sensors work by emitting a laser pulse and calculating the time it takes for the light to reflect back, providing highly accurate and reliable distance measurements in millimeters. The three sensors are strategically placed on the robot to provide multi-directional awareness for obstacle avoidance and maintaining a consistent distance from the walls. They are the primary tool for the robot's navigation on the track.

<img src="https://drive.google.com/uc?id=1NXoMHVktarTHrdZuAl4HXU65G1BZpMTT" width="20%" alt="An image of a VL53L0X ToF distance sensor"/>

### MPU-6050 3-Axis Accelerometer & Gyroscope

The MPU-6050 is used to monitor the robot's orientation and heading. The gyroscope provides real-time data on the robot's yaw, pitch, and roll. The robot primarily uses the yaw axis to track its heading and maintain accurate directional control. Before each use, the gyro is calibrated to ensure precision, and a starting reference angle is set to 0. This allows the robot to consistently track its orientation and make precise turns, such as a 90-degree turn, by adjusting the offset relative to its starting position. This sensor is crucial for ensuring the robot drives in a straight line and turns accurately.


### HuskyLens AI Vision Sensor
The HuskyLens is a powerful AI vision sensor that provides the robot with the ability to "see" and identify objects. It is pre-trained to recognize colors and objects, which is a key part of your strategy for the Obstacle Challenge. The robot uses the HuskyLens for several key functions:

- **Color Recognition:** It is trained to detect specific colors like red and green for identifying traffic blocks, pink for the parallel parking markers, and blue and orange lines to turn.

- **Object Positioning:** The sensor provides the x and y coordinates of the detected objects, which are directly used by the program to guide the robot's movements.
This sensor allows the robot to perform complex tasks like avoiding obstacles and executing precise maneuvers such as parallel parking.

<img src="https://drive.google.com/uc?id=1YfXz-XhAxRQu1AgmiXbnKuT8Nj0EGX9x" width="20%" alt="An image of a Huskylens AI vision sensor"/>

---

# Schematics <a class="anchor"></a>

This schematic provides a clear overview of the robot's electronic design. It shows how a central ESP32 microcontroller manages various sensors and motors, enabling autonomous navigation and obstacle avoidance. The design is modular, with a focus on efficient communication and power management.

<img src="https://drive.google.com/uc?id=1aF5MVUdIMGfIHesjWJOWcKdBSu5RwNBk" width="50%" alt="A schematic of the robot's electronic components and connections"/>

### Power Management
The robot's power is supplied by a 6V battery pack, which connects at CN1. This power is distributed to all components in two ways. A voltage regulator (U8) steps down the 6V to a stable 3.3V to safely power the ESP32 and other sensitive electronics. The 6V supply is also used directly to power the motors and servo, as they require higher voltage and current.

### Motors
The Miuzei MG90S 9G Micro Servo Motor (S1) connects to pin D32 on the board for its control signal. The 24mm Brushless DC Gear Motor connects to the board via its motor driver (not explicitly shown) to a GPIO pin for control. Both motors are powered by the external 6V supply

### Sensors

- **VL53L0X ToF Lidar Sensors (U2, U3, U4):** The three VL53L0X Lidar sensors (U2, U3, U4) connect to the board's I2C pins (SDA/SCL) via an I2C Multiplexer (U7).

- **I2C Multiplexer (U7) & I2C Expander (U5):** To manage the three Lidar sensors on a single I2C bus, an I2C Multiplexer is used to allow the microcontroller to communicate with each sensor individually. An I2C Expander is also included to provide additional I2C communication lines for other devices.

- **HuskyLens (UB):** The HuskyLens (UB) connects to the board's serial communication pins (RXD2/TXD2) to send data back and forth.

| Part Name | Product | Price |
| ----------- | ----------- | ----------- |
| Battery | [`NiMH Battery Packs`](https://www.amazon.ca/melasta-Controller-Transmitter-Batteries-Rechargeable/dp/B08H1VGPTQ/ref=sr_1_7?dib=eyJ2IjoiMSJ9.6jvflqZLSyioPNMTbi8u2oe0zjAEgO0SVPFmtKSFcVizyx8WJCpY7NcH67l6ZsVLjccSUX8HYYjTynHbsuqijKooCKc_3E3V4i9yGfv1DUzkUEpPnH7BWjww65ARWq3aR8I3X-4wDlUcIDOTiW2SNK2GfzKjpEqyjw2gWkhN3qZLF-YHq3X34O7wB6gIdI6kQjp9vD7B4ZKpChUHuOPTyEezkS0Ww22aKja5_yWcUTZewEimsz45EgEAp40r7HhbXSbVoyv8Z3yoRuE6NEykaONUX4CWj9M31CB7GmyHM8U.VH-fCOSL3T6fqm7b1sa9Ko1dU032TcThg869M1KAW-Q&dib_tag=se&gad_source=1&hvadid=249594509029&hvdev=c&hvexpln=0&hvlocphy=9000820&hvnetw=g&hvocijid=14621881054563641559--&hvqmt=e&hvrand=14621881054563641559&hvtargid=kwd-307540910796&hydadcr=29607_10647357&keywords=nimh+battery+packs&mcid=16df915f92a43ecc8818107c43aee59d&qid=1756174155&sr=8-7) | $26.59 |
| Drive Motor | [`24mm Brushless DC Gear Motor – 6V 175RPM`](https://ca.robotshop.com/products/e-s-motor-24mm-brushless-dc-gear-motor-6v-175rpm?qd=f4e8ef762cd02e5a0efc04a59a1c2b2e) | $17.43 | 
| Servo Motor| [`Miuzei MG90S 9G Micro Servo Motor`](https://www.amazon.ca/Miuzei-MG90S-Servo-Helicopter-Arduino/dp/B0BWJ4RKGV/ref=sr_1_1_sspa?dib=eyJ2IjoiMSJ9.SjyQKb523oHkxGq8PZ33pXReP1_e_7FqP-xfnh4b3jZYwBlFnqYn3YfGZIt1VAZFgdQQPbQ28JjAq5Q_OZ9rJM26C2zVBQ2RIiqlaPzHOVu1u_A26R-ppvWzVuxkWyoYrTyqZXVHsXjhdK6FuN1Q89Ya0LATUSz7Ov6aD9w_EueGaBZmUSwLkKOr6cfwBffRFrB5ZC-irsOd57WjfhrXDH5drSJtA5gYU1mBC3Lkb7-G-CraqkPVl18oWgp0ao1i6DB2GteeZjfId37Kl5zk-1BfClGpkLqgh5kT6wC73CE.60P5bf61P-tOKAz1bI-IDdX9t9Z3JUCbb4ZwwRZxXPE&dib_tag=se&keywords=mg90s%2Bservo&qid=1756174433&sr=8-1-spons&sp_csd=d2lkZ2V0TmFtZT1zcF9hdGY&th=1) | $8.49 |
| Distance Sensors | [`VL53L0X V2 Distance Sensors`](https://www.adafruit.com/product/3317?srsltid=AfmBOoo2bXDFNLP4muxH_TJ6E1TMgPw9tgMk8_leCCFIUnABXe_XegRi) | $14.95 |
| Gyro | [`MPU-6050 3-Axis Accelerometer & Gyroscope: LINK NEEDED`](https://carisma-shop.com/products/gt24-alum-motor-mount) | $TBD |
| Camera | [`Huskylens`](https://ca.robotshop.com/products/gravity-huskylens-ai-machine-vision-sensor-w-silicone-case?gad_source=1&gad_campaignid=20151185247&gbraid=0AAAAAD_f_xxytUT8IaTqhSAT_ir4KZ1jB&gclid=CjwKCAjwk7DFBhBAEiwAeYbJsc7MoTx8vF9xUZyPZp27axQPZ4kNTacxE1th6vTxau1L4F4zaG-6MnRoCdAcQAvD_BwE) | $83.43 |



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

**Total Car Cost: $180.79 CAD**

---

# Obstacle Management <a class="anchor"></a>

## Libraries


## Strategy

### Open Challenge

This program controls the robot using TOF sensors and a gyro to navigate by following the outer wall. When the robot detects a wall ahead, it chooses the clearer side by comparing right and left values, and stores it in side. From that point on, the robot consistently follows the chosen outer wall, using TOF readings and gyro correction to stay aligned. Because the outer wall distance is always fixed, this method remains reliable even if interior walls shift or move. A turn count tracks progress through the maze, and once it reaches 12, the robot stops wall-following and drives straight to the finish using gyro-based control.

| Straight Movement | Turning |
| ----------------- | ------- |
| <img src="https://drive.google.com/uc?id=1DB79bmORLYsZtvS3ZY7Et7zxQinYhLz2"/> | <img src="https://drive.google.com/uc?id=10EQ50uIVgxQVyQ04zlm_7qe28uHlypXn"/> |

| Open Challenge Flowchart |
| ------------------------ |
| <img src="https://drive.google.com/uc?id=1ebbFPcefdsMD9-E0WnutMVh5yYC2ZdSq" /> |

### Obstacle Challenge

Our approach focuses on maintaining precise control and adaptability while navigating the course. The robot will use gyro-based line following to stay straight on the track, supported by distance sensors to prevent collisions on the walls. When encountering a block, the robot will slow down and maneuver around it before continuing forward once the path is clear. Turns will be guided by the camera system, which identifies the blue and orange lines on the mat to ensure consistent and accurate direction changes. Throughout the run, we will track progress by counting completed turns, allowing the robot to recognize when the course has been finished. This plan balances speed, accuracy, and reliability to effectively handle obstacles and complete the challenge.

| Red Block Movement | Green Block Movement |
| ----------------- | ------- |
| <img src="https://drive.google.com/uc?id=1x1ThfU5bREkVYrc2lWV1rFM2sHI3Szyz" /> | <img src="https://drive.google.com/uc?id=1t3yGyIsXJndeDdpIoREGKFj_onKRimM3"/> |

<br>

## Obstacle Challenge Turning Logic

In the **Obstacle Challenge**, our robot had to detect the blue and orange lines on the playing field and update its gyro heading to execute precise turning maneuvers.  
We implemented **three distinct turning logics** depending on what obstacle is detected ahead:

---

### If we see a Green Block → Do Green Turning Logic  

<table>
<tr>
<td width="40%">
<img src="https://drive.google.com/uc?id=1_S9_KFHU9lJkQZhPrbB9JMGBXcy7Chq2" alt="Green Turning" width="350"/><br>
<em>Figure 1: Green turning logic – go forward, then turn to go around the block.</em>
</td>
<td width="60%">
<ul>
<li>The robot first drives forward past the green block.</li>
<li>Once the block is cleared, it performs a controlled turn using the updated gyro heading.</li>
<li>This ensures the robot smoothly goes around the block without losing alignment.</li>
</ul>
</td>
</tr>
</table>

---

### If we see a Red Block → Do Red Turning Logic  

<table>
<tr>
<td width="40%">
<img src="https://drive.google.com/uc?id=1t3JghLeIdHi3IofLzN8IA0bfSzszBdW0" alt="Red Turning" width="350"/><br>
<em>Figure 2: Red turning logic – sharp turn around the red block.</em>
</td>
<td width="60%">
<ul>
<li>The robot immediately executes a <b>sharp turn</b> as soon as it detects the red block.</li>
<li>This quick maneuver avoids collision while still keeping the robot on course.</li>
<li>The gyro is then used to realign before moving forward again.</li>
</ul>
</td>
</tr>
</table>

---

### If No Block is Detected → Do No Block Turning Logic  

<table>
<tr>
<td width="40%">
<img src="https://drive.google.com/uc?id=1rmYoQZw9NiFVDCYeccVctoPgYiQ5xjv2" alt="No Block Turning" width="350"/><br>
<em>Figure 3: Final turning logic – align to the center when no block is detected.</em>
</td>
<td width="60%">
<ul>
<li>The robot drives forward into the middle of the field.</li>
<li>It then performs a turn and reverses slightly.</li>
<li>The backward movement helps re-center the robot in the next section for better alignment.</li>
</ul>
</td>
</tr>
</table>

---

By combining **line detection (blue/orange lines)** with **gyro updates**, the robot could reliably identify its position and apply the correct turning strategy. This adaptive logic ensured consistent navigation through different obstacle configurations.


## Dodging Blocks

These are the following steps we take to dodge a block and generally, just have the robot run through the laps.

- Detect and identify colored blocks (Red, Green, Blue, Orange, Pink).  
- Slow down automatically as it approaches obstacles.  
- Dodge blocks smoothly by adjusting steering.  
- Maintain stable heading while wall-following.

---

### Block Detection (HuskyLens)

The **HuskyLens** provides:

- `xCenter` → horizontal position of the block.  
- `yCenter` → vertical position (bigger = closer).  
- `width / height` → block size in pixels.  

In the `camread()` function:
- Each color activates a flag (`rp`, `gp`, `bl`, `ol`, `pw`).  
- Positions `(x, y)` are stored.  
- The **closest block** is the one with the **largest yCenter**.  

---

### Adaptive Speed Control

Motor speed decreases as blocks get closer:

- `curr_y` = `yCenter` of closest block.  
- Larger `y` → Closer block → Slower motor.  
- Minimum speed of **45** is enforced.  

---

### Block Avoidance (Steering Offset)

Each block influences the steering correction.  

Example: **Red Block (forces left dodge)**

- Formula = `(desired_x - current_x) * distance_y`.  
- Far block (small y) → small correction.  
- Close block (large y) → bigger correction.  

The combined correction is:

This value is passed into the steering algorithm.

---

### Steering & Wall Following (`forward()` Function)

Main control law that combines wall-following, block avoidance, and gyro correction:

if (lwd < 250) lwallval = 0.15 * (lwd - 250);
else lwallval = 0;

float kp = 0.8;
int angle;

// Correction logic
if (distance) {
    angle = (int)(kp * (g - (offsetangle - block + rwallval - lwallval)));
} else {
    if (side == 1)
        angle = (int)(kp * (g - (offsetangle - block - lwallval)));
    else
        angle = (int)(kp * (g - (offsetangle - block + rwallval)));
}

// Servo steering
int pos = 95 - angle;
pos = constrain(pos, 65, 115);
myservo.write(pos);

// Motor forward with adaptive speed
motor.run_motor(1, motorSpeed);

#### Breakdown of `forward()`:
- **Wall Following** → Keeps robot centered using TOF sensors (`rwd`, `lwd`).  
- **Block Avoidance** → Adds correction (`block = target_x`) from HuskyLens.  
- **Gyro Correction** → Maintains stable heading with IMU yaw.  
- **Steering Command** → Servo angle constrained between `65` and `115`.  
- **Motor Drive** → Runs forward at adaptive speed.  

---

### System Summary

- **Closest Block** = Block with highest `yCenter`.  
- **Speed Control** = Proportional to `yCenter` (closer = slower).  
- **Dodging** = Steering correction from block offset.  
- **Navigation** = Combination of wall following, block avoidance, and gyro correction.  

---

### Future Improvements

- Tune coefficients (`0.0035`, `0.15`, `kp=0.8`) for better performance.  
- Add PID-based velocity control for smoother deceleration.  
- Expand block behaviors:
  - **Blue** = Full stop  
  - **Orange** = Turn around  
  - **Pink** = Right-side dodge  


