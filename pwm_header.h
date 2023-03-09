#ifndef pwm_header_h
#define pwm_header_h
#include <stdlib.h>
#include <avr/io.h>
#define FREQ 47000
#define TONE_PRESCALER 1UL

void init_PWM(void);
void PWM(uint16_t FREQ, uint16_t duty_cycle);

#endif /* pwm_header_h */
