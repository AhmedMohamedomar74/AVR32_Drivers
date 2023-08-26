/*
 * main.c
 *
 *  Created on: Aug 21, 2023
 *      Author: ahmedomar
 */
#include "../HAL/LED/LED.h"
#include "../HAL/SEVEN_SEG/SEVEN_SEG.h"


int main(void)
{

	while (1)
	{
		Seven_Segment(3,0);
		//seven_segment(10);
	}
	return 0;
}
