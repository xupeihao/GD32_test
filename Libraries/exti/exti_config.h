#ifndef __EXTI_CONFIG_H__
#define __EXTI_CONFIG_H__

#include "gd32f4xx.h"

// 外部中断使能控制
#define USE_LIB_EXTI_0      0
#define USE_LIB_EXTI_1      0
#define USE_LIB_EXTI_2      0
#define USE_LIB_EXTI_3      0
#define USE_LIB_EXTI_4      0
#define USE_LIB_EXTI_5      0
#define USE_LIB_EXTI_6      0
#define USE_LIB_EXTI_7      0
#define USE_LIB_EXTI_8      0
#define USE_LIB_EXTI_9      0
#define USE_LIB_EXTI_10     0
#define USE_LIB_EXTI_11     0
#define USE_LIB_EXTI_12     0
#define USE_LIB_EXTI_13     0
#define USE_LIB_EXTI_14     0
#define USE_LIB_EXTI_15     0

/*================ 完整EXTI配置块 ================*/

/************************ EXTI 0 ***********************/
#if USE_LIB_EXTI_0
#define LIB_EXTI0_SOFT_TRIG_ENABLE  0
#define LIB_EXTI0_NVIC              1, 1

#if LIB_EXTI0_SOFT_TRIG_ENABLE == 0
    #define LIB_EXT0_GPIO_RCU   RCU_GPIOA
    #define LIB_EXT0_GPIO_PORT  GPIOA
    #define LIB_EXT0_GPIO_SRC   EXTI_SOURCE_GPIOA
    #define LIB_EXT0_GPIO_PUPD  GPIO_PUPD_NONE
    #define LIB_EXT0_TRIG       EXTI_TRIG_BOTH
#endif
#endif
/************************ EXTI 1 ***********************/
#if USE_LIB_EXTI_1
#define LIB_EXTI1_SOFT_TRIG_ENABLE  0
#define LIB_EXTI1_NVIC              1, 1

#if LIB_EXTI1_SOFT_TRIG_ENABLE == 0
    #define LIB_EXT1_GPIO_RCU   RCU_GPIOC
    #define LIB_EXT1_GPIO_PORT  GPIOC
    #define LIB_EXT1_GPIO_SRC   EXTI_SOURCE_GPIOC
    #define LIB_EXT1_GPIO_PUPD  GPIO_PUPD_PULLUP
    #define LIB_EXT1_TRIG       EXTI_TRIG_BOTH
#endif
#endif

/************************ EXTI 2 ***********************/
#if USE_LIB_EXTI_2
#define LIB_EXTI2_SOFT_TRIG_ENABLE  0
#define LIB_EXTI2_NVIC              1, 1

#if LIB_EXTI2_SOFT_TRIG_ENABLE == 0
    #define LIB_EXT2_GPIO_RCU   RCU_GPIOC
    #define LIB_EXT2_GPIO_PORT  GPIOC
    #define LIB_EXT2_GPIO_SRC   EXTI_SOURCE_GPIOC
    #define LIB_EXT2_GPIO_PUPD  GPIO_PUPD_PULLUP
    #define LIB_EXT2_TRIG       EXTI_TRIG_BOTH
#endif
#endif

/************************ EXTI 3 ***********************/
#if USE_LIB_EXTI_3
#define LIB_EXTI3_SOFT_TRIG_ENABLE  0
#define LIB_EXTI3_NVIC              1, 1

#if LIB_EXTI3_SOFT_TRIG_ENABLE == 0
    #define LIB_EXT3_GPIO_RCU   RCU_GPIOC
    #define LIB_EXT3_GPIO_PORT  GPIOC
    #define LIB_EXT3_GPIO_SRC   EXTI_SOURCE_GPIOC
    #define LIB_EXT3_GPIO_PUPD  GPIO_PUPD_PULLUP
    #define LIB_EXT3_TRIG       EXTI_TRIG_BOTH
#endif
#endif
/************************ EXTI 4 ***********************/
#if USE_LIB_EXTI_4
#define LIB_EXTI4_SOFT_TRIG_ENABLE  0
#define LIB_EXTI4_NVIC              1, 1

