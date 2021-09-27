/*
 * main.c
 *
 *  Created on: Sep 5, 2021
 *      Author: Shady
 */

#include "MCAL/SPI/SPI_Master.h"
#include "MCAL/UART/UART.h"

int main() {

	USART_Init(103);
	SPI_MASTER_INIT();
char x=0;
	while (1) {
		x=USART_Receive();
		if (x=='0'){
		SPI_MSTR_TRNSMT(0x00);
		} else if (x=='3')
		{
			SPI_MSTR_TRNSMT(0x03);
		}
	}

}
