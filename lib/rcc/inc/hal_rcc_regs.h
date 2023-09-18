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

#define RCC_CIR_LSIRDYF_POS     (0x00)
#define RCC_CIR_LSIRDYF_MSK     (0x01 << RCC_CIR_LSIRDYF_POS)
#define RCC_CIR_LSERDYF_POS     (0x01)
#define RCC_CIR_LSERDYF_MSK     (0x01 << RCC_CIR_LSERDYF_POS)
#define RCC_CIR_HSIRDYF_POS     (0x02)
#define RCC_CIR_HSIRDYF_MSK     (0x01 << RCC_CIR_HSIRDYF_POS)
#define RCC_CIR_HSERDYF_POS     (0x03)
#define RCC_CIR_HSERDYF_MSK     (0x01 << RCC_CIR_HSERDYF_POS)
#define RCC_CIR_PLLRDYF_POS     (0x04)
#define RCC_CIR_PLLRDYF_MSK     (0x01 << RCC_CIR_PLLRDYF_POS)
#define RCC_CIR_PLLI2SRDYF_POS  (0x05)
#define RCC_CIR_PLLI2SRDYF_MSK  (0x01 << RCC_CIR_PLLI2SRDYF_POS)
#define RCC_CIR_PLLSAIRDYF_POS  (0x06)
#define RCC_CIR_PLLSAIRDYF_MSK  (0x01 << RCC_CIR_PLLSAIRDYF_POS)
#define RCC_CIR_CSSF_POS        (0x07)
#define RCC_CIR_CSSF_MSK        (0x01 << RCC_CIR_CSSF_POS)
#define RCC_CIR_LSIRDYIE_POS    (0x08)
#define RCC_CIR_LSIRDYIE_MSK    (0x01 << RCC_CIR_LSIRDYIE_POS)
#define RCC_CIR_LSERDYIE_POS    (0x09)
#define RCC_CIR_LSERDYIE_MSK    (0x01 << RCC_CIR_LSERDYIE_POS)
#define RCC_CIR_HSIRDYIE_POS    (0x0A)
#define RCC_CIR_HSIRDYIE_MSK    (0x01 << RCC_CIR_HSIRDYIE_POS)
#define RCC_CIR_HSERDYIE_POS    (0x0B)
#define RCC_CIR_HSERDYIE_MSK    (0x01 << RCC_CIR_HSERDYIE_POS)
#define RCC_CIR_PLLRDYIE_POS    (0x0C)
#define RCC_CIR_PLLRDYIE_MSK    (0x01 << RCC_CIR_PLLRDYIE_POS)
#define RCC_CIR_PLLI2SRDYIE_POS (0x0D)
#define RCC_CIR_PLLI2SRDYIE_MSK (0x01 << RCC_CIR_PLLI2SRDYIE_POS)
#define RCC_CIR_PLLSAIRDYIE_POS (0x0E)
#define RCC_CIR_PLLSAIRDYIE_MSK (0x01 << RCC_CIR_PLLSAIRDYIE_POS)
#define RCC_CIR_LSIRDYC_POS     (0x10)
#define RCC_CIR_LSIRDYC_MSK     (0x01 << RCC_CIR_LSIRDYC_POS)
#define RCC_CIR_LSERDYC_POS     (0x11)
#define RCC_CIR_LSERDYC_MSK     (0x01 << RCC_CIR_LSERDYC_POS)
#define RCC_CIR_HSIRDYC_POS     (0x12)
#define RCC_CIR_HSIRDYC_MSK     (0x01 << RCC_CIR_HSIRDYC_POS)
#define RCC_CIR_HSERDYC_POS     (0x13)
#define RCC_CIR_HSERDYC_MSK     (0x01 << RCC_CIR_HSERDYC_POS)
#define RCC_CIR_PLLRDYC_POS     (0x14)
#define RCC_CIR_PLLRDYC_MSK     (0x01 << RCC_CIR_PLLRDYC_POS)
#define RCC_CIR_PLLI2SRDYC_POS  (0x15)
#define RCC_CIR_PLLI2SRDYC_MSK  (0x01 << RCC_CIR_PLLI2SRDYC_POS)    
#define RCC_CIR_PLLSAIRDYC_POS  (0x16)
#define RCC_CIR_PLLSAIRDYC_MSK  (0x01 << RCC_CIR_PLLSAIRDYC_POS)
#define RCC_CIR_CSSC_POS        (0x17)
#define RCC_CIR_CSSC_MSK        (0x01 << RCC_CIR_CSSC_POS)

/* RCC AHB1 peripheral reset register (RCC_AHB1RSTR) */
#define RCC_AHB1RSTR_DEFAULT (0x00000000U)

#define RCC_AHB1RSTR_GPIOARST_POS   (0x00)
#define RCC_AHB1RSTR_GPIOARST_MSK   (0x01 << RCC_AHB1RSTR_GPIOARST_POS)
#define RCC_AHB1RSTR_GPIOBRST_POS   (0x01)
#define RCC_AHB1RSTR_GPIOBRST_MSK   (0x01 << RCC_AHB1RSTR_GPIOBRST_POS)
#define RCC_AHB1RSTR_GPIOCRST_POS   (0x02)
#define RCC_AHB1RSTR_GPIOCRST_MSK   (0x01 << RCC_AHB1RSTR_GPIOCRST_POS)
#define RCC_AHB1RSTR_GPIODRST_POS   (0x03)
#define RCC_AHB1RSTR_GPIODRST_MSK   (0x01 << RCC_AHB1RSTR_GPIODRST_POS)
#define RCC_AHB1RSTR_GPIOERST_POS   (0x04)
#define RCC_AHB1RSTR_GPIOERST_MSK   (0x01 << RCC_AHB1RSTR_GPIOERST_POS)
#define RCC_AHB1RSTR_GPIOFRST_POS   (0x05)
#define RCC_AHB1RSTR_GPIOFRST_MSK   (0x01 << RCC_AHB1RSTR_GPIOFRST_POS)
#define RCC_AHB1RSTR_GPIOGRST_POS   (0x06)
#define RCC_AHB1RSTR_GPIOGRST_MSK   (0x01 << RCC_AHB1RSTR_GPIOGRST_POS)
#define RCC_AHB1RSTR_GPIOHRST_POS   (0x07)
#define RCC_AHB1RSTR_GPIOHRST_MSK   (0x01 << RCC_AHB1RSTR_GPIOHRST_POS)
#define RCC_AHB1RSTR_GPIOIRST_POS   (0x08)
#define RCC_AHB1RSTR_GPIOIRST_MSK   (0x01 << RCC_AHB1RSTR_GPIOIRST_POS)
#define RCC_AHB1RSTR_GPIOJRST_POS   (0x09)
#define RCC_AHB1RSTR_GPIOJRST_MSK   (0x01 << RCC_AHB1RSTR_GPIOJRST_POS)
#define RCC_AHB1RSTR_GPIOKRST_POS   (0x0A)
#define RCC_AHB1RSTR_GPIOKRST_MSK   (0x01 << RCC_AHB1RSTR_GPIOKRST_POS)
#define RCC_AHB1RSTR_CRCRST_POS     (0x0C)
#define RCC_AHB1RSTR_CRCRST_MSK     (0x01 << RCC_AHB1RSTR_CRCRST_POS)
#define RCC_AHB1RSTR_DMA1RST_POS    (0x15)
#define RCC_AHB1RSTR_DMA1RST_MSK    (0x01 << RCC_AHB1RSTR_DMA1RST_POS)
#define RCC_AHB1RSTR_DMA2RST_POS    (0x16)
#define RCC_AHB1RSTR_DMA2RST_MSK    (0x01 << RCC_AHB1RSTR_DMA2RST_POS)
#define RCC_AHB1RSTR_DMA2DRST_POS   (0x17)
#define RCC_AHB1RSTR_DMA2DRST_MSK   (0x01 << RCC_AHB1RSTR_DMA2DRST_POS)
#define RCC_AHB1RSTR_ETHMACRST_POS  (0x19)
#define RCC_AHB1RSTR_ETHMACRST_MSK  (0x01 << RCC_AHB1RSTR_ETHMACRST_POS)
#define RCC_AHB1RSTR_OTGHSRST_POS   (0x1D)
#define RCC_AHB1RSTR_OTGHSRST_MSK   (0x01 << RCC_AHB1RSTR_OTGHSRST_POS)

