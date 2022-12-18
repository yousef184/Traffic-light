/*
 * timer.h
 *
 * Created: 11/14/2022 9:27:11 PM
 *  Author: YousefElsayed
 */ 


#ifndef TIMER_H_
#define TIMER_H_

#include "../DIO/DIO.h"


void timer_init();//initialize Timer0
void timer_delay(uint16_t millisec); //delay of specific amount default uses 256 prescalar




#endif /* TIMER_H_ */