# Collision-Avoidance
## Overview
A simple collision avoidance system scheduled with freeRTOS.
This README provides an overview of the hardware components, drivers, and real-time operating system (RTOS) integration for a Collision-Avoidance project.

## Hardware Components

### Ultrasonic Sensor

- **Amount:** 1
- **Pin Description:**
  - Echo: TIMER1 (PD5)
  - Trigger: Any Adjacent pin
- **Driver:** Enable, Disable, ReadDistance

### LCD Display

- **Amount:** 1
- **Pin Description:** Any single 13 pin (except INT and PWM)
- **Driver:** Fully implemented

### DC Motors

- **Amount:** 2
- **Pin Description:** 1 PWM Channels with Timer0 (PB3) and 2 DIOs
- **Driver:** Forward, RotateLeft, RotateRight, Backward, Stop

## RTOS Integration (MVC)
- **Resourses:** Timer2
- **Driver:**
  - APIs: Init, Creat, Schedule, Sort, Set priority
  - Task Attributes: ID, Name, Priority, Priodicity, Call bach function
- 
### Task 1 - Model (Sensing) Task

- **Priority:** 0 (Highest)
- 
### Task 2 - Control Task

- **Priority:** 2 or 1 (Emergency level-based)

### Task 3 - View Task

- **Priority:** 2 or 1 (Emergency level-based)

## Future Plans

### Ultrasonic Sensors

- Increase the amount to 3 sensors to enhance decision reliability.

### DC Motors

- Implement speed control based on distance measurements from the ultrasonic sensors. [DONE]
- Full navigation with 45 degree wheels

### RTOS

- Adjust task priorities based on an emergency level-based system for improved responsiveness and control.
- Preemtive kernel implementation
