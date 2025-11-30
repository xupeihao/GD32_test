#include "lib_exti.h"

// 辅助函数：软件初始化
void lib_exti_soft_init(exti_line_enum extix, IRQn_Type irqn, uint8_t pre_priority,
                        uint8_t sub_priority) {
    rcu_periph_clock_enable(RCU_SYSCFG);
    exti_init(extix, EXTI_INTERRUPT, EXTI_TRIG_NONE);
    exti_interrupt_flag_clear(extix);
    nvic_irq_enable(irqn, pre_priority, sub_priority);
}

// 辅助函数：硬件初始化
void lib_exti_hard_init(rcu_periph_enum rcu, uint32_t port, uint32_t pin,
                        uint32_t pupd,
                        uint8_t src_port, uint8_t src_pin,
                        exti_trig_type_enum trig,
                        exti_line_enum extix, IRQn_Type irqn, uint8_t pre_priority,
                        uint8_t sub_priority) {
    // GPIO初始化
    rcu_periph_clock_enable(rcu);
    gpio_mode_set(port, GPIO_MODE_INPUT, pupd, pin);

    // 外部中断初始化
    rcu_periph_clock_enable(RCU_SYSCFG);
    syscfg_exti_line_config(src_port, src_pin);
    exti_init(extix, EXTI_INTERRUPT, trig);
    exti_interrupt_flag_clear(extix);
    nvic_irq_enable(irqn, pre_priority, sub_priority);
}

