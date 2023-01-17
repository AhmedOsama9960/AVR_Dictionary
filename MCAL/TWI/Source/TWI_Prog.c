/*
 * TWI_Prog.c
 *
 *  Created on: Sep 8, 2022
 *      Author: osama
 */

#include "../../../Common/bitmath.h"
#include "../../../Common/macros.h"
#include "../../../Common/typedef.h"

#include "../Header/TWI_Register.h"
#include "../Header/TWI_Interface.h"
#include "../Header/TWI_Private.h"
#include "../Header/TWI_Config.h"


void TWI_VoidMasterInit(u8 Local_u8SlaveAddress)
{
//set the bit rate of 400kbps from the SCL frequency
	TWBR = 2;
	// setting the prescaller
#if	TWI_prescaller	==	CLK_1
	voidclear(TWSR,TWPS0);
	voidclear(TWSR,TWPS1);
#elif	TWI_prescaller	==	CLK_4
	voidset_bit(TWSR,TWPS0);
	voidclear(TWSR,TWPS1);
#elif	TWI_prescaller	==	CLK_16
	voidset_bit(TWSR,TWPS1);
	voidclear(TWSR,TWPS0);
#elif	TWI_prescaller	==	CLK_64
	voidset_bit(TWSR,TWPS0);
	voidset_bit(TWSR,TWPS1);
#endif

	if(Local_u8SlaveAddress != false)
	{
		TWAR = Local_u8SlaveAddress<<1;
	}
	/*Enable TWI*/
	voidset_bit(TWCR,TWEN);

}

void TWI_VoidSlaveInit(u8 Local_u8SlaveAddress)
{
	TWAR = Local_u8SlaveAddress<<1;
	voidset_bit(TWCR,TWEN);
}

TWI_ErrorStatus TWI_SendStartCondition(void)
{
//start bit
	voidset_bit(TWCR,TWSTA);
	//polling for the flag
	while( (u8read(TWCR,TWINT)) != true);
	if ((TWSR & 0xf8) != START_ACK)
	{
		Error_State = start_error;
	}
	return Error_State;
}
TWI_ErrorStatus TWI_SendSlaveAddressWithWrite(u8 Local_u8SlaveAddress)
{
//slave address in TWDR after shift 1;
	TWDR = (Local_u8SlaveAddress<<1);
	voidset_bit(TWDR,0);
	while( (u8read(TWCR,TWINT)) != true);
	if (((TWSR&0xf8)!=SLAVE_ADD_AND_WR_ACK))
	{
		Error_State = address_error;
	}
	return Error_State;
}
TWI_ErrorStatus TWI_MasterWriteDataByte(u8 Local_u8SendDatatype)
{
	TWDR = Local_u8SendDatatype;
	while( (u8read(TWCR,TWINT)) != true);
	if (((TWSR&0xf8) != WR_BYTE_ACK))
		{
			Error_State = data_error;
		}
	voidset_bit(TWCR,TWINT);
	return Error_State;
}

void TWI_STOPCondition(void)
{
	// TWCR set the bit for the stop condition
	voidset_bit(TWCR,TWSTO);
	//flag polling
	while( (u8read(TWCR,TWINT)) != true);
		voidset_bit(TWCR,TWINT);
}


