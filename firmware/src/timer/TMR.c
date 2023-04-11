#include "TMR.h"
// #include "system/time/sys_time.h"

static bool isTmrExpired = false;
// static SYS_TIME_HANDLE tmrHandle;

static void _Timer_Callback ( uintptr_t context )
{
    isTmrExpired = true;

}

void TMR_Init(uint32_t timeoutMs)
{
    //  tmrHandle = SYS_TIME_CallbackRegisterMS(_Timer_Callback, 0, timeoutMs, SYS_TIME_PERIODIC);
}

void TMR_Start(void)
{

}

void TMR_Stop(void)
{

}

bool TMR_IsExpired(void)
{
    bool ret = isTmrExpired;
    isTmrExpired = false;
    return ret;

}