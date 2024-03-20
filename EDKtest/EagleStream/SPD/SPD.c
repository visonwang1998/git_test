#include "SPD.h"
#include <Library/UefiBootServicesTableLib.h>	// For use gBS
#include <Library\TimerLib.h>
#include <stdio.h>								
#include <Library/UefiLib.h>                    // For use Printf	
#include <stdlib.h>								// For use atoi
#include <Uefi.h>
#include <string.h>								// For use strstr, strncpy, strtok...etc
#include <Library/UefiRuntimeServicesTableLib.h>// For use gRT
#include <Library/MemoryAllocationLib.h>
#include <I3cDefinitions.h>
#include <SpdAccessCommon.h>
#include <UsraAccessType.h>
#include <Include/Protocol/Smbios.h>
#include <IndustryStandard/SmBios.h>
#include <Ddr5SpdRegisters.h>
#include <SiliconRegAccess.h>

EFI_GUID gEfiSmbiosProtocolGuid = {0x3583ff6, 0xcb36, 0x4940, { 0x94, 0x7e, 0xb9, 0xb3, 0x9f, 0x4a, 0xfa, 0xf7}};

#define SPD_DDR5_PAGE_SIZE        128 // Size of 1 SPD page for DDR5
//
// DDR_*_TCK_MIN use 1 ps(picosecond) precision
//
#define DDR_4400_TCK_MIN                455
#define DDR_4800_TCK_MIN                417
#define DDR_5200_TCK_MIN                385
#define DDR_5600_TCK_MIN                358
#define DDR_6000_TCK_MIN                334
#define DDR_6400_TCK_MIN                313
#define DDR_6800_TCK_MIN                295
#define DDR_7200_TCK_MIN                278
#define DDR_7600_TCK_MIN                264
#define DDR_8000_TCK_MIN                250
#define DDR_8400_TCK_MIN                239

#define SPD_MODULE_PART_DDR5 20                 // Number of bytes of module part - DDR5
#define SPD_MODULE_SERIAL    4                  // Number of bytes of Module Serial Number
#define SPD_TYPE_DDR5         0x12  // DDR5 SDRAM

#define MAX_SOCKET 2
#define MAX_CH 8 // Max channel per scket
#define MAX_DIMM 2  // Max DIMM per channel
#define MAX_MC_CH 2  // Max number of channels per MC
// For SPR, one I3C instance has 2 MCs
#define SPR_I3C_MC_NUMBER  2

#define DEVICE_CONTROL_SB_I3C0_REG 0x2A028004
#define HCI_VERSION_SB_I3C1_REG 0x2A129000
#define HCI_VERSION_SB_I3C0_REG 0x2A028000
#define RESET_CTRL_SB_I3C0_REG 0x2A028010
//I3C0 First Register Offset
#define SPR_I3C0_REG_OFFSET0 HCI_VERSION_SB_I3C0_REG
//I3C1 First Register Offset
#define SPR_I3C1_REG_OFFSET0 HCI_VERSION_SB_I3C1_REG
//Offset delta between I3C0 and I3C1 registers for SPR
#define SPR_SMB_OFFSET_DELTA (SPR_I3C1_REG_OFFSET0 - SPR_I3C0_REG_OFFSET0)
#define MAX_SMB_INSTANCE 2
#define MTS 4  //TSOD

//
// Bit mask for bits in the status register
//
#define I3C_WRITE_DONE_BIT_MASK      BIT0
#define I3C_READ_DONE_BIT_MASK       BIT1
#define I3C_CMD_QUEUE_READY_BIT_MASK BIT3
#define I3C_RESPONSE_READY_BIT_MASK  BIT4
#define I3C_TRANSFER_ERROR_BIT_MASK  BIT9

typedef struct
{
	UINTN           Capacity;
	CHAR8           *Unit;
} SIZE_DATA;

typedef struct
{
	UINT8 DeviceExist;
	CHAR8* DimmName;
	CHAR8* Type;
	CHAR8* Manufacturer;
	SIZE_DATA Size;
	UINT32 Speed;
	UINT8 SerialNumber[SPD_MODULE_SERIAL];
	UINT8 PartNumber[SPD_MODULE_PART_DDR5];
} SPD_STRUCT;

typedef struct {
	SPD_STRUCT	Spd;
	SPD_STRUCT	Smbios; 
	UINT8 SpdData[1024];
} SPD_DATA;

typedef struct _JEDEC_MF_ID
{
	UINT16           VendorId;
	CHAR8           *ManufacturerString;
} JEDEC_MF_ID;

JEDEC_MF_ID MemoryModuleManufacturerList[] =
{
	{ 0x0400, "Fujitsu" },
	{ 0x0700, "Hitachi" },
	{ 0x8900, "Intel" },
	{ 0x1000, "NEC" },
	{ 0x1c00, "Mitsubishi" },
	{ 0x1f00, "Atmel" },
	{ 0xa400, "IBM" },
	{ 0x2c00, "Micron" },
	{ 0xad00, "SK Hynix" },
	{ 0xb000, "Sharp" },
	{ 0xbf00, "SST" },
	{ 0x3e00, "Oracle" },
	{ 0x6200, "Sanyo" },
	{ 0x9800, "Toshiba" },
	{ 0xb300, "IDT" },
	{ 0xc100, "Infineon" },
	{ 0xc200, "Macronix" },
	{ 0x4500, "SanDisk" },
	{ 0xce00, "Samsung" },
	{ 0xda00, "Winbond" },
	{ 0xe000, "LG Semi" },
	{ 0x3400, "AgigA" },
	{ 0x7a01, "Apacer" },
	{ 0x4f01, "Transcend" },
	{ 0x9801, "Kingston" },
	{ 0xba01, "PNY" },
	{ 0x9401, "Smart"},
	{ 0x4001, "Viking" },
	{ 0x9e02, "Corsair" },
	{ 0xfe02, "Elpida" },
	{ 0x0b03, "Nanya" },
	{ 0x2503, "Kingmax" },
	{ 0x9403, "Mushkin" },
	{ 0xcb04, "A-DATA" },
	{ 0xef04, "Team Group" },
	{ 0xb004, "OCZ" },
	{ 0xcd04, "G Skill" },
	{ 0x5105, "Qimonda" },
	{ 0x5705, "AENEON" },
	{ 0x0205, "Patriot" },
	{ 0x9b05, "Crucial" },
	{ 0xf705, "Avant" },
	{ 0x1606, "Avexir" },
	{ 0x3406, "Super Talent" },
	{ 0x6d06, "V_Color" },
	{ 0xd306, "Silicon Power" },
	{ 0xf106, "InnoDisk" },
	{ 0x7007, "Panram" },
	{ 0xf707, "ACPI" },
	{ 0xff00, "Undefined" }	
};


typedef union {
  struct {
    UINT8 Page          : 3; // Bits[2:0] - Page to be selected
    UINT8 I2cLegacyMode : 1; // Bits[3]   - I2C Legacy Mode Addressing
    UINT8 Reserved      : 4; // Bits[7:4] - Reserved
  } Bits;
  UINT8 Data;
} SPD_DDR5_MR11_STRUCT;

