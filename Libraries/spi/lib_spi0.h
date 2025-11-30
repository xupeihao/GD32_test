#ifndef __LIB_SPI0_H__
#define __LIB_SPI0_H__


#include "spi_config.h"

#if USE_LIB_SPI_0


void lib_spi0_init();

#if LIB_SPI0_USE_MOSI
void lib_spi0_write(uint8_t data);
#endif

#if LIB_SPI0_USE_MISO
uint8_t lib_spi0_read();
#endif

#if LIB_SPI0_USE_MOSI && LIB_SPI0_USE_MISO
uint8_t lib_spi0_write_read(uint8_t data);
#endif


#endif

#endif