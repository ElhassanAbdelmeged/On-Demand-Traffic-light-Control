/*
 * push_button.h
 *
 *  Created on: Dec 14, 2022
 *      Author: dell
 */

#ifndef PUSH_BUTTON_H_
#define PUSH_BUTTON_H_

#include"../MCAL/gpio.h"

/*
 * the button is pull down connected so logic high / rising edge will occur when the button is pressed
 * */
void BUTTON_init(uint8 port_num, uint8 pin_num);

#endif /* PUSH_BUTTON_H_ */
