/*
 * CAN_private.h
 *
 *  Created on: Feb 3, 2022
 *      Author: Mohammed Ali
 */

#ifndef MCAL_CAN_CAN_PRIVATE_H_
#define MCAL_CAN_CAN_PRIVATE_H_

/******************************************************************************/
/*                                                                            */
/*                         Controller Area Network                            */
/*                                                                            */
/******************************************************************************/

#define CAN1_BASE             ((u32)0x40006400)

/**
  * @brief Controller Area Network TxMailBox
  */

typedef struct
{
  __IO u32 TIR;
  __IO u32 TDTR;
  __IO u32 TDLR;
  __IO u32 TDHR;
} CAN_TxMailBox_TypeDef;

/**
  * @brief Controller Area Network FIFOMailBox
  */

typedef struct
{
  __IO u32 RIR;
  __IO u32 RDTR;
  __IO u32 RDLR;
  __IO u32 RDHR;
} CAN_FIFOMailBox_TypeDef;

/**
  * @brief Controller Area Network FilterRegister
  */

typedef struct
{
  __IO u32 FR1;
  __IO u32 FR2;
} CAN_FilterRegister_TypeDef;

/**
  * @brief Controller Area Network
  */

typedef struct
{
  __IO u32 MCR;
  __IO u32 MSR;
  __IO u32 TSR;
  __IO u32 RF0R;
  __IO u32 RF1R;
  __IO u32 IER;
  __IO u32 ESR;
  __IO u32 BTR;
  u32  RESERVED0[88];
  CAN_TxMailBox_TypeDef sTxMailBox[3];
  CAN_FIFOMailBox_TypeDef sFIFOMailBox[2];
  u32  RESERVED1[12];
  __IO u32 FMR;
  __IO u32 FM1R;
  u32  RESERVED2;
  __IO u32 FS1R;
  u32  RESERVED3;
  __IO u32 FFA1R;
  u32  RESERVED4;
  __IO u32 FA1R;
  u32  RESERVED5[8];
#ifndef STM32F10X_CL
  CAN_FilterRegister_TypeDef sFilterRegister[14];
#else
  CAN_FilterRegister_TypeDef sFilterRegister[28];
#endif /* STM32F10X_CL */
} CAN_TypeDef;


/*!< CAN control and status registers */
/*******************  Bit definition for CAN_MCR register  ********************/
#define  CAN_MCR_INRQ                        ((u16)0x0001)            /*!< Initialization Request */
#define  CAN_MCR_SLEEP                       ((u16)0x0002)            /*!< Sleep Mode Request */
#define  CAN_MCR_TXFP                        ((u16)0x0004)            /*!< Transmit FIFO Priority */
#define  CAN_MCR_RFLM                        ((u16)0x0008)            /*!< Receive FIFO Locked Mode */
#define  CAN_MCR_NART                        ((u16)0x0010)            /*!< No Automatic Retransmission */
#define  CAN_MCR_AWUM                        ((u16)0x0020)            /*!< Automatic Wakeup Mode */
#define  CAN_MCR_ABOM                        ((u16)0x0040)            /*!< Automatic Bus-Off Management */
#define  CAN_MCR_TTCM                        ((u16)0x0080)            /*!< Time Triggered Communication Mode */
#define  CAN_MCR_RESET                       ((u16)0x8000)            /*!< CAN software master reset */

/*******************  Bit definition for CAN_MSR register  ********************/
#define  CAN_MSR_INAK                        ((u16)0x0001)            /*!< Initialization Acknowledge */
#define  CAN_MSR_SLAK                        ((u16)0x0002)            /*!< Sleep Acknowledge */
#define  CAN_MSR_ERRI                        ((u16)0x0004)            /*!< Error Interrupt */
#define  CAN_MSR_WKUI                        ((u16)0x0008)            /*!< Wakeup Interrupt */
#define  CAN_MSR_SLAKI                       ((u16)0x0010)            /*!< Sleep Acknowledge Interrupt */
#define  CAN_MSR_TXM                         ((u16)0x0100)            /*!< Transmit Mode */
#define  CAN_MSR_RXM                         ((u16)0x0200)            /*!< Receive Mode */
#define  CAN_MSR_SAMP                        ((u16)0x0400)            /*!< Last Sample Point */
#define  CAN_MSR_RX                          ((u16)0x0800)            /*!< CAN Rx Signal */

/*******************  Bit definition for CAN_TSR register  ********************/
#define  CAN_TSR_RQCP0                       ((u32)0x00000001)        /*!< Request Completed Mailbox0 */
#define  CAN_TSR_TXOK0                       ((u32)0x00000002)        /*!< Transmission OK of Mailbox0 */
#define  CAN_TSR_ALST0                       ((u32)0x00000004)        /*!< Arbitration Lost for Mailbox0 */
#define  CAN_TSR_TERR0                       ((u32)0x00000008)        /*!< Transmission Error of Mailbox0 */
#define  CAN_TSR_ABRQ0                       ((u32)0x00000080)        /*!< Abort Request for Mailbox0 */
#define  CAN_TSR_RQCP1                       ((u32)0x00000100)        /*!< Request Completed Mailbox1 */
#define  CAN_TSR_TXOK1                       ((u32)0x00000200)        /*!< Transmission OK of Mailbox1 */
#define  CAN_TSR_ALST1                       ((u32)0x00000400)        /*!< Arbitration Lost for Mailbox1 */
#define  CAN_TSR_TERR1                       ((u32)0x00000800)        /*!< Transmission Error of Mailbox1 */
#define  CAN_TSR_ABRQ1                       ((u32)0x00008000)        /*!< Abort Request for Mailbox 1 */
#define  CAN_TSR_RQCP2                       ((u32)0x00010000)        /*!< Request Completed Mailbox2 */
#define  CAN_TSR_TXOK2                       ((u32)0x00020000)        /*!< Transmission OK of Mailbox 2 */
#define  CAN_TSR_ALST2                       ((u32)0x00040000)        /*!< Arbitration Lost for mailbox 2 */
#define  CAN_TSR_TERR2                       ((u32)0x00080000)        /*!< Transmission Error of Mailbox 2 */
#define  CAN_TSR_ABRQ2                       ((u32)0x00800000)        /*!< Abort Request for Mailbox 2 */
#define  CAN_TSR_CODE                        ((u32)0x03000000)        /*!< Mailbox Code */

#define  CAN_TSR_TME                         ((u32)0x1C000000)        /*!< TME[2:0] bits */
#define  CAN_TSR_TME0                        ((u32)0x04000000)        /*!< Transmit Mailbox 0 Empty */
#define  CAN_TSR_TME1                        ((u32)0x08000000)        /*!< Transmit Mailbox 1 Empty */
#define  CAN_TSR_TME2                        ((u32)0x10000000)        /*!< Transmit Mailbox 2 Empty */

#define  CAN_TSR_LOW                         ((u32)0xE0000000)        /*!< LOW[2:0] bits */
#define  CAN_TSR_LOW0                        ((u32)0x20000000)        /*!< Lowest Priority Flag for Mailbox 0 */
#define  CAN_TSR_LOW1                        ((u32)0x40000000)        /*!< Lowest Priority Flag for Mailbox 1 */
#define  CAN_TSR_LOW2                        ((u32)0x80000000)        /*!< Lowest Priority Flag for Mailbox 2 */

/*******************  Bit definition for CAN_RF0R register  *******************/
#define  CAN_RF0R_FMP0                       ((u8)0x03)               /*!< FIFO 0 Message Pending */
#define  CAN_RF0R_FULL0                      ((u8)0x08)               /*!< FIFO 0 Full */
#define  CAN_RF0R_FOVR0                      ((u8)0x10)               /*!< FIFO 0 Overrun */
#define  CAN_RF0R_RFOM0                      ((u8)0x20)               /*!< Release FIFO 0 Output Mailbox */

/*******************  Bit definition for CAN_RF1R register  *******************/
#define  CAN_RF1R_FMP1                       ((u8)0x03)               /*!< FIFO 1 Message Pending */
#define  CAN_RF1R_FULL1                      ((u8)0x08)               /*!< FIFO 1 Full */
#define  CAN_RF1R_FOVR1                      ((u8)0x10)               /*!< FIFO 1 Overrun */
#define  CAN_RF1R_RFOM1                      ((u8)0x20)               /*!< Release FIFO 1 Output Mailbox */

/********************  Bit definition for CAN_IER register  *******************/
#define  CAN_IER_TMEIE                       ((u32)0x00000001)        /*!< Transmit Mailbox Empty Interrupt Enable */
#define  CAN_IER_FMPIE0                      ((u32)0x00000002)        /*!< FIFO Message Pending Interrupt Enable */
#define  CAN_IER_FFIE0                       ((u32)0x00000004)        /*!< FIFO Full Interrupt Enable */
#define  CAN_IER_FOVIE0                      ((u32)0x00000008)        /*!< FIFO Overrun Interrupt Enable */
#define  CAN_IER_FMPIE1                      ((u32)0x00000010)        /*!< FIFO Message Pending Interrupt Enable */
#define  CAN_IER_FFIE1                       ((u32)0x00000020)        /*!< FIFO Full Interrupt Enable */
#define  CAN_IER_FOVIE1                      ((u32)0x00000040)        /*!< FIFO Overrun Interrupt Enable */
#define  CAN_IER_EWGIE                       ((u32)0x00000100)        /*!< Error Warning Interrupt Enable */
#define  CAN_IER_EPVIE                       ((u32)0x00000200)        /*!< Error Passive Interrupt Enable */
#define  CAN_IER_BOFIE                       ((u32)0x00000400)        /*!< Bus-Off Interrupt Enable */
#define  CAN_IER_LECIE                       ((u32)0x00000800)        /*!< Last Error Code Interrupt Enable */
#define  CAN_IER_ERRIE                       ((u32)0x00008000)        /*!< Error Interrupt Enable */
#define  CAN_IER_WKUIE                       ((u32)0x00010000)        /*!< Wakeup Interrupt Enable */
#define  CAN_IER_SLKIE                       ((u32)0x00020000)        /*!< Sleep Interrupt Enable */

/********************  Bit definition for CAN_ESR register  *******************/
#define  CAN_ESR_EWGF                        ((u32)0x00000001)        /*!< Error Warning Flag */
#define  CAN_ESR_EPVF                        ((u32)0x00000002)        /*!< Error Passive Flag */
#define  CAN_ESR_BOFF                        ((u32)0x00000004)        /*!< Bus-Off Flag */

#define  CAN_ESR_LEC                         ((u32)0x00000070)        /*!< LEC[2:0] bits (Last Error Code) */
#define  CAN_ESR_LEC_0                       ((u32)0x00000010)        /*!< Bit 0 */
#define  CAN_ESR_LEC_1                       ((u32)0x00000020)        /*!< Bit 1 */
#define  CAN_ESR_LEC_2                       ((u32)0x00000040)        /*!< Bit 2 */

#define  CAN_ESR_TEC                         ((u32)0x00FF0000)        /*!< Least significant byte of the 9-bit Transmit Error Counter */
#define  CAN_ESR_REC                         ((u32)0xFF000000)        /*!< Receive Error Counter */

/*******************  Bit definition for CAN_BTR register  ********************/
#define  CAN_BTR_BRP                         ((u32)0x000003FF)        /*!< Baud Rate Prescaler */
#define  CAN_BTR_TS1                         ((u32)0x000F0000)        /*!< Time Segment 1 */
#define  CAN_BTR_TS2                         ((u32)0x00700000)        /*!< Time Segment 2 */
#define  CAN_BTR_SJW                         ((u32)0x03000000)        /*!< Resynchronization Jump Width */
#define  CAN_BTR_LBKM                        ((u32)0x40000000)        /*!< Loop Back Mode (Debug) */
#define  CAN_BTR_SILM                        ((u32)0x80000000)        /*!< Silent Mode */

/*!< Mailbox registers */
/******************  Bit definition for CAN_TI0R register  ********************/
#define  CAN_TI0R_TXRQ                       ((u32)0x00000001)        /*!< Transmit Mailbox Request */
#define  CAN_TI0R_RTR                        ((u32)0x00000002)        /*!< Remote Transmission Request */
#define  CAN_TI0R_IDE                        ((u32)0x00000004)        /*!< Identifier Extension */
#define  CAN_TI0R_EXID                       ((u32)0x001FFFF8)        /*!< Extended Identifier */
#define  CAN_TI0R_STID                       ((u32)0xFFE00000)        /*!< Standard Identifier or Extended Identifier */

/******************  Bit definition for CAN_TDT0R register  *******************/
#define  CAN_TDT0R_DLC                       ((u32)0x0000000F)        /*!< Data Length Code */
#define  CAN_TDT0R_TGT                       ((u32)0x00000100)        /*!< Transmit Global Time */
#define  CAN_TDT0R_TIME                      ((u32)0xFFFF0000)        /*!< Message Time Stamp */

/******************  Bit definition for CAN_TDL0R register  *******************/
#define  CAN_TDL0R_DATA0                     ((u32)0x000000FF)        /*!< Data byte 0 */
#define  CAN_TDL0R_DATA1                     ((u32)0x0000FF00)        /*!< Data byte 1 */
#define  CAN_TDL0R_DATA2                     ((u32)0x00FF0000)        /*!< Data byte 2 */
#define  CAN_TDL0R_DATA3                     ((u32)0xFF000000)        /*!< Data byte 3 */

/******************  Bit definition for CAN_TDH0R register  *******************/
#define  CAN_TDH0R_DATA4                     ((u32)0x000000FF)        /*!< Data byte 4 */
#define  CAN_TDH0R_DATA5                     ((u32)0x0000FF00)        /*!< Data byte 5 */
#define  CAN_TDH0R_DATA6                     ((u32)0x00FF0000)        /*!< Data byte 6 */
#define  CAN_TDH0R_DATA7                     ((u32)0xFF000000)        /*!< Data byte 7 */

/*******************  Bit definition for CAN_TI1R register  *******************/
#define  CAN_TI1R_TXRQ                       ((u32)0x00000001)        /*!< Transmit Mailbox Request */
#define  CAN_TI1R_RTR                        ((u32)0x00000002)        /*!< Remote Transmission Request */
#define  CAN_TI1R_IDE                        ((u32)0x00000004)        /*!< Identifier Extension */
#define  CAN_TI1R_EXID                       ((u32)0x001FFFF8)        /*!< Extended Identifier */
#define  CAN_TI1R_STID                       ((u32)0xFFE00000)        /*!< Standard Identifier or Extended Identifier */

/*******************  Bit definition for CAN_TDT1R register  ******************/
#define  CAN_TDT1R_DLC                       ((u32)0x0000000F)        /*!< Data Length Code */
#define  CAN_TDT1R_TGT                       ((u32)0x00000100)        /*!< Transmit Global Time */
#define  CAN_TDT1R_TIME                      ((u32)0xFFFF0000)        /*!< Message Time Stamp */

/*******************  Bit definition for CAN_TDL1R register  ******************/
#define  CAN_TDL1R_DATA0                     ((u32)0x000000FF)        /*!< Data byte 0 */
#define  CAN_TDL1R_DATA1                     ((u32)0x0000FF00)        /*!< Data byte 1 */
#define  CAN_TDL1R_DATA2                     ((u32)0x00FF0000)        /*!< Data byte 2 */
#define  CAN_TDL1R_DATA3                     ((u32)0xFF000000)        /*!< Data byte 3 */

/*******************  Bit definition for CAN_TDH1R register  ******************/
#define  CAN_TDH1R_DATA4                     ((u32)0x000000FF)        /*!< Data byte 4 */
#define  CAN_TDH1R_DATA5                     ((u32)0x0000FF00)        /*!< Data byte 5 */
#define  CAN_TDH1R_DATA6                     ((u32)0x00FF0000)        /*!< Data byte 6 */
#define  CAN_TDH1R_DATA7                     ((u32)0xFF000000)        /*!< Data byte 7 */

