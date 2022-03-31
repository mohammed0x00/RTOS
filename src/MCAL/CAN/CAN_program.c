/*
 * CAN_program.c
 *
 *  Created on: Feb 3, 2022
 *      Author: Mohammed Ali
 */


#include "STD_Types.h"
#include "Bit_Math.h"

#include "CAN_private.h"
#include "CAN_config.h"
#include "CAN_interface.h"

static u32 txCounter = 0;
u8 blink = 0xAA;

void CAN_Init(void)
{
  /* Configuration after reset:
   * **************************
   * CAN reception/transmission frozen during debug.
   * Time Triggered Communication mode disabled.
   * The Sleep mode is left on software request.
   * Automatic retransmission.
   * Receive FIFO not locked on overrun.
   * */

  /* Set automatic bus-off management */
  CAN1->MCR |= CAN_MCR_ABOM;

  /* Set transmit FIFO priority driven by the request order */
  CAN1->MCR |= CAN_MCR_TXFP;

  /* Initialization request */
  CAN1->MCR |= CAN_MCR_INRQ;

  /* Request to exit Sleep mode */
  CAN1->MCR &= ~CAN_MCR_SLEEP;

  /* Wait for initialization mode */
  while((CAN_MSR_SLAK == (CAN_MSR_SLAK & CAN1->MSR))
      || (CAN_MSR_INAK != (CAN_MSR_INAK & CAN1->MSR)))
  {
    /* Do nothing until initialization mode is entered */
  }

  /* Setup timing parameters,
   * BaudRate = 1 Mbps, BRP[9:0] = 4, TS1[3:0] = 6, TS2[2:0] = 0, SJW[1:0] = 0
   * tq = (BRP[9:0] + 1) x tPCLK = 5 * 0,0222 = 0,111 us
   * tBS1 = tq x (TS1[3:0] + 1) = 0.111 * 7 = 0.777 us
   * tBS2 = tq x (TS2[2:0] + 1) = 0.111 * 1 = 0.111 us
   * NominalBitTime = 1 × tq + tBS1 + tBS2 = 0.111 + 0.777 + 0.111 = 0,9999 (1) us
   * BaudRate = 1 / NominalBitTime = 1 MBits/s */
  CAN1->BTR = 0x00060004;

  //////
  CAN1->BTR |= CAN_BTR_LBKM;

  /* Reset identifier register, no extension, no remote */
  CAN1->sTxMailBox[0].TIR = 0;

  /* Set CAN standard identifier = 0x100 */
  CAN1->sTxMailBox[0].TIR |= 0x20000000;

  /* Set CAN frame length to 8 */
  CAN1->sTxMailBox[0].TDTR &= ~CAN_TDT0R_DLC;
  CAN1->sTxMailBox[0].TDTR |= 0x00000008;

  /* Reset transmit data registers  */
  CAN1->sTxMailBox[0].TDLR = 0;
  CAN1->sTxMailBox[0].TDHR = 0;

  /* Filter setup,
   * Filter 1 0x25           Turn on/off green led
   * Filter 2 (0x10 - 0x1F)  Turn on/off green led
   * Filter 3 0x15           Turn on/off red led
   * Filter 4 0x20 - 0x2F    Turn on/off red led
   *
   * After reset filters in init mode and for CAN1
   * filter until number 13. Filter scale dual 16-bit */

  /* Set Filter init mode */
  CAN1->FMR |= CAN_FMR_FINIT;

  /* Set filer mode, 1 and 3 list, 2 and 4 mask */
  CAN1->FM1R &= ~(CAN_FM1R_FBM2 | CAN_FM1R_FBM4);
  CAN1->FM1R |= (CAN_FM1R_FBM1 | CAN_FM1R_FBM3);

  /* Set FIFO 0 for all filters */
  CAN1->FFA1R &= ~(CAN_FFA1R_FFA1 | CAN_FFA1R_FFA2
      | CAN_FFA1R_FFA3 | CAN_FFA1R_FFA4);

  /* Filter mapping
   *   15-8          7-5    4   3    2-0
   * STID[10:3] STID[2:0] RTR IDE EXID[17:15]
   * */

  /* Filter 0 Deactivated ID Mask (16-bit) No. 0, 1 */

  /* Set filter 1, list mode with ID = 0x25 */
  CAN1->sFilterRegister[1].FR1 = 0x04A004A0; /* No. 2, 3 */
  CAN1->sFilterRegister[1].FR2 = 0x04A004A0; /* No. 4, 5 */

  /* Set filter 2, mask mode with ID = 0x10:0x1F */
  CAN1->sFilterRegister[2].FR1 = 0xFE1F0200; /* No. 6 */
  CAN1->sFilterRegister[2].FR2 = 0xFE1F0200; /* No. 7 */

  /* Set filter 3, list mode with ID = 0x15 */
  CAN1->sFilterRegister[3].FR1 = 0x02A002A0; /* No. 8, 9 */
  CAN1->sFilterRegister[3].FR2 = 0x02A002A0; /* No. 10, 11 */

  /* Set filter 4, mask mode with ID = 0x20:0x2F */
  CAN1->sFilterRegister[4].FR1 = 0xFE1F0400; /* No. 12 */
  CAN1->sFilterRegister[4].FR2 = 0xFE1F0400; /* No. 13 */

  /* Activate filters */
  CAN1->FA1R |= (CAN_FA1R_FACT1 | CAN_FA1R_FACT2
      | CAN_FA1R_FACT3 | CAN_FA1R_FACT4);

  /* Active filters mode */
  CAN1->FMR &= ~CAN_FMR_FINIT;

  /* Request normal mode */
  CAN1->MCR &= ~(CAN_MCR_INRQ | CAN_MCR_SLEEP);
}

