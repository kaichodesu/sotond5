#include "mainsreq.h"
//PWM-----------------------------------------------------

int step;

void init_PWM(void)
{
	DDRD |= _BV(PD5);
	TCCR1A = _BV(COM1A0)
		 |_BV(WGM10);
	TCCR1B = _BV(WGM13)
		 | _BV(CS11);
	step = 10/((F_CPU)/(2*PRESCALER*FREQ));
}

void PWM(float mainsreq)
{
    OCR1A = (uint16_t) mainsreq/step;
}
//--------------------------------------------------------

