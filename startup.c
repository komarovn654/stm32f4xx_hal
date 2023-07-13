#include "stdint.h"

#include "main.h"

/* Memory defines */
#define SRAM_START 0x20000000
#define SRAM_SIZE  (128 * 1024)
#define SRAM_END (SRAM_START + SRAM_SIZE)

#define STACK_START SRAM_END

/* Memory boundaries */
extern uint32_t* _sdata;
extern uint32_t* _edata;
extern uint32_t* _etext;
extern uint32_t* _sbss;
extern uint32_t* _ebss;

void DefaultHandler(void);

/* Vector table functions prototypes */
void ResetHandler               (void);
void NMIHandler                 (void) __attribute__((weak, alias("DefaultHandler")));
void HardFaultHandler           (void) __attribute__((weak, alias("DefaultHandler")));
void MemManageHandler           (void) __attribute__((weak, alias("DefaultHandler")));
void BusFaultHandler            (void) __attribute__((weak, alias("DefaultHandler")));
void UsageFaultHandler          (void) __attribute__((weak, alias("DefaultHandler")));
void SVCallHandler              (void) __attribute__((weak, alias("DefaultHandler")));
void DebugMonitorHandler        (void) __attribute__((weak, alias("DefaultHandler")));
void PendSVHandler              (void) __attribute__((weak, alias("DefaultHandler")));
void SysTickHandler             (void) __attribute__((weak, alias("DefaultHandler")));
void WWDGHandler                (void) __attribute__((weak, alias("DefaultHandler")));
void PVDHandler                 (void) __attribute__((weak, alias("DefaultHandler")));
void TampStampHandler           (void) __attribute__((weak, alias("DefaultHandler")));
void RTCWkupHandler             (void) __attribute__((weak, alias("DefaultHandler")));
void FlashHandler               (void) __attribute__((weak, alias("DefaultHandler")));
void RCCHandler                 (void) __attribute__((weak, alias("DefaultHandler")));
void EXTI0Handler               (void) __attribute__((weak, alias("DefaultHandler")));
void EXTI1Handler               (void) __attribute__((weak, alias("DefaultHandler")));
void EXTI2Handler               (void) __attribute__((weak, alias("DefaultHandler")));
void EXTI3Handler               (void) __attribute__((weak, alias("DefaultHandler")));
void EXTI4Handler               (void) __attribute__((weak, alias("DefaultHandler")));
void DMA1Stream0Handler         (void) __attribute__((weak, alias("DefaultHandler")));
void DMA1Stream1Handler         (void) __attribute__((weak, alias("DefaultHandler")));
void DMA1Stream2Handler         (void) __attribute__((weak, alias("DefaultHandler")));
void DMA1Stream3Handler         (void) __attribute__((weak, alias("DefaultHandler")));
void DMA1Stream4Handler         (void) __attribute__((weak, alias("DefaultHandler")));
void DMA1Stream5Handler         (void) __attribute__((weak, alias("DefaultHandler")));
void DMA1Stream6Handler         (void) __attribute__((weak, alias("DefaultHandler")));
void ADCHandler                 (void) __attribute__((weak, alias("DefaultHandler")));
void CAN1TXHandler              (void) __attribute__((weak, alias("DefaultHandler")));
void CAN1RX0Handler             (void) __attribute__((weak, alias("DefaultHandler")));
void CAN1RX1Handler             (void) __attribute__((weak, alias("DefaultHandler")));
void CAN1SCEHandler             (void) __attribute__((weak, alias("DefaultHandler")));
void EXTI9_5Handler             (void) __attribute__((weak, alias("DefaultHandler")));
void TIM1BrkTIM9Handler         (void) __attribute__((weak, alias("DefaultHandler")));
void TIM1UpTIM10Handler         (void) __attribute__((weak, alias("DefaultHandler")));
void TIM1TrgComTIM11Handler     (void) __attribute__((weak, alias("DefaultHandler")));
void TIM1CCHandler              (void) __attribute__((weak, alias("DefaultHandler")));
void TIM2Handler                (void) __attribute__((weak, alias("DefaultHandler")));
void TIM3Handler                (void) __attribute__((weak, alias("DefaultHandler")));
void TIM4Handler                (void) __attribute__((weak, alias("DefaultHandler")));
void I2C1EVHandler              (void) __attribute__((weak, alias("DefaultHandler")));
void I2C1ERHandler              (void) __attribute__((weak, alias("DefaultHandler")));
void I2C2EVHandler              (void) __attribute__((weak, alias("DefaultHandler")));
void I2C2ERHandler              (void) __attribute__((weak, alias("DefaultHandler")));
void SPI1Handler                (void) __attribute__((weak, alias("DefaultHandler")));
void SPI2Handler                (void) __attribute__((weak, alias("DefaultHandler")));
void USART1Handler              (void) __attribute__((weak, alias("DefaultHandler")));
void USART2Handler              (void) __attribute__((weak, alias("DefaultHandler")));
void USART3Handler              (void) __attribute__((weak, alias("DefaultHandler")));
void EXTI15_10Handler           (void) __attribute__((weak, alias("DefaultHandler")));
void RTCAlarmHandler            (void) __attribute__((weak, alias("DefaultHandler")));
void OTGFSWkupHandler           (void) __attribute__((weak, alias("DefaultHandler")));
void TIM8BrkTIM12Handler        (void) __attribute__((weak, alias("DefaultHandler")));
void TIM8UpTIM13Handler         (void) __attribute__((weak, alias("DefaultHandler")));
void TIM8TrgComTIM14Handler     (void) __attribute__((weak, alias("DefaultHandler")));
void TIM8CCHandler              (void) __attribute__((weak, alias("DefaultHandler")));
void DMA1Stream7Handler         (void) __attribute__((weak, alias("DefaultHandler")));
void FSMCHandler                (void) __attribute__((weak, alias("DefaultHandler")));
void SDIOHandler                (void) __attribute__((weak, alias("DefaultHandler")));
void TIM5Handler                (void) __attribute__((weak, alias("DefaultHandler")));
void SPI3Handler                (void) __attribute__((weak, alias("DefaultHandler")));
void UART4Handler               (void) __attribute__((weak, alias("DefaultHandler")));
void UART5Handler               (void) __attribute__((weak, alias("DefaultHandler")));
void TIM6DACHandler             (void) __attribute__((weak, alias("DefaultHandler")));
void TIM7Handler                (void) __attribute__((weak, alias("DefaultHandler")));
void DMA2Stream0Handler         (void) __attribute__((weak, alias("DefaultHandler")));
void DMA2Stream1Handler         (void) __attribute__((weak, alias("DefaultHandler")));
void DMA2Stream2Handler         (void) __attribute__((weak, alias("DefaultHandler")));
void DMA2Stream3Handler         (void) __attribute__((weak, alias("DefaultHandler")));
void DMA2Stream4Handler         (void) __attribute__((weak, alias("DefaultHandler")));
void ETHHandler                 (void) __attribute__((weak, alias("DefaultHandler")));
void ETHWkupHandler             (void) __attribute__((weak, alias("DefaultHandler")));
void CAN2TXHandler              (void) __attribute__((weak, alias("DefaultHandler")));
void CAN2RX0Handler             (void) __attribute__((weak, alias("DefaultHandler")));
void CAN2RX1Handler             (void) __attribute__((weak, alias("DefaultHandler")));
void CAN2SCEHandler             (void) __attribute__((weak, alias("DefaultHandler")));
void OTGFSHandler               (void) __attribute__((weak, alias("DefaultHandler")));
void DMA2Stream5Handler         (void) __attribute__((weak, alias("DefaultHandler")));
void DMA2Stream6Handler         (void) __attribute__((weak, alias("DefaultHandler")));
void DMA2Stream7Handler         (void) __attribute__((weak, alias("DefaultHandler")));
void USART6Handler              (void) __attribute__((weak, alias("DefaultHandler")));
void I2C3EVHandler              (void) __attribute__((weak, alias("DefaultHandler")));
void I2C3ERHandler              (void) __attribute__((weak, alias("DefaultHandler")));
void OTGHSEp1OutHandler         (void) __attribute__((weak, alias("DefaultHandler")));
void OTGHSEp1InHandler          (void) __attribute__((weak, alias("DefaultHandler")));
void OTGHSWkupHandler           (void) __attribute__((weak, alias("DefaultHandler")));
void OTGHSHandler               (void) __attribute__((weak, alias("DefaultHandler")));
void DCMIHandler                (void) __attribute__((weak, alias("DefaultHandler")));
void CRYPHandler                (void) __attribute__((weak, alias("DefaultHandler")));
void HASHRngHandler             (void) __attribute__((weak, alias("DefaultHandler")));
void FPUHandler                 (void) __attribute__((weak, alias("DefaultHandler")));

