#include <adc.h>


unsigned int gainFactor = 8;
void adc_init(char pos, char neg){
	ADCA_CTRLA |= (1<<ADC_ENABLE_bp)|(1<<ADC_START_bp);		//start and enable ADC
	ADCA_REFCTRL |= (0<<ADC_REFSEL0_bp)|(0<<ADC_REFSEL1_bp)|(0<<ADC_REFSEL2_bp)|(1<<ADC_BANDGAP_bp);	//set to use internal 1v reference and turn on bandgap reference
	adc_pinSelect(pos,neg);
	//implement event interrupt
}
void adc_pinSelect(char pos,char neg){
	
	int c = neg[strlen(neg)-1];
	if(c > 52){
		ADCA_CH0_CTRL = (ADC_CH_GAIN_32X_gc|ADC_CH_INPUTMODE_DIFFWGAINH_gc|ADC_CH_START_bm);
	}
	else{
		ADCA_CH0_CTRL = (ADC_CH_GAIN_32X_gc|ADC_CH_INPUTMODE_DIFFWGAINL_gc|ADC_CH_START_bm);
	}
	ADCA_CH0_MUXCTRL = (pos|neg);		//
}
void adc_runContinuous(){
	ADCA_CTRLA |= (1<<ADC_FREERUN_bp);
}
void adc_singleSample(){
	ADCA_CTRLA &= (0<<ADC_FREERUN_bp);
}
void gainAdjust(int volt){
	
}
int adc_get(){
	adc_singleSample();
	int voltage = ADCA_TEMP;
	if(voltage >=0.96){
		gainAdjust(voltage);
		adc_get();
	}
	else if(voltage<=0.52){
		gainAdjust(voltage);
		adc_get();
	}
	return voltage
}