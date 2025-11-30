#ifndef __RTC_CONFIG_H__
#define __RTC_CONFIG_H__

#include "gd32f4xx.h"
#include <stdio.h>


#define USE_LIB_RTC		0



#if USE_LIB_RTC
///OSC: 0-32.768k  1-IRC32K	 2-HXTAL
#define LIB_RTC_USE_OSC	 	0

#define LIB_RTC_USE_ALARM0	0
#define LIB_RTC_USE_ALARM1	0

#if LIB_RTC_USE_ALARM0 || LIB_RTC_USE_ALARM1
#define LIB_RTC_ALARM_NVIC	2, 2
#endif




#endif



#endif