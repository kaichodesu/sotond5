#include <stdio.h>
#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#include <stdbool.h>
#include "../libio/io.h"

volatile uint16_t adc_read;
volatile bool calibrating, adc_rdy, sync, adc_mux_rdy;
uint8_t TIMER0_TOP = 233;
uint8_t phase_delay = 176;
//  TOP value used to fine tune the phase delay to capture the mains AC phase.

void init_timers(void)
{
	TCCR0A = 0x02; // set timer0 to CTC mode with 1024 prescaler
	TCCR0B = 0x05;
	TCNT0 = 0;
    TIMSK0 = 0;
    sync = false;
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
    adc_rdy = true;
    // a flag for the main loop
}

ISR(TIMER0_COMPA_vect){
    sync = true;
}

ISR(TIMER2_COMPA_vect){
    TCCR2B = 0x00;
    //  Stop the timer after reset.
    adc_mux_rdy = true;
}

void calibrate_timer0(void)
{
    int i;
    calibrating = true;
    ADCSRA |= _BV(ADIE);
    adts_disable();
    //  Turn off OCR0A triggering if it is enabled.
	ADMUX = 0x05;
    //  Select PA5 as the ADC source.
    ADCSRA |=_BV(ADATE);
    ADCSRA |= _BV(ADSC);
    //  start conversions in free running mode
    for(i = 0; i < 20; i++)
    while(adc_read <= 20){}
        //  Waiting for the ADC to rise into the rectified waveform.
    for(i = 0; i < 20; i++)
	while(adc_read > 0){}
    //  The instant the ADC reaches 0 again, we are in phase, and can reset the timer.
    ADCSRA &= ~_BV(ADIE);
    //  Turn off ADC interrupts
    init_timers();
    //  Start Timer
    OCR0A = phase_delay;
    TIMSK0 |= _BV(OCIE0A);
    //ADCSRA &= ~_BV(ADIE);
    //  Reset timer 0 and turn off ADC interrupts
    sync = false;
	while(sync == false); //here we have reached a peak
	TCNT0 = 0; //reset timer count
	OCR0A = TIMER0_TOP;//output compare 1 cycle after the peak

    ADMUX = 0x06;
    adts_enable();
    ADCSRA |= _BV(ADIE);
	calibrating = false;
    adc_rdy = false;
    //  Restart ADC on Timer0 interrupts
}

void init_adc(void){
    sei();
    ADCSRA |= _BV(ADPS2) |_BV(ADPS1)/*|_BV(ADPS0)*/;
    //  ADC ~200kHz
    ADCSRA |= _BV(ADEN);
    //  Enable ADC
    calibrate_timer0();
}

