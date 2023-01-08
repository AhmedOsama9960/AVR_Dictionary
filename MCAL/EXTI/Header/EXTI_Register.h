/*
 * External_Interrupt_Register.h
 *
 *  Created on: Aug 17, 2022
 *      Author: osama
 */


#ifndef MCAL_EXTI_HEADER_EXTI_REGISTER_H_
#define MCAL_EXTI_HEADER_EXTI_REGISTER_H_

#include "../../../Common/typedef.h"

#define MCUCR 	  (*(volatile u8*)0x55)
#define MCUCSR    (*(volatile u8*)0x54)
#define GICR	  (*(volatile u8*)0x5b)
#define GIFR	  (*(volatile u8*)0x5A)


#define INT0		6
#define INT1		7
#define INT2		5

#define INTF0		6
#define INTF1		7
#define INTF2		5




#endif /* MCAL_EXTI_HEADER_EXTI_REGISTER_H_ */
