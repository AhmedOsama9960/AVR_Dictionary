/*
 * DIO_register.h

 *
 *  Created on: Aug 8, 2022
 *      Author: osama
 */


#include "../../Common/typedef.h"

#define DIO_PORTA *(volatile u8*)0x3B
#define DIO_DDRA  *(volatile u8*)0x3A
#define DIO_PINA  *(volatile u8*)0x39

#define DIO_PORTB *(volatile u8*)0x38
#define DIO_DDRB  *(volatile u8*)0x37
#define DIO_PINB  *(volatile u8*)0x36

#define DIO_PORTC *(volatile u8*)0x35
#define DIO_DDRC  *(volatile u8*)0x34
#define DIO_PINC  *(volatile u8*)0x33

#define DIO_PORTD *(volatile u8*)0x32
#define DIO_DDRD  *(volatile u8*)0x31
#define DIO_PIND  *(volatile u8*)0x30

#ifndef MCAL_DIO_DIO_REGISTER_H_
#define MCAL_DIO_DIO_REGISTER_H_

#endif /* MCAL_DIO_DIO_REGISTER_H_ */
