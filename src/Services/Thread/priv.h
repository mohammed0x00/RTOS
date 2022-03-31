/*
 * priv.h
 *
 *  Created on: Feb 11, 2022
 *      Author: Mohammed Ali
 */

#ifndef SERVICES_THREAD_PRIV_H_
#define SERVICES_THREAD_PRIV_H_

/* Typedef */
/* Define  */
/* Macro */
#define LOG2(x) (31U - __CLZ(x))

/* Variables */
OSThread * volatile OS_curr; /* pointer to the current thread */
OSThread * volatile OS_next; /* pointer to the next thread to run */
OSThread * OS_thread[32]; /* array of threads started so far */

volatile OSThread_Ctrl OS_existSet; /* bitmask of threads that are exist */
volatile OSThread_Ctrl OS_readySet; /* bitmask of threads that are ready to run */
volatile OSThread_Ctrl OS_delayedSet; /* bitmask of threads that are delayed */
volatile OSThread_Ctrl OS_blockedSet; /* bitmask of threads that are blocked */
volatile OSThread_Ctrl OS_currThreadMask; /* bitmask of the current thread  */

/* Function prototypes */

/* process all timeouts */
void OS_tick(void);

/* this function must be called with interrupts DISABLED */
void OS_scheduler(void);

/* Interrupts handlers */
void PendSV_Handler(void) __attribute((naked));
void SysTick_Handler(void);

#endif /* SERVICES_THREAD_PRIV_H_ */
