/*
 * DIO.h
 *
 *  Created on: Feb 24, 2022
 *      Author: kkhalil
 */

#ifndef MCAL_DIO_H
#define MCAL_DIO_H

//#include "stm32f103x8_gpio_driver.h"

unsigned char Dio_ReadChannel  (unsigned char ID);
void		  Dio_WriteChannel (unsigned char ID, unsigned char Level);

#define PORTA 0
#define PORTB 1

//DIO IDs (PortB) LED
#define LED_ID	  15
#define LED_GPIO_Port_Used  PORTB


//DIO IDs (PortA) DoorLock
#define DIO_Door_ID  0
#define DoorLock_GPIO_Port_Used  PORTA



#endif