typedef union {
  struct {
    UINT8 Address : 7; // Bits[6:0] - Address bits
    UINT8 MemReg  : 1; // Bits[7]   - 1 for NVM location, 0 for internal register
  } Bits;
  UINT8 Data;
} SPD_DDR5_ADDRESS_FIRST_BYTE_STRUCT;

typedef struct {
  INT32 TckValue;
  UINT16 DdrFreqValue;
} TCK_TO_DDR_FREQ_STRUCT;


SPD_DATA gSpdData[MAX_SOCKET][MAX_CH][MAX_DIMM];
EFI_SMBIOS_PROTOCOL *gSmbios = NULL;
USRA_PROTOCOL *mUsra = NULL;

//
//  Name : Xtoi
//  receives an string representing an hex number (without the leading 0x)
//  and returns its value as integer
// 
size_t Xtoi(const char* hexstr)
{
	size_t r = 0;
	size_t i;
	size_t l = strlen(hexstr);
	
	for (i = 0; i < l; i++)
	{
			switch(hexstr[i])
			{
					case '0':
					case '1':
					case '2':
					case '3':
					case '4':
					case '5':
					case '6':
					case '7':
					case '8':
					case '9':                       
							r |= ((size_t)(hexstr[i] - '0')) << ((l - i - 1) * 4);
							break;
					case 'a':
					case 'b':
					case 'c':
					case 'd':
					case 'e':
					case 'f':
							r |= ((size_t)(hexstr[i] - 'a' + 10)) << ((l - i - 1) * 4);
							break;
					case 'A':
					case 'B':
					case 'C':
					case 'D':
					case 'E':
					case 'F':
							r |= ((size_t)(hexstr[i] - 'A' + 10)) << ((l - i - 1) * 4);
							break;
					default:
							i = l;  // force loop exit
			}
	}
	
	return r;
}

UINT32
GetInstanceOffset (
  IN UINT16 Instance,
  IN UINT32 RegOffset
  )
{
  UINT32 InstanceOffset = 0;

  if (Instance >= MAX_SMB_INSTANCE) {
    printf ("Invalid Instance %d\n", Instance);
    return InstanceOffset;
  }

  // Sanity check for Valid Incoming Register Offset is not Instance 1
  if (RegOffset >= SPR_I3C1_REG_OFFSET0) {
    printf ("Invalid Register Offset\n");
    return InstanceOffset;
  }

  //Calculate I3C1 register offset
  InstanceOffset = RegOffset + (Instance * SPR_SMB_OFFSET_DELTA);

  return InstanceOffset;
}

USRA_PROTOCOL *
EFIAPI
GetUsraProtocol (
	VOID
)
{
	EFI_STATUS	Status;
	USRA_PROTOCOL	*Usra = NULL;
	//
	// USRA protocol need to be installed before the module access USRA.
	//
	EFI_GUID DxeUsraProtocolGuid = { 0xfd480a76, 0xb134, 0x4ef7, { 0xad, 0xfe, 0xb0, 0xe0, 0x54, 0x63, 0x98, 0x07 }};
	Status = gBS->LocateProtocol (&DxeUsraProtocolGuid, NULL, (VOID **)&Usra);

	if (Status != EFI_SUCCESS) {
		Print(L"Locate usra protocol fail, Status = %r\n", Status);
	return NULL;
	}

	return Usra;
}

RETURN_STATUS
EFIAPI
RegisterRead (
	IN USRA_ADDRESS             *Address,
	OUT VOID                     *Buffer
)
{
	if (mUsra == NULL) {
	mUsra = GetUsraProtocol ();
	if (mUsra == NULL) {
		return RETURN_DEVICE_ERROR;
	}
	}

	return mUsra->RegRead (Address, Buffer);
}

RETURN_STATUS
EFIAPI
RegisterWrite (
	IN USRA_ADDRESS	*Address,
	IN VOID	*Buffer
)
{
	if (mUsra == NULL) {
	mUsra = GetUsraProtocol ();
	if (mUsra == NULL) {
		return RETURN_DEVICE_ERROR;
	}
	}
	// printf("RegisterWrite = %x\n", *Address);
	return mUsra->RegWrite (Address, Buffer);
}


// [Gbt_Jim_Y0008] +
//
// Ported from EGS RC `Intel\CpRcPkg\Library\DxeUsraLib\UsraLibCommon.c`.
//

/**
  This API get the flat address from the given USRA Address.

  @param[in] Address              A pointer of the address of the USRA Address Structure to be read out

  @retval                         The flat address
**/
UINTN
EFIAPI
GetRegisterAddress (
  IN USRA_ADDRESS           *Address
  )
{
  if (mUsra == NULL) {
    mUsra = GetUsraProtocol ();
    if (mUsra == NULL) {
      //ASSERT (FALSE);	// [Gbt_Jim_Y0008] macro ASSERT is not defined, comment out.
      return RETURN_DEVICE_ERROR;
    }
  }

  return mUsra->GetRegAddr (Address);
}
// [Gbt_Jim_Y0008] -


UINT32
EFIAPI
UsraCsrRead (
	IN UINT8	SocketId,
	IN UINT8	BoxInst,
	IN UINT32	CsrOffset
)
{
	USRA_ADDRESS	RegisterId;
	UINT32	Data32 = 0;

	USRA_CSR_OFFSET_ADDRESS (RegisterId, SocketId, BoxInst, CsrOffset);
	RegisterRead (&RegisterId, &Data32);

	return Data32;
}

VOID
EFIAPI
UsraCsrWrite (
	IN	UINT8	SocketId,
	IN	UINT8	BoxInst,
	IN	UINT32	CsrOffset,
	IN	OUT UINT32	Data32
)
{
	USRA_ADDRESS	RegisterId;

	USRA_CSR_OFFSET_ADDRESS (RegisterId, SocketId, BoxInst, CsrOffset);

	RegisterWrite (&RegisterId, &Data32);
}

EFI_STATUS
EFIAPI
WaitForHostNotBusyTarget (
	IN UINT8	Socket,
	IN UINT8	Instance,
	IN UINT32	I3cStatusReg
)
{
	UINT32	Timeout;
	INTR_STATUS_SB_I3C0_STRUCT	I3cStatus;
	EFI_STATUS	Status = EFI_DEVICE_ERROR;

	Timeout = 100000;

	//
	// Wait for there is space in the command queue
	//
	do {
	I3cStatus.Data = UsraCsrRead (Socket, Instance, I3cStatusReg);
	if (I3cStatus.Bits.cmd_queue_ready_stat == 1) {
		Status = EFI_SUCCESS;
		break;
	}

	gBS->Stall(1);
	Timeout--;

	// Wait for timeout
	} while (Timeout > 0);

	return Status;
}