/*******************  Bit definition for CAN_TI2R register  *******************/
#define  CAN_TI2R_TXRQ                       ((u32)0x00000001)        /*!< Transmit Mailbox Request */
#define  CAN_TI2R_RTR                        ((u32)0x00000002)        /*!< Remote Transmission Request */
#define  CAN_TI2R_IDE                        ((u32)0x00000004)        /*!< Identifier Extension */
#define  CAN_TI2R_EXID                       ((u32)0x001FFFF8)        /*!< Extended identifier */
#define  CAN_TI2R_STID                       ((u32)0xFFE00000)        /*!< Standard Identifier or Extended Identifier */

/*******************  Bit definition for CAN_TDT2R register  ******************/
#define  CAN_TDT2R_DLC                       ((u32)0x0000000F)        /*!< Data Length Code */
#define  CAN_TDT2R_TGT                       ((u32)0x00000100)        /*!< Transmit Global Time */
#define  CAN_TDT2R_TIME                      ((u32)0xFFFF0000)        /*!< Message Time Stamp */

/*******************  Bit definition for CAN_TDL2R register  ******************/
#define  CAN_TDL2R_DATA0                     ((u32)0x000000FF)        /*!< Data byte 0 */
#define  CAN_TDL2R_DATA1                     ((u32)0x0000FF00)        /*!< Data byte 1 */
#define  CAN_TDL2R_DATA2                     ((u32)0x00FF0000)        /*!< Data byte 2 */
#define  CAN_TDL2R_DATA3                     ((u32)0xFF000000)        /*!< Data byte 3 */

/*******************  Bit definition for CAN_TDH2R register  ******************/
#define  CAN_TDH2R_DATA4                     ((u32)0x000000FF)        /*!< Data byte 4 */
#define  CAN_TDH2R_DATA5                     ((u32)0x0000FF00)        /*!< Data byte 5 */
#define  CAN_TDH2R_DATA6                     ((u32)0x00FF0000)        /*!< Data byte 6 */
#define  CAN_TDH2R_DATA7                     ((u32)0xFF000000)        /*!< Data byte 7 */

/*******************  Bit definition for CAN_RI0R register  *******************/
#define  CAN_RI0R_RTR                        ((u32)0x00000002)        /*!< Remote Transmission Request */
#define  CAN_RI0R_IDE                        ((u32)0x00000004)        /*!< Identifier Extension */
#define  CAN_RI0R_EXID                       ((u32)0x001FFFF8)        /*!< Extended Identifier */
#define  CAN_RI0R_STID                       ((u32)0xFFE00000)        /*!< Standard Identifier or Extended Identifier */

/*******************  Bit definition for CAN_RDT0R register  ******************/
#define  CAN_RDT0R_DLC                       ((u32)0x0000000F)        /*!< Data Length Code */
#define  CAN_RDT0R_FMI                       ((u32)0x0000FF00)        /*!< Filter Match Index */
#define  CAN_RDT0R_TIME                      ((u32)0xFFFF0000)        /*!< Message Time Stamp */

/*******************  Bit definition for CAN_RDL0R register  ******************/
#define  CAN_RDL0R_DATA0                     ((u32)0x000000FF)        /*!< Data byte 0 */
#define  CAN_RDL0R_DATA1                     ((u32)0x0000FF00)        /*!< Data byte 1 */
#define  CAN_RDL0R_DATA2                     ((u32)0x00FF0000)        /*!< Data byte 2 */
#define  CAN_RDL0R_DATA3                     ((u32)0xFF000000)        /*!< Data byte 3 */

/*******************  Bit definition for CAN_RDH0R register  ******************/
#define  CAN_RDH0R_DATA4                     ((u32)0x000000FF)        /*!< Data byte 4 */
#define  CAN_RDH0R_DATA5                     ((u32)0x0000FF00)        /*!< Data byte 5 */
#define  CAN_RDH0R_DATA6                     ((u32)0x00FF0000)        /*!< Data byte 6 */
#define  CAN_RDH0R_DATA7                     ((u32)0xFF000000)        /*!< Data byte 7 */

/*******************  Bit definition for CAN_RI1R register  *******************/
#define  CAN_RI1R_RTR                        ((u32)0x00000002)        /*!< Remote Transmission Request */
#define  CAN_RI1R_IDE                        ((u32)0x00000004)        /*!< Identifier Extension */
#define  CAN_RI1R_EXID                       ((u32)0x001FFFF8)        /*!< Extended identifier */
#define  CAN_RI1R_STID                       ((u32)0xFFE00000)        /*!< Standard Identifier or Extended Identifier */

/*******************  Bit definition for CAN_RDT1R register  ******************/
#define  CAN_RDT1R_DLC                       ((u32)0x0000000F)        /*!< Data Length Code */
#define  CAN_RDT1R_FMI                       ((u32)0x0000FF00)        /*!< Filter Match Index */
#define  CAN_RDT1R_TIME                      ((u32)0xFFFF0000)        /*!< Message Time Stamp */

/*******************  Bit definition for CAN_RDL1R register  ******************/
#define  CAN_RDL1R_DATA0                     ((u32)0x000000FF)        /*!< Data byte 0 */
#define  CAN_RDL1R_DATA1                     ((u32)0x0000FF00)        /*!< Data byte 1 */
#define  CAN_RDL1R_DATA2                     ((u32)0x00FF0000)        /*!< Data byte 2 */
#define  CAN_RDL1R_DATA3                     ((u32)0xFF000000)        /*!< Data byte 3 */

/*******************  Bit definition for CAN_RDH1R register  ******************/
#define  CAN_RDH1R_DATA4                     ((u32)0x000000FF)        /*!< Data byte 4 */
#define  CAN_RDH1R_DATA5                     ((u32)0x0000FF00)        /*!< Data byte 5 */
#define  CAN_RDH1R_DATA6                     ((u32)0x00FF0000)        /*!< Data byte 6 */
#define  CAN_RDH1R_DATA7                     ((u32)0xFF000000)        /*!< Data byte 7 */

/*!< CAN filter registers */
/*******************  Bit definition for CAN_FMR register  ********************/
#define  CAN_FMR_FINIT                       ((u8)0x01)               /*!< Filter Init Mode */

/*******************  Bit definition for CAN_FM1R register  *******************/
#define  CAN_FM1R_FBM                        ((u16)0x3FFF)            /*!< Filter Mode */
#define  CAN_FM1R_FBM0                       ((u16)0x0001)            /*!< Filter Init Mode bit 0 */
#define  CAN_FM1R_FBM1                       ((u16)0x0002)            /*!< Filter Init Mode bit 1 */
#define  CAN_FM1R_FBM2                       ((u16)0x0004)            /*!< Filter Init Mode bit 2 */
#define  CAN_FM1R_FBM3                       ((u16)0x0008)            /*!< Filter Init Mode bit 3 */
#define  CAN_FM1R_FBM4                       ((u16)0x0010)            /*!< Filter Init Mode bit 4 */
#define  CAN_FM1R_FBM5                       ((u16)0x0020)            /*!< Filter Init Mode bit 5 */
#define  CAN_FM1R_FBM6                       ((u16)0x0040)            /*!< Filter Init Mode bit 6 */
#define  CAN_FM1R_FBM7                       ((u16)0x0080)            /*!< Filter Init Mode bit 7 */
#define  CAN_FM1R_FBM8                       ((u16)0x0100)            /*!< Filter Init Mode bit 8 */
#define  CAN_FM1R_FBM9                       ((u16)0x0200)            /*!< Filter Init Mode bit 9 */
#define  CAN_FM1R_FBM10                      ((u16)0x0400)            /*!< Filter Init Mode bit 10 */
#define  CAN_FM1R_FBM11                      ((u16)0x0800)            /*!< Filter Init Mode bit 11 */
#define  CAN_FM1R_FBM12                      ((u16)0x1000)            /*!< Filter Init Mode bit 12 */
#define  CAN_FM1R_FBM13                      ((u16)0x2000)            /*!< Filter Init Mode bit 13 */

/*******************  Bit definition for CAN_FS1R register  *******************/
#define  CAN_FS1R_FSC                        ((u16)0x3FFF)            /*!< Filter Scale Configuration */
#define  CAN_FS1R_FSC0                       ((u16)0x0001)            /*!< Filter Scale Configuration bit 0 */
#define  CAN_FS1R_FSC1                       ((u16)0x0002)            /*!< Filter Scale Configuration bit 1 */
#define  CAN_FS1R_FSC2                       ((u16)0x0004)            /*!< Filter Scale Configuration bit 2 */
#define  CAN_FS1R_FSC3                       ((u16)0x0008)            /*!< Filter Scale Configuration bit 3 */
#define  CAN_FS1R_FSC4                       ((u16)0x0010)            /*!< Filter Scale Configuration bit 4 */
#define  CAN_FS1R_FSC5                       ((u16)0x0020)            /*!< Filter Scale Configuration bit 5 */
#define  CAN_FS1R_FSC6                       ((u16)0x0040)            /*!< Filter Scale Configuration bit 6 */
#define  CAN_FS1R_FSC7                       ((u16)0x0080)            /*!< Filter Scale Configuration bit 7 */
#define  CAN_FS1R_FSC8                       ((u16)0x0100)            /*!< Filter Scale Configuration bit 8 */
#define  CAN_FS1R_FSC9                       ((u16)0x0200)            /*!< Filter Scale Configuration bit 9 */
#define  CAN_FS1R_FSC10                      ((u16)0x0400)            /*!< Filter Scale Configuration bit 10 */
#define  CAN_FS1R_FSC11                      ((u16)0x0800)            /*!< Filter Scale Configuration bit 11 */
#define  CAN_FS1R_FSC12                      ((u16)0x1000)            /*!< Filter Scale Configuration bit 12 */
#define  CAN_FS1R_FSC13                      ((u16)0x2000)            /*!< Filter Scale Configuration bit 13 */

/******************  Bit definition for CAN_FFA1R register  *******************/
#define  CAN_FFA1R_FFA                       ((u16)0x3FFF)            /*!< Filter FIFO Assignment */
#define  CAN_FFA1R_FFA0                      ((u16)0x0001)            /*!< Filter FIFO Assignment for Filter 0 */
#define  CAN_FFA1R_FFA1                      ((u16)0x0002)            /*!< Filter FIFO Assignment for Filter 1 */
#define  CAN_FFA1R_FFA2                      ((u16)0x0004)            /*!< Filter FIFO Assignment for Filter 2 */
#define  CAN_FFA1R_FFA3                      ((u16)0x0008)            /*!< Filter FIFO Assignment for Filter 3 */
#define  CAN_FFA1R_FFA4                      ((u16)0x0010)            /*!< Filter FIFO Assignment for Filter 4 */
#define  CAN_FFA1R_FFA5                      ((u16)0x0020)            /*!< Filter FIFO Assignment for Filter 5 */
#define  CAN_FFA1R_FFA6                      ((u16)0x0040)            /*!< Filter FIFO Assignment for Filter 6 */
#define  CAN_FFA1R_FFA7                      ((u16)0x0080)            /*!< Filter FIFO Assignment for Filter 7 */
#define  CAN_FFA1R_FFA8                      ((u16)0x0100)            /*!< Filter FIFO Assignment for Filter 8 */
#define  CAN_FFA1R_FFA9                      ((u16)0x0200)            /*!< Filter FIFO Assignment for Filter 9 */
#define  CAN_FFA1R_FFA10                     ((u16)0x0400)            /*!< Filter FIFO Assignment for Filter 10 */
#define  CAN_FFA1R_FFA11                     ((u16)0x0800)            /*!< Filter FIFO Assignment for Filter 11 */
#define  CAN_FFA1R_FFA12                     ((u16)0x1000)            /*!< Filter FIFO Assignment for Filter 12 */
#define  CAN_FFA1R_FFA13                     ((u16)0x2000)            /*!< Filter FIFO Assignment for Filter 13 */

/*******************  Bit definition for CAN_FA1R register  *******************/
#define  CAN_FA1R_FACT                       ((u16)0x3FFF)            /*!< Filter Active */
#define  CAN_FA1R_FACT0                      ((u16)0x0001)            /*!< Filter 0 Active */
#define  CAN_FA1R_FACT1                      ((u16)0x0002)            /*!< Filter 1 Active */
#define  CAN_FA1R_FACT2                      ((u16)0x0004)            /*!< Filter 2 Active */
#define  CAN_FA1R_FACT3                      ((u16)0x0008)            /*!< Filter 3 Active */
#define  CAN_FA1R_FACT4                      ((u16)0x0010)            /*!< Filter 4 Active */
#define  CAN_FA1R_FACT5                      ((u16)0x0020)            /*!< Filter 5 Active */
#define  CAN_FA1R_FACT6                      ((u16)0x0040)            /*!< Filter 6 Active */
#define  CAN_FA1R_FACT7                      ((u16)0x0080)            /*!< Filter 7 Active */
#define  CAN_FA1R_FACT8                      ((u16)0x0100)            /*!< Filter 8 Active */
#define  CAN_FA1R_FACT9                      ((u16)0x0200)            /*!< Filter 9 Active */
#define  CAN_FA1R_FACT10                     ((u16)0x0400)            /*!< Filter 10 Active */
#define  CAN_FA1R_FACT11                     ((u16)0x0800)            /*!< Filter 11 Active */
#define  CAN_FA1R_FACT12                     ((u16)0x1000)            /*!< Filter 12 Active */
#define  CAN_FA1R_FACT13                     ((u16)0x2000)            /*!< Filter 13 Active */

/*******************  Bit definition for CAN_F0R1 register  *******************/
#define  CAN_F0R1_FB0                        ((u32)0x00000001)        /*!< Filter bit 0 */
#define  CAN_F0R1_FB1                        ((u32)0x00000002)        /*!< Filter bit 1 */
#define  CAN_F0R1_FB2                        ((u32)0x00000004)        /*!< Filter bit 2 */
#define  CAN_F0R1_FB3                        ((u32)0x00000008)        /*!< Filter bit 3 */
#define  CAN_F0R1_FB4                        ((u32)0x00000010)        /*!< Filter bit 4 */
#define  CAN_F0R1_FB5                        ((u32)0x00000020)        /*!< Filter bit 5 */
#define  CAN_F0R1_FB6                        ((u32)0x00000040)        /*!< Filter bit 6 */
#define  CAN_F0R1_FB7                        ((u32)0x00000080)        /*!< Filter bit 7 */
#define  CAN_F0R1_FB8                        ((u32)0x00000100)        /*!< Filter bit 8 */
#define  CAN_F0R1_FB9                        ((u32)0x00000200)        /*!< Filter bit 9 */
#define  CAN_F0R1_FB10                       ((u32)0x00000400)        /*!< Filter bit 10 */
#define  CAN_F0R1_FB11                       ((u32)0x00000800)        /*!< Filter bit 11 */
#define  CAN_F0R1_FB12                       ((u32)0x00001000)        /*!< Filter bit 12 */
#define  CAN_F0R1_FB13                       ((u32)0x00002000)        /*!< Filter bit 13 */
#define  CAN_F0R1_FB14                       ((u32)0x00004000)        /*!< Filter bit 14 */
#define  CAN_F0R1_FB15                       ((u32)0x00008000)        /*!< Filter bit 15 */
#define  CAN_F0R1_FB16                       ((u32)0x00010000)        /*!< Filter bit 16 */
#define  CAN_F0R1_FB17                       ((u32)0x00020000)        /*!< Filter bit 17 */
#define  CAN_F0R1_FB18                       ((u32)0x00040000)        /*!< Filter bit 18 */
#define  CAN_F0R1_FB19                       ((u32)0x00080000)        /*!< Filter bit 19 */
#define  CAN_F0R1_FB20                       ((u32)0x00100000)        /*!< Filter bit 20 */
#define  CAN_F0R1_FB21                       ((u32)0x00200000)        /*!< Filter bit 21 */
#define  CAN_F0R1_FB22                       ((u32)0x00400000)        /*!< Filter bit 22 */
#define  CAN_F0R1_FB23                       ((u32)0x00800000)        /*!< Filter bit 23 */
#define  CAN_F0R1_FB24                       ((u32)0x01000000)        /*!< Filter bit 24 */
#define  CAN_F0R1_FB25                       ((u32)0x02000000)        /*!< Filter bit 25 */
#define  CAN_F0R1_FB26                       ((u32)0x04000000)        /*!< Filter bit 26 */
#define  CAN_F0R1_FB27                       ((u32)0x08000000)        /*!< Filter bit 27 */
#define  CAN_F0R1_FB28                       ((u32)0x10000000)        /*!< Filter bit 28 */
#define  CAN_F0R1_FB29                       ((u32)0x20000000)        /*!< Filter bit 29 */
#define  CAN_F0R1_FB30                       ((u32)0x40000000)        /*!< Filter bit 30 */
#define  CAN_F0R1_FB31                       ((u32)0x80000000)        /*!< Filter bit 31 */

