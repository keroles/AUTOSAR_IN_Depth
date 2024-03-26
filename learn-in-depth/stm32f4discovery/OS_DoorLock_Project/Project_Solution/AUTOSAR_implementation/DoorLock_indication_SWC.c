/*
 * DoorLock_indication_SWC.c
 *
 *  Created on: Feb 27, 2022
 *      Author: kkhalil
 */

#include "RTE_gen/Rte_DoorLock_indication_SWC.h"

#define LEDON  1
#define LEDOFF 0
void DoorLock_indication_runnable(void)
{
	unsigned char Door_State = 0 ;

	//Read DoorState from RTE SR Interface
	Door_State = Rte_IRead_DoorLock_indication_SWC_DoorLock_indication_RP_SR_DoorState_DoorState();

	if (Door_State == 0)
	{
		//Door is Closed
		//Invoke Operation "Led_Switch(LEDSrate);"
		Rte_Call_DoorLock_indication_SWC_RP_CS_Led_Switch_Led_Switch(LEDOFF);
	}else
	{
		//Door is opened
		//Invoke Operation "Led_Switch(LEDSrate);"
		Rte_Call_DoorLock_indication_SWC_RP_CS_Led_Switch_Led_Switch(LEDON);


	}
}
