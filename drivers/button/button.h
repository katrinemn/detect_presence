/*
 *      buttonTask.h
 *
 *      Created on: 11-02-2016
 *      Author: Katrine Maria Nielsen
 */

#ifndef BUTTON_H_
#define BUTTON_H_

/***************************** Include files *******************************/
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


/*****************************   Prototypes   *******************************/
extern int8_t getButtonValue();
extern void buttonInit();

#endif /* BUTTON_H_ */
