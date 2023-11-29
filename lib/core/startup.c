#include "stdint.h"
#include "stddef.h"

int main(int ac, char** av);
void __libc_init_array(void);

/* Memory defines */
#define SRAM_START 0x20000000
#define SRAM_SIZE  (128 * 1024)
#define SRAM_END (SRAM_START + SRAM_SIZE)

#define STACK_START SRAM_END

/* Memory boundaries */
extern uint32_t* _sidata;
extern uint32_t* _sdata;
extern uint32_t* _edata;
extern uint32_t* _sbss;
extern uint32_t* _ebss;

/* Vector table functions prototypes */
void ResetHandler               (void);
void NMIHandler                 (void) __attribute__((weak, alias("DefaultHandler"), noreturn));
void HardFaultHandler           (void) __attribute__((weak, alias("DefaultHandler"), noreturn));
void MemManageHandler           (void) __attribute__((weak, alias("DefaultHandler"), noreturn));
void BusFaultHandler            (void) __attribute__((weak, alias("DefaultHandler"), noreturn));
void UsageFaultHandler          (void) __attribute__((weak, alias("DefaultHandler"), noreturn));
void SVCallHandler              (void) __attribute__((weak, alias("DefaultHandler"), noreturn));
void DebugMonitorHandler        (void) __attribute__((weak, alias("DefaultHandler"), noreturn));
void PendSVHandler              (void) __attribute__((weak, alias("DefaultHandler"), noreturn));
void SysTickHandler             (void) __attribute__((weak, alias("DefaultHandler"), noreturn));
void WWDGHandler                (void) __attribute__((weak, alias("DefaultHandler"), noreturn));
void PVDHandler                 (void) __attribute__((weak, alias("DefaultHandler"), noreturn));
void TampStampHandler           (void) __attribute__((weak, alias("DefaultHandler"), noreturn));
void RTCWkupHandler             (void) __attribute__((weak, alias("DefaultHandler"), noreturn));
void FlashHandler               (void) __attribute__((weak, alias("DefaultHandler"), noreturn));
void RCCHandler                 (void) __attribute__((weak, alias("DefaultHandler"), noreturn));
void EXTI0Handler               (void) __attribute__((weak, alias("DefaultHandler"), noreturn));
void EXTI1Handler               (void) __attribute__((weak, alias("DefaultHandler"), noreturn));
void EXTI2Handler               (void) __attribute__((weak, alias("DefaultHandler"), noreturn));
void EXTI3Handler               (void) __attribute__((weak, alias("DefaultHandler"), noreturn));
void EXTI4Handler               (void) __attribute__((weak, alias("DefaultHandler"), noreturn));
void DMA1Stream0Handler         (void) __attribute__((weak, alias("DefaultHandler"), noreturn));
void DMA1Stream1Handler         (void) __attribute__((weak, alias("DefaultHandler"), noreturn));
void DMA1Stream2Handler         (void) __attribute__((weak, alias("DefaultHandler"), noreturn));
void DMA1Stream3Handler         (void) __attribute__((weak, alias("DefaultHandler"), noreturn));
void DMA1Stream4Handler         (void) __attribute__((weak, alias("DefaultHandler"), noreturn));
void DMA1Stream5Handler         (void) __attribute__((weak, alias("DefaultHandler"), noreturn));
void DMA1Stream6Handler         (void) __attribute__((weak, alias("DefaultHandler"), noreturn));
void ADCHandler                 (void) __attribute__((weak, alias("DefaultHandler"), noreturn));
void CAN1TXHandler              (void) __attribute__((weak, alias("DefaultHandler"), noreturn));
void CAN1RX0Handler             (void) __attribute__((weak, alias("DefaultHandler"), noreturn));
void CAN1RX1Handler             (void) __attribute__((weak, alias("DefaultHandler"), noreturn));
void CAN1SCEHandler             (void) __attribute__((weak, alias("DefaultHandler"), noreturn));
void EXTI9_5Handler             (void) __attribute__((weak, alias("DefaultHandler"), noreturn));
void TIM1BrkTIM9Handler         (void) __attribute__((weak, alias("DefaultHandler"), noreturn));
void TIM1UpTIM10Handler         (void) __attribute__((weak, alias("DefaultHandler"), noreturn));
void TIM1TrgComTIM11Handler     (void) __attribute__((weak, alias("DefaultHandler"), noreturn));
void TIM1CCHandler              (void) __attribute__((weak, alias("DefaultHandler"), noreturn));
void TIM2Handler                (void) __attribute__((weak, alias("DefaultHandler"), noreturn));
void TIM3Handler                (void) __attribute__((weak, alias("DefaultHandler"), noreturn));
void TIM4Handler                (void) __attribute__((weak, alias("DefaultHandler"), noreturn));
void I2C1EVHandler              (void) __attribute__((weak, alias("DefaultHandler"), noreturn));
void I2C1ERHandler              (void) __attribute__((weak, alias("DefaultHandler"), noreturn));
void I2C2EVHandler              (void) __attribute__((weak, alias("DefaultHandler"), noreturn));
void I2C2ERHandler              (void) __attribute__((weak, alias("DefaultHandler"), noreturn));
void SPI1Handler                (void) __attribute__((weak, alias("DefaultHandler"), noreturn));
void SPI2Handler                (void) __attribute__((weak, alias("DefaultHandler"), noreturn));
void USART1Handler              (void) __attribute__((weak, alias("DefaultHandler"), noreturn));
void USART2Handler              (void) __attribute__((weak, alias("DefaultHandler"), noreturn));
void USART3Handler              (void) __attribute__((weak, alias("DefaultHandler"), noreturn));
void EXTI15_10Handler           (void) __attribute__((weak, alias("DefaultHandler"), noreturn));
void RTCAlarmHandler            (void) __attribute__((weak, alias("DefaultHandler"), noreturn));
void OTGFSWkupHandler           (void) __attribute__((weak, alias("DefaultHandler"), noreturn));
void TIM8BrkTIM12Handler        (void) __attribute__((weak, alias("DefaultHandler"), noreturn));
void TIM8UpTIM13Handler         (void) __attribute__((weak, alias("DefaultHandler"), noreturn));
void TIM8TrgComTIM14Handler     (void) __attribute__((weak, alias("DefaultHandler"), noreturn));
void TIM8CCHandler              (void) __attribute__((weak, alias("DefaultHandler"), noreturn));
void DMA1Stream7Handler         (void) __attribute__((weak, alias("DefaultHandler"), noreturn));
void FSMCHandler                (void) __attribute__((weak, alias("DefaultHandler"), noreturn));
void SDIOHandler                (void) __attribute__((weak, alias("DefaultHandler"), noreturn));
void TIM5Handler                (void) __attribute__((weak, alias("DefaultHandler"), noreturn));
void SPI3Handler                (void) __attribute__((weak, alias("DefaultHandler"), noreturn));
void UART4Handler               (void) __attribute__((weak, alias("DefaultHandler"), noreturn));
void UART5Handler               (void) __attribute__((weak, alias("DefaultHandler"), noreturn));
void TIM6DACHandler             (void) __attribute__((weak, alias("DefaultHandler"), noreturn));
void TIM7Handler                (void) __attribute__((weak, alias("DefaultHandler"), noreturn));
void DMA2Stream0Handler         (void) __attribute__((weak, alias("DefaultHandler"), noreturn));
void DMA2Stream1Handler         (void) __attribute__((weak, alias("DefaultHandler"), noreturn));
void DMA2Stream2Handler         (void) __attribute__((weak, alias("DefaultHandler"), noreturn));
void DMA2Stream3Handler         (void) __attribute__((weak, alias("DefaultHandler"), noreturn));
void DMA2Stream4Handler         (void) __attribute__((weak, alias("DefaultHandler"), noreturn));
void ETHHandler                 (void) __attribute__((weak, alias("DefaultHandler"), noreturn));
void ETHWkupHandler             (void) __attribute__((weak, alias("DefaultHandler"), noreturn));
void CAN2TXHandler              (void) __attribute__((weak, alias("DefaultHandler"), noreturn));
void CAN2RX0Handler             (void) __attribute__((weak, alias("DefaultHandler"), noreturn));
void CAN2RX1Handler             (void) __attribute__((weak, alias("DefaultHandler"), noreturn));
void CAN2SCEHandler             (void) __attribute__((weak, alias("DefaultHandler"), noreturn));
void OTGFSHandler               (void) __attribute__((weak, alias("DefaultHandler"), noreturn));
void DMA2Stream5Handler         (void) __attribute__((weak, alias("DefaultHandler"), noreturn));
void DMA2Stream6Handler         (void) __attribute__((weak, alias("DefaultHandler"), noreturn));
void DMA2Stream7Handler         (void) __attribute__((weak, alias("DefaultHandler"), noreturn));
void USART6Handler              (void) __attribute__((weak, alias("DefaultHandler"), noreturn));
void I2C3EVHandler              (void) __attribute__((weak, alias("DefaultHandler"), noreturn));
void I2C3ERHandler              (void) __attribute__((weak, alias("DefaultHandler"), noreturn));
void OTGHSEp1OutHandler         (void) __attribute__((weak, alias("DefaultHandler"), noreturn));
void OTGHSEp1InHandler          (void) __attribute__((weak, alias("DefaultHandler"), noreturn));
void OTGHSWkupHandler           (void) __attribute__((weak, alias("DefaultHandler"), noreturn));
void OTGHSHandler               (void) __attribute__((weak, alias("DefaultHandler"), noreturn));
void DCMIHandler                (void) __attribute__((weak, alias("DefaultHandler"), noreturn));
void CRYPHandler                (void) __attribute__((weak, alias("DefaultHandler"), noreturn));
void HASHRngHandler             (void) __attribute__((weak, alias("DefaultHandler"), noreturn));
void FPUHandler                 (void) __attribute__((weak, alias("DefaultHandler"), noreturn));

