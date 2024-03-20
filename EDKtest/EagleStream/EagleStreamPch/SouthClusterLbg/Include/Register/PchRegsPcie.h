/** @file
  Register names for PCH PCI-E root port devices

  Conventions:

  - Prefixes:
    Definitions beginning with "R_" are registers
    Definitions beginning with "B_" are bits within registers
    Definitions beginning with "V_" are meaningful values within the bits
    Definitions beginning with "S_" are register sizes
    Definitions beginning with "N_" are the bit position
  - In general, PCH registers are denoted by "_PCH_" in register names
  - Registers / bits that are different between PCH generations are denoted by
    "_PCH_[generation_name]_" in register/bit names.
  - Registers / bits that are specific to PCH-H denoted by "_H_" in register/bit names.
    Registers / bits that are specific to PCH-LP denoted by "_LP_" in register/bit names.
    e.g., "_PCH_H_", "_PCH_LP_"
    Registers / bits names without _H_ or _LP_ apply for both H and LP.
  - Registers / bits that are different between SKUs are denoted by "_[SKU_name]"
    at the end of the register/bit names
  - Registers / bits of new devices introduced in a PCH generation will be just named
    as "_PCH_" without [generation_name] inserted.

@copyright
 Copyright (c) 1999 - 2015 Intel Corporation. All rights reserved
 This software and associated documentation (if any) is furnished
 under a license and may only be used or copied in accordance
 with the terms of the license. Except as permitted by the
 license, no part of this software or documentation may be
 reproduced, stored in a retrieval system, or transmitted in any
 form or by any means without the express written consent of
 Intel Corporation.
 This file contains an 'Intel Peripheral Driver' and is uniquely
 identified as "Intel Reference Module" and is licensed for Intel
 CPUs and chipsets under the terms of your license agreement with
 Intel or your vendor. This file may be modified by the user, subject
 to additional terms of the license agreement.

@par Specification Reference:
**/
#ifndef _PCH_REGS_PCIE_H_
#define _PCH_REGS_PCIE_H_

//
// PCH PCI Express Root Ports (d: 8-19, 26, 27)
//
#define PCI_DEVICE_NUMBER_PCH_PCIE_DEVICE_1       8
#define PCI_DEVICE_NUMBER_PCH_PCIE_DEVICE_2       9
#define PCI_DEVICE_NUMBER_PCH_PCIE_DEVICE_3       10
#define PCI_DEVICE_NUMBER_PCH_PCIE_DEVICE_4       11
#define PCI_DEVICE_NUMBER_PCH_PCIE_DEVICE_5       12
#define PCI_DEVICE_NUMBER_PCH_PCIE_DEVICE_6       13
#define PCI_DEVICE_NUMBER_PCH_PCIE_DEVICE_7       14
#define PCI_DEVICE_NUMBER_PCH_PCIE_DEVICE_8       15
#define PCI_DEVICE_NUMBER_PCH_PCIE_DEVICE_9       16
#define PCI_DEVICE_NUMBER_PCH_PCIE_DEVICE_10      17
#define PCI_DEVICE_NUMBER_PCH_PCIE_DEVICE_11      18
#define PCI_DEVICE_NUMBER_PCH_PCIE_DEVICE_12      19
#define PCI_DEVICE_NUMBER_PCH_PCIE_DEVICE_13      26
#define PCI_DEVICE_NUMBER_PCH_PCIE_DEVICE_14      27
#define PCI_DEVICE_NUMBER_PCH_PCIE_ROOT_PORTS     8
#define PCI_FUNCTION_NUMBER_PCH_PCIE_ROOT_PORT_1  0
#define PCI_FUNCTION_NUMBER_PCH_PCIE_ROOT_PORT_2  0
#define PCI_FUNCTION_NUMBER_PCH_PCIE_ROOT_PORT_3  0
#define PCI_FUNCTION_NUMBER_PCH_PCIE_ROOT_PORT_4  0
#define PCI_FUNCTION_NUMBER_PCH_PCIE_ROOT_PORT_5  0
#define PCI_FUNCTION_NUMBER_PCH_PCIE_ROOT_PORT_6  0
#define PCI_FUNCTION_NUMBER_PCH_PCIE_ROOT_PORT_7  0
#define PCI_FUNCTION_NUMBER_PCH_PCIE_ROOT_PORT_8  0
#define PCI_FUNCTION_NUMBER_PCH_PCIE_ROOT_PORT_9  0
#define PCI_FUNCTION_NUMBER_PCH_PCIE_ROOT_PORT_10 0
#define PCI_FUNCTION_NUMBER_PCH_PCIE_ROOT_PORT_11 0
#define PCI_FUNCTION_NUMBER_PCH_PCIE_ROOT_PORT_12 0
#define PCI_FUNCTION_NUMBER_PCH_PCIE_ROOT_PORT_13 0
#define PCI_FUNCTION_NUMBER_PCH_PCIE_ROOT_PORT_14 0


#define V_PCH_PCIE_VENDOR_ID                      V_PCH_INTEL_VENDOR_ID

