#ifndef __LIB_RTC_H__
#define __LIB_RTC_H__

#include "rtc_config.h"

#if USE_LIB_RTC

typedef struct {
	uint16_t year;
	uint8_t month;
	uint8_t date;
	uint8_t week;
	uint8_t hour;
	uint8_t minute;
	uint8_t second;
} lib_rtc_time_t;


#if LIB_RTC_USE_ALARM0 || LIB_RTC_USE_ALARM1
typedef struct {
	uint8_t date;
	uint8_t week;
	uint8_t date_week_state; // 0: disable 1: week 2: date
	uint8_t hour;
	uint8_t hour_enable;
	uint8_t minute;
	uint8_t minute_enable;
	uint8_t second;
	uint8_t second_enable;
} lib_rtc_alarm_t;

#define LIB_RTC_ALARM_DEFAULT	{0, 0, 0, 0, 0, 0, 0, 0, 0}

#endif


void lib_rtc_init();

void lib_rtc_config_clk(uint32_t clk);

void lib_rtc_set_time(lib_rtc_time_t time);
void lib_rtc_get_time(lib_rtc_time_t *time);

#if LIB_RTC_USE_ALARM0
void lib_rtc_config_alarm0(lib_rtc_alarm_t alarm);
extern void lib_rtc_on_alarm0();
#endif

#if LIB_RTC_USE_ALARM1
void lib_rtc_config_alarm1(lib_rtc_alarm_t alarm);
extern void lib_rtc_on_alarm1();
#endif


#endif

#endif