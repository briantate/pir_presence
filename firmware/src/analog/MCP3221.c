#include "MCP3221.h"
#include "drv_i2c.h"

DRV_HANDLE i2cDriverHandle = DRV_HANDLE_INVALID;

struct MCP3221
{
    bool isActive;
    uint16_t address;
    uint16_t value;
};

#define MAX_MCP3221_INSTANCES 4
static struct MCP3221 mcp3221Pool[MAX_MCP3221_INSTANCES] = {0};
static uint8_t numberOfMcp3221 = 0;

STATUS_T MCP3221_BusInit(void)
{
    STATUS_T ret = STATUS_UNKNOWN_ERR;

    i2cDriverHandle = DRV_I2C_Open( DRV_I2C_INDEX_0, DRV_IO_INTENT_READWRITE);
    if( DRV_HANDLE_INVALID != i2cDriverHandle)
    {
        ret = STATUS_OK;
    }
        
    return ret;
}

mcp3221Handle MCP3221_Create(uint16_t address)
{
    mcp3221Handle mcp3221 = NULL;
    for(uint8_t i = (uint8_t)0; i<MAX_MCP3221_INSTANCES; i++)
    {
        if(!mcp3221Pool[i].isActive)
        {
            mcp3221 = &mcp3221Pool[i];
			mcp3221->isActive = true;
            mcp3221->value = 0;
            mcp3221->address = address;
            return mcp3221;
        }
    }
    return mcp3221;
}

void MCP3221_Destroy(mcp3221Handle mcp3221)
{
    mcp3221->address = 0;
    mcp3221->value = 0;
    mcp3221->isActive = false;
}

bool MCP3221_IsActive(mcp3221Handle mcp3221)
{
    return mcp3221->isActive;
}
