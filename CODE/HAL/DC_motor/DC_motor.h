/*
 * DC_motor.h
 *
 *  Created on: Aug 31, 2023
 *      Author: hanyt
 */

#ifndef DC_MOTOR_DC_MOTOR_H_
#define DC_MOTOR_DC_MOTOR_H_



#include "MCAL/Tiva_GPTM_Timers/Tiva_GPTM_Timers.h"
#include "MCAL/Tiva_DIO/Tiva_DIO.h"



#define SPEED       60
#define ANGLE       25


#define MOTOR1_PWM     (PF2)  /* MOTOR PWM 1 */    /* Data sheet page 1351 */
#define MOTOR2_PWM     (PB2)  /* MOTOR PWM 2 */

#define MOTOR1_CTL_1     (PB0)  /* MOTOR 1 control pin 1 */
#define MOTOR1_CTL_2     (PB1)  /* MOTOR 1 control pin 2 */
#define MOTOR2_CTL_1     (PB6)  /* MOTOR 2 control pin 1 */
#define MOTOR2_CTL_2     (PB7)  /* MOTOR 2 control pin 2 */

#define M1_TIMER        TIMER1
#define M2_TIMER        TIMER3


typedef enum
{
    LEFT,
    RIGHT,
    REVERSE
} CarDirType;



/**
 * @brief Initializes the DC motors and associated pins.
 */
void motors_Init(void);

/**
 * @brief Turns the car in one direction (e.g., clockwise).
 */
void Turn_oneDirection(void);

/**
 * @brief Turns the car in the opposite direction (e.g., counterclockwise).
 */
void Turn_OtherDirection(void);

/**
 * @brief Turns the car in the specified direction by adjusting motor speeds and control pins.
 *
 * @param dir The direction to turn the car (LEFT, RIGHT, or REVERSE).
 * @param angle The angle by which to turn the car.
 */
void turn_Car(CarDirType dir, uint8_t angle);

/**
 * @brief Moves the car forward with a specified PWM value.
 *
 * @param pwm The PWM value that controls the motor speed.
 */
void move_Forward(uint32_t pwm);

/**
 * @brief Moves the car backward with a specified PWM value.
 *
 * @param pwm The PWM value that controls the motor speed.
 */
void move_Backward(uint32_t pwm);



#endif /* DC_MOTOR_DC_MOTOR_H_ */
