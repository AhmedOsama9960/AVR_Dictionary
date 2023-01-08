/*
 * UART_Prog.c
 *
 *  Created on: Sep 1, 2022
 *      Author: osama
 */


#include "../../../Common/bitmath.h"
#include "../../../Common/macros.h"
#include "../../../Common/typedef.h"

#include "../Header/UART_Interface.h"
#include "../Header/UART_register.h"
#include "../Header/UART_Private.h"
#include "../Header/UART_Config.h"


static u8 Global_Data = 0;
/*----------------------------------------------Polling--------------------------------------------------------------*/
void UART_voidInit(void)
{
u8 ucsrc_temp = 0x80;

//UART_Mode
#if UART_Mode == Async_Mode
	voidclear(UART_UCSRC,UMSEL);
#elif UART_Mode == Sync_Mode
	voidset_bit(UART_UCSRC,UMSEL);
#endif

//UART_Parity_Modes
#if UART_Parity_Mode == UART_Parity_Off
	voidclear(UART_UCSRC,UPM1);
	voidclear(UART_UCSRC,UPM0);
#elif UART_Parity_Mode == UART_Parity_Even
	voidset_bit(UART_UCSRC,UPM1);
	voidclear(UART_UCSRC,UPM0);
#elif UART_Parity_Mode == UART_parity_Odd
	voidset_bit(UART_UCSRC,UPM1);
	voidset_bit(UART_UCSRC,UPM0);
#endif

//UART StopBits
#if UART_Stop_Bits == One_Stop_Bit
	voidclear(UART_UCSRC,USBS);
#elif UART_Stop_Bits == Two_Stop_Bit
	voidset_bit(UART_UCSRC,USBS);
#endif

//UART_Number Of Data

#if UART_No_Of_Data == five_BitData
	voidclear(UART_UCSRC,UCSZ1);
	voidclear(UART_UCSRC,UCSZ0);
	voidclear(UART_UCSRB,UCSZ2);
#elif UART_No_Of_Data == Six_BitData
	voidclear(UART_UCSRC,UCSZ1);
	voidset_bit(UART_UCSRC,UCSZ0);
	voidclear(UART_UCSRB,UCSZ2);
#elif UART_No_Of_Data == Seven_BitData
	voidset_bit(UART_UCSRC,UCSZ1);
	voidclear(UART_UCSRC,UCSZ0);
	voidclear(UART_UCSRB,UCSZ2);
#elif UART_No_Of_Data == Eight_BitData
	voidset_bit(ucsrc_temp,UCSZ1);
	voidset_bit(ucsrc_temp,UCSZ0);
	voidclear(UART_UCSRB,UCSZ2);
#elif UART_No_Of_Data == Nine_BitData
	voidset_bit(UART_UCSRC,UCSZ1);
	voidset_bit(UART_UCSRC,UCSZ0);
	voidset_bit(UART_UCSRB,UCSZ2);
#endif

		// initialize the UCSRC register in one access
	UART_UCSRC = ucsrc_temp;
//Baudrate

UART_UBRRL = UART_Baudrate;
UART_UBRRH = 0;
}

void UART_voidSend(u8 Local_Data)
{
	UART_UDR = Local_Data;
	voidset_bit(UART_UCSRB,TXEN);
	while( (u8read(UART_UCSRA,UDRE)) == 0);		//check if the transmission is still in process
	//we can make it as double speed

}

u8 UART_u8Receive(void)
{
	//enable Receiving mode
	voidset_bit(UART_UCSRB,RXEN);
	//checking if the receive is complete
	while( (u8read(UART_UCSRA,RXC)) == 0);
	//return the data
	return UART_UDR;
}
void UART_voidsendString(u8 *str)
{
u16 i = 0;
while(str[i] != NotFound)
{
	UART_voidSend(str[i]);
	i++;
}

}

/*-----------------------------------------------Interrupt------------------------------------------------------*/
void UART_voidInterruptInit(void)
{
	u8 ucsrc_temp = 0x80;

	//UART_Mode
	#if UART_Mode == Async_Mode
		voidclear(UART_UCSRC,UMSEL);
	#elif UART_Mode == Sync_Mode
		voidset_bit(UART_UCSRC,UMSEL);
	#endif

	//UART_Parity_Modes
	#if UART_Parity_Mode == UART_Parity_Off
		voidclear(UART_UCSRC,UPM1);
		voidclear(UART_UCSRC,UPM0);
	#elif UART_Parity_Mode == UART_Parity_Even
		voidset_bit(UART_UCSRC,UPM1);
		voidclear(UART_UCSRC,UPM0);
	#elif UART_Parity_Mode == UART_parity_Odd
		voidset_bit(UART_UCSRC,UPM1);
		voidset_bit(UART_UCSRC,UPM0);
	#endif

	//UART StopBits
	#if UART_Stop_Bits == One_Stop_Bit
		voidclear(UART_UCSRC,USBS);
	#elif UART_Stop_Bits == Two_Stop_Bit
		voidset_bit(UART_UCSRC,USBS);
	#endif

	//UART_Number Of Data

	#if UART_No_Of_Data == five_BitData
		voidclear(UART_UCSRC,UCSZ1);
		voidclear(UART_UCSRC,UCSZ0);
		voidclear(UART_UCSRB,UCSZ2);
	#elif UART_No_Of_Data == Six_BitData
		voidclear(UART_UCSRC,UCSZ1);
		voidset_bit(UART_UCSRC,UCSZ0);
		voidclear(UART_UCSRB,UCSZ2);
	#elif UART_No_Of_Data == Seven_BitData
		voidset_bit(UART_UCSRC,UCSZ1);
		voidclear(UART_UCSRC,UCSZ0);
		voidclear(UART_UCSRB,UCSZ2);
	#elif UART_No_Of_Data == Eight_BitData
		voidset_bit(ucsrc_temp,UCSZ1);
		voidset_bit(ucsrc_temp,UCSZ0);
		voidclear(UART_UCSRB,UCSZ2);
	#elif UART_No_Of_Data == Nine_BitData
		voidset_bit(UART_UCSRC,UCSZ1);
		voidset_bit(UART_UCSRC,UCSZ0);
		voidset_bit(UART_UCSRB,UCSZ2);
	#endif

	//Baudrate as per the config
	UART_UCSRC = ucsrc_temp;
	UART_UBRRL = UART_Baudrate;

	// enable the receive Interrupt
	voidset_bit(UART_UCSRB,RXCIE);

}

void UART_voidStartSend(u8 Local_Data)
{
	UART_UDR = Local_Data;
	voidset_bit(UART_UCSRB,TXEN);				//start transmission
	while( (u8read(UART_UCSRA,UDRE)) == 0);		//check if the transmission is still in process
	//we can make it as double speed

}
void UART_voidStartReceive(void)
{
	//enable Receiving mode
	voidset_bit(UART_UCSRB,RXEN);
}
void UART_ReceiveCallBackFunction(u8 *Data)
{
	*Data = Global_Data;
}
void __vector_13 (void)
{
	Global_Data = UART_UDR;
}
