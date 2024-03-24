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


#define PWM_Set (*(volatile unsigned int*)(0x40020414)) |= (1U << (15))
#define PWM_Clear (*(volatile unsigned int*)(0x40020414)) &= ~(1U << (15))


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
unsigned int T_high_ticks = 50;
unsigned int T_Low_ticks = 50;
unsigned int T_PWM_Period_ticks = 100;
unsigned char DutyCycle_percentage = 0 ;

#define APP_Task_task1_START_SEC_CODE
#include "tpl_memmap.h"
TASK(task1)
{
	//Basic Task
	//init PWM
	T_PWM_Period_ticks = 100 ; //100 ticks
	DutyCycle_percentage = 20 ; //20%

	//get from uart the duty cycle from the user

	// Calculate T_high and T_low based on the DutyCycle_percentage
	T_high_ticks = (DutyCycle_percentage * T_PWM_Period_ticks) / 100;
	T_Low_ticks = T_PWM_Period_ticks - T_high_ticks;

//	SetRelAlarm(Task_High_alarm,T_Low_ticks,0 );
	TerminateTask();

}
#define APP_Task_task1_STOP_SEC_CODE
#include "tpl_memmap.h"
//-------------------------------------------

//-------------------------------------------
#define APP_Task_Task_High_START_SEC_CODE
#include "tpl_memmap.h"
TASK(Task_High)
{
	PWM_Set;
	SetRelAlarm(Task_Low_alarm,T_high_ticks,0 );

	TerminateTask();

}
#define APP_Task_Task_High_STOP_SEC_CODE
#include "tpl_memmap.h"
//-------------------------------------------

//-------------------------------------------
#define APP_Task_Task_Low_START_SEC_CODE
#include "tpl_memmap.h"
TASK(Task_Low)
{

	PWM_Clear;
	SetRelAlarm(Task_High_alarm,T_Low_ticks,0 );

	TerminateTask();

}
#define APP_Task_Task_Low_STOP_SEC_CODE
#include "tpl_memmap.h"
//-------------------------------------------
/*
 *  * This is necessary for ST libraries
 *   */
FUNC(void, OS_CODE) assert_failed(uint8_t* file, uint32_t line)
				{
				}

