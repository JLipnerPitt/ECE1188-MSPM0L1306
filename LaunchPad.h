#ifndef LAUNCHPAD
#define LAUNCHPAD

#include <stdint.h>

#define RED       0x4000000
#define GREEN     0x2000
#define BLUE      0x8000000
#define YELLOW    0x4002000
#define AQUA      0x8002000
#define WHITE     0xC020000
#define PURPLE    0xC000000

void GPIOA_Init(void);
uint8_t GPIOA_Input(void);
void GPIOA_LED(uint8_t);
void GPIOA_Output(uint32_t);

#endif
