#include <stdio.h>
#include <Library/UefiLib.h>// For use Printf	
#include <stdlib.h>// For use atoi
#include <string.h>// For use strstr, strncpy, strtok...etc
#include <Library/UefiBootServicesTableLib.h>// For use gBS
#include <Uefi.h>
#include <Library/ShellLib.h>


#include <Library/IoLib.h>						// For use Ioread32
#include <Protocol/SimpleTextOut.h>
#include <Protocol/PciRootBridgeIo.h>			// For use EFI_PCI_ROOT_BRIDGE_IO_PROTOCOL

//hsio read
#include <PchAccess.h>
#include <Register/PchRegsPcr.h>
#include <Register/PchRegsFia.h>
#include <Library/PchP2sbLib.h>
#include <Library/PchSbiAccessLib.h>
#include <Library/PchInitCommonLib.h>
#include <Library/PchPcieRpLib.h>

//[Gbt_Lulu_C001] +
#include <Library/PciSegmentLib.h>  //For use PciSegmentRead32
#include <SiliconRegAccess.h>
//[Gbt_Lulu_C001] +
#include <Library/MemoryAllocationLib.h>
#include <Protocol/HiiDatabase.h>
#include <Library/HiiLib.h>

#include <SPD.h> // For SPD command

//[Gbt_Lulu_C006] +
#include <Kcs.h> // For Ipmi
//[Gbt_Lulu_C006] -

//[GBT_Chris_W_EGSTool_1]+
#include <Protocol/SmbusHc.h>					// For smbus protocol
#include <Library/SmbusLib.h>					// For smbus protocol
#include <IndustryStandard/SmBus.h>				// For smbus protocol
//[GBT_Chris_W_EGSTool_1]-

// [Gbt_Jim_Y0008]+
#include <UsraAccessApi.h>
// [Gbt_Jim_Y0008]-

#ifndef _FACE_H
#define _FACE_H

#define	CommonTitle "\
==============================================================================\n\
%s\n\
Version: %s  %s  %s\n\
Confirmed Platform : \n\
EagleStream \n\
==============================================================================\n"

#define Title	"[EagleStream Utility]"
#define Ver		"0.03"
#define DATE	"Date: " ## __DATE__
#define TIME	"Time: " ## __TIME__


typedef struct {
	CHAR8*	ArgStr;
	UINT8	ArgNumNeed;
	EFI_STATUS (*func)(int argc, char ** argv);
} ARG_INPUT_LIST;



#define BPB_TABLE_NUMBER 		0x07
#define SATA_BASE_ADDRESS		0xFD000000
#define ModPhy1					0xA5
#define ModPhy2					0xA6
#define TXDWORD6_ADDRESS		0X18
#define TXDWORD8_ADDRESS		0X20
#define TX_BASE					0x80
#define SATA_INVALID_DWORD  0xFFFFFFFF

//[GBT_Chris_W_EGSTool_1]+
#define SWITCH_ADDRESS               0xE2
#define SLOT_SWITCH_ADDRESS          0xE6
#define SECOND_SLOT_SWITCH_ADDRESS   0xEA
#define THIRD_SLOT_SWITCH_ADDRESS    0xEC
#define MPS_DATA_LENGTH              0x800
#define SIGNATURE_OFFSET             0x7F0
//[GBT_Chris_W_EGSTool_1]-

// [GBT_Deann_W0046] +
#define PCI_CFG_ADDRESS(bus,dev,func,reg) ((UINT32)((((UINTN)bus) << 24) + (((UINTN)dev) << 16) + (((UINTN)func) << 8) + ((UINTN)reg)))
#define PCIE_CFG_ADDRESS(bus, dev, func, reg) ((UINTN)(gPcieBase + (bus << 20) + (dev << 15) + (func << 12) + reg))

#define CPU_NUMBER 2
#define CPU_BUS_NUMBER 6

#define UPI_LINK_NUMBER 4
#define MAX_LANES_PER_LINK_SPR 24
#define MAX_SET_OF_PRESET_COEFF 11

