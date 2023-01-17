/*
 * Temp_Program.c
 *
 *  Created on: Aug 23, 2022
 *      Author: osama
 */

#include"../../../MCAL/ADC/Header/ADC_Interface.h"

void temp_voidinit(void)
{
	ADC_voidInit();
}

/* Instructions :
 *
	// call for ADC_read channel
	//equation to convert from digital to analog
	//equation to convert from analog to signal(temp)
	//return temp
 */
u8 temp_u8get_temp_(u8 channel)
{
	u16 Digital_Data = ADC_u16Readdata(channel);
 	u16 Analog_data  = (u16)(((u32)Digital_Data * 5000UL)/1024);
 	u8 temp_signal = Analog_data / 10 ; 			//check about this question for each LM35
 	return temp_signal;
}
