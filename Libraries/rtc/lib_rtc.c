#include "lib_rtc.h"

#if USE_LIB_RTC


static uint32_t rtc_clk_src;
static uint16_t factor_asyn;
static uint16_t factor_syn;
static uint16_t year_base = 2000;


#define WRITE_BCD(val) 	(((val / 10) << 4) + (val % 10))
#define READ_BCD(val) 	((val >> 4) * 10 + (val & 0x0F))

void lib_rtc_init() {
	rcu_periph_clock_enable(RCU_PMU);
    pmu_backup_write_enable();

#if LIB_RTC_USE_OSC == 1
	lib_rtc_config_clk(RCU_RTCSRC_IRC32K);
#elif LIB_RTC_USE_OSC == 2
	lib_rtc_config_clk(RCU_RTCSRC_HXTAL_DIV_RTCDIV);
#else
	lib_rtc_config_clk(RCU_RTCSRC_LXTAL);
#endif
}

void lib_rtc_config_clk(uint32_t clk) {
	
	if((RCU_BDCTL & RCU_BDCTL_RTCSRC) != clk) {
		rcu_bkp_reset_enable();
		rcu_bkp_reset_disable();
	}
	
	ErrStatus status = ERROR;
	if(clk == RCU_RTCSRC_LXTAL) {
		rcu_osci_on(RCU_LXTAL);
		status = rcu_osci_stab_wait(RCU_LXTAL);
		rcu_rtc_clock_config(RCU_RTCSRC_LXTAL);
		
		factor_asyn = 0x7F;
		factor_syn = 0xFF;
	} else if(clk == RCU_RTCSRC_IRC32K) {
		rcu_osci_on(RCU_IRC32K);
		status = rcu_osci_stab_wait(RCU_IRC32K);
		rcu_rtc_clock_config(RCU_RTCSRC_IRC32K);		
		
		factor_asyn = 0x7F;
		factor_syn = 0xF9;
	} else if(clk == RCU_RTCSRC_HXTAL_DIV_RTCDIV) {
		rcu_osci_on(RCU_HXTAL);
		status = rcu_osci_stab_wait(RCU_HXTAL);
		rcu_rtc_div_config(RCU_RTC_HXTAL_DIV8);
		rcu_rtc_clock_config(RCU_RTCSRC_HXTAL_DIV_RTCDIV);
		
		factor_asyn = 0x7F;
		factor_syn = (HXTAL_VALUE / 8) / 128 - 1;
	}
	if(status == ERROR) {
		printf("OSC start ERROR\r\n");
		return;
	}
	rtc_clk_src = clk;
	
	rcu_periph_clock_enable(RCU_RTC);
    rtc_register_sync_wait();
	
	rcu_all_reset_flag_clear();
}

void lib_rtc_set_time(lib_rtc_time_t time) {
	
	year_base = (time.year / 100) * 100;
	
    rtc_parameter_struct	rtc_initpara;
    rtc_initpara.year			= WRITE_BCD(time.year % 100);
    rtc_initpara.month			= WRITE_BCD(time.month);
    rtc_initpara.date			= WRITE_BCD(time.date);
    rtc_initpara.day_of_week	= WRITE_BCD(time.week);
    rtc_initpara.hour			= WRITE_BCD(time.hour);
    rtc_initpara.minute			= WRITE_BCD(time.minute);
    rtc_initpara.second			= WRITE_BCD(time.second);
    rtc_initpara.factor_asyn	= factor_asyn;
    rtc_initpara.factor_syn		= factor_syn; 
    rtc_initpara.am_pm			= time.hour >=12 ? RTC_PM : RTC_AM;
    rtc_initpara.display_format = RTC_24HOUR;

    rtc_init(&rtc_initpara);
}

void lib_rtc_get_time(lib_rtc_time_t *time) {
	
	rtc_parameter_struct	rtc_initpara;
    rtc_current_time_get(&rtc_initpara);

    time->year 		= READ_BCD(rtc_initpara.year) + year_base;
    time->month 	= READ_BCD(rtc_initpara.month);
    time->date 		= READ_BCD(rtc_initpara.date);
    time->week 		= READ_BCD(rtc_initpara.day_of_week);
    time->hour 		= READ_BCD(rtc_initpara.hour);
    time->minute 	= READ_BCD(rtc_initpara.minute);
    time->second 	= READ_BCD(rtc_initpara.second);
}


