
Strategy
====

This directory consists of an explanation and diagrams of our strategy for both the open and obstacle rounds.

## Open Challenge Strategy

In the open challenge, the only changes to the mat are the size of the interior walls. To tackle these challenges, we will be using laser distance sensors to measure the distance from the walls. By having multiple sensors around the robot, the robot can accurately calculate the distance to the surrounding walls. The robot can use these readings from the sensor to correct itself and make sure it stays parallel to the wall. The robot will know when to turn using the distance sensors as one sensor will be placed in the front. Once the distance is less than a certain amount, the robot will know to turn. We keep track of the laps by keeping track of each turn we compete so we know when to end.
| Straight Movement | Turning |
| ----------------- | ------- |
| ![image](Straight.png) | ![image](Turn.png) |

| Open Challenge Flowchart |
| ------------------------ |
| ![image](FlowChart.png) |

