/*
 * Switch_interface.h
 *
 *  Created on: Aug 13, 2022
 *      Author: osama
 */

#ifndef HAL_SWITCH_HEADER_SWITCH_INTERFACE_H_
#define HAL_SWITCH_HEADER_SWITCH_INTERFACE_H_

void SWITCH_Void_Set_ON(u8 Group,u8 Pin_No);
u8 SWITCH_u8_Read_Value(u8 Group,u8 Pin_No);

#endif /* HAL_SWITCH_HEADER_SWITCH_INTERFACE_H_ */
