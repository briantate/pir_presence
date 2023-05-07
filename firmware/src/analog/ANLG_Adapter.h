#ifndef ANLG_ADAPTER_H
#define ANLG_ADAPTER_H

#include "stdbool.h"
#include "stdint.h"

bool ANLG_Init(void);
void ANLG_DeInit(void);
uint16_t ANLG_ConversionResultGet(void);

#endif // ANLG_ADAPTER_H
