#include "lib_usart.h"



void lib_usart_init() {
#if USE_LIB_USART_0
	lib_usart0_init();
#endif

#if USE_LIB_USART_1
	lib_usart1_init();
#endif

#if USE_LIB_USART_2
	lib_usart2_init();
#endif

#if USE_LIB_USART_3
	lib_usart3_init();
#endif

#if USE_LIB_USART_4
	lib_usart4_init();
#endif

#if USE_LIB_USART_5
	lib_usart5_init();
#endif

#if USE_LIB_USART_6
	lib_usart6_init();
#endif

#if USE_LIB_USART_7
	lib_usart7_init();
#endif	
}