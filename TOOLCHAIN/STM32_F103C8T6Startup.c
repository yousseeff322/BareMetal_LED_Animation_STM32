#include "STD_type.h"

void main (void) ; 
#define SRAM_START   0x20000000U
#define SRAM_SIZE    (20*1024)
#define SRAM_END     ( (SRAM_START) + (SRAM_SIZE) ) 
#define STACK_START  (SRAM_END)

extern u32 _etext; 
extern u32 _sdata; 
extern u32 _edata; 
extern u32 _sbss; 
extern u32 _ebss; 

void Reset_Handler (void) ; 

void Reset_Handler (void) {
	
/* copy .data section from flash to SRAM*/
	u32 Size = (u32)&_edata - (u32)&_sdata ;
	u8* SrcPtr = (u8*)&_etext ; 		/*start of data section on flash */
	u8* DesPtr = (u8*)&_sdata ; 		/*start of data section on SRAM */
	u32 u8Counter ; 
	
	for (u8Counter = 0 ; u8Counter < Size ; u8Counter++)
	{
		*DesPtr = *SrcPtr ; 
		DesPtr++ ; 
		SrcPtr++ ; 
	}
	
/* initial .bss section in SRAM to zero */ 

	 Size = (u32)&_ebss - (u32)&_sbss ;
     DesPtr = (u8*)&_sbss ; 
	
		for (u8Counter = 0 ; u8Counter < Size ; u8Counter++)
	{
		*DesPtr = 0U ; 
		 DesPtr++ ; 
	}
	
	
/* (option) Call init function of standard library */ 

/* call main */ 
	main(); 	
	
	while(1) ;
}




void Default_Handler (void) 
{
	while(1) ; 
}


void NMI_Handler				 (void) __attribute__((weak,alias("Default_Handler")));
void HardFault_Handler			 (void) __attribute__((weak,alias("Default_Handler")));
void MemManage_Handler			 (void) __attribute__((weak,alias("Default_Handler")));
void BusFault_Handler			 (void) __attribute__((weak,alias("Default_Handler")));
void UsageFault_Handler			 (void) __attribute__((weak,alias("Default_Handler")));
void SVC_Handler				 (void) __attribute__((weak,alias("Default_Handler")));
void DebugMon_Handler			 (void) __attribute__((weak,alias("Default_Handler")));
void PendSV_Handler				 (void) __attribute__((weak,alias("Default_Handler")));
void SysTick_Handler			 (void) __attribute__((weak,alias("Default_Handler")));
void WWDG_IRQHandler      		 (void) __attribute__((weak,alias("Default_Handler")));
void PVD_IRQHandler       		 (void) __attribute__((weak,alias("Default_Handler")));
void TAMPER_IRQHandler			 (void) __attribute__((weak,alias("Default_Handler")));
void RTC_IRQHandler  			 (void) __attribute__((weak,alias("Default_Handler")));
void FLASH_IRQHandler     		 (void) __attribute__((weak,alias("Default_Handler")));
void RCC_IRQHandler       		 (void) __attribute__((weak,alias("Default_Handler")));
void EXTI0_IRQHandler     		 (void) __attribute__((weak,alias("Default_Handler")));
void EXTI1_IRQHandler     		 (void) __attribute__((weak,alias("Default_Handler")));
void EXTI2_IRQHandler     		 (void) __attribute__((weak,alias("Default_Handler")));
void EXTI3_IRQHandler     		 (void) __attribute__((weak,alias("Default_Handler")));
void EXTI4_IRQHandler     		 (void) __attribute__((weak,alias("Default_Handler")));
void DMA1_Channel1_IRQHandler    (void) __attribute__((weak,alias("Default_Handler")));
void DMA1_Channel2_IRQHandler    (void) __attribute__((weak,alias("Default_Handler")));
void DMA1_Channel3_IRQHandler    (void) __attribute__((weak,alias("Default_Handler")));
void DMA1_Channel4_IRQHandler    (void) __attribute__((weak,alias("Default_Handler")));
void DMA1_Channel5_IRQHandler    (void) __attribute__((weak,alias("Default_Handler")));
void DMA1_Channel6_IRQHandler    (void) __attribute__((weak,alias("Default_Handler")));
void DMA1_Channel7_IRQHandler    (void) __attribute__((weak,alias("Default_Handler")));
void ADC1_2_IRQHandler           (void) __attribute__((weak,alias("Default_Handler")));
void USB_HP_CAN1_TX_IRQHandler   (void) __attribute__((weak,alias("Default_Handler")));
void USB_LP_CAN1_RX0_IRQHandler  (void) __attribute__((weak,alias("Default_Handler")));
void CAN1_RX1_IRQHandler         (void) __attribute__((weak,alias("Default_Handler")));
void CAN1_SCE_IRQHandler         (void) __attribute__((weak,alias("Default_Handler")));
void EXTI9_5_IRQHandler          (void) __attribute__((weak,alias("Default_Handler")));
void TIM1_BRK_IRQHandler         (void) __attribute__((weak,alias("Default_Handler")));
void TIM1_UP_IRQHandler          (void) __attribute__((weak,alias("Default_Handler")));
void TIM1_TRG_COM_IRQHandler     (void) __attribute__((weak,alias("Default_Handler")));
void TIM1_CC_IRQHandler          (void) __attribute__((weak,alias("Default_Handler")));
void TIM2_IRQHandler             (void) __attribute__((weak,alias("Default_Handler")));
void TIM3_IRQHandler             (void) __attribute__((weak,alias("Default_Handler")));
void TIM4_IRQHandler             (void) __attribute__((weak,alias("Default_Handler")));
void I2C1_EV_IRQHandler          (void) __attribute__((weak,alias("Default_Handler")));
void I2C1_ER_IRQHandler          (void) __attribute__((weak,alias("Default_Handler")));
void I2C2_EV_IRQHandler          (void) __attribute__((weak,alias("Default_Handler")));
void I2C2_ER_IRQHandler          (void) __attribute__((weak,alias("Default_Handler")));
void SPI1_IRQHandler             (void) __attribute__((weak,alias("Default_Handler")));
void SPI2_IRQHandler             (void) __attribute__((weak,alias("Default_Handler")));
void USART1_IRQHandler           (void) __attribute__((weak,alias("Default_Handler")));
void USART2_IRQHandler           (void) __attribute__((weak,alias("Default_Handler")));
void USART3_IRQHandler           (void) __attribute__((weak,alias("Default_Handler")));
void EXTI15_10_IRQHandler        (void) __attribute__((weak,alias("Default_Handler")));
void RTC_Alarm_IRQHandler        (void) __attribute__((weak,alias("Default_Handler")));
void USBWakeUp_IRQHandler        (void) __attribute__((weak,alias("Default_Handler")));


