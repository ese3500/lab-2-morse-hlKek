/*
 * ArduinoCode.c
 *
 * Created: 2/5/2023 2:11:26 PM
 * Author : Kek Hian Leng
 */ 

#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#define F_CPU 16000000UL


void initialize () {
	cli(); //disable all global interrupts
	DDRB &= ~(1<<DDB0); //set PB0 to be input pin
	DDRD |= (1<<DDD7); //SET PD7 as output
	PORTD |= (1<<PORTD7); //use PD7 as permanent 5v output
	
	DDRB |= (1<<DDB5); //set PB5 (LED) as output
	
	TCCR1B &= ~(1<<CS10);
	TCCR1B |= (1<<CS11);
	TCCR1B &= ~(1<<CS12);
	
	
	
	TCCR1B |= (1<<ICES1); //look for falling edge
	
	TIFR1 |= (1<<ICF1); //clear input capture flag
	
	TIMSK1 |= (1<<ICIE1); // Enable input capture interrupt
	
	
	sei(); //Enable global interrupts
}

ISR (TIMER1_CAPT_vect) {
	
	
	PORTB ^= (1<<PORTB5);

TCCR1B ^= (1<<ICES1);
TIFR1 |= (1<<ICF1); //clear input capture flag
}


int main(void)
{
    /* Replace with your application code */
	
	initialize();
	while(1);
	
	
	}
		