/*******************  Bit definition for CAN_F1R1 register  *******************/
#define  CAN_F1R1_FB0                        ((u32)0x00000001)        /*!< Filter bit 0 */
#define  CAN_F1R1_FB1                        ((u32)0x00000002)        /*!< Filter bit 1 */
#define  CAN_F1R1_FB2                        ((u32)0x00000004)        /*!< Filter bit 2 */
#define  CAN_F1R1_FB3                        ((u32)0x00000008)        /*!< Filter bit 3 */
#define  CAN_F1R1_FB4                        ((u32)0x00000010)        /*!< Filter bit 4 */
#define  CAN_F1R1_FB5                        ((u32)0x00000020)        /*!< Filter bit 5 */
#define  CAN_F1R1_FB6                        ((u32)0x00000040)        /*!< Filter bit 6 */
#define  CAN_F1R1_FB7                        ((u32)0x00000080)        /*!< Filter bit 7 */
#define  CAN_F1R1_FB8                        ((u32)0x00000100)        /*!< Filter bit 8 */
#define  CAN_F1R1_FB9                        ((u32)0x00000200)        /*!< Filter bit 9 */
#define  CAN_F1R1_FB10                       ((u32)0x00000400)        /*!< Filter bit 10 */
#define  CAN_F1R1_FB11                       ((u32)0x00000800)        /*!< Filter bit 11 */
#define  CAN_F1R1_FB12                       ((u32)0x00001000)        /*!< Filter bit 12 */
#define  CAN_F1R1_FB13                       ((u32)0x00002000)        /*!< Filter bit 13 */
#define  CAN_F1R1_FB14                       ((u32)0x00004000)        /*!< Filter bit 14 */
#define  CAN_F1R1_FB15                       ((u32)0x00008000)        /*!< Filter bit 15 */
#define  CAN_F1R1_FB16                       ((u32)0x00010000)        /*!< Filter bit 16 */
#define  CAN_F1R1_FB17                       ((u32)0x00020000)        /*!< Filter bit 17 */
#define  CAN_F1R1_FB18                       ((u32)0x00040000)        /*!< Filter bit 18 */
#define  CAN_F1R1_FB19                       ((u32)0x00080000)        /*!< Filter bit 19 */
#define  CAN_F1R1_FB20                       ((u32)0x00100000)        /*!< Filter bit 20 */
#define  CAN_F1R1_FB21                       ((u32)0x00200000)        /*!< Filter bit 21 */
#define  CAN_F1R1_FB22                       ((u32)0x00400000)        /*!< Filter bit 22 */
#define  CAN_F1R1_FB23                       ((u32)0x00800000)        /*!< Filter bit 23 */
#define  CAN_F1R1_FB24                       ((u32)0x01000000)        /*!< Filter bit 24 */
#define  CAN_F1R1_FB25                       ((u32)0x02000000)        /*!< Filter bit 25 */
#define  CAN_F1R1_FB26                       ((u32)0x04000000)        /*!< Filter bit 26 */
#define  CAN_F1R1_FB27                       ((u32)0x08000000)        /*!< Filter bit 27 */
#define  CAN_F1R1_FB28                       ((u32)0x10000000)        /*!< Filter bit 28 */
#define  CAN_F1R1_FB29                       ((u32)0x20000000)        /*!< Filter bit 29 */
#define  CAN_F1R1_FB30                       ((u32)0x40000000)        /*!< Filter bit 30 */
#define  CAN_F1R1_FB31                       ((u32)0x80000000)        /*!< Filter bit 31 */

/*******************  Bit definition for CAN_F2R1 register  *******************/
#define  CAN_F2R1_FB0                        ((u32)0x00000001)        /*!< Filter bit 0 */
#define  CAN_F2R1_FB1                        ((u32)0x00000002)        /*!< Filter bit 1 */
#define  CAN_F2R1_FB2                        ((u32)0x00000004)        /*!< Filter bit 2 */
#define  CAN_F2R1_FB3                        ((u32)0x00000008)        /*!< Filter bit 3 */
#define  CAN_F2R1_FB4                        ((u32)0x00000010)        /*!< Filter bit 4 */
#define  CAN_F2R1_FB5                        ((u32)0x00000020)        /*!< Filter bit 5 */
#define  CAN_F2R1_FB6                        ((u32)0x00000040)        /*!< Filter bit 6 */
#define  CAN_F2R1_FB7                        ((u32)0x00000080)        /*!< Filter bit 7 */
#define  CAN_F2R1_FB8                        ((u32)0x00000100)        /*!< Filter bit 8 */
#define  CAN_F2R1_FB9                        ((u32)0x00000200)        /*!< Filter bit 9 */
#define  CAN_F2R1_FB10                       ((u32)0x00000400)        /*!< Filter bit 10 */
#define  CAN_F2R1_FB11                       ((u32)0x00000800)        /*!< Filter bit 11 */
#define  CAN_F2R1_FB12                       ((u32)0x00001000)        /*!< Filter bit 12 */
#define  CAN_F2R1_FB13                       ((u32)0x00002000)        /*!< Filter bit 13 */
#define  CAN_F2R1_FB14                       ((u32)0x00004000)        /*!< Filter bit 14 */
#define  CAN_F2R1_FB15                       ((u32)0x00008000)        /*!< Filter bit 15 */
#define  CAN_F2R1_FB16                       ((u32)0x00010000)        /*!< Filter bit 16 */
#define  CAN_F2R1_FB17                       ((u32)0x00020000)        /*!< Filter bit 17 */
#define  CAN_F2R1_FB18                       ((u32)0x00040000)        /*!< Filter bit 18 */
#define  CAN_F2R1_FB19                       ((u32)0x00080000)        /*!< Filter bit 19 */
#define  CAN_F2R1_FB20                       ((u32)0x00100000)        /*!< Filter bit 20 */
#define  CAN_F2R1_FB21                       ((u32)0x00200000)        /*!< Filter bit 21 */
#define  CAN_F2R1_FB22                       ((u32)0x00400000)        /*!< Filter bit 22 */
#define  CAN_F2R1_FB23                       ((u32)0x00800000)        /*!< Filter bit 23 */
#define  CAN_F2R1_FB24                       ((u32)0x01000000)        /*!< Filter bit 24 */
#define  CAN_F2R1_FB25                       ((u32)0x02000000)        /*!< Filter bit 25 */
#define  CAN_F2R1_FB26                       ((u32)0x04000000)        /*!< Filter bit 26 */
#define  CAN_F2R1_FB27                       ((u32)0x08000000)        /*!< Filter bit 27 */
#define  CAN_F2R1_FB28                       ((u32)0x10000000)        /*!< Filter bit 28 */
#define  CAN_F2R1_FB29                       ((u32)0x20000000)        /*!< Filter bit 29 */
#define  CAN_F2R1_FB30                       ((u32)0x40000000)        /*!< Filter bit 30 */
#define  CAN_F2R1_FB31                       ((u32)0x80000000)        /*!< Filter bit 31 */

/*******************  Bit definition for CAN_F3R1 register  *******************/
#define  CAN_F3R1_FB0                        ((u32)0x00000001)        /*!< Filter bit 0 */
#define  CAN_F3R1_FB1                        ((u32)0x00000002)        /*!< Filter bit 1 */
#define  CAN_F3R1_FB2                        ((u32)0x00000004)        /*!< Filter bit 2 */
#define  CAN_F3R1_FB3                        ((u32)0x00000008)        /*!< Filter bit 3 */
#define  CAN_F3R1_FB4                        ((u32)0x00000010)        /*!< Filter bit 4 */
#define  CAN_F3R1_FB5                        ((u32)0x00000020)        /*!< Filter bit 5 */
#define  CAN_F3R1_FB6                        ((u32)0x00000040)        /*!< Filter bit 6 */
#define  CAN_F3R1_FB7                        ((u32)0x00000080)        /*!< Filter bit 7 */
#define  CAN_F3R1_FB8                        ((u32)0x00000100)        /*!< Filter bit 8 */
#define  CAN_F3R1_FB9                        ((u32)0x00000200)        /*!< Filter bit 9 */
#define  CAN_F3R1_FB10                       ((u32)0x00000400)        /*!< Filter bit 10 */
#define  CAN_F3R1_FB11                       ((u32)0x00000800)        /*!< Filter bit 11 */
#define  CAN_F3R1_FB12                       ((u32)0x00001000)        /*!< Filter bit 12 */
#define  CAN_F3R1_FB13                       ((u32)0x00002000)        /*!< Filter bit 13 */
#define  CAN_F3R1_FB14                       ((u32)0x00004000)        /*!< Filter bit 14 */
#define  CAN_F3R1_FB15                       ((u32)0x00008000)        /*!< Filter bit 15 */
#define  CAN_F3R1_FB16                       ((u32)0x00010000)        /*!< Filter bit 16 */
#define  CAN_F3R1_FB17                       ((u32)0x00020000)        /*!< Filter bit 17 */
#define  CAN_F3R1_FB18                       ((u32)0x00040000)        /*!< Filter bit 18 */
#define  CAN_F3R1_FB19                       ((u32)0x00080000)        /*!< Filter bit 19 */
#define  CAN_F3R1_FB20                       ((u32)0x00100000)        /*!< Filter bit 20 */
#define  CAN_F3R1_FB21                       ((u32)0x00200000)        /*!< Filter bit 21 */
#define  CAN_F3R1_FB22                       ((u32)0x00400000)        /*!< Filter bit 22 */
#define  CAN_F3R1_FB23                       ((u32)0x00800000)        /*!< Filter bit 23 */
#define  CAN_F3R1_FB24                       ((u32)0x01000000)        /*!< Filter bit 24 */
#define  CAN_F3R1_FB25                       ((u32)0x02000000)        /*!< Filter bit 25 */
#define  CAN_F3R1_FB26                       ((u32)0x04000000)        /*!< Filter bit 26 */
#define  CAN_F3R1_FB27                       ((u32)0x08000000)        /*!< Filter bit 27 */
#define  CAN_F3R1_FB28                       ((u32)0x10000000)        /*!< Filter bit 28 */
#define  CAN_F3R1_FB29                       ((u32)0x20000000)        /*!< Filter bit 29 */
#define  CAN_F3R1_FB30                       ((u32)0x40000000)        /*!< Filter bit 30 */
#define  CAN_F3R1_FB31                       ((u32)0x80000000)        /*!< Filter bit 31 */

/*******************  Bit definition for CAN_F4R1 register  *******************/
#define  CAN_F4R1_FB0                        ((u32)0x00000001)        /*!< Filter bit 0 */
#define  CAN_F4R1_FB1                        ((u32)0x00000002)        /*!< Filter bit 1 */
#define  CAN_F4R1_FB2                        ((u32)0x00000004)        /*!< Filter bit 2 */
#define  CAN_F4R1_FB3                        ((u32)0x00000008)        /*!< Filter bit 3 */
#define  CAN_F4R1_FB4                        ((u32)0x00000010)        /*!< Filter bit 4 */
#define  CAN_F4R1_FB5                        ((u32)0x00000020)        /*!< Filter bit 5 */
#define  CAN_F4R1_FB6                        ((u32)0x00000040)        /*!< Filter bit 6 */
#define  CAN_F4R1_FB7                        ((u32)0x00000080)        /*!< Filter bit 7 */
#define  CAN_F4R1_FB8                        ((u32)0x00000100)        /*!< Filter bit 8 */
#define  CAN_F4R1_FB9                        ((u32)0x00000200)        /*!< Filter bit 9 */
#define  CAN_F4R1_FB10                       ((u32)0x00000400)        /*!< Filter bit 10 */
#define  CAN_F4R1_FB11                       ((u32)0x00000800)        /*!< Filter bit 11 */
#define  CAN_F4R1_FB12                       ((u32)0x00001000)        /*!< Filter bit 12 */
#define  CAN_F4R1_FB13                       ((u32)0x00002000)        /*!< Filter bit 13 */
#define  CAN_F4R1_FB14                       ((u32)0x00004000)        /*!< Filter bit 14 */
#define  CAN_F4R1_FB15                       ((u32)0x00008000)        /*!< Filter bit 15 */
#define  CAN_F4R1_FB16                       ((u32)0x00010000)        /*!< Filter bit 16 */
#define  CAN_F4R1_FB17                       ((u32)0x00020000)        /*!< Filter bit 17 */
#define  CAN_F4R1_FB18                       ((u32)0x00040000)        /*!< Filter bit 18 */
#define  CAN_F4R1_FB19                       ((u32)0x00080000)        /*!< Filter bit 19 */
#define  CAN_F4R1_FB20                       ((u32)0x00100000)        /*!< Filter bit 20 */
#define  CAN_F4R1_FB21                       ((u32)0x00200000)        /*!< Filter bit 21 */
#define  CAN_F4R1_FB22                       ((u32)0x00400000)        /*!< Filter bit 22 */
#define  CAN_F4R1_FB23                       ((u32)0x00800000)        /*!< Filter bit 23 */
#define  CAN_F4R1_FB24                       ((u32)0x01000000)        /*!< Filter bit 24 */
#define  CAN_F4R1_FB25                       ((u32)0x02000000)        /*!< Filter bit 25 */
#define  CAN_F4R1_FB26                       ((u32)0x04000000)        /*!< Filter bit 26 */
#define  CAN_F4R1_FB27                       ((u32)0x08000000)        /*!< Filter bit 27 */
#define  CAN_F4R1_FB28                       ((u32)0x10000000)        /*!< Filter bit 28 */
#define  CAN_F4R1_FB29                       ((u32)0x20000000)        /*!< Filter bit 29 */
#define  CAN_F4R1_FB30                       ((u32)0x40000000)        /*!< Filter bit 30 */
#define  CAN_F4R1_FB31                       ((u32)0x80000000)        /*!< Filter bit 31 */

