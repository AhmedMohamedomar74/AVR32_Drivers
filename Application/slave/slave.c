#include "slave.h"

void slave_init(u8 slave_add)
{
    SLAVE_INIT(slave_add);
}

u8 slave_recieve()
{
    u8 ret_val;
    ret_val = I2C_Slave_Receive();
    return ret_val;
}    
