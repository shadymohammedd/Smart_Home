/*
 * SPI.h
 *
 *  Created on: Sep 24, 2021
 *      Author: shady
 */

#ifndef MCAL_SPI_SPI_H_
#define MCAL_SPI_SPI_H_

#include <avr/io.h>
#include <util/delay.h>
#include "../../BIT_MATH.h"
#include "../../STD_TYPES.h"

void SPI_MasterInit(void);
void SPI_MasterTransmit(char cData);
void SPI_SlaveInit(void);
uint8 SPI_SlaveReceive(void);


#endif /* MCAL_SPI_SPI_H_ */
