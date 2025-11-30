#ifndef __LIB_TIMER11_H__
#define __LIB_TIMER11_H__


#include "timer_config.h"


#if USE_LIB_TIMER_11


void lib_timer11_init();
// 1ÃëÖÓÖ´ÐÐ freq´Î£¬psc * freq > Ö÷Æµ/65536
void lib_timer11_update_period(uint16_t psc, float freq);

#if LIB_TIMER11_MODE == 0
extern void lib_timer11_on_cb();
#elif LIB_TIMER11_MODE == 1
#if LIB_TIMER11_USE_CH0
void lib_timer11_ch0_duty(float duty);
#endif
#if LIB_TIMER11_USE_CH1
void lib_timer11_ch1_duty(float duty);
#endif
#endif


#endif

#endif