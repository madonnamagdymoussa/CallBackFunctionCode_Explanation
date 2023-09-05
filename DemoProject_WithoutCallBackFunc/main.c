

#include "Led.h"
#include "GPTM.h"
#include "GPTM_config.h"
#include "Button.h"

void GPTM_WideSubTimer0A_Handler(void){
    GPTM_WideSubTimerA_ClearInterrupt();
    Leds_ToggleRedLed();

}

int main(void)
{
    __asm("  CPSIE  I");
    Led_InitializeAllLeds();
    ButtonInitializations();

    while(1){



    }
}
