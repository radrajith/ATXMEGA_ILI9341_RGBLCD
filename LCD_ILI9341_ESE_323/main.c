/*
 * LCD_ILI9341_ESE_323.c
 *
 * Created: 11/29/2016 2:21:02 PM
 * Author : radrajith
 */ 

#include <avr/io.h>
#include "ili9341.h"
#include "gfx.h"

void rotate(){
	setRotation(2);
}

int main(void)
{
	begin();					//initialize spi driver
	clear(ILI9341_WHITE);
	gfx_setTextColor(ILI9341_PURPLE);
	gfx_setCursor(20, 20);
	gfx_setTextSize(5);
	gfx_setBgColor(ILI9341_WHITE);
	//clear(ILI9341_GOLD);		//clear the
	setRotation(3);				//change this between 0 and 3 depending on the orientation of the
	//gfx_print('hey');
	gfx_write('C');
	gfx_write('O');
	gfx_write('D');
	//gfx_write('E');
	gfx_write('E');
	gfx_write('D');
	gfx_write('\n');
	gfx_setTextSize(3);
	gfx_setTextColor(ILI9341_GREEN);
	gfx_setCursor(20, 80);
	gfx_write('B');
	gfx_write('Y');
	gfx_write(' ');
	gfx_write('R');
	gfx_write('A');
	gfx_write('J');
	gfx_write('I');
	gfx_write('T');
	gfx_write('H');
	gfx_setTextColor(ILI9341_DEEPPINK);
	gfx_setCursor(20,120);
	gfx_write('=');
	gfx_write(']');
	char *a = "WORKING";
	//printf()
	gfx_print(a);

	
	//gfx_write('R');
	while(1)
	{
		
		//_delay_ms(1000);
		//TODO:://write to data register Please write your application code
		//clear(ILI9341_BLUEVIOLET);
		//gfx_write('2');
		
		_delay_ms(10);
		
		//clear(ILI9341_BROWN);
		//clear(ILI9341_DEEPPINK);
		//clear(ILI9341_GREEN);
		//_delay_ms(100);
	}
}
