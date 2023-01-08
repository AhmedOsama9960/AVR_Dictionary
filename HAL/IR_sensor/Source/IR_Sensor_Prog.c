/*
 * IR_Sensor_Prog.c
 *
 *  Created on: Oct 15, 2022
 *      Author: osama
 */

#include "../../../Common/bitmath.h"
#include "../../../Common/typedef.h"
#include "../../../Common/macros.h"

#include "../../../MCAL/DIO/DIO_interface.h"

void IR_Sensor_void_init(u8 group_No, u8 Pin_No)
{
	/*set the pin as input to receive the signal through it*/
	DIO_VoidSetPinDir(group_No,Pin_No,input);
}

u8 IR_Sensor_u8_SignalReceive(u8 group_No, u8 Pin_No)
{
	return DIO_u8ReadPinValue(group_No, Pin_No);
}
