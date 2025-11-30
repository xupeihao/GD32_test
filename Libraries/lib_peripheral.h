#ifndef __LIB_PERIPHERAL_H__
#define __LIB_PERIPHERAL_H__


#include "usart/lib_usart.h"
#include "timer/lib_timer.h"
#include "exti/lib_exti.h"
#include "rtc/lib_rtc.h"
#include "wdog/lib_wdog.h"
#include "adc/lib_adc.h"
#include "spi/lib_spi.h"
#include "i2c/lib_i2c.h"

#if USE_LIB_USART_0 || USE_LIB_USART_1 || USE_LIB_USART_2 || USE_LIB_USART_3 || USE_LIB_USART_4 || USE_LIB_USART_5 || USE_LIB_USART_6 || USE_LIB_USART_7
#define USE_LIB_USART	1
#endif

#if USE_LIB_TIMER_0 || USE_LIB_TIMER_1 || USE_LIB_TIMER_2 || USE_LIB_TIMER_3 || USE_LIB_TIMER_4 || USE_LIB_TIMER_5 || USE_LIB_TIMER_6 || USE_LIB_TIMER_7 || USE_LIB_TIMER_8 || USE_LIB_TIMER_9 || USE_LIB_TIMER_10 || USE_LIB_TIMER_11 || USE_LIB_TIMER_12 || USE_LIB_TIMER_13
#define USE_LIB_TIMER	1
#endif

#if USE_LIB_EXTI_0	|| USE_LIB_EXTI_1 || USE_LIB_EXTI_2	|| USE_LIB_EXTI_3 || USE_LIB_EXTI_4	|| USE_LIB_EXTI_5 || USE_LIB_EXTI_6 || USE_LIB_EXTI_7 || USE_LIB_EXTI_8 || USE_LIB_EXTI_9 || USE_LIB_EXTI_10 || USE_LIB_EXTI_11 || USE_LIB_EXTI_12 || USE_LIB_EXTI_13 || USE_LIB_EXTI_14 || USE_LIB_EXTI_15
#define USE_LIB_EXTI	1
#endif

#if USE_LIB_ADC_0
#define USE_LIB_ADC		1
#endif

#if USE_LIB_SPI_0 || USE_LIB_SPI_1 || USE_LIB_SPI_2 || USE_LIB_SPI_3 || USE_LIB_SPI_4 || USE_LIB_SPI_5
#define USE_LIB_SPI		1
#endif

#if USE_LIB_I2C_0 || USE_LIB_I2C_1 || USE_LIB_I2C_2
#define USE_LIB_I2C		1
#endif

void lib_peripheral_init();


#endif