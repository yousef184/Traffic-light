/*
 * interrupts.h
 *
 *  Created on: Oct 15, 2022
 *      Author: Omar Nabih
 */

#ifndef INTERRUPTS_H_
#define INTERRUPTS_H_

#include "../../UTILITIES/common_macros.h"
#include "../../UTILITIES/std_types.h"
#include "../../UTILITIES/micro_config.h"

										/* interrupts definitions */
#define INT_0 0
#define INT_1 1
#define INT_2 2

										/* interrupts sense definitions */
#define low_level 0
#define logical_change 1
#define falling_edge 2
#define rising_edge 3

											/* typedefs */
typedef enum EN_INTERRUPTSError_t
{
    INTERRUPTS_OK, INTERRUPTS_ERROR
}EN_INTERRUPTSError_t;

										/* functions prototype */
EN_INTERRUPTSError_t external_interrupt_init(uint8_t interrupt, uint8_t interrupt_sense);
#endif /* INTERRUPTS_H_ */
