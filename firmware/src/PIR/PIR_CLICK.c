#include "PIR_CLICK.h"

//PIR click is powered by 3.3V
//Kemet PL-N823-01 is the IR sensor
    // "KEMET’s Pyroelectric Infrared Sensors use the pyroelectric
    // effect of ceramic by absorbing infrared rays emitted from
    // the human body. This detects the natural infrared signature
    // produced by humans."
    //Output voltage

typedef struct PIR* pirHandle;
typedef void (*PIR_Callback_t)(PIR_EVENT event, pirHandle handle);
typedef uint16_t (*Analog_ReadChannel_t)(uint8_t channel);

pirHandle PIR_Open(uint16_t address, PIR_Callback_t cb, Analog_ReadChannel_t ReadChannel){}
void PIR_Close(pirHandle pir){}
bool PIR_IsDeviceActive(pirHandle pir){}
bool PIR_Run(pirHandle pir)
{
    //should read analog channels
    //should compare against a threshold
    //should call user callback if event is detected
}
bool PIR_IsPresenceDetected(pirHandle pir){}   