uint32_t pVectorTable[] __attribute__((section(".vector_table"))) = {
    STACK_START,
    (uint32_t)ResetHandler,
    (uint32_t)NMIHandler,
    (uint32_t)HardFaultHandler,
    (uint32_t)MemManageHandler,
    (uint32_t)BusFaultHandler,
    (uint32_t)UsageFaultHandler,
    (uint32_t)0,
    (uint32_t)0,
    (uint32_t)0,
    (uint32_t)0,
    (uint32_t)SVCallHandler,
    (uint32_t)DebugMonitorHandler,
    (uint32_t)0,
    (uint32_t)PendSVHandler,
    (uint32_t)SysTickHandler,
    (uint32_t)WWDGHandler,
    (uint32_t)PVDHandler,
    (uint32_t)TampStampHandler,
    (uint32_t)RTCWkupHandler,
    (uint32_t)FlashHandler,
    (uint32_t)RCCHandler,
    (uint32_t)EXTI0Handler,
    (uint32_t)EXTI1Handler,
    (uint32_t)EXTI2Handler,
    (uint32_t)EXTI3Handler,
    (uint32_t)EXTI4Handler,
    (uint32_t)DMA1Stream0Handler,
    (uint32_t)DMA1Stream1Handler,
    (uint32_t)DMA1Stream2Handler,
    (uint32_t)DMA1Stream3Handler,
    (uint32_t)DMA1Stream4Handler,
    (uint32_t)DMA1Stream5Handler,
    (uint32_t)DMA1Stream6Handler,
    (uint32_t)ADCHandler,
    (uint32_t)CAN1TXHandler,
    (uint32_t)CAN1RX0Handler,
    (uint32_t)CAN1RX1Handler,
    (uint32_t)CAN1SCEHandler,
    (uint32_t)EXTI9_5Handler,
    (uint32_t)TIM1BrkTIM9Handler,
    (uint32_t)TIM1UpTIM10Handler,
    (uint32_t)TIM1TrgComTIM11Handler,
    (uint32_t)TIM1CCHandler,
    (uint32_t)TIM2Handler,
    (uint32_t)TIM3Handler,
    (uint32_t)TIM4Handler,
    (uint32_t)I2C1EVHandler,
    (uint32_t)I2C1ERHandler,
    (uint32_t)I2C2EVHandler,
    (uint32_t)I2C2ERHandler,
    (uint32_t)SPI1Handler,
    (uint32_t)SPI2Handler,
    (uint32_t)USART1Handler,
    (uint32_t)USART2Handler,
    (uint32_t)USART3Handler,
    (uint32_t)EXTI15_10Handler,
    (uint32_t)RTCAlarmHandler,
    (uint32_t)OTGFSWkupHandler,
    (uint32_t)TIM8BrkTIM12Handler,
    (uint32_t)TIM8UpTIM13Handler,
    (uint32_t)TIM8TrgComTIM14Handler,
    (uint32_t)TIM8CCHandler,
    (uint32_t)DMA1Stream7Handler,
    (uint32_t)FSMCHandler,
    (uint32_t)SDIOHandler,
    (uint32_t)TIM5Handler,
    (uint32_t)SPI3Handler,
    (uint32_t)UART4Handler,
    (uint32_t)UART5Handler,
    (uint32_t)TIM6DACHandler,
    (uint32_t)TIM7Handler,
    (uint32_t)DMA2Stream0Handler,
    (uint32_t)DMA2Stream1Handler,
    (uint32_t)DMA2Stream2Handler,
    (uint32_t)DMA2Stream3Handler,
    (uint32_t)DMA2Stream4Handler,
    (uint32_t)ETHHandler,
    (uint32_t)ETHWkupHandler,
    (uint32_t)CAN2TXHandler,
    (uint32_t)CAN2RX0Handler,
    (uint32_t)CAN2RX1Handler,
    (uint32_t)CAN2SCEHandler,
    (uint32_t)OTGFSHandler,
    (uint32_t)DMA2Stream5Handler,
    (uint32_t)DMA2Stream6Handler,
    (uint32_t)DMA2Stream7Handler,
    (uint32_t)USART6Handler,
    (uint32_t)I2C3EVHandler,
    (uint32_t)I2C3ERHandler,
    (uint32_t)OTGHSEp1OutHandler,
    (uint32_t)OTGHSEp1InHandler,
    (uint32_t)OTGHSWkupHandler,
    (uint32_t)OTGHSHandler,
    (uint32_t)DCMIHandler,
    (uint32_t)CRYPHandler,
    (uint32_t)HASHRngHandler,
    (uint32_t)FPUHandler,
};

void ResetHandler(void)
{
    uint32_t size = (uint32_t *)&_edata - (uint32_t *)&_sdata;
    uint32_t* pDst = (uint32_t *)&_etext;
    uint32_t* pSrc = (uint32_t *)&_sdata;

    for (uint32_t i = 0; i < size; i++) {
        *pSrc++ = *pDst++;
    }

    size = (uint32_t)(&_ebss - &_sbss);
    pDst = (uint32_t *)&_sbss;
    for (uint32_t i = 0; i < size; i++) {
        *pDst++ = 0;
    }

    main();
}

void DefaultHandler(void)
{
    while(1);
}