u32 Vectors[] __attribute__((section(".isr_vector"))) =
{
    STACK_START,             // Initial Stack Pointer
    (u32)Reset_Handler,      // Reset Handler
    (u32)NMI_Handler,        // NMI Handler
    (u32)HardFault_Handler,  // Hard Fault Handler
    (u32)MemManage_Handler,  // Memory Management Fault Handler
    (u32)BusFault_Handler,   // Bus Fault Handler
    (u32)UsageFault_Handler, // Usage Fault Handler
    0, 0, 0, 0,              // Reserved
    (u32)SVC_Handler,        // SVCall Handler
    (u32)DebugMon_Handler,   // Debug Monitor Handler
    0,                       // Reserved
    (u32)PendSV_Handler,     // PendSV Handler
    (u32)SysTick_Handler,    // SysTick Handler
    (u32)WWDG_IRQHandler,    // Window Watchdog Interrupt
    (u32)PVD_IRQHandler,     // PVD through EXTI Line detect
    (u32)TAMPER_IRQHandler,  // Tamper interrupt
    (u32)RTC_IRQHandler,     // RTC global interrupt
    (u32)FLASH_IRQHandler,   // Flash global interrupt
    (u32)RCC_IRQHandler,     // RCC global interrupt
    (u32)EXTI0_IRQHandler,   // EXTI Line 0 interrupt
    (u32)EXTI1_IRQHandler,   // EXTI Line 1 interrupt
    (u32)EXTI2_IRQHandler,   // EXTI Line 2 interrupt
    (u32)EXTI3_IRQHandler,   // EXTI Line 3 interrupt
    (u32)EXTI4_IRQHandler,   // EXTI Line 4 interrupt
    (u32)DMA1_Channel1_IRQHandler,  // DMA1 Channel 1 global interrupt
    (u32)DMA1_Channel2_IRQHandler,  // DMA1 Channel 2 global interrupt
    (u32)DMA1_Channel3_IRQHandler,  // DMA1 Channel 3 global interrupt
    (u32)DMA1_Channel4_IRQHandler,  // DMA1 Channel 4 global interrupt
    (u32)DMA1_Channel5_IRQHandler,  // DMA1 Channel 5 global interrupt
    (u32)DMA1_Channel6_IRQHandler,  // DMA1 Channel 6 global interrupt
    (u32)DMA1_Channel7_IRQHandler,  // DMA1 Channel 7 global interrupt
    (u32)ADC1_2_IRQHandler,         // ADC1 and ADC2 global interrupt
    (u32)USB_HP_CAN1_TX_IRQHandler, // USB High Priority or CAN1 TX interrupts
    (u32)USB_LP_CAN1_RX0_IRQHandler,// USB Low Priority or CAN1 RX0 interrupts
    (u32)CAN1_RX1_IRQHandler,       // CAN1 RX1 interrupt
    (u32)CAN1_SCE_IRQHandler,       // CAN1 SCE interrupt
    (u32)EXTI9_5_IRQHandler,        // External Line[9:5] interrupts
    (u32)TIM1_BRK_IRQHandler,       // TIM1 Break interrupt
    (u32)TIM1_UP_IRQHandler,        // TIM1 Update interrupt
    (u32)TIM1_TRG_COM_IRQHandler,   // TIM1 Trigger and Commutation interrupts
    (u32)TIM1_CC_IRQHandler,        // TIM1 Capture Compare interrupt
    (u32)TIM2_IRQHandler,           // TIM2 global interrupt
    (u32)TIM3_IRQHandler,           // TIM3 global interrupt
    (u32)TIM4_IRQHandler,           // TIM4 global interrupt
    (u32)I2C1_EV_IRQHandler,        // I2C1 Event interrupt
    (u32)I2C1_ER_IRQHandler,        // I2C1 Error interrupt
    (u32)I2C2_EV_IRQHandler,        // I2C2 Event interrupt
    (u32)I2C2_ER_IRQHandler,        // I2C2 Error interrupt
    (u32)SPI1_IRQHandler,           // SPI1 global interrupt
    (u32)SPI2_IRQHandler,           // SPI2 global interrupt
    (u32)USART1_IRQHandler,         // USART1 global interrupt
    (u32)USART2_IRQHandler,         // USART2 global interrupt
    (u32)USART3_IRQHandler,         // USART3 global interrupt
    (u32)EXTI15_10_IRQHandler,      // External Line[15:10] interrupts
    (u32)RTC_Alarm_IRQHandler,      // RTC Alarm through EXTI Line interrupt
    (u32)USBWakeUp_IRQHandler       // USB WakeUp from suspend through EXTI Line interrupt
};
