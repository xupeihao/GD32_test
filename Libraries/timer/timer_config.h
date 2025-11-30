#ifndef __TIMER_CONFIG_H__
#define __TIMER_CONFIG_H__


#include "gd32f4xx.h"
#include "gd32f4xx_rcu.h"
#include "gd32f4xx_gpio.h"
#include "gd32f4xx_timer.h"
#include <stdio.h>

#define USE_LIB_TIMER_0		0
#define USE_LIB_TIMER_1		0
#define USE_LIB_TIMER_2		0
#define USE_LIB_TIMER_3		0
#define USE_LIB_TIMER_4		0
#define USE_LIB_TIMER_5		1
#define USE_LIB_TIMER_6		0
#define USE_LIB_TIMER_7		0
#define USE_LIB_TIMER_8		0
#define USE_LIB_TIMER_9		0
#define USE_LIB_TIMER_10	0
#define USE_LIB_TIMER_11	0
#define USE_LIB_TIMER_12	0
#define USE_LIB_TIMER_13	0


/******************* TIMER 0 ***************/
#if USE_LIB_TIMER_0

///// 0: base  1: output
#define LIB_TIMER0_MODE		1

///// 1秒钟执行 FREQ 次
///// PSC * FREQ  >  主频 / 65536
#define LIB_TIMER0_PSC		10
#define LIB_TIMER0_FREQ		1000

#if LIB_TIMER0_MODE == 0
/////// 基础功能
#define LIB_TIMER0_NVIC		0, 0
#define LIB_TIMER0_CB		1
#elif LIB_TIMER0_MODE == 1
/////// 通用功能
#define LIB_TIMER0_USE_CH0_P	1
#define LIB_TIMER0_USE_CH0_N	1
#define LIB_TIMER0_USE_CH1_P	1
#define LIB_TIMER0_USE_CH1_N	1
#define LIB_TIMER0_USE_CH2_P	1
#define LIB_TIMER0_USE_CH2_N	1
#define LIB_TIMER0_USE_CH3		1

/**
*|	 CH			| 		PIN
*|--------------|----------------------------------------
*|   CH0		|	OP:	PA8 PE9		|	ON:	PA7 PB13 PE8
*|--------------|----------------------------------------
*|   CH1		|	OP:	PA9 PE11	|	ON:	PA7 PB13 PE8
*|--------------|----------------------------------------
*|   CH2 		|	OP:	PA10 PE13	|	ON:	PA7 PB13 PE8
*|--------------|----------------------------------------
*|   CH3 		|	PA11 PE14
*/
////////// CH0
#if LIB_TIMER0_USE_CH0_P
#define LIB_TIMER0_CH0_P_RCU	RCU_GPIOD
#define LIB_TIMER0_CH0_P_PIN	GPIOD, GPIO_PIN_12
#endif
#if LIB_TIMER0_USE_CH0_N
#define LIB_TIMER0_CH0_N_RCU	RCU_GPIOD
#define LIB_TIMER0_CH0_N_PIN	GPIOD, GPIO_PIN_12
#endif
#if LIB_TIMER0_USE_CH0_P || LIB_TIMER0_USE_CH0_N 
#define LIB_TIMER0_CH0_MODE	TIMER_OC_MODE_PWM0
/// float [0, 100]
#define LIB_TIMER0_CH0_DUTY	10.0
#endif

////////// CH1
#if LIB_TIMER0_USE_CH1_P
#define LIB_TIMER0_CH1_P_RCU	RCU_GPIOD
#define LIB_TIMER0_CH1_P_PIN	GPIOD, GPIO_PIN_12
#endif
#if LIB_TIMER0_USE_CH1_N
#define LIB_TIMER0_CH1_N_RCU	RCU_GPIOD
#define LIB_TIMER0_CH1_N_PIN	GPIOD, GPIO_PIN_12
#endif
#if LIB_TIMER0_USE_CH1_P || LIB_TIMER0_USE_CH1_N 
#define LIB_TIMER0_CH1_MODE	TIMER_OC_MODE_PWM0
/// float [0, 100]
#define LIB_TIMER0_CH1_DUTY	10.0
#endif

