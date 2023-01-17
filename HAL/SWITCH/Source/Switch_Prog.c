/*
 * Switch_Prog.c
 *
 *  Created on: Aug 13, 2022
 *      Author: osama
 */

#include "../../../Common/macros.h"
#include "../../../Common/bitmath.h"
#include "../../../Common/typedef.h"

#include "../../../MCAL/DIO/DIO_interface.h"
#include "../Header/Switch_interface.h"



void SWITCH_Void_Set_ON(u8 Group,u8 Pin_No)
{
	//set the pin of the switch with input
	DIO_VoidSetPinDir(Group,Pin_No,input);
	//make the pull-up resistor active
	DIO_VoidSetPinValue(Group,Pin_No,high);
}


u8 SWITCH_u8_Read_Value(u8 Group,u8 Pin_No)
{
	//read the value of the pin of the switch
	u8 Read = 0;
	Read = DIO_u8ReadPinValue(Group,Pin_No);
	//return the value of it
	return Read;
}

