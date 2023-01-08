///*
// * TrafficLight.c
// *
// *  Created on: Sep 12, 2022
// *      Author: osama
// */
//
//#include "../Common/typedef.h"
//#include "../Common/macros.h"
//#include "../MCAL/DIO/DIO_interface.h"
//#include "../MCAL/Timer0/Header/Tim0_interface.h"
//#include "../HAL/Sev_Seg/Header/SevSeg_Interface.h"
//#include "../MCAL/GIE/Header/GIE_Interface.h"
//#include <util/delay.h>
//
//void Traffic_Fun(void);
//void main()
//{
//	//enable the global interrupt
//	GIE_voidEnable_GIE();
//	//initiate the timer
//	Tim0_voidInitCTC(125);
//	//Initiate the 7-Seg
//	DIO_VoidSetPortDir(group_A,Max_Output);
//	//pass the callback function to CTC layer
//	Tim0_callbackfunctionCTC(Traffic_Fun);
//	//make the ports as outputs
//	DIO_VoidSetPortDir(group_C,Max_Output);
//
//
//	while(1)
//	{
//
//	}
//}
//
//void Traffic_Fun(void)
//{
//static u16 counter_1 = 0;
//static u8 counter_2 = 1;
//static u8 counter_3 = 0;
//	//increment the counter until the number of counters come
//       counter_1++;
//if(counter_1 == 250)
//{
//
//	SevSeg_VoidDisplayNo(counter_3);
//
//	if(counter_2 == 10)
//	{
//		DIO_VoidSetPinValue(group_C,PIN_C0,high);
//		DIO_VoidSetPinValue(group_C,PIN_C1,low);
//		DIO_VoidSetPinValue(group_C,PIN_C2,low);
//		counter_3 = 0;
//	}
//	else if(counter_2 == 20)
//		{
//			DIO_VoidSetPinValue(group_C,PIN_C0,low);
//			DIO_VoidSetPinValue(group_C,PIN_C1,high);
//			DIO_VoidSetPinValue(group_C,PIN_C2,low);
//			counter_3 = 0;
//		}
//	else if(counter_2 == 30)
//	{
//		DIO_VoidSetPinValue(group_C,PIN_C0,low);
//		DIO_VoidSetPinValue(group_C,PIN_C1,low);
//		DIO_VoidSetPinValue(group_C,PIN_C2,high);
//		counter_3 = 0;
//		counter_2 = 0;
//	}
//	counter_2++;
//	counter_3++;
//	counter_1 = 0;
//}
//}
//
//
//
//
//
//
//
//
//
//