////////// CH2
#if LIB_TIMER0_USE_CH2_P
#define LIB_TIMER0_CH2_P_RCU	RCU_GPIOD
#define LIB_TIMER0_CH2_P_PIN	GPIOD, GPIO_PIN_12
#endif
#if LIB_TIMER0_USE_CH2_N
#define LIB_TIMER0_CH2_N_RCU	RCU_GPIOD
#define LIB_TIMER0_CH2_N_PIN	GPIOD, GPIO_PIN_12
#endif
#if LIB_TIMER0_USE_CH2_P || LIB_TIMER0_USE_CH2_N 
#define LIB_TIMER0_CH2_MODE	TIMER_OC_MODE_PWM0
/// float [0, 100]
#define LIB_TIMER0_CH2_DUTY	10.0
#endif

////////// CH3
#if LIB_TIMER0_USE_CH3
#define LIB_TIMER0_CH3_RCU		RCU_GPIOD
#define LIB_TIMER0_CH3_PIN		GPIOD, GPIO_PIN_12
#define LIB_TIMER0_CH3_MODE		TIMER_OC_MODE_PWM0
/// float [0, 100]
#define LIB_TIMER0_CH3_DUTY	10.0
#endif

#endif /** LIB_TIMER0_MODE **/

#endif /** USE_LIB_TIMER_0 **/


/******************* TIMER 1 ***************/
#if USE_LIB_TIMER_1

///// 0: base  1: output
#define LIB_TIMER1_MODE		1

///// 1秒钟执行 FREQ 次
///// PSC * FREQ  >  主频 / 65536
#define LIB_TIMER1_PSC		10
#define LIB_TIMER1_FREQ		1000

#if LIB_TIMER1_MODE == 0
/////// 基础功能
#define LIB_TIMER1_NVIC		0, 0
#define LIB_TIMER1_CB		1
#elif LIB_TIMER1_MODE == 1
/////// 通用功能
#define LIB_TIMER1_USE_CH0	0
#define LIB_TIMER1_USE_CH1	1
#define LIB_TIMER1_USE_CH2	0
#define LIB_TIMER1_USE_CH3	0

/**
*|	CH			| 		PIN
*|--------------|--------------------
*|   CH0		|	PA0	PA5	PA15 PB8
*|--------------|--------------------
*|   CH1		|	PA1	PB3	PB9
*|--------------|--------------------
*|   CH2 		|	PA2	PB10
*|--------------|--------------------
*|   CH3 		|	PA3	PB2	PB11
*/
#if LIB_TIMER1_USE_CH0
#define LIB_TIMER1_CH0_RCU	RCU_GPIOD
#define LIB_TIMER1_CH0_PIN	GPIOD, GPIO_PIN_12

#define LIB_TIMER1_CH0_MODE	TIMER_OC_MODE_PWM0
/// float [0, 100]
#define LIB_TIMER1_CH0_DUTY	10.0
#endif

#if LIB_TIMER1_USE_CH1
#define LIB_TIMER1_CH1_RCU	RCU_GPIOB
#define LIB_TIMER1_CH1_PIN	GPIOB, GPIO_PIN_9
#define LIB_TIMER1_CH1_MODE	TIMER_OC_MODE_PWM0
/// float [0, 100]
#define LIB_TIMER1_CH1_DUTY	0.0
#endif

#if LIB_TIMER1_USE_CH2
#define LIB_TIMER1_CH2_RCU	RCU_GPIOD
#define LIB_TIMER1_CH2_PIN	GPIOD, GPIO_PIN_14
#define LIB_TIMER1_CH2_MODE	TIMER_OC_MODE_PWM0
/// float [0, 100]
#define LIB_TIMER1_CH2_DUTY	30.0
#endif