/*******************  Bit definition for CAN_F5R1 register  *******************/
#define  CAN_F5R1_FB0                        ((u32)0x00000001)        /*!< Filter bit 0 */
#define  CAN_F5R1_FB1                        ((u32)0x00000002)        /*!< Filter bit 1 */
#define  CAN_F5R1_FB2                        ((u32)0x00000004)        /*!< Filter bit 2 */
#define  CAN_F5R1_FB3                        ((u32)0x00000008)        /*!< Filter bit 3 */
#define  CAN_F5R1_FB4                        ((u32)0x00000010)        /*!< Filter bit 4 */
#define  CAN_F5R1_FB5                        ((u32)0x00000020)        /*!< Filter bit 5 */
#define  CAN_F5R1_FB6                        ((u32)0x00000040)        /*!< Filter bit 6 */
#define  CAN_F5R1_FB7                        ((u32)0x00000080)        /*!< Filter bit 7 */
#define  CAN_F5R1_FB8                        ((u32)0x00000100)        /*!< Filter bit 8 */
#define  CAN_F5R1_FB9                        ((u32)0x00000200)        /*!< Filter bit 9 */
#define  CAN_F5R1_FB10                       ((u32)0x00000400)        /*!< Filter bit 10 */
#define  CAN_F5R1_FB11                       ((u32)0x00000800)        /*!< Filter bit 11 */
#define  CAN_F5R1_FB12                       ((u32)0x00001000)        /*!< Filter bit 12 */
#define  CAN_F5R1_FB13                       ((u32)0x00002000)        /*!< Filter bit 13 */
#define  CAN_F5R1_FB14                       ((u32)0x00004000)        /*!< Filter bit 14 */
#define  CAN_F5R1_FB15                       ((u32)0x00008000)        /*!< Filter bit 15 */
#define  CAN_F5R1_FB16                       ((u32)0x00010000)        /*!< Filter bit 16 */
#define  CAN_F5R1_FB17                       ((u32)0x00020000)        /*!< Filter bit 17 */
#define  CAN_F5R1_FB18                       ((u32)0x00040000)        /*!< Filter bit 18 */
#define  CAN_F5R1_FB19                       ((u32)0x00080000)        /*!< Filter bit 19 */
#define  CAN_F5R1_FB20                       ((u32)0x00100000)        /*!< Filter bit 20 */
#define  CAN_F5R1_FB21                       ((u32)0x00200000)        /*!< Filter bit 21 */
#define  CAN_F5R1_FB22                       ((u32)0x00400000)        /*!< Filter bit 22 */
#define  CAN_F5R1_FB23                       ((u32)0x00800000)        /*!< Filter bit 23 */
#define  CAN_F5R1_FB24                       ((u32)0x01000000)        /*!< Filter bit 24 */
#define  CAN_F5R1_FB25                       ((u32)0x02000000)        /*!< Filter bit 25 */
#define  CAN_F5R1_FB26                       ((u32)0x04000000)        /*!< Filter bit 26 */
#define  CAN_F5R1_FB27                       ((u32)0x08000000)        /*!< Filter bit 27 */
#define  CAN_F5R1_FB28                       ((u32)0x10000000)        /*!< Filter bit 28 */
#define  CAN_F5R1_FB29                       ((u32)0x20000000)        /*!< Filter bit 29 */
#define  CAN_F5R1_FB30                       ((u32)0x40000000)        /*!< Filter bit 30 */
#define  CAN_F5R1_FB31                       ((u32)0x80000000)        /*!< Filter bit 31 */

/*******************  Bit definition for CAN_F6R1 register  *******************/
#define  CAN_F6R1_FB0                        ((u32)0x00000001)        /*!< Filter bit 0 */
#define  CAN_F6R1_FB1                        ((u32)0x00000002)        /*!< Filter bit 1 */
#define  CAN_F6R1_FB2                        ((u32)0x00000004)        /*!< Filter bit 2 */
#define  CAN_F6R1_FB3                        ((u32)0x00000008)        /*!< Filter bit 3 */
#define  CAN_F6R1_FB4                        ((u32)0x00000010)        /*!< Filter bit 4 */
#define  CAN_F6R1_FB5                        ((u32)0x00000020)        /*!< Filter bit 5 */
#define  CAN_F6R1_FB6                        ((u32)0x00000040)        /*!< Filter bit 6 */
#define  CAN_F6R1_FB7                        ((u32)0x00000080)        /*!< Filter bit 7 */
#define  CAN_F6R1_FB8                        ((u32)0x00000100)        /*!< Filter bit 8 */
#define  CAN_F6R1_FB9                        ((u32)0x00000200)        /*!< Filter bit 9 */
#define  CAN_F6R1_FB10                       ((u32)0x00000400)        /*!< Filter bit 10 */
#define  CAN_F6R1_FB11                       ((u32)0x00000800)        /*!< Filter bit 11 */
#define  CAN_F6R1_FB12                       ((u32)0x00001000)        /*!< Filter bit 12 */
#define  CAN_F6R1_FB13                       ((u32)0x00002000)        /*!< Filter bit 13 */
#define  CAN_F6R1_FB14                       ((u32)0x00004000)        /*!< Filter bit 14 */
#define  CAN_F6R1_FB15                       ((u32)0x00008000)        /*!< Filter bit 15 */
#define  CAN_F6R1_FB16                       ((u32)0x00010000)        /*!< Filter bit 16 */
#define  CAN_F6R1_FB17                       ((u32)0x00020000)        /*!< Filter bit 17 */
#define  CAN_F6R1_FB18                       ((u32)0x00040000)        /*!< Filter bit 18 */
#define  CAN_F6R1_FB19                       ((u32)0x00080000)        /*!< Filter bit 19 */
#define  CAN_F6R1_FB20                       ((u32)0x00100000)        /*!< Filter bit 20 */
#define  CAN_F6R1_FB21                       ((u32)0x00200000)        /*!< Filter bit 21 */
#define  CAN_F6R1_FB22                       ((u32)0x00400000)        /*!< Filter bit 22 */
#define  CAN_F6R1_FB23                       ((u32)0x00800000)        /*!< Filter bit 23 */
#define  CAN_F6R1_FB24                       ((u32)0x01000000)        /*!< Filter bit 24 */
#define  CAN_F6R1_FB25                       ((u32)0x02000000)        /*!< Filter bit 25 */
#define  CAN_F6R1_FB26                       ((u32)0x04000000)        /*!< Filter bit 26 */
#define  CAN_F6R1_FB27                       ((u32)0x08000000)        /*!< Filter bit 27 */
#define  CAN_F6R1_FB28                       ((u32)0x10000000)        /*!< Filter bit 28 */
#define  CAN_F6R1_FB29                       ((u32)0x20000000)        /*!< Filter bit 29 */
#define  CAN_F6R1_FB30                       ((u32)0x40000000)        /*!< Filter bit 30 */
#define  CAN_F6R1_FB31                       ((u32)0x80000000)        /*!< Filter bit 31 */

/*******************  Bit definition for CAN_F7R1 register  *******************/
#define  CAN_F7R1_FB0                        ((u32)0x00000001)        /*!< Filter bit 0 */
#define  CAN_F7R1_FB1                        ((u32)0x00000002)        /*!< Filter bit 1 */
#define  CAN_F7R1_FB2                        ((u32)0x00000004)        /*!< Filter bit 2 */
#define  CAN_F7R1_FB3                        ((u32)0x00000008)        /*!< Filter bit 3 */
#define  CAN_F7R1_FB4                        ((u32)0x00000010)        /*!< Filter bit 4 */
#define  CAN_F7R1_FB5                        ((u32)0x00000020)        /*!< Filter bit 5 */
#define  CAN_F7R1_FB6                        ((u32)0x00000040)        /*!< Filter bit 6 */
#define  CAN_F7R1_FB7                        ((u32)0x00000080)        /*!< Filter bit 7 */
#define  CAN_F7R1_FB8                        ((u32)0x00000100)        /*!< Filter bit 8 */
#define  CAN_F7R1_FB9                        ((u32)0x00000200)        /*!< Filter bit 9 */
#define  CAN_F7R1_FB10                       ((u32)0x00000400)        /*!< Filter bit 10 */
#define  CAN_F7R1_FB11                       ((u32)0x00000800)        /*!< Filter bit 11 */
#define  CAN_F7R1_FB12                       ((u32)0x00001000)        /*!< Filter bit 12 */
#define  CAN_F7R1_FB13                       ((u32)0x00002000)        /*!< Filter bit 13 */
#define  CAN_F7R1_FB14                       ((u32)0x00004000)        /*!< Filter bit 14 */
#define  CAN_F7R1_FB15                       ((u32)0x00008000)        /*!< Filter bit 15 */
#define  CAN_F7R1_FB16                       ((u32)0x00010000)        /*!< Filter bit 16 */
#define  CAN_F7R1_FB17                       ((u32)0x00020000)        /*!< Filter bit 17 */
#define  CAN_F7R1_FB18                       ((u32)0x00040000)        /*!< Filter bit 18 */
#define  CAN_F7R1_FB19                       ((u32)0x00080000)        /*!< Filter bit 19 */
#define  CAN_F7R1_FB20                       ((u32)0x00100000)        /*!< Filter bit 20 */
#define  CAN_F7R1_FB21                       ((u32)0x00200000)        /*!< Filter bit 21 */
#define  CAN_F7R1_FB22                       ((u32)0x00400000)        /*!< Filter bit 22 */
#define  CAN_F7R1_FB23                       ((u32)0x00800000)        /*!< Filter bit 23 */
#define  CAN_F7R1_FB24                       ((u32)0x01000000)        /*!< Filter bit 24 */
#define  CAN_F7R1_FB25                       ((u32)0x02000000)        /*!< Filter bit 25 */
#define  CAN_F7R1_FB26                       ((u32)0x04000000)        /*!< Filter bit 26 */
#define  CAN_F7R1_FB27                       ((u32)0x08000000)        /*!< Filter bit 27 */
#define  CAN_F7R1_FB28                       ((u32)0x10000000)        /*!< Filter bit 28 */
#define  CAN_F7R1_FB29                       ((u32)0x20000000)        /*!< Filter bit 29 */
#define  CAN_F7R1_FB30                       ((u32)0x40000000)        /*!< Filter bit 30 */
#define  CAN_F7R1_FB31                       ((u32)0x80000000)        /*!< Filter bit 31 */

/*******************  Bit definition for CAN_F8R1 register  *******************/
#define  CAN_F8R1_FB0                        ((u32)0x00000001)        /*!< Filter bit 0 */
#define  CAN_F8R1_FB1                        ((u32)0x00000002)        /*!< Filter bit 1 */
#define  CAN_F8R1_FB2                        ((u32)0x00000004)        /*!< Filter bit 2 */
#define  CAN_F8R1_FB3                        ((u32)0x00000008)        /*!< Filter bit 3 */
#define  CAN_F8R1_FB4                        ((u32)0x00000010)        /*!< Filter bit 4 */
#define  CAN_F8R1_FB5                        ((u32)0x00000020)        /*!< Filter bit 5 */
#define  CAN_F8R1_FB6                        ((u32)0x00000040)        /*!< Filter bit 6 */
#define  CAN_F8R1_FB7                        ((u32)0x00000080)        /*!< Filter bit 7 */
#define  CAN_F8R1_FB8                        ((u32)0x00000100)        /*!< Filter bit 8 */
#define  CAN_F8R1_FB9                        ((u32)0x00000200)        /*!< Filter bit 9 */
#define  CAN_F8R1_FB10                       ((u32)0x00000400)        /*!< Filter bit 10 */
#define  CAN_F8R1_FB11                       ((u32)0x00000800)        /*!< Filter bit 11 */
#define  CAN_F8R1_FB12                       ((u32)0x00001000)        /*!< Filter bit 12 */
#define  CAN_F8R1_FB13                       ((u32)0x00002000)        /*!< Filter bit 13 */
#define  CAN_F8R1_FB14                       ((u32)0x00004000)        /*!< Filter bit 14 */
#define  CAN_F8R1_FB15                       ((u32)0x00008000)        /*!< Filter bit 15 */
#define  CAN_F8R1_FB16                       ((u32)0x00010000)        /*!< Filter bit 16 */
#define  CAN_F8R1_FB17                       ((u32)0x00020000)        /*!< Filter bit 17 */
#define  CAN_F8R1_FB18                       ((u32)0x00040000)        /*!< Filter bit 18 */
#define  CAN_F8R1_FB19                       ((u32)0x00080000)        /*!< Filter bit 19 */
#define  CAN_F8R1_FB20                       ((u32)0x00100000)        /*!< Filter bit 20 */
#define  CAN_F8R1_FB21                       ((u32)0x00200000)        /*!< Filter bit 21 */
#define  CAN_F8R1_FB22                       ((u32)0x00400000)        /*!< Filter bit 22 */
#define  CAN_F8R1_FB23                       ((u32)0x00800000)        /*!< Filter bit 23 */
#define  CAN_F8R1_FB24                       ((u32)0x01000000)        /*!< Filter bit 24 */
#define  CAN_F8R1_FB25                       ((u32)0x02000000)        /*!< Filter bit 25 */
#define  CAN_F8R1_FB26                       ((u32)0x04000000)        /*!< Filter bit 26 */
#define  CAN_F8R1_FB27                       ((u32)0x08000000)        /*!< Filter bit 27 */
#define  CAN_F8R1_FB28                       ((u32)0x10000000)        /*!< Filter bit 28 */
#define  CAN_F8R1_FB29                       ((u32)0x20000000)        /*!< Filter bit 29 */
#define  CAN_F8R1_FB30                       ((u32)0x40000000)        /*!< Filter bit 30 */
#define  CAN_F8R1_FB31                       ((u32)0x80000000)        /*!< Filter bit 31 */

/*******************  Bit definition for CAN_F9R1 register  *******************/
#define  CAN_F9R1_FB0                        ((u32)0x00000001)        /*!< Filter bit 0 */
#define  CAN_F9R1_FB1                        ((u32)0x00000002)        /*!< Filter bit 1 */
#define  CAN_F9R1_FB2                        ((u32)0x00000004)        /*!< Filter bit 2 */
#define  CAN_F9R1_FB3                        ((u32)0x00000008)        /*!< Filter bit 3 */
#define  CAN_F9R1_FB4                        ((u32)0x00000010)        /*!< Filter bit 4 */
#define  CAN_F9R1_FB5                        ((u32)0x00000020)        /*!< Filter bit 5 */
#define  CAN_F9R1_FB6                        ((u32)0x00000040)        /*!< Filter bit 6 */
#define  CAN_F9R1_FB7                        ((u32)0x00000080)        /*!< Filter bit 7 */
#define  CAN_F9R1_FB8                        ((u32)0x00000100)        /*!< Filter bit 8 */
#define  CAN_F9R1_FB9                        ((u32)0x00000200)        /*!< Filter bit 9 */
#define  CAN_F9R1_FB10                       ((u32)0x00000400)        /*!< Filter bit 10 */
#define  CAN_F9R1_FB11                       ((u32)0x00000800)        /*!< Filter bit 11 */
#define  CAN_F9R1_FB12                       ((u32)0x00001000)        /*!< Filter bit 12 */
#define  CAN_F9R1_FB13                       ((u32)0x00002000)        /*!< Filter bit 13 */
#define  CAN_F9R1_FB14                       ((u32)0x00004000)        /*!< Filter bit 14 */
#define  CAN_F9R1_FB15                       ((u32)0x00008000)        /*!< Filter bit 15 */
#define  CAN_F9R1_FB16                       ((u32)0x00010000)        /*!< Filter bit 16 */
#define  CAN_F9R1_FB17                       ((u32)0x00020000)        /*!< Filter bit 17 */
#define  CAN_F9R1_FB18                       ((u32)0x00040000)        /*!< Filter bit 18 */
#define  CAN_F9R1_FB19                       ((u32)0x00080000)        /*!< Filter bit 19 */
#define  CAN_F9R1_FB20                       ((u32)0x00100000)        /*!< Filter bit 20 */
#define  CAN_F9R1_FB21                       ((u32)0x00200000)        /*!< Filter bit 21 */
#define  CAN_F9R1_FB22                       ((u32)0x00400000)        /*!< Filter bit 22 */
#define  CAN_F9R1_FB23                       ((u32)0x00800000)        /*!< Filter bit 23 */
#define  CAN_F9R1_FB24                       ((u32)0x01000000)        /*!< Filter bit 24 */
#define  CAN_F9R1_FB25                       ((u32)0x02000000)        /*!< Filter bit 25 */
#define  CAN_F9R1_FB26                       ((u32)0x04000000)        /*!< Filter bit 26 */
#define  CAN_F9R1_FB27                       ((u32)0x08000000)        /*!< Filter bit 27 */
#define  CAN_F9R1_FB28                       ((u32)0x10000000)        /*!< Filter bit 28 */
#define  CAN_F9R1_FB29                       ((u32)0x20000000)        /*!< Filter bit 29 */
#define  CAN_F9R1_FB30                       ((u32)0x40000000)        /*!< Filter bit 30 */
#define  CAN_F9R1_FB31                       ((u32)0x80000000)        /*!< Filter bit 31 */

