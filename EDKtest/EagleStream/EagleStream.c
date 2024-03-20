#include "EagleStream.h"

UINT8	gDump = 0;
EFI_SMBUS_HC_PROTOCOL	*gSmbus = NULL; //[GBT_Chris_W_EGSTool_1]
// [GBT_Deann_W0046] +
UINT8	gBusNumber[CPU_NUMBER][CPU_BUS_NUMBER] = {
	{0x7E, 0, 0, 0, 0, 0},
	{0xFE, 0, 0, 0, 0, 0}
};

//[Gbt_Lulu_C001] +
UINT8	gSegmentBusNumber[CPU_NUMBER][CPU_BUS_NUMBER] = {
	{0xFE, 0, 0, 0, 0, 0},
	{0xFE, 0, 0, 0, 0, 0}
};
//[Gbt_Lulu_C001] -

UINT32	LANE_TX_COEFF_ARRAY[MAX_SET_OF_PRESET_COEFF] = {0xc900, 0x8a00, 0xa980, 0x6a80, 0xc00, 0xb04, 0xa86, 0xa884, 0x6906, 0xa08, 0x10800};
UPI_DATA	gUpiData[CPU_NUMBER];
USB_OC_DATA	gUsbOcData[USB_OC_NUMBER];
USB2_STR_DATA	gUsb2StrData[USB2_NUMBER];
// [GBT_Deann_W0046] -

VOID
PrintError()
{
	gST->ConOut->SetAttribute(gST->ConOut, EFI_LIGHTRED );
	Print(L"ERROR\n");
	gST->ConOut->SetAttribute(gST->ConOut, EFI_WHITE );
}

VOID
PrintSuccess()
{
	gST->ConOut->SetAttribute(gST->ConOut, EFI_LIGHTGREEN );
	Print(L"SUCCESS\n");
	gST->ConOut->SetAttribute(gST->ConOut, EFI_WHITE );
}

VOID
PrintFail()
{
	gST->ConOut->SetAttribute(gST->ConOut, EFI_LIGHTRED );
	Print(L"FAIL\n");
	gST->ConOut->SetAttribute(gST->ConOut, EFI_WHITE );
}

VOID
PrintPass()
{
	gST->ConOut->SetAttribute(gST->ConOut, EFI_LIGHTGREEN );
	Print(L"PASS\n");
	gST->ConOut->SetAttribute(gST->ConOut, EFI_WHITE );
}

VOID
FReadFile (
	FILE	*in,
	VOID	**Buffer,
	UINTN	*Length
	)
{
	fseek(in, 0, SEEK_END);
	*Length = ftell(in);
	*Buffer = malloc(*Length);
	fseek(in, 0, SEEK_SET);
	fread(*Buffer, *Length, 1, in);
}

UINT32
GetPcieBase (VOID)
{
	EFI_STATUS	Status;
	EFI_PCI_ROOT_BRIDGE_IO_PROTOCOL *PciRootBridgeIo = NULL;
	UINT32	PcieAddress = 0;
	UINT32	Value32 = 0;
	UINT32	PcieBase = 0;
	UINT32	i;
    
	Status = gBS->LocateProtocol(&gEfiPciRootBridgeIoProtocolGuid, NULL, &PciRootBridgeIo); 
	if(EFI_ERROR(Status)){
		printf("Locate PCI Root Bridge IO Protocol : %r \n", Status);
		return 0;
	}

	PcieAddress = PCI_CFG_ADDRESS(0, 0, 0, 0);
	Status = PciRootBridgeIo->Pci.Read(PciRootBridgeIo, EfiPciWidthUint32, PcieAddress, 1, &Value32);

	for(i = 0x0F; i >=1; i--){
		if(Value32 == MmioRead32((UINT32)i << 28)) break;
	}
	PcieBase = (UINT32)i << 28;

	//printf("PcieBase = 0x%X \n", PcieBase);
	return PcieBase;
}

UINTN
MmPcieAddress(
    IN UINT32						Base,
    IN UINT32                       Bus,
    IN UINT32                       Device,
    IN UINT32                       Function,
    IN UINT32                       Register
)
{
	return ((UINTN)(Base + (Bus << 20) + (Device << 15) + (Function << 12) + Register));
}

UINT8
PcieCapabilitiesOffset(
    IN UINT32						Base,
    IN UINT16                       Bus,
    IN UINT8                        Device,
    IN UINT8                        Function,
    IN UINT8                        Register
)
{
	UINT16  PciPrimaryStatus;
	UINT8   CapabilityOffset;
	UINT16  data16;
	UINT8   ItemCnt;

	PciPrimaryStatus	= 0;
	CapabilityOffset	= 0;
	data16				= 0;
	ItemCnt 		 	= 0;
	
	PciPrimaryStatus = MmioRead16(MmPcieAddress(Base, Bus, Device, Function, PCI_PRIMARY_STATUS_OFFSET));

	if(PciPrimaryStatus & EFI_PCI_STATUS_CAPABILITY){
		CapabilityOffset = MmioRead8(MmPcieAddress(Base, Bus, Device, Function, 0x34));

		while(ItemCnt < MAX_CAPABILITIES){   // maximum possible number of items in list
			if((CapabilityOffset & 3) || (CapabilityOffset < CAP_OFFSET_BASE)){    // dword alignment; lower limit			
				CapabilityOffset = 0;  // bad format or normal end of list, set not found
				break;          // terminate search
			}
			// CapOffset &= ~DWORD_MSK;  // not needed if b[1::0] must = 0
			// offset is good, get capabilities ID and next offset
			data16 = MmioRead16(MmPcieAddress(Base, Bus, Device, Function, CapabilityOffset));
			if((UINT8)(data16 & CAPABILITIES_MSK) == Register){
				break;  // requested ID found
			}
			// next item
			CapabilityOffset = (UINT8)(data16 >> 8);   // b[15::8] = next ptr
			ItemCnt++;
		}
	}
	return CapabilityOffset;
}

EFI_STATUS
GetBiosInfoFromToken(VOID)
{
	FILE	*pFile;
	char	mystring[300];
	char	*pChar;
	char	*TargetStr;
	char	Name[10];
	char	BiosVer[10];

	// Load Token.h
	Print(L"Open file(Token.h)...");
	pFile = fopen("Token.h", "r");
	if(pFile == NULL){
		PrintError();
		return EFI_LOAD_ERROR;
	}else{
		PrintSuccess();
		while(fgets(mystring, 300, pFile) != NULL)
		{
			// Get BASE_BOARD_PRODUCT_NAME
			TargetStr = "BASE_BOARD_PRODUCT_NAME";
			pChar = strstr(mystring, TargetStr);
			if(pChar != NULL)
			{
				pChar = strtok (pChar, "\t");
				if(strcmp(pChar, TargetStr) != 0) continue;
				pChar = strtok (NULL, "\n");
				strcpy(Name, pChar);
			}

			// Get OEM_BIOS_VERSION
			TargetStr = "OEM_BIOS_VERSION";
			pChar = strstr(mystring, TargetStr);
			if(pChar != NULL)
			{
				pChar = strtok (pChar, "\t");
				if(strcmp(pChar, TargetStr) != 0) continue;
				pChar = strtok (NULL, "\n");
				strcpy(BiosVer, pChar);
			}
		}

		gST->ConOut->SetAttribute(gST->ConOut, EFI_YELLOW);
		printf("Token Info:\n");
		printf("  Project Name : %s\n", Name);
		printf("  BIOS Version : %s\n", BiosVer);		
		gST->ConOut->SetAttribute(gST->ConOut, EFI_WHITE);
	}
	fclose(pFile);

	return EFI_SUCCESS;
}

EFI_STATUS
GetHsioPcieConfig(
	IN UINT8 RpIndex 
	)
{
	EFI_STATUS	Status;
	UINT32	Value32;
	UINTN	PcieRp1StrpFuseCfg;
	UINTN	RpDev;
	UINTN	RpFun;
	UINT8	RpDisable;
	
	Status = PchSbiRpPciRead32( RpIndex , R_PCH_PCIE_STRPFUSECFG, &Value32);
	if(EFI_ERROR(Status)){
		printf("ERROR: Please Unlock SBI in BIOS setup\n");
		return Status;
	}
	
	PcieRp1StrpFuseCfg = (Value32 & B_PCH_PCIE_STRPFUSECFG_RPC) >> N_PCH_PCIE_STRPFUSECFG_RPC;
	switch (PcieRp1StrpFuseCfg) {

		case 4:
			//config as _ _ _x8
			if((RpIndex % 4) == 0) printf("__ __ __ x8  ");
			break;
		case 3:
			//config as _x4_x4
			if((RpIndex % 2) == 0) printf("__ x4 __ x4  ");
			break;
	
		case 2:
			//config as __ x4 x2 x2
			if((RpIndex % 4) < 3) printf("__ x4 x2 x2  ");
			break;
		case 1:
			//config as x2 x2 __ x4
			if((RpIndex % 4) != 1) printf("x2 x2 __ x4  ");
			break;
		case 0:
			//config as x2 x2 x2 x2
			printf("x2 x2 x2 x2  ");
			break;
		default:
			printf("Reserved ");
			break;
    }

	Status = GetPchPcieRpDevFun(RpIndex, &RpDev, &RpFun, &RpDisable);
	if(RpDisable == 0) printf("Dev:0x%02X Fun:0x%02X\n", RpDev, RpFun);
	else printf("Disabled\n");

	return Status;
}

EFI_STATUS
GetLaneOwnerStatusRegister(VOID)
{
	UINT32	Value32;
	UINT8	Value8;
	UINT8	i, j;

	for(i = 0; i < 3; i++){
		// Read Lane Owner Status 1 ~ 5
		Value32 = MmioRead32(PCH_PCR_ADDRESS(PID_FIA, R_PCH_PCR_FIA_LOS1_REG_BASE + (i * 4)));

		for(j = 0; j < 8; j++){
			// Total 24 Lane
			if(((i * 8) + j) > 23) break;
			Value8 = (Value32 >> (j * 4)) & 0x0F;
			printf("Lane%02d: ", (i * 8) + j);
			switch(Value8){
				case V_PCH_PCR_FIA_LANE_OWN_PCIEDMI:
				//GBT_Lulu_C0004] +
					if(i * 8 + j > 4){
						printf("PCIe	");
						GetHsioPcieConfig(((i * 8) + j - 4));
					}
					else printf("DMI\n");
					break;
				//GBT_Lulu_C0004] +
				case V_PCH_PCR_FIA_LANE_OWN_USB3:
					printf("USB3\n");
					break;
				case V_PCH_PCR_FIA_LANE_OWN_SATA:
					if((((i * 8) + j) >= 16) && (((i * 8) + j) <= 23)) printf("SATA2\n");
					else if((((i * 8) + j) >= 8) && (((i * 8) + j) <= 15)) printf("SATA1\n");
					else printf("SATA0\n");
					break;
				case V_PCH_PCR_FIA_LANE_OWN_GBE:
					printf("GbE\n");
					break;
				//GBT_Lulu_C0004] +
				case V_PCH_PCR_FIA_LANE_OWN_MUXPCIE:
					printf("Muxed PCIe port\n");
					break;
				//GBT_Lulu_C0004] -
				default:
					printf("Reserved\n");
					break;
			}
		}
	}

	return EFI_SUCCESS;
}

