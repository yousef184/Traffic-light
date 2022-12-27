/*
 * button.c
 *
 *  Created on: Oct 5, 2022
 *      Author: Omar Nabih
 */

#include "button.h"

// 1. Button initialization
EN_BUTTONError_t BUTTON_init(uint8_t buttonPort, uint8_t buttonPin)
{
	EN_BUTTONError_t BUTTON_init_error = BUTTON_OK;

	DIO_init(buttonPort, buttonPin, IN);

	if(TRUE)
	{
		EN_BUTTONError_t BUTTON_init_error = BUTTON_OK;
	}

	return BUTTON_init_error;
}

// 2. get button state
EN_BUTTONError_t BUTTON_state(uint8_t buttonPort, uint8_t buttonPin, uint8_t* value)
{
	EN_BUTTONError_t BUTTON_state_error = BUTTON_OK;

	DIO_read(buttonPort, buttonPin, value);

	if(TRUE)
	{
		EN_BUTTONError_t BUTTON_state_error = BUTTON_OK;
	}

	return BUTTON_state_error;
} // this function takes address to a flag as a parameter to modify it --> (&buttonState)

// 3. Button interrupt initialization
EN_BUTTONError_t BUTTON_interrupt_init(uint8_t button_interrupt, uint8_t button_interrupt_sense)
{
	EN_BUTTONError_t BUTTON_interrupt_init_error = BUTTON_OK;

	switch(button_interrupt)
	{
	case INT_0 :
		external_interrupt_init(button_interrupt, button_interrupt_sense);
		BUTTON_init(PORT_D, PD2);

		if(TRUE)
		{
			EN_BUTTONError_t BUTTON_interrupt_init_error = BUTTON_OK;
		}

		break;

	case INT_1 :
		external_interrupt_init(button_interrupt, button_interrupt_sense);
		BUTTON_init(PORT_D, PD3);

		if(TRUE)
		{
			EN_BUTTONError_t BUTTON_interrupt_init_error = BUTTON_OK;
		}

		break;

	case INT_2 :
		external_interrupt_init(button_interrupt, button_interrupt_sense);
		BUTTON_init(PORT_B, PB2);

		if(TRUE)
		{
			EN_BUTTONError_t BUTTON_interrupt_init_error = BUTTON_OK;
		}

		break;

	}

	return BUTTON_interrupt_init_error;
}
