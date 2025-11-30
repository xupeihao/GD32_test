#include "lib_spi0.h"

#if USE_LIB_SPI_0

#define __SPIx				SPI0
#define __SPIx_RCU		RCU_SPI0

#define __SPIx_USE_MOSI	LIB_SPI0_USE_MOSI
#define __SPIx_USE_MISO	LIB_SPI0_USE_MISO

#define __SPIx_CLK_RCU	LIB_SPI0_CLK_RCU
#define __SPIx_CLK_PIN	LIB_SPI0_CLK_PIN

#define __SPIx_MOSI_RCU	LIB_SPI0_MOSI_RCU
#define __SPIx_MOSI_PIN	LIB_SPI0_MOSI_PIN

#define __SPIx_MISO_RCU	LIB_SPI0_MISO_RCU
#define __SPIx_MISO_PIN	LIB_SPI0_MISO_PIN

#define __SPIx_PLPH		LIB_SPI0_PLPH
#define __SPIx_PSC		LIB_SPI0_PSC
#define __SPIx_ENDIAN	LIB_SPI0_ENDIAN


void lib_spi0_init() {
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
	spi_enable(__SPIx);
}

#if LIB_SPI0_USE_MOSI
void lib_spi0_write(uint8_t data) {
	// 写
	while(RESET == spi_i2s_flag_get(__SPIx, SPI_FLAG_TBE)){};
	spi_i2s_data_transmit(__SPIx, data);
	// 读
	while(RESET == spi_i2s_flag_get(__SPIx, SPI_FLAG_RBNE)){};
	spi_i2s_data_receive(__SPIx);
}
#endif

#if LIB_SPI0_USE_MISO
uint8_t lib_spi0_read() {
	// 写
	while(RESET == spi_i2s_flag_get(__SPIx, SPI_FLAG_TBE)){};
    spi_i2s_data_transmit(__SPIx, 0xFF);
	// 读
	while(RESET == spi_i2s_flag_get(__SPIx, SPI_FLAG_RBNE)){};
	return spi_i2s_data_receive(__SPIx);
}
#endif

#if LIB_SPI0_USE_MOSI && LIB_SPI0_USE_MISO
uint8_t lib_spi0_write_read(uint8_t data) {
	// 写
	while(RESET == spi_i2s_flag_get(__SPIx, SPI_FLAG_TBE)){};
    spi_i2s_data_transmit(__SPIx, data);
	// 读
	while(RESET == spi_i2s_flag_get(__SPIx, SPI_FLAG_RBNE)){};
	return spi_i2s_data_receive(__SPIx);
}
#endif

#endif
