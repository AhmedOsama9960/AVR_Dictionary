/*
 * DIO_program.c
 *
 *  Created on: Aug 8, 2022
 *      Author: osama
 */
#include "../../Common/typedef.h"
#include "../../Common/bitmath.h"
#include "../../Common/macros.h"
#include "DIO_private.h"
#include "DIO_interface.h"
#include "DIO_register.h"
#include "util/delay.h"


void DIO_VoidSetPinDir(u8 Group, u8 PinNumber, u8 status)
{
	if(status == input)
{
	switch (Group)
	{
	case group_A :
		voidclear(DIO_DDRA,PinNumber);
		break;
	case group_B :
		voidclear(DIO_DDRB,PinNumber);
		break;
	case group_C :
		voidclear(DIO_DDRC,PinNumber);
		break;
	case group_D :
		voidclear(DIO_DDRD,PinNumber);
		break;
	}
}
	else if(status == output)
{
	switch (Group)
	{
	case group_A :
		voidset_bit(DIO_DDRA,PinNumber);
		break;
	case group_B :
		voidset_bit(DIO_DDRB,PinNumber);
		break;
	case group_C :
		voidset_bit(DIO_DDRC,PinNumber);
		break;
	case group_D :
		voidset_bit(DIO_DDRD,PinNumber);
		break;
	}
}
}
void DIO_VoidSetPinValue(u8 Group, u8 PinNumber, u8 output_status)
{
	if(output_status == low)
	{
		switch (Group)
		{
		case group_A :
			voidclear(DIO_PORTA,PinNumber);
			break;
		case group_B :
			voidclear(DIO_PORTB,PinNumber);
			break;
		case group_C :
			voidclear(DIO_PORTC,PinNumber);
			break;
		case group_D :
			voidclear(DIO_PORTD,PinNumber);
			break;
		}
	}
		else if(output_status == high)
	{
		switch (Group)
		{
		case group_A :
			voidset_bit(DIO_PORTA , PinNumber);
			break;
		case group_B :
			voidset_bit(DIO_PORTB,PinNumber);
			break;
		case group_C :
			voidset_bit(DIO_PORTC,PinNumber);
			break;
		case group_D :
			voidset_bit(DIO_PORTD,PinNumber);
			break;
		}
	}
}

u8 DIO_u8ReadPinValue(u8 Group, u8 PinNumber)
{
	u8 Local_Return_Data = 0;
	switch (Group)
			{
			case group_A :
				Local_Return_Data = u8read(DIO_PINA,PinNumber);
				break;
			case group_B :
				Local_Return_Data = u8read(DIO_PINB,PinNumber);
				break;
			case group_C :
				Local_Return_Data = u8read(DIO_PINC,PinNumber);
				break;
			case group_D :
				Local_Return_Data = u8read(DIO_PIND,PinNumber);
				break;
			}
	return Local_Return_Data;
}

void DIO_VoidSetPortDir(u8 Group, u8 Local_Dir_Status)
{
	switch (Group)
		{
		case group_A :
			DIO_DDRA = Local_Dir_Status;
			break;
		case group_B :
			DIO_DDRB = Local_Dir_Status;
			break;
		case group_C :
			DIO_DDRC = Local_Dir_Status;
			break;
		case group_D :
			DIO_DDRD = Local_Dir_Status;
			break;
		}


}

void DIO_VoidSetPortValue(u8 Group, u8 Output_Status)
{
	switch (Group)
			{
			case group_A :
				DIO_PORTA = Output_Status;
				break;
			case group_B :
				DIO_PORTB = Output_Status;
				break;
			case group_C :
				DIO_PORTC = Output_Status;
				break;
			case group_D :
				DIO_PORTD = Output_Status;
				break;
			}
}

u8 DIO_u8ReadPortValue(u8 Group, u8 Local_Read_Value)
{
	u8 Local_Return_Data ;
	switch (Group)
				{
				case group_A :
					DIO_PINA = Local_Read_Value;
					break;
				case group_B :
					DIO_PINB = Local_Read_Value;
					break;
				case group_C :
					DIO_PINC = Local_Read_Value;
					break;
				case group_D :
					DIO_PIND = Local_Read_Value;
					break;
				}
	return Local_Return_Data;
}

void Toggle_Port(u8 Group, u8 Port_Value)
{
	//set port value with specific pins to make them output
	DIO_VoidSetPortDir(Group,Port_Value);
	//set them high
	DIO_VoidSetPortValue(Group,Port_Value);
	//delay one second
	_delay_ms(1000);
	//make them set off again
	DIO_VoidSetPortValue(Group,Zero_Output);
	//delay one second
	_delay_ms(1000);
}
