/*
 * ultraSonic.h
 *
 *  Created on: Aug 31, 2023
 *      Author: hanyt
 */

#ifndef ULTRASONIC_ULTRASONIC_H_
#define ULTRASONIC_ULTRASONIC_H_


#include "../../MCAL/Tiva_GPTM_Timers/Tiva_GPTM_Timers.h"
#include "MCAL/Tiva_DIO/Tiva_DIO.h"

#define max_Obestacle_Distance      10U

#define TRIG_PIN     (PC5)  /* for signal out pin */
#define ECHO_PIN     (PC4)  /* for capture pin */


/**
 * @brief Initializes the UltraSonic Sensor with the specified trigger and echo pins.
 *
 * @param trigg The trigger pin of the ultrasonic sensor (output pin).
 * @param echoo The echo pin of the ultrasonic sensor (input pin).
 */
void ultraSonic_Init(DIO_AllPINS_TYPE trigg, DIO_AllPINS_TYPE echoo);

/**
 * @brief Reads the distance measured by the ultrasonic sensor and returns the value in centimeters (cm).
 *
 * @return The measured distance in centimeters.
 */
uint32_t ultraSonic_Read_CM(void);



#endif /* ULTRASONIC_ULTRASONIC_H_ */
