#ifndef NVIC_H
#define NVIC_H

#include "std_types.h"
#include "tm4c123gh6pm_registers.h"
#include "stdint.h"


#define MEM_FAULT_PRIORITY_MASK              0x000000E0
#define MEM_FAULT_PRIORITY_BITS_POS          5

#define BUS_FAULT_PRIORITY_MASK              0x0000E000
#define BUS_FAULT_PRIORITY_BITS_POS          13

#define USAGE_FAULT_PRIORITY_MASK            0x00E00000
#define USAGE_FAULT_PRIORITY_BITS_POS        21

#define SVC_PRIORITY_MASK                    0xE0000000
#define SVC_PRIORITY_BITS_POS                29

#define DEBUG_MONITOR_PRIORITY_MASK          0x000000E0
#define DEBUG_MONITOR_PRIORITY_BITS_POS      5

#define PENDSV_PRIORITY_MASK                 0x00E00000
#define PENDSV_PRIORITY_BITS_POS             21

#define SYSTICK_PRIORITY_MASK                0xE0000000
#define SYSTICK_PRIORITY_BITS_POS            29

#define MEM_FAULT_ENABLE_MASK                0x00010000
#define BUS_FAULT_ENABLE_MASK                0x00020000
#define USAGE_FAULT_ENABLE_MASK              0x00040000

#define PRI_BASE 0xE000E400  // Base address for PRI registers
#define PENDSV_INTERRUPT_PRIORITY       7       /* Lowest Priority Level */
#define BUS_FAULT_ENABLE_BIT_POS        17
#define USAGE_FAULT_ENABLE_BIT_POS      18
#define MEM_MANAGE_FAULT_ENABLE_BIT_POS 16
#define MEM_MANAGE_FAULT_PRIORITY_BITS_POS 5
#define MEM_MANAGE_FAULT_PRIORITY       1
#define MEM_MANAGE_FAULT_PRIORITY_MASK  0xFFFFFF1F

/* Enable Exceptions ... This Macro enable IRQ interrupts, Programmable Systems Exceptions and Faults by clearing the I-bit in the PRIMASK. */
#define Enable_Exceptions()    __asm(" CPSIE I ")

/* Disable Exceptions ... This Macro disable IRQ interrupts, Programmable Systems Exceptions and Faults by setting the I-bit in the PRIMASK. */
#define Disable_Exceptions()   __asm(" CPSID I ")

/* Enable Faults ... This Macro enable Faults by clearing the F-bit in the FAULTMASK */
#define Enable_Faults()        __asm(" CPSIE F ")

/* Disable Faults ... This Macro disable Faults by setting the F-bit in the FAULTMASK */
#define Disable_Faults()       __asm(" CPSID F ")

/*******************************************************************************
 *                           Data Types Declarations                           *
 *******************************************************************************/
typedef uint8 NVIC_IRQType;

typedef uint8 NVIC_IRQPriorityType;

typedef enum
{
    EXCEPTION_RESET_TYPE,
    EXCEPTION_NMI_TYPE,
    EXCEPTION_HARD_FAULT_TYPE,
    EXCEPTION_MEM_FAULT_TYPE,
    EXCEPTION_BUS_FAULT_TYPE,
    EXCEPTION_USAGE_FAULT_TYPE,
    EXCEPTION_SVC_TYPE,
    EXCEPTION_DEBUG_MONITOR_TYPE,
    EXCEPTION_PEND_SV_TYPE,
    EXCEPTION_SYSTICK_TYPE
}NVIC_ExceptionType;

typedef uint8 NVIC_ExceptionPriorityType;


// Define types for IRQ and Exception numbers

/*
typedef enum {
    NVIC_EN0_REG ,
    NVIC_EN1_REG ,
    NVIC_EN2_REG ,
    NVIC_EN3_REG ,
    NVIC_EN4_REG
} NVIC_EN;

typedef enum {
    NVIC_DIS0_REG ,
    NVIC_DIS1_REG ,
    NVIC_DIS2_REG ,
    NVIC_DIS3_REG ,
    NVIC_DIS4_REG
} NVIC_DIS_REG;

typedef enum {
    NVIC_PRI0_REG,
    NVIC_PRI1_REG,
    NVIC_PRI2_REG,
    NVIC_PRI3_REG,
    NVIC_PRI4_REG,
    NVIC_PRI5_REG,
    NVIC_PRI6_REG,
    NVIC_PRI7_REG,
    NVIC_PRI8_REG,
    NVIC_PRI9_REG,
    NVIC_PRI10_REG,
    NVIC_PRI11_REG,
    NVIC_PRI12_REG,
    NVIC_PRI13_REG,
    NVIC_PRI14_REG,
    NVIC_PRI15_REG,
    NVIC_PRI16_REG,
    NVIC_PRI17_REG,
    NVIC_PRI18_REG,
    NVIC_PRI19_REG,
    NVIC_PRI20_REG,
    NVIC_PRI21_REG,
    NVIC_PRI22_REG,
    NVIC_PRI23_REG,
    NVIC_PRI24_REG,
    NVIC_PRI25_REG,
    NVIC_PRI26_REG,
    NVIC_PRI27_REG,
    NVIC_PRI28_REG,
    NVIC_PRI29_REG,
    NVIC_PRI30_REG,
    NVIC_PRI31_REG,
    NVIC_PRI32_REG,
    NVIC_PRI33_REG,
    NVIC_PRI34_REG
} NVIC_PRI_REG;

typedef enum {
    NVIC_SYSTEM_PRI1_REG,
    NVIC_SYSTEM_PRI2_REG,
    NVIC_SYSTEM_PRI3_REG,
    NVIC_SYSTEM_SYSHNDCTRL,
    NVIC_SYSTEM_INTCTRL,
    NVIC_SYSTEM_CFGCTRL
} NVIC_SCB_REG;
*/
// Function prototypes
void NVIC_EnableIRQ(NVIC_IRQType IRQ_Num);
void NVIC_DisableIRQ(NVIC_IRQType IRQ_Num);
void NVIC_SetPriorityIRQ(NVIC_IRQType IRQ_Num, NVIC_IRQPriorityType IRQ_Priority);
void NVIC_EnableException(NVIC_ExceptionType Exception_Num);
void NVIC_DisableException(NVIC_ExceptionType Exception_Num);
void NVIC_SetPriorityException(NVIC_ExceptionType Exception_Num, NVIC_ExceptionPriorityType Exception_Priority);

#endif // NVIC_H