#if LIB_RTC_USE_ALARM0
void lib_rtc_config_alarm0(lib_rtc_alarm_t alarm) {
	rcu_all_reset_flag_clear();
	rtc_alarm_disable(RTC_ALARM0);
	rtc_alarm_struct rtc_alarm_time;
	
	// RTC_ALARM_DATE_MASK | RTC_ALARM_HOUR_MASK | RTC_ALARM_MINUTE_MASK;
	uint32_t mask = RTC_ALARM_ALL_MASK;
	if(alarm.date_week_state) {
		mask &= ~RTC_ALARM_DATE_MASK;
	}
	if(alarm.hour_enable) {
		mask &= ~RTC_ALARM_HOUR_MASK;
	}
	if(alarm.minute_enable) {
		mask &= ~RTC_ALARM_MINUTE_MASK;
	}
	if(alarm.second_enable) {
		mask &= ~RTC_ALARM_SECOND_MASK;
	}
	rtc_alarm_time.alarm_mask		= mask;
    rtc_alarm_time.weekday_or_date	= RTC_ALARM_DATE_SELECTED;
    rtc_alarm_time.alarm_day		= WRITE_BCD((alarm.date_week_state == 1) ? alarm.week : alarm.date);
    rtc_alarm_time.alarm_hour		= WRITE_BCD(alarm.hour);
    rtc_alarm_time.alarm_minute		= WRITE_BCD(alarm.minute);
    rtc_alarm_time.alarm_second		= WRITE_BCD(alarm.second);
    rtc_alarm_time.am_pm			= alarm.hour >= 12 ? RTC_PM : RTC_AM;
	
	rtc_alarm_config(RTC_ALARM0, &rtc_alarm_time);
	rtc_alarm_enable(RTC_ALARM0);
	rtc_flag_clear(RTC_FLAG_ALRM0);
	
	exti_init(EXTI_17, EXTI_INTERRUPT, EXTI_TRIG_RISING);
	exti_interrupt_enable(EXTI_17);
	exti_flag_clear(EXTI_17);
	
	rtc_interrupt_enable(RTC_INT_ALARM0);
	nvic_irq_enable(RTC_Alarm_IRQn, LIB_RTC_ALARM_NVIC);
}
#endif

#if LIB_RTC_USE_ALARM1
void lib_rtc_config_alarm1(lib_rtc_alarm_t alarm) {
		rcu_all_reset_flag_clear();
	rtc_alarm_disable(RTC_ALARM1);
	rtc_alarm_struct rtc_alarm_time;
	
	// RTC_ALARM_DATE_MASK | RTC_ALARM_HOUR_MASK | RTC_ALARM_MINUTE_MASK;
	uint32_t mask = RTC_ALARM_ALL_MASK;
	if(alarm.date_week_state) {
		mask &= ~RTC_ALARM_DATE_MASK;
	}
	if(alarm.hour_enable) {
		mask &= ~RTC_ALARM_HOUR_MASK;
	}
	if(alarm.minute_enable) {
		mask &= ~RTC_ALARM_MINUTE_MASK;
	}
	if(alarm.second_enable) {
		mask &= ~RTC_ALARM_SECOND_MASK;
	}
	rtc_alarm_time.alarm_mask		= mask;
    rtc_alarm_time.weekday_or_date	= RTC_ALARM_DATE_SELECTED;
    rtc_alarm_time.alarm_day		= WRITE_BCD((alarm.date_week_state == 1) ? alarm.week : alarm.date);
    rtc_alarm_time.alarm_hour		= WRITE_BCD(alarm.hour);
    rtc_alarm_time.alarm_minute		= WRITE_BCD(alarm.minute);
    rtc_alarm_time.alarm_second		= WRITE_BCD(alarm.second);
    rtc_alarm_time.am_pm			= alarm.hour >= 12 ? RTC_PM : RTC_AM;
	
	rtc_alarm_config(RTC_ALARM1, &rtc_alarm_time);
	rtc_alarm_enable(RTC_ALARM1);
	rtc_flag_clear(RTC_FLAG_ALRM1);
	
	exti_init(EXTI_17, EXTI_INTERRUPT, EXTI_TRIG_RISING);
	exti_interrupt_enable(EXTI_17);
	exti_flag_clear(EXTI_17);
	
	rtc_interrupt_enable(RTC_INT_ALARM1);
	nvic_irq_enable(RTC_Alarm_IRQn, LIB_RTC_ALARM_NVIC);
}
#endif


#if LIB_RTC_USE_ALARM0 || LIB_RTC_USE_ALARM1
void RTC_Alarm_IRQHandler() {

	if(SET == rtc_flag_get(RTC_FLAG_ALRM0) && SET == exti_interrupt_flag_get(EXTI_17)) {
		// clear
		exti_interrupt_flag_clear(EXTI_17);
		rtc_flag_clear(RTC_FLAG_ALRM0);
		
		#if LIB_RTC_USE_ALARM0
		lib_rtc_on_alarm0();
		#endif
	}
	
	if(SET == rtc_flag_get(RTC_FLAG_ALRM1) && SET == exti_interrupt_flag_get(EXTI_17)) {
		// clear
		exti_interrupt_flag_clear(EXTI_17);
		rtc_flag_clear(RTC_FLAG_ALRM1);
		
		#if LIB_RTC_USE_ALARM1
		lib_rtc_on_alarm1();
		#endif
	}
	
}
#endif


#endif