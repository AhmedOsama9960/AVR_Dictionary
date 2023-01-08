/*
 * UART_Interface.h
 *
 *  Created on: Sep 1, 2022
 *      Author: osama
 */

#ifndef MCAL_UART_HEADER_UART_INTERFACE_H_
#define MCAL_UART_HEADER_UART_INTERFACE_H_

#include "../../../Common/typedef.h"

/*----------------------------------------------Polling--------------------------------------------------------------*/
void UART_voidInit(void);
void UART_voidSend(u8 Local_Data);
u8 UART_u8Receive(void);
void UART_voidsendString(u8 *str);


/*-----------------------------------------------Interrupt------------------------------------------------------*/
void UART_voidInterruptInit(void);
void UART_voidStartSend(u8 Local_Data);
void UART_voidStartReceive(void);
void UART_ReceiveCallBackFunction(u8 *Data);
void __vector_13 (void) __attribute__((signal));

#endif /* MCAL_UART_HEADER_UART_INTERFACE_H_ */
