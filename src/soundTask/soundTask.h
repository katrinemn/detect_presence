/*
 * x_task.h
 *
 *  Created on: 25-04-2016
 *      Author: Katrine Maria Nielsen
 */

#ifndef SOUND_TASK_H_
#define SOUND_TASK_H_

/***************************** Include files *******************************/
#include <stdbool.h>
#include <stdint.h>
#include "FreeRTOS.h"
#include "task.h"
#include <threading/threading.h>
#include "emp_type.h"
#include "queue.h"
#include "semphr.h"
#include "priorities.h"
#include "UI_protocol.h"
#include <drivers/soundDetector/soundDetector.h>

/*****************************   Prototypes   *******************************/
extern BaseType_t soundTaskInit();

#endif /* SOUND_TASK_H_ */
