#include <avr/io.h>
#include <util/delay.h>
#include <math.h>
#include "lcdlib/lcd.c"

int main(){
    init_lcd();
    int i;
    for (i = 0; i < 20 ; i++){
        BLC_lo();
        _delay_ms(1000);
        BLC_hi();
        _delay_ms(1000);
    }
    return 0;
}
