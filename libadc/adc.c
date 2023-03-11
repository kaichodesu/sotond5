#include <stdio.h>
#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#include "../libio/io.h"

volatile uint16_t adc_read;

void init_timer0(void)
{
	TCCR0A = 0x02; // set timer0 to CTC mode with 1024 prescaler
	TCCR0B = 0x05;
	TCNT0 = 0;
    OCR0A = 116;

	//set prescaler to 1024, count up to 116 (OCR0A),
}

void adts_disable(void){
    ADCSRB = 0;
}

void adts_enable(void){
    ADCSRB |=_BV(ADTS1);
	ADCSRB |=_BV(ADTS0);
}

ISR(ADC_vect){
    adc_read = ADC;
}

void calibrate_timer0(void)
{
    ADCSRA |= _BV(ADIE);
    adts_disable();
    //  Turn off OCR0A triggering if it is enabled.
	ADMUX = 0x06;
    //  Select PA4 as the ADC source.
    ADCSRA |=_BV(ADATE);
    ADCSRA |= _BV(ADSC);
    //  start conversions in free running mode
    while(adc_read < 100){}
        //  Waiting for the ADC to rise into the rectified waveform.
	while(adc_read > 10){}
    //  The instant the ADC reaches 0 again, we are in phase, and can reset the timer.
    TCNT0 = 0;
    adts_enable();
    ADCSRA &= ~_BV(ADIE);
    //  Reset timer 0 and turn off ADC interrupts
    OCR0A = 88; //made this 1 value larger than necessary to prevent interrupt
	while(TCNT0 < 87); //here we have reached a peak

	TCNT0 = 0; //reset timer count
	OCR0A = 116;//output compare 1 cycle after the peak

}

void init_adc(void){
    sei();
    ADCSRA |= _BV(ADPS2) |_BV(ADPS1);
    //  ADC ~200kHz
    ADCSRA |= _BV(ADEN);
    //  Enable ADC and ADC Interrupt
    //  Enable Auto triggering
    calibrate_timer0();
}

