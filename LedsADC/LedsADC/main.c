/*
 * LedsADC.c
 *
 * Created: 27/04/2018 11:38:28
 * Author : Aitor Gustavo Camacho Guti�rrez (Alumnostr09)
 */ 

#include <avr/io.h>
//Pr�ctica introductoria al Arduino Multipurpose UMA Shield - Parte 1 - LEDs Archivo
//Ejercicio 1
 //El LED0 est� conectado al puerto B, patilla 2
 //Configura PB.2 como salida (queremos escribir en el LED) mediante DDRB
 
int main(void)
{
    DDRB =(1<<2);
    PORTB =(1<<2);
	
    while (1) ;
   
}

