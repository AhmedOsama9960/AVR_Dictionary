/*
 * SPI_Prog.c
 *
 *  Created on: Sep 5, 2022
 *      Author: osama
 */




#include "../../../Common/bitmath.h"
#include "../../../Common/macros.h"
#include "../../../Common/typedef.h"

#include "../Header/SPI_Interface.h"
#include "../Header/SPI_config.h"
#include "../Header/SPI_private.h"
#include "../Header/SPI_register.h"

void SPI_voidInit(u8 Local_Type)
{
	//The pattern of data transfer to slaves
#if	Data_Order == LSB
	voidset_bit(SPCR,DORD);
#elif	Data_Order == MSB
	voidclear(SPCR,DORD);
#endif

//CLock Polarity & Clock Phase
#if	SPI_CPOL == Rising
	voidclear(SPCR,CPOL);
#elif	SPI_CPOL == Falling
	voidset_bit(SPCR,CPOL);
#endif

#if SPI_CPHA == Sample
	voidclear(SPCR,CPHA);
#elif	SPI_CPHA == Setup
	voidset_bit(SPCR,CPHA);
#endif

//Prescaller without or with Double_Speed
#if	Prescaller	==	CLK_4

#elif	Prescaller == CLK_16
	voidset_bit(SPCR,SPR0);
#elif	Prescaller == CLK_64
	voidset_bit(SPCR,SPR1);
#elif	Prescaller == CLK_128
	voidset_bit(SPCR,SPR0);
	voidset_bit(SPCR,SPR1);
	//if you want to activate the Double Speed
#elif	Prescaller == CLK_2
	voidset_bit(SPSR,SPI2X);
#elif	Prescaller == CLK_8
	voidset_bit(SPSR,SPI2X);
	voidset_bit(SPCR,SPR0);
#elif	Prescaller == CLK_32
	voidset_bit(SPSR,SPI2X);
	voidset_bit(SPCR,SPR1);
#elif	Prescaller == CLK_64_DoubleSpeed
	voidset_bit(SPSR,SPI2X);
	voidset_bit(SPCR,SPR0);
	voidset_bit(SPCR,SPR1);

#endif
if (Local_Type == Master)
{
	//Master Select case
	voidset_bit(SPCR,MSTR);
	//SS should be high
}
else
{
	//Master Select case
	voidclear(SPCR,MSTR);
	//SS should be high
}
}

void SPI_voidTransiver(u8 * Local_Data)
{
SPI_Data = * Local_Data;
// enable the SPI
voidset_bit(SPCR,SPE);
//polling
while ((u8read(SPSR,SPIF)) == false);
//return by reference
* Local_Data = SPI_Data;
}



