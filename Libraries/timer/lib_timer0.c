#include "lib_timer0.h"

#if USE_LIB_TIMER_0


#define __TIMERx_RCU		RCU_TIMER0
#define __TIMERx			TIMER0
#define __TIMERx_IRQn		TIMER0_IRQn
///// 查手册
#define __TIMERx_AF			GPIO_AF_1

#define __TIMERx_PSC		LIB_TIMER0_PSC
#define __TIMERx_FREQ		LIB_TIMER0_FREQ

#define __TIMERx_MODE				LIB_TIMER0_MODE
#define __TIMERx_FUNC_INIT			lib_timer0_init
#define __TIMERx_FUNC_UPDATE_PERIOD	lib_timer0_update_period

#if __TIMERx_MODE == 0
#define __TIMERx_NVIC		LIB_TIMER0_NVIC
#define __TIMERx_CB			LIB_TIMER0_CB

#define __TIMERx_FUNC_IRQ	TIMER0_IRQHandler
#define __TIMERx_FUNC_CB	lib_timer0_on_cb
#elif __TIMERx_MODE == 1

#define __TIMERx_USE_CH0_P	LIB_TIMER0_USE_CH0_P
#define __TIMERx_USE_CH0_N	LIB_TIMER0_USE_CH0_N
#define __TIMERx_USE_CH1_P	LIB_TIMER0_USE_CH1_P
#define __TIMERx_USE_CH1_N	LIB_TIMER0_USE_CH1_N
#define __TIMERx_USE_CH2_P	LIB_TIMER0_USE_CH2_P
#define __TIMERx_USE_CH2_N	LIB_TIMER0_USE_CH2_N
#define __TIMERx_USE_CH3	LIB_TIMER0_USE_CH3

#if __TIMERx_USE_CH0_P
#define __TIMERx_CH0_P_RCU		LIB_TIMER0_CH0_P_RCU
#define __TIMERx_CH0_P_PIN		LIB_TIMER0_CH0_P_PIN
#endif
#if __TIMERx_USE_CH0_N
#define __TIMERx_CH0_N_RCU		LIB_TIMER0_CH0_N_RCU
#define __TIMERx_CH0_N_PIN		LIB_TIMER0_CH0_N_PIN
#endif
#if __TIMERx_USE_CH0_P || __TIMERx_USE_CH0_N
#define __TIMERx_CH0_MODE		LIB_TIMER0_CH0_MODE
#define __TIMERx_CH0_DUTY		LIB_TIMER0_CH0_DUTY
#define __TIMERx_CH0_FUNC_DUTY	lib_timer0_ch0_duty
#endif

#if __TIMERx_USE_CH1_P
#define __TIMERx_CH1_P_RCU		LIB_TIMER0_CH1_P_RCU
#define __TIMERx_CH1_P_PIN		LIB_TIMER0_CH1_P_PIN
#endif
#if __TIMERx_USE_CH1_N
#define __TIMERx_CH1_N_RCU		LIB_TIMER0_CH1_N_RCU
#define __TIMERx_CH1_N_PIN		LIB_TIMER0_CH1_N_PIN
#endif
#if __TIMERx_USE_CH1_P || __TIMERx_USE_CH1_N
#define __TIMERx_CH1_MODE		LIB_TIMER0_CH1_MODE
#define __TIMERx_CH1_DUTY		LIB_TIMER0_CH1_DUTY
#define __TIMERx_CH1_FUNC_DUTY	lib_timer0_ch1_duty
#endif

#if __TIMERx_USE_CH2_P
#define __TIMERx_CH2_P_RCU		LIB_TIMER0_CH2_P_RCU
#define __TIMERx_CH2_P_PIN		LIB_TIMER0_CH2_P_PIN
#endif
#if __TIMERx_USE_CH2_N
#define __TIMERx_CH2_N_RCU		LIB_TIMER0_CH2_N_RCU
#define __TIMERx_CH2_N_PIN		LIB_TIMER0_CH2_N_PIN
#endif
#if __TIMERx_USE_CH2_P || __TIMERx_USE_CH2_N
#define __TIMERx_CH2_MODE		LIB_TIMER0_CH2_MODE
#define __TIMERx_CH2_DUTY		LIB_TIMER0_CH2_DUTY
#define __TIMERx_CH2_FUNC_DUTY	lib_timer0_ch2_duty
#endif

