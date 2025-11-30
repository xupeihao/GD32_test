#ifndef __LIB_TIMER4_H__
#define __LIB_TIMER4_H__


#include "timer_config.h"


#if USE_LIB_TIMER_4


void lib_timer4_init();
// 1ÃëÖÓÖ´ÐÐ freq´Î£¬psc * freq > Ö÷Æµ/65536
void lib_timer4_update_period(uint16_t psc, float freq);

#if LIB_TIMER4_MODE == 0
extern void lib_timer4_on_cb();
#elif LIB_TIMER4_MODE == 1
#if LIB_TIMER4_USE_CH0
void lib_timer4_ch0_duty(float duty);
#endif
#if LIB_TIMER4_USE_CH1
void lib_timer4_ch1_duty(float duty);
#endif
#if LIB_TIMER4_USE_CH2
void lib_timer4_ch2_duty(float duty);
#endif
#if LIB_TIMER4_USE_CH3
void lib_timer4_ch3_duty(float duty);
#endif
#endif


#endif

#endif