/*******************  Bit definition for CAN_F10R1 register  ******************/
#define  CAN_F10R1_FB0                       ((u32)0x00000001)        /*!< Filter bit 0 */
#define  CAN_F10R1_FB1                       ((u32)0x00000002)        /*!< Filter bit 1 */
#define  CAN_F10R1_FB2                       ((u32)0x00000004)        /*!< Filter bit 2 */
#define  CAN_F10R1_FB3                       ((u32)0x00000008)        /*!< Filter bit 3 */
#define  CAN_F10R1_FB4                       ((u32)0x00000010)        /*!< Filter bit 4 */
#define  CAN_F10R1_FB5                       ((u32)0x00000020)        /*!< Filter bit 5 */
#define  CAN_F10R1_FB6                       ((u32)0x00000040)        /*!< Filter bit 6 */
#define  CAN_F10R1_FB7                       ((u32)0x00000080)        /*!< Filter bit 7 */
#define  CAN_F10R1_FB8                       ((u32)0x00000100)        /*!< Filter bit 8 */
#define  CAN_F10R1_FB9                       ((u32)0x00000200)        /*!< Filter bit 9 */
#define  CAN_F10R1_FB10                      ((u32)0x00000400)        /*!< Filter bit 10 */
#define  CAN_F10R1_FB11                      ((u32)0x00000800)        /*!< Filter bit 11 */
#define  CAN_F10R1_FB12                      ((u32)0x00001000)        /*!< Filter bit 12 */
#define  CAN_F10R1_FB13                      ((u32)0x00002000)        /*!< Filter bit 13 */
#define  CAN_F10R1_FB14                      ((u32)0x00004000)        /*!< Filter bit 14 */
#define  CAN_F10R1_FB15                      ((u32)0x00008000)        /*!< Filter bit 15 */
#define  CAN_F10R1_FB16                      ((u32)0x00010000)        /*!< Filter bit 16 */
#define  CAN_F10R1_FB17                      ((u32)0x00020000)        /*!< Filter bit 17 */
#define  CAN_F10R1_FB18                      ((u32)0x00040000)        /*!< Filter bit 18 */
#define  CAN_F10R1_FB19                      ((u32)0x00080000)        /*!< Filter bit 19 */
#define  CAN_F10R1_FB20                      ((u32)0x00100000)        /*!< Filter bit 20 */
#define  CAN_F10R1_FB21                      ((u32)0x00200000)        /*!< Filter bit 21 */
#define  CAN_F10R1_FB22                      ((u32)0x00400000)        /*!< Filter bit 22 */
#define  CAN_F10R1_FB23                      ((u32)0x00800000)        /*!< Filter bit 23 */
#define  CAN_F10R1_FB24                      ((u32)0x01000000)        /*!< Filter bit 24 */
#define  CAN_F10R1_FB25                      ((u32)0x02000000)        /*!< Filter bit 25 */
#define  CAN_F10R1_FB26                      ((u32)0x04000000)        /*!< Filter bit 26 */
#define  CAN_F10R1_FB27                      ((u32)0x08000000)        /*!< Filter bit 27 */
#define  CAN_F10R1_FB28                      ((u32)0x10000000)        /*!< Filter bit 28 */
#define  CAN_F10R1_FB29                      ((u32)0x20000000)        /*!< Filter bit 29 */
#define  CAN_F10R1_FB30                      ((u32)0x40000000)        /*!< Filter bit 30 */
#define  CAN_F10R1_FB31                      ((u32)0x80000000)        /*!< Filter bit 31 */

/*******************  Bit definition for CAN_F11R1 register  ******************/
#define  CAN_F11R1_FB0                       ((u32)0x00000001)        /*!< Filter bit 0 */
#define  CAN_F11R1_FB1                       ((u32)0x00000002)        /*!< Filter bit 1 */
#define  CAN_F11R1_FB2                       ((u32)0x00000004)        /*!< Filter bit 2 */
#define  CAN_F11R1_FB3                       ((u32)0x00000008)        /*!< Filter bit 3 */
#define  CAN_F11R1_FB4                       ((u32)0x00000010)        /*!< Filter bit 4 */
#define  CAN_F11R1_FB5                       ((u32)0x00000020)        /*!< Filter bit 5 */
#define  CAN_F11R1_FB6                       ((u32)0x00000040)        /*!< Filter bit 6 */
#define  CAN_F11R1_FB7                       ((u32)0x00000080)        /*!< Filter bit 7 */
#define  CAN_F11R1_FB8                       ((u32)0x00000100)        /*!< Filter bit 8 */
#define  CAN_F11R1_FB9                       ((u32)0x00000200)        /*!< Filter bit 9 */
#define  CAN_F11R1_FB10                      ((u32)0x00000400)        /*!< Filter bit 10 */
#define  CAN_F11R1_FB11                      ((u32)0x00000800)        /*!< Filter bit 11 */
#define  CAN_F11R1_FB12                      ((u32)0x00001000)        /*!< Filter bit 12 */
#define  CAN_F11R1_FB13                      ((u32)0x00002000)        /*!< Filter bit 13 */
#define  CAN_F11R1_FB14                      ((u32)0x00004000)        /*!< Filter bit 14 */
#define  CAN_F11R1_FB15                      ((u32)0x00008000)        /*!< Filter bit 15 */
#define  CAN_F11R1_FB16                      ((u32)0x00010000)        /*!< Filter bit 16 */
#define  CAN_F11R1_FB17                      ((u32)0x00020000)        /*!< Filter bit 17 */
#define  CAN_F11R1_FB18                      ((u32)0x00040000)        /*!< Filter bit 18 */
#define  CAN_F11R1_FB19                      ((u32)0x00080000)        /*!< Filter bit 19 */
#define  CAN_F11R1_FB20                      ((u32)0x00100000)        /*!< Filter bit 20 */
#define  CAN_F11R1_FB21                      ((u32)0x00200000)        /*!< Filter bit 21 */
#define  CAN_F11R1_FB22                      ((u32)0x00400000)        /*!< Filter bit 22 */
#define  CAN_F11R1_FB23                      ((u32)0x00800000)        /*!< Filter bit 23 */
#define  CAN_F11R1_FB24                      ((u32)0x01000000)        /*!< Filter bit 24 */
#define  CAN_F11R1_FB25                      ((u32)0x02000000)        /*!< Filter bit 25 */
#define  CAN_F11R1_FB26                      ((u32)0x04000000)        /*!< Filter bit 26 */
#define  CAN_F11R1_FB27                      ((u32)0x08000000)        /*!< Filter bit 27 */
#define  CAN_F11R1_FB28                      ((u32)0x10000000)        /*!< Filter bit 28 */
#define  CAN_F11R1_FB29                      ((u32)0x20000000)        /*!< Filter bit 29 */
#define  CAN_F11R1_FB30                      ((u32)0x40000000)        /*!< Filter bit 30 */
#define  CAN_F11R1_FB31                      ((u32)0x80000000)        /*!< Filter bit 31 */

/*******************  Bit definition for CAN_F12R1 register  ******************/
#define  CAN_F12R1_FB0                       ((u32)0x00000001)        /*!< Filter bit 0 */
#define  CAN_F12R1_FB1                       ((u32)0x00000002)        /*!< Filter bit 1 */
#define  CAN_F12R1_FB2                       ((u32)0x00000004)        /*!< Filter bit 2 */
#define  CAN_F12R1_FB3                       ((u32)0x00000008)        /*!< Filter bit 3 */
#define  CAN_F12R1_FB4                       ((u32)0x00000010)        /*!< Filter bit 4 */
#define  CAN_F12R1_FB5                       ((u32)0x00000020)        /*!< Filter bit 5 */
#define  CAN_F12R1_FB6                       ((u32)0x00000040)        /*!< Filter bit 6 */
#define  CAN_F12R1_FB7                       ((u32)0x00000080)        /*!< Filter bit 7 */
#define  CAN_F12R1_FB8                       ((u32)0x00000100)        /*!< Filter bit 8 */
#define  CAN_F12R1_FB9                       ((u32)0x00000200)        /*!< Filter bit 9 */
#define  CAN_F12R1_FB10                      ((u32)0x00000400)        /*!< Filter bit 10 */
#define  CAN_F12R1_FB11                      ((u32)0x00000800)        /*!< Filter bit 11 */
#define  CAN_F12R1_FB12                      ((u32)0x00001000)        /*!< Filter bit 12 */
#define  CAN_F12R1_FB13                      ((u32)0x00002000)        /*!< Filter bit 13 */
#define  CAN_F12R1_FB14                      ((u32)0x00004000)        /*!< Filter bit 14 */
#define  CAN_F12R1_FB15                      ((u32)0x00008000)        /*!< Filter bit 15 */
#define  CAN_F12R1_FB16                      ((u32)0x00010000)        /*!< Filter bit 16 */
#define  CAN_F12R1_FB17                      ((u32)0x00020000)        /*!< Filter bit 17 */
#define  CAN_F12R1_FB18                      ((u32)0x00040000)        /*!< Filter bit 18 */
#define  CAN_F12R1_FB19                      ((u32)0x00080000)        /*!< Filter bit 19 */
#define  CAN_F12R1_FB20                      ((u32)0x00100000)        /*!< Filter bit 20 */
#define  CAN_F12R1_FB21                      ((u32)0x00200000)        /*!< Filter bit 21 */
#define  CAN_F12R1_FB22                      ((u32)0x00400000)        /*!< Filter bit 22 */
#define  CAN_F12R1_FB23                      ((u32)0x00800000)        /*!< Filter bit 23 */
#define  CAN_F12R1_FB24                      ((u32)0x01000000)        /*!< Filter bit 24 */
#define  CAN_F12R1_FB25                      ((u32)0x02000000)        /*!< Filter bit 25 */
#define  CAN_F12R1_FB26                      ((u32)0x04000000)        /*!< Filter bit 26 */
#define  CAN_F12R1_FB27                      ((u32)0x08000000)        /*!< Filter bit 27 */
#define  CAN_F12R1_FB28                      ((u32)0x10000000)        /*!< Filter bit 28 */
#define  CAN_F12R1_FB29                      ((u32)0x20000000)        /*!< Filter bit 29 */
#define  CAN_F12R1_FB30                      ((u32)0x40000000)        /*!< Filter bit 30 */
#define  CAN_F12R1_FB31                      ((u32)0x80000000)        /*!< Filter bit 31 */

/*******************  Bit definition for CAN_F13R1 register  ******************/
#define  CAN_F13R1_FB0                       ((u32)0x00000001)        /*!< Filter bit 0 */
#define  CAN_F13R1_FB1                       ((u32)0x00000002)        /*!< Filter bit 1 */
#define  CAN_F13R1_FB2                       ((u32)0x00000004)        /*!< Filter bit 2 */
#define  CAN_F13R1_FB3                       ((u32)0x00000008)        /*!< Filter bit 3 */
#define  CAN_F13R1_FB4                       ((u32)0x00000010)        /*!< Filter bit 4 */
#define  CAN_F13R1_FB5                       ((u32)0x00000020)        /*!< Filter bit 5 */
#define  CAN_F13R1_FB6                       ((u32)0x00000040)        /*!< Filter bit 6 */
#define  CAN_F13R1_FB7                       ((u32)0x00000080)        /*!< Filter bit 7 */
#define  CAN_F13R1_FB8                       ((u32)0x00000100)        /*!< Filter bit 8 */
#define  CAN_F13R1_FB9                       ((u32)0x00000200)        /*!< Filter bit 9 */
#define  CAN_F13R1_FB10                      ((u32)0x00000400)        /*!< Filter bit 10 */
#define  CAN_F13R1_FB11                      ((u32)0x00000800)        /*!< Filter bit 11 */
#define  CAN_F13R1_FB12                      ((u32)0x00001000)        /*!< Filter bit 12 */
#define  CAN_F13R1_FB13                      ((u32)0x00002000)        /*!< Filter bit 13 */
#define  CAN_F13R1_FB14                      ((u32)0x00004000)        /*!< Filter bit 14 */
#define  CAN_F13R1_FB15                      ((u32)0x00008000)        /*!< Filter bit 15 */
#define  CAN_F13R1_FB16                      ((u32)0x00010000)        /*!< Filter bit 16 */
#define  CAN_F13R1_FB17                      ((u32)0x00020000)        /*!< Filter bit 17 */
#define  CAN_F13R1_FB18                      ((u32)0x00040000)        /*!< Filter bit 18 */
#define  CAN_F13R1_FB19                      ((u32)0x00080000)        /*!< Filter bit 19 */
#define  CAN_F13R1_FB20                      ((u32)0x00100000)        /*!< Filter bit 20 */
#define  CAN_F13R1_FB21                      ((u32)0x00200000)        /*!< Filter bit 21 */
#define  CAN_F13R1_FB22                      ((u32)0x00400000)        /*!< Filter bit 22 */
#define  CAN_F13R1_FB23                      ((u32)0x00800000)        /*!< Filter bit 23 */
#define  CAN_F13R1_FB24                      ((u32)0x01000000)        /*!< Filter bit 24 */
#define  CAN_F13R1_FB25                      ((u32)0x02000000)        /*!< Filter bit 25 */
#define  CAN_F13R1_FB26                      ((u32)0x04000000)        /*!< Filter bit 26 */
#define  CAN_F13R1_FB27                      ((u32)0x08000000)        /*!< Filter bit 27 */
#define  CAN_F13R1_FB28                      ((u32)0x10000000)        /*!< Filter bit 28 */
#define  CAN_F13R1_FB29                      ((u32)0x20000000)        /*!< Filter bit 29 */
#define  CAN_F13R1_FB30                      ((u32)0x40000000)        /*!< Filter bit 30 */
#define  CAN_F13R1_FB31                      ((u32)0x80000000)        /*!< Filter bit 31 */

