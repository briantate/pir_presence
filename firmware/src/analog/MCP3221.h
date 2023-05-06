#ifndef MCP3221_H
#define MCP3221_H

#include "Defs.h"
#include <stdbool.h>

typedef enum
{
    MCP3221_EVENT_CONVERSION_PENDING = 0,
    MCP3221_EVENT_CONVERSION_COMPLETE = 1,
    MCP3221_EVENT_CONVERSION_ERROR = -1,
    MCP3221_EVENT_HANDLE_INVALID = -2,
}MCP3221_EVENT;

typedef struct MCP3221* mcp3221Handle;
typedef void (*MCP3221_Callback_t)(MCP3221_EVENT event);

mcp3221Handle MCP3221_Open(uint16_t address, MCP3221_Callback_t cb);
void MCP3221_Close(mcp3221Handle mcp3221);
bool MCP3221_IsDeviceActive(mcp3221Handle mcp3221);
bool MCP3221_ConversionStart(mcp3221Handle mcp3221);
MCP3221_EVENT MCP3221_ConversionStatusGet(mcp3221Handle mcp3221);
uint16_t MCP3221_ConversionResultGet(mcp3221Handle mcp3221);

#ifdef TEST
void MCP3221_SetBuffer(mcp3221Handle mcp3221, uint8_t val0, uint8_t val1);
#endif /*TEST*/


#endif // MCP3221_H
