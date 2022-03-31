/*
 * Thread.h
 *
 *  Created on: Feb 8, 2022
 *      Author: Mohammed Ali
 */

#ifndef SERVICES_THREAD_THREAD_H_
#define SERVICES_THREAD_THREAD_H_

/* Handler Function Declaration and Definition
 */
#define THREAD_HANDLER(x) __attribute__ ((naked)) void (x)(void)

/* Used to handle the running thread
 * example : OSThread_Suspend(OS_CURRENT_THREAD_CTRL);
 * */
#define OS_CURRENT_THREAD_CTRL		0x00000001U

/* Thread Control Block (TCB) */
typedef struct {
	void * sp; /* stack pointer */
    u32 timeout; /* timeout delay down-counter */
    u8 priority; /* thread priority */
    /* ... other attributes associated with a thread */
} OSThread;

typedef void (*OSThreadHandler)();

/* Used to handle a thread
 * example : OSThread_Suspend, OSThread_Resume;
 * */
typedef u32 OSThread_Ctrl;

/* OS initialization */
void OS_init(void);

/* transfer control to the RTOS to run the threads */
void OS_run(void);

/* blocking delay */
void OSThread_Delay(u32 ticks);

/* Call Schedular */
void OSThread_Yield(void);

/* Block a thread */
void OSThread_Suspend(OSThread_Ctrl thread);

/* Unblock a thread */
void OSThread_Resume(OSThread_Ctrl thread);

OSThread_Ctrl OSThread_Create(
    OSThread *me,
    u8 prio, /* thread priority */
    OSThreadHandler threadHandler,
    void *stack, u32 stkSize);


#endif /* SERVICES_THREAD_THREAD_H_ */
