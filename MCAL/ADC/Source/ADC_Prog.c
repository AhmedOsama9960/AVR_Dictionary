/*
 * ADC_Prog.c
 *
 *  Created on: Aug 22, 2022
 *      Author: osama
 */

#include "../../../Common/bitmath.h"
#include "../../../Common/macros.h"
#include "../../../Common/typedef.h"

#include "../../DIO/DIO_interface.h"
#include "../Header/ADC_Config.h"
#include"../Header/ADC_Interface.h"
#include "../Header/ADC_private.h"
#include "../Header/ADC_register.h"


//static global pointer to function
static u16 *Global_Data = NULL;

void ADC_voidInit(void)
{
//voltage reference selection
voidset_bit(ADMUX,ADC_REFS0);
voidclear(ADMUX,ADC_REFS1);

//no initialization for left adjuster
voidclear(ADMUX,ADC_ADLAR);

//enable ADC
voidset_bit(ADCSRA,ADC_ADEN);
//enable interrupt
voidset_bit(ADCSRA,ADC_ADIE);

#if ADC_Prescaller == ADC_Prescaler2
	(ADCSRA,ADC_ADPS0);
	voidclear(ADCSRA,ADC_ADPS1);
	voidclear(ADCSRA,ADC_ADPS2);
#elif ADC_Prescaller == ADC_Prescaler4
	voidclear(ADCSRA,ADC_ADPS0);
	voidset_bit(ADCSRA,ADC_ADPS1);
	voidclear(ADCSRA,ADC_ADPS2);
#elif ADC_Prescaller == ADC_Prescaler8
	voidset_bit(ADCSRA,ADC_ADPS0);
	voidset_bit(ADCSRA,ADC_ADPS1);
	voidclear(ADCSRA,ADC_ADPS2);
#elif ADC_Prescaller == ADC_Prescaler16
	voidclear(ADCSRA,ADC_ADPS0);
	voidclear(ADCSRA,ADC_ADPS1);
	voidset_bit(ADCSRA,ADC_ADPS2);
#elif ADC_Prescaller == ADC_Prescaler32
	voidset_bit(ADCSRA,ADC_ADPS0);
	voidclear(ADCSRA,ADC_ADPS1);
	voidset_bit(ADCSRA,ADC_ADPS2);
#elif ADC_Prescaller == ADC_Prescaler64
	voidclear(ADCSRA,ADC_ADPS0);
	voidset_bit(ADCSRA,ADC_ADPS1);
	voidset_bit(ADCSRA,ADC_ADPS2);
#elif ADC_Prescaller == ADC_Prescaler128
	voidset_bit(ADCSRA,ADC_ADPS0);
	voidset_bit(ADCSRA,ADC_ADPS1);
	voidset_bit(ADCSRA,ADC_ADPS2);
#endif

}

u16 ADC_u16Readdata(u8 channel)
{
	//make all the ADC_MUX pins with 1
	channel &= 0x1f;

	//make the last three bits with high regarding the init setting
	ADMUX &= 0xE0;

	//set the channel as per you want according to the table until the 7th
	ADMUX |= channel;

	//start conversion
	voidset_bit(ADCSRA,ADC_ADSC);

	//check ADIF as indication for the end of ADC operation
	while( (u8read(ADCSRA,ADC_ADIF)) == 0);
	//storing the information in a variable to return it
	u16 return_value = ADC_Data;

	return return_value;

}

void ADC_voidcallbackfunction( u16* Data_Var)
{
	Data_Var = Global_Data;
}

void __vector_16(void)
{
	* Global_Data = ADC_Data;
}

