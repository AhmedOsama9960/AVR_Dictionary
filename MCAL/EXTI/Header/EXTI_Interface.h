/*
 * EXTI_Interface.h
 *
 *  Created on: Aug 17, 2022
 *      Author: osama
 */

#ifndef MCAL_EXTI_HEADER_EXTI_INTERFACE_H_
#define MCAL_EXTI_HEADER_EXTI_INTERFACE_H_

void EXIT_0callback_function(void(*ptf)(void));
void __vector_1(void) __attribute__((signal));

void EXIT_1callback_function(void(*ptf)(void));
void __vector_2(void) __attribute__((signal));

void EXIT_2callback_function(void(*ptf)(void));
void __vector_3(void) __attribute__((signal));

void EXTI0_voidInit0(void);

void EXIT_voidINIT(u8 Init_No, u8 Control);
void EXIT_voidSetcontrol(u8 init_No ,u8 Control);

#endif /* MCAL_EXTI_HEADER_EXTI_INTERFACE_H_ */
