#pragma once

#define hal_assert(func, ...) do { \
        if (ERROR_ASSERT == func(__VA_ARGS__)) return ERROR_ASSERT; \
    } while(0)

#define SET_BIT(reg, bit)   (reg |= (uint32_t)bit)
#define CLR_BIT(reg, bit)   (reg &= ~(uint32_t)bit)
#define GET_BIT(reg, bit)   (reg & (uint32_t)bit)