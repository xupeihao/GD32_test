#include "lib_peripheral.h"






void lib_peripheral_init() {
#if USE_LIB_USART
	lib_usart_init();
#endif
#if USE_LIB_TIMER
	lib_timer_init();
#endif
#if USE_LIB_EXTI	
	lib_exti_init();
#endif
#if USE_LIB_RTC	
	lib_rtc_init();
#endif

#if USE_LIB_WDOG
	lib_wdog_init();
#endif
	
#if USE_LIB_ADC
	lib_adc_init();
#endif
	
#if USE_LIB_SPI
	lib_spi_init();
#endif

#if USE_LIB_I2C
	lib_i2c_init();
#endif

}
