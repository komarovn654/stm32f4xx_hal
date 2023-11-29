#include "hal_core.h"
#include "hal_flash_regs.h"

utest_static void _flash_setup_required(FLASH_TypeDef* addr)
{
    addr->ACR = FLASH_ACR_DEFAULT;

    SET_BIT(addr->ACR, /*FLASH_LATENCY_REQUIRED*/5 << FLASH_ACR_LATENCY_POS);
    SET_BIT(addr->ACR, 1 << FLASH_ACR_PRFTEN_POS | 1 << FLASH_ACR_DCEN_POS | 1 << FLASH_ACR_ICEN_POS);
}

void flash_setup_required(void)
{
    _flash_setup_required(FLASH);
}