EFI_STATUS
ResumeProcSmb (
	IN UINT8	Socket,
	IN UINT16	SmbInstance
)
{
	EFI_STATUS	Status;
	UINT8	Instance;
	UINT32	Timeout;
	UINT32	I3cDevCtrlReg;
	UINT32	I3cResetReg;
	UINT32	I3cStatusReg;
	DEVICE_CONTROL_SB_I3C0_STRUCT	I3cDevCtrl;
	RESET_CTRL_SB_I3C0_STRUCT	ResetCtrl;
	INTR_STATUS_SB_I3C0_STRUCT	I3cStatus;

	Status = EFI_SUCCESS;
	Instance = (UINT8) SmbInstance;

	I3cDevCtrlReg = GetInstanceOffset (Instance, DEVICE_CONTROL_SB_I3C0_REG);
	I3cResetReg = GetInstanceOffset (Instance, RESET_CTRL_SB_I3C0_REG);
	I3cStatusReg = GetInstanceOffset (Instance, INTR_STATUS_SB_I3C0_REG);

	// reset queue and fifo
	ResetCtrl.Data = UsraCsrRead (Socket, Instance, I3cResetReg);
	ResetCtrl.Bits.cmd_queue_rst = I3C_ENABLE;
	ResetCtrl.Bits.resp_queue_rst = I3C_ENABLE;
	ResetCtrl.Bits.tx_fifo_rst = I3C_ENABLE;
	ResetCtrl.Bits.rx_fifo_rst = I3C_ENABLE;
	ResetCtrl.Bits.ibi_queue_rst = I3C_ENABLE;
	UsraCsrWrite (Socket, Instance, I3cResetReg, ResetCtrl.Data);
	//
	// Wait for queue and fifo reset completion.
	//
	Timeout = 100000;

	do {
		ResetCtrl.Data = UsraCsrRead (Socket, Instance, I3cResetReg);
		gBS->Stall(1);
		Timeout--;

		if (Timeout <= 0) {
			Status = EFI_TIMEOUT;
			break;
		}

	} while ((ResetCtrl.Bits.cmd_queue_rst == 1) || (ResetCtrl.Bits.resp_queue_rst == 1) || (ResetCtrl.Bits.tx_fifo_rst == 1) ||
			(ResetCtrl.Bits.rx_fifo_rst == 1) || (ResetCtrl.Bits.ibi_queue_rst == 1));
	//
	// Check error status
	//
	I3cStatus.Data = UsraCsrRead (Socket, Instance, I3cStatusReg);

	if (I3cStatus.Bits.transfer_err_stat == 1) {
		// write 1 to clear
		UsraCsrWrite (Socket, Instance, I3cStatusReg, I3cStatus.Data);
	}
	//
	// Resume I3C
	//
	I3cDevCtrl.Data = UsraCsrRead (Socket, Instance, I3cDevCtrlReg);
	I3cDevCtrl.Bits.resume = 1;
	UsraCsrWrite (Socket, Instance, I3cDevCtrlReg, I3cDevCtrl.Data);

	return Status;
} // ResumeProcSmb

EFI_STATUS
SmbReadCommon (
	IN UINT8	Socket,
	IN SMB_DEVICE_STRUCT	Dev,
	IN UINT8	ByteOffset,
	OUT volatile UINT8	*Data
)
{
	EFI_STATUS                              Status;
	UINT32                                  I3cStatusReg;
	UINT32                                  I3cCmdReg;
	UINT32                                  I3cDataReg;
	UINT32                                  I3cRespReg;
	UINT32                                  Timeout;
	RESPONSE_QUEUE_PORT_SB_I3C0_STRUCT      I3cResp;
	UINT8                                   TransactionID;
	UINT8                                   Instance;
	UINT8                                   SubOffsetLen;
	UINT32                                  SubOffset;
	COMMAND_QUEUE_PORT_SB_I3C0_STRUCT       CmdPort;
	COMBO_TRANSFER_COMMAND_LOW_WITHOUT_DAT  ComboCommandLow;
	COMBO_TRANSFER_COMMAND_HIGH_WITHOUT_DAT ComboCommandHigh;
	// Same address with RX_DATA_PORT and TX_DATA_PORT, single bi-direction design
	volatile ALIAS_DATA_PORT_SB_I3C0_STRUCT DataPort;
	INTR_STATUS_SB_I3C0_STRUCT              I3cStatus;
	UINT8                                   I2cOrI3c;

	Status = EFI_SUCCESS;
	TransactionID = TidRead;
	Instance = (UINT8) Dev.address.SmbInstance;

	I3cCmdReg = GetInstanceOffset (Instance, COMMAND_QUEUE_PORT_SB_I3C0_REG);
	I3cStatusReg = GetInstanceOffset (Instance, INTR_STATUS_SB_I3C0_REG);
	I3cDataReg = GetInstanceOffset (Instance, ALIAS_DATA_PORT_SB_I3C0_REG);  // Use DATA_PORT for reading and writing
	I3cRespReg = GetInstanceOffset (Instance, RESPONSE_QUEUE_PORT_SB_I3C0_REG);
	I2cOrI3c = 0; //I3Cs
	// Use 2 Byte addressing when accessing the DDR5 SPD data in I3C mode
	// or accessing DDRT Temperature Sensor
	if (( (I2cOrI3c == 0) && (Dev.address.deviceType == DTI_EEPROM)) ||
		((Dev.address.deviceType == DTI_RCD_FMC) && (Dev.compId == MTS))) {
		SubOffsetLen = SUBOFFSET_16_BIT;
		SubOffset = (Dev.SpdPage | (ByteOffset << 8));  // The low byte should follow the definition of SPD_DDR5_ADDRESS_SECOND_BYTE_STRUCT
	} else {
		SubOffsetLen = SUBOFFSET_8_BIT;
		SubOffset = ByteOffset;
	}
	//
	// Form read command
	//
	ComboCommandLow.Data = 0x0;
	ComboCommandLow.Bits.com_attr = I3C_COM_ATTR_WWR_COMBO_XFER;  // 0x3: WWR_COMBO_XFER: Write+Write/Read Combo Transfer;
	ComboCommandLow.Bits.tid = TransactionID; // Transaction ID field is used as identification tag for the command.
	ComboCommandLow.Bits.i2cni3c = I2cOrI3c; // 0x0: I3C device 0x1: I2C device
	ComboCommandLow.Bits.slave_address = (UINT32) ((Dev.address.deviceType << I3C_STRAP_ADDRESS_OFFSET) | Dev.address.strapAddress);
	//Indicates 8-or 16-bit sub-offset Values:0x0: 8_BIT_SUBOFFSET: 8 bit suboffset; 0x1: suboffset_16_bit:16 bit suboffset
	ComboCommandLow.Bits.suboffset_16_bit = SubOffsetLen;
	ComboCommandLow.Bits.mode_speed = I3cSdr0I2cFm;
	ComboCommandLow.Bits.rnw = RNW_READ; // 0x1: READ: Read transfer
	ComboCommandLow.Bits.roc = ROC_REQUIRED; // 0x1: REQUIRED: Response Status is required
	ComboCommandLow.Bits.toc = TOC_STOP; // 0x1: STOP: Stop (P) is issued at end of the transfer

	ComboCommandHigh.Data = 0x0;
	ComboCommandHigh.Bits.offset_suboffset = SubOffset;

	if (Dev.compId == MTS) {
		if (Dev.address.deviceType == DTI_RCD_FMC) {
		ComboCommandHigh.Bits.data_length = 0x4;  // 4 bytes read data length for SMBUS remote packet
		}
		else {
		ComboCommandHigh.Bits.data_length = 0x2;
		}
	} else {
		ComboCommandHigh.Bits.data_length = 1;  // 1 byte
	}

	CmdPort.Data = 0x0;
	CmdPort.Bits.command = ComboCommandLow.Data;
	//
	// Send command can check the rx_thld_stat to see if there is space in rx_fifo
	//
	// Low 32 bits
	Status = WaitForHostNotBusyTarget (Socket, Instance, I3cStatusReg);

	if (EFI_ERROR (Status)) {
		// printf("WaitForHostNotBusTarget\n");
		return EFI_NOT_FOUND;
	}

	UsraCsrWrite (Socket, Instance, I3cCmdReg, CmdPort.Bits.command);
	// High 32 bits
	// wait for there is space in the command queue
	Status = WaitForHostNotBusyTarget (Socket, Instance, I3cStatusReg);

	if (EFI_ERROR (Status)) {
		printf("WaitForHostNotBusTarget\n");
		return Status;
	}
	
	// High 32 bits
	CmdPort.Bits.command = ComboCommandHigh.Data;
	
	UsraCsrWrite (Socket, Instance, I3cCmdReg, CmdPort.Bits.command);
	//
	// Check Transfer Complete
	//
	Timeout = 100000;

	do {
		I3cStatus.Data = UsraCsrRead (Socket, Instance, I3cStatusReg);

		gBS->Stall(1); // Delay 10ms
		Timeout--;

		if (Timeout <= 0) {
		printf("EFI_TIMEOUT\n");
		Status = EFI_TIMEOUT;
		break;
		}
	}while((I3cStatus.Bits.resp_ready_stat == 0) && (I3cStatus.Bits.transfer_err_stat == 0));
	//
	// Wait for the read data
	//
	Timeout = 100000;

	do {
		I3cStatus.Data = UsraCsrRead (Socket, Instance, I3cStatusReg);

		gBS->Stall(1);
		Timeout--;

		if (Timeout <= 0) {
		Status = EFI_TIMEOUT;
		break;
		}
	} while ((I3cStatus.Bits.rx_thld_stat == 0) && (I3cStatus.Bits.transfer_err_stat == 0));
	//
	// If read data is valid
	//
	if ((I3cStatus.Bits.rx_thld_stat == 1) && (I3cStatus.Bits.transfer_err_stat == 0)) {
		DataPort.Data = UsraCsrRead (Socket, Instance, I3cDataReg);

		if (Dev.compId == MTS) {
		*Data = (UINT8) DataPort.Bits.data_port;  //lsb
		*(Data + 1) = (UINT8) (DataPort.Bits.data_port >> 8); //msb
		} else {
		*Data = (UINT8) DataPort.Bits.data_port;
		}
	} else {
		Status = EFI_DEVICE_ERROR;
	}
	//
	// Check response status
	//
	I3cResp.Data = UsraCsrRead (Socket, Instance, I3cRespReg);

	if ((I3cResp.Bits.tid != TransactionID) || I3cResp.Bits.err_status == 1) {
		Status = EFI_DEVICE_ERROR;
		printf("Final\n");
	}

	return Status;
} //SmbReadCommon

