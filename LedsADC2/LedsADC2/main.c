/*
 * LedsADC2.c
 *
 * Created: 27/04/2018 11:51:28
 * Author : Aitor Gustavo Camacho Gutiérrez
 */ 

#include <avr/io.h>

//Práctica introductoria al Arduino Multipurpose UMA Shield - Parte 1 - LEDs Archivo
	//Ejercicio 2
	//Configuramos como salida el puerto DDRD (antes el B)
	
int main(void)
{
	
	
	DDRD =(1<<2);
	PORTB =(1<<2); //Encendemos Led 0 (Que está conectado con PB.2)
	
	
	
	
	while (1) ; //Bucle infinito 
	
}

