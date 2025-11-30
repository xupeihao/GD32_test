#ifndef __LIB_USART_H__
#define __LIB_USART_H__

#include "usart_config.h"

#if USE_LIB_USART_0
#include "lib_usart0.h"
#endif

#if USE_LIB_USART_1
#include "lib_usart1.h"
#endif

#if USE_LIB_USART_2
#include "lib_usart2.h"
#endif

#if USE_LIB_USART_3
#include "lib_usart3.h"
#endif

#if USE_LIB_USART_4
#include "lib_usart4.h"
#endif

#if USE_LIB_USART_5
#include "lib_usart5.h"
#endif

#if USE_LIB_USART_6
#include "lib_usart6.h"
#endif

#if USE_LIB_USART_7
#include "lib_usart7.h"
#endif


void lib_usart_init();  // 统一初始化函数

#endif