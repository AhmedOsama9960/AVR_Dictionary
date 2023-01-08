/*
 * Implementations.c
 *
 *  Created on: Jan 6, 2023
 *      Author: osama
 */

#include "../../Common/bitmath.h"
#include "../../Common/typedef.h"
#include "../../Common/macros.h"


#include "../Header_Files/Config.h"
#include "../Header_Files/Interface.h"
#include "../../MCAL/DIO/DIO_interface.h"
#include "../../HAL/Servo_Motor/Header/Servo_M_interface.h"
#include "../../HAL/UltraSonic_Sensor/Header/UltraSonic_interface.h"
#include "../../HAL/IR_sensor/Header/IR_Sensor_Interface.h"
#include <util/delay.h>

/*-----------------------------------------------Global Functions-------------------------------------------------------------*/
void obstacle_detection(void)
{
	u16 obstacle_right = 0;
	u16 obstacle_left  = 0;
		DIO_VoidSetPortValue(group_A,No_Power);		//stop the wheels
		DIO_VoidSetPinValue(group_A,PIN_A1,high);	//reverse direction in case of obstacles for both wheels
		DIO_VoidSetPinValue(group_A,PIN_A3,high);
		_delay_ms(750);
		DIO_VoidSetPortValue(group_A,No_Power);
		Servo_Checker(&obstacle_right,&obstacle_left);		//check if there is something again
		if (obstacle_right > Obstacles)
		{
				DIO_VoidSetPinValue(group_A,PIN_A2,high);		// run the left wheel for a while
				_delay_ms(750);
		}
		else if (obstacle_left > Obstacles)
		{
				DIO_VoidSetPinValue(group_A,PIN_A0,high);		// run the right wheel for a while
				_delay_ms(750);
		}
		else
		{
			//Misra Rule
		}
}
/*--------------------------------------------------------------------------------------------------------------*/
void Servo_Checker (u16 *ob_right, u16 * ob_left)
{
	/*make the Servo go 90 degree*/
Servo_M_Values(Right_Angle);
Trig(group_D,PIN_D7);
	/*receive the value of the obstacle on the right position*/
*ob_right = Ultra_Distance_Calc();
_delay_ms(750);

	/*rotating the Servo-M back with 90 degree to check if there an obstacle*/
Servo_M_Values(Left_Angle);
Trig(group_D,PIN_D7);
	/*store the value if there is*/
*ob_left = Ultra_Distance_Calc();
_delay_ms(750);

Servo_M_Values(Correct_angle); 		// make it straight
_delay_ms(500);
}


/*--------------------------------------------------------------------------------------------------------------*/
void line_Follower(u8 IR_Right, u8 IR_Left)
{
	if(IR_Right == Interception && IR_Left == Interception)
	{
		while(IR_Right != No_Interception || IR_Left != No_Interception)
		{
			DIO_VoidSetPortValue(group_A,No_Power);
		}
	}
	else if (IR_Right == Interception)
	{
		while(IR_Right != No_Interception)
		{
			DIO_VoidSetPinValue(group_A,PIN_A2,high);		//run the left motor
			IR_Right = IR_Sensor_u8_SignalReceive(group_B,PIN_B0);
		}
		DIO_VoidSetPortValue(group_A,No_Power);
	}
	else if (IR_Left == Interception)
	{
		while(IR_Left != No_Interception)
		{
			DIO_VoidSetPinValue(group_A,PIN_A0,high);			//run the right motor until IR sensor gets signal right
			IR_Left  = IR_Sensor_u8_SignalReceive(group_B,PIN_B1);
		}
		DIO_VoidSetPortValue(group_A,No_Power);
	}
}
/*-------------------------------------------------------------------------------------------------------------------*/
void Bluetooth_Control(u8 action)
{
switch(action)
		{
		case Forward:
				DIO_VoidSetPinValue(group_A,PIN_A0,high);
				DIO_VoidSetPinValue(group_A,PIN_A2,high);
			break;
		case Reverse:
				DIO_VoidSetPinValue(group_A,PIN_A1,high);
				DIO_VoidSetPinValue(group_A,PIN_A3,high);
			break;

		case Left:
				DIO_VoidSetPinValue(group_A,PIN_A0,high);
			break;

		case Right:
				DIO_VoidSetPinValue(group_A,PIN_A2,high);
			break;
		case Stop:
				DIO_VoidSetPortValue(group_A,No_Power);
			break;
		case Front_Light:
				flag++;
			break;
		}
}
