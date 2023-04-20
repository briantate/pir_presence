#ifdef TEST

#include "unity.h"

#include "MCP3221.h"
#include "mock_drv_i2c.h"
#include "Defs.h"

#define MAX_MCP3221 (4)
mcp3221Handle mcp3221[MAX_MCP3221] = {0};

void setUp(void)
{
    for(uint8_t i = 0; i<MAX_MCP3221; i++)
    {
       mcp3221[i] = MCP3221_Create(0xa5a5);
    }
}

void tearDown(void)
{
    for(uint8_t i = 0; i<MAX_MCP3221; i++)
    {
        MCP3221_Destroy(mcp3221[i]);
    }
}

void test_MCP3221_Create_Should_CreateAnInstanceOfMCP3221_IfAvailable(void)
{
    TEST_IGNORE_MESSAGE("Ignore MCP3221_Create test after confirming functionality");
    TEST_ASSERT_NOT_EQUAL(0, MCP3221_Create(0xa5a5));
    TEST_ASSERT_NOT_EQUAL(0, MCP3221_Create(0xa5a5));
    TEST_ASSERT_NOT_EQUAL(0, MCP3221_Create(0xa5a5));
    TEST_ASSERT_NOT_EQUAL(0, MCP3221_Create(0xa5a5));
    TEST_ASSERT_EQUAL(0, MCP3221_Create(0xa5a5));    //expect failure when trying to create more than 4 MCP3221's
}

void test_MCP3221_Destroy_should_FreeMCP3221Element(void)
{
    TEST_IGNORE_MESSAGE("Ignore MCP3221_Destroy test after confirming functionality");
    mcp3221Handle myMCP3221 = MCP3221_Create(0x5678);
    TEST_ASSERT_NOT_EQUAL(0, myMCP3221);
    TEST_ASSERT_TRUE(MCP3221_IsActive(myMCP3221));
    MCP3221_Destroy(myMCP3221);
    TEST_ASSERT_FALSE(MCP3221_IsActive(myMCP3221));
}

void test_MCP3221_BusInit_Should_InitI2CBusAndReturnStatus(void)
{
    DRV_I2C_Open_ExpectAndReturn( DRV_I2C_INDEX_0, DRV_IO_INTENT_READWRITE, DRV_HANDLE_INVALID );
    TEST_ASSERT_EQUAL(STATUS_UNKNOWN_ERR, MCP3221_BusInit());

    DRV_I2C_Open_ExpectAndReturn( DRV_I2C_INDEX_0, DRV_IO_INTENT_READWRITE, 0x12345678 );
    TEST_ASSERT_EQUAL(STATUS_OK, MCP3221_BusInit());
}


#endif // TEST
