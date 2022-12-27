/*
 * app.h
 *
 *  Created on: Oct 13, 2022
 *      Author: Omar Nabih
 */

#ifndef APPLICATION_APP_H_
#define APPLICATION_APP_H_

#include "../ECUAL/BUTTON/button.h"
#include "../ECUAL/LED/led.h"


extern uint8_t yellow_traffic_flag;
void APP_START(void);
static void pedestrain_context_switch(void);
#endif /* APPLICATION_APP_H_ */
