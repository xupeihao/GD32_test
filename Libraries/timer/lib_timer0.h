#ifndef __LIB_TIMER0_H__
#define __LIB_TIMER0_H__


#include "timer_config.h"


#if USE_LIB_TIMER_0


void lib_timer0_init();
// 1ÃëÖÓÖ´ÐÐ freq´Î£¬psc * freq > Ö÷Æµ/65536
void lib_timer0_update_period(uint16_t psc, float freq);

#if LIB_TIMER0_MODE == 0
extern void lib_timer3_on_cb();
#elif LIB_TIMER0_MODE == 1
#if LIB_TIMER0_USE_CH0_P || LIB_TIMER0_USE_CH0_N
void lib_timer0_ch0_duty(float duty);
#endif
#if LIB_TIMER0_USE_CH1_P || LIB_TIMER0_USE_CH1_N
void lib_timer0_ch1_duty(float duty);
#endif
#if LIB_TIMER0_USE_CH2_P || LIB_TIMER0_USE_CH2_N
void lib_timer0_ch2_duty(float duty);
#endif
#if LIB_TIMER0_USE_CH3
void lib_timer0_ch3_duty(float duty);
#endif
#endif


#endif

#endif