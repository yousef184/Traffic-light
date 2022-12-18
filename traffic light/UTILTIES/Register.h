/*
 * Register.h
 *
 * Created: 10/24/2022 6:26:23 PM
 *  Author: YousefElsayed
 */ 


#ifndef REGISTER_H_
#define REGISTER_H_

typedef unsigned char uint8_t;
typedef unsigned short uint16_t;
typedef unsigned int uint32_t;

#define PORTA *((volatile uint8_t *)0x3B)
#define DDRA *((volatile uint8_t *)0x3A)
#define PINA *((volatile uint8_t *)0x39)


#define PORTB *((volatile uint8_t *)0x38)
#define DDRB *((volatile uint8_t *)0x37)
#define PINB *((volatile uint8_t *)0x36)


#define PORTC *((volatile uint8_t *)0x35)
#define DDRC *((volatile uint8_t *)0x34)
#define PINC *((volatile uint8_t *)0x33)


#define PORTD *((volatile uint8_t*)0x32)
#define DDRD *((volatile uint8_t *)0x31)
#define PIND *((volatile uint8_t *)0x30)


#define TCCR0 *((volatile uint8_t*)0x53)
#define TCNT0 *((volatile uint8_t *)0x52)
#define TIFR *((volatile uint8_t *)0x58)
#define TIMSK (*(volatile uint8_t*)(0x59))

#define SREG (*(volatile uint8_t*)(0x5F))
#define GICR (*(volatile uint8_t*)(0x5B))
#define MCUCR (*(volatile uint8_t*)(0x55))

#define ADMUX *((volatile uint8_t*)0x27)
#define ADCSRA *((volatile uint8_t*)0x26)
#define ADCL *((volatile uint8_t*)0x24)
#define ADCH *((volatile uint8_t *)0x25)

#define UBRRH *((volatile uint8_t*)0x40)
#define UCSRC *((volatile uint8_t*)0x40)
#define UCSRB *((volatile uint8_t*)0x2A)
#define UBRRL *((volatile uint8_t *)0x29)
#define UCSRA *((volatile uint8_t*)0x2B)
#define UDR *((volatile uint8_t*)0x2C)

#endif /* REGISTER_H_ */