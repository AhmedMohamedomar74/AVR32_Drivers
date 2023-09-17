#include "master.h"

void master_init()
{
    INIT_master();
}

void master_send_slave(u8 slave_add)
{
    send_start_condition();
    M_Write_slave_add(slave_add);
    M_Write_slave_Data_byte(2);
    I2C_stop_condition();
}
