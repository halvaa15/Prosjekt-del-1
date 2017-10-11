/*
 * Prosjekt del 1.cpp
 *
 * Created: 11.10.2017 10.36.31
 * Author : halva
 */ 

#ifndef F_CPU
#define F_CPU 1000000UL
#endif

#include <avr/io.h>		//Headerfil som gir oss forskjellige input/output operasjoner
#include <util/delay.h>		//Bibliotek for delay-funksjoner

int main(void)
{
	DDRD = 0b00000001;	//DDR = data direction. B = område på mirkokontroleren. Her setter vi pinne 0 på området D til å være en utgang.
	PORTD = 0b00000000;
	
    while (1) 
    {
		//Skru på lyset
		PORTD |= 0b00000001;		//Setter pinnen PD0 til å være høy
		_delay_ms(100);
		
		//Skru av lyset
		PORTD &= 0b11111110;		//Setter pinnen til å være lav
		_delay_ms(100);
    }
}

