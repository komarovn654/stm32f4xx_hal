#pragma once

#define hal_assert(func, ...) do { \
        if (ERROR_ASSERT == func(__VA_ARGS__)) return ERROR_ASSERT; \
    } while(0)

#if (defined UTEST_TARGET && UTEST_TARGET==1) || (defined UTEST_HOST && UTEST_HOST==1)
#define utest_static

#define WAIT_TICKS(EVENT, TIMEOUT)
#define WAIT_TICKS_RET_ERR(EVENT, TIMEOUT, ERROR) 
#elif
#define utest_static static

#define WAIT_TICKS(EVENT, TIMEOUT) do { \
    while ((!(EVENT)) && (TIMEOUT > 0)) { \
        TIMEOUT--; \
    } \
} while(0)

#define WAIT_TICKS_RET_ERR(EVENT, TIMEOUT, ERROR) do { \
    volatile uint32_t timeout = TIMEOUT; \
    while ((!(EVENT)) && (timeout > 0)) { \
        timeout--; \
    } \
    if (timeout <= 0) { \
        return ERROR; \
    } \
} while(0)
#endif

#define SET_BIT(REG, BIT)   (REG |= (uint32_t)BIT)
#define CLR_BIT(REG, BIT)   (REG &= ~(uint32_t)BIT)
#define GET_BIT(REG, BIT)   (REG & (uint32_t)BIT)
#define GET_BIT_VAL(REG, BIT, POS) (GET_BIT(REG, BIT) >> POS)