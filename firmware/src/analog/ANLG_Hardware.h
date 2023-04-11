/* a light wrapper for the analog hardware*/

#ifndef ANLG_HARDWARE_H
#define ANLG_HARDWARE_H

#include <stdint.h>
#include "Defs.h"

typedef enum _ADC_CHANNELS_T
{
    ADC_CH_0 = 0,
    ADC_CH_1,
    ADC_CH_2,
    ADC_CH_3,
    NUM_ADC_CHANNELS
} ADC_CHANNELS_T;

void ANLG_Hardware_Init(void);
STATUS_T ANLG_Hardware_IsReady(ADC_CHANNELS_T channel);
uint16_t ANLG_Hardware_ReadChannel(ADC_CHANNELS_T channel);

#endif // ANLG_HARDWARE_H
