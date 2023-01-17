/*
 * LCD_interface.h
 *
 *  Created on: Aug 11, 2022
 *      Author: osama
 */

#ifndef HAL_LCD_HEADER_FILES_LCD_INTERFACE_H_
#define HAL_LCD_HEADER_FILES_LCD_INTERFACE_H_

#include "../../../Common/typedef.h"

void LCD_void_SendCommand(u8 Local_Command);
void LCD_void_SendChar(char Local_Char);
void LCD_voidInit(void);

void LCD_voidSendString(char *Reference_String);
void LCD_voidGoTo(u8 Local_Rowposition, u8 Local_Colomposition);
void LCD_Blink(void);
void LCD_Clear(void);


#endif /* HAL_LCD_HEADER_FILES_LCD_INTERFACE_H_ */
