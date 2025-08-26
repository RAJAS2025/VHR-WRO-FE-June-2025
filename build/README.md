Build
====

This directory documents the materials used to construct our robot, along with the reasoning behind our drivetrain, gearing, and steering choices. It also includes the design iterations, comparisons between old and new robots, the CAD process, and how electrical components, 3D-printed parts, VEX pieces, and LEGO elements were integrated into our fully 3D-printed chassis. An assembly video is also provided to demonstrate how the robot comes together.
## Drivetrain & Chassis Design

Our robot is a four-wheeled vehicle that uses a **rear-wheel drive with sharp front-wheel servo steering**. The chassis was custom-modeled in SolidWorks for a compact, lightweight structure that minimizes complexity while maximizing reliability. By separating the steering system from the drivetrain, we avoided issues with spacing and ensured that the steering servo and the drive motors operate independently without interference. This gave us two possible configurations: front-wheel drive with rear steering or rear-wheel drive with front steering.  

We chose the **rear-wheel drive with front steering** configuration because it provides several advantages:  

- **Better torque transfer** through the reinforced LEGO differential.  
- **Greater stability** under load, as the weight of the robot is more evenly distributed over the rear drive wheels.  
- **Improved maneuverability**, since steering and driving forces are separated between the front and rear axles.  
- **Familiar control response**, matching our previous experience with other rear-driven LEGO robots.  

This design results in a simple, efficient, and reliable drivetrain well-suited for our competition needs.


| Rear-Wheel Drive | Front Wheel Drive |
| ---------------- | ----------------- |
| ![image](https://drive.google.com/uc?id=1Jf-CvguoRfaVFCoVMNndH-xFYlsa_ZU-) | ![image](https://drive.google.com/uc?id=1VLR8ZvrXIQMaj_SNlWJ1fxSpYCzsmNQD) |

## Steering

Our steering mechanism is a four-bar with free-spinning wheels mounted on it. The motor will move the four-bar, which changes the angle of the wheels, which in turn changes the direction that the vehicle is travelling in. This type of steering proved to be the most efficient for our purposes and was also the easiest version for us to implement, as it only required a servo motor and a simple rig that connected the servo to the wheel axles. The rig was 3D printed along with the servo mount as one piece and had a LEGO axle-shaped cross hole that would turn along with the servo.

| Four-Bar Steering Mechanism |
| --------------------------- |
| ![image](https://drive.google.com/uc?id=16rHeZFgRDMQf3lHZIuXqODQA6GuB-DN7) |

## Materials

When creating our robot, we wanted to be able to easily iterate and update the robot in many ways as we tested it. In order to achieve these goals, we decided to use LEGO Technic pieces to construct the majority of our robot. LEGO technic was the perfect choice for us since our robotics centre, Zebra Robotics, focuses on LEGO robotics and competitions related to that, so we have an abundance of LEGO technic pieces. Our team members also have extensive experience in working with LEGO Technic parts and completing challenges with them. In order to attach the electronic components onto our chassis, we 3D printed mounts for the components, as they allowed us to smoothly integrate the non-LEGO parts with the LEGO parts.
