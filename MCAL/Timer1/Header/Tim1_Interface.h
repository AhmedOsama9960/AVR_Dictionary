/*
 * Tim1_Interface.h
 *
 *  Created on: Aug 30, 2022
 *      Author: osama
 */

#ifndef MCAL_TIMER1_HEADER_TIM1_INTERFACE_H_
#define MCAL_TIMER1_HEADER_TIM1_INTERFACE_H_

#include "../../../Common/typedef.h"
#include "Tim1_register.h"


void TIMER1_voidInitNormalMode(void);
void TIMER1_voidStop(void);

void ICU_voidSetTrigger(u8 Copy_u8Edge);
void ICU_voidEnableInterrupt(void);

void ICU_voidDisableInterrupt(void);
void ICU_CallbackFun(void (*ptr)(void));

void __vector_6(void) __attribute__((signal));
u16 ICU_u16Read_Capture_Register(void);

void Tim1_CallbackFunTimerOverFlow(void (*ptr_2)(void));
void __vector_9(void) __attribute__((signal));


#endif /* MCAL_TIMER1_HEADER_TIM1_INTERFACE_H_ */
