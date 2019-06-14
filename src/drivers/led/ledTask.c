/*
 *      ledTask.h
 *
 *      Created on: 11-02-2017
 *      Author: Katrine Maria Nielsen
 */

/*************************** Include files *********************************/
#include <drivers/led/ledTask.h>

/*****************************    Defines    *******************************/
#define XTASKSTACKSIZE        	    100         // Stack size in words
#define LED						    GPIOPinRead(GPIO_PORTF_BASE, GPIO_PIN_1 | GPIO_PIN_2 | GPIO_PIN_3)

/*****************************    Variables    *******************************/
INT8U LED_value = 0;
INT8U receive_buffer = 0;

/***************************** Functions ***********************************/
static void ledTask(void *pvParameters)
{
	// Get the current tick count.
    portTickType ui32WakeTime = xTaskGetTickCount();

    // Loop forever
    while(true)
    {

        if(xQueueReceive(UI_Q,&receive_buffer, 0))
        {

        }

        // Wait for the required amount of time to check back
        vTaskDelayUntil(&ui32WakeTime, 10 / portTICK_RATE_MS);
    }
}

BaseType_t ledTaskInit()
{
    SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOF);
    GPIOPinTypeGPIOInput(GPIO_PORTF_BASE, GPIO_PIN_1 | GPIO_PIN_2 | GPIO_PIN_3);
    // Create the task
    if(xTaskCreate(ledTask, (const portCHAR *)"LED TASK", XTASKSTACKSIZE, NULL, tskIDLE_PRIORITY + PRIORITY_X_TASK, NULL) != pdTRUE)
    	return 0;
    else
    	return 1;
}