// 主初始化函数
void lib_exti_init() {
    /* ========== EXTI 0 ========== */
    #if USE_LIB_EXTI_0
        #if LIB_EXTI0_SOFT_TRIG_ENABLE
            lib_exti_soft_init(EXTI_0, EXTI0_IRQn, LIB_EXTI0_NVIC);
        #else
            lib_exti_hard_init(LIB_EXT0_GPIO_RCU, LIB_EXT0_GPIO_PORT, GPIO_PIN_0,
                            LIB_EXT0_GPIO_PUPD, LIB_EXT0_GPIO_SRC,
                            EXTI_SOURCE_PIN0, LIB_EXT0_TRIG, EXTI_0, EXTI0_IRQn, LIB_EXTI0_NVIC);
        #endif
    #endif

    /* ========== EXTI 1 ========== */
    #if USE_LIB_EXTI_1
        #if LIB_EXTI1_SOFT_TRIG_ENABLE
            lib_exti_soft_init(EXTI_1, EXTI1_IRQn, LIB_EXTI1_NVIC);
        #else
            lib_exti_hard_init(LIB_EXT1_GPIO_RCU, LIB_EXT1_GPIO_PORT, GPIO_PIN_1,
                            LIB_EXT1_GPIO_PUPD, LIB_EXT1_GPIO_SRC,
                            EXTI_SOURCE_PIN1, LIB_EXT1_TRIG, EXTI_1, EXTI1_IRQn, LIB_EXTI1_NVIC);
        #endif
    #endif

    /* ========== EXTI 2 ========== */
    #if USE_LIB_EXTI_2
        #if LIB_EXTI2_SOFT_TRIG_ENABLE
            lib_exti_soft_init(EXTI_2, EXTI2_IRQn, LIB_EXTI2_NVIC);
        #else
            lib_exti_hard_init(LIB_EXT2_GPIO_RCU, LIB_EXT2_GPIO_PORT, GPIO_PIN_2,
                            LIB_EXT2_GPIO_PUPD, LIB_EXT2_GPIO_SRC,
                            EXTI_SOURCE_PIN2, LIB_EXT2_TRIG, EXTI_2, EXTI2_IRQn, LIB_EXTI2_NVIC);
        #endif
    #endif

    /* ========== EXTI 3 ========== */
    #if USE_LIB_EXTI_3
        #if LIB_EXTI3_SOFT_TRIG_ENABLE
            lib_exti_soft_init(EXTI_3, EXTI3_IRQn, LIB_EXTI3_NVIC);
        #else
            lib_exti_hard_init(LIB_EXT3_GPIO_RCU, LIB_EXT3_GPIO_PORT, GPIO_PIN_3,
                            LIB_EXT3_GPIO_PUPD, LIB_EXT3_GPIO_SRC,
                            EXTI_SOURCE_PIN3, LIB_EXT3_TRIG, EXTI_3, EXTI3_IRQn, LIB_EXTI3_NVIC);
        #endif
    #endif

    /* ========== EXTI 4 ========== */
    #if USE_LIB_EXTI_4
        #if LIB_EXTI4_SOFT_TRIG_ENABLE
            lib_exti_soft_init(EXTI_4, EXTI4_IRQn, LIB_EXTI4_NVIC);
        #else
            lib_exti_hard_init(LIB_EXT4_GPIO_RCU, LIB_EXT4_GPIO_PORT, GPIO_PIN_4,
                            LIB_EXT4_GPIO_PUPD, LIB_EXT4_GPIO_SRC,
                            EXTI_SOURCE_PIN4, LIB_EXT4_TRIG, EXTI_4, EXTI4_IRQn, LIB_EXTI4_NVIC);
        #endif
    #endif

    /* ========== EXTI 5 ========== */
    #if USE_LIB_EXTI_5
        #if LIB_EXTI5_SOFT_TRIG_ENABLE
            lib_exti_soft_init(EXTI_5, EXTI5_9_IRQn, LIB_EXTI5_NVIC);
        #else
            lib_exti_hard_init(LIB_EXT5_GPIO_RCU, LIB_EXT5_GPIO_PORT, GPIO_PIN_5,
                            LIB_EXT5_GPIO_PUPD, LIB_EXT5_GPIO_SRC,
                            EXTI_SOURCE_PIN5, LIB_EXT5_TRIG, EXTI_5, EXTI5_9_IRQn, LIB_EXTI5_NVIC);
        #endif
    #endif

    /* ========== EXTI 6 ========== */
    #if USE_LIB_EXTI_6
        #if LIB_EXTI6_SOFT_TRIG_ENABLE
            lib_exti_soft_init(EXTI_6, EXTI5_9_IRQn, LIB_EXTI6_NVIC);
        #else
            lib_exti_hard_init(LIB_EXT6_GPIO_RCU, LIB_EXT6_GPIO_PORT, GPIO_PIN_6,
                            LIB_EXT6_GPIO_PUPD, LIB_EXT6_GPIO_SRC,
                            EXTI_SOURCE_PIN6, LIB_EXT6_TRIG, EXTI_6, EXTI5_9_IRQn, LIB_EXTI6_NVIC);
        #endif
    #endif

    /* ========== EXTI 7 ========== */
    #if USE_LIB_EXTI_7
        #if LIB_EXTI7_SOFT_TRIG_ENABLE
            lib_exti_soft_init(EXTI_7, EXTI5_9_IRQn, LIB_EXTI7_NVIC);
        #else
            lib_exti_hard_init(LIB_EXT7_GPIO_RCU, LIB_EXT7_GPIO_PORT, GPIO_PIN_7,
                            LIB_EXT7_GPIO_PUPD, LIB_EXT7_GPIO_SRC,
                            EXTI_SOURCE_PIN7, LIB_EXT7_TRIG, EXTI_7, EXTI5_9_IRQn, LIB_EXTI7_NVIC);
        #endif
    #endif

    /* ========== EXTI 8 ========== */
    #if USE_LIB_EXTI_8
        #if LIB_EXTI8_SOFT_TRIG_ENABLE
            lib_exti_soft_init(EXTI_8, EXTI5_9_IRQn, LIB_EXTI8_NVIC);
        #else
            lib_exti_hard_init(LIB_EXT8_GPIO_RCU, LIB_EXT8_GPIO_PORT, GPIO_PIN_8,
                            LIB_EXT8_GPIO_PUPD, LIB_EXT8_GPIO_SRC,
                            EXTI_SOURCE_PIN8, LIB_EXT8_TRIG, EXTI_8, EXTI5_9_IRQn, LIB_EXTI8_NVIC);
        #endif
    #endif

    /* ========== EXTI 9 ========== */
    #if USE_LIB_EXTI_9
        #if LIB_EXTI9_SOFT_TRIG_ENABLE
            lib_exti_soft_init(EXTI_9, EXTI5_9_IRQn, LIB_EXTI9_NVIC);
        #else
            lib_exti_hard_init(LIB_EXT9_GPIO_RCU, LIB_EXT9_GPIO_PORT, GPIO_PIN_9,
                            LIB_EXT9_GPIO_PUPD, LIB_EXT9_GPIO_SRC,
                            EXTI_SOURCE_PIN9, LIB_EXT9_TRIG, EXTI_9, EXTI5_9_IRQn, LIB_EXTI9_NVIC);
        #endif
    #endif

    /* ========== EXTI 10 ========== */
    #if USE_LIB_EXTI_10
        #if LIB_EXTI10_SOFT_TRIG_ENABLE
            lib_exti_soft_init(EXTI_10, EXTI10_15_IRQn, LIB_EXTI10_NVIC);
        #else
            lib_exti_hard_init(LIB_EXT10_GPIO_RCU, LIB_EXT10_GPIO_PORT, GPIO_PIN_10,
                            LIB_EXT10_GPIO_PUPD, LIB_EXT10_GPIO_SRC,
                            EXTI_SOURCE_PIN10, LIB_EXT10_TRIG, EXTI_10, EXTI10_15_IRQn, LIB_EXTI10_NVIC);
        #endif
    #endif

    /* ========== EXTI 11 ========== */
    #if USE_LIB_EXTI_11
        #if LIB_EXTI11_SOFT_TRIG_ENABLE
            lib_exti_soft_init(EXTI_11, EXTI10_15_IRQn, LIB_EXTI11_NVIC);
        #else
            lib_exti_hard_init(LIB_EXT11_GPIO_RCU, LIB_EXT11_GPIO_PORT, GPIO_PIN_11,
                            LIB_EXT11_GPIO_PUPD, LIB_EXT11_GPIO_SRC,
                            EXTI_SOURCE_PIN11, LIB_EXT11_TRIG, EXTI_11, EXTI10_15_IRQn, LIB_EXTI11_NVIC);
        #endif
    #endif

    /* ========== EXTI 12 ========== */
    #if USE_LIB_EXTI_12
        #if LIB_EXTI12_SOFT_TRIG_ENABLE
            lib_exti_soft_init(EXTI_12, EXTI10_15_IRQn, LIB_EXTI12_NVIC);
        #else
            lib_exti_hard_init(LIB_EXT12_GPIO_RCU, LIB_EXT12_GPIO_PORT, GPIO_PIN_12,
                            LIB_EXT12_GPIO_PUPD, LIB_EXT12_GPIO_SRC,
                            EXTI_SOURCE_PIN12, LIB_EXT12_TRIG, EXTI_12, EXTI10_15_IRQn, LIB_EXTI12_NVIC);
        #endif
    #endif

    /* ========== EXTI 13 ========== */
    #if USE_LIB_EXTI_13
        #if LIB_EXTI13_SOFT_TRIG_ENABLE
            lib_exti_soft_init(EXTI_13, EXTI10_15_IRQn, LIB_EXTI13_NVIC);
        #else
            lib_exti_hard_init(LIB_EXT13_GPIO_RCU, LIB_EXT13_GPIO_PORT, GPIO_PIN_13,
                            LIB_EXT13_GPIO_PUPD, LIB_EXT13_GPIO_SRC,
                            EXTI_SOURCE_PIN13, LIB_EXT13_TRIG, EXTI_13, EXTI10_15_IRQn, LIB_EXTI13_NVIC);
        #endif
    #endif

    /* ========== EXTI 14 ========== */
    #if USE_LIB_EXTI_14
        #if LIB_EXTI14_SOFT_TRIG_ENABLE
            lib_exti_soft_init(EXTI_14, EXTI10_15_IRQn, LIB_EXTI14_NVIC);
        #else
            lib_exti_hard_init(LIB_EXT14_GPIO_RCU, LIB_EXT14_GPIO_PORT, GPIO_PIN_14,
                            LIB_EXT14_GPIO_PUPD, LIB_EXT14_GPIO_SRC,
                            EXTI_SOURCE_PIN14, LIB_EXT14_TRIG, EXTI_14, EXTI10_15_IRQn, LIB_EXTI14_NVIC);
        #endif
    #endif

    /* ========== EXTI 15 ========== */
    #if USE_LIB_EXTI_15
        #if LIB_EXTI15_SOFT_TRIG_ENABLE
            lib_exti_soft_init(EXTI_15, EXTI10_15_IRQn, LIB_EXTI15_NVIC);
        #else
            lib_exti_hard_init(LIB_EXT15_GPIO_RCU, LIB_EXT15_GPIO_PORT, GPIO_PIN_15,
                            LIB_EXT15_GPIO_PUPD, LIB_EXT15_GPIO_SRC,
                            EXTI_SOURCE_PIN15, LIB_EXT15_TRIG, EXTI_15, EXTI10_15_IRQn, LIB_EXTI15_NVIC);
        #endif
    #endif
}

