#include "mainsreq.h"
#include <avr/interrupt.h>

//PWM-----------------------------------------------------
void init_PWM(void)
{
	DDRD |= _BV(PD5);
	TCCR1A = _BV(COM1A1)|_BV(WGM10)|_BV(WGM12);
	//  Fast PWM
	TCCR1B = _BV(CS10);
}

void PWM(uint8_t duty_cycle)
{
    OCR1A = (uint8_t) duty_cycle;
}
//--------------------------------------------------------

