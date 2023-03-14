#define PV_CALIBRATED 4.4
#define WIND_CALIBRATED 3.79
#define VBUS_CALIBRATED 3.10
#define IBUS_CALIBRATED 5
#define F_CPU 12000000UL

#include <avr/interrupt.h>
#include <stdbool.h>
#include <avr/io.h>
#include <util/delay.h>
#include <math.h>
#include <stdio.h>
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
uint16_t watchdog = 0;


bool battery_pwr_state[2] = {false,false};
uint8_t power_kw_digit[2] = {0,0};
uint8_t power_10_digit[2] = {0,0};
uint8_t power_100_digit[2] = {0,0};
uint8_t bar_value_sun[2] = {0,0};
uint8_t bar_value_wind[2] = {0,0};
char string[3];
uint8_t wind_pwr;
uint8_t pv_pwr;
float power;
uint8_t power1, power10, power100;
float ibusarray[20], windarray[20], pvarray[20];




void init(){
    TIMER0_TOP = 233;
    OFFSET = 176;
    init_lcd();
    set_orientation(North);
    init_io();
    init_graphics();
    //kamimashita();
    init_adc();
    init_PWM();
    //init_graphics();
    //init_adc();
}


void lcd_update(void){
    //  We only want to draw to pixels that have changed.
    wind_pwr = round((Wind/3) * 94);
    pv_pwr = round((PV) * 94);
	power = BusI * 300/1000;
	power1 = (uint8_t) floor(power);
	power10 = ((uint8_t) round(power * 100)) % 10;
	power100 = ((uint8_t) floor(power * 10)) % 10;

	power_kw_digit[0] = power_kw_digit[1];  //used to make present-state become previous-state
	power_10_digit[0] = power_10_digit[1];
	power_100_digit[0] = power_100_digit[1];
	bar_value_wind[0] = bar_value_wind[1];
	bar_value_sun[0] = bar_value_sun[1];

	power_kw_digit[1] = power1;
	power_10_digit[1] = power10;
	power_100_digit[1] = power100;

	bar_value_wind[1] = wind_pwr;
	bar_value_sun[1] = pv_pwr;

	if(power_kw_digit[0] != power_kw_digit[1] )
	{
		pwr_kw(power_kw_digit[1]);
	}

    if(battery_pwr_state[0] != battery_pwr_state[1]);
	{
		bat_pwr(battery_pwr_state[1]);
	}

	if(power_10_digit[0] != power_10_digit[1])
	{
		pwr_10(power_10_digit[1]);
	}

	if(bar_value_sun[0] != bar_value_sun[1])
	{
		pwr_bar_sun(pv_pwr);
    }

	if(power_100_digit[0] != power_100_digit[1])
	{
		pwr_100(power_100_digit[1]);
	}

	if(bar_value_wind[0] != bar_value_wind[1])
	{
		pwr_bar_wind(wind_pwr);
	}


}

