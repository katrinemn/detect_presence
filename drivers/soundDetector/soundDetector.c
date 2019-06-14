/*
 *      soundTask.h
 *
 *      Created on: 11-02-2017
 *      Author: Katrine Maria Nielsen
 */

/*************************** Include files *********************************/
#include <drivers/soundDetector/soundDetector.h>
/*****************************    Defines    *******************************/
#define SOUND_DETECTOR               HWREG(ADC0_BASE + ADC_O_SSFIFO2)

/***************************** Variables ***********************************/

/***************************** Functions ***********************************/

int16_t getSoundValue()
{
    int16_t soundValue = SOUND_DETECTOR;
    return soundValue;
}

void soundDetectorInit()
{
    //1. Enable the ADC clock using the RCGCADC
    SysCtlPeripheralEnable(SYSCTL_PERIPH_ADC0); // use ADC0

    //2. Enable the clock to the appropriate GPIO modules via the RCGCGPIO register
    SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOE); //use port E

    //3. Set the GPIO AFSEL bits for the ADC input pins (see page 669).
    GPIOPadConfigSet(GPIO_PORTE_BASE,GPIO_PIN_2, GPIO_STRENGTH_2MA,GPIO_PIN_TYPE_ANALOG); // PE2

    //4. Configure the AINx signals to be analog inputs by clearing the corresponding DEN bit in the
    //   GPIO Digital Enable (GPIODEN) register (see page 680).
    HWREG(GPIO_PORTE_BASE + GPIO_O_DEN) &= ~(1<<2); // PE2

    //5. Disable the analog isolation circuit for all ADC input pins that are to be used by writing a 1 to
    //   the appropriate bits of the GPIOAMSEL register (see page 685) in the associated GPIO block.
    HWREG(GPIO_PORTE_BASE + GPIO_O_AMSEL)  |= (1<<2);

    //6. If required by the application, reconfigure the sample sequencer priorities in the ADCSSPRI
    //   register. The default configuration has Sample Sequencer 0 with the highest priority and Sample
    //   Sequencer 3 as the lowest priority.

     /* Sample Sequencer Configuration */

    //1. Ensure that the sample sequencer is disabled by clearing the corresponding ASENn bit in the
    //   ADCACTSS register. Programming of the sample sequencers is allowed without having them
    //   enabled. Disabling the sequencer during programming prevents erroneous execution if a trigger
    //   event were to occur during the configuration process.
    HWREG(ADC0_BASE + ADC_O_ACTSS) &= ~(1 << 2); // disable sample sequencer 2

    //2. Configure the trigger event for the sample sequencer in the ADCEMUX register.
    HWREG(ADC0_BASE + ADC_O_EMUX) = (0xF << 8); // SS2; trigger event = continous sample

    //3. When using a PWM generator as the trigger source, use the ADC Trigger Source Select
    //  (ADCTSSEL) register to specify in which PWM module the generator is located. The default
    //   register reset selects PWM module 0 for all generators.

    //4. For each sample in the sample sequence, configure the corresponding input source in the
    //   ADCSSMUXn register.
    HWREG(ADC0_BASE + ADC_O_SSMUX2) = 1; // ani1

    //5. For each sample in the sample sequence, configure the sample control bits in the corresponding
    //   nibble in the ADCSSCTLn register. When programming the last nibble, ensure that the END bit
    //   is set. Failure to set the END bit causes unpredictable behavior.
    HWREG(ADC0_BASE + ADC_O_SSCTL2) = 0x2; // 0010

    //6. If interrupts are to be used, set the corresponding MASK bit in the ADCIM register.

    //7. Enable the sample sequencer logic by setting the corresponding ASENn bit in the ADCACTSS
    //   register.
    HWREG(ADC0_BASE + ADC_O_ACTSS)  |= (1 << 2);

}
