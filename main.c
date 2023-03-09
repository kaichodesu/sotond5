#include <avr/io.h>
#include <util/delay.h>
#include <math.h>
#include "liblcd/lcd.h"
#include "liblcd/ili934x.h"
#include "libio/io.h"
// DISPLAY 240 x 320

void init(){
    init_lcd();
    set_orientation(North);
    init_io();
    init_graphics();
}

int main(){
    init();
    _delay_ms(2000);
    calibrate_graphics();
    return 0;
}