EFI_STATUS
EFIAPI
GetSmbAddress (
	IN UINT8               Socket,
	IN UINT8               Channel,
	IN UINT8               Dimm,
	OUT SMB_DEVICE_STRUCT  *Dev
)
{
	Dev->mcId = Channel / MAX_MC_CH;
	// For 10nm each socket has its own SMBUS controller
	Dev->address.SmbSocket = Socket;
	//Calculate I3C Instance from Memory Controller Id
	Dev->address.SmbInstance = Dev->mcId / SPR_I3C_MC_NUMBER;
	Dev->address.strapAddress = Dimm + ((Channel % (I3C_MAX_DIMM_NUM / MAX_DIMM)) * MAX_DIMM);

	return EFI_SUCCESS;
}

VOID
SelectPageAndOffsetDdr5 (
	IN UINT16             ByteOffset,
	IN SMB_DEVICE_STRUCT  *SpdDev,
	OUT UINT8             *SmbOffset
)
{
	SMB_DEVICE_STRUCT                   SpdPageDev;
	UINT16                              PageOffset;
	SPD_DDR5_MR11_STRUCT                Mr11Data;
	SPD_DDR5_ADDRESS_FIRST_BYTE_STRUCT  SmbAddressData;
	UINT8                               SpdPage;

	PageOffset = 0;
	SpdPageDev = *SpdDev;
	Mr11Data.Data = 0;
	SmbAddressData.Data = 0;

	// DDR5 pages are broken up into 128 bit chunks
	SpdPage = (UINT8) (ByteOffset / SPD_DDR5_PAGE_SIZE);
	PageOffset = SPD_DDR5_PAGE_SIZE * SpdPage;
	SpdDev->SpdPage = SpdPage;
	SmbAddressData.Bits.MemReg = 1;
	SmbAddressData.Bits.Address = (UINT8) (ByteOffset - PageOffset);

	*SmbOffset = SmbAddressData.Data;

	return;
}

EFI_STATUS
EFIAPI
SpdReadByte (
	IN UINT8      Socket,
	IN UINT8      Channel,
	IN UINT8      Dimm,
	IN UINT16     ByteOffset,
	OUT UINT8     *Data
){
	SMB_DEVICE_STRUCT	SpdDev;
	EFI_STATUS	Status = EFI_SUCCESS;
	UINT8	SmbOffset = 0;
	
	SpdDev.compId = SPD;
	SpdDev.address.controller = PLATFORM_SMBUS_CONTROLLER_PROCESSOR;
	SpdDev.address.deviceType = DTI_EEPROM;

	GetSmbAddress(Socket, Channel, Dimm, &SpdDev);
	SelectPageAndOffsetDdr5 (ByteOffset, &SpdDev, &SmbOffset);
	Status = SmbReadCommon (Socket, SpdDev, SmbOffset, Data);
	if(EFI_ERROR (Status)){
		// Resume to Retry if error detected
		ResumeProcSmb (Socket, SpdDev.address.SmbInstance);
		Status = SmbReadCommon (Socket, SpdDev, SmbOffset, Data);
		// Resume if Retry failed
		if (EFI_ERROR (Status)) {
			ResumeProcSmb (Socket, SpdDev.address.SmbInstance);
		}
	}
	return Status;
}

