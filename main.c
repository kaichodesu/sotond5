#define PV_CALIBRATED 3.16
#define WIND_CALIBRATED 3.23
#define VBUS_CALIBRATED 3.10
#define IBUS_CALIBRATED 3.33
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




void init(){
    TIMER0_TOP = 233;
    OFFSET = 176;
    init_lcd();
    set_orientation(North);
    init_io();
    init_graphics();
    kamimashita();
    init_timers();
    init_adc();
    init_PWM();
    init_graphics();
    init_adc();
}


void lcd_update(void){
    //  We only want to draw to pixels that have changed.
    wind_pwr = (Wind/3.3) * 94;
    pv_pwr = (PV/3.3) * 94;
	power = BusI * 300/1000;
	power1 = (uint8_t) power % 10;
	power10 = (uint8_t) (power * 10) % 10;
	power100 = (uint8_t) (power * 100) % 10;

	power_kw_digit[0] = power_kw_digit[1];  //used to make present-state become previous-state
	power_10_digit[0] = power_10_digit[1];
	power_100_digit[0] = power_100_digit[1];
	bar_value_wind[0] = bar_value_wind[1];
	bar_value_sun[0] = bar_value_sun[1];

	if(PINA &=_BV(0))
	{
		LC1_green();
	}
	else
		LC1_red();

	if(PINA &=_BV(1))
	{
		LC2_green();
	}
	else
		LC2_red();

	if(PINA &=_BV(2))
	{
		LC3_green();
	}
	else
		LC3_red();

	if(PIND &=_BV(2))
	{
		LS1_green();
	}
	else
		LS1_red();

	if(PIND &=_BV(3))
	{
		LS2_green();
	}
	else
		LS2_red();

	if(PINA &=_BV(7))
	{
		LS3_green();
	}
	else
		LS3_red();



	if(PIND &=_BV(1)) // replace with pin value
	{
		battery_pwr_state[1] = 0;
	}
	else
		battery_pwr_state[1] = 1;

	power_kw_digit[1] = power1;
	power_10_digit[1] = power10;
	power_100_digit[1] = power100;

	bar_value_wind[1] = wind_pwr;
	bar_value_sun[1] = pv_pwr;

	if(power_kw_digit[0] != power_kw_digit[1] )
	{
		pwr_kw(power_kw_digit[1]);
	}

	if(power_10_digit[0] != power_10_digit[1])
	{
		pwr_10(power_10_digit[1]);
	}

	if(power_100_digit[0] != power_100_digit[1])
	{
		pwr_100(power_100_digit[1]);
	}

	if(battery_pwr_state[0] != battery_pwr_state[1]);
	{
		bat_pwr(battery_pwr_state[1]);
	}

	if(bar_value_sun[0] != bar_value_sun[1])
	{
		pwr_bar_sun(pv_pwr);
	}

	if(bar_value_wind[0] != bar_value_wind[1])
	{
		pwr_bar_wind(wind_pwr);
	}


}


int main(){
    uint8_t i = 0;
    init();
    while(1){
        if(sync){
            LS1_hi();
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

            if (drift == 0 || drift == 4){
                while(adc_rdy == 0);
                adc_rdy = false;
                //TCCR2B = 0x01;
                //  Start the ADCMUX timer for the next conversion
                BusI = adc_read*IBUS_CALIBRATED/1024;
                adc_rdy = false;
                ADCSRA |=_BV(ADSC);
                //adc_mux_rdy = false;
                //  We change ADMUX while the current conversion is taking place
                while(adc_rdy == 0);
                //TCCR2B = 0x01;
                //  Start the ADCMUX timer for the next conversion
                BusI = adc_read*IBUS_CALIBRATED/1024;
                adc_rdy = false;
                ADCSRA |=_BV(ADSC);
                //adc_mux_rdy = false;
                //  We change ADMUX while the current conversion is taking place
                while(adc_rdy == 0);
                //TCCR2B = 0x01;
                //  Start the ADCMUX timer for the next conversion
                adc_rdy = false;
                BusI = adc_read*IBUS_CALIBRATED/1024;
            }

            //  Reading Wind Capacity==========================================
            //while(adc_mux_rdy == 0);
            ADMUX = 0x03;
            ADCSRA |=_BV(ADSC);
            //adc_mux_rdy = false;
            //  We change ADMUX while the current conversion is taking place
            while(adc_rdy == 0);
            //TCCR2B = 0x01;
            //  Start the ADCMUX timer for the next conversion
            Wind = adc_read*WIND_CALIBRATED/1024;
            adc_rdy = false;
            ADCSRA |=_BV(ADSC);
            //adc_mux_rdy = false;
            //  We change ADMUX while the current conversion is taking place
            while(adc_rdy == 0);
            //TCCR2B = 0x01;
            //  Start the ADCMUX timer for the next conversion
            Wind = adc_read*WIND_CALIBRATED/1024;
            adc_rdy = false;
            ADCSRA |=_BV(ADSC);
            //adc_mux_rdy = false;
            //  We change ADMUX while the current conversion is taking place
            while(adc_rdy == 0);
            //TCCR2B = 0x01;
            //  Start the ADCMUX timer for the next conversion
            Wind = adc_read*WIND_CALIBRATED/1024;
            adc_rdy = false;
            ADCSRA |=_BV(ADSC);
            //adc_mux_rdy = false;
            //  We change ADMUX while the current conversion is taking place
            while(adc_rdy == 0);
            //TCCR2B = 0x01;
            //  Start the ADCMUX timer for the next conversion
            Wind = adc_read*WIND_CALIBRATED/1024;
            adc_rdy = false;

            //==================================================================
            //  Reading PV Capacity
            //while(adc_mux_rdy == 0);
            //ADMUX = 0x06;
            //adc_mux_rdy = false;
            //  We change ADMUX while the current conversion is taking place
            ADMUX = 0x04;
            ADCSRA |=_BV(ADSC);
            while(adc_rdy == 0);
            PV = adc_read*PV_CALIBRATED/1024;
            adc_rdy = false;
            ADCSRA |=_BV(ADSC);
            while(adc_rdy == 0);
            PV = adc_read*PV_CALIBRATED/1024;
            adc_rdy = false;

            //==================================================================

            if (drift == 3 | drift == 7)
                ADMUX = 0x06;
            else
                ADMUX = 0x03;

            algorithm();

            PWM((uint8_t)round((MainsReq/10)*255));

            drift++;

            if (drift%4)
                lcd_update();
                //  Runs the screen at 50Hz.

            /*if (drift == 1 | drift == 3 | drift == 5 | drift == 7){
                TIMER0_TOP = 233;
            }
            if (drift == 2 | drift == 4 | drift == 6){
                TIMER0_TOP = 234;
            }*/
            if (drift == 8)
                drift = 0;

            TIMSK0 |= _BV(OCIE0A);
            adts_enable();
            ADCSRA |=_BV(ADATE);
            ADCSRA |=_BV(ADSC);
            //  Re-enable the TIMER0 Interrupt.
            //  Turning Auto Triggering back on.
            LS1_lo();
        }

    }
    return 0;
}
