/*
 * EXTI_Prog.c
 *
 *  Created on: Aug 17, 2022
 *      Author: osama
 */


#include "../../../Common/bitmath.h"
#include "../../../Common/macros.h"
#include "../../../Common/typedef.h"

#include "../../DIO/DIO_interface.h"
#include "../Header/EXTI_Register.h"
#include"../Header/EXTI_Interface.h"
#include "../Header/EXTI_Config.h"
#include "../Header/EXTI_private.h"

static void(*GPTF_1)(void) = NULL;
static void(*GPTF_2)(void) = NULL;
static void(*GPTF_3)(void) = NULL;

void EXIT_0callback_function(void(*ptf)(void))
{
	GPTF_1 = ptf;
}

void __vector_1(void)
{
	GPTF_1();
}

void EXIT_1callback_function(void(*ptf)(void))
{
	GPTF_2 = ptf;
}

void __vector_2(void)
{
	GPTF_2();
}

void EXIT_2callback_function(void(*ptf)(void))
{
	GPTF_3 = ptf;
}

void __vector_3(void)
{
	GPTF_3();
}

void EXTI0_voidInit0(void)
{
	//select the pin as input as active the pull up resistance
	DIO_VoidSetPinDir(EXIT0_Group,EXIT0_PIN,input);
	DIO_VoidSetPinValue(EXIT0_Group,EXIT0_PIN,high);

	//Enable INT0
	voidset_bit(GICR,INT0);

	//check about options
#if		EXIT0_TriggerMode == EXIT_LOW
			voidclear(MCUCR,ISC00);
			voidclear(MCUCR,ISC01);
#elif	EXIT0_TriggerMode == EXIT_OnChange
			voidset_bit(MCUCR,ISC00);
			voidclear(MCUCR,ISC01);
#elif	EXIT0_TriggerMode == EXIT_fallingedge
			voidclear(MCUCR,ISC00);
			voidset_bit(MCUCR,ISC01);
#elif	EXIT0_TriggerMode == EXIT_risingedge
			voidset_bit(MCUCR,ISC00);
			voidset_bit(MCUCR,ISC01);
#endif

}



void EXIT_voidINIT(u8 Init_No, u8 Control)
{
	//Initialization for a specific external-interrupt
	switch(Init_No)
	{
	case EXIT_0:

		//make the pin as output as active the pull-up resistor
		DIO_VoidSetPinDir(EXIT0_Group,EXIT0_PIN,input);
		DIO_VoidSetPinValue(EXIT0_Group,EXIT0_PIN,high);

		//enable INT0
		voidset_bit(GICR,INT0);

		//check the options for INT0
		if (Control == EXIT_LOW)
		{
			voidclear(MCUCR,ISC00);
			voidclear(MCUCR,ISC01);
		}
		else if (Control == EXIT_OnChange)
		{
			voidset_bit(MCUCR,ISC00);
			voidclear(MCUCR,ISC01);
		}
		else if (Control == EXIT_fallingedge)
		{
			voidclear(MCUCR,ISC00);
			voidset_bit(MCUCR,ISC01);
		}
		else
		{
			voidset_bit(MCUCR,ISC00);
			voidset_bit(MCUCR,ISC01);
		}
		break;

	case EXIT_1:

		//make the pin as output as active the pull-up resistor
		DIO_VoidSetPinDir(EXIT1_Group,EXIT1_PIN,input);
		DIO_VoidSetPinValue(EXIT1_Group,EXIT1_PIN,high);

		//enable INT1
		voidset_bit(GICR,INT1);

		//check the options
		if (Control == EXIT_LOW)
			{
				voidclear(MCUCR,ISC10);
				voidclear(MCUCR,ISC11);
			}
			else if (Control == EXIT_OnChange)
			{
				voidset_bit(MCUCR,ISC10);
				voidclear(MCUCR,ISC11);
			}
			else if (Control == EXIT_fallingedge)
			{
				voidclear(MCUCR,ISC10);
				voidset_bit(MCUCR,ISC11);
			}
			else
			{
				voidset_bit(MCUCR,ISC10);
				voidset_bit(MCUCR,ISC11);
			}

		break;

	case EXIT_2:

		//make the pin as output as active the pull-up resistor
		DIO_VoidSetPinDir(EXIT2_Group,EXIT2_PIN,input);
		DIO_VoidSetPinValue(EXIT2_Group,EXIT2_PIN,high);

		//enable INT2
		voidset_bit(GICR,INT2);
		//check the options
		 if (Control == EXIT_fallingedge)
			{
				voidclear(MCUCR,ISC2);
			}
			else
			{
				voidset_bit(MCUCR,ISC2);
			}
		break;
	}
}


void EXIT_voidSetcontrol(u8 init_No ,u8 Control)
{

	switch(init_No)
	{

	case EXIT_0:
		//check the options for INT0
				if (Control == EXIT_LOW)
				{
					voidclear(MCUCR,ISC00);
					voidclear(MCUCR,ISC01);
				}
				else if (Control == EXIT_OnChange)
				{
					voidset_bit(MCUCR,ISC00);
					voidclear(MCUCR,ISC01);
				}
				else if (Control == EXIT_fallingedge)
				{
					voidclear(MCUCR,ISC00);
					voidset_bit(MCUCR,ISC01);
				}
				else
				{
					voidset_bit(MCUCR,ISC00);
					voidset_bit(MCUCR,ISC01);
				}
		break;

	case EXIT_1:
		//check the options
				if (Control == EXIT_LOW)
					{
						voidclear(MCUCR,ISC10);
						voidclear(MCUCR,ISC11);
					}
					else if (Control == EXIT_OnChange)
					{
						voidset_bit(MCUCR,ISC10);
						voidclear(MCUCR,ISC11);
					}
					else if (Control == EXIT_fallingedge)
					{
						voidclear(MCUCR,ISC10);
						voidset_bit(MCUCR,ISC11);
					}
					else
					{
						voidset_bit(MCUCR,ISC10);
						voidset_bit(MCUCR,ISC11);
					}
		break;

	case EXIT_2:
		//check the options
				 if (Control == EXIT_fallingedge)
					{
						voidclear(MCUCR,ISC2);
					}
					else
					{
						voidset_bit(MCUCR,ISC2);
					}
		break;
	}
}



