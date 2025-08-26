# The Team <a class="anchor"></a>

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
<img src="https://drive.google.com/uc?id=1DvdrtPkqM7Knqy3OlnnTlUUaTfWU8p-L" width="40%"/> <img src="https://drive.google.com/uc?id=1Naz8VsuH2fz2HpzyK-oHjj93q9z5KsKU" width="40%"/>

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

Potential Chassis Improvements
TO BE ADDED

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

### Distance Sensor Holder

The distance sensor holder combines a custom-made 4M LEGO beam with a secure TinkerCAD-designed mount to keep the TOF sensor rigid and stable. This eliminates vibration or shifting during operation, ensuring accurate and consistent sensor readings. The LEGO integration allows for easy attachment to the chassis while maintaining a locked position, supporting reliable obstacle detection and wall-following maneuvers.

<img src="https://drive.google.com/uc?id=1M6zluK-iLSjezei6UIyS69u5_PhCzkHq" />

## Motors

### 24mm Brushless DC Gear Motor
The robot's forward and backward propulsion is provided by a 24mm brushless DC gear motor. This motor was chosen for its ideal balance of high speed and torque. The brushless design makes it highly efficient, durable, and provides a smooth, consistent power delivery. This motor is the core of the drivetrain, ensuring reliable and powerful movement throughout the competition.

<img src="https://drive.google.com/uc?id=1zPMkLOjHfUfX1sFINI6UgpPYMk2pBiHa" width="20%" />

### Miuzei MG90S 9G Micro Servo Motor
The robot's steering mechanism is controlled by a Miuzei MG90S 9G Micro Servo Motor. A servo is a specialized motor designed for precise angular control rather than continuous rotation. This particular model was chosen for its metal gear construction, which offers greater durability and higher torque than plastic gear versions. The servo's ability to hold a specific angle is what allows the robot to make precise steering adjustments and navigate tight corners effectively.

<img src="https://drive.google.com/uc?id=11jJfRISsUBbroW9buTjq_ObbzrjjaPJ_" width="20%" />

## New Drivetrain & Chassis Design

Our robot is a four-wheeled vehicle that uses a **rear-wheel drive with sharp front-wheel servo steering**. The chassis was custom-modeled in SolidWorks for a compact, lightweight structure that minimizes complexity while maximizing reliability. By separating the steering system from the drivetrain, we avoided issues with spacing and ensured that the steering servo and the drive motors operate independently without interference. This gave us two possible configurations: front-wheel drive with rear steering or rear-wheel drive with front steering.  

We chose the **rear-wheel drive with front steering** configuration because it provides several advantages:  
- **More precise steering**, since the front wheels focus only on steering.  
- **Balanced handling**, with weight distributed between front and rear.  
- **No torque steer**, unlike front-wheel drive systems.  
- **Stronger traction under acceleration**, as weight shifts to the rear drive wheels.  
- **Better power handling**, making it suitable for higher torque motors.  
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
| <img src="https://drive.google.com/uc?id=16rHeZFgRDMQf3lHZIuXqODQA6GuB-DN7" /> |

## Old Drivetrain & Chassis Design

Our old robot also used a rear-wheel drive system with the same advantages. However, it was built mostly from LEGO pieces, making it bulkier and less optimized. The drivetrain design placed the motor vertically at the back, which consumed a lot of space.


| Back Photo of Motor | Side Photo of Motor |
| ---------------- | ----------------- |
| ![image](https://drive.google.com/uc?id=14TVYNowK-BndGGxMD3PfKOjJBTohapYJ) | ![image](https://drive.google.com/uc?id=1WCMvpPhPwMwsXJ10z-Ut7Bo1HqB2yM2O) |
