/*
 *      AccelerometerTask.h
 *
 *      Created on: 11-02-2017
 *      Author: Katrine Maria Nielsen
 */


/**************************** Include files ********************************/
#include "drivers/accelerometer/accelerometer.h"

/*****************************  Defines  ***********************************/

/******************************** Variables **************************************/
volatile static uint_fast8_t g_vui8I2CDoneFlag;     // Global flags to alert I2C transaction is complete
volatile static uint_fast8_t g_vui8ErrorFlag;       // Global flags to alert I2C transaction error has occurred.
static tI2CMInstance g_sI2CMI2C0Inst;               // The I2C master driver instance data, for the I2C2 peripheral
static uint8_t writeDataBuffer[200] = {0};          // Buffer for the I2C writing, due to the register addr, so to use the buffer
static tMPU6050 sMPU6050;

/******************************** Functions **************************************/
void I2CM_I2C0_IntHandler()
{
    // Pass through to the I2CM interrupt handler provided by sensor library.
    // This is required to be at application level so that I2CMIntHandler can
    // receive the instance structure pointer as an argument.
    I2CMIntHandler(&g_sI2CMI2C0Inst);
}

static void I2CWait(char *pcFilename, uint_fast32_t ui32Line)
{
    // Wait
    while(g_vui8I2CDoneFlag == 0 && g_vui8ErrorFlag == 0)
    {
       vTaskDelay(pdMS_TO_TICKS(1));
    }

    // If an error occurrs, notify user
    if(g_vui8ErrorFlag)
    {
        UARTprintf("I2C Error: %d line: %d\n", g_vui8ErrorFlag, ui32Line);
    }

    // Clear the data flag for next use
    g_vui8I2CDoneFlag = 0;
}

static void I2CCallback(void *pvCallbackData, uint_fast8_t ui8Status)
{
    // If the transaction succeeded set the data flag to indicate to
    // application that this transaction is complete and data may be ready.
    if(ui8Status == I2CM_STATUS_SUCCESS)
        g_vui8I2CDoneFlag = 1;
    // Store the most recent status in case it was an error condition
    g_vui8ErrorFlag = ui8Status;
}

static void I2C0Init()
{
    // The I2C2 peripheral must be enabled before use.
    ROM_SysCtlPeripheralEnable(SYSCTL_PERIPH_I2C0);
    ROM_SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOB);

    // Configure the pin muxing for I2C3 functions on port D0 and D1.
    // This step is not necessary if your part does not support pin muxing.
    ROM_GPIOPinConfigure(GPIO_PB2_I2C0SCL);
    ROM_GPIOPinConfigure(GPIO_PB3_I2C0SDA);

    // Select the I2C function for these pins.  This function will also
    // configure the GPIO pins pins for I2C operation, setting them to
    // open-drain operation with weak pull-ups.  Consult the data sheet
    // to see which functions are allocated per pin.
    ROM_GPIOPinTypeI2CSCL(GPIO_PORTB_BASE, GPIO_PIN_2);
    ROM_GPIOPinTypeI2C(GPIO_PORTB_BASE, GPIO_PIN_3);

    I2CIntRegister(I2C0_BASE, I2CM_I2C0_IntHandler);
    I2CMasterTimeoutSet(I2C0_BASE, 0x7D);

    // Initialize the I2C master driver. It is assumed that the I2C module has
    // already been enabled and the I2C pins have been configured.
    I2CMInit(&g_sI2CMI2C0Inst, I2C0_BASE, INT_I2C0, 0xFF, 0xFF, ROM_SysCtlClockGet());

    ROM_I2CMasterInitExpClk(I2C0_BASE, ROM_SysCtlClockGet(), false);
    I2CMasterTimeoutSet(I2C0_BASE, 0x7D);
}

static int I2CWrite(unsigned char slaveAddr, unsigned char regAddr, const unsigned char *dataPtr,  unsigned short dataLength)
{
    int32_t result = 0;
    g_vui8I2CDoneFlag = 0;
    uint16_t iCounter = 0; // Counter for move the register address and the write data into the write buffer

    // Put the register address into the i2c write buffer
    writeDataBuffer[0] = regAddr;

    // Copy data to buffer
    if(dataLength > 0)
        for(iCounter = 1; iCounter <= dataLength; iCounter++)
            writeDataBuffer[iCounter] = dataPtr[iCounter - 1];

    // Write
    I2CMWrite(&g_sI2CMI2C0Inst, slaveAddr, writeDataBuffer, (dataLength+1), I2CCallback, 0);

    // Wait for completion
    I2CWait(__FILE__, __LINE__);

    // Check result
    if(g_vui8ErrorFlag)
        result = 1;

    // Return
    return result;
}

