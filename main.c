#define PV_CALIBRATED 3.16
#define WIND_CALIBRATED 3.23
#define VBUS_CALIBRATED 3.10
#define IBUS_CALIBRATED 3.33

#include <avr/interrupt.h>
#include <stdbool.h>
#include <avr/io.h>
#include <util/delay.h>
#include <math.h>
#include "liblcd/lcd.h"
#include "liblcd/ili934x.h"
#include "libio/io.h"
#include "libadc/adc.h"
#include "libalg/alg.h"
#include "mainsreq/mainsreq.h"
// DISPLAY 240 x 320

uint16_t ibus, pvc, wtc;
uint16_t drift = 0;
//  An unsigned int used to regulate TIMER0 drift.

void init(){
    init_lcd();
    set_orientation(North);
    init_io();
    init_graphics();
    init_timers();
    init_adc();
    init_PWM();
}

void lcd_update(void){

}

void lcd_test(void){
    int i;
        for(i = 0; i < 10; i++){
            bat_pwr(i%2);
            pwr_kw(i%3);
            pwr_10(i);
            pwr_100(i);
            _delay_ms(1000);
        }
}

int main(){
    init();
    uint16_t pwm = 127;
    while(1){
        if(sync){

            LS3_hi();
        if (pwm >=255)
            pwm = 0;
        PWM(pwm);
        pwm++;

            TCCR2B = 0x01;
            //  Starting the ADCMUX timer.
            sync = false;
            TIMSK0 &= ~_BV(OCIE0A);
            //  Disable TIMER0 Interrupt
            adts_disable();
            //  Enable Free Running Mode

            //  Reading IBUS value.
            while(adc_mux_rdy == 0);
            ADMUX = 0x03;
            adc_mux_rdy = false;
            //  We change ADMUX while the current conversion is taking place
            while(adc_rdy == 0);
            TCCR2B = 0x01;
            //  Start the ADCMUX timer for the next conversion
            BusI = adc_read;
            adc_rdy = false;

            //  Reading Wind Capacity
            while(adc_mux_rdy == 0);
            ADMUX = 0x04;
            adc_mux_rdy = false;
            //  We change ADMUX while the current conversion is taking place
            while(adc_rdy == 0);
            TCCR2B = 0x01;
            //  Start the ADCMUX timer for the next conversion
            wtc = adc_read;
            adc_rdy = false;

            //  Reading PV Capacity
            while(adc_mux_rdy == 0);
            ADMUX = 0x05;
            adc_mux_rdy = false;
            //  We change ADMUX while the current conversion is taking place
            while(adc_rdy == 0);
            pvc = adc_read;
            adc_rdy = false;

            PV = pvc*PV_CALIBRATED/1024;
            Wind = wtc*WIND_CALIBRATED/1024;
            BusI = ibus*IBUS_CALIBRATED/1024;

            // algorithm();

            LS3_lo();

            TIMSK0 |= _BV(OCIE0A);
            adts_enable();
            ADCSRA |=_BV(ADATE);
            //  Re-enable the TIMER0 Interrupt.
            //  Turning Auto Triggering back on.

        }

    }
    return 0;
}
