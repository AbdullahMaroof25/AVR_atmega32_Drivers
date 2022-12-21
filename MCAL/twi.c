

  
/*
 * I2C.c
 *
 *  Created on: Jan 15, 2018
 *      Author: Mohamed
 */
#include "twi.h"

// for master
void I2C_Init()
{
	/*TWBR = 0x02;
	TWCR = (1<<TWEN);
	TWSR = 0x00;
	TWAR = 0b00000010;*/
	TWBR=32;
	TWCR=(1<<TWEN);
	TWSR=0;
}

// for slave
void TWI_Init_S(u8 slave_address ,GENERAL_CALL_t mode)
{
	TWCR |= (1 << 2); //enable module
	TWSR = 0x00 ; //set prescaller bits to zero
	TWAR = (slave_address << 1); // the address
	TWCR = ((1<<TWINT) | (1 << TWEN) | (1 <<TWEA) | (1 <<TWIE));
	
	TWBR = 32;
	if (mode == enable_general_call)
	{
		TWAR |= (1<< 0);
	}
	else if(mode == disable_general_call)
	{
		TWAR &= ~(1<< 0);
	}
}


void I2C_Start()
{
	TWCR = (1<<TWINT)|(1<<TWSTA)|(1<<TWEN);
	while(Bit_Is_Clear(TWCR,TWINT));
}

void I2C_Stop()
{
	TWCR = (1<<TWINT)|(1<<TWSTO)|(1<<TWEN);
}

void I2C_Write(uint8 data)
{
	TWDR = data;
	TWCR = (1<<TWINT)|(1<<TWEN);
	while(Bit_Is_Clear(TWCR,TWINT));
}

uint8 I2C_Read_ACK()
{
	TWCR = (1<<TWINT)|(1<<TWEN)|(1<<TWEA);
	while(Bit_Is_Clear(TWCR,TWINT));
	return TWDR;
}

uint8 I2C_Read_NO_ACK()
{
	TWCR = (1<<TWINT)|(1<<TWEN);
	while(Bit_Is_Clear(TWCR,TWINT));
	return TWDR;
}

uint8 I2C_Status()
{
	uint8 status;
	status = (TWSR & 0xF8);
	return status;
}