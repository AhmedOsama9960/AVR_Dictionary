/*
 * DC_Motor_PRog.c
 *
 *  Created on: Aug 19, 2022
 *      Author: osama
 */

#include "../../../Common/macros.h"
#include "../../../Common/bitmath.h"
#include "../../../Common/typedef.h"

#include "../../../MCAL/DIO/DIO_interface.h"
#include "../../DC_Motor/Header/DC_Motor_interface.h"




void DCM_void1TransTurnOn(u8 Group, u8 TranPin)
{
	//Turn-on DCM
	DIO_VoidSetPinDir(Group, TranPin,output);
	DIO_VoidSetPinValue(Group,TranPin,high);
}


void DCM_void4TransTurnOn(u8 Group, u8 Trans1Pin, u8 Trans2Pin, u8 Trans3Pin, u8 Trans4Pin)
{
	DIO_VoidSetPortDir(Group,output);
	//Turn-on the DCM in a clockwise direction
	DIO_VoidSetPinValue(Group,Trans1Pin,high);
	DIO_VoidSetPinValue(Group,Trans2Pin,low);
	DIO_VoidSetPinValue(Group,Trans3Pin,low);
	DIO_VoidSetPinValue(Group,Trans4Pin,high);
}

void DCM_voidTurnOff(u8 Group, u8 PIN_NO)
{
	//turn off the whole port
	DIO_VoidSetPinDir(Group,PIN_NO,output);
	DIO_VoidSetPinValue(Group,PIN_NO,high);
}


void DCM_voidReverseDirection(u8 Group, u8 Trans1Pin, u8 Trans2Pin, u8 Trans3Pin, u8 Trans4Pin)
{
	DIO_VoidSetPortDir(Group,output);

	//in case you want to reverse
	DIO_VoidSetPinValue(Group,Trans1Pin,low);
	DIO_VoidSetPinValue(Group,Trans2Pin,high);
	DIO_VoidSetPinValue(Group,Trans3Pin,high);
	DIO_VoidSetPinValue(Group,Trans4Pin,low);


}
