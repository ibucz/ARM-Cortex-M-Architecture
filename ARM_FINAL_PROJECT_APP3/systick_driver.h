/*
 * systick_driver.h
 *
 *  Created on: Jul 30, 2024
 *      Author: DELL
 */

#ifndef SYSTICK_DRIVER_H_
#define SYSTICK_DRIVER_H_

#include "std_types.h"
#include "tm4c123gh6pm_registers.h"
#include "stdint.h"

// Define a function pointer type for the callback function

// Function prototypes
void SysTick_Init(uint16_t a_TimeInMilliSeconds);
void SysTick_StartBusyWait(uint16_t a_TimeInMilliSeconds);
void SysTick_Handler(void);
void SysTick_SetCallBack(volatile void (*Ptr2Func)(void));
void SysTick_Stop(void);
void SysTick_Start(void);
void SysTick_DeInit(void);


#endif /* SYSTICK_DRIVER_H_ */