/* RCC AHB1 peripheral reset register (RCC_AHB2RSTR) */
#define RCC_AHB2RSTR_DEFAULT (0x00000000U)

#define RCC_AHB2RSTR_DCMIRST_POS    (0x00)
#define RCC_AHB2RSTR_DCMIRST_MSK    (0x01 << RCC_AHB2RSTR_DCMIRST_POS)
#define RCC_AHB2RSTR_CRYPRST_POS    (0x04)
#define RCC_AHB2RSTR_CRYPRST_MSK    (0x01 << RCC_AHB2RSTR_CRYPRST_POS)
#define RCC_AHB2RSTR_HASHRST_POS    (0x05)
#define RCC_AHB2RSTR_HASHRST_MSK    (0x01 << RCC_AHB2RSTR_HASHRST_POS)
#define RCC_AHB2RSTR_RNGRST_POS     (0x06)
#define RCC_AHB2RSTR_RNGRST_MSK     (0x01 << RCC_AHB2RSTR_RNGRST_POS)
#define RCC_AHB2RSTR_OTGFSRST_POS   (0x07)
#define RCC_AHB2RSTR_OTGFSRST_MSK   (0x01 << RCC_AHB2RSTR_OTGFSRST_POS)

/* RCC AHB3 peripheral reset register (RCC_AHB3RSTR) */
#define RCC_AHB3RSTR_DEFAULT (0x00000000U)

#define RCC_AHB3RSTR_FMCRST_POS (0x00)
#define RCC_AHB3RSTR_FMCRST_MSK (0x01 << RCC_AHB3RSTR_FMCRST_POS)

/* RCC APB1 peripheral reset register (RCC_APB1RSTR) */
#define RCC_APB1RSTR_DEFAULT (0x00000000U)

#define RCC_APB1RSTR_TIM2RST_POS    (0x00)
#define RCC_APB1RSTR_TIM2RST_MSK    (0x01 << RCC_APB1RSTR_TIM2RST_POS)
#define RCC_APB1RSTR_TIM3RST_POS    (0x01)
#define RCC_APB1RSTR_TIM3RST_MSK    (0x01 << RCC_APB1RSTR_TIM3RST_POS)
#define RCC_APB1RSTR_TIM4RST_POS    (0x02)
#define RCC_APB1RSTR_TIM4RST_MSK    (0x01 << RCC_APB1RSTR_TIM4RST_POS)
#define RCC_APB1RSTR_TIM5RST_POS    (0x03)
#define RCC_APB1RSTR_TIM5RST_MSK    (0x01 << RCC_APB1RSTR_TIM5RST_POS)
#define RCC_APB1RSTR_TIM6RST_POS    (0x04)
#define RCC_APB1RSTR_TIM6RST_MSK    (0x01 << RCC_APB1RSTR_TIM6RST_POS)
#define RCC_APB1RSTR_TIM7RST_POS    (0x05)
#define RCC_APB1RSTR_TIM7RST_MSK    (0x01 << RCC_APB1RSTR_TIM7RST_POS)
#define RCC_APB1RSTR_TIM12RST_POS   (0x06)
#define RCC_APB1RSTR_TIM12RST_MSK   (0x01 << RCC_APB1RSTR_TIM12RST_POS)
#define RCC_APB1RSTR_TIM13RST_POS   (0x07)
#define RCC_APB1RSTR_TIM13RST_MSK   (0x01 << RCC_APB1RSTR_TIM13RST_POS)
#define RCC_APB1RSTR_TIM14RST_POS   (0x08)
#define RCC_APB1RSTR_TIM14RST_MSK   (0x01 << RCC_APB1RSTR_TIM14RST_POS)
#define RCC_APB1RSTR_WWDGRST_POS    (0x0B)
#define RCC_APB1RSTR_WWDGRST_MSK    (0x01 << RCC_APB1RSTR_WWDGRST_POS)
#define RCC_APB1RSTR_SPI2RST_POS    (0x0E)
#define RCC_APB1RSTR_SPI2RST_MSK    (0x01 << RCC_APB1RSTR_SPI2RST_POS)
#define RCC_APB1RSTR_SPI3RST_POS    (0x0F)
#define RCC_APB1RSTR_SPI3RST_MSK    (0x01 << RCC_APB1RSTR_SPI3RST_POS)
#define RCC_APB1RSTR_USART2RST_POS  (0x11)
#define RCC_APB1RSTR_USART2RST_MSK  (0x01 << RCC_APB1RSTR_USART2RST_POS)
#define RCC_APB1RSTR_USART3RST_POS  (0x12)
#define RCC_APB1RSTR_USART3RST_MSK  (0x01 << RCC_APB1RSTR_USART3RST_POS)
#define RCC_APB1RSTR_UART4RST_POS   (0x13)
#define RCC_APB1RSTR_UART4RST_MSK   (0x01 << RCC_APB1RSTR_UART4RST_POS)
#define RCC_APB1RSTR_UART5RST_POS   (0x14)
#define RCC_APB1RSTR_UART5RST_MSK   (0x01 << RCC_APB1RSTR_UART5RST_POS)
#define RCC_APB1RSTR_I2C1RST_POS    (0x15)
#define RCC_APB1RSTR_I2C1RST_MSK    (0x01 << RCC_APB1RSTR_I2C1RST_POS)
#define RCC_APB1RSTR_I2C2RST_POS    (0x16)
#define RCC_APB1RSTR_I2C2RST_MSK    (0x01 << RCC_APB1RSTR_I2C2RST_POS)
#define RCC_APB1RSTR_I2C3RST_POS    (0x17)
#define RCC_APB1RSTR_I2C3RST_MSK    (0x01 << RCC_APB1RSTR_I2C3RST_POS)
#define RCC_APB1RSTR_CAN1RST_POS    (0x19)
#define RCC_APB1RSTR_CAN1RST_MSK    (0x01 << RCC_APB1RSTR_CAN1RST_POS)
#define RCC_APB1RSTR_CAN2RST_POS    (0x1A)
#define RCC_APB1RSTR_CAN2RST_MSK    (0x01 << RCC_APB1RSTR_CAN2RST_POS)
#define RCC_APB1RSTR_PWRRST_POS     (0x1C)
#define RCC_APB1RSTR_PWRRST_MSK     (0x01 << RCC_APB1RSTR_PWRRST_POS)
#define RCC_APB1RSTR_DACRST_POS     (0x1D)
#define RCC_APB1RSTR_DACRST_MSK     (0x01 << RCC_APB1RSTR_DACRST_POS)
#define RCC_APB1RSTR_UART7RST_POS   (0x1E)
#define RCC_APB1RSTR_UART7RST_MSK   (0x01 << RCC_APB1RSTR_UART7RST_POS)
#define RCC_APB1RSTR_UART8RST_POS   (0x1F)
#define RCC_APB1RSTR_UART8RST_MSK   (0x01 << RCC_APB1RSTR_UART8RST_POS)