/* ================= 中断服务函数 ================= */

// EXTI0中断处理
#if USE_LIB_EXTI_0
    #if LIB_EXTI0_SOFT_TRIG_ENABLE
    void lib_exti0_soft_trig() {
        exti_software_interrupt_enable(EXTI_0);
    }
    #endif

    void EXTI0_IRQHandler() {
        if(SET == exti_interrupt_flag_get(EXTI_0)) {
            exti_interrupt_flag_clear(EXTI_0);
            lib_exti0_on_trig();
        }
    }
#endif

// EXTI1中断处理
#if USE_LIB_EXTI_1
    #if LIB_EXTI1_SOFT_TRIG_ENABLE
    void lib_exti1_soft_trig() {
        exti_software_interrupt_enable(EXTI_1);
    }
    #endif

    void EXTI1_IRQHandler() {
        if(SET == exti_interrupt_flag_get(EXTI_1)) {
            exti_interrupt_flag_clear(EXTI_1);
            lib_exti1_on_trig();
        }
    }
#endif

// EXTI2中断处理
#if USE_LIB_EXTI_2
    #if LIB_EXTI2_SOFT_TRIG_ENABLE
    void lib_exti2_soft_trig() {
        exti_software_interrupt_enable(EXTI_2);
    }
    #endif

    void EXTI2_IRQHandler() {
        if(SET == exti_interrupt_flag_get(EXTI_2)) {
            exti_interrupt_flag_clear(EXTI_2);
            lib_exti2_on_trig();
        }
    }
