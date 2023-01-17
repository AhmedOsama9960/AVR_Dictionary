/*
 * ADC_Interface.h
 *
 *  Created on: Aug 22, 2022
 *      Author: osama
 */

#ifndef MCAL_ADC_HEADER_ADC_INTERFACE_H_
#define MCAL_ADC_HEADER_ADC_INTERFACE_H_

#include "../../../Common/typedef.h"

void ADC_voidInit(void);
u16 ADC_u16Readdata(u8 channel);
void ADC_voidcallbackfunction(u16* Data_Var);
void __vector_16(void) __attribute__((signal));


#endif /* MCAL_ADC_HEADER_ADC_INTERFACE_H_ */
