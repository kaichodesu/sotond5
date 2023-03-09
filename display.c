#include "H:\D5\software\liblcd.tar\liblcd\lcdlib\lcd.h"  
#include <avr/io.h>
#include <util/delay.h>
#include <math.h>

void drawL();
void drawOne();
void drawTwo();
void drawThree();
void Cover1();
void Cover2();
void Cover3();
void powerBar();
void powerBar_vertical();
void batteryBar();
void drawJ();
void drawSun();
int main()
{
	init_lcd();
	clear_screen();
	
	drawSun();
	
		drawL();
	powerBar();
	batteryBar();
	//display_string("   \n\n\n           THE SCREEN WORKS!");
	
	//drawL();
	//drawOne();
	//drawTwo();
	//drawThree();
	//display_string2("           F U STEVE");
	/*
	while(1)
	{
		
		
		drawOne();
		drawTwo();
		drawThree();
		
		_delay_ms(6000);
		
		Cover2();
		
		_delay_ms(6000);
		
		Cover1();
		drawTwo();
		
		_delay_ms(6000);
		Cover3();
		drawOne();
		_delay_ms(6000);
		
		
		
		
	}
	*/
	
		
	
	return 0;
}

void batteryBar()
{
	
	rectangle rectangleGreen = {20,60,227,250};
	fill_rectangle(rectangleGreen,GREEN);
	rectangle rectangleCyan = {60,100,227,250};
	fill_rectangle(rectangleCyan,CYAN);
	rectangle rectangleYellow = {100,140,227,250};
	fill_rectangle(rectangleYellow,YELLOW); 
	rectangle rectangleMagenta = {140,180,227,250};
	fill_rectangle(rectangleMagenta,MAGENTA);
	rectangle rectangleRed = {180,220,227,250};
	fill_rectangle(rectangleRed,RED);
}

void powerBar()
{
	rectangle rectangleGreen = {20,60,267,290};
	fill_rectangle(rectangleGreen,GREEN);
	rectangle rectangleCyan = {60,100,267,290};
	fill_rectangle(rectangleCyan,CYAN);
	rectangle rectangleYellow = {100,140,267,290};
	fill_rectangle(rectangleYellow,YELLOW); 
	rectangle rectangleMagenta = {140,180,267,290};
	fill_rectangle(rectangleMagenta,MAGENTA);
	rectangle rectangleRed = {180,220,267,290};
	fill_rectangle(rectangleRed,RED);
}

void powerBar_vertical()
{
	rectangle rectangleGreen = {100,140,260,300};
	fill_rectangle(rectangleGreen,GREEN);
	rectangle rectangleCyan = {100,140,220,260};
	fill_rectangle(rectangleCyan,CYAN);
	rectangle rectangleYellow = {100,140,180,220};
	fill_rectangle(rectangleYellow,YELLOW); 
	rectangle rectangleMagenta = {100,140,140,180};
	fill_rectangle(rectangleMagenta,MAGENTA);
	rectangle rectangleRed = {100,140,100,140};
	fill_rectangle(rectangleRed,RED);
}

void Cover1()
{
	rectangle cover = {70,95,30,80};
	fill_rectangle(cover,BLACK);
}

void Cover2()
{
	rectangle cover = {135,150,30,80};
	fill_rectangle(cover,BLACK);
}

void Cover3()
{
	rectangle cover = {190,205,30,80};
	fill_rectangle(cover,BLACK);
}

/*void CoverBarMains(power)
{
	power1;
	power2;
	power3;
	power4;
	rectangle r1 = {};
}
*/

void drawL()
{
	rectangle L1 = {20,25,30,75};
	rectangle L2 = {20,40,75,80};
	fill_rectangle(L1,GREEN);
	fill_rectangle(L2, GREEN);

	
}

void drawOne()
{
	rectangle O1 = {80,85,30,80};
	rectangle O2 = {75, 80,30,35};
	rectangle O3 = {70,95,75,80};
	fill_rectangle(O1, BLACK);
	fill_rectangle(O2, BLACK);
	fill_rectangle(O3, BLACK);
}

void drawTwo()
{
	rectangle two1 = { 135,145,30,35};
	rectangle two2 = {145,150,30,55};
	rectangle two3 = {135,145,55,60};
	rectangle two4 = {135,140,60,80};
	rectangle two5 = {135,150,75,80};
	
	//rectangle two2 = { 135,140,30,80};
	//rectangle two3 = { 140,150,75,80};
	fill_rectangle(two1, BLACK);
	fill_rectangle(two2, BLACK);
	fill_rectangle(two3, BLACK);
	fill_rectangle(two4, BLACK);
	fill_rectangle(two5, BLACK);
	
}

void drawThree()
{
	//rectangle three1 = { 160,175,30,35};
	//rectangle three2 = { 170,175,35,80};
	//rectangle three3 = { 160,170,57,62};
	//rectangle three4 = { 160,170,75,80};
	
	rectangle three1 = { 190,205,30,35};
	rectangle three2 = { 200,205,35,80};
	rectangle three3 = { 190,200,52,57};
	rectangle three4 = { 190,200,75,80};

	
	fill_rectangle(three1, BLACK);
	fill_rectangle(three2, BLACK);
	fill_rectangle(three3, BLACK);
	fill_rectangle(three4, BLACK);
	
}

void drawJ()
{
	rectangle J_top = { 40, 200, 30,70};
	rectangle J_body1 = {100,140,30,260};
	rectangle J_body2 = {60,140,230,260};
	rectangle J_body3 = {60,90,180,230};
	
	fill_rectangle(J_top, 0xEE5C);
	fill_rectangle(J_body1, 0xEE5C);
	fill_rectangle(J_body2,0xEE5C);
	fill_rectangle(J_body3, 0xEE5C);
	
}


void drawCircle() //unfilled circle
{
	double theta = -3.14;
	float radius  = 50; 
	double theta2 = 0;
	
	
	rectangle rect;
	
	for(theta; theta < 3.14; theta +=0.01)
	{
		rect.left = 120+ (radius - radius * cos(theta));
		rect.right = rect.left + 1; //rect.left + (radius * 2) - (2*radius* sin(theta)) ;
		rect.top = 160 - radius * sin(theta);
		rect.bottom =  rect.top + 1;
		fill_rectangle(rect, BLACK);
	}
	
}

void drawCircle2()
{
	double theta = -3.14;
	float radius  = 50; 
	double theta2 = 0;
	
	
	rectangle rect;
	
	for(theta; theta < 3.14; theta +=0.01)
	{
		rect.left = 120+ (radius - radius * cos(theta));
		rect.right = rect.left + 1; //rect.left + (radius * 2) - (2*radius* sin(theta)) ;
		rect.top = 160 - radius * sin(theta);
		rect.bottom =  rect.top + 1;
		fill_rectangle(rect, BLACK);
		radius -= 0.1;
	}
}

//need to draw numbers 0-9, ensure they have the same height and width. the numbers will be shifted corresponding to what they are affecting.
//alternatively can use the small text to print the value we are seeing.

//need to draw two waves for the wind symbol

//avr-gcc -mmcu=atmega644p -L../lcdlib -o test.elf test.c -llcd

//avr-objcopy -O ihex test.elf test.hex

//avrdude -c usbasp -p m644p -U flash:w:test.hex

