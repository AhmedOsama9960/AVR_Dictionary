/*
 * bitmath.h
 *
 *  Created on: Aug 8, 2022
 *      Author: osama
 */






#ifndef COMMON_BITMATH_H_
#define COMMON_BITMATH_H_

#define voidset_bit(reg,bit) reg|=(1<<bit)
#define voidtoggle(reg,bit)  reg^=(1<<bit)
#define voidclear(reg,bit)   reg&=~(1<<bit)
#define u8read(reg,bit)       (reg>>bit)&1

#endif /* COMMON_BITMATH_H_ */