EFI_STATUS
CmpSataData(int argc, char** argv)
{
	EFI_STATUS Status;
	FILE	*pFile;
	BPBID_TABLEID	   *BpbTable;
	HSIO_SATA_TABLES   *SATATableList;
	SATA_REGISTER	   *SataRegConfig;
//[Gbt_Lulu_C005] +
	EFI_GUID		   EfiIpmiTransportProtocolGuid_A5 = EFI_IPMI_TRANSPORT_PROTOCOL_APTIO5_GUID;
	EFI_IPMI_TRANSPORT_APTIO5_15 *IpmiTransportPortocol = NULL;
	UINT8			   CommandData[] = {0x0A, 0x3C, 0x00, 1};
	UINT8			   CommandDataSize = sizeof(CommandData);
	UINT8			   ResponseData[16] = {0};
	UINT8			   ResponseDataSize = sizeof(ResponseData);
//[Gbt_Lulu_C005] -
	UINT16			   BpbID = 0xFFFF;
	UINT8			   Temp = 0;
	UINT8   		   BpbTableSize = 0;
	char			   *pChar;
	char			   *TargetStr;
	int     		   FileIndex, Index;
	char			   *mystring;
	UINT8			   Error[3] = {0};
	UINT8			   *ErrorIndex;
	UINT8 			   TableID, SataCtrlIndex, PortIndex, MaxPort;
	UINT8 			   BpbIndex;
	UINT32  		   D6Address, D8Address;

	UINT32 			   DwIndex    = 0;
	UINT32 			   DwMmioAddr = 0;
	UINT32 			   DwMmioRes  = 0;
	UINT32 			   ConfigTxDw6  = 0;
	UINT32 			   ConfigTxDw8  = 0;

	TableID = 0xFF;
//[Gbt_Lulu_C006] +
    Status = gBS->LocateProtocol(
                  &EfiIpmiTransportProtocolGuid_A5,
                  NULL,
                  &IpmiTransportPortocol
                  );

    Status = IpmiTransportPortocol->SendIpmiCommand(
             IpmiTransportPortocol,
             0x2E,
             0,
             0x11,
             CommandData,
             CommandDataSize,
             (UINT8*)&ResponseData,
             &ResponseDataSize
             );
	if(EFI_ERROR (Status)){
		Print(L"Send Ipmi fail : %r\n", Status);
		return Status;
	}
//[Gbt_Lulu_C006] -

	BpbID = ((UINT16)ResponseData[13]) << 8 | ResponseData[12];
	Status = GetBiosInfoFromToken();
	if(EFI_ERROR(Status)) return Status;

	mystring = malloc( sizeof(char) * 600);

	pFile = fopen("Token.h", "r");
	while(fgets(mystring, 600, pFile) != NULL){
		TargetStr = "BPBID_TABLE_LIST";
		pChar = strstr(mystring, TargetStr);
		if(pChar != NULL){
			if((strncmp(pChar, TargetStr, sizeof(TargetStr)) == 0) && (pChar[strlen(TargetStr)] == '\t')){
				pChar = strtok(pChar, "\t");
				for(FileIndex = 0; FileIndex < 64; FileIndex++){
					pChar = strtok(NULL, ",");
					if(pChar != NULL){
						BpbTableSize++;
					}else break;
				}
			}
		}
	}
	fclose(pFile);

	BpbTable = (BPBID_TABLEID*)malloc(sizeof(BPBID_TABLEID) * (BpbTableSize / 2));
	

	pFile = fopen("Token.h", "r");
	while(fgets(mystring, 600, pFile) != NULL){
		TargetStr = "BPBID_TABLE_LIST";
		pChar = strstr(mystring, TargetStr);
		if(pChar != NULL){
			if((strncmp(pChar, TargetStr, sizeof(TargetStr)) == 0) && (pChar[strlen(TargetStr)] == '\t')){
				pChar = strtok(pChar, "\t");
				for(FileIndex = 0; FileIndex < BpbTableSize ; FileIndex++){
					pChar = strtok(NULL, " ,{}");
					if(pChar != NULL){
						if(FileIndex % 2 == 0){
							BpbTable[FileIndex / 2].BpbId = (UINT16)strtoul(pChar, NULL, 16);
						}else{
							BpbTable[FileIndex / 2].TableId = (UINT8)strtoul(pChar, NULL, 16);
						}

					}
					else break;
				}
			}
		}
	}
	fclose(pFile);



	if((BpbTableSize / 2) > 1){
		for(BpbIndex = 1; BpbIndex < ((BpbTableSize / 2) - 1); BpbIndex++){
			if(BpbTable[BpbIndex].TableId < BpbTable[BpbIndex + 1].TableId){
				Temp = BpbTable[BpbIndex + 1].TableId;
			}else Temp = BpbTable[BpbIndex].TableId;	
		}
	}

	SATATableList = (HSIO_SATA_TABLES*)malloc(sizeof(HSIO_SATA_TABLES) * (Temp + 3));	
	pFile = fopen("Token.h", "r");

	//
	//	Most of magic numbers represents the number of (word) tokens in macro definition.
	//	For each SATA controller, there are maximum 8 ports supported, each port
	//	have 2 signal config dwords, thus 16 config dwords for each controller.
	//	Since there are 3 SATA controllers and have total 20 SATA ports
	//	(SATA0=8, SATA1=8, SATA2=4) on Emmitsburg PCH, 40 config words are
	//	expected.
	//	The `1` in `41` comes from the table id used to match the BPB of
	//	The system.
	//	To sum it up, the magic number is calculated from the following formula:
	//	```
	//	1 + (SATA ports in system * number of config dwords)
	//	where:
	//	SATA ports = 8 + 8 + 4 = 20
	//	number of config dwords = 2
	//	Thus the result `41`.
	//	```
	//

	while(fgets(mystring, 600 , pFile) != NULL){
		//
		//	Get to the start of token (macro) definition, macro identifier and definition
		// 	is separated by '\t' character if it is generated from SDL.
		//
		TargetStr = "SATA_TABLE_LIST";
		pChar = strstr(mystring, TargetStr);
		if((strncmp(pChar, TargetStr, sizeof(TargetStr)) == 0) && (pChar[strlen(TargetStr)] == '\t')){
			pChar = strtok(pChar, "\t");
			for(FileIndex = 0; FileIndex < 41 * (Temp + 3) ; FileIndex++){
				// `FileIndex` represents the number of token scanned.
				pChar = strtok (NULL," ,{}");
				if(pChar != NULL){
					// Table id sits at every 41n token, n = [0, 1, 2, ...].
					if(FileIndex % 41 == 0){
						// table id
						SATATableList[FileIndex / 41].SATA.TableId = (UINT8)strtoul(pChar, NULL, 16);
					} else {
						if((FileIndex % 41) < 17){
							// port0
							SataRegConfig = &SATATableList[FileIndex / 41].SATA.SATA0Port[0];
							Index = ((FileIndex - 1) % 41) / 2;
						} else if ((FileIndex % 41) > 16 && (FileIndex % 41) < 33){
							// port1
							SataRegConfig = &SATATableList[(FileIndex / 41)].SATA.SATA1Port[0];
							Index = (((FileIndex - 1) % 41) - 16) / 2;
						} else {
							// port2
							SataRegConfig = &SATATableList[(FileIndex / 41)].SATA.SATA2Port[0];
							Index = (((FileIndex - 1) % 41) - 32) / 2;
						}
						switch((FileIndex - 1) % 2){
							case 0:
								SataRegConfig[Index].TX_DWORD6 = (UINT32)strtoul(pChar, NULL, 16);
								break;
							case 1:
								SataRegConfig[Index].TX_DWORD8 = (UINT32)strtoul(pChar, NULL, 16);
								break;
							default:
								break;
						}
					}
				} else {
					break;
				}
			}
		}
	}
	fclose(pFile);
	
	for(BpbIndex = 0; BpbIndex < (BpbTableSize / 2); BpbIndex++){
		if(BpbID == BpbTable[BpbIndex].BpbId){
			TableID = BpbTable[BpbIndex].TableId;
			break;
		}else TableID = 0xFF;
	}

	//
	// This variable relates to BPB design, for now it is a fixed value, uncomment
	// if BPB table selection is adopted.
	//

	for(Index = 0; Index < (Temp + 3) ; Index++){
		if(TableID == SATATableList[Index].SATA.TableId){
			for(SataCtrlIndex = 0; SataCtrlIndex < 3; SataCtrlIndex++){
				if(SataCtrlIndex == 0){
					SataRegConfig = &SATATableList[Index].SATA.SATA0Port[0];
					D6Address = TXDWORD6_ADDRESS | (ModPhy2 << 16) ;
					D8Address = TXDWORD8_ADDRESS | (ModPhy2 << 16) ;
					ErrorIndex = &Error[0];
					MaxPort = 8;
				}else if(SataCtrlIndex == 1){
					SataRegConfig = &SATATableList[Index].SATA.SATA1Port[0];
					D6Address = TXDWORD6_ADDRESS | (ModPhy1 << 16 ) | 0x1000;
					D8Address = TXDWORD8_ADDRESS | (ModPhy1 << 16 ) | 0x1000;
					ErrorIndex = &Error[1];
					MaxPort = 8;
				}else{
					SataRegConfig = &SATATableList[Index].SATA.SATA2Port[0];
					
					D6Address = TXDWORD6_ADDRESS | (ModPhy1 << 16 ) | 0x800;
					D8Address = TXDWORD8_ADDRESS | (ModPhy1 << 16 ) | 0x800;
					ErrorIndex = &Error[2];
					MaxPort = 4;
				}

				//
				// The ordering of SATA ports have opposite direction then the HSIO
				// numbering in Emmitsburg PCH, which is different from previous
				// platform like Purley (Lewisburg).
				// To adapt this design, we are reading ModPhyn registers in descending order.
				// For future porting of this function, make sure the HSIO muxing
				// table (refer to PCH EDS) is checked and any necessary adjustment is made.
				//
				for(PortIndex = 0; PortIndex < MaxPort ; PortIndex++){
					//
					// Read DWORD in descending order.
					//
					DwIndex = (MaxPort - 1) - PortIndex;
					
					//
					// Read SATAn_m TX_DWORD6 value from PCR[ModPhyn].
					//
					DwMmioAddr = (SATA_BASE_ADDRESS | D6Address)| TX_BASE | 0x200 * DwIndex;
					DwMmioRes  = MmioRead32(DwMmioAddr);

					ConfigTxDw6 = SataRegConfig[PortIndex].TX_DWORD6;

					switch(ConfigTxDw6){
						case 0xFFFFFFFF:
							break;
						default: 
							if(ConfigTxDw6 != DwMmioRes && ConfigTxDw6 != SATA_INVALID_DWORD){
								if(SataCtrlIndex == 0){
									*ErrorIndex += 1;
									printf("SATA0_%X ,TX_DWORD6 : ", PortIndex);
									printf("MemoryData = 0x%08X, FileData = 0x%08X\n", DwMmioRes, ConfigTxDw6);
								}else if(SataCtrlIndex == 1){
									*ErrorIndex += 1;
									printf("SATA1_%X ,TX_DWORD6 : ", PortIndex);
									printf("MemoryData = 0x%08X, FileData = 0x%08X\n", DwMmioRes, ConfigTxDw6);
								} else{
									*ErrorIndex += 1;
									printf("SATA2_%X ,TX_DWORD6 : ", PortIndex);
									printf("MemoryData = 0x%08X, FileData = 0x%08X\n", DwMmioRes, ConfigTxDw6);
								}
							}
							break;
					}

					//
					// Read SATAn_m TX_DWORD8 value from PCR[ModPhyn].
					//
					DwMmioAddr = (SATA_BASE_ADDRESS | D8Address)| TX_BASE | 0x200 * DwIndex;
					DwMmioRes  = MmioRead32(DwMmioAddr);

					ConfigTxDw8 = SataRegConfig[PortIndex].TX_DWORD8;

					switch(ConfigTxDw8){
						case 0XFFFFFFFF:
							break;
						default:
							if(ConfigTxDw8 != DwMmioRes && ConfigTxDw8 != SATA_INVALID_DWORD){
								if(SataCtrlIndex == 0){
									*ErrorIndex += 1;
									printf("SATA0_%X, TX_DWORD8 : ", PortIndex);
									printf("MemoryData = 0x%08X, FileData = 0x%08X\n", DwMmioRes, ConfigTxDw8);
								}else if(SataCtrlIndex == 1){
									*ErrorIndex +=1;
									printf("SATA1_%X, TX_DWORD8 : ", PortIndex);
									printf("MemoryData = 0x%08X, FileData = 0x%08X\n", DwMmioRes, ConfigTxDw8);
								}else{
									*ErrorIndex += 1;
									printf("SATA2_%X, TX_DWORD8 : ", PortIndex);
									printf("MemoryData = 0x%08X, FileData = 0x%08X\n", DwMmioRes, ConfigTxDw8);
								}
							}
							break;
					}
				}
				if(SataCtrlIndex == 0 && Error[0] == 0)
					printf("SATA0 Pass!!\n");
				else if(SataCtrlIndex == 1 && Error[1] == 0)
					printf("SATA1 Pass!!\n");
				else if(SataCtrlIndex == 2 && Error[2] == 0)
					printf("SATA2 Pass!!\n");
				else Status = EFI_NO_MAPPING;
			}
			break;
		}
	}

	free(BpbTable);
	free(SATATableList);
	free(mystring);
	return Status;
}

EFI_STATUS
ReadSatsData(int argc, char** argv)
{
	EFI_STATUS 		   Status;
	UINT8 			   SataCtrlIndex, PortIndex, MaxPort, i, error = 0;
	UINT8			   NO_VALUE = 0;
	UINT32  		   D6Address, D8Address;
	UINT8 			   DwIndex = 0;

	Status = GetBiosInfoFromToken();
	if(EFI_ERROR(Status)) return Status;
//GBT_Lulu_C0004] +

// Check [Disable BIOS Done] -> ENABLE ?
	for(SataCtrlIndex = 0; SataCtrlIndex < 3; SataCtrlIndex++){
		if(SataCtrlIndex == 0){// sata 0
			D6Address = TXDWORD6_ADDRESS | (ModPhy2 << 16); 
			D8Address = TXDWORD8_ADDRESS | (ModPhy2 << 16);
			MaxPort = 8;
			for(i = 0; i < MaxPort; i++){
				if(MmioRead32((SATA_BASE_ADDRESS|D6Address)|TX_BASE| i * 200) == 0xFFFFFFFF && MmioRead32((SATA_BASE_ADDRESS|D8Address)|TX_BASE| i * 200) == 0xFFFFFFFF){
					NO_VALUE++;
				}
			}
			if(NO_VALUE != MaxPort){
			}else error++;
			NO_VALUE = 0;
		}
		else if(SataCtrlIndex == 1){// sata 1
			D6Address = TXDWORD6_ADDRESS | (ModPhy1 << 16) | 0x1000;
			D8Address = TXDWORD8_ADDRESS | (ModPhy1 << 16) | 0x1000;;
			MaxPort = 8;
			for(i = 0; i < MaxPort; i++){
				if(MmioRead32((SATA_BASE_ADDRESS|D6Address)|TX_BASE| i * 200) == 0xFFFFFFFF && MmioRead32((SATA_BASE_ADDRESS|D8Address)|TX_BASE| i * 200) == 0xFFFFFFFF){
					NO_VALUE++;
				}
			}
			if(NO_VALUE != MaxPort){
			}else error++;
			NO_VALUE = 0;
		}
		else{// sata 2
			D6Address = TXDWORD6_ADDRESS | (ModPhy1 << 16) | 0x800;
			D8Address = TXDWORD8_ADDRESS | (ModPhy1 << 16) | 0x800;
			MaxPort = 4;
			for(i = 0; i < MaxPort; i++){
				if(MmioRead32((SATA_BASE_ADDRESS|D6Address)|TX_BASE| i * 200) == 0xFFFFFFFF && MmioRead32((SATA_BASE_ADDRESS|D8Address)|TX_BASE| i * 200) == 0xFFFFFFFF){
					NO_VALUE++;
				}
			}
			if(NO_VALUE != MaxPort){
			}else error++;
			NO_VALUE = 0;
		}
		if(error == 3){
			gST->ConOut->SetAttribute(gST->ConOut, EFI_LIGHTRED );
			Print(L"CAN'T READ SATA PORT\n 1. [Dfx knob Enable] -> ENABLE\n 2.into [IIO DFX CONFIGURATION]\n 3. [Disable BIOS Done] -> ENABLE\n");
			gST->ConOut->SetAttribute(gST->ConOut, EFI_WHITE );
		}	
	}

	if(error != 3){
		for(SataCtrlIndex = 0; SataCtrlIndex < 3; SataCtrlIndex++){
		if(SataCtrlIndex == 0){// sata 0
			D6Address = TXDWORD6_ADDRESS | (ModPhy2 << 16); 
			D8Address = TXDWORD8_ADDRESS | (ModPhy2 << 16);
			MaxPort = 8;
			printf("           TX_DWORD6     TX_DWORD8\n");
		}
		else if(SataCtrlIndex == 1){// sata 1
			D6Address = TXDWORD6_ADDRESS | (ModPhy1 << 16) | 0x1000;
			D8Address = TXDWORD8_ADDRESS | (ModPhy1 << 16) | 0x1000;;
			MaxPort = 8;
			printf("           TX_DWORD6     TX_DWORD8\n");
		}
		else{// sata 2
			D6Address = TXDWORD6_ADDRESS | (ModPhy1 << 16) | 0x800;
			D8Address = TXDWORD8_ADDRESS | (ModPhy1 << 16) | 0x800;
			MaxPort = 4;
			printf("           TX_DWORD6     TX_DWORD8\n");
		}
		for(PortIndex = 0; PortIndex < MaxPort ; PortIndex++){
			//
			// The ordering of HSIO lanes and SATA ports have opposite "direction"
			// in Emmitsburg PCH, please refer to PCH EDS for more information.
			// Here is a reduced table from PCH EDS for example:
			//
			// HSIO Lane#	0  1  2  3  4  5  6  7  8  9 10 11 12 13 14 15 
			// SATA2                    3  2  1  0
			// SATA1                                7  6  5  4  3  2  1  0
			//
			// As this may change in future PCH implementation, make sure you have
			// checked PCH EDS before porting this function to other platform.
			//
			DwIndex = (MaxPort - 1) - PortIndex;
			if(SataCtrlIndex == 0){
				printf("SATA0_%X   ", PortIndex);
			}
			else if(SataCtrlIndex == 1){
				printf("SATA1_%X   ", PortIndex);
			}
			else{
				printf("SATA2_%X   ", PortIndex);
			}
			printf("0x%08X ", ((MmioRead32((SATA_BASE_ADDRESS | D6Address)| TX_BASE | 0x200 * DwIndex))));
			printf("  0x%08X \n", ((MmioRead32((SATA_BASE_ADDRESS | D8Address)| TX_BASE | 0x200 * DwIndex))));
			}
		}
	}
	return Status;
//GBT_Lulu_C0004] -
}

// [GBT_Deann_W0046] +
UINT8
CpuUpiLinkCounter(VOID)
{
	UINT8	Segment = 0; //[Gbt_Lulu_C001]+
	UINT8	Bus = 0;
	UINT8	Dev = 0;
	UINT8	Cpu = 0;
	UINT8	Link = 0;
	UINT8	LinkCounter = 0;
	UINT32	DidVid = 0;
	UINT32	KtiLp0 = 0;

	for (Cpu = 0; Cpu < CPU_NUMBER; Cpu++){
//[Gbt_Lulu_C001]+		
		Segment = Cpu;
		Bus = gSegmentBusNumber[Segment][0];
//[Gbt_Lulu_C001]-
		LinkCounter = 0; // Because the two CPU type are the same, so only need count one CPU UPI

		for (Link = 0; Link < UPI_LINK_NUMBER; Link++){

			// Follow Skylake EDS Spec B(3):D(14-16):F(0) is UPI device.
			// Follow Icelake EDS Spec B(30):D(2-4):F(1) is UPI device.
			// Follow Sapphire Rapids EDS Spec B(30):D(1-4):F(1) is UPI device.
			if(Link == 0) Dev = 1;
			else if(Link == 1) Dev = 2;
			else if(Link == 2) Dev = 3;
			else Dev = 4;

			// Get ktilp0 Register value
			//[Gbt_Lulu_C001]+
			KtiLp0 = PciSegmentRead32(PCI_SEGMENT_LIB_ADDRESS (Segment, Bus, Dev, 1, 0x94));			
			//[Gbt_Lulu_C001]-

			// Check CPU UPI H/W Connect?
			if(KtiLp0 != 0x09000000){
				gUpiData[Cpu].Register.Link[Link].LinkStatus = 1;
			}

			// UPI device exist?
			//[Gbt_Lulu_C001]+
			DidVid = PciSegmentRead32(PCI_SEGMENT_LIB_ADDRESS (Segment, Bus, Dev, 1, 0));
			//[Gbt_Lulu_C001]-

			// If UPI device exist, then LinkCounter plus one.
			if(DidVid != 0xFFFFFFFF){
				LinkCounter++;
			}
		}
	}

	return LinkCounter;
}

