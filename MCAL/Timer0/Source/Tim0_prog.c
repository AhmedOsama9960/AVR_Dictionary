/*
 * Tim0_prog.c
 *
 *  Created on: Aug 24, 2022
 *      Author: osama
 */


#include "../../../Common/typedef.h"
#include "../../../Common/bitmath.h"
#include "../../../Common/macros.h"

#include "../Header/Tim0_register.h"
#include "../Header/TIm0_Private.h"
#include "../Header/Tim0_interface.h"
#include "../Header/Tim0_config.h"
#include "../../DIO/DIO_interface.h"

static void(*GPTF_1)(void) = NULL;
static void(*GPTF_2)(void) = NULL;

/*---------------------------------------------------------Normal Mode------------------------------------------------------------------------------------------*/
void Tim0_voidInitnormal_mode(u8 preload)
{
	//set the start point of the timer
	TCNT0 = preload;

	//set the timer on normal mode
	voidclear(TCCR0,WGM01);
	voidclear(TCCR0,WGM00);

	//enable the interrupt
	voidset_bit(TIMSK0,TOIE);
	//select the prescalling as per the requirements
#if Timer0_Prescaller == CLK_1
		voidclear(TCCR0,CS02);
		voidclear(TCCR0,CS01);
		voidset_bit(TCCR0,CS00);
#elif Timer0_Prescaller == CLK_8
		voidclear(TCCR0,CS02);
		voidset_bit(TCCR0,CS01);
		voidclear(TCCR0,CS00);
#elif Timer0_Prescaller == CLK_64
		voidclear(TCCR0,CS02);
		voidset_bit(TCCR0,CS01);
		voidset_bit(TCCR0,CS00);
#elif Timer0_Prescaller == CLK_256
		voidset_bit(TCCR0,CS02);
		voidclear(TCCR0,CS01);
		voidclear(TCCR0,CS00);
#elif Timer0_Prescaller == CLK_1024
		voidset_bit(TCCR0,CS02);
		voidclear(TCCR0,CS01);
		voidset_bit(TCCR0,CS00);
#endif

}


void Tim0_callbackfunctionNormal(void(*PTF)(void))
{
	GPTF_1 = PTF;
}

void __vector_11(void)
{

		GPTF_1();
}

void Tim0_voidSetPreload(u8 Preload)
{
	TCNT0 = Preload;
}
/*----------------------------------------------------CTC Mode---------------------------------------------------------------------------------------*/

void Tim0_voidInitCTC(u8 Local_Compare_value)
{

	//set the end point of the timer
	OCR0 = Local_Compare_value;

	//set the timer on CTC mode
	voidset_bit(TCCR0,WGM01);
	voidclear(TCCR0,WGM00);

	//enable the interrupt For CTC
	voidset_bit(TIMSK0,OCIE0);

	//select the prescalling as per the requirements
#if Timer0_Prescaller == CLK_1
		voidclear(TCCR0,CS02);
		voidclear(TCCR0,CS01);
		voidset_bit(TCCR0,CS00);
#elif Timer0_Prescaller == CLK_8
		voidclear(TCCR0,CS02);
		voidset_bit(TCCR0,CS01);
		voidclear(TCCR0,CS00);
#elif Timer0_Prescaller == CLK_64
		voidclear(TCCR0,CS02);
		voidset_bit(TCCR0,CS01);
		voidset_bit(TCCR0,CS00);
#elif Timer0_Prescaller == CLK_256
		voidset_bit(TCCR0,CS02);
		voidclear(TCCR0,CS01);
		voidclear(TCCR0,CS00);
#elif Timer0_Prescaller == CLK_1024
		voidset_bit(TCCR0,CS02);
		voidclear(TCCR0,CS01);
		voidset_bit(TCCR0,CS00);
#endif

		//selet the mode of OC0 pin
#if Pin_Operation == toggle
		voidclear(TCCR0,COM00);
		voidset_bit(TCCR0,COM01);
#elif	Pin_Operation == clear
		voidclear(TCCR0,COM01);
		voidset_bit(TCCR0,COM00);
#elif	Pin_Operation == set
		voidset_bit(TCCR0,COM00);
		voidset_bit(TCCR0,COM01);
#endif
}
void Tim0_callbackfunctionCTC(void(*PTF)(void))
{
	GPTF_2 = PTF;
}
void __vector_10(void)
{
	u8 counter = 0;
	counter++;
	if(counter == 10)
	{
	GPTF_2();
	counter = 0;
	}
}


/*---------------------------------------------------------PWM Mode------------------------------------------------------------------------------------------*/


void Tim0_voidFast_PWMInit(u8 Dutycycle)
{

	//set the timer on PWM mode
		voidset_bit(TCCR0,WGM01);
		voidset_bit(TCCR0,WGM00);

//select the mode
#if PWM_Mode == Inverting
	voidset_bit(TCCR0,COM00);
	voidset_bit(TCCR0,COM01);
	OCR0 = ((1-Dutycycle) * 256)/100;


#elif PWM_mode == Non_Inverting
	voidclear(TCCR0,COM00);
	voidset_bit(TCCR0,COM01);
	OCR0 = (Dutycycle * 256)/100;


#endif

	//select the prescalling as per the requirements
#if Timer0_Prescaller == CLK_1
		voidclear(TCCR0,CS02);
		voidclear(TCCR0,CS01);
		voidset_bit(TCCR0,CS00);
#elif Timer0_Prescaller == CLK_8
		voidclear(TCCR0,CS02);
		voidset_bit(TCCR0,CS01);
		voidclear(TCCR0,CS00);
#elif Timer0_Prescaller == CLK_64
		voidclear(TCCR0,CS02);
		voidset_bit(TCCR0,CS01);
		voidset_bit(TCCR0,CS00);
#elif Timer0_Prescaller == CLK_256
		voidset_bit(TCCR0,CS02);
		voidclear(TCCR0,CS01);
		voidclear(TCCR0,CS00);
#elif Timer0_Prescaller == CLK_1024
		voidset_bit(TCCR0,CS02);
		voidclear(TCCR0,CS01);
		voidset_bit(TCCR0,CS00);
#endif

}

void Tim0_voidFPWM_SetDutyCycle(u8 Dutycycle)
{
#if PWM_Mode == Inverting
	voidset_bit(TCCR0,COM00);
	voidset_bit(TCCR0,COM01);
	OCR0 = ((1-Dutycycle) * 256)/100;

#elif PWM_mode == Non_Inverting
	voidclear(TCCR0,COM00);
	voidset_bit(TCCR0,COM01);
	OCR0 = (Dutycycle * 256)/100;
#endif
}

