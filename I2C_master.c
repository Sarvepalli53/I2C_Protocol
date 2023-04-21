/*
 * i2c_master.c
 *
 * Created: 4/3/2023 7:45:32 PM
 * Author : ADMIN
 */ 

#include <avr/io.h>
//#include F_PU 16000000L
#include <util/delay.h>

void i2c_write (unsigned char data)
{
	TWDR = data;
	TWCR = (1<<TWINT)|(1<<TWEN);
	while((TWCR&(1<<TWINT)) == 0);
}

void i2c_start(void)
{
	TWCR = (1<<TWINT)|(1<<TWSTA)|(1<<TWEN);
	while((TWCR&(1<<TWINT))==0);
}
void i2cstop()
{
	TWCR =(1<<TWINT)|(1<<TWEN)|(1<<TWSTO);
	//no need to add check TWINT bit for STOP condition
	
}
void i2c_init(void)
{
	TWSR = 0x00;
	TWBR = 0x47;
	TWCR = (1<<TWEN);
	
}

int main(void)
{
	i2c_init();
	i2c_start();
	i2c_write(0b11010000);
	i2c_write(0b11110000);
	i2cstop();
	while(1);
	return 0;
	
	
	
}



