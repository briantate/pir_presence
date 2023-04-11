#ifdef TEST

#include "unity.h"

#include "ANLG_Model.h"
// #include "mock_filter.h"

void setUp(void)
{
}

void tearDown(void)
{
}

void test_ANLG_Model_GetData_should_returnZeroWhenChannelIsIllegal(void)
{
    TEST_ASSERT_EQUAL_HEX(0, ANLG_Model_GetData(9));
}

void test_ANLG_Model_GetData_should_returnZeroWhenNoValueCapturedYet(void)
{
    ANLG_Model_Init();
    
    TEST_ASSERT_EQUAL_HEX(0, ANLG_Model_GetData(0));
    TEST_ASSERT_EQUAL_HEX(0, ANLG_Model_GetData(NUM_ANALOG_MODEL_CHANNELS -1));
}

void test_ANLG_Model_GetData_should_returnLatestData(void)
{
    ANLG_Model_Init();

    // filter_AddVal_ExpectAndReturn(0x0000, 0x1234, 0x4321);
    ANLG_Model_UpdateData(0, 0x1234);

    TEST_ASSERT_EQUAL_HEX16(0x4321, ANLG_Model_GetData(0));
    TEST_ASSERT_EQUAL_HEX16(0, ANLG_Model_GetData(1));
    TEST_ASSERT_EQUAL_HEX16(0, ANLG_Model_GetData(NUM_ANALOG_MODEL_CHANNELS-1));
}

void test_ANLG_Model_GetData_should_MaintainStaleData(void)
{
    ANLG_Model_Init();

    // filter_AddVal_ExpectAndReturn(0x0000, 0x1234, 0x8675);
    ANLG_Model_UpdateData(0, 0x1234);

    // filter_AddVal_ExpectAndReturn(0x0000, 0x2525, 0x3434);
    ANLG_Model_UpdateData(1, 0x2525);

    TEST_ASSERT_EQUAL_HEX16(0x8675, ANLG_Model_GetData(0));
    TEST_ASSERT_EQUAL_HEX16(0x3434, ANLG_Model_GetData(1));
    TEST_ASSERT_EQUAL_HEX16(0, ANLG_Model_GetData(NUM_ANALOG_MODEL_CHANNELS-1));

    // filter_AddVal_ExpectAndReturn(0x3434, 0x1234, 0x1919);
    ANLG_Model_UpdateData(1, 0x1234);

    // filter_AddVal_ExpectAndReturn(0x0000, 0x1234, 0x6767);
    ANLG_Model_UpdateData(3, 0x1234);

    TEST_ASSERT_EQUAL_HEX16(0x8675, ANLG_Model_GetData(0));
    TEST_ASSERT_EQUAL_HEX16(0x1919, ANLG_Model_GetData(1));
    TEST_ASSERT_EQUAL_HEX16(0x6767, ANLG_Model_GetData(3));
    TEST_ASSERT_EQUAL_HEX16(0, ANLG_Model_GetData(NUM_ANALOG_MODEL_CHANNELS-1));
}

void test_ANLG_Model_UpdatetData_should_DoNothingWhenChannelIsIllegal(void)
{
    
    //first set data to known value
    extern uint16_t analogData[];
    for(uint8_t i=0; i< NUM_ANALOG_MODEL_CHANNELS; i++ )
    {
        analogData[i] = 0x1234;
    }

    ANLG_Model_UpdateData(NUM_ANALOG_MODEL_CHANNELS +1, 0xA5A5);

    for(uint8_t i=0; i< NUM_ANALOG_MODEL_CHANNELS; i++ )
    {
        TEST_ASSERT_EQUAL_HEX(0x1234, ANLG_Model_GetData(i));
    }

}

#endif // TEST
