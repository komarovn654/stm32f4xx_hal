#pragma once

#include "hal_rcc_regs.h"
#include "hal_errors.h"

error rcc_reset(RCC_TypeDef* addr);
uint32_t rcc_ahb_prescaler(RCC_TypeDef* addr);