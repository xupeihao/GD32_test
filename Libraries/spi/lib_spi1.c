#include "lib_spi1.h"

#if USE_LIB_SPI_1

#define __SPIx				SPI1
#define __SPIx_RCU		RCU_SPI1

#define __SPIx_USE_MOSI	LIB_SPI1_USE_MOSI
#define __SPIx_USE_MISO	LIB_SPI1_USE_MISO

#define __SPIx_CLK_RCU	LIB_SPI1_CLK_RCU
#define __SPIx_CLK_PIN	LIB_SPI1_CLK_PIN

#define __SPIx_MOSI_RCU	LIB_SPI1_MOSI_RCU
#define __SPIx_MOSI_PIN	LIB_SPI1_MOSI_PIN

#define __SPIx_MISO_RCU	LIB_SPI1_MISO_RCU
#define __SPIx_MISO_PIN	LIB_SPI1_MISO_PIN

#define __SPIx_PLPH		LIB_SPI1_PLPH
#define __SPIx_PSC		LIB_SPI1_PSC
#define __SPIx_ENDIAN	LIB_SPI1_ENDIAN


#if __SPIx_USE_MOSI
#define __SPIx_MOSI_USE_DMA	LIB_SPI1_MOSI_USE_DMA
#if __SPIx_MOSI_USE_DMA
#define __SPIx_DMA_RCU				RCU_DMA0
#define __SPIx_DMA_CH				DMA0, DMA_CH4
#define __SPIx_DMA_CH_SUB			DMA_SUBPERI0
#define __SPIx_DMA_FUNC_WRITE		lib_spi1_dma_write
#define __SPIx_DMA_FUNC_ON_COMPLETE	lib_spi1_dma_on_complete
#define __SPIx_DMA_FUNC_WRITE_IRQ	DMA0_Channel4_IRQHandler
#endif
#endif

#define __SPIx_FUNC_INIT		lib_spi1_init
#define __SPIx_FUNC_WRITE		lib_spi1_write
#define __SPIx_FUNC_READ		lib_spi1_read
#define __SPIx_FUNC_WRITE_READ	lib_spi1_write_read


#if __SPIx_MOSI_USE_DMA
static void spi_dma_mosi_init() {
	/***************** DMA m2p *******************/
	// 时钟
	rcu_periph_clock_enable(__SPIx_DMA_RCU);
	// 重置dma
	dma_deinit(__SPIx_DMA_CH);

	//////// dma 配置
	dma_single_data_parameter_struct dsdps;
	dma_single_data_para_struct_init(&dsdps);
	// 方向
	dsdps.direction = DMA_MEMORY_TO_PERIPH;
	
	// 内存: src 
	// dsdps.memory0_addr = (uint32_t)src;
	dsdps.memory_inc = DMA_MEMORY_INCREASE_ENABLE;
	
	// 外设: dst
	dsdps.periph_addr = (uint32_t)(&SPI_DATA(__SPIx));
	dsdps.periph_inc = DMA_PERIPH_INCREASE_DISABLE;
	
	// 数据长度
	// dsdps.number = ARR_LEN;
	
	// 数据宽度
	dsdps.periph_memory_width = DMA_MEMORY_WIDTH_8BIT;
	// 传输优先级
	dsdps.priority = DMA_PRIORITY_ULTRA_HIGH;
	dma_single_data_mode_init(__SPIx_DMA_CH, &dsdps);

	//////// 配置 dma 子连接
	dma_channel_subperipheral_select(__SPIx_DMA_CH, __SPIx_DMA_CH_SUB);
	
	
	dma_interrupt_enable(__SPIx_DMA_CH, DMA_INT_FTF);
	nvic_irq_enable(DMA0_Channel4_IRQn, 2, 2);
}
#endif

