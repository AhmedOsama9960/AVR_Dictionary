/*
 * SPI_register.h
 *
 *  Created on: Sep 5, 2022
 *      Author: osama
 */

#ifndef MCAL_SPI_HEADER_SPI_REGISTER_H_
#define MCAL_SPI_HEADER_SPI_REGISTER_H_

#include "../../../Common/typedef.h"


#define SPCR		*((volatile u8 *)0x2D)
#define SPSR		*((volatile u8 *)0x2E)
//SPDR
#define SPI_Data	*((volatile u8 *)0x2F)


/*---------------------------------SPCR Register---------------------------*/
#define SPIE	7
#define SPE		6
#define DORD	5
#define MSTR	4
#define CPOL	3
#define CPHA	2
#define SPR1	1
#define SPR0	0

/*---------------------------------SPSR Register---------------------------*/
#define SPIF	7
#define WCOL	6
#define SPI2X	0




#endif /* MCAL_SPI_HEADER_SPI_REGISTER_H_ */
