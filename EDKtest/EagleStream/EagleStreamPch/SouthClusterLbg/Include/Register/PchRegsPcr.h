/** @file
  Register names for PCH private chipset register

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
 Copyright (c) 2013 - 2014 Intel Corporation. All rights reserved
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
#ifndef _PCH_REGS_PCR_H_
#define _PCH_REGS_PCR_H_

///
/// Definition for PCR base address (defined in PchReservedResources.h)
///
//#define PCH_PCR_BASE_ADDRESS            0xFD000000
//#define PCH_PCR_MMIO_SIZE               0x01000000
/**
  Definition for PCR address
  The PCR address is used to the PCR MMIO programming
**/
#define PCH_PCR_ADDRESS(Pid, Offset)    (PCH_PCR_BASE_ADDRESS | ((UINT8)(Pid) << 16) | (UINT16)(Offset))

/**
  Definition for SBI PID
  The PCH_SBI_PID defines the PID for PCR MMIO programming and PCH SBI programming as well.
**/
typedef enum {
  PID_ICLK       = 0xAD,
  PID_MODPHY0    = 0xA4,
  PID_MODPHY1    = 0xA5,
  PID_MODPHY2    = 0xA6,
  PID_OPIPHY     = 0xAC, // @todo EBG: delete after resolving dmi14 dependencies
  PID_USB2       = 0xCA,
  PID_DMI        = 0x88,
  PID_RLINK      = 0x89,

  PID_SATA0      = 0x73,
  PID_SATA1      = 0x74,
  PID_SATA2      = 0x75,

  PID_DSP        = 0xD7,
  PID_ESPISPI    = 0x72,
  PID_FIA        = 0xCF,
  PID_PCIE0_P0   = 0x40,
  PID_PCIE0_P1   = 0x41,
  PID_PCIE0_P2   = 0x42,
  PID_PCIE0_P3   = 0x43,
  PID_PCIE1_P0   = 0x44,
  PID_PCIE1_P1   = 0x45,
  PID_PCIE1_P2   = 0x46,
  PID_PCIE1_P3   = 0x47,
  PID_PCIE2_P0   = 0x48,
  PID_PCIE2_P1   = 0x49,
  PID_PCIE2_P2   = 0x4A,
  PID_PCIE2_P3   = 0x4B,
  PID_PCIE3_P0   = 0x4C,
  PID_PCIE3_P1   = 0x4D,
  PID_PCIE3_P2   = 0x4E,
  PID_PCIE3_P3   = 0x4F,

  PID_XHCI       = 0x70,
  PID_OTG        = 0x71, // @todo EBG: delete after resolving client usb dependencies
  PID_SERIALIO   = 0xCB,
  PID_GBE        = 0xDB,
  PID_ICC        = 0xDC,
  PID_PMC        = 0xCC,
  PID_PMCBR      = 0xCD,
  PID_PSF9       = 0x7C,
  PID_PSF8       = 0x7D,
  PID_PSF7       = 0x7E,
  PID_PSF6       = 0xBF,
  PID_PSF5       = 0xBE,
  PID_CSME_PSF   = 0xBD,
  PID_PSF3       = 0xBC,
  PID_PSF2       = 0xBB,
  PID_PSF1       = 0xBA,
  PID_PSTH       = 0xC9,
  PID_LPC        = 0xC7,
  PID_SMB        = 0xC6,
  PID_P2S        = 0xC5,
  PID_IEH        = 0xC2,
  PID_ITSS       = 0xC4,
  PID_RTC_HOST   = 0xC3,
  PID_MCSMB      = 0xC1,
  PID_DMASMB     = 0xC0,
  PID_IO_WIDGET  = 0xC8,

  PID_DTS0       = 0xB2,
  PID_DTS1       = 0xB3,
  PID_DTS2       = 0xB4,
  PID_DTS3       = 0xB5,
  PID_GPIOCOM0   = 0x6E,
  PID_GPIOCOM1   = 0x6D,
  PID_GPIOCOM2   = 0x6C,
  PID_GPIOCOM3   = 0x6B,
  PID_GPIOCOM4   = 0x6A,
  PID_GPIOCOM5   = 0x69,
  PID_TAM        = 0x65,
  PID_TAP2IOSFSB = 0x68,
  PID_ENDEBUG    = 0x67,
  PID_IOSFSB2TAP = 0x66,
  PID_DCI        = 0xB8,
  PID_NPK        = 0xB6,
  PID_DFXAGG     = 0xB7,
  PID_FUSE       = 0xD5,
  PID_DRNG       = 0xD2,
  PID_FSPROX4    = 0x64,
  PID_FSPROX3    = 0x63,
  PID_FSPROX2    = 0x62,
  PID_FSPROX1    = 0x61,
  PID_FSPROX0    = 0x60,
  PID_CSME17     = 0x51,
  PID_CSME16     = 0x38,
  PID_CSME15     = 0x9F,
  PID_CSME14     = 0x9E,
  PID_CSME13     = 0x9D,
  PID_CSME12     = 0x9C,
  PID_CSME11     = 0x9B,
  PID_CSME10     = 0x9A,
  PID_CSME9      = 0x99,
  PID_CSME8      = 0x98,
  PID_CSME7      = 0x97,
  PID_CSME6      = 0x96,
  PID_CSME5      = 0x95,
  PID_CSME4      = 0x94,
  PID_CSME3      = 0x93,
  PID_CSME2      = 0x92,
  PID_CSME1      = 0x91,
  PID_CSME0      = 0x90,
  PID_HOTHAM     = 0x53,
  PID_CSMERTC    = 0x52
} PCH_SBI_PID;

#endif
