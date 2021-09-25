/*
 * DIO_CONFIG.h
 *
 *  Created on: Sep 5, 2021
 *      Author: Shady
 */

#ifndef MCAL_DIO_DIO_CONFIG_H_
#define MCAL_DIO_DIO_CONFIG_H_

typedef enum {
		//PORTA
		N_c,
		POT,
		RELAY,
		BUZZER,
		LCD4,
		LCD5,
		LCD6,
		LCD7,

		//portB
		BUTTON_0,
		RS,
		RW,
		LCD_E,
		SS,
		MOSI,
		MISO,
		SCK,

		//portC
		SCL,
		SDA,
		LED_0,
		H_A1,
		H_A2,
		H_A3,
		H_A4,
		LED_1,

		//portD
		RX,
		TX,
		BUTTON_2,
		LED_2,
		H_EN1,
		H_EN2,
		BUTTON_1,
		SERVO

	}DIO_Channel_Type;
typedef enum {
		DIO_Pin0,
		DIO_Pin1,
		DIO_Pin2,
		DIO_Pin3,
		DIO_Pin4,
		DIO_Pin5,
		DIO_Pin6,
		DIO_Pin7

	}DIO_PIN;

typedef enum {
		DIO_PortA,
		DIO_PortB,
		DIO_PortC,
		DIO_PortD

	}DIO_PORT;

typedef enum {
		LOW,
		HIGH

	}DIO_LEVEL;

typedef enum {
		INPUT,
		OUTPUT

	}DIO_DIR;

	typedef struct {
		DIO_PORT Pin_Port;
		DIO_PIN Pin;
		DIO_DIR Pin_Direction;
		DIO_LEVEL Pin_level;
	}DIO_PINcfgs;





#endif /* MCAL_DIO_DIO_CONFIG_H_ */
