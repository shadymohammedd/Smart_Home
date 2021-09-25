/*
 * DIO_INIT.c
 *
 *  Created on: Sep 5, 2021
 *      Author: Shady
 */
#include "DIO.h"


DIO_PINcfgs PIN_Cfgs[]={

		//Port A
		/*{DIO_PortA , DIO_Pin0 , OUTPUT, LOW},
		{DIO_PortA , DIO_Pin1 , OUTPUT, LOW},
		{DIO_PortA , DIO_Pin2 , OUTPUT, LOW},
		{DIO_PortA , DIO_Pin3 , OUTPUT, LOW},
		{DIO_PortA , DIO_Pin4 , OUTPUT, LOW},
		{DIO_PortA , DIO_Pin5 , OUTPUT, LOW},
		{DIO_PortA , DIO_Pin6 , OUTPUT, LOW},
		{DIO_PortA , DIO_Pin7 , OUTPUT, LOW},*/
		//Port B
		{DIO_PortB , DIO_Pin0 , INPUT},
		{DIO_PortB , DIO_Pin1 , INPUT},
		{DIO_PortB , DIO_Pin2 , INPUT},
		{DIO_PortB , DIO_Pin3 , INPUT},
		{DIO_PortB , DIO_Pin4 , INPUT},
		{DIO_PortB , DIO_Pin5 , INPUT},
		{DIO_PortB , DIO_Pin6 , OUTPUT},
		{DIO_PortB , DIO_Pin7 , INPUT},
		//Port C
		/*{DIO_PortC , DIO_Pin0 , OUTPUT, LOW},
		{DIO_PortC , DIO_Pin1 , OUTPUT, LOW},*/
		//{DIO_PortC , DIO_Pin2 , OUTPUT, LOW},
		/*{DIO_PortC , DIO_Pin3 , OUTPUT, LOW},
		{DIO_PortC , DIO_Pin4 , OUTPUT, LOW},
		{DIO_PortC , DIO_Pin5 , OUTPUT, LOW},
		{DIO_PortC , DIO_Pin6 , OUTPUT, LOW},
		{DIO_PortC , DIO_Pin7 , OUTPUT, LOW},*/
		//Port D
		//{DIO_PortD , DIO_Pin0 , INPUT, LOW},
		//{DIO_PortD , DIO_Pin1 , INPUT, LOW},
		{DIO_PortD , DIO_Pin2 , OUTPUT},
		/*{DIO_PortD , DIO_Pin3 , OUTPUT, LOW},
		{DIO_PortD , DIO_Pin4 , OUTPUT, LOW},
		{DIO_PortD , DIO_Pin5 , OUTPUT, LOW},*/
		{DIO_PortD , DIO_Pin6 , OUTPUT},
		//{DIO_PortD , DIO_Pin7 , OUTPUT, LOW},


};


void DIO_INIT(void){
	int count = sizeof(PIN_Cfgs)/sizeof(PIN_Cfgs[0]);
	int i;
	for (i=0 ;i<count ;i++){
		if(PIN_Cfgs[i].Pin_Port==DIO_PortA){
			if(PIN_Cfgs[i].Pin==OUTPUT){
				SET_BIT(DDRA,PIN_Cfgs[i].Pin);
			}
			else {
				CLEAR_BIT(DDRA,PIN_Cfgs[i].Pin);
			}
		}
		if(PIN_Cfgs[i].Pin_Port==DIO_PortB){
			if(PIN_Cfgs[i].Pin==OUTPUT){
				SET_BIT(DDRB,PIN_Cfgs[i].Pin);
			}
			else {
				CLEAR_BIT(DDRB,PIN_Cfgs[i].Pin);
			}
		}
		if(PIN_Cfgs[i].Pin_Port==DIO_PortC){
			if(PIN_Cfgs[i].Pin==OUTPUT){
				SET_BIT(DDRC,PIN_Cfgs[i].Pin);
			}
			else {
				CLEAR_BIT(DDRC,PIN_Cfgs[i].Pin);
			}
		}
		if(PIN_Cfgs[i].Pin_Port==DIO_PortD){
			if(PIN_Cfgs[i].Pin==OUTPUT){
				SET_BIT(DDRD,PIN_Cfgs[i].Pin);
			}
			else {
				CLEAR_BIT(DDRD,PIN_Cfgs[i].Pin);
			}
		}
	}

}




DIO_LEVEL DIO_READ(DIO_Channel_Type channel){

	DIO_PORT port =  channel /8;
	DIO_PIN pin =  channel %8;


	switch (port){
	case(DIO_PortA):
		return	GET_BIT(PINA,pin);
	break;

	case(DIO_PortB):
		return	GET_BIT(PINB,pin);
	break;

	case(DIO_PortC):
		return	GET_BIT(PINC,pin);
	break;

	case(DIO_PortD):
		return	GET_BIT(PIND,pin);
	break;
	default:
		return -1;
	break;

	}

}




void DIO_WRITE(DIO_Channel_Type channel , DIO_LEVEL level){

	DIO_PORT port =  channel /8;
	DIO_PIN pin =  channel %8;

	switch (port){
		case(DIO_PortA):
				if (level==HIGH){
					SET_BIT(PORTA,pin);
					}else{CLEAR_BIT(PORTA,pin);}
		break;

		case(DIO_PortB):
				if (level==HIGH){
					SET_BIT(PORTB,pin);
					}else{CLEAR_BIT(PORTB,pin);}
		break;

		case(DIO_PortC):
				if (level==HIGH){
					SET_BIT(PORTC,pin);
					}else{CLEAR_BIT(PORTC,pin);}
		break;

		case(DIO_PortD):
				if (level==HIGH){
					SET_BIT(PORTD,pin);
					}else{CLEAR_BIT(PORTD,pin);}
		break;

		default:
		break;

	}

}
