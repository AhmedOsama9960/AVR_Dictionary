/*
 * Servo_M_prog.c
 *
 *  Created on: Aug 30, 2022
 *      Author: osama
 */


#include "../../../Common/macros.h"
#include "../../../Common/bitmath.h"
#include "../../../Common/typedef.h"

#include "../../../MCAL/Timer1/Header/Tim1_Interface.h"
#include "../Header/Servo_M_interface.h"
#include "../Header/Servo_M_config.h"
#include <util/delay.h>

void Servo_voidInit(void)
{

	//selecting the mode of Timer_1
voidset_bit(TCCR1A,WGM11);
voidclear(TCCR1A,WGM10);

//Compare Output Mode
voidset_bit(TCCR1B,WGM13);
voidset_bit(TCCR1B,WGM12);
voidclear(TCCR1A,COM1A0);

//Force Compare
voidset_bit(TCCR1A,COM1A1);

//selecting the prescaller
voidclear(TCCR1B,CS12);
voidset_bit(TCCR1B,CS11);
voidclear(TCCR1B,CS10);
ICR1 = 19999;

}


void Servo_M_Values(u8 Angle)
{
	//OCR1A must be from 0 to 300!!
	if(Angle == 180)
		OCR1A = 2500;
	else if (Angle == 90)
		OCR1A = 500;
	else if (Angle == 0)
		OCR1A = 1500;

}