#if LIB_EXTI4_SOFT_TRIG_ENABLE == 0
    #define LIB_EXT4_GPIO_RCU   RCU_GPIOB
    #define LIB_EXT4_GPIO_PORT  GPIOB
    #define LIB_EXT4_GPIO_SRC   EXTI_SOURCE_GPIOB
    #define LIB_EXT4_GPIO_PUPD  GPIO_PUPD_PULLUP
    #define LIB_EXT4_TRIG       EXTI_TRIG_FALLING
#endif
#endif

/************************ EXTI 5 ***********************/
#if USE_LIB_EXTI_5
#define LIB_EXTI5_SOFT_TRIG_ENABLE  1
#define LIB_EXTI5_NVIC              1, 1

#if LIB_EXTI5_SOFT_TRIG_ENABLE == 0
    #define LIB_EXT5_GPIO_RCU   RCU_GPIOC
    #define LIB_EXT5_GPIO_PORT  GPIOC
    #define LIB_EXT5_GPIO_SRC   EXTI_SOURCE_GPIOC
    #define LIB_EXT5_GPIO_PUPD  GPIO_PUPD_NONE
    #define LIB_EXT5_TRIG       EXTI_TRIG_BOTH
#endif
#endif
/************************ EXTI 6 ***********************/
#if USE_LIB_EXTI_6
#define LIB_EXTI6_SOFT_TRIG_ENABLE  1
#define LIB_EXTI6_NVIC              1, 1

#if LIB_EXTI6_SOFT_TRIG_ENABLE == 0
    #define LIB_EXT6_GPIO_RCU   RCU_GPIOC
    #define LIB_EXT6_GPIO_PORT  GPIOC
    #define LIB_EXT6_GPIO_SRC   EXTI_SOURCE_GPIOC
    #define LIB_EXT6_GPIO_PUPD  GPIO_PUPD_NONE
    #define LIB_EXT6_TRIG       EXTI_TRIG_BOTH
#endif
#endif
/************************ EXTI 7 ***********************/
#if USE_LIB_EXTI_7
#define LIB_EXTI7_SOFT_TRIG_ENABLE  1
#define LIB_EXTI7_NVIC              1, 1

#if LIB_EXTI7_SOFT_TRIG_ENABLE == 0
    #define LIB_EXT7_GPIO_RCU   RCU_GPIOC
    #define LIB_EXT7_GPIO_PORT  GPIOC
    #define LIB_EXT7_GPIO_SRC   EXTI_SOURCE_GPIOC
    #define LIB_EXT7_GPIO_PUPD  GPIO_PUPD_NONE
    #define LIB_EXT7_TRIG       EXTI_TRIG_BOTH
#endif
#endif
/************************ EXTI 8 ***********************/
#if USE_LIB_EXTI_8
#define LIB_EXTI8_SOFT_TRIG_ENABLE  0
#define LIB_EXTI8_NVIC              1, 1

#if LIB_EXTI8_SOFT_TRIG_ENABLE == 0
    #define LIB_EXT8_GPIO_RCU   RCU_GPIOB
    #define LIB_EXT8_GPIO_PORT  GPIOB
    #define LIB_EXT8_GPIO_SRC   EXTI_SOURCE_GPIOB
    #define LIB_EXT8_GPIO_PUPD  GPIO_PUPD_NONE
    #define LIB_EXT8_TRIG       EXTI_TRIG_BOTH
#endif
#endif
/************************ EXTI 9 ***********************/
#if USE_LIB_EXTI_9
#define LIB_EXTI9_SOFT_TRIG_ENABLE  1
#define LIB_EXTI9_NVIC              1, 1

#if LIB_EXTI9_SOFT_TRIG_ENABLE == 0
    #define LIB_EXT9_GPIO_RCU   RCU_GPIOC
    #define LIB_EXT9_GPIO_PORT  GPIOC
    #define LIB_EXT9_GPIO_SRC   EXTI_SOURCE_GPIOC
    #define LIB_EXT9_GPIO_PUPD  GPIO_PUPD_NONE
    #define LIB_EXT9_TRIG       EXTI_TRIG_BOTH
#endif
#endif
/************************ EXTI 10 ***********************/
#if USE_LIB_EXTI_10
#define LIB_EXTI10_SOFT_TRIG_ENABLE  1
#define LIB_EXTI10_NVIC              1, 1

