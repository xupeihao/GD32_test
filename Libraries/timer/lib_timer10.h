#ifndef __LIB_TIMER10_H__
#define __LIB_TIMER10_H__


#include "timer_config.h"


#if USE_LIB_TIMER_10


void lib_timer10_init();
// 1ÃëÖÓÖ´ÐÐ freq´Î£¬psc * freq > Ö÷Æµ/65536
void lib_timer10_update_period(uint16_t psc, float freq);

#if LIB_TIMER10_MODE == 0
extern void lib_timer10_on_cb();
#elif LIB_TIMER10_MODE == 1
#if LIB_TIMER10_USE_CH0
void lib_timer10_ch0_duty(float duty);
#endif
#endif


#endif

#endif