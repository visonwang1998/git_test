/** @file
  System Infor Var Hearder File

  @copyright
  INTEL CONFIDENTIAL
  Copyright 2017 - 2021 Intel Corporation. <BR>

  The source code contained or described herein and all documents related to the
  source code ("Material") are owned by Intel Corporation or its suppliers or
  licensors. Title to the Material remains with Intel Corporation or its suppliers
  and licensors. The Material may contain trade secrets and proprietary    and
  confidential information of Intel Corporation and its suppliers and licensors,
  and is protected by worldwide copyright and trade secret laws and treaty
  provisions. No part of the Material may be used, copied, reproduced, modified,
  published, uploaded, posted, transmitted, distributed, or disclosed in any way
  without Intel's prior express written permission.

  No license under any patent, copyright, trade secret or other intellectual
  property right is granted to or conferred upon you by disclosure or delivery
  of the Materials, either expressly, by implication, inducement, estoppel or
  otherwise. Any license under such intellectual property rights must be
  express and approved by Intel in writing.

  Unless otherwise agreed by Intel in writing, you may not remove or alter
  this notice or any other notice embedded in Materials by Intel or
  Intel's suppliers or licensors in any way.
**/

#ifndef _SYSTEM_INFO_VAR_INCLUDES_
#define _SYSTEM_INFO_VAR_INCLUDES_

#include <Uefi.h>

#define POSTED_METHOD_DISABLED  0
#define POSTED_METHOD_ENABLED   1

#pragma pack (push,1)

typedef enum BootMode {
  NormalBoot  = 0,  // Normal path through RC with full init, mem detection, init, training, etc.
                    //    Some of these MRC specific init routines can be skipped based on MRC input params
                    //    in addition to the sub-boot type (WarmBoot, WarmBootFast, etc).
  S3Resume    = 1   // S3 flow through RC. Should do the bare minimum required for S3
                    //    init and be optimized for speed.
} BootMode;

//
// This is used to determine what type of die is connected to a UPI link
//
typedef enum {
  UpiConnectionTypeCpu,
  UpiConnectionTypePcieGen4,
  UpiConnectionTypeFpga,
  UpiConnectionTypeMax
} UPI_CONNECTION_TYPE;

typedef struct {
  UINT32 StackPresentBitmap[MAX_SOCKET];           ///< bitmap of present stacks per socket
  UINT8  StackBus[MAX_SOCKET][MAX_LOGIC_IIO_STACK];///< Bus of each stack
  UINT32 StackMmiol[MAX_SOCKET][MAX_IIO_STACK];    ///< mmiol of each IIO stack, if it works as CXL, the mmiol base is RCRBBAR
  UINT8  SocketFirstBus[MAX_SOCKET];
  UINT8  Socket10nmUboxBus0[MAX_SOCKET];           //10nm CPU use only
  UINT8  TotIoDie[MAX_SOCKET];                     //GNR & SRF CPU use only
  UINT8  TotCmpDie[MAX_SOCKET];                    //GNR & SRF CPU use only
  UINT8  SocketLastBus[MAX_SOCKET];
  UINT8  segmentSocket[MAX_SOCKET];
  UINT8  KtiPortCnt;
  UINT32 socketPresentBitMap;
  UINT32 SecondaryNodeBitMap;
  UINT32 FpgaPresentBitMap;
  UINT32 mmCfgBase;
  UINT64 SocketMmCfgBase[MAX_SOCKET];
  UINT8  DdrMaxCh;
  UINT8  DdrMaxImc;                               ///< Logical number of IMC count, ignoring logical holes
  UINT8  DdrPhysicalMaxImc;                       ///< Physical number of IMC count from Capid
  UINT8  DdrNumChPerMc;
  UINT8  DdrNumPseudoChPerCh;
  UINT8  imcEnabled[MAX_SOCKET][MAX_IMC];
  UINT8  mcId[MAX_SOCKET][MAX_CH];
  MRC_MST MemSsType[MAX_SOCKET];                    ///< MemSsType global identifier for DDR vs. HBM
  UINT32  MmioBar[MAX_SOCKET][TYPE_MAX_MMIO_BAR];
  UINT8   HbmMaxCh;
  UINT8   HbmMaxIoInst;
  UINT8   HbmNumChPerMc;
  UINT8   HbmNumChPerIo;
  UINT32  LastCsrAddress[2];
  UINT32  LastCsrMmioAddr;
  UINT8   CsrCachingEnable;
  UINT32  LastCsrMcAddress[2];
  UINT32  LastCsrMcMmioPhyAddr;
  UINT8   CsrPciBarCachingEnable;
  UINT32  LastCsrPciBarAddr[2];
  UINT64  LastCsrPciBarPhyAddr;
  UINT32  LastSBPortId[MAX_SOCKET];
  UPI_CONNECTION_TYPE         UpiConnectionType[MAX_SOCKET];
  BOOLEAN PostedCsrAccessAllowed;                   // SW is allowed to use posted CSR writes method when TRUE
  BOOLEAN PostedWritesEnabled;                      // All CSR writes use posted method when TRUE, non-posted when FALSE
  BOOLEAN DataPopulated;                            // CPU_CSR_ACCESS_VAR is unavailable when FALSE
  HPM_VSEC_RESOURCE SocketHpmVsecRes[MAX_SOCKET];   // HPM VSEC info for all sockets
  BOOLEAN HbmSku;
  UINT8   HcxType[MAX_SOCKET];
  STACKID_SWAP_INFO StackIdSwapInfo[MAX_SOCKET];    //StackID sync after do StackId swap,including Stack swap table and whether do stack swap
  UINT64  Cxl1p1Rcrb[MAX_SOCKET][MAX_IIO_STACK];    // CXL 1.1 RCRB, one per PI5 stack
  UINT32  DmiRcrb[MAX_SOCKET];                      // DMI RCRB region, one per socket
  UINT8   FabricType;                               //Compute die 10x6, 10x5, and 6x5 type is stored
  UINT8   ChopType;                                 //Compute Die Chop Type
  UINT8   MdfInstCount;
} CPU_CSR_ACCESS_VAR;

