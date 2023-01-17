/*
 * LED_interface.h
 *
 *  Created on: Aug 13, 2022
 *      Author: osama
 */

#ifndef HAL_LED_HEADER_LED_INTERFACE_H_
#define HAL_LED_HEADER_LED_INTERFACE_H_

void LED_Set_void_High(u8 Group,u8 Pin_No);
void LED_Set_void_Low(u8 Group,u8 Pin_No);
void LED_Void_Set_Port(u8 Group, u8 Port_Value);
void LED_void_Toggle(u8 Group, u8 Pin_No);

#endif /* HAL_LED_HEADER_LED_INTERFACE_H_ */