//ConfigSocketLinkEparams
UINT32
GetUpiPHTCL(
	UINT8	SocId,
	UINT8	Link,
	UINT8	Lane
	)
{
	UINT32 KtiPhTclLanesRegOffset [MAX_LANES_PER_LINK_SPR]  = {
                                                          PH_TCL_LANE0_KTI_REUT_REG,
                                                          PH_TCL_LANE1_KTI_REUT_REG,
                                                          PH_TCL_LANE2_KTI_REUT_REG,
                                                          PH_TCL_LANE3_KTI_REUT_REG,
                                                          PH_TCL_LANE4_KTI_REUT_REG,
                                                          PH_TCL_LANE5_KTI_REUT_REG,
                                                          PH_TCL_LANE6_KTI_REUT_REG,
                                                          PH_TCL_LANE7_KTI_REUT_REG,
                                                          PH_TCL_LANE8_KTI_REUT_REG,
                                                          PH_TCL_LANE9_KTI_REUT_REG,
                                                          PH_TCL_LANE10_KTI_REUT_REG,
                                                          PH_TCL_LANE11_KTI_REUT_REG,
                                                          PH_TCL_LANE12_KTI_REUT_REG,
                                                          PH_TCL_LANE13_KTI_REUT_REG,
                                                          PH_TCL_LANE14_KTI_REUT_REG,
                                                          PH_TCL_LANE15_KTI_REUT_REG,
                                                          PH_TCL_LANE16_KTI_REUT_REG,
                                                          PH_TCL_LANE17_KTI_REUT_REG,
                                                          PH_TCL_LANE18_KTI_REUT_REG,
                                                          PH_TCL_LANE19_KTI_REUT_REG,
                                                          PH_TCL_LANE20_KTI_REUT_REG,
                                                          PH_TCL_LANE21_KTI_REUT_REG,
                                                          PH_TCL_LANE22_KTI_REUT_REG,
                                                          PH_TCL_LANE23_KTI_REUT_REG
                                                        };
	UINT32	PHTCL = 0;
	UINT8	Bus;
	UINT8	Dev;
//[Gbt_Lulu_C001]+
	UINT8	Seg = 0;

	switch (SocId)
	{
	case 0:
		Seg = 0;
		break;

	case 1:
		Seg = 1;
		break;

	default:
		break;
	}

	Bus = gSegmentBusNumber[Seg][0];
//[Gbt_Lulu_C001]-
	if(Link == 0) Dev = 1;
	else if(Link == 1) Dev = 2;
	else if(Link == 2) Dev = 3;
	else Dev = 4;

//    printf("\nSocId:%d, Link:%d, Lane:%d\n", SocId, Link, Lane);  
//[Gbt_Lulu_C001]+
	PHTCL = PciSegmentRead32(PCI_SEGMENT_LIB_ADDRESS (Seg, Bus, Dev, 2, (KtiPhTclLanesRegOffset[Lane] & 0x00000FFF)));
//[Gbt_Lulu_C001]+
//	  printf("PHTCL: 0x%x\n", PHTCL);

	return PHTCL;
}

EFI_STATUS
GetUpiDataFromRegister(VOID)
{
	UINT8	Cpu;
	UINT8	Link;
	UINT8	Lane;
	UINT8	UpiCounter;

	// Count CPU UPI Link
	UpiCounter = CpuUpiLinkCounter();

	for(Cpu = 0; Cpu < CPU_NUMBER; Cpu++){
		for(Link = 0; Link < UpiCounter; Link++){
			if (gUpiData[Cpu].Register.Link[Link].LinkStatus != 1) continue;

			for(Lane = 0; Lane < MAX_LANES_PER_LINK_SPR; Lane++){
				gUpiData[Cpu].Register.Link[Link].PH_TCL[Lane] = GetUpiPHTCL(Cpu, Link, Lane);
//[Gbt_Lulu_C001]+
//[Gbt_Lulu_C001]-
				if(gUpiData[Cpu].Register.Link[Link].PH_TCL[Lane] == 0xFFFFFFFF){
					gST->ConOut->SetAttribute(gST->ConOut, EFI_LIGHTRED);
					printf("ERROR: Please set [EV DFX Features] as [Enable] in BIOS setup\n");
					printf("ERROR: Please set [Lock Chipset] as [Disable] in BIOS setup\n");
					continue;
					//return EFI_WRITE_PROTECTED;
				}else{
					if(gDump == 1) printf("CPU%d P%d PH_TCL[%02d] = 0x%X\n ", Cpu, Link, Lane, gUpiData[Cpu].Register.Link[Link].PH_TCL[Lane]);
				}
			}
		}
	}

	return EFI_SUCCESS;
}

EFI_STATUS
GetUpiDataFromFile(
	UINT8   *Flag
){
	EFI_STATUS	Status;
	FILE	*pFile;
	char	mystring[300];
	char	*pChar = NULL; //[Gbt_Chris_W0011]
	char	*TargetStr;
	UINT8	Cpu;
	UINT8	Link;
	UINT8	Lane;
	UINT8	Done = 0;
	UINT8	UpiPerLane = 0; //[Gbt_Chris_W0011]
	UINT32	Index;

	Status = GetBiosInfoFromToken();
	if(EFI_ERROR(Status)) return Status;

	pFile = fopen("Token.h", "r");
//[Gbt_Chris_W0011]+ Use token "UPI_PerLane_TXEQ" is 1 or 0, exist or not to judge whether need to compare.
	while(fgets(mystring, 300, pFile) != NULL)
	{
		TargetStr = "UPI_PerLane_TXEQ";
		pChar = strstr(mystring, TargetStr);
		if(pChar != NULL)
		{
			if((strncmp(pChar, TargetStr, sizeof(TargetStr)) == 0) && (pChar[strlen(TargetStr)] == '\t')){
				pChar = strtok (pChar, "\t");
				pChar = strtok (NULL, "\t");
				UpiPerLane = (UINT8)strtoul(pChar, NULL, 16);
				printf("UPI_PerLane_TXEQ: %x\n", UpiPerLane);
				break;
			}
		}
	}

	if(pChar == NULL || UpiPerLane == 0){
		printf("Didn't program UPI PH_TCL.\n");
		*Flag = 1;
		return	EFI_SUCCESS;
	}
//[Gbt_Chris_W0011]-

	while(fgets(mystring, 300, pFile) != NULL)
	{
		Done = 0;
		for(Cpu = 0; Cpu < CPU_NUMBER; Cpu++){
			for(Link = 0; Link < UPI_LINK_NUMBER; Link++){
				for(Lane = 0; Lane < MAX_LANES_PER_LINK_SPR; Lane++){
					// Get CxPx_TXEQLx
					if(Lane > 19) TargetStr = "C0P0_TXEQL20";
					else if(Lane > 9) TargetStr = "C0P0_TXEQL10";
					else TargetStr = "C0P0_TXEQL0";
					TargetStr[1] = '0' + Cpu;
					TargetStr[3] = '0' + Link;
					if(Lane > 19) TargetStr[11] = '0' + (Lane - 20);
					else if(Lane > 9) TargetStr[11] = '0' + (Lane - 10);
					else TargetStr[10] = '0' + Lane;

					// Search TargetStr in mystring string 
					pChar = strstr(mystring, TargetStr);
					if(pChar != NULL)
					{
						if((strncmp(pChar, TargetStr, sizeof(TargetStr)) == 0) && (pChar[strlen(TargetStr)] == '\t')){
							pChar = strtok (pChar, "\t");
							if(gDump) printf("%s = ", pChar);
							pChar = strtok (NULL, "\n");
							Index = (UINT32)strtoul(pChar, NULL, 16);
							gUpiData[Cpu].File.Link[Link].PH_TCL[Lane] = LANE_TX_COEFF_ARRAY[Index];
							if(gDump) printf("0x%X\n", gUpiData[Cpu].File.Link[Link].PH_TCL[Lane]);
							Done = 1;
							gUpiData[Cpu].File.Link[Link].LinkStatus = 1;
							break;
						}
					}
				}

				if(Done == 1) break;
			}

			if(Done == 1) break;
		}
	}
	fclose(pFile);

	return EFI_SUCCESS;
}

EFI_STATUS
CmpUpiData(VOID)
{
	EFI_STATUS	Status = EFI_SUCCESS;
	UINT8	Cpu;
	UINT8	Link;
	UINT8	Lane;
	UINT8   UpiCount = 0;
	UINT8   BiosFileCount = 0;
	UINT8	UpiLinkCount = 0;
	UINT8	CheckFlag = 0;

	UpiCount = CpuUpiLinkCounter();

	// Check Cpu UPI Count
	if ( UpiCount != 4 ){
		CheckFlag = 1;
	}

	// Count BIOS and CPU UPI value
	for(Cpu = 0; Cpu < CPU_NUMBER; Cpu++){
		for( Link = 0; Link < UPI_LINK_NUMBER; Link++ ){
			if(gUpiData[Cpu].Register.Link[Link].LinkStatus == 1) UpiLinkCount++;
			if(gUpiData[Cpu].File.Link[Link].LinkStatus == 1) BiosFileCount++;
		}
	}

	// Because the two CPU type are the same, so only need count one CPU UPI Link
	UpiLinkCount /= CPU_NUMBER;
	BiosFileCount /= CPU_NUMBER;

	// Check BIOS and CPU UPI Link Count
	if ( UpiLinkCount != BiosFileCount ){
		CheckFlag |= 2;
	}

	// Compare File data and Register data
	for(Cpu = 0; Cpu < CPU_NUMBER; Cpu++){
		for(Link = 0; Link < UpiLinkCount; Link++){
			for(Lane = 0; Lane < MAX_LANES_PER_LINK_SPR; Lane++){
				Print(L"CPU%x Link%x PH_TCL%02d: File: 0x%8X, Register: 0x%8X ==> ", Cpu, Link, Lane, gUpiData[Cpu].File.Link[Link].PH_TCL[Lane], gUpiData[Cpu].Register.Link[Link].PH_TCL[Lane]);
				if(gUpiData[Cpu].File.Link[Link].PH_TCL[Lane] == (gUpiData[Cpu].Register.Link[Link].PH_TCL[Lane] & 0x3FFFF)){
					PrintPass();
				}else{
					PrintFail();
					CheckFlag |= 4;
				}
			}
		}
	}

	switch(CheckFlag){
		case 1:
			gST->ConOut->SetAttribute(gST->ConOut, EFI_LIGHTRED);
			printf("ERROR: Please replace to 4 pairs UPI CPU.\n");
			Status = EFI_DEVICE_ERROR;
		break;

		case 2:
			gST->ConOut->SetAttribute(gST->ConOut, EFI_LIGHTRED);
			printf("ERROR: The BIOS UPI count and CPU UPI link count not same.\n");
			printf("ERROR: The BIOS UPI count = %d, CPU UPI link count = %d\n", BiosFileCount, UpiLinkCount);
			Status = EFI_UNSUPPORTED;
		break;

		case 3:
			gST->ConOut->SetAttribute(gST->ConOut, EFI_LIGHTRED);
			printf("ERROR: Please replace to 4 pairs UPI CPU.\n");
			printf("ERROR: The BIOS UPI count and CPU UPI link count not same.\n");
			printf("ERROR: The BIOS UPI count = %d, CPU UPI link count = %d\n", BiosFileCount, UpiLinkCount);
			Status = EFI_DEVICE_ERROR;
		break;

		case 4:
			gST->ConOut->SetAttribute(gST->ConOut, EFI_LIGHTRED);
			printf("ERROR: Has PH_TCL Setting Fail\n");
			Status = EFI_INVALID_PARAMETER;
		break;

		case 5:
			gST->ConOut->SetAttribute(gST->ConOut, EFI_LIGHTRED);
			printf("ERROR: Please replace to 4 pairs UPI CPU.\n");
			printf("ERROR: Has PH_TCL Setting Fail\n");
			Status = EFI_DEVICE_ERROR;
		break;

		case 6:
			gST->ConOut->SetAttribute(gST->ConOut, EFI_LIGHTRED);
			printf("ERROR: The BIOS UPI count and CPU UPI link count not same.\n");
			printf("ERROR: The BIOS UPI count = %d, CPU UPI link count = %d\n", BiosFileCount, UpiLinkCount);
			printf("ERROR: Has PH_TCL Setting Fail\n");
			Status = EFI_UNSUPPORTED;
		break;

		case 7:
			gST->ConOut->SetAttribute(gST->ConOut, EFI_LIGHTRED);
			printf("ERROR: Please replace to 4 pairs UPI CPU.\n");
			printf("ERROR: The BIOS UPI count and CPU UPI link count not same.\n");
			printf("ERROR: The BIOS UPI count = %d, CPU UPI link count = %d\n", BiosFileCount, UpiLinkCount);
			printf("ERROR: Has PH_TCL Setting Fail\n");
			Status = EFI_DEVICE_ERROR;
		break;

		default:
			Status = EFI_SUCCESS;
		break;
	}

	return Status;
}

EFI_STATUS
GetUsbOcDataFromFile(VOID)
{
	EFI_STATUS	Status;
	FILE	*pFile;
	char	mystring[300];
	char	*pChar;
	char	*TargetStr;
	UINT8	OcPin;
	UINT8	UsbPort;

	Status = GetBiosInfoFromToken();
	if(EFI_ERROR(Status)) return Status;

	pFile = fopen("Token.h", "r");
	while(fgets(mystring, 300, pFile) != NULL)
	{
		// Get USB20_OVER_CURRENT_SETTING
		TargetStr = "USB20_OVER_CURRENT_SETTING";
		pChar = strstr(mystring, TargetStr);
		if(pChar != NULL)
		{
			if((strncmp(pChar, TargetStr, sizeof(TargetStr)) == 0) && (pChar[strlen(TargetStr)] == '\t')){
				pChar = strtok (pChar, "\t");
				for(UsbPort = 0; UsbPort < USB2_NUMBER; UsbPort++){
					pChar = strtok (NULL, ",");
					OcPin = (UINT8)strtoul(pChar, NULL, 16);
					if(OcPin >= USB_OC_NUMBER) continue;
					else gUsbOcData[OcPin].File.Usb2OcMapping |= 1 << UsbPort;
					if(gDump) printf("File.Usb2OcMapping[%d] = 0x%04X\n", OcPin, gUsbOcData[OcPin].File.Usb2OcMapping);
				}
			}
		}

		// Get USB30_OVER_CURRENT_SETTING
		TargetStr = "USB30_OVER_CURRENT_SETTING";
		pChar = strstr(mystring, TargetStr);
		if(pChar != NULL)
		{
			if((strncmp(pChar, TargetStr, sizeof(TargetStr)) == 0) && (pChar[strlen(TargetStr)] == '\t')){
				pChar = strtok (pChar, "\t");
				for(UsbPort = 0; UsbPort < USB3_NUMBER; UsbPort++){
					pChar = strtok (NULL, ",");
					OcPin = (UINT8)strtoul(pChar, NULL, 16);
					if(OcPin >= USB_OC_NUMBER) continue;
					else gUsbOcData[OcPin].File.Usb3OcMapping |= 1 << UsbPort;
					if(gDump) printf("File.Usb3OcMapping[%d] = 0x%04X\n", OcPin, gUsbOcData[OcPin].File.Usb3OcMapping);
				}
				
			}
		}
	}

	fclose(pFile);

	return EFI_SUCCESS;
}

