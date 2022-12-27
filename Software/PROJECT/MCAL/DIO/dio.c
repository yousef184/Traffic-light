/*
 * DIO.c
 *
 *  Created on: Oct 5, 2022
 *      Author: Omar Nabih
 */

#include "dio.h"

											/* Functions Definitions */

// 1. DIO initialization
EN_DIOError_t DIO_init(uint8_t portNumber, uint8_t pinNumber, bool direction)
{
	EN_DIOError_t DIO_init_error = DIO_OK;

	switch(portNumber)

	{

	case PORT_A :
		if(direction == IN)
		{
			CLEAR_BIT(DDRA, pinNumber);
		}
		else if(direction == OUT)
		{
			SET_BIT(DDRA, pinNumber);
		}

	if (TRUE)
	{
		DIO_init_error = DIO_OK;
	}

	break;

	case PORT_B :
		if(direction == IN)
		{
			CLEAR_BIT(DDRB, pinNumber);
		}
		else if(direction == OUT)
		{
			SET_BIT(DDRB, pinNumber);
		}

	if (TRUE)
	{
		DIO_init_error = DIO_OK;
	}

	break;

	case PORT_C :
		if(direction == IN)
		{
			CLEAR_BIT(DDRC, pinNumber);
		}
		else if(direction == OUT)
		{
			SET_BIT(DDRC, pinNumber);
		}

	if (TRUE)
	{
		DIO_init_error = DIO_OK;
	}

	break;

	case PORT_D :
		if(direction == IN)
		{
			CLEAR_BIT(DDRD, pinNumber);
		}
		else if(direction == OUT)
		{
			SET_BIT(DDRD, pinNumber);
		}

	if (TRUE)
	{
		DIO_init_error = DIO_OK;
	}

	break;

	}

	return DIO_init_error;
}

// 2. DIO write (HIGH or LOW)
EN_DIOError_t DIO_write(uint8_t portNumber, uint8_t pinNumber, bool value)
{
	EN_DIOError_t DIO_write_error = DIO_OK;

	switch(portNumber)

	{

		case PORT_A :
			if(value == LOW)
			{
				CLEAR_BIT(PORTA, pinNumber);
			}
			else if(value == HIGH)
			{
				SET_BIT(PORTA, pinNumber);
			}

		if (TRUE)
		{
			DIO_write_error = DIO_OK;
		}

		break;

		case PORT_B :
			if(value == LOW)
			{
				CLEAR_BIT(PORTB, pinNumber);
			}
			else if(value == HIGH)
			{
				SET_BIT(PORTB, pinNumber);
			}

		if (TRUE)
		{
			DIO_write_error = DIO_OK;
		}

		break;

		case PORT_C :
			if(value == LOW)
			{
				CLEAR_BIT(PORTC, pinNumber);
			}
			else if(value == HIGH)
			{
				SET_BIT(PORTC, pinNumber);
			}

		if (TRUE)
		{
			DIO_write_error = DIO_OK;
		}

		break;

		case PORT_D :
			if(value == LOW)
			{
				CLEAR_BIT(PORTD, pinNumber);
			}
			else if(value == HIGH)
			{
				SET_BIT(PORTD, pinNumber);
			}

		if (TRUE)
		{
			DIO_write_error = DIO_OK;
		}

		break;

	}

	return DIO_write_error;

}

// 3. DIO toggle
EN_DIOError_t DIO_toggle(uint8_t portNumber, uint8_t pinNumber)
{
	EN_DIOError_t DIO_toggle_error = DIO_OK;

	switch(portNumber)
	{
			case PORT_A :
					TOGGLE_BIT(PORTA, pinNumber);

			if (TRUE)
				{
					DIO_toggle_error = DIO_OK;
				}

			break;


			case PORT_B :
					TOGGLE_BIT(PORTB, pinNumber);

			if (TRUE)
				{
					DIO_toggle_error = DIO_OK;
				}

			break;


			case PORT_C :
					TOGGLE_BIT(PORTC, pinNumber);

			if (TRUE)
				{
					DIO_toggle_error = DIO_OK;
				}

			break;


			case PORT_D :
				TOGGLE_BIT(PORTD, pinNumber);

			if (TRUE)
				{
					DIO_toggle_error = DIO_OK;
				}

			break;
	}

	return DIO_toggle_error;
}

// 4. DIO Read
EN_DIOError_t DIO_read(uint8_t portNumber, uint8_t pinNumber, uint8_t* value)
{
	EN_DIOError_t DIO_read_error = DIO_OK;

	switch(portNumber)
	{
			case PORT_A :
				*value = BIT_READ(PINA, pinNumber);

			if (TRUE)
				{
					DIO_read_error = DIO_OK;
				}

			break;


			case PORT_B :
				*value = BIT_READ(PINB, pinNumber);

			if (TRUE)
				{
					DIO_read_error = DIO_OK;
				}

			break;


			case PORT_C :
				*value = BIT_READ(PINC, pinNumber);

			if (TRUE)
				{
					DIO_read_error = DIO_OK;
				}

			break;


			case PORT_D :
				*value = BIT_READ(PIND, pinNumber);

			if (TRUE)
				{
					DIO_read_error = DIO_OK;
				}

			break;

	}

	return DIO_read_error;
}

