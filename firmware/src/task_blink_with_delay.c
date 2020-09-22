#include "task_blink_with_delay.h"


void task_blink_with_delay(void* pvParams){
    for(;;){
        vTaskDelay(500/portTICK_PERIOD_MS);
        //GPIO_RH0_Toggle();
        GPIO_RH1_Toggle();
    }
}
