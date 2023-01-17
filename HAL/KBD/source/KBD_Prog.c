/*
 * KBD_Prog.c
 *
 *  Created on: Aug 10, 2022
 *      Author: osama
 */


#include "../../../Common/bitmath.h"
#include "../../../Common/macros.h"
#include "../../../Common/typedef.h"

#include "../../../MCAL/DIO/DIO_interface.h"
#include "../header/KBD_Config.h"
#include"../header/KBD_interface.h"

void KBD_void_Init(void)
{
	//set Coloums as output
DIO_VoidSetPinDir(KBD_ColoumGroup,KBDColoum0,output);
DIO_VoidSetPinDir(KBD_ColoumGroup,KBDColoum1,output);
DIO_VoidSetPinDir(KBD_ColoumGroup,KBDColoum2,output);
DIO_VoidSetPinDir(KBD_ColoumGroup,KBDColoum3,output);

//set Rows as input
DIO_VoidSetPinDir(KBD_ROWGroup,KBDRow0,input);
DIO_VoidSetPinDir(KBD_ROWGroup,KBDRow1,input);
DIO_VoidSetPinDir(KBD_ROWGroup,KBDRow2,input);
DIO_VoidSetPinDir(KBD_ROWGroup,KBDRow3,input);

//set row pins as high for pull-up resistor
DIO_VoidSetPinValue(KBD_ROWGroup,KBDRow0,high);
DIO_VoidSetPinValue(KBD_ROWGroup,KBDRow1,high);
DIO_VoidSetPinValue(KBD_ROWGroup,KBDRow2,high);
DIO_VoidSetPinValue(KBD_ROWGroup,KBDRow3,high);


}

u8 KBD_u8_ReadButton(void)
{
u8 Local_return = NotFound;
u8 Local_Counter1 = 0;
u8 Local_Counter2 = 0;
DIO_VoidSetPinValue(KBD_ColoumGroup,KBDColoum0,high);
DIO_VoidSetPinValue(KBD_ColoumGroup,KBDColoum1,high);
DIO_VoidSetPinValue(KBD_ColoumGroup,KBDColoum2,high);
DIO_VoidSetPinValue(KBD_ColoumGroup,KBDColoum3,high);

for(Local_Counter1 = COLOUM_Start; Local_Counter1<(COLOUM_End+1);Local_Counter1++)
{
	//set Coloum as low(GND)
	DIO_VoidSetPinValue(KBD_ColoumGroup,Local_Counter1,low);
	for(Local_Counter2 = ROW_Start; Local_Counter2<(ROW_End+1);Local_Counter2++)
	{
		if(DIO_u8ReadPinValue(KBD_ROWGroup,Local_Counter2) == pressed)
		{
			Local_return = KBD[Local_Counter2][Local_Counter1];
			break;
		}
		else
		{
			//for Misra Rule
		}
	}
	DIO_VoidSetPinValue(KBD_ColoumGroup,Local_Counter1,high);
}
return Local_return;
}
