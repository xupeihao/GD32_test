#ifndef __USART_CONFIG_H__
#define __USART_CONFIG_H__

#include "gd32f4xx.h"
#include "gd32f4xx_gpio.h"
#include "gd32f4xx_rcu.h"
#include <stdio.h>


/// 通过配置文件去改动实现
// 串口的开关
#define USE_LIB_USART_0		1
#define USE_LIB_USART_1		0
#define USE_LIB_USART_2		0
#define USE_LIB_USART_3		0
#define USE_LIB_USART_4		0
#define USE_LIB_USART_5		0
#define USE_LIB_USART_6		0
#define USE_LIB_USART_7		0


/// 0 表示 串口0作为printf
/// 1 表示 串口1作为printf
/// 2 表示 串口2作为printf
#define USE_LIB_USART_PRINT	0


/******************* USART 0 配置 ********************/
/**
*---------------------------------
*	TXD			| 		RXD
*---------------|-----------------
*   PA9			|		PA10
*---------------|-----------------
*   PA15		|		PB3
*---------------|-----------------
*   PB6 		|		PB7
*---------------------------------
*/
#if USE_LIB_USART_0

#define LIB_USART0_ENABLE_TX		1
#define LIB_USART0_ENABLE_RX		1
#if LIB_USART0_ENABLE_TX
#define LIB_USART0_ENABLE_TX_DMA	0
#endif
#if LIB_USART0_ENABLE_RX
#define LIB_USART0_ENABLE_RX_DMA	0
#define LIB_USART0_RX_NVIC			2, 0
#define LIB_USART0_RX_LEN			128
#define LIB_USART0_RX_CALLBACK		0

#if LIB_USART0_ENABLE_RX_DMA
// DMA1 CH2 or DMA1 CH5
#define LIB_USART0_RX_DMA_RCU	RCU_DMA1
#define LIB_USART0_RX_DMA_CH	DMA1, DMA_CH2
#endif

#endif
#if LIB_USART0_ENABLE_TX
///// TXD
#define LIB_USART0_TX_RCU		RCU_GPIOA
#define LIB_USART0_TX_PIN		GPIOA, GPIO_PIN_9
#endif
#if LIB_USART0_ENABLE_RX
///// RXD
#define LIB_USART0_RX_RCU		RCU_GPIOA
#define LIB_USART0_RX_PIN		GPIOA, GPIO_PIN_10
#endif
//// USART config
#define LIB_USART0_BAUDRATE		115200
#define LIB_USART0_PARITY		USART_PM_NONE
#define LIB_USART0_DATA_LEN		USART_WL_8BIT
#define LIB_USART0_STOPBIT		USART_STB_1BIT

#endif

/******************* USART 1 配置 ********************/
/**
*---------------------------------
*	TXD			| 		RXD
*---------------|-----------------
*   PA2			|		PA3
*---------------|-----------------
*   PD5			|		PD6
*---------------------------------
*/
#if USE_LIB_USART_1

#define LIB_USART1_ENABLE_TX		1
#define LIB_USART1_ENABLE_RX		1
#if LIB_USART1_ENABLE_TX
#define LIB_USART1_ENABLE_TX_DMA	1
#endif
#if LIB_USART1_ENABLE_RX
#define LIB_USART1_ENABLE_RX_DMA	1
#define LIB_USART1_RX_NVIC			2, 0
#define LIB_USART1_RX_LEN			128
#define LIB_USART1_RX_CALLBACK		1
#endif

#if LIB_USART1_ENABLE_TX
///// TXD
#define LIB_USART1_TX_RCU		RCU_GPIOA
#define LIB_USART1_TX_PIN		GPIOA, GPIO_PIN_2
#endif
#if LIB_USART1_ENABLE_RX
///// RXD
#define LIB_USART1_RX_RCU		RCU_GPIOA
#define LIB_USART1_RX_PIN		GPIOA, GPIO_PIN_3
#endif
//// USART config
#define LIB_USART1_BAUDRATE		115200
#define LIB_USART1_PARITY		USART_PM_NONE
#define LIB_USART1_DATA_LEN		USART_WL_8BIT
#define LIB_USART1_STOPBIT		USART_STB_1BIT

#endif

/******************* USART 2 配置 ********************/
/**
*---------------------------------
*	TXD			| 		RXD
*---------------|-----------------
*   PB10		|		PB11
*---------------|-----------------
*   PC10		|		PC5
*---------------|-----------------
*   PD8 		|		PD9
*---------------------------------
*/
#if USE_LIB_USART_2

#define LIB_USART2_ENABLE_TX		1
#define LIB_USART2_ENABLE_RX		1
#if LIB_USART2_ENABLE_TX
#define LIB_USART2_ENABLE_TX_DMA	1
#endif
#if LIB_USART2_ENABLE_RX
#define LIB_USART2_ENABLE_RX_DMA	1
#define LIB_USART2_RX_NVIC			2, 0
#define LIB_USART2_RX_LEN			128
#define LIB_USART2_RX_CALLBACK		1
#endif