#define USB2_NUMBER 16
#define USB3_NUMBER 10
#define USB_OC_NUMBER 8
//
// Over Current Mapping registers
//
#define R_XHCI_MEM_U2OCM1   0x90A4    ///< XHCI USB2 Overcurrent Pin N Mapping
#define R_XHCI_MEM_U3OCM1   0x9124    ///< XHCI USB3 Overcurrent Pin N Mapping

#define PH_TCL_LANE0_KTI_REUT_REG  0x09120344
#define PH_TCL_LANE1_KTI_REUT_REG  0x09120348
#define PH_TCL_LANE2_KTI_REUT_REG  0x0912034C
#define PH_TCL_LANE3_KTI_REUT_REG  0x09120350
#define PH_TCL_LANE4_KTI_REUT_REG  0x09120388
#define PH_TCL_LANE5_KTI_REUT_REG  0x09120354
#define PH_TCL_LANE6_KTI_REUT_REG  0x09120358
#define PH_TCL_LANE7_KTI_REUT_REG  0x0912035C
#define PH_TCL_LANE8_KTI_REUT_REG  0x09120360
#define PH_TCL_LANE9_KTI_REUT_REG  0x09120364
#define PH_TCL_LANE10_KTI_REUT_REG 0x09120368
#define PH_TCL_LANE11_KTI_REUT_REG 0x0912036C
#define PH_TCL_LANE12_KTI_REUT_REG 0x09120370
#define PH_TCL_LANE13_KTI_REUT_REG 0x09120374
#define PH_TCL_LANE14_KTI_REUT_REG 0x09120378
#define PH_TCL_LANE15_KTI_REUT_REG 0x0912037C
#define PH_TCL_LANE16_KTI_REUT_REG 0x09120380
#define PH_TCL_LANE17_KTI_REUT_REG 0x09120384
#define PH_TCL_LANE18_KTI_REUT_REG 0x0912038C
#define PH_TCL_LANE19_KTI_REUT_REG 0x09120390
#define PH_TCL_LANE20_KTI_REUT_REG 0x09120394
#define PH_TCL_LANE21_KTI_REUT_REG 0x09120398
#define PH_TCL_LANE22_KTI_REUT_REG 0x0912039C
#define PH_TCL_LANE23_KTI_REUT_REG 0x091203A0
typedef struct {
	UINT32	PH_TCL[MAX_LANES_PER_LINK_SPR];
	UINT8   LinkStatus;
} UPI_PER_LINK;
typedef struct {
	UPI_PER_LINK	Link[UPI_LINK_NUMBER];
} UPI_PER_CPU;

typedef struct {
	UPI_PER_CPU	File;
	UPI_PER_CPU	Register;
} UPI_DATA;

typedef struct {
	UINT16	Usb2OcMapping;
	UINT16	Usb3OcMapping;
} USB_OC;

typedef struct {
	USB_OC	File;
	USB_OC	Register;
} USB_OC_DATA;

typedef struct {
/** Per Port HS Preemphasis Bias (PERPORTPETXISET)
  000b - 0mV
  001b - 11.25mV
  010b - 16.9mV
  011b - 28.15mV
  100b - 28.15mV
  101b - 39.35mV
  110b - 45mV
  111b - 56.3mV
**/
  UINT8   Petxiset;
/** Per Port HS Transmitter Bias (PERPORTTXISET)
  000b - 0mV
  001b - 11.25mV
  010b - 16.9mV
  011b - 28.15mV
  100b - 28.15mV
  101b - 39.35mV
  110b - 45mV
  111b - 56.3mV
**/
  UINT8   Txiset;
/**
  Per Port HS Transmitter Emphasis (IUSBTXEMPHASISEN)
  00b - Emphasis OFF
  01b - De-emphasis ON
  10b - Pre-emphasis ON
  11b - Pre-emphasis & De-emphasis ON
**/
  UINT8   Predeemp;
/**
  Per Port Half Bit Pre-emphasis (PERPORTTXPEHALF)
  1b - half-bit pre-emphasis
  0b - full-bit pre-emphasis
**/
  UINT8   Pehalfbit;
/**
  Semi Flexi Pre/DE-emphasis (reg_predeemp_semiflexi_en):
  1: Choose the predeemp setting (increase the DC amplitude)
  0: Choose the predeemp setting (decrease the DC amplitude)
**/
  UINT8   PredeempSemiflexEn;
  UINT8   ReservedBytes0[3];      // Reserved bytes
} USB2_PHY_PARAMETERS;