/* RCC APB2 peripheral reset register (RCC_APB2RSTR) */
#define RCC_APB2RSTR_DEFAULT (0x00000000U)

#define RCC_APB2RSTR_TIM1RST_POS    (0x00)
#define RCC_APB2RSTR_TIM1RST_MSK    (0x01 << RCC_APB2RSTR_TIM1RST_POS)
#define RCC_APB2RSTR_TIM8RST_POS    (0x01)
#define RCC_APB2RSTR_TIM8RST_MSK    (0x01 << RCC_APB2RSTR_TIM8RST_POS)
#define RCC_APB2RSTR_USART1RST_POS  (0x04)
#define RCC_APB2RSTR_USART1RST_MSK  (0x01 << RCC_APB2RSTR_USART1RST_POS)
#define RCC_APB2RSTR_USART6RST_POS  (0x05)
#define RCC_APB2RSTR_USART6RST_MSK  (0x01 << RCC_APB2RSTR_USART6RST_POS)
#define RCC_APB2RSTR_ADCRST_POS     (0x08)
#define RCC_APB2RSTR_ADCRST_MSK     (0x01 << RCC_APB2RSTR_ADCRST_POS)
#define RCC_APB2RSTR_SDIORST_POS    (0x0B)
#define RCC_APB2RSTR_SDIORST_MSK    (0x01 << RCC_APB2RSTR_SDIORST_POS)
#define RCC_APB2RSTR_SPI1RST_POS    (0x0C)
#define RCC_APB2RSTR_SPI1RST_MSK    (0x01 << RCC_APB2RSTR_SPI1RST_POS)
#define RCC_APB2RSTR_SPI4RST_POS    (0x0D)
#define RCC_APB2RSTR_SPI4RST_MSK    (0x01 << RCC_APB2RSTR_SPI4RST_POS)
#define RCC_APB2RSTR_SYSCFGRST_POS  (0x0E)
#define RCC_APB2RSTR_SYSCFGRST_MSK  (0x01 << RCC_APB2RSTR_SYSCFGRST_POS)
#define RCC_APB2RSTR_TIM9RST_POS    (0x10)
#define RCC_APB2RSTR_TIM9RST_MSK    (0x01 << RCC_APB2RSTR_TIM9RST_POS)
#define RCC_APB2RSTR_TIM10RST_POS   (0x11)
#define RCC_APB2RSTR_TIM10RST_MSK   (0x01 << RCC_APB2RSTR_TIM10RST_POS)
#define RCC_APB2RSTR_TIM11RST_POS   (0x12)
#define RCC_APB2RSTR_TIM11RST_MSK   (0x01 << RCC_APB2RSTR_TIM11RST_POS)
#define RCC_APB2RSTR_SPI5RST_POS    (0x14)
#define RCC_APB2RSTR_SPI5RST_MSK    (0x01 << RCC_APB2RSTR_SPI5RST_POS)
#define RCC_APB2RSTR_SPI6RST_POS    (0x15)
#define RCC_APB2RSTR_SPI6RST_MSK    (0x01 << RCC_APB2RSTR_SPI6RST_POS)
#define RCC_APB2RSTR_SAI1RST_POS    (0x16)
#define RCC_APB2RSTR_SAI1RST_MSK    (0x01 << RCC_APB2RSTR_SAI1RST_POS)
#define RCC_APB2RSTR_LTDCRST_POS    (0x1A)
#define RCC_APB2RSTR_LTDCRST_MSK    (0x01 << RCC_APB2RSTR_LTDCRST_POS)

/* RCC AHB1 peripheral clock register (RCC_AHB1ENR) */
#define RCC_AHB1ENR_DEFAULT (0x00100000U)

