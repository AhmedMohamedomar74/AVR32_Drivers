/*
 * SEVEN_SEG.c
 *
 *  Created on: Aug 25, 2023
 *      Author: ahmedomar
 */
#include "SEVEN_SEG.h"

Error_state Seven_Segment(u8 numebr, u8 seven_seg_id)
{
    Error_state local_err = Unvalid_Port;
    SEVEN_SEG_t *local_ptr_1 = NULL;
    for (u8 LoopIteratorOne = 0; LoopIteratorOne < legnth; LoopIteratorOne++)
    {
        if (LoopIteratorOne == seven_seg_id)
        {
        	local_err = SS_valid;
            break;
        }
        else
        {
        	local_err = SS_not_valid;
        }
    }
    local_ptr_1 = &seven_segments_arr[seven_seg_id];
    if (local_ptr_1 == NULL)
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
            if ((PORTA != local_ptr_1->PORT) && (PORTB != local_ptr_1->PORT) && (PORTC != local_ptr_1->PORT) && (PORTD != local_ptr_1->PORT))
            {
                local_err = Unvalid_Port;
            }
            else
            {
                for (u8 LoopIteratorOne = 0; LoopIteratorOne < legnth; LoopIteratorOne++)
                {
                    if (LoopIteratorOne == local_ptr_1->SEVEN_SEG_ID)
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
                    if (comman_anode == local_ptr_1->SEVEN_SEG_type)
                    {
                        GPIO_setPortDirection(local_ptr_1->PORT, 0xff);
                        GPIO_setPortValue(local_ptr_1->PORT, CA_SevenSegmentValues[numebr]);
                    }
                    else if (comman_cathode == local_ptr_1->SEVEN_SEG_type)
                    {
                        GPIO_setPortDirection(local_ptr_1->PORT, 0xff);
                        GPIO_setPortValue(local_ptr_1->PORT, CC_SevenSegmentValues[numebr]);
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
