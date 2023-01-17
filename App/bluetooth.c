///*
// * bluetooth.c
// *
// *  Created on: Oct 18, 2022
// *      Author: osama
// */
//
//
//#include "../MCAL/DIO/DIO_interface.h"
//#include "../MCAL/UART/Header/UART_Interface.h"
//#include "../MCAL/GIE/Header/GIE_Interface.h"
//#include "../MCAL/EXTI/Header/EXTI_Interface.h"
//#include "../MCAL/Timer1/Header/Tim1_Interface.h"
//#include "../HAL/DC_Motor/Header/DC_Motor_interface.h"
//#include "../HAL/IR_sensor/Header/IR_Sensor_Interface.h"
//#include "../HAL/Servo_Motor/Header/Servo_M_interface.h"
//#include "../HAL/UltraSonic_Sensor/Header/UltraSonic_interface.h"
//
//#define Forward 		'F'
//#define	Reverse			'B'
//#define Left			'L'
//#define Right			'R'
//#define Stop			'S'
//#define No_Power		0
//
//void main (){
//u8 action;
//DIO_VoidSetPortDir(group_A,0xff);
//UART_voidInit();
//
//while(1){
//
//action = UART_u8Receive();						// receive the action from the mobile
//		switch(action)
//		{
//		case Forward:
//					DIO_VoidSetPinValue(group_A,PIN_A0,high);
//					DIO_VoidSetPinValue(group_A,PIN_A2,high);
//						break;
//		case Reverse:
//				DIO_VoidSetPinValue(group_A,PIN_A1,high);
//				DIO_VoidSetPinValue(group_A,PIN_A3,high);
//			break;
//
//		case Left:
//				DIO_VoidSetPinValue(group_A,PIN_A0,high);
//				break;
//		case Right:
//
//				DIO_VoidSetPinValue(group_A,PIN_A2,high);
//			break;
//		case Stop:
//			DIO_VoidSetPortValue(group_A,No_Power);
//			break;
//		}
//}
//}
