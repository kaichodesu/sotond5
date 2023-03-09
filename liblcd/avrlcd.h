/*  Author: Steve Gunn
 * Licence: This work is licensed under the Creative Commons Attribution License.
 *           View this license at http://creativecommons.org/about/licenses/
 */
 
#include <avr/io.h>


#define CTRL_PORT	PORTC
#define CTRL_DDR	DDRC
#define CTRL_PIN	PINC
#define DATA_PORT	PORTB
#define DATA_DDR	DDRB
#define DATA_PIN	PINB

#define CS			0	/* Active low chip select enable */
#define BLC			1	/* Active High back light control */
#define RESET		2
#define WR			3
#define RS			4
#define RD			5
#define VSYNC		6
#define FMARK		7

#define CS_lo()		CTRL_PORT &= ~_BV(CS)
#define CS_hi()		CTRL_PORT |= _BV(CS)
#define BLC_lo()	CTRL_PORT &= ~_BV(BLC)
#define BLC_hi()	CTRL_PORT |= _BV(BLC)
#define RESET_lo()	CTRL_PORT &= ~_BV(RESET)
#define RESET_hi()	CTRL_PORT |= _BV(RESET)
#define WR_lo()		CTRL_PORT &= ~_BV(WR)
#define WR_hi()		CTRL_PORT |= _BV(WR)
#define RS_lo()		CTRL_PORT &= ~_BV(RS)
#define RS_hi()		CTRL_PORT |= _BV(RS)
#define RD_lo()		CTRL_PORT &= ~_BV(RD)
#define RD_hi()		CTRL_PORT |= _BV(RD)
#define VSYNC_lo()	CTRL_PORT &= ~_BV(VSYNC)
#define VSYNC_hi()	CTRL_PORT |= _BV(VSYNC)
#define WRITE(x)	DATA_PORT = (x)

