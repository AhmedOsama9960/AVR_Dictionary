/*
 * TWI_Register.h
 *
 *  Created on: Sep 8, 2022
 *      Author: osama
 */

#ifndef MCAL_TWI_HEADER_TWI_REGISTER_H_
#define MCAL_TWI_HEADER_TWI_REGISTER_H_

#include "../../../Common/typedef.h"

#define TWBR	*((volatile u8 *)0x20)
#define TWCR	*((volatile u8 *)0x56)
#define TWSR	*((volatile u8 *)0x21)
#define TWDR	*((volatile u8 *)0x23)
#define TWAR	*((volatile u8 *)0x22)


/*-------TWCR bits -----*/

#define TWINT	7
#define TWEA	6
#define TWSTA	5
#define TWSTO	4
#define TWWC	3
#define TWEN	2
#define TWIE	0

/*-------TWSR bits -----*/
#define TWS7	7
#define TWS6	6
#define TWS5	5
#define TWS4	4
#define TWS3	3
#define TWPS1	1
#define TWPS0	0



#endif /* MCAL_TWI_HEADER_TWI_REGISTER_H_ */
