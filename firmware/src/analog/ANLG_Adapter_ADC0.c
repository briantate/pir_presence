#include "ANLG_Adapter.h"
#include "peripheral/adc/plib_adc0.h"
#include "Defs.h"

STATIC bool isConversionComplete;
STATIC uint16_t analogValue;

bool ANLG_Init(void)
{
    isConversionComplete = true;
    analogValue = 0;
    ADC0_Enable();
    return true;
}

void ANLG_DeInit(void)
{
    ADC0_Disable();
}

uint16_t ANLG_ConversionResultGet(void)
{
    if(true == isConversionComplete)
    {
        ADC0_ConversionStart();

        while(!ADC0_ConversionStatusGet())
        {

        };

        analogValue = ADC0_ConversionResultGet();
        if(4095 < analogValue)
        {
            analogValue = 4095;
        }
    }

    return analogValue;
}
