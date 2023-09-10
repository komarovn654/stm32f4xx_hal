#pragma once

#include "stdio.h"

#define RCC_SYSCLK_MAX      (180000000)
#define RCC_PLLCLK_DEFAULT  (96000000)
#define RCC_SYSCLK_DEFAULT  (16000000)
#define RCC_HCLK_DEFAULT    (16000000)
#define RCC_FCLK_DEFAULT    (16000000)
#define RCC_SYSTICK_DEFAULT (16000000) 

typedef struct clocks {
    uint32_t sysclk;
    uint32_t hclk;
    uint32_t fclk;
    uint32_t systick;
} clocks;

void rcc_clocks_set_default(void);
clocks* rcc_clocks_get(void);
void rcc_clocks_update(void);