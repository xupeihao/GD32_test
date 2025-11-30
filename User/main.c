#include "gd32f4xx.h"
#include "systick.h"
#include <stdio.h>
#include "Task.h"




void lib_timer5_on_cb() {
	Task_update();
}

//void lib_usart0_on_recv(uint8_t* data, uint16_t len) {
//	
//}


int main(void) {

	nvic_priority_group_set(NVIC_PRIGROUP_PRE2_SUB2);

    systick_config();
	
	lib_peripheral_init();
	
	printf("MCU start\r\n");
	
	App_init();


    while(1) {
		Task_run();
    }

}