/*
 *      soundTask.h
 *
 *      Created on: 11-02-2017
 *      Author: Katrine Maria Nielsen
 */

/*************************** Include files *********************************/
#include <soundTask/soundTask.h>
/*****************************    Defines    *******************************/
#define SOUNDTASKSTACKSIZE        	100         // Stack size in words

/***************************** Variables ***********************************/

/***************************** Functions ***********************************/
static void soundTask(void *pvParameters)
{
	// Get the current tick count.
    portTickType ui32WakeTime = xTaskGetTickCount();
    int16_t queueValue;
    // Loop forever
    while(true)
    {
         queueValue =  getSoundValue();
         xQueueSend(SOUND_Q,&queueValue,portMAX_DELAY);
        // Wait for the required amount of time to check back
        vTaskDelayUntil(&ui32WakeTime, 200 / portTICK_RATE_MS);
    }
}

BaseType_t soundTaskInit()
{
    soundDetectorInit();

    // Create the task
    if(xTaskCreate(soundTask, (const portCHAR *)"SOUNDTASK", SOUNDTASKSTACKSIZE, NULL, tskIDLE_PRIORITY + PRIORITY_SOUND_TASK, NULL) != pdTRUE)
    	return 0;
    else
    	return 1;
}
