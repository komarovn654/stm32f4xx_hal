#pragma once

#include "stdint.h"

typedef struct FLASH_TypeDef
{
    uint32_t ACR;
    uint32_t KEYR;
    uint32_t OPTKEYR;
    uint32_t SR;
    uint32_t CR;
    uint32_t OPTCR;
} FLASH_TypeDef;

#define FLASH_BASE 0x40023C00

#define FLASH ((FLASH_TypeDef *) FLASH_BASE)

/* Flash access control register (FLASH_ACR) */
#define FLASH_ACR_DEFAULT       (0x00000000)

#define FLASH_ACR_LATENCY_POS   (0x00)
#define FLASH_ACR_LATENCY_MSK   (0x07 << FLASH_ACR_LATENCY_POS)
#define FLASH_ACR_PRFTEN_POS    (0x08)
#define FLASH_ACR_PRFTEN_MSK    (0x01 << FLASH_ACR_PRFTEN_POS)
#define FLASH_ACR_ICEN_POS      (0x09)
#define FLASH_ACR_ICEN_MSK      (0x01 << FLASH_ACR_ICEN_POS)
#define FLASH_ACR_DCEN_POS      (0x0A)
#define FLASH_ACR_DCEN_MSK      (0x01 << FLASH_ACR_DCEN_POS)
#define FLASH_ACR_ICRST_POS     (0x0B)
#define FLASH_ACR_ICRST_MSK     (0x01 << FLASH_ACR_ICRST_POS)
#define FLASH_ACR_DCRST_POS     (0x0C)
#define FLASH_ACR_DCRST_MSK     (0x01 << FLASH_ACR_DCRST_POS)

/* Flash key register (FLASH_KEYR) */
#define FLASH_KEYR_DEFAULT      (0x00000000)

#define FLASH_KEYR_POS          (0x00)
#define FLASH_KEYR_MSK          (0xFFFFFFFF << FLASH_KEYR_POS)

/* Flash option key register (FLASH_OPTKEYR) */
#define FLASH_OPTKEYR_DEFAULT   (0x00000000)

#define FLASH_OPTKEYR_POS       (0x00)
#define FLASH_OPTKEYR_MSK       (0xFFFFFFFF << FLASH_OPTKEYR_POS)

/* Flash status register (FLASH_SR) */
#define FLASH_SR_DEFAULT        (0x00000000)

#define FLASH_SR_EOP_POS        (0x00)
#define FLASH_SR_EOP_MSK        (0x01 << FLASH_SR_EOP_POS)
#define FLASH_SR_OPERR_POS      (0x01)
#define FLASH_SR_OPERR_MSK      (0x01 << FLASH_SR_OPERR_POS)
#define FLASH_SR_WRPERR_POS     (0x04)
#define FLASH_SR_WRPERR_MSK     (0x01 << FLASH_SR_WRPERR_POS)
#define FLASH_SR_PGAERR_POS     (0x05)
#define FLASH_SR_PGAERR_MSK     (0x01 << FLASH_SR_PGAERR_POS)
#define FLASH_SR_PGPERR_POS     (0x06)
#define FLASH_SR_PGPERR_MSK     (0x01 << FLASH_SR_PGPERR_POS)
#define FLASH_SR_PGSERR_POS     (0x07)
#define FLASH_SR_PGSERR_MSK     (0x01 << FLASH_SR_PGSERR_POS)
#define FLASH_SR_BSY_POS        (0x10)
#define FLASH_SR_BSY_MSK        (0x01 << FLASH_SR_BSY_POS)

/* Flash control register (FLASH_CR) */
#define FLASH_CR_DEFAULT        (0x80000000)

#define FLASH_CR_PG_POS         (0x00)
#define FLASH_CR_PG_MSK         (0x01 << FLASH_CR_PG_POS)
#define FLASH_CR_SER_POS        (0x01)
#define FLASH_CR_SER_MSK        (0x01 << FLASH_CR_SER_POS)
#define FLASH_CR_MER_POS        (0x02)
#define FLASH_CR_MER_MSK        (0x01 << FLASH_CR_MER_POS)
#define FLASH_CR_SNB_POS        (0x03)
#define FLASH_CR_SNB_MSK        (0x0F << FLASH_CR_SNB_POS)
#define FLASH_CR_PSIZE_POS      (0x08)
#define FLASH_CR_PSIZE_MSK      (0x03 << FLASH_CR_PSIZE_POS)
#define FLASH_CR_STRT_POS       (0x0F)
#define FLASH_CR_STRT_MSK       (0x01 << FLASH_CR_STRT_POS)
#define FLASH_CR_EOPIE_POS      (0x18)
#define FLASH_CR_EOPIE_MSK      (0x01 << FLASH_CR_EOPIE_POS)
#define FLASH_CR_ERRIE_POS      (0x19)
#define FLASH_CR_ERRIE_MSK      (0x01 << FLASH_CR_ERRIE_POS)
#define FLASH_CR_LOCK_POS       (0x1F)
#define FLASH_CR_LOCK_MSK       (0x01 << FLASH_CR_LOCK_POS)

/* Flash option control register (FLASH_OPTCR) */
#define FLASH_OPTCR_DEFAULT     ( 0x0FFFAAED)

#define FLASH_OPTCR_OPTLOCK_POS (0x00)
#define FLASH_OPTCR_OPTLOCK_MSK (0x01 << FLASH_OPTCR_OPTLOCK_POS)
#define FLASH_OPTCR_OPTSTRT_POS (0x01)
#define FLASH_OPTCR_OPTSTRT_MSK (0x01 << FLASH_OPTCR_OPTSTRT_POS)
#define FLASH_OPTCR_BOR_LEV_POS (0x02)
#define FLASH_OPTCR_BOR_LEV_MSK (0x03 << FLASH_OPTCR_BOR_LEV_POS)
#define FLASH_OPTCR_USER_POS    (0x05)
#define FLASH_OPTCR_USER_MSK    (0x07 << FLASH_OPTCR_USER_POS)
#define FLASH_OPTCR_RDP_POS     (0x08)
#define FLASH_OPTCR_RDP_MSK     (0xFF << FLASH_OPTCR_RDP_POS)
#define FLASH_OPTCR_NWRP_POS    (0x10)
#define FLASH_OPTCR_NWRP_MSK    (0xFFF << FLASH_OPTCR_NWRP_POS)
