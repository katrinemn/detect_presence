/*
 *      CO2Task.h
 *
 *      Created on: 11-02-2017
 *      Author: Katrine Maria Nielsen
 */

/*************************** Include files *********************************/
#include "CO2Task/CO2Task.h"

/*****************************    Defines    *******************************/
#define CO2TASKSTACKSIZE        	100         // Stack size in words
/***************************** Variables ***********************************/
INT16U queueValue;

/***************************** Functions ***********************************/
static void CO2Task(void *pvParameters)
{
	// Get the current tick count.
    portTickType ui32WakeTime = xTaskGetTickCount();

    // Loop forever
    while(true)
    {
       queueValue = getCO2Value();
       xQueueSend(CO2_Q,&queueValue,portMAX_DELAY);
        vTaskDelayUntil(&ui32WakeTime, 200 / portTICK_PERIOD_MS);
    }
}

BaseType_t CO2TaskInit()
{
	CO2SensorInit();

    if(xTaskCreate(CO2Task, (const portCHAR *)"CO2_TASK", CO2TASKSTACKSIZE, NULL, tskIDLE_PRIORITY + PRIORITY_CO2_TASK, NULL) != pdTRUE)
    	return 0;
    else
    	return 1;
}
