/*
 * SysTick_private.h
 *
 *  Created on: Feb 9, 2022
 *      Author: Mohammed Ali
 */

#ifndef MCAL_SYSTICK_SYSTICK_PRIVATE_H_
#define MCAL_SYSTICK_SYSTICK_PRIVATE_H_

/******************************************************************************/
/*                                                                            */
/*                               SystemTick                                   */
/*                                                                            */
/******************************************************************************/

#define SysTick_BASE        (0xE000E000UL +  0x0010UL)                    /*!< SysTick Base Address               */


/*****************  Bit definition for SysTick_CTRL register  *****************/
#define  SysTick_CTRL_ENABLE                 ((u32)0x00000001)        /*!< Counter enable */
#define  SysTick_CTRL_TICKINT                ((u32)0x00000002)        /*!< Counting down to 0 pends the SysTick handler */
#define  SysTick_CTRL_CLKSOURCE              ((u32)0x00000004)        /*!< Clock source */
#define  SysTick_CTRL_COUNTFLAG              ((u32)0x00010000)        /*!< Count Flag */

/*****************  Bit definition for SysTick_LOAD register  *****************/
#define  SysTick_LOAD_RELOAD                 ((u32)0x00FFFFFF)        /*!< Value to load into the SysTick Current Value Register when the counter reaches 0 */

/*****************  Bit definition for SysTick_VAL register  ******************/
#define  SysTick_VAL_CURRENT                 ((u32)0x00FFFFFF)        /*!< Current value at the time the register is accessed */

/*****************  Bit definition for SysTick_CALIB register  ****************/
#define  SysTick_CALIB_TENMS                 ((u32)0x00FFFFFF)        /*!< Reload value to use for 10ms timing */
#define  SysTick_CALIB_SKEW                  ((u32)0x40000000)        /*!< Calibration value is not exactly 10 ms */
#define  SysTick_CALIB_NOREF                 ((u32)0x80000000)        /*!< The reference clock is not provided */

/** \brief  Structure type to access the System Timer (SysTick).
 */
typedef struct
{
  __IO u32 CTRL;                    /*!< Offset: 0x000 (R/W)  SysTick Control and Status Register */
  __IO u32 LOAD;                    /*!< Offset: 0x004 (R/W)  SysTick Reload Value Register       */
  __IO u32 VAL;                     /*!< Offset: 0x008 (R/W)  SysTick Current Value Register      */
  __I  u32 CALIB;                   /*!< Offset: 0x00C (R/ )  SysTick Calibration Register        */
} SysTick_Type;

#define SysTick             ((SysTick_Type   *)     SysTick_BASE  )   /*!< SysTick configuration struct       */

#endif /* MCAL_SYSTICK_SYSTICK_PRIVATE_H_ */
