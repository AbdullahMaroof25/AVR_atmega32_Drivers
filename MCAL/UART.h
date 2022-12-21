

#ifndef UART_H_
#define UART_H_

#include "BitMath.h"
#include "StdTypes.h"
#include "MemMap.h"


void Uart_Init(void);
void Uart_Send_Char(u8 data);
u8 Uart_Receive_Char(void);
void Uart_SendString(u8 *str);
void Uart_ReceiveString(u8 *str);



#endif /* UART_H_ */