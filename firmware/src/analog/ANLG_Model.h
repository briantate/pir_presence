#ifndef ANLG_MODEL_H
#define ANLG_MODEL_H

#include <stdint.h>

typedef enum _ANALOG_MODEL_CHANNEL
{
    ANALOG_CH_0 = 0,
    ANALOG_CH_1,
    ANALOG_CH_2,
    ANALOG_CH_3,
    ANALOG_CH_4,
    ANALOG_CH_5,
    NUM_ANALOG_MODEL_CHANNELS
} ANALOG_MODEL_CHANNEL_T;

void ANLG_Model_Init(void);
uint16_t ANLG_Model_GetData(ANALOG_MODEL_CHANNEL_T channel);
void ANLG_Model_UpdateData(ANALOG_MODEL_CHANNEL_T channel, uint16_t val);

#endif // ANLG_MODEL_H
