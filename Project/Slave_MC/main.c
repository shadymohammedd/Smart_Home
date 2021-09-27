/*
 * main.c
 *
 *  Created on: Sep 5, 2021
 *      Author: Shady
 */
#include "BIT_MATH.h"
#include "STD_TYPES.h"
#include "MCAL/SPI/SPI_Slave.h"
int main() {
	SET_BIT(DDRC, 2);
	SET_BIT(DDRC, 7);
	SET_BIT(DDRC, 6);
	SPI_SLAVE_INIT();

	while (1) {


		switch ( SPI_SLV_RECEV()) {

		case 0X00:
			TOG_BIT(PORTC, 2);
//			TOG_BIT(PORTC, 6);
//			TOG_BIT(PORTC, 7);
			break;
		case 0x03:
		TOG_BIT(PORTC, 6);
			break;
		default:
		//	TOG_BIT(PORTC, 7);
			break;

		}

	}

}
