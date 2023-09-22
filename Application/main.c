#include "slave/slave.h"
#include "master/master.h"
#include "../MCAL/GPIO/GPIO.h"
#include "../MCAL/ADC/ADC.h"

//slave app 
int main(void)
{
	u8 recieved_data;
	slave_init(SLAVE_ADD);
	GPIO_setPortDirection(PORTA,Out_Port_direction);
	while (1)
	{
		recieved_data = slave_recieve();
		GPIO_setPortValue(PORTA,recieved_data);
	}
}
// master app

/*int main()
{
	master_init();
	while (1)
	{
		master_send_slave(SLAVE_ADD);
	}
	
}*/

/*int main()
{
	INIT_ADC(&ADC1);
	GPIO_setPortDirection(PORTB,0xff);
	u16 x;
	while (1)
	{
		x = ADC_Read_test();
		GPIO_setPortValue(PORTB,x);
	}
	
}*/
