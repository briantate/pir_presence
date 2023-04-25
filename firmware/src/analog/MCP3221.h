#ifndef MCP3221_H
#define MCP3221_H

#include "Defs.h"
#include <stdbool.h>

typedef enum
{
    MCP3221_CONVERSION_PENDING = 0,
    MCP3221_CONVERSION_COMPLETE = 1,
    MCP3221_EVENT_ERROR = -1,
}MCP3221_EVENT;

typedef struct MCP3221* mcp3221Handle;
typedef void (*MCP3221_Callback_t)(MCP3221_EVENT event);

mcp3221Handle MCP3221_Open(uint16_t address, MCP3221_Callback_t cb);
void MCP3221_Close(mcp3221Handle mcp3221);
bool MCP3221_IsDeviceActive(mcp3221Handle mcp3221);
bool MCP3221_StartConversion(mcp3221Handle mcp3221);
bool MCP3221_IsConversionReady(mcp3221Handle mcp3221);
uint16_t MCP3221_GetResult(mcp3221Handle mcp3221);


#endif // MCP3221_H
