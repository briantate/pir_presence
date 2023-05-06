#include "MCP3221.h"
#include "../config/default/driver/i2c/drv_i2c.h"

#define TWELVE_BIT (0xFFF)

STATIC struct MCP3221
{
    bool isActive;
    DRV_HANDLE i2cDriverHandle;
    DRV_I2C_TRANSFER_HANDLE i2cTransferHandle;
    uint16_t address;
    uint8_t buffer[2];
    uint16_t value;
    DRV_I2C_TRANSFER_EVENT event;
    MCP3221_Callback_t cb;
};

#define MAX_MCP3221_INSTANCES 4
static struct MCP3221 mcp3221Pool[MAX_MCP3221_INSTANCES] = {0};
static uint8_t numberOfMcp3221 = 0;

/* Private prototypes*/

STATIC void _I2CEventHandler (
    DRV_I2C_TRANSFER_EVENT event,
    DRV_I2C_TRANSFER_HANDLE transferHandle,
    uintptr_t context
);


/* Public API*/

#ifdef TEST
void MCP3221_SetBuffer(mcp3221Handle mcp3221, uint8_t val0, uint8_t val1)
{
    mcp3221->buffer[0] = val0;
    mcp3221->buffer[1] = val1;
}
#endif /*TEST*/

mcp3221Handle MCP3221_Open(uint16_t address, MCP3221_Callback_t cb)
{
    mcp3221Handle mcp3221 = NULL;
    for(uint8_t i = (uint8_t)0; i<MAX_MCP3221_INSTANCES; i++)
    {
        if(!mcp3221Pool[i].isActive)
        {
            mcp3221 = &mcp3221Pool[i];
            mcp3221->i2cDriverHandle = DRV_I2C_Open( DRV_I2C_INDEX_0, DRV_IO_INTENT_READWRITE);
            if( DRV_HANDLE_INVALID == mcp3221->i2cDriverHandle)
            { 
               return 0;
            }
            else
            {
                DRV_I2C_TransferEventHandlerSet(
                    mcp3221->i2cDriverHandle,
                    _I2CEventHandler,
                    (uintptr_t)mcp3221
                );
                
                mcp3221->isActive = true;
                mcp3221->value = 0;
                mcp3221->address = address;
                mcp3221->cb = cb;
                mcp3221->event = 0;
                numberOfMcp3221++;
                return mcp3221;
            }
        }
    }
    return mcp3221;
}

void MCP3221_Close(mcp3221Handle mcp3221)
{
    if(mcp3221->isActive)
    {
        DRV_I2C_Close(mcp3221->i2cDriverHandle);
        mcp3221->address = 0;
        mcp3221->value = 0;
        mcp3221->cb = NULL;
        mcp3221->isActive = false;
        mcp3221->event = 0;
        numberOfMcp3221--;
    }   
}

bool MCP3221_IsDeviceActive(mcp3221Handle mcp3221)
{
    return mcp3221->isActive;
}

bool MCP3221_ConversionStart(mcp3221Handle mcp3221)
{
    mcp3221->event = 0;
    DRV_I2C_ReadTransferAdd(mcp3221->i2cDriverHandle, 
                            mcp3221->address, 
                            mcp3221->buffer, 
                            2, 
                            &mcp3221->i2cTransferHandle);
    return true;
}

MCP3221_EVENT MCP3221_ConversionStatusGet(mcp3221Handle mcp3221)
{
    return mcp3221->event;
}

uint16_t MCP3221_ConversionResultGet(mcp3221Handle mcp3221)
{
    mcp3221->event = 0;
    return mcp3221->value;
}


/* Private functions*/

STATIC void _I2CEventHandler (
    DRV_I2C_TRANSFER_EVENT event,
    DRV_I2C_TRANSFER_HANDLE transferHandle,
    uintptr_t context
)
{
    mcp3221Handle mcp3221 = (mcp3221Handle)context;

    mcp3221->event = event;

    if ( DRV_I2C_TRANSFER_EVENT_COMPLETE == event)
    {
        mcp3221->value = TWELVE_BIT & ((mcp3221->buffer[1] ) | (mcp3221->buffer[0] << 8));
    }

    if(mcp3221->cb)
    {
        mcp3221->cb(mcp3221->event);
    }
}

    
