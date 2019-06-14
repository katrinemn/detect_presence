/*
 *      accelerometerTask.h
 *
 *      Created on: 11-02-2017
 *      Author: Katrine Maria Nielsen
 */

#ifndef ACCELEROMETER_H_
#define ACCELEROMETER_H_

/***************************** Include files *******************************/
#include <stdbool.h>
#include <stdint.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "FreeRTOS.h"
#include "task.h"
#include "emp_type.h"
#include "UI_protocol.h"
#include "queue.h"
#include "semphr.h"
#include "priorities.h"
#include "stateBuffers/stateBuffers.h"
#include "inc/hw_memmap.h"
#include "inc/hw_ints.h"
#include "driverlib/pin_map.h"
#include "driverlib/i2c.h"
#include "driverlib/rom.h"
#include "driverlib/gpio.h"
#include "driverlib/sysctl.h"
#include "sensorlib/i2cm_drv.h"
#include "utils/uartstdio.h"
#include "sensorlib/hw_mpu6050.h"
#include "sensorlib/mpu6050.h"
#include "queue.h"
#include "semphr.h"
#include "priorities.h"



/*****************************   Prototypes   *******************************/
extern void I2CM_I2C0_IntHandler();
extern void MPU6050ReadAccel();
extern void MPU6050ReadInit();
extern void MPU6050Initialize();
extern float * MPU6050GetAccelMean(int xreadings);
extern float * MPU6050GetAccelChange(int xreadings);

#endif /* ACCELEROMETER_H_ */
