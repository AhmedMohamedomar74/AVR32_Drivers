/*
 * KEY_PAD_config.h
 *
 *  Created on: Aug 27, 2023
 *      Author: ahmedomar
 */

#ifndef KEY_PAD_CONFIG_H_
#define KEY_PAD_CONFIG_H_

#include "../../MCAL/GPIO.h"
// define the the start and the end for row and coulmn bins
#define ROW_INIT PIN0
#define ROW_END  ROW_INIT+3
#define COL_INIT PIN4   
#define COL_END PIN7   
#define ROW_NUMBERS 4
#define COL_NUMBERS 4
// Select wich port you need
// define the port of the keypad
#define KEYPAD_PORT PORTC
// define rows pins and coulmns
#define Row_0 ROW_INIT
#define Row_1 ROW_INIT+1
#define Row_2 ROW_INIT+2
#define Row_3 ROW_INIT+3
#define Col_0 COL_INIT
#define Col_1 COL_INIT+1
#define Col_2 COL_INIT+2
#define Col_3 COL_INIT+3

#define NOT_PRESSED 0XFF


extern u8 keybad_values [ROW_NUMBERS][COL_NUMBERS];

#endif /* KEY_PAD_CONFIG_H_ */
