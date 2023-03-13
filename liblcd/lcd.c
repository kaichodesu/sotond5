/*  Author: kaicho (ys6g21)
 */
#include <avr/io.h>
#include "ili934x.h"
#include "graphics.h"
#include "fonts.h"
#include "lcd.h"
#include <stdbool.h>
#define __ELPM_word_classic__(addr)     \
(__extension__({                        \
    uint32_t __addr32 = (uint32_t)(addr); \
    uint16_t __result;                  \
    __asm__ __volatile__                \
    (                                   \
        "out %2, %C1"   "\n\t"          \
        "mov r31, %B1"  "\n\t"          \
        "mov r30, %A1"  "\n\t"          \
        "elpm"          "\n\t"          \
        "mov %A0, r0"   "\n\t"          \
        "in r0, %2"     "\n\t"          \
        "adiw r30, 1"   "\n\t"          \
        "adc r0, __zero_reg__" "\n\t"   \
        "out %2, r0"    "\n\t"          \
        "elpm"          "\n\t"          \
        "mov %B0, r0"   "\n\t"          \
        : "=r" (__result)               \
        : "r" (__addr32),               \
          "I" (_SFR_IO_ADDR(RAMPZ))     \
        : "r0", "r30", "r31"            \
    );                                  \
    __result;                           \
}))
#define __ELPM_word(addr)   __ELPM_word_classic__(addr)
#define pgm_read_word_far(address_long)  __ELPM_word((uint32_t)(address_long))
#define RAMPZ _SFR_IO8(0x3B)
#define pgm_get_far_address(var)                          \
({                                                    \
	uint_farptr_t tmp;                                \
                                                      \
	__asm__ __volatile__(                             \
                                                      \
			"ldi	%A0, lo8(%1)"           "\n\t"    \
			"ldi	%B0, hi8(%1)"           "\n\t"    \
			"ldi	%C0, hh8(%1)"           "\n\t"    \
			"clr	%D0"                    "\n\t"    \
		:                                             \
			"=d" (tmp)                                \
		:                                             \
			"p"  (&(var))                             \
	);                                                \
	tmp;                                              \
})
#include "pgmspace.h"
//  Dammit AVR why dont you include standard library functions.
//  The 1284P supports LPM and ELPM but its not in iom1284p.h ;(


//  Three Digits, digit 1 = kW
//  Digit 2 = 100s of W
//  Digit 3 = 10s of W
//  Digit 1 Anchor (19, 102)
//  Digit 2 Anchor (55, 102)
//  Digit 3 Anchor (80, 102)  (Multiply by 2 for display)
//  Each Digit is 21 x 37, Digit texture is 370 tall, starting at 9.
void pwr_kw(uint8_t digit){
	if(digit >= 3)
		digit = 2;
	uint16_t x, y;
	uint32_t address = pgm_get_far_address(digit1);
	//  pgm_get_far_address will throw a r26 undefined error unless the value has been assigned at compile time
	write_cmd(COLUMN_ADDRESS_SET);
	write_data16(38);
	write_data16(79);
	write_cmd(PAGE_ADDRESS_SET);
	write_data16(204);
	write_data16(277);
	write_cmd(MEMORY_WRITE);
	for(y = 0; y <= 36; y++){
		for(x = 0; x <= 20; x++){
			write_data16( pgm_read_word_far(address + 2*((9-digit)*777+x+y*21)));
			write_data16( pgm_read_word_far(address + 2*((9-digit)*777+x+y*21)));
		}
		for(x = 0; x <= 20; x++){
			write_data16( pgm_read_word_far(address + 2*((9-digit)*777+x+y*21)));
			write_data16( pgm_read_word_far(address + 2*((9-digit)*777+x+y*21)));
		}
	}
}

void pwr_100(uint8_t digit){
	if(digit >= 10)
		digit = 9;
	uint16_t x, y;
	uint32_t address = pgm_get_far_address(digit2);
	write_cmd(COLUMN_ADDRESS_SET);
	write_data16(110);
	write_data16(151);
	write_cmd(PAGE_ADDRESS_SET);
	write_data16(204);
	write_data16(277);
	write_cmd(MEMORY_WRITE);
	for(y = 0; y <= 36; y++){
		for(x = 0; x <= 20; x++){
			write_data16( pgm_read_word_far(address + 2*((9-digit)*777+x+y*21)));
			write_data16( pgm_read_word_far(address + 2*((9-digit)*777+x+y*21)));
		}
		for(x = 0; x <= 20; x++){
			write_data16( pgm_read_word_far(address + 2*((9-digit)*777+x+y*21)));
			write_data16( pgm_read_word_far(address + 2*((9-digit)*777+x+y*21)));
		}
	}
}

void pwr_10(uint8_t digit){
	if(digit >= 10)
		digit = 9;
	uint16_t x, y;
	uint32_t address = pgm_get_far_address(d3);
	write_cmd(COLUMN_ADDRESS_SET);
	write_data16(160);
	write_data16(201);
	write_cmd(PAGE_ADDRESS_SET);
	write_data16(204);
	write_data16(277);
	write_cmd(MEMORY_WRITE);
	for(y = 0; y <= 36; y++){
		for(x = 0; x <= 20; x++){
			write_data16( pgm_read_word_far(address + 2*((9-digit)*777+x+y*21)));
			write_data16( pgm_read_word_far(address + 2*((9-digit)*777+x+y*21)));
		}
		for(x = 0; x <= 20; x++){
			write_data16( pgm_read_word_far(address + 2*((9-digit)*777+x+y*21)));
			write_data16( pgm_read_word_far(address + 2*((9-digit)*777+x+y*21)));
		}
	}
}

