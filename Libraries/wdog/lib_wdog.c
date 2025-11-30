#include "lib_wdog.h"


#if LIB_WDOG_USE_FW
static uint16_t fw_timeout;
#endif

void lib_wdog_init() {
#if LIB_WDOG_USE_FW
	lib_wdog_config_fw(LIB_WDOG_FW_TIMEOUT);
#endif
#if LIB_WDOG_USE_WW
	lib_wdog_config_ww(LIB_WDOG_WW_TIMEOUT_MIN, LIB_WDOG_WW_TIMEOUT_MAX);
#endif
}


#if LIB_WDOG_USE_FW
void lib_wdog_config_fw(uint16_t timeout) {
	// FWDGT_PSC_DIV4:	 32000 /   4 	= 8000 HZ
    // FWDGT_PSC_DIV8: 	 32000 /   8 	= 4000 HZ
    // FWDGT_PSC_DIV16:  32000 /  16 	= 2000 HZ
    // FWDGT_PSC_DIV32:  32000 /  32 	= 1000 HZ
    // FWDGT_PSC_DIV64:  32000 /  64 	=  500 HZ
    // FWDGT_PSC_DIV128: 32000 / 128 	=  250 HZ
    // FWDGT_PSC_DIV256: 32000 / 256 	=  125 HZ
	
	//  4096 / 8000 HZ	[0.125,   512]ms
    //  4096 / 4000 HZ	[ 0.25,  1024]ms
    //  4096 / 2000 HZ	[  0.5,  2048]ms
    //  4096 / 1000 HZ	[	 1,  4096]ms
    //  4096 /  500 HZ	[    2,  8192]ms
    //  4096 /  250 HZ	[    4, 16384]ms
    //  4096 /  125 HZ	[    8, 32768]ms
	
	fw_timeout = timeout;
	
	uint8_t prescaler_div;
	uint16_t period;
	if(fw_timeout > 16384) {
		prescaler_div = FWDGT_PSC_DIV256;
		if(fw_timeout > 32768) {
			period = 4096;
		} else {
			period = fw_timeout / 8;
		}
	} else if(fw_timeout > 8192) {
		prescaler_div = FWDGT_PSC_DIV128;
		period = fw_timeout / 4;
	} else if(fw_timeout > 4096) {
		prescaler_div = FWDGT_PSC_DIV64;
		period = fw_timeout / 2;
	} else if(fw_timeout > 2048) {
		prescaler_div = FWDGT_PSC_DIV32;
		period = fw_timeout / 1;
	} else if(fw_timeout > 1024) {
		prescaler_div = FWDGT_PSC_DIV16;
		period = fw_timeout * 2;
	} else if(fw_timeout > 512) {
		prescaler_div = FWDGT_PSC_DIV8;
		period = fw_timeout * 4;
	} else {
		prescaler_div = FWDGT_PSC_DIV4;
		period = fw_timeout * 8;
	}
	rcu_all_reset_flag_clear();
	fwdgt_config(period - 1, prescaler_div);
    fwdgt_enable();
}

void lib_wdog_fw_feeddog() {
	fwdgt_counter_reload();
}
#endif


#if LIB_WDOG_USE_WW
/**
 * @brief  配置并启动窗口看门狗 (WWDGT)
 * @param  min_ms: 窗口的起始时间 (单位: 毫秒)。喂狗操作必须在此时间之后。
 * @param  max_ms: 窗口的结束时间, 即超时时间 (单位: 毫秒)。喂狗必须在此时间之前。
 *                 如果 min_ms >= max_ms，函数将直接返回。
 * @retval None
 */
