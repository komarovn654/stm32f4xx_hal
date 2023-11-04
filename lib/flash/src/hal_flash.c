#include "hal_core.h"
#include "hal_flash_regs.h"

utest_static flash_setup_cache(FLASH_TypeDef* addr)
{
    
}

void flash_setup_required(FLASH_TypeDef* addr)
{
    CLR_BIT(addr->ACR, FLASH_ACR_LATENCY_MSK);
    SET_BIT(addr->ACR, FLASH_LATENCY_REQUIRED << FLASH_ACR_LATENCY_POS);
}
