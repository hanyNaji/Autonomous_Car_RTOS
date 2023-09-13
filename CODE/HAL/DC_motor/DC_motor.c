/*
 * DC_motor.c
 *
 *  Created on: Aug 31, 2023
 *      Author: hany nagy
 */

#include "DC_motor.h"


/**
 * @brief Initializes the DC motors and associated pins.
 */
void motors_Init(void)
{
    GPTM_PWM_init(M1_TIMER, MOTOR1_PWM);
    GPTM_PWM_init(M2_TIMER, MOTOR2_PWM);


    DIO_InitPin(MOTOR1_CTL_1, OUTPUT);
    DIO_InitPin(MOTOR1_CTL_2, OUTPUT);
    DIO_InitPin(MOTOR2_CTL_1, OUTPUT);
    DIO_InitPin(MOTOR2_CTL_2, OUTPUT);
}



/**
 * @brief Turns the car in one direction (e.g., clockwise).
 */
void Turn_oneDirection(void)
{
     SYSCTL_RCGCGPIO_R |= 0x01;   /* enable clock to PORTF */
     GPIO_PORTA_DIR_R  |= 0xFF ;          /* pin digital */
     GPIO_PORTA_DEN_R  |= 0xFF  ;       /* pin digital */
     GPIO_PORTA_DATA_R |=(1<<2);
     GPIO_PORTA_DATA_R &=~(1<<3);
     GPIO_PORTA_DATA_R |=(1<<4);
     GPIO_PORTA_DATA_R &=~(1<<5);

}

/**
 * @brief Turns the car in the opposite direction (e.g., counterclockwise).
 */
void Turn_OtherDirection(void)
{
    SYSCTL_RCGCGPIO_R |= 0x01;   /* enable clock to PORTF */
    GPIO_PORTA_DIR_R |= (1<<3)|(1<<2);            /* pin digital */
    GPIO_PORTA_DEN_R |= (1<<3)|(1<<2);
    GPIO_PORTA_DATA_R |=(1<<3);
    GPIO_PORTA_DATA_R &=~(1<<2);
}

/**
 * @brief Turns the car in the specified direction by adjusting motor speeds and control pins.
 *
 * @param dir The direction to turn the car (LEFT, RIGHT, or REVERSE).
 * @param angle The angle by which to turn the car.
 */
void turn_Car(CarDirType dir, uint8_t angle)
{

    switch (dir)
    {
        case LEFT:
            GPTM_PWM_Duty_Cycle(M1_TIMER, SPEED);
            GPTM_PWM_Duty_Cycle(M2_TIMER, SPEED/2);
            DIO_WritePin(MOTOR1_CTL_1, HIGH);
            DIO_WritePin(MOTOR1_CTL_2, LOW);
            DIO_WritePin(MOTOR2_CTL_1, HIGH);
            DIO_WritePin(MOTOR2_CTL_2, LOW);
            break;
        case RIGHT:
            GPTM_PWM_Duty_Cycle(M1_TIMER, SPEED/2);
            GPTM_PWM_Duty_Cycle(M2_TIMER, SPEED);
            DIO_WritePin(MOTOR1_CTL_1, LOW);
            DIO_WritePin(MOTOR1_CTL_2, HIGH);
            DIO_WritePin(MOTOR2_CTL_1, LOW);
            DIO_WritePin(MOTOR2_CTL_2, HIGH);
            break;
        case REVERSE:
            GPTM_PWM_Duty_Cycle(M1_TIMER, SPEED);
            GPTM_PWM_Duty_Cycle(M2_TIMER, SPEED);
            DIO_WritePin(MOTOR1_CTL_1, LOW);
            DIO_WritePin(MOTOR1_CTL_2, HIGH);
            DIO_WritePin(MOTOR2_CTL_1, LOW);
            DIO_WritePin(MOTOR2_CTL_2, HIGH);
            break;
        default:
            break;
    }

    _delay_ms(30 * angle/10);

    GPTM_PWM_Duty_Cycle(M1_TIMER, 30);
    GPTM_PWM_Duty_Cycle(M2_TIMER, 30);
}

/**
 * @brief Moves the car forward with a specified PWM value.
 *
 * @param pwm The PWM value that controls the motor speed.
 */
void move_Forward(uint32_t pwm)
{
    GPTM_PWM_Duty_Cycle (M1_TIMER, pwm);
    GPTM_PWM_Duty_Cycle (M2_TIMER, pwm);
    DIO_WritePin(MOTOR1_CTL_1, LOW);
    DIO_WritePin(MOTOR1_CTL_2, HIGH);
    DIO_WritePin(MOTOR2_CTL_1, HIGH);
    DIO_WritePin(MOTOR2_CTL_2, LOW);
}

/**
 * @brief Moves the car backward with a specified PWM value.
 *
 * @param pwm The PWM value that controls the motor speed.
 */
void move_Backward(uint32_t pwm)
{

    GPTM_PWM_Duty_Cycle (M1_TIMER, pwm);
    GPTM_PWM_Duty_Cycle (M2_TIMER, pwm);
    DIO_WritePin(MOTOR1_CTL_1, HIGH);
    DIO_WritePin(MOTOR1_CTL_2, LOW);
    DIO_WritePin(MOTOR2_CTL_1, LOW);
    DIO_WritePin(MOTOR2_CTL_2, HIGH);
}





