/*
 * Core_interface.h
 *
 *  Created on: Dec 19, 2021
 *      Author: Mohammed Ali
 */

#ifndef MCAL_CORE_CORE_INTERFACE_H_
#define MCAL_CORE_CORE_INTERFACE_H_

#if !defined __ASM
#define __ASM asm
#endif

#if !defined __INLINE
#define __INLINE inline
#endif

#if !defined __VOLATILE
#define __VOLATILE inline
#endif

__attribute__( ( always_inline ) ) static __INLINE u8 __CLZ(u32 value)
{
  u8 result;

  __ASM volatile ("clz %0, %1" : "=r" (result) : "r" (value) );
  return(result);
}

__attribute__( ( always_inline ) ) static __INLINE void * getSP(void)
{
    register void *sp;
    __ASM volatile ("mov %0, sp" : "=r"(sp));
    return sp;
}

__attribute__( ( always_inline ) ) static __INLINE void setSP(register void * sp)
{
	 __ASM volatile ("msr msp, %0" : : "r" (sp));
}

__attribute__( ( always_inline ) ) static __INLINE void __enable_irq()               { __ASM volatile ("cpsie i"); }
__attribute__( ( always_inline ) ) static __INLINE void __disable_irq()              { __ASM volatile ("cpsid i"); }
__attribute__( ( always_inline ) ) static __INLINE void __enable_fault_irq()         { __ASM volatile ("cpsie f"); }
__attribute__( ( always_inline ) ) static __INLINE void __disable_fault_irq()        { __ASM volatile ("cpsid f"); }
__attribute__( ( always_inline ) ) static __INLINE void __NOP()                      { __ASM volatile ("nop"); }
__attribute__( ( always_inline ) ) static __INLINE void __WFI()                      { __ASM volatile ("wfi"); }
__attribute__( ( always_inline ) ) static __INLINE void __WFE()                      { __ASM volatile ("wfe"); }
__attribute__( ( always_inline ) ) static __INLINE void __SEV()                      { __ASM volatile ("sev"); }
__attribute__( ( always_inline ) ) static __INLINE void __ISB()                      { __ASM volatile ("isb"); }
__attribute__( ( always_inline ) ) static __INLINE void __DSB()                      { __ASM volatile ("dsb"); }
__attribute__( ( always_inline ) ) static __INLINE void __DMB()                      { __ASM volatile ("dmb"); }
__attribute__( ( always_inline ) ) static __INLINE void __CLREX()                    { __ASM volatile ("clrex"); }

__attribute__( ( always_inline ) ) static __INLINE void pushR4toR11()                { __ASM volatile ("push {r4-r11}"); }
__attribute__( ( always_inline ) ) static __INLINE void popR4toR11()                { __ASM volatile ("pop {r4-r11}"); }
__attribute__( ( always_inline ) ) static __INLINE void __BXLR()                { __ASM volatile ("bx lr"); }

#endif /* MCAL_CORE_CORE_INTERFACE_H_ */
