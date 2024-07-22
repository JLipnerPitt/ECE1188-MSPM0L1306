#ifndef LAUNCHPAD
#define LAUNCHPAD

#include <stdint.h>

void GPIOA_Init(void);
uint8_t GPIOA_Input(void);
void GPIOA_LED(uint8_t);
void GPIOA_Output(uint32_t);

#endif
