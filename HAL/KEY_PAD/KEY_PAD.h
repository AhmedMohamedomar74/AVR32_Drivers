/*
 * KEY_PAD.h
 *
 *  Created on: Aug 27, 2023
 *      Author: ahmedomar
 */

#ifndef KEY_PAD_H_
#define KEY_PAD_H_

#include "KEY_PAD_config.h"
Error_state keypad_init ();
Error_state return_char_keypad(u8 *r_char);
#endif /* KEY_PAD_H_ */
