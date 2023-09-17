#include "I2C.h"

void INIT_master(void)
{
    /*set prescaller 0*/
    TWSR &= ~(1 << TWPS1); // clear bit
    TWSR &= ~(1 << TWPS0); // clear bit
    TWBR = 2;
    TWCR |= (1 << TWEA); /*SET ACK*/
    TWCR |= (1 << TWEN); /*ENABLE TWI*/
}

void INIT_slave(u8 master_address)
{
    TWAR = (master_address << 1); /*the address is 7 bit and it starts from second bit in register*/
    TWCR |= (1 << TWEA);          /*SET ACK*/
    TWCR |= (1 << TWEN);          /*ENABLE I2C*/
}

I2C_Error_State send_start_condition(void)
{
    I2C_Error_State local_err = I2C_Ok;
    /* Send Start Condition */
    TWCR |= (1 << TWSTA);
    /* Clear Flag */
    TWCR |= (1 << TWINT);
    /* Polling on The Flag */
    while (((TWCR >> TWINT) & 1) == 0)
        ;
    /* Check on ACK */
    if ((TWSR & 0xF8) != M_SC_ACK)
    {
        local_err = I2C_SC_Error;
    }
    return local_err;
}

I2C_Error_State send_repeated_start_condition(void)
{
    I2C_Error_State local_err = I2C_Ok;
    /* Send Start Condition */
    TWCR |= (1 << TWSTA);
    /* Clear Flag */
    TWCR |= (1 << TWINT);
    /* Polling on The Flag */
    while (((TWCR >> TWINT) & 1) == 0)
        ;
    /* Check on ACK */
    if ((TWSR & 0xF8) != M_RSC_ACK)
    {
        local_err = I2C_RSC_Error;
    }
    return local_err;
}

I2C_Error_State M_Write_slave_add(u8 slave_add)
{
    I2C_Error_State local_err = I2C_Ok;
    TWDR = (slave_add << 1);
    TWDR &= ~(1 << TWD0); // Write operation
    /*clear start condiotn */
    TWCR &= ~(1 << TWSTA);
    /* Clear Flag */
    TWCR |= (1 << TWINT);
    /* Polling on The Flag */
    while (((TWCR >> TWINT) & 1) == 0)
        ;
    /* Check on ACK */
    if ((TWSR & 0xF8) != MT_SLA_W_ACK)
    {
        local_err = I2C_MT_SLA_W_Error;
    }
    return local_err;
}

I2C_Error_State M_Read_slave_add(u8 slave_add)
{
    I2C_Error_State local_err = I2C_Ok;
    TWDR = (slave_add << 1);
    TWDR &= ~(1 << TWD0); // Write operation
    /*clear start condiotn */
    TWCR &= ~(1 << TWSTA);
    /* Clear Flag */
    TWCR |= (1 << TWINT);
    /* Polling on The Flag */
    while (((TWCR >> TWINT) & 1) == 0)
        ;
    /* Check on ACK */
    if ((TWSR & 0xF8) != M_SLA_R_ACK)
    {
        local_err = I2C_MR_SLA_R_Error;
    }
    return local_err;
}

I2C_Error_State M_Write_slave_Data_byte(u8 byte_Data)
{
    I2C_Error_State local_err = I2C_Ok;
    TWDR = byte_Data;
    /* Clear Flag */
    TWCR |= (1 << TWINT);
    /* Polling on The Flag */
    while (((TWCR >> TWINT) & 1) == 0)
        ;
    /* Check on ACK */
    if ((TWSR & 0xF8) != I2C_MT_DATA_ACK)
    {
        local_err = I2C_MT_Data_Error;
    }
    return local_err;
}

I2C_Error_State M_Read_slave_Data_byte(u8 *byte_Data)
{
    I2C_Error_State local_err = I2C_Ok;
    /* Clear Flag */
    TWCR |= (1 << TWINT);
    /* Polling on The Flag */
    while (((TWCR >> TWINT) & 1) == 0)
        ;
    /* Check on ACK */
    if ((TWSR & 0xF8) != I2C_MT_DATA_ACK)
    {
        local_err = I2C_MT_Data_Error;
    }
    else
    {
        *byte_Data = TWDR;
    }

    return local_err;
}

void I2C_stop_condition(void)
{
    TWCR |= (1 << TWSTO);
    TWCR |= (1 << TWINT);
}

I2C_Error_State I2C_Slave_Receive(u8 *byte_Dat)
{
    I2C_Error_State local_err = I2C_Ok;
    TWCR |= (1 << TWEA); /*SET ACK*/
    TWCR |= (1 << TWEN); /*ENABLE TWI*/
    /* Clear Flag */
    TWCR |= (1 << TWINT);
    while (((TWCR >> TWINT) & 1) == 0)
        ;
    /* Check on ACK */
    if (((TWSR & 0xF8) == 0x88) || ((TWSR & 0xF8) == 0x98))
    {
        *byte_Dat = TWDR;
    }
    if ((TWSR & 0xF8) == 0xA0) /* Check wether STOP/REPEATED START */
    {
        TWCR |= (1 << TWINT); /* Clear interrupt flag & return -1 */
        *byte_Dat = -1;
    }
    else
        *byte_Dat = -2;
    return local_err;
}
