///*
// * Led_Brightness.c
// *
// *  Created on: Sep 1, 2022
// *      Author: osama
// */
//
//#include "../Common/typedef.h"
//#include "../Common/macros.h"
//
//#include "../MCAL/DIO/DIO_interface.h"
//#include "../MCAL/ADC/Header/ADC_Interface.h"
//#include "../MCAL/Timer0/Header/Tim0_interface.h"
//#include "../MCAL/Timer2/Header/Tim2_interface.h"
//
//
//
//void main()
//{
//	DIO_VoidSetPinDir(group_A,PIN_A0,input);
//	ADC_voidInit();
//	DIO_VoidSetPinDir(group_B,PIN_B3,output);
//	DIO_VoidSetPinDir(group_D,PIN_D7,output);
//	while(1)
//	{
//		u16 ADC_Data = ADC_u16Readdata(0);
//		Tim2_voidFast_PWMInit(ADC_Data);
//		Tim0_voidFast_PWMInit(ADC_Data);
//
//	}
//
//
//}
