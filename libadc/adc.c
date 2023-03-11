#include <stdio.h>
#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#include <stdbool.h>
#include "../libio/io.h"

volatile uint16_t adc_read;
volatile bool calibrating, adc_rdy, sync;
const uint8_t OFFSET = 176;
//  TOP value used to fine tune the phase delay to capture the mains AC phase.

void init_timer0(void)
{
	TCCR0A = 0x02; // set timer0 to CTC mode with 1024 prescaler
	TCCR0B = 0x05;
	TCNT0 = 0;
    OCR0A = 234;
    TIMSK0 = 0;

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
    if(calibrating)
        adc_read = ADC;
    else
        adc_rdy = true;
    // a flag for the main loop
}

ISR(TIMER0_COMPA_vect){
    sync = true;
}

void calibrate_timer0(void)
{
    calibrating = true;
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
    OCR0A = OFFSET;
    adts_enable();
    ADCSRA &= ~_BV(ADIE);
    TIMSK0 |= _BV(OCIE0A);
    //ADCSRA &= ~_BV(ADIE);
    //  Reset timer 0 and turn off ADC interrupts
	while(!sync); //here we have reached a peak
	TCNT0 = 0; //reset timer count
	OCR0A = 234;//output compare 1 cycle after the peak
	sync = false;
    ADCSRA |= _BV(ADIE);
	calibrating = false;
}

void init_adc(void){
    sei();
    ADCSRA |= _BV(ADPS2) |_BV(ADPS1);
    //  ADC ~200kHz
    ADCSRA |= _BV(ADEN);
    //  Enable ADC
    calibrate_timer0();
}

