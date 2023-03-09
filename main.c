#include <avr/io.h>
#include <util/delay.h>
#include <math.h>
#include "liblcd/lcd.h"
#include "liblcd/ili934x.h"
#include "libio/io.h"
// DISPLAY 240 x 320

uint16_t drift = 0;
//  An unsigned int used to regulate TIMER0 drift.
uint16_t vbus, ibus, pvc, wtc;


void init(){
    init_lcd();
    set_orientation(North);
    init_io();
    init_graphics();
}

int main(){
    init();
    while(1){
        algorithm(/*TODO*/);
}

ISR(TIMER0_COMPA_vect){
    cli();
    //  Disable interrupts during this routine.
    //  While it generally is not advisable to run long code in ISRs, we only have one interrupt and are using the ISR as a main clock, so it
    //  should be fine for this application.
    adts_disable();
    ADCSRA &=~_BV(ADATE);
    //  Disabling Auto Triggering
	while(ADCSRA &_BV(ADSC));
	vbus = ADC;
    //  First conversion for the 4VAC bus.  The conversion should have already started from the Timer0 Interrupt.

    ADMUX = 0x03;
    ADCSRA |=_BV(ADSC);
    while(ADCSRA &_BV(ADSC));
	ibus = ADC;
    //  Second conversion for the 10VAC bus.

    ADMUX = 0x05;
    ADCSRA |=_BV(ADSC);
    while(ADCSRA &_BV(ADSC));
	wtc = ADC;
    //  Third for Wind Turbine Capacity.

    ADMUX = 0x06;
    ADCSRA |=_BV(ADSC);
    while(ADCSRA &_BV(ADSC));
	pvc = ADC;
    ADCSRA |=_BV(ADATE);
    //  Fourth for PV Capacity.

    drift++;
    //  Increment the drift supervisor.
    if(drift > 3000){
        //  After 1 minute, recalibrate
        drift = 0;
        calibrate_timer0();
    }
    sei();
    //  Enable interrupts to prepare for the next conversion.
}
