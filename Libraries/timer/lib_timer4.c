#include "lib_timer4.h"

#if USE_LIB_TIMER_4


#define __TIMERx_RCU		RCU_TIMER4
#define __TIMERx			TIMER4
#define __TIMERx_IRQn		TIMER4_IRQn
///// 查手册
#define __TIMERx_AF			GPIO_AF_2

#define __TIMERx_PSC		LIB_TIMER4_PSC
#define __TIMERx_FREQ		LIB_TIMER4_FREQ

#define __TIMERx_MODE				LIB_TIMER4_MODE
#define __TIMERx_FUNC_INIT			lib_timer4_init
#define __TIMERx_FUNC_UPDATE_PERIOD	lib_timer4_update_period

#if __TIMERx_MODE == 0
#define __TIMERx_NVIC		LIB_TIMER4_NVIC
#define __TIMERx_CB			LIB_TIMER4_CB

#define __TIMERx_FUNC_IRQ	TIMER4_IRQHandler
#define __TIMERx_FUNC_CB	lib_timer4_on_cb
#elif __TIMERx_MODE == 1

#define __TIMERx_USE_CH0	LIB_TIMER4_USE_CH0
#define __TIMERx_USE_CH1	LIB_TIMER4_USE_CH1
#define __TIMERx_USE_CH2	LIB_TIMER4_USE_CH2
#define __TIMERx_USE_CH3	LIB_TIMER4_USE_CH3

#if __TIMERx_USE_CH0
#define __TIMERx_CH0_RCU		LIB_TIMER4_CH0_RCU
#define __TIMERx_CH0_PIN		LIB_TIMER4_CH0_PIN
#define __TIMERx_CH0_MODE		LIB_TIMER4_CH0_MODE
#define __TIMERx_CH0_DUTY		LIB_TIMER4_CH0_DUTY
#define __TIMERx_CH0_FUNC_DUTY	lib_timer4_ch0_duty
#endif
#if __TIMERx_USE_CH1
#define __TIMERx_CH1_RCU		LIB_TIMER4_CH1_RCU
#define __TIMERx_CH1_PIN		LIB_TIMER4_CH1_PIN
#define __TIMERx_CH1_MODE		LIB_TIMER4_CH1_MODE
#define __TIMERx_CH1_DUTY		LIB_TIMER4_CH1_DUTY
#define __TIMERx_CH1_FUNC_DUTY	lib_timer4_ch1_duty
#endif
#if __TIMERx_USE_CH2
#define __TIMERx_CH2_RCU		LIB_TIMER4_CH2_RCU
#define __TIMERx_CH2_PIN		LIB_TIMER4_CH2_PIN
#define __TIMERx_CH2_MODE		LIB_TIMER4_CH2_MODE
#define __TIMERx_CH2_DUTY		LIB_TIMER4_CH2_DUTY
#define __TIMERx_CH2_FUNC_DUTY	lib_timer4_ch2_duty
#endif
#if __TIMERx_USE_CH3
#define __TIMERx_CH3_RCU		LIB_TIMER4_CH3_RCU
#define __TIMERx_CH3_PIN		LIB_TIMER4_CH3_PIN
#define __TIMERx_CH3_MODE		LIB_TIMER4_CH3_MODE
#define __TIMERx_CH3_DUTY		LIB_TIMER4_CH3_DUTY
#define __TIMERx_CH3_FUNC_DUTY	lib_timer4_ch3_duty
#endif

#endif

static uint16_t period;


