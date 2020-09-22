#ifndef TASK_BLINK_KEEP_ALIVE_H
#define	TASK_BLINK_KEEP_ALIVE_H

#include "FreeRTOS.h"
#include "task.h"

#include "peripheral/gpio/plib_gpio.h"


void task_blink_keep_alive(void* pvParams);

#endif	/* TASK_BLINK_KEEP_ALIVE_H */

