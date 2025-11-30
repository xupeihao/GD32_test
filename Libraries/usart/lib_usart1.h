#ifndef __LIB_USART1_H__
#define __LIB_USART1_H__

#include "usart_config.h"

#if USE_LIB_USART_1

// 初始化
void lib_usart1_init();


// 功能接口

#if LIB_USART1_ENABLE_TX
/////// 发送

// 发送一个字节的接口
void lib_usart1_send_byte(uint8_t data);

// 发送多个字节的接口
void lib_usart1_send_data(uint8_t* data, uint16_t len);

// 发送字符串的接口
void lib_usart1_send_string(char* str);

#endif


#if LIB_USART1_ENABLE_RX

/////// 接收
/// 声明函数
#if LIB_USART1_RX_CALLBACK
extern void lib_usart1_on_recv(uint8_t* data, uint16_t len);
#endif

#endif /*LIB_USART0_ENABLE_RX*/


#endif


#endif