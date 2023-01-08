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
void Tim2_voidInitnormal_mode(u8 preload);
void Tim2_callbackfunctionNormal(void(*PTF)(void));
void __vector_5(void) __attribute__((signal));

//Timer0 In CTC Mode
void Tim2_voidInitCTC(u8 Local_Compare_value);
void Tim2_callbackfunctionCTC(void(*PTF)(void));
void __vector_4(void) __attribute__((signal));

//Set preload Value
void Tim2_voidSetPreload(u8 Preload);

//TIM0 PWM Mode

void Tim2_voidFast_PWMInit(u8 Dutycycle);

//set dutycycle during runtime
void Tim2_voidFPWM_SetDutyCycle(u8 Dutycycle);


#endif /* MCAL_TIMER0_HEADER_TIM0_INTERFACE_H_ */
