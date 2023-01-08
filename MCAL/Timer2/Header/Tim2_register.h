/*
 * Tim0_register.h
 *
 *  Created on: Aug 24, 2022
 *      Author: osama
 */

#ifndef MCAL_TIMER0_HEADER_TIM0_REGISTER_H_
#define MCAL_TIMER0_HEADER_TIM0_REGISTER_H_

#include "../../../Common/typedef.h"

#define TCCR2		*((volatile u8 *)0x45)
#define TCNT2	    *((volatile u8 *)0x44)
#define TIMSK	    *((volatile u8 *)0x59)
#define TIFR	    *((volatile u8 *)0x58)
#define OCR2	    *((volatile u8 *)0x43)

/*for TCCR0 Register*/
//Select The Mode
#define WGM20	6
#define WGM21	3

//Force Compare Control
#define FOC2	7

//Select the output of Oc0 PIN
#define COM20	4
#define COM21	5

//Select The Prescalling
#define CS22	2
#define CS21	1
#define CS20    0

//Control The Enable Interrupt and Read The Flag In Normal Mode
#define TOIE2	6
#define TOV2	6

//Control The Enable Interrupt and Read The Flag In CTC Mode
#define OCIE2 	7
#define OCF2	7


#endif /* MCAL_TIMER0_HEADER_TIM0_REGISTER_H_ */
