#include <stdio.h>
#include <avr/io.h>
#include "debug.h"
#define BAUD 9600
#include <util/setbaud.h>
#include <util/twi.h>
#include <util/delay.h>
#include <avr/interrupt.h>

double voltage;

void init_timer0(void)
{
	TCCR0A = 0x02; // set timer0 to CTC mode with 1024 prescaler
	TCCR0B = 0x05;
	TCNT0 = 0;

	//set prescaler to 1024, count up to 116 (OCR0A),
}

void init_adc(void)
{
	ADCSRA |=_BV(ADPS2) |_BV(ADPS1);
	ADMUX |= 0x00;  // TODO

	ADCSRA |=_BV(ADEN);
	ADCSRA |=_BV(ADATE);

	ADCSRA |= _BV(ADSC);	// start conversions in free running mode

	while(ADCSRA &_BV(ADSC)); //wait for first conversion to complete
	while((3.3/1024)*ADC < 0.5); //these 3 loops  ensure we are at correct position
	while((3.3/1024)*ADC > 0.5);
	while((3.3/1024)*ADC > 0.01);

		init_timer0(); //initialise timer 0 in CTC mode
		OCR0A = 88; //made this 1 value larger than necessary to prevent interrupt
		if(TCNT0 == 87) //here we have reached a peak
		{
			TCNT0 = 0; //reset timer count
			OCR0A = 116; //output compare 1 cycle after the peak
		}


	ADCSRB |=_BV(ADTS1); //interrupt on OCR0A
	ADCSRB |=_BV(ADTS0);


}

ISR(TIMER0_COMPA_vect)
{
	ADCSRA |= _BV(ADSC);
	while(ADCSRA &_BV(ADSC));
	voltage = (3.3/1024)*ADC;

	//Place print statement here for testing purposes

}
