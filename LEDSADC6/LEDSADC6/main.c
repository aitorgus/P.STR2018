/*
 * LEDSADC6.c
 *
 * Created: 03/05/2018 11:52:40
 * Author : Aitor
 */ 

#include <avr/io.h>

void initADC(void) {
	ADCSRA = (1 <<ADEN)+ (1<< ADPS2)+(0<<ADPS1)+(0<<ADPS0);
	//ADEN A 1 ACTIVO CONVERSION
	//1 << ADPS2 divisor de reloj en 16 (pag 8), dejo el resto a 0 (mirar tabla)
	
	//ADPS2:0 (son 3 bits de control) Preescalado del reloj para la conversi�n, ADC necesita entre 50 Khz a 200 Khz
	//a mayor frecuencia , conversi�n mas r�pida
	//Menor frecuencia, conversi�n mas exacta
	
	ADMUX = (1 << REFS0)  + (1 << ADLAR);
	ADMUX |= 5;
	
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
	ADCSRA |= (1<<ADSC);
	//Esperamos la conversi�n
	while ( ADCSRA & (1 << ADSC));
	return ADCH;
	
}

void digitalWrite(unsigned char data) {
	PORTB = (0b00000001 & data )<<2; //Como est� en el puerto B2 (hay que desplazarlo dos posiciones a la izq)
	PORTB |= (0b00000010 & data); //Est� en la segunda posicion (est� en su sitio)
	PORTB |= (0b00000100 & data)>>2 ; //Esta en la posicion 2 (HAY QUE DESPLAZARLO 2 A LA DERECHA PARA QUE SE UBIQUE EN EL 0)
	PORTD = (0b00001000 & data)<<4 ; //Estamos la posicion 3 y queremos llegar a PD7 (DESPLAZO 4 POSICIONES)
	PORTD |= (0b00010000 & data)<<1   ; //Estamos en posicion 4 y queremos llegar pd5 (desplazo 1)
	PORTD |= (0b00100000 & data)>>1  ;
	PORTC = (0b01000000 & data)>>2 ;
	PORTC |= (0b1000000 & data)>>4 ;
}

int main(void)
{
	DDRB = 0b00000111;
	DDRC = 0b00011000;
	DDRD = 0b10110000;
	unsigned char leer;
	
	initADC();
	while (1)
	{leer = getADCH();
		digitalWrite(leer);
		
	}
}




