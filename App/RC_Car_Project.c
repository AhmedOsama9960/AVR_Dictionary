///*
// * RC_Car_Project.c
// *
// *  Created on: Oct 15, 2022
// *      Author: osama
// */
//
///* Name : Ahmed Osama Mostafa Ahmed
// */
//
//
///*-------------------------------------Preprocessor phase [Libraries & Drivers]---------------------------------------------*/
//#include "../Common/bitmath.h"
//#include "../Common/typedef.h"
//#include "../Common/macros.h"
//
//
//#include "../Header_Files/Config.h"
//#include "../Header_Files/Interface.h"
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
//#include <util/delay.h>
//
//
//
//
///*-------------------------------------------------Main Function------------------------------------------------------*/
//int main(void)
//{
//	/*creating all needed variables*/
//	/*for ultra sonic*/
//	u16 Ultra_Distance = 0;
//
//	/*for the system exchanges */
//	u8 flag = 1;
//
//	/*for the BlueTooth module*/
//	u8 action = 0;
//	/* for IR sensor*/
//	u8 IR_Sensor_Right = 0;
//	u8 IR_Sensor_Left  = 0;
//
//								/*	DIO Direction [States] Of each Pins	*/
//
//	DIO_VoidSetPinDir(group_D,PIN_D0,input);	// for UART RX
//	DIO_VoidSetPinDir(group_D,PIN_D5,output);	// for Servo Motor [OC1A]
//
//	/* To be Noted ------ [Right-Motor has PinA0 & PINA1]---[Left-Motor has PinA1 & PINA3]    */
//
//	DIO_VoidSetPortDir(group_A,First_Four_Bits); /*For Motors*/
//
//								/* Initialize the sensors and Peripherals */
//	UART_voidInterruptInit();
//	UART_voidStartReceive();
//	Ultrasonic_voidInit_Timer_InterruptMode(group_D,PIN_D7,INT_0);		// init for ultrasonic
//	Servo_voidInit();
//	IR_Sensor_void_init(group_B,PIN_B0);	//for the right sensor
//	IR_Sensor_void_init(group_B,PIN_B1);	//for the left sensor
//
//
//	while(1){
//		UART_ReceiveCallBackFunction(&action);					// receive the action from the mobile
//	/*-----------------------------	*//* for BlueTooth Control*//*----------------------------------------------*/
//	if(flag == Bluetooth_Mode)
//	{
//		switch(action)
//		{
//		case Forward:
//				DIO_VoidSetPinValue(group_A,PIN_A0,high);
//				DIO_VoidSetPinValue(group_A,PIN_A2,high);
//			break;
//		case Reverse:
//				DIO_VoidSetPinValue(group_A,PIN_A1,high);
//				DIO_VoidSetPinValue(group_A,PIN_A3,high);
//			break;
//
//		case Left:
//				DIO_VoidSetPinValue(group_A,PIN_A0,high);
//			break;
//
//		case Right:
//				DIO_VoidSetPinValue(group_A,PIN_A2,high);
//			break;
//		case Stop:
//				DIO_VoidSetPortValue(group_A,No_Power);
//			break;
//		case Front_Light:
//				flag++;
//			break;
//		}
//	}
///*-----------------------------	*//* UltraSonic Mode and Servo *//*----------------------------------------------*/
//	else if (flag == Avoid_Obstacle)
//	{
//		if(action == Back_Light)				//to change the modes through the mobile app
//		{
//					flag++;
//		}
//		Servo_M_Values(Correct_angle);
//		DIO_VoidSetPinValue(group_A,PIN_A0,high);
//		DIO_VoidSetPinValue(group_A,PIN_A2,high);
//		Trig(group_D,PIN_D7);					// to send the signals each 15us
//		Ultra_Distance = Ultra_Distance_Calc();
//		if (Ultra_Distance < Obstacles)
//		{
//			 obstacle_detection();
//		}
//		else
//		{
//			//Misra Rule
//		}
//	}
//
///*------------------------------------*//* Line Follower Mode *//*--------------------------------------------*/
//	else if (flag == Line_Follower)
//	{
//		if(action == Horn_ON)			//to change the modes through the mobile app
//				flag=Bluetooth_Mode;
//
//		IR_Sensor_Right = IR_Sensor_u8_SignalReceive(group_B,PIN_B0);
//		IR_Sensor_Left  = IR_Sensor_u8_SignalReceive(group_B,PIN_B1);
//
//
//		if(IR_Sensor_Left == No_Interception && IR_Sensor_Right == No_Interception)
//				{
//
//					DIO_VoidSetPinValue(group_A,PIN_A0,high);
//					DIO_VoidSetPinValue(group_A,PIN_A2,high);
//				}
//		else if(IR_Sensor_Left == Interception || IR_Sensor_Right == Interception)
//				{
//					/*make the car stop in this situation to fix it*/
//					DIO_VoidSetPortValue(group_A,No_Power);
//					line_Follower(IR_Sensor_Right,IR_Sensor_Left);
//				}
//	}
//	}
//	return 0;
//}
