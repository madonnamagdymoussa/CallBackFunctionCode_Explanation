

#include "Led.h"
#include "Button.h"
int main(void)
{
    __asm("  CPSIE  I");
    Led_InitializeAllLeds();
    ButtonInitializations();

    while(1){



    }
}
