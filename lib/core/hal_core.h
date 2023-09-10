#pragma once

#define hal_assert(func, ...) do { \
        if (ERROR_ASSERT == func(__VA_ARGS__)) return ERROR_ASSERT; \
    } while(0)

#if (defined UTEST_TARGET && UTEST_TARGET==1) || (defined UTEST_HOST && UTEST_HOST==1)
#define utest_static 
#elif
#define utest_static static
#endif

#define SET_BIT(reg, bit)   (reg |= (uint32_t)bit)
#define CLR_BIT(reg, bit)   (reg &= ~(uint32_t)bit)
#define GET_BIT(reg, bit)   (reg & (uint32_t)bit)