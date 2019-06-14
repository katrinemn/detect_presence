/*
 *      stateBuffers.h
 *
 *      Created on: 11-02-2017
 *      Author: Katrine Maria Nielsen
 */

#ifndef STATE_BUFFERS_H_
#define STATE_BUFFERS_H_

/**************************** Include files ********************************/
#include <stdint.h>
#include <stdbool.h>
#include "emp_type.h"
#include <stdio.h>
#include "utils/uartstdio.h"

/****************************  Prototypes **********************************/
// Blabla
extern	INT8U   getLED();
extern  INT8U   setLED(INT8U on);
extern  void    printUART(INT16U on);
extern  void    printStringUART(const char *pcString);
extern  void    printUARTData(int16_t CO2, int16_t PIR, int16_t SOUND,int16_t x, int16_t y, int16_t z);

#endif /* STATE_BUFFERS_H_ */
