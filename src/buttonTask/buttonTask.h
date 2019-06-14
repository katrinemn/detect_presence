/*
 *      buttonTask.h
 *
 *      Created on: 11-02-2016
 *      Author: Katrine Maria Nielsen
 */

#ifndef BUTTON_TASK_H_
#define BUTTON_TASK_H_

/***************************** Include files *******************************/
#include <stdbool.h>
#include <stdint.h>
#include "FreeRTOS.h"
#include "task.h"
#include "queue.h"
#include "semphr.h"
#include "priorities.h"
#include <threading/threading.h>
#include "emp_type.h"
#include "UI_protocol.h"
#include <stdbool.h>
#include "stateBuffers/stateBuffers.h"
#include "inc/hw_memmap.h"
#include "inc/hw_types.h"
#include "inc/hw_gpio.h"
#include "driverlib/sysctl.h"
#include "driverlib/gpio.h"
#include "driverlib/rom.h"
#include "utils/uartstdio.h"
#include "FreeRTOS.h"
#include "drivers/button/button.h"

/*****************************   Prototypes   *******************************/
extern BaseType_t buttonTaskInit();

#endif /* BUTTON_TASK_H_ */
