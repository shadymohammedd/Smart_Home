/*
 * DIO.h
 *
 *  Created on: Sep 5, 2021
 *      Author: Shady
 */

#ifndef MCAL_DIO_DIO_H_
#define MCAL_DIO_DIO_H_

#include <avr/io.h>
#include "DIO_CONFIG.h"
#include "../../BIT_MATH.h"
#include "../../STD_TYPES.h"

void DIO_INIT(void);
DIO_LEVEL DIO_READ(DIO_Channel_Type channel);
void DIO_WRITE(DIO_Channel_Type channel , DIO_LEVEL level);



#endif /* MCAL_DIO_DIO_H_ */
