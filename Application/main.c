/*
 * main.c
 *
 *  Created on: Aug 21, 2023
 *      Author: ahmedomar
 */
#include "../HAL/LED/LED.h"
#include "../HAL/SEVEN_SEG/SEVEN_SEG.h"

int check_prime(int a);
int main(void)
{

	while (1)
	{
		for (int var = 0; var < 20; ++var) {
			Seven_Segment_Mul(var);
			_delay_ms(3000);
		}
		//Seven_Segment_Mul(56);
	}
	return 0;
}
int check_prime(int a)
{
   int c;

   for (c = 2; c <= a - 1; c++)
   {
      if (a%c == 0)
     return 0;
   }
   if (c == a)
      return 1;
}
