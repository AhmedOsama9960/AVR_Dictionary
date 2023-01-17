/*
 * LED_Prog.c
 *
 *  Created on: Aug 13, 2022
 *      Author: osama
 */
#include "../../../Common/macros.h"
#include "../../../Common/bitmath.h"
#include "../../../Common/typedef.h"

#include "../../../MCAL/DIO/DIO_interface.h"
#include "../header/LED_interface.h"

//set the pin high for LED startup
void LED_Set_void_High(u8 Group,u8 Pin_No)
{
DIO_VoidSetPinDir(Group,Pin_No,output);
DIO_VoidSetPinValue(Group,Pin_No,high);
}

//making the pin is low to turn-off the LED
void LED_Set_void_Low(u8 Group,u8 Pin_No)
{
	DIO_VoidSetPinDir(Group,Pin_No,output);
}

//turn-on pins of the port for LED startup
void LED_Void_Set_Port(u8 Group, u8 Port_Value)
{
DIO_VoidSetPortDir(Group,Port_Value);
DIO_VoidSetPortValue(Group,high);
}

void LED_void_Toggle(u8 Group, u8 Pin_No)
{
	DIO_VoidSetPinValue(Group,Pin_No,high);
	DIO_VoidSetPinValue(Group,Pin_No,low);
}
