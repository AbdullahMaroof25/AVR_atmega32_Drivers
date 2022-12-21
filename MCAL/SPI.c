
#include "SPI.h"

void SPI_Init_Master(void)
{
	//the MSB of the data word is transmitted first
	CLEAR_BIT(SPCR,DORD);
	// Master select
	SET_BIT(SPCR,MSTR);
	// rising leading edge 
	CLEAR_BIT(SPCR,CPOL);
	// sample leading edge
	CLEAR_BIT(SPCR,CPHA);
	// divide the freq by 4
	CLEAR_BIT(SPCR,SPR0);
	CLEAR_BIT(SPCR,SPR1);
	CLEAR_BIT(SPSR,SPI2X);
	// enable spi
	SET_BIT(SPCR,SPE);
	
}
void SPI_Init_Slave(void)
{
	//the MSB of the data word is transmitted first
	CLEAR_BIT(SPCR,DORD);
	// slave select
	CLEAR_BIT(SPCR,MSTR);
	// rising leading edge
	CLEAR_BIT(SPCR,CPOL);
	// sample leading edge
	CLEAR_BIT(SPCR,CPHA);
	// divide the freq by 4
	CLEAR_BIT(SPCR,SPR0);
	CLEAR_BIT(SPCR,SPR1);
	CLEAR_BIT(SPSR,SPI2X);
	// enable spi
	SET_BIT(SPCR,SPE);
	
}

void SPI_Transmit_NoBlock(u8 data)
{
	 SPDR = data;
}
u8 SPI_Recive_NoBlock(void)
{
	return SPDR;
}
void SPI_Transmit(u8 data)
{
	while(!READ_BIT(SPSR,SPIF));
	SPDR = data;
}
u8 SPI_Recive(void)
{
	while(!READ_BIT(SPSR,SPIF));
	return SPDR;
	
}