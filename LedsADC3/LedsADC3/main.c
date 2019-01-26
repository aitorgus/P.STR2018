/*
 * LedsADC3.c
 *
 * Created: 27/04/2018 12:03:15
 * Author : 
 */ 
//Seminario 2. Parte 1. Ejercicio 3

//Escribe una función void digitalWrite() que muestre por los leds
//el valor binario de data 
#include <avr/io.h>

//Observar tabla Puertos "UMA MULTIPURPOSE"

void digitalWrite(unsigned char data) {
/* Puerto PB2*/	PORTB = (0b00000001 & data )<<2; 
/* Puerto PB1*/	PORTB |= (0b00000010 & data); 
/* Puerto PB0*/	PORTB |= (0b00000100 & data)>>2; 
/* Puerto PD7*/	PORTD = (0b00001000 & data)<<4; 
/* Puerto PD5*/	PORTD |= (0b00010000 & data)<<1; 
/* Puerto PD4*/	PORTD |= (0b00100000 & data)>>1;
/* Puerto PC4*/	PORTC = (0b01000000 & data)>>2;
/* Puerto PC3*/	PORTC |= (0b1000000 & data)>>4;
	
	
}

int main(void)
{
	
	while(1) {
   digitalWrite(0x0f); 
   
	}
   
   
}

