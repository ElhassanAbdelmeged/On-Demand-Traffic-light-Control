/*
 * app.h
 *
 *  Created on: Dec 17, 2022
 *      Author: dell
 */

#ifndef APP_H_
#define APP_H_
#include<avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include"../MCAL/gpio.h"
#include"../MCAL/timer.h"
#include "../Utilities/std_types.h"
#include "../Utilities/common_macros.h"
#include"../HAL/led.h"
#include"../HAL/push_button.h"
#include"../Utilities/INT0.h"

/*******************************************************************************
 *                               Types Declaration                             *
 *******************************************************************************/


typedef enum{ red,yellow,green}LED_STATE;



/*******************************************************************************
 *                              Functions Prototypes                           *
 *******************************************************************************/

/*
 * Description :
 * It is just a incremented counter
 * used to be called back by the timer
 * which set to make an interrupt every 1 second
 * so the counter's value will increase every 1 second
 */

void TIMER_ISR_COUNTER(void);


/*
 * Description :
 *If pressed when the cars' Red LED is on,
 *the pedestrian's Green LED and the cars' Red LEDs will be on for five seconds, this means that
 *pedestrians can cross the street while the pedestrian's Green LED is on.
 *If pressed when the cars' Green LED is on or the cars' Yellow LED is blinking,
 * the pedestrian Red LED will be on{ NOT MENTIONED for which time so i will light it for 1 second}
 * then bothYellow LEDs start to blink for five seconds,
 * then the cars' Red LED and pedestrian Green LEDs are on for five seconds,
 *this means that pedestrian must wait until the Green LED is on.
 */



void INT0_ISR_calledback(void);


void app_start(void);

#endif /* APP_H_ */
