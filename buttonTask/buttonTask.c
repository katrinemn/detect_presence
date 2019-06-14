/*
 *      buttonTask.h
 *
 *      Created on: 11-02-2017
 *      Author: Katrine Maria Nielsen
 */

/*************************** Include files *********************************/
#include <buttonTask/buttonTask.h>


/*****************************    Defines    *******************************/
#define BUTTONTASKSTACKSIZE 100

/***************************** Variables ***********************************/

/***************************** Functions ***********************************/
static void buttonTask(void *pvParameters)
{
	// Get the current tick count.
    portTickType ui32WakeTime = xTaskGetTickCount();

    int8_t buttonValue;
    int8_t previousValue = 0;
    while(true)
    {

        buttonValue = getButtonValue();
        if(buttonValue && buttonValue != previousValue)
        {
            //printUART(buttonValue);

            xQueueSend(bUI_Q,&buttonValue,portMAX_DELAY);
            previousValue = buttonValue;
        }

        vTaskDelayUntil(&ui32WakeTime, 25 / portTICK_RATE_MS);
    }
}

BaseType_t buttonTaskInit()
{
    buttonInit();

    if(xTaskCreate(buttonTask, (const portCHAR *)"BUTTON_TASK", BUTTONTASKSTACKSIZE, NULL, tskIDLE_PRIORITY + PRIORITY_BUTTON_TASK, NULL) != pdTRUE)
    	return 0;
    else
    	return 1;
}
