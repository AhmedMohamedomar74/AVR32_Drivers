/*
 * main.c
 *
 *  Created on: Aug 21, 2023
 *      Author: ahmedomar
 */
#include "../HAL/LED/LED.h"
#include "../HAL/SEVEN_SEG/SEVEN_SEG.h"
#include "../HAL/KEY_PAD/KEY_PAD.h"

u8 x;
int main(void)
{

	while (1)
	{
		keypad_init();
		return_char_keypad(&x);
		Seven_Segment_Mul(x);
		return 0;
	}
}
