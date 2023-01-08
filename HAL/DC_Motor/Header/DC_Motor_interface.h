/*
 * DC_Motor_interface.h
 *
 *  Created on: Aug 19, 2022
 *      Author: osama
 */


#ifndef HAL_DC_MOTOR_HEADER_DC_MOTOR_INTERFACE_H_
#define HAL_DC_MOTOR_HEADER_DC_MOTOR_INTERFACE_H_

#include "../../../Common/typedef.h"

void DCM_void1TransTurnOn(u8 Group, u8 TranPin);

void DCM_void4TransTurnOn(u8 Group, u8 Trans1Pin, u8 Trans2Pin, u8 Trans3Pin, u8 Trans4Pin);

void DCM_voidTurnOff(u8 Group, u8 PIN_NO);

void DCM_voidReverseDirection(u8 Group, u8 Trans1Pin, u8 Trans2Pin, u8 Trans3Pin, u8 Trans4Pin);



#endif /* HAL_DC_MOTOR_HEADER_DC_MOTOR_INTERFACE_H_ */
