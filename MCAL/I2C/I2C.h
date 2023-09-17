/*
 * I2C.h
 *
 *  Created on: Sep 17, 2023
 *      Author: ahmedomar
 */

#ifndef _I2C_H
#define _I2C_H
#include "../MCAL_REGs.h"

/*TWSR*/
/**
 * Prescaller control
*/
typedef enum
{
    TWPS0 = 0,
    TWPS1,
}TWSR_pin_t;

/*TWCR*/
/**
 * Controll regiseter 
*/
typedef enum
{
    TWIE = 0, /*TWI Interrupt Enable*/
    TWEN = 2, /*TWI Enable Bit*/
    TWWC, /*TWI Write Collision Flag*/
    TWSTO, /*TWI STOP Condition Bit*/
    TWSTA, /*TWI START Condition Bit*/
    TWEA, /*TWI Enable Acknowledge Bit*/
    TWINT, /*TWI Interrupt Flag*/

}TWCR_pin_t;

typedef enum
{
    TWD0 = 0,
}TWDR_pin_t;


typedef enum
{
    M_SC_ACK    = 0x08,
    M_RSC_ACK = 0x10,
    MT_SLA_W_ACK = 0x18,// master transmitt slave addrress acknoladge
    I2C_MT_DATA_ACK = 0x28, //master transmitt date to slave
    M_SLA_R_ACK = 0x40, //master read address acknoladge 
    MR_DATA_ACK = 0x50, //master read data ackmoladge 
    SR_DATA_ACK = 0x88,
}mode_t;

typedef enum 
{
    I2C_Ok,
    I2C_SC_Error, //error for start condiotion
    I2C_RSC_Error,//error for Re-start condiotion
    I2C_MT_SLA_W_Error, // error master transmitt slave addrress acknoladge
    I2C_MR_SLA_R_Error, // error master recieve slave addrress acknoladge
    I2C_MT_Data_Error,// error master transmitt slave data acknoladge
    I2C_MR_Data_Error,// error master recieve slave data acknoladge
    I2C_SR_Data_Error,//error slave recieve slave data acknoladge
}I2C_Error_State;

void INIT_master (void);
void INIT_slave (u8 master_address);
I2C_Error_State send_start_condition (void);
I2C_Error_State send_repeated_start_condition (void);
I2C_Error_State M_Write_slave_add (u8 slave_add);
I2C_Error_State M_Read_slave_add (u8 slave_add);
I2C_Error_State M_Write_slave_Data_byte (u8 byte_Data);
I2C_Error_State M_Read_slave_Data_byte (u8 *byte_Data);
void I2C_stop_condition (void);
I2C_Error_State I2C_Slave_Receive();
#endif