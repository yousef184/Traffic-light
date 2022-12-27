/*
 * app.c
 *
 *  Created on: Oct 13, 2022
 *      Author: Omar Nabih
 */
#include "app.h"

uint8_t green_traffic_flag = LOW;
uint8_t red_traffic_flag = LOW;
void APP_START(void)
{
	// 1. external interrupt initialization INT0
	BUTTON_interrupt_init(INT_0, rising_edge);

											/*traffic lights*/
	// 2. cars traffic lights initialization
	LED_init(traffic_lights_port, traffic_red_pin);
	LED_init(traffic_lights_port, traffic_yellow_pin);
	LED_init(traffic_lights_port, traffic_green_pin);

	// 3. cars traffic lights off
	LED_off(traffic_lights_port, traffic_red_pin);
	LED_off(traffic_lights_port, traffic_yellow_pin);
	LED_off(traffic_lights_port, traffic_green_pin);

										/*pedestrian lights*/
	// 4. pedestrian traffic lights initialization
	LED_init(pedestrian_lights_port, pedestrian_red_pin);
	LED_init(pedestrian_lights_port, pedestrian_yellow_pin);
	LED_init(pedestrian_lights_port, pedestrian_green_pin);

	// 5. pedestrian traffic lights off
	LED_off(pedestrian_lights_port, pedestrian_red_pin);
	LED_off(pedestrian_lights_port, pedestrian_yellow_pin);
	LED_off(pedestrian_lights_port, pedestrian_green_pin);

	while(TRUE)
	{
		// 6. cars green on & pedestrian red on for 5 seconds
		LED_on(traffic_lights_port, traffic_green_pin);
		green_traffic_flag = HIGH;
		LED_on(pedestrian_lights_port, pedestrian_red_pin);
		LED_normal_delay();

		// 7. cars green off & cars yellow blinks for 5 seconds while pedestrian red still on
		LED_off(traffic_lights_port, traffic_green_pin);
		green_traffic_flag = LOW;
		LED_traffic_yellow_blink();

		// 8. cars red on & pedestrian red off & pedestrian green on for 5 seconds
		LED_on(traffic_lights_port, traffic_red_pin);
		red_traffic_flag = HIGH;
		LED_off(pedestrian_lights_port, pedestrian_red_pin);
		LED_on(pedestrian_lights_port, pedestrian_green_pin);
		LED_normal_delay();

		// 9. cars red off & pedestrian green off & pedestrian red on and cars yellow blinks for 5 seconds
		LED_off(traffic_lights_port, traffic_red_pin);
		red_traffic_flag = LOW;
		LED_off(pedestrian_lights_port, pedestrian_green_pin);
		LED_on(pedestrian_lights_port, pedestrian_red_pin);
		LED_traffic_yellow_blink();

	}
}

ISR(INT0_vect)
{
	pedestrain_context_switch();
}

static void pedestrain_context_switch(void)
{
	if(red_traffic_flag == HIGH)
	{
		// 1. cars red on and pedestrian green on for 5 seconds
		LED_on(traffic_lights_port, traffic_red_pin);
		LED_on(pedestrian_lights_port, pedestrian_green_pin);
		LED_pedestrian_delay();

		// 2. cars red off & both yellow leds blink for 5 seconds and pedestrian green still on
		LED_off(traffic_lights_port, traffic_red_pin);
		LED_yellow_blink();

		// 3. pedestrian green off & pedestrian red on and cars green on for 5 seconds
		LED_off(pedestrian_lights_port, pedestrian_green_pin);
		LED_on(pedestrian_lights_port, pedestrian_red_pin);
		LED_on(traffic_lights_port, traffic_green_pin);
		LED_pedestrian_delay();

		// 4. cars green off & both yellow led blink for 5 seconds and pedestrian red still on
		LED_off(traffic_lights_port, traffic_green_pin);
		LED_traffic_yellow_blink();

		// 5. cars led on and back to normal mode & pedestrian red is still on
		LED_on(traffic_lights_port, traffic_red_pin);
	}

	else if(yellow_traffic_flag == HIGH)
	{
		// 1. both yellow led blink for 5 seconds
		LED_yellow_blink();

		// 2. pedestrian red off & cars red on and pedestrian green on for 5 seconds
		LED_off(pedestrian_lights_port, pedestrian_red_pin);
		LED_on(traffic_lights_port, traffic_red_pin);
		LED_on(pedestrian_lights_port, pedestrian_green_pin);
		LED_pedestrian_delay();

		// 3. cars red off & both yellow led blink for 5 seconds and pedestrian green still on
		LED_off(traffic_lights_port, traffic_red_pin);
		LED_yellow_blink();

		// 4. pedestrian green off & cars green on and pedestrian red on for 5 seconds
		LED_off(pedestrian_lights_port, pedestrian_green_pin);
		LED_on(traffic_lights_port, traffic_green_pin);
		LED_on(pedestrian_lights_port, pedestrian_red_pin);
		LED_pedestrian_delay();

		// 5. cars green off & pedestrian red still on & yellow traffic blinks and back to normal mode
		LED_off(traffic_lights_port, traffic_green_pin);
		LED_traffic_yellow_blink();
	}

	else if(green_traffic_flag == HIGH)
	{
		// 1. both yellow leds blink for 5 seconds
		LED_yellow_blink();

		// 2. cars green off & pedestrian red off & cars red on and pedestrian green on for 5 seconds
		LED_off(traffic_lights_port, traffic_green_pin);
		LED_off(pedestrian_lights_port, pedestrian_red_pin);
		LED_on(traffic_lights_port, traffic_red_pin);
		LED_on(pedestrian_lights_port, pedestrian_green_pin);
		LED_pedestrian_delay();

		// 3. cars red off & both yellow leds blink for 5 seconds & pedestrian green still on
		LED_off(traffic_lights_port, traffic_red_pin);
		LED_yellow_blink();

		// 4. pedestrian green off & cars green on and pedestrian red on for 5 seconds & back to normal mode
		LED_off(pedestrian_lights_port, pedestrian_green_pin);
		LED_on(traffic_lights_port, traffic_green_pin);
		LED_on(pedestrian_lights_port, pedestrian_red_pin);
		LED_pedestrian_delay();
	}
}



