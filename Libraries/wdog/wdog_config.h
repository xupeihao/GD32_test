#ifndef __WDOG_CONFIG_H__
#define __WDOG_CONFIG_H__

#include "gd32f4xx.h"

#define USE_LIB_WDOG	0


#if USE_LIB_WDOG
#define LIB_WDOG_USE_FW		0
#define LIB_WDOG_USE_WW		1

#if LIB_WDOG_USE_FW
/// 毫秒为单位，不超过32768
#define LIB_WDOG_FW_TIMEOUT	5000
#endif


#if LIB_WDOG_USE_WW
#define LIB_WDOG_WW_TIMEOUT_MIN	18
#define LIB_WDOG_WW_TIMEOUT_MAX	24
#endif


#endif


#endif