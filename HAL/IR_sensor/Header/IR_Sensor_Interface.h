/*
 * IR_Sensor_Interface.h
 *
 *  Created on: Oct 15, 2022
 *      Author: osama
 */

#ifndef HAL_IR_SENSOR_HEADER_IR_SENSOR_INTERFACE_H_
#define HAL_IR_SENSOR_HEADER_IR_SENSOR_INTERFACE_H_

#include "../../../Common/bitmath.h"
#include "../../../Common/typedef.h"
#include "../../../Common/macros.h"

void IR_Sensor_void_init(u8 group_No, u8 Pin_No);
u8 IR_Sensor_u8_SignalReceive(u8 group_No, u8 Pin_No);

#endif /* HAL_IR_SENSOR_HEADER_IR_SENSOR_INTERFACE_H_ */
