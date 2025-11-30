#ifndef __LIB_TIMER8_H__
#define __LIB_TIMER8_H__


#include "timer_config.h"


#if USE_LIB_TIMER_8


void lib_timer8_init();
// 1ÃëÖÓÖ´ÐÐ freq´Î£¬psc * freq > Ö÷Æµ/65536
void lib_timer8_update_period(uint16_t psc, float freq);

#if LIB_TIMER8_MODE == 0
extern void lib_timer8_on_cb();
#elif LIB_TIMER8_MODE == 1
#if LIB_TIMER8_USE_CH0
void lib_timer8_ch0_duty(float duty);
#endif
#if LIB_TIMER8_USE_CH1
void lib_timer8_ch1_duty(float duty);
#endif
#endif


#endif

#endif