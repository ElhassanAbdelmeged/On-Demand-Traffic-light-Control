/*
 * INT0.h
 *
 *  Created on: Dec 14, 2022
 *      Author: dell
 */

#ifndef INT0_H_
#define INT0_H_

#include "../Utilities/std_types.h"
#include <avr/interrupt.h>

void INT0_init(void);
void INT0_setCallBack(void(*a_ptr)(void));


#endif /* INT0_H_ */
