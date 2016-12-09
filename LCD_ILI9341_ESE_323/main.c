/*
 * LCD_ILI9341_ESE_323.c
 *
 * Created: 11/29/2016 2:21:02 PM
 * Author : radrajith
 */ 


//for using printf, go to device programming- toolchain- general check  "Use vprintf library(-WI,-u,vfprintf)"
// go to miscellaneous tab and add "-Wl,-lprintf_flt"		//without quotes

#include <avr/io.h>
#include "ili9341.h"
#include "gfx.h"
#include "adc.h"
#include "snake.h"
#include <avr/interrupt.h>
# define F_CPU 1000000UL 
void rotate(){
	setRotation(2);
}
void readADC(){
	adc_init(POS_ADC0, NEG_ADC1);		//the adc used for pos and neg are passed in
	double voltage = adc_get();
	char value[5];
	sprintf(value, "%.3f", voltage);
	gfx_setCursor(20,160);
	gfx_print(value);
	double voltage1 = voltage/4095;
	//voltage1 = (voltage1)/32;
	gfx_setCursor(20,180);
	sprintf(value, "%.3f", voltage1);
	gfx_println(value);
	//return value;
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
	setRotation(3);
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
	
	//readADC();
	//gfx_printInt(34);
	//gfx_println("its working");
	//gfx_println();
	
	while(1)
	{
		/*
		if((PORTD_IN & PIN2_bm)){
			startupScreen();
		}
		else{
			clear(ILI9341_BLACK);
		}
		*/
		readADC();
		//snake_update(1);
		_delay_ms(10000);
		//Snake_display();
	}
}
