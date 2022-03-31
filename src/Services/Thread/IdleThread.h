/*
 * IdleThread.h
 *
 *  Created on: Feb 8, 2022
 *      Author: Mohammed Ali
 */

#ifndef SERVICES_THREAD_IDLETHREAD_H_
#define SERVICES_THREAD_IDLETHREAD_H_

/* Implement this function in your app */
__attribute__((weak)) void OS_onIdle(void);

/* Called from the initialization function to create the idle thread */
void createIdleThread(void);

#endif /* SERVICES_THREAD_IDLETHREAD_H_ */
