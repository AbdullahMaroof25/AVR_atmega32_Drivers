


#ifndef SPI_H_
#define SPI_H_

#include "BitMath.h"
#include "StdTypes.h"
#include "MemMap.h"

void SPI_Init_Master(void);
void SPI_Init_Slave(void);
void SPI_Transmit_NoBlock(u8 data);
u8 SPI_Recive_NoBlock(void);
void SPI_Transmit(u8 data);
u8 SPI_Recive(void);




#endif /* SPI_H_ */