#include "slave.h"

void slave_init(u8 slave_add)
{
    INIT_slave(slave_add);
}

u8 slave_recieve()
{
    u8 ret_val;
    I2C_Slave_Receive(& ret_val);
    return ret_val;
}    