#define RCC_AHB1ENR_GPIOAEN_POS         (0x00)
#define RCC_AHB1ENR_GPIOAEN_MSK         (0x01 << RCC_AHB1ENR_GPIOAEN_POS)
#define RCC_AHB1ENR_GPIOBEN_POS         (0x01)
#define RCC_AHB1ENR_GPIOBEN_MSK         (0x01 << RCC_AHB1ENR_GPIOBEN_POS)
#define RCC_AHB1ENR_GPIOCEN_POS         (0x02)
#define RCC_AHB1ENR_GPIOCEN_MSK         (0x01 << RCC_AHB1ENR_GPIOCEN_POS)
#define RCC_AHB1ENR_GPIODEN_POS         (0x03)
#define RCC_AHB1ENR_GPIODEN_MSK         (0x01 << RCC_AHB1ENR_GPIODEN_POS)
#define RCC_AHB1ENR_GPIOEEN_POS         (0x04)
#define RCC_AHB1ENR_GPIOEEN_MSK         (0x01 << RCC_AHB1ENR_GPIOEEN_POS)
#define RCC_AHB1ENR_GPIOFEN_POS         (0x05)
#define RCC_AHB1ENR_GPIOFEN_MSK         (0x01 << RCC_AHB1ENR_GPIOFEN_POS)
#define RCC_AHB1ENR_GPIOGEN_POS         (0x06)
#define RCC_AHB1ENR_GPIOGEN_MSK         (0x01 << RCC_AHB1ENR_GPIOGEN_POS)
#define RCC_AHB1ENR_GPIOHEN_POS         (0x07)
#define RCC_AHB1ENR_GPIOHEN_MSK         (0x01 << RCC_AHB1ENR_GPIOHEN_POS)
#define RCC_AHB1ENR_GPIOIEN_POS         (0x08)
#define RCC_AHB1ENR_GPIOIEN_MSK         (0x01 << RCC_AHB1ENR_GPIOIEN_POS)
#define RCC_AHB1ENR_GPIOJEN_POS         (0x09)
#define RCC_AHB1ENR_GPIOJEN_MSK         (0x01 << RCC_AHB1ENR_GPIOJEN_POS)
#define RCC_AHB1ENR_GPIOKEN_POS         (0x0A)
#define RCC_AHB1ENR_GPIOKEN_MSK         (0x01 << RCC_AHB1ENR_GPIOKEN_POS)
#define RCC_AHB1ENR_CRCEN_POS           (0x0C)
#define RCC_AHB1ENR_CRCEN_MSK           (0x01 << RCC_AHB1ENR_CRCEN_POS)
#define RCC_AHB1ENR_BKPSRAMEN_POS       (0x12)
#define RCC_AHB1ENR_BKPSRAMEN_MSK       (0x01 << RCC_AHB1ENR_BKPSRAMEN_POS)
#define RCC_AHB1ENR_CCMDATARAMEN_POS    (0x14)
#define RCC_AHB1ENR_CCMDATARAMEN_MSK    (0x01 << RCC_AHB1ENR_CCMDATARAMEN_POS)
#define RCC_AHB1ENR_DMA1EN_POS          (0x15)
#define RCC_AHB1ENR_DMA1EN_MSK          (0x01 << RCC_AHB1ENR_DMA1EN_POS)
#define RCC_AHB1ENR_DMA2EN_POS          (0x16)
#define RCC_AHB1ENR_DMA2EN_MSK          (0x01 << RCC_AHB1ENR_DMA2EN_POS)
#define RCC_AHB1ENR_DMA2DEN_POS         (0x17)
#define RCC_AHB1ENR_DMA2DEN_MSK         (0x01 << RCC_AHB1ENR_DMA2DEN_POS)
#define RCC_AHB1ENR_ETHMACEN_POS        (0x19)
#define RCC_AHB1ENR_ETHMACEN_MSK        (0x01 << RCC_AHB1ENR_ETHMACEN_POS)
#define RCC_AHB1ENR_ETHMACTXEN_POS      (0x1A)
#define RCC_AHB1ENR_ETHMACTXEN_MSK      (0x01 << RCC_AHB1ENR_ETHMACTXEN_POS)
#define RCC_AHB1ENR_ETHMACRXEN_POS      (0x1B)
#define RCC_AHB1ENR_ETHMACRXEN_MSK      (0x01 << RCC_AHB1ENR_ETHMACRXEN_POS)
#define RCC_AHB1ENR_ETHMACPTPEN_POS     (0x1C)
#define RCC_AHB1ENR_ETHMACPTPEN_MSK     (0x01 << RCC_AHB1ENR_ETHMACPTPEN_POS)
#define RCC_AHB1ENR_OTGHSEN_POS         (0x1D)
#define RCC_AHB1ENR_OTGHSEN_MSK         (0x01 << RCC_AHB1ENR_OTGHSEN_POS)
#define RCC_AHB1ENR_OTGHSULPIEN_POS     (0x1E)
#define RCC_AHB1ENR_OTGHSULPIEN_MSK     (0x01 << RCC_AHB1ENR_OTGHSULPIEN_POS)

/* RCC AHB2 peripheral clock enable register (RCC_AHB2ENR) */
#define RCC_AHB2ENR_DEFAULT (0x00000000U)

#define RCC_AHB2ENR_DCMIEN_POS  (0x00)
#define RCC_AHB2ENR_DCMIEN_MSK  (0x01 << RCC_AHB2ENR_DCMIEN_POS)
#define RCC_AHB2ENR_CRYPEN_POS  (0x04)
#define RCC_AHB2ENR_CRYPEN_MSK  (0x01 << RCC_AHB2ENR_CRYPEN_POS)
#define RCC_AHB2ENR_HASHEN_POS  (0x05)
#define RCC_AHB2ENR_HASHEN_MSK  (0x01 << RCC_AHB2ENR_HASHEN_POS)
#define RCC_AHB2ENR_RNGEN_POS   (0x06)
#define RCC_AHB2ENR_RNGEN_MSK   (0x01 << RCC_AHB2ENR_RNGEN_POS)
#define RCC_AHB2ENR_OTGFSEN_POS (0x07)
#define RCC_AHB2ENR_OTGFSEN_MSK (0x01 << RCC_AHB2ENR_OTGFSEN_POS)

/* RCC AHB3 peripheral clock enable register (RCC_AHB3ENR) */
#define RCC_AHB3ENR_DEFAULT (0x00000000U)

#define RCC_AHB3ENR_FMCEN_POS  (0x00)
#define RCC_AHB3ENR_FMCEN_MSK  (0x01 << RCC_AHB3ENR_FMCEN_POS)

/* RCC APB1 peripheral clock enable register (RCC_APB1ENR) */
#define RCC_APB1ENR_DEFAULT (0x00000000U)

