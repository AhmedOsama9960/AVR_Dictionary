/*
 * typedef.h
 *
 *  Created on: Aug 8, 2022
 *      Author: osama
 */

#ifndef COMMON_TYPEDEF_H_
#define COMMON_TYPEDEF_H_

typedef unsigned  char          u8;
typedef signed    char          s8;
typedef unsigned  short         u16;
typedef signed    short     	s16;
typedef unsigned  int       	u32;
typedef signed    int       	s32;
typedef unsigned  long int  	ul32;
typedef 		    long  		l32;
typedef unsigned long long int	ull64;
typedef           float     	f32;
typedef           double    	d64;
typedef         long double 	ld128;



typedef enum
{
noerror,
start_error,
address_error,
data_error,
stop_error
}TWI_ErrorStatus;

#endif /* COMMON_TYPEDEF_H_ */
