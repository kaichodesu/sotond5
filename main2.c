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

void init(){
    init_io();
}

int main(){
    init();
    while(1){
    cli();
    LS1_hi();
    LS2_hi();
    LS3_hi();}
    return 0;
}
