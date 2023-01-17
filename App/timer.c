///*
// * timer.c
// *
// *  Created on: Aug 30, 2022
// *      Author: osama
// */
//
//#include "../Common/macros.h"
//#include "../Common/typedef.h"
//
//#include "../MCAL/DIO/DIO_interface.h"
//#include "../MCAL/Timer0/Header/Tim0_interface.h"
//#include "../HAL/Servo_Motor/Header/Servo_M_interface.h"
//#include "../HAL/SWITCH/Header/Switch_interface.h"
//#include "../MCAL/GIE/Header/GIE_Interface.h"
//#include <util/delay.h>
//
//void StartMotor(void);
//
//void main()
//{
//	//init for GIE
//	GIE_voidEnable_GIE();
//
//	//init for TIMER 0
//	Tim0_voidInitCTC(250);
//
//	DIO_VoidSetPortDir(group_A,Max_Output);
//	DIO_VoidSetPinDir(group_B,PIN_B3,output);
//	Tim0_callbackfunctionCTC(StartMotor);
//while(1)
//{
//	DIO_VoidSetPortValue(group_A,Max_Output);
//	_delay_ms(100);
//
//}
//}
//
//void StartMotor(void)
//{
//	static u8 counter = 0;
//	counter++;
//	if (counter == 250)
//		{
//		DIO_VoidSetPortValue(group_A,low);
//		_delay_ms(100);
//		counter = 0;
//		}
//
//}
