#pragma once

#define hal_assert(func, ...) do { \
        if (ERROR_ASSERT == func(__VA_ARGS__)) return ERROR_ASSERT; \
    } while(0)

#if (defined UTEST_HOST && UTEST_HOST==1)
    #define WAIT_TICKS(EVENT, TIMEOUT) (void)TIMEOUT
    #define WAIT_TICKS_RET_ERR(EVENT, TIMEOUT, ERROR) (void)TIMEOUT
#else
    #define WAIT_TICKS(EVENT, TIMEOUT) do { \
        volatile uint32_t __timeout = TIMEOUT; \
        while ((!(EVENT)) && (__timeout > 0)) { \
            __timeout--; \
        } \
    } while(0)

    #define WAIT_TICKS_RET_ERR(EVENT, TIMEOUT, ERROR) do { \
        volatile int32_t __timeout = TIMEOUT; \
        while ((!(EVENT)) && (__timeout > 0)) { \
            __timeout--; \
        } \
        if (__timeout <= 0) { \
            return ERROR; \
        } \
    } while(0)
#endif

#if (defined UTEST_TARGET && UTEST_TARGET==1) || (defined UTEST_HOST && UTEST_HOST==1)
    #define utest_static
#else
    #define utest_static static
#endif

#define SET_BIT(REG, BIT)   (REG |= (uint32_t)BIT)
#define CLR_BIT(REG, BIT)   (REG &= ~(uint32_t)BIT)
#define GET_BIT(REG, BIT)   (REG & (uint32_t)BIT)
#define GET_BIT_VAL(REG, BIT, POS) (GET_BIT(REG, BIT) >> POS)