/*******************************************************************************
  Main Source File

  Company:
    Microchip Technology Inc.

  File Name:
    main.c

  Summary:
    This file contains the "main" function for a project.

  Description:
    This file contains the "main" function for a project.  The
    "main" function calls the "SYS_Initialize" function to initialize the state
    machines of all modules in the system
 *******************************************************************************/

// *****************************************************************************
// *****************************************************************************
// Section: Included Files
// *****************************************************************************
// *****************************************************************************

#include <stddef.h>                     // Defines NULL
#include <stdbool.h>                    // Defines true
#include <stdlib.h>                     // Defines EXIT_FAILURE
#include "definitions.h"                // SYS function prototypes

#include "FreeRTOS.h"
#include "task.h"

#include "task_blink_keep_alive.h"
#include "task_blink_with_delay.h"

// *****************************************************************************
// *****************************************************************************
// Section: Main Entry Point
// *****************************************************************************
// *****************************************************************************

TaskHandle_t task_handler_blink_keep_alive;
TaskHandle_t task_handler_blink_with_delay;



//typedef void ( * SYS_TIME_CALLBACK ) ( uintptr_t context );
void timer_event_handler(uintptr_t context){
    vTaskResume(task_handler_blink_keep_alive);
}







int main ( void )
{
    /* Initialize all modules */
    SYS_Initialize ( NULL );

    SYS_TIME_HANDLE handle = SYS_TIME_TimerCreate(0,SYS_TIME_MSToCount(500),&timer_event_handler,NULL,SYS_TIME_PERIODIC);
    if(handle == SYS_TIME_HANDLE_INVALID){
        GPIO_RH2_Set(); // error
    }
    SYS_TIME_TimerStart(handle);

    //GPIO_RH0_Set();
    //GPIO_RH1_Set();
            
    while ( true )
    {
        /* Maintain state machines of all polled MPLAB Harmony modules. */


        /* Maintain system services */


        /* Maintain Device Drivers */


        /* Maintain Middleware & Other Libraries */


        /* Maintain the application's state machine. */
        
        /* Create OS Thread for APP_Tasks. */
        xTaskCreate((TaskFunction_t) task_blink_keep_alive,
                    "task_blink_keep_alive",
                    1024,
                    NULL,
                    1,
                    &task_handler_blink_keep_alive);

        xTaskCreate((TaskFunction_t) task_blink_with_delay,
                    "task_blink_with_delay",
                    1024,
                    NULL,
                    1,
                    &task_handler_blink_with_delay);




        /* Start RTOS Scheduler. */

         /**********************************************************************
         * Create all Threads for APP Tasks before starting FreeRTOS Scheduler *
         ***********************************************************************/
        vTaskStartScheduler(); /* This function never returns. */
    }

    /* Execution should not come here during normal operation */

    return ( EXIT_FAILURE );
}


/*******************************************************************************
 End of File
*/