EFI_STATUS
ReadSPD(
	IN UINT8	Socket,
	IN UINT8	Channel,
	IN UINT8	Dimm
)
{
	EFI_STATUS Status = EFI_SUCCESS;
	UINT16	Offset = 0;
	UINT16	NumberOfByte = 1024;
	// Fill out relevant data for a SPD SMbus transaction
	// Read Number of byte in spd device reg
	for(Offset = 0; Offset < NumberOfByte; Offset++){
		Status = SpdReadByte(Socket, Channel, Dimm, Offset, &gSpdData[Socket][Channel][Dimm].SpdData[Offset]);
		if(EFI_ERROR (Status)){
			gSpdData[Socket][Channel][Dimm].Spd.DeviceExist = FALSE;
			return Status;
		}
	}

	return EFI_SUCCESS;
}


void
ReadSPDFromChip()
{
	UINT8	Socket, Channel, Dimm;
	UINT8	DimmCount;
	EFI_STATUS Status = EFI_SUCCESS;

	DimmCount = 0;
	for(Socket = 0; Socket < MAX_SOCKET; Socket++){
		for(Channel = 0; Channel < MAX_CH; Channel++){
			for(Dimm = 0; Dimm < MAX_DIMM; Dimm++){
				gSpdData[Socket][Channel][Dimm].Spd.DimmName = DimmList[DimmCount];
				DimmCount ++;
				Status = ReadSPD(Socket, Channel, Dimm);
				if(!EFI_ERROR (Status)){
					gSpdData[Socket][Channel][Dimm].Spd.DeviceExist = TRUE;
				}else{
					gSpdData[Socket][Channel][Dimm].Spd.DeviceExist = FALSE;
				}
			}
		}
	}
}

void
DumpSpdCfg(
	void
)
{
	UINTN Socket, Channel, Dimm;
	UINT16 count = 0;
	UINT16	Index = 0;

	for( Socket = 0; Socket < MAX_SOCKET; Socket++ ){
		for( Channel = 0; Channel < MAX_CH; Channel++ ){
			for( Dimm = 0; Dimm < MAX_DIMM; Dimm++ ){
				if( gSpdData[Socket][Channel][Dimm].Spd.DeviceExist == TRUE ){
					printf("\n");
					printf("%s\n", gSpdData[Socket][Channel][Dimm].Spd.DimmName);
					printf("        00 01 02 03 04 05 06 07 08 09 0A 0B 0C 0D 0E 0F\n");
					printf("========================================================\n");
					printf("0000 || ");

					for( Index = 0; Index < 1024; Index++ ){
						count++;
						printf("%2.2X ",  gSpdData[Socket][Channel][Dimm].SpdData[Index]);
						if(count % 16 == 0)
						{
							printf("\n");
							if( Index + 1 != 1024){
								printf("%4.4X || ", Index + 1);
							}
						}
					}
				}
			}//Dimm
		}//Channel
	}//Socket

	return;
}

void
CalculationSize(
	IN UINT8	Socket,
	IN UINT8	Channel,
	IN UINT8	Dimm
){
	FIRST_SDRAM_DENSITY_AND_PACKAGE_STRUCT	FirstDensityPackageStruct;
	UINT8	SdramDestinyPerDie;
	UINT8	SdramDestinyPerDieTable[] = {0, 4, 8, 12, 16, 24, 32, 48, 64};
	UINT8	DiePerPackage;
	UINT8	SDiePerPackageTable[] = {1, 2, 2, 4, 8, 16};
	FIRST_SDRAM_I_O_WIDTH_STRUCT	FirstIOWidthStuct;
	UINT8	SdramIOWidth;
	UINT8	SdramIOWidthTable[] = {4, 8, 16, 32};
	COMMON_MODULE_ORGANIZATION_STRUCT	ModuleOrgReg;
	UINT8	PackageRankPerChannel;
	UINT8	PackageRankPerChannelTable[] = {1, 2, 3, 4, 5, 6, 7, 8};
	BOOLEAN	RankMixIndicator = FALSE;
	COMMON_MEMORY_CHANNEL_BUS_WIDTH_STRUCT	ChannelBusWidthReg;
	UINT8	PrimaryBusWidthPerChannel;
	UINT8	PrimaryBusWidthPerChannelTable[] = {8, 16, 32, 64};
	UINT8	NumberOfChannelsPerDimm;
	UINT8	NumberOfChannelsPerDimmTable[] = {1, 2};
	UINT16	RankSize;
	UINT16	Capacity;

	FirstDensityPackageStruct.Data = gSpdData[Socket][Channel][Dimm].SpdData[SPD_FIRST_SDRAM_DENSITY_AND_PACKAGE_REG];
	FirstIOWidthStuct.Data = gSpdData[Socket][Channel][Dimm].SpdData[SPD_FIRST_SDRAM_I_O_WIDTH_REG];
	ModuleOrgReg.Data = gSpdData[Socket][Channel][Dimm].SpdData[SPD_COMMON_MODULE_ORGANIZATION_REG];
	ChannelBusWidthReg.Data = gSpdData[Socket][Channel][Dimm].SpdData[SPD_COMMON_MEMORY_CHANNEL_BUS_WIDTH_REG];

	SdramDestinyPerDie = SdramDestinyPerDieTable[FirstDensityPackageStruct.Bits.sdram_density_per_die];
	DiePerPackage = SDiePerPackageTable[FirstDensityPackageStruct.Bits.die_per_package];

	SdramIOWidth = SdramIOWidthTable[FirstIOWidthStuct.Bits.sdram_i_o_width];

	PackageRankPerChannel = PackageRankPerChannelTable[ModuleOrgReg.Bits.number_of_package_ranks_per_channel];
	RankMixIndicator = ModuleOrgReg.Bits.rank_mix;

	PrimaryBusWidthPerChannel = PrimaryBusWidthPerChannelTable[ChannelBusWidthReg.Bits.primary_bus_width_per_channel_in_bits];
	NumberOfChannelsPerDimm = NumberOfChannelsPerDimmTable[ChannelBusWidthReg.Bits.number_of_channels_per_dimm];

	//Caculate capacity
	RankSize = PrimaryBusWidthPerChannel / SdramIOWidth * DiePerPackage * SdramDestinyPerDie / 8;
	Capacity = NumberOfChannelsPerDimm * RankSize * PackageRankPerChannel;

	gSpdData[Socket][Channel][Dimm].Spd.Size.Capacity = Capacity;
	gSpdData[Socket][Channel][Dimm].Spd.Size.Unit = "GB";

}

void
SpdGetSerialNumber(
	IN UINT8	Socket,
	IN UINT8	Channel,
	IN UINT8	Dimm
){
	UINT8	Index;

	for (Index = 0; Index < SPD_MODULE_SERIAL; Index++) {
		gSpdData[Socket][Channel][Dimm].Spd.SerialNumber[Index] = gSpdData[Socket][Channel][Dimm].SpdData[SPD_MODULE_SERIAL_NUMBER_0_REG + Index];
	}
}

