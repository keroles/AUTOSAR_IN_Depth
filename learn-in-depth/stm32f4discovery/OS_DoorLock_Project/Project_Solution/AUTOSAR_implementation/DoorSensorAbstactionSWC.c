/*
 * DoorSensorAbstactionSWC.c
 *
 *  Created on: Feb 27, 2022
 *      Author: kkhalil
 */


#include "RTE_gen/Rte_DoorSensorAbstactionSWC.h"
#include "MCAL/DIO.h"

#define LEDON  0
#define LEDOFF 1
/*****************************************************
 * Runnable: 	ReadDoorSensor
 * Period:		0.01
 *****************************************************/
void ReadDoorSensor_runnable(void)
{
	unsigned int  DoorState =0 ;


	//READ GPIO Pin 3
	DoorState = Dio_ReadChannel(DIO_Door_ID);

	//Write DoorState to RTE SR IF
	Rte_IWrite_DoorSensorAbstactionSWC_ReadDoorSensor_PP_SR_DoorState(DoorState);
}

/*****************************************************
 * Port: 		PP_CS_LEDSwitch
 * Interface:	IF_CS_LED
 * Operation:	Led_Switch
 *****************************************************/
Std_ReturnType Led_Switch_runnable(myuint8 LedState)
{
	if (LedState == LEDON)
	{
		Dio_WriteChannel(LED_ID, LEDON);
		return RTE_E_IF_CS_LED_E_ok;

	}else if (LedState == LEDOFF)
	{
		Dio_WriteChannel(LED_ID, LEDOFF);
		return RTE_E_IF_CS_LED_E_ok;
	}else
	{
		return RTE_E_IF_CS_LED_E_Not_ok ;
	}

}












