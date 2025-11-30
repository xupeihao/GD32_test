#include "Task.h"



uint32_t g_cnt = 0;




typedef struct {
	void (*fun)();
	uint32_t 	period;  
	uint32_t 	last_time; 
} Task_t;



Task_t tasks[] = {

};


uint16_t task_cnt = sizeof(tasks) / sizeof(Task_t);



void Task_run() {
	for(uint16_t i = 0; i < task_cnt; i++) {

		if(g_cnt  >= tasks[i].period + tasks[i].last_time) {
			tasks[i].last_time = g_cnt;

			tasks[i].fun();
		}
	}
}


void Task_update() {
	g_cnt++;
}