#ifndef __LIB_ADC0_H__
#define __LIB_ADC0_H__

#include "adc_config.h"


void lib_adc0_init();

uint16_t lib_adc0_get(uint8_t chn);


#endif