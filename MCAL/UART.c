#include "UART.h"


void Uart_Init(void)
{
	// baud rate 9600
	UBRRL=51;
	// enable transmitter and receiver
	SET_BIT(UCSRB,TXEN);
	SET_BIT(UCSRB,RXEN);
	// to enbale , asyn , dis parity , 1 stop bit , 8 bit charcater size 
	UCSRC = 134;
}
void Uart_Send_Char(u8 data)
{
	while(!READ_BIT(UCSRA,UDRE));
	UDR=data;
}
u8 Uart_Receive_Char(void)
{
	while(!READ_BIT(UCSRA,RXC));
	return UDR;
	
}

void Uart_SendString(u8 *str)
{
	u8 i = 0;
	for (i=0;str[i];i++)
	{
		Uart_Send_Char(str[i]);
	}
	Uart_Send_Char('#');
}
void Uart_ReceiveString(u8 *str)
{
	u8 i =0;
	str[i]=Uart_Receive_Char();
	while(str!=0x0d)
	{
		i++;
		str[i]=Uart_Receive_Char();
	}
	str[i]=0;
}
