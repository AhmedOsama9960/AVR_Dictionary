/*
 * KBD_Config.h
 *
 *  Created on: Aug 10, 2022
 *      Author: osama
 */

#ifndef HAL_KBD_HEADER_KBD_CONFIG_H_
#define HAL_KBD_HEADER_KBD_CONFIG_H_

#define ROW            4
#define COLOUM         4
#define ROW_Start      0
#define ROW_End		   3
#define COLOUM_Start   4
#define COLOUM_End     7


/*		{1,2,3,4},
		{5,6,7,8},
		{9,10,11,12},
		{13,14,15,16}
*/
u8 KBD[ROW][COLOUM] =
{
		{'7','8','9','*'},
		{'4','5','6','-'},
		{'1','2','3','+'},
		{'/','0','.','='}
};


#define KBD_ROWGroup    group_A
#define KBDRow0         PIN_A0
#define KBDRow1         PIN_A1
#define KBDRow2         PIN_A2
#define KBDRow3         PIN_A3

#define KBD_ColoumGroup     group_A
#define KBDColoum0           PIN_A4
#define KBDColoum1           PIN_A5
#define KBDColoum2           PIN_A6
#define KBDColoum3           PIN_A7


#endif /* HAL_KBD_HEADER_KBD_CONFIG_H_ */
