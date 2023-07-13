#include "stdint.h"

typedef struct
{
    uint32_t CR1;
    uint32_t CR2;
    uint32_t SMCR;
    uint32_t DIER;
    uint32_t SR;
    uint32_t EGR;
    uint32_t CCMR1;
    uint32_t CCMR2;
    uint32_t CCER;
    uint32_t CNT;
    uint32_t PSC;
    uint32_t ARR;
    uint32_t RCR;
    uint32_t CCR1;
    uint32_t CCR2;
    uint32_t CCR3;
    uint32_t CCR4;
    uint32_t BDTR;
    uint32_t DCR;
    uint32_t DMAR;
} TIM1_8_TypeDef;

#define TIM1_BASE 0x40010000
#define TIM8_BASE 0x40010400

#define TIM1 ((TIM1_8_TypeDef *) TIM1_BASE)
#define TIM8 ((TIM1_8_TypeDef *) TIM8_BASE)

/* TIM1 and TIM8 control register 1 (TIMx_CR1) */
#define TIM1_8_CR1_CEN_POS      (0x00)
#define TIM1_8_CR1_CEN_MSK      (0x01 << TIM1_8_CR1_CEN_POS)
#define TIM1_8_CR1_UDIS_POS     (0x01)
#define TIM1_8_CR1_UDIS_MSK     (0x01 << TIM1_8_CR1_UDIS_POS)
#define TIM1_8_CR1_URS_POS      (0x02)
#define TIM1_8_CR1_URS_MSK      (0x01 << TIM1_8_CR1_URS_POS)
#define TIM1_8_CR1_OPM_POS      (0x03)
#define TIM1_8_CR1_OPM_MSK      (0x01 << TIM1_8_CR1_OPM_POS)
#define TIM1_8_CR1_DIR_POS      (0x04)
#define TIM1_8_CR1_DIR_MSK      (0x01 << TIM1_8_CR1_DIR_POS)
#define TIM1_8_CR1_CMS_POS      (0x05)
#define TIM1_8_CR1_CMS_MSK      (0x03 << TIM1_8_CR1_CMS_POS)
#define TIM1_8_CR1_ARPE_POS     (0x07)
#define TIM1_8_CR1_ARPE_MSK     (0x01 << TIM1_8_CR1_ARPE_POS)
#define TIM1_8_CR1_CKD_POS      (0x08)
#define TIM1_8_CR1_CKD_MSK      (0x03 << TIM1_8_CR1_CKD_POS)

#define TIM_CLOCK_DIVISON_1     (0x00)
#define TIM_CLOCK_DIVISON_2     (0x01)
#define TIM_CLOCK_DIVISON_4     (0x02)
