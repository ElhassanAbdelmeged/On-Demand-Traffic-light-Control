#include <avr/io.h>
#include <avr/interrupt.h>
#include"../Utilities/INT0.h"
#include "../Utilities/common_macros.h"
#include "../Utilities/std_types.h"

/*******************************************************************************
 *                           Global Variables                                  *
 *******************************************************************************/

/* Global variables to hold the address of the call back function in the application */
static volatile void (*g_INT0_callBackPtr )(void) = NULL_PTR;

/*******************************************************************************
 *                       Interrupt Service Routines                            *
 *******************************************************************************/


ISR(INT0_vect)
{

	if(g_INT0_callBackPtr != NULL_PTR)
		{
			/* Call the Call Back function in the application after the edge is detected */
			(*g_INT0_callBackPtr )();
		}
}


/* External INT0 enable and configuration function */
void INT0_init(void)
{
	DDRD  &= (~(1<<PD2));               // Configure INT0/PD2 as input pin
	MCUCR |= (1<<ISC00) | (1<<ISC01);   // Trigger INT0 with the raising edge
	GICR  |= (1<<INT0);                 // Enable external interrupt pin INT0
	SREG  |= (1<<7);                    // Enable interrupts by setting I-bit
}


void INT0_setCallBack(void(*a_ptr)(void))
{

	/* Save the address of the Call back function in a global variable */
	g_INT0_callBackPtr = a_ptr;

}