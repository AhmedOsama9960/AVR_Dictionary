/*
 * Tim0_config.h
 *
 *  Created on: Aug 24, 2022
 *      Author: osama
 */

#ifndef MCAL_TIMER0_HEADER_TIM0_CONFIG_H_
#define MCAL_TIMER0_HEADER_TIM0_CONFIG_H_

/*
#define CLK_1        //no prescalling
#define CLK_8        //clkI/O/8 (From prescaler)
#define CLK_64       //clkI/O/64 (From prescaler)
#define CLK_256	 	 //clkI/O/256 (From prescaler)
#define CLK_1024	//clkI/O/1024(From prescaler)

 */

//setting the prescaller as per the requirement
#define Timer2_Prescaller		 CLK_64

/*-----------------------------------------------------------------------------------------*/
/* Inverting	 			Off Then on
 * Non_Inverting			On then off
 */
#define PWM_mode		Non_Inverting

#endif /* MCAL_TIMER0_HEADER_TIM0_CONFIG_H_ */
