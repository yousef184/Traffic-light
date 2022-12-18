/*
 * LED.c
 *
 * Created: 11/4/2022 11:10:03 AM
 *  Author: YousefElsayed
 */ 
#include "LED.h"

void led_init(uint8_t ledPort, uint8_t ledPin)
{
	DIO_init(ledPort,ledPin,OUT);
}
void led_on(uint8_t ledPort, uint8_t ledPin)
{
	DIO_write(ledPort,ledPin,HIGH);
}
void led_off(uint8_t ledPort, uint8_t ledPin)
{
	DIO_write(ledPort,ledPin,LOW);
}
void led_toggle(uint8_t ledPort, uint8_t ledPin)
{
	DIO_toggle(ledPort,ledPin);
}