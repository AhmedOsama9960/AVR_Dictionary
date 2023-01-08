/*
 * Interface.h
 *
 *  Created on: Aug 10, 2022
 *      Author: osama
 */

#ifndef HAL_SEV_SEG_HEADER_SEVSEG_INTERFACE_H_
#define HAL_SEV_SEG_HEADER_SEVSEG_INTERFACE_H_

void SevSeg_VoidDisplayNo(u8 Local_Number);
void SevSeg_VoidDisplayRang(void);
void SevSeg_VoidClear(void);
void SevSeg_VoidTurnoff(void);
void SevSeg_voidInit(void);
void SevSeg_voidTwo7Seg(u8 Group_1,u8 Group_2, u8 start, u8 end);



#endif /* HAL_SEV_SEG_HEADER_SEVSEG_INTERFACE_H_ */
