/*
 * SPI.h
 *
 *  Created on: Sep 24, 2021
 *      Author: shady
 */

#ifndef MCAL_SPI_SPI_SLAVE_H_
#define MCAL_SPI_SPI_SLAVE_H_

#include <avr/io.h>
#include "../../BIT_MATH.h"
#include "../../STD_TYPES.h"
#include "SPI_Slave_Config.h"

//void SPI_MasterInit(void);
//void SPI_MasterTransmit(char cData);
//void SPI_SlaveInit(void);
//char SPI_SlaveReceive(void);
void SPI_SLAVE_INIT();
uint8 SPI_SLV_RECEV(void);

#endif /* MCAL_SPI_SPI_SLAVE_H_ */
