/*
 * LED.h
 *
 *  Created on: Aug 22, 2023
 *      Author: ahmedomar
 */

#ifndef LED_H_
#define LED_H_

#include "LED_Config.h"


Led_state LED_ON (u8 PORT,u8 PIN);
Led_state LED_OFF (u8 PORT,u8 PIN);
void Toggel_LED (u8 PORT,u8 PIN);
#endif /* LED_H_ */
