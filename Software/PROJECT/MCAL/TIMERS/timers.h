/*
 * timers.h
 *
 *  Created on: Oct 21, 2022
 *      Author: Omar Nabih
 */

#ifndef TIMERS_H_
#define TIMERS_H_

#include "../../UTILITIES/std_types.h"
#include "../../UTILITIES/common_macros.h"
#include "../../UTILITIES/micro_config.h"

#define no_prescaling 1
#define clk_8 2
#define clk_64 3
#define clk_256 4
#define clk_1024 5

																		/* Typedefs */
typedef enum EN_TIMERSError_t
{
    TIMERS_OK, TIMERS_ERROR
}EN_TIMERSError_t;

																		/* TIMER 0 */

EN_TIMERSError_t TIMER0_init_normal_mode(void);
EN_TIMERSError_t TIMER0_set_initial_value(uint8_t initial_value);
EN_TIMERSError_t TIMER0_interrupt_enable(void);
EN_TIMERSError_t TIMER0_start_normal_mode(uint8_t prescalar);
EN_TIMERSError_t TIMER0_clear_ovf_flag(void);
EN_TIMERSError_t TIMER0_stop_normal_mode(void);

																		/* TIMER 1 */
EN_TIMERSError_t TIMER1_init_normal_mode(void);
EN_TIMERSError_t TIMER1_set_initial_value(uint16_t initial_value);
EN_TIMERSError_t TIMER1_interrupt_enable(void);
EN_TIMERSError_t TIMER1_start_normal_mode(uint8_t prescalar);
EN_TIMERSError_t TIMER1_clear_ovf_flag(void);
EN_TIMERSError_t TIMER1_stop_normal_mode(void);
#endif /* TIMERS_H_ */
