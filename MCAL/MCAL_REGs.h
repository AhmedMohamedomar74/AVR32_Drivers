/*
 * MCAL_REGs.h
 *
 *  Created on: Aug 21, 2023
 *      Author: ahmedomar
 */

#ifndef MCAL_REGS_H_
#define MCAL_REGS_H_
#include "../LIB/STD.h" 


#define MAX_PIN 7

/***************************
 * base address
 **************************/
// Group A
#define PORTA_BASE 0X3B
#define DDRA_BASE 0x3A
#define PINA_BASE 0X39
// Group B
#define PORTB_BASE 0X38
#define DDRB_BASE 0x37
#define PINB_BASE 0X36
// Group C
#define PORTC_BASE 0X35
#define DDRC_BASE 0x34
#define PINC_BASE 0X33
// Group D
#define PORTD_BASE 0X32
#define DDRD_BASE 0x31
#define PIND_BASE 0X30

// POINTER FOR GROUPS
#define PORTA_Ptr *((volatile u8 *)PORTA_BASE) //(volatile u8*) it used for casting
#define DDRA_Ptr *((volatile u8 *)DDRA_BASE)   // volatile it used to avoid optmization
#define PINA_Ptr *((volatile u8 *)PINA_BASE)
#define PORTB_Ptr *((volatile u8 *)PORTB_BASE)
#define DDRB_Ptr *((volatile u8 *)DDRB_BASE)  
#define PINB_Ptr *((volatile u8 *)PINB_BASE)
#define PORTC_Ptr *((volatile u8 *)PORTC_BASE)
#define DDRC_Ptr *((volatile u8 *)DDRC_BASE)  
#define PINC_Ptr *((volatile u8 *)PINC_BASE)
#define PORTD_Ptr *((volatile u8 *)PORTD_BASE)
#define DDRD_Ptr *((volatile u8 *)DDRD_BASE)  
#define PIND_Ptr *((volatile u8 *)PIND_BASE)
#endif /* MCAL_REGS_H_ */
