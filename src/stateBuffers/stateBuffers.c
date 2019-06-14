/*
 *      stateBuffers.h
 *
 *      Created on: 11-02-2017
 *      Author: Katrine Maria Nielsen
 */

/*************************** Include files *********************************/
#include <stateBuffers/stateBuffers.h>
#include "FreeRTOS.h"
#include "task.h"
#include "queue.h"
#include "semphr.h"
#include "../threading/threading.h"

/*****************************  Defines  ***********************************/
//

/****************************  Variables  **********************************/
static INT8U ledOn = false;

/***************************** Functions ***********************************/


/***************************************************************************/


INT8U setLED(INT8U on)
{
	xSemaphoreTake(ledMutexX, portMAX_DELAY);
	ledOn = on;
	xSemaphoreGive(ledMutexX);
	return ledOn;
}

INT8U getLED()
{
	xSemaphoreTake(ledMutexX, portMAX_DELAY);
	INT8U returnVal = ledOn;
	xSemaphoreGive(ledMutexX);
	return returnVal;
}

void    printStringUART(const char *pcString)
{
    xSemaphoreTake(uartMutexX, portMAX_DELAY);
    UARTprintf("%s %s",pcString, "b");
    xSemaphoreGive(uartMutexX);
}

void printUART(INT16U on)
{
    xSemaphoreTake(uartMutexX, portMAX_DELAY);
    UARTprintf("\%d \%s",on, "b");
    xSemaphoreGive(uartMutexX);
}
void printUARTData(int16_t CO2, int16_t PIR, int16_t SOUND, int16_t x, int16_t y, int16_t z)
{
    xSemaphoreTake(uartMutexX, portMAX_DELAY);
    UARTprintf("%16d %16d %16d %16d %16d %16d b\n",CO2, PIR, SOUND,x,y,z);
    xSemaphoreGive(uartMutexX);
}
void printUARTDataf(INT16U CO2, INT8U PIR, INT8U SOUND)
{
    xSemaphoreTake(uartMutexX, portMAX_DELAY);
    UARTprintf("%s %16d %s %08d %s %16d %s","CO2: ",CO2,"PIR: ", PIR,"SOUND: ", SOUND ,"b");
    xSemaphoreGive(uartMutexX);
}
/***************************************************************************/
