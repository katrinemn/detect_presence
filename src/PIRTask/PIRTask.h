/*
 *      PIRTask.h
 *
 *      Created on: 11-02-2016
 *      Author: Katrine Maria Nielsen
 */

#ifndef PIR_TASK_H_
#define PIR_TASK_H_

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
#include "stateBuffers/stateBuffers.h"
#include "drivers/PIR/PIR.h"
/*****************************   Prototypes   *******************************/
extern uint32_t PIRTaskInit();

#endif /* PIR_TASK_H_ */