#define RCC_APB1ENR_TIM2EN_POS      (0x00)
#define RCC_APB1ENR_TIM2EN_MSK      (0x01 << RCC_APB1ENR_TIM2EN_POS)
#define RCC_APB1ENR_TIM3EN_POS      (0x01)
#define RCC_APB1ENR_TIM3EN_MSK      (0x01 << RCC_APB1ENR_TIM3EN_POS)
#define RCC_APB1ENR_TIM4EN_POS      (0x02)
#define RCC_APB1ENR_TIM4EN_MSK      (0x01 << RCC_APB1ENR_TIM4EN_POS)
#define RCC_APB1ENR_TIM5EN_POS      (0x03)
#define RCC_APB1ENR_TIM5EN_MSK      (0x01 << RCC_APB1ENR_TIM5EN_POS)
#define RCC_APB1ENR_TIM6EN_POS      (0x04)
#define RCC_APB1ENR_TIM6EN_MSK      (0x01 << RCC_APB1ENR_TIM6EN_POS)
#define RCC_APB1ENR_TIM7EN_POS      (0x05)
#define RCC_APB1ENR_TIM7EN_MSK      (0x01 << RCC_APB1ENR_TIM7EN_POS)
#define RCC_APB1ENR_TIM12EN_POS     (0x06)
#define RCC_APB1ENR_TIM12EN_MSK     (0x01 << RCC_APB1ENR_TIM12EN_POS)
#define RCC_APB1ENR_TIM13EN_POS     (0x07)
#define RCC_APB1ENR_TIM13EN_MSK     (0x01 << RCC_APB1ENR_TIM13EN_POS)
#define RCC_APB1ENR_TIM14EN_POS     (0x08)
#define RCC_APB1ENR_TIM14EN_MSK     (0x01 << RCC_APB1ENR_TIM14EN_POS)
#define RCC_APB1ENR_WWDGEN_POS      (0x0B)
#define RCC_APB1ENR_WWDGEN_MSK      (0x01 << RCC_APB1ENR_WWDGEN_POS)
#define RCC_APB1ENR_SPI2EN_POS      (0x0E)
#define RCC_APB1ENR_SPI2EN_MSK      (0x01 << RCC_APB1ENR_SPI2EN_POS)
#define RCC_APB1ENR_SPI3EN_POS      (0x0F)
#define RCC_APB1ENR_SPI3EN_MSK      (0x01 << RCC_APB1ENR_SPI3EN_POS)
#define RCC_APB1ENR_USART2EN_POS    (0x11)
#define RCC_APB1ENR_USART2EN_MSK    (0x01 << RCC_APB1ENR_USART2EN_POS)
#define RCC_APB1ENR_USART3EN_POS    (0x12)
#define RCC_APB1ENR_USART3EN_MSK    (0x01 << RCC_APB1ENR_USART3EN_POS)
#define RCC_APB1ENR_UART4EN_POS     (0x13)
#define RCC_APB1ENR_UART4EN_MSK     (0x01 << RCC_APB1ENR_UART4EN_POS)
#define RCC_APB1ENR_UART5EN_POS     (0x14)
#define RCC_APB1ENR_UART5EN_MSK     (0x01 << RCC_APB1ENR_UART5EN_POS)
#define RCC_APB1ENR_I2C1EN_POS      (0x15)
#define RCC_APB1ENR_I2C1EN_MSK      (0x01 << RCC_APB1ENR_I2C1EN_POS)
#define RCC_APB1ENR_I2C2EN_POS      (0x16)
#define RCC_APB1ENR_I2C2EN_MSK      (0x01 << RCC_APB1ENR_I2C2EN_POS)
#define RCC_APB1ENR_I2C3EN_POS      (0x17)
#define RCC_APB1ENR_I2C3EN_MSK      (0x01 << RCC_APB1ENR_I2C3EN_POS)
#define RCC_APB1ENR_CAN1EN_POS      (0x19)
#define RCC_APB1ENR_CAN1EN_MSK      (0x01 << RCC_APB1ENR_CAN1EN_POS)
#define RCC_APB1ENR_CAN2EN_POS      (0x1A)
#define RCC_APB1ENR_CAN2EN_MSK      (0x01 << RCC_APB1ENR_CAN2EN_POS)
#define RCC_APB1ENR_PWREN_POS       (0x1C)
#define RCC_APB1ENR_PWREN_MSK       (0x01 << RCC_APB1ENR_PWREN_POS)
#define RCC_APB1ENR_DACEN_POS       (0x1D)
#define RCC_APB1ENR_DACEN_MSK       (0x01 << RCC_APB1ENR_DACEN_POS)
#define RCC_APB1ENR_UART7EN_POS     (0x1E)
#define RCC_APB1ENR_UART7EN_MSK     (0x01 << RCC_APB1ENR_UART7EN_POS)
#define RCC_APB1ENR_UART8EN_POS     (0x1F)
#define RCC_APB1ENR_UART8EN_MSK     (0x01 << RCC_APB1ENR_UART8EN_POS)

/* RCC APB2 peripheral clock enable register (RCC_APB2ENR) */
#define RCC_APB2ENR_DEFAULT (0x00000000U)

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

/* RCC AHB1 peripheral clock enable in low power mode register (RCC_AHB1LPENR) */
#define RCC_AHB1LPENR_DEFAULT (0x7EEF97FFU)

#define RCC_AHB1LPENR_GPIOALPEN_POS     (0x00)
#define RCC_AHB1LPENR_GPIOALPEN_MSK     (0x01 << RCC_AHB1LPENR_GPIOALPEN_POS)
#define RCC_AHB1LPENR_GPIOBLPEN_POS     (0x01)
#define RCC_AHB1LPENR_GPIOBLPEN_MSK     (0x01 << RCC_AHB1LPENR_GPIOBLPEN_POS)
#define RCC_AHB1LPENR_GPIOCLPEN_POS     (0x02)
#define RCC_AHB1LPENR_GPIOCLPEN_MSK     (0x01 << RCC_AHB1LPENR_GPIOCLPEN_POS)
#define RCC_AHB1LPENR_GPIODLPEN_POS     (0x03)
#define RCC_AHB1LPENR_GPIODLPEN_MSK     (0x01 << RCC_AHB1LPENR_GPIODLPEN_POS)
#define RCC_AHB1LPENR_GPIOELPEN_POS     (0x04)
#define RCC_AHB1LPENR_GPIOELPEN_MSK     (0x01 << RCC_AHB1LPENR_GPIOELPEN_POS)
#define RCC_AHB1LPENR_GPIOFLPEN_POS     (0x05)
#define RCC_AHB1LPENR_GPIOFLPEN_MSK     (0x01 << RCC_AHB1LPENR_GPIOFLPEN_POS)
#define RCC_AHB1LPENR_GPIOGLPEN_POS     (0x06)
#define RCC_AHB1LPENR_GPIOGLPEN_MSK     (0x01 << RCC_AHB1LPENR_GPIOGLPEN_POS)
#define RCC_AHB1LPENR_GPIOHLPEN_POS     (0x07)
#define RCC_AHB1LPENR_GPIOHLPEN_MSK     (0x01 << RCC_AHB1LPENR_GPIOHLPEN_POS)
#define RCC_AHB1LPENR_GPIOILPEN_POS     (0x08)
#define RCC_AHB1LPENR_GPIOILPEN_MSK     (0x01 << RCC_AHB1LPENR_GPIOILPEN_POS)
#define RCC_AHB1LPENR_GPIOJLPEN_POS     (0x09)
#define RCC_AHB1LPENR_GPIOJLPEN_MSK     (0x01 << RCC_AHB1LPENR_GPIOJLPEN_POS)
#define RCC_AHB1LPENR_GPIOKLPEN_POS     (0x0A)
#define RCC_AHB1LPENR_GPIOKLPEN_MSK     (0x01 << RCC_AHB1LPENR_GPIOKLPEN_POS)
#define RCC_AHB1LPENR_CRCLPEN_POS       (0x00)
#define RCC_AHB1LPENR_CRCLPEN_MSK       (0x01 << RCC_AHB1LPENR_CRCLPEN_POS)
#define RCC_AHB1LPENR_FLITFLPEN_POS     (0x0C)
#define RCC_AHB1LPENR_FLITFLPEN_MSK     (0x01 << RCC_AHB1LPENR_FLITFLPEN_POS)
#define RCC_AHB1LPENR_SRAM1LPEN_POS     (0x0F)
#define RCC_AHB1LPENR_SRAM1LPEN_MSK     (0x01 << RCC_AHB1LPENR_SRAM1LPEN_POS)
#define RCC_AHB1LPENR_SRAM2LPEN_POS     (0x10)
#define RCC_AHB1LPENR_SRAM2LPEN_MSK     (0x01 << RCC_AHB1LPENR_SRAM2LPEN_POS)
#define RCC_AHB1LPENR_BKPSRAMLPEN_POS   (0x11)
#define RCC_AHB1LPENR_BKPSRAMLPEN_MSK   (0x01 << RCC_AHB1LPENR_BKPSRAMLPEN_POS)
#define RCC_AHB1LPENR_SRAM3LPEN_POS     (0x12)
#define RCC_AHB1LPENR_SRAM3LPEN_MSK     (0x01 << RCC_AHB1LPENR_SRAM3LPEN_POS)
#define RCC_AHB1LPENR_DMA1LPEN_POS      (0x14)
#define RCC_AHB1LPENR_DMA1LPEN_MSK      (0x01 << RCC_AHB1LPENR_DMA1LPEN_POS)
#define RCC_AHB1LPENR_DMA2LPEN_POS      (0x15)
#define RCC_AHB1LPENR_DMA2LPEN_MSK      (0x01 << RCC_AHB1LPENR_DMA2LPEN_POS)
#define RCC_AHB1LPENR_DMA2DLPEN_POS     (0x16)
#define RCC_AHB1LPENR_DMA2DLPEN_MSK     (0x01 << RCC_AHB1LPENR_DMA2DLPEN_POS)
#define RCC_AHB1LPENR_ETHMACLPEN_POS    (0x18)
#define RCC_AHB1LPENR_ETHMACLPEN_MSK    (0x01 << RCC_AHB1LPENR_ETHMACLPEN_POS)
#define RCC_AHB1LPENR_ETHMACTXLPEN_POS  (0x19)
#define RCC_AHB1LPENR_ETHMACTXLPEN_MSK  (0x01 << RCC_AHB1LPENR_ETHMACTXLPEN_POS)
#define RCC_AHB1LPENR_ETHMACRXLPEN_POS  (0x1A)
#define RCC_AHB1LPENR_ETHMACRXLPEN_MSK  (0x01 << RCC_AHB1LPENR_ETHMACRXLPEN_POS)
#define RCC_AHB1LPENR_ETHMACPTPLPEN_POS (0x1B)
#define RCC_AHB1LPENR_ETHMACPTPLPEN_MSK (0x01 << RCC_AHB1LPENR_ETHMACPTPLPEN_POS)
#define RCC_AHB1LPENR_OTGHSLPEN_POS     (0x1C)
#define RCC_AHB1LPENR_OTGHSLPEN_MSK     (0x01 << RCC_AHB1LPENR_OTGHSLPEN_POS)
#define RCC_AHB1LPENR_OTGHSULPILPEN_POS (0x1D)
#define RCC_AHB1LPENR_OTGHSULPILPEN_MSK (0x01 << RCC_AHB1LPENR_OTGHSULPILPEN_POS)