void __SPIx_FUNC_INIT() {
	///// gpio初始化
	////////////// GPIO ////////////////
	spi_io_init(__SPIx_CLK_RCU, __SPIx_CLK_PIN, GPIO_AF_5);//clk
#if __SPIx_USE_MOSI
	spi_io_init(__SPIx_MOSI_RCU,__SPIx_MOSI_PIN, GPIO_AF_5);//mosi
#endif
#if __SPIx_USE_MISO
	spi_io_init(__SPIx_MISO_RCU,__SPIx_MISO_PIN, GPIO_AF_5);//miso
#endif
	
	////////////// SPI /////////////////
	////SPI 电路初始化
	rcu_periph_clock_enable(__SPIx_RCU);
	spi_i2s_deinit(__SPIx);
	spi_parameter_struct spi_struct;
	spi_struct_para_init(&spi_struct);///设置默认值

	spi_struct.device_mode          = SPI_MASTER;
    spi_struct.trans_mode           = SPI_TRANSMODE_FULLDUPLEX;
    spi_struct.frame_size           = SPI_FRAMESIZE_8BIT;
    spi_struct.nss                  = SPI_NSS_SOFT;
    spi_struct.clock_polarity_phase = __SPIx_PLPH;
    spi_struct.prescale             = __SPIx_PSC;
    spi_struct.endian               = __SPIx_ENDIAN;
	
	spi_init(__SPIx, &spi_struct);
	
#if __SPIx_MOSI_USE_DMA	
	//初始化dma
	spi_dma_mosi_init();
	// 启用dma mosi
	spi_dma_enable(__SPIx, SPI_DMA_TRANSMIT);
#endif	
	
	spi_enable(__SPIx);
}

#if __SPIx_USE_MOSI
void __SPIx_FUNC_WRITE(uint8_t data) {
	// 写
	while(RESET == spi_i2s_flag_get(__SPIx, SPI_FLAG_TBE)){};
	spi_i2s_data_transmit(__SPIx, data);
	// 读
	while(RESET == spi_i2s_flag_get(__SPIx, SPI_FLAG_RBNE)){};
	spi_i2s_data_receive(__SPIx);
}


#if __SPIx_MOSI_USE_DMA
void __SPIx_DMA_FUNC_WRITE(uint32_t addr, uint16_t len, uint8_t increase) {
	// 内存地址不确定，长度不确定， 发送
	dma_memory_address_config(__SPIx_DMA_CH, DMA_MEMORY_0, addr);
	dma_transfer_number_config(__SPIx_DMA_CH, len);
	
	if(increase) {
		dma_memory_address_generation_config(__SPIx_DMA_CH, DMA_MEMORY_INCREASE_ENABLE);
	} else {
		dma_memory_address_generation_config(__SPIx_DMA_CH, DMA_MEMORY_INCREASE_DISABLE);
	}
	/// 告诉dma去干活
	dma_channel_enable(__SPIx_DMA_CH);
	
//	///判断状态
//	while(RESET == dma_flag_get(__SPIx_DMA_CH, DMA_FLAG_FTF));
//	dma_flag_clear(__SPIx_DMA_CH, DMA_FLAG_FTF);
//	
//	// 停止干活
//	dma_channel_disable(__SPIx_DMA_CH);
}

void __SPIx_DMA_FUNC_WRITE_IRQ() {
	if(SET == dma_interrupt_flag_get(__SPIx_DMA_CH, DMA_INT_FLAG_FTF)) {
		dma_interrupt_flag_clear(__SPIx_DMA_CH, DMA_INT_FLAG_FTF);
		
		// dma传输完成
		__SPIx_DMA_FUNC_ON_COMPLETE();
	}
}
#endif

#endif

#if __SPIx_USE_MISO
uint8_t __SPIx_FUNC_READ() {
	// 写
	while(RESET == spi_i2s_flag_get(__SPIx, SPI_FLAG_TBE)){};
    spi_i2s_data_transmit(__SPIx, 0xFF);
	// 读
	while(RESET == spi_i2s_flag_get(__SPIx, SPI_FLAG_RBNE)){};
	return spi_i2s_data_receive(__SPIx);
}
#endif

#if __SPIx_USE_MOSI && __SPIx_USE_MISO
uint8_t __SPIx_FUNC_WRITE_READ(uint8_t data) {
	// 写
	while(RESET == spi_i2s_flag_get(__SPIx, SPI_FLAG_TBE)){};
    spi_i2s_data_transmit(__SPIx, data);
	// 读
	while(RESET == spi_i2s_flag_get(__SPIx, SPI_FLAG_RBNE)){};
	return spi_i2s_data_receive(__SPIx);
}
#endif

#endif
