#pragma once

#include "stdint.h"

typedef struct RCC_TypeDef
{
    uint32_t CR;
    uint32_t PLLCFGR;
    uint32_t CFGR;
    uint32_t CIR;
    uint32_t AHB1RSTR;
    uint32_t AHB2RSTR;
    uint32_t AHB3RSTR;
    uint32_t reserved1;
    uint32_t APB1RSTR;
    uint32_t APB2RSTR;
    uint32_t reserved2;
    uint32_t reserved3;
    uint32_t AHB1ENR;
    uint32_t AHB2ENR;
    uint32_t AHB3ENR;
    uint32_t reserved4;
    uint32_t APB1ENR;
    uint32_t APB2ENR;
    uint32_t reserved5;
    uint32_t reserved6;
    uint32_t AHB1LPENR;
    uint32_t AHB2LPENR;
    uint32_t AHB3LPENR;
    uint32_t reserved7;
    uint32_t APB1LPENR;
    uint32_t APB2LPENR;
    uint32_t reserved8;
    uint32_t reserved9;
    uint32_t BDCR;
    uint32_t reserved10;
    uint32_t reserved11;
    uint32_t SSCGR;
    uint32_t PLLI2SCFGR;
    uint32_t PLLSAICFGR;
    uint32_t DCKCFGR;
} RCC_TypeDef;

#define RCC_BASE 0x40023800

#define RCC ((RCC_TypeDef *) RCC_BASE)

/* RCC clock control register (RCC_CR) */
#define RCC_CR_DEFAULT          (0x00000083)

#define RCC_CR_HSION_POS        (0x00)
#define RCC_CR_HSION_MSK        (0x01 << RCC_CR_HSION_POS)
#define RCC_CR_HSIRDY_POS       (0x01)
#define RCC_CR_HSIRDY_MSK       (0x01 << RCC_CR_HSIRDY_POS)
#define RCC_CR_HSITRIM_POS      (0x03)
#define RCC_CR_HSITRIM_MSK      (0x1F << RCC_CR_HSITRIM_POS)
#define RCC_CR_HSICAL_POS       (0x08)
#define RCC_CR_HSICAL_MSK       (0xFF << RCC_CR_HSICAL_POS)
#define RCC_CR_HSEON_POS        (0x10)
#define RCC_CR_HSEON_MSK        (0x1 << RCC_CR_HSEON_POS)
#define RCC_CR_HSERDY_POS       (0x11)
#define RCC_CR_HSERDY_MSK       (0x01 << RCC_CR_HSERDY_POS)
#define RCC_CR_HSEBYP_POS       (0x12)
#define RCC_CR_HSEBYP_MSK       (0x01 << RCC_CR_HSEBYP_POS)
#define RCC_CR_CSSON_POS        (0x13)
#define RCC_CR_CSSON_MSK        (0x01 << RCC_CR_CSSON_POS)
#define RCC_CR_PLLON_POS        (0x18)
#define RCC_CR_PLLON_MSK        (0x01 << RCC_CR_PLLON_POS)
#define RCC_CR_PLLRDY_POS       (0x19)
#define RCC_CR_PLLRDY_MSK       (0x01 << RCC_CR_PLLRDY_POS)
#define RCC_CR_PLLI2SON_POS     (0x1A)
#define RCC_CR_PLLI2SON_MSK     (0x01 << RCC_CR_PLLI2SON_POS)
#define RCC_CR_PLLI2SRDY_POS    (0x1B)
#define RCC_CR_PLLI2SRDY_MSK    (0x01 << RCC_CR_PLLI2SRDY_POS)

#define RCC_CR_HSI_ON           (0x01)

/* RCC PLL configuration register (RCC_PLLCFGR) */
#define RCC_PLLCFGR_DEFAULT (0x24003010)

