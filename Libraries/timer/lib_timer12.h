#ifndef __LIB_TIMER12_H__
#define __LIB_TIMER12_H__


#include "timer_config.h"


#if USE_LIB_TIMER_12


void lib_timer12_init();
// 1ÃëÖÓÖ´ÐÐ freq´Î£¬psc * freq > Ö÷Æµ/65536
void lib_timer12_update_period(uint16_t psc, float freq);

#if LIB_TIMER12_MODE == 0
extern void lib_timer12_on_cb();
#elif LIB_TIMER12_MODE == 1
#if LIB_TIMER12_USE_CH0
void lib_timer12_ch0_duty(float duty);
#endif
#endif


#endif

#endif