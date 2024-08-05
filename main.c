

/**
 * main.c
 */
#include <mspm0l130x.h>
#include "Motor_Simple.h"
#include "SysTick.h"

int main(void)
{
    //LaunchPad_Init(); // built-in switches and LEDs
    //Bump_Init();      // bump switches
    SysTick_Init();
    Motor_InitSimple();     // initializes motor drivers
    while (1) {
        Motor_ForwardSimple(1250,250);
        //Motor_BackwardSimple(1250,250);
        //Motor_LeftSimple(1250,250);
        //Motor_RightSimple(1250,250);
    }
}
