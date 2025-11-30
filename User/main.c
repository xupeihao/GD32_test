#include "gd32f4xx.h"
#include "systick.h"
#include <stdio.h>




void lib_timer5_on_cb() {

}

//void lib_usart0_on_recv(uint8_t* data, uint16_t len) {
//	
//}


int main(void) {

	nvic_priority_group_set(NVIC_PRIGROUP_PRE2_SUB2);

    systick_config();
	

	printf("MCU start\r\n");
	



    while(1) {

    }

}