#include "PIR_CLICK.h"
#include "analog/ANLG_Adapter.h"

//PIR click is powered by 3.3V
//Kemet PL-N823-01 is the IR sensor
    // "KEMET’s Pyroelectric Infrared Sensors use the pyroelectric
    // effect of ceramic by absorbing infrared rays emitted from
    // the human body. This detects the natural infrared signature
    // produced by humans."
    //Output voltage
#define MOTION_DETECT_THRESHOLD (2500)


bool PIR_Init(void)
{
   return ANLG_Init();

}

bool PIR_IsPresent(void)
{
    return (ANLG_ConversionResultGet() >= MOTION_DETECT_THRESHOLD);
}
  