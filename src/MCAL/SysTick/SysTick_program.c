/*
 * SysTick_program.c
 *
 *  Created on: Feb 9, 2022
 *      Author: Mohammed Ali
 */

#include "STD_Types.h"
#include "Bit_Math.h"

#include <MCAL/SysTick/SysTick_private.h>
#include <MCAL/SysTick/SysTick_config.h>
#include <MCAL/SysTick/SysTick_interface.h>

STD_ERR SysTick_Config(u32 ticks)
{
  if (ticks > SysTick_LOAD_RELOAD)  return (ERR);            /* Reload value impossible */

  SysTick->LOAD  = (ticks & SysTick_LOAD_RELOAD) - 1;      /* set reload register */
  SysTick->VAL   = 0;                                          /* Load the SysTick Counter Value */
  SysTick->CTRL  = SysTick_CTRL_CLKSOURCE |
		  	  	   SysTick_CTRL_TICKINT   |
				   SysTick_CTRL_ENABLE;                    /* Enable SysTick IRQ and SysTick Timer */
  return NO_ERR;                                                  /* Function successful */
}


void SysTick_Stop(u32 ticks)
{
	SysTick->CTRL  = 0; /* Disable SysTick IRQ and SysTick Timer */
}
