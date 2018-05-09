/*
 * LEDSADC4.c
 *
 * Created: 03/05/2018 11:11:55
 * Author : Aitor
 */ 
//Escribe una función void initADC(void) que inicialice ADC
#include <avr/io.h>

void initADC(void) {
	ADCSRA = (1 <<ADEN)+ (1<< ADPS2)+(0<<ADPS1)+(0<<ADPS0);
	//ADEN A 1 ACTIVO CONVERSION
	//1 << ADPS2 divisor de reloj en 16 (pag 8), dejo el resto a 0 (mirar tabla)
	
	//ADPS2:0 (son 3 bits de control) Preescalado del reloj para la conversión, ADC necesita entre 50 Khz a 200 Khz
	//a mayor frecuencia , conversión mas rápida
	//Menor frecuencia, conversión mas exacta
	
	ADMUX = (1 << REFS0)  + (1 << ADLAR);
	//REFS0 REFERENCIA AL VOLTAJE EXTERNO
	// ADLAR (ALINEACIÓN RESULTADO 0 A LA DERECHA , 1 A LA IZQUIERDA)
	//CON 0 A LA DERECHA
	
	
}
int main(void)
{
    
    while (1) 
    {
		
    }
}

