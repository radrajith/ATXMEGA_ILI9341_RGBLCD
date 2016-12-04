/*
 * LCD_ILI9341_ESE_323.c
 *
 * Created: 11/29/2016 2:21:02 PM
 * Author : radrajith
 */ 

#include <avr/io.h>
#include "ili9341.h"
#include "gfx.h"
#include "adc.h"
#include "snake.h"
# define F_CPU 1000000UL 
void rotate(){
	setRotation(2);
}
void readADC(){
	adc_init(POS_ADC0, NEG_ADC1);		//the adc used for pos and neg are passed in
	int current = adc_get();
}
void startupScreen(){
	int color = 0;
	int a = 0;
	int axis = 0;
	for(int i = 0; i<((TFTWIDTH-130)/2) ; i=i+5){
		if((a%2) == 0){
			color = ILI9341_WHITE;
		}
		else{
			color = ILI9341_BLACK;
		}
		a++;
		fillrect(i,i, (TFTWIDTH-(2*i)), (TFTHEIGHT-(2*i)), color);
		axis = i;
	}
	gfx_setCursor(axis+10, axis+10);
	gfx_setTextColor(ILI9341_RED);
	gfx_setTextSize(3);
	//setRotation(3);
	gfx_print("ESE 323");

	_delay_ms(15000);
}

int main(void)
{
	begin();					//initialize spi driver
	setRotation(1);
	clear(ILI9341_RED);
	//fillScreen();				//random background generator
	gfx_setTextColor(ILI9341_PURPLE);
	gfx_setCursor(20, 20);
	gfx_setTextSize(5);
	gfx_setBgColor(ILI9341_WHITE);
	//clear(ILI9341_GOLD);		//clear the
					//change this between 0 and 3 depending on the orientation of the
	//gfx_print('hey');
	gfx_print("CODED");
	//gfx_write('\n');
	
	gfx_setTextSize(3);
	gfx_setTextColor(ILI9341_GREEN);
	gfx_setCursor(20, 80);
	gfx_print("BY RAJITH");
	gfx_setTextColor(ILI9341_DEEPPINK);
	gfx_setCursor(20,120);
	gfx_print("=]");
	gfx_print("1.23 A");
	//gfx_printInt(34);
	gfx_println("its working");
	clear(ILI9341_BLACK);
	//fix printing any variable 
	//_delay_ms(5000);
	//snake_init();
	//################Finish building gfx_println function###################
	//gfx_write('R');
	drawPixel(50,50, ILI9341_BLACK);
	startupScreen();
	
	int b = 90;
	int a = 0;
	while(1)
	{
		//snake_run();
		//clear(ILI9341_WHITE);
		//_delay_ms(100000);
		//clear(ILI9341_GREEN);
		//clear(ILI9341_BLACK);
		/*
		clear(ILI9341_BLACK);
			drawHLine(0, getHeight()/2, getWidth(), ILI9341_BLUE);
			drawVLine(getWidth()/2, 0, getHeight(), ILI9341_BLUE);
		for (int i = 1; i < 318; i++)
		{
			int a;
			a =  119 + (sin(((i*1.13)*3.14) / 180) * 95);
			drawPixel(i , a,  ILI9341_CYAN);
		}
		clear(ILI9341_BLACK);
			drawHLine(0, getHeight()/2, getWidth(), ILI9341_BLUE);
			drawVLine(getWidth()/2, 0, getHeight(), ILI9341_BLUE);
		
		for (int i = 1; i < 318; i++)
		{
			int a;
			a =  119 + (cos(((i*1.13)*3.14) / 180) * 95);
			drawPixel(i , a,  ILI9341_CYAN);
		}
		
		*/
		//_delay_ms(1000);
	}
}
