/*
 * TWI_Private.h
 *
 *  Created on: Sep 8, 2022
 *      Author: osama
 */

#ifndef MCAL_TWI_HEADER_TWI_PRIVATE_H_
#define MCAL_TWI_HEADER_TWI_PRIVATE_H_

#include "../../../Common/bitmath.h"
#include "../../../Common/macros.h"
#include "../../../Common/typedef.h"

#define START_ACK                0x08 // start has been sent
#define REP_START_ACK            0x10 // repeated start
#define SLAVE_ADD_AND_WR_ACK     0x18 // Master transmit ( slave address + Write request ) ACK
#define SLAVE_ADD_AND_RD_ACK     0x40 // Master transmit ( slave address + Read request ) ACK
#define WR_BYTE_ACK              0x28 // Master transmit data ACK
#define RD_BYTE_WITH_NACK        0x58 // Master received data with not ACK
#define SLAVE_ADD_RCVD_RD_REQ    0xA8 // means that slave address is received with write req
#define SLAVE_ADD_RCVD_WR_REQ    0x60 // means that slave address is received with read req
#define SLAVE_DATA_RECEIVED      0x80 // means that read byte req is received
#define SLAVE_BYTE_TRANSMITTED   0xC0 // means that write byte req is received


TWI_ErrorStatus Error_State = noerror;

#define CLK_1		1
#define CLK_4		2
#define CLK_16		3
#define CLK_64		4

#endif /* MCAL_TWI_HEADER_TWI_PRIVATE_H_ */
