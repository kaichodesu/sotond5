/*  Author: Steve Gunn
 * Licence: This work is licensed under the Creative Commons Attribution License.
 *           View this license at http://creativecommons.org/about/licenses/
 */
 
#include "ili934x.h"
#include "graphics.h"
#include "fonts.h"
#include "lcd.h"
#include <stdbool.h>

lcd display = {LCDWIDTH, LCDHEIGHT, North, 0, 0, 0x20E4, 0xFF99};

void init_lcd()
{
	/* Disable JTAG in software, so that it does not interfere with Port C  */
	/* It will be re-enabled after a power cycle if the JTAGEN fuse is set. */
	MCUCR |= (1<<JTD);
	MCUCR |= (1<<JTD);
	
	/* Configure ports */
	CTRL_DDR = 0x7F;
	// PIN 7 on the control port is an input.
	DATA_DDR = 0xFF;
	
	init_display_controller();
}

void set_orientation(orientation o)
{
	display.orient = o;
	write_cmd(MEMORY_ACCESS_CONTROL);
	if (o==North) { 
		display.width = LCDWIDTH;
		display.height = LCDHEIGHT;
		write_data(0x48);
	}
	else if (o==West) {
		display.width = LCDHEIGHT;
		display.height = LCDWIDTH;
		write_data(0xE8);
	}
	else if (o==South) {
		display.width = LCDWIDTH;
		display.height = LCDHEIGHT;
		write_data(0x88);
	}
	else if (o==East) {
		display.width = LCDHEIGHT;
		display.height = LCDWIDTH;
		write_data(0x28);
	}
	write_cmd(COLUMN_ADDRESS_SET);
	write_data16(0);
	write_data16(display.width-1);
	write_cmd(PAGE_ADDRESS_SET);
	write_data16(0);
	write_data16(display.height-1);
}

void init_graphics()
{
	uint16_t x, y;
	write_cmd(COLUMN_ADDRESS_SET);
	write_data16(0);
	write_data16(240);
	write_cmd(PAGE_ADDRESS_SET);
	write_data16(0);
	write_data16(160);
	write_cmd(MEMORY_WRITE);
	for(y = 0; y <= 79; y++){
		for(x = 0; x <= 119; x++){
			write_data16(pgm_read_word(&bg1_1[x+y*120]));
			write_data16(pgm_read_word(&bg1_1[x+y*120]));
		}
		for(x = 0; x <= 119; x++){
			write_data16(pgm_read_word(&bg1_1[x+y*120]));
			write_data16(pgm_read_word(&bg1_1[x+y*120]));
		}
	}
	write_cmd(COLUMN_ADDRESS_SET);
	write_data16(0);
	write_data16(240);
	write_cmd(PAGE_ADDRESS_SET);
	write_data16(160);
	write_data16(320);
	write_cmd(MEMORY_WRITE);
	for(y = 0; y <= 79; y++){
		for(x = 0; x <= 119; x++){
			write_data16(pgm_read_word(&bg1_2[x+y*120]));
			write_data16(pgm_read_word(&bg1_2[x+y*120]));
		}
		for(x = 0; x <= 119; x++){
			write_data16(pgm_read_word(&bg1_2[x+y*120]));
			write_data16(pgm_read_word(&bg1_2[x+y*120]));
		}
	}
}