#define R_USB2_PCR_PP_LANE_BASE_ADDR      0x4000    ///< PP LANE base address
#define R_USB2_PCR_PER_PORT               0x00      ///< USB2 PER PORT          Addr[7:2] = 0x00
#define R_USB2_PCR_PER_PORT_2             0x26      ///< USB2 PER PORT 2        Addr[7:2] = 0x26

typedef struct {
	USB2_PHY_PARAMETERS File;
	USB2_PHY_PARAMETERS Register;
	UINT8	PortConfig;
} USB2_STR_DATA;
// [GBT_Deann_W0046] -

#pragma pack(1)
//[GBT_Chris_W_EGSTool_1]+
typedef struct{
	UINT8	Name[7];
} MPS_CHIP_SIG;

typedef struct {
	UINT8    SmbusAddress;
	UINT8    Register;
	UINT8    Length;
	UINT16   Data;
} MPS_BINARY_FORMAT;
//[GBT_Chris_W_EGSTool_1]-

typedef struct{
    UINT32   TX_DWORD6;
    UINT32   TX_DWORD8;
} SATA_REGISTER;

typedef struct{
    UINT8 		    TableId;
    SATA_REGISTER   SATA0Port[8];
    SATA_REGISTER	SATA1Port[8];
	SATA_REGISTER	SATA2Port[4];
} SATA_TOTAL;

typedef struct{
    SATA_TOTAL	SATA;
} HSIO_SATA_TABLES;

typedef struct{
    UINT16 		BpbId;
    UINT8    	TableId;
} BPBID_TABLEID;

#define  PCIE_CAP_REG   0x02 //PCI Express Capabilities Register (Offset 02h)

//Pcieerr
//Pcieerror
#define  CAP_OFFSET_BASE		0x40
#define  CAP_OFFSET_LIMIT		0x100
// PCI r2.2 figure 6-10
#define  CAP_MIN_SIZE      		4
#define  MAX_CAPABILITIES		(CAP_OFFSET_LIMIT - CAP_OFFSET_BASE) / CAP_MIN_SIZE
#define  CAPABILITIES_MSK		0xFF
#define  EX_CAP_OFFSET_BASE 	0x100
#define  EX_CAP_OFFSET_LIMIT	0x1000
#define  EX_CAP_MIN_SIZE		4
#define  MAX_EX_CAPABILITIES	(EX_CAP_OFFSET_LIMIT - EX_CAP_OFFSET_BASE) / EX_CAP_MIN_SIZE
#define  EXCAPABILITIES_MSK		0xFFF

