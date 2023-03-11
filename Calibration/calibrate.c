#include "calibrate.h"

//In the main program we initialise the ADC
//Select the PIN we want (busv, busi, wind, pv) and send it to the channel_adc function
//We do this for all the analogue inputs
void init_adc(void)
{
    ADMUX = 0;
    ADCSRA = _BV(ADEN) | 6;
    
    //ADCSRA = 0x86;
    
    //ADCSRA |=_BV(ADPS2) |_BV(ADPS1);
    //ADMUX |= 0x00;
    //ADCSRA |=_BV(ADSC);
    //ADCSRA |=_BV(ADEN);
}
void cannel_adc(uint8_t c)
{
    ADMUX |= c;
}

uint16_t read_adc(void)
{
    ADCSRA|= _BV(ADSC);
    while(ADCSRA &= _BV(ADSC));
    return ADC
}
//concatenate strings
void displayBusV()
{
    uint16_t result;
    float voltage;
    char str1[100] = "BusV: ";
    result = read_adc();
    voltage = (3.3*result)/1024.0;
    char val[MAX];
    gcvt(voltage, 6, val);
    char str_res[100];
    int i = 0, j = 0;
    while (str1[i] != '\0') {
        str_res[j] = str1[i];
        i++;
        j++;
    }
    i = 0;
    while (val[i] != '\0') {
        str3[j] = val[i];
        i++;
        j++;
    }
    str3[j] = '\0';
    display_string(str3);
}

void displayBusI()
{
    uint16_t result;
    float current;
    char str1[100] = "  BusI: ";
    result = read_adc();
    current = (3.3*result)/1024.0;
    char val[MAX];
    gcvt(current, 6, val);
    char str_res[100];
    int i = 0, j = 0;
    while (str1[i] != '\0') {
        str_res[j] = str1[i];
        i++;
        j++;
    }
    i = 0;
    while (val[i] != '\0') {
        str3[j] = val[i];
        i++;
        j++;
    }
    str3[j] = '\0';
    display_string(str3);
}

void displayWind()
{
    uint16_t result;
    float wind;
    char str1[100] = "  Wind: ";
    result = read_adc();
    wind = (3.3*result)/1024.0;
    char val[MAX];
    gcvt(wind, 6, val);
    char str_res[100];
    int i = 0, j = 0;
    while (str1[i] != '\0') {
        str_res[j] = str1[i];
        i++;
        j++;
    }
    i = 0;
    while (val[i] != '\0') {
        str3[j] = val[i];
        i++;
        j++;
    }
    str3[j] = '\0';
    display_string(str3);
}

void displayPV()
{
    uint16_t result;
    float pv;
    char str1[100] = "  PV: ";
    result = read_adc();
    pv = (3.3*result)/1024.0;
    char val[MAX];
    gcvt(pv, 6, val);
    char str_res[100];
    int i = 0, j = 0;
    while (str1[i] != '\0') {
        str_res[j] = str1[i];
        i++;
        j++;
    }
    i = 0;
    while (val[i] != '\0') {
        str3[j] = val[i];
        i++;
        j++;
    }
    str3[j] = '\0';
    display_string(str3);
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
