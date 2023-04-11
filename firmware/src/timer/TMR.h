//A Wrapper for a periodic hardware timer

#ifndef TMR_H
#define TMR_H

#include <stdbool.h>
#include <stdint.h>

void TMR_Init(uint32_t timeoutMs);
void TMR_Start(void);
void TMR_Stop(void);
bool TMR_IsExpired(void);

#endif // TMR_H
