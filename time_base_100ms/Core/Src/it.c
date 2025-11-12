/*
 * it.c
 *
 *  Created on: Nov 8, 2025
 *      Author: burak
 */

#include "main.h"

void SysTick_Handler(void)
{
	HAL_IncTick();
	HAL_SYSTICK_IRQHandler();
}
