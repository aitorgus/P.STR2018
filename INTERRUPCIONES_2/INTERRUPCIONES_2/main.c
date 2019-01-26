/*
 * INTERRUPCIONES_2.c
 *
 * Created: 04/05/2018 10:50:55
 * Author : 
 */ 

//Acceso a las interrupciones dadas por las pulsaciones de los botones 

#include <avr/io.h>
#include <avr/interrupt.h> //Permiten el control de IRQs
unsigned contador=0; //Debemos de poner a 0 la variable global

void initADC(void) {
	ADCSRA = (1 <<ADEN)+ (1<< ADPS2)+(0<<ADPS1)+(0<<ADPS0)+(1<<ADIE) + (1<<ADSC);
	//ADIE activa interrupciones
	//ADSC
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


void digitalWrite(unsigned char data) {
	PORTB = (0b00000001 & data )<<2; //Como está en el puerto B2 (hay que desplazarlo dos posiciones a la izq)
	PORTB |= (0b00000010 & data); //Está en la segunda posicion (está en su sitio)
	PORTB |= (0b00000100 & data)>>2 ; //Esta en la posicion 2 (HAY QUE DESPLAZARLO 2 A LA DERECHA PARA QUE SE UBIQUE EN EL 0)
	PORTD = (0b00001000 & data)<<4 ; //Estamos la posicion 3 y queremos llegar a PD7 (DESPLAZO 4 POSICIONES)
	PORTD |= (0b00010000 & data)<<1   ; //Estamos en posicion 4 y queremos llegar pd5 (desplazo 1)
	PORTD |= (0b00100000 & data)<<1  ;
	PORTC = (0b01000000 & data)>>2 ;
	PORTC |= (0b1000000 & data)>>4 ;
}

ISR(ADC_vect) {
	//Seleccionamos ADC
	ADMUX |= (5 & 0X0F);
	digitalWrite(ADCH);
	ADCSRA |= (1<<ADSC); //Vuelvo a activar el contador
	
}

ISR(PCINT0_vect) //Puerto B 
{ 
	if ((PINB & (1<< PINB4)) >> 4)
	{
		//Pulsamos botón A, el contador se incrementa
		contador++;
		
		digitalWrite(contador);
	}
	else if ((PINB & (1<<PINB3))>> 3)
	{
		contador--;
		digitalWrite(contador);
	}
	
}

ISR(PCINT2_vect){
	
if ((PIND & (1<<PIND2))>>2)

	{
		initADC();
	}
	
	
}



int main(void)
{
	
	cli(); //Deshabilito interrupciones
	DDRB = 0b00000111;
	DDRC = 0b00011000;
	DDRD = 0b10110000;
	PCICR=(1<<PCIE0)+(1<<PCIE2) ;//MASCARA (PÁGINA 8)
	PCMSK0 =(1<<PCINT4)+(1<<PCINT3)  ;//BOTONES QUE ESTÁN EN EL 0 (PAGINA 9)
	PCMSK2=(1<<PCINT18) ;//BOTON PD2 (PÁGINA 9)
	//Mirar pagina 8 , disyuntiva entre puerto D o B pines PCIE2 O PCIE0.
	//El mas es una disyunción
	
	//PCMSK2 lo usamos para el puerto D2.

	
	digitalWrite(0x00);//Ponemos a 0 los leds
	
	sei(); //Las habilito de nuevo
	while (1)
	{
		
	}
}

