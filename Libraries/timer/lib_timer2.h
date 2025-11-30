#ifndef __LIB_TIMER2_H__
#define __LIB_TIMER2_H__


#include "timer_config.h"


#if USE_LIB_TIMER_2


void lib_timer2_init();
// 1ÃëÖÓÖ´ÐÐ freq´Î£¬psc * freq > Ö÷Æµ/65536
void lib_timer2_update_period(uint16_t psc, float freq);

#if LIB_TIMER2_MODE == 0
extern void lib_timer2_on_cb();
#elif LIB_TIMER2_MODE == 1
#if LIB_TIMER2_USE_CH0
void lib_timer2_ch0_duty(float duty);
#endif
#if LIB_TIMER2_USE_CH1
void lib_timer2_ch1_duty(float duty);
#endif
#if LIB_TIMER2_USE_CH2
void lib_timer2_ch2_duty(float duty);
#endif
#if LIB_TIMER2_USE_CH3
void lib_timer2_ch3_duty(float duty);
#endif
#endif


#endif

#endif