EFI_STATUS
GetUsbOcDataFromRegister(VOID)
{
	UINT8	OcPin;
	UINT8	UsbPort;
	UINTN	XhciPciAddressBAR0;
	UINTN	XhciPciAddressBAR1;
	UINTN 	XhciMmioBase;

	XhciPciAddressBAR0 = (UINTN)PciSegmentRead32(PCI_SEGMENT_LIB_ADDRESS(0, 0, 20, 0, 0x10));
	// 64 bits
	if((XhciPciAddressBAR0 & (BIT1 | BIT2)) == BIT2){
		XhciPciAddressBAR1 = (UINTN)PciSegmentRead32(PCI_SEGMENT_LIB_ADDRESS(0, 0, 20, 0, 0x10 + 0x04));
		XhciMmioBase = (XhciPciAddressBAR0 & 0xFFFFFFF0) + (XhciPciAddressBAR1 << 32);
	}
	// 32 bits
	else {
		XhciMmioBase = (UINTN)MmioRead32(XhciPciAddressBAR0);
	}

	for(OcPin = 0; OcPin < USB_OC_NUMBER; OcPin++){
		gUsbOcData[OcPin].Register.Usb2OcMapping = MmioRead16(XhciMmioBase + R_XHCI_MEM_U2OCM1 + (OcPin * 4));
		gUsbOcData[OcPin].Register.Usb3OcMapping = MmioRead16(XhciMmioBase + R_XHCI_MEM_U3OCM1 + (OcPin * 4));

		if(gDump == 1){
			if((gUsbOcData[OcPin].Register.Usb2OcMapping == 0) && (gUsbOcData[OcPin].Register.Usb3OcMapping == 0)) continue;
			printf("USB OC#%d\n", OcPin);
			printf("  USB2 Port: ");
			for(UsbPort = 0; UsbPort < USB2_NUMBER; UsbPort++){
				if((gUsbOcData[OcPin].Register.Usb2OcMapping >> UsbPort) & 0x01) printf("%d ", UsbPort);
			}
			printf("\n");
			printf("  USB3 Port: ");
			for(UsbPort = 0; UsbPort < USB3_NUMBER; UsbPort++){
				if((gUsbOcData[OcPin].Register.Usb3OcMapping >> UsbPort) & 0x01) printf("%d ", UsbPort);
			}
			printf("\n");
		}
	}

	return EFI_SUCCESS;
}

EFI_STATUS
CmpUsbOcData(VOID)
{
	EFI_STATUS Status;
	UINT8	   UsbPort;
	UINT8	   OcPin;

	Status = EFI_SUCCESS;

	// Compare File data and Register data
	for(OcPin = 0; OcPin < USB_OC_NUMBER; OcPin++){
		if((gUsbOcData[OcPin].Register.Usb2OcMapping == 0) &&
			(gUsbOcData[OcPin].Register.Usb3OcMapping == 0) &&
			(gUsbOcData[OcPin].File.Usb2OcMapping == 0) &&
			(gUsbOcData[OcPin].File.Usb2OcMapping == 0)) continue;
		
		Print(L"USB OC#%d\n", OcPin);
		Print(L"  USB2 Port: File: ");
		for(UsbPort = 0; UsbPort < USB2_NUMBER; UsbPort++){
				if((gUsbOcData[OcPin].File.Usb2OcMapping >> UsbPort) & 0x01) Print(L"%d ", UsbPort);
		}
		Print(L"Register: ");
		for(UsbPort = 0; UsbPort < USB2_NUMBER; UsbPort++){
				if((gUsbOcData[OcPin].Register.Usb2OcMapping >> UsbPort) & 0x01) Print(L"%d ", UsbPort);
		}
		Print(L"==> ");
		if(gUsbOcData[OcPin].File.Usb2OcMapping == gUsbOcData[OcPin].Register.Usb2OcMapping){
			PrintPass();
		}else{
			PrintFail();
		}

		Print(L"  USB3 Port: File: ");
		for(UsbPort = 0; UsbPort < USB3_NUMBER; UsbPort++){
				if((gUsbOcData[OcPin].File.Usb3OcMapping >> UsbPort) & 0x01) Print(L"%d ", UsbPort);
		}
		Print(L"Register: ");
		for(UsbPort = 0; UsbPort < USB3_NUMBER; UsbPort++){
				if((gUsbOcData[OcPin].Register.Usb3OcMapping >> UsbPort) & 0x01) Print(L"%d ", UsbPort);
		}
		Print(L"==> ");
		if(gUsbOcData[OcPin].File.Usb3OcMapping == gUsbOcData[OcPin].Register.Usb3OcMapping){
			PrintPass();
		}else{
			PrintFail();
			Status = EFI_INVALID_PARAMETER;
		}
	}

	return Status;
}

EFI_STATUS
GetUsbStrDataFromFile(VOID)
{
	EFI_STATUS	Status;
	FILE	*pFile;
	char	mystring[300];
	char	*pChar;
	char	*TargetStr;
	UINT8	UsbPort;

	Status = GetBiosInfoFromToken();
	if(EFI_ERROR(Status)) return Status;

	pFile = fopen("Token.h", "r");
	while(fgets(mystring, 300, pFile) != NULL)
	{
		// Get PCH_USB_PORT_MAPPING
		TargetStr = "PCH_USB_PORT_MAPPING";
		pChar = strstr(mystring, TargetStr);
		if(pChar != NULL)
		{
			if((strncmp(pChar, TargetStr, sizeof(TargetStr)) == 0) && (pChar[strlen(TargetStr)] == '\t')){
				pChar = strtok (pChar, "\t");
				for(UsbPort = 0; UsbPort < USB2_NUMBER; UsbPort++){
					pChar = strtok (NULL, ",");
					gUsb2StrData[UsbPort].PortConfig = (UINT8)strtoul(pChar, NULL, 16);
				}
			}
		}

		// Get USB20_STRENGTH_SETTING
		TargetStr = "USB20_STRENGTH_SETTING";
		pChar = strstr(mystring, TargetStr);
		if(pChar != NULL)
		{
			if((strncmp(pChar, TargetStr, sizeof(TargetStr)) == 0) && (pChar[strlen(TargetStr)] == '\t')){
				pChar = strtok (pChar, "\t}, {"); //    "\t"  and  "}"  and  ","  and  " "  and  "{" are string's watershed
				for(UsbPort = 0; UsbPort < USB2_NUMBER; UsbPort++){	
					pChar = strtok (NULL, "\t}, {");
					gUsb2StrData[UsbPort].File.Petxiset = (UINT8)strtoul(pChar, NULL, 16);
					pChar = strtok (NULL, "\t}, {");
					gUsb2StrData[UsbPort].File.Txiset = (UINT8)strtoul(pChar, NULL, 16);
					pChar = strtok (NULL, "\t}, {");
					gUsb2StrData[UsbPort].File.Predeemp = (UINT8)strtoul(pChar, NULL, 16);
					pChar = strtok (NULL, "\t}, {");
					gUsb2StrData[UsbPort].File.Pehalfbit = (UINT8)strtoul(pChar, NULL, 16);	
					pChar = strtok (NULL, "\t}, {");
					gUsb2StrData[UsbPort].File.PredeempSemiflexEn = (UINT8)strtoul(pChar, NULL, 16);					
				}				
			}
		}
	}

	fclose(pFile);

	return EFI_SUCCESS;
}

EFI_STATUS
GetUsbStrDataFromRegister(VOID)
{
	EFI_STATUS	Status;
	UINT8	UsbPort;
	UINT32	Value32;
	UINT64	Offset;
	UINT8	Response;

	for(UsbPort = 0; UsbPort < USB2_NUMBER; UsbPort++){
		Offset = R_USB2_PCR_PP_LANE_BASE_ADDR | R_USB2_PCR_PER_PORT | ((UsbPort + 1) << 8);
		Value32 = 0;
		Status = PchSbiExecution(
			PID_USB2,
			Offset,
			PrivateControlRead,
			FALSE,
			&Value32,
			&Response);
		if(Status == EFI_WRITE_PROTECTED){
			gST->ConOut->SetAttribute(gST->ConOut, EFI_LIGHTRED);
			printf("ERROR: Please set [Dfx Knob Enabled] as [Enable] in BIOS setup\n");
			printf("ERROR: Please set [Disable BIOS Done] as [Enable] in BIOS setup\n");
			return Status;
		}
		gUsb2StrData[UsbPort].Register.Pehalfbit = (Value32 >> 14) & 0x01;
		gUsb2StrData[UsbPort].Register.Petxiset = (Value32 >> 11) & 0x07;
		gUsb2StrData[UsbPort].Register.Txiset = (Value32 >> 8) & 0x07;
		Offset = R_USB2_PCR_PP_LANE_BASE_ADDR | R_USB2_PCR_PER_PORT_2 | ((UsbPort + 1) << 8);
		Value32 = 0;
		Status = PchSbiExecution(
			PID_USB2,
			Offset,
			PrivateControlRead,
			FALSE,
			&Value32,
			&Response);
		if(Status == EFI_WRITE_PROTECTED){
			gST->ConOut->SetAttribute(gST->ConOut, EFI_LIGHTRED);
			printf("ERROR: Please set [Dfx Knob Enabled] as [Enable] in BIOS setup\n");
			printf("ERROR: Please set [Disable BIOS Done] as [Enable] in BIOS setup\n");
			return Status;
		}
		gUsb2StrData[UsbPort].Register.Predeemp = (Value32 >> 23) & 0x03;
		gUsb2StrData[UsbPort].Register.PredeempSemiflexEn = (Value32 >> 30) & 0x01;

		if(gDump == 1){
			printf("USB2 Port%d: Token: {%X, %X, %X, %X, %X}\n",
				UsbPort,
				gUsb2StrData[UsbPort].Register.Petxiset,
				gUsb2StrData[UsbPort].Register.Txiset, 
				gUsb2StrData[UsbPort].Register.Predeemp, 
				gUsb2StrData[UsbPort].Register.Pehalfbit,
				gUsb2StrData[UsbPort].Register.PredeempSemiflexEn);
			printf("  HS Pre-emphasis Bias = 0x%X, HS TX Bias = 0x%X\n", gUsb2StrData[UsbPort].Register.Petxiset, gUsb2StrData[UsbPort].Register.Txiset);
			printf("  HS TX Emphasis = 0x%X, Half Bit Pre-emphasis = 0x%X\n", gUsb2StrData[UsbPort].Register.Predeemp, gUsb2StrData[UsbPort].Register.Pehalfbit);
			printf("  Semi Flexi Pre/DE-emphasis = 0x%X\n", gUsb2StrData[UsbPort].Register.PredeempSemiflexEn);
		}
	}

	return EFI_SUCCESS;
}

EFI_STATUS
CmpUsbStrData(VOID)
{
	EFI_STATUS Status;
	UINT8	   UsbPort;

	Status = EFI_SUCCESS;

	// Compare File data and Register data
	for(UsbPort = 0; UsbPort < USB2_NUMBER; UsbPort++){
		Print(L"USB2 Port%d ", UsbPort);
		if(gUsb2StrData[UsbPort].PortConfig < USB3_NUMBER){
			Print(L"BIOS Setting - USB3 Port%d\n", gUsb2StrData[UsbPort].PortConfig);
		}
		else if(gUsb2StrData[UsbPort].PortConfig == 0x20){
			Print(L"BIOS Setting - USB 2.0 Only\n");
		}
		else if(gUsb2StrData[UsbPort].PortConfig == 0xBC){
			Print(L"BIOS Setting - Connect BMC USB 2.0\n");
		}
		else{
			Print(L"BIOS Setting - No Use\n");
			continue;
		}

		Print(L"  CombineData: File: {%X,%X,%X,%X,%X}, Register: {%X,%X,%X,%X,%X} ==> ",
			gUsb2StrData[UsbPort].File.Petxiset, 
			gUsb2StrData[UsbPort].File.Txiset, 
			gUsb2StrData[UsbPort].File.Predeemp, 
			gUsb2StrData[UsbPort].File.Pehalfbit,
			gUsb2StrData[UsbPort].File.PredeempSemiflexEn, 
			gUsb2StrData[UsbPort].Register.Petxiset, 
			gUsb2StrData[UsbPort].Register.Txiset,
			gUsb2StrData[UsbPort].Register.Predeemp,
			gUsb2StrData[UsbPort].Register.Pehalfbit,
			gUsb2StrData[UsbPort].Register.PredeempSemiflexEn);		

		if((gUsb2StrData[UsbPort].File.Petxiset == gUsb2StrData[UsbPort].Register.Petxiset) &&
			(gUsb2StrData[UsbPort].File.Txiset == gUsb2StrData[UsbPort].Register.Txiset) &&
			(gUsb2StrData[UsbPort].File.Predeemp == gUsb2StrData[UsbPort].Register.Predeemp) &&
			(gUsb2StrData[UsbPort].File.Pehalfbit == gUsb2StrData[UsbPort].Register.Pehalfbit) &&
			(gUsb2StrData[UsbPort].File.PredeempSemiflexEn == gUsb2StrData[UsbPort].Register.PredeempSemiflexEn)		
			)
		{
			PrintPass();
		}else{
			PrintFail();
			Status = EFI_INVALID_PARAMETER;
		}
	}

	return Status;
}
// [GBT_Deann_W0046] -

BOOLEAN
PcieDeviceOnBus(
    IN UINT32  Base,
    IN UINT16  Bus
)
{
	UINT8   Device = 0;
	UINT8   Function = 0;

	for(Device = 0; Device <= PCI_MAX_DEVICE; Device++){
		for(Function = 0; Function <= PCI_MAX_FUNC; Function++){
			if((MmioRead16(MmPcieAddress(Base, Bus, Device, Function, PCI_VENDOR_ID_OFFSET))) != 0xFFFF)
				return TRUE;
		}
	}
	return FALSE;
}

BOOLEAN
PcieIsPciBridgeDevice(
    IN      UINT32   Base,
    IN      UINT16   Bus,
    IN      UINT8    Device,
    IN      UINT8    Function
)
{
	UINT32  Data32 = 0;

	Data32 = MmioRead32(MmPcieAddress(Base, Bus, Device, Function, PCI_REVISION_ID_OFFSET));
	Data32 &= 0xffffff00;
	if((Data32 == 0x06040000) || (Data32 == 0x06040100)){
		return TRUE;
	}
	return FALSE;
}

UINT16
PcieExtendedCapabilitiesOffset(
    IN  UINT32   		Base,
    IN  UINT16    		Bus,
    IN  UINT8    		Device,
    IN  UINT8    		Function,
    IN  UINT16   		ExtCapabilityId,
    IN  UINT16   		VendorSpecificId
)
{
	UINT16 ExCapOffset = 0;
	UINT16 ExItemCnt = 0;
	UINT32 data32;

	if(Bus == 0 && Device == 0 && ExtCapabilityId == PCIE_EXT_CAP_HEADER_AERC)
		return 0x148;

	if(PcieCapabilitiesOffset(Base, Bus, Device, Function, EFI_PCI_CAPABILITY_ID_PCIEXP)){
		ExCapOffset = PCIE_ENHANCED_CAPABILITY_PTR;
		while(ExItemCnt < MAX_EX_CAPABILITIES){     // maximum possible number of items
			if((ExCapOffset & 3) || (ExCapOffset < EX_CAP_OFFSET_BASE)){     // dword alignment; lower limit			
				ExCapOffset = 0;  // if bad format or normal end of list, set not found
				break;			  //  terminate search
			}
			// offset is good, get capabilities ID and next offset
			// capabilities ID check
			//data32 = PciExpressRead32(PCI_PCIE_ADDR(Bus, Device, Function, ExCapOffset));	// get ID
			data32 = MmioRead32(MmPcieAddress(Base, Bus, Device, Function, ExCapOffset));
			if((data32 & EXCAPABILITIES_MSK) == ExtCapabilityId){
				if(ExtCapabilityId != 0x00B){
					break;  // requested Extended ID found
				}
				else{      // check VSEC ID
				
					// if (PciExpressRead16(PCI_PCIE_ADDR(Bus, Device, Function, ExCapOffset + PCIE_EXT_VENDOR_SPECIFIC_HEADER_OFFSET)) == VendorSpecificId) {
					if(MmioRead16(MmPcieAddress(Base, Bus, Device, Function, ExCapOffset + 0x04)) == VendorSpecificId){
						break;	// requested VSCE ID found
					}
				}
			}
			// next item
			ExCapOffset = (UINT16)(data32 >> 20);  // b[31::20] = next ptr
			ExItemCnt++;
		}
	}
	return ExCapOffset;
}