void __TIMERx_FUNC_INIT() {
	uint16_t psc = __TIMERx_PSC;
	float freq = __TIMERx_FREQ;
	// 周期值
	period = (uint16_t)(SystemCoreClock /(psc * freq));
	
#if __TIMERx_MODE == 1	
	/////////////////// GPIO ///////////////////////////
	#if __TIMERx_USE_CH0
	////// CH0
	afio_init(__TIMERx_CH0_RCU, __TIMERx_CH0_PIN, __TIMERx_AF);
	#endif
	#if __TIMERx_USE_CH1
	////// CH1
	afio_init(__TIMERx_CH1_RCU, __TIMERx_CH1_PIN, __TIMERx_AF);
	#endif
	#if __TIMERx_USE_CH2
	////// CH2
	afio_init(__TIMERx_CH2_RCU, __TIMERx_CH2_PIN, __TIMERx_AF);
	#endif
	#if __TIMERx_USE_CH3
	////// CH3
	afio_init(__TIMERx_CH3_RCU, __TIMERx_CH3_PIN, __TIMERx_AF);
	#endif
#endif
	
	//////////// TIMER //////////////////////
	rcu_periph_clock_enable(__TIMERx_RCU);
	
	timer_deinit(__TIMERx);
	timer_parameter_struct	initpara;
	timer_struct_para_init(&initpara); //设置默认值
	initpara.prescaler         = psc - 1;
	initpara.period            = period - 1;
	timer_init(__TIMERx, &initpara);
	

#if __TIMERx_MODE == 0
//////////////////////// BASE ////////////////////
	//// 配置中断
	timer_interrupt_enable(__TIMERx, TIMER_INT_UP);
	//// 中断优先级
	nvic_irq_enable(__TIMERx_IRQn, __TIMERx_NVIC);

#elif __TIMERx_MODE == 1
//////////////////////// OUTPUT ///////////////////

#if __TIMERx_USE_CH0
	chn_init(__TIMERx, TIMER_CH_0, __TIMERx_CH0_MODE, period, __TIMERx_CH0_DUTY);
#endif
#if __TIMERx_USE_CH1
	chn_init(__TIMERx, TIMER_CH_1, __TIMERx_CH1_MODE, period, __TIMERx_CH1_DUTY);
#endif
#if __TIMERx_USE_CH2
	chn_init(__TIMERx, TIMER_CH_2, __TIMERx_CH2_MODE, period, __TIMERx_CH2_DUTY);
#endif
#if __TIMERx_USE_CH3
	chn_init(__TIMERx, TIMER_CH_3, __TIMERx_CH3_MODE, period, __TIMERx_CH3_DUTY);
#endif

	
#endif
	
	timer_enable(__TIMERx);	
}


void __TIMERx_FUNC_UPDATE_PERIOD(uint16_t psc, float freq) {
	// 1秒钟执行 freq次，psc * freq > 主频/65536
	if(psc * freq < SystemCoreClock/65536) {
		printf("error: psc * freq < SystemCoreClock/65536");
		return;
	}
	
	// 周期值
	period = (uint16_t)(SystemCoreClock /(psc * freq));

	timer_parameter_struct	initpara;
	timer_struct_para_init(&initpara); //设置默认值
	initpara.prescaler         = psc - 1;
	initpara.period            = period - 1;
	timer_init(__TIMERx, &initpara);
}


#if __TIMERx_MODE == 0
//////////////////////// BASE ////////////////////
void __TIMERx_FUNC_IRQ() {

	if(SET == timer_interrupt_flag_get(__TIMERx, TIMER_INT_FLAG_UP)) {
		timer_interrupt_flag_clear(__TIMERx, TIMER_INT_FLAG_UP);
		
		// 回调
#if __TIMERx_CB
		__TIMERx_FUNC_CB();
#endif
	}
}
#elif __TIMERx_MODE == 1
//////////////////////// PWM OUT ////////////////////
#if __TIMERx_USE_CH0
void __TIMERx_CH0_FUNC_DUTY(float duty) {
	// [0, 100]
	if(duty < 0) duty = 0;
	if(duty > 100) duty = 100;
	uint16_t pulse = (uint16_t)(duty * period / 100.0) - 1;
	timer_channel_output_pulse_value_config(__TIMERx, TIMER_CH_0, pulse);
}
#endif
#if __TIMERx_USE_CH1
void __TIMERx_CH1_FUNC_DUTY(float duty) {
	// [0, 100]
	if(duty < 0) duty = 0;
	if(duty > 100) duty = 100;
	uint16_t pulse = (uint16_t)(duty * period / 100.0) - 1;
	timer_channel_output_pulse_value_config(__TIMERx, TIMER_CH_1, pulse);
}
#endif
#if __TIMERx_USE_CH2
void __TIMERx_CH2_FUNC_DUTY(float duty) {
	// [0, 100]
	if(duty < 0) duty = 0;
	if(duty > 100) duty = 100;
	uint16_t pulse = (uint16_t)(duty * period / 100.0) - 1;
	timer_channel_output_pulse_value_config(__TIMERx, TIMER_CH_2, pulse);
}
#endif
#if __TIMERx_USE_CH3
void __TIMERx_CH3_FUNC_DUTY(float duty) {
	// [0, 100]
	if(duty < 0) duty = 0;
	if(duty > 100) duty = 100;
	uint16_t pulse = (uint16_t)(duty * period / 100.0) - 1;
	timer_channel_output_pulse_value_config(__TIMERx, TIMER_CH_3, pulse);
}
#endif
#endif



#endif