//  Three Digits, digit 1 = kW
//  Digit 2 = 100s of W
//  Digit 3 = 10s of W
//  Digit 1 Anchor (19, 102)
//  Digit 2 Anchor (55, 102)
//  Digit 3 Anchor (80, 102)  (Multiply by 2 for display)
//  Each Digit is 21 x 37, Digit texture is 370 tall, starting at 9.
void pwr_kw(uint8_t digit){
	if(digit >= 3)
		digit = 0;
	uint16_t x, y;
	write_cmd(COLUMN_ADDRESS_SET);
	write_data16(38);
	write_data16(79);
	write_cmd(PAGE_ADDRESS_SET);
	write_data16(204);
	write_data16(277);
	write_cmd(MEMORY_WRITE);
	for(y = 0; y <= 36; y++){
		for(x = 0; x <= 20; x++){
			write_data16(pgm_read_word(&digit1[(2-digit)*777+x+y*21]));
			write_data16(pgm_read_word(&digit1[(2-digit)*777+x+y*21]));
		}
		for(x = 0; x <= 20; x++){
			write_data16(pgm_read_word(&digit1[(2-digit)*777+x+y*21]));
			write_data16(pgm_read_word(&digit1[(2-digit)*777+x+y*21]));
		}
	}
}

void pwr_100(uint8_t digit){
	if(digit >= 10)
		digit = 0;
	uint16_t x, y;
	write_cmd(COLUMN_ADDRESS_SET);
	write_data16(110);
	write_data16(151);
	write_cmd(PAGE_ADDRESS_SET);
	write_data16(204);
	write_data16(277);
	write_cmd(MEMORY_WRITE);
	for(y = 0; y <= 36; y++){
		for(x = 0; x <= 20; x++){
			write_data16(pgm_read_word(&digit2[(9-digit)*777+x+y*21]));
			write_data16(pgm_read_word(&digit2[(9-digit)*777+x+y*21]));
		}
		for(x = 0; x <= 20; x++){
			write_data16(pgm_read_word(&digit2[(9-digit)*777+x+y*21]));
			write_data16(pgm_read_word(&digit2[(9-digit)*777+x+y*21]));
		}
	}
}

void pwr_10(uint8_t digit){
	if(digit >= 10)
		digit = 0;
	uint16_t x, y;
	write_cmd(COLUMN_ADDRESS_SET);
	write_data16(160);
	write_data16(201);
	write_cmd(PAGE_ADDRESS_SET);
	write_data16(204);
	write_data16(277);
	write_cmd(MEMORY_WRITE);
	for(y = 0; y <= 36; y++){
		for(x = 0; x <= 20; x++){
			write_data16(pgm_read_word(&d3[(9-digit)*777+x+y*21]));
			write_data16(pgm_read_word(&d3[(9-digit)*777+x+y*21]));
		}
		for(x = 0; x <= 20; x++){
			write_data16(pgm_read_word(&d3[(9-digit)*777+x+y*21]));
			write_data16(pgm_read_word(&d3[(9-digit)*777+x+y*21]));
		}
	}
}

void bat_pwr(bool state){
	//  14px wide, 25px tall
	//  Anchoring to coordinate (106, 28)
	uint16_t x, y;
	write_cmd(COLUMN_ADDRESS_SET);
	write_data16(106);
	write_data16(133);
	write_cmd(PAGE_ADDRESS_SET);
	write_data16(28);
	write_data16(77);
	write_cmd(MEMORY_WRITE);
	if(state){
		for(y = 0; y <= 24; y++){
			for(x = 0; x <= 13; x++){
				write_data16(pgm_read_word_near(&BATCHR[x+y*14]));
				write_data16(pgm_read_word_near(&BATCHR[x+y*14]));
			}
			for(x = 0; x <= 13; x++){
				write_data16(pgm_read_word_near(&BATCHR[x+y*14]));
				write_data16(pgm_read_word_near(&BATCHR[x+y*14]));
			}
		}
	}
	else {
		for(y = 0; y <= 24; y++){
			for(x = 0; x <= 13; x++){
				write_data16(pgm_read_word_near(&BATDRN[x+y*14]));
				write_data16(pgm_read_word_near(&BATDRN[x+y*14]));
			}
			for(x = 0; x <= 13; x++){
				write_data16(pgm_read_word_near(&BATDRN[x+y*14]));
				write_data16(pgm_read_word_near(&BATDRN[x+y*14]));
			}
		}
	}
}