/* RCC AHB2 peripheral clock enable in low power mode register (RCC_AHB2LPENR) */
#define RCC_AHB2LPENR_DEFAULT (0x000000F1U)

#define RCC_AHB2LPENR_DCMILPEN_POS  (0x00)
#define RCC_AHB2LPENR_DCMILPEN_MSK  (0x01 << RCC_AHB2LPENR_DCMILPEN_POS)
#define RCC_AHB2LPENR_CRYPLPEN_POS  (0x04)
#define RCC_AHB2LPENR_CRYPLPEN_MSK  (0x01 << RCC_AHB2LPENR_CRYPLPEN_POS)
#define RCC_AHB2LPENR_HASHLPEN_POS  (0x05)
#define RCC_AHB2LPENR_HASHLPEN_MSK  (0x01 << RCC_AHB2LPENR_HASHLPEN_POS)
#define RCC_AHB2LPENR_RNGLPEN_POS   (0x06)
#define RCC_AHB2LPENR_RNGLPEN_MSK   (0x01 << RCC_AHB2LPENR_RNGLPEN_POS)
#define RCC_AHB2LPENR_OTGFSLPEN_POS (0x07)
#define RCC_AHB2LPENR_OTGFSLPEN_MSK (0x01 << RCC_AHB2LPENR_OTGFSLPEN_POS)

/* RCC AHB3 peripheral clock enable in low power mode register (RCC_AHB3LPENR) */
#define RCC_AHB3LPENR_DEFAULT (0x00000001U)

#define RCC_AHB2LPENR_FMCLPEN_POS  (0x00)
#define RCC_AHB2LPENR_FMCLPEN_MSK  (0x01 << RCC_AHB2LPENR_FMCLPEN_POS)

/* RCC APB1 peripheral clock enable in low power mode register (RCC_APB1LPENR) */
#define RCC_APB1LPENR_DEFAULT (0xF6FEC9FFU)

#define RCC_APB1LPENR_TIM2LPEN_POS      (0x00)
#define RCC_APB1LPENR_TIM2LPEN_MSK      (0x01 << RCC_APB1LPENR_TIM2LPEN_POS)
#define RCC_APB1LPENR_TIM3LPEN_POS      (0x01)
#define RCC_APB1LPENR_TIM3LPEN_MSK      (0x01 << RCC_APB1LPENR_TIM3LPEN_POS)
#define RCC_APB1LPENR_TIM4LPEN_POS      (0x02)
#define RCC_APB1LPENR_TIM4LPEN_MSK      (0x01 << RCC_APB1LPENR_TIM4LPEN_POS)
#define RCC_APB1LPENR_TIM5LPEN_POS      (0x03)
#define RCC_APB1LPENR_TIM5LPEN_MSK      (0x01 << RCC_APB1LPENR_TIM5LPEN_POS)
#define RCC_APB1LPENR_TIM6LPEN_POS      (0x04)
#define RCC_APB1LPENR_TIM6LPEN_MSK      (0x01 << RCC_APB1LPENR_TIM6LPEN_POS)
#define RCC_APB1LPENR_TIM7LPEN_POS      (0x05)
#define RCC_APB1LPENR_TIM7LPEN_MSK      (0x01 << RCC_APB1LPENR_TIM7LPEN_POS)
#define RCC_APB1LPENR_TIM12LPEN_POS     (0x06)
#define RCC_APB1LPENR_TIM12LPEN_MSK     (0x01 << RCC_APB1LPENR_TIM12LPEN_POS)
#define RCC_APB1LPENR_TIM13LPEN_POS     (0x07)
#define RCC_APB1LPENR_TIM13LPEN_MSK     (0x01 << RCC_APB1LPENR_TIM13LPEN_POS)
#define RCC_APB1LPENR_TIM14LPEN_POS     (0x08)
#define RCC_APB1LPENR_TIM14LPEN_MSK     (0x01 << RCC_APB1LPENR_TIM14LPEN_POS)
#define RCC_APB1LPENR_WWDGLPEN_POS      (0x0B)
#define RCC_APB1LPENR_WWDGLPEN_MSK      (0x01 << RCC_APB1LPENR_WWDGLPEN_POS)
#define RCC_APB1LPENR_SPI2LPEN_POS      (0x0E)
#define RCC_APB1LPENR_SPI2LPEN_MSK      (0x01 << RCC_APB1LPENR_SPI2LPEN_POS)
#define RCC_APB1LPENR_SPI3LPEN_POS      (0x0F)
#define RCC_APB1LPENR_SPI3LPEN_MSK      (0x01 << RCC_APB1LPENR_SPI3LPEN_POS)
#define RCC_APB1LPENR_USART2LPEN_POS    (0x11)
#define RCC_APB1LPENR_USART2LPEN_MSK    (0x01 << RCC_APB1LPENR_USART2LPEN_POS)
#define RCC_APB1LPENR_USART3LPEN_POS    (0x12)
#define RCC_APB1LPENR_USART3LPEN_MSK    (0x01 << RCC_APB1LPENR_USART3LPEN_POS)
#define RCC_APB1LPENR_UART4LPEN_POS     (0x13)
#define RCC_APB1LPENR_UART4LPEN_MSK     (0x01 << RCC_APB1LPENR_UART4LPEN_POS)
#define RCC_APB1LPENR_UART5LPEN_POS     (0x14)
#define RCC_APB1LPENR_UART5LPEN_MSK     (0x01 << RCC_APB1LPENR_UART5LPEN_POS)
#define RCC_APB1LPENR_I2C1LPEN_POS      (0x15)
#define RCC_APB1LPENR_I2C1LPEN_MSK      (0x01 << RCC_APB1LPENR_I2C1LPEN_POS)
#define RCC_APB1LPENR_I2C2LPEN_POS      (0x16)
#define RCC_APB1LPENR_I2C2LPEN_MSK      (0x01 << RCC_APB1LPENR_I2C2LPEN_POS)
#define RCC_APB1LPENR_I2C3LPEN_POS      (0x17)
#define RCC_APB1LPENR_I2C3LPEN_MSK      (0x01 << RCC_APB1LPENR_I2C3LPEN_POS)
#define RCC_APB1LPENR_CAN1LPEN_POS      (0x19)
#define RCC_APB1LPENR_CAN1LPEN_MSK      (0x01 << RCC_APB1LPENR_CAN1LPEN_POS)
#define RCC_APB1LPENR_CAN2LPEN_POS      (0x1A)
#define RCC_APB1LPENR_CAN2LPEN_MSK      (0x01 << RCC_APB1LPENR_CAN2LPEN_POS)
#define RCC_APB1LPENR_PWRLPEN_POS       (0x1C)
#define RCC_APB1LPENR_PWRLPEN_MSK       (0x01 << RCC_APB1LPENR_PWRLPEN_POS)
#define RCC_APB1LPENR_DACLPEN_POS       (0x1D)
#define RCC_APB1LPENR_DACLPEN_MSK       (0x01 << RCC_APB1LPENR_DACLPEN_POS)
#define RCC_APB1LPENR_UART7LPEN_POS     (0x1E)
#define RCC_APB1LPENR_UART7LPEN_MSK     (0x01 << RCC_APB1LPENR_UART7LPEN_POS)
#define RCC_APB1LPENR_UART8LPEN_POS     (0x1F)
#define RCC_APB1LPENR_UART8LPEN_MSK     (0x01 << RCC_APB1LPENR_UART8LPEN_POS)

