/*
 * application.h
 *
 * Created: 11/15/2022 3:49:39 PM
 *  Author: YousefElsayed
 */ 


#ifndef APPLICATION_H_
#define APPLICATION_H_

#include "../ECUAL/led/led.h"
#include "../ECUAL/button/button.h"
#include "../ECUAL/timer/timer.h"
#include "../UTILTIES/interrupts.h"


void app_init(void);
void app_start(void);



#endif /* APPLICATION_H_ */