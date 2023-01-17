/*
 * ADC_register.h
 *
 *  Created on: Aug 22, 2022
 *      Author: osama
 */

#ifndef MCAL_ADC_HEADER_ADC_REGISTER_H_
#define MCAL_ADC_HEADER_ADC_REGISTER_H_

#include "../../../Common/typedef.h"

#define ADMUX         *((volatile u8*)0x27)
#define ADCSRA        *((volatile u8*)0x26)
#define ADC_Data      *((volatile u16*)0x24)


//ADMUX Register Bits
#define ADC_REFS1		7
#define ADC_REFS0		6
#define ADC_ADLAR		5
#define ADC_MUX4		4
#define ADC_MUX3		3
#define ADC_MUX2		2
#define ADC_MUX1		1
#define ADC_MUX0		0



//ADCSRA Register Bits
#define ADC_ADEN		7
#define ADC_ADSC		6
#define ADC_ADIF		4
#define ADC_ADIE		3
#define ADC_ADPS2		2
#define ADC_ADPS1		1
#define ADC_ADPS0		0




#endif /* MCAL_ADC_HEADER_ADC_REGISTER_H_ */