#if LIB_TIMER1_USE_CH3
#define LIB_TIMER1_CH3_RCU	RCU_GPIOB
#define LIB_TIMER1_CH3_PIN	GPIOB, GPIO_PIN_9
#define LIB_TIMER1_CH3_MODE	TIMER_OC_MODE_PWM0
/// float [0, 100]
#define LIB_TIMER1_CH3_DUTY	0.0
#endif

#endif


#endif


/******************* TIMER 2 ***************/
#if USE_LIB_TIMER_2

///// 0: base  1: output
#define LIB_TIMER2_MODE		1

///// 1秒钟执行 FREQ 次
///// PSC * FREQ  >  主频 / 65536
#define LIB_TIMER2_PSC		10
#define LIB_TIMER2_FREQ		1000

#if LIB_TIMER2_MODE == 0
/////// 基础功能
#define LIB_TIMER2_NVIC		0, 0
#define LIB_TIMER2_CB		1
#elif LIB_TIMER2_MODE == 1
/////// 通用功能
#define LIB_TIMER2_USE_CH0	0
#define LIB_TIMER2_USE_CH1	1
#define LIB_TIMER2_USE_CH2	0
#define LIB_TIMER2_USE_CH3	0

/**
*|	CH			| 		PIN
*|--------------|-----------------
*|   CH0		|	PA6	PB4	PC6
*|--------------|-----------------
*|   CH1		|	PA7	PB5	PC7
*|--------------|-----------------
*|   CH2 		|	PB0	PC8
*|--------------|-----------------
*|   CH3 		|	PB1	PC9
*/
#if LIB_TIMER2_USE_CH0
#define LIB_TIMER2_CH0_RCU	RCU_GPIOD
#define LIB_TIMER2_CH0_PIN	GPIOD, GPIO_PIN_12

#define LIB_TIMER2_CH0_MODE	TIMER_OC_MODE_PWM0
/// float [0, 100]
#define LIB_TIMER2_CH0_DUTY	10.0
#endif

#if LIB_TIMER2_USE_CH1
#define LIB_TIMER2_CH1_RCU	RCU_GPIOB
#define LIB_TIMER2_CH1_PIN	GPIOB, GPIO_PIN_9
#define LIB_TIMER2_CH1_MODE	TIMER_OC_MODE_PWM0
/// float [0, 100]
#define LIB_TIMER2_CH1_DUTY	0.0
#endif

#if LIB_TIMER2_USE_CH2
#define LIB_TIMER2_CH2_RCU	RCU_GPIOD
#define LIB_TIMER2_CH2_PIN	GPIOD, GPIO_PIN_14
#define LIB_TIMER2_CH2_MODE	TIMER_OC_MODE_PWM0
/// float [0, 100]
#define LIB_TIMER2_CH2_DUTY	30.0
#endif

#if LIB_TIMER2_USE_CH3
#define LIB_TIMER2_CH3_RCU	RCU_GPIOB
#define LIB_TIMER2_CH3_PIN	GPIOB, GPIO_PIN_9
#define LIB_TIMER2_CH3_MODE	TIMER_OC_MODE_PWM0
/// float [0, 100]
#define LIB_TIMER2_CH3_DUTY	0.0
#endif

#endif


#endif


/******************* TIMER 3 ***************/
#if USE_LIB_TIMER_3

///// 0: base  1: output
#define LIB_TIMER3_MODE		1

///// 1秒钟执行 FREQ 次
///// PSC * FREQ  >  主频 / 65536
#define LIB_TIMER3_PSC		10
#define LIB_TIMER3_FREQ		1000

#if LIB_TIMER3_MODE == 0
/////// 基础功能
#define LIB_TIMER3_NVIC		0, 0
#define LIB_TIMER3_CB		1
#elif LIB_TIMER3_MODE == 1
/////// 通用功能
#define LIB_TIMER3_USE_CH0	0
#define LIB_TIMER3_USE_CH1	0
#define LIB_TIMER3_USE_CH2	0
#define LIB_TIMER3_USE_CH3	1

