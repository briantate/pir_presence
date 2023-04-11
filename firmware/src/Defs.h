#ifndef DEFS_H
#define DEFS_H

#include <stdint.h>

#define VERSION_MAJOR        (0)
#define VERSION_MINOR        (1)

/* Test overrides*/
#ifdef TEST
#define STATIC
#define INLINE
#else
#define STATIC               static
#define INLINE               inline
#endif


typedef enum _status_t
{
    STATUS_OK = 0,
    STATUS_NONE_YET,
    STATUS_UNKNOWN_ERR,
} STATUS_T;




#endif //DEFS_H
