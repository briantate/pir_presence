#ifdef TEST

#include "unity.h"

#include "PIR_CLICK.h"
#include "mock_ANLG_Adapter.h"

void setUp(void)
{
}

void tearDown(void)
{
}

void test_PIR_CLICK_Init_Should_InitializeSubmodules(void)
{
    ANLG_Init_ExpectAndReturn(true);
    TEST_ASSERT_TRUE(PIR_Init());
}

void test_PIR_CLICK_IsPresent_Should_ReturnTrueWhenVoltageThresholdExceeded(void)
{
    ANLG_ConversionResultGet_ExpectAndReturn(0);
    TEST_ASSERT_FALSE(PIR_IsPresent());
    
    ANLG_ConversionResultGet_ExpectAndReturn(1000);
    TEST_ASSERT_FALSE(PIR_IsPresent());

    ANLG_ConversionResultGet_ExpectAndReturn(2500);
    TEST_ASSERT_TRUE(PIR_IsPresent());
    
    ANLG_ConversionResultGet_ExpectAndReturn(4095);
    TEST_ASSERT_TRUE(PIR_IsPresent());
    
    ANLG_ConversionResultGet_ExpectAndReturn(4095);
    TEST_ASSERT_TRUE(PIR_IsPresent());


}

#endif // TEST
