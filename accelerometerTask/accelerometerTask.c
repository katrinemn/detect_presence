/*
 *      AccelerometerTask.h
 *
 *      Created on: 11-02-2017
 *      Author: Katrine Maria Nielsen
 */
/**************************** Include files ********************************/

#include <accelerometerTask/accelerometerTask.h>
#include "drivers/accelerometer/accelerometer.h"
/*****************************  Defines  ***********************************/
# define ACCELEROMETERTASKSTACKSIZE     500

/*****************************  Variables  *********************************/
float ACCValue[3];
float x[3];

/***************************** Functions ***********************************/

static void accelerometerTask(void *pvParameters)
{
    portTickType ui32WakeTime = xTaskGetTickCount();

    MPU6050ReadInit();
    // Loop forever
    while(true)
    {
        float * data = MPU6050GetAccelChange(1);
        //char string[50];
       // sprintf(string, "x: %f y: %f z: %f", data[0], data[1], data[2]);
        //UARTprintf("Acc: %s\n", string);
        //vTaskDelay(1);
        x[0] =data[0];
        x[1] = data[1];
        x[2] = data[2];
        xQueueSend(ACC_Q,&x,portMAX_DELAY);

        vTaskDelayUntil(&ui32WakeTime, pdMS_TO_TICKS(100));
    }
}

BaseType_t accelerometerTaskInit()
{
    MPU6050Initialize();

    // Create the task
    return xTaskCreate(accelerometerTask, (const portCHAR *)"ACCELEROMETER_TASK", ACCELEROMETERTASKSTACKSIZE, NULL, tskIDLE_PRIORITY + PRIORITY_ACCELEROMETER_TASK, NULL) == pdTRUE;
}
