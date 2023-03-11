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
    //init_timer0();
    //init_adc();
}

void lcd_update(void){
}

int main(){
    init();
    while(1){
        /*if(sync){
            sync = false;
            TIMSK0 &= ~_BV(OCIE0A);
            //  Disable TIMER0 Interrupt
            adts_disable();
            //  Enable free running mode on the ADC.
            while(adc_rdy == 0);
            BusI = ADC;
            adc_rdy = false;

            TIMSK0 |= _BV(OCIE0A);
            //  Re-enable the TIMER0 Interrupt.
        }*/

        int i;

        bat_pwr(true);

        _delay_ms(5000);

        bat_pwr(false);

        _delay_ms(5000);

        for(i = 0; i < 11; i++){
            pwr_kw(i);
            pwr_10(i);
            pwr_100(i);
            _delay_ms(5000);
        }
    }
    return 0;
}

/*ISR(TIMER0_COMPA_vect){
    sync = true;
    LS3_hi();
    //  Disable interrupts during this routine.
    //  While it generally is not advisable to run long code in ISRs, we only have one interrupt and are using the ISR as a main clock, so it
    //  should be fine for this application.
    //adts_disable();
    //  Disabling Auto Triggering
	//while(ADCSRA &_BV(ADSC));
    //ibus = ADC;
    //LS3_hi();
    //  First conversion for the 10VAC bus.  The conversion should have already started from the Timer0 Interrupt.
*/
    /*ADMUX = 0x03;
    ADCSRA |=_BV(ADSC);
    while(ADCSRA &_BV(ADSC));
	vbus = ADC;
    //  Second conversion for the 4VAC bus.*/

    //====

    /*
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
    //  Turning Auto Triggering back on.

    PV = pvc*PV_CALIBRATED/1024;
    Wind = wtc*WIND_CALIBRATED/1024;
    BusI = ibus*IBUS_CALIBRATED/1024;

    MainsReq =   (10/MainsMAX) * BusI;
*/

    /*if(BusI + BatteryChargeI < MainsMAX){
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
/*
    drift++
    //  Increment the drift supervisor.
    if(drift%50 == 0){
        //  Update the UI every second
        lcd_update();
    }

    if(drift > 3000){
        //  After 1 minute, recalibrate
        drift = 0;
        calibrate_timer0();
    }
    //  Enable interrupts to prepare for the next conversion.
}*/
