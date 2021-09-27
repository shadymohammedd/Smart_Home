/*
 * SPI.h
 *
 *  Created on: Sep 24, 2021
 *      Author: shady
 */

#ifndef MCAL_SPI_SPI_MASTER_H_
#define MCAL_SPI_SPI_MASTER_H_

#include <avr/io.h>
#include "../../BIT_MATH.h"
#include "../../STD_TYPES.h"
#include "SPI_Master_Config.h"

//void SPI_MasterInit(void);
//void SPI_MasterTransmit(char cData);
//void SPI_SlaveInit(void);
//char SPI_SlaveReceive(void);
void SPI_MASTER_INIT();
void SPI_MSTR_TRNSMT(uint8 data);

#endif /* MCAL_SPI_SPI_MASTER_H_ */