#if __TIMERx_USE_CH3
#define __TIMERx_CH3_RCU		LIB_TIMER0_CH3_RCU
#define __TIMERx_CH3_PIN		LIB_TIMER0_CH3_PIN
#define __TIMERx_CH3_MODE		LIB_TIMER0_CH3_MODE
#define __TIMERx_CH3_DUTY		LIB_TIMER0_CH3_DUTY
#define __TIMERx_CH3_FUNC_DUTY	lib_timer0_ch3_duty
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
	#if __TIMERx_USE_CH0_P
	////// CH0_P
	afio_init(__TIMERx_CH0_P_RCU, __TIMERx_CH0_P_PIN, __TIMERx_AF);
	#endif
	#if __TIMERx_USE_CH0_N
	////// CH0_N
	afio_init(__TIMERx_CH0_N_RCU, __TIMERx_CH0_N_PIN, __TIMERx_AF);
	#endif
	#if __TIMERx_USE_CH1_P
	////// CH1_P
	afio_init(__TIMERx_CH1_P_RCU, __TIMERx_CH1_P_PIN, __TIMERx_AF);
	#endif
	#if __TIMERx_USE_CH1_N
	////// CH1_N
	afio_init(__TIMERx_CH1_N_RCU, __TIMERx_CH1_N_PIN, __TIMERx_AF);
	#endif
	#if __TIMERx_USE_CH2_P
	////// CH2_P
	afio_init(__TIMERx_CH2_P_RCU, __TIMERx_CH2_P_PIN, __TIMERx_AF);
	#endif
	#if __TIMERx_USE_CH2_N
	////// CH2_N
	afio_init(__TIMERx_CH2_N_RCU, __TIMERx_CH2_N_PIN, __TIMERx_AF);
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

	timer_oc_parameter_struct ocpara;


#if __TIMERx_USE_CH0_P || __TIMERx_USE_CH0_N
	timer_channel_output_struct_para_init(&ocpara);//设置默认值
	#if __TIMERx_USE_CH0_P
	ocpara.outputstate  = (uint16_t)TIMER_CCX_ENABLE;
	#endif
	#if __TIMERx_USE_CH0_N
	ocpara.outputnstate = TIMER_CCXN_ENABLE;
	#endif
	chn_out(__TIMERx, TIMER_CH_0, __TIMERx_CH0_MODE, period, __TIMERx_CH0_DUTY);
#endif
#if __TIMERx_USE_CH1_P || __TIMERx_USE_CH1_N
	timer_channel_output_struct_para_init(&ocpara);//设置默认值
	#if __TIMERx_USE_CH1_P
	ocpara.outputstate  = (uint16_t)TIMER_CCX_ENABLE;
	#endif
	#if __TIMERx_USE_CH1_N
	ocpara.outputnstate = TIMER_CCXN_ENABLE;
	#endif
	chn_out(__TIMERx, TIMER_CH_1, __TIMERx_CH1_MODE, period, __TIMERx_CH1_DUTY);
#endif
#if __TIMERx_USE_CH2_P || __TIMERx_USE_CH2_N
	timer_channel_output_struct_para_init(&ocpara);//设置默认值
	#if __TIMERx_USE_CH2_P
	ocpara.outputstate  = (uint16_t)TIMER_CCX_ENABLE;
	#endif
	#if __TIMERx_USE_CH2_N
	ocpara.outputnstate = TIMER_CCXN_ENABLE;
	#endif
	chn_out(__TIMERx, TIMER_CH_2, __TIMERx_CH2_MODE, period, __TIMERx_CH2_DUTY);
#endif
#if __TIMERx_USE_CH3
	chn_init(__TIMERx, TIMER_CH_3, __TIMERx_CH3_MODE, period, __TIMERx_CH3_DUTY);
#endif

	////// Break电路打开
	timer_break_parameter_struct breakpara;
	timer_break_struct_para_init(&breakpara);// 默认值
    breakpara.breakpolarity   = TIMER_BREAK_POLARITY_HIGH;
    breakpara.outputautostate = TIMER_OUTAUTO_ENABLE;
    breakpara.breakstate      = TIMER_BREAK_ENABLE;
    timer_break_config(__TIMERx, &breakpara);
	timer_break_enable(__TIMERx);
	
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
#if __TIMERx_USE_CH0_P || LIB_TIMER0_USE_CH0_N
void __TIMERx_CH0_FUNC_DUTY(float duty) {
	// [0, 100]
	if(duty < 0) duty = 0;
	if(duty > 100) duty = 100;
	uint16_t pulse = (uint16_t)(duty * period / 100.0) - 1;
	timer_channel_output_pulse_value_config(__TIMERx, TIMER_CH_0, pulse);
}
#endif
#if __TIMERx_USE_CH1_P || LIB_TIMER0_USE_CH1_N
void __TIMERx_CH1_FUNC_DUTY(float duty) {
	// [0, 100]
	if(duty < 0) duty = 0;
	if(duty > 100) duty = 100;
	uint16_t pulse = (uint16_t)(duty * period / 100.0) - 1;
	timer_channel_output_pulse_value_config(__TIMERx, TIMER_CH_1, pulse);
}
#endif
#if __TIMERx_USE_CH2_P || LIB_TIMER0_USE_CH2_N
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