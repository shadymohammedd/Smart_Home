/*
 * SPI_INIT.c
 *
 *  Created on: Sep 24, 2021
 *      Author: shady
 */


#include "SPI.h"

void SPI_MasterInit(void)
{

/* Set MOSI and SCK output, all others input */
DDRB = (1<<PORTB5)|(1<<PORTB7);
/* Enable SPI, Master, set clock rate fck/16 */
SPCR = (1<<SPE)|(1<<MSTR)|(1<<SPR0);
}


void SPI_MasterTransmit(char cData)
{
/* Start transmission */
SPDR = cData;
/* Wait for transmission complete */
while(!(SPSR & (1<<SPIF)));
}


void SPI_SlaveInit(void)
{
/* Set MISO output, all others input */
DDRB = (1<<PORTB6);
/* Enable SPI */
SPCR = (1<<SPE);
}

uint8 SPI_SlaveReceive(void)
{

/* Wait for reception complete */
while(!(SPSR & (1<<SPIF)))
;
/* Return data register */
return SPDR;
}
