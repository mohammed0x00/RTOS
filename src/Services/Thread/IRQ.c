/*
 * IRQ.c
 *
 *  Created on: Feb 11, 2022
 *      Author: Mohammed Ali
 */

/* Includes */
#include "STD_Types.h"
#include "Bit_Math.h"

#include "MCAL/Core/Core_interface.h"
#include "MCAL/SysTick/SysTick_interface.h"
#include "HAL/Interrupts/Interrupts_interface.h"

#include "OSConfig.h"
#include "Thread.h"
#include "IdleThread.h"
#include "priv.h"

/* Private typedef */
/* Private define  */
/* Private macro */
/* Private variables */
/* Private function prototypes */
/* Private functions */

void PendSV_Handler(void)
{
	__disable_irq();
	if (OS_curr != (OSThread *)0)
	{
		pushR4toR11();
		OS_curr->sp = getSP();
	}
	OS_curr = OS_next;
	setSP(OS_curr->sp);
	popR4toR11();
	__enable_irq();
	__BXLR();
}

void SysTick_Handler(void)
{
	static u8 schedTicks = 0;
	OS_tick();

	if(schedTicks >= OS_CFG_SHEDTICKS)
	{
		schedTicks = 0;
		__disable_irq();
		OS_scheduler();
		__enable_irq();
	}
	else
	{
		schedTicks++;
	}
}
