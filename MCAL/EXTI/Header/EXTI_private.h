/*
 * EXTI_private.h
 *
 *  Created on: Aug 17, 2022
 *      Author: osama
 */

#ifndef MCAL_EXTI_HEADER_EXTI_PRIVATE_H_
#define MCAL_EXTI_HEADER_EXTI_PRIVATE_H_



#define EXIT0_Group 	group_D
#define EXIT1_Group		group_D
#define EXIT2_Group		group_B

#define EXIT0_PIN 		PIN_D2
#define EXIT1_PIN       PIN_D3
#define EXIT2_PIN		PIN_B2

#define EXIT_LOW			0
#define EXIT_OnChange 		1
#define EXIT_fallingedge	2
#define EXIT_risingedge		3


//Interrupt Sense Control Bits

#define ISC00		0
#define ISC01		1

#define ISC10		2
#define ISC11		3

#define ISC2		6


//Initialization Numbers
#define EXIT_0      0
#define EXIT_1      1
#define EXIT_2      2


#endif /* MCAL_EXTI_HEADER_EXTI_PRIVATE_H_ */
