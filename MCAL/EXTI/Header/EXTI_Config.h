/*
 * EXTI_Config.h
 *
 *  Created on: Aug 17, 2022
 *      Author: osama
 */

#ifndef MCAL_EXTI_HEADER_EXTI_CONFIG_H_
#define MCAL_EXTI_HEADER_EXTI_CONFIG_H_
#include "../Header/EXTI_private.h"


/*Select One of those modes
	EXIT_LOW			0
	EXIT_OnChange 		1
	EXIT_fallingedge	2
	EXIT_risingedge		3
 */

#define EXIT0_TriggerMode   EXIT_OnChange

/*Select One of those modes
	EXIT_LOW			0
	EXIT_OnChange 		1
	EXIT_fallingedge	2
	EXIT_risingedge		3
 */

#define EXIT1_TriggerMode   EXIT_OnChange

/*Select One of those modes
	EXIT_LOW			0
	EXIT_OnChange 		1
	EXIT_fallingedge	2
	EXIT_risingedge		3
 */

#define EXIT2_TriggerMode   EXIT_OnChange


#endif /* MCAL_EXTI_HEADER_EXTI_CONFIG_H_ */