#define RCC_PLLCFGR_PLLM_POS    (0x00)
#define RCC_PLLCFGR_PLLM_MSK    (0x3F << RCC_PLLCFGR_PLLM_POS)
#define RCC_PLLCFGR_PLLN_POS    (0x06)
#define RCC_PLLCFGR_PLLN_MSK    (0x3FF << RCC_PLLCFGR_PLLN_POS)
#define RCC_PLLCFGR_PLLP_POS    (0x10)
#define RCC_PLLCFGR_PLLP_MSK    (0x03 << RCC_PLLCFGR_PLLP_POS)
#define RCC_PLLCFGR_PLLSRC_POS  (0x16)
#define RCC_PLLCFGR_PLLSRC_MSK  (0x01 << RCC_PLLCFGR_PLLSRC_POS)
#define RCC_PLLCFGR_PLLQ_POS    (0x18)
#define RCC_PLLCFGR_PLLQ_MSK    (0x0F << RCC_PLLCFGR_PLLQ_POS)

#define PLL_SOURCE_HSE (1)
#define PLL_SOURCE_HSI (0)

#define PLL_PLLCFGR_P(REG_VALUE) PLL_PLLCFGR_P ## REG_VALUE
#define PLL_PLLCFGR_P0 (2)
#define PLL_PLLCFGR_P1 (4)
#define PLL_PLLCFGR_P2 (6)
#define PLL_PLLCFGR_P3 (8)

/* RCC clock configuration register (RCC_CFGR) */
#define RCC_CFGR_DEFAULT (0x00000000U)

#define RCC_CFGR_SW_POS         (0x00)
#define RCC_CFGR_SW_MSK         (0x03 << RCC_CFGR_SW_POS)
#define RCC_CFGR_SWS_POS        (0x02)
#define RCC_CFGR_SWS_MSK        (0x03 << RCC_CFGR_SWS_POS)
#define RCC_CFGR_HPRE_POS       (0x04)
#define RCC_CFGR_HPRE_MSK       (0x0F << RCC_CFGR_HPRE_POS)
#define RCC_CFGR_PPRE1_POS      (0x0A)
#define RCC_CFGR_PPRE1_MSK      (0x07 << RCC_CFGR_PPRE1_POS)
#define RCC_CFGR_PPRE2_POS      (0x0D)
#define RCC_CFGR_PPRE2_MSK      (0x07 << RCC_CFGR_PPRE2_POS)
#define RCC_CFGR_RTCPRE_POS     (0x10)
#define RCC_CFGR_RTCPRE_MSK     (0x1F << RCC_CFGR_RTCPRE_POS)
#define RCC_CFGR_MCO1_POS       (0x15)
#define RCC_CFGR_MCO1_MSK       (0x03 << RCC_CFGR_MCO1_POS)
#define RCC_CFGR_I2SSRC_POS     (0x17)
#define RCC_CFGR_I2SSRC_MSK     (0x01 << RCC_CFGR_I2SSRC_POS)
#define RCC_CFGR_MCO1PRE_POS    (0x18)
#define RCC_CFGR_MCO1PRE_MSK    (0x07 << RCC_CFGR_MCO1PRE_POS)
#define RCC_CFGR_MCO2PRE_POS    (0x1B)
#define RCC_CFGR_MCO2PRE_MSK    (0x07 << RCC_CFGR_MCO2PRE_POS)
#define RCC_CFGR_MCO2_POS       (0x1E)
#define RCC_CFGR_MCO2_MSK       (0x03 << RCC_CFGR_MCO2_POS)

#define SW_SRC_HSI              (0x00)
#define SW_SRC_HSE              (0x01)
#define SW_SRC_PLL              (0x02)

#define SWS_ACT_HSI             (0x00)
#define SWS_ACT_HSE             (0x01)
#define SWS_ACT_PLL             (0x02)

#define MCO1_SRC_HSI            (0x00)
#define MCO1_SRC_LSE            (0x01)
#define MCO1_SRC_HSE            (0x02)
#define MCO1_SRC_PLL            (0x03)

#define MCO1_DIV2               (0x04)
#define MCO1_DIV3               (0x05)
#define MCO1_DIV4               (0x06)
#define MCO1_DIV5               (0x07)

#define MCO2_SRC_SYSCLK         (0x00)
#define MCO2_SRC_PLLI2S         (0x01)
#define MCO2_SRC_HSE            (0x02)
#define MCO2_SRC_PLL            (0x03)

