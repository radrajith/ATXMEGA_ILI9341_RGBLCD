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
void rotate(){
	setRotation(2);
}
void readADC(){
	adc_init(POS_ADC0, NEG_ADC1);		//the adc used for pos and neg are passed in
	int current = adc_get();
}

int main(void)
{
	begin();					//initialize spi driver
	setRotation(3);
	clear(ILI9341_RED);
	gfx_setTextColor(ILI9341_PURPLE);
	gfx_setCursor(20, 20);
	gfx_setTextSize(5);
	gfx_setBgColor(ILI9341_RED);
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
	gfx_println("its working");
	//################Finish building gfx_println function###################
	
	//gfx_write('R');
	while(1)
	{
		
		//_delay_ms(1000);
		//TODO:://write to data register Please write your application code
		//clear(ILI9341_BLUEVIOLET);
		//gfx_write('2');
		//adc_init(POS_ADC0, NEG_ADC1);		//the adc used for pos and neg are passed in
		//gfx_write(adc_get());
		_delay_ms(10);
		
		//clear(ILI9341_BROWN);
		//clear(ILI9341_DEEPPINK);
		//clear(ILI9341_GREEN);
		//_delay_ms(100);
	}
}
