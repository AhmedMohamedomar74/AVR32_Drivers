/*
 * SEVEN_SEG.c
 *
 *  Created on: Aug 25, 2023
 *      Author: ahmedomar
 */
#include "SEVEN_SEG.h"

Error_state Seven_Segment(u8 numebr)
{
    Error_state local_err = Unvalid_Port;
    SEVEN_SEG_t *local_ptr = &seven_segments_arr[1];
    if (local_ptr == NULL)
    {
        local_err = NULL_POINTER;
    }
    else
    {
        if (numebr > 0x09)
        {
            local_err = Can_not_assign_to_SS;
        }
        else
        {
            if ((PORTA != local_ptr->PORT) && (PORTB != local_ptr->PORT) && (PORTC != local_ptr->PORT) && (PORTD != local_ptr->PORT))
            {
                local_err = Unvalid_Port;
            }
            else
            {
                for (u8 LoopIteratorOne = 0; LoopIteratorOne < legnth; LoopIteratorOne++)
                {
                    if (LoopIteratorOne == local_ptr->SEVEN_SEG_ID)
                    {
                        local_err = SS_valid;
                        break;
                    }
                    else
                    {
                        local_err = SS_not_valid;
                    }
                }
                if (SS_valid == local_err)
                {
                    if (comman_anode == local_ptr->SEVEN_SEG_type)
                    {
                        GPIO_setPortDirection(local_ptr->PORT, 0xff);
                        GPIO_setPortValue(local_ptr->PORT, CA_SevenSegmentValues[numebr]);
                    }
                    else if (comman_cathode == local_ptr->SEVEN_SEG_type)
                    {
                        GPIO_setPortDirection(local_ptr->PORT, 0xff);
                        GPIO_setPortValue(local_ptr->PORT, CC_SevenSegmentValues[numebr]);
                    }
                }
                else
                {
                }
            }
        }
    }

    return local_err;
}
