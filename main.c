
#include <stdio.h>
#include <avr/io.h>
#include <avr/interrupt.h>
#include "uart.h"
#include "util/delay.h"
#define F_CPU 16000000UL
#define BAUD_RATE 9600
#define BAUD_PRESCALER (((F_CPU / (BAUD_RATE * 16UL))) - 1)

volatile unsigned int overflow, pulse_width, current, endofword, dot, dash ; // Initialize all relevant variables

long long edge1, edge2;
char String[25]; //Array of characters
char debug[25];
char output [25];

void initialize () {
	cli(); //disable all global interrupts
	DDRB &= ~(1<<DDB0); //set PB0 to be input pin
	DDRD |= (1<<DDD7); //SET PD7 as output
	PORTD |= (1<<PORTD7); //use PD7 as permanent 5v output
	
	DDRB |= (1<<DDB5); //set PB5 (LED) as output
	TCCR1B |= (1<<ICES1); //look for falling edge
	TCCR1B &= ~(1<<CS10);	// Select timer 1 with a prescaler of 256. 1 tick in 1.6e-5s, 62500hz
	TCCR1B &= ~(1<<CS11);
	TCCR1B |= (1<<CS12);
	TIMSK1 |= (1 << TOIE1);; // enable overflows flag
	TCCR1A &= ~(1 << WGM10); //set timer 1 to normal mode
	TCCR1A &= ~(1 << WGM11);
	TCCR1B &= ~(1 << WGM12);
	TCCR1B |= (1<<ICNC1); //noise filter
	
	TIFR1 |= (1<<ICF1); //clear input capture flag
	
	TIMSK1 |= (1<<ICIE1); // Enable input capture interrupt
	
	
	
	
	sei(); //Enable global interrupts
	UART_init(BAUD_PRESCALER);
	edge1 = 0;
	edge2=0;
	overflow = 0;
	current = 0;
	endofword = 0;
	pulse_width = 0;
	dot=0;
	dash=0;
	for (int i = 0; i < 25; i++) {
		String[i] = '0';
	}
	
	for (int i = 0; i < 25; i++) {
		output[i] = '0';
	}

	

}

