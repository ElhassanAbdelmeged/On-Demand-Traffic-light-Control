#include <util/delay.h>
#include"../HAL/push_button.h"

void BUTTON_init(uint8 port_num, uint8 pin_num)
{

	GPIO_setupPinDirection(port_num, pin_num, PIN_INPUT);

}