#if LIB_USART2_ENABLE_TX
///// TXD
#define LIB_USART2_TX_RCU		RCU_GPIOB
#define LIB_USART2_TX_PIN		GPIOB, GPIO_PIN_10
#endif
#if LIB_USART2_ENABLE_RX
///// RXD
#define LIB_USART2_RX_RCU		RCU_GPIOB
#define LIB_USART2_RX_PIN		GPIOB, GPIO_PIN_11
#endif
//// USART config
#define LIB_USART2_BAUDRATE		115200
#define LIB_USART2_PARITY		USART_PM_NONE
#define LIB_USART2_DATA_LEN		USART_WL_8BIT
#define LIB_USART2_STOPBIT		USART_STB_1BIT

#endif


/******************* USART 3 配置 ********************/
/**
*---------------------------------
*	TXD			| 		RXD
*---------------|-----------------
*   PA0			|		PA1
*---------------|-----------------
*   PC10		|		PC11
*---------------------------------
*/
#if USE_LIB_USART_3

#define LIB_USART3_ENABLE_TX		1
#define LIB_USART3_ENABLE_RX		1
#if LIB_USART3_ENABLE_TX
#define LIB_USART3_ENABLE_TX_DMA	1
#endif
#if LIB_USART3_ENABLE_RX
#define LIB_USART3_ENABLE_RX_DMA	1
#define LIB_USART3_RX_NVIC			2, 0
#define LIB_USART3_RX_LEN			128
#define LIB_USART3_RX_CALLBACK		1
#endif

#if LIB_USART3_ENABLE_TX
///// TXD
#define LIB_USART3_TX_RCU		RCU_GPIOA
#define LIB_USART3_TX_PIN		GPIOA, GPIO_PIN_0
#endif
#if LIB_USART3_ENABLE_RX
///// RXD
#define LIB_USART3_RX_RCU		RCU_GPIOA
#define LIB_USART3_RX_PIN		GPIOA, GPIO_PIN_1
#endif
//// USART config
#define LIB_USART3_BAUDRATE		115200
#define LIB_USART3_PARITY		USART_PM_NONE
#define LIB_USART3_DATA_LEN		USART_WL_8BIT
#define LIB_USART3_STOPBIT		USART_STB_1BIT

#endif


/******************* USART 4 配置 ********************/
/**
*---------------------------------
*	TXD			| 		RXD
*---------------|-----------------
*   PC12		|		PD2
*---------------------------------
*/
#if USE_LIB_USART_4

#define LIB_USART4_ENABLE_TX		1
#define LIB_USART4_ENABLE_RX		1
#if LIB_USART4_ENABLE_TX
#define LIB_USART4_ENABLE_TX_DMA	1
#endif
#if LIB_USART4_ENABLE_RX
#define LIB_USART4_ENABLE_RX_DMA	1
#define LIB_USART4_RX_NVIC			2, 0
#define LIB_USART4_RX_LEN			128
#define LIB_USART4_RX_CALLBACK		1
#endif

#if LIB_USART4_ENABLE_TX
///// TXD
#define LIB_USART4_TX_RCU		RCU_GPIOC
#define LIB_USART4_TX_PIN		GPIOC, GPIO_PIN_12
#endif
#if LIB_USART4_ENABLE_RX
///// RXD
#define LIB_USART4_RX_RCU		RCU_GPIOD
#define LIB_USART4_RX_PIN		GPIOD, GPIO_PIN_2
#endif
//// USART config
#define LIB_USART4_BAUDRATE		115200
#define LIB_USART4_PARITY		USART_PM_NONE
#define LIB_USART4_DATA_LEN		USART_WL_8BIT
#define LIB_USART4_STOPBIT		USART_STB_1BIT

#endif


/******************* USART 5 配置 ********************/
/**
*---------------------------------
*	TXD			| 		RXD
*---------------|-----------------
*   PA11		|		PA12
*---------------|-----------------
*   PC6 		|		PC7
*---------------|-----------------
*   PG14 		|		PG9
*---------------------------------
*/
#if USE_LIB_USART_5

