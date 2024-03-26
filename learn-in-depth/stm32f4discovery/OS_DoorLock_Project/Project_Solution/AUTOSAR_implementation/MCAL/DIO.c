/*
 * DIO.c
 *
 *  Created on: Feb 24, 2022
 *      Author: kkhalil
 */


#include "DIO.h"

#define LED_PB15_Set (*(volatile unsigned int*)(0x40020414)) |= (1U << (15))
#define LED_PB15_clear (*(volatile unsigned int*)(0x40020414)) &= ~(1U << (15))

#define GPIOA_IDR (*(volatile unsigned int*)(0x40020010)) // GPIOA Input Data Register address



unsigned char Dio_ReadChannel  (unsigned char ID)
{

	unsigned int DIO_Door_pinState ;
	
	//for stm32f103c8t6
	//	return (MCAL_GPIO_ReadPin(GPIO_Port_Used, ID));

	////for stm32f407Vg
	if(ID == DIO_Door_ID)
	{
		DIO_Door_pinState = (GPIOA_IDR & (1 << 0)) ? 1 : 0;

		return DIO_Door_pinState ;
	}

}
void  Dio_WriteChannel (unsigned char ID, unsigned char Level)
{
	//for stm32f103c8t6
	//	MCAL_GPIO_WritePin(GPIO_Port_Used, ID, Level);

	////for stm32f407Vg
	if(ID == LED_ID)
	{
		if (Level)
		{
			LED_PB15_Set;
		}else
		{
			LED_PB15_clear;
		}
	}
}
