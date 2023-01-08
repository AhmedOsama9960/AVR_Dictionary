/*
 * UltraSonic_interface.h
 *
 *  Created on: Sep 27, 2022
 *      Author: osama
 */

#ifndef HAL_ULTRASONIC_SENSOR_HEADER_ULTRASONIC_INTERFACE_H_
#define HAL_ULTRASONIC_SENSOR_HEADER_ULTRASONIC_INTERFACE_H_

#include "../../../Common/typedef.h"

void Ultrasonic_voidInit_Timer_InterruptMode(u8 Group, u8 Trigger_PIN,u8 INT_No);
void Ultrasonic_voidISRFunction(void);
u16 Ultra_Distance_Calc(void);


void Ultrasonic_voidInit_ICU_Method(u8 Group, u8 Trigger_PIN);
f32 Ultrasonic_voidDistance(void);

void Trig(u8 Group, u8 Trigger_PIN);
void timeroverflow(void);

#endif /* HAL_ULTRASONIC_SENSOR_HEADER_ULTRASONIC_INTERFACE_H_ */