void
SpdGetModuleManufacturerId (
	IN UINT8	Socket,
	IN UINT8	Channel,
	IN UINT8	Dimm
)
{
	MODULE_MANUFACTURER_ID_CODE_0_STRUCT ManufactureId0Reg;
	MODULE_MANUFACTURER_ID_CODE_1_STRUCT ManufactureId1Reg;
	UINT16	ManufacturerId = 0;
	UINT8 Index;

	ManufactureId0Reg.Data = gSpdData[Socket][Channel][Dimm].SpdData[SPD_MODULE_MANUFACTURER_ID_CODE_0_REG];
	ManufactureId1Reg.Data = gSpdData[Socket][Channel][Dimm].SpdData[SPD_MODULE_MANUFACTURER_ID_CODE_1_REG];

	ManufacturerId = (UINT16) (ManufactureId1Reg.Bits.last_non_zero_byte_module_manufacturer << 8)
						| (UINT16) (ManufactureId0Reg.Bits.number_of_continuation_codes_module_manufacturer);
	for(Index = 0; Index < sizeof(MemoryModuleManufacturerList)/sizeof(JEDEC_MF_ID); Index++){
		if(ManufacturerId == MemoryModuleManufacturerList[Index].VendorId){
			gSpdData[Socket][Channel][Dimm].Spd.Manufacturer = MemoryModuleManufacturerList[Index].ManufacturerString;
			break;
		}
	}
}

//
// Bytes 329~348 (0x149~15C): Module Part Number
//
void
SpdGetPartNumber(
	IN UINT8	Socket,
	IN UINT8	Channel,
	IN UINT8	Dimm
)
{
	UINT8 i;
	for(i = 0; i < SPD_MODULE_PART_DDR5; i++){
		gSpdData[Socket][Channel][Dimm].Spd.PartNumber[i] = gSpdData[Socket][Channel][Dimm].SpdData[SPD_MODULE_PART_NUMBER_0_REG + i];
	}
}

void
SpdGetSpeed(
	IN UINT8	Socket,
	IN UINT8	Channel,
	IN UINT8	Dimm
)
{
	UINT8	Data;
	INT32	CommonTck;
	UINT8	Index;
	TCK_TO_DDR_FREQ_STRUCT TckToDdrFreq[] = {
		{DDR_8400_TCK_MIN, 8400},
		{DDR_8000_TCK_MIN, 8000},
		{DDR_7600_TCK_MIN, 7600},
		{DDR_7200_TCK_MIN, 7200},
		{DDR_6800_TCK_MIN, 6800},
		{DDR_6400_TCK_MIN, 6400},
		{DDR_6000_TCK_MIN, 6000},
		{DDR_5600_TCK_MIN, 5600},
		{DDR_5200_TCK_MIN, 5200},
		{DDR_4800_TCK_MIN, 4800},
		{DDR_4400_TCK_MIN, 4400},
	};

	Data = gSpdData[Socket][Channel][Dimm].SpdData[SPD_SDRAM_MINIMUM_CYCLE_TIME_TCKAVGMIN_LSB_REG];
	CommonTck = Data;
	
	Data = gSpdData[Socket][Channel][Dimm].SpdData[SPD_SDRAM_MINIMUM_CYCLE_TIME_TCKAVGMIN_MSB_REG];
	CommonTck |= Data << 8;

	for (Index = 0; Index < (sizeof (TckToDdrFreq) / sizeof (TckToDdrFreq[0])); Index++) {
		if (CommonTck <= TckToDdrFreq[Index].TckValue) {
		gSpdData[Socket][Channel][Dimm].Spd.Speed = TckToDdrFreq[Index].DdrFreqValue;
		break;
		}
	}

}

EFI_STATUS
SmbiosGetStringByIndex(
	IN    CHAR8   *OptionalStrStart,
	IN    UINT8   Index, 
	OUT   UINT8  **String
)
{
	UINTN          StrSize;

	if (Index == 0) {
	(*String) = NULL;
	return EFI_NOT_FOUND;
	}
	StrSize = 0;
	do {
	Index--;
	OptionalStrStart += StrSize;
	StrSize           = AsciiStrSize (OptionalStrStart); // size includes null terminator
	// SMBIOS strings are NULL terminated, and end of all strings is indicated with NULL
	// loop until at end of all SMBIOS strings (found NULL terminator at string index past string's NULL), and Index != 0
	} while (OptionalStrStart[StrSize] != 0 && Index != 0);

	if ((Index != 0) || (StrSize == 1)) {
		//
		// Meet the end of strings set but Index is non-zero
		(*String) = NULL;
		return EFI_NOT_FOUND;
	} 
	
	(*String) = (UINT8*)OptionalStrStart;
	return EFI_SUCCESS;
}

void
AnalysisData(
	void
)
{
	UINT8 Socket, Channel, Dimm;
	for(Socket = 0; Socket < MAX_SOCKET; Socket++){
		for(Channel = 0; Channel < MAX_CH; Channel ++){
			for(Dimm = 0; Dimm < MAX_DIMM; Dimm++){
				if(gSpdData[Socket][Channel][Dimm].Spd.DeviceExist == TRUE){
					CalculationSize(Socket, Channel, Dimm);
					SpdGetSpeed(Socket, Channel, Dimm);

					if(gSpdData[Socket][Channel][Dimm].SpdData[SPD_KEY_BYTE_HOST_BUS_COMMAND_PROTOCOL_TYPE_REG] == SPD_TYPE_DDR5)
					{
						gSpdData[Socket][Channel][Dimm].Spd.Type = "DDR5";
						SpdGetModuleManufacturerId(Socket, Channel, Dimm);
						SpdGetSerialNumber(Socket, Channel, Dimm);
						SpdGetPartNumber(Socket, Channel, Dimm);
					}
				}
			}//Dimm
		}//Channel
	}//Socket
}

void
PrintResault(
)
{
	UINT8 Socket, Channel, Dimm;
	UINT8 Index;
	for(Socket = 0; Socket < MAX_SOCKET; Socket++){
		for(Channel = 0; Channel < MAX_CH; Channel ++){
			for(Dimm = 0; Dimm < MAX_DIMM; Dimm++){

				printf("%s : ", gSpdData[Socket][Channel][Dimm].Spd.DimmName);

				if(gSpdData[Socket][Channel][Dimm].Spd.DeviceExist == 1)
				{
					gST->ConOut->SetAttribute(gST->ConOut, EFI_LIGHTGREEN);
					printf(" Installed!!\n");
					gST->ConOut->SetAttribute(gST->ConOut, EFI_WHITE);

					printf("Type = %s\n", gSpdData[Socket][Channel][Dimm].Spd.Type);
					printf("Size = %d %s\n", gSpdData[Socket][Channel][Dimm].Spd.Size.Capacity, gSpdData[Socket][Channel][Dimm].Spd.Size.Unit);
					printf("Speed = %d\n", gSpdData[Socket][Channel][Dimm].Spd.Speed);
					printf("Manufacturer = %s\n", gSpdData[Socket][Channel][Dimm].Spd.Manufacturer);

					printf("SerialNumber = ");
					for(Index = 0; Index < SPD_MODULE_SERIAL; Index++)
						printf("%2.2X", gSpdData[Socket][Channel][Dimm].Spd.SerialNumber[Index]);
					printf("\n");

					printf("PartNumber = ");
					for(Index = 0; Index < SPD_MODULE_PART_DDR5; Index++)
						printf("%c", gSpdData[Socket][Channel][Dimm].Spd.PartNumber[Index]);
					printf("\n");
				}else{
					gST->ConOut->SetAttribute(gST->ConOut, EFI_LIGHTRED);
					printf(" No DIMM!!\n");
					gST->ConOut->SetAttribute(gST->ConOut, EFI_WHITE);
				}
				printf("========================================\n");
			}
		}
	}
}

