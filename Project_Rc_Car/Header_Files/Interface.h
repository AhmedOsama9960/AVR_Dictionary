/*
 * Function_Prototypes.h
 *
 *  Created on: Jan 6, 2023
 *      Author: osama
 */

#ifndef PROJECT_RC_CAR_HEADER_FILES_INTERFACE_H_
#define PROJECT_RC_CAR_HEADER_FILES_INTERFACE_H_

							/*Declarations for Global Functions [Prototypes]*/
extern u8 flag;
void line_Follower(u8 IR_Right, u8 IR_Left);
void Servo_Checker (u16 *ob_right, u16 * ob_left);
void obstacle_detection(void);
void Bluetooth_Control(u8 action);

#endif /* PROJECT_RC_CAR_HEADER_FILES_INTERFACE_H_ */
