#include <buttonTask/buttonTask.h>
#include <CO2Task/CO2Task.h>
#include <drivers/led/ledTask.h>
#include <soundTask/soundTask.h>
#include <PIRTask/PIRTask.h>
#include <stateBuffers/stateBuffers.h>
#include <stdbool.h>
#include <stdint.h>
#include "inc/hw_memmap.h"
#include "inc/hw_types.h"
#include "driverlib/gpio.h"
#include "driverlib/pin_map.h"
#include "driverlib/rom.h"
#include "driverlib/sysctl.h"
#include "driverlib/uart.h"
#include "utils/uartstdio.h"
#include "FreeRTOS.h"
#include "task.h"
#include "queue.h"
#include "semphr.h"
#include "threading/threading.h"
#include "inputInterpret/inputInterpretTask.h"
#include "accelerometerTask/accelerometerTask.h"


// The error routine that is called if the driver library encounters an error.
#ifdef DEBUG
void
__error__(char *pcFilename, uint32_t ui32Line)
{
}

#endif

// This hook is called by FreeRTOS when an stack overflow error is detected.
void vApplicationStackOverflowHook(xTaskHandle *pxTask, char *pcTaskName)
{
    // This function can not return, so loop forever.  Interrupts are disabled
    // on entry to this function, so no processor interrupts will interrupt
    // this loop.
    while(1)
    {
    }
}

void vTaskInitError()
{
    while(1)
    {

    }
}

void
ConfigureUART(void)
{
    //
    // Enable the GPIO Peripheral used by the UART.
    //
    ROM_SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOA);

    //
    // Enable UART0
    //
    ROM_SysCtlPeripheralEnable(SYSCTL_PERIPH_UART0);

    //
    // Configure GPIO Pins for UART mode.
    //
    ROM_GPIOPinConfigure(GPIO_PA0_U0RX);
    ROM_GPIOPinConfigure(GPIO_PA1_U0TX);
    ROM_GPIOPinTypeUART(GPIO_PORTA_BASE, GPIO_PIN_0 | GPIO_PIN_1);

    //
    // Use the internal 16MHz oscillator as the UART clock source.
    //
    UARTClockSourceSet(UART0_BASE, UART_CLOCK_PIOSC);

    //
    // Initialize the UART for console I/O.
    //
    UARTStdioConfig(0, 9600, 16000000);
}
// Initialize FreeRTOS and start the initial set of tasks.
int main()
{
    ROM_SysCtlClockSet(SYSCTL_SYSDIV_4 | SYSCTL_USE_PLL | SYSCTL_XTAL_16MHZ | SYSCTL_OSC_MAIN);

	ConfigureUART();

	if(xQueuesCreated() == pdTRUE && xSemaphoresCreated() == pdTRUE)
	{

		if(!buttonTaskInit())
			vTaskInitError();

        if(!PIRTaskInit())
            vTaskInitError();

        if(!CO2TaskInit())
            vTaskInitError();

        if(!ledTaskInit())
            vTaskInitError();

        if(!soundTaskInit())
            vTaskInitError();

        if(!accelerometerTaskInit())
            vTaskInitError();

        if(!interpretTaskInit())
            vTaskInitError();

		// Start the scheduler. This should not return.
		vTaskStartScheduler();
	}

	// In case the scheduler returns for some reason, catch that
	while(1);
}