EFI_STATUS
PcieErrCheck
(
    IN UINT32						Base,
    IN UINT16                       Bus,
    IN UINT8                        Device,
    IN UINT8                        Function,
    IN GBT_PCIE_ERROR				PcieItem
)
{
	EFI_STATUS		Status;
	UINT8       	PcieCap;
	UINT8			AerCorrErr;
	UINT8			AerNfatErr;
	UINT8			AerFatErr;
	UINT8			AerAdNfatErr;
	UINT16      	AerCap, VendorId, DeviceId;
	UINT32      	ErrorMask;
	UINT16      	DeviceControl;

	UINT32 			MaskDiff;
	UINT32 			RegAecc;
	UINT32 			RegLinkCap;

	Status				= EFI_SUCCESS;
	PcieCap				= 0;
	AerCorrErr 			= 0;
	AerNfatErr 			= 0;
	AerFatErr 			= 0;
	AerAdNfatErr 		= 0;
	AerCap				= 0; 
	VendorId			= 0; 
	DeviceId			= 0;
	ErrorMask			= 0;
	DeviceControl		= 0;

	MaskDiff 			= 0;
	RegAecc 			= 0;
	RegLinkCap			= 0;


	PcieCap = PcieCapabilitiesOffset(Base, Bus, Device, Function, EFI_PCI_CAPABILITY_ID_PCIEXP);
	if(PcieCap == 0)
		return EFI_DEVICE_ERROR;

	VendorId = MmioRead16(MmPcieAddress(Base, Bus, Device, Function, PCI_VENDOR_ID_OFFSET));
	DeviceId = MmioRead16(MmPcieAddress(Base, Bus, Device, Function, PCI_DEVICE_ID_OFFSET));
	printf("Vendor ID = 0x%X, Device ID = 0x%X for %X:%X:%X \n", VendorId, DeviceId, Bus, Device, Function);

	DeviceControl = MmioRead16(MmPcieAddress(Base, Bus, Device, Function, 0x04));
// [GBT_Deann_W0028] +
	if((PcieItem.Bits.PropagateSerr << 8) != (DeviceControl & BIT8)){
		printf("B%X:D%X:F%X Pcie SERR bit doesn't match \n", Bus, Device, Function);
		Status = EFI_NO_MAPPING;
	}
	
	if((PcieItem.Bits.PropagatePerr << 6) != (DeviceControl & BIT6)){
		printf("B%X:D%X:F%X Pcie PERR bit doesn't match \n", Bus, Device, Function);
		Status = EFI_NO_MAPPING;
	}
// [GBT_Deann_W0028] -	
	
	DeviceControl = MmioRead16(MmPcieAddress(Base, Bus, Device, Function, PcieCap + GET_DEVCTL_OFFSET(Bus, Device, Function)));
	if(PcieItem.Bits.PcieCorrErrEn != (DeviceControl & BIT0)){
		printf("B%X:D%X:F%X offset %X Pcie Correct Error bit doesn't match \n", Bus, Device, Function, PcieCap + GET_DEVCTL_OFFSET(Bus, Device, Function));
		Status = EFI_NO_MAPPING;
	}
	if((PcieItem.Bits.PcieUncorrErrEn << 1) != (DeviceControl & BIT1)){
		printf("B%X:D%X:F%X offset %X Pcie UnCorrect Error bit doesn't match \n", Bus, Device, Function, PcieCap + GET_DEVCTL_OFFSET(Bus, Device, Function));
		Status = EFI_NO_MAPPING;
	}
	if((PcieItem.Bits.PcieFatalErrEn << 2) != (DeviceControl & BIT2)){
		printf("B%X:D%X:F%X offset %X Pcie Fatal Error bit doesn't match \n", Bus, Device, Function, PcieCap + GET_DEVCTL_OFFSET(Bus, Device, Function));
		Status = EFI_NO_MAPPING;
	}
	
	
	AerCap = PcieExtendedCapabilitiesOffset(Base, Bus, Device, Function, PCIE_EXT_CAP_HEADER_AERC, 0xFF);
	//printf("AerCap offset = %x\n", AerCap);
	
	if(AerCap){
		ErrorMask = MmioRead32(MmPcieAddress(Base, Bus, Device, Function, AerCap + PCIE_AER_OFFSET_REG_CEM));

		//
		//	Test if bits are not masked (enabled) when BIOS option turned on, all
		//  masked if turned off, using reverse logic here for convenience.
		//
		MaskDiff = (PcieAerCorrErrBitMap & (~ErrorMask));
		//
		//	If option is on, should have matching bits same as mask.
		//  If option is off, should have no match and being zero.
		//	Other configurations are considered to be errors.
		//
		//  Note that optional error bits are hard-wired as '0' if not implemented
		//  per PCIe specification,
		//  If there are bits cannot be disabled, please check the manual of
		//  the device.
		//
		if ((MaskDiff == 0 && PcieItem.Bits.PcieAerCorrErrEn == 0) ||
			(MaskDiff == PcieAerCorrErrBitMap && PcieItem.Bits.PcieAerCorrErrEn != 0)){
			// Being consistent with BIOS item setup, pass.
			(void)0;
		} else {
			printf("B%X:D%X:F%X Pcie Aer Correctable Error bits doesn't match, mask difference: 0x%08X \n",
				Bus, Device, Function, MaskDiff
			);
			Status = EFI_NO_MAPPING;
		}


		MaskDiff = (PcieAerAdNfatErrBitMap & (~ErrorMask));

		if ((MaskDiff == 0 && PcieItem.Bits.PcieAerAdNfatErrEn == 0) ||
			(MaskDiff == PcieAerAdNfatErrBitMap && PcieItem.Bits.PcieAerAdNfatErrEn != 0)){
			// Being consistent with BIOS item setup, pass.
			(void)0;
		} else {
			printf("B%X:D%X:F%X Pcie Aer Ad Non-Fatal Error bit doesn't match, mask difference: 0x%08X \n",
				Bus, Device, Function, MaskDiff
			);
			Status = EFI_NO_MAPPING;
		}


		ErrorMask = MmioRead32(MmPcieAddress(Base, Bus, Device, Function, AerCap + PCIE_AER_OFFSET_REG_UEM));
		

		MaskDiff = PcieAerFatErrBitMap & (~ErrorMask);

		if ((MaskDiff == 0 && PcieItem.Bits.PcieAerFatErrEn == 0) ||
			(MaskDiff == PcieAerFatErrBitMap && PcieItem.Bits.PcieAerFatErrEn != 0)){
			// Being consistent with BIOS item setup, pass.
			(void)0;
		} else {
			printf("B%X:D%X:F%X Pcie Aer Fatal Error bits doesn't match, mask difference: 0x%08X \n",
				Bus, Device, Function, MaskDiff
			);
			Status = EFI_NO_MAPPING;
		}


		MaskDiff = PcieAerNfatErrBitMap & (~ErrorMask);

		if ((MaskDiff == 0 && PcieItem.Bits.PcieAerNfatErrEn == 0) ||
			(MaskDiff == PcieAerNfatErrBitMap && PcieItem.Bits.PcieAerNfatErrEn != 0)){
			// Being consistent with BIOS item setup, pass.
			(void)0;
		} else {
			printf("B%X:D%X:F%X Pcie Aer Non-Fatal Error bits doesn't match, mask difference: 0x%08X \n",
				Bus, Device, Function, MaskDiff
			);
			Status = EFI_NO_MAPPING;
		}


		//
		// For IOU ports, ECRC mask bit is turned on if ECRC check and generation are enabled.
		// For individual PCIe devices, the option turns on the error bit and AECC
		// ECRC check and enable bits.
		//
		// This is based on the following codes:
		// - `Intel\ServerRasPkg\Library\PcieRasLib\PcieRasLib.c(2389)`
		// - `Intel\ServerRasPkg\Library\IioRasLib\Iio.c(165)`
		//
		RegAecc = MmioRead32(MmPcieAddress(Base, Bus, Device, Function, AerCap + PCIE_AER_OFFSET_REG_AECC));

		//
		// Per PCIe specification:
		// > If the Receiver does not implement ECRC Checking or ECRC Checking
		//   is not enabled, the Receiver will not detect an ECRC Error.
		//
		if ((RegAecc & B_PCIE_AER_AECC_ECRC_CHK_CAP) != 0){
			MaskDiff = PcieAerEcrcBitMap & (~ErrorMask);
			if ((MaskDiff == 0 && PcieItem.Bits.PcieAerEcrcEn == 0) ||
				(MaskDiff == PcieAerEcrcBitMap && PcieItem.Bits.PcieAerEcrcEn != 0)){
				// Being consistent with BIOS item setup, pass.
				(void)0;
			} else {
				printf("B%X:D%X:F%X Pcie Aer ECRC Error bits doesn't match, mask difference: 0x%08X \n",
					Bus, Device, Function, MaskDiff
				);
				Status = EFI_NO_MAPPING;
			}
		} else {
			printf("B%X:D%X:F%X does not support ECRC error check\n", Bus, Device, Function);
		}

		//
		// PCIE_LINK_CAPABILITY_OFFSET = 0x0C
		//
		RegLinkCap = MmioRead32(MmPcieAddress(Base, Bus, Device, Function, PcieCap + 0x0C));

		//
		// Test if device is capable of report Surprise Down Error.
		// "Surprise Down Error Reporting Capable" is bit 19 of Link Capability
		// Register in PCIe Capability Register.
		//
		if ((RegLinkCap & BIT19) != 0){
			MaskDiff = PcieAerSurpriseLinkDownBitMap & (~ErrorMask);
			if ((MaskDiff == 0 && PcieItem.Bits.PcieAerSurpriseLinkDownEn == 0) ||
				(MaskDiff == PcieAerSurpriseLinkDownBitMap && PcieItem.Bits.PcieAerSurpriseLinkDownEn != 0)){
				// Being consistent with BIOS item setup, pass.
				(void)0;
			} else {
				printf("B%X:D%X:F%X Pcie Aer Surprise Down Error bit doesn't match, mask difference: 0x%08X \n",
					Bus, Device, Function, MaskDiff
				);
				Status = EFI_NO_MAPPING;
			}
		} else {
			printf("B%X:D%X:F%X does not support Surprise Down Error report\n", Bus, Device, Function);
		}
		

		//
		// This bit is mandatory for PCIe devices, no additional check is required.
		//
		MaskDiff = PcieAerUreBitMap & (~ErrorMask);
		if ((MaskDiff == 0 && PcieItem.Bits.PcieAerUreEn == 0) ||
			(MaskDiff == PcieAerUreBitMap && PcieItem.Bits.PcieAerUreEn != 0)){
			// Being consistent with BIOS item setup, pass.
			(void)0;
		} else {
			printf("B%X:D%X:F%X Pcie Aer Unsupported Request Error bits doesn't match, mask difference: 0x%08X \n",
				Bus, Device, Function, MaskDiff
			);
			Status = EFI_NO_MAPPING;
		}
	}

	return Status;
}

VOID
PcieErrRead
(
    IN UINT32						Base,
    IN UINT16                       Bus,
    IN UINT8                        Device,
    IN UINT8                        Function,
    IN GBT_PCIE_ERROR				PcieItem
)
{ 
	UINT8       	CapabilitiesOffset;
	UINT8			AerCorrErr = 0;
	UINT8			AerNfatErr = 0;
	UINT8			AerFatErr = 0;
	UINT8			AerAdNfatErr = 0;
	UINT16      	AerCap, VendorId, DeviceId;
	UINT32      	ErrorMask;
	UINT16      	DeviceControl;

	UINT32			MaskDiff;
	UINT32			RegAecc;
	UINT32			RegLinkCap;
	
	CapabilitiesOffset	= 0;
	AerCorrErr 			= 0;
	AerNfatErr 			= 0;
	AerFatErr 			= 0;
	AerAdNfatErr 		= 0;
	AerCap				= 0; 
	VendorId			= 0; 
	DeviceId			= 0;
	ErrorMask			= 0;
	DeviceControl		= 0;

	MaskDiff			= 0;
	RegAecc				= 0;
	RegLinkCap			= 0;

	CapabilitiesOffset = PcieCapabilitiesOffset(Base, Bus, Device, Function, EFI_PCI_CAPABILITY_ID_PCIEXP);
	if(CapabilitiesOffset == 0)
		return ;

	VendorId = MmioRead16(MmPcieAddress(Base, Bus, Device, Function, PCI_VENDOR_ID_OFFSET));
	DeviceId = MmioRead16(MmPcieAddress(Base, Bus, Device, Function, PCI_DEVICE_ID_OFFSET));
	printf("Vender ID = 0x%X, Device ID = 0x%X for %X:%X:%X \n", VendorId, DeviceId, Bus, Device, Function);

	DeviceControl = MmioRead16(MmPcieAddress(Base, Bus, Device, Function, 0x04));
	printf("Pcie PERR bit = %X \n", (DeviceControl & BIT6) >> 6);
	printf("Pcie SERR bit = %X \n", (DeviceControl & BIT8) >> 8);

	DeviceControl = MmioRead16(MmPcieAddress(Base, Bus, Device, Function, CapabilitiesOffset + GET_DEVCTL_OFFSET(Bus, Device, Function)));
	printf("Pcie Correct Error bit  = %X \n", (DeviceControl & BIT0));
	printf("Pcie UnCorrect Error bit  = %X \n", (DeviceControl & BIT1) >> 1);
	printf("Pcie Faral Error bit  = %X \n", (DeviceControl & BIT2) >> 2);

	AerCap = PcieExtendedCapabilitiesOffset(Base, Bus, Device, Function, PCIE_EXT_CAP_HEADER_AERC, 0xFF);
	if(AerCap){
		ErrorMask = MmioRead32(MmPcieAddress(Base, Bus, Device, Function, AerCap + PCIE_AER_OFFSET_REG_CEM));
		printf("Pcie Aer Correctable Error Mask Register  = %X \n", ErrorMask);
		if((PcieAerCorrErrBitMap & ErrorMask) == 0) AerCorrErr = 1;
		printf("Pcie Aer Correct Error bit  = %X \n", AerCorrErr);

		ErrorMask = MmioRead32(MmPcieAddress(Base, Bus, Device, Function, AerCap + PCIE_AER_OFFSET_REG_UEM));
		printf("Pcie Aer Uncorrectable Error Mask Register  = %X \n", ErrorMask);


		MaskDiff = (PcieAerFatErrBitMap & (~ErrorMask));
		if (MaskDiff == PcieAerFatErrBitMap){
			AerFatErr = 1;
		}
		
		MaskDiff = (PcieAerNfatErrBitMap & (~ErrorMask));
		if (MaskDiff == PcieAerNfatErrBitMap){
			AerNfatErr = 1;
		}

		MaskDiff = (PcieAerAdNfatErrBitMap & (~ErrorMask));
		if (MaskDiff == PcieAerAdNfatErrBitMap){
			AerAdNfatErr = 1;
		}

		printf("Pcie Aer Fatal Error  bit  = %X \n", AerFatErr);
		printf("Pcie Aer Not Fatal Error bit  = %X \n", AerNfatErr);
		printf("Pcie Aer Ad Not Fatal Error bit  = %X \n", AerAdNfatErr);


		RegAecc = MmioRead32(MmPcieAddress(Base, Bus, Device, Function, AerCap + PCIE_AER_OFFSET_REG_AECC));
		if ((RegAecc & B_PCIE_AER_AECC_ECRC_CHK_CAP) != 0){
			MaskDiff = PcieAerEcrcBitMap & (~ErrorMask);
			printf("Pcie Aer ECRC Error bit = %X \n", MaskDiff? 1: 0);
		} else {
			printf("Device does not support ECRC error check\n", Bus, Device, Function);
		}


		//
		// PCIE_LINK_CAPABILITY_OFFSET = 0x0C
		//
		RegLinkCap = MmioRead32(MmPcieAddress(Base, Bus, Device, Function, CapabilitiesOffset + 0x0C));
		
		//
		// "Surprise Down Error Reporting Capable" is bit 19 of Link Capability
		// Register in PCIe Capability Register.
		//
		if ((RegLinkCap & BIT19) != 0){
			MaskDiff = PcieAerSurpriseLinkDownBitMap & (~ErrorMask);
			printf("Pcie Aer Surprise Link Down Error bit = %X \n", MaskDiff? 1: 0);
		} else {
			printf("Device does not support Surprise Down Error report\n", Bus, Device, Function);
		}
		

		MaskDiff = PcieAerUreBitMap & (~ErrorMask);
		printf("Pcie Aer Unsupported Request Error bit = %X \n", MaskDiff? 1: 0);

	} 
}