void
PrintSmbiosResault(
	void
)
{
	UINT8 Socket, Channel, Dimm;
	UINT8 Index;
	for(Socket = 0; Socket < MAX_SOCKET; Socket++){
		for(Channel = 0; Channel < MAX_CH; Channel ++){
			for(Dimm = 0; Dimm < MAX_DIMM; Dimm++){

				printf("%s : ", gSpdData[Socket][Channel][Dimm].Smbios.DimmName);

				if(gSpdData[Socket][Channel][Dimm].Smbios.DeviceExist == 1)
				{
					gST->ConOut->SetAttribute(gST->ConOut, EFI_LIGHTGREEN);
					printf(" Installed!!\n");
					gST->ConOut->SetAttribute(gST->ConOut, EFI_WHITE);

					printf("Type = %s\n", gSpdData[Socket][Channel][Dimm].Smbios.Type);
					printf("Speed = %d\n", gSpdData[Socket][Channel][Dimm].Smbios.Speed);
					printf("Manufacturer = %s\n", gSpdData[Socket][Channel][Dimm].Smbios.Manufacturer);

					printf("SerialNumber = ");
					for(Index = 0; Index < SPD_MODULE_SERIAL; Index++)
						printf("%2.2X", gSpdData[Socket][Channel][Dimm].Smbios.SerialNumber[Index]);
					printf("\n");

					printf("PartNumber = %s\n", gSpdData[Socket][Channel][Dimm].Smbios.PartNumber);
				}else{
					gST->ConOut->SetAttribute(gST->ConOut, EFI_LIGHTRED);
					printf(" No DIMM!!\n");
					gST->ConOut->SetAttribute(gST->ConOut, EFI_WHITE);
				}
				printf("========================================\n");
			}
		}
	}
}

void
JudgeSMBIOSSIZE(
	UINT8	Socket,
	UINT8	Channel,
	UINT8	Dimm,
	SMBIOS_TABLE_TYPE17	*SmbiosStruct
)
{
	UINTN Size = 0;

	Size = SmbiosStruct->Size;
	//
	// If Size >= 32G, value = 0x7FFF.
	// It must to check size in ExtendedSize.
	//
	if(Size == 0x7FFF)
	{
		gSpdData[Socket][Channel][Dimm].Smbios.Size.Unit = "GB";  
		Size = SmbiosStruct->ExtendedSize & 0x7FFFFFFF;  // Bits 31 => Reserved
		Size = Size / 1024;
		gSpdData[Socket][Channel][Dimm].Smbios.Size.Capacity = Size;
		return;
	}
	
		//
		// If Bits 15 = 1, KB units.
		// If Bits 15 = 0, MB units.
		//
	if( (Size & 0x8000) != 0)
		Size /= 1024;

	if(Size >= 1024)
	{
		gSpdData[Socket][Channel][Dimm].Smbios.Size.Unit = "GB";
		Size = Size / 1024;
		gSpdData[Socket][Channel][Dimm].Smbios.Size.Capacity = Size;
		return;
	}
	else
	{
		gSpdData[Socket][Channel][Dimm].Smbios.Size.Unit = "MB";
		gSpdData[Socket][Channel][Dimm].Smbios.Size.Capacity = Size;
		return;
	}
	
}

void
ReadSMBIOS(
	void
){
	EFI_STATUS Status = EFI_SUCCESS;
	SMBIOS_TABLE_TYPE17	*SmbiosType17Record;
	EFI_SMBIOS_HANDLE	SmbiosHandle;
	EFI_SMBIOS_TABLE_HEADER	*SmbiosHeader;
	EFI_SMBIOS_TYPE	SmbiosType17;
	UINT8	Socket, Channel, Dimm;
	UINTN	SerialNumber;
	UINT8	i;
	BOOLEAN SmbiosEndFalg = FALSE;
	UINT8	*StringStart;

	Status = gBS->LocateProtocol (&gEfiSmbiosProtocolGuid,
									NULL,
									(VOID **)&gSmbios );
	if (EFI_ERROR(Status)){
		printf("Locate Protocol fail\n");
		return;
	}

	SmbiosType17 = EFI_SMBIOS_TYPE_MEMORY_DEVICE;
	SmbiosHandle= SMBIOS_HANDLE_PI_RESERVED;

	for(Socket = 0; Socket < MAX_SOCKET; Socket++){
		for(Channel = 0; Channel < MAX_CH; Channel ++){
			for(Dimm = 0; Dimm < MAX_DIMM; Dimm++){
				Status = gSmbios->GetNext (gSmbios, &SmbiosHandle, &SmbiosType17, &SmbiosHeader, NULL);
				if(EFI_ERROR (Status) || SmbiosHandle == SMBIOS_HANDLE_PI_RESERVED || SmbiosEndFalg){
					gSpdData[Socket][Channel][Dimm].Smbios.DeviceExist = FALSE;
					SmbiosEndFalg = TRUE;
					gSpdData[Socket][Channel][Dimm].Smbios.DeviceExist = FALSE;
					continue;
				}
				
				SmbiosType17Record = (SMBIOS_TABLE_TYPE17*)SmbiosHeader;

				Status = SmbiosGetStringByIndex (
							(CHAR8*)((UINT8*)SmbiosType17Record + SmbiosType17Record->Hdr.Length), 
							SmbiosType17Record->DeviceLocator, 
							&StringStart );
				if(!EFI_ERROR (Status)){
					gSpdData[Socket][Channel][Dimm].Smbios.DimmName = StringStart;
				}

				if(SmbiosType17Record->Size == 0){
					gSpdData[Socket][Channel][Dimm].Smbios.DeviceExist = FALSE;
					continue;
				}

				gSpdData[Socket][Channel][Dimm].Smbios.DeviceExist = TRUE;

				Status = SmbiosGetStringByIndex (
							(CHAR8*)((UINT8*)SmbiosType17Record + SmbiosType17Record->Hdr.Length), 
							SmbiosType17Record->Manufacturer, 
							&StringStart );
				if(!EFI_ERROR (Status)){
					gSpdData[Socket][Channel][Dimm].Smbios.Manufacturer = StringStart;
				}

				Status = SmbiosGetStringByIndex (
							(CHAR8*)((UINT8*)SmbiosType17Record + SmbiosType17Record->Hdr.Length), 
							SmbiosType17Record->PartNumber, 
							&StringStart );

				if(!EFI_ERROR (Status)){
					for(i =0; i < SPD_MODULE_PART_DDR5; i++){
						if(i < strlen(StringStart)){
							gSpdData[Socket][Channel][Dimm].Smbios.PartNumber[i] = StringStart[i];
						}else{
							gSpdData[Socket][Channel][Dimm].Smbios.PartNumber[i] = 0;
						}
					}
				}

				Status = SmbiosGetStringByIndex (
							(CHAR8*)((UINT8*)SmbiosType17Record + SmbiosType17Record->Hdr.Length), 
							SmbiosType17Record->SerialNumber, 
							&StringStart );
				if(!EFI_ERROR (Status)){
					SerialNumber = Xtoi(StringStart);
					for(i = 0; i < SPD_MODULE_SERIAL; i++){
						gSpdData[Socket][Channel][Dimm].Smbios.SerialNumber[i] = (SerialNumber >> (SPD_MODULE_SERIAL - i - 1) * 8) & 0xFF;
					}
				}

				gSpdData[Socket][Channel][Dimm].Smbios.Type = "DDR5";
				gSpdData[Socket][Channel][Dimm].Smbios.Speed = SmbiosType17Record->Speed;
				JudgeSMBIOSSIZE(Socket, Channel, Dimm, SmbiosType17Record);
			}//Dimm
		}//Channel
	}//Socket
}

