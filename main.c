#include <stdbool.h>
#include <avr/io.h>
#include <util/delay.h>
#include <math.h>
#include "liblcd/lcd.h"
#include "liblcd/ili934x.h"
#include "libio/io.h"
#include "libadc/adc.h"
#include <avr/interrupt.h>
// DISPLAY 240 x 320
#define PV_CALIBRATED 3.16
#define WIND_CALIBRATED 3.23
#define VBUS_CALIBRATED 3.10
#define IBUS_CALIBRATED 3.33

//========================================================================//
// Scenario constants
const uint8_t MainsMAX = 2;
const uint8_t BatteryChargeI = 1;
const float Load1 = 1.2;
const float Load2 = 2;
const float Load3 = 0.8;
//========================================================================//

uint16_t drift = 0;
//  An unsigned int used to regulate TIMER0 drift.
uint16_t ibus, pvc, wtc;
//  uints for initial time sensitive data storage
float PV, Wind, BusI, MainsReq;

void init(){
    init_lcd();
    set_orientation(North);
    init_io();
    init_graphics();
    init_timers();
    init_adc();
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
    while(1){
        if(sync){

            LS3_hi();

            TCCR2B = 0x01;
            //  Starting the ADCMUX timer.
            sync = false;
            TIMSK0 &= ~_BV(OCIE0A);
            //  Disable TIMER0 Interrupt
            adts_disable();
            //  Enable Free Running Mode

            while(adc_mux_rdy == 0);
            ADMUX = 0x03;
            adc_mux_rdy = false;
            //  We change ADMUX while the current conversion is taking place

            while(adc_rdy == 0);
            BusI = adc_read;
            adc_rdy = false;
            /*
            ADMUX = 0x03;
            ADCSRA |=_BV(ADSC);
            while(ADCSRA &_BV(ADSC));
            wtc = ADC;
            //  Third for Wind Turbine Capacity.

            ADMUX = 0x04;
            ADCSRA |=_BV(ADSC);
            while(ADCSRA &_BV(ADSC));
            pvc = ADC;
            */
            LS3_lo();


            //  Fourth for PV Capacity.

            /*
            PV = pvc*PV_CALIBRATED/1024;
            Wind = wtc*WIND_CALIBRATED/1024;
            BusI = ibus*IBUS_CALIBRATED/1024;

            MainsReq =   (10/MainsMAX) * BusI;

            if(BusI + BatteryChargeI < MainsMAX){
                DBAT_lo();
                CBAT_hi();
            }
            else{
                CBAT_lo();
                DBAT_hi();
            }

            if(MainsReq >= 10){
                MainsReq = 10;
            }

            if(~LC1 && ~LC2 && ~LC3){
                LS1_lo();
                LS2_lo();
                LS3_lo();

            }

            if(LC1 && ~LC2 && ~LC3){
                //we will take the busI in the next if loop BusIdiff. If BusI < Bus
                if(Load1 < MainsMAX + PV + Wind){
                    LS1_hi();
                }
            }
            else LS1_lo();

            if(~LC1 && LC2 && ~LC3 ){
                if(Load2 < MainsMAX + PV + Wind){
                    LS2_hi();
                }
                else LS2_lo();
            }

            if( LC1 && LC2 && ~LC3){
                if(Load1 + Load2 < MainsMAX + PV + Wind){
                    LS2_hi();
                }
                else LS2_lo();
                if(Load1 < MainsMAX + PV + Wind){
                    LS1_hi();
                }
                else LS1_lo();
            }

            if(~LC1 && ~LC2 && LC3){
                if(Load3 < MainsMAX + PV + Wind){
                    LS3_hi();
                }
                else LS3_lo();
            }

            if(LC1 && ~LC2 && LC3){
                if(Load3 + Load1  < MainsMAX + PV + Wind){
                    LS3_hi();
                }
                else LS3_lo();

                if(Load1 < MainsMAX + PV + Wind){
                    LS1_hi();
                }
                else LS1_lo();
            }

            if(~LC1 && LC2 && LC3  ){
                if(Load2 + Load3 < MainsMAX + PV + Wind){
                    LS3_hi();
                }
                else LS3_lo();

                if(Load2 < MainsMAX + PV + Wind){
                    LS2_hi();
                }
                else LS2_lo();
            }

            if(LC1 && LC2 && LC3 ){
                if(Load1 + Load2 + Load3  < MainsMAX + PV + Wind){
                    LS3_hi();
                }
                else LS3_lo();

                if(Load2 + Load1 < MainsMAX + PV + Wind){
                    LS2_hi();
                }
                else LS2_lo();

                if(Load1 < MainsMAX + PV + Wind){
                    LS1_hi();
                }
                else LS1_lo();
            }

            */

            TIMSK0 |= _BV(OCIE0A);
            adts_enable();
            ADCSRA |=_BV(ADATE);
            //  Re-enable the TIMER0 Interrupt.
            //  Turning Auto Triggering back on.

        }

    }
    return 0;
}
