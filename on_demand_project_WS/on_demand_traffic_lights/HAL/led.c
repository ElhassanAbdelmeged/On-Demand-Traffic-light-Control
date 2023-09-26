#include <util/delay.h>
#include"../HAL/led.h"
#include"../Utilities/common_macros.h"
#include<avr/io.h>



Error_state  LED_init(uint8 port_num, uint8 pin_num)
{
	Error_state led_state=valid;

	if(port_num>3||pin_num>7)
		{
		Error_state led_state=not_valid;
		}
	else{GPIO_setupPinDirection(port_num,pin_num,PIN_OUTPUT);}

	return led_state;
}





Error_state LED_on(uint8 port_num, uint8 pin_num)
{
	Error_state led_state=valid;

	if(port_num>3||pin_num>7)
		{
		Error_state led_state=not_valid;
		}
	else{
	GPIO_writePin(port_num, pin_num, LOGIC_HIGH);
	}

	return led_state;
}




Error_state LED_off(uint8 port_num, uint8 pin_num)
{
	Error_state led_state=valid;

	if(port_num>3||pin_num>7)
		{
		Error_state led_state=not_valid;
		}
	else{
	GPIO_writePin(port_num, pin_num, LOGIC_LOW);
}
	return led_state;
}


Error_state LED_toggle(uint8 port_num, uint8 pin_num)
{
	Error_state led_state=valid;

	if(port_num==PORTA_ID)
	{
		TOGGLE_BIT(PORTA,pin_num);
	}

	else if(port_num==PORTB_ID)
	{
		TOGGLE_BIT(PORTB,pin_num);
	}
else if(port_num==PORTC_ID)
{
	TOGGLE_BIT(PORTC,pin_num);
}

	else if(port_num==PORTD_ID)
	{
		TOGGLE_BIT(PORTC,pin_num);
	}





	_delay_ms(1000);
	return led_state;
}
