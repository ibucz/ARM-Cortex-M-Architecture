#include "NVIC_driver.h"

// Array of pointers to NVIC enable registers
volatile uint32 * const NVIC_EN_REGS[] = {
    &NVIC_EN0_REG,
    &NVIC_EN1_REG,
    &NVIC_EN2_REG,
    &NVIC_EN3_REG,
    &NVIC_EN4_REG
};

// Array of pointers to NVIC disable registers
volatile uint32 * const NVIC_DIS_REGS[] = {
    &NVIC_DIS0_REG,
    &NVIC_DIS1_REG,
    &NVIC_DIS2_REG,
    &NVIC_DIS3_REG,
    &NVIC_DIS4_REG
};

// Array of pointers to NVIC priority registers
volatile uint32 * const NVIC_PRI_REGS[] = {
    &NVIC_PRI0_REG,
    &NVIC_PRI1_REG,
    &NVIC_PRI2_REG,
    &NVIC_PRI3_REG,
    &NVIC_PRI4_REG,
    &NVIC_PRI5_REG,
    &NVIC_PRI6_REG,
    &NVIC_PRI7_REG,
    &NVIC_PRI8_REG,
    &NVIC_PRI9_REG,
    &NVIC_PRI10_REG,
    &NVIC_PRI11_REG,
    &NVIC_PRI12_REG,
    &NVIC_PRI13_REG,
    &NVIC_PRI14_REG,
    &NVIC_PRI15_REG,
    &NVIC_PRI16_REG,
    &NVIC_PRI17_REG,
    &NVIC_PRI18_REG,
    &NVIC_PRI19_REG,
    &NVIC_PRI20_REG,
    &NVIC_PRI21_REG,
    &NVIC_PRI22_REG,
    &NVIC_PRI23_REG,
    &NVIC_PRI24_REG,
    &NVIC_PRI25_REG,
    &NVIC_PRI26_REG,
    &NVIC_PRI27_REG,
    &NVIC_PRI28_REG,
    &NVIC_PRI29_REG,
    &NVIC_PRI30_REG,
    &NVIC_PRI31_REG,
    &NVIC_PRI32_REG,
    &NVIC_PRI33_REG,
    &NVIC_PRI34_REG
};

// Array of pointers to System Control Block (SCB) priority registers
volatile uint32 * const NVIC_SCB_PRI_REGS[] = {
    &NVIC_SYSTEM_PRI1_REG,
    &NVIC_SYSTEM_PRI2_REG,
    &NVIC_SYSTEM_PRI3_REG
};

// Enable specific IRQ
/*********************************************************************
 * Service Name: NVIC_EnableIRQ
 * Sync/Async: Synchronous
 * Reentrancy: reentrant
 * Parameters (in): IRQ_Num - Number of the IRQ from the target vector table
 * Parameters (inout): None
 * Parameters (out): None
 * Return value: None
 * Description: Function to enable Interrupt request for specific IRQ
**********************************************************************/
void NVIC_EnableIRQ(NVIC_IRQType IRQ_Num) {
    NVIC_EN_REGS[IRQ_Num / 32][0] |= (1 << (IRQ_Num % 32));
}

// Disable specific IRQ
/*********************************************************************
 * Service Name: NVIC_DISableIRQ
 * Sync/Async: Synchronous
 * Reentrancy: reentrant
 * Parameters (in): IRQ_Num - Number of the IRQ from the target vector table
 * Parameters (inout): None
 * Parameters (out): None
 * Return value: None
 * Description: Function to disable Interrupt request for specific IRQ
**********************************************************************/
void NVIC_DisableIRQ(NVIC_IRQType IRQ_Num) {
    NVIC_DIS_REGS[IRQ_Num / 32][0] |= (1 << (IRQ_Num % 32));
}

// Set priority for specific IRQ
/*********************************************************************
 * Service Name: NVIC_SetPriorityIRQ
 * Sync/Async: Synchronous
 * Reentrancy: reentrant
 * Parameters (in): IRQ_Num - Number of the IRQ from the target vector table / IRQ_Priority -to set Priority of Interrupt
 * Parameters (inout): None
 * Parameters (out): None
 * Return value: None
 * Description: Function to SetPriorityIRQ in Vector table
**********************************************************************/
void NVIC_SetPriorityIRQ(NVIC_IRQType IRQ_Num, NVIC_IRQPriorityType IRQ_Priority) {
    uint8 reg_offset = IRQ_Num / 4;
    uint8 bit_pos = (IRQ_Num % 4) * 8 + 5;
    NVIC_PRI_REGS[reg_offset][0] = (NVIC_PRI_REGS[reg_offset][0] & ~(0xFF << bit_pos)) | (IRQ_Priority << bit_pos);
}

// Enable specific system or fault exception
/*********************************************************************
 * Service Name: NVIC_EnableException
 * Sync/Async: Synchronous
 * Reentrancy: reentrant
 * Parameters (in): Exception_Num - Number of the EXception from the target vector table
 * Parameters (inout): None
 * Parameters (out): None
 * Return value: None
 * Description: Function to Enable Exception interrupt
**********************************************************************/
void NVIC_EnableException(NVIC_ExceptionType Exception_Num) {
    NVIC_SYSTEM_SYSHNDCTRL |= (1 << Exception_Num);
}

// Disable specific system or fault exception
/*********************************************************************
 * Service Name: NVIC_DisableException
 * Sync/Async: Synchronous
 * Reentrancy: reentrant
 * Parameters (in): Exception_Num - Number of the EXception from the target vector table
 * Parameters (inout): None
 * Parameters (out): None
 * Return value: None
 * Description: Function to DISable Exception interrupt
**********************************************************************/

void NVIC_DisableException(NVIC_ExceptionType Exception_Num) {
    NVIC_SYSTEM_SYSHNDCTRL &= ~(1 << Exception_Num);
}

// Set priority for specific system or fault exception
/*********************************************************************
 * Service Name: NVIC_SetPriorityException
 * Sync/Async: Synchronous
 * Reentrancy: reentrant
 * Parameters (in): Exception_Num - Number of the Exception from the target vector table / Exception_Priority -to set Priority of Interrupt
 * Parameters (inout): None
 * Parameters (out): None
 * Return value: None
 * Description: Function to SetPriority Exception in Vector table
**********************************************************************/
void NVIC_SetPriorityException(NVIC_ExceptionType Exception_Num, NVIC_ExceptionPriorityType Exception_Priority) {
    uint8 reg_offset = Exception_Num / 4;
    uint8 bit_pos = (Exception_Num % 4) * 8 + 5;
    NVIC_SCB_PRI_REGS[reg_offset][0] = (NVIC_SCB_PRI_REGS[reg_offset][0] & ~(0xFF << bit_pos)) | (Exception_Priority << bit_pos);
}