/* RCC APB2 peripheral clock enabled in low power mode register (RCC_APB2LPENR) */
#define RCC_APB2LPENR_DEFAULT (0x04777F33U)

#define RCC_APB2LPENR_TIM1LPEN_POS      (0x00)
#define RCC_APB2LPENR_TIM1LPEN_MSK      (0x01 << RCC_APB2LPENR_TIM1LPEN_POS)
#define RCC_APB2LPENR_TIM8LPEN_POS      (0x01)
#define RCC_APB2LPENR_TIM8LPEN_MSK      (0x01 << RCC_APB2LPENR_TIM8LPEN_POS)
#define RCC_APB2LPENR_USART1LPEN_POS    (0x04)
#define RCC_APB2LPENR_USART1LPEN_MSK    (0x01 << RCC_APB2LPENR_USART1LPEN_POS)
#define RCC_APB2LPENR_USART6LPEN_POS    (0x05)
#define RCC_APB2LPENR_USART6LPEN_MSK    (0x01 << RCC_APB2LPENR_USART6LPEN_POS)
#define RCC_APB2LPENR_ADC1LPEN_POS      (0x08)
#define RCC_APB2LPENR_ADC1LPEN_MSK      (0x01 << RCC_APB2LPENR_ADC1LPEN_POS)
#define RCC_APB2LPENR_ADC2LPEN_POS      (0x09)
#define RCC_APB2LPENR_ADC2LPEN_MSK      (0x01 << RCC_APB2LPENR_ADC2LPEN_POS)
#define RCC_APB2LPENR_ADC3LPEN_POS      (0x0A)
#define RCC_APB2LPENR_ADC3LPEN_MSK      (0x01 << RCC_APB2LPENR_ADC3LPEN_POS)
#define RCC_APB2LPENR_SDIOLPEN_POS      (0x0B)
#define RCC_APB2LPENR_SDIOLPEN_MSK      (0x01 << RCC_APB2LPENR_SDIOLPEN_POS)
#define RCC_APB2LPENR_SPI1LPEN_POS      (0x0C)
#define RCC_APB2LPENR_SPI1LPEN_MSK      (0x01 << RCC_APB2LPENR_SPI1LPEN_POS)
#define RCC_APB2LPENR_SPI4LPEN_POS      (0x0D)
#define RCC_APB2LPENR_SPI4LPEN_MSK      (0x01 << RCC_APB2LPENR_SPI4LPEN_POS)
#define RCC_APB2LPENR_SYSCFGLPEN_POS    (0x0E)
#define RCC_APB2LPENR_SYSCFGLPEN_MSK    (0x01 << RCC_APB2LPENR_SYSCFGLPEN_POS)
#define RCC_APB2LPENR_TIM9LPEN_POS      (0x10)
#define RCC_APB2LPENR_TIM9LPEN_MSK      (0x01 << RCC_APB2LPENR_TIM9LPEN_POS)
#define RCC_APB2LPENR_TIM10LPEN_POS     (0x11)
#define RCC_APB2LPENR_TIM10LPEN_MSK     (0x01 << RCC_APB2LPENR_TIM10LPEN_POS)
#define RCC_APB2LPENR_TIM11LPEN_POS     (0x12)
#define RCC_APB2LPENR_TIM11LPEN_MSK     (0x01 << RCC_APB2LPENR_TIM11LPEN_POS)
#define RCC_APB2LPENR_SPI5LPEN_POS      (0x14)
#define RCC_APB2LPENR_SPI5LPEN_MSK      (0x01 << RCC_APB2LPENR_SPI5LPEN_POS)
#define RCC_APB2LPENR_SPI6LPEN_POS      (0x15)
#define RCC_APB2LPENR_SPI6LPEN_MSK      (0x01 << RCC_APB2LPENR_SPI6LPEN_POS)
#define RCC_APB2LPENR_SAI1LPEN_POS      (0x16)
#define RCC_APB2LPENR_SAI1LPEN_MSK      (0x01 << RCC_APB2LPENR_SAI1LPEN_POS)
#define RCC_APB2LPENR_LTDCLPEN_POS      (0x1A)
#define RCC_APB2LPENR_LTDCLPEN_MSK      (0x01 << RCC_APB2LPENR_LTDCLPEN_POS)

/* RCC Backup domain control register (RCC_BDCR) */
#define RCC_BDCR_DEFAULT (0x00000000U)

