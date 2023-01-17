/*
 * LCD_prog.c
 *
 *  Created on: Aug 11, 2022
 *      Author: osama
 */


#include "../../../Common/macros.h"
#include "../../../Common/typedef.h"
#include "../../../Common/bitmath.h"

#include "../../../MCAL/DIO/DIO_interface.h"
#include "../Header Files/LCD_config.h"
#include "../Header Files/LCD_private.h"
#include "../Header Files/LCD_interface.h"
#include <util/delay.h>

void LCD_void_SendCommand(u8 Local_Command)
{
	DIO_VoidSetPortValue(LCD_DataGroup,Local_Command);
DIO_VoidSetPinValue(LCD_ControlGroup,LCD_ControlRS,low);   // low command // high data
DIO_VoidSetPinValue(LCD_ControlGroup,LCD_ControlRW,low); // low read  /// high write
DIO_VoidSetPinValue(LCD_ControlGroup,LCD_ControlE,high);
_delay_us(1);
DIO_VoidSetPinValue(LCD_ControlGroup,LCD_ControlE,low);
_delay_ms(3);
}

void LCD_voidInit(void)
{
	// Select the Direction
	DIO_VoidSetPortDir(LCD_DataGroup,Max_Output);
	 // make those LCD pins as are output to receive commands
	DIO_VoidSetPinDir(LCD_ControlGroup,LCD_ControlRS,output);
	DIO_VoidSetPinDir(LCD_ControlGroup,LCD_ControlRW,output);
	DIO_VoidSetPinDir(LCD_ControlGroup,LCD_ControlE,output);
	//the initialization steps of the LCD from DataSheet
	_delay_ms(35);
	LCD_void_SendCommand(LCD_Set8Bit2Line5x8);
	_delay_ms(1);
	LCD_void_SendCommand(LCD_CursorON);
	_delay_ms(1);
	LCD_void_SendCommand(LCD_ClearDisplay);
	_delay_ms(2);
	LCD_void_SendCommand(LCD_EntryMode2);

}

void LCD_void_SendChar(char Local_Char)
{
	static u8 counter = 0;

		if (counter == 15)
		{
			LCD_voidGoTo(2,0);
		}
		DIO_VoidSetPortValue(LCD_DataGroup,Local_Char);
		counter++;
	DIO_VoidSetPinValue(LCD_ControlGroup,LCD_ControlRS,high); // high data
	DIO_VoidSetPinValue(LCD_ControlGroup,LCD_ControlRW,low);  //low read
	DIO_VoidSetPinValue(LCD_ControlGroup,LCD_ControlE,high);  //enable the reading sequence for the LCD
	_delay_us(1);
	DIO_VoidSetPinValue(LCD_ControlGroup,LCD_ControlE,low);
	_delay_ms(1);
}


void LCD_voidSendString(char *Reference_String)
{
	static u8 i = 0;
	while (Reference_String[i] != NotFound)
	{
		if (i == 15)
		{
			LCD_voidGoTo(2,0);
		}
			LCD_void_SendChar(Reference_String[i]);
		i++;
	}
}

void LCD_voidGoTo(u8 Local_Rowposition, u8 Local_Colomposition)
{
	u8 Position[] = {LCD_FirstRow,LCD_SecondRow};
	LCD_void_SendCommand(Position[Local_Rowposition-1]+Local_Colomposition-1);
	_delay_ms(10);
}

void LCD_Blink(void)
{
LCD_void_SendCommand(LCD_DisplayOFF);
_delay_ms(250);
LCD_void_SendCommand(LCD_DisplayON);
_delay_ms(250);
}

void LCD_Clear(void)
{
LCD_void_SendCommand(LCD_ClearDisplay);
_delay_ms(100);
}

