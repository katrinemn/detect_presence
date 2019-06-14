/*
 *      PIRTask.h
 *
 *      Created on: 11-02-2016
 *      Author: Katrine Maria Nielsen
 */

#ifndef PIR_H_
#define PIR_H_

/***************************** Include files *******************************/

#include <stdint.h>
#include <stdbool.h>
#include "inc/hw_types.h"
#include "inc/hw_memmap.h"
#include "driverlib/sysctl.h"
#include "driverlib/gpio.h"

/*****************************   Prototypes   *******************************/
extern int8_t getPIRValue();
extern void PIRSensorInit();

#endif /* PIR_H_ */
