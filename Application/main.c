#include "master/master.h"
#include "slave/slave.h"


//slave app 
/*int main(void)
{
	u8 recieved_data;
	Slave_init_func();
	while (1)
	{
		recieved_data = Slave_recieve();
		GPIO_setPortValue(PORTA,recieved_data);
	}
}*/
// master app

int main()
{
	master_init_fun();
	for (u8 i = 0; i >=0 ; i++)
	{
		master_transmitt(i);
		_delay_ms(1000);
	}
}

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
