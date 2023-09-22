#include "../../MCAL/I2C/I2C.h"
#define SLAVE_ADD 0X7A
#define MASTER_ADD 0X7B
void master_init();
void master_send_slave (u8 slave_add);