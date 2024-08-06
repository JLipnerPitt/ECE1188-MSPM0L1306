

/**
 * main.c
 */
#include <mspm0l130x.h>
#include "LaunchPad.h"
#include "SysTickInts.h"

volatile uint8_t semaphore;

void SysTick_Handler(void){
  uint8_t status = GPIOA_Input();
  switch(status) { // switches are negative logic on PA14 and PA18
       case 0x10: // SW1 pressed, red led at 8 Hz
         GPIOA_Output(0);
         SysTick->LOAD = 4000000;
         GPIOA->DOUTTGL31_0 = 1<<0;
         break;
       case 0x01: // SW2 pressed, green led at 64 Hz
           GPIOA_LED(0);
           SysTick->LOAD = 500000;
           GPIOA->DOUTTGL31_0 = 1<<13;
         break;
       case 0x00: // both switches pressed, both leds flash at their respective frequencies
           SysTick->LOAD = 500000;
           if (semaphore < 8) {
               GPIOA->DOUTTGL31_0 = 1<<13;
           }
           else {
               GPIOA->DOUTTGL31_0 = 1<<0 | 1<<13;
               semaphore = 0;
           }
           semaphore++;
         break;
       default: // neither switch pressed, no light
           GPIOA_Output(0);
           GPIOA_LED(0);
           semaphore = 0;
  }
  SysTick->VAL = 0;
}

int main(void) {
    GPIOA_Init();
    SysTick_Init(4000000,2);  // set up SysTick for 8 Hz interrupts

    while(1) {
        uint32_t i, j, temp, length;
        uint32_t a[100]={5000,5308,5614,5918,6219,6514,
        6804,7086,7361,7626,7880,8123,8354,8572,8776,8964,9137,
        9294,9434,9556,9660,9746,9813,9861,9890,9900,9890,9861,
        9813,9746,9660,9556,9434,9294,9137,8964,8776,8572,8354,
        8123,7880,7626, 7361,7086,6804,6514,6219,5918,5614,
        5308,5000,4692,4386,4082,3781,3486,3196,2914,2639,2374,
        2120,1877,1646,1428,1224,1036,863,706,566,444,340,254,
        187,139,110,100,110,139,187,254,340,444,566,706,863,
        1036, 1224, 1428, 1646,1877,2120,2374,2639,2914,
        3196,3486,3781,4082,4386,4692};
        length = 100;

        for (i = 0; i < length; i++) {
            for (j = 0; j < length - i - 1; j++) {
                 if (a[j + 1] < a[j]) {
                     temp = a[j];
                     a[j] = a[j + 1];
                     a[j + 1] = temp;
                 }
            }
        }
    }
}
