/*
 * interrupts.c
 *
 *  Created on: Oct 15, 2022
 *      Author: Omar Nabih
 */
#include "interrupts.h"

// 1. External interrupts initialization
EN_INTERRUPTSError_t external_interrupt_init(uint8_t interrupt, uint8_t interrupt_sense)
{
	EN_INTERRUPTSError_t INTERRUPTS_error = INTERRUPTS_OK;

	switch(interrupt)

	{

	case INT_0 :

		if(interrupt_sense == low_level)
		{
			SREG  &= ~(1<<7); 					// disable interrupts by clearing I-bit
			GICR  |= (1<<INT0);                	// Enable external interrupt pin INT0
			MCUCR &= ~(1<<ISC00) & ~(1<<ISC01); // Trigger INT0 with the low level
			SREG  |= (1<<7); 					// Enable interrupts by setting I-bit
		}

		else if(interrupt_sense == logical_change)
		{
			SREG  &= ~(1<<7); 					// disable interrupts by clearing I-bit
			GICR  |= (1<<INT0);                 // Enable external interrupt pin INT0
			MCUCR |= (1<<ISC00);
			MCUCR &= ~(1<<ISC01);				// trigger INT0 with logical change
			SREG  |= (1<<7); 					// Enable interrupts by setting I-bit
		}

		else if(interrupt_sense == falling_edge)
		{
			SREG  &= ~(1<<7); 					// disable interrupts by clearing I-bit
			GICR  |= (1<<INT0);                 // Enable external interrupt pin INT0
			MCUCR |= (1<<ISC01);
			MCUCR &= ~(1<<ISC00);				// trigger INT0 with falling edge
			SREG  |= (1<<7); 					// Enable interrupts by setting I-bit
		}

		else if(interrupt_sense == rising_edge)
		{
			SREG  &= ~(1<<7); 					// disable interrupts by clearing I-bit
			GICR  |= (1<<INT0);                 // Enable external interrupt pin INT0
			MCUCR |= (1<<ISC01);
			MCUCR |= (1<<ISC00);					// trigger INT0 with rising edge
			SREG  |= (1<<7); 					// Enable interrupts by setting I-bit
		}

	if (TRUE)
	{
		INTERRUPTS_error = INTERRUPTS_OK;
	}

		break;

	case INT_1 :

		if(interrupt_sense == low_level)
		{
			SREG  &= ~(1<<7); 					// disable interrupts by clearing I-bit
			GICR  |= (1<<INT1);                	// Enable external interrupt pin INT1
			MCUCR &= ~(1<<ISC10) & ~(1<<ISC11); // Trigger INT1 with the low level
			SREG  |= (1<<7); 					// Enable interrupts by setting I-bit
		}

		else if(interrupt_sense == logical_change)
		{
			SREG  &= ~(1<<7); 					// disable interrupts by clearing I-bit
			GICR  |= (1<<INT1);                 // Enable external interrupt pin INT1
			MCUCR |= (1<<ISC10);
			MCUCR &= ~(1<<ISC11);				// trigger INT1 with logical change
			SREG  |= (1<<7); 					// Enable interrupts by setting I-bit
		}

		else if(interrupt_sense == falling_edge)
		{
			SREG  &= ~(1<<7); 					// disable interrupts by clearing I-bit
			GICR  |= (1<<INT1);                 // Enable external interrupt pin INT1
			MCUCR |= (1<<ISC11);
			MCUCR &= ~(1<<ISC10);				// trigger INT1 with falling edge
			SREG  |= (1<<7); 					// Enable interrupts by setting I-bit
		}

		else if(interrupt_sense == rising_edge)
		{
			SREG  &= ~(1<<7); 					// disable interrupts by clearing I-bit
			GIFR  &= ~(1<<7);
			GICR  |= (1<<INT1);                 // Enable external interrupt pin INT1
			MCUCR |= (1<<ISC11);
			MCUCR |= (1<<ISC10);					// trigger INT1 with rising edge
			SREG  |= (1<<7); 					// Enable interrupts by setting I-bit
		}

	if (TRUE)
	{
		INTERRUPTS_error = INTERRUPTS_OK;
	}

		break;

	case INT_2 :

		if(interrupt_sense == falling_edge)
		{
			SREG  &= ~(1<<7); 					// disable interrupts by clearing I-bit
			GICR  |= (1<<INT2);                 // Enable external interrupt pin INT2
			MCUCSR &= ~(1<<ISC2);				// Trigger INT2 with falling edge
		}

		else if(interrupt_sense == rising_edge)
		{
			SREG  &= ~(1<<7); 					// disable interrupts by clearing I-bit
			GICR  |= (1<<INT2);                 // Enable external interrupt pin INT0
			MCUCSR |= (1<<ISC2);				// Trigger INT2 with rising edge
		}

	if (TRUE)
	{
		INTERRUPTS_error = INTERRUPTS_OK;
	}

		break;

	}

	return INTERRUPTS_error;
}


