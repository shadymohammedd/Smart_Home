/*
 * UART.h
 *
 *  Created on: Sep 24, 2021
 *      Author: shady
 */

#ifndef MCAL_UART_UART_H_
#define MCAL_UART_UART_H_

#include <avr/io.h>
#include <util/delay.h>
#include "../../BIT_MATH.h"
#include "../../STD_TYPES.h"
void USART_Init( unsigned int baud );
unsigned char USART_Receive( void );
void USART_Transmit( unsigned char data );


#endif /* MCAL_UART_UART_H_ */
