/*
 * BUTTON.c
 *
 * Created: 11/4/2022 11:27:29 AM
 *  Author: YousefElsayed
 */ 

#include "BUTTON.h"


void button_init(uint8_t portNumber, uint8_t pinNumber)
{
	DIO_init(portNumber,pinNumber,IN);
}

void button_read(uint8_t portNumber, uint8_t pinNumber , uint8_t *value)
{
	DIO_read(portNumber,pinNumber,value);
	
}
