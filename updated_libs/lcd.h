/*  Author: Steve Gunn
 * Licence: This work is licensed under the Creative Commons Attribution License.
 *           View this license at http://creativecommons.org/about/licenses/
 */
 
#include <stdint.h>
#include <stdbool.h>

#define LCDWIDTH	240
#define LCDHEIGHT	320

/* Colour definitions RGB565 */
#define WHITE       0xFFFF
#define BLACK       0x0000
#define BLUE        0x001F      
#define GREEN       0x07E0      
#define CYAN        0x07FF      
#define RED         0xF800      
#define MAGENTA     0xF81F      
#define YELLOW      0xFFE0      

typedef enum {North, West, South, East} orientation;

typedef struct {
	uint16_t width, height;
	orientation orient;
	uint16_t x, y;
	uint16_t foreground, background;
} lcd;

typedef struct {
	uint16_t left, right;
	uint16_t top, bottom;
} rectangle;	

extern lcd display;
void fill_rectangle(rectangle r, uint16_t col);
void init_lcd();
void set_orientation(orientation o);
void init_graphics();
void bat_pwr(bool state);
void pwr_kw(uint8_t digit);
void pwr_10(uint8_t digit);
void pwr_100(uint8_t digit);
void LC1_green(void);
void LC1_red(void);
void LC2_green(void);
void LC2_red(void);
void LC3_green(void);
void LC3_red(void);
void pwr_bar_wind(uint8_t pwr);
void pwr_bar_sun(uint8_t pwr);
