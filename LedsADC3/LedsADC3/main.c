/*
 * LedsADC3.c
 *
 * Created: 27/04/2018 12:03:15
 * Author : Aitor Gustavo Camacho Gutiérrez
 */ 


#include <avr/io.h>

void digitalWrite(unsigned char data) {
	PORTB = (0b00000001 & data)<<2;
	PORTB |= (0b00000010 & data);
	PORTB |= (0b00000100 & data)>>2;
	PORTD = (0b00001000 & data) <<4;//
	PORTD |= (0b00010000 & data)<<1;
	PORTD |= (0b00100000 & data)>>1;
	PORTC = (0b01000000 & data) >>2;
	PORTC |= (0b10000000 & data)>>4;
	
	
}

int main(void)
{
	
	while(1) {
   digitalWrite(0x0F); 
   
	//for (f=0; f<40000; f++); //Hacemos una espera de 40.000 posiciones
	}
   
   
}

