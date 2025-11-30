#include "gd32f4xx.h"
#include "systick.h"
#include <stdio.h>
#include "app.h"
// FreeRTOS.h and task.h are already included in app.h
void vApplicationStackOverflowHook(TaskHandle_t pxTask, char *pcTaskName) {
    printf("Stack overflow in task %s\r\n", pcTaskName);
    // 可以添加其他处理，如打印任务栈信息
}

TaskHandle_t xTaskStartHandle = NULL;
TaskHandle_t xTask1Handle = NULL;

void vTask1(void *pvParameters) {

    while(1) {
        printf("Task1 is running\r\n");
        vTaskDelay(pdMS_TO_TICKS(1000));  // 每秒打印一次信息
    }
    

    // vTaskDelete(NULL);
}

void lib_timer5_on_cb() {

}

//void lib_usart0_on_recv(uint8_t* data, uint16_t len) {
//	
//}

void vTaskStart(void *pvParameters) {
    App_init();
    

    xTaskCreate(vTask1, "Task1", 256, NULL, 1, &xTask1Handle);
    

    vTaskDelete(NULL);
}

int main(void) {

	// 配置中断优先级分组为4位抢占优先级，0位子优先级
    nvic_priority_group_set(NVIC_PRIGROUP_PRE4_SUB0);
    

	printf("MCU start\r\n");
	

    xTaskCreate(vTaskStart, "TaskStart", 256, NULL, 2, &xTaskStartHandle);

    vTaskStartScheduler();

    while(1) {};

}