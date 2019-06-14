/*
 *      buttonTask.h
 *
 *      Created on: 11-02-2017
 *      Author: Katrine Maria Nielsen
 */

/*************************** Include files *********************************/
#include "drivers/button/button.h"

/*****************************    Defines    *******************************/
#define BUTTONTASKSTACKSIZE        	100         // Stack size in words
#define	SWITCH_BITS					GPIOPinRead(GPIO_PORTF_BASE, GPIO_PIN_4 | GPIO_PIN_0)
#define	SWITCH_ONE_VALUE			    GPIOPinRead(GPIO_PORTF_BASE, GPIO_PIN_0)
#define	SWITCH_TWO_VALUE			    GPIOPinRead(GPIO_PORTF_BASE, GPIO_PIN_4)
#define BTN_OFF						1
#define BTN_ON						0

/***************************** Variables ***********************************/
volatile int8_t previousValueOne = 0x0;
volatile int8_t previousValueTwo = 0x0;

/***************************** Functions ***********************************/
int8_t getButtonValue()
{
    int8_t  pressValue = 0;
    	int8_t buttonValue = SWITCH_BITS;

    	if((SWITCH_ONE_VALUE) != previousValueOne)
    	{
    		previousValueOne = (SWITCH_ONE_VALUE);
    		if(previousValueOne)
    			pressValue = SWITCH_ONE_OFF;
    		else
    			pressValue = SWITCH_ONE_ON;
    		return pressValue;
    	}


    	if((SWITCH_TWO_VALUE) != previousValueTwo)
		{
    		previousValueTwo = (SWITCH_TWO_VALUE);
    		if(previousValueTwo)
    		    pressValue = SWITCH_TWO_OFF;
    		else
    		    pressValue = SWITCH_TWO_ON;
    		 return pressValue;

		}
    return 0;
}

void buttonInit()
{
        SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOF);
        HWREG(GPIO_PORTF_BASE + GPIO_O_LOCK) = GPIO_LOCK_KEY;
        HWREG(GPIO_PORTF_BASE + GPIO_O_CR) = 0xFF;
         GPIOPinTypeGPIOInput(GPIO_PORTF_BASE, GPIO_PIN_4);
        GPIOPinTypeGPIOInput(GPIO_PORTF_BASE, GPIO_PIN_0);
        GPIOPadConfigSet(GPIO_PORTF_BASE,GPIO_PIN_4, GPIO_STRENGTH_2MA,GPIO_PIN_TYPE_STD_WPU);
        GPIOPadConfigSet(GPIO_PORTF_BASE,GPIO_PIN_0, GPIO_STRENGTH_2MA,GPIO_PIN_TYPE_STD_WPU);
}