void* pVectorTable[] __attribute__((section(".vector_table"))) = {
    (void *)STACK_START,
    &ResetHandler,
    &NMIHandler,
    &HardFaultHandler,
    &MemManageHandler,
    &BusFaultHandler,
    &UsageFaultHandler,
    NULL,
    NULL,
    NULL,
    NULL,
    &SVCallHandler,
    &DebugMonitorHandler,
    NULL,
    &PendSVHandler,
    &SysTickHandler,
    &WWDGHandler,
    &PVDHandler,
    &TampStampHandler,
    &RTCWkupHandler,
    &FlashHandler,
    &RCCHandler,
    &EXTI0Handler,
    &EXTI1Handler,
    &EXTI2Handler,
    &EXTI3Handler,
    &EXTI4Handler,
    &DMA1Stream0Handler,
    &DMA1Stream1Handler,
    &DMA1Stream2Handler,
    &DMA1Stream3Handler,
    &DMA1Stream4Handler,
    &DMA1Stream5Handler,
    &DMA1Stream6Handler,
    &ADCHandler,
    &CAN1TXHandler,
    &CAN1RX0Handler,
    &CAN1RX1Handler,
    &CAN1SCEHandler,
    &EXTI9_5Handler,
    &TIM1BrkTIM9Handler,
    &TIM1UpTIM10Handler,
    &TIM1TrgComTIM11Handler,
    &TIM1CCHandler,
    &TIM2Handler,
    &TIM3Handler,
    &TIM4Handler,
    &I2C1EVHandler,
    &I2C1ERHandler,
    &I2C2EVHandler,
    &I2C2ERHandler,
    &SPI1Handler,
    &SPI2Handler,
    &USART1Handler,
    &USART2Handler,
    &USART3Handler,
    &EXTI15_10Handler,
    &RTCAlarmHandler,
    &OTGFSWkupHandler,
    &TIM8BrkTIM12Handler,
    &TIM8UpTIM13Handler,
    &TIM8TrgComTIM14Handler,
    &TIM8CCHandler,
    &DMA1Stream7Handler,
    &FSMCHandler,
    &SDIOHandler,
    &TIM5Handler,
    &SPI3Handler,
    &UART4Handler,
    &UART5Handler,
    &TIM6DACHandler,
    &TIM7Handler,
    &DMA2Stream0Handler,
    &DMA2Stream1Handler,
    &DMA2Stream2Handler,
    &DMA2Stream3Handler,
    &DMA2Stream4Handler,
    &ETHHandler,
    &ETHWkupHandler,
    &CAN2TXHandler,
    &CAN2RX0Handler,
    &CAN2RX1Handler,
    &CAN2SCEHandler,
    &OTGFSHandler,
    &DMA2Stream5Handler,
    &DMA2Stream6Handler,
    &DMA2Stream7Handler,
    &USART6Handler,
    &I2C3EVHandler,
    &I2C3ERHandler,
    &OTGHSEp1OutHandler,
    &OTGHSEp1InHandler,
    &OTGHSWkupHandler,
    &OTGHSHandler,
    &DCMIHandler,
    &CRYPHandler,
    &HASHRngHandler,
    &FPUHandler,
};

void ResetHandler(void)
{
    uint32_t size = (uint32_t)&_edata - (uint32_t)&_sdata;
    uint32_t* pDst = (uint32_t *)&_sidata;
    uint32_t* pSrc = (uint32_t *)&_sdata;

    for (uint32_t i = 0; i < size; i++) {
        *pSrc++ = *pDst++;
    }

    size = (uint32_t)&_ebss - (uint32_t)&_sbss;
    pDst = (uint32_t *)&_sbss;
    for (uint32_t i = 0; i < size; i++) {
        *pDst++ = 0;
    }

    __libc_init_array();
    main(0, NULL);
}

void __attribute__((naked, noreturn)) DefaultHandler(void)
{
    while(1);
}