/**
*|	CH			| 		PIN
*|--------------|-----------------
*|   CH0		|	PB6	PD12
*|--------------|-----------------
*|   CH1		|	PB7	PD13
*|--------------|-----------------
*|   CH2 		|	PB8	PD14
*|--------------|-----------------
*|   CH3 		|	PB9	PD14
*/
#if LIB_TIMER3_USE_CH0
#define LIB_TIMER3_CH0_RCU	RCU_GPIOD
#define LIB_TIMER3_CH0_PIN	GPIOD, GPIO_PIN_12

#define LIB_TIMER3_CH0_MODE	TIMER_OC_MODE_PWM0
/// float [0, 100]
#define LIB_TIMER3_CH0_DUTY	10.0
#endif

#if LIB_TIMER3_USE_CH1
#define LIB_TIMER3_CH1_RCU	RCU_GPIOD
#define LIB_TIMER3_CH1_PIN	GPIOD, GPIO_PIN_13
#define LIB_TIMER3_CH1_MODE	TIMER_OC_MODE_PWM0
/// float [0, 100]
#define LIB_TIMER3_CH1_DUTY	20.0
#endif

#if LIB_TIMER3_USE_CH2
#define LIB_TIMER3_CH2_RCU	RCU_GPIOD
#define LIB_TIMER3_CH2_PIN	GPIOD, GPIO_PIN_14
#define LIB_TIMER3_CH2_MODE	TIMER_OC_MODE_PWM0
/// float [0, 100]
#define LIB_TIMER3_CH2_DUTY	30.0
#endif

#if LIB_TIMER3_USE_CH3
#define LIB_TIMER3_CH3_RCU	RCU_GPIOB
#define LIB_TIMER3_CH3_PIN	GPIOB, GPIO_PIN_9
#define LIB_TIMER3_CH3_MODE	TIMER_OC_MODE_PWM0
/// float [0, 100]
#define LIB_TIMER3_CH3_DUTY	0.0
#endif

#endif

#endif


/******************* TIMER 4 ***************/
#if USE_LIB_TIMER_4

///// 0: base  1: output
#define LIB_TIMER4_MODE		1

///// 1秒钟执行 FREQ 次
///// PSC * FREQ  >  主频 / 65536
#define LIB_TIMER4_PSC		10
#define LIB_TIMER4_FREQ		1000

#if LIB_TIMER4_MODE == 0
/////// 基础功能
#define LIB_TIMER4_NVIC		0, 0
#define LIB_TIMER4_CB		1
#elif LIB_TIMER4_MODE == 1
/////// 通用功能
#define LIB_TIMER4_USE_CH0	0
#define LIB_TIMER4_USE_CH1	0
#define LIB_TIMER4_USE_CH2	0
#define LIB_TIMER4_USE_CH3	1

/**
*|	 CH			| 		PIN
*|--------------|-----------------
*|   CH0		|	PA0	PH10
*|--------------|-----------------
*|   CH1		|	PA1	PH11
*|--------------|-----------------
*|   CH2 		|	PA2	PH12
*|--------------|-----------------
*|   CH3 		|	PA3	PI0
*/
#if LIB_TIMER4_USE_CH0
#define LIB_TIMER4_CH0_RCU	RCU_GPIOD
#define LIB_TIMER4_CH0_PIN	GPIOD, GPIO_PIN_12

#define LIB_TIMER4_CH0_MODE	TIMER_OC_MODE_PWM0
/// float [0, 100]
#define LIB_TIMER4_CH0_DUTY	10.0
#endif

#if LIB_TIMER4_USE_CH1
#define LIB_TIMER4_CH1_RCU	RCU_GPIOD
#define LIB_TIMER4_CH1_PIN	GPIOD, GPIO_PIN_13
#define LIB_TIMER4_CH1_MODE	TIMER_OC_MODE_PWM0
/// float [0, 100]
#define LIB_TIMER4_CH1_DUTY	20.0
#endif