EFI_STATUS
CmpSPD(
	void
)
{
	UINTN Socket, Channel, Dimm;
	EFI_STATUS	Status = EFI_SUCCESS;
	UINT8 k;
	UINT8 dump;

	for( Socket = 0; Socket < MAX_SOCKET; Socket++ ){
		for( Channel = 0; Channel < MAX_CH; Channel++ ){
			for( Dimm = 0; Dimm < MAX_DIMM; Dimm++ ){
				dump = 0;
				if(gSpdData[Socket][Channel][Dimm].Spd.DeviceExist == 1)
				{
					if(strcmp(gSpdData[Socket][Channel][Dimm].Spd.DimmName, gSpdData[Socket][Channel][Dimm].Smbios.DimmName) == 0)
					{
						printf("                             -- %s --                          => match\n", gSpdData[Socket][Channel][Dimm].Spd.DimmName);
						printf("               Data from SPD                Data from SMBIOS table\n");

						printf("Type              %-29s%-23s", gSpdData[Socket][Channel][Dimm].Spd.Type, gSpdData[Socket][Channel][Dimm].Smbios.Type);
						if(strcmp(gSpdData[Socket][Channel][Dimm].Spd.Type, gSpdData[Socket][Channel][Dimm].Smbios.Type) == 0)
							printf(" => PASS\n");
						else
						{
							printf(" => FAIL\n");
							Status = EFI_DEVICE_ERROR;
						}

						printf("Size              %-4d%-25s%-4d%-19s", gSpdData[Socket][Channel][Dimm].Spd.Size.Capacity, gSpdData[Socket][Channel][Dimm].Spd.Size.Unit, gSpdData[Socket][Channel][Dimm].Smbios.Size.Capacity, gSpdData[Socket][Channel][Dimm].Smbios.Size.Unit);
						if((gSpdData[Socket][Channel][Dimm].Spd.Size.Capacity == gSpdData[Socket][Channel][Dimm].Smbios.Size.Capacity) && (gSpdData[Socket][Channel][Dimm].Spd.Size.Unit == gSpdData[Socket][Channel][Dimm].Smbios.Size.Unit))
							printf(" => PASS\n");
						else
						{
							printf(" => FAIL\n");
							Status = EFI_DEVICE_ERROR;
						}

						printf("Speed             %-29d%-23d", gSpdData[Socket][Channel][Dimm].Spd.Speed, gSpdData[Socket][Channel][Dimm].Smbios.Speed);
						if(gSpdData[Socket][Channel][Dimm].Spd.Speed == gSpdData[Socket][Channel][Dimm].Smbios.Speed)
							printf(" => PASS\n");
						else
						{
							printf(" => FAIL\n");
							Status = EFI_DEVICE_ERROR;
						}

						printf("Manufacturer      %-29s%-23s", gSpdData[Socket][Channel][Dimm].Spd.Manufacturer, gSpdData[Socket][Channel][Dimm].Smbios.Manufacturer);
						if(strcmp(gSpdData[Socket][Channel][Dimm].Spd.Manufacturer, gSpdData[Socket][Channel][Dimm].Smbios.Manufacturer) == 0)
							printf(" => PASS\n");
						else
						{
							printf(" => FAIL\n");
							Status = EFI_DEVICE_ERROR;
						}

						printf("Serial Number     ");
						for(k = 0; k < SPD_MODULE_SERIAL; k++) printf("%2.2X", gSpdData[Socket][Channel][Dimm].Spd.SerialNumber[k]);
						printf("                     ");
						for(k = 0; k < SPD_MODULE_SERIAL; k++) printf("%2.2X", gSpdData[Socket][Channel][Dimm].Smbios.SerialNumber[k]);
						printf("               ");
						if(*gSpdData[Socket][Channel][Dimm].Spd.SerialNumber == *gSpdData[Socket][Channel][Dimm].Smbios.SerialNumber)
							printf(" => PASS\n");
						else
						{
							printf(" => FAIL\n");
							Status = EFI_DEVICE_ERROR;
						}

						printf("Part Number       ");
						for(k = 0; k < SPD_MODULE_PART_DDR5; k++) printf("%c", gSpdData[Socket][Channel][Dimm].Spd.PartNumber[k]);
						printf("         ");

						for(k = 0; k < SPD_MODULE_PART_DDR5; k++) printf("%c", gSpdData[Socket][Channel][Dimm].Smbios.PartNumber[k]);
						printf("   ");
						if(memcmp(gSpdData[Socket][Channel][Dimm].Spd.PartNumber, gSpdData[Socket][Channel][Dimm].Smbios.PartNumber, SPD_MODULE_PART_DDR5) == 0)
							printf(" => PASS\n");
						else
						{
							printf(" => FAIL\n");
							Status = EFI_DEVICE_ERROR;
						}

						dump = 1;
					}

					if(dump == 0)
					{
						Status = EFI_DEVICE_ERROR;
						printf("%s                                                             => Fail\n", gSpdData[Socket][Channel][Dimm].Spd.DimmName);
						printf("ERROR : Cant find match device in SMBIOS table");
					}
					printf("\n");
				}
			}//Dimm
		}//Channel
	}//Socket

	return Status;
}

EFI_STATUS
Spd_R_Function ()
{

	ReadSPDFromChip();
	AnalysisData();
	PrintResault();

	return EFI_SUCCESS;
}

EFI_STATUS
Spd_D_Function ()
{
	EFI_STATUS	Status = EFI_SUCCESS;
	ReadSPDFromChip();
	DumpSpdCfg();

	return Status;
}

EFI_STATUS
Spd_C_Function()
{
	EFI_STATUS	Status = EFI_SUCCESS;

	ReadSPDFromChip();
	AnalysisData();
	// PrintResault();
	ReadSMBIOS();
	// PrintSmbiosResault();
	Status = CmpSPD();


	return Status;
}