static int I2CRead(unsigned char slaveAddr, unsigned char regAddr, unsigned char *dataPtr, unsigned short dataLength)
{
    int32_t result = 0;
    g_vui8I2CDoneFlag = 0;

    // Read
    I2CMRead(&g_sI2CMI2C0Inst, slaveAddr, &regAddr, 1, dataPtr, dataLength, I2CCallback, 0);

    // Wait for completion
    I2CWait(__FILE__, __LINE__);

    // Check result
    if(g_vui8ErrorFlag)
        result = 1;

    // Return
    return result;
}

void MPU6050Initialize()
{
    // Init I2C
    I2C0Init();
}
void MPU6050ReadInit()
{
    // Initialize the MPU6050. This code assumes that the I2C master instance has already been initialized
    MPU6050Init(&sMPU6050, &g_sI2CMI2C0Inst, 0x68, I2CCallback, &sMPU6050);

    // Wait for completion
    I2CWait(__FILE__, __LINE__);

    // Configure the MPU6050 for +/- 4 g accelerometer range
    MPU6050ReadModifyWrite(&sMPU6050, MPU6050_O_ACCEL_CONFIG, ~MPU6050_ACCEL_CONFIG_AFS_SEL_M, MPU6050_ACCEL_CONFIG_AFS_SEL_4G, I2CCallback, &sMPU6050);

    // Wait for completion
    I2CWait(__FILE__, __LINE__);

    // Get address
    unsigned char address = 0;
    I2CRead(sMPU6050.ui8Addr, MPU6050_O_WHO_AM_I, &address, 1);

    // Print


    unsigned char writeData = 0;
    I2CWrite(sMPU6050.ui8Addr, MPU6050_O_PWR_MGMT_1, &writeData, 1);

}

float * MPU6050GetAccelMean(int xreadings)
{
    float Total[3] = {0};
    float fAccel[3] = {0};
    int i = 0;
    for(; i < xreadings; i++)
    {

        if(MPU6050DataRead(&sMPU6050, I2CCallback, &sMPU6050) == 1)
        {
            // Wait for completion
            I2CWait(__FILE__, __LINE__);

            // FLOAT

            // Print acc
            MPU6050DataAccelGetFloat(&sMPU6050, &fAccel[0], &fAccel[1], &fAccel[2]);
            Total[0]+=fAccel[0];
            Total[1]+=fAccel[1];
            Total[2]+=fAccel[2];

        }
        else
        {
            UARTprintf("MPU6050DataRead error!\n");
        }
    }
    Total[0] /= xreadings;
    Total[1] /= xreadings;
    Total[2] /= xreadings;


    return Total;

}

float * MPU6050GetAccelChange(int xreadings)
{
    float * initial = MPU6050GetAccelMean(xreadings);
    float previous[3] = {0};
    float new[3] = {0};
     previous[0] = initial[0]*100;
     previous[1] = initial[1]*100;
     previous[2] = initial[2]*100;
    float * subtractor = MPU6050GetAccelMean(xreadings);
    new[0] = subtractor[0]*100;
    new[1] = subtractor[1]*100;
    new[2] = subtractor[2]*100;
    float total[3] = {0};
    total[0] = previous[0]-new[0];
    total[1] = previous[1]-new[1];
    total[2] = previous[2]-new[2];
    vTaskDelay(pdMS_TO_TICKS(1));
    return total;

}

void MPU6050ReadAccel()
{
    float fAccel[3] = {0};
    // Request another reading from the MPU6050.
    if(MPU6050DataRead(&sMPU6050, I2CCallback, &sMPU6050) == 1)
    {
        // Wait for completion
        I2CWait(__FILE__, __LINE__);

        // FLOAT

        // Print acc
        MPU6050DataAccelGetFloat(&sMPU6050, &fAccel[0], &fAccel[1], &fAccel[2]);
        char string[50];
        sprintf(string, "x: %f y: %f z: %f", fAccel[0], fAccel[1], fAccel[2]);
        UARTprintf("Acc: %s\n", string);

    }
    else
    {
        UARTprintf("MPU6050DataRead error!\n");
    }

}
