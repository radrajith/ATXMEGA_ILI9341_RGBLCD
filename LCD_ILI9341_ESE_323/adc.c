#include "adc.h"


unsigned int gainFactor = 8;
#define gain1 ADC_CH_GAIN_8X_gc
#define gain2 ADC_CH_GAIN_16X_gc
#define gain3 ADC_CH_GAIN_32X_gc
#define gain4 ADC_CH_GAIN_64X_gc
int state = 1;

void adc_init(char pos, char neg){
	state = 3;
	ADCA_CH0_CTRL = (ADC_CH_GAIN_32X_gc|ADC_CH_INPUTMODE_DIFFWGAINL_gc|ADC_CH_START_bm);
	ADCA_CH0_MUXCTRL = (pos|neg);		//
	ADCA_CTRLA |= (1<<ADC_ENABLE_bp);	//start and enable ADC
	ADCA_PRESCALER = ADC_PRESCALER_DIV32_gc;
	//ADCA_CTRLB	|= ADC_convmode
	
	adc_pinSelect(pos,neg);
	//implement event interrupt
}
void adc_pinSelect(char pos,char neg){
	/*
	int c = neg[strlen(neg)-1];
	if(c > 52){
		ADCA_CH0_CTRL = (ADC_CH_GAIN_32X_gc|ADC_CH_INPUTMODE_DIFFWGAINH_gc|ADC_CH_START_bm);
	}
	else{
		ADCA_CH0_CTRL = (ADC_CH_GAIN_32X_gc|ADC_CH_INPUTMODE_DIFFWGAINL_gc|ADC_CH_START_bm);
	}
	*/
	
	
	
	//ADCA_CH0_CTRL = ADC_CH_INPUTMODE_DIFFWGAINL_gc;
}
void adc_runContinuous(){
	ADCA_CTRLA |= (1<<ADC_FREERUN_bp);
}
void adc_singleSample(){
	ADCA_CTRLA |= ADC_START_bm;
	//ADCA_CTRLA &= (0<<ADC_FREERUN_bp);
	_delay_ms(100);
}
void gainAdjust(int volt){
	
	int inc = 0;
	if(volt>0.96){	//0f5c
		state++;
		inc = 1;
	}
	else if(volt<0.48){	//07ae
		state--;
	}
	switch(state){
		case 1:
			ADCA_CH0_CTRL = (gain1);
			break;
		case 2:
			ADCA_CH0_CTRL = (gain2);
			break;
		case 3:
			ADCA_CH0_CTRL = (gain3);
			break;
		case 4:
			ADCA_CH0_CTRL = (gain4);	
			break;
		default:
			if(inc)
			{
				state = 1;
			}
			else
			{
				state = 4;
			}
	}
			
}
double calculate(double num){
	double volt;
	switch(state){
		case 1:
			volt = (num*100)/8;
			break;
		case 2:
			volt = (num*100)/16;
			break;
		case 3:
			volt = (num*100)/32;
			break;
		case 4:
			volt = (num*100)/64;
			break;	
	}
	return volt;
}

double adc_get(){
	adc_singleSample();
	double voltage = ADCA_CH0_RES;
	//gainAdjust(voltage);
	//voltage = ADCA_CH0_RES;
	//gfx_print(voltage);
	
	//return calculate(voltage);
	return voltage;
}
