#ifndef PIR_CLICK_H
#define PIR_CLICK_H

#include "Defs.h"
#include <stdbool.h>

typedef enum
{
    PIR_EVENT_CONVERSION_PENDING = 0,
    PIR_EVENT_BEING_DETECTED = 1,
    PIR_EVENT_CONVERSION_ERROR = -1,
    PIR_EVENT_HANDLE_INVALID = -2,
}PIR_EVENT;

typedef struct PIR* pirHandle;
typedef void (*PIR_Callback_t)(PIR_EVENT event);

pirHandle PIR_Open(uint16_t address, PIR_Callback_t cb);
void PIR_Close(pirHandle pir);
bool PIR_IsDeviceActive(pirHandle pir);
bool PIR_IsPresenceDetected(pirHandle pir);

#endif // PIR_CLICK_H
