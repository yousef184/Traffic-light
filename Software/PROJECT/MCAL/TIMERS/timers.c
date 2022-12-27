/*
 * timers.c
 *
 *  Created on: Oct 21, 2022
 *      Author: Omar Nabih
 */

#include "timers.h"

													/* TIMER0 normal mode Functions */
// 1. TIMER0 initialization
EN_TIMERSError_t TIMER0_init_normal_mode(void)
{
	EN_TIMERSError_t TIMER0_init_error = TIMERS_OK;

	TCCR0 = 0x00; // normal mode
	SET_BIT(TCCR0,FOC0);

	if(TRUE)
	{
		TIMER0_init_error = TIMERS_OK;
	}

	return TIMER0_init_error;
}

// 2. Set initial value to TIMER0
EN_TIMERSError_t TIMER0_set_initial_value(uint8_t initial_value)
{
	EN_TIMERSError_t TIMER0_set_initial_value_error = TIMERS_OK;

	TCNT0 = initial_value; // setting initial value;

	if(TRUE)
	{
		TIMER0_set_initial_value_error = TIMERS_OK;
	}

	return TIMER0_set_initial_value_error;
}

// 3. Enable TIMER0 interrupts if needed
EN_TIMERSError_t TIMER0_interrupt_enable(void)
{
	EN_TIMERSError_t TIMER0_interrupt_enable_error = TIMERS_OK;

	SET_BIT(SREG,7);
	SET_BIT(TIMSK,TOIE0);

	if(TRUE)
	{
		TIMER0_interrupt_enable_error = TIMERS_OK;
	}

	return TIMER0_interrupt_enable_error;
}

// 4. Start TIMER0
EN_TIMERSError_t TIMER0_start_normal_mode(uint8_t prescalar)
{
	EN_TIMERSError_t TIMER0_start_normal_mode_error = TIMERS_OK;

	switch (prescalar)
	{

	case no_prescaling :
		SET_BIT(TCCR0,CS00);
		CLEAR_BIT(TCCR0,CS01);
		CLEAR_BIT(TCCR0,CS02);

		if(TRUE)
		{
			TIMER0_start_normal_mode_error = TIMERS_OK;
		}

		break;

	case clk_8 :
		SET_BIT(TCCR0,CS01);
		CLEAR_BIT(TCCR0,CS00);
		CLEAR_BIT(TCCR0,CS02);

		if(TRUE)
		{
			TIMER0_start_normal_mode_error = TIMERS_OK;
		}

		break;

	case clk_64 :
		SET_BIT(TCCR0,CS00);
		SET_BIT(TCCR0,CS01);
		CLEAR_BIT(TCCR0,CS02);

		if(TRUE)
		{
			TIMER0_start_normal_mode_error = TIMERS_OK;
		}

		break;

	case clk_256 :
		CLEAR_BIT(TCCR0,CS00);
		CLEAR_BIT(TCCR0,CS01);
		SET_BIT(TCCR0,CS02);

		if(TRUE)
		{
			TIMER0_start_normal_mode_error = TIMERS_OK;
		}

		break;

	case clk_1024 :
		SET_BIT(TCCR0,CS00);
		CLEAR_BIT(TCCR0,CS01);
		SET_BIT(TCCR0,CS02);

		if(TRUE)
		{
			TIMER0_start_normal_mode_error = TIMERS_OK;
		}

		break;

	}

	return TIMER0_start_normal_mode_error;

}

 // 5. Clear TOV0 bit to resume the program if needed
EN_TIMERSError_t TIMER0_clear_ovf_flag(void)
{
	EN_TIMERSError_t TIMER0_clear_ovf_flag_error = TIMERS_OK;

	SET_BIT(TIFR,TOV0);

	if(TRUE)
	{
		TIMER0_clear_ovf_flag_error = TIMERS_OK;
	}

	return TIMER0_clear_ovf_flag_error;
}

// 6. Stop TIMER0 time counting
EN_TIMERSError_t TIMER0_stop_normal_mode(void)
{
	EN_TIMERSError_t TIMER0_stop_normal_mode_error = TIMERS_OK;

	TCCR0 = 0x00;

	if(TRUE)
	{
		TIMER0_stop_normal_mode_error = TIMERS_OK;
	}

	return TIMER0_stop_normal_mode_error;
}


												/* TIMER1 normal mode Functions */
