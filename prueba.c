/* Programa de prueba: hace parpadear el LED del Arduino muy rápidamente */

#include <avr/io.h>
#include <avr/interrupt.h>

int main(void)
{
	unsigned f;
	unsigned char c;

	c=0;
	DDRB=(1<<5);
	while (1)
	{
		if (c==0) 
		{
			PORTB &= ~(1 << 5);
			c=1;
		}
		else 
		{
			PORTB |= (1 << 5);
			c=0;
		}
		for (f=0; f<40000; f++);
	}

	return(0);
}