#define LIB_USART5_ENABLE_TX		1
#define LIB_USART5_ENABLE_RX		1
#if LIB_USART5_ENABLE_TX
#define LIB_USART5_ENABLE_TX_DMA	1
#endif
#if LIB_USART5_ENABLE_RX
#define LIB_USART5_ENABLE_RX_DMA	1
#define LIB_USART5_RX_NVIC			2, 0
#define LIB_USART5_RX_LEN			128
#define LIB_USART5_RX_CALLBACK		1
#endif
#if LIB_USART5_ENABLE_TX_DMA
// DMA1 CH6 or DMA1 CH7
#define LIB_USART5_TX_DMA_RCU	RCU_DMA1
#define LIB_USART5_TX_DMA_CH	DMA1, DMA_CH6
#endif
#if LIB_USART5_ENABLE_RX_DMA
// DMA1 CH1 or DMA1 CH2
#define LIB_USART5_RX_DMA_RCU	RCU_DMA1
#define LIB_USART5_RX_DMA_CH	DMA1, DMA_CH1
#endif
#if LIB_USART5_ENABLE_TX
///// TXD
#define LIB_USART5_TX_RCU		RCU_GPIOA
#define LIB_USART5_TX_PIN		GPIOA, GPIO_PIN_11
#endif
#if LIB_USART5_ENABLE_RX
///// RXD
#define LIB_USART5_RX_RCU		RCU_GPIOA
#define LIB_USART5_RX_PIN		GPIOA, GPIO_PIN_12
#endif
//// USART config
#define LIB_USART5_BAUDRATE		115200
#define LIB_USART5_PARITY		USART_PM_NONE
#define LIB_USART5_DATA_LEN		USART_WL_8BIT
#define LIB_USART5_STOPBIT		USART_STB_1BIT

#endif

/******************* USART 6 配置 ********************/
/**
*---------------------------------
*	TXD			| 		RXD
*---------------|-----------------
*   PF7			|		PE8
*---------------|-----------------
*   PF6			|		PE7
*---------------------------------
*/
#if USE_LIB_USART_6

#define LIB_USART6_ENABLE_TX		1
#define LIB_USART6_ENABLE_RX		1
#if LIB_USART6_ENABLE_TX
#define LIB_USART6_ENABLE_TX_DMA	1
#endif
#if LIB_USART6_ENABLE_RX
#define LIB_USART6_ENABLE_RX_DMA	1
#define LIB_USART6_RX_NVIC			2, 0
#define LIB_USART6_RX_LEN			128
#define LIB_USART6_RX_CALLBACK		1
#endif

#if LIB_USART6_ENABLE_TX
///// TXD
#define LIB_USART6_TX_RCU		RCU_GPIOF
#define LIB_USART6_TX_PIN		GPIOF, GPIO_PIN_7
#endif
#if LIB_USART6_ENABLE_RX
///// RXD
#define LIB_USART6_RX_RCU		RCU_GPIOE
#define LIB_USART6_RX_PIN		GPIOE, GPIO_PIN_8
#endif
//// USART config
#define LIB_USART6_BAUDRATE		115200
#define LIB_USART6_PARITY		USART_PM_NONE
#define LIB_USART6_DATA_LEN		USART_WL_8BIT
#define LIB_USART6_STOPBIT		USART_STB_1BIT

#endif


/******************* USART 7 配置 ********************/
/**
*---------------------------------
*	TXD			| 		RXD
*---------------|-----------------
*   PE1			|		PE0
*---------------------------------
*/
#if USE_LIB_USART_7

#define LIB_USART7_ENABLE_TX		1
#define LIB_USART7_ENABLE_RX		1
#if LIB_USART7_ENABLE_TX
#define LIB_USART7_ENABLE_TX_DMA	1
#endif
#if LIB_USART7_ENABLE_RX
#define LIB_USART7_ENABLE_RX_DMA	1
#define LIB_USART7_RX_NVIC			2, 0
#define LIB_USART7_RX_LEN			128
#define LIB_USART7_RX_CALLBACK		1
#endif

#if LIB_USART7_ENABLE_TX
///// TXD
#define LIB_USART7_TX_RCU		RCU_GPIOE
#define LIB_USART7_TX_PIN		GPIOE, GPIO_PIN_1
#endif
#if LIB_USART7_ENABLE_RX
///// RXD
#define LIB_USART7_RX_RCU		RCU_GPIOE
#define LIB_USART7_RX_PIN		GPIOE, GPIO_PIN_0
#endif
//// USART config
#define LIB_USART7_BAUDRATE		115200
#define LIB_USART7_PARITY		USART_PM_NONE
#define LIB_USART7_DATA_LEN		USART_WL_8BIT
#define LIB_USART7_STOPBIT		USART_STB_1BIT

#endif





/************************************************ DONT change ***************************************/

static inline void lib_usart_gpio_init(rcu_periph_enum rcu, uint32_t port, uint32_t pin, uint32_t af) {
	rcu_periph_clock_enable(rcu);
	gpio_mode_set(port, GPIO_MODE_AF, GPIO_PUPD_PULLUP, pin);
	gpio_output_options_set(port, GPIO_OTYPE_PP, GPIO_OSPEED_MAX, pin);
	gpio_af_set(port, af, pin);
}




#endif