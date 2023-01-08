/*
 * Tim0_register.h
 *
 *  Created on: Aug 24, 2022
 *      Author: osama
 */

#ifndef MCAL_TIMER0_HEADER_TIM0_REGISTER_H_
#define MCAL_TIMER0_HEADER_TIM0_REGISTER_H_

#include "../../../Common/typedef.h"

#define TCCR0		*((volatile u8 *)0x53)
#define TCNT0	    *((volatile u8 *)0x52)
#define TIMSK0	    *((volatile u8 *)0x59)
#define TIFR0	    *((volatile u8 *)0x58)
#define OCR0	    *((volatile u8 *)0x5C)

/*for TCCR0 Register*/
//Select The Mode
#define WGM00	6
#define WGM01	3

//Force Compare Control
#define FOC0	7

//Select the output of Oc0 PIN
#define COM00	4
#define COM01	5

//Select The Prescalling
#define CS02	2
#define CS01	1
#define CS00    0

//Control The Enable Interrupt and Read The Flag In Normal Mode
#define TOIE	0
#define TOV0	0

//Control The Enable Interrupt and Read The Flag In CTC Mode
#define OCIE0 	1
#define OCF0	1


#endif /* MCAL_TIMER0_HEADER_TIM0_REGISTER_H_ */
