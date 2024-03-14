/*
 * AUTOSAR IN Depth Materials
 * www.learn-in-depth.com
 * Eng.Keroles Shenouda
 * eng.keroles.karam@gmail.com
 *
 */


//    PA15   (*(unsigned int*)(0x40020014)) >> 15
//    PB15   (*(unsigned int*)(0x40020414)) >> 15
//    PC15   (*(unsigned int*)(0x40020814)) >> 15
//    PD15:  (*(unsigned int*)(0x40020C14)) >> 15


#define PA15_green (*(volatile unsigned int*)(0x40020014))
#define PB15_yellow (*(volatile unsigned int*)(0x40020414))
#define PC15_red (*(volatile unsigned int*)(0x40020814))

#include "tp.h"
#include "tpl_os.h"


#define APP_Task_Task1_START_SEC_CODE
#include "tpl_memmap.h"

FUNC(int, OS_APPL_CODE) main(void)
{
	initBoard();
	StartOS(OSDEFAULTAPPMODE);
	return 0;
}

TASK(Task1_Green)
{
	PA15_green |= 1<<15 ;
	PB15_yellow &= ~(1<<15);
	PC15_red &= ~(1<<15);
	delay(500) ; //500ms for simulation
	ChainTask(Task2_yellow);
}
#define APP_Task_Task1_STOP_SEC_CODE

#define APP_Task_Task2_START_SEC_CODE
#include "tpl_memmap.h"
uint32_t Task2count = 0;
TASK(Task2_yellow)
{
	PA15_green &= ~(1<<15);
	PB15_yellow  |= 1<<15 ;
	PC15_red &= ~(1<<15);
	delay(500) ; //500ms for simulation
	ChainTask(Task3_Red);
}
#define APP_Task_Task2_STOP_SEC_CODE

#define APP_Task_Task3_START_SEC_CODE
#include "tpl_memmap.h"
TASK(Task3_Red)
{
	PA15_green &= ~(1<<15);
	PB15_yellow  &= ~(1<<15);
	PC15_red  |= 1<<15 ;
	delay(500) ; //500ms for simulation
	ChainTask(Task1_Green);

}
#define APP_Task_Task3_STOP_SEC_CODE


/*
 *  * This is necessary for ST libraries
 *   */
FUNC(void, OS_CODE) assert_failed(uint8_t* file, uint32_t line)
{
}