/*******************  Bit definition for CAN_F0R2 register  *******************/
#define  CAN_F0R2_FB0                        ((u32)0x00000001)        /*!< Filter bit 0 */
#define  CAN_F0R2_FB1                        ((u32)0x00000002)        /*!< Filter bit 1 */
#define  CAN_F0R2_FB2                        ((u32)0x00000004)        /*!< Filter bit 2 */
#define  CAN_F0R2_FB3                        ((u32)0x00000008)        /*!< Filter bit 3 */
#define  CAN_F0R2_FB4                        ((u32)0x00000010)        /*!< Filter bit 4 */
#define  CAN_F0R2_FB5                        ((u32)0x00000020)        /*!< Filter bit 5 */
#define  CAN_F0R2_FB6                        ((u32)0x00000040)        /*!< Filter bit 6 */
#define  CAN_F0R2_FB7                        ((u32)0x00000080)        /*!< Filter bit 7 */
#define  CAN_F0R2_FB8                        ((u32)0x00000100)        /*!< Filter bit 8 */
#define  CAN_F0R2_FB9                        ((u32)0x00000200)        /*!< Filter bit 9 */
#define  CAN_F0R2_FB10                       ((u32)0x00000400)        /*!< Filter bit 10 */
#define  CAN_F0R2_FB11                       ((u32)0x00000800)        /*!< Filter bit 11 */
#define  CAN_F0R2_FB12                       ((u32)0x00001000)        /*!< Filter bit 12 */
#define  CAN_F0R2_FB13                       ((u32)0x00002000)        /*!< Filter bit 13 */
#define  CAN_F0R2_FB14                       ((u32)0x00004000)        /*!< Filter bit 14 */
#define  CAN_F0R2_FB15                       ((u32)0x00008000)        /*!< Filter bit 15 */
#define  CAN_F0R2_FB16                       ((u32)0x00010000)        /*!< Filter bit 16 */
#define  CAN_F0R2_FB17                       ((u32)0x00020000)        /*!< Filter bit 17 */
#define  CAN_F0R2_FB18                       ((u32)0x00040000)        /*!< Filter bit 18 */
#define  CAN_F0R2_FB19                       ((u32)0x00080000)        /*!< Filter bit 19 */
#define  CAN_F0R2_FB20                       ((u32)0x00100000)        /*!< Filter bit 20 */
#define  CAN_F0R2_FB21                       ((u32)0x00200000)        /*!< Filter bit 21 */
#define  CAN_F0R2_FB22                       ((u32)0x00400000)        /*!< Filter bit 22 */
#define  CAN_F0R2_FB23                       ((u32)0x00800000)        /*!< Filter bit 23 */
#define  CAN_F0R2_FB24                       ((u32)0x01000000)        /*!< Filter bit 24 */
#define  CAN_F0R2_FB25                       ((u32)0x02000000)        /*!< Filter bit 25 */
#define  CAN_F0R2_FB26                       ((u32)0x04000000)        /*!< Filter bit 26 */
#define  CAN_F0R2_FB27                       ((u32)0x08000000)        /*!< Filter bit 27 */
#define  CAN_F0R2_FB28                       ((u32)0x10000000)        /*!< Filter bit 28 */
#define  CAN_F0R2_FB29                       ((u32)0x20000000)        /*!< Filter bit 29 */
#define  CAN_F0R2_FB30                       ((u32)0x40000000)        /*!< Filter bit 30 */
#define  CAN_F0R2_FB31                       ((u32)0x80000000)        /*!< Filter bit 31 */

/*******************  Bit definition for CAN_F1R2 register  *******************/
#define  CAN_F1R2_FB0                        ((u32)0x00000001)        /*!< Filter bit 0 */
#define  CAN_F1R2_FB1                        ((u32)0x00000002)        /*!< Filter bit 1 */
#define  CAN_F1R2_FB2                        ((u32)0x00000004)        /*!< Filter bit 2 */
#define  CAN_F1R2_FB3                        ((u32)0x00000008)        /*!< Filter bit 3 */
#define  CAN_F1R2_FB4                        ((u32)0x00000010)        /*!< Filter bit 4 */
#define  CAN_F1R2_FB5                        ((u32)0x00000020)        /*!< Filter bit 5 */
#define  CAN_F1R2_FB6                        ((u32)0x00000040)        /*!< Filter bit 6 */
#define  CAN_F1R2_FB7                        ((u32)0x00000080)        /*!< Filter bit 7 */
#define  CAN_F1R2_FB8                        ((u32)0x00000100)        /*!< Filter bit 8 */
#define  CAN_F1R2_FB9                        ((u32)0x00000200)        /*!< Filter bit 9 */
#define  CAN_F1R2_FB10                       ((u32)0x00000400)        /*!< Filter bit 10 */
#define  CAN_F1R2_FB11                       ((u32)0x00000800)        /*!< Filter bit 11 */
#define  CAN_F1R2_FB12                       ((u32)0x00001000)        /*!< Filter bit 12 */
#define  CAN_F1R2_FB13                       ((u32)0x00002000)        /*!< Filter bit 13 */
#define  CAN_F1R2_FB14                       ((u32)0x00004000)        /*!< Filter bit 14 */
#define  CAN_F1R2_FB15                       ((u32)0x00008000)        /*!< Filter bit 15 */
#define  CAN_F1R2_FB16                       ((u32)0x00010000)        /*!< Filter bit 16 */
#define  CAN_F1R2_FB17                       ((u32)0x00020000)        /*!< Filter bit 17 */
#define  CAN_F1R2_FB18                       ((u32)0x00040000)        /*!< Filter bit 18 */
#define  CAN_F1R2_FB19                       ((u32)0x00080000)        /*!< Filter bit 19 */
#define  CAN_F1R2_FB20                       ((u32)0x00100000)        /*!< Filter bit 20 */
#define  CAN_F1R2_FB21                       ((u32)0x00200000)        /*!< Filter bit 21 */
#define  CAN_F1R2_FB22                       ((u32)0x00400000)        /*!< Filter bit 22 */
#define  CAN_F1R2_FB23                       ((u32)0x00800000)        /*!< Filter bit 23 */
#define  CAN_F1R2_FB24                       ((u32)0x01000000)        /*!< Filter bit 24 */
#define  CAN_F1R2_FB25                       ((u32)0x02000000)        /*!< Filter bit 25 */
#define  CAN_F1R2_FB26                       ((u32)0x04000000)        /*!< Filter bit 26 */
#define  CAN_F1R2_FB27                       ((u32)0x08000000)        /*!< Filter bit 27 */
#define  CAN_F1R2_FB28                       ((u32)0x10000000)        /*!< Filter bit 28 */
#define  CAN_F1R2_FB29                       ((u32)0x20000000)        /*!< Filter bit 29 */
#define  CAN_F1R2_FB30                       ((u32)0x40000000)        /*!< Filter bit 30 */
#define  CAN_F1R2_FB31                       ((u32)0x80000000)        /*!< Filter bit 31 */

/*******************  Bit definition for CAN_F2R2 register  *******************/
#define  CAN_F2R2_FB0                        ((u32)0x00000001)        /*!< Filter bit 0 */
#define  CAN_F2R2_FB1                        ((u32)0x00000002)        /*!< Filter bit 1 */
#define  CAN_F2R2_FB2                        ((u32)0x00000004)        /*!< Filter bit 2 */
#define  CAN_F2R2_FB3                        ((u32)0x00000008)        /*!< Filter bit 3 */
#define  CAN_F2R2_FB4                        ((u32)0x00000010)        /*!< Filter bit 4 */
#define  CAN_F2R2_FB5                        ((u32)0x00000020)        /*!< Filter bit 5 */
#define  CAN_F2R2_FB6                        ((u32)0x00000040)        /*!< Filter bit 6 */
#define  CAN_F2R2_FB7                        ((u32)0x00000080)        /*!< Filter bit 7 */
#define  CAN_F2R2_FB8                        ((u32)0x00000100)        /*!< Filter bit 8 */
#define  CAN_F2R2_FB9                        ((u32)0x00000200)        /*!< Filter bit 9 */
#define  CAN_F2R2_FB10                       ((u32)0x00000400)        /*!< Filter bit 10 */
#define  CAN_F2R2_FB11                       ((u32)0x00000800)        /*!< Filter bit 11 */
#define  CAN_F2R2_FB12                       ((u32)0x00001000)        /*!< Filter bit 12 */
#define  CAN_F2R2_FB13                       ((u32)0x00002000)        /*!< Filter bit 13 */
#define  CAN_F2R2_FB14                       ((u32)0x00004000)        /*!< Filter bit 14 */
#define  CAN_F2R2_FB15                       ((u32)0x00008000)        /*!< Filter bit 15 */
#define  CAN_F2R2_FB16                       ((u32)0x00010000)        /*!< Filter bit 16 */
#define  CAN_F2R2_FB17                       ((u32)0x00020000)        /*!< Filter bit 17 */
#define  CAN_F2R2_FB18                       ((u32)0x00040000)        /*!< Filter bit 18 */
#define  CAN_F2R2_FB19                       ((u32)0x00080000)        /*!< Filter bit 19 */
#define  CAN_F2R2_FB20                       ((u32)0x00100000)        /*!< Filter bit 20 */
#define  CAN_F2R2_FB21                       ((u32)0x00200000)        /*!< Filter bit 21 */
#define  CAN_F2R2_FB22                       ((u32)0x00400000)        /*!< Filter bit 22 */
#define  CAN_F2R2_FB23                       ((u32)0x00800000)        /*!< Filter bit 23 */
#define  CAN_F2R2_FB24                       ((u32)0x01000000)        /*!< Filter bit 24 */
#define  CAN_F2R2_FB25                       ((u32)0x02000000)        /*!< Filter bit 25 */
#define  CAN_F2R2_FB26                       ((u32)0x04000000)        /*!< Filter bit 26 */
#define  CAN_F2R2_FB27                       ((u32)0x08000000)        /*!< Filter bit 27 */
#define  CAN_F2R2_FB28                       ((u32)0x10000000)        /*!< Filter bit 28 */
#define  CAN_F2R2_FB29                       ((u32)0x20000000)        /*!< Filter bit 29 */
#define  CAN_F2R2_FB30                       ((u32)0x40000000)        /*!< Filter bit 30 */
#define  CAN_F2R2_FB31                       ((u32)0x80000000)        /*!< Filter bit 31 */

/*******************  Bit definition for CAN_F3R2 register  *******************/
#define  CAN_F3R2_FB0                        ((u32)0x00000001)        /*!< Filter bit 0 */
#define  CAN_F3R2_FB1                        ((u32)0x00000002)        /*!< Filter bit 1 */
#define  CAN_F3R2_FB2                        ((u32)0x00000004)        /*!< Filter bit 2 */
#define  CAN_F3R2_FB3                        ((u32)0x00000008)        /*!< Filter bit 3 */
#define  CAN_F3R2_FB4                        ((u32)0x00000010)        /*!< Filter bit 4 */
#define  CAN_F3R2_FB5                        ((u32)0x00000020)        /*!< Filter bit 5 */
#define  CAN_F3R2_FB6                        ((u32)0x00000040)        /*!< Filter bit 6 */
#define  CAN_F3R2_FB7                        ((u32)0x00000080)        /*!< Filter bit 7 */
#define  CAN_F3R2_FB8                        ((u32)0x00000100)        /*!< Filter bit 8 */
#define  CAN_F3R2_FB9                        ((u32)0x00000200)        /*!< Filter bit 9 */
#define  CAN_F3R2_FB10                       ((u32)0x00000400)        /*!< Filter bit 10 */
#define  CAN_F3R2_FB11                       ((u32)0x00000800)        /*!< Filter bit 11 */
#define  CAN_F3R2_FB12                       ((u32)0x00001000)        /*!< Filter bit 12 */
#define  CAN_F3R2_FB13                       ((u32)0x00002000)        /*!< Filter bit 13 */
#define  CAN_F3R2_FB14                       ((u32)0x00004000)        /*!< Filter bit 14 */
#define  CAN_F3R2_FB15                       ((u32)0x00008000)        /*!< Filter bit 15 */
#define  CAN_F3R2_FB16                       ((u32)0x00010000)        /*!< Filter bit 16 */
#define  CAN_F3R2_FB17                       ((u32)0x00020000)        /*!< Filter bit 17 */
#define  CAN_F3R2_FB18                       ((u32)0x00040000)        /*!< Filter bit 18 */
#define  CAN_F3R2_FB19                       ((u32)0x00080000)        /*!< Filter bit 19 */
#define  CAN_F3R2_FB20                       ((u32)0x00100000)        /*!< Filter bit 20 */
#define  CAN_F3R2_FB21                       ((u32)0x00200000)        /*!< Filter bit 21 */
#define  CAN_F3R2_FB22                       ((u32)0x00400000)        /*!< Filter bit 22 */
#define  CAN_F3R2_FB23                       ((u32)0x00800000)        /*!< Filter bit 23 */
#define  CAN_F3R2_FB24                       ((u32)0x01000000)        /*!< Filter bit 24 */
#define  CAN_F3R2_FB25                       ((u32)0x02000000)        /*!< Filter bit 25 */
#define  CAN_F3R2_FB26                       ((u32)0x04000000)        /*!< Filter bit 26 */
#define  CAN_F3R2_FB27                       ((u32)0x08000000)        /*!< Filter bit 27 */
#define  CAN_F3R2_FB28                       ((u32)0x10000000)        /*!< Filter bit 28 */
#define  CAN_F3R2_FB29                       ((u32)0x20000000)        /*!< Filter bit 29 */
#define  CAN_F3R2_FB30                       ((u32)0x40000000)        /*!< Filter bit 30 */
#define  CAN_F3R2_FB31                       ((u32)0x80000000)        /*!< Filter bit 31 */

/*******************  Bit definition for CAN_F4R2 register  *******************/
#define  CAN_F4R2_FB0                        ((u32)0x00000001)        /*!< Filter bit 0 */
#define  CAN_F4R2_FB1                        ((u32)0x00000002)        /*!< Filter bit 1 */
#define  CAN_F4R2_FB2                        ((u32)0x00000004)        /*!< Filter bit 2 */
#define  CAN_F4R2_FB3                        ((u32)0x00000008)        /*!< Filter bit 3 */
#define  CAN_F4R2_FB4                        ((u32)0x00000010)        /*!< Filter bit 4 */
#define  CAN_F4R2_FB5                        ((u32)0x00000020)        /*!< Filter bit 5 */
#define  CAN_F4R2_FB6                        ((u32)0x00000040)        /*!< Filter bit 6 */
#define  CAN_F4R2_FB7                        ((u32)0x00000080)        /*!< Filter bit 7 */
#define  CAN_F4R2_FB8                        ((u32)0x00000100)        /*!< Filter bit 8 */
#define  CAN_F4R2_FB9                        ((u32)0x00000200)        /*!< Filter bit 9 */
#define  CAN_F4R2_FB10                       ((u32)0x00000400)        /*!< Filter bit 10 */
#define  CAN_F4R2_FB11                       ((u32)0x00000800)        /*!< Filter bit 11 */
#define  CAN_F4R2_FB12                       ((u32)0x00001000)        /*!< Filter bit 12 */
#define  CAN_F4R2_FB13                       ((u32)0x00002000)        /*!< Filter bit 13 */
#define  CAN_F4R2_FB14                       ((u32)0x00004000)        /*!< Filter bit 14 */
#define  CAN_F4R2_FB15                       ((u32)0x00008000)        /*!< Filter bit 15 */
#define  CAN_F4R2_FB16                       ((u32)0x00010000)        /*!< Filter bit 16 */
#define  CAN_F4R2_FB17                       ((u32)0x00020000)        /*!< Filter bit 17 */
#define  CAN_F4R2_FB18                       ((u32)0x00040000)        /*!< Filter bit 18 */
#define  CAN_F4R2_FB19                       ((u32)0x00080000)        /*!< Filter bit 19 */
#define  CAN_F4R2_FB20                       ((u32)0x00100000)        /*!< Filter bit 20 */
#define  CAN_F4R2_FB21                       ((u32)0x00200000)        /*!< Filter bit 21 */
#define  CAN_F4R2_FB22                       ((u32)0x00400000)        /*!< Filter bit 22 */
#define  CAN_F4R2_FB23                       ((u32)0x00800000)        /*!< Filter bit 23 */
#define  CAN_F4R2_FB24                       ((u32)0x01000000)        /*!< Filter bit 24 */
#define  CAN_F4R2_FB25                       ((u32)0x02000000)        /*!< Filter bit 25 */
#define  CAN_F4R2_FB26                       ((u32)0x04000000)        /*!< Filter bit 26 */
#define  CAN_F4R2_FB27                       ((u32)0x08000000)        /*!< Filter bit 27 */
#define  CAN_F4R2_FB28                       ((u32)0x10000000)        /*!< Filter bit 28 */
#define  CAN_F4R2_FB29                       ((u32)0x20000000)        /*!< Filter bit 29 */
#define  CAN_F4R2_FB30                       ((u32)0x40000000)        /*!< Filter bit 30 */
#define  CAN_F4R2_FB31                       ((u32)0x80000000)        /*!< Filter bit 31 */

