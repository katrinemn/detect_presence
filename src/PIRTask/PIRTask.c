/*
 *      PIRTask.h
 *
 *      Created on: 11-02-2017
 *      Author: Katrine Maria Nielsen
 */

/*************************** Include files *********************************/
#include <PIRTask/PIRTask.h>
/*****************************    Defines    *******************************/
#define PIRTASKSTACKSIZE        	100         // Stack size in words
#define PIR_SENSOR              (GPIO_PORTA_DATA_R & 0x04)
/***************************** Variables ***********************************/
INT8U queueValue;
INT8U currentValue = 0;
/***************************** Functions ***********************************/
static void PIRTask(void *pvParameters)
{
	// Get the current tick count.
    portTickType ui32WakeTime = xTaskGetTickCount();

    // Loop forever
    while(true)
    {
        queueValue = getPIRValue();;
         xQueueSend(PIR_Q,&queueValue,portMAX_DELAY);

        vTaskDelayUntil(&ui32WakeTime, 200 / portTICK_RATE_MS);
    }
}

uint32_t PIRTaskInit()
{
    PIRSensorInit();

    // Create the task
    if(xTaskCreate(PIRTask, (const portCHAR *)"PIR_TASK", PIRTASKSTACKSIZE, NULL, tskIDLE_PRIORITY + PRIORITY_PIR_TASK, NULL) != pdTRUE)
    	return 0;
    else
    	return 1;
}