EFI_STATUS
PcieEnableDeviceAndSubDevices(
    IN UINT32   						Base,
    IN UINT16   						Bus,
    IN UINT8    						Device,
    IN UINT8    						Function,
    IN GBT_PCIE_ERROR					PcieItem,
    char								**argv
)
{
	EFI_STATUS	Status;
	UINT8 		SecondaryBusNumber;
	UINT8 		SubordinateBusNumber;
	UINT8		ErrorIndex;

	Status               = EFI_SUCCESS;
	SecondaryBusNumber   = 0;
	SubordinateBusNumber = 0;
	ErrorIndex			 = 0;

	if(PcieIsPciBridgeDevice(Base, Bus, Device, Function)){
		SecondaryBusNumber = MmioRead8(
		                         MmPcieAddress(
		                             Base,
		                             Bus,
		                             Device,
		                             Function,
		                             PCI_BRIDGE_SECONDARY_BUS_REGISTER_OFFSET
		                         ));

		SubordinateBusNumber = MmioRead8(
		                           MmPcieAddress(
		                               Base,
		                               Bus,
		                               Device,
		                               Function,
		                               PCI_BRIDGE_SUBORDINATE_BUS_REGISTER_OFFSET
		                           ));

		if(SubordinateBusNumber >= SecondaryBusNumber){
			if(strcasecmp(argv[2], "c") == 0){
				Status = PcieErrCheck(Base, Bus, Device, Function, PcieItem);
				if(Status == EFI_NO_MAPPING) ErrorIndex++;
			}
			else if(strcasecmp(argv[2], "r") == 0){
				PcieErrRead(Base, Bus, Device, Function, PcieItem); 
			}
			for(Bus = SecondaryBusNumber; Bus <= SubordinateBusNumber; Bus++){
				for(Device = 0; Device <= 0x1F; Device++){
					for(Function = 0; Function <= 7; Function++){
						if(!PcieIsPciBridgeDevice(Base, Bus, Device, Function)){
							continue;
						}
						if((MmioRead16(MmPcieAddress(Base, Bus, Device, Function, PCI_VENDOR_ID_OFFSET))) == 0xFFFF)
							continue;
						if(strcasecmp(argv[2], "c") == 0){
							Status = PcieErrCheck(Base, Bus, Device, Function, PcieItem);
							if(Status == EFI_NO_MAPPING) ErrorIndex++;
						}
						else if(strcasecmp(argv[2], "r") == 0){
							PcieErrRead(Base, Bus, Device, Function, PcieItem);
						}
					} // Function
				} // Device.
				if(Bus == 0xFF) break;
			} // Bus
		} //Subordinate & Secondary Bus
	}// IsPcieBridgeDevice
	
	if(ErrorIndex != 0) Status = EFI_NO_MAPPING;
	return Status;
}

CHAR16 *
DuplicateString8To16(
	CHAR8 *String
	)
{
	CHAR16 *DuplicateString;
	UINTN  StringLength;
	UINTN  Index;

	DuplicateString = NULL;
	StringLength    = 0;
	Index           = 0;

	if(String) {
		StringLength    = AsciiStrLen(String);
		DuplicateString = AllocateZeroPool(((StringLength + 1) * sizeof(CHAR16)));

		if(DuplicateString) {
			for(Index = 0; Index < StringLength; Index++) {
				DuplicateString[Index] = (CHAR16)String[Index];
			}
		}
	}

	return DuplicateString;
}

CHAR8 *
GetVarNameData(
	CHAR8    *VarName,
	EFI_GUID VarGuid,
	UINT32   *VarAttr,
	UINTN    *VarSize
	)
{
	EFI_STATUS Status;
	CHAR16     *VarName16;
	UINT32     VarAttribute;
	CHAR8      *VarData;
	UINTN      VarDataSize;


	Status       = EFI_SUCCESS;
	VarName16    = DuplicateString8To16(VarName);
	VarAttribute = 7;
	VarData      = NULL;
	VarDataSize  = 0;


	if(VarName16 == NULL) {
		Print(L"[GetVarNameData]: Out Of Resources - VarName16\n");
		goto ErrorExit;
	}

	Status = gST->RuntimeServices->GetVariable(
		                               VarName16,
		                               &VarGuid,
		                               &VarAttribute,
		                               &VarDataSize,
		                               VarData
                              		);

	if(Status != EFI_BUFFER_TOO_SMALL) {
		Print(L"[GetVarNameData]: Get Variable %s Size Fail Status = %r\n", VarName16, Status);
		goto ErrorExit;
	}

	VarData = (CHAR8 *)AllocateZeroPool(VarDataSize);

	if(VarData == NULL) {
		Print(L"[GetVarNameData]: Out Of Resources - VarData\n");
		goto ErrorExit;
	}

	Status = gST->RuntimeServices->GetVariable(
		                               VarName16,
		                               &VarGuid,
		                               &VarAttribute,
		                               &VarDataSize,
		                               VarData
		                              );

	if(EFI_ERROR(Status)) {
		Print(L"[GetVarNameData]: Get Variable %s Fail Status = %r\n", VarName16, Status);
		FreePool(VarData);
		VarData = NULL;
		goto ErrorExit;
	}

	*VarAttr = VarAttribute;
	*VarSize = VarDataSize;

ErrorExit:
	if(VarName16) {
		FreePool(VarName16);
	}

	return VarData;
}


EFI_STATUS
ScanItem(
	EFI_HII_HANDLE          HiiHandle,
	EFI_HII_PACKAGE_HEADER  *Package,
	GBT_PCIE_ERROR   		*PcieError,
	BOOLEAN                 *Flag
)
{
	EFI_STATUS            	Status;
	UINTN                 	PackageIndex;
	UINT8                 	*TempPoint8;
	EFI_IFR_OP_HEADER     	*IfrOpHdr;
	EFI_IFR_ONE_OF        	*IfrOneOf;
	EFI_IFR_VARSTORE      	*IfrVarstore;
	EFI_IFR_VARSTORE_EFI  	*IfrVarstoreEfi;
	CHAR16                	*QuestionString;
	UINT64                	TempValue64;
	UINT64                	InitValue64;
	BOOLEAN					VarFind;
	IFR_VAR_NAME         	*VarStorePtr;
	CHAR8                 	*VarData;
	UINTN                 	VarSize;
	UINT32                	VarAttr;
	UINT16					Index;
	UINT8					FindCount;

	Status            = EFI_SUCCESS;
	PackageIndex      = sizeof(EFI_HII_PACKAGE_HEADER);
	TempPoint8        = (UINT8 *)Package;
	IfrOpHdr          = NULL;
	QuestionString	  = NULL;
	TempValue64       = 0;
	InitValue64       = 0;
	IfrVarstore       = NULL;
	IfrVarstoreEfi    = NULL;
	VarFind			  = FALSE;
	VarStorePtr	  	  = NULL;
	VarData           = NULL;
	VarSize           = 0;
	VarAttr           = 0;
	FindCount		  = 0;
	
	VarStorePtr = malloc(sizeof(IFR_VAR_NAME));


	while (PackageIndex < Package->Length) {
		IfrOpHdr = (EFI_IFR_OP_HEADER *)(TempPoint8 + PackageIndex);
		PackageIndex += IfrOpHdr->Length;
			
		if(*Flag == TRUE) break;
		
		switch(IfrOpHdr->OpCode){
			case EFI_IFR_ONE_OF_OP:
			case EFI_IFR_NUMERIC_OP:
			case EFI_IFR_CHECKBOX_OP:
				if(!VarFind) break;
				
				IfrOneOf       = (EFI_IFR_ONE_OF *)IfrOpHdr;
				QuestionString = NULL;
				
				if(IfrOneOf->Question.Header.Prompt) {
					QuestionString = HiiGetString(HiiHandle, IfrOneOf->Question.Header.Prompt, NULL);
				} 
				else {
					break;
				}
				
				if((QuestionString == NULL) || !StrCmp(QuestionString, GBT_SETUP_NO_STRING16) || StrLen(QuestionString) == 0) {
					break;
				}
				
				for(Index = 0; Index < PcieItemCount; Index++) {
					if(!StrCmp(QuestionString, PcieErrorItem[Index])) {
						FindCount++;
						break;
					}
				}
				if(Index == PcieItemCount) break;

				if(FindCount == PcieItemCount) *Flag = TRUE;;
				

				VarSize = 0;
				VarData = GetVarNameData(VarStorePtr->Name, VarStorePtr->Guid, &VarAttr, &VarSize);
				if(VarData == NULL || VarSize == 0) {
					Print(L"Skip This Packet\n");
					break;
				}
				
				TempValue64 = 0xFFFFFFFFFFFFFFFF;
				InitValue64 = 0xFFFFFFFFFFFFFFFF;

				if(IfrOpHdr->OpCode == EFI_IFR_CHECKBOX_OP) {
					TempValue64 = *(UINT8 *)(&VarData[IfrOneOf->Question.VarStoreInfo.VarOffset]);					
				}else {
					switch(IfrOneOf->Flags & EFI_IFR_NUMERIC_SIZE) {
						case EFI_IFR_NUMERIC_SIZE_1:
							TempValue64 = *(UINT8 *)(&VarData[IfrOneOf->Question.VarStoreInfo.VarOffset]);
							break;

						case EFI_IFR_NUMERIC_SIZE_2:
							TempValue64 = *(UINT16 *)(&VarData[IfrOneOf->Question.VarStoreInfo.VarOffset]);
							break;

						case EFI_IFR_NUMERIC_SIZE_4:
							TempValue64 = *(UINT32 *)(&VarData[IfrOneOf->Question.VarStoreInfo.VarOffset]);
							break;

						case EFI_IFR_NUMERIC_SIZE_8:
							TempValue64 = *(UINT64 *)(&VarData[IfrOneOf->Question.VarStoreInfo.VarOffset]);
							break;
					}										
				}
				PcieError->Data |= (UINT32)(TempValue64 << Index);
				break;
			case EFI_IFR_VARSTORE_OP:
				IfrVarstore = (EFI_IFR_VARSTORE *)IfrOpHdr;
				if(IfrVarstore->VarStoreId && !VarFind){
					if(!strcmp("IntelSetup", IfrVarstore->Name)) {
						VarFind = TRUE;
						VarStorePtr->Guid       = IfrVarstore->Guid;
						VarStorePtr->VarStoreId = IfrVarstore->VarStoreId;
						VarStorePtr->Size       = IfrVarstore->Size;
						VarStorePtr->Name       = IfrVarstore->Name;
					}
				}
				IfrVarstore = NULL;
				break;
			case EFI_IFR_VARSTORE_EFI_OP:
				IfrVarstoreEfi = (EFI_IFR_VARSTORE_EFI *)IfrOpHdr;

				if(IfrVarstoreEfi->VarStoreId && !VarFind){
					if(!strcmp("IntelSetup", IfrVarstoreEfi->Name)) {
						VarFind = TRUE;
						VarStorePtr->Guid       = IfrVarstoreEfi->Guid;
						VarStorePtr->VarStoreId = IfrVarstoreEfi->VarStoreId;
						VarStorePtr->Size       = IfrVarstoreEfi->Size;
						VarStorePtr->Attributes = IfrVarstoreEfi->Attributes;
						VarStorePtr->Name       = IfrVarstoreEfi->Name;
					}
				}

				IfrVarstoreEfi = NULL;
				break;
		}
	}	

	free(VarStorePtr);
	VarStorePtr = NULL;

	return Status;
}

EFI_STATUS
GetPcieErrorItemValue(
	GBT_PCIE_ERROR	*Item,
	BOOLEAN			*FindFlag
)
{
	EFI_STATUS                  Status;
	EFI_HII_DATABASE_PROTOCOL   *pHiiDatabaseProtocol;
	UINTN                       HiiHandleSize;
	EFI_HII_HANDLE              *HiiHandleBuffer;
	UINTN                       ListCount;
	UINTN                       Index;
	UINTN                       HiiPackageListLength;
	EFI_HII_PACKAGE_LIST_HEADER *HiiPackageList;
	UINTN                       PackageListIndex;
	UINT8                       *TempPoint8;
	EFI_HII_PACKAGE_HEADER      *Package;
	UINTN                       FormSetCount;


	Status               = EFI_SUCCESS;
	pHiiDatabaseProtocol = NULL;
	HiiHandleSize        = 0;
	HiiHandleBuffer      = NULL;
	ListCount            = 0;
	Index                = 0;
	HiiPackageListLength = 0;
	HiiPackageList       = NULL;
	PackageListIndex     = 0;
	TempPoint8           = NULL;
	Package              = NULL;
	FormSetCount         = 0;

	Status = gBS->LocateProtocol(
	                             &gEfiHiiDatabaseProtocolGuid,
	                             NULL,
	                             (VOID **)&pHiiDatabaseProtocol
	                            );

	if(EFI_ERROR(Status)) {
		Print(L"[GetPcieErrorItemValue]: Locate Hii Database Protocol Fail - %r\n", Status);
		return Status;
	}

	//
	// Get HII Package List Handle Buffer Size
	//
	Status = pHiiDatabaseProtocol->ListPackageLists(
	                                                pHiiDatabaseProtocol,
	                                                EFI_HII_PACKAGE_TYPE_ALL,
	                                                NULL,
	                                                &HiiHandleSize,
	                                                HiiHandleBuffer
	                                               );

	if(Status == EFI_BUFFER_TOO_SMALL) {
		HiiHandleBuffer = AllocateZeroPool(HiiHandleSize);

		if(HiiHandleBuffer == NULL) {
			Print(L"[GetPcieErrorItemValue]: Out Of Resources - HiiHandleBuffer\n");
			return EFI_OUT_OF_RESOURCES;
		}

		Status = pHiiDatabaseProtocol->ListPackageLists(
		                                                pHiiDatabaseProtocol,
		                                                EFI_HII_PACKAGE_TYPE_ALL,
		                                                NULL,
		                                                &HiiHandleSize,
		                                                HiiHandleBuffer
		                                               );
	}

	if(EFI_ERROR(Status)) {
		Print(L"[GetPcieErrorItemValue]: Get Hii Package List Handle Buffer Fail - %r\n", Status);
		goto ErrorExit;
	}

	ListCount = HiiHandleSize / sizeof(EFI_HII_HANDLE);

	for(Index = 0; Index < ListCount; Index++) {
		HiiPackageListLength = 0;
		HiiPackageList       = NULL;
		Status = pHiiDatabaseProtocol->ExportPackageLists(
		                                                  pHiiDatabaseProtocol,
		                                                  HiiHandleBuffer[Index],
		                                                  &HiiPackageListLength,
		                                                  HiiPackageList
		                                                 );

		if(Status == EFI_BUFFER_TOO_SMALL) {
			HiiPackageList = AllocateZeroPool(HiiPackageListLength * sizeof(EFI_HII_PACKAGE_LIST_HEADER));

			if(HiiPackageList == NULL) {
				Print(L"[GetPcieErrorItemValue]: Out Of Resources - HiiPackageList\n");
				Status = EFI_OUT_OF_RESOURCES;
				goto ErrorExit;
			}

			Status = pHiiDatabaseProtocol->ExportPackageLists(
			                                                  pHiiDatabaseProtocol,
			                                                  HiiHandleBuffer[Index],
			                                                  &HiiPackageListLength,
			                                                  HiiPackageList
			                                                 );
		}

		if(EFI_ERROR(Status)) {
			Print(L"[GetPcieErrorItemValue]: Export Package Lists Fail - %r\n", Status);
			goto ErrorExit;
		}

		TempPoint8       = (UINT8 *)HiiPackageList;
		PackageListIndex = sizeof(EFI_HII_PACKAGE_LIST_HEADER);

		while(PackageListIndex < HiiPackageList->PackageLength){
			Package           = (EFI_HII_PACKAGE_HEADER *)(TempPoint8 + PackageListIndex);
			PackageListIndex += Package->Length;

			if(Package->Length == 0) {
				break;
			}

			if(Package->Type == EFI_HII_PACKAGE_FORMS) {
				Status = ScanItem(HiiHandleBuffer[Index], Package, Item, FindFlag);
				if(EFI_ERROR(Status)) {
					Print(L"[GetPcieErrorItemValue]: ScanItem Error - %r\n", Status);
					break;
				}
			}
		}

		FreePool(HiiPackageList);
		HiiPackageList = NULL;
	}

ErrorExit:
	if(HiiPackageList) {
		FreePool(HiiPackageList);
	}

	if(HiiHandleBuffer) {
		FreePool(HiiHandleBuffer);
	}

	return Status;
}

