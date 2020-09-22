#include "task_blink_keep_alive.h"


void task_blink_keep_alive(void* pvParams){
    for(;;){
        vTaskSuspend(NULL);
        GPIO_RH0_Toggle();
        //GPIO_RH1_Toggle();
    }
}
