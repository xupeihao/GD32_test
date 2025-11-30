#ifndef __LIB_I2C2_H__
#define __LIB_I2C2_H__

#include "I2C_config.h"

#if USE_LIB_I2C_2
#include "systick.h"
#include "gd32f4xx.h"

void lib_i2c2_init();

uint8_t lib_i2c2_read(uint8_t addr, uint8_t reg, uint8_t* data, uint32_t len);

uint8_t lib_i2c2_write(uint8_t addr, uint8_t reg, uint8_t* data, uint32_t len);

uint8_t lib_i2c2_write2(uint8_t addr, uint8_t reg, uint8_t* data, uint32_t offset, uint32_t len);

void lib_i2c2_deinit();

#endif

#endif