typedef struct {
  UINT32 MeRequestedSizeNv;
  UINT32 MeRequestedAlignmentNv;
  UINT8  SbspSocketIdNv;
} SYS_INFO_VAR_NVRAM;

typedef struct _CPUID_REGISTER_INFO {
  UINT32 Eax;
  UINT32 Ebx;
  UINT32 Ecx;
  UINT32 Edx;
} CPUID_REGISTER_INFO;

typedef struct {
  UINT32 capid0;
  UINT32 capid1;
} SOC_CAPID_REGISTER_INFO;

typedef struct {
  UINT32 capid2;
  UINT32 capid4;
  UINT32 capid5;
  UINT32 capid10;
} DIELET_CAPID_REGISTER_INFO;

typedef struct {
  UINT32 capid3;
  UINT32 capid6lo; // Corresponding to CAPID6
  UINT32 capid6hi; // Corresponding to CAPID7
  UINT32 capid8;
  UINT32 capid9;
} COMPUTE_DIE_CAPID_REGISTER_INFO;

typedef struct _PROCESSOR_COMMON_INFO {
  SOC_CAPID_REGISTER_INFO           SocCapId;
  DIELET_CAPID_REGISTER_INFO        DieletCapId[MAX_COMPUTE_DIE + MAX_IO_DIE];
  COMPUTE_DIE_CAPID_REGISTER_INFO   ComputeDieCapId[MAX_COMPUTE_DIE];
  CPUID_REGISTER_INFO               ExtCpuid7;
  CPUID_REGISTER_INFO               ExtCpuid1B;
} PROCESSOR_COMMON_INFO;

typedef union _MC_DISABLE_MASK {
  UINT8  ComputeDie[MAX_COMPUTE_DIE];    // Bitmask of disabled MCs per compute die: 0 = MC enabled, 1 = MC disabled
  UINT32 Data;
} MC_DISABLE_MASK;

typedef struct {
  UINT32 MeRequestedSize;
  UINT32 MeRequestedAlignment;
  UINT32 CheckPoint;
  UINT8  ResetRequired;
  UINT8  Emulation;
  BootMode SysBootMode;
  CPU_CSR_ACCESS_VAR        CpuCsrAccessVarHost;    // Common resource for CsrAccessRoutines
  UINT64   CpuFreq;
  UINT8    SocketId;
  SYS_INFO_VAR_NVRAM SysInfoVarNvram;
  BOOLEAN  UsraTraceControl;
  UINT16   UsraTraceConfiguration;                 // Bit               7       6        5           4                     3:0
                                                   //               Write, Modify, GetAddr, Long/Short, Trace 0x5 as signature
                                                   // Bit               15                              14:11   10     9     8
                                                   // DumpCpuCsrAccessVar,                                TBD, CSR, PCIE, Read
  BOOLEAN               CpuCsrAccessVarInfoDumped;
  PROCESSOR_COMMON_INFO ProcessorCommonInfo[MAX_SOCKET];
  EFI_PHYSICAL_ADDRESS  SocAddrMapData;
  UINTN                 UsraPpiPtr;
  MC_DISABLE_MASK       PhysicalMcDisableMask[MAX_SOCKET];
} SYSTEM_INFO_VAR;

#pragma pack (pop)

#endif //#ifndef _SYSTEM_INFO_VAR_INCLUDES_
