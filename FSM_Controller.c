

/**
 * main.c
 */
#include <mspm0l130x.h>
#include "Launchpad.h"
#include "SysTick.h"

// linked list at home
struct State {
    uint32_t output; // output led
    uint32_t delay; // amount of time in state
    const struct State *next_state[4]; // 3 possible next states based on inputs
};
typedef const struct State State_t; // lets us create state structures with the State_t initializer

// states
#define Zero       &FSM[0] // no coins inserted/0 cents
#define fivecents     &FSM[1]
#define tencents    &FSM[2]
#define fifteencents    &FSM[3]
#define twentycents    &FSM[4] // clown emoji

// dark --- 0 - Zero state
// red R-- 0x01 - 5 cents state
// blue --B 0x04 - 10 cents state
// green -G- 0x02 - 15 cents state
// yellow RG- 0x03 - 20 cents state
// sky blue -GB 0x06
// white RGB 0x07
// pink R-B 0x05

State_t FSM[5]={
 {0x0,225,{Zero,tencents,fivecents,Zero}}, // zero
 {RED,225,{fivecents,fifteencents,tencents,fivecents}}, // 5cents
 {BLUE,225,{tencents,twentycents,fifteencents,tencents}}, // 10 cents
 {GREEN,1750,{Zero,Zero,Zero,Zero}}, // 15 cents
 {YELLOW,1750,{fivecents,fivecents,fivecents,fivecents}} // 20 cents
};

// converts the input into a 2 bit vector
uint8_t transform_input(uint32_t input) {
    uint8_t leading = (input >> 3) & (0x02); // converts 00010010 to 00000010
    uint8_t trailing = input & 0x01; // converts 00010010 to 00000001
    volatile uint8_t final;
    final = leading | trailing;
    return final;
}

int main(void) {
    GPIOA_Init();
    SysTick_Init();
    State_t *curr_state;  // pointer to the current state
    uint32_t input;
    curr_state = Zero; // starts at Zero state
    volatile uint8_t temp;
    while(1) {
        //GPIOA_Output(0x0);
        GPIOA_Output(curr_state->output);
        SysTick_Wait1ms(curr_state->delay);
        temp = GPIOA_Input();
        input = transform_input(temp);
        curr_state = curr_state->next_state[input];
    }
}
