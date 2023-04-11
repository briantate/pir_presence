#include "ANLG_Model.h"
// #include "filter.h"
#include "Defs.h"

STATIC uint16_t analogData[NUM_ANALOG_MODEL_CHANNELS];

void ANLG_Model_Init(void)
{
    for(ANALOG_MODEL_CHANNEL_T i=0; i<NUM_ANALOG_MODEL_CHANNELS; i++)
    {
        analogData[i] = 0;
    }
}

uint16_t ANLG_Model_GetData(ANALOG_MODEL_CHANNEL_T channel)
{
    uint16_t ret = 0;
    if(NUM_ANALOG_MODEL_CHANNELS > channel)
    {
        ret = analogData[channel];
    }
    return ret;
}

void ANLG_Model_UpdateData(ANALOG_MODEL_CHANNEL_T channel, uint16_t val)
{
    if(NUM_ANALOG_MODEL_CHANNELS > channel)
    {
        analogData[channel] = val;
    }   
    //Do Nothing if invalid channel?
}
