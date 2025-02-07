/*
 * systick_driver.c
 *
 *  Created on: Jul 30, 2024
 *      Author: DELL
 */
#include "systick_driver.h"

// Static variable to store the callback function pointer
static volatile void(*g_CallBackPtr)(void)=NULL_PTR;

/* Enable the SystTick Timer to run using the System Clock with specified time in milliseconds */
/*********************************************************************
 * Service Name: SysTick_Init
 * Return value: None
 *  Sync/Async: Synchronous
 *  Description:1- Disable the SysTick Timer by Clear the ENABLE Bit
 *              2-Set the Reload value with 15999999 to count 0.2 Second
 *              3-Clear the Current Register value
 *              Configure the SysTick Control Register
     * Enable the SysTick Timer (ENABLE = 1)
     * Enable SysTick Interrupt (INTEN = 1)
     * Choose the clock source to be System Clock (CLK_SRC = 1)
     * Assign priority level 3 to the SysTick Interrupt
 *
**********************************************************************/
void SysTick_Init(uint16_t a_TimeInMilliSeconds)
{
    uint32_t ticks;

       // Assuming a system clock frequency of 48 MHz
       // Convert time in milliseconds to SysTick ticks
       // For a 16 MHz clock, there are 16,000 ticks per millisecond
       ticks = (16000 * a_TimeInMilliSeconds) - 1;

    SYSTICK_CTRL_REG    = 0;              /* Disable the SysTick Timer by Clear the ENABLE Bit */
    SYSTICK_RELOAD_REG  = ticks;       /* Set the Reload value with 15999999 to count 1 Second */
    SYSTICK_CURRENT_REG = 0;              /* Clear the Current Register value */
    /* Configure the SysTick Control Register
     * Enable the SysTick Timer (ENABLE = 1)
     * Disable SysTick Interrupt (INTEN = 0)
     * Choose the clock source to be System Clock (CLK_SRC = 1) */
    SYSTICK_CTRL_REG   |= 0x07;
}


// Busy-wait function using SysTick timer
void SysTick_StartBusyWait(uint16_t a_TimeInMilliSeconds)
{
    uint32_t ticks;

    // Convert time in milliseconds to SysTick ticks
    ticks = (16000 * a_TimeInMilliSeconds) - 1;

    // Set the reload value
    SYSTICK_RELOAD_REG = ticks;

    // Clear the current value register
    SYSTICK_CURRENT_REG = 0;

    // Start SysTick timer
    SYSTICK_CTRL_REG  |= 0x01;

    // Busy-wait until the timer counts down to zero
    while (!(SYSTICK_CTRL_REG  & 0x10000));

    // Stop the SysTick timer
    SYSTICK_CTRL_REG  &= ~0x01;
}

// SysTick interrupt handler
void SysTick_Handler(void)
{
    // Call the callback function if set
    if (g_CallBackPtr != NULL_PTR)
    {
        (*g_CallBackPtr)();
    }
}

// Set the callback function to be executed in SysTick Handler
void SysTick_SetCallBack(volatile void (*Ptr2Func)(void))
{
    g_CallBackPtr = Ptr2Func;
}

// Stop the SysTick timer
void SysTick_Stop(void)
{
    SYSTICK_CTRL_REG &= ~0x01;  // Disable the timer
}

// Start or resume the SysTick timer
void SysTick_Start(void)
{
    SYSTICK_CTRL_REG |= 0x01;  // Enable the timer
}

// De-initialize the SysTick timer
void SysTick_DeInit(void)
{
    SYSTICK_CTRL_REG &= ~0x01;  // Disable the timer
    SYSTICK_RELOAD_REG = 0;    // Clear the reload value
    SYSTICK_CURRENT_REG = 0;   // Clear the current value
 //   SysTick_Callback = 0;      // Clear the callback function
}