EFI_STATUS
PcieErrScan(int argc, char** argv)
{
	EFI_STATUS 		   		  	Status;
	UINT32 			   		  	PcieBase;
	UINT16                    	bus;
	UINT8                     	dev = 0;
	UINT8                     	fun = 0;
	UINT8					  	SecondaryBusNumber;
	UINT8       				CapabilitiesOffset;
	UINT8						ErrorIndex;
	GBT_PCIE_ERROR				PcieItem;
	BOOLEAN						Findflag;

// [Gbt_Jim_Y0008] +
	USRA_ADDRESS				UsraSegBase;
	UINT64						PciBaseBdf;
	UINTN						SegBase;
	UINTN						CpuIdx;
// [Gbt_Jim_Y0008] -

	Status              = EFI_SUCCESS;
	PcieBase            = 0;
	bus                 = 0;
	dev                 = 0;
	fun                 = 0;
	SecondaryBusNumber  = 0;
	CapabilitiesOffset  = 0;
	ErrorIndex			= 0;
	Findflag			= FALSE;

	PcieItem.Data		= 0;

	Status = GetBiosInfoFromToken();
	if (EFI_ERROR(Status)){
		return Status;
	}

	Status = GetPcieErrorItemValue(&PcieItem, &Findflag);
	
	if(EFI_ERROR(Status) || !Findflag) {
		Print(L"GetPcieErrorValue fail Status : %r\n", Status);
		return Status;
	}	
	
	if(PcieItem.Bits.PcieErrEn == 0){
		printf("Pcie Error bit is disable.\n");
		return EFI_NO_MAPPING;
	}


	//
	// Currently (EGS) when multi-segment is enabled, Intel RC distributes one segment
	// per CPU, for future porting, please ensure Intel keep the same policy 
	// before using this tool.
	//
// [Gbt_Jim_Y0008]+
	for (CpuIdx = 0; CpuIdx < CPU_NUMBER; CpuIdx++){
		//
		// Do reverse base address look up using the first device of each segment,
		// based on Intel USRA library.
		//
		PciBaseBdf = PCI_SEGMENT_LIB_ADDRESS(CpuIdx, 0, 0, 0, 0);
		USRA_PCIE_SEG_LIB_ADDRESS(UsraSegBase, PciBaseBdf, EfiPciWidthUint32);
		SegBase = GetRegisterAddress(&UsraSegBase);
// [Gbt_Jim_Y0008]-

		PcieBase = (UINT32)SegBase;
		for(bus = 0; bus <= 0xFF; bus++){
			for(dev = 0; dev <= 0x1F; dev++){
				for(fun = 0; fun <= 0x07; fun++){
					if((MmioRead16(MmPcieAddress(PcieBase, bus, dev, fun, PCI_VENDOR_ID_OFFSET))) == 0xFFFF)
						continue;

					CapabilitiesOffset = PcieCapabilitiesOffset(PcieBase, bus, dev, fun, EFI_PCI_CAPABILITY_ID_PCIEXP);
					if(CapabilitiesOffset == 0)
					{
						// printf("Not PCIe device\n");
						continue;
					}	

					if(((MmioRead8(MmPcieAddress(PcieBase, bus, dev, fun, CapabilitiesOffset + PCIE_CAP_REG))) & 0xf0) != 0x40) //Indicate Dev/Fun type is Root Port of PCI Express Root Complex
					{
						// printf("Not pcie root port\n");
						continue;
					}	

					if((bus == 0) & (dev == 0) & (fun == 0)){
						if(strcasecmp(argv[2], "c") == 0){
							Status = PcieErrCheck(PcieBase, bus, dev, fun, PcieItem);
							if(Status == EFI_NO_MAPPING) ErrorIndex++;
						}
						else if(strcasecmp(argv[2], "r") == 0){
							PcieErrRead(PcieBase, bus, dev, fun, PcieItem); 
						}
					}
					SecondaryBusNumber = MmioRead8(MmPcieAddress(PcieBase, bus, dev, fun, PCI_BRIDGE_SECONDARY_BUS_REGISTER_OFFSET));

					if((SecondaryBusNumber != 0) /*&& PcieDeviceOnBus(PcieBase, SecondaryBusNumber)*/){
						// (#3433+) scans bus number [secondary bus, subordinate bus], non-recursive.
						Status = PcieEnableDeviceAndSubDevices(PcieBase, bus, dev, fun, PcieItem, argv);
						if(Status == EFI_NO_MAPPING) ErrorIndex++;
					}
				}
			}
		}
// [Gbt_Jim_Y0008]+
	}
// [Gbt_Jim_Y0008]-

	
	if (ErrorIndex != 0) {
		Status = EFI_NO_MAPPING;
	} else {
		if(strcasecmp(argv[2], "c") == 0){
			gST->ConOut->SetAttribute(gST->ConOut, EFI_WHITE);
			printf("PCIE Error check :  ");
			gST->ConOut->SetAttribute(gST->ConOut, EFI_LIGHTGREEN);
			printf("PASS!!!!!\n");
			gST->ConOut->SetAttribute(gST->ConOut, EFI_WHITE);
		}
	}
	return Status;
}

//[GBT_Chris_W_EGSTool_1]+
EFI_STATUS
ConfirmChecksum (
	IN UINT32   DataLength,
	IN UINT8    *Binary
){
	UINT8    Value8 = 0;
	UINT32   i;

	for(i = 0; i < DataLength; i++){
		Value8 = Value8 + Binary[i];
	}
	if(Value8 == 0) return EFI_SUCCESS;
	else return EFI_LOAD_ERROR;
}

/*
 * According channel spec common design :
 *      CPU 0 VR -> E2_Ch1
 *      CPU 1 VR -> E2_Ch2
 *      CPU 2 VR -> E2_Ch6
 *      CPU 3 VR -> E2_Ch7
 */
UINT8
JugdeSmbusChannel(
	UINT8 NumSocket
){
	UINT8 SelectChannel = 0xFF;

	switch(NumSocket){
		case 0 :
			SelectChannel = 1;
			break;
		case 1 :
			SelectChannel = 2;
			break;
		case 2 :
			SelectChannel = 6;
			break;
		case 3 :
			SelectChannel = 7;
			break;
		default :
			break;
	}

	return SelectChannel;
}

EFI_STATUS
SmbusSwitchSelect(
	IN UINT8   SwitchAddress,
	IN UINT8   SwitchChannel
){
	EFI_STATUS                 Status = EFI_SUCCESS;
	EFI_SMBUS_DEVICE_ADDRESS   SlaveAddress;
	UINTN                      SmbusLength = 0x01;
	UINT8                      Value8;

	// Check Smbus switch exist or not
	if(SwitchChannel != 0xFF){
		switch(SwitchChannel){
			case 0:
				Value8 = 0x01; // PCA9548 Ch0
				break;
			case 1:
				Value8 = 0x02; // PCA9548 Ch1
				break;
			case 2:
				Value8 = 0x04; // PCA9548 Ch2
				break;
			case 3:
				Value8 = 0x08; // PCA9548 Ch3
				break;
			case 4:
				Value8 = 0x10; // PCA9548 Ch4
				break;
			case 5:
				Value8 = 0x20; // PCA9548 Ch5
				break;
			case 6:
				Value8 = 0x40; // PCA9548 Ch6
				break;
			case 7:
				Value8 = 0x80; // PCA9548 Ch7
				break;
			case 0xFF:
				Value8 = 0x00; // Disable all channel
				break;
			default:
				Status = EFI_INVALID_PARAMETER;
				return Status;
		}
		SlaveAddress.SmbusDeviceAddress = (SwitchAddress >> 1) ;
		Status = gSmbus->Execute (
			gSmbus,
			SlaveAddress,
			0x00, //SmbusOffset,
			EfiSmbusWriteByte,
			FALSE,
			&SmbusLength,
			&Value8
			);
		if(EFI_ERROR(Status)) return Status;
	}
	return Status;
}

EFI_STATUS
MpsReadData(
	IN MPS_BINARY_FORMAT   *BinaryFormatPtr
){
	EFI_STATUS                 Status;
	UINT8                      SmbReadOperation;
	UINTN                      DataLength;
	EFI_SMBUS_DEVICE_ADDRESS   SlaveAddress;
	UINTN                      ChipData;
	UINTN                      FileData;

	if(BinaryFormatPtr->Length == 1){
		SmbReadOperation = EfiSmbusReadByte;
		DataLength = 1;
		FileData = BinaryFormatPtr->Data;
	} else if(BinaryFormatPtr->Length == 2){
		SmbReadOperation = EfiSmbusReadWord;
		DataLength = 2;
		FileData = BinaryFormatPtr->Data;
	} else if((BinaryFormatPtr->Length & 0xF0) == 0x80){
		SmbReadOperation = EfiSmbusReadBlock;
		DataLength = (BinaryFormatPtr->Length & 0x0F);
		FileData = BinaryFormatPtr->Data;
	} else{
		return EFI_INVALID_PARAMETER;
	}

	SlaveAddress.SmbusDeviceAddress = BinaryFormatPtr->SmbusAddress;
	ChipData = 0;
	Status = gSmbus->Execute(
		gSmbus,
		SlaveAddress,
		BinaryFormatPtr->Register,
		SmbReadOperation,
		FALSE,
		&DataLength,
		&ChipData);

	if(!EFI_ERROR(Status)){
		if(ChipData == FileData){
			return EFI_SUCCESS;
		} else if(BinaryFormatPtr->Register == 0){
			return EFI_SUCCESS;
		} else{
			printf("MPS MPS SmbusAddress[0x%02X].Offset[0x%02X] not match, ChipData = 0x%04X, FileData = 0x%04X\n", BinaryFormatPtr->SmbusAddress, BinaryFormatPtr->Register, ChipData, FileData);
			return RETURN_UNSUPPORTED;
		}
	} else{
		printf("Smbus read SmbusAddress[0x%02X].Offset[0x%02X] error:%r\n", BinaryFormatPtr->SmbusAddress, BinaryFormatPtr->Register, Status);
		return Status;
	}
}

EFI_STATUS
MpsSwitchPage(
	MPS_BINARY_FORMAT   *BinaryFormatPtr
){
	EFI_STATUS                 Status = EFI_SUCCESS;
	UINT8                      SmbWriteOperation, SmbReadOperation;
	UINT8                      i;
	UINTN                      DataLength;
	UINTN                      Data;
	EFI_SMBUS_DEVICE_ADDRESS   SlaveAddress;

	if(BinaryFormatPtr->Length == 1){
		SmbWriteOperation = EfiSmbusWriteByte;
		SmbReadOperation = EfiSmbusReadByte;
		DataLength = 1;
	} else if(BinaryFormatPtr->Length == 2){
		SmbWriteOperation = EfiSmbusWriteWord;
		SmbReadOperation = EfiSmbusReadWord;
		DataLength = 2;
	} else if((BinaryFormatPtr->Length & 0xF0) == 0x80){
		SmbWriteOperation = EfiSmbusWriteBlock;
		SmbReadOperation = EfiSmbusReadBlock;
		DataLength = (BinaryFormatPtr->Length & 0x0F);
	} else{
		return EFI_INVALID_PARAMETER;
	}

	SlaveAddress.SmbusDeviceAddress = BinaryFormatPtr->SmbusAddress;
	for(i = 0; i < 3; i++){
		Status = gSmbus->Execute(
			gSmbus,
			SlaveAddress,
			BinaryFormatPtr->Register,
			SmbWriteOperation,
			FALSE,
			&DataLength,
			&BinaryFormatPtr->Data);

		Status = gSmbus->Execute(
			gSmbus,
			SlaveAddress,
			BinaryFormatPtr->Register,
			SmbReadOperation,
			FALSE,
			&DataLength,
			&Data);

		if(Data == BinaryFormatPtr->Data)
			break;
	}

	return Status;
}

EFI_STATUS
MpsCmpDate(
	IN  UINT8   *RegionOffset,
	OUT UINT8   *Error
){
	EFI_STATUS          Status = EFI_SUCCESS;
	UINTN               BinaryOffset;
	MPS_BINARY_FORMAT   *BinaryFormatPtr;
	UINT16              CurrentPage = 0;

	for(BinaryOffset = 0; BinaryOffset < MPS_DATA_LENGTH; BinaryOffset += sizeof(MPS_BINARY_FORMAT)){
		BinaryFormatPtr = (MPS_BINARY_FORMAT*)(RegionOffset + BinaryOffset);

		if((BinaryFormatPtr->SmbusAddress == 0) && \
			(BinaryFormatPtr->Register == 0) && \
			(BinaryFormatPtr->Length == 0) && \
			(BinaryFormatPtr->Data == 0)){
				Status = EFI_SUCCESS;
				break;
		}

		if(BinaryFormatPtr->Register == 0){
			CurrentPage = BinaryFormatPtr->Data;
			printf("\n----- Current Page = %x ----\n", CurrentPage);
		}

		if(CurrentPage == 2){
			if(BinaryFormatPtr->Register > 0x1E){
				continue;
			}
		}

		//If register is 0, switch page and no need to compare.
		if(BinaryFormatPtr->Register == 0){
			Status = MpsSwitchPage(BinaryFormatPtr);
			if(EFI_ERROR(Status)){
				printf("Switch page %x failed\n", BinaryFormatPtr->Data);
				return Status;
			} else{
				continue;
			}
		}

		Status = MpsReadData(BinaryFormatPtr);
		if(EFI_ERROR(Status)){
			*Error = 1;
		}
	}
	return Status;
}

UINT8
CalculateRegionCount(
	IN UINTN	FileSize,
	IN UINT8	*Binary,
	IN UINT8	CpuNumbers
)
{
	UINT8 TotalRegion;
	UINT8 *RegionOffset;
	
	TotalRegion  = 0;
	RegionOffset = Binary;
	
	while(TRUE){
		if((((MPS_BINARY_FORMAT*)RegionOffset)->SmbusAddress == 0) && (((MPS_BINARY_FORMAT*)RegionOffset)->Register == 0) &&
			(((MPS_BINARY_FORMAT*)RegionOffset)->Length == 0) && (((MPS_BINARY_FORMAT*)RegionOffset)->Data == 0)) {
			break;
		}
		TotalRegion++;
		RegionOffset += MPS_DATA_LENGTH;
	}
	printf("TotalRegion : %d \n", TotalRegion);
	
	return TotalRegion / CpuNumbers;
}