#if LIB_TIMER4_USE_CH2
#define LIB_TIMER4_CH2_RCU	RCU_GPIOD
#define LIB_TIMER4_CH2_PIN	GPIOD, GPIO_PIN_14
#define LIB_TIMER4_CH2_MODE	TIMER_OC_MODE_PWM0
/// float [0, 100]
#define LIB_TIMER4_CH2_DUTY	30.0
#endif

#if LIB_TIMER4_USE_CH3
#define LIB_TIMER4_CH3_RCU	RCU_GPIOB
#define LIB_TIMER4_CH3_PIN	GPIOB, GPIO_PIN_9
#define LIB_TIMER4_CH3_MODE	TIMER_OC_MODE_PWM0
/// float [0, 100]
#define LIB_TIMER4_CH3_DUTY	0.0
#endif

#endif

#endif


/******************* TIMER 5 ***************/
#if USE_LIB_TIMER_5

#define LIB_TIMER5_NVIC		0, 0

///// 1秒钟执行 FREQ 次
///// PSC * FREQ  >  主频 / 65536
#define LIB_TIMER5_PSC		5
#define LIB_TIMER5_FREQ		1000

#define LIB_TIMER5_CB		1

#endif



/******************* TIMER 6 ***************/
#if USE_LIB_TIMER_6

#define LIB_TIMER6_NVIC		0, 0

///// 1秒钟执行 FREQ 次
///// PSC * FREQ  >  主频 / 65536
#define LIB_TIMER6_PSC		5000
#define LIB_TIMER6_FREQ		100

#define LIB_TIMER6_CB		1

#endif



/******************* TIMER 7 ***************/
#if USE_LIB_TIMER_7

///// 0: base  1: output
#define LIB_TIMER7_MODE		1

///// 1秒钟执行 FREQ 次
///// PSC * FREQ  >  主频 / 65536
#define LIB_TIMER7_PSC		10
#define LIB_TIMER7_FREQ		1000

#if LIB_TIMER7_MODE == 0
/////// 基础功能
#define LIB_TIMER7_NVIC		0, 0
#define LIB_TIMER7_CB		1
#elif LIB_TIMER7_MODE == 1
/////// 通用功能
#define LIB_TIMER7_USE_CH0_P	1
#define LIB_TIMER7_USE_CH0_N	1
#define LIB_TIMER7_USE_CH1_P	1
#define LIB_TIMER7_USE_CH1_N	1
#define LIB_TIMER7_USE_CH2_P	1
#define LIB_TIMER7_USE_CH2_N	1
#define LIB_TIMER7_USE_CH3		1

/**
*|	 CH			| 		PIN
*|--------------|----------------------------------------
*|   CH0		|	OP:	PC6 PI15	|	ON:	PA5 PA7 PH13
*|--------------|----------------------------------------
*|   CH1		|	OP:	PC7 PI6		|	ON:	PB0 PB14 PH14
*|--------------|----------------------------------------
*|   CH2 		|	OP:	PC8 PI7		|	ON:	PB1 PB15 PH15
*|--------------|----------------------------------------
*|   CH3 		|	PC9 PI2
*/
////////// CH0
#if LIB_TIMER7_USE_CH0_P
#define LIB_TIMER7_CH0_P_RCU	RCU_GPIOD
#define LIB_TIMER7_CH0_P_PIN	GPIOD, GPIO_PIN_12
#endif
#if LIB_TIMER7_USE_CH0_N
#define LIB_TIMER7_CH0_N_RCU	RCU_GPIOD
#define LIB_TIMER7_CH0_N_PIN	GPIOD, GPIO_PIN_12
#endif
#if LIB_TIMER7_USE_CH0_P || LIB_TIMER7_USE_CH0_N 
#define LIB_TIMER7_CH0_MODE	TIMER_OC_MODE_PWM0
/// float [0, 100]
#define LIB_TIMER7_CH0_DUTY		10.0
#endif

