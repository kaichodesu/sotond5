#include "pwm_header.h"
//PWM-----------------------------------------------------
void init_PWM(void)
{
	DDR5 |= _BV(PD5);
	TCCR1A = _BV(COM1A0)
		 |_BV(WGM10);
	TCCR1B = _BV(WGM13)
		 | _BV(CS11);
}

void PWM(uint16_t FREQ, uint16_t duty_cycle)
{
    OC1RA = (uint16_t) (F_CPU)/(2*TONE_PRESCALER*FREQ);
}
//--------------------------------------------------------

