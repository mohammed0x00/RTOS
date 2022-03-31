/*
 * IdleThread.c
 *
 *  Created on: Feb 8, 2022
 *      Author: Mohammed Ali
 */
/* Includes */
#include "STD_Types.h"
#include "Bit_Math.h"

#include "MCAL/Core/Core_interface.h"

#include "Thread.h"
#include "IdleThread.h"

/* Private typedef */
/* Private define  */
/* Private macro */
/* Private variables */
OSThread idleThread;
u32 stack_idleThread[40];

/* Private function prototypes */
void idleThread_Handler(void);

/* Private functions */

/**
**===========================================================================
**
**  Abstract: Idle Thread
**
**===========================================================================
*/

void idleThread_Handler(void) {
    while (1) {
        OS_onIdle();
    }
}

void createIdleThread(void)
{
	/* start idleThread thread */
	OSThread_Create(&idleThread,
				   0U, /* idle thread priority */
				   &idleThread_Handler,
				   stack_idleThread, sizeof(stack_idleThread));
}

__attribute__((weak)) void OS_onIdle(void)
{
	/* Wait for interrupts */
	__WFI();
}
