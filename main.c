#include <avr/io.h>
#include <util/delay.h>
#include <math.h>
#include "lcdlib/lcd.h"
#include "lcdlib/ili934x.h"
// DISPLAY 240 x 320

int main(){
    init_lcd();
    set_orientation(North);
    int index;
    init_graphics();
    _delay_ms(2000);
    calibrate_graphics();
    return 0;
}
