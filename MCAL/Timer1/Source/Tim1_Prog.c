/*
 * Tim1_Prog.c
 *
 *  Created on: Aug 31, 2022
 *      Author: osama
 */

#include "../../../Common/typedef.h"
#include "../../../Common/bitmath.h"
#include "../../../Common/macros.h"

#include "../Header/Tim1_interface.h"
#include "../Header/Tim1_Private.h"
#include "../Header/Tim1_config.h"
#include "../Header/Tim1_register.h"
#include "../../DIO/DIO_interface.h"

static void(*GPTF_1)(void) = NULL;
static void(*GPTF_2)(void) = NULL;
/*------------------------------------------------------NormalMode----------------------------------------------------*/
void TIMER1_voidInitNormalMode(void)
{
//to initialize the normal mode
voidclear(TCCR1A,WGM11);
voidclear(TCCR1A,WGM10);
voidclear(TCCR1B,WGM12);
voidclear(TCCR1B,WGM13);

//setting the prescaller with 8 as recommended
voidclear(TCCR1B,CS12);
voidset_bit(TCCR1B,CS11);
voidclear(TCCR1B,CS10);
}

void TIMER1_voidStop(void)
{
voidclear(TCCR1B,CS12);
voidclear(TCCR1B,CS11);
voidclear(TCCR1B,CS10);
}
void Tim1_CallbackFunTimerOverFlow(void (*ptr_2)(void))
{
	GPTF_2 = ptr_2;
}
void __vector_9(void)
{
	GPTF_2();
}
/*---------------------------------------Input_Capture_Mode-----------------------------------------------------------*/
void ICU_voidSetTrigger(u8 Copy_u8Edge)
{
	if (Copy_u8Edge == ICU_Falling_Edge)
{
	voidclear(TCCR1B,ICES1);
}
	else
{
	voidset_bit(TCCR1B,ICNC1);
	voidset_bit(TCCR1B,ICES1);
}
}
void ICU_voidEnableInterrupt(void)
{
	voidset_bit(TIMSK,TICIE1);
}
void ICU_voidDisableInterrupt(void)
{
	voidclear(TIMSK,TICIE1);
}
void ICU_CallbackFun(void (*ptr)(void))
{
	GPTF_1 = ptr;
}
void __vector_6(void)
{
	GPTF_1();
}

u16 ICU_u16Read_Capture_Register(void)
{
	return ICR1;
}
