#include "lib_i2c.h"



void lib_i2c_init() {
#if USE_LIB_I2C_0
	lib_i2c0_init();
#endif

#if USE_LIB_I2C_1
	lib_i2c1_init();
#endif

#if USE_LIB_I2C_2
	lib_i2c2_init();
#endif
}