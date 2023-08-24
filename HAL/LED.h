/*
 * LED.h
 *
 *  Created on: Aug 22, 2023
 *      Author: ahmedomar
 */

#ifndef LED_H_
#define LED_H_

#include "LED_Config.h"
#include <avr/delay.h>

Error_state LED_ON();
Error_state LED_OFF();
Error_state Toggel_LED();

extern Error_state local_error;

#endif /* LED_H_ */
