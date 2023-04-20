#ifndef MCP3221_H
#define MCP3221_H

#include "Defs.h"
#include <stdbool.h>

typedef struct MCP3221* mcp3221Handle;
// typedef uint16_t (*ADC_GetVal_t)(void); //I2C read function injection

STATUS_T MCP3221_BusInit(void);
mcp3221Handle MCP3221_Create(uint16_t address);
void MCP3221_Destroy(mcp3221Handle mcp3221);
bool MCP3221_IsActive(mcp3221Handle mcp3221);


#endif // MCP3221_H