#define MCO2_DIV2               (0x04)
#define MCO2_DIV3               (0x05)
#define MCO2_DIV4               (0x06)
#define MCO2_DIV5               (0x07)

/* RCC clock interrupt register (RCC_CIR) */
#define RCC_CIR_DEFAULT (0x00000000U)

#define RCC_CIR
#define RCC_CIR
#define RCC_CIR
#define RCC_CIR
#define RCC_CIR


/* RCC APB2 peripheral clock enable register (RCC_APB2ENR) */
#define RCC_APB2ENR_TIM1EN_POS      (0x00)
#define RCC_APB2ENR_TIM1EN_MSK      (0x01 << RCC_APB2ENR_TIM1EN_POS)
#define RCC_APB2ENR_TIM8EN_POS      (0x01)
#define RCC_APB2ENR_TIM8EN_MSK      (0x01 << RCC_APB2ENR_TIM8EN_POS)
#define RCC_APB2ENR_USART1EN_POS    (0x04)
#define RCC_APB2ENR_USART1EN_MSK    (0x01 << RCC_APB2ENR_USART1EN_POS)
#define RCC_APB2ENR_USART6EN_POS    (0x05)
#define RCC_APB2ENR_USART6EN_MSK    (0x01 << RCC_APB2ENR_USART6EN_POS)
#define RCC_APB2ENR_ADC1EN_POS      (0x08)
#define RCC_APB2ENR_ADC1EN_MSK      (0x01 << RCC_APB2ENR_ADC1EN_POS)
#define RCC_APB2ENR_ADC2EN_POS      (0x09)
#define RCC_APB2ENR_ADC2EN_MSK      (0x01 << RCC_APB2ENR_ADC2EN_POS)
#define RCC_APB2ENR_ADC3EN_POS      (0x0A)
#define RCC_APB2ENR_ADC3EN_MSK      (0x01 << RCC_APB2ENR_ADC3EN_POS)
#define RCC_APB2ENR_SDIOEN_POS      (0x0B)
#define RCC_APB2ENR_SDIOEN_MSK      (0x01 << RCC_APB2ENR_SDIOEN_POS)
#define RCC_APB2ENR_SPI1EN_POS      (0x0C)
#define RCC_APB2ENR_SPI1EN_MSK      (0x01 << RCC_APB2ENR_SPI1EN_POS)
#define RCC_APB2ENR_SPI4EN_POS      (0x0D)
#define RCC_APB2ENR_SPI4EN_MSK      (0x01 << RCC_APB2ENR_SPI4EN_POS)
#define RCC_APB2ENR_SYSCFGEN_POS    (0x0E)
#define RCC_APB2ENR_SYSCFGEN_MSK    (0x01 << RCC_APB2ENR_SYSCFGEN_POS)
#define RCC_APB2ENR_TIM9EN_POS      (0x10)
#define RCC_APB2ENR_TIM9EN_MSK      (0x01 << RCC_APB2ENR_TIM9EN_POS)
#define RCC_APB2ENR_TIM10EN_POS     (0x11)
#define RCC_APB2ENR_TIM10EN_MSK     (0x01 << RCC_APB2ENR_TIM10EN_POS)
#define RCC_APB2ENR_TIM11EN_POS     (0x12)
#define RCC_APB2ENR_TIM11EN_MSK     (0x01 << RCC_APB2ENR_TIM11EN_POS)
#define RCC_APB2ENR_SPI5EN_POS      (0x14)
#define RCC_APB2ENR_SPI5EN_MSK      (0x01 << RCC_APB2ENR_SPI5EN_POS)
#define RCC_APB2ENR_SPI6EN_POS      (0x15)
#define RCC_APB2ENR_SPI6EN_MSK      (0x01 << RCC_APB2ENR_SPI6EN_POS)
#define RCC_APB2ENR_SAI1EN_POS      (0x16)
#define RCC_APB2ENR_SAI1EN_MSK      (0x01 << RCC_APB2ENR_SAI1EN_POS)
#define RCC_APB2ENR_LTDCEN_POS      (0x1A)
#define RCC_APB2ENR_LTDCEN_MSK      (0x01 << RCC_APB2ENR_LTDCEN_POS)
