#ifndef _GPIO_H
#define _GPIO_H
// Includes
#include "MCAL_REGs.h"
#include <stdio.h>
// defines
//@ref ports
#define PORTA 0
#define PORTB 1
#define PORTC 2
#define PORTD 3
//@ref pins
#define PIN0 0
#define PIN1 1
#define PIN2 2
#define PIN3 3
#define PIN4 4
#define PIN5 5
#define PIN6 6
#define PIN7 7
//@ref pin value
#define low_value 0
#define high_value 1
//@ref pin direction
#define Input_direction 0
#define Output_direction 1
//@ref pin state
#define state_low 0
#define state_high 1
// API
void GPIO_setPortValue(u8 portId, u8 value);
void GPIO_setPinValue(u8 portId, u8 PinId, u8 value);
void GPIO_setPortDirection(u8 portId, u8 PortDirectionValue);
void GPIO_setPindDirection(u8 portId, u8 PinId, u8 PintDirectionValue);
u8 GPIO_getPortValue(u8 portId);
u8 GPIO_PinValue(u8 portId, u8 PinId);

#endif
