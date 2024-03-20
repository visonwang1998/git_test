#define SPD                             1
//
// Definitions for use with SMB_ADDRESS_STRUCT controller member,
// Enumerated Platform SMBUS controllers
//
#define PLATFORM_SMBUS_CONTROLLER_PROCESSOR   0
#define PLATFORM_SMBUS_CONTROLLER_PCH         1
//
// DDR5 specific 4-bit DTI(SPD5 Device Type ID) / LID(Local Device Type ID) Code
//
#define DDR5_TS0            0x02  // '0010' specifies TS0
#define DDR5_TS1            0x06  // '0110' specifies TS1
#define DTI_PMIC            0x09  // '1001' specifies PMIC
#define DTI_EEPROM          0x0A  // '1010' specifies EEPROM's
#define DTI_RCD_FMC         0x0B  // '1011' specifies RCD or NVMCTLR device

#define COMMAND_QUEUE_PORT_SB_I3C0_REG 0x2A0280C0
#define INTR_STATUS_SB_I3C0_REG 0x2A028020
#define DATA_PORT_SB_I3C0_REG 0x2A0280C8
#define RESPONSE_QUEUE_PORT_SB_I3C0_REG 0x2A0280C4

#define ALIAS_DATA_PORT_SB_I3C0_REG DATA_PORT_SB_I3C0_REG

CHAR8 *DimmList[] =
{
	"DIMM_P0_A0", "DIMM_P0_A1",
	"DIMM_P0_B0", "DIMM_P0_B1",
	"DIMM_P0_C0", "DIMM_P0_C1",
	"DIMM_P0_D0", "DIMM_P0_D1",
	"DIMM_P0_E0", "DIMM_P0_E1",
	"DIMM_P0_F0", "DIMM_P0_F1",
	"DIMM_P0_G0", "DIMM_P0_G1",
	"DIMM_P0_H0", "DIMM_P0_H1",
	"DIMM_P1_I0", "DIMM_P1_I1",
	"DIMM_P1_J0", "DIMM_P1_J1",
	"DIMM_P1_K0", "DIMM_P1_K1",
  "DIMM_P1_L0", "DIMM_P1_L1",
  "DIMM_P1_M0", "DIMM_P1_M1",
  "DIMM_P1_N0", "DIMM_P1_N1",
  "DIMM_P1_O0", "DIMM_P1_O1",
	"DIMM_P1_P0", "DIMM_P1_P1"
};

///
/// SM Bus Address Data Structure.
//
typedef struct smbAddress {
  ///
  /// Reserved bit.
  //
  UINT16   rsvd:1;
  ///
  /// SM Bus slave address (0...7).
  //
  UINT16   strapAddress:3;

  ///
  /// @brief
  /// SM Bus device type.<BR>
  /// @details
  ///   0x03 = TSOD.<BR>
  ///   0x06 = write-protect operation for an EEPROM.<BR>
  ///   0x0B = LRDIMM buffer.<BR>
  ///   0x05 = DCP_FIVE  DDR3 Vref control on the reference platform.<BR>
  ///   0x07 = DCP_SEVEN, an alternate for Vref control.<BR>
  ///   0x0A = EEPROM.<BR>
  ///   0x0B = NVMCTLR device.<BR>
  //
  UINT16   deviceType:4;
  ///
  /// SMBus Instance.
  //
  UINT16   SmbInstance:4;
  ///
  /// @brief
  /// SM Bus controller location.<BR>
  /// @details
  ///   0 = Processor.<BR>
  ///   1 = PCH.<BR>
  //
  UINT16   controller:1;

  ///
  /// Socket on which the SM Bus controller resides
  //
  UINT16    SmbSocket:3;
} SMB_ADDRESS_STRUCT;

typedef struct smbDevice {
  ///
  /// @brief
  /// Component ID.<BR>
  /// @details
  ///   1 = SPD.<BR>
  ///   2 = DCP_ISL9072X.<BR>
  ///   3 = DCP_AD5247.<BR>
  ///   4 = MTS.<BR>
  ///   5 = RSTPLD.<BR>
  ///   6 = NO_DEV.<BR>
  //
  UINT16              compId;
  ///
  /// Memory Controller ID.
  //
  UINT8               mcId;
  ///
  /// SM Bus device address.
  //
  SMB_ADDRESS_STRUCT  address;
  ///
  /// SPD Page Number.
  //
  UINT8               SpdPage;
} SMB_DEVICE_STRUCT;

