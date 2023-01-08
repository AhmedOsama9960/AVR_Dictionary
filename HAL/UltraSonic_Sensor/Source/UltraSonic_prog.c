/*
 * UltraSonic_prog.c
 *
 *  Created on: Sep 27, 2022
 *      Author: osama
 */

#include "../../../Common/bitmath.h"
#include "../../../Common/macros.h"
#include "../../../Common/typedef.h"

#include "../../../MCAL/DIO/DIO_interface.h"
#include "../../../MCAL/GIE/Header/GIE_Interface.h"
#include "../../../MCAL/EXTI/Header/EXTI_Interface.h"
#include "../../../MCAL/Timer0/Header/Tim0_interface.h"
#include "../../../MCAL/Timer0/Header/Tim0_register.h"
#include "../../../MCAL/Timer1/Header/Tim1_Interface.h"
#include "../../../MCAL/Timer1/Header/Tim1_Private.h"
#include "../Header/UltraSonic_interface.h"
#include "../Header/UltraSonic_private.h"
#include <util/delay.h>



u8 echo          = Starting;
u16 count 		 = Zero;
u16 Time 		 = Zero;
u16 TimerOverflow_1=Zero;

/*---------------------------------------------SW_Method/Timer+Interrupt-------------------------------------------*/
void Ultrasonic_voidInit_Timer_InterruptMode(u8 Group, u8 Trigger_PIN, u8 INT_No)
{
	// setting Trig pin as output and high
				DIO_VoidSetPinDir(Group,Trigger_PIN, output);
	//init the Global Interrupt
				GIE_voidEnable_GIE();
	//Init the EX-INT
				EXIT_voidINIT(INT_No,Any_Logical_Change);
				Tim0_voidInitnormal_mode(Zero);
				Tim0_callbackfunctionNormal(timeroverflow);
				EXIT_0callback_function(Ultrasonic_voidISRFunction);
}

void Ultrasonic_voidISRFunction(void)
{
	if (echo == Falling)
	{
		echo = Starting;
	}
	else
	{
		//Misra Rule
	}
	echo++;
}

u16 Ultra_Distance_Calc(void)
{
	while(echo == Rising);
	TCNT0=Zero;
	TimerOverflow_1 = Zero;
	while(echo == Falling);
	Time = TCNT0;
	count = Time + (TimerOverflow_1 * 255);
	return (count/466.47);
}

/*-------------------------------------------By Input Capture Unit----------------------------------------------------*/
void Ultrasonic_voidInit_ICU_Method(u8 Group, u8 Trigger_PIN)
{
		// setting Trig pin as output and high
		DIO_VoidSetPinDir(Group, Trigger_PIN, output);

		//setting the ICP pin as input and high
		DIO_VoidSetPinDir(group_D,PIN_D6,input);
		DIO_VoidSetPinValue(group_D,PIN_D6,high);

		//init the Global Interrupt
		GIE_voidEnable_GIE();

		//enable the interrupt For timer 1
		TIMSK = (1 << TOIE1);
		TCCR1A = 0;	// set all bits to zeros
}


f32 Ultrasonic_voidDistance(void)
{
			TCNT1 = 0;	/* Clear Timer counter */
			TCCR1B = 0x41;	/* Capture on rising edge, No prescaler*/
			TIFR = 1<<ICF1;	/* Clear ICP flag (Input Capture flag) */
			TIFR = 1<<TOV1;	/* Clear Timer Overflow flag */

			while ((TIFR & (1 << ICF1)) == 0);/* Wait for rising edge */
			TCNT1 = 0;	/* Clear Timer counter */
			TCCR1B = 0x01;	/* Capture on falling edge, No prescaler */
			TIFR = 1<<ICF1;	/* Clear ICP flag (Input Capture flag) */
			TIFR = 1<<TOV1;	/* Clear Timer Overflow flag */
			TimerOverflow_1 = 0;/* Clear Timer overflow count */

			while ((TIFR & (1 << ICF1)) == 0);/* Wait for falling edge */
			count = ICR1 + (65535 * TimerOverflow_1);	/* Take count */
			/* 8MHz Timer freq, sound speed =343 m/s */
			return ((f32)count/466.47);
}
/*---------------------------------------------------------------------------------------------------------------------*/
void Trig(u8 Group, u8 Trigger_PIN)
{
		DIO_VoidSetPinValue(Group,Trigger_PIN,high);
		//wait 15us for the sound wave outputs from Trig Pin
		_delay_us(10);
		DIO_VoidSetPinValue(Group,Trigger_PIN,low);
}

void timeroverflow(void)
{
	TimerOverflow_1++;
}
