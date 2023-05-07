#ifdef TEST

#include "unity.h"

#include "MCP3221.h"
#include "mock_drv_i2c.h"
#include "Defs.h"

mcp3221Handle mcp3221 = 0;

void MyMCP3221_Callback(MCP3221_EVENT event)
{
    //do stuff
}

void setUp(void)
{
    DRV_I2C_Open_ExpectAndReturn( DRV_I2C_INDEX_0, DRV_IO_INTENT_READWRITE, 0x12345678 );
    DRV_I2C_TransferEventHandlerSet_ExpectAnyArgs();
    mcp3221 = MCP3221_Open(0xa5a5, MyMCP3221_Callback);
}

void tearDown(void)
{
    DRV_I2C_Close_ExpectAnyArgs();
    MCP3221_Close(mcp3221);
}

void test_MCP3221_Create_Should_CreateAnInstanceOfMCP3221(void)
{
    TEST_IGNORE_MESSAGE("Ignore MCP3221_Create test after confirming functionality");
    DRV_I2C_Open_ExpectAndReturn( DRV_I2C_INDEX_0, DRV_IO_INTENT_READWRITE, DRV_HANDLE_INVALID );
    TEST_ASSERT_EQUAL(0, MCP3221_Open(0xa5a5, MyMCP3221_Callback));    //expect failure when i2c open fails

    DRV_I2C_Open_ExpectAndReturn( DRV_I2C_INDEX_0, DRV_IO_INTENT_READWRITE, 0x12345678 );
    DRV_I2C_TransferEventHandlerSet_ExpectAnyArgs();
    TEST_ASSERT_NOT_EQUAL(0, MCP3221_Open(0xa5a5, MyMCP3221_Callback));
    DRV_I2C_Open_ExpectAndReturn( DRV_I2C_INDEX_0, DRV_IO_INTENT_READWRITE, 0x12345678 );
    DRV_I2C_TransferEventHandlerSet_ExpectAnyArgs();
    TEST_ASSERT_NOT_EQUAL(0, MCP3221_Open(0xa5a5, MyMCP3221_Callback));
    DRV_I2C_Open_ExpectAndReturn( DRV_I2C_INDEX_0, DRV_IO_INTENT_READWRITE, 0x12345678 );
    DRV_I2C_TransferEventHandlerSet_ExpectAnyArgs();
    TEST_ASSERT_NOT_EQUAL(0, MCP3221_Open(0xa5a5, MyMCP3221_Callback));
    DRV_I2C_Open_ExpectAndReturn( DRV_I2C_INDEX_0, DRV_IO_INTENT_READWRITE, 0x12345678 );
    DRV_I2C_TransferEventHandlerSet_ExpectAnyArgs();
    TEST_ASSERT_NOT_EQUAL(0, MCP3221_Open(0xa5a5, MyMCP3221_Callback));
   
    TEST_ASSERT_EQUAL(0, MCP3221_Open(0xa5a5, MyMCP3221_Callback));    //expect failure when trying to create more than 4 MCP3221's
}

void test_MCP3221_Destroy_should_FreeMCP3221Element(void)
{
    TEST_IGNORE_MESSAGE("Ignore MCP3221_Destroy test after confirming functionality");
    DRV_I2C_Open_ExpectAndReturn( DRV_I2C_INDEX_0, DRV_IO_INTENT_READWRITE, 0x12345678 );
    mcp3221Handle myMCP3221 =MCP3221_Open(0xa5a5, MyMCP3221_Callback);
    TEST_ASSERT_NOT_EQUAL(0, myMCP3221);
    TEST_ASSERT_TRUE(MCP3221_IsDeviceActive(myMCP3221));
    DRV_I2C_Close_ExpectAnyArgs();
    MCP3221_Close(myMCP3221);
    TEST_ASSERT_FALSE(MCP3221_IsDeviceActive(myMCP3221));
}

void test_MCP3221_StartConversion_Should_InitiateI2cRead(void)
{

    DRV_I2C_ReadTransferAdd_ExpectAnyArgs();
    TEST_ASSERT_TRUE(MCP3221_ConversionStart(mcp3221));
}

extern void _I2CEventHandler (
    DRV_I2C_TRANSFER_EVENT event,
    DRV_I2C_TRANSFER_HANDLE transferHandle,
    uintptr_t context
);

void test_MCP3221_ConversionStatusGet_Should_ReturnConversionStatus(void)
{
    DRV_I2C_TRANSFER_HANDLE handle;

    _I2CEventHandler( DRV_I2C_TRANSFER_EVENT_PENDING, handle, (uintptr_t)mcp3221);
    TEST_ASSERT_EQUAL(MCP3221_EVENT_CONVERSION_PENDING, MCP3221_ConversionStatusGet(mcp3221));

    _I2CEventHandler( DRV_I2C_TRANSFER_EVENT_COMPLETE, handle, (uintptr_t)mcp3221);
    TEST_ASSERT_EQUAL(MCP3221_EVENT_CONVERSION_COMPLETE, MCP3221_ConversionStatusGet(mcp3221));

    _I2CEventHandler(DRV_I2C_TRANSFER_EVENT_ERROR , handle, (uintptr_t)mcp3221);
    TEST_ASSERT_EQUAL(MCP3221_EVENT_CONVERSION_ERROR, MCP3221_ConversionStatusGet(mcp3221));

    _I2CEventHandler(DRV_I2C_TRANSFER_EVENT_HANDLE_INVALID , handle, (uintptr_t)mcp3221);
    TEST_ASSERT_EQUAL(MCP3221_EVENT_HANDLE_INVALID, MCP3221_ConversionStatusGet(mcp3221));
}


void test_MCP3221_GetResult_Should_ReturnLatestValue(void)
{
    MCP3221_SetBuffer(mcp3221, 0x05, 0x5A);
    
    DRV_I2C_TRANSFER_HANDLE handle;

    _I2CEventHandler( DRV_I2C_TRANSFER_EVENT_COMPLETE, handle, (uintptr_t)mcp3221);

    TEST_ASSERT_EQUAL_HEX16(0x055A, MCP3221_ConversionResultGet(mcp3221));

}



#endif // TEST
