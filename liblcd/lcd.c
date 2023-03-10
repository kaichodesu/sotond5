/*  Author: Steve Gunn
 * Licence: This work is licensed under the Creative Commons Attribution License.
 *           View this license at http://creativecommons.org/about/licenses/
 */
 
#include "ili934x.h"
#include "graphics.h"
#include "lcd.h"

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
	write_data16(320);
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

void calibrate_graphics()
//  Calibration graphic 120*39px
//  Y offset 216px
{
	uint8_t x, y;
	write_cmd(COLUMN_ADDRESS_SET);
	write_data16(0);
	write_data16(240);
	write_cmd(PAGE_ADDRESS_SET);
	write_data16(216);
	write_data16(294);
	write_cmd(MEMORY_WRITE);
	for(y = 0; y <= 38; y++){
		for(x = 0; x <= 119; x++){
			write_data16(pgm_read_word(&bg1_3[x+y*120]));
			write_data16(pgm_read_word(&bg1_3[x+y*120]));
		}
		for(x = 0; x <= 119; x++){
			write_data16(pgm_read_word(&bg1_3[x+y*120]));
			write_data16(pgm_read_word(&bg1_3[x+y*120]));
		}
	}
}