#if LIB_EXTI10_SOFT_TRIG_ENABLE == 0
    #define LIB_EXT10_GPIO_RCU   RCU_GPIOC
    #define LIB_EXT10_GPIO_PORT  GPIOC
    #define LIB_EXT10_GPIO_SRC   EXTI_SOURCE_GPIOC
    #define LIB_EXT10_GPIO_PUPD  GPIO_PUPD_NONE
    #define LIB_EXT10_TRIG       EXTI_TRIG_BOTH
#endif
#endif
/************************ EXTI 11 ***********************/
#if USE_LIB_EXTI_11
#define LIB_EXTI11_SOFT_TRIG_ENABLE  0
#define LIB_EXTI11_NVIC              1, 1

#if LIB_EXTI11_SOFT_TRIG_ENABLE == 0
    #define LIB_EXT11_GPIO_RCU   RCU_GPIOD
    #define LIB_EXT11_GPIO_PORT  GPIOD
    #define LIB_EXT11_GPIO_SRC   EXTI_SOURCE_GPIOD
    #define LIB_EXT11_GPIO_PUPD  GPIO_PUPD_NONE
    #define LIB_EXT11_TRIG       EXTI_TRIG_BOTH
#endif
#endif
/************************ EXTI 12 ***********************/
#if USE_LIB_EXTI_12
#define LIB_EXTI12_SOFT_TRIG_ENABLE  1
#define LIB_EXTI12_NVIC              1, 1

#if LIB_EXTI12_SOFT_TRIG_ENABLE == 0
    #define LIB_EXT12_GPIO_RCU   RCU_GPIOC
    #define LIB_EXT12_GPIO_PORT  GPIOC
    #define LIB_EXT12_GPIO_SRC   EXTI_SOURCE_GPIOC
    #define LIB_EXT12_GPIO_PUPD  GPIO_PUPD_NONE
    #define LIB_EXT12_TRIG       EXTI_TRIG_BOTH
#endif
#endif
/************************ EXTI 13 ***********************/
#if USE_LIB_EXTI_13
#define LIB_EXTI13_SOFT_TRIG_ENABLE  1
#define LIB_EXTI13_NVIC              1, 1

#if LIB_EXTI13_SOFT_TRIG_ENABLE == 0
    #define LIB_EXT13_GPIO_RCU   RCU_GPIOC
    #define LIB_EXT13_GPIO_PORT  GPIOC
    #define LIB_EXT13_GPIO_SRC   EXTI_SOURCE_GPIOC
    #define LIB_EXT13_GPIO_PUPD  GPIO_PUPD_NONE
    #define LIB_EXT13_TRIG       EXTI_TRIG_BOTH
#endif
#endif
/************************ EXTI 14 ***********************/
#if USE_LIB_EXTI_14
#define LIB_EXTI14_SOFT_TRIG_ENABLE  1
#define LIB_EXTI14_NVIC              1, 1

#if LIB_EXTI14_SOFT_TRIG_ENABLE == 0
    #define LIB_EXT14_GPIO_RCU   RCU_GPIOC
    #define LIB_EXT14_GPIO_PORT  GPIOC
    #define LIB_EXT14_GPIO_SRC   EXTI_SOURCE_GPIOC
    #define LIB_EXT14_GPIO_PUPD  GPIO_PUPD_NONE
    #define LIB_EXT14_TRIG       EXTI_TRIG_BOTH
#endif
#endif
/************************ EXTI 15 ***********************/
#if USE_LIB_EXTI_15
#define LIB_EXTI15_SOFT_TRIG_ENABLE  0
#define LIB_EXTI15_NVIC              1, 1

#if LIB_EXTI15_SOFT_TRIG_ENABLE == 0
    #define LIB_EXT15_GPIO_RCU   RCU_GPIOD
    #define LIB_EXT15_GPIO_PORT  GPIOD
    #define LIB_EXT15_GPIO_SRC   EXTI_SOURCE_GPIOD
    #define LIB_EXT15_GPIO_PUPD  GPIO_PUPD_NONE
    #define LIB_EXT15_TRIG       EXTI_TRIG_BOTH
#endif
#endif


#endif