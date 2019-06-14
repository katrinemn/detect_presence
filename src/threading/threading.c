/*
 *      threading.h
 *
 *      Created on: 11-02-2017
 *      Author: Katrine Maria Nielsen
 */

/*************************** Include files *********************************/
#include "threading.h"

/***************************** Variables ***********************************/
// Queue handles
xQueueHandle bUI_Q;
xQueueHandle UI_Q;
xQueueHandle PIR_Q;
xQueueHandle CO2_Q;
xQueueHandle SOUND_Q;
xQueueHandle ACC_Q;

// Mutex handles
xSemaphoreHandle uartMutexX;
xSemaphoreHandle xMutexX;
xSemaphoreHandle ledMutexX;

/***************************** Functions ************************************/
BaseType_t xQueuesCreated()
{
	// Create queues
	bUI_Q = xQueueCreate(20, sizeof(INT8U));
	UI_Q = xQueueCreate(20, sizeof(INT16U));
	PIR_Q = xQueueCreate(20, sizeof(INT8U));
	CO2_Q = xQueueCreate(20, sizeof(INT16U));
	SOUND_Q = xQueueCreate(20, sizeof(INT16U));
	ACC_Q = xQueueCreate(20, sizeof(float[3]));

	// Check to see that queues were in fact created
	if(bUI_Q == NULL || UI_Q == NULL || CO2_Q == NULL || PIR_Q == NULL || SOUND_Q == NULL || ACC_Q ==NULL)
	{
		return pdFALSE;
	}
	else
	{
		return pdTRUE;
	}
}

BaseType_t xSemaphoresCreated()
{
	// Create mutexes
    uartMutexX = xSemaphoreCreateMutex();
	xMutexX	= xSemaphoreCreateMutex();
	ledMutexX = xSemaphoreCreateMutex();

	// Check to see that semaphores were in fact created
	if( xMutexX == NULL || ledMutexX == NULL || uartMutexX == NULL)
	{
		return pdFALSE;
	}
	else
	{
		return pdTRUE;
	}
}
