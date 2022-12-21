/*
 * I2C.h
 *
 *  Created on: Jan 15, 2018
 *      Author: Mohamed
 */

#ifndef twi_H_
#define twi_H


typedef unsigned char uint8;
typedef signed char sint8;
typedef unsigned short uint16;
typedef signed short sint16;
typedef unsigned long uint32;
typedef signed long sint32;
#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#define Set_Bit(REG,BIT) (REG |= (1<<BIT))
#define Clear_Bit(REG,BIT) (REG &= (~(1<<BIT)))
#define Toggle_Bit(REG,BIT) (REG ^= (1<<BIT))
#define ROR(REG,NUM) (REG = ((REG >> NUM) | (REG << (8-NUM))))
#define ROL(REG,NUM) (REG = ((REG << NUM) | (REG >> (8-NUM))))
#define Bit_Is_Set(REG,BIT) (REG & (1<<BIT))
#define Bit_Is_Clear(REG,BIT) (!(REG & (1<<BIT)))

#define I2C_START         0x08
#define I2C_REP_START     0x10
#define I2C_MT_SLA_W_ACK  0x18
#define I2C_MT_SLA_R_ACK  0x40
#define I2C_MT_DATA_ACK   0x28
#define I2C_MR_DATA_ACK   0x50
#define I2C_MR_DATA_NACK  0x58


void I2C_Init();
void I2C_Start();
void I2C_Stop();
void I2C_Write(uint8 data);
uint8 I2C_Read_ACK();
uint8 I2C_Read_NO_ACK();
uint8 I2C_Status();


#endif /* twi_H_ */