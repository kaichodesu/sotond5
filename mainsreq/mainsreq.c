#include "mainsreq.h"
//PWM-----------------------------------------------------
void init_PWM(void)
{
	DDRD |= _BV(PD5);
	TCCR1A = _BV(COM1A0)
		 |_BV(WGM10);
	TCCR1B = _BV(WGM13)
		 | _BV(CS11);
}

void PWM(uint16_t frequency, uint16_t duty_cycle)
{
    OCR1A = (uint16_t) duty_cycle;
}
//--------------------------------------------------------

