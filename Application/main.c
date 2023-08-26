/*
 * main.c
 *
 *  Created on: Aug 21, 2023
 *      Author: ahmedomar
 */
#include "../HAL/LED/LED.h"

u8 x;
int main(void)
{

	while (1)
	{
		Seven_Segment(3);
		//seven_segment(10);
	}
	return 0;
}