//Copy from Intel\ServerSiliconPkg\Library\ProcSmbIpLib\Include\Registers\Spr\SB_I3C0.h
typedef union {
  ///
  /// Individual bit fields
  ///
  struct {
    UINT32 data_length : 16;
                            /* Bits[15:0], Access Type=RO, default=0x00000000*/
                            /*  */
    UINT32 reserved_16_23 : 8;
                            /* Bits[23:16], Access Type=RO, default=0x00000000*/
                            /*  */
    UINT32 tid : 4;
                            /* Bits[27:24], Access Type=RO, default=0x00000000*/
                            /*  */
    UINT32 err_status : 4;
                            /* Bits[31:28], Access Type=RO, default=0x00000000*/
                            /*  */
  } Bits;
  UINT32 Data;
} RESPONSE_QUEUE_PORT_SB_I3C0_STRUCT;

typedef union {
  ///
  /// Individual bit fields
  ///
  struct {
    UINT32 version : 32;
                            /* Bits[31:0], Access Type=RO, default=0x00000052*/
                            /*  */
  } Bits;
  UINT32 Data;
} HCI_VERSION_SB_I3C1_STRUCT;

typedef union {
  ///
  /// Individual bit fields
  ///
  struct {
    UINT32 command : 32;

                            /* Bits[31:0], Access Type=WO, default=0x00000000*/

                            /*  */
  } Bits;
  UINT32 Data;

} COMMAND_QUEUE_PORT_SB_I3C0_STRUCT;

///
/// Common struct for TX_DATA_PORT
/// For SPR the reg struct is DATA_PORT_SB_I3CX_STRUCT
/// FOR GNRSRF the reg struct is TX_DATA_PORT_SB_I3CX_STRUCT
///
typedef union {
  ///
  /// Individual bit fields
  ///
  struct {
    UINT32 data_port : 32;

    /* Bits[31:0], Access Type=WO, default=0x00000000*/

    /*  */

} Bits;
  UINT32 Data;

} ALIAS_DATA_PORT_SB_I3C0_STRUCT;

typedef union {
  ///
  /// Individual bit fields
  ///
  struct {
    UINT32 tx_thld_stat : 1;

                            /* Bits[0:0], Access Type=RO, default=0x00000000*/

                            /*  */
    UINT32 rx_thld_stat : 1;

                            /* Bits[1:1], Access Type=RO, default=0x00000000*/

                            /*  */
    UINT32 ibi_status_thld_stat : 1;

                            /* Bits[2:2], Access Type=RO, default=0x00000000*/

                            /*  */
    UINT32 cmd_queue_ready_stat : 1;

                            /* Bits[3:3], Access Type=RO, default=0x00000000*/

                            /*  */
    UINT32 resp_ready_stat : 1;

                            /* Bits[4:4], Access Type=RO, default=0x00000000*/

                            /*  */
    UINT32 transfer_abort_stat : 1;

                            /* Bits[5:5], Access Type=RW/1C, default=0x00000000*/

                            /*  */
    UINT32 reserved_6_8 : 3;

                            /* Bits[8:6], Access Type=RO, default=0x00000000*/

                            /*  */
    UINT32 transfer_err_stat : 1;

                            /* Bits[9:9], Access Type=RW/1C, default=0x00000000*/

                            /*  */
    UINT32 hc_internal_err_stat : 1;

                            /* Bits[10:10], Access Type=RW/1C, default=0x00000000*/

                            /*  */
    UINT32 reserved_11_13 : 3;

                            /* Bits[13:11], Access Type=RO, default=0x00000000*/

                            /*  */
    UINT32 ppoll_cmd_miss_stat : 1;

                            /* Bits[14:14], Access Type=RW/1C, default=0x00000000*/

                            /*  */
    UINT32 bus_reset_done_stat : 1;

                            /* Bits[15:15], Access Type=RW/1C, default=0x00000000*/

                            /*  */
    UINT32 reserved_16_31 : 16;

                            /* Bits[31:16], Access Type=RO, default=0x00000000*/

                            /*  */

  } Bits;
  UINT32 Data;

} INTR_STATUS_SB_I3C0_STRUCT;