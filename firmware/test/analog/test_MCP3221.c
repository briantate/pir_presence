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
    TEST_ASSERT_TRUE(MCP3221_StartConversion(mcp3221));
}

void test_MCP3221_IsConversionReady_Should_ReturnTrueIfReady(void){TEST_IGNORE_MESSAGE("Need to implement");}
void test_MCP3221_GetResult_Should_ReturnLatestValue(void){TEST_IGNORE_MESSAGE("Need to implement");}

#endif // TEST
