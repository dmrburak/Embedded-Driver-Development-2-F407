/*
 * msp.c
 *
 *  Created on: Nov 8, 2025
 *      Author: burak
 */

#include "main.h"

void HAL_MspInit(void)
{

	//1. Set up the priority grouping of the arm cortex mx processor
	HAL_NVIC_SetPriorityGrouping(NVIC_PRIORITYGROUP_4);

	//2. Enable the required system exceptions of the arm cortex mx processor
	SCB->SHCSR |= (0x7 << 16); // usage fault, memory fault and bus fault system exceptions

	//3. Configure the priority for the system exceptions
	HAL_NVIC_SetPriority(MemoryManagement_IRQn, 0, 0);
	HAL_NVIC_SetPriority(BusFault_IRQn, 0, 0);
	HAL_NVIC_SetPriority(UsageFault_IRQn, 0, 0);

}


void HAL_TIM_Base_MspInit(TIM_HandleTypeDef *htim)
{
	//1.enable the clock for the TIM6 peripheral
	__HAL_RCC_TIM6_CLK_ENABLE();

	//2.enable the IRQ of TIM2
	HAL_NVIC_EnableIRQ(TIM6_DAC_IRQn);

	//3.setup the priority for TIM6_DAC_IRQn
	HAL_NVIC_SetPriority(TIM6_DAC_IRQn, 15, 0);//subpriority is zero because we're using NVIC_PRIORITYGROUP_4
}
