#ifndef __LIB_I2C_H__
#define __LIB_I2C_H__


#include "i2c_config.h"


#if USE_LIB_I2C_0
#include "lib_i2c0.h"
#endif

#if USE_LIB_I2C_1
#include "lib_i2c1.h"
#endif

#if USE_LIB_I2C_2
#include "lib_i2c2.h"
#endif

void lib_i2c_init();

#endif