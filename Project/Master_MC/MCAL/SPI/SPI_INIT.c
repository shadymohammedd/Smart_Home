/*
 * SPI_INIT.c
 *
 *  Created on: Sep 24, 2021
 *      Author: shady
 */
//
//#include "SPI.h"
//
//void SPI_MasterInit(void) {
//
//	/* Set MOSI and SCK output, all others input */
//	DDRB = (1 << PORTB5) | (1 << PORTB7);
//	/* Enable SPI, Master, set clock rate fck/16 */
//	SPCR = (1 << SPE) | (1 << MSTR) | (3 << SPR0);
//}
//
//void SPI_MasterTransmit(char cData) {
//	/* Start transmission */
//	SPDR = cData;
//	/* Wait for transmission complete */
//	while (!(SPSR & (1 << SPIF)))
//		;
//}
//
//void SPI_SlaveInit(void) {
//	/* Set MISO output, all others input */
//	DDRB = (1 << PORTB6);
//	/* Enable SPI */
//	SPCR = (1 << SPE);
//}
//
//char SPI_SlaveReceive(void) {
//
//	/* Wait for reception complete */
//	while (!(SPSR & (1 << SPIF)))
//		;
//	/* Return data register */
//	return SPDR;
//}
//
#include "SPI_Master.h"

void SPI_MASTER_INIT() {

	/* Set MOSI and SCK output, all others input */
	SET_BIT(DDRB, 5);
	SET_BIT(DDRB, 7);
	// Enable SPI.
#if SPI_STATUS == ENABLE
	SET_BIT(SPCR, SPE);
#elif SPI_STATUS == DISABLE
	CLEAR_BIT(SPCR, SPE);
#endif

	// Enabling Slave/Master.
#if SPI_MSTR_SLVE_SET == MASTER
	SET_BIT(SPCR, MSTR);
#elif SPI_MSTR_SLVE_SET == SLAVE
	CLEAR_BIT(SPCR, MSTR);
#endif

	// Setting Speed mode and Frequency
	switch (SPI_CLOCK_SPEED) {

	case NORMAL_SPEED_BIT:
#if SPI_CLOCK_FREQ == FOSC_4
		CLEAR_BIT(SPCR, SPR0);
		CLEAR_BIT(SPCR, SPR1);
		CLEAR_BIT(SPSR, SPI2X);
#elif SPI_CLOCK_FREQ == FOSC_16
		SET_BIT(SPCR, SPR0);
		CLEAR_BIT(SPCR, SPR1);
		CLEAR_BIT(SPSR, SPI2X);
#elif SPI_CLOCK_FREQ == FOSC_64
		CLEAR_BIT(SPCR, SPR0);
		SET_BIT(SPCR, SPR1);
		CLEAR_BIT(SPSR, SPI2X);
#elif SPI_CLOCK_FREQ == FOSC_128
		SET_BIT(SPCR, SPR0);
		SET_BIT(SPCR, SPR1);
		CLEAR_BIT(SPSR, SPI2X);
#endif
		break;
	case DOUBLE_SPEED_BIT:
#if SPI_CLOCK_FREQ == FOSC_2
		CLEAR_BIT(SPCR, SPR0);
		CLEAR_BIT(SPCR, SPR1);
		SET_BIT(SPSR, SPI2X);
#elif SPI_CLOCK_FREQ == FOSC_8
		SET_BIT(SPCR, SPR0);
		CLEAR_BIT(SPCR, SPR1);
		SET_BIT(SPSR, SPI2X);
#elif SPI_CLOCK_FREQ == FOSC_32
		CLEAR_BIT(SPCR, SPR0);
		SET_BIT(SPCR, SPR1);
		SET_BIT(SPSR, SPI2X);
#elif SPI_CLOCK_FREQ == FOSC_64
		SET_BIT(SPCR, SPR0);
		SET_BIT(SPCR, SPR1);
		SET_BIT(SPSR, SPI2X);
#endif
		break;
	default:
		break;
	}

	// Plarity Setting.
#if SPI_MODE == LeSampRise_TrSetFall
	CLEAR_BIT(SPCR, CPHA);
	CLEAR_BIT(SPCR, CPOL);
#elif SPI_MODE == LeSetRise_TrSampFall
	SET_BIT(SPCR, CPHA);
	CLEAR_BIT(SPCR, CPOL);
#elif SPI_MODE == LeSampFall_TrSetRise
	CLEAR_BIT(SPCR, CPHA);
	SET_BIT(SPCR, CPOL);
#elif SPI_MODE == LeSetFall_TrSampRise
	SET_BIT(SPCR, CPHA);
	SET_BIT(SPCR, CPOL);
#endif
}

void SPI_MSTR_TRNSMT(uint8 data) {
	SPDR = data;

	while (!(SPSR & (1 << SPIF)))
		;
}

