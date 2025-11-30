#ifndef __ADC_CONFIG_H__
#define __ADC_CONFIG_H__

#include "gd32f4xx.h"
#include "systick.h"

#define USE_LIB_ADC_0			0


#define LIB_ADC_CHN_ROUTINE     0
#define LIB_ADC_CHN_INSERT      1

///////////////////// ADC 0 ///////////////////
#if USE_LIB_ADC_0

#define LIB_ADC0_RESOLUTION     ADC_RESOLUTION_12B
#define LIB_ADC0_DATAALIGN      ADC_DATAALIGN_RIGHT

#define LIB_ADC0_CHN_TYPE       LIB_ADC_CHN_ROUTINE


#define LIB_ADC0_CHNS_LEN       1
#define LIB_ADC0_CHNS           {                   \
									ADC_CHANNEL_2,  \
								}
#define LIB_ADC0_SAMPLETIMES	{						\
									ADC_SAMPLETIME_480,	\
								}

                      


#endif









#endif