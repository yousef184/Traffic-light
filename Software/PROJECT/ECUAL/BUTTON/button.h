/*
 * button.h
 *
 *  Created on: Oct 5, 2022
 *      Author: Omar Nabih
 */

#ifndef BUTTON_H_
#define BUTTON_H_

#include"../../MCAL/DIO/dio.h"
#include "../../MCAL/INTERRUPTS/interrupts.h"

#define BUTTON_1_PORT PORT_C
#define BUTTON_1_PIN PIN0
#define BUTTON_2_PORT PORT_C
#define BUTTON_2_PIN PIN1      //buttons and ports definitions

									  /* button state definition */
#define BUTTON_PRESSED HIGH
#define BUTTON_NOT_PRESSED LOW

											/* Typedefs */
typedef enum EN_BUTTONError_t
{
    BUTTON_OK, BUTTON_ERROR
}EN_BUTTONError_t;

										/*functions prototypes*/
EN_BUTTONError_t BUTTON_init(uint8_t buttonPort, uint8_t buttonPin);
EN_BUTTONError_t BUTTON_state(uint8_t buttonPort, uint8_t buttonPin, uint8_t* value);
EN_BUTTONError_t BUTTON_interrupt_init(uint8_t interrupt, uint8_t interrupt_sense);
#endif /* BUTTON_H_ */
