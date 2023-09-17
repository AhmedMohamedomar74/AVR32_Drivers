#include "../../MCAL/I2C/I2C.h"
#define SLAVE_ADD 0XA4
void master_init();
void master_send_slave (u8 slave_add);