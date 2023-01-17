/*
 * Step_Motor_Interface.h
 *
 *  Created on: Aug 29, 2022
 *      Author: osama
 */

#ifndef HAL_STEPPER_MOTOR_HEADER_STEP_MOTOR_INTERFACE_H_
#define HAL_STEPPER_MOTOR_HEADER_STEP_MOTOR_INTERFACE_H_

#include "../../../Common/bitmath.h"
#include "../../../Common/macros.h"
#include "../../../Common/typedef.h"

//connection from darling pair IC
//red coil in stepper motor gets 5v and others are from the software

void Stepper_Motor_Full_Coil__void_init(u8 Group, u16 No_of_rotations);

#endif /* HAL_STEPPER_MOTOR_HEADER_STEP_MOTOR_INTERFACE_H_ */
