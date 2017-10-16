/*
 * Prosjekt1.cpp
 *
 * Created: 09.10.2017 11.08.05
 * Author : Barstad
 */ 

#ifndef F_CPU
#define F_CPU 1000000UL
#endif 

#include <avr/io.h>		//Headerfil som gir oss forskjellige input/output operasjoner
#include <util/delay.h>		//bibliotek for delay-funksjoner




int main(void)
{
    DDRD = 0b00000001;	//DDR = data direction. B = omr�de B p� mikrokontrolleren. Her setter vi pinne 0 p� omr�det B til � v�re en utgang. 
	PORTD = 0b00000000;	
	
    while (1) 
    {
		//Skru p� lyset
		PORTD |= 0b00000001;		//Setter pinnen PB0 til � v�re h�y.
		_delay_ms(100);
		
		//Skru av lyset
		PORTD &= 0b11111110;		//Setter pinnen til � v�re lav.
		_delay_ms(100);
		
    }
}