void analog_read(){
    //  Reading Wind Capacity==========================================
            //while(adc_mux_rdy == 0);
            ADMUX = 0x03;
            ADCSRA |=_BV(ADSC);
            //adc_mux_rdy = false;
            //  We change ADMUX while the current conversion is taking place
            while(adc_rdy == 0);
            //TCCR2B = 0x01;
            //  Start the ADCMUX timer for the next conversion
            windarray[0] = adc_read*WIND_CALIBRATED*3.3/1024;
            adc_rdy = false;
            ADCSRA |=_BV(ADSC);
            while(adc_rdy == 0);
            windarray[1] = adc_read*WIND_CALIBRATED*3.3/1024;
            adc_rdy = false;
            ADCSRA |=_BV(ADSC);
            while(adc_rdy == 0);
            windarray[2] = adc_read*WIND_CALIBRATED*3.3/1024;
            adc_rdy = false;
            ADCSRA |=_BV(ADSC);
            while(adc_rdy == 0);
            windarray[3] = adc_read*WIND_CALIBRATED*3.3/1024;
            adc_rdy = false;
            ADCSRA |=_BV(ADSC);
            while(adc_rdy == 0);
            windarray[4] = adc_read*WIND_CALIBRATED*3.3/1024;
            adc_rdy = false;
            Wind = (windarray[0] + windarray[1] + windarray[2] + windarray[3] + windarray[4])/5;

            //==================================================================
            //  Reading PV Capacity
            //while(adc_mux_rdy == 0);
            //ADMUX = 0x06;
            //adc_mux_rdy = false;
            //  We change ADMUX while the current conversion is taking place
            ADMUX = 0x04;
            ADCSRA |=_BV(ADSC);
            while(adc_rdy == 0);
            pvarray[0] = adc_read*PV_CALIBRATED/1024;
            adc_rdy = false;
            ADCSRA |=_BV(ADSC);
            while(adc_rdy == 0);
            pvarray[1] = adc_read*PV_CALIBRATED/1024;
            adc_rdy = false;
            ADCSRA |=_BV(ADSC);
            while(adc_rdy == 0);
            pvarray[2] = adc_read*PV_CALIBRATED/1024;
            adc_rdy = false;
            ADCSRA |=_BV(ADSC);
            while(adc_rdy == 0);
            pvarray[3] = adc_read*PV_CALIBRATED/1024;
            adc_rdy = false;
            ADCSRA |=_BV(ADSC);
            while(adc_rdy == 0);
            pvarray[4] = adc_read*PV_CALIBRATED/1024;
            adc_rdy = false;
            PV = (pvarray[0] + pvarray[1] + pvarray[2] + pvarray[3] + pvarray[4])/5;

            //==================================================================
            ADMUX = 0x06;
}

int main(){
    uint8_t i = 0;
    PV = 1;
    Wind = 3;
    init();
    while(1){
        if(sync){
            //  ADMUX preset to PA6
            //TCCR2B = 0x01;
            //  Starting the ADCMUX timer.
            sync = false;
            TIMSK0 &= ~_BV(OCIE0A);
            //  Disable TIMER0 Interrupt
            adts_disable();
            ADCSRA &=~_BV(ADATE);
            //  Disable auto triggering.

            //  Reading IBUS value.
            //while(adc_mux_rdy == 0);
            //ADMUX = 0x03;
            //adc_mux_rdy = false;
            //  We change ADMUX while the current conversion is taking place


                while(adc_rdy == 0);
                adc_rdy = false;
                //TCCR2B = 0x01;
                //  Start the ADCMUX timer for the next conversion
                ibusarray[0] = adc_read/205;
                adc_rdy = false;
                ADCSRA |=_BV(ADSC);
                //adc_mux_rdy = false;
                //  We change ADMUX while the current conversion is taking place
                while(adc_rdy == 0);
                ibusarray[1] = adc_read/205;
                adc_rdy = false;
                ADCSRA |=_BV(ADSC);
                while(adc_rdy == 0);
                ibusarray[2] = adc_read/205;
                adc_rdy = false;
                ADCSRA |=_BV(ADSC);
                while(adc_rdy == 0);
                ibusarray[3] = adc_read/205;
                adc_rdy = false;
                ADCSRA |=_BV(ADSC);
                while(adc_rdy == 0);
                ibusarray[4] = adc_read/205;
                adc_rdy = false;
                BusI = (ibusarray[0] + ibusarray[1] + ibusarray[2] + ibusarray[3] + ibusarray[4])/5;

            algorithm();
            drift++;


            watchdog++;

            lcd_update();
            //  Runs the screen at 50Hz.

            MainsReq = 10/MainsMAX * BusI;
            if (MainsReq >= 10)
                MainsReq = 10;

            if (drift == 1){
                OCR0A = 233;
            }
            if (drift == 8){
                drift = 0;
                OCR0A = 236;
            }

            void analog_read();

            if(watchdog < 500){
            TIMSK0 |= _BV(OCIE0A);
            adts_enable();
            ADCSRA |=_BV(ADATE);
            ADCSRA |=_BV(ADSC);
            //  Re-enable the TIMER0 Interrupt.
            //  Turning Auto Triggering back on.
            }
            else{
                watchdog = 0;
                ADMUX = 0x05;
                calibrate_timer0();
                TIMSK0 |= _BV(OCIE0A);
                adts_enable();
                ADCSRA |=_BV(ADATE);
                ADCSRA |=_BV(ADSC);

            }

        }

    }
    return 0;
}
