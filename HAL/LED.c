#include "LED.h"
#include <util/delay.h>
/*
 * LED.c
 *
 *  Created on: Aug 22, 2023
 *      Author: ahmedomar
 */

Led_state LED_ON(u8 PORT, u8 PIN)
{
    Led_state Local_Led_status = Not_Working;
    GPIO_setPindDirection(PORT,PIN,Output_direction);
    GPIO_setPinValue(PORT,PIN,high_value);
    Local_Led_status = Working;
    return Local_Led_status;
}

Led_state LED_OFF(u8 PORT, u8 PIN)
{
    Led_state Local_Led_status = Working;
    GPIO_setPindDirection(PORT,PIN,Output_direction);
    GPIO_setPinValue(PORT,PIN,low_value);
    Local_Led_status = Not_Working;
    return Local_Led_status;
}

void Toggel_LED(u8 PORT, u8 PIN)
{
    LED_ON(PORT,PIN);
    _delay_ms(1000);
    LED_OFF(PORT,PIN);
    _delay_ms(1000);
}
