#include "calibrate.h"

//In the main program we initialise the ADC
//Select the PIN we want (busv, busi, wind, pv) and send it to the channel_adc function
//We do this for all the analogue inputs
//Then we call the displayAnalogueInput function and display the desired value
void init_adc(void)
{
    
    ADCSRA |=_BV(ADPS2) |_BV(ADPS1);
    ADMUX |= 0x00;
    ADCSRA |=_BV(ADSC);
    ADCSRA |=_BV(ADEN);
}
void cannel_adc(uint8_t c)
{
    ADMUX |= c;
/*
    if(c==1)
    {
        ADMUX |= 0x08;
    }
    else if(c==2)
    {
        ADMUX |= 0x10;
    }
    else if(c==3)
    {
        ADMUX |= 0x20;
    }
    else if(c==4)
    {
        ADMUX |= 0x40;
    }
*/
    
}

uint16_t read_adc(void)
{
    
    ADCSRA|= _BV(ADSC);
    while(ADCSRA &= _BV(ADSC));
    return ADC
}
//Problem to figure out: since the display string function only writes to a single position on the display, the values will overwrite each other, therefore need to shift the position after we write each analogue input value
void displayAnalogueInput()
{
    uint16_t result;
    float voltage;
    result = read_adc();
    voltage = (3.3*result)/1024.0;
    char val[MAX];
    gcvt(voltage, 6, val);
    displayString(val);
}

void digital()
{
    int lc1 = PINA & _BV(0);
    int lc2 = PINA & _BV(1);
    int lc3 = PINA & _BV(2);
    if(lc1==1)
    {
        rectangle rectangle1 = {20,60,227,250};
        fill_rectangle(rectangle1,GREEN);
    }
    else if(lc1==0)
    {
        rectangle cover1 = {20,60,227,250};
        fill_rectangle(cover1,BLACK);
    }
    if(lc2==1)
    {
        rectangle rectangle2 = {100,140,227,250};
        fill_rectangle(rectangle2,GREEN);
    }
    else if(lc2==0)
    {
        rectangle cover2 = {100,140,227,250};
        fill_rectangle(cover2,BLACK);
    }
    if(lc3==1)
    {
        rectangle rectangle3 = {180,220,227,250};
        fill_rectangle(rectangle3,GREEN);
    }
    else if(lc3==0)
    {
        rectangle cover3 = {180,220,227,250};
        fill_rectangle(cover3,BLACK);
    }
}