////////// CH1
#if LIB_TIMER7_USE_CH1_P
#define LIB_TIMER7_CH1_P_RCU	RCU_GPIOD
#define LIB_TIMER7_CH1_P_PIN	GPIOD, GPIO_PIN_12
#endif
#if LIB_TIMER7_USE_CH1_N
#define LIB_TIMER7_CH1_N_RCU	RCU_GPIOD
#define LIB_TIMER7_CH1_N_PIN	GPIOD, GPIO_PIN_12
#endif
#if LIB_TIMER7_USE_CH1_P || LIB_TIMER7_USE_CH1_N 
#define LIB_TIMER7_CH1_MODE	TIMER_OC_MODE_PWM0
/// float [0, 100]
#define LIB_TIMER7_CH1_DUTY		10.0
#endif

////////// CH2
#if LIB_TIMER7_USE_CH2_P
#define LIB_TIMER7_CH2_P_RCU	RCU_GPIOD
#define LIB_TIMER7_CH2_P_PIN	GPIOD, GPIO_PIN_12
#endif
#if LIB_TIMER7_USE_CH2_N
#define LIB_TIMER7_CH2_N_RCU	RCU_GPIOD
#define LIB_TIMER7_CH2_N_PIN	GPIOD, GPIO_PIN_12
#endif
#if LIB_TIMER7_USE_CH2_P || LIB_TIMER7_USE_CH2_N 
#define LIB_TIMER7_CH2_MODE	TIMER_OC_MODE_PWM0
/// float [0, 100]
#define LIB_TIMER7_CH2_DUTY		10.0
#endif

////////// CH3
#if LIB_TIMER7_USE_CH3
#define LIB_TIMER7_CH3_RCU		RCU_GPIOD
#define LIB_TIMER7_CH3_PIN		GPIOD, GPIO_PIN_12
#define LIB_TIMER7_CH3_MODE		TIMER_OC_MODE_PWM0
/// float [0, 100]
#define LIB_TIMER7_CH3_DUTY		10.0
#endif

#endif /** LIB_TIMER0_MODE **/


#endif /** USE_LIB_TIMER_0 **/



/******************* TIMER 8 ***************/
#if USE_LIB_TIMER_8

///// 0: base  1: output
#define LIB_TIMER8_MODE		1

///// 1秒钟执行 FREQ 次
///// PSC * FREQ  >  主频 / 65536
#define LIB_TIMER8_PSC		10
#define LIB_TIMER8_FREQ		1000

#if LIB_TIMER8_MODE == 0
/////// 基础功能
#define LIB_TIMER8_NVIC		0, 0
#define LIB_TIMER8_CB		1
#elif LIB_TIMER8_MODE == 1
/////// 通用功能
#define LIB_TIMER8_USE_CH0	1
#define LIB_TIMER8_USE_CH1	1

/**
*|	CH			| 		PIN
*|--------------|-----------------
*|   CH0		|	PA2	PE5
*|--------------|-----------------
*|   CH1		|	PA3 PE6
*|--------------|-----------------
*/
#if LIB_TIMER8_USE_CH0
#define LIB_TIMER8_CH0_RCU	RCU_GPIOD
#define LIB_TIMER8_CH0_PIN	GPIOD, GPIO_PIN_12
#define LIB_TIMER8_CH0_MODE	TIMER_OC_MODE_PWM0
/// float [0, 100]
#define LIB_TIMER8_CH0_DUTY	10.0
#endif

#if LIB_TIMER8_USE_CH1
#define LIB_TIMER8_CH1_RCU	RCU_GPIOD
#define LIB_TIMER8_CH1_PIN	GPIOD, GPIO_PIN_13
#define LIB_TIMER8_CH1_MODE	TIMER_OC_MODE_PWM0
/// float [0, 100]
#define LIB_TIMER8_CH1_DUTY	20.0
#endif


#endif

#endif

/******************* TIMER 9 ***************/
#if USE_LIB_TIMER_9

///// 0: base  1: output
#define LIB_TIMER9_MODE		1

