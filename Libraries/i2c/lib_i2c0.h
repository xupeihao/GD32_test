#ifndef __LIB_I2C0_H__
#define __LIB_I2C0_H__

#include "I2C_config.h"

#if USE_LIB_I2C_0
#include "systick.h"
#include "gd32f4xx.h"


void lib_i2c0_init();

uint8_t lib_i2c0_read(uint8_t addr, uint8_t reg, uint8_t* data, uint32_t len);

uint8_t lib_i2c0_write(uint8_t addr, uint8_t reg, uint8_t* data, uint32_t len);

uint8_t lib_i2c0_write2(uint8_t addr, uint8_t reg, uint8_t* data, uint32_t offset, uint32_t len);

void lib_i2c0_deinit();

#endif

#endif