void CAN_Transmit(void)
{
  /* Check if transmission mailbox empty */
  if(CAN_TSR_TME0 == (CAN_TSR_TME0 & CAN1->TSR))
  {
    /* Increment TX counter */
    txCounter++;

    /* Set TX data */
    CAN1->sTxMailBox[0].TDLR = txCounter;

    /* Transmission request */
    CAN1->sTxMailBox[0].TIR |= CAN_TI0R_TXRQ;
  }
  else
  {
    /* Do nothing */
  }
}

void CAN_Receive(void)
{
  u8 rxData;
  u8 dlc;
  u8 filterIndex;

  /* Check FIFO message pending */
  if(0 != (CAN_RF0R_FMP0 & CAN1->RF0R))
  {
    /* FIFO not empty, read data */
    rxData = (u8)(CAN1->sFIFOMailBox[0].RDLR);

    /* Get filter match index */
    filterIndex = (u8)(CAN1->sFIFOMailBox[0].RDTR >> 8);

    /* Get data length code */
    dlc = (u8)(CAN1->sFIFOMailBox[0].RDTR);

    /* Check filter index */
    if((2 <= filterIndex) && (7 >= filterIndex) && (1 == dlc))
    {
      /* Green led control */
      if(0x0F == rxData)
      {
        /* Turn off green led */
        blink ^= 0xFF;
      }
      else if (0x1F == rxData)
      {
        /* Turn on green led */
    	blink ^= 0xFF;
      }
      else
      {
        /* Do nothing, invalid led control command */
      }
    }
    else if ((8 <= filterIndex) && (13 >= filterIndex) && (1 == dlc))
    {
      /* Red led control */
      if(0x0F == rxData)
      {
        /* Turn off red led */
    	  blink ^= 0xFF;
      }
      else if (0x1F == rxData)
      {
        /* Turn on red led */
    	  blink ^= 0xFF;
      }
      else
      {
        /* Do nothing, invalid led control command */
      }
    }
    else
    {
      /* Do noting, filter index or DLC not valid */
    }

    /* Release FIFO for the next message */
    CAN1->RF0R |= CAN_RF0R_RFOM0;
  }
  else
  {
    /* Do nothing, no new data */
  }
}


