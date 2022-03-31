/*
 * SysTick_interface.h
 *
 *  Created on: Feb 9, 2022
 *      Author: Mohammed Ali
 */

#ifndef MCAL_SYSTICK_SYSTICK_INTERFACE_H_
#define MCAL_SYSTICK_SYSTICK_INTERFACE_H_

STD_ERR SysTick_Config(u32 ticks);
void SysTick_Stop(u32 ticks);

#endif /* MCAL_SYSTICK_SYSTICK_INTERFACE_H_ */
