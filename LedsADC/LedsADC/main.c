/*
 * LedsADC.c
 *
 * Created: 27/04/2018 11:38:28
 * Author : Aitor Gustavo Camacho Gutiérrez (Alumnostr09)
 */ 

#include <avr/io.h>
//Práctica introductoria al Arduino Multipurpose UMA Shield - Parte 1 - LEDs Archivo

int main(void)
{
    DDRB =(1<<2);
    PORTB =(1<<2);
	
    while (1) ;
   
}

