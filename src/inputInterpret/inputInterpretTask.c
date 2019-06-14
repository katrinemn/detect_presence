/*
 *      inputInterpretTask.h
 *
 *      Created on: 11-02-2017
 *      Author: Katrine Maria Nielsen
 */

/*************************** Include files *********************************/
#include <inputInterpret/inputInterpretTask.h>

/*****************************    Defines    *******************************/
#define INPUT_INTERPRET_TASKSTACKSIZE        	500         // Stack size in words

/***************************** Variables ***********************************/
INT16U  CO2Buffer;
INT8U   PIRBuffer;
INT16U   SOUNDBuffer;
INT16U   CO2Count = 0;
INT32U   CO2Value = 0;
float   ACCValue[3];
int16_t buttonValue = 0;


/***************************** Functions ***********************************/
static void interpretTask(void *pvParameters)
{
    // Get the current tick count.
    portTickType ui32WakeTime = xTaskGetTickCount();
    int i = 0;

    while(true)
    {
       // i++;
        //printUARTData(i, 2*10, 3, 4,5,i*2);
       if(xQueueReceive(CO2_Q,&CO2Buffer, 0) && xQueueReceive(PIR_Q,&PIRBuffer, 0) && xQueueReceive(SOUND_Q,&SOUNDBuffer, 0) && xQueueReceive(ACC_Q,&ACCValue, 0))
       {
           int16_t  x = ACCValue[0];
           int16_t  y = ACCValue[1];
           int16_t  z = ACCValue[2];
           printUARTData(CO2Buffer, PIRBuffer, SOUNDBuffer, x,y,z);
       }
       if(xQueueReceive(bUI_Q,&buttonValue, 0))
           printStringUART("sb");
       /* if(xQueueReceive(ACC_Q,&ACCValue, 0))
        {
            char string[50];
            int16_t  x = ACCValue[0]*100;
            int16_t  y = ACCValue[1]*100;
            int16_t  z = ACCValue[2]*100;


           //UARTprintf("%d \n", x);
           printUARTData(x, y, z);
        }*/


        vTaskDelayUntil(&ui32WakeTime,pdMS_TO_TICKS(100));
    }
}

BaseType_t interpretTaskInit()
{
    // Init stuff that is task related

    // Create the task
    if(xTaskCreate(interpretTask, (const portCHAR *)"INPUT_INTERPRET_TASK", INPUT_INTERPRET_TASKSTACKSIZE, NULL, tskIDLE_PRIORITY + PRIORITY_INPUTINTERPRET_TASK, NULL) != pdTRUE)
        return 0;
    else
        return 1;
}
