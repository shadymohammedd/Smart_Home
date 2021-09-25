/*
 * main.c
 *
 *  Created on: Sep 5, 2021
 *      Author: Shady
 */

#include "MCAL/DIO/DIO.h"
#include "MCAL/SPI/SPI.h"
#include "MCAL/UART/UART.h"

int main() {
	//DIO_INIT();
	USART_Init(103);
	SPI_MasterInit();

	while (1) {
		uint8 x = USART_Receive();
//		USART_Transmit(x);
		SPI_MasterTransmit(x);
	}

}