/*******************  Bit definition for CAN_F5R2 register  *******************/
#define  CAN_F5R2_FB0                        ((u32)0x00000001)        /*!< Filter bit 0 */
#define  CAN_F5R2_FB1                        ((u32)0x00000002)        /*!< Filter bit 1 */
#define  CAN_F5R2_FB2                        ((u32)0x00000004)        /*!< Filter bit 2 */
#define  CAN_F5R2_FB3                        ((u32)0x00000008)        /*!< Filter bit 3 */
#define  CAN_F5R2_FB4                        ((u32)0x00000010)        /*!< Filter bit 4 */
#define  CAN_F5R2_FB5                        ((u32)0x00000020)        /*!< Filter bit 5 */
#define  CAN_F5R2_FB6                        ((u32)0x00000040)        /*!< Filter bit 6 */
#define  CAN_F5R2_FB7                        ((u32)0x00000080)        /*!< Filter bit 7 */
#define  CAN_F5R2_FB8                        ((u32)0x00000100)        /*!< Filter bit 8 */
#define  CAN_F5R2_FB9                        ((u32)0x00000200)        /*!< Filter bit 9 */
#define  CAN_F5R2_FB10                       ((u32)0x00000400)        /*!< Filter bit 10 */
#define  CAN_F5R2_FB11                       ((u32)0x00000800)        /*!< Filter bit 11 */
#define  CAN_F5R2_FB12                       ((u32)0x00001000)        /*!< Filter bit 12 */
#define  CAN_F5R2_FB13                       ((u32)0x00002000)        /*!< Filter bit 13 */
#define  CAN_F5R2_FB14                       ((u32)0x00004000)        /*!< Filter bit 14 */
#define  CAN_F5R2_FB15                       ((u32)0x00008000)        /*!< Filter bit 15 */
#define  CAN_F5R2_FB16                       ((u32)0x00010000)        /*!< Filter bit 16 */
#define  CAN_F5R2_FB17                       ((u32)0x00020000)        /*!< Filter bit 17 */
#define  CAN_F5R2_FB18                       ((u32)0x00040000)        /*!< Filter bit 18 */
#define  CAN_F5R2_FB19                       ((u32)0x00080000)        /*!< Filter bit 19 */
#define  CAN_F5R2_FB20                       ((u32)0x00100000)        /*!< Filter bit 20 */
#define  CAN_F5R2_FB21                       ((u32)0x00200000)        /*!< Filter bit 21 */
#define  CAN_F5R2_FB22                       ((u32)0x00400000)        /*!< Filter bit 22 */
#define  CAN_F5R2_FB23                       ((u32)0x00800000)        /*!< Filter bit 23 */
#define  CAN_F5R2_FB24                       ((u32)0x01000000)        /*!< Filter bit 24 */
#define  CAN_F5R2_FB25                       ((u32)0x02000000)        /*!< Filter bit 25 */
#define  CAN_F5R2_FB26                       ((u32)0x04000000)        /*!< Filter bit 26 */
#define  CAN_F5R2_FB27                       ((u32)0x08000000)        /*!< Filter bit 27 */
#define  CAN_F5R2_FB28                       ((u32)0x10000000)        /*!< Filter bit 28 */
#define  CAN_F5R2_FB29                       ((u32)0x20000000)        /*!< Filter bit 29 */
#define  CAN_F5R2_FB30                       ((u32)0x40000000)        /*!< Filter bit 30 */
#define  CAN_F5R2_FB31                       ((u32)0x80000000)        /*!< Filter bit 31 */

/*******************  Bit definition for CAN_F6R2 register  *******************/
#define  CAN_F6R2_FB0                        ((u32)0x00000001)        /*!< Filter bit 0 */
#define  CAN_F6R2_FB1                        ((u32)0x00000002)        /*!< Filter bit 1 */
#define  CAN_F6R2_FB2                        ((u32)0x00000004)        /*!< Filter bit 2 */
#define  CAN_F6R2_FB3                        ((u32)0x00000008)        /*!< Filter bit 3 */
#define  CAN_F6R2_FB4                        ((u32)0x00000010)        /*!< Filter bit 4 */
#define  CAN_F6R2_FB5                        ((u32)0x00000020)        /*!< Filter bit 5 */
#define  CAN_F6R2_FB6                        ((u32)0x00000040)        /*!< Filter bit 6 */
#define  CAN_F6R2_FB7                        ((u32)0x00000080)        /*!< Filter bit 7 */
#define  CAN_F6R2_FB8                        ((u32)0x00000100)        /*!< Filter bit 8 */
#define  CAN_F6R2_FB9                        ((u32)0x00000200)        /*!< Filter bit 9 */
#define  CAN_F6R2_FB10                       ((u32)0x00000400)        /*!< Filter bit 10 */
#define  CAN_F6R2_FB11                       ((u32)0x00000800)        /*!< Filter bit 11 */
#define  CAN_F6R2_FB12                       ((u32)0x00001000)        /*!< Filter bit 12 */
#define  CAN_F6R2_FB13                       ((u32)0x00002000)        /*!< Filter bit 13 */
#define  CAN_F6R2_FB14                       ((u32)0x00004000)        /*!< Filter bit 14 */
#define  CAN_F6R2_FB15                       ((u32)0x00008000)        /*!< Filter bit 15 */
#define  CAN_F6R2_FB16                       ((u32)0x00010000)        /*!< Filter bit 16 */
#define  CAN_F6R2_FB17                       ((u32)0x00020000)        /*!< Filter bit 17 */
#define  CAN_F6R2_FB18                       ((u32)0x00040000)        /*!< Filter bit 18 */
#define  CAN_F6R2_FB19                       ((u32)0x00080000)        /*!< Filter bit 19 */
#define  CAN_F6R2_FB20                       ((u32)0x00100000)        /*!< Filter bit 20 */
#define  CAN_F6R2_FB21                       ((u32)0x00200000)        /*!< Filter bit 21 */
#define  CAN_F6R2_FB22                       ((u32)0x00400000)        /*!< Filter bit 22 */
#define  CAN_F6R2_FB23                       ((u32)0x00800000)        /*!< Filter bit 23 */
#define  CAN_F6R2_FB24                       ((u32)0x01000000)        /*!< Filter bit 24 */
#define  CAN_F6R2_FB25                       ((u32)0x02000000)        /*!< Filter bit 25 */
#define  CAN_F6R2_FB26                       ((u32)0x04000000)        /*!< Filter bit 26 */
#define  CAN_F6R2_FB27                       ((u32)0x08000000)        /*!< Filter bit 27 */
#define  CAN_F6R2_FB28                       ((u32)0x10000000)        /*!< Filter bit 28 */
#define  CAN_F6R2_FB29                       ((u32)0x20000000)        /*!< Filter bit 29 */
#define  CAN_F6R2_FB30                       ((u32)0x40000000)        /*!< Filter bit 30 */
#define  CAN_F6R2_FB31                       ((u32)0x80000000)        /*!< Filter bit 31 */

/*******************  Bit definition for CAN_F7R2 register  *******************/
#define  CAN_F7R2_FB0                        ((u32)0x00000001)        /*!< Filter bit 0 */
#define  CAN_F7R2_FB1                        ((u32)0x00000002)        /*!< Filter bit 1 */
#define  CAN_F7R2_FB2                        ((u32)0x00000004)        /*!< Filter bit 2 */
#define  CAN_F7R2_FB3                        ((u32)0x00000008)        /*!< Filter bit 3 */
#define  CAN_F7R2_FB4                        ((u32)0x00000010)        /*!< Filter bit 4 */
#define  CAN_F7R2_FB5                        ((u32)0x00000020)        /*!< Filter bit 5 */
#define  CAN_F7R2_FB6                        ((u32)0x00000040)        /*!< Filter bit 6 */
#define  CAN_F7R2_FB7                        ((u32)0x00000080)        /*!< Filter bit 7 */
#define  CAN_F7R2_FB8                        ((u32)0x00000100)        /*!< Filter bit 8 */
#define  CAN_F7R2_FB9                        ((u32)0x00000200)        /*!< Filter bit 9 */
#define  CAN_F7R2_FB10                       ((u32)0x00000400)        /*!< Filter bit 10 */
#define  CAN_F7R2_FB11                       ((u32)0x00000800)        /*!< Filter bit 11 */
#define  CAN_F7R2_FB12                       ((u32)0x00001000)        /*!< Filter bit 12 */
#define  CAN_F7R2_FB13                       ((u32)0x00002000)        /*!< Filter bit 13 */
#define  CAN_F7R2_FB14                       ((u32)0x00004000)        /*!< Filter bit 14 */
#define  CAN_F7R2_FB15                       ((u32)0x00008000)        /*!< Filter bit 15 */
#define  CAN_F7R2_FB16                       ((u32)0x00010000)        /*!< Filter bit 16 */
#define  CAN_F7R2_FB17                       ((u32)0x00020000)        /*!< Filter bit 17 */
#define  CAN_F7R2_FB18                       ((u32)0x00040000)        /*!< Filter bit 18 */
#define  CAN_F7R2_FB19                       ((u32)0x00080000)        /*!< Filter bit 19 */
#define  CAN_F7R2_FB20                       ((u32)0x00100000)        /*!< Filter bit 20 */
#define  CAN_F7R2_FB21                       ((u32)0x00200000)        /*!< Filter bit 21 */
#define  CAN_F7R2_FB22                       ((u32)0x00400000)        /*!< Filter bit 22 */
#define  CAN_F7R2_FB23                       ((u32)0x00800000)        /*!< Filter bit 23 */
#define  CAN_F7R2_FB24                       ((u32)0x01000000)        /*!< Filter bit 24 */
#define  CAN_F7R2_FB25                       ((u32)0x02000000)        /*!< Filter bit 25 */
#define  CAN_F7R2_FB26                       ((u32)0x04000000)        /*!< Filter bit 26 */
#define  CAN_F7R2_FB27                       ((u32)0x08000000)        /*!< Filter bit 27 */
#define  CAN_F7R2_FB28                       ((u32)0x10000000)        /*!< Filter bit 28 */
#define  CAN_F7R2_FB29                       ((u32)0x20000000)        /*!< Filter bit 29 */
#define  CAN_F7R2_FB30                       ((u32)0x40000000)        /*!< Filter bit 30 */
#define  CAN_F7R2_FB31                       ((u32)0x80000000)        /*!< Filter bit 31 */

/*******************  Bit definition for CAN_F8R2 register  *******************/
#define  CAN_F8R2_FB0                        ((u32)0x00000001)        /*!< Filter bit 0 */
#define  CAN_F8R2_FB1                        ((u32)0x00000002)        /*!< Filter bit 1 */
#define  CAN_F8R2_FB2                        ((u32)0x00000004)        /*!< Filter bit 2 */
#define  CAN_F8R2_FB3                        ((u32)0x00000008)        /*!< Filter bit 3 */
#define  CAN_F8R2_FB4                        ((u32)0x00000010)        /*!< Filter bit 4 */
#define  CAN_F8R2_FB5                        ((u32)0x00000020)        /*!< Filter bit 5 */
#define  CAN_F8R2_FB6                        ((u32)0x00000040)        /*!< Filter bit 6 */
#define  CAN_F8R2_FB7                        ((u32)0x00000080)        /*!< Filter bit 7 */
#define  CAN_F8R2_FB8                        ((u32)0x00000100)        /*!< Filter bit 8 */
#define  CAN_F8R2_FB9                        ((u32)0x00000200)        /*!< Filter bit 9 */
#define  CAN_F8R2_FB10                       ((u32)0x00000400)        /*!< Filter bit 10 */
#define  CAN_F8R2_FB11                       ((u32)0x00000800)        /*!< Filter bit 11 */
#define  CAN_F8R2_FB12                       ((u32)0x00001000)        /*!< Filter bit 12 */
#define  CAN_F8R2_FB13                       ((u32)0x00002000)        /*!< Filter bit 13 */
#define  CAN_F8R2_FB14                       ((u32)0x00004000)        /*!< Filter bit 14 */
#define  CAN_F8R2_FB15                       ((u32)0x00008000)        /*!< Filter bit 15 */
#define  CAN_F8R2_FB16                       ((u32)0x00010000)        /*!< Filter bit 16 */
#define  CAN_F8R2_FB17                       ((u32)0x00020000)        /*!< Filter bit 17 */
#define  CAN_F8R2_FB18                       ((u32)0x00040000)        /*!< Filter bit 18 */
#define  CAN_F8R2_FB19                       ((u32)0x00080000)        /*!< Filter bit 19 */
#define  CAN_F8R2_FB20                       ((u32)0x00100000)        /*!< Filter bit 20 */
#define  CAN_F8R2_FB21                       ((u32)0x00200000)        /*!< Filter bit 21 */
#define  CAN_F8R2_FB22                       ((u32)0x00400000)        /*!< Filter bit 22 */
#define  CAN_F8R2_FB23                       ((u32)0x00800000)        /*!< Filter bit 23 */
#define  CAN_F8R2_FB24                       ((u32)0x01000000)        /*!< Filter bit 24 */
#define  CAN_F8R2_FB25                       ((u32)0x02000000)        /*!< Filter bit 25 */
#define  CAN_F8R2_FB26                       ((u32)0x04000000)        /*!< Filter bit 26 */
#define  CAN_F8R2_FB27                       ((u32)0x08000000)        /*!< Filter bit 27 */
#define  CAN_F8R2_FB28                       ((u32)0x10000000)        /*!< Filter bit 28 */
#define  CAN_F8R2_FB29                       ((u32)0x20000000)        /*!< Filter bit 29 */
#define  CAN_F8R2_FB30                       ((u32)0x40000000)        /*!< Filter bit 30 */
#define  CAN_F8R2_FB31                       ((u32)0x80000000)        /*!< Filter bit 31 */

