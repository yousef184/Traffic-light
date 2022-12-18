/*
 * BUTTON.h
 *
 * Created: 11/4/2022 11:27:39 AM
 *  Author: YousefElsayed
 */ 


#ifndef BUTTON_H_
#define BUTTON_H_
#include "../../MCAL/DIO/DIO.h"


void button_init(uint8_t portNumber, uint8_t pinNumber);
void button_read(uint8_t portNumber, uint8_t pinNumber , uint8_t *value);


#endif /* BUTTON_H_ */