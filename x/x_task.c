/*
 *      x_task.h
 *
 *      Created on: 11-02-2017
 *      Author: Katrine Maria Nielsen
 */

/*************************** Include files *********************************/
#include "x_task.h"

/*****************************    Defines    *******************************/
#define XTASKSTACKSIZE        	100         // Stack size in words

/***************************** Functions ***********************************/
static void XTask(void *pvParameters)
{
	// Get the current tick count.
    portTickType ui32WakeTime = xTaskGetTickCount();

    // Loop forever
    while(true)
    {

        // Wait for the required amount of time to check back
        vTaskDelayUntil(&ui32WakeTime, 10 / portTICK_RATE_MS);
    }
}

BaseType_t XTaskInit()
{
	// Init stuff that is task related

    // Create the task
    if(xTaskCreate(XTask, (const portCHAR *)"TASKNAME", XTASKSTACKSIZE, NULL, tskIDLE_PRIORITY + PRIORITY_X_TASK, NULL) != pdTRUE)
    	return 0;
    else
    	return 1;
}
