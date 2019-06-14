/*
 *      accelerometerTask.h
 *
 *      Created on: 11-02-2017
 *      Author: Katrine Maria Nielsen
 */

#ifndef ACCELEROMETER_TASK_H_
#define ACCELEROMETER_TASK_H_

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
#include "drivers/accelerometer/accelerometer.h"


/*****************************   Prototypes   *******************************/
extern BaseType_t accelerometerTaskInit();


#endif /* ACCELEROMETER_TASK_H_ */
