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
	STM_EVAL_PBInit(BUTTON_USER, BUTTON_MODE_EXTI);
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
	unsigned char TASK_ID = Task_Low_alarm ;
	PWM_Set;
	SetRelAlarm(TASK_ID,T_high_ticks,0 );

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
//-------------------------------------------

#define APP_ISR_isr_button_START_SEC_CODE
#include "tpl_memmap.h"
unsigned char PWM_states = 0;
ISR(isr_button)
{
	switch(PWM_states)
	{
	case 0:
		DutyCycle_percentage = 70 ;
		PWM_states++ ;
		break;
	case 1:
		DutyCycle_percentage = 50 ;
		PWM_states++ ;
		break;
	case 2:
		DutyCycle_percentage = 30 ;
		PWM_states=0;
		break;
	}

}
#define APP_ISR_isr_button_STOP_SEC_CODE
#include "tpl_memmap.h"
//-------------------------------------------

void StartupHook(void)
{
	//check RCC
	//for debugging
	static int X =0 ;
	X++ ;
}
void ShutdownHook(StatusType error)
{
	/* You can check the error parameter to see if the shutdown was due to an error. */
	/* Perform necessary cleanup operations here */
	/* Save system states or log shutdown event */
	/* Any final actions before shutdown */
}
void PreTaskHook(void)
{
	static int count = 0;
	TaskType currentTask;
	StatusType status = GetTaskID(&currentTask);
	if (status == E_OK && currentTask == Task_High)
	{
		count++;
	}
	/* ... other pre-task actions ... */
}
void PostTaskHook(void)
{
	/* Perform any necessary actions after a task has ended. */
	//    LogTaskEnd(GetRunningTaskID());

	/* For example, clean up task-specific peripherals or update system status. */

}
void ErrorHook(StatusType error)
{
	/* This example assumes that OS services return detailed error information */
//	int serviceId = OSErrorGetServiceId();
	TaskType callingTask ;
	GetTaskID(&callingTask);

	switch(error)
	{
	case E_OS_ACCESS:
		/* Handle access errors */
		/* ... add custom code here ... */
		break;

	case E_OS_ID:
		/* Handle invalid ID errors */
		/* ... add custom code here ... */
		break;

	case E_OS_STATE:
		/* Handle state errors, depending on the service ID */
		//            switch(serviceId)
		//            {
		//                case OSServiceId_SetAbsAlarm:
		//                    /* Handle SetAbsAlarm specific state error */
		//                    /* ... add custom code here ... */
		//                    break;
		//
		//                case OSServiceId_SetRelAlarm:
		//                    /* Handle SetRelAlarm specific state error */
		//                    /* ... add custom code here ... */
		//                    break;
		//
		//                case OSServiceId_GetEvent:
		//                    /* Handle GetEvent specific state error */
		//                    /* ... add custom code here ... */
		//                    break;
		//
		//                /* Add cases for other service IDs as needed */
		//                default:
		//                    /* Handle other state errors or undefined service IDs */
		//                    /* ... add custom code here ... */
		//                    break;
		//            }
		break;

		/* Add cases for other error statuses as needed */
	default:
		/* Handle other errors or undefined error statuses */
		/* ... add custom code here ... */
		break;
	}
}
/*
 *  * This is necessary for ST libraries
 *   */
FUNC(void, OS_CODE) assert_failed(uint8_t* file, uint32_t line)
																{
																}

