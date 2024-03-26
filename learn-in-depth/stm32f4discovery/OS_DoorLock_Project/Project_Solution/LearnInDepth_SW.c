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


#define GPIOA_MODER (*(volatile uint32_t*)(0x40020000)) // GPIOA Mode Register address
#define RCC_AHB1ENR (*(volatile uint32_t*)(0x40023830)) // RCC AHB1 peripheral clock enable register address
#define RCC_AHB1ENR_GPIOAEN (1 << 0) // GPIOA clock enable bit




#include "tp.h"
#include "tpl_os.h"

unsigned char RTE_LedState ;

void init_GPIOA_PIN0_as_input(void) {
    // Enable GPIOA clock
    RCC_AHB1ENR |= RCC_AHB1ENR_GPIOAEN;

    // Configure GPIOA PIN 0 as input (00 in MODER register for pin 0)
    GPIOA_MODER &= ~(3UL << (0 * 2)); // Clear the 2 bits corresponding to pin 0
}

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
	init_GPIOA_PIN0_as_input();
	StartOS(OSDEFAULTAPPMODE);
	return 0;
				}
//-------------------------------------------
#define APP_Task_RteTaskCyclicTask_START_SEC_CODE
#include "tpl_memmap.h"
TASK(RteTaskCyclicTask)
{

		ReadDoorSensor_runnable();
		DoorLock_indication_runnable();
	TerminateTask();
}
#define APP_Task_RteTaskCyclicTask_STOP_SEC_CODE
#include "tpl_memmap.h"
//-------------------------------------------
//-------------------------------------------
#define APP_Task_RteTaskOIE_START_SEC_CODE
#include "tpl_memmap.h"
TASK(RteTaskOIE)
{
	EventMaskType receivedEvents;

	while(1)
	{
		WaitEvent(OSOIEvent);
		GetEvent(RteTaskOIE, &receivedEvents);
        // Clear the event after handling
         ClearEvent(OSOIEvent);
		if ((receivedEvents & OSOIEvent) == OSOIEvent)
		{
			Led_Switch_runnable(RTE_LedState);
		}
	}

}
#define APP_Task_RteTaskOIE_STOP_SEC_CODE
#include "tpl_memmap.h"
//-------------------------------------------
void Rte_Call_DoorLock_indication_SWC_RP_CS_Led_Switch_Led_Switch_SetEvent(unsigned char LedState)
{
	RTE_LedState = LedState ;
	SetEvent(RteTaskOIE,OSOIEvent);
}
/*
 *  * This is necessary for ST libraries
 *   */
FUNC(void, OS_CODE) assert_failed(uint8_t* file, uint32_t line)
				{
				}