#endif

// EXTI3中断处理
#if USE_LIB_EXTI_3
    #if LIB_EXTI3_SOFT_TRIG_ENABLE
    void lib_exti3_soft_trig() {
        exti_software_interrupt_enable(EXTI_3);
    }
    #endif

    void EXTI3_IRQHandler() {
        if(SET == exti_interrupt_flag_get(EXTI_3)) {
            exti_interrupt_flag_clear(EXTI_3);
            lib_exti3_on_trig();
        }
    }
#endif

// EXTI4中断处理
#if USE_LIB_EXTI_4
    #if LIB_EXTI4_SOFT_TRIG_ENABLE
    void lib_exti4_soft_trig() {
        exti_software_interrupt_enable(EXTI_4);
    }
    #endif

    void EXTI4_IRQHandler() {
        if(SET == exti_interrupt_flag_get(EXTI_4)) {
            exti_interrupt_flag_clear(EXTI_4);
            lib_exti4_on_trig();
        }
    }
#endif

// EXTI5-9中断处理(共享中断线)
#if (USE_LIB_EXTI_5 || USE_LIB_EXTI_6 || USE_LIB_EXTI_7 || USE_LIB_EXTI_8 || USE_LIB_EXTI_9)
    #if USE_LIB_EXTI_5 && LIB_EXTI5_SOFT_TRIG_ENABLE
    void lib_exti5_soft_trig() {
        exti_software_interrupt_enable(EXTI_5);
    }
    #endif

    #if USE_LIB_EXTI_6 && LIB_EXTI6_SOFT_TRIG_ENABLE
    void lib_exti6_soft_trig() {
        exti_software_interrupt_enable(EXTI_6);
    }
    #endif

    #if USE_LIB_EXTI_7 && LIB_EXTI7_SOFT_TRIG_ENABLE
    void lib_exti7_soft_trig() {
        exti_software_interrupt_enable(EXTI_7);
    }
    #endif

    #if USE_LIB_EXTI_8 && LIB_EXTI8_SOFT_TRIG_ENABLE
    void lib_exti8_soft_trig() {
        exti_software_interrupt_enable(EXTI_8);
    }
    #endif

    #if USE_LIB_EXTI_9 && LIB_EXTI9_SOFT_TRIG_ENABLE
    void lib_exti9_soft_trig() {
        exti_software_interrupt_enable(EXTI_9);
    }
    #endif

    void EXTI5_9_IRQHandler() {
        #if USE_LIB_EXTI_5
        if(SET == exti_interrupt_flag_get(EXTI_5)) {
            exti_interrupt_flag_clear(EXTI_5);
            lib_exti5_on_trig();
        }
        #endif
        
        #if USE_LIB_EXTI_6
        if(SET == exti_interrupt_flag_get(EXTI_6)) {
            exti_interrupt_flag_clear(EXTI_6);
            lib_exti6_on_trig();
        }
        #endif
        
        #if USE_LIB_EXTI_7
        if(SET == exti_interrupt_flag_get(EXTI_7)) {
            exti_interrupt_flag_clear(EXTI_7);
            lib_exti7_on_trig();
        }
        #endif
        
        #if USE_LIB_EXTI_8
        if(SET == exti_interrupt_flag_get(EXTI_8)) {
            exti_interrupt_flag_clear(EXTI_8);
            lib_exti8_on_trig();
        }
        #endif
        
        #if USE_LIB_EXTI_9
        if(SET == exti_interrupt_flag_get(EXTI_9)) {
            exti_interrupt_flag_clear(EXTI_9);
            lib_exti9_on_trig();
        }
        #endif
    }
