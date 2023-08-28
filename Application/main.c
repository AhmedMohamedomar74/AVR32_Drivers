/*
 * main.c
 *
 *  Created on: Aug 21, 2023
 *      Author: ahmedomar
 */
#include "../HAL/LED/LED.h"
#include "../HAL/SEVEN_SEG/SEVEN_SEG.h"
#include "../HAL/KEY_PAD/KEY_PAD.h"

u8 return_char;
int main(void)
{

	keypad_init(&keypad_opj1);
	while (1)
	{
		/*for (u8 i = 0; i < 100; i++)
		{
			Seven_Segment_Mul(i);
			//_delay_ms(1000);

		}*/
		return_char_keypad(&keypad_opj1,&return_char);

		Seven_Segment_Mul(return_char);
		//GPIO_setPindDirection(PORTD,PIN0,Out_Port_direction);
	}
}
