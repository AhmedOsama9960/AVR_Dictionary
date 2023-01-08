/*
 * GIE_prog.c
 *
 *  Created on: Aug 25, 2022
 *      Author: osama
 */

#include "../../../Common/bitmath.h"
#include "../../../Common/macros.h"
#include "../../../Common/typedef.h"
#include "../Header/GIE_register.h"

void GIE_voidEnable_GIE(void)
{

	voidset_bit(SREG,I_Bit);

}

void GIE_voidDisable_GIE(void)
{

	voidclear(SREG,I_Bit);

}
