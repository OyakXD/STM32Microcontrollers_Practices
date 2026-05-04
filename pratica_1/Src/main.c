/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Oyaklek - alveskayo2005@gmail.com
 * @brief          : Main program body
 ******************************************************************************
 * @attention
 *
 * Copyright (c) 2026 STMicroelectronics.
 * All rights reserved.
 *
 * This software is licensed under terms that can be found in the LICENSE file
 * in the root directory of this software component.
 * If no LICENSE file comes with this software, it is provided AS-IS.
 *
 ******************************************************************************
 */

#include "stm32f1xx.h"

int main(void) {

	/* Clocks GPIOs */
	RCC->APB2ENR |= (1 << 4);
	RCC->APB2ENR |= (1 << 3);
	RCC->APB2ENR |= (1 << 2);
	/* --------------------- */

	/*input with pull-up / pull-down */
	GPIOA->CRH &= 0xFFFFF000;
	GPIOA->CRH |= 0x00000888;
	/*----------------------- */
	/* pull-up */
	GPIOA->ODR |= (1 << 8) | (1 << 9) | (1 << 10);

	/* output led_int */
	GPIOC->CRH &= 0xFF0FFFFF;
	GPIOC->CRH |= 0x00200000;
	/* ------------------------ */

	/* output led PB8 & PB9 */
	GPIOB->CRH &= 0xFFFFF000;
	GPIOB->CRH |= 0x00000222;
	/* ------------------------ */

	/* turn off led initials */
	GPIOC->BSRR = (1 << 13);
	GPIOB->BRR = (1 << 8) | (1 << 9);
	/* --------------------- */

	while(1) {

		if(GPIOA->IDR & (1 << 8)){
			GPIOC->BSRR = (1 << 13);
		} else {
			GPIOC->BRR = (1 << 13);
		}


		if(GPIOA->IDR & (1 << 9)) {
			GPIOB->BRR = (1 << 8);
		} else {
			GPIOB->BSRR = (1 << 8);
		}


		if (GPIOA->IDR & (1 << 10)) {
			GPIOB->BRR = (1 << 9);
		} else {
			GPIOB->BSRR = (1 << 9);
		}
	}
}
