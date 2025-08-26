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

In the open challenge, the only changes to the mat are the size of the interior walls. To tackle these challenges, we will be using laser distance sensors to measure the distance from the walls. By having multiple sensors around the robot, the robot can accurately calculate the distance to the surrounding walls. The robot can use these readings from the sensor to correct itself and make sure it stays parallel to the wall. The robot will know when to turn using the distance sensors as one sensor will be placed in the front. Once the distance is less than a certain amount, the robot will know to turn. We keep track of the laps by keeping track of each turn we compete so we know when to end.

| Straight Movement | Turning |
| ----------------- | ------- |
| ![image](https://drive.google.com/uc?id=1DB79bmORLYsZtvS3ZY7Et7zxQinYhLz2) | ![image](https://drive.google.com/uc?id=10EQ50uIVgxQVyQ04zlm_7qe28uHlypXn) |

| Open Challenge Flowchart |
| ------------------------ |
| ![image](https://drive.google.com/uc?id=1ebbFPcefdsMD9-E0WnutMVh5yYC2ZdSq) |

 ### Obstacle Challenge

Our approach focuses on maintaining precise control while navigating the dynamic course. We plan to use gyro-based line following to keep the robot moving straight along the track, while wall safety sensors prevent collisions if the robot gets too close to the edges. When a block is detected, the robot will decelerate to maneuver around it, using an algorithm that continues turning until the obstacle is fully passed, then accelerates again once the path is clear. For turns, the robot uses a camera system to detect the blue and orange lines on the mat, allowing accurate and consistent adjustments. This strategy combines speed, precision, and adaptability to handle obstacles effectively while staying on course.

| 1 Block Movement | 2 Block Movement|
| ----------------- | ------- |
| ![image](https://drive.google.com/uc?id=1o8-S4fOHuvVPILtzNyMyq0V-x_8KhPgD) | ![image](https://drive.google.com/uc?id=1D9FqWyBBqiH5tIUv-c189Mm-1k3GZKxQ) |

