/*
 *      ledTask.h
 *
 *      Created on: 11-02-2017
 *      Author: Katrine Maria Nielsen
 */

#ifndef LED_TASK_H_
#define LED_TASK_H_

/***************************** Include files *******************************/
#include <stdbool.h>
#include <stdint.h>
#include "../../stateBuffers/stateBuffers.h"
#include "FreeRTOS.h"
#include "task.h"
#include "emp_type.h"
#include "queue.h"
#include "semphr.h"
#include "priorities.h"
#include "threading/threading.h"
#include "UI_protocol.h"
#include "utils/uartstdio.h"
#include <stdint.h>
#include <stdbool.h>
#include "inc/hw_types.h"
#include "inc/hw_memmap.h"
#include "driverlib/sysctl.h"
#include "driverlib/gpio.h"

/*****************************   Prototypes   *******************************/
extern BaseType_t ledTaskInit();

#endif /* LED_TASK_H_ */
