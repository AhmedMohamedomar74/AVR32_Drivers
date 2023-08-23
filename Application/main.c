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
		LED_ON(PORTA,PIN0);
	}
	return 0;
}
