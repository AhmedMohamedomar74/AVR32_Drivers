/*
 * main.c
 *
 *  Created on: Aug 21, 2023
 *      Author: ahmedomar
 */
#include "../HAL/LED.h"

int main(void)
{

	while (1)
	{
		LED_OFF();
		_delay_ms(1000);
		Toggel_LED();
		_delay_ms(1000);

	}
	return 0;
}
