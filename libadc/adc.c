#include <stdio.h>
#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>

void init_timer0(void)
{
	TCCR0A = 0x02; // set timer0 to CTC mode with 1024 prescaler
	TCCR0B = 0x05;
	TCNT0 = 0;

	//set prescaler to 1024, count up to 116 (OCR0A),
}

void adts_disable(void){
    ADCSRB = 0;
}

void adts_enable(void){
    ADCSRB |=_BV(ADTS1);
	ADCSRB |=_BV(ADTS0);
}

void calibrate_timer0(void)
{
    adts_disable();
    //  Turn off OCR0A triggering if it is enabled.
	ADMUX = 0x04;
    //  Select PA4 as the ADC source.
    ADCSRA |= _BV(ADSC);
    //  start conversions in free running mode

	while(ADCSRA &_BV(ADSC));
    //  wait for first conversion to complete
	while(ADC < 100);
    //  Waiting for the ADC to rise into the rectified waveform.
	while(ADC > 0.01);
    //  The instant the ADC reaches 0 again, we are in phase, and can reset the timer.
    TCNT0 = 0;
    //  Reset timer 0.
    OCR0A = 88; //made this 1 value larger than necessary to prevent interrupt
	while(TCNT0 < 87); //here we have reached a peak

	TCNT0 = 0; //reset timer count
	OCR0A = 116; //output compare 1 cycle after the peak

	adts_enable();
}

void init_adc(void){
    ADCSRA |=_BV(ADPS2) |_BV(ADPS1);
    ADCSRA |=_BV(ADEN);
    //  Enable ADC
	ADCSRA |=_BV(ADATE);
    //  Enable Auto triggering
    calibrate_timer0();
}

