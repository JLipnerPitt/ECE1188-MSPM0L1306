/*
 * Copyright (c) 2021, Texas Instruments Incorporated
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * *  Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 *
 * *  Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * *  Neither the name of Texas Instruments Incorporated nor the names of
 *    its contributors may be used to endorse or promote products derived
 *    from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
 * THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;
 * OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR
 * OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
 * EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#include <mspm0l130x.h>

// dark --- 0 - Zero state
// red R-- 0x01 - 5 cents state
// blue --B 0x04 - 10 cents state
// green -G- 0x02 - 15 cents state
// yellow RG- 0x03 - 20 cents state
// sky blue -GB 0x06
// white RGB 0x07
// pink R-B 0x05

void GPIOA_Init(void) {
    // configuring LEDs
    GPIOA->GPRCM.PWREN = (0x26000000 | 0x01); // Enables Power for GPIOA Register
    GPIOA->DOE31_0 |= (1<<0) | (1<<13) | (1<<26) | (1<<27); // Enables PA27, PA26, PA13, PA0 as output

    // (1<<0) - See page 735 of the technical reference manual.
    // (1<<7) - Connects peripheral. Writing 1 makes the output latch of the dataflow “transparent”.
    IOMUX->SECCFG.PINCM[0] |= (1<<0) | (1<<7) | (1<<26); // see datasheet for why this pin is inverted with (1<<26)
    IOMUX->SECCFG.PINCM[13] |= (1<<0) | (1<<7);
    IOMUX->SECCFG.PINCM[26] |= (1<<0) | (1<<7);
    IOMUX->SECCFG.PINCM[27] |= (1<<0) | (1<<7);

    // configuring input switches

    // PA18, Switch 1
    // (1<<0) - See page 735 of the technical reference manual.
    // (1<<7) - Connects peripheral. Writing 1 makes the output latch of the dataflow “transparent”.
    // (1<<18) - Input Enable Control Selection. Writing 1 enables as input.
    // (1<<26) - Data inversion selection. Writing 1 enables data inversion.
    // See page 16 in the datasheet. Switch 1 is already inherently configured as Pull-down.
    IOMUX->SECCFG.PINCM[18] |= (1<<0) | (1<<7) | (1<<18) | (1<<26);


    // PA14, Switch 2
    // (1<<0) - See Page 735 of the technical reference manual.
    // (1<<7) - Connects peripheral. Writing 1 makes the output latch of the dataflow “transparent”.
    // (1<<17) - Pull Up control selection. Writing 1 configures as pull-up.
    // (1<<18) - Input Enable Control Selection. Writing 1 enables as input.
    IOMUX->SECCFG.PINCM[14] |= (1<<0) | (1<<7) | (1<<17) | (1<<18);
}

void GPIOA_LED(uint8_t data) {
    // PA0 = red led
    GPIOA->DOUT3_0 = (GPIOA->DOUT3_0 & 0xE) | data;
}

void GPIOA_Output(uint32_t data) {
    // PA27 = blue led, PA26 = red led, PA13 = green led
    GPIOA->DOUT31_0 = (GPIOA->DOUT31_0 & 0x3FFDFFF) | data;
}

uint8_t GPIOA_Input(void) {
    return (GPIOA->DIN19_16 >> 12) | (GPIOA->DIN15_12 >> 16); // reads PA18 and PA14
}