#endif

// EXTI10-15中断处理(共享中断线)
#if (USE_LIB_EXTI_10 || USE_LIB_EXTI_11 || USE_LIB_EXTI_12 || USE_LIB_EXTI_13 || USE_LIB_EXTI_14 || USE_LIB_EXTI_15)
    #if USE_LIB_EXTI_10 && LIB_EXTI10_SOFT_TRIG_ENABLE
    void lib_exti10_soft_trig() {
        exti_software_interrupt_enable(EXTI_10);
    }
    #endif
    
    #if USE_LIB_EXTI_11 && LIB_EXTI11_SOFT_TRIG_ENABLE
    void lib_exti11_soft_trig() {
        exti_software_interrupt_enable(EXTI_11);
    }
    #endif
    
    #if USE_LIB_EXTI_12 && LIB_EXTI12_SOFT_TRIG_ENABLE
    void lib_exti12_soft_trig() {
        exti_software_interrupt_enable(EXTI_12);
    }
    #endif
    
    #if USE_LIB_EXTI_13 && LIB_EXTI13_SOFT_TRIG_ENABLE
    void lib_exti13_soft_trig() {
        exti_software_interrupt_enable(EXTI_13);
    }
    #endif
    
    #if USE_LIB_EXTI_14 && LIB_EXTI14_SOFT_TRIG_ENABLE
    void lib_exti14_soft_trig() {
        exti_software_interrupt_enable(EXTI_14);
    }
    #endif
    
    #if USE_LIB_EXTI_15 && LIB_EXTI15_SOFT_TRIG_ENABLE
    void lib_exti15_soft_trig() {
        exti_software_interrupt_enable(EXTI_15);
    }
    #endif

    void EXTI10_15_IRQHandler() {		
        #if USE_LIB_EXTI_10
        if(SET == exti_interrupt_flag_get(EXTI_10)) {
            exti_interrupt_flag_clear(EXTI_10);
            lib_exti10_on_trig();
        }
        #endif
        
        #if USE_LIB_EXTI_11
        if(SET == exti_interrupt_flag_get(EXTI_11)) {
            exti_interrupt_flag_clear(EXTI_11);
            lib_exti11_on_trig();
        }
        #endif
        
        #if USE_LIB_EXTI_12
        if(SET == exti_interrupt_flag_get(EXTI_12)) {
            exti_interrupt_flag_clear(EXTI_12);
            lib_exti12_on_trig();
        }
        #endif
        
        #if USE_LIB_EXTI_13
        if(SET == exti_interrupt_flag_get(EXTI_13)) {
            exti_interrupt_flag_clear(EXTI_13);
            lib_exti13_on_trig();
        }
        #endif
        
        #if USE_LIB_EXTI_14
        if(SET == exti_interrupt_flag_get(EXTI_14)) {
            exti_interrupt_flag_clear(EXTI_14);
            lib_exti14_on_trig();
        }
        #endif
        
        #if USE_LIB_EXTI_15
        if(SET == exti_interrupt_flag_get(EXTI_15)) {
            exti_interrupt_flag_clear(EXTI_15);
            lib_exti15_on_trig();
        }
        #endif
    }
#endif