void bat_pwr(bool state){
	//  14px wide, 25px tall
	//  Anchoring to coordinate (106, 28)
	uint16_t x, y;
	uint32_t addresschr = pgm_get_far_address(BATCHR);
	uint32_t addressdrn = pgm_get_far_address(BATDRN);
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
				write_data16(pgm_read_word_far(addresschr + 2*(x+y*14)));
				write_data16(pgm_read_word_far(addresschr + 2*(x+y*14)));
			}
			for(x = 0; x <= 13; x++){
				write_data16(pgm_read_word_far(addresschr + 2*(x+y*14)));
				write_data16(pgm_read_word_far(addresschr + 2*(x+y*14)));
			}
		}
	}
	else {
		for(y = 0; y <= 24; y++){
			for(x = 0; x <= 13; x++){
				write_data16(pgm_read_word_far(addressdrn + 2*(x+y*14)));
				write_data16(pgm_read_word_far(addressdrn + 2*(x+y*14)));
			}
			for(x = 0; x <= 13; x++){
				write_data16(pgm_read_word_far(addressdrn + 2*(x+y*14)));
				write_data16(pgm_read_word_far(addressdrn + 2*(x+y*14)));
			}
		}
	}
}

void kamimashita()
{
	// (40,149)
	uint16_t x, y;
	uint32_t address = pgm_get_far_address(hachikuji);
	write_cmd(COLUMN_ADDRESS_SET);
	write_data16(40);
	write_data16(199);
	write_cmd(PAGE_ADDRESS_SET);
	write_data16(149);
	write_data16(238);
	write_cmd(MEMORY_WRITE);
	for(y = 0; y <= 89; y++){
		for(x = 0; x <= 159; x++){
			write_data16(pgm_read_word_far(address + 2*(x+y*160)));
		}
	}
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
			write_data16( pgm_read_word( &(bg1_1[x+y*120])));
			write_data16( pgm_read_word( &(bg1_1[x+y*120])));
		}
		for(x = 0; x <= 119; x++){
			write_data16( pgm_read_word( &(bg1_1[x+y*120])));
			write_data16( pgm_read_word( &(bg1_1[x+y*120])));
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
			write_data16( pgm_read_word( &(bg1_2[x+y*120])));
			write_data16( pgm_read_word( &(bg1_2[x+y*120])));
		}
		for(x = 0; x <= 119; x++){
			write_data16( pgm_read_word( &(bg1_2[x+y*120])));
			write_data16( pgm_read_word( &(bg1_2[x+y*120])));
		}
	}
}

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

void fill_rectangle(rectangle r, uint16_t col)
{
	uint16_t x, y;
	write_cmd(COLUMN_ADDRESS_SET);
	write_data16(r.left);
	write_data16(r.right);
	write_cmd(PAGE_ADDRESS_SET);
	write_data16(r.top);
	write_data16(r.bottom);
	write_cmd(MEMORY_WRITE);
	for(x=r.left; x<=r.right; x++)
		for(y=r.top; y<=r.bottom; y++)
			write_data16(col);
}

void LC1_green(void)
{
	rectangle LC1 = {24,28,18,22};
	fill_rectangle(LC1,GREEN);
}

void LC1_red(void)
{
	rectangle LC1 = {24,28,18,22};
	fill_rectangle(LC1,RED);
}

void LC2_green(void)
{
	rectangle LC2 = {24,28,50,54};
	fill_rectangle(LC2,GREEN);
}

void LC2_red(void)
{
	rectangle LC2 = {24,28,50,54};
	fill_rectangle(LC2,RED);
}

void LC3_green(void)
{
	rectangle LC3 = {24,28,80,84};
	fill_rectangle(LC3,GREEN);
}

void LC3_red(void)
{
	rectangle LC3 = {24,28,80,84};
	fill_rectangle(LC3,RED);
}


void LS1_green(void)
{
	rectangle LC1 = {212,216,18,22};
	fill_rectangle(LC1,GREEN);
}

void LS1_red(void)
{
	rectangle LC1 = {212,216,18,22};
	fill_rectangle(LC1,RED);
}

void LS2_green(void)
{
	rectangle LC2 = {212,216,50,54};
	fill_rectangle(LC2,GREEN);
}

void LS2_red(void)
{
	rectangle LC2 = {212,216,50,54};
	fill_rectangle(LC2,RED);
}

void LS3_green(void)
{
	rectangle LC3 = {212,216,80,84};
	fill_rectangle(LC3,GREEN);
}

void LS3_red(void)
{
	rectangle LC3 = {212,216,80,84};
	fill_rectangle(LC3,RED);
}



void pwr_bar_wind(uint8_t pwr)
{

	rectangle blue = {90,91,173,182};
	rectangle white = {91,92,173,182};

	if(pwr > 94)
		pwr = 94;

	blue.right = 90 + pwr;

	white.left = blue.right;
	white.right = 184;

	fill_rectangle(blue, 0x3E9F);
	fill_rectangle(white, WHITE);
}

void pwr_bar_sun(uint8_t pwr)
{

	rectangle blue = {90,91,121,130};
	rectangle white = {91,92,121,130};

	if(pwr > 94)
		pwr = 94;

	blue.right = 90 + pwr ;

	white.left = blue.right;
	white.right = 184;

	fill_rectangle(blue, 0x3E9F);
	fill_rectangle(white, WHITE);
}

