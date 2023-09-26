/*
 * led.h
 *
 *  Created on: Dec 14, 2022
 *      Author: dell
 */

#ifndef LED_H_
#define LED_H_
#include"../MCAL/gpio.h"
#include<avr/io.h>

typedef enum{not_valid,valid}Error_state;
Error_state LED_init(uint8 port_num, uint8 pin_num);
Error_state LED_on(uint8 port_num, uint8 pin_num);
Error_state LED_off(uint8 port_num, uint8 pin_num);
Error_state LED_toggle(uint8 port_num, uint8 pin_num);

#endif /* LED_H_ */
