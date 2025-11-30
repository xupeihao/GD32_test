#ifndef __LIB_EXTI_H__
#define __LIB_EXTI_H__

#include "exti_config.h"

void lib_exti_init();

/*================ 完整EXTI回调声明 ================*/

#if USE_LIB_EXTI_0
    #if LIB_EXTI0_SOFT_TRIG_ENABLE
    void lib_exti0_soft_trig();
    #endif
    extern void lib_exti0_on_trig();
#endif

#if USE_LIB_EXTI_1
    #if LIB_EXTI1_SOFT_TRIG_ENABLE
    void lib_exti1_soft_trig();
    #endif
    extern void lib_exti1_on_trig();
#endif

#if USE_LIB_EXTI_2
    #if LIB_EXTI2_SOFT_TRIG_ENABLE
    void lib_exti2_soft_trig();
    #endif
    extern void lib_exti2_on_trig();
#endif

// ============ 新增EXTI声明 (3-15) =========== //

#if USE_LIB_EXTI_3
    #if LIB_EXTI3_SOFT_TRIG_ENABLE
    void lib_exti3_soft_trig();
    #endif
    extern void lib_exti3_on_trig();
#endif

#if USE_LIB_EXTI_4
    #if LIB_EXTI4_SOFT_TRIG_ENABLE
    void lib_exti4_soft_trig();
    #endif
    extern void lib_exti4_on_trig();
#endif

#if USE_LIB_EXTI_5
    #if LIB_EXTI5_SOFT_TRIG_ENABLE
    void lib_exti5_soft_trig();
    #endif
    extern void lib_exti5_on_trig();
#endif

#if USE_LIB_EXTI_6
    #if LIB_EXTI6_SOFT_TRIG_ENABLE
    void lib_exti6_soft_trig();
    #endif
    extern void lib_exti6_on_trig();
#endif

#if USE_LIB_EXTI_7
    #if LIB_EXTI7_SOFT_TRIG_ENABLE
    void lib_exti7_soft_trig();
    #endif
    extern void lib_exti7_on_trig();
#endif

#if USE_LIB_EXTI_8
    #if LIB_EXTI8_SOFT_TRIG_ENABLE
    void lib_exti8_soft_trig();
    #endif
    extern void lib_exti8_on_trig();
#endif

#if USE_LIB_EXTI_9
    #if LIB_EXTI9_SOFT_TRIG_ENABLE
    void lib_exti9_soft_trig();
    #endif
    extern void lib_exti9_on_trig();
#endif

#if USE_LIB_EXTI_10
    #if LIB_EXTI10_SOFT_TRIG_ENABLE
    void lib_exti10_soft_trig();
    #endif
    extern void lib_exti10_on_trig();
#endif

#if USE_LIB_EXTI_11
    #if LIB_EXTI11_SOFT_TRIG_ENABLE
    void lib_exti11_soft_trig();
    #endif
    extern void lib_exti11_on_trig();
#endif

#if USE_LIB_EXTI_12
    #if LIB_EXTI12_SOFT_TRIG_ENABLE
    void lib_exti12_soft_trig();
    #endif
    extern void lib_exti12_on_trig();
#endif

#if USE_LIB_EXTI_13
    #if LIB_EXTI13_SOFT_TRIG_ENABLE
    void lib_exti13_soft_trig();
    #endif
    extern void lib_exti13_on_trig();
#endif

#if USE_LIB_EXTI_14
    #if LIB_EXTI14_SOFT_TRIG_ENABLE
    void lib_exti14_soft_trig();
    #endif
    extern void lib_exti14_on_trig();
#endif

#if USE_LIB_EXTI_15
    #if LIB_EXTI15_SOFT_TRIG_ENABLE
    void lib_exti15_soft_trig();
    #endif
    extern void lib_exti15_on_trig();
#endif

#endif