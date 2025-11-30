#ifndef __LIB_WDOG_H__
#define __LIB_WDOG_H__


#include "wdog_config.h"


#if USE_LIB_WDOG

void lib_wdog_init();

#if LIB_WDOG_USE_FW
void lib_wdog_config_fw(uint16_t timeout);
void lib_wdog_fw_feeddog();
#endif

#if LIB_WDOG_USE_WW
void lib_wdog_config_ww(uint16_t min_ms, uint16_t max_ms);
void lib_wdog_ww_feeddog();
#endif

#endif

#endif