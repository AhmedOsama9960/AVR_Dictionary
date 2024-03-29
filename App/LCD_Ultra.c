///*
// * LCD_16x2_C_file.c
// * http://www.electronicwings.com
// *
// */
//
//
///*
// * LCD_16x2_H_file.h
// * http://www.electronicwings.com
// *
// */
//
//#ifndef LCD_16x2_H_H_					/* Define library H file if not defined */
//#define LCD_16x2_H_H_
//
//#define F_CPU 8000000UL					/* Define CPU Frequency e.g. here its 8MHz */
//#include <avr/io.h>						/* Include AVR std. library file */
//#include <util/delay.h>					/* Include Delay header file */
//#include "../HAL/UltraSonic_Sensor/Header/UltraSonic_interface.h"
//#define LCD_Data_Dir DDRC				/* Define LCD data port direction */
//#define LCD_Command_Dir DDRA			/* Define LCD command port direction register */
//#define LCD_Data_Port PORTC				/* Define LCD data port */
//#define LCD_Command_Port PORTA			/* Define LCD data port */
//#define RS PA5							/* Define Register Select (data reg./command reg.) signal pin */
//#define RW PA6							/* Define Read/Write signal pin */
//#define EN PA7							/* Define Enable signal pin */
//
//void LCD_Command (char);				/* LCD command write function */
//void LCD_Char (char);					/* LCD data write function */
//void LCD_Init (void);					/* LCD Initialize function */
//void LCD_String (char*);				/* Send string to LCD function */
//void LCD_String_xy (char,char,char*);	/* Send row, position and string to LCD function */
//
//
//#endif									/* LCD_16x2_H_FILE_H_ */
//
//
//void LCD_Command (char cmd)							/* LCD command write function */
//{
//	LCD_Data_Port = cmd;							/* Write command data to LCD data port */
//	LCD_Command_Port &= ~((1<<RS)|(1<<RW));			/* Make RS LOW (command reg.), RW LOW (Write) */
//	LCD_Command_Port |= (1<<EN);					/* High to Low transition on EN (Enable) */
//	_delay_us(1);
//	LCD_Command_Port &= ~(1<<EN);
//	_delay_ms(3);									/* Wait little bit */
//}
//
//void LCD_Char (char char_data)						/* LCD data write function */
//{
//	LCD_Data_Port = char_data;						/* Write data to LCD data port */
//	LCD_Command_Port &= ~(1<<RW);					/* Make RW LOW (Write) */
//	LCD_Command_Port |= (1<<EN)|(1<<RS);			/* Make RS HIGH (data reg.) and High to Low transition on EN (Enable) */
//	_delay_us(1);
//	LCD_Command_Port &= ~(1<<EN);
//	_delay_ms(1);									/* Wait little bit */
//}
//
//void LCD_Init (void)								/* LCD Initialize function */
//{
//	LCD_Command_Dir |= (1<<RS)|(1<<RW)|(1<<EN);		/* Make LCD command port direction as o/p */
//	LCD_Data_Dir = 0xFF;							/* Make LCD data port direction as o/p */
//
//	_delay_ms(20);									/* LCD power up time to get things ready, it should always >15ms */
//	LCD_Command (0x38);								/* Initialize 16X2 LCD in 8bit mode */
//	LCD_Command (0x0C);								/* Display ON, Cursor OFF command */
//	LCD_Command (0x06);								/* Auto Increment cursor */
//	LCD_Command (0x01);								/* Clear LCD command */
//	LCD_Command (0x80);								/* 8 is for first line and 0 is for 0th position */
//}
//
//void LCD_String (char *str)							/* Send string to LCD function */
//{
//	int i;
//	for(i=0;str[i]!=0;i++)							/* Send each char of string till the NULL */
//	{
//		LCD_Char (str[i]);							/* Call LCD data write */
//	}
//}
//
//void LCD_String_xy (char row, char pos, char *str)	/* Send string to LCD function */
//{
//	if (row == 1)
//		LCD_Command((pos & 0x0F)|0x80);				/* Command of first row and required position<16 */
//	else if (row == 2)
//		LCD_Command((pos & 0x0F)|0xC0);				/* Command of Second row and required position<16 */
//	LCD_String(str);								/* Call LCD string function */
//}
//
//
//int main()
//{
//	char string[10];
//	u16 distance;
//	Ultrasonic_voidInit_Timer_InterruptMode(4,7,0);
//	LCD_Init();
//
//	while(1)
//		{
//			Trig(4,7);
//			distance = Ultra_Distance_Calc();
//
//			LCD_String_xy(1, 0, "Ultrasonic");
//			itoa(distance,string,10);
//			//dtostrf(distance, 2, 2, string);/* Convert distance into string */
//			strcat(string, " cm   ");
//			LCD_String_xy(2, 0, "Dist = ");
//			LCD_String_xy(2, 7, string);	/* Print distance on LDC16x2 */
//
//		}
//	return 0;
//}
