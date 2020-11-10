/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Auto-generated by STM32CubeIDE
 * @brief          : Main program body
 ******************************************************************************
 * @attention
 *
 * <h2><center>&copy; Copyright (c) 2020 STMicroelectronics.
 * All rights reserved.</center></h2>
 *
 * This software component is licensed by ST under BSD 3-Clause license,
 * the "License"; You may not use this file except in compliance with the
 * License. You may obtain a copy of the License at:
 *                        opensource.org/licenses/BSD-3-Clause
 *
 ******************************************************************************
 */
#include <stdint.h>

int main(void)
{
/*These are pointers pointing to the respective peripheral memory-addresses(address + offset) needed for  our
 * small project, i.e to light our LED on the stm32f407vet black board, this code should work on your discovery or nucleo board.
 * this is not the most efficient and professional to get our task done. But a peep on how bit-wise operations are relevant in
 * embedded systems, we'll use bitwise-shift operations next time.
 */
	uint32_t *pAddress_RCC = (uint32_t*)0x40023830;
	uint32_t *pAddress_GPIOC_portModeReg = (uint32_t*)0x40020800;
	uint32_t *pAddress_GPIOC_portOutputReg = (uint32_t*)0x40020814;

//	enabling the clock for GPIO port C
/*This is actually de-referencing the the pointer(pAddress_RCC), so we can write b0100(Hex: 0x04) to the pAddress_RCC register
 * with this we'll succeed in "setting" the 2nd bit-position high, thus enabling portC 's clock.
 */
	*pAddress_RCC |= 0x04;

// clearing the port mode register
/*Here we use a mask value, to clear the bit-postions needed in the register for our project. This register (pAddress_GPIOC_portModeReg)
 * handles the mode of the gpio pin(output, input, analog..). Since we want an output mode, we first clear the required bit-positions
 * needed(1:0), so with the mask value, we zero out the 0th and 1st bit positions in the register.
 */
	*pAddress_GPIOC_portModeReg &=  0xFFFFFFFC;

// setting the port mode register
/*We set our pin as an output here by writing (01) to the 1st and 0th bit-positions in the register(pAddress_GPIOC_portModeReg).
 * Quick note: stm32f4 mcu has 32bit registers
 */
	*pAddress_GPIOC_portModeReg |= 0x00000001;

//	setting pin 0 of port C high
/*we are just setting PC0 on the board high
 *
 */
	*pAddress_GPIOC_portOutputReg |= 0x01;

    /* Loop forever */
	while(1);
}
