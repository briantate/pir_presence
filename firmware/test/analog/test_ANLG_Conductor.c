#ifdef TEST

#include "unity.h"

#include "mock_ANLG_Model.h"
#include "mock_ANLG_Hardware.h"
#include "mock_TMR.h"
#include "ANLG_Conductor.h"

void setUp(void)
{
}

void tearDown(void)
{
}

void test_ANLG_Conductor_Init_should_InitAllSubmodules(void)
{
    ANLG_Model_Init_Expect();
    ANLG_Hardware_Init_Expect();
    TMR_Init_Expect(5);
    TMR_Start_Expect();

    ANLG_Conductor_Init();
}

void test_ANLG_Conductor_Run_should_NotUpdateTheModelIfNoChannelIsReady(void)
{
    TMR_IsExpired_ExpectAndReturn(true);
    ANLG_Hardware_IsReady_ExpectAndReturn(0, STATUS_NONE_YET);
    ANLG_Hardware_IsReady_ExpectAndReturn(1, STATUS_NONE_YET);
    ANLG_Hardware_IsReady_ExpectAndReturn(2, STATUS_NONE_YET);
    ANLG_Hardware_IsReady_ExpectAndReturn(3, STATUS_NONE_YET);


    ANLG_Conductor_Run();
}

void test_ANLG_Conductor_Run_should_UpdateTheModelForChannelsWithData(void)
{
    TMR_IsExpired_ExpectAndReturn(true);
    ANLG_Hardware_IsReady_ExpectAndReturn(0, STATUS_OK);
    ANLG_Hardware_ReadChannel_ExpectAndReturn(0, 0x1234);
    ANLG_Model_UpdateData_Expect(0, 0x1234);
    ANLG_Hardware_IsReady_ExpectAndReturn(1, STATUS_NONE_YET);
    ANLG_Hardware_IsReady_ExpectAndReturn(2, STATUS_OK);
    ANLG_Hardware_ReadChannel_ExpectAndReturn(2, 0x5678);
    ANLG_Model_UpdateData_Expect(2, 0x5678);

    ANLG_Hardware_IsReady_ExpectAndReturn(3, STATUS_NONE_YET);

    ANLG_Conductor_Run();
}

void test_ANLG_Conductor_Run_should_NotSampleWhenTmrNotExpired(void)
{

    TMR_IsExpired_ExpectAndReturn(false);
    
    //No other functions expected here
    
    ANLG_Conductor_Run();
}

void test_ANLG_Conductor_Run_should_SampleWhenNotExpired(void)
{

    TMR_IsExpired_ExpectAndReturn(true);
    ANLG_Hardware_IsReady_ExpectAndReturn(0, STATUS_NONE_YET);
    ANLG_Hardware_IsReady_ExpectAndReturn(1, STATUS_NONE_YET);
    ANLG_Hardware_IsReady_ExpectAndReturn(2, STATUS_NONE_YET);
    ANLG_Hardware_IsReady_ExpectAndReturn(3, STATUS_NONE_YET);

    ANLG_Conductor_Run();
}
#endif // TEST
