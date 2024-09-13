#include "STD_type.h"
#include "BIT_MATH.h"

#include "DIO_interface.h"
#include "RCC_interface.h"
#include "SYSTICK_interface.h"

void main(void) {

    // Initialize system and peripherals
    MRCC_VidInit();
    MRCC_VidEnablePeripheralClock(RCC_APB2, GPIOA_RCC);
    // Set pin directions
    MGPIO_VidSetPinDirection(GPIOA, PIN0, OUT_SPEED_2MHZ_PP);     // LED
    MGPIO_VidSetPinDirection(GPIOA, PIN1, OUT_SPEED_2MHZ_PP);     // LED
    MGPIO_VidSetPinDirection(GPIOA, PIN2, OUT_SPEED_2MHZ_PP);     // LED
    MGPIO_VidSetPinDirection(GPIOA, PIN3, OUT_SPEED_2MHZ_PP);     // LED
    MGPIO_VidSetPinDirection(GPIOA, PIN4, OUT_SPEED_2MHZ_PP);     // LED
    MGPIO_VidSetPinDirection(GPIOA, PIN5, OUT_SPEED_2MHZ_PP);     // LED
    MGPIO_VidSetPinDirection(GPIOA, PIN6, OUT_SPEED_2MHZ_PP);     // LED
    MGPIO_VidSetPinDirection(GPIOA, PIN7, OUT_SPEED_2MHZ_PP);     // LED


    MSTK_voidInit();


   while (1) {
        // Forward direction (from PA0 to PA7)
        for (u8 i = 0; i < 8; i++) {
            MGPIO_VidSetPinValue(GPIOA, i, HIGH);
            MSTK_voidSetBusyWait(200000);  
            
            MGPIO_VidSetPinValue(GPIOA, i, LOW);
        }

        // Backward direction (from PA7 to PA0)
        for (u8 i = 7; i > 0; i--) {
            MGPIO_VidSetPinValue(GPIOA, i, HIGH);
            MSTK_voidSetBusyWait(200000);  
            
            MGPIO_VidSetPinValue(GPIOA, i, LOW);
        }
    }
        }





