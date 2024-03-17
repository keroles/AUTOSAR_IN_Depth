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


#define PA15_red (*(volatile unsigned int*)(0x40020014)) ^= (1U << (15))
#define PB15_blue (*(volatile unsigned int*)(0x40020414)) ^= (1U << (15))
#define PC15_orange (*(volatile unsigned int*)(0x40020814)) ^= (1U << (15))

#include "tp.h"
#include "tpl_os.h"
//simple mydelay function
void mydelay(unsigned int ms)
{
	unsigned int i;
	for(i=0;i<ms;i++)
	{
	}
}
typedef struct Sbuffer
{
   TaskType SourceID;
   uint8_t Data[8];
}TaskBuffer_t ;

TaskBuffer_t SharedBuffer ;

FUNC(int, OS_APPL_CODE) main(void)
				{
	initBoard();
	StartOS(OSDEFAULTAPPMODE);
	return 0;
				}
#define APP_Task_task1_START_SEC_CODE
#include "tpl_memmap.h"
uint32_t task1count = 0;

TASK(task1) //red LED
{

	//////===================
//	GetResource(Shared_OSresource);
	SharedBuffer.SourceID = task1 ;
	SharedBuffer.Data[0]= 1;
	//////===================

	//do some job
	while(task1count++ < 100)
	{
		PA15_red;
		mydelay(100);
	}

	ActivateTask(task2);  //Schedule run task2
	//do some job
	while(task1count++ < 200)
	{
		PA15_red;
		mydelay(100);
	}
//    ReleaseResource(Shared_OSresource);
	while(task1count++ < 300)
	{
		PA15_red;
		mydelay(100);
	}
	TerminateTask();

}
#define APP_Task_task1_STOP_SEC_CODE
#include "tpl_memmap.h"
//===================================================
#define APP_Task_task2_START_SEC_CODE
#include "tpl_memmap.h"
uint32_t task2count = 0;

TASK(task2)
{
	while(task2count++ < 100)
	{
		PB15_blue;
		mydelay(100);
	}
	ActivateTask(task3);  //Schedule run task3
	while(task2count++ < 200)
	{
		PB15_blue;
		mydelay(100);
	}
	TerminateTask();//Schedule run task1
}
#define APP_Task_task2_STOP_SEC_CODE
#include "tpl_memmap.h"
//===================================================
#define APP_Task_task3_START_SEC_CODE
#include "tpl_memmap.h"
uint32_t task3count = 0;

TASK(task3)
{
//	GetResource(Shared_OSresource);
	SharedBuffer.SourceID = task3 ;
	SharedBuffer.Data[0]= 3;
	//////===================
	while(task3count++ < 100)
	{
		PC15_orange;
		mydelay(100);
	}
//    ReleaseResource(Shared_OSresource);
	TerminateTask(); //Schedule run task1

}
#define APP_Task_task3_STOP_SEC_CODE
#include "tpl_memmap.h"
//===================================================


/*
 *  * This is necessary for ST libraries
 *   */
FUNC(void, OS_CODE) assert_failed(uint8_t* file, uint32_t line)
				{
				}

