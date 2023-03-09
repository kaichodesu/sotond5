#include <stdlib.h>
#include <stdio.h>
#include <avr/io.h>
#include "ili934x.h"
#include "font.h"
#include "graphics.h"
#include "lcd.h"
#define MAX 100
#ifndef calibrate_h
#define calibrate_h
void init_adc(void);
void cannel_adc(uint8_t c);
uint16_t read_adc(void);
void displayAnalogueInput();
void digital();

#endif /* calibrate_h */
