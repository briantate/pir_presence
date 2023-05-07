#ifdef TEST

#include "unity.h"

#include "ANLG_Adapter.h"
#include "mock_plib_adc0.h"
TEST_FILE("ANLG_Adapter_ADC0.c")

extern bool isConversionComplete;
extern uint16_t analogValue;

void setUp(void)
{
}

void tearDown(void)
{
}

void test_ANLG_Adapter_Init_and_DeInit_Should_EnableDisableADC0(void)
{
    ADC0_Enable_Expect();
    TEST_ASSERT_TRUE(ANLG_Init());

    ADC0_Disable_Expect();
    ANLG_DeInit();
}

void test_ANLG_ConversionResultGet_Should_StartConversionWhenNeeded_And_ReturnLastResult(void)
{
    isConversionComplete = false;
    TEST_ASSERT_EQUAL(0, ANLG_ConversionResultGet());

    isConversionComplete = true;
    ADC0_ConversionStart_Expect();
    ADC0_ConversionStatusGet_ExpectAndReturn(true);
    ADC0_ConversionResultGet_ExpectAndReturn(analogValue);
    TEST_ASSERT_EQUAL(0, ANLG_ConversionResultGet());

    analogValue = 0xFF;
    isConversionComplete = true;
    ADC0_ConversionStart_Expect();
    ADC0_ConversionStatusGet_ExpectAndReturn(true);
    ADC0_ConversionResultGet_ExpectAndReturn(analogValue);
    TEST_ASSERT_EQUAL(analogValue, ANLG_ConversionResultGet());
}

#endif // TEST
