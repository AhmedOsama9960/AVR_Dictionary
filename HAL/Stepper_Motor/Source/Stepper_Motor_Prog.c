/*
 * Stepper_Motor_Prog.c
 *
 *  Created on: Aug 29, 2022
 *      Author: osama
 */

#include "../../../Common/bitmath.h"
#include "../../../Common/macros.h"
#include "../../../Common/typedef.h"

#include "../Header/Step_Motor_Interface.h"
#include "../../../MCAL/DIO/DIO_interface.h"
#include <util/delay.h>


void Stepper_Motor_Full_Coil__void_init(u8 Group, u16 No_of_rotations)
{
	DIO_VoidSetPortDir(Group,Max_Output);
	for(u16 i = 0; i<(No_of_rotations*250); i++)
	{
	DIO_VoidSetPinValue(Group,PIN_A0,high);
	DIO_VoidSetPinValue(Group,PIN_A1,low);
	DIO_VoidSetPinValue(Group,PIN_A2,low);
	DIO_VoidSetPinValue(Group,PIN_A3,low);
	_delay_ms(2);

	DIO_VoidSetPinValue(Group,PIN_A0,low);
	DIO_VoidSetPinValue(Group,PIN_A1,high);
	DIO_VoidSetPinValue(Group,PIN_A2,low);
	DIO_VoidSetPinValue(Group,PIN_A3,low);
	_delay_ms(2);

	DIO_VoidSetPinValue(Group,PIN_A0,low);
	DIO_VoidSetPinValue(Group,PIN_A1,low);
	DIO_VoidSetPinValue(Group,PIN_A2,high);
	DIO_VoidSetPinValue(Group,PIN_A3,low);
	_delay_ms(2);

	DIO_VoidSetPinValue(Group,PIN_A0,low);
	DIO_VoidSetPinValue(Group,PIN_A1,low);
	DIO_VoidSetPinValue(Group,PIN_A2,low);
	DIO_VoidSetPinValue(Group,PIN_A3,high);
	_delay_ms(2);
	}
}

