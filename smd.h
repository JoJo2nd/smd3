
#include "smdconfig.h"

// utils header?

#ifdef SMD_PLATFORM_WINDOWS
#include <intrin.h>

uint32_t __inline smd_ctz32(uint32_t value)
{
    unsigned long trailing_zero = 0;

    if (_BitScanForward(&trailing_zero, value))
    {
        return trailing_zero;
    }
    else
    {
        // This is undefined, I better choose 32 than 0
        return 32;
    }
}

uint32_t __inline smd_clz32(uint32_t value)
{
    unsigned long leading_zero = 0;

    if (_BitScanReverse(&leading_zero, value))
    {
        return 31 - leading_zero;
    }
    else
    {
        // Same remarks as above
        return 32;
    }
}

uint32_t __inline smd_ctz64(uint64_t value)
{
    unsigned long trailing_zero = 0;

    if (_BitScanForward64(&trailing_zero, value))
    {
        return trailing_zero;
    }
    else
    {
        // This is undefined
        return 64;
    }
}

uint32_t __inline smd_clz64(uint64_t value)
{
    unsigned long leading_zero = 0;

    if (_BitScanReverse64(&leading_zero, value))
    {
        return 63 - leading_zero;
    }
    else
    {
        // Same remarks as above
        return 64;
    }
}
#endif

#define smd_make_fourCC(a,b,c,d) (uint32_t)( (((uint32_t)d&0xFF) << 24) | (((uint32_t)c&0xFF) << 16) | (((uint32_t)b&0xFF) << 8) | (((uint32_t)a&0xFF)))

//

#include "debug.h"
#include "unicode.h"
#include "getopt.h"
#include "minfs.h"
#include "sock.h"
#include "thread.h"
#include "smd_proc.h"
// todo: cross platform fiber support