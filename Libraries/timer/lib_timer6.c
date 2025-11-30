#include "lib_timer6.h"

#if USE_LIB_TIMER_6


#define __TIMERx_RCU		RCU_TIMER6
#define __TIMERx			TIMER6
#define __TIMERx_IRQn		TIMER6_IRQn

#define __TIMERx_NVIC		LIB_TIMER6_NVIC
#define __TIMERx_PSC		LIB_TIMER6_PSC
#define __TIMERx_FREQ		LIB_TIMER6_FREQ
#define __TIMERx_CB			LIB_TIMER6_CB

#define __TIMERx_FUNC_INIT	lib_timer6_init
#define __TIMERx_FUNC_IRQ	TIMER6_IRQHandler
#define __TIMERx_FUNC_CB	lib_timer6_on_cb

void __TIMERx_FUNC_INIT() {
	///// 1秒钟执行 freq 次
	//// psc * freq  >  主频 / 65536

	///// 初始 Timer5 
	///rcu
	rcu_periph_clock_enable(__TIMERx_RCU);
	
	///timer
	timer_deinit(__TIMERx);

	timer_parameter_struct	initpara;
	timer_struct_para_init(&initpara); //设置默认值
	
	initpara.prescaler         = __TIMERx_PSC - 1;						// 分频计数，是一个寄存器(16bit)
    
	/// 分频 * 频率 > 最小值 SystemCoreClock/65536 = 2564
	initpara.period            = SystemCoreClock / (__TIMERx_PSC * __TIMERx_FREQ) - 1;	// 周期计数器，是一个寄存器(16bit)
	
	
	timer_init(__TIMERx, &initpara);
	
	
	//// 配置中断
	timer_interrupt_enable(__TIMERx, TIMER_INT_UP);
	//// 中断优先级
	nvic_irq_enable(__TIMERx_IRQn, __TIMERx_NVIC);
	
	
	timer_enable(__TIMERx);
	
}


void __TIMERx_FUNC_IRQ() {

	if(SET == timer_interrupt_flag_get(__TIMERx, TIMER_INT_FLAG_UP)) {
		timer_interrupt_flag_clear(__TIMERx, TIMER_INT_FLAG_UP);
		
		// 回调
#if __TIMERx_CB
		__TIMERx_FUNC_CB();
#endif
	}

}



#endif