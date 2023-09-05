#include "GPIO.h"
#include "GPIO_config.h"
#include "GPTM.h"
#include "GPTM_config.h"
#include "lstd.h"

u8_t Button1_PressedFlag=0;
u8_t Button2_PressedFlag=0;
u8_t RedLedState=0;


void EXTIFIntHandler(void){
    GPIO_EXTIClearInterrupt(PortF, Channel_4);
    GPIO_ToggleBitBandBits(Channel_2,PortF );

}

/*void Application_PortFCallBackFunc(void){

    GPIO_EXTIClearInterrupt(PortF, Channel_4);
    GPIO_ToggleBitBandBits(Channel_2,PortF );
}*/




void ButtonInitializations(void){
    GPIO_ConfigureInputPin(&GPIO_ConfigurePin_PF0);
    GPIO_ConfigureInputPin(&GPIO_ConfigurePin_PF4);

    GPIO_ConfigureInterruptSource(FallingEdge,PortF, Channel_4 );
    //RegisterCallbackFunction(PortF, Application_PortFCallBackFunc);
}

void ReadButtonState(void){

        /**********************Check for button 1**********************/
            if( 0 == GPIO_ReadBitBandBits(Channel_4,PortF) ){

                 GPTM_GenerateDelay(GPTM_Config_ArrPtrStruct[0], 170, milli_Sec);

                     if(0 == GPIO_ReadBitBandBits(Channel_4,PortF) ){
                     Button1_PressedFlag=1;
                     GPTM_GenerateDelay(GPTM_Config_ArrPtrStruct[0], 50, milli_Sec);
                 }

            }

            else{
                Button1_PressedFlag=0;
            }

            /**********************Check for button 2**********************/
            if( 0 == GPIO_ReadBitBandBits(Channel_0,PortF) ){

                 GPTM_GenerateDelay(GPTM_Config_ArrPtrStruct[0], 150, milli_Sec);


                 if(0 == GPIO_ReadBitBandBits(Channel_0,PortF) ){
                     Button2_PressedFlag=1;

                     GPTM_GenerateDelay(GPTM_Config_ArrPtrStruct[0], 50, milli_Sec);
                 }

             }
            else{
                 Button2_PressedFlag=0;
             }

            GPTM_GenerateDelay(GPTM_Config_ArrPtrStruct[0], 50, milli_Sec);
}



