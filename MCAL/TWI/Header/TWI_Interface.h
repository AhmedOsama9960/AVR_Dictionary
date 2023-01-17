/*
 * TWI_Interface.h
 *
 *  Created on: Sep 8, 2022
 *      Author: osama
 */

#ifndef MCAL_TWI_HEADER_TWI_INTERFACE_H_
#define MCAL_TWI_HEADER_TWI_INTERFACE_H_

#include "../../../Common/typedef.h"

void TWI_VoidMasterInit(u8 Local_u8SlaveAddress);
void TWI_VoidSlaveInit(u8 Local_u8SlaveAddress);
TWI_ErrorStatus TWI_SendStartCondition(void);
TWI_ErrorStatus TWI_SendRepeatedStart(void);
TWI_ErrorStatus TWI_SendSlaveAddressWithWrite(u8 Local_u8SlaveAddress);
TWI_ErrorStatus TWI_MasterWriteDataByte(u8 Local_u8SendDatatype);
TWI_ErrorStatus TWI_MasterReadDataByte(u8 *Local_u8ReturnDatatype);
void TWI_STOPCondition(void);

#endif /* MCAL_TWI_HEADER_TWI_INTERFACE_H_ */
