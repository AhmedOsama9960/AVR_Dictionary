/*
 * TIm0_Private.h
 *
 *  Created on: Aug 24, 2022
 *      Author: osama
 */

#ifndef MCAL_TIMER0_HEADER_TIM0_PRIVATE_H_
#define MCAL_TIMER0_HEADER_TIM0_PRIVATE_H_

/*defining all the options to select the prescaller*/

#define CLK_1    1     //no prescalling
#define CLK_8    2     //clkI/O/8 (From prescaler)
#define CLK_64   3     //clkI/O/64 (From prescaler)
#define CLK_256	 4	   //clkI/O/256 (From prescaler)
#define CLK_1024 5	   //ClkI/O/1024 (From prescaler)


/*----------------------------------------------------------*/
//Select the mode in PWM
#define Inverting		1
#define Non_Inverting	2

#endif /* MCAL_TIMER0_HEADER_TIM0_PRIVATE_H_ */
