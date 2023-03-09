#include <avr/io.h>

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
 * 4_1  PA0 DIGITAL IN
 * 4_2  PA1 DIGITAL IN
 * 4_3  PA2 DIGITAL IN
 */

#define LS1_lo()	PORTD &= ~_BV(2)
#define LS1_hi()	PORTD |= _BV(2)
#define LS2_lo()	PORTD &= ~_BV(3)
#define LS2_hi()	PORTD |= _BV(3)
#define LS3_lo()	PORTA &= ~_BV(7)
#define LS3_hi()	PORTA |= _BV(7)
#define CBAT_lo()	PORTD &= ~_BV(0)
#define CBAT_hi()	PORTD |= _BV(0)
#define DBAT_lo()	PORTD &= ~_BV(1)
#define DBAT_hi()	PORTD |= _BV(1)

