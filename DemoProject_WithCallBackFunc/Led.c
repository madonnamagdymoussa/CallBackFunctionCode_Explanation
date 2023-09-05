#include "GPTM_config.h"
#include "GPTM.h"
#include "GPIO_config.h"
#include "GPIO.h"
#include "Led.h"

void CallBack_GPTM(void){
       GPTM_WideSubTimerA_ClearInterrupt();
       GPIO_ToggleBitBandBits(Channel_1,PortF );
    }

void Led_InitializeAllLeds(){

    GPIO_ConfigureOutputPin(&GPIO_ConfigurePin_PF2);
    GPIO_ConfigureOutputPin(&GPIO_ConfigurePin_PF1);
    GPIO_ConfigureOutputPin(&GPIO_ConfigurePin_PF3);

    /*Initialize the GPTM as it will be used in blinking the led */
    GPTM_InitializeDelayMode(GPIO_TimerAFSELConfig_ArrPtrStruct[0], GPTM_Config_ArrPtrStruct[0]);
    GPTM_GenerateDelay_Interrupt(GPTM_Config_ArrPtrStruct[0], 100, milli_Sec);

    GPTM_RegisterCallbackFunction(CallBack_GPTM);

}

void Leds_ToggleRedLed(void){
    GPIO_ToggleBitBandBits(Channel_1,PortF );

}


