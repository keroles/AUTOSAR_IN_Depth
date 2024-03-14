/**
 * @file handlers_atsam3x8e.h
 *
 * @section descr File description
 *
 * ATSAM3X8E platform specific routines and variables
 *
 * @section copyright Copyright
 *
 * Trampoline OS
 *
 * Trampoline is copyright (c) IRCCyN 2005+
 * Copyright DG for function and data structures documentation and THUMB2 port
 * Trampoline is protected by the French intellectual property law.
 *
 * This software is distributed under the Lesser GNU Public Licence
 *
 * @section infos File informations
 *
 * $Date$
 * $Rev$
 * $Author$
 * $URL$
 */

#include "tpl_compiler.h"

/******************************************************************************
 * Exception handlers.
 ******************************************************************************/
FUNC(void, OS_CODE)NMI_Handler(void);
FUNC(void, OS_CODE)HardFault_Handler(void);
FUNC(void, OS_CODE)MemManage_Handler(void);
FUNC(void, OS_CODE)BusFault_Handler(void);
FUNC(void, OS_CODE)UsageFault_Handler(void);
//FUNC(void, OS_CODE)SVCall_Handler(void);
FUNC(void, OS_CODE)DebugMonitor_Handler(void);
FUNC(void, OS_CODE)PendSV_Handler(void);

/******************************************************************************
 * IRQ acknowledge functions.
 ******************************************************************************/
// void SysTick_ClearFlag(void);
// FUNC(void, OS_CODE) TIM2_IRQ_ClearFlag(void);
// FUNC(void, OS_CODE) TIM3_IRQ_ClearFlag(void);
