# Autonomous Car Project (with simple manual non-preemptive scheduler)

This project implements an autonomous car using a Tiva C Series TM4C123 microcontroller. It integrates various sensors, motors, and timers to create a self-driving car capable of obstacle avoidance and real-time data display on an LCD.

## Overview

The project utilizes a modular architecture with separate layers for hardware abstraction (HAL), microcontroller abstraction (MCAL), and application logic. It integrates the following components:

- **Microcontroller Abstraction Layer (MCAL):**
  - DIO (Digital Input/Output) module for pin initialization.
  - GPTM (General-Purpose Timer Module) for timer configuration.
  - ADC (Analog-to-Digital Converter) for temperature sensing.

- **Hardware Abstraction Layer (HAL):**
  - UltraSonic module for interfacing with ultrasonic distance sensors.
  - DC Motor module for controlling the car's motors.
  - LCD Driver module for displaying real-time data.
  - Sensor module for reading LDRs (Light Dependent Resistors) and onboard temperature sensor.

- **Application Logic:**
  - Scheduler module for managing multiple tasks.
  - Tasks include reading sensor data, controlling motors, and obstacle avoidance.

## Configuration

Before running the project, make sure to configure the following parameters:

- Task periods (`TASK_1_PERIOD`, `TASK_2_PERIOD`, `TASK_3_PERIOD`): Adjust the timing intervals for different tasks.
- GPIO pins (`SW1`, `SW2`): Configure the switches according to your hardware setup.
- Maximum obstacle distance (`max_Obestacle_Distance`): Set the maximum obstacle distance (in centimeters) for obstacle avoidance.

## Tasks

The project includes the following tasks:

1. **Task 1:** Reads LDR values and controls the car's movement based on the difference between left and right LDRs.
2. **Task 2:** Displays temperature, ultrasonic distance, LDR difference, and elapsed time on the LCD.
3. **Task 3:** Reads ultrasonic distance and performs obstacle avoidance if an obstacle is detected.

## How to Use

To use this project, follow these steps:

1. Include the provided HAL and MCAL files in your Tiva C Series TM4C123 project.
2. Configure the hardware connections according to your setup.
3. Adjust task periods and GPIO pin configurations as needed.
4. Build and flash the project to your microcontroller.
5. The autonomous car will perform tasks based on sensor readings and user inputs.
