#include "App.h"

#include "lvgl.h"

#include "lv_port_disp.h"
#include "lv_port_indev.h"

#include "ui.h"


void App_ui_init() {


//	// LVGL框架初始化
	lv_init();
	
	// 硬件驱动初始化
	/// 1) 屏幕（方向问题）
	lv_port_disp_init();
	
	/// 2) 触摸
	lv_port_indev_init();
	
	/// TODO:
//	LCD_Init();//直接和硬件打交道
//	CST816T_Init();//直接和硬件打交道
	
//	// 界面
	ui_init();
	
	
	//// 设置当前的系统时钟
	lib_rtc_time_t time;
    time.year = 2025;
	time.month = 11;
	time.date = 12;
	time.week = 3;
	time.hour = 12;
	time.minute = 19;
	time.second = 33;
	lib_rtc_set_time(time);
	
}

void App_ui_lvgl_display_task() {
	lv_timer_handler();
}

void App_ui_lvgl_touch_task() {
	CST816T_scan();
}

void App_ui_rtc_task() {
	lib_rtc_time_t time;
	lib_rtc_get_time(&time);
	
	 char *weekdays[] = {"", "\u4e00", "\u4e8c", "\u4e09", "\u56db", "\u4e94", "\u516d", "\u65e5"};
	
	 // week: 0 到 6
	 // week: 1 到 7
	 
	lv_label_set_text_fmt(ui_lbYear, "%d", time.year);
    lv_label_set_text_fmt(ui_lbMonth, "%02d", time.month);
    lv_label_set_text_fmt(ui_lbDay, "%02d", time.date);
    lv_label_set_text_fmt(ui_lbWeek, "%s", weekdays[time.week]);
    lv_label_set_text_fmt(ui_lbHour, "%02d", time.hour);
    lv_label_set_text_fmt(ui_lbMinute, "%02d", time.minute);
    lv_label_set_text_fmt(ui_lbSecond, "%02d", time.second);
	
}
