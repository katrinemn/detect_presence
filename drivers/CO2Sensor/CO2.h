/*
 *      CO2Task.h
 *
 *      Created on: 11-02-2017
 *      Author: Katrine Maria Nielsen
 */

#ifndef CO2_H_
#define CO2_H_

/***************************** Include files *******************************/
#include <stdbool.h>
#include <stdint.h>
#include <stdbool.h>
#include <stdint.h>
#include "UI_protocol.h"
#include "driverlib/rom.h"
#include "inc/hw_types.h"
#include "inc/hw_gpio.h"
#include "inc/hw_memmap.h"
#include "inc/hw_types.h"
#include "driverlib/gpio.h"
#include "driverlib/pin_map.h"
#include "driverlib/sysctl.h"
#include "inc/hw_adc.h"

/*****************************   Prototypes   *******************************/
extern int16_t getCO2Value();
extern void CO2SensorInit();

#endif /* CO2_H_ */
