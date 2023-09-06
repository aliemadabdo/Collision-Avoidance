# Collision-Avoidance
## Overview
A simple collision avoidance system scheduled with freeRTOS.
This README provides an overview of the hardware components, drivers, and real-time operating system (RTOS) integration for a Collision-Avoidance project.

## Hardware Components

### Ultrasonic Sensor

- **Amount:** 1
- **Pin Description:**
  - Echo: INT (PD2, PD3, PB2)
  - Trigger: Any Adjacent pin
- **Driver:** Enable, Disable, ReadDistance

### LCD Display

- **Amount:** 1
- **Pin Description:** Any single 13 pin (except INT and PWM)
- **Driver:** Fully implemented

### DC Motors

- **Amount:** 2
- **Pin Description:** 4 PWM Channels (PB3, PD4, PD5, PD7)
- **Driver:** Forward, RotateLeft, RotateRight, Rotate180

## RTOS Integration (MVC)

### Task 1 - Model (Sensing) Task

- **Priority:** 3 (Highest)

### Task 2 - View Task

- **Priority:** 2 or 1 (Emergency level-based)

### Task 3 - Control Task

- **Priority:** 2 or 1 (Emergency level-based)

## Future Plans

### Ultrasonic Sensors

- Increase the amount to 3 sensors to enhance decision reliability.

### LCD Display

- Plan to re-implement the driver for better performance and flexibility.

### DC Motors

- Implement speed control based on distance measurements from the ultrasonic sensors.

### RTOS

- Adjust task priorities based on an emergency level-based system for improved responsiveness and control.
