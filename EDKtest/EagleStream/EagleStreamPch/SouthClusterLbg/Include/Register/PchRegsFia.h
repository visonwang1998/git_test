/** @file
  Register definition for FIA component

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
 Copyright (c) 2014 Intel Corporation. All rights reserved
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
#ifndef _PCH_REGS_FIA_H_
#define _PCH_REGS_FIA_H_


//
// Private chipset regsiter (Memory space) offset definition
// The PCR register defines is used for PCR MMIO programming and PCH SBI programming as well.
//

//
// PID:FIA
//
#define R_PCH_FIA_PCR_CC                                  0
#define B_PCH_FIA_PCR_CC_SRL                              BIT31
#define B_PCH_FIA_PCR_CC_PTOCGE                           BIT17
#define B_PCH_FIA_PCR_CC_OSCDCGE                          BIT16
#define B_PCH_FIA_PCR_CC_SCPTCGE                          BIT15

#define R_PCH_FIA_PCR_CLSDM1                              0x18
#define B_PCH_FIA_PCR_CLSDM1_DMIPDIPSLSD                  (BIT17 | BIT16)
#define B_PCH_FIA_PCR_CLSDM1_PCIEPDIPSLSD                 (BIT1 | BIT0)
#define R_PCH_FIA_PCR_PLLCTL                              0x20
#define B_PCH_FIA_PCR_PLLCTL_PLLCLKVADT                   (BIT30 | BIT29 | BIT28)
#define B_PCH_FIA_PCR_PLLCTL_CL0PLLWAIT                   (BIT14 | BIT13 | BIT12)
#define B_PCH_FIA_PCR_PLLCTL_PLLACBGD                     BIT31
#define B_PCH_FIA_PCR_PLLCTL_CL1PLLFO                     BIT1
#define B_PCH_FIA_PCR_PLLCTL_CL0PLLFO                     BIT0
#define N_PCH_FIA_PCR_PLLCTL_CL0PLLWAIT                   12
#define R_PCH_FIA_PCR_PMC                                 0x40
#define B_PCH_FIA_PCR_PMC_OILODVRE                        (BIT21 | BIT20)
#define B_PCH_FIA_PCR_PMC_PRDPGE                          BIT3
#define R_PCH_FIA_PCR_PGCUC                               0x48
#define B_PCH_FIA_PCR_PGCUC_ACC_CLKGATE_DISABLED          BIT0
#define R_PCH_FIA_PCR_PGCUCSOC                            0x50
#define B_PCH_FIA_PCR_PGCUCSOC_ACC_SOC_CLKGATE_DISABLED   BIT0

#define R_PCH_FIA_PCR_TREFCLKONTMR1                       0x180 // T refclkon timer 1, controls delay between CLKREQ asserted and CLKSRC
#define R_PCH_FIA_PCR_TREFCLKONTMR2                       0x184
#define R_PCH_FIA_PCR_TREFCLKONTMR3                       0x188
#define R_PCH_FIA_PCR_TREFCLKONTMR4                       0x18C
#define B_PCH_FIA_PCR_TREFCLKON_FIELD                     0xF   // each TREFCLKON field has 4 bits
#define S_PCH_FIA_PCR_TREFCLKON_FIELD                     4     // each TREFCLKON field has 4 bits
#define S_PCH_FIA_PCR_TREFCLKON_FIELDS_PER_REG            8     // there are 8 TREFCLKON fields per register
#define V_PCH_FIA_PCR_TREFCLKON_0us                       0x0
#define V_PCH_FIA_PCR_TREFCLKON_5us                       0x1
#define V_PCH_FIA_PCR_TREFCLKON_10us                      0x2
#define V_PCH_FIA_PCR_TREFCLKON_15us                      0x3
#define V_PCH_FIA_PCR_TREFCLKON_20us                      0x4
#define V_PCH_FIA_PCR_TREFCLKON_25us                      0x5
#define V_PCH_FIA_PCR_TREFCLKON_30us                      0x6
#define V_PCH_FIA_PCR_TREFCLKON_35us                      0x7
#define V_PCH_FIA_PCR_TREFCLKON_40us                      0x8
#define V_PCH_FIA_PCR_TREFCLKON_45us                      0x9
#define V_PCH_FIA_PCR_TREFCLKON_50us                      0xA
#define V_PCH_FIA_PCR_TREFCLKON_60us                      0xB
#define V_PCH_FIA_PCR_TREFCLKON_70us                      0xC
#define V_PCH_FIA_PCR_TREFCLKON_80us                      0xD
#define V_PCH_FIA_PCR_TREFCLKON_90us                      0xE
#define V_PCH_FIA_PCR_TREFCLKON_100us                     0xF

#define R_PCH_PCR_FIA_LOS1_REG_BASE                       0x300
#define R_PCH_PCR_FIA_LOS2_REG_BASE                       0x304
#define R_PCH_PCR_FIA_LOS3_REG_BASE                       0x308
#define V_PCH_PCR_FIA_LANE_OWN_PCIEDMI                    0x0
#define V_PCH_PCR_FIA_LANE_OWN_USB3                       0x1
#define V_PCH_PCR_FIA_LANE_OWN_SATA                       0x2
#define V_PCH_PCR_FIA_LANE_OWN_GBE                        0x4
#define V_PCH_PCR_FIA_LANE_OWN_MUXPCIE                    0xC

#define B_PCH_FIA_PCR_LOS1_L0O                            (BIT3 | BIT2 | BIT1 | BIT0)
#define B_PCH_FIA_PCR_LOS1_L1O                            (BIT7 | BIT6 | BIT5 | BIT4)
#define B_PCH_FIA_PCR_LOS1_L2O                            (BIT11 | BIT10 | BIT9 | BIT8)
#define B_PCH_FIA_PCR_LOS1_L3O                            (BIT15 | BIT14 | BIT13 | BIT12)
#define B_PCH_FIA_PCR_LOS1_L4O                            (BIT19 | BIT18 | BIT17 | BIT16)
#define B_PCH_FIA_PCR_LOS1_L5O                            (BIT23 | BIT22 | BIT21 | BIT20)
#define B_PCH_FIA_PCR_LOS1_L6O                            (BIT27 | BIT26 | BIT25 | BIT24)
#define B_PCH_FIA_PCR_LOS1_L7O                            (BIT31 | BIT30 | BIT29 | BIT28)
#define B_PCH_FIA_PCR_LOS2_L8O                            (BIT3 | BIT2 | BIT1 | BIT0)
#define B_PCH_FIA_PCR_LOS2_L9O                            (BIT7 | BIT6 | BIT5 | BIT4)
#define B_PCH_FIA_PCR_LOS2_L10O                           (BIT11 | BIT10 | BIT9 | BIT8)
#define B_PCH_FIA_PCR_LOS2_L11O                           (BIT15 | BIT14 | BIT13 | BIT12)
#define B_PCH_FIA_PCR_LOS2_L12O                           (BIT19 | BIT18 | BIT17 | BIT16)
#define B_PCH_FIA_PCR_LOS2_L13O                           (BIT23 | BIT22 | BIT21 | BIT20)
#define B_PCH_FIA_PCR_LOS2_L14O                           (BIT27 | BIT26 | BIT25 | BIT24)
#define B_PCH_FIA_PCR_LOS2_L15O                           (BIT31 | BIT30 | BIT29 | BIT28)
#define B_PCH_FIA_PCR_LOS3_L16O                           (BIT3 | BIT2 | BIT1 | BIT0)
#define B_PCH_FIA_PCR_LOS3_L17O                           (BIT7 | BIT6 | BIT5 | BIT4)
#define B_PCH_FIA_PCR_LOS3_L18O                           (BIT11 | BIT10 | BIT9 | BIT8)
#define B_PCH_FIA_PCR_LOS3_L19O                           (BIT15 | BIT14 | BIT13 | BIT12)
#define B_PCH_FIA_PCR_LOS3_L20O                           (BIT19 | BIT18 | BIT17 | BIT16)
#define B_PCH_FIA_PCR_LOS3_L21O                           (BIT23 | BIT22 | BIT21 | BIT20)
#define B_PCH_FIA_PCR_LOS3_L22O                           (BIT27 | BIT26 | BIT25 | BIT24)
#define B_PCH_FIA_PCR_LOS3_L23O                           (BIT31 | BIT30 | BIT29 | BIT28)
#define B_PCH_FIA_PCR_LOS4_L24O                           (BIT3 | BIT2 | BIT1 | BIT0)
#define B_PCH_FIA_PCR_LOS4_L25O                           (BIT7 | BIT6 | BIT5 | BIT4)
#define B_PCH_FIA_PCR_LOS4_L26O                           (BIT11 | BIT10 | BIT9 | BIT8)
#define B_PCH_FIA_PCR_LOS4_L27O                           (BIT15 | BIT14 | BIT13 | BIT12)
#define B_PCH_FIA_PCR_LOS4_L28O                           (BIT19 | BIT18 | BIT17 | BIT16)
#define B_PCH_FIA_PCR_LOS4_L29O                           (BIT23 | BIT22 | BIT21 | BIT20)
#define B_PCH_FIA_PCR_LOS4_L30O                           (BIT27 | BIT26 | BIT25 | BIT24)
#define B_PCH_FIA_PCR_LOS4_L31O                           (BIT31 | BIT30 | BIT29 | BIT28)
#define B_PCH_FIA_PCR_LOS5_L32O                           (BIT3 | BIT2 | BIT1 | BIT0)
#define B_PCH_FIA_PCR_LOS5_L33O                           (BIT7 | BIT6 | BIT5 | BIT4)
#define B_PCH_FIA_PCR_LOS5_L34O                           (BIT11 | BIT10 | BIT9 | BIT8)
#define B_PCH_FIA_PCR_LOS5_L35O                           (BIT15 | BIT14 | BIT13 | BIT12)
#define B_PCH_FIA_PCR_LOS5_L36O                           (BIT19 | BIT18 | BIT17 | BIT16)
#define B_PCH_FIA_PCR_LOS5_L37O                           (BIT23 | BIT22 | BIT21 | BIT20)

#endif
