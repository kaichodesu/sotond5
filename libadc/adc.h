#include <stdbool.h>

void init_timers(void);
void init_adc(void);
void calibrate_timer0(void);
void adts_disable(void);
void adts_enable(void);

extern volatile uint16_t adc_read;
extern volatile bool calibrating, adc_rdy, sync, adc_mux_rdy;
extern uint8_t TIMER0_TOP;
extern uint8_t phase_delay;