///// 1秒钟执行 FREQ 次
///// PSC * FREQ  >  主频 / 65536
#define LIB_TIMER9_PSC		10
#define LIB_TIMER9_FREQ		1000

#if LIB_TIMER9_MODE == 0
/////// 基础功能
#define LIB_TIMER9_NVIC		0, 0
#define LIB_TIMER9_CB		1
#elif LIB_TIMER9_MODE == 1
/////// 通用功能
#define LIB_TIMER9_USE_CH0	1

/**
*|	CH			| 		PIN
*|--------------|-----------------
*|   CH0		|	PB8	PF6
*|--------------|-----------------
*/
#if LIB_TIMER9_USE_CH0
#define LIB_TIMER9_CH0_RCU	RCU_GPIOB
#define LIB_TIMER9_CH0_PIN	GPIOB, GPIO_PIN_8
#define LIB_TIMER9_CH0_MODE	TIMER_OC_MODE_PWM0
/// float [0, 100]
#define LIB_TIMER9_CH0_DUTY	10.0
#endif

#endif

#endif


/******************* TIMER 10 ***************/
#if USE_LIB_TIMER_10

///// 0: base  1: output
#define LIB_TIMER10_MODE		1

///// 1秒钟执行 FREQ 次
///// PSC * FREQ  >  主频 / 65536
#define LIB_TIMER10_PSC		10
#define LIB_TIMER10_FREQ		1000

#if LIB_TIMER10_MODE == 0
/////// 基础功能
#define LIB_TIMER10_NVIC		0, 0
#define LIB_TIMER10_CB		1
#elif LIB_TIMER10_MODE == 1
/////// 通用功能
#define LIB_TIMER10_USE_CH0	1

/**
*|	CH			| 		PIN
*|--------------|-----------------
*|   CH0		|	PB9	PF7
*|--------------|-----------------
*/
#if LIB_TIMER10_USE_CH0
#define LIB_TIMER10_CH0_RCU		RCU_GPIOB
#define LIB_TIMER10_CH0_PIN		GPIOB, GPIO_PIN_9
#define LIB_TIMER10_CH0_MODE	TIMER_OC_MODE_PWM0
/// float [0, 100]
#define LIB_TIMER10_CH0_DUTY	10.0
#endif

#endif

#endif


/******************* TIMER 11 ***************/
#if USE_LIB_TIMER_11

///// 0: base  1: output
#define LIB_TIMER11_MODE		1

///// 1秒钟执行 FREQ 次
///// PSC * FREQ  >  主频 / 65536
#define LIB_TIMER11_PSC		10
#define LIB_TIMER11_FREQ		1000

#if LIB_TIMER11_MODE == 0
/////// 基础功能
#define LIB_TIMER11_NVIC		0, 0
#define LIB_TIMER11_CB		1
#elif LIB_TIMER11_MODE == 1
/////// 通用功能
#define LIB_TIMER11_USE_CH0	1
#define LIB_TIMER11_USE_CH1	1

/**
*|	CH			| 		PIN
*|--------------|-----------------
*|   CH0		|	PB14 PH6
*|--------------|-----------------
*|   CH1		|	PB15 PF6
*|--------------|-----------------
*/
#if LIB_TIMER11_USE_CH0
#define LIB_TIMER11_CH0_RCU		RCU_GPIOD
#define LIB_TIMER11_CH0_PIN		GPIOD, GPIO_PIN_12
#define LIB_TIMER11_CH0_MODE	TIMER_OC_MODE_PWM0
/// float [0, 100]
#define LIB_TIMER11_CH0_DUTY	10.0
#endif

#if LIB_TIMER11_USE_CH1
#define LIB_TIMER11_CH1_RCU		RCU_GPIOD
#define LIB_TIMER11_CH1_PIN		GPIOD, GPIO_PIN_13
#define LIB_TIMER11_CH1_MODE	TIMER_OC_MODE_PWM0
/// float [0, 100]
#define LIB_TIMER11_CH1_DUTY	20.0
#endif

