#ifndef TASK_BLINK_WITH_DELAY_H
#define	TASK_BLINK_WITH_DELAY_H

#include "FreeRTOS.h"
#include "task.h"

#include "peripheral/gpio/plib_gpio.h"

void task_blink_with_delay(void* pvParams);

#endif	/* TASK_BLINK_WITH_DELAY_H */

