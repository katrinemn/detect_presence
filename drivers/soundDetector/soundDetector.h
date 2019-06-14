/*
 * x_task.h
 *
 *  Created on: 25-04-2016
 *      Author: Katrine Maria Nielsen
 */

#ifndef SOUND_DETECTOR_H_
#define SOUND_DETECTOR_H_

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
extern void soundDetectorInit();
extern int16_t getSoundValue();


#endif /* SOUND_DETECTOR_H_ */
