/*
 * Thread.c
 *
 *  Created on: Feb 8, 2022
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

/**
**===========================================================================
**
**  Abstract: Threads Management
**
**===========================================================================
*/

void OSThread_Delay(u32 ticks)
{
    __disable_irq();
    /* never call OS_delay from the idleThread */
    if(OS_curr != OS_thread[0])
    {
		OS_curr->timeout = ticks;
		OS_readySet &= ~OS_currThreadMask;
		OS_delayedSet |= OS_currThreadMask;
		OS_scheduler();
    }
    __enable_irq();
}

void OSThread_Yield(void)
{
    __disable_irq();
    OS_scheduler();
    __enable_irq();
}

void OSThread_Suspend(OSThread_Ctrl thread) {
	__disable_irq();
	/* never call OS_Suspend from the idleThread */
	if(OS_curr != OS_thread[0])
	{
		if(thread == OS_CURRENT_THREAD_CTRL)
		{
			OS_readySet &= ~OS_currThreadMask;
			OS_blockedSet |= OS_currThreadMask;
			OS_scheduler();
		}
		else
		{
			OS_readySet &= ~thread;
			OS_blockedSet |= thread;
		}
	}
	__enable_irq();
}

void OSThread_Resume(OSThread_Ctrl thread) {
	__disable_irq();
	/* never call OS_Suspend from the idleThread */
	if(OS_curr != OS_thread[0])
	{
		if(thread == OS_CURRENT_THREAD_CTRL)
		{

		}
		else
		{
			OS_blockedSet &= ~thread;
			OS_readySet |= thread;
		}
	}
	__enable_irq();
}

OSThread_Ctrl OSThread_Create(
    OSThread *me,
    u8 prio, /* thread priority */
    OSThreadHandler threadHandler,
    void *stack, u32 stkSize)
{
    /* round down the stack top to the 8-byte boundary
    * NOTE: ARM Cortex-M stack grows down from hi -> low memory
    */
    u32 * sp = (u32 *)((((u32)stack + stkSize) / 8) * 8);
    u32 * stk_limit;
    u32 bit;

    *(--sp) = (1U << 24);  /* xPSR */
    *(--sp) = (u32)threadHandler; /* PC */
    *(--sp) = 0xDEADBEEFU; /* LR  */
    *(--sp) = 0xDEAD000CU; /* R12 */
    *(--sp) = 0xDEAD0003U; /* R3  */
    *(--sp) = 0xDEAD0002U; /* R2  */
    *(--sp) = 0xDEAD0001U; /* R1  */
    *(--sp) = 0xDEAD0000U; /* R0  */
    /* additionally, fake registers R4-R11 */
    *(--sp) = 0xDEAD000BU; /* R11 */
    *(--sp) = 0xDEAD000AU; /* R10 */
    *(--sp) = 0xDEAD0009U; /* R9 */
    *(--sp) = 0xDEAD0008U; /* R8 */
    *(--sp) = 0xDEAD0007U; /* R7 */
    *(--sp) = 0xDEAD0006U; /* R6 */
    *(--sp) = 0xDEAD0005U; /* R5 */
    *(--sp) = 0xDEAD0004U; /* R4 */

    /* save the top of the stack in the thread's attibute */
    me->sp = sp;

    /* round up the bottom of the stack to the 8-byte boundary */
    stk_limit = (u32 *)(((((u32)stack - 1U) / 8) + 1U) * 8);

    /* pre-fill the unused part of the stack with 0xDEADBEEF */
    for (sp = sp - 1U; sp >= stk_limit; --sp) {
        *sp = 0xDEADBEEFU;
    }

    if(OS_existSet == 0U)
    {
    	bit = 0U;
    }
    else
    {
    	bit = LOG2(OS_existSet) + 1;
    }

    OS_thread[bit] = me;
    me->priority = prio;
    OS_existSet |= 1U << bit;

    /* make the thread ready to run */
    OS_readySet |= 1U << bit;

    return 1U << bit;
}
