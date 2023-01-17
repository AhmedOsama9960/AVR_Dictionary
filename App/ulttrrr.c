//#include "../MCAL/DIO/DIO_interface.h"
//#include "../HAL/UltraSonic_Sensor/Header/UltraSonic_interface.h"
//#include "../HAL/Servo_Motor/Header/Servo_M_interface.h"
//#include "../MCAL/GIE/Header/GIE_Interface.h"
//#include "../MCAL/EXTI/Header/EXTI_Interface.h"
//#include <stdio.h>
//#include <util/delay.h>
//
//#define Obstacles 5
//#define No_Power	0
//
//
//
//
//int main(void)
//{
//
//	DIO_VoidSetPortDir(group_A,0x0f);
//	DIO_VoidSetPinDir(group_D,PIN_D5,output);
//	Ultrasonic_voidInit_Timer_InterruptMode(group_D,PIN_D7,0);
//	Servo_voidInit();
//	while(1)
//	{
//		Servo_M_Values(0);
//		DIO_VoidSetPinValue(group_A,PIN_A0,high);
//		DIO_VoidSetPinValue(group_A,PIN_A2,high);
//		Trig(group_D,PIN_D7);
//
//
//
//		if(Ultra_Distance_Calc() < 20)
//		{
//			DIO_VoidSetPinValue(group_A,PIN_A0,low);
//			DIO_VoidSetPinValue(group_A,PIN_A2,low);
//			_delay_ms(1000);
//		}
//
////		if (dis_0 < 20)
////		{
////			DIO_VoidSetPinValue(group_A,PIN_A0,low);
////			DIO_VoidSetPinValue(group_A,PIN_A2,low);
////			_delay_ms(1000);
////			DIO_VoidSetPinValue(group_A,PIN_A1,high);
////			DIO_VoidSetPinValue(group_A,PIN_A3,high);
////			_delay_ms(1000);
////			DIO_VoidSetPinValue(group_A,PIN_A0,low);
////			DIO_VoidSetPinValue(group_A,PIN_A3,low);
////			Servo_M_Values(90);
////			dis_r = Ultra_Distance_Calc();
////			_delay_ms(750);
////			Servo_M_Values(180);
////			dis_l = Ultra_Distance_Calc();
////			_delay_ms(750);
////		if (dis_l < 20)
////		{
////			DIO_VoidSetPinValue(group_A,PIN_A1,high);
////			_delay_ms(1000);
////		}
////		if ( dis_r < 20)
////		{
////			DIO_VoidSetPinValue(group_A,PIN_A0,high);
////			_delay_ms(1000);
////		}
////		}
//	}
//return 0;
//}
