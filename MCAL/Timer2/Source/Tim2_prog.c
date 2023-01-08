/*
 * Tim0_prog.c
 *
 *  Created on: Aug 24, 2022
 *      Author: osama
 */


#include "../../../Common/typedef.h"
#include "../../../Common/bitmath.h"
#include "../../../Common/macros.h"

#include "../Header/Tim2_interface.h"
#include "../Header/TIm2_Private.h"
#include "../Header/Tim2_config.h"
#include "../Header/Tim2_register.h"
#include "../../DIO/DIO_interface.h"
static void(*GPTF_1)(void) = NULL;
static void(*GPTF_2)(void) = NULL;

/*---------------------------------------------------------Normal Mode------------------------------------------------------------------------------------------*/
void Tim2_voidInitnormal_mode(u8 preload)
{
	//set the start point of the timer
	TCNT2 = preload;

	//set the timer on normal mode
	voidclear(TCCR2,WGM21);
	voidclear(TCCR2,WGM20);

	//enable the interrupt
	voidset_bit(TIMSK,TOIE2);
	//select the prescalling as per the requirements
#if Timer2_Prescaller == CLK_1
		voidclear(TCCR2,CS22);
		voidclear(TCCR2,CS21);
		voidset_bit(TCCR2,CS20);
#elif Timer2_Prescaller == CLK_8
		voidclear(TCCR2,CS22);
		voidset_bit(TCCR2,CS21);
		voidclear(TCCR2,CS20);
#elif Timer2_Prescaller == CLK_64
		voidclear(TCCR2,CS22);
		voidset_bit(TCCR2,CS21);
		voidset_bit(TCCR2,CS20);
#elif Timer2_Prescaller == CLK_256
		voidset_bit(TCCR2,CS22);
		voidclear(TCCR2,CS21);
		voidclear(TCCR2,CS20);
#elif Timer2_Prescaller == CLK_1024
		voidset_bit(TCCR2,CS22);
		voidclear(TCCR2,CS21);
		voidset_bit(TCCR2,CS20);
#endif

}


void Tim2_callbackfunctionNormal(void(*PTF)(void))
{
	GPTF_1 = PTF;
}

void __vector_5(void)
{
		GPTF_1();
}
/*----------------------------------------------------CTC Mode---------------------------------------------------------------------------------------*/

void Tim2_voidInitCTC(u8 Local_Compare_value)
{

	//set the end point of the timer
	OCR2 = Local_Compare_value;

	//set the timer on CTC mode
	voidset_bit(TCCR2,WGM21);
	voidclear(TCCR2,WGM20);

	//enable the interrupt For CTC
	voidset_bit(TIMSK,OCIE2);

	//select the prescalling as per the requirements
#if Timer2_Prescaller == CLK_1
		voidclear(TCCR2,CS22);
		voidclear(TCCR2,CS21);
		voidset_bit(TCCR2,CS20);
#elif Timer2_Prescaller == CLK_8
		voidclear(TCCR2,CS22);
		voidset_bit(TCCR2,CS21);
		voidclear(TCCR2,CS20);
#elif Timer2_Prescaller == CLK_64
		voidclear(TCCR2,CS22);
		voidset_bit(TCCR2,CS21);
		voidset_bit(TCCR2,CS20);
#elif Timer2_Prescaller == CLK_256
		voidset_bit(TCCR2,CS22);
		voidclear(TCCR2,CS21);
		voidclear(TCCR2,CS20);
#elif Timer2_Prescaller == CLK_1024
		voidset_bit(TCCR2,CS22);
		voidclear(TCCR2,CS21);
		voidset_bit(TCCR2,CS20);
#endif

}
void Tim2_callbackfunctionCTC(void(*PTF)(void))
{
	GPTF_2 = PTF;
}
void __vector_4(void)
{
	GPTF_2();
}

void Tim2_voidSetPreload(u8 Preload)
{
	TCNT2 = Preload;
}

/*---------------------------------------------------------PWM Mode------------------------------------------------------------------------------------------*/


void Tim2_voidFast_PWMInit(u8 Dutycycle)
{

	//set the timer on PWM mode
		voidset_bit(TCCR2,WGM21);
		voidset_bit(TCCR2,WGM20);

//select the mode
#if PWM_Mode == Inverting
	voidset_bit(TCCR2,COM20);
	voidset_bit(TCCR2,COM21);
	OCR2 = ((1-Dutycycle) * 256)/100;


#elif PWM_mode == Non_Inverting
	voidclear(TCCR2,COM20);
	voidset_bit(TCCR2,COM21);
	OCR2 = (Dutycycle * 256)/100;


#endif

	//select the prescalling as per the requirements
#if Timer2_Prescaller == CLK_1
		voidclear(TCCR2,CS22);
		voidclear(TCCR2,CS21);
		voidset_bit(TCCR2,CS20);
#elif Timer2_Prescaller == CLK_8
		voidclear(TCCR2,CS22);
		voidset_bit(TCCR2,CS21);
		voidclear(TCCR2,CS20);
#elif Timer2_Prescaller == CLK_64
		voidclear(TCCR2,CS22);
		voidset_bit(TCCR2,CS21);
		voidset_bit(TCCR2,CS20);
#elif Timer2_Prescaller == CLK_256
		voidset_bit(TCCR2,CS22);
		voidclear(TCCR2,CS21);
		voidclear(TCCR2,CS20);
#elif Timer2_Prescaller == CLK_1024
		voidset_bit(TCCR2,CS22);
		voidclear(TCCR2,CS21);
		voidset_bit(TCCR2,CS20);
#endif

}

void Tim2_voidFPWM_SetDutyCycle(u8 Dutycycle)
{
#if PWM_Mode == Inverting
	voidset_bit(TCCR2,COM20);
	voidset_bit(TCCR2,COM21);
	OCR2 = ((1-Dutycycle) * 256)/100;

#elif PWM_mode == Non_Inverting
	voidclear(TCCR2,COM20);
	voidset_bit(TCCR2,COM21);
	OCR2 = (Dutycycle * 256)/100;
#endif
}

