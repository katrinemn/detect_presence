/*
 *      PIRTask.h
 *
 *      Created on: 11-02-2017
 *      Author: Katrine Maria Nielsen
 */

/*************************** Include files *********************************/
#include <drivers/PIR/PIR.h>
/*****************************    Defines    *******************************/
#define PIR_SENSOR              GPIOPinRead(GPIO_PORTA_BASE, GPIO_PIN_2)
/***************************** Variables ***********************************/

/***************************** Functions ***********************************/
int8_t getPIRValue()
{
    int8_t PIRValue = PIR_SENSOR;
    return PIRValue;
}



void PIRSensorInit()
{
    SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOA);
    GPIOPinTypeGPIOInput(GPIO_PORTA_BASE, GPIO_PIN_2);
}
