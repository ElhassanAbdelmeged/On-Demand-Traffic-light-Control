#include "../application/app.h"




//typedef enum{ red,yellow,green}LED_STATE;
LED_STATE g_theWorkingLed=red; //flage to check which cars' led is on
uint8 i=0;
uint8 g_flag=0;
uint8 g_Timer_ticks=0;

void app_start(void)
{


	Timer1_ConfigType TIMER_Configs={0,1000,F_CPU_1024,CTC_MODE};
	Timer1_init(&TIMER_Configs);


	/*pedestrian*/
	LED_init(PORTB_ID , PIN0_ID); //red
	LED_init(PORTB_ID , PIN1_ID) ;//yellow
	LED_init(PORTB_ID , PIN2_ID); //green
	/*CARS*/
	LED_init(PORTA_ID , PIN0_ID) ;//red
	LED_init(PORTA_ID , PIN1_ID) ;//yellow
	LED_init(PORTA_ID , PIN2_ID) ;//green

	BUTTON_init(PORTD_ID , PIN2_ID);

	sei();
	INT0_init();






	while(1)
	{

		INT0_setCallBack(INT0_ISR_calledback);


/*___________________cars green_____________________________________*/
		g_theWorkingLed=green;
		g_Timer_ticks=0;
		LED_on(PORTB_ID, PIN0_ID);//pedestrian red
		LED_on (PORTA_ID , PIN2_ID) ; //car green
		Timer1_setCallBack(TIMER_ISR_COUNTER);
		while(g_Timer_ticks!=5);
		LED_off(PORTB_ID, PIN0_ID);
		LED_off (PORTA_ID , PIN2_ID) ;

/*________________yellows________________________________________*/
		g_theWorkingLed=yellow;
		for(i=0;i<10;i++)
		{
			TOGGLE_BIT(PORTB,PIN1_ID);
			TOGGLE_BIT(PORTA,PIN1_ID);
			_delay_ms(500);
		}

		/*to be sure the yellow will be off*/
		LED_off(PORTB_ID, PIN1_ID);
		LED_off(PORTA_ID, PIN1_ID);

/*___________________cars red_____________________________________*/

		g_theWorkingLed=red;
		g_Timer_ticks=0;
		LED_on(PORTB_ID, PIN2_ID);
		LED_on (PORTA_ID , PIN0_ID) ;
		Timer1_setCallBack(TIMER_ISR_COUNTER);
		while(g_Timer_ticks!=5);
		LED_off(PORTB_ID, PIN2_ID);//ped. green
		LED_off (PORTA_ID , PIN0_ID) ; //car red



	}

}



void INT0_ISR_calledback(void)
{

	_delay_ms(30);
if(!(PIND&(1<<PIN2_ID)))  //to neglect the long press effect
{

	//while(PIND&(1<<PIN2_ID)){break;}

		/*If pressed when the cars' Green LED is on or the cars' Yellow LED is blinking,
			 * the pedestrian Red LED will be on{ NOT MENTIONED for which time so i will light it for 1 second}
			 * then bothYellow LEDs start to blink for five seconds,
			 * then the cars' Red LED and pedestrian Green LEDs are on for five seconds,
			 *this means that pedestrian must wait until the Green LED is on.
			 */
		if ((g_theWorkingLed==yellow)||(g_theWorkingLed==green))
		{
			LED_off(PORTB_ID, PIN2_ID);//ped. green
			LED_off (PORTA_ID , PIN0_ID) ; //car red
			LED_off(PORTB_ID, PIN0_ID);
			LED_off (PORTA_ID , PIN2_ID) ;
			LED_off(PORTB_ID, PIN1_ID);
			LED_off(PORTA_ID, PIN1_ID);

			LED_on(PORTB_ID, PIN0_ID);//pedestrian red
			LED_on(PORTA_ID, PIN2_ID);
			_delay_ms(1000);
			LED_off(PORTB_ID, PIN0_ID);//pedestrian red
			LED_off(PORTA_ID, PIN2_ID);
			for(i=0;i<10;i++)
			{

				TOGGLE_BIT(PORTB,PIN1_ID);
				TOGGLE_BIT(PORTA,PIN1_ID);
				_delay_ms(500);

			}
			/*to be sure the yellow will be off*/
			LED_off(PORTB_ID, PIN1_ID);
			LED_off(PORTA_ID, PIN1_ID);


			//g_Timer_ticks=0;
			LED_on(PORTB_ID, PIN2_ID);
			LED_on (PORTA_ID , PIN0_ID) ;
			Timer1_setCallBack(TIMER_ISR_COUNTER);
			//while(g_Timer_ticks!=5);
			_delay_ms(5000);
			LED_off(PORTB_ID, PIN2_ID);//ped. green
			LED_off (PORTA_ID , PIN0_ID) ; //car red


		}



		/*If pressed when the cars' Red LED is on,
			 *the pedestrian's Green LED and the cars' Red LEDs will be on for five seconds, this means that
			 *pedestrians can cross the street while the pedestrian's Green LED is on.*/

		else if (red==g_theWorkingLed)
		{

	/*
			LED_on(PORTB_ID, PIN2_ID);
			LED_on (PORTA_ID , PIN0_ID) ;

			_delay_ms(5000);
	*/
		}



}

else{

}

}


/*
 * Description :
 * It is just a incremented counter
 * used to be called back by the timer
 * which set to make an interrupt every 1 second
 * so the counter's value will increase every 1 second
 */



void TIMER_ISR_COUNTER(void)
{
	g_Timer_ticks++;
}
