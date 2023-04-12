#include "ANLG_Model.h"
#include "ANLG_Hardware.h"
#include "ANLG_Conductor.h"
#include "TMR.h"
#include <stdbool.h>

void ANLG_Conductor_Init(void)
{
    ANLG_Model_Init();
    ANLG_Hardware_Init();
    TMR_Init(5);
    TMR_Start();
}

void ANLG_Conductor_Run(void)
{
    uint8_t i;
    uint16_t value;

    if(true == TMR_IsExpired())
    {
        for(i=0; i<NUM_ADC_CHANNELS; i++)
        {
            if(STATUS_OK == ANLG_Hardware_IsReady(i))
            {
                value = ANLG_Hardware_ReadChannel(i);
                ANLG_Model_UpdateData(i, value);
            }
        }
    }

}