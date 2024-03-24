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
FUNC(int, OS_APPL_CODE) main(void)
						{
	initBoard();
	StartOS(OSDEFAULTAPPMODE);
	return 0;
						}
//-------------------------------------------
#define APP_Task_task1_START_SEC_CODE
#include "tpl_memmap.h"
TASK(task1)
{
	for(int i =0 ; i<100 ; i++)
	{
		PB15_blue;
		mydelay(10);
	}
	SetEvent(task2,Task2_event1);
	for(int i =0 ; i<100 ; i++)
	{
		PB15_blue;
		mydelay(10);
	}
	SetEvent(task2,Task2_event2);
	for(int i =0 ; i<100 ; i++)
	{
		PB15_blue;
		mydelay(10);
	}

	TerminateTask();
}
#define APP_Task_task1_STOP_SEC_CODE
#include "tpl_memmap.h"
//-------------------------------------------
//-------------------------------------------
#define APP_Task_task2_START_SEC_CODE
#include "tpl_memmap.h"
TASK(task2)
{
	EventMaskType receivedEvents;

	while(1)
	{
		WaitEvent(Task2_event1 | Task2_event2);
		GetEvent(task2, &receivedEvents);
		// Clear the event after handling
		if ((receivedEvents & Task2_event1) == Task2_event1)
		{
			ClearEvent(Task2_event1);
			for(int i =0 ; i<100 ; i++)
			{
				PA15_red;
				mydelay(10);
			}
		}else if ((receivedEvents & Task2_event2)== Task2_event2 )
		{
			ClearEvent(Task2_event2);
			for(int i =0 ; i<100 ; i++)
			{
				PA15_red;
				mydelay(10);
			}

		}
	}

}
#define APP_Task_task2_STOP_SEC_CODE
#include "tpl_memmap.h"
//-------------------------------------------

/*
 *  * This is necessary for ST libraries
 *   */
FUNC(void, OS_CODE) assert_failed(uint8_t* file, uint32_t line)
						{
						}

