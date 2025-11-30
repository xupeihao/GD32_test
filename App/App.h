#ifndef __APP_H__
#define __APP_H__


#include "board_config.h"
#include "stdio.h"
#include "bsp.h"
#include "string.h"
#include "FreeRTOS.h"
#include "task.h"

//extern TaskHandle_t xTask1Handle ;



void App_init();




/////////////////// UI/UX ///////////////////////
void App_ui_init();

/////////////////FreeRTOS Task///////////////////
void vTask1(void *pvParameters);



#endif