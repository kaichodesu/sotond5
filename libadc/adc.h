void init_timer0(void);
void init_adc(void);
void calibrate_timer0(void);
void adts_disable(void);
void adts_enable(void);

extern volatile uint16_t adc_read;
