#include "lib_adc.h"



void lib_adc_init() {
    
       // ÷ÿ÷√
    adc_deinit();
    // ≈‰÷√÷˜∆µ
    adc_clock_config(ADC_ADCCK_PCLK2_DIV8);
    
#if USE_LIB_ADC_0
    lib_adc0_init();
#endif    
}