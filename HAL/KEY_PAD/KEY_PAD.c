#include "KEY_PAD.h"
/*
 * KEY_PAD.c
 *
 *  Created on: Aug 27, 2023
 *      Author: ahmedomar
 */

Error_state keypad_init()
{
    Error_state local_err = Unvalid_Port;
    if ((PORTA != KEYPAD_PORT) && (PORTB != KEYPAD_PORT) && (PORTC != KEYPAD_PORT) && (PORTD != KEYPAD_PORT))
    {
        local_err = Unvalid_Port;
    }
    else
    {
    	local_err = Valid_Port;
    	            GPIO_setPin_PUll_UP(KEYPAD_PORT, Row_0);
    	            GPIO_setPin_PUll_UP(KEYPAD_PORT, Row_1);
    	            GPIO_setPin_PUll_UP(KEYPAD_PORT, Row_2);
    	            GPIO_setPin_PUll_UP(KEYPAD_PORT, Row_3);
    	            GPIO_setPindDirection(KEYPAD_PORT, Col_0, Output_direction);
    	            GPIO_setPindDirection(KEYPAD_PORT, Col_1, Output_direction);
    	            GPIO_setPindDirection(KEYPAD_PORT, Col_2, Output_direction);
    	            GPIO_setPindDirection(KEYPAD_PORT, Col_3, Output_direction);
    	            GPIO_setPinValue(KEYPAD_PORT, Col_0, high_value);
    	            GPIO_setPinValue(KEYPAD_PORT, Col_1, high_value);
    	            GPIO_setPinValue(KEYPAD_PORT, Col_2, high_value);
    	            GPIO_setPinValue(KEYPAD_PORT, Col_3, high_value);
    }

    return local_err;
}

Error_state return_char_keypad(u8 *r_char)
{
    Error_state local_err;
    if (Valid_pin == keypad_init())
    {
        local_err = Working;
        *r_char = NOT_PRESSED;
        u8 loop_iterator_coulmn = 0;
        u8 loop_iterator_row = 0;
        for (loop_iterator_coulmn = 0 + COL_INIT; loop_iterator_coulmn < COL_END; loop_iterator_coulmn++)
        {
            GPIO_setPinValue(KEYPAD_PORT, loop_iterator_coulmn, low_value);
            for (loop_iterator_row = 0 + ROW_INIT; loop_iterator_row < ROW_END; loop_iterator_row++)
            {
                GPIO_getPIN(KEYPAD_PORT, loop_iterator_row, r_char); // the pointer points to ?
                if (*r_char == low_value)
                {
                    _delay_ms(50); // delay for bouncing
                    r_char = &keybad_values[loop_iterator_row - ROW_INIT][loop_iterator_coulmn - COL_INIT];
                }
                GPIO_getPIN(KEYPAD_PORT, loop_iterator_row, r_char);
                while (low_value == *r_char)
                {
                    GPIO_getPIN(KEYPAD_PORT, loop_iterator_row, r_char);
                }
                break;
            }
            GPIO_setPinValue(KEYPAD_PORT, loop_iterator_coulmn, high_value);
        }
    }
    else
    {
        local_err = keypad_init();
        r_char = NULL;
    }
    return local_err;
}
