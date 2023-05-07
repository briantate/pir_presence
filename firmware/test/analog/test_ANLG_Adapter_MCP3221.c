#ifdef TEST

#include "unity.h"

#include "ANLG_Adapter.h"
#include "mock_MCP3221.h"
TEST_FILE("ANLG_Adapter_MCP3221.c")

mcp3221Handle myMCP3221;

extern mcp3221Handle mcp3221; //from the implementation
extern bool isConversionComplete; //from the implementation
extern uint16_t analogValue; //from the implementation

void setUp(void)
{
}

void tearDown(void)
{
}

void test_ANLG_Adapter_Init_and_DeInit_Should_OpenCloseMCP3221(void)
{
    MCP3221_Open_ExpectAnyArgsAndReturn(0);
    TEST_ASSERT_FALSE(ANLG_Init());
    TEST_ASSERT_EQUAL(0, mcp3221);

    myMCP3221 = (mcp3221Handle)0xa5a5a5a5;

    MCP3221_Open_ExpectAnyArgsAndReturn(myMCP3221);
    TEST_ASSERT_TRUE(ANLG_Init());
    TEST_ASSERT_EQUAL(myMCP3221, mcp3221);

    MCP3221_Close_ExpectAnyArgs();
    ANLG_DeInit();
    TEST_ASSERT_EQUAL(0, mcp3221);
}

void test_ANLG_Adapter_ConversionResultGet_Should_StartConversionWhenNeeded_And_ReturnLastResult(void)
{
    isConversionComplete = false;
    TEST_ASSERT_EQUAL(0, ANLG_ConversionResultGet());

    isConversionComplete = true;
    MCP3221_ConversionStart_ExpectAnyArgsAndReturn(true);
    TEST_ASSERT_EQUAL(0, ANLG_ConversionResultGet());

    analogValue = 0xFF;
    isConversionComplete = true;
    MCP3221_ConversionStart_ExpectAnyArgsAndReturn(true);
    TEST_ASSERT_EQUAL(analogValue, ANLG_ConversionResultGet());
}

extern void _MCP3221_Callback(MCP3221_EVENT event);

void test_ANLG_MCP3221_Callback_Should_FlagConversionCompleteAnd_GetAnalogResult(void)
{
    uint16_t testVal = 0xA5;
    isConversionComplete = false;

    MCP3221_ConversionResultGet_ExpectAnyArgsAndReturn(testVal);
    _MCP3221_Callback(MCP3221_EVENT_CONVERSION_COMPLETE);
    TEST_ASSERT_TRUE(isConversionComplete);
    TEST_ASSERT_EQUAL(testVal, analogValue);

}

#endif // TEST
