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
bool battery_pwr_state[2] = {0,0};
uint8_t power_kw_digit[2] = {0,0};
uint8_t power_10_digit[2] = {0,0};
uint8_t power_100_digit[2] = {0,0};

uint8_t bar_value_sun[2] = {0,0};
uint8_t bar_value_wind[2] = {0,0};


char string[3];
float power = BusI * 240;

 uint8_t wind_pwr = (Wind/1) * 94;
 uint8_t pv_pwr = (PV/3) * 94;
 




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
    init_timer0();
    init_adc();
}



void lcd_update(void){
	
	sprintf(string, "%f", power); //

	uint8_t power1 = (uint8_t) string[0]; 
	uint8_t power10 = (uint8_t) string[1];
	uint8_t power100 = (uint8_t) string[2];
	power_kw_digit[0] = power_kw_digit[1];  //used to make present-state become previous-state
	power_10_digit[0] = power_10_digit[1];
	power_100_digit[0] = power_100_digit[1];
	bar_value_wind[0] = bar_value_wind[1];
	bar_value_sun[0] = bar_value_sun[1];
	

	if(CBAT_lo()) // replace with pin value
	{
		battery_pwr_state[1] = 0; 
	}
	else 
		battery_pwr_state[1] = 1
		
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
		pwr_kw(power_100_digit[1]);
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
            sync = false;
            TIMSK0 &= ~_BV(OCIE0A);
            //  Disable TIMER0 Interrupt
            adts_disable();
            while(adc_rdy == 0);
            ADCSRA |=_BV(ADATE);
            //  Disable Autotriggering
            BusI = ADC;
            adc_rdy = false;

            ADMUX = 0x03;
            ADCSRA |=_BV(ADSC);
            while(ADCSRA &_BV(ADSC));
            wtc = ADC;
            //  Third for Wind Turbine Capacity.

            ADMUX = 0x04;
            ADCSRA |=_BV(ADSC);
            while(ADCSRA &_BV(ADSC));
            pvc = ADC;
            //  Fourth for PV Capacity.

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
	
		lcd_update();
			
            if(~LC1 && ~LC2 && ~LC3){
                LS1_lo();
                LS2_lo();
                LS3_lo();
				
				LC1_red();
				LC2_red();
				LC3_red();
				
				LS1_red();
				LS2_red();
				LS3_red();

            }

            if(LC1 && ~LC2 && ~LC3){
                if(Load1 < MainsMAX + PV + Wind){
                    LS1_hi();
					LC1_green();
					LC2_red();
					LC3_red();
				
					LS1_green();
					LS2_red();
					LS3_red();
                }
            
            else {
				LS1_lo();
				
				LC1_green();
				LC2_red();
				LC3_red();
				
				LS1_red();
				LS2_red();
				LS3_red();
			}
			}

            if(~LC1 && LC2 && ~LC3 ){
                if(Load2 < MainsMAX + PV + Wind){
                    LS2_hi();
					
					LC1_red();
					LC2_green();
					LC3_red();
					
					LS1_red();
					LS2_green();
					LS3_red();
                }
                else{
					LS2_lo();
					
					LC1_red();
					LC2_green();
					LC3_red();
				
					LS1_red();
					LS2_red();
					LS3_red();
					
					
				}
            }

            if( LC1 && LC2 && ~LC3){
                if(Load1 + Load2 < MainsMAX + PV + Wind){
                    LS2_hi();
					
					LC1_green();
					LC2_green();
					LC3_red();
					
					LS1_green();
					LS2_green();
					LS3_red();
                }
                else{
					LS2_lo();
					
					LC1_green();
					LC2_green();
					LC3_red();
					
					LS1_green();
					LS2_red();
					LS3_red();
					
					
				}
                if(Load1 < MainsMAX + PV + Wind){
                    LS1_hi();
					
					LC1_green();
					LS1_green();
                }
                else {
					LS1_lo();
					
					LS1_red();
				}
            }

            if(~LC1 && ~LC2 && LC3){
                if(Load3 < MainsMAX + PV + Wind){
                    LS3_hi();
					
					LC1_red();
					LC2_red();
					LC3_green();
					
					LS1_red();
					LS2_red();
					LS3_green();
                }
                else{
					LS3_lo();
					
					LC1_red();
					LC2_red();
					LC3_green();
					
					LS1_red();
					LS2_red();
					LS3_red();
					
					
				}
				
            }

            if(LC1 && ~LC2 && LC3){
                if(Load3 + Load1  < MainsMAX + PV + Wind){
                    LS3_hi();
					
					LC1_green();
					LC2_red();
					LC3_green();
					
					LS1_green();
					LS2_red();
					LS3_green();
                }
                else {
					LS3_lo();
					
					LC1_green();
					LC2_red();
					LC3_green();
					
					LS1_green();
					LS2_red();
					LS3_red();
					
					
					
				}

                if(Load1 < MainsMAX + PV + Wind){
                    LS1_hi();
					
					LC1_green();
					LS1_green();
                }
                else{
					LS1_lo();
					
					LC1_green();
					LS1_red();
				}
            }

            if(~LC1 && LC2 && LC3  ){
                if(Load2 + Load3 < MainsMAX + PV + Wind){
                    LS3_hi();
					
					LC1_red();
					LC2_green();
					LC3_green();
					
					LS1_red();
					LS2_green();
					LS3_green();
                }
                else {
					LS3_lo();
					
					LC1_red();
					LC2_green();
					LC3_green();
					
					LS1_red();
					LS2_green();
					LS3_red();
					
				}

                if(Load2 < MainsMAX + PV + Wind){
                    LS2_hi();
					
					LC2_green();
					LS2_green();
					
				
                }
                else{
					LS2_lo();
					
					LC2_green();
					LS2_red();
				}
            }

            if(LC1 && LC2 && LC3 ){
                if(Load1 + Load2 + Load3  < MainsMAX + PV + Wind){
                    LS3_hi();
					
					LC1_green();
					LC2_green();
					LC3_green();
					
					LS1_green();
					LS2_green();
					LS3_green();
                }
                else {
					LS3_lo();
					
					LC1_green();
					LC2_green();
					LC3_green();
					
					LS1_green();
					LS2_green();
					LS3_red();
					
				}
				

                if(Load2 + Load1 < MainsMAX + PV + Wind){
                    LS2_hi();
					
					LC2_green();
					LS2_green();
					
					
                }
                else{
					LS2_lo();
					
					LC2_green();
					LS2_red();
					
				}

                if(Load1 < MainsMAX + PV + Wind){
                    LS1_hi();
					
					LC1_green();
					LS1_green();
					
                }
                else{
					LS1_lo();
					
					LC1_green();
					LS1_red();
				}
            }

            TIMSK0 |= _BV(OCIE0A);
            adts_enable();
            ADCSRA |=_BV(ADATE);
            //  Re-enable the TIMER0 Interrupt.
            //  Turning Auto Triggering back on.
        }

    }
    return 0;
}
