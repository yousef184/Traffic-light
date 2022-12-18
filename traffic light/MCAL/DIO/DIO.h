/*
 * DIO.h
 *
 * Created: 11/4/2022 10:02:14 AM
 *  Author: YousefElsayed
 */ 


#ifndef DIO_H_
#define DIO_H_
#include "../../UTILTIES/Register.h"


#define PORT_A 'A'
#define PORT_B 'B'
#define PORT_C 'C'
#define PORT_D 'D'

#define IN 0
#define OUT 1

#define LOW 0
#define HIGH 1

void DIO_init(uint8_t portNumber, uint8_t pinNumber, uint8_t direction);
void DIO_write(uint8_t portNumber, uint8_t pinNumber, uint8_t value);
void DIO_toggle(uint8_t portNumber, uint8_t pinNumber);
void DIO_read(uint8_t portNumber, uint8_t pinNumber, uint8_t *value);

#endif /* DIO_H_ */