#endif

#endif


/******************* TIMER 12 ***************/
#if USE_LIB_TIMER_12

///// 0: base  1: output
#define LIB_TIMER12_MODE		1

///// 1秒钟执行 FREQ 次
///// PSC * FREQ  >  主频 / 65536
#define LIB_TIMER12_PSC		10
#define LIB_TIMER12_FREQ		1000

#if LIB_TIMER12_MODE == 0
/////// 基础功能
#define LIB_TIMER12_NVIC		0, 0
#define LIB_TIMER12_CB		1
#elif LIB_TIMER12_MODE == 1
/////// 通用功能
#define LIB_TIMER12_USE_CH0	1

/**
*|	CH			| 		PIN
*|--------------|-----------------
*|   CH0		|	PA6	PF8
*|--------------|-----------------
*/
#if LIB_TIMER12_USE_CH0
#define LIB_TIMER12_CH0_RCU		RCU_GPIOA
#define LIB_TIMER12_CH0_PIN		GPIOA, GPIO_PIN_6
#define LIB_TIMER12_CH0_MODE	TIMER_OC_MODE_PWM0
/// float [0, 100]
#define LIB_TIMER12_CH0_DUTY	10.0
#endif

#endif

#endif


/******************* TIMER 13 ***************/
#if USE_LIB_TIMER_13

///// 0: base  1: output
#define LIB_TIMER13_MODE		1

///// 1秒钟执行 FREQ 次
///// PSC * FREQ  >  主频 / 65536
#define LIB_TIMER13_PSC		10
#define LIB_TIMER13_FREQ		1000

#if LIB_TIMER13_MODE == 0
/////// 基础功能
#define LIB_TIMER13_NVIC		0, 0
#define LIB_TIMER13_CB		1
#elif LIB_TIMER13_MODE == 1
/////// 通用功能
#define LIB_TIMER13_USE_CH0	1

/**
*|	CH			| 		PIN
*|--------------|-----------------
*|   CH0		|	PA7	PF9
*|--------------|-----------------
*/
#if LIB_TIMER13_USE_CH0
#define LIB_TIMER13_CH0_RCU		RCU_GPIOA
#define LIB_TIMER13_CH0_PIN		GPIOA, GPIO_PIN_7
#define LIB_TIMER13_CH0_MODE	TIMER_OC_MODE_PWM0
/// float [0, 100]
#define LIB_TIMER13_CH0_DUTY	10.0
#endif

#endif

#endif




/**************************************************************/
static inline void afio_init(rcu_periph_enum rcu, uint32_t port, uint32_t pin, uint32_t af) {
	rcu_periph_clock_enable(rcu);
	gpio_mode_set(port, GPIO_MODE_AF, GPIO_PUPD_NONE, pin);
	gpio_output_options_set(port, GPIO_OTYPE_PP, GPIO_OSPEED_MAX, pin);
	
	gpio_af_set(port, af, pin);
}

static inline void chn_init(uint32_t timerx, uint16_t chn, uint16_t mode, uint16_t period, float duty) {
	timer_oc_parameter_struct ocpara;

	timer_channel_output_struct_para_init(&ocpara);//设置默认值
	ocpara.outputstate  = (uint16_t)TIMER_CCX_ENABLE;
	timer_channel_output_config(timerx, chn, &ocpara);
	
	timer_channel_output_mode_config(timerx, chn, mode);

	uint16_t pulse = (uint16_t)(duty * period / 100.0) - 1;
	timer_channel_output_pulse_value_config(timerx, chn, pulse);
}

static inline void chn_out(uint32_t timerx, uint16_t chn, uint16_t mode, uint16_t period, float duty) {
	timer_channel_output_mode_config(timerx, chn, mode);
	uint16_t pulse = (uint16_t)(duty * period / 100.0) - 1;
	timer_channel_output_pulse_value_config(timerx, chn, pulse);
}








#endif