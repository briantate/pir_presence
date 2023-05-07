#include "ANLG_Adapter.h"
#include "MCP3221.h"
#include "Defs.h"

STATIC mcp3221Handle mcp3221;
STATIC bool isConversionComplete;
STATIC uint16_t analogValue;

STATIC void _MCP3221_Callback(MCP3221_EVENT event)
{
    isConversionComplete = true;
    if (MCP3221_EVENT_CONVERSION_COMPLETE == event)
    {
        analogValue = MCP3221_ConversionResultGet(mcp3221);
    }
}


bool ANLG_Init(void)
{
    bool ret = false;
    isConversionComplete = true;
    analogValue = 0;
    mcp3221 = MCP3221_Open(0x4D, _MCP3221_Callback);
    if(0!=mcp3221)
    {
        ret = true;
    }
    return ret;
}

void ANLG_DeInit(void)
{
    MCP3221_Close(mcp3221);
    mcp3221 = 0;
}

uint16_t ANLG_ConversionResultGet(void)
{
    if(isConversionComplete)
    {
        isConversionComplete = false;
        MCP3221_ConversionStart(mcp3221);
    }

    return analogValue;
}