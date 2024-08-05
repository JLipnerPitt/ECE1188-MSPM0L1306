#ifndef MOTOR_SIMPLE
#define MOTOR_SIMPLE

#include <stdint.h>

void Motor_InitSimple(void);
void Motor_StopSimple(void);
void Motor_ForwardSimple(uint16_t, uint32_t);
void Motor_BackwardSimple(uint16_t, uint32_t);
void Motor_LeftSimple(uint16_t, uint32_t);
void Motor_RightSimple(uint16_t, uint32_t);

#endif
