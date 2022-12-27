/*
 * led.h
 *
 *  Created on: Oct 5, 2022
 *      Author: Omar Nabih
 */

#ifndef LED_H_
#define LED_H_

#include"../../MCAL/DIO/dio.h"
#include"../../MCAL/TIMERS/timers.h"

																/* Timers Definitions */
#define no_of_overflows 20
																/* LED definitions */
#define traffic_lights_port PORT_A
#define traffic_red_pin PA0
#define traffic_yellow_pin PA1
#define traffic_green_pin PA2

#define pedestrian_lights_port PORT_B
#define pedestrian_red_pin PB0
#define pedestrian_yellow_pin PB1
#define pedestrian_green_pin PB2

																		/* Typedefs */
typedef enum EN_LEDError_t
{
    LED_OK, LED_ERROR
}EN_LEDError_t;
																/* LED functions prototypes*/
EN_LEDError_t LED_init(uint8_t ledPort, uint8_t ledPin);
EN_LEDError_t LED_on(uint8_t ledPort, uint8_t ledPin);
EN_LEDError_t LED_off(uint8_t ledPort, uint8_t ledPin);
EN_LEDError_t LED_toggle(uint8_t ledPort, uint8_t ledPin);
EN_LEDError_t LED_blink(uint8_t ledPort, uint8_t ledPin);
EN_LEDError_t LED_yellow_blink(void);
EN_LEDError_t LED_traffic_yellow_blink(void);
																/* DELAY functions prototypes */
EN_LEDError_t LED_normal_delay(void);
EN_LEDError_t LED_pedestrian_delay(void);
EN_LEDError_t LED_yellow_delay(void);

#endif /* LED_H_ */
