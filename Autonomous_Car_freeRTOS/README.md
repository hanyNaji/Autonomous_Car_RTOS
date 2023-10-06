# Autonomous Car using FreeRTOS

This project is an implementation of an autonomous car using FreeRTOS (Real-Time Operating System). The car is equipped with various sensors and motors to navigate and make decisions based on sensor data.

## Description

The project includes the following components and features:

- **Hardware Abstraction Layer (HAL):**
  - Ultrasonic sensor interface
  - DC motor control
  - LCD display driver
  - Light-dependent resistors (LDRs) for light detection
  - On-board temperature sensor interface

- **Middleware Communication:**
  - FreeRTOS tasks for sensor data acquisition and control
  - Task scheduling and synchronization using queues

- **Interrupt Handling:**
  - Interrupt handlers for timer and GPIO input
  - Timer for measuring elapsed time

- **Tasks:**
  - **Task 1 (LDR):** Reads data from LDRs and calculates differences.
  - **Task 2 (LCD Display):** Displays temperature, ultrasonic, LDR, and time elapsed readings on an LCD.
  - **Task 3 (Ultrasonic):** Performs ultrasonic readings and obstacle avoidance.
  - **Task 4 (Motors):** Controls car movement based on ultrasonic data and LDR differences.

## File Structure

- `app.c`: Contains the main application code.
- `main.c`: Entry point for the program.
- `HAL/`: Directory containing HAL drivers for sensors, motors, and LCD.
- `MCAL/`: Directory containing hardware-specific drivers for Tiva C series.
- `utils/`: Utility functions and definitions.
- `README.md`: This file, providing an overview of the project.

## Prerequisites

- Tiva C series development board.
- Code Composer Studio or other compatible development environment.
- FreeRTOS library.

## Installation and Usage

1. Clone this repository to your local development environment.
2. Set up your development environment with the required tools and libraries.
3. Open the project in your IDE.
4. Build and flash the code onto your Tiva C series board.
5. Watch your autonomous car in action!

