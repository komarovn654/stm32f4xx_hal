#include "stdint.h"

typedef struct
{
    uint32_t CR1;
    uint32_t RESERVED1;
    uint32_t SMCR;
    uint32_t DIER;
    uint32_t SR;
    uint32_t EGR;
    uint32_t CCMR1;
    uint32_t RESERVED2;
    uint32_t CCER;
    uint32_t CNT;
    uint32_t PSC;
    uint32_t ARR;
    uint32_t RESERVED3;
    uint32_t CCR1;
    uint32_t RESERVED4;
    uint32_t RESERVED5;
    uint32_t RESERVED6;
    uint32_t RESERVED7;
    uint32_t RESERVED8;
    uint32_t RESERVED9;
    uint32_t OR;
} TIM10_11_13_14_TypeDef;

#define TIM10_BASE 0x40014400
#define TIM11_BASE 0x40014800
#define TIM13_BASE 0x40001C00
#define TIM14_BASE 0x40002000

#define TIM10 ((TIM10_11_13_14_TypeDef *) TIM10_BASE)
#define TIM11 ((TIM10_11_13_14_TypeDef *) TIM11_BASE)
#define TIM13 ((TIM10_11_13_14_TypeDef *) TIM13_BASE)
#define TIM14 ((TIM10_11_13_14_TypeDef *) TIM14_BASE)

/* TIM10/11/13/14 control register 1 (TIMx_CR1) */
#define TIM_CR1_CEN_POS     (0x00)
#define TIM_CR1_CEN_MSK     (0x01 << TIM_CR1_CEN_POS)
#define TIM_CR1_UDIS_POS    (0x01)
#define TIM_CR1_UDIS_MSK    (0x01 << TIM_CR1_UDIS_POS)
#define TIM_CR1_URS_POS     (0x02)
#define TIM_CR1_URS_MSK     (0x01 << TIM_CR1_URS_POS)
#define TIM_CR1_OPM_POS     (0x03)
#define TIM_CR1_OPM_MSK     (0x01 << TIM_CR1_OPM_POS)
#define TIM_CR1_ARPE_POS    (0x07)
#define TIM_CR1_ARPE_MSK    (0x01 << TIM_CR1_ARPE_POS)
#define TIM_CR1_CKD_POS     (0x08)
#define TIM_CR1_CKD_MSK     (0x03 << TIM_CR1_CKD_POS)

#define TIM_CLOCK_DIVISON_1 (0x00)
#define TIM_CLOCK_DIVISON_2 (0x01)
#define TIM_CLOCK_DIVISON_4 (0x02)

/* TIM10/11/13/14 Interrupt enable register (TIMx_DIER) */
#define TIM_DIER_UIE_POS    (0x00)
#define TIM_DIER_UIE_MSK    (0x01 << TIM_DIER_UIE_POS)
#define TIM_DIER_CC1IE_POS  (0x01)
#define TIM_DIER_CC1IE_MSK  (0x01 << TIM_DIER_UIE_MSK)

/* TIM10/11/13/14 status register (TIMx_SR) */
#define TIM_SR_UIF_POS      (0x00)
#define TIM_SR_UIF_MSK      (0x01 << TIM_SR_UIF_POS)
#define TIM_SR_CC1IF_POS    (0x01)
#define TIM_SR_CC1IF_MSK    (0x01 << TIM_SR_CC1IF_POS)
#define TIM_SR_CC1OF_POS    (0x09)
#define TIM_SR_CC1OF_MSK    (0x01 << TIM_SR_CC1OF_POS)

/* TIM10/11/13/14 event generation register (TIMx_EGR) */
#define TIM_EGR_UG_POS      (0x00)
#define TIM_EGR_UG_MSK      (0x01 << TIM_EGR_UG_POS)
#define TIM_EGR_CC1G_POS    (0x01)
#define TIM_EGR_CC1G_MSK    (0x01 << TIM_EGR_CC1G_POS)

/* TIM10/11/13/14 capture/compare mode register 1 (TIMx_CCMR1) */
#define TIM_CCMR1_CC1S_POS      (0x00)
#define TIM_CCMR1_CC1S_MSK      (0x03 << TIM_CCMR1_CC1S_POS)
/* Output compare mode */ 
#define TIM_CCMR1_OC1FE_POS     (0x02)
#define TIM_CCMR1_OC1FE_MSK     (0x01 << TIM_CCMR1_OC1FE_POS)
#define TIM_CCMR1_OC1PE_POS     (0x03)
#define TIM_CCMR1_OC1PE_MSK     (0x01 << TIM_CCMR1_OC1PE_POS)
#define TIM_CCMR1_OC1M_POS      (0x04)
#define TIM_CCMR1_OC1M_MSK      (0x03 << TIM_CCMR1_OC1M_POS)
/* Input compare mode */
#define TIM_CCMR1_IC1PSC_POS    (0x02)
#define TIM_CCMR1_IC1PSC_MSK    (0x03 << TIM_CCMR1_IC1PSC_POS)
#define TIM_CCMR1_IC1F_POS      (0x04)
#define TIM_CCMR1_IC1F_MSK      (0x03 << TIM_CCMR1_IC1F_POS)

/* TIM10/11/13/14 capture/compare enable register (TIMx_CCER) */
#define TIM_CCMR1_CC1E_POS      (0x00)
#define TIM_CCMR1_CC1E_MSK      (0x01 << TIM_CCMR1_CC1E_POS)
#define TIM_CCMR1_CC1P_POS      (0x01)
#define TIM_CCMR1_CC1P_MSK      (0x01 << TIM_CCMR1_CC1P_POS)
#define TIM_CCMR1_CC1NP_POS     (0x03)
#define TIM_CCMR1_CC1NP_MSK     (0x01 << TIM_CCMR1_CC1NP_POS)

/* TIM10/11/13/14 counter (TIMx_CNT) */
#define TIM_CCMR1_CNT_POS       (0x00)
#define TIM_CCMR1_CNT_MSK       (0x0F << TIM_CCMR1_CNT_POS)

/* TIM10/11/13/14 prescaler (TIMx_PSC) */
#define TIM_CCMR1_PSC_POS       (0x00)
#define TIM_CCMR1_PSC_MSK       (0x0F << TIM_CCMR1_PSC_POS)

/* TIM10/11/13/14 auto-reload register (TIMx_ARR) */
#define TIM_CCMR1_ARR_POS       (0x00)
#define TIM_CCMR1_ARR_MSK       (0x0F << TIM_CCMR1_PSC_POS)

/* TIM10/11/13/14 capture/compare register 1 (TIMx_CCR1) */
#define TIM_CCMR1_CCR1_POS      (0x00)
#define TIM_CCMR1_CCR1_MSK      (0x0F << TIM_CCMR1_PSC_POS)
