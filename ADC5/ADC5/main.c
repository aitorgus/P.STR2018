/*
 * ADC5.c
 *
 * Created: 03/05/2018 11:33:26
 * Author : Aitor
 */ 
//Escribe una funci�n unsigned char getADCH(void) que inicie una conversi�n del ADC, espere que finalice, y por �ltimo devuelva el contenido de ADCH (parte
//alta de la conversi�n).
#include <avr/io.h>

void initADC(void) {
	ADCSRA = (1 <<ADEN)+ (1<< ADPS2)+(0<<ADPS1)+(0<<ADPS0);
	//ADEN A 1 ACTIVO CONVERSION
	//1 << ADPS2 divisor de reloj en 16 (pag 8), dejo el resto a 0 (mirar tabla)
	
	//ADPS2:0 (son 3 bits de control) Preescalado del reloj para la conversi�n, ADC necesita entre 50 Khz a 200 Khz
	//a mayor frecuencia , conversi�n mas r�pida
	//Menor frecuencia, conversi�n mas exacta
	
	ADMUX = (1 << REFS0)  + (1 << ADLAR);
	//REFS0 REFERENCIA AL VOLTAJE EXTERNO
	// ADLAR (ALINEACI�N RESULTADO 0 A LA DERECHA , 1 A LA IZQUIERDA)
	//CON 0 A LA DERECHA
}
char getADCH (void){
	
	int ADCchanel=5;
	//ADMUX 3:0 , Para seleccionar el canal ADC5 -> 0101
	//En primer lugar , seleccionamos el canal de ADC
	ADMUX |= (ADCchanel & 0x0F);
	//Conversion simple 
	ADCSRA = (1<<ADSC);
	//Esperamos la conversi�n
	while ( ADCSRA & (1 << ADSC));
	return ADCH;
	
}


int main(void)
{
    
    while (1) 
    {
		
    }
}