// 1. TIMER1 initialization
EN_TIMERSError_t TIMER1_init_normal_mode(void)
{
	EN_TIMERSError_t TIMER1_init_error = TIMERS_OK;

	TCCR1A = 0x00; // normal mode
	TCCR1B = 0x00; // normal mode

	if(TRUE)
	{
		TIMER1_init_error = TIMERS_OK;
	}

	return TIMER1_init_error;
}

// 2. Set initial value to TIMER1
EN_TIMERSError_t TIMER1_set_initial_value(uint16_t initial_value)
{
	EN_TIMERSError_t TIMER1_set_initial_value_error = TIMERS_OK;

	TCNT1 = initial_value;

	if(TRUE)
	{
		TIMER1_set_initial_value_error = TIMERS_OK;
	}

	return TIMER1_set_initial_value_error;
}

// 3. Enable TIMER1 interrupts if needed
EN_TIMERSError_t TIMER1_interrupt_enable(void)
{
	EN_TIMERSError_t TIMER1_set_interrupt_enable_error = TIMERS_OK;

	SET_BIT(SREG,7);
	SET_BIT(TIMSK,TOIE1);

	if(TRUE)
	{
		TIMER1_set_interrupt_enable_error = TIMERS_OK;
	}

	return TIMER1_set_interrupt_enable_error;
}

// 4. Start TIMER1
EN_TIMERSError_t TIMER1_start_normal_mode(uint8_t prescalar)
{
	EN_TIMERSError_t TIMER1_start_normal_mode_error = TIMERS_OK;

	switch (prescalar)
		{

		case no_prescaling :
			SET_BIT(TCCR1B,CS10);
			CLEAR_BIT(TCCR1B,CS11);
			CLEAR_BIT(TCCR1B,CS12);

			if(TRUE)
			{
				TIMER1_start_normal_mode_error = TIMERS_OK;
			}

			break;

		case clk_8 :
			SET_BIT(TCCR1B,CS11);
			CLEAR_BIT(TCCR1B,CS10);
			CLEAR_BIT(TCCR1B,CS12);

			if(TRUE)
			{
				TIMER1_start_normal_mode_error = TIMERS_OK;
			}

			break;

		case clk_64 :
			SET_BIT(TCCR1B,CS10);
			SET_BIT(TCCR1B,CS11);
			CLEAR_BIT(TCCR1B,CS12);

			if(TRUE)
			{
				TIMER1_start_normal_mode_error = TIMERS_OK;
			}

			break;

		case clk_256 :
			CLEAR_BIT(TCCR1B,CS10);
			CLEAR_BIT(TCCR1B,CS11);
			SET_BIT(TCCR1B,CS12);

			if(TRUE)
			{
				TIMER1_start_normal_mode_error = TIMERS_OK;
			}

			break;

		case clk_1024 :
			SET_BIT(TCCR1B,CS10);
			CLEAR_BIT(TCCR1B,CS11);
			SET_BIT(TCCR1B,CS12);

			if(TRUE)
			{
				TIMER1_start_normal_mode_error = TIMERS_OK;
			}

			break;

		}

	return TIMER1_start_normal_mode_error;

}

// 5. Clear TOV1 bit to resume the program if needed
EN_TIMERSError_t TIMER1_clear_ovf_flag(void)
{
	EN_TIMERSError_t TIMER1_clear_ovf_flag_error = TIMERS_OK;

	SET_BIT(TIFR,TOV1);

	if(TRUE)
	{
		TIMER1_clear_ovf_flag_error = TIMERS_OK;
	}

	return TIMER1_clear_ovf_flag_error;
}

// 6. Stop TIMER1 time counting
EN_TIMERSError_t TIMER1_stop_normal_mode(void)
{
	EN_TIMERSError_t TIMER1_stop_normal_mode_error = TIMERS_OK;

	TCCR1B = 0x00;

	if(TRUE)
	{
		TIMER1_stop_normal_mode_error = TIMERS_OK;
	}

	return TIMER1_stop_normal_mode_error;
}