//
// AER Register offset...
//
#define PCIE_AER_OFFSET_REG_UES                                   0x04
#define   B_PCIE_AER_UES_DMWR_REQ_EGR_BLK_ERR                     BIT27
#define   B_PCIE_AER_UES_POI_TLP_EGR_BLK_ERR                      BIT26
#define   B_PCIE_AER_UES_TLP_PRE_BLK_ERR                          BIT25
#define   B_PCIE_AER_UES_ATO_EGR_BLK_ERR                          BIT24
#define   B_PCIE_AER_UES_MC_BLK_TLP_ERR                           BIT23
#define   B_PCIE_AER_UES_UNC_INT_ERR                              BIT22
#define   B_PCIE_AER_UES_ACS_VIO_ERR                              BIT21
#define   B_PCIE_AER_UES_UNS_REQ_ERR                              BIT20
#define   B_PCIE_AER_UES_ECRC_ERR                                 BIT19
#define   B_PCIE_AER_UES_MAL_TLP_ERR                              BIT18
#define   B_PCIE_AER_UES_RCV_OVR_ERR                              BIT17
#define   B_PCIE_AER_UES_UNE_CPL_ERR                              BIT16
#define   B_PCIE_AER_UES_CPL_ABT_ERR                              BIT15
#define   B_PCIE_AER_UES_CTO_ERR                                  BIT14
#define   B_PCIE_AER_UES_FLW_CTL_PRO_ERR                          BIT13
#define   B_PCIE_AER_UES_POI_TLP_ERR                              BIT12
#define   B_PCIE_AER_UES_SUPRISE_LINK_DOWN_ERR                    BIT5
#define   B_PCIE_AER_UES_DAT_LNK_ERR                              BIT4
#define PCIE_AER_OFFSET_REG_UEM                                   0x08
#define PCIE_AER_OFFSET_REG_UESEV                                 0x0C
#define   B_PCIE_AER_UESEV_CTO_SEV                                BIT14
#define PCIE_AER_OFFSET_REG_CES                                   0x10
#define   B_PCIE_AER_CES_HLOG_OVRF_ERR                            BIT15
#define   B_PCIE_AER_CES_COR_INT_ERR                              BIT14
#define   B_PCIE_AER_CES_ADV_NON_FAT_ERR                          BIT13
#define   B_PCIE_AER_CES_REP_TMR_TOT_ERR                          BIT12
#define   B_PCIE_AER_CES_REP_NUM_ROV_ERR                          BIT8
#define   B_PCIE_AER_CES_BAD_DLLP_ERR                             BIT7
#define   B_PCIE_AER_CES_BAD_TLP_ERR                              BIT6
#define   B_PCIE_AER_CES_RCV_ERR                                  BIT0

#define PCIE_AER_OFFSET_REG_CEM                                   0x14
#define PCIE_AER_OFFSET_REG_AECC                                  0x18
#define   B_PCIE_AER_AECC_ECRC_GEN_CAP                            BIT5
#define   B_PCIE_AER_AECC_ECRC_GEN_EN                             BIT6
#define   B_PCIE_AER_AECC_ECRC_CHK_CAP                            BIT7
#define   B_PCIE_AER_AECC_ECRC_CHK_EN                             BIT8
#define PCIE_AER_OFFSET_REG_REC                                   0x2c
#define PCIE_AER_OFFSET_REG_RES                                   0x30
#define   B_PCIE_AER_ROOT_ERR_STS_COR                             BIT0
#define   B_PCIE_AER_ROOT_ERR_STS_MUL_COR                         BIT1
#define   B_PCIE_AER_ROOT_ERR_STS_FAT_NONFAT                      BIT2
#define   B_PCIE_AER_ROOT_ERR_STS_MUL_FAT_NONFAT                  BIT3
#define   B_PCIE_AER_ROOT_ERR_STS_FIR_UNC_FAT                     BIT4
#define PCIE_AER_OFFSET_REG_ERRSID                                0x34


