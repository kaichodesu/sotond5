#ifndef pwm_header_h
#define pwm_header_h
#include <stdlib.h>
#include <avr/io.h>
#include <util/delay.h>
#define FREQ 47000
#define PRESCALER 1UL

void init_PWM(void);
void pwm(float mainsreq);

#endif /* pwm_header_h */
