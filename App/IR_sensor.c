///*
// * IR_sensor.c
// *
// *  Created on: Oct 25, 2022
// *      Author: osama
// */
//
//
//#include "../MCAL/DIO/DIO_interface.h"
//#include "../HAL/IR_sensor/Header/IR_Sensor_Interface.h"
//#include "../Common/typedef.h"
//#include "../Common/macros.h"
//#include "../Common/bitmath.h"
//
//
//void main()
//{
//		DIO_VoidSetPortDir(group_A,0x0f);
//		IR_Sensor_void_init(group_B,PIN_B0);	//for the right sensor
//		IR_Sensor_void_init(group_B,PIN_B1);	//for the left sensor
//
//		while(1)
//		{
//				if(IR_Sensor_u8_SignalReceive(group_B,PIN_B0))
//				{
//					DIO_VoidSetPinValue(group_A,PIN_A0,low);
//				}
//				else
//					DIO_VoidSetPinValue(group_A,PIN_A0,high);
//				if(IR_Sensor_u8_SignalReceive(group_B,PIN_B1))
//								{
//									DIO_VoidSetPinValue(group_A,PIN_A2,low);
//								}
//				else
//					DIO_VoidSetPinValue(group_A,PIN_A2,high);
//		}
//
//}
//
//
//
