/*
 * threading.h
 *
 *  Created on: 11-02-2017
 *      Author: Katrine Maria Nielsen
 */

#ifndef THREADING_H_
#define THREADING_H_

/***************************** Include files *******************************/
#include <stdint.h>
#include <stdbool.h>
#include "FreeRTOS.h"
#include "queue.h"
#include "semphr.h"
#include "emp_type.h"

/*****************************   Variables   *******************************/
// Queue handles
extern xQueueHandle bUI_Q;
extern xQueueHandle UI_Q;
extern xQueueHandle PIR_Q;
extern xQueueHandle CO2_Q;
extern xQueueHandle SOUND_Q;
extern xQueueHandle ACC_Q;

// Mutex handles
extern xSemaphoreHandle ledMutexX;
extern xSemaphoreHandle xMutexX;
extern xSemaphoreHandle uartMutexX;

/*****************************   Prototypes   *******************************/
extern BaseType_t xQueuesCreated();
extern BaseType_t xSemaphoresCreated();


#endif /* THREADING_H_ */
