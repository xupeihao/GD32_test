#ifndef __LIB_TIMER9_H__
#define __LIB_TIMER9_H__


#include "timer_config.h"


#if USE_LIB_TIMER_9


void lib_timer9_init();
// 1ÃëÖÓÖ´ÐÐ freq´Î£¬psc * freq > Ö÷Æµ/65536
void lib_timer9_update_period(uint16_t psc, float freq);

#if LIB_TIMER9_MODE == 0
extern void lib_timer9_on_cb();
#elif LIB_TIMER9_MODE == 1
#if LIB_TIMER9_USE_CH0
void lib_timer9_ch0_duty(float duty);
#endif
#endif


#endif

#endif