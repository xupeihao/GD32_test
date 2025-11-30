#ifndef __LIB_USART3_H__
#define __LIB_USART3_H__

#include "usart_config.h"

#if USE_LIB_USART_3

// 初始化
void lib_usart3_init();


// 功能接口

#if LIB_USART3_ENABLE_TX
/////// 发送

// 发送一个字节的接口
void lib_usart3_send_byte(uint8_t data);

// 发送多个字节的接口
void lib_usart3_send_data(uint8_t* data, uint16_t len);

// 发送字符串的接口
void lib_usart3_send_string(char* str);

#endif

#if LIB_USART3_ENABLE_RX

/////// 接收
/// 声明函数
#if LIB_USART3_RX_CALLBACK
extern void lib_usart3_on_recv(uint8_t* data, uint16_t len);
#endif

#endif /*LIB_USART3_ENABLE_RX*/


#endif


#endif