EFI_STATUS
CmpMpsData(int argc, char** argv)
{
	EFI_STATUS   Status;
	FILE         *MPSROMFile;
	FILE         *TokenFile = NULL;
	UINT8        *FileBuffer;
	UINTN        FileLength;
	UINT8        SelectChannel;
	UINT8        C, R;
	UINT8        *RegionOffset = NULL;
	UINT8        CpuNumbers = 0;
	UINT8        RegionNumbers = 0;
	char         mystring[300];
	char         *pChar = NULL;
	char         *TargetStr;
	MPS_CHIP_SIG *ChipSig;
	UINT8        ErrorCnt = 0;

	Status = gBS->LocateProtocol(&gEfiSmbusHcProtocolGuid, NULL, (VOID**)&gSmbus);
	if(EFI_ERROR(Status)){
		printf("Locate SMBus Protocol : %r \n", Status);
		return Status;
	}

	Status = GetBiosInfoFromToken();
	if(EFI_ERROR(Status)) return Status;

	Status = SmbusSwitchSelect(SLOT_SWITCH_ADDRESS, 0xFF);
	Status = SmbusSwitchSelect(SECOND_SLOT_SWITCH_ADDRESS, 0xFF);
	Status = SmbusSwitchSelect(THIRD_SLOT_SWITCH_ADDRESS, 0xFF);

	TokenFile = fopen("Token.h", "r");
	if(TokenFile == NULL){
		gST->ConOut->SetAttribute(gST->ConOut, EFI_LIGHTRED);
		printf("Open Token file error!!!\n");
		return EFI_LOAD_ERROR;
	} else{
		while(fgets(mystring, 300, TokenFile) != NULL){
			TargetStr = "NUMBER_CPU_SOCKETS";
			pChar = strstr(mystring, TargetStr);
			if(pChar != NULL)
			{
				pChar = strtok (pChar, "\t");
				if(strcmp(pChar, TargetStr) != 0) continue;
				pChar = strtok (NULL, "\n");
				CpuNumbers = (UINT8)strtoul(pChar, NULL, 16);
			}
		}
		printf("NUMBER_CPU_SOCKETS: %d\n", CpuNumbers);
	}
	fclose(TokenFile);

	MPSROMFile = fopen("IRROM.bin", "rb");
	if(MPSROMFile == NULL){
		printf("Open IRROM file error!!!\n");
		return EFI_LOAD_ERROR;
	} else{
		FReadFile(MPSROMFile, &FileBuffer, &FileLength);

		//Confirm checksum of IRROM.bin
		Status = ConfirmChecksum((UINT32)FileLength, (UINT8*)FileBuffer);
		if(EFI_ERROR(Status)){
			gST->ConOut->SetAttribute(gST->ConOut, EFI_LIGHTRED);
			printf("IRROM file checksum error!!!\n");
			fclose(MPSROMFile);
			return Status;
		}

		RegionNumbers = CalculateRegionCount(FileLength, (UINT8*)FileBuffer, CpuNumbers);
		if(RegionNumbers == 0){
			gST->ConOut->SetAttribute(gST->ConOut, EFI_LIGHTRED);
			printf("IRROM file get total region fail!!!\n");
			fclose(MPSROMFile);
			return Status;
		}

		for(C = 0; C < CpuNumbers; C++){
			SelectChannel = JugdeSmbusChannel(C);
			Status = SmbusSwitchSelect(SWITCH_ADDRESS, SelectChannel);
			if(EFI_ERROR(Status)){
				gST->ConOut->SetAttribute(gST->ConOut, EFI_LIGHTRED);
				printf("MPS switch to Ch%d error\n", SelectChannel);
				fclose(MPSROMFile);
				return Status;
			}
			printf("\n============ Check CPU %x ============\n", C);

			for(R = 0; R < RegionNumbers; R++){
				printf("\n====== Region %x ======\n", R);
				RegionOffset = (UINT8*)FileBuffer + (C * RegionNumbers + R) * MPS_DATA_LENGTH;

				(MPS_CHIP_SIG*)ChipSig = (MPS_CHIP_SIG*)((UINT8*)RegionOffset + SIGNATURE_OFFSET);
				if(!((ChipSig->Name[0] == 'M') && (ChipSig->Name[1] == 'P') && (ChipSig->Name[2] == 'S') && (ChipSig->Name[3] == '2')
						&& (ChipSig->Name[4] == '9') && (ChipSig->Name[5] == '7') && (ChipSig->Name[6] == 'x'))){
					printf("MPS chip of Cpu%d Region%d signature error\n", C, R);
					continue;
				}

				Status = MpsCmpDate(RegionOffset, &ErrorCnt);
			}
		}
		if(ErrorCnt == 0){
			gST->ConOut->SetAttribute(gST->ConOut, EFI_LIGHTGREEN);
			printf("MPS check successful\n");
			gST->ConOut->SetAttribute(gST->ConOut, EFI_WHITE);
		} else{
			gST->ConOut->SetAttribute(gST->ConOut, EFI_LIGHTRED);
			printf("MPS check fail\n");
			gST->ConOut->SetAttribute(gST->ConOut, EFI_WHITE);
		}
		fclose(MPSROMFile);
	}

	return Status;
}
//[GBT_Chris_W_EGSTool_1]-

VOID
ShowHelpMsg()
{
	gST->ConOut->SetAttribute(gST->ConOut, EFI_WHITE);
	printf(CommonTitle, Title, Ver, DATE, TIME);
	printf("Commands:\n");
	printf("/hsio r     -> Read PCH HSIO setting\n");
	printf("/upi c      -> Check UPI TAP setting\n");
	printf("/upi r      -> Read UPI TAP setting\n");
	printf("/usb oc c   -> Check USB OC setting\n");
	printf("/usb oc r   -> Read USB OC setting\n");
	printf("/usb str c  -> Check USB Strength setting\n");
	printf("/usb str r  -> Read USB Strength setting\n");
	printf("/sata r     -> Read SATA and sSATA signal value\n");
	printf("/sata c     -> Check SATA and sSATA signal Solution setting\n");
	printf("/ir c [IRROM File Name] -> Check IR Power Solution setting\n");
	printf("/mps [IRROM.bin] [Token.h] -> Check MPS Power Solution setting\n");
	printf("/ti c [IRROM File Name] -> Check TI Power Solution setting\n");	//[Gbt_Chris_W0010]
	printf("/sbi r [PID] [Offset]        -> Read register via SBI\n");
	printf("/sbi w [PID] [Offset] [Data] -> Write register via SBI\n");
	printf("/spd r      -> Read SPD data and analysis\n");
	printf("/spd d      -> Dump all SPD data\n");
	printf("/spd c      -> Check SPD \n");	
	printf("/PcieErr r  -> Read PCIe Root Port error setting\n");
	printf("/PcieErr c  -> Check PCIe Root Port error setting\n");
}

EFI_STATUS
Arg_owner_Function(int argc, char** argv)
{
	gST->ConOut->SetAttribute(gST->ConOut, EFI_WHITE);
	printf("Programmer: Jonas.Hsu / Gigabyte Server BIOS Team \n");
	return EFI_SUCCESS;
}

EFI_STATUS
Arg_upi_Function(int argc, char** argv)
{
// [GBT_Deann_W0046] +
	EFI_STATUS	Status;
	UINT8		Flag = 0; //Flag for not support UPI test and return success.

	if(strcasecmp(argv[2], "r") == 0){
		gDump = 1;
		Status = GetUpiDataFromRegister();
		return Status;
	}
	else if(strcasecmp(argv[2], "c") == 0){
		Status = GetUpiDataFromRegister();
		if(EFI_ERROR(Status)) return Status;
		Status = GetUpiDataFromFile(&Flag);
		if(Flag) return EFI_SUCCESS;
		if(EFI_ERROR(Status)) return Status;
		Status = CmpUpiData();
		return Status;
	}
	
	gST->ConOut->SetAttribute(gST->ConOut, EFI_LIGHTRED);
	printf("Invalid Parameter, please reference help\n");
	return EFI_INVALID_PARAMETER;
// [GBT_Deann_W0046] -
}

EFI_STATUS
Arg_usb_Function(int argc, char** argv)
{
// [GBT_Deann_W0046] +
	EFI_STATUS	Status;

	if(strcasecmp(argv[2], "oc") == 0){
		if(strcasecmp(argv[3], "r") == 0){
			gDump = 1;
			Status = GetUsbOcDataFromRegister();
			return Status;
		}
		else if(strcasecmp(argv[3], "c") == 0){
			Status = GetUsbOcDataFromRegister();
			if(EFI_ERROR(Status)) return Status;
			Status = GetUsbOcDataFromFile();
			if(EFI_ERROR(Status)) return Status;
			Status = CmpUsbOcData();
			return Status;
		}
	}
	else if(strcasecmp(argv[2], "str") == 0){
		if(strcasecmp(argv[3], "r") == 0){
			gDump = 1;
			Status = GetUsbStrDataFromRegister();
			return Status;
		}
		else if(strcasecmp(argv[3], "c") == 0){
			Status = GetUsbStrDataFromRegister();
			if(EFI_ERROR(Status)) return Status;
			Status = GetUsbStrDataFromFile();
			if(EFI_ERROR(Status)) return Status;
			Status = CmpUsbStrData();
			return Status;
		}
	}

	gST->ConOut->SetAttribute(gST->ConOut, EFI_LIGHTRED);
	printf("Invalid Parameter, please reference help\n");
	return EFI_INVALID_PARAMETER;
// [GBT_Deann_W0046] -
}

EFI_STATUS
Arg_hsio_Function(int argc, char** argv)
{
	EFI_STATUS	Status;

	if(strcasecmp(argv[2], "r") == 0){
		gDump = 1;
		Status = GetLaneOwnerStatusRegister();
		return Status;
	}

	gST->ConOut->SetAttribute(gST->ConOut, EFI_LIGHTRED);
	printf("Invalid Parameter, please reference help\n");
	return EFI_INVALID_PARAMETER;
}

EFI_STATUS
Arg_ir_Function(int argc, char** argv)
{
	EFI_STATUS	Status = EFI_SUCCESS;
	
	return Status;
}

EFI_STATUS
Arg_mps_Function(int argc, char** argv)
{
	EFI_STATUS	Status;

	Status = CmpMpsData(argc, argv);
	printf("CmpMpsData: %r\n", Status);
	return Status;
}

EFI_STATUS
Arg_ti_Function(int argc, char** argv)
{
	EFI_STATUS	Status = EFI_SUCCESS;
	
	return Status;
}

EFI_STATUS
Arg_sbi_Function(int argc, char** argv)
{
	EFI_STATUS	Status;
	UINT8	PID;
	UINT16	Offset;
	UINT32	Value32;
	UINT8	Response;

	if(strcasecmp(argv[2], "r") == 0){
		PID = (UINT8)strtol(argv[3], NULL, 16);
		Offset = (UINT16)strtol(argv[4], NULL, 16);;
		Value32 = 0;
		Status = PchSbiExecution(
			PID,		//PID_USB2
			Offset,
			PrivateControlRead,
			FALSE,
			&Value32,
			&Response);
		if(Status == EFI_WRITE_PROTECTED){
			gST->ConOut->SetAttribute(gST->ConOut, EFI_LIGHTRED);
			printf("ERROR: Please Unlock SBI in BIOS setup\n");
			return Status;
		}

		printf("SBI Read PID:0x%02X Offset:0x%04X = 0x%08X\n", PID, Offset, Value32);
	}
	else if(strcasecmp(argv[2], "w") == 0){
		PID = (UINT8)strtol(argv[3], NULL, 16);
		Offset = (UINT16)strtol(argv[4], NULL, 16);
		Value32 = (UINT32)strtoull(argv[5], NULL, 16);
		Status = PchSbiExecution(
			PID,		//PID_USB2
			Offset,
			PrivateControlWrite,
			TRUE,
			&Value32,
			&Response);
		if(Status == EFI_WRITE_PROTECTED){
			gST->ConOut->SetAttribute(gST->ConOut, EFI_LIGHTRED);
			printf("ERROR: Please Unlock SBI in BIOS setup\n");
			return Status;
		}

		printf("SBI Write PID:0x%02X Offset:0x%04X = 0x%08X\n", PID, Offset, Value32);
	}

	gST->ConOut->SetAttribute(gST->ConOut, EFI_LIGHTRED);
	printf("Invalid Parameter, please reference help\n");
	return EFI_INVALID_PARAMETER;
}

EFI_STATUS
Arg_spd_Function(int argc, char** argv)
{
	EFI_STATUS	Status;

	if(strcasecmp(argv[2], "r") == 0)
	{
		Status = Spd_R_Function();
		return Status;
	}
	else if(strcasecmp(argv[2], "d") == 0)
	{
		Status = Spd_D_Function();

		return Status;
	}
	else if(strcasecmp(argv[2], "c") == 0)
	{
		Status = Spd_C_Function();
		if(Status != EFI_SUCCESS)
		{
			printf("Device error\n");
			return Status;
		}
		return Status;
	}

	gST->ConOut->SetAttribute(gST->ConOut, EFI_LIGHTRED);
	printf("Invalid Parameter, please reference help\n");
	return EFI_INVALID_PARAMETER;
}

EFI_STATUS
Arg_sata_Function(int argc, char** argv)
{
	EFI_STATUS	Status;
	if(strcasecmp(argv[2], "c") == 0){
		Status = CmpSataData(argc, argv);
		return Status;
	}else if(strcasecmp(argv[2], "r") == 0){
		Status = ReadSatsData(argc, argv);
		return Status;
	}

	gST->ConOut->SetAttribute(gST->ConOut, EFI_LIGHTRED);
	printf("Invalid Parameter, please reference help\n");
	return EFI_INVALID_PARAMETER;
}

EFI_STATUS
Arg_pcieerr_Function(int argc, char** argv)
{
	EFI_STATUS	Status = EFI_SUCCESS;

	if((strcasecmp(argv[2], "c") == 0) | (strcasecmp(argv[2], "r") == 0)){
		Status = PcieErrScan(argc, argv);
		return Status;
	}

	gST->ConOut->SetAttribute(gST->ConOut, EFI_LIGHTRED);
	printf("Invalid Parameter, please reference help\n");
// [GBT_Deann_W0028] +	
	gST->ConOut->SetAttribute(gST->ConOut, EFI_WHITE);
// [GBT_Deann_W0028] -	
	return EFI_INVALID_PARAMETER;
}


ARG_INPUT_LIST ArgInputList[] = {
	{"/hsio", 2, Arg_hsio_Function},
	{"/upi", 2, Arg_upi_Function},
	{"/usb", 3, Arg_usb_Function},
	{"/ir", 3, Arg_ir_Function},
	{"/mps", 3, Arg_mps_Function},
	{"/ti", 3, Arg_ti_Function},  //[Gbt_Chris_W0010] Add TI VR program check function.
	{"/sbi", 4, Arg_sbi_Function},
	{"/spd", 2, Arg_spd_Function},
	{"/sata", 2, Arg_sata_Function},
	{"/pcieerr", 2, Arg_pcieerr_Function},
	{"/owner", 1, Arg_owner_Function}
};

int main(int argc, char* argv[])
{
	EFI_STATUS	ReturnStatus = EFI_INVALID_PARAMETER;
	UINT32	i;

	// Check input Arg[1] strings
	for(i = 0; i < sizeof(ArgInputList)/sizeof(ArgInputList[0]); i++){
		if(strcasecmp(argv[1], ArgInputList[i].ArgStr) == 0){
//			printf("Find match Arg[1] string : %s \n", ArgInputList[i].ArgStr);
			if((argc-1) >= ArgInputList[i].ArgNumNeed){
//				printf("Argc number match : %d, execute target function \n", ArgInputList[i].ArgNumNeed);
				ReturnStatus = ArgInputList[i].func(argc, argv);
				break;
			}else{
				gST->ConOut->SetAttribute(gST->ConOut, EFI_LIGHTRED);
				printf("Number of Input Arg wrong \n");
				printf("Enter %d parameter, but should more than %d \n", argc-1, ArgInputList[i].ArgNumNeed);
				return EFI_INVALID_PARAMETER;
			}
		}
	}

	// Status error, display help message
	if(ReturnStatus != EFI_SUCCESS){
		ShowHelpMsg();
		return ReturnStatus;
	}

	return ReturnStatus;
}