#define PCIE_EXT_CAP_HEADER_AERC		0x0001
#define PCIE_ENHANCED_CAPABILITY_PTR	0x0100
#define GET_DEVCTL_OFFSET(Bus, Dev, Func) (((Bus) == 0 && (Dev) == 0 && (Func) == 0) ? 0x60 : 0x08)
#define PcieAerNfatErrBitMap		(B_PCIE_AER_UES_CTO_ERR |B_PCIE_AER_UES_ACS_VIO_ERR |B_PCIE_AER_UES_CPL_ABT_ERR |B_PCIE_AER_UES_UNE_CPL_ERR |B_PCIE_AER_UES_POI_TLP_EGR_BLK_ERR |B_PCIE_AER_UES_TLP_PRE_BLK_ERR |B_PCIE_AER_UES_ATO_EGR_BLK_ERR |B_PCIE_AER_UES_MC_BLK_TLP_ERR |B_PCIE_AER_UES_DMWR_REQ_EGR_BLK_ERR)
#define PcieAerFatErrBitMap		  (B_PCIE_AER_UES_DAT_LNK_ERR |B_PCIE_AER_UES_POI_TLP_ERR |B_PCIE_AER_UES_FLW_CTL_PRO_ERR |B_PCIE_AER_UES_RCV_OVR_ERR |B_PCIE_AER_UES_MAL_TLP_ERR |B_PCIE_AER_UES_UNC_INT_ERR)
#define PcieAerCorrErrBitMap		(B_PCIE_AER_CES_RCV_ERR |B_PCIE_AER_CES_BAD_TLP_ERR |B_PCIE_AER_CES_BAD_DLLP_ERR |B_PCIE_AER_CES_REP_NUM_ROV_ERR |B_PCIE_AER_CES_REP_TMR_TOT_ERR |B_PCIE_AER_CES_COR_INT_ERR |B_PCIE_AER_CES_HLOG_OVRF_ERR)
#define PcieAerAdNfatErrBitMap	(B_PCIE_AER_CES_ADV_NON_FAT_ERR)
#define PcieAerEcrcBitMap			  (B_PCIE_AER_UES_ECRC_ERR)
#define PcieAerSurpriseLinkDownBitMap (B_PCIE_AER_UES_SUPRISE_LINK_DOWN_ERR)
#define PcieAerUreBitMap				(B_PCIE_AER_UES_UNS_REQ_ERR)

#define GBT_SETUP_NO_STRING16               L"N/A"


CHAR16 *PcieErrorItem[] = 
{
	L"PCIE Error",
	L"Corrected Error",
	L"Uncorrected Error",
	L"Fatal Error Enable",
	L"PCIE AER Corrected Errors",
	L"PCIE AER Advisory Nonfatal Error",
	L"PCIE AER NonFatal Error",
// [GBT_Deann_W0028] +
	L"PCIE AER Fatal Error ", // whitley string have " " at the end,  different to Purley.
	L"Assert NMI on SERR",
	L"Assert NMI on PERR",
// [GBT_Deann_W0028] -   	
// [Gbt_Jim_Y0005] +
	L"PCIE ECRC Error ",
	L"PCIE Unsupported Request Error ",
	L"PCIE Surprise Link Down Error "
// [Gbt_Jim_Y0005] -
};

UINT16	PcieItemCount = sizeof(PcieErrorItem) / sizeof(PcieErrorItem[0]);

typedef union {
  struct {
  UINT8 		PcieErrEn : 1;
  UINT8    	PcieCorrErrEn : 1;
  UINT8    	PcieUncorrErrEn : 1;
  UINT8    	PcieFatalErrEn : 1;
  UINT8    	PcieAerCorrErrEn : 1;
  UINT8    	PcieAerAdNfatErrEn : 1;
  UINT8    	PcieAerNfatErrEn : 1;
  UINT8    	PcieAerFatErrEn : 1;
// [GBT_Deann_W0028] +	
  UINT8    	PropagateSerr : 1;
  UINT8    	PropagatePerr : 1;
// [GBT_Deann_W0028] -	
// [Gbt_Jim_Y0006] +
	UINT8 		PcieAerEcrcEn : 1;
	UINT8			PcieAerUreEn : 1;
	UINT8			PcieAerSurpriseLinkDownEn : 1;
// [Gbt_Jim_Y0006] -
  } Bits;
  UINT32 Data;
} GBT_PCIE_ERROR;

typedef struct _IFR_VAR_NAME {
    EFI_GUID                 Guid;
    EFI_VARSTORE_ID          VarStoreId;
    UINT16                   Size;
	UINT32                   Attributes;	
    CHAR8*                   Name;
} IFR_VAR_NAME;

#pragma	pack()

#endif

