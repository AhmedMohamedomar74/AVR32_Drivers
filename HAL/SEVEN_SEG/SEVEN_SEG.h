/*
 * SEVEN_SEG.h
 *
 *  Created on: Aug 25, 2023
 *      Author: ahmedomar
 */

#ifndef SEVEN_SEG_H_
#define SEVEN_SEG_H_

#include "SEVEN_SEG_Config.h"
// Array of values for Common Anode seven-segment display
const u8 CA_SevenSegmentValues[] = {
    0xC0, // 0
    0xF9, // 1
    0xA4, // 2
    0xB0, // 3
    0x99, // 4
    0x92, // 5
    0x82, // 6
    0xF8, // 7
    0x80, // 8
    0x90, // 9
};

// Array of values for Common Cathode seven-segment display
const u8 CC_SevenSegmentValues[] = {
    0x3F, // 0
    0x06, // 1
    0x5B, // 2
    0x4F, // 3
    0x66, // 4
    0x6D, // 5
    0x7D, // 6
    0x07, // 7
    0x7F, // 8
    0x6F  // 9
};

Error_state Seven_Segment(u8 numebr, u8 seven_seg_id);
#endif /* SEVEN_SEG_H_ */
