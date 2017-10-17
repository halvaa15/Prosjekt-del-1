/*
 * Prosjekt1.cpp
 *
 * Created: 17.10.2017 11.08.05
 * Author : Barstad
 */ 

#include <avr/io.h>		//Headerfil som gir oss forskjellige input/output operasjoner

#define BIT_IS_SET(byte, bit) (byte & (1 << bit))	//Sjekker et byte (f.eks. PINB) og sjekker om det tilh�rende bit (f.eks. PB0) er 1
#define BIT_IS_CLEAR(byte, bit) (!(byte & (1 << bit))	//Gj�r det samme, men sjekker at tilh�rende bit er 0

int main(void)
{
    DDRB &= ~(1 << PB0);	//DDR = data direction. B = omr�de B p� mikrokontrolleren. Setter PB0 (pinne 14) til � v�re 0, alts� input
	
	PORTB |= (1 << PB0);	//Aktiverer intern pull-up resistor p� inngang PB0 (pinne 14)
	
	DDRD |= (1 << PD0);		//Setter PD0 (pinne 2) til � v�re 1 (definerer den til � v�re en utgang)
	
	
    while (1)	//Begynner uendelig loop
    {
		//Skru p� lyset
		if(BIT_IS_CLEAR(PINB, PB0)))		//Hvis pinne 14 er h�y
		{
			PORTD |= (1 << PD0);	//Setter PD0 (pinne 2) h�y, og LED-en lyser
		}
		
		else if(BIT_IS_SET(PINB, PB0))	//Hvis pinne 14 er lav
		{
			PORTD &= ~(1 << PD0);	//Setter PD0 (pinne 2) lav, og LED-en lyser ikke
		}
		
		else
		{
		}
		
    }
	
	return (0);		//Kun for � ikke f� anmerkning p� kompileringen
}