void print () { //compare string
	
if (strcmp(String, "._") == 0) {
	
	sprintf(output, "A");
	UART_putstring(output);
	
	} else if (
	
	strcmp(String, "_...") == 0) {
	sprintf(output, "B");
	UART_putstring(output);
	} else if (strcmp(String, "_._.") == 0) {
			sprintf(output, "C");
	UART_putstring(output);
	} else if (strcmp(String, "_..") == 0) {
			sprintf(output, "D");
	UART_putstring(output);
	} else if (strcmp(String, ".") == 0) {
			sprintf(output, "E");
	UART_putstring(output);
	} else if (strcmp(String, ".._.") == 0) {
			sprintf(output, "F");
	UART_putstring(output);
	} else if (strcmp(String, "__.") == 0) {
			sprintf(output, "G");
	UART_putstring(output);
	} else if (strcmp(String, "....") == 0) {
			sprintf(output, "H");
	UART_putstring(output);
	} else if (strcmp(String, "..") == 0) {
			sprintf(output, "I");
	UART_putstring(output);
	} else if (strcmp(String, ".___") == 0) {
			sprintf(output, "J");
	UART_putstring(output);
	} else if (strcmp(String, "_._") == 0) {
			sprintf(output, "K");
	UART_putstring(output);
	} else if (strcmp(String, "._..") == 0) {
			sprintf(output, "L");
	UART_putstring(output);
	} else if (strcmp(String, "__") == 0) {
			sprintf(output, "M");
	UART_putstring(output);
	} else if (strcmp(String, "_.") == 0) {
			sprintf(output, "N");
	UART_putstring(output);
	} else if (strcmp(String, "___") == 0) {
			sprintf(output, "O");
	UART_putstring(output);
	} else if (strcmp(String, ".__.") == 0) {
			sprintf(output, "P");
	UART_putstring(output);
	} else if (strcmp(String, "__._") == 0) {
			sprintf(output, "Q");
	UART_putstring(output);
	} else if (strcmp(String, "._.") == 0) {
			sprintf(output, "R");
	UART_putstring(output);
	} else if (strcmp(String, "...") == 0) {
			sprintf(output, "S");
	UART_putstring(output);
	} else if (strcmp(String, "_") == 0) {
			sprintf(output, "T");
	UART_putstring(output);
	} else if (strcmp(String, ".._") == 0) {
			sprintf(output, "U");
	UART_putstring(output);
	} else if (strcmp(String, "..._") == 0) {
			sprintf(output, "V");
	UART_putstring(output);
	} else if (strcmp(String, ".__") == 0) {
			sprintf(output, "W");
	UART_putstring(output);
	} else if (strcmp(String, "_.._") == 0) {
			sprintf(output, "X");
	UART_putstring(output);
	} else if (strcmp(String, "_.__") == 0) {
			sprintf(output, "Y");
	UART_putstring(output);
	} else if (strcmp(String, "__..") == 0) {
			sprintf(output, "Z");
	UART_putstring(output);
	} else if (strcmp(String, ".____") == 0) {
			sprintf(output, "1");
	UART_putstring(output);
	} else if (strcmp(String, "..___") == 0) {
			sprintf(output, "2");
	UART_putstring(output);
	} else if (strcmp(String, "...__") == 0) {
			sprintf(output, "3");
	UART_putstring(output);
	} else if (strcmp(String, "...._") == 0) {
			sprintf(output, "4");
	UART_putstring(output);
	} else if (strcmp(String, ".....") == 0) {
			sprintf(output, "5");
	UART_putstring(output);
	} else if (strcmp(String, "_....") == 0) {
			sprintf(output, "6");
	UART_putstring(output);
	} else if (strcmp(String, "__...") == 0) {
			sprintf(output, "7");
	UART_putstring(output);
	} else if (strcmp(String, "___..") == 0) {
			sprintf(output, "8");
	UART_putstring(output);
	} else if (strcmp(String, "____.") == 0) {
			sprintf(output, "9");
	UART_putstring(output);
	} else if (strcmp(String, "_____") == 0) {
			sprintf(output, "0");
	UART_putstring(output);
}
	
	for (int i = 0; i < 25; i++) {
		String[i] = '\0';
		
	}
	for (int i = 0; i < 25; i++) {
		output[i] = '\0';
	}
	current = 0;


};

ISR (TIMER1_OVF_vect)
{
	overflow+=65536; //count the number of overflows in ticks
}


ISR (TIMER1_CAPT_vect) {

	TIMSK1 |= (1<<TOIE1); //Enable timer overflow interrupt

	PORTB ^= (1<<PORTB5); //toggle led for debug
	
	if ((PINB & (1<<PINB0))) { //if button is pressed
		
		
		edge1 =ICR1 + overflow;
		pulse_width = edge1-edge2;
		
		//determine if space
		if (pulse_width > 25000) {


			endofword = 1;
			
		}
		
		
		
		} else { //if a button is released
		edge2=TCNT1 + overflow;
		
		pulse_width = edge2-edge1;
		
		if (pulse_width > 1875 && pulse_width < 12500) { //within the time interval for a dot
			
			dot=1;
			

			} else {

			dash=1;

		}
		endofword=0;
	}
	overflow = 0;
	TIMSK1 |= (1<<TOIE1); //Enable timer overflow interrupt
	TCCR1B ^= (1<<ICES1); //toggle edge
	TIFR1 |= (1<<ICF1); //clear input capture flag
	
}




int main(void)
{
	/* Replace with your application code */

	initialize();
	while(1)  {
		/*sprintf(output, "9");*/

		if (endofword == 1) { //space and print
			

			sprintf(debug, " ");
			UART_putstring(debug);
			print();
			current=0;
			endofword = 0;
			
		}
		if (dot) {
			//sprintf(debug, ".");
			//UART_putstring(debug);
			String[current] = '.';
			current++;
			dot=0;
			_delay_ms(50);
		}
		if (dash) {
			//sprintf(debug, "-");
			//UART_putstring(debug);
			String[current] = '-';
			current++;
			dash=0;
			_delay_ms(50);
		}
		
	}

	
	
	
	
	
	
}
