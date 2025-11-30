#ifndef __LIB_TIMER1_H__
#define __LIB_TIMER1_H__


#include "timer_config.h"


#if USE_LIB_TIMER_1


void lib_timer1_init();
// 1ÃëÖÓÖ´ÐÐ freq´Î£¬psc * freq > Ö÷Æµ/65536
void lib_timer1_update_period(uint16_t psc, float freq);

#if LIB_TIMER1_MODE == 0
extern void lib_timer1_on_cb();
#elif LIB_TIMER1_MODE == 1
#if LIB_TIMER1_USE_CH0
void lib_timer1_ch0_duty(float duty);
#endif
#if LIB_TIMER1_USE_CH1
void lib_timer1_ch1_duty(float duty);
#endif
#if LIB_TIMER1_USE_CH2
void lib_timer1_ch2_duty(float duty);
#endif
#if LIB_TIMER1_USE_CH3
void lib_timer1_ch3_duty(float duty);
#endif
#endif


#endif

#endif