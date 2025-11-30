#ifndef __SPI_CONFIG_H__
#define __SPI_CONFIG_H__

#include "gd32f4xx.h"
#include "gd32f4xx_gpio.h"
#include "gd32f4xx_rcu.h"


#define USE_LIB_SPI_0	0
#define USE_LIB_SPI_1	0
#define USE_LIB_SPI_2	0
#define USE_LIB_SPI_3	0
#define USE_LIB_SPI_4	0
#define USE_LIB_SPI_5	0


////////////////////// SPI 0 ///////////////////////
#if USE_LIB_SPI_0

#define LIB_SPI0_USE_MOSI	1
#define LIB_SPI0_USE_MISO	0

/**
|-----------|-----------|-----------|
|	MOSI	|	MISO	|	CLK		|
|-----------|-----------|-----------|
|	PA7		|	PA6		|	PA5		|
|-----------|-----------|-----------|
|	PB5		|	PB4		|	PB3		|
|-----------|-----------|-----------|
*/

#define	LIB_SPI0_CLK_RCU	RCU_GPIOA
#define	LIB_SPI0_CLK_PIN	GPIOA, GPIO_PIN_5

#if LIB_SPI0_USE_MOSI
#define LIB_SPI0_MOSI_RCU	RCU_GPIOA
#define LIB_SPI0_MOSI_PIN	GPIOA, GPIO_PIN_7
#endif

#if LIB_SPI0_USE_MISO
#define LIB_SPI0_MISO_RCU	RCU_GPIOA
#define LIB_SPI0_MISO_PIN	GPIOA, GPIO_PIN_6
#endif

#define	LIB_SPI0_PLPH		SPI_CK_PL_LOW_PH_1EDGE
#define LIB_SPI0_PSC		SPI_PSC_2
#define LIB_SPI0_ENDIAN		SPI_ENDIAN_MSB

#endif



////////////////////// SPI 1 ///////////////////////
#if USE_LIB_SPI_1

#define LIB_SPI1_USE_MOSI		1
#define LIB_SPI1_USE_MISO		0
#if LIB_SPI1_USE_MOSI
#define LIB_SPI1_MOSI_USE_DMA	1
#endif
/**
|-----------|-----------|-----------|
|	MOSI	|	MISO	|	CLK		|
|-----------|-----------|-----------|
|	PB15	|	PB14	|	PB10	|
|-----------|-----------|-----------|
|	PC1		|	PC2		|	PB13	|
|-----------|-----------|-----------|
|	PC3		|	PI2		|	PC7		|
|-----------|-----------|-----------|
|	PI3		|			|	PD3		|
|-----------|-----------|-----------|
|			|			|	PI1		|
|-----------|-----------|-----------|
*/

#define	LIB_SPI1_CLK_RCU	RCU_GPIOB
#define	LIB_SPI1_CLK_PIN	GPIOB, GPIO_PIN_10

#if LIB_SPI1_USE_MOSI
#define LIB_SPI1_MOSI_RCU	RCU_GPIOB
#define LIB_SPI1_MOSI_PIN	GPIOB, GPIO_PIN_15
#endif

#if LIB_SPI1_USE_MISO
#define LIB_SPI1_MISO_RCU	RCU_GPIOA
#define LIB_SPI1_MISO_PIN	GPIOA, GPIO_PIN_6
#endif

#define	LIB_SPI1_PLPH		SPI_CK_PL_LOW_PH_1EDGE
#define LIB_SPI1_PSC		SPI_PSC_4
#define LIB_SPI1_ENDIAN		SPI_ENDIAN_MSB

#endif



////////////////////// SPI 2 ///////////////////////
#if USE_LIB_SPI_2

#define LIB_SPI2_USE_MOSI		1
#define LIB_SPI2_USE_MISO		0
#if LIB_SPI2_USE_MOSI
#define LIB_SPI2_MOSI_USE_DMA	0
#endif
/**
|-----------|-----------|-----------|
|	MOSI	|	MISO	|	CLK		|
|-----------|-----------|-----------|
|	PB0		|	PB4		|	PB3		|
|-----------|-----------|-----------|
|	PB2		|	PC11	|	PC10	|
|-----------|-----------|-----------|
|	PB5		|			|			|
|-----------|-----------|-----------|
|	PC1		|			|			|
|-----------|-----------|-----------|
|	PC12	|			|			|
|-----------|-----------|-----------|
|	PD0		|			|			|
|-----------|-----------|-----------|
|	PD6		|			|			|
|-----------|-----------|-----------|
*/

#define	LIB_SPI2_CLK_RCU	RCU_GPIOC
#define	LIB_SPI2_CLK_PIN	GPIOC, GPIO_PIN_10

#if LIB_SPI2_USE_MOSI
#define LIB_SPI2_MOSI_RCU	RCU_GPIOB
#define LIB_SPI2_MOSI_PIN	GPIOB, GPIO_PIN_5
#endif

#if LIB_SPI2_USE_MISO
#define LIB_SPI2_MISO_RCU	RCU_GPIOA
#define LIB_SPI2_MISO_PIN	GPIOA, GPIO_PIN_6
#endif

#define	LIB_SPI2_PLPH		SPI_CK_PL_LOW_PH_1EDGE
#define LIB_SPI2_PSC		SPI_PSC_2
#define LIB_SPI2_ENDIAN		SPI_ENDIAN_MSB

#endif




























/////////////////////////////////////////////////////////////////////////////////////
static inline void spi_io_init(rcu_periph_enum rcu, uint32_t port, uint32_t pin, uint32_t af) {
	rcu_periph_clock_enable(rcu);
    gpio_mode_set(port, GPIO_MODE_AF, GPIO_PUPD_NONE, pin);
    gpio_output_options_set(port, GPIO_OTYPE_PP, GPIO_OSPEED_50MHZ, pin);
	gpio_af_set(port, af, pin);
}


#endif