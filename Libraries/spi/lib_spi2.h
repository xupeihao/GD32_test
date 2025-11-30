#ifndef __LIB_SPI2_H__
#define __LIB_SPI2_H__


#include "spi_config.h"

#if USE_LIB_SPI_2


void lib_spi2_init();

#if LIB_SPI2_USE_MOSI

void lib_spi2_write(uint8_t data);

#if LIB_SPI2_MOSI_USE_DMA
void lib_spi2_dma_write(uint32_t addr, uint16_t len, uint8_t increase);
extern void lib_spi2_dma_on_complete();
#endif

#endif





#if LIB_SPI2_USE_MISO
uint8_t lib_spi2_read();
#endif

#if LIB_SPI2_USE_MOSI && LIB_SPI2_USE_MISO
uint8_t lib_spi2_write_read(uint8_t data);
#endif


#endif

#endif