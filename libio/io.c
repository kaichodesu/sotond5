#include <avr/io.h>
#include "io.h"

/*
 * 1_1  PD5 PWM     OUT
 * 2_1  PA3 ANALOG  IN
 * 2_2  PA4 ANALOG  IN
 * 2_3  PA5 ANALOG  IN
 * 2_4  PA6 ANALOG  IN
 * 3_1  PD0 DIGITAL OUT CBAT
 * 3_2  PD1 DIGITAL OUT DBAT
 * 3_3  PD2 DIGITAL OUT LS1
 * 3_4  PD3 DIGITAL OUT LS2
 * 3_5  PA7 DIGITAL OUT LS3
 * 4_1  PA0 DIGITAL IN  LC1
 * 4_2  PA1 DIGITAL IN  LC2 
 * 4_3  PA2 DIGITAL IN  LC3
 */

void init_io()
{
    DDRD |= _BV(PD5);
    DDRA &= ~_BV(PA3);
    DDRA &= ~_BV(PA4);
    DDRA &= ~_BV(PA5);
    DDRA &= ~_BV(PA6);
    DDRD |= _BV(PD0);
    DDRD |= _BV(PD1);
    DDRD |= _BV(PD2);
    DDRD |= _BV(PD3);
    DDRA |= _BV(PA7);
    DDRA &= ~_BV(PA0);
    DDRA &= ~_BV(PA1);
    DDRA &= ~_BV(PA2);
    PORTA = 0x80;
}
