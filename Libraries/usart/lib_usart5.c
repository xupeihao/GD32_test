#include "lib_usart5.h"

#if USE_LIB_USART_5


#define	__USARTx_INDEX		5
#define __USARTx_RCU		RCU_USART5
#define __USARTx			USART5
#define __USARTx_AF			GPIO_AF_8
#define __USARTx_IRQn		USART5_IRQn
#define __USARTx_IRQHandler	USART5_IRQHandler

#define __USARTx_INIT			lib_usart5_init
#define __USARTx_SEND_BYTE		lib_usart5_send_byte
#define __USARTx_SEND_DATA		lib_usart5_send_data
#define __USARTx_SEND_STRING	lib_usart5_send_string
#define __USARTx_ON_RECV		lib_usart5_on_recv

#define __USARTx_RX_CALLBACK	LIB_USART5_RX_CALLBACK

#define __USARTx_ENABLE_TX		LIB_USART5_ENABLE_TX
#define __USARTx_ENABLE_RX		LIB_USART5_ENABLE_RX

#define __USARTx_TX_RCU			LIB_USART5_TX_RCU		
#define __USARTx_TX_PIN			LIB_USART5_TX_PIN

#define __USARTx_RX_RCU			LIB_USART5_RX_RCU		
#define __USARTx_RX_PIN			LIB_USART5_RX_PIN

//// USART config
#define __USARTx_BAUDRATE		LIB_USART5_BAUDRATE		
#define __USARTx_PARITY			LIB_USART5_PARITY		
#define __USARTx_DATA_LEN		LIB_USART5_DATA_LEN		
#define __USARTx_STOPBIT		LIB_USART5_STOPBIT		

#if __USARTx_ENABLE_TX
#define __USARTx_ENABLE_TX_DMA	LIB_USART5_ENABLE_TX_DMA
#if __USARTx_ENABLE_TX_DMA
#define	__USARTx_TX_DMA_RCU		LIB_USART5_TX_DMA_RCU
#define __USARTx_TX_DMA_CH		LIB_USART5_TX_DMA_CH
#define __USARTx_TX_DMA_CH_SUB	DMA_SUBPERI5
#endif
#endif
#if __USARTx_ENABLE_RX
#define __USARTx_ENABLE_RX_DMA	LIB_USART5_ENABLE_RX_DMA
#define __USARTx_RX_LEN			LIB_USART5_RX_LEN
#if __USARTx_ENABLE_RX_DMA
#include <string.h>
#define	__USARTx_RX_DMA_RCU		LIB_USART5_RX_DMA_RCU
#define __USARTx_RX_DMA_CH		LIB_USART5_RX_DMA_CH
#define __USARTx_RX_DMA_CH_SUB	DMA_SUBPERI5
#endif

static uint8_t recv_buff[__USARTx_RX_LEN];
static uint16_t recv_cnt = 0;
#endif


#if __USARTx_ENABLE_TX_DMA
static void dma_tx_init() {
	////// 总线时钟初始化
	rcu_periph_clock_enable(__USARTx_TX_DMA_RCU);
	dma_deinit(__USARTx_TX_DMA_CH);
	dma_single_data_parameter_struct init_struct;
	dma_single_data_para_struct_init(&init_struct);// 设置默认值
	init_struct.direction           = DMA_MEMORY_TO_PERIPH;

//	init_struct.memory0_addr        = (uint32_t)src;
    init_struct.memory_inc          = DMA_MEMORY_INCREASE_ENABLE;
	
	init_struct.periph_addr         = (uint32_t)(&USART_DATA(__USARTx));
    init_struct.periph_inc          = DMA_PERIPH_INCREASE_DISABLE;

    init_struct.periph_memory_width = DMA_PERIPH_WIDTH_8BIT;

//   init_struct.number              = 10;
    init_struct.priority            = DMA_PRIORITY_ULTRA_HIGH;
	
	dma_single_data_mode_init(__USARTx_TX_DMA_CH, &init_struct);
	
	dma_channel_subperipheral_select(__USARTx_TX_DMA_CH, __USARTx_TX_DMA_CH_SUB);
	dma_flag_clear(__USARTx_TX_DMA_CH, DMA_FLAG_FTF);
}
#endif


#if __USARTx_ENABLE_RX_DMA
static void dma_rx_init() {
	rcu_periph_clock_enable(__USARTx_RX_DMA_RCU);
	
	dma_deinit(__USARTx_RX_DMA_CH);
	dma_single_data_parameter_struct init_struct;
	dma_single_data_para_struct_init(&init_struct);
	init_struct.direction           = DMA_PERIPH_TO_MEMORY;
	
	init_struct.periph_addr         = (uint32_t)(&USART_DATA(__USARTx));
    init_struct.periph_inc          = DMA_PERIPH_INCREASE_DISABLE;
	
	init_struct.memory0_addr        = (uint32_t)recv_buff;
    init_struct.memory_inc          = DMA_MEMORY_INCREASE_ENABLE;
	
    init_struct.periph_memory_width = DMA_PERIPH_WIDTH_8BIT;
    
    init_struct.number              = __USARTx_RX_LEN;
    init_struct.priority            = DMA_PRIORITY_ULTRA_HIGH;
	
	dma_single_data_mode_init(__USARTx_RX_DMA_CH, &init_struct);
	
	dma_channel_subperipheral_select(__USARTx_RX_DMA_CH, __USARTx_RX_DMA_CH_SUB);
	
	dma_flag_clear(__USARTx_RX_DMA_CH, DMA_FLAG_FTF);
	
	/// 通知DMA去外设寄存器等待数据到来
	dma_channel_enable(__USARTx_RX_DMA_CH);
}
#endif


