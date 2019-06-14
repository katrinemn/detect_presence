/*
 *      x_task.h
 *
 *      Created on: 11-02-2017
 *      Author: Katrine Maria Nielsen
 */

#ifndef X_TASK_H_
#define X_TASK_H_

/***************************** Include files *******************************/
#include <stdbool.h>
#include <stdint.h>
#include "FreeRTOS.h"
#include "task.h"
#include "queue.h"
#include "semphr.h"
#include "priorities.h"

/*****************************   Prototypes   *******************************/
extern BaseType_t XTaskInit();

#endif /* X_TASK_H_ */
