//All the libraries and macros are defined in the main code
//--------------------------------------------------------
MainsReq = 10;
while(BusV>=BusVMAX)
{
	MainsReq = MainsReq - 0.1;
}
MainsReq = MainsReq + 0.1;
MainsMAX = (10/MainsReq)*BusI;
//--------------------------------------------------------

//PWM-----------------------------------------------------
void init_PWM(void)
{
	DDR5 |= _BV(PD5);
	TCCR1A = _BV(COM1A0)
		 |_BV(WGM10);
	TCCR1B = _BV(WGM13)
		 | _BV(CS11);
}

void PWM(uint16_t freq, float MainsReq)
{
    step = (uint16_t) 10/((F_CPU)/(2*TONE_PRESCALER*freq));
	OC1RA = MainsReq * (10/step);
}
//--------------------------------------------------------