void __USARTx_INIT() {
	// 初始化串口0
	/// 外设初始化
	/////1. 初始化外设的时钟
	rcu_periph_clock_enable(__USARTx_RCU);
	/////2. 引脚初始化
#if __USARTx_ENABLE_TX
	/////// TX：发送
	lib_usart_gpio_init(__USARTx_TX_RCU, __USARTx_TX_PIN, __USARTx_AF);
#endif
#if __USARTx_ENABLE_RX	
	/////// RX: 接收
	lib_usart_gpio_init(__USARTx_RX_RCU, __USARTx_RX_PIN, __USARTx_AF);
#endif
	
	/////3. 外设功能初始化
    usart_deinit(__USARTx); //de init
    usart_baudrate_set(__USARTx, __USARTx_BAUDRATE); //波特率
	// 校验位
	usart_parity_config(__USARTx, __USARTx_PARITY);
	// 数据位
	usart_word_length_set(__USARTx, __USARTx_DATA_LEN);
	// 停止位
	usart_stop_bit_set(__USARTx, __USARTx_STOPBIT);
	
#if __USARTx_ENABLE_TX_DMA
	///// 4. DMA 初始化TX
	dma_tx_init();
	////// 外设和dma建立关系，外设去打开
	usart_dma_transmit_config(__USARTx, USART_TRANSMIT_DMA_ENABLE);
#endif

#if __USARTx_ENABLE_RX_DMA
	///// 5. DMA 初始化RX
	dma_rx_init();
	////// 外设和dma建立关系，外设去打开
	usart_dma_receive_config(__USARTx, USART_RECEIVE_DMA_ENABLE);
#endif
	
#if __USARTx_ENABLE_TX
	usart_transmit_config(__USARTx, USART_TRANSMIT_ENABLE); // 发送功能打开
#endif

#if __USARTx_ENABLE_RX
    usart_receive_config(__USARTx, USART_RECEIVE_ENABLE);	  // 接收功能打开
	
	///中断配置
	//// 1)电路的中断配置，中断源--》中断函数
#if !LIB_USART0_ENABLE_RX_DMA
	usart_interrupt_enable(__USARTx, USART_INT_RBNE);// 接收的中断
#endif
	usart_interrupt_enable(__USARTx, USART_INT_IDLE);// 闲置的中断
	
	//// 2)中断优先级
	nvic_irq_enable(__USARTx_IRQn, LIB_USART0_RX_NVIC);
#endif
	
    usart_enable(__USARTx);
}


#if __USARTx_ENABLE_TX
void __USARTx_SEND_BYTE(uint8_t data) {
#if __USARTx_ENABLE_TX_DMA
	__USARTx_SEND_DATA(&data, 1);
#else
	usart_data_transmit(__USARTx, data);
	while(RESET == usart_flag_get(__USARTx, USART_FLAG_TBE));
#endif
}


void __USARTx_SEND_DATA(uint8_t* data, uint16_t len) {
#if __USARTx_ENABLE_TX_DMA
	dma_memory_address_config(__USARTx_TX_DMA_CH, DMA_MEMORY_0, (uint32_t)data);
	dma_transfer_number_config(__USARTx_TX_DMA_CH, len);
	
	dma_channel_enable(__USARTx_TX_DMA_CH);
	
	///判断状态
	while(RESET == dma_flag_get(__USARTx_TX_DMA_CH, DMA_FLAG_FTF));
	dma_flag_clear(__USARTx_TX_DMA_CH, DMA_FLAG_FTF);	
#else
	for(uint16_t i = 0; i < len; i++) {
		__USARTx_SEND_BYTE(data[i]);
	}
#endif
}


void __USARTx_SEND_STRING(char* str) {
#if __USARTx_ENABLE_TX_DMA
	__USARTx_SEND_DATA((uint8_t*)str, strlen(str));
#else 	
	while(str && *str) {
		__USARTx_SEND_BYTE(*str);
		str++;
	}
#endif
}

#endif

#if USE_LIB_USART_PRINT == __USARTx_INDEX
int fputc(int ch, FILE *f)
{
	__USARTx_SEND_BYTE((uint8_t)ch);
    return ch;
}
#endif


#if __USARTx_ENABLE_RX
void __USARTx_IRQHandler() {
#if !__USARTx_ENABLE_RX_DMA
	if(SET == usart_interrupt_flag_get(__USARTx, USART_INT_FLAG_RBNE)) { 
		usart_interrupt_flag_clear(__USARTx, USART_INT_FLAG_RBNE);
		recv_buff[recv_cnt++] = usart_data_receive(__USARTx);

	}
#endif	
	if(SET == usart_interrupt_flag_get(__USARTx, USART_INT_FLAG_IDLE)) {
		usart_data_receive(__USARTx);
#if !__USARTx_ENABLE_RX_DMA		
		recv_buff[recv_cnt] = 0;
	#if __USARTx_RX_CALLBACK
		__USARTx_ON_RECV(recv_buff, recv_cnt);
	#endif
		recv_cnt = 0;
#else
	dma_channel_disable(__USARTx_RX_DMA_CH);
	dma_flag_clear(__USARTx_RX_DMA_CH, DMA_FLAG_FTF);

	uint32_t num = dma_transfer_number_get(__USARTx_RX_DMA_CH);
	recv_cnt = __USARTx_RX_LEN - num;
	
	recv_buff[recv_cnt] = 0;
	#if __USARTx_RX_CALLBACK
	if(recv_cnt > 0) {		
		__USARTx_ON_RECV(recv_buff, recv_cnt);
	}
	#endif
	dma_channel_enable(__USARTx_RX_DMA_CH);
#endif
	}
}
#endif


#endif