//
// LBG Production (PRQ) PCI Express Root Ports Device ID's
//
#define V_PCH_LBG_PROD_PCIE_DEVICE_ID_PORT1            0x1BB8  ///< PCI Express Root Port #1,  LBG PRQ
#define V_PCH_LBG_PROD_PCIE_DEVICE_ID_PORT2            0x1BB9  ///< PCI Express Root Port #2,  LBG PRQ
#define V_PCH_LBG_PROD_PCIE_DEVICE_ID_PORT3            0x1BBA  ///< PCI Express Root Port #3,  LBG PRQ
#define V_PCH_LBG_PROD_PCIE_DEVICE_ID_PORT4            0x1BBB  ///< PCI Express Root Port #4,  LBG PRQ
#define V_PCH_LBG_PROD_PCIE_DEVICE_ID_PORT5            0x1BBC  ///< PCI Express Root Port #5,  LBG PRQ
#define V_PCH_LBG_PROD_PCIE_DEVICE_ID_PORT6            0x1BBD  ///< PCI Express Root Port #6,  LBG PRQ
#define V_PCH_LBG_PROD_PCIE_DEVICE_ID_PORT7            0x1BBE  ///< PCI Express Root Port #7,  LBG PRQ
#define V_PCH_LBG_PROD_PCIE_DEVICE_ID_PORT8            0x1BBF  ///< PCI Express Root Port #8,  LBG PRQ
#define V_PCH_LBG_PROD_PCIE_DEVICE_ID_PORT9            0x1BC0  ///< PCI Express Root Port #9,  LBG PRQ
#define V_PCH_LBG_PROD_PCIE_DEVICE_ID_PORT10           0x1BC1  ///< PCI Express Root Port #10, LBG PRQ
#define V_PCH_LBG_PROD_PCIE_DEVICE_ID_PORT11           0x1BC2  ///< PCI Express Root Port #11, LBG PRQ
#define V_PCH_LBG_PROD_PCIE_DEVICE_ID_PORT12           0x1BC3  ///< PCI Express Root Port #12, LBG PRQ
#define V_PCH_LBG_PROD_PCIE_DEVICE_ID_PORT13           0x1BC4  ///< PCI Express Root Port #13, LBG PRQ
#define V_PCH_LBG_PROD_PCIE_DEVICE_ID_PORT14           0x1BC5  ///< PCI Express Root Port #14, LBG PRQ

//lulu
#define R_PCH_PCIE_STRPFUSECFG                    0xFC
#define B_PCH_PCIE_STRPFUSECFG_SERM               BIT29
#define B_PCH_PCIE_STRPFUSECFG_PXIP               (BIT27 | BIT26 | BIT25 | BIT24)
#define N_PCH_PCIE_STRPFUSECFG_PXIP               24
#define V_PCIE_CFG_STRPFUSECFG_PXIP               0x0
#define B_PCIE_CFG_STRPFUSECFG_RPC_SIP17          (BIT16 | BIT15 | BIT14)
#define B_PCH_PCIE_STRPFUSECFG_RPC                (BIT15 | BIT14)
#define V_PCH_PCIE_STRPFUSECFG_RPC_1_1_1_1        0
#define V_PCH_PCIE_STRPFUSECFG_RPC_2_1_1          1
#define V_PCH_PCIE_STRPFUSECFG_RPC_2_2            2
#define V_PCH_PCIE_STRPFUSECFG_RPC_4              3
#define V_PCIE_CFG_STRPFUSECFG_RPC_4_SIP17        4
#define N_PCH_PCIE_STRPFUSECFG_RPC                14
#define B_PCIE_CFG_STRPFUSECFG_LR                 BIT13
#define B_PCH_PCIE_STRPFUSECFG_MODPHYIOPMDIS      BIT9
#define B_PCH_PCIE_STRPFUSECFG_PLLSHTDWNDIS       BIT8
#define B_PCH_PCIE_STRPFUSECFG_STPGATEDIS         BIT7
#define B_PCH_PCIE_STRPFUSECFG_ASPMDIS            BIT6
#define B_PCH_PCIE_STRPFUSECFG_LDCGDIS            BIT5
#define B_PCH_PCIE_STRPFUSECFG_LTCGDIS            BIT4
#define B_PCH_PCIE_STRPFUSECFG_CDCGDIS            BIT3
#define B_PCH_PCIE_STRPFUSECFG_DESKTOPMOB         BIT2

//
// PCIE PCRs (PID:SPA SPB SPC SPD SPE)
//
#define R_PCH_PCR_SPX_PCD                         0                       ///< Port configuration and disable
#define B_PCH_PCR_SPX_PCD_RP1FN                   (BIT2 | BIT1 | BIT0)    ///< Port 1 Function Number
#define B_PCH_PCR_SPX_PCD_RP1CH                   BIT3                    ///< Port 1 config hide
#define B_PCH_PCR_SPX_PCD_RP2FN                   (BIT6 | BIT5 | BIT4)    ///< Port 2 Function Number
#define B_PCH_PCR_SPX_PCD_RP2CH                   BIT7                    ///< Port 2 config hide
#define B_PCH_PCR_SPX_PCD_RP3FN                   (BIT10 | BIT9 | BIT8)   ///< Port 3 Function Number
#define B_PCH_PCR_SPX_PCD_RP3CH                   BIT11                   ///< Port 3 config hide
#define B_PCH_PCR_SPX_PCD_RP4FN                   (BIT14 | BIT13 | BIT12) ///< Port 4 Function Number
#define B_PCH_PCR_SPX_PCD_RP4CH                   BIT15                   ///< Port 4 config hide
#define S_PCH_PCR_SPX_PCD_RP_FIELD                4                       ///< 4 bits for each RP FN
#define B_PCH_PCR_SPX_PCD_P1D                     BIT16                   ///< Port 1 disable
#define B_PCH_PCR_SPX_PCD_P2D                     BIT17                   ///< Port 2 disable
#define B_PCH_PCR_SPX_PCD_P3D                     BIT18                   ///< Port 3 disable
#define B_PCH_PCR_SPX_PCD_P4D                     BIT19                   ///< Port 4 disable
#define B_PCH_PCR_SPX_PCD_SRL                     BIT31                   ///< Secured Register Lock

#endif