void lib_wdog_config_ww(uint16_t min_ms, uint16_t max_ms) {
    // 1. 输入参数校验
    if (min_ms >= max_ms) {
        // 无效的窗口时间，直接返回
        return;
    }

    // 2. 使能WWDGT时钟
    rcu_periph_clock_enable(RCU_WWDGT);

    // 3. 获取PCLK1时钟频率
    // WWDGT的时钟源是 PCLK1 / 4096
    uint32_t pclk1_freq = rcu_clock_freq_get(CK_APB1);

    // 4. 选择最合适的预分频器 (Prescaler)
    // 目标：选择一个最小的预分频器，使其能满足 max_ms 的要求。
    // WWDGT的计数器是7位的，有效范围是 0x40-0x7F。
    // 最大超时 tick 数 = 0x7F - 0x3F = 64 ticks。
    // Timeout(ms) = 64 * (4096 * Prescaler_div) / (PCLK1_freq / 1000)
    
    uint32_t prescaler_val; // 用于 wwdgt_config() 的寄存器值
    uint32_t prescaler_div; // 用于计算的实际分频因子 (1, 2, 4, 8)

    // 从最大的分频比开始尝试，确保 max_ms 不会溢出
    // 计算以毫秒为单位的 PCLK1 频率
    uint32_t pclk1_freq_ms = pclk1_freq / 1000;

    // 检查DIV8所能支持的最大时间
    if (max_ms > (uint32_t)(64 * 4096 * 8) / pclk1_freq_ms) {
        // 如果请求的 max_ms 超过了最大预分频器所能提供的最大时间，
        // 则无法满足要求。这里可以选择饱和到最大值或直接返回。
        // 为安全起见，我们饱和到最大配置。
        prescaler_val = WWDGT_CFG_PSC_DIV8;
        prescaler_div = 8;
    } else if (max_ms > (uint32_t)(64 * 4096 * 4) / pclk1_freq_ms) {
        prescaler_val = WWDGT_CFG_PSC_DIV8;
        prescaler_div = 8;
    } else if (max_ms > (uint32_t)(64 * 4096 * 2) / pclk1_freq_ms) {
        prescaler_val = WWDGT_CFG_PSC_DIV4;
        prescaler_div = 4;
    } else if (max_ms > (uint32_t)(64 * 4096 * 1) / pclk1_freq_ms) {
        prescaler_val = WWDGT_CFG_PSC_DIV2;
        prescaler_div = 2;
    } else {
        prescaler_val = WWDGT_CFG_PSC_DIV1;
        prescaler_div = 1;
    }

    // 5. 计算每个tick代表的时间 (ms)
    // 使用浮点数进行精确计算，避免整数除法带来的误差
    double tick_ms = (4096.0 * prescaler_div) / pclk1_freq_ms;

    // 6. 计算计数器重载值 (T[6:0])
    // 公式: max_ms = (T - 0x3F) * tick_ms
    // => T = (max_ms / tick_ms) + 0x3F
    uint8_t counter_val = (uint8_t)((max_ms / tick_ms) + 0x3F + 0.5); // +0.5 用于四舍五入

    // 约束 T 的值在 [0x40, 0x7F] 范围内
    if (counter_val > 0x7F) {
        counter_val = 0x7F;
    } else if (counter_val < 0x40) {
        counter_val = 0x40;
    }

    // 7. 计算窗口值 (W[6:0])
    // 窗口开始的时间点 min_ms 对应着窗口值 W。
    // 当计数器从 T 减到 W 时，经过的时间就是 (T - W) 个 ticks。
    // 公式: min_ms = (T - W) * tick_ms
    // => W = T - (min_ms / tick_ms)
    uint8_t window_val = (uint8_t)(counter_val - (min_ms / tick_ms) + 0.5); // +0.5 用于四舍五入

    // 约束 W 的值在 [0x40, T] 范围内
    if (window_val < 0x40) {
        window_val = 0x40;
    }
    // 窗口值不能大于计数器重载值
    if (window_val > counter_val) {
        window_val = counter_val;
    }
    
    // 8. 配置并使能WWDGT
    // wwdgt_config(重载值, 窗口值, 预分频器);
    wwdgt_config(counter_val, window_val, prescaler_val);
    wwdgt_enable();
}
void lib_wdog_ww_feeddog() {
}
#endif