#define RCC_BDCR_LSEON_POS  (0x00)
#define RCC_BDCR_LSEON_MSK  (0x01 << RCC_BDCR_LSEON_POS)
#define RCC_BDCR_LSERDY_POS (0x01)
#define RCC_BDCR_LSERDY_MSK (0x01 << RCC_BDCR_LSERDY_POS)
#define RCC_BDCR_LSEBYP_POS (0x02)
#define RCC_BDCR_LSEBYP_MSK (0x01 << RCC_BDCR_LSEBYP_POS)
#define RCC_BDCR_RTCSEL_POS (0x08)
#define RCC_BDCR_RTCSEL_MSK (0x03 << RCC_BDCR_RTCSEL_POS)
#define RCC_BDCR_RTCEN_POS  (0x0F)
#define RCC_BDCR_RTCEN_MSK  (0x01 << RCC_BDCR_RTCEN_POS)
#define RCC_BDCR_BDRST_POS  (0x10)
#define RCC_BDCR_BDRST_MSK  (0x01 << RCC_BDCR_BDRST_POS)

/* RCC clock control & status register (RCC_CSR) */
#define RCC_CSR_DEFAULT (0x0E000000U)

#define RCC_CSR_LSION_POS       (0x00)
#define RCC_CSR_LSION_MSK       (0x01 << RCC_CSR_LSION_POS)
#define RCC_CSR_LSIRDY_POS      (0x01)
#define RCC_CSR_LSIRDY_MSK      (0x01 << RCC_CSR_LSIRDY_POS)
#define RCC_CSR_RMVF_POS        (0x18)
#define RCC_CSR_RMVF_MSK        (0x01 << RCC_CSR_RMVF_POS)
#define RCC_CSR_BORRSTF_POS     (0x19)
#define RCC_CSR_BORRSTF_MSK     (0x01 << RCC_CSR_BORRSTF_POS)
#define RCC_CSR_PINRSTF_POS     (0x1A)
#define RCC_CSR_PINRSTF_MSK     (0x01 << RCC_CSR_PINRSTF_POS)
#define RCC_CSR_PORRSTF_POS     (0x1B)
#define RCC_CSR_PORRSTF_MSK     (0x01 << RCC_CSR_PORRSTF_POS)
#define RCC_CSR_SFTRSTF_POS     (0x1C)
#define RCC_CSR_SFTRSTF_MSK     (0x01 << RCC_CSR_SFTRSTF_POS)
#define RCC_CSR_IWDGRSTF_POS    (0x1D)
#define RCC_CSR_IWDGRSTF_MSK    (0x01 << RCC_CSR_IWDGRSTF_POS)
#define RCC_CSR_WWDGRSTF_POS    (0x1E)
#define RCC_CSR_WWDGRSTF_MSK    (0x01 << RCC_CSR_WWDGRSTF_POS)
#define RCC_CSR_LPWRRSTF_POS    (0x1F)
#define RCC_CSR_LPWRRSTF_MSK    (0x01 << RCC_CSR_LPWRRSTF_POS)

/* RCC spread spectrum clock generation register (RCC_SSCGR) */
#define RCC_SSCGR_DEFAULT (0x00000000U)

#define RCC_SSCGR_MODPER_POS    (0x00)
#define RCC_SSCGR_MODPER_MSK    (0x1FFF << RCC_SSCGR_MODPER_POS)
#define RCC_SSCGR_INCSTEP_POS   (0x0D)
#define RCC_SSCGR_INCSTEP_MSK   (0x7FFF << RCC_SSCGR_INCSTEP_POS)
#define RCC_SSCGR_SPREADSEL_POS (0x1E)
#define RCC_SSCGR_SPREADSEL_MSK (0x01 << RCC_SSCGR_SPREADSEL_POS)
#define RCC_SSCGR_SSCGEN_POS    (0x1F)

/* RCC PLLI2S configuration register (RCC_PLLI2SCFGR) */
#define RCC_PLLI2SCFGR_DEFAULT (0x24003000U)

#define RCC_PLLI2SCFGR_PLLI2SN_POS  (0x06)
#define RCC_PLLI2SCFGR_PLLI2SN_MSK  (0x1FF << RCC_PLLI2SCFGR_PLLI2SN_POS)
#define RCC_PLLI2SCFGR_PLLI2SQ_POS  (0x18)
#define RCC_PLLI2SCFGR_PLLI2SQ_MSK  (0x0F << RCC_PLLI2SCFGR_PLLI2SQ_POS)
#define RCC_PLLI2SCFGR_PLLI2SR_POS  (0x1C)
#define RCC_PLLI2SCFGR_PLLI2SR_MSK  (0x07 << RCC_PLLI2SCFGR_PLLI2SR_POS)

/* RCC PLL configuration register (RCC_PLLSAICFGR) */
#define RCC_PLLSAICFGR_DEFAULT (0x24003000U)

#define RCC_PLLSAICFGR_PLLSAIN_POS  (0x06)
#define RCC_PLLSAICFGR_PLLSAIN_MSK  (0x1FF << RCC_PLLSAICFGR_PLLSAIN_POS)
#define RCC_PLLSAICFGR_PLLSAIQ_POS  (0x18)
#define RCC_PLLSAICFGR_PLLSAIQ_MSK  (0x0F << RCC_PLLSAICFGR_PLLSAIQ_POS)
#define RCC_PLLSAICFGR_PLLSAIR_POS  (0x1C)
#define RCC_PLLSAICFGR_PLLSAIR_MSK  (0x07 << RCC_PLLSAICFGR_PLLSAIR_POS)

/* RCC Dedicated Clock Configuration Register (RCC_DCKCFGR) */
#define RCC_DCKCFGR_DEFAULT (0x00000000U)

#define RCC_DCKCFGR_PLLI2SDIVQ_POS (0x00)
#define RCC_DCKCFGR_PLLI2SDIVQ_MSK (0x1F << RCC_DCKCFGR_PLLI2SDIVQ_POS)
#define RCC_DCKCFGR_PLLSAIDIVQ_POS (0x08)
#define RCC_DCKCFGR_PLLSAIDIVQ_MSK (0x1F << RCC_DCKCFGR_PLLSAIDIVQ_POS)
#define RCC_DCKCFGR_PLLSAIDIVR_POS (0x10)
#define RCC_DCKCFGR_PLLSAIDIVR_MSK (0x03 << RCC_DCKCFGR_PLLSAIDIVR_POS)
#define RCC_DCKCFGR_SAI1ASRC_POS   (0x14)
#define RCC_DCKCFGR_SAI1ASRC_MSK   (0x03 << RCC_DCKCFGR_SAI1ASRC_POS)
#define RCC_DCKCFGR_SAI1BSRC_POS   (0x16)
#define RCC_DCKCFGR_SAI1BSRC_MSK   (0x03 << RCC_DCKCFGR_SAI1BSRC_POS)
#define RCC_DCKCFGR_TIMPRE_POS     (0x18)
#define RCC_DCKCFGR_TIMPRE_MSK     (0x01 << RCC_DCKCFGR_TIMPRE_POS)