/*******************  Bit definition for CAN_F9R2 register  *******************/
#define  CAN_F9R2_FB0                        ((u32)0x00000001)        /*!< Filter bit 0 */
#define  CAN_F9R2_FB1                        ((u32)0x00000002)        /*!< Filter bit 1 */
#define  CAN_F9R2_FB2                        ((u32)0x00000004)        /*!< Filter bit 2 */
#define  CAN_F9R2_FB3                        ((u32)0x00000008)        /*!< Filter bit 3 */
#define  CAN_F9R2_FB4                        ((u32)0x00000010)        /*!< Filter bit 4 */
#define  CAN_F9R2_FB5                        ((u32)0x00000020)        /*!< Filter bit 5 */
#define  CAN_F9R2_FB6                        ((u32)0x00000040)        /*!< Filter bit 6 */
#define  CAN_F9R2_FB7                        ((u32)0x00000080)        /*!< Filter bit 7 */
#define  CAN_F9R2_FB8                        ((u32)0x00000100)        /*!< Filter bit 8 */
#define  CAN_F9R2_FB9                        ((u32)0x00000200)        /*!< Filter bit 9 */
#define  CAN_F9R2_FB10                       ((u32)0x00000400)        /*!< Filter bit 10 */
#define  CAN_F9R2_FB11                       ((u32)0x00000800)        /*!< Filter bit 11 */
#define  CAN_F9R2_FB12                       ((u32)0x00001000)        /*!< Filter bit 12 */
#define  CAN_F9R2_FB13                       ((u32)0x00002000)        /*!< Filter bit 13 */
#define  CAN_F9R2_FB14                       ((u32)0x00004000)        /*!< Filter bit 14 */
#define  CAN_F9R2_FB15                       ((u32)0x00008000)        /*!< Filter bit 15 */
#define  CAN_F9R2_FB16                       ((u32)0x00010000)        /*!< Filter bit 16 */
#define  CAN_F9R2_FB17                       ((u32)0x00020000)        /*!< Filter bit 17 */
#define  CAN_F9R2_FB18                       ((u32)0x00040000)        /*!< Filter bit 18 */
#define  CAN_F9R2_FB19                       ((u32)0x00080000)        /*!< Filter bit 19 */
#define  CAN_F9R2_FB20                       ((u32)0x00100000)        /*!< Filter bit 20 */
#define  CAN_F9R2_FB21                       ((u32)0x00200000)        /*!< Filter bit 21 */
#define  CAN_F9R2_FB22                       ((u32)0x00400000)        /*!< Filter bit 22 */
#define  CAN_F9R2_FB23                       ((u32)0x00800000)        /*!< Filter bit 23 */
#define  CAN_F9R2_FB24                       ((u32)0x01000000)        /*!< Filter bit 24 */
#define  CAN_F9R2_FB25                       ((u32)0x02000000)        /*!< Filter bit 25 */
#define  CAN_F9R2_FB26                       ((u32)0x04000000)        /*!< Filter bit 26 */
#define  CAN_F9R2_FB27                       ((u32)0x08000000)        /*!< Filter bit 27 */
#define  CAN_F9R2_FB28                       ((u32)0x10000000)        /*!< Filter bit 28 */
#define  CAN_F9R2_FB29                       ((u32)0x20000000)        /*!< Filter bit 29 */
#define  CAN_F9R2_FB30                       ((u32)0x40000000)        /*!< Filter bit 30 */
#define  CAN_F9R2_FB31                       ((u32)0x80000000)        /*!< Filter bit 31 */

/*******************  Bit definition for CAN_F10R2 register  ******************/
#define  CAN_F10R2_FB0                       ((u32)0x00000001)        /*!< Filter bit 0 */
#define  CAN_F10R2_FB1                       ((u32)0x00000002)        /*!< Filter bit 1 */
#define  CAN_F10R2_FB2                       ((u32)0x00000004)        /*!< Filter bit 2 */
#define  CAN_F10R2_FB3                       ((u32)0x00000008)        /*!< Filter bit 3 */
#define  CAN_F10R2_FB4                       ((u32)0x00000010)        /*!< Filter bit 4 */
#define  CAN_F10R2_FB5                       ((u32)0x00000020)        /*!< Filter bit 5 */
#define  CAN_F10R2_FB6                       ((u32)0x00000040)        /*!< Filter bit 6 */
#define  CAN_F10R2_FB7                       ((u32)0x00000080)        /*!< Filter bit 7 */
#define  CAN_F10R2_FB8                       ((u32)0x00000100)        /*!< Filter bit 8 */
#define  CAN_F10R2_FB9                       ((u32)0x00000200)        /*!< Filter bit 9 */
#define  CAN_F10R2_FB10                      ((u32)0x00000400)        /*!< Filter bit 10 */
#define  CAN_F10R2_FB11                      ((u32)0x00000800)        /*!< Filter bit 11 */
#define  CAN_F10R2_FB12                      ((u32)0x00001000)        /*!< Filter bit 12 */
#define  CAN_F10R2_FB13                      ((u32)0x00002000)        /*!< Filter bit 13 */
#define  CAN_F10R2_FB14                      ((u32)0x00004000)        /*!< Filter bit 14 */
#define  CAN_F10R2_FB15                      ((u32)0x00008000)        /*!< Filter bit 15 */
#define  CAN_F10R2_FB16                      ((u32)0x00010000)        /*!< Filter bit 16 */
#define  CAN_F10R2_FB17                      ((u32)0x00020000)        /*!< Filter bit 17 */
#define  CAN_F10R2_FB18                      ((u32)0x00040000)        /*!< Filter bit 18 */
#define  CAN_F10R2_FB19                      ((u32)0x00080000)        /*!< Filter bit 19 */
#define  CAN_F10R2_FB20                      ((u32)0x00100000)        /*!< Filter bit 20 */
#define  CAN_F10R2_FB21                      ((u32)0x00200000)        /*!< Filter bit 21 */
#define  CAN_F10R2_FB22                      ((u32)0x00400000)        /*!< Filter bit 22 */
#define  CAN_F10R2_FB23                      ((u32)0x00800000)        /*!< Filter bit 23 */
#define  CAN_F10R2_FB24                      ((u32)0x01000000)        /*!< Filter bit 24 */
#define  CAN_F10R2_FB25                      ((u32)0x02000000)        /*!< Filter bit 25 */
#define  CAN_F10R2_FB26                      ((u32)0x04000000)        /*!< Filter bit 26 */
#define  CAN_F10R2_FB27                      ((u32)0x08000000)        /*!< Filter bit 27 */
#define  CAN_F10R2_FB28                      ((u32)0x10000000)        /*!< Filter bit 28 */
#define  CAN_F10R2_FB29                      ((u32)0x20000000)        /*!< Filter bit 29 */
#define  CAN_F10R2_FB30                      ((u32)0x40000000)        /*!< Filter bit 30 */
#define  CAN_F10R2_FB31                      ((u32)0x80000000)        /*!< Filter bit 31 */

/*******************  Bit definition for CAN_F11R2 register  ******************/
#define  CAN_F11R2_FB0                       ((u32)0x00000001)        /*!< Filter bit 0 */
#define  CAN_F11R2_FB1                       ((u32)0x00000002)        /*!< Filter bit 1 */
#define  CAN_F11R2_FB2                       ((u32)0x00000004)        /*!< Filter bit 2 */
#define  CAN_F11R2_FB3                       ((u32)0x00000008)        /*!< Filter bit 3 */
#define  CAN_F11R2_FB4                       ((u32)0x00000010)        /*!< Filter bit 4 */
#define  CAN_F11R2_FB5                       ((u32)0x00000020)        /*!< Filter bit 5 */
#define  CAN_F11R2_FB6                       ((u32)0x00000040)        /*!< Filter bit 6 */
#define  CAN_F11R2_FB7                       ((u32)0x00000080)        /*!< Filter bit 7 */
#define  CAN_F11R2_FB8                       ((u32)0x00000100)        /*!< Filter bit 8 */
#define  CAN_F11R2_FB9                       ((u32)0x00000200)        /*!< Filter bit 9 */
#define  CAN_F11R2_FB10                      ((u32)0x00000400)        /*!< Filter bit 10 */
#define  CAN_F11R2_FB11                      ((u32)0x00000800)        /*!< Filter bit 11 */
#define  CAN_F11R2_FB12                      ((u32)0x00001000)        /*!< Filter bit 12 */
#define  CAN_F11R2_FB13                      ((u32)0x00002000)        /*!< Filter bit 13 */
#define  CAN_F11R2_FB14                      ((u32)0x00004000)        /*!< Filter bit 14 */
#define  CAN_F11R2_FB15                      ((u32)0x00008000)        /*!< Filter bit 15 */
#define  CAN_F11R2_FB16                      ((u32)0x00010000)        /*!< Filter bit 16 */
#define  CAN_F11R2_FB17                      ((u32)0x00020000)        /*!< Filter bit 17 */
#define  CAN_F11R2_FB18                      ((u32)0x00040000)        /*!< Filter bit 18 */
#define  CAN_F11R2_FB19                      ((u32)0x00080000)        /*!< Filter bit 19 */
#define  CAN_F11R2_FB20                      ((u32)0x00100000)        /*!< Filter bit 20 */
#define  CAN_F11R2_FB21                      ((u32)0x00200000)        /*!< Filter bit 21 */
#define  CAN_F11R2_FB22                      ((u32)0x00400000)        /*!< Filter bit 22 */
#define  CAN_F11R2_FB23                      ((u32)0x00800000)        /*!< Filter bit 23 */
#define  CAN_F11R2_FB24                      ((u32)0x01000000)        /*!< Filter bit 24 */
#define  CAN_F11R2_FB25                      ((u32)0x02000000)        /*!< Filter bit 25 */
#define  CAN_F11R2_FB26                      ((u32)0x04000000)        /*!< Filter bit 26 */
#define  CAN_F11R2_FB27                      ((u32)0x08000000)        /*!< Filter bit 27 */
#define  CAN_F11R2_FB28                      ((u32)0x10000000)        /*!< Filter bit 28 */
#define  CAN_F11R2_FB29                      ((u32)0x20000000)        /*!< Filter bit 29 */
#define  CAN_F11R2_FB30                      ((u32)0x40000000)        /*!< Filter bit 30 */
#define  CAN_F11R2_FB31                      ((u32)0x80000000)        /*!< Filter bit 31 */

/*******************  Bit definition for CAN_F12R2 register  ******************/
#define  CAN_F12R2_FB0                       ((u32)0x00000001)        /*!< Filter bit 0 */
#define  CAN_F12R2_FB1                       ((u32)0x00000002)        /*!< Filter bit 1 */
#define  CAN_F12R2_FB2                       ((u32)0x00000004)        /*!< Filter bit 2 */
#define  CAN_F12R2_FB3                       ((u32)0x00000008)        /*!< Filter bit 3 */
#define  CAN_F12R2_FB4                       ((u32)0x00000010)        /*!< Filter bit 4 */
#define  CAN_F12R2_FB5                       ((u32)0x00000020)        /*!< Filter bit 5 */
#define  CAN_F12R2_FB6                       ((u32)0x00000040)        /*!< Filter bit 6 */
#define  CAN_F12R2_FB7                       ((u32)0x00000080)        /*!< Filter bit 7 */
#define  CAN_F12R2_FB8                       ((u32)0x00000100)        /*!< Filter bit 8 */
#define  CAN_F12R2_FB9                       ((u32)0x00000200)        /*!< Filter bit 9 */
#define  CAN_F12R2_FB10                      ((u32)0x00000400)        /*!< Filter bit 10 */
#define  CAN_F12R2_FB11                      ((u32)0x00000800)        /*!< Filter bit 11 */
#define  CAN_F12R2_FB12                      ((u32)0x00001000)        /*!< Filter bit 12 */
#define  CAN_F12R2_FB13                      ((u32)0x00002000)        /*!< Filter bit 13 */
#define  CAN_F12R2_FB14                      ((u32)0x00004000)        /*!< Filter bit 14 */
#define  CAN_F12R2_FB15                      ((u32)0x00008000)        /*!< Filter bit 15 */
#define  CAN_F12R2_FB16                      ((u32)0x00010000)        /*!< Filter bit 16 */
#define  CAN_F12R2_FB17                      ((u32)0x00020000)        /*!< Filter bit 17 */
#define  CAN_F12R2_FB18                      ((u32)0x00040000)        /*!< Filter bit 18 */
#define  CAN_F12R2_FB19                      ((u32)0x00080000)        /*!< Filter bit 19 */
#define  CAN_F12R2_FB20                      ((u32)0x00100000)        /*!< Filter bit 20 */
#define  CAN_F12R2_FB21                      ((u32)0x00200000)        /*!< Filter bit 21 */
#define  CAN_F12R2_FB22                      ((u32)0x00400000)        /*!< Filter bit 22 */
#define  CAN_F12R2_FB23                      ((u32)0x00800000)        /*!< Filter bit 23 */
#define  CAN_F12R2_FB24                      ((u32)0x01000000)        /*!< Filter bit 24 */
#define  CAN_F12R2_FB25                      ((u32)0x02000000)        /*!< Filter bit 25 */
#define  CAN_F12R2_FB26                      ((u32)0x04000000)        /*!< Filter bit 26 */
#define  CAN_F12R2_FB27                      ((u32)0x08000000)        /*!< Filter bit 27 */
#define  CAN_F12R2_FB28                      ((u32)0x10000000)        /*!< Filter bit 28 */
#define  CAN_F12R2_FB29                      ((u32)0x20000000)        /*!< Filter bit 29 */
#define  CAN_F12R2_FB30                      ((u32)0x40000000)        /*!< Filter bit 30 */
#define  CAN_F12R2_FB31                      ((u32)0x80000000)        /*!< Filter bit 31 */

/*******************  Bit definition for CAN_F13R2 register  ******************/
#define  CAN_F13R2_FB0                       ((u32)0x00000001)        /*!< Filter bit 0 */
#define  CAN_F13R2_FB1                       ((u32)0x00000002)        /*!< Filter bit 1 */
#define  CAN_F13R2_FB2                       ((u32)0x00000004)        /*!< Filter bit 2 */
#define  CAN_F13R2_FB3                       ((u32)0x00000008)        /*!< Filter bit 3 */
#define  CAN_F13R2_FB4                       ((u32)0x00000010)        /*!< Filter bit 4 */
#define  CAN_F13R2_FB5                       ((u32)0x00000020)        /*!< Filter bit 5 */
#define  CAN_F13R2_FB6                       ((u32)0x00000040)        /*!< Filter bit 6 */
#define  CAN_F13R2_FB7                       ((u32)0x00000080)        /*!< Filter bit 7 */
#define  CAN_F13R2_FB8                       ((u32)0x00000100)        /*!< Filter bit 8 */
#define  CAN_F13R2_FB9                       ((u32)0x00000200)        /*!< Filter bit 9 */
#define  CAN_F13R2_FB10                      ((u32)0x00000400)        /*!< Filter bit 10 */
#define  CAN_F13R2_FB11                      ((u32)0x00000800)        /*!< Filter bit 11 */
#define  CAN_F13R2_FB12                      ((u32)0x00001000)        /*!< Filter bit 12 */
#define  CAN_F13R2_FB13                      ((u32)0x00002000)        /*!< Filter bit 13 */
#define  CAN_F13R2_FB14                      ((u32)0x00004000)        /*!< Filter bit 14 */
#define  CAN_F13R2_FB15                      ((u32)0x00008000)        /*!< Filter bit 15 */
#define  CAN_F13R2_FB16                      ((u32)0x00010000)        /*!< Filter bit 16 */
#define  CAN_F13R2_FB17                      ((u32)0x00020000)        /*!< Filter bit 17 */
#define  CAN_F13R2_FB18                      ((u32)0x00040000)        /*!< Filter bit 18 */
#define  CAN_F13R2_FB19                      ((u32)0x00080000)        /*!< Filter bit 19 */
#define  CAN_F13R2_FB20                      ((u32)0x00100000)        /*!< Filter bit 20 */
#define  CAN_F13R2_FB21                      ((u32)0x00200000)        /*!< Filter bit 21 */
#define  CAN_F13R2_FB22                      ((u32)0x00400000)        /*!< Filter bit 22 */
#define  CAN_F13R2_FB23                      ((u32)0x00800000)        /*!< Filter bit 23 */
#define  CAN_F13R2_FB24                      ((u32)0x01000000)        /*!< Filter bit 24 */
#define  CAN_F13R2_FB25                      ((u32)0x02000000)        /*!< Filter bit 25 */
#define  CAN_F13R2_FB26                      ((u32)0x04000000)        /*!< Filter bit 26 */
#define  CAN_F13R2_FB27                      ((u32)0x08000000)        /*!< Filter bit 27 */
#define  CAN_F13R2_FB28                      ((u32)0x10000000)        /*!< Filter bit 28 */
#define  CAN_F13R2_FB29                      ((u32)0x20000000)        /*!< Filter bit 29 */
#define  CAN_F13R2_FB30                      ((u32)0x40000000)        /*!< Filter bit 30 */
#define  CAN_F13R2_FB31                      ((u32)0x80000000)        /*!< Filter bit 31 */

/* Existing CAN units */
#define CAN1                ((CAN_TypeDef *) CAN1_BASE)

#endif /* MCAL_CAN_CAN_PRIVATE_H_ */
