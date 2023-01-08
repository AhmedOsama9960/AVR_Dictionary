/*
 * DIO_interface.h
 *
 *  Created on: Aug 8, 2022
 *      Author: osama
 */

#ifndef MCAL_DIO_DIO_INTERFACE_H_
#define MCAL_DIO_DIO_INTERFACE_H_
#include "../../Common/typedef.h"
#include "DIO_private.h"
#include "DIO_interface.h"
#include "DIO_register.h"

//For A Specific PIN
void DIO_VoidSetPinDir(u8 Group, u8 PinNumber, u8 status);
void DIO_VoidSetPinValue(u8 Group, u8 PinNumber, u8 output_status);
u8 DIO_u8ReadPinValue(u8 Group, u8 PinNumber);

//For A Specific PORT Values as a Whole
void DIO_VoidSetPortDir(u8 Group, u8 Local_Dir_Status);
void DIO_VoidSetPortValue(u8 Group, u8 Output_Status);
u8 DIO_u8ReadPortValue(u8 Group, u8 Local_Read_Value);

//For A Specific PORT TO Toggle As a Whole
void Toggle_Port(u8 Group, u8 Port_Value);

#endif /* MCAL_DIO_DIO_INTERFACE_H_ */
