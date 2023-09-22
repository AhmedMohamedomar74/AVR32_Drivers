#include "master.h"

void master_init()
{
    MASTER_INIT(MASTER_ADD);
}

void master_send_slave(u8 slave_add)
{
    START_CONDTION_SEND();
    M_SEND_SLAVE_ADD_W(slave_add);
    M_SEND_SLAVE_DATA_W(5);
    STOP_CONDTION_SEND();
}
