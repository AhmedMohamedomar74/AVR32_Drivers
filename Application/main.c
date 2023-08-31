/*
 * main.c
 *
 *  Created on: Aug 31, 2023
 *      Author: ahmedomar
 */
#include "../HAL/LCD/LCD.h"

int main(void)
{
	init_lcd();
	LCD_set_cursor(1,1);
	while(1)
	{
		displayNumberOnLCD(-123456789);
		LCD_Display_special_char(1,2);
		_delay_ms(1000);
		LCD_clear();
	}
}
