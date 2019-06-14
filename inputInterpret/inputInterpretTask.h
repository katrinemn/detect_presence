/*
 *      x_task.h
 *
 *      Created on: 11-02-2017
 *      Author: Katrine Maria Nielsen
 */

#ifndef INPUTINTERPRET_TASK_H_
#define INPUTINTERPRET_TASK_H_

/***************************** Include files *******************************/
#include <stdbool.h>
#include <stdint.h>
#include "FreeRTOS.h"
#include "task.h"
#include "queue.h"
#include "semphr.h"
#include "priorities.h"
#include "emp_type.h"
#include "stateBuffers/stateBuffers.h"
#include "threading/threading.h"

/*****************************   Prototypes   *******************************/
extern BaseType_t interpretTaskInit();

#endif /* INPUTINTERPRET_TASK_H_ */
