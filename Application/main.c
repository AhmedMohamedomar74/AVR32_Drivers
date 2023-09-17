#include "slave/slave.h"
#include "master/master.h"
#include "../MCAL/GPIO/GPIO.h"

//slave app 
/*int main(void)
{
	u8 recieved_data;
	slave_init(SLAVE_ADD);
	GPIO_setPortDirection(PORTA,Out_Port_direction);
	while (1)
	{
		recieved_data = slave_recieve();
		GPIO_setPortValue(PORTA,recieved_data);
	}
}*/
// master app

int main()
{
	master_init();
	while (1)
	{
		master_send_slave(SLAVE_ADD);
	}
	
}
