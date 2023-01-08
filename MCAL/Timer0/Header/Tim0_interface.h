/*
 * Tim0_interface.h
 *
 *  Created on: Aug 24, 2022
 *      Author: osama
 */

#ifndef MCAL_TIMER0_HEADER_TIM0_INTERFACE_H_
#define MCAL_TIMER0_HEADER_TIM0_INTERFACE_H_

#include "../../../Common/typedef.h"

//Timer0 In Normal Mode
void Tim0_voidInitnormal_mode(u8 preload);
void Tim0_callbackfunctionNormal(void(*PTF)(void));
void __vector_11(void) __attribute__((signal));

//Timer0 In CTC Mode
void Tim0_voidInitCTC(u8 Local_Compare_value);
void Tim0_callbackfunctionCTC(void(*PTF)(void));
void __vector_10(void) __attribute__((signal));

//Set preload Value
void Tim0_voidSetPreload(u8 Preload);

//TIM0 PWM Mode

void Tim0_voidFast_PWMInit(u8 Dutycycle);

//set dutycycle during runtime
void Tim0_voidFPWM_SetDutyCycle(u8 Dutycycle);

#endif /* MCAL_TIMER0_HEADER_TIM0_INTERFACE_H_ */
