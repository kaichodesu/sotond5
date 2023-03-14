#include "mainsreq.h"
//PWM-----------------------------------------------------

uint16_t step;

void init_PWM(void)
{
	DDRD |= _BV(PD5);
	TCCR1A = _BV(COM1A0)
		 |_BV(WGM10);
	TCCR1B = _BV(WGM13)
		 | _BV(CS11);
	step = 10/((F_CPU)/(2*PRESCALER*FREQ));
}

void pwm(float mainsreq)
{
	cli();
    OCR1A = (uint16_t) mainsreq/step;
	sei();
}
//--------------------------------------------------------

