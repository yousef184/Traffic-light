/*
 * led.c
 *
 *  Created on: Oct 5, 2022
 *      Author: Omar Nabih
 */

#include "led.h"

uint8_t g_ovf = 0;
uint8_t delay_flag = LOW;
uint8_t yellow_traffic_flag = LOW;

// 1. LED initialization
EN_LEDError_t LED_init(uint8_t ledPort, uint8_t ledPin)
{
	EN_LEDError_t LED_init_error = LED_OK;

	DIO_init(ledPort, ledPin, OUT);

	if(TRUE)
	{
		LED_init_error = LED_OK;
	}

	return LED_init_error;
}

// 2. Turn LED on
EN_LEDError_t LED_on(uint8_t ledPort, uint8_t ledPin)
{
	EN_LEDError_t LED_on_error = LED_OK;

	DIO_write(ledPort, ledPin, HIGH);

	if(TRUE)
	{
		LED_on_error = LED_OK;
	}

	return LED_on_error;
}

// 3. Turn LED off
EN_LEDError_t LED_off(uint8_t ledPort, uint8_t ledPin)
{
	EN_LEDError_t LED_off_error = LED_OK;

	DIO_write(ledPort, ledPin, LOW);

	if(TRUE)
	{
		LED_off_error = LED_OK;
	}

	return LED_off_error;
}

// 4. Toggle LED
EN_LEDError_t LED_toggle(uint8_t ledPort, uint8_t ledPin)
{
	EN_LEDError_t LED_toggle_error = LED_OK;

	DIO_toggle(ledPort, ledPin);

	if(TRUE)
	{
		LED_toggle_error = LED_OK;
	}

	return LED_toggle_error;
}

// 5. LED Blinking
EN_LEDError_t LED_blink(uint8_t ledPort, uint8_t ledPin)
{
	EN_LEDError_t LED_blink_error = LED_OK;

	LED_toggle(ledPort, ledPin);
	_delay_ms(100);

	if(TRUE)
	{
		LED_blink_error = LED_OK;
	}

	return LED_blink_error;
}

// 6. LED delay to be used in normal mode using TIMER0
EN_LEDError_t LED_normal_delay(void)
{
	EN_LEDError_t LED_normal_delay_error = LED_OK;

	TIMER0_init_normal_mode();
	TIMER0_set_initial_value(11);
	TIMER0_interrupt_enable();
	TIMER0_start_normal_mode(clk_1024);

	while(delay_flag != HIGH);
	delay_flag = LOW;
	TIMER0_stop_normal_mode();

	if(TRUE)
	{
		LED_normal_delay_error = LED_OK;
	}

	return LED_normal_delay_error;
}

// 7. LED delay to be used in pedestrian mode using TIMER1
EN_LEDError_t LED_pedestrian_delay(void)
{
	EN_LEDError_t LED_pedestrian_delay_error = LED_OK;

	TIMER1_init_normal_mode();
	TIMER1_set_initial_value(46004);
	TIMER1_start_normal_mode(clk_256);

	while ((TIFR & (1<<TOV1)) == 0);

	TIMER1_stop_normal_mode();
	TIMER1_clear_ovf_flag();

	if(TRUE)
	{
		LED_pedestrian_delay_error = LED_OK;
	}

	return LED_pedestrian_delay_error;
}

// 8. Both yellow LEDs blinking
EN_LEDError_t LED_yellow_blink(void)
{
	EN_LEDError_t LED_yellow_blink_error = LED_OK;

	TIMER1_init_normal_mode();
	TIMER1_set_initial_value(46004);
	TIMER1_start_normal_mode(clk_256);
	while ((TIFR & (1<<TOV1)) == 0)
	{
		LED_blink(traffic_lights_port, traffic_yellow_pin);
		LED_blink(pedestrian_lights_port, pedestrian_yellow_pin);
	}
	TIMER1_stop_normal_mode();
	TIMER1_clear_ovf_flag();
	LED_off(traffic_lights_port, traffic_yellow_pin);
	LED_off(pedestrian_lights_port, pedestrian_yellow_pin);

	if(TRUE)
	{
		LED_yellow_blink_error = LED_OK;
	}

	return LED_yellow_blink_error;
}

// 9. Cars traffic yellow LED blinking
EN_LEDError_t LED_traffic_yellow_blink(void)
{
	EN_LEDError_t LED_traffic_yellow_blink = LED_OK;

	uint8_t blink_counter = 0;
	yellow_traffic_flag = HIGH;

	while(blink_counter < 50)
	{
		LED_blink(traffic_lights_port, traffic_yellow_pin);
		blink_counter++;
	}

	blink_counter = 0;
	LED_off(traffic_lights_port, traffic_yellow_pin);
	yellow_traffic_flag = LOW;

	if(TRUE)
	{
		LED_traffic_yellow_blink = LED_OK;
	}

	return LED_traffic_yellow_blink;
}

ISR(TIMER0_OVF_vect)
{
	g_ovf++;
	TIMER0_set_initial_value(11);

	if(g_ovf == no_of_overflows)
	{
		delay_flag = HIGH;
		g_ovf = 0;
	}
}
