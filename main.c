#include <stdint.h>
#include <stdbool.h>
#include "inc/hw_memmap.h"
#include "driverlib/debug.h"
#include "driverlib/gpio.h"
#include "driverlib/sysctl.h"
#include "inc/tm4c123gh6pm.h"

PortFunctionInit(void)
{
//
        volatile uint32_t delay;
    // Enable the GPIO port that is used for the on-board LED.
    //
    SYSCTL_RCGC2_R = SYSCTL_RCGC2_GPIOF;

    //
    // Do a dummy read to insert a few cycles after enabling the peripheral.
    //
    delay = SYSCTL_RCGC2_R;

            GPIO_PORTF_LOCK_R = 0x4C4F434B;
            GPIO_PORTF_CR_R |= 0x01;
            GPIO_PORTF_DIR_R |= 0x04;
            GPIO_PORTF_DIR_R &= ~0x01;
            GPIO_PORTF_DEN_R |= 0x05;
            GPIO_PORTF_PUR_R |= 0x01;


 }
int main(void){
    PortFunctionInit();

        while(1)
        {
            if(GPIOPinRead(GPIO_PORTF_BASE,GPIO_PIN_0)==00){
                            GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_2,0x04);
                            SysCtlDelay(2000000);

                            GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_2,0x00);
                            SysCtlDelay(2000000);
            }
            else{
                GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_2,0x04);
}

 }
 }
