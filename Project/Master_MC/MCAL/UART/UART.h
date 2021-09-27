/*
 * UART.h
 *
 *  Created on: Sep 24, 2021
 *      Author: shady
 */

#ifndef MCAL_UART_UART_H_
#define MCAL_UART_UART_H_

#include <avr/io.h>
#include "../../BIT_MATH.h"
#include "../../STD_TYPES.h"
//void USART_Init( unsigned int baud );
//unsigned char USART_Receive( void );
//void USART_Transmit( unsigned char data );
void USART_Init(uint32 baud);
void USART_Transmit_5_8(uint8 data);
uint8 USART_Receive(void);

#endif /* MCAL_UART_UART_H_ */
