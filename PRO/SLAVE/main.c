/*
 * main.c
 *
 *  Created on: Sep 5, 2021
 *      Author: Shady
 */
#include "MCAL/DIO/DIO.h"
#include "MCAL/SPI/SPI.h"

int main() {
	SPI_SlaveInit();
	SET_BIT(DDRA, 0);
	SET_BIT(DDRA, 1);
	uint8 data;
	while (1) {
		data = SPI_SlaveReceive();
		if (data == '0') {
			SET_BIT(PORTA,0);
//			TOGGLE_BIT(PORTA, 0);
		} else if (data == '1') {
			SET_BIT(PORTA,1);
//			TOGGLE_BIT(PORTA, 1);
		} else {

			CLEAR_BIT(PORTA, 0);
			CLEAR_BIT(PORTA, 1);

		}
	}

}
