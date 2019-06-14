/*
 *      CO2Task.h
 *
 *      Created on: 11-02-2017
 *      Author: Katrine Maria Nielsen
 */

#ifndef CO2_TASK_H_
#define CO2_TASK_H_

/***************************** Include files *******************************/
#include <stdbool.h>
#include <stdint.h>
#include "FreeRTOS.h"
#include "task.h"
#include <threading/threading.h>
#include "emp_type.h"
#include "UI_protocol.h"
#include "queue.h"
#include "semphr.h"
#include "priorities.h"
#include "stateBuffers/stateBuffers.h"
#include "drivers/CO2Sensor/CO2.h"


/*****************************   Prototypes   *******************************/
extern BaseType_t CO2TaskInit();

#endif /* CO2_TASK_H_ */
