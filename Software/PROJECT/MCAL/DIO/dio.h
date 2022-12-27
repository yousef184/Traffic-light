/*
 * DIO.h
 *
 *  Created on: Oct 5, 2022
 *      Author: Omar Nabih
 */

#ifndef DIO_H_
#define DIO_H_


#include "../../UTILITIES/std_types.h"
#include "../../UTILITIES/common_macros.h"
#include "../../UTILITIES/micro_config.h"


												/* Ports macros */
#define PORT_A 'A'
#define PORT_B 'B'
#define PORT_C 'C'
#define PORT_D 'D'

												/* direction defines*/
#define IN (0u)
#define OUT (1u)

													/* Typedefs */
typedef enum EN_DIOError_t
{
    DIO_OK, DIO_ERROR
}EN_DIOError_t;

											/* Functions Prototypes */
EN_DIOError_t DIO_init(uint8_t portNumber, uint8_t pinNumber, bool direction);
EN_DIOError_t DIO_write(uint8_t portNumber, uint8_t pinNumber, bool value);
EN_DIOError_t DIO_toggle(uint8_t portNumber, uint8_t pinNumber);
EN_DIOError_t DIO_read(uint8_t portNumber, uint8_t pinNumber, uint8_t* value);

#endif /* DIO_H_ */
