/*
 * LED.h
 *
 * Created: 11/4/2022 11:09:49 AM
 *  Author: YousefElsayed
 */ 


#ifndef LED_H_
#define LED_H_
#include "../../MCAL/DIO/DIO.h"

void led_init(uint8_t ledPort, uint8_t ledPin);
void led_on(uint8_t ledPort, uint8_t ledPin);
void led_off(uint8_t ledPort, uint8_t ledPin);
void led_toggle(uint8_t ledPort, uint8_t ledPin);

#endif /* LED_H_ */