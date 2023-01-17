///*
// * main.c
// *
// *  Created on: Sep 19, 2022
// *      Author: osama
// */
//
//#include "../Common/bitmath.h"
//#include "../Common/macros.h"
//#include "../Common/typedef.h"
//
//#include "../MCAL/DIO/DIO_interface.h"
//#include "../HAL/LED/header/LED_interface.h"
//
//
//void app_voidRedTask(void * Copy_pv);
//void app_voidGreenTask(void * Copy_pv);
//void app_voidYellowTask(void * Copy_pv);
//
//#define RED_Task_Priority		4
//#define Green_Task_Priority		3
//#define Yellow_Task_Priority	1
//
//int main(void)
//{
//	DIO_VoidSetPinDir(group_A,PIN_A0,output);
//	DIO_VoidSetPinDir(group_A,PIN_A1,output);
//	DIO_VoidSetPinDir(group_A,PIN_A2,output);
//
//	xTaskCreate(&app_voidRedTask,NULL,200,NULL,RED_Task_Priority,NULL);
//	xTaskCreate(&app_voidGreenTask,NULL,200,NULL,Green_Task_Priority,NULL);
//	xTaskCreate(&app_voidYellowTask,NULL,200,NULL,Yellow_Task_Priority,NULL);
//
//	//start Scheduler
//	vTaskStartScheduler();
//return 0;
//}
//
//void app_voidRedTask(void * Copy_pv)
//{
//
//	while(1)
//	{
//		DIO_VoidSetPinValue(group_A,PIN0,high);
//		vTaskDelay(200);
//		DIO_VoidSetPinValue(group_A,PIN0,low);
//		vTaskDelay(200);
//	}
//}
//
//void app_voidGreenTask(void * Copy_pv)
//{
//	while(1)
//		{
//			DIO_VoidSetPinValue(group_A,PIN1,high);
//			vTaskDelay(500);
//			DIO_VoidSetPinValue(group_A,PIN1,low);
//			vTaskDelay(500);
//		}
//}
//void app_voidYellowTask(void * Copy_pv)
//{
//	while(1)
//		{
//			DIO_VoidSetPinValue(group_A,PIN2,high);
//			vTaskDelay(1000);
//			DIO_VoidSetPinValue(group_A,PIN2,low);
//			vTaskDelay(1000);
//		}
//}
//
