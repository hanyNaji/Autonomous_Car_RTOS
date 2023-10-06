/*
 * scheduler.h
 *
 *  Created on: Sep 9, 2023
 *      Author: hany Nagy
 */

#ifndef APP_SCHEDULER_H_
#define APP_SCHEDULER_H_




/*** Application ***/

#include <stdint.h>
#include <math.h>
#include <stdbool.h>

#include "inc/hw_memmap.h"
#include "inc/hw_types.h"

#include "driverlib/rom.h"
#include "driverlib/sysctl.h"
#include "driverlib/interrupt.h"
#include "driverlib/timer.h"

#include "utils/cpu_usage.h"

#include "FreeRTOS.h"
#include "task.h"
#include "queue.h"
#include "semphr.h"

#include "inc/hw_ints.h"


void LCD_Display(uint32_t temp, uint32_t ultra, int32_t ldr_diff, uint32_t elapsed_time);

void system_config();

/************ Tasks ************/

/**
 * @brief Task 1 function that performs LDRs readings,
 *        and swings the car based on the LDR.s differences.
 */
void Task_1_LDR(void* p);

/**
 * @brief Task 2 function that displays temperature, LDRs, ultraSonic
 *        and time elapsed readings values on an LCD.
 */
void Task_2_LCD_Display(void* p);


/**
 * @brief Task 3 function that performs ultraSonic reading,
 *        avoid obstacles if ultraSonic_Read_CM <= 10 CM.
 */
void Task_3_UltraSonic(void* p);


/**
 * @brief Task 4 function that performs car moving,
 *        avoid obstacles if ultraSonic_Read_CM <= 10 CM.
 *        and swings the car based on the LDR.s differences.
 */
void Task_4_MOTORS(void* p);


#endif /* APP_SCHEDULER_H_ */
