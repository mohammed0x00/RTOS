/*
 * Scheduler.c
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

/**
**===========================================================================
**
**  Abstract: Initialization and Scheduler
**
**===========================================================================
*/

void OS_init(void)
{
	OS_existSet = 0x00000000U;
	OS_readySet = 0x00000000U;
	OS_delayedSet = 0x00000000U;
	OS_blockedSet = 0x00000000U;

    /* set the PendSV interrupt priority to the lowest level 0xFF */
	Interrupts_SetPriority(PendSV_IRQn, 15);
	Interrupts_SetPriority(SysTick_IRQn, 14);

    createIdleThread();

    OS_currThreadMask = 0x00000001U;
    OS_curr = (OSThread *)0;
}

void OS_scheduler(void)
{
    /* OS_next = ... */
	if(OS_readySet > 0x00000001U)
	{
		OS_currThreadMask = (OS_currThreadMask - 1) & OS_readySet & (0xFFFFFFFEU);
		if(OS_currThreadMask == 0x00000000U)
		{
			OS_currThreadMask = 1U << LOG2(OS_readySet);
		}
	}
	else
	{
		/* No threads available */
		OS_currThreadMask = OS_readySet;
	}


    OS_next = OS_thread[LOG2(OS_currThreadMask)];

    /* trigger PendSV, if needed */
    if (OS_next != OS_curr) {
        Interrupts_PendSVSetPending();
    }
}

void OS_run(void)
{
	SysTick_Config(OS_CFG_TICKCYCLES);

    __disable_irq();
    OS_scheduler();
    __enable_irq();

    /* Error occurred */
    while(1);
}

void OS_tick(void)
{
	OSThread_Ctrl tempSet = OS_delayedSet;
    while (tempSet != 0U) {
    	u32 bit = 1U << LOG2(tempSet);
        OSThread *t = OS_thread[LOG2(tempSet)];
        (t->timeout)--;
        if (t->timeout == 0U) {
            OS_readySet   |= bit;  /* insert to set */
            OS_delayedSet &= ~bit; /* remove from set */
        }
        tempSet &= ~bit; /* remove from working set */
    }
}
