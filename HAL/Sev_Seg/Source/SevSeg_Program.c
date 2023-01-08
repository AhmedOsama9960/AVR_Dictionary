/*
 * Program.c
 *
 *  Created on: Aug 10, 2022
 *      Author: osama
 */
#include "../../../Common/macros.h"
#include "../../../Common/typedef.h"
#include "../../../Common/bitmath.h"

#include "../Header/SevSeg_Private.h"
#include "../Header/SevSeg_Interface.h"
#include "../Header/SevSeg_Config.h"
#include <util/delay.h>

static u8 SevSeg_Arr_Numbers[10]= {
		CA_ZERO,
		CA_ONE,
		CA_TWO,
		CA_THREE,
		CA_FOUR,
		CA_FIVE,
		CA_SIX,
		CA_SEVEN,
		CA_EIGHT,
		CA_NINE};



void SevSeg_voidInit(void)
{
DIO_VoidSetPortDir(SevSeg_Group, Max_Output);
}

void SevSeg_VoidDisplayNo(u8 Local_Number)
{
	if(Local_Number<10 && Local_Number>=0)
DIO_VoidSetPortValue(SevSeg_Group,SevSeg_Arr_Numbers[Local_Number]);
}



void SevSeg_VoidDisplayRang(void)
{
	u8 Local_Counter;
	for( Local_Counter = 0; Local_Counter<10;Local_Counter++){
	DIO_VoidSetPortValue(SevSeg_Group,SevSeg_Arr_Numbers[Local_Counter]);
	_delay_ms(1000);
	}
}
void SevSeg_VoidClear(void)
{
DIO_VoidSetPortValue(SevSeg_Group,SevSeg_Arr_Numbers[0]);
}

void SevSeg_VoidTurnoff(void)
{
DIO_VoidSetPortValue(SevSeg_Group,SevSeg_turnoff);
}

void SevSeg_voidTwo7Seg(u8 Group_1,u8 Group_2, u8 start, u8 end)
{
	u8 Local_Counter_1;
	u8 Local_counter_2;
		for( Local_Counter_1 = start; Local_Counter_1>=0; Local_Counter_1--){
			DIO_VoidSetPortValue(Group_1,SevSeg_Arr_Numbers[Local_Counter_1]);
			for(Local_counter_2 = end;Local_counter_2 >= 0; Local_counter_2--)
			{
				DIO_VoidSetPortValue(Group_2,SevSeg_Arr_Numbers[Local_counter_2]);
				_delay_ms(1000);
				}
		}

}
