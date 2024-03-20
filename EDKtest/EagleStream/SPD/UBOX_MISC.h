
/** @file
  UBOX_MISC.h

  @copyright
  INTEL CONFIDENTIAL
  Copyright 2007 - 2021 Intel Corporation. <BR>
  
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
  
  This file contains Silicon register definitions.
  
  This is a generated file; please do not modify it directly.
  
**/

/* The following security policy groups are used by registers in this file:     */

/* SPRA0 Security Policy Groups:                                                */
/* LB_MCHECK_W                                                                  */
/*  Security_ReadAccess_Str:                                                    */
/*    HOSTIA_POSTBOOT_SAI | HOSTIA_UCODE_SAI | HOSTIA_SMM_SAI |                 */
/*    HOSTIA_SUNPASS_SAI | HOSTIA_BOOT_SAI | SAI_Reserved_5 | SAI_Reserved_6 |  */
/*    SAI_Reserved_7 | GT_SAI | PM_PCS_SAI | HW_CPU_SAI | MEM_CPL_SAI | VTD_SAI */
/*    | PM_DIE_TO_DIE_SAI | OOB_MSM_UNTRUSTED_SAI | HOSTCP_PMA_SAI |            */
/*    CSE_INTEL_SAI | CSE_OEM_SAI | FUSE_CTRL_SAI | FUSE_PULLER_SAI |           */
/*    PECI_MSM_SAI | PM_IOSS_SAI | CSE_DNX_SAI | FXR_INTERNAL_SAI |             */
/*    DFX_INTEL_MANUFACTURING_SAI | DFX_UNTRUSTED_SAI | SAI_Reserved_26 |       */
/*    IRC_SAI | NPK_SAI | DISPLAY2_SAI | DISPLAY3_SAI | HW_PCH_SAI |            */
/*    SAI_Reserved_32 | SAI_Reserved_33 | SAI_Reserved_34 | GT_PMA_SAI |        */
/*    HSP_SAI | SAI_Reserved_37 | SAI_Reserved_38 | SAI_Reserved_39 |           */
/*    UNCORE_PMA_SAI | RC_MORPHED_SAI | DFX_INTEL_PRODUCTION_SAI |              */
/*    DFX_THIRDPARTY_SAI | DISPLAY_SAI | SAI_Reserved_45 | SAI_Reserved_46 |    */
/*    DISPLAY_KVM_SAI | GT2_SAI | SAI_Reserved_49 | DEVICE_UNTRUSTED_IAL_SAI |  */
/*    SAI_Reserved_51 | CORE_EVENT_PROXY_SAI | DEVICE_ABORT_SAI |               */
/*    RCIOMMU_BYPASS_SAI | SAI_Reserved_55 | SAI_Reserved_56 | IE_CSE_SAI |     */
/*    SAI_Reserved_58 | SAI_Reserved_59 | CPM_SAI | OOB_MSM_SAI | XGBE_SAI |    */
/*    DEVICE_UNTRUSTED_SAI                                                      */
/*  Security_WriteAccess_Str:                                                   */
/*    HOSTIA_UCODE_SAI | HOSTIA_SUNPASS_SAI | PM_PCS_SAI |                      */
/*    DFX_INTEL_MANUFACTURING_SAI | DFX_INTEL_PRODUCTION_SAI | HOSTIA_BOOT_SAI  */
/*    | HOSTIA_SMM_SAI | OOB_MSM_SAI                                            */
/*  Security_Read_CP_Secured:                                                   */
/*    0                                                                         */
/* LB_W                                                                         */
/*  Security_ReadAccess_Str:                                                    */
/*    HOSTIA_POSTBOOT_SAI | HOSTIA_UCODE_SAI | HOSTIA_SMM_SAI |                 */
/*    HOSTIA_SUNPASS_SAI | HOSTIA_BOOT_SAI | SAI_Reserved_5 | SAI_Reserved_6 |  */
/*    SAI_Reserved_7 | GT_SAI | PM_PCS_SAI | HW_CPU_SAI | MEM_CPL_SAI | VTD_SAI */
/*    | PM_DIE_TO_DIE_SAI | OOB_MSM_UNTRUSTED_SAI | HOSTCP_PMA_SAI |            */
/*    CSE_INTEL_SAI | CSE_OEM_SAI | FUSE_CTRL_SAI | FUSE_PULLER_SAI |           */
/*    PECI_MSM_SAI | PM_IOSS_SAI | CSE_DNX_SAI | FXR_INTERNAL_SAI |             */
/*    DFX_INTEL_MANUFACTURING_SAI | DFX_UNTRUSTED_SAI | SAI_Reserved_26 |       */
/*    IRC_SAI | NPK_SAI | DISPLAY2_SAI | DISPLAY3_SAI | HW_PCH_SAI |            */
/*    SAI_Reserved_32 | SAI_Reserved_33 | SAI_Reserved_34 | GT_PMA_SAI |        */
/*    HSP_SAI | SAI_Reserved_37 | SAI_Reserved_38 | SAI_Reserved_39 |           */
/*    UNCORE_PMA_SAI | RC_MORPHED_SAI | DFX_INTEL_PRODUCTION_SAI |              */
/*    DFX_THIRDPARTY_SAI | DISPLAY_SAI | SAI_Reserved_45 | SAI_Reserved_46 |    */
/*    DISPLAY_KVM_SAI | GT2_SAI | SAI_Reserved_49 | DEVICE_UNTRUSTED_IAL_SAI |  */
/*    SAI_Reserved_51 | CORE_EVENT_PROXY_SAI | DEVICE_ABORT_SAI |               */
/*    RCIOMMU_BYPASS_SAI | SAI_Reserved_55 | SAI_Reserved_56 | IE_CSE_SAI |     */
/*    SAI_Reserved_58 | SAI_Reserved_59 | CPM_SAI | OOB_MSM_SAI | XGBE_SAI |    */
/*    DEVICE_UNTRUSTED_SAI                                                      */
/*  Security_WriteAccess_Str:                                                   */
/*    HOSTIA_UCODE_SAI | HOSTIA_SUNPASS_SAI | PM_PCS_SAI |                      */
/*    DFX_INTEL_MANUFACTURING_SAI | DFX_INTEL_PRODUCTION_SAI | HOSTIA_BOOT_SAI  */
/*    | HOSTIA_SMM_SAI | OOB_MSM_SAI                                            */
/*  Security_Read_CP_Secured:                                                   */
/*    0                                                                         */
/* OS_W                                                                         */
/*  Security_ReadAccess_Str:                                                    */
/*    HOSTIA_POSTBOOT_SAI | HOSTIA_UCODE_SAI | HOSTIA_SMM_SAI |                 */
/*    HOSTIA_SUNPASS_SAI | HOSTIA_BOOT_SAI | SAI_Reserved_5 | SAI_Reserved_6 |  */
/*    SAI_Reserved_7 | GT_SAI | PM_PCS_SAI | HW_CPU_SAI | MEM_CPL_SAI | VTD_SAI */
/*    | PM_DIE_TO_DIE_SAI | OOB_MSM_UNTRUSTED_SAI | HOSTCP_PMA_SAI |            */
/*    CSE_INTEL_SAI | CSE_OEM_SAI | FUSE_CTRL_SAI | FUSE_PULLER_SAI |           */
/*    PECI_MSM_SAI | PM_IOSS_SAI | CSE_DNX_SAI | FXR_INTERNAL_SAI |             */
/*    DFX_INTEL_MANUFACTURING_SAI | DFX_UNTRUSTED_SAI | SAI_Reserved_26 |       */
/*    IRC_SAI | NPK_SAI | DISPLAY2_SAI | DISPLAY3_SAI | HW_PCH_SAI |            */
/*    SAI_Reserved_32 | SAI_Reserved_33 | SAI_Reserved_34 | GT_PMA_SAI |        */
/*    HSP_SAI | SAI_Reserved_37 | SAI_Reserved_38 | SAI_Reserved_39 |           */
/*    UNCORE_PMA_SAI | RC_MORPHED_SAI | DFX_INTEL_PRODUCTION_SAI |              */
/*    DFX_THIRDPARTY_SAI | DISPLAY_SAI | SAI_Reserved_45 | SAI_Reserved_46 |    */
/*    DISPLAY_KVM_SAI | GT2_SAI | SAI_Reserved_49 | DEVICE_UNTRUSTED_IAL_SAI |  */
/*    SAI_Reserved_51 | CORE_EVENT_PROXY_SAI | DEVICE_ABORT_SAI |               */
/*    RCIOMMU_BYPASS_SAI | SAI_Reserved_55 | SAI_Reserved_56 | IE_CSE_SAI |     */
/*    SAI_Reserved_58 | SAI_Reserved_59 | CPM_SAI | OOB_MSM_SAI | XGBE_SAI |    */
/*    DEVICE_UNTRUSTED_SAI                                                      */
/*  Security_WriteAccess_Str:                                                   */
/*    HOSTIA_POSTBOOT_SAI | HOSTIA_UCODE_SAI | HOSTIA_SMM_SAI |                 */
/*    HOSTIA_SUNPASS_SAI | HOSTIA_BOOT_SAI | PM_PCS_SAI |                       */
/*    DFX_INTEL_MANUFACTURING_SAI | DFX_INTEL_PRODUCTION_SAI |                  */
/*    DFX_UNTRUSTED_SAI | OOB_MSM_SAI | DFX_THIRDPARTY_SAI                      */
/*  Security_Read_CP_Secured:                                                   */
/*    0                                                                         */
/* P_U_CODE                                                                     */
/*  Security_ReadAccess_Str:                                                    */
/*    HOSTIA_UCODE_SAI | HOSTIA_SUNPASS_SAI | PM_PCS_SAI |                      */
/*    DFX_INTEL_MANUFACTURING_SAI | DFX_INTEL_PRODUCTION_SAI | UNCORE_PMA_SAI | */
/*    OOB_MSM_SAI                                                               */
/*  Security_WriteAccess_Str:                                                   */
/*    HOSTIA_UCODE_SAI | HOSTIA_SUNPASS_SAI | PM_PCS_SAI |                      */
/*    DFX_INTEL_MANUFACTURING_SAI | DFX_INTEL_PRODUCTION_SAI                    */
/*  Security_Read_CP_Secured:                                                   */
/*    0                                                                         */

/* SPRB0 Security Policy Groups:                                                */
/* LB_MCHECK_W                                                                  */
/*  Security_ReadAccess_Str:                                                    */
/*    HOSTIA_POSTBOOT_SAI | HOSTIA_UCODE_SAI | HOSTIA_SMM_SAI |                 */
/*    HOSTIA_SUNPASS_SAI | HOSTIA_BOOT_SAI | SAI_Reserved_5 | SAI_Reserved_6 |  */
/*    SAI_Reserved_7 | GT_SAI | PM_PCS_SAI | HW_CPU_SAI | MEM_CPL_SAI | VTD_SAI */
/*    | PM_DIE_TO_DIE_SAI | OOB_MSM_UNTRUSTED_SAI | HOSTCP_PMA_SAI |            */
/*    CSE_INTEL_SAI | CSE_OEM_SAI | FUSE_CTRL_SAI | FUSE_PULLER_SAI |           */
/*    PECI_MSM_SAI | PM_IOSS_SAI | CSE_DNX_SAI | FXR_INTERNAL_SAI |             */
/*    DFX_INTEL_MANUFACTURING_SAI | DFX_UNTRUSTED_SAI | SAI_Reserved_26 |       */
/*    IRC_SAI | NPK_SAI | DISPLAY2_SAI | DISPLAY3_SAI | HW_PCH_SAI |            */
/*    SAI_Reserved_32 | SAI_Reserved_33 | SAI_Reserved_34 | GT_PMA_SAI |        */
/*    HSP_SAI | SAI_Reserved_37 | SAI_Reserved_38 | SAI_Reserved_39 |           */
/*    UNCORE_PMA_SAI | RC_MORPHED_SAI | DFX_INTEL_PRODUCTION_SAI |              */
/*    DFX_THIRDPARTY_SAI | DISPLAY_SAI | SAI_Reserved_45 | SAI_Reserved_46 |    */
/*    DISPLAY_KVM_SAI | GT2_SAI | SAI_Reserved_49 | DEVICE_UNTRUSTED_IAL_SAI |  */
/*    SAI_Reserved_51 | CORE_EVENT_PROXY_SAI | DEVICE_ABORT_SAI |               */
/*    RCIOMMU_BYPASS_SAI | SAI_Reserved_55 | SAI_Reserved_56 | IE_CSE_SAI |     */
/*    SAI_Reserved_58 | SAI_Reserved_59 | CPM_SAI | OOB_MSM_SAI | XGBE_SAI |    */
/*    DEVICE_UNTRUSTED_SAI                                                      */
/*  Security_WriteAccess_Str:                                                   */
/*    HOSTIA_UCODE_SAI | HOSTIA_SUNPASS_SAI | PM_PCS_SAI |                      */
/*    DFX_INTEL_MANUFACTURING_SAI | DFX_INTEL_PRODUCTION_SAI | HOSTIA_BOOT_SAI  */
/*    | HOSTIA_SMM_SAI | OOB_MSM_SAI                                            */
/*  Security_Read_CP_Secured:                                                   */
/*    0                                                                         */
/* LB_W                                                                         */
/*  Security_ReadAccess_Str:                                                    */
/*    HOSTIA_POSTBOOT_SAI | HOSTIA_UCODE_SAI | HOSTIA_SMM_SAI |                 */
/*    HOSTIA_SUNPASS_SAI | HOSTIA_BOOT_SAI | SAI_Reserved_5 | SAI_Reserved_6 |  */
/*    SAI_Reserved_7 | GT_SAI | PM_PCS_SAI | HW_CPU_SAI | MEM_CPL_SAI | VTD_SAI */
/*    | PM_DIE_TO_DIE_SAI | OOB_MSM_UNTRUSTED_SAI | HOSTCP_PMA_SAI |            */
/*    CSE_INTEL_SAI | CSE_OEM_SAI | FUSE_CTRL_SAI | FUSE_PULLER_SAI |           */
/*    PECI_MSM_SAI | PM_IOSS_SAI | CSE_DNX_SAI | FXR_INTERNAL_SAI |             */
/*    DFX_INTEL_MANUFACTURING_SAI | DFX_UNTRUSTED_SAI | SAI_Reserved_26 |       */
/*    IRC_SAI | NPK_SAI | DISPLAY2_SAI | DISPLAY3_SAI | HW_PCH_SAI |            */
/*    SAI_Reserved_32 | SAI_Reserved_33 | SAI_Reserved_34 | GT_PMA_SAI |        */
/*    HSP_SAI | SAI_Reserved_37 | SAI_Reserved_38 | SAI_Reserved_39 |           */
/*    UNCORE_PMA_SAI | RC_MORPHED_SAI | DFX_INTEL_PRODUCTION_SAI |              */
/*    DFX_THIRDPARTY_SAI | DISPLAY_SAI | SAI_Reserved_45 | SAI_Reserved_46 |    */
/*    DISPLAY_KVM_SAI | GT2_SAI | SAI_Reserved_49 | DEVICE_UNTRUSTED_IAL_SAI |  */
/*    SAI_Reserved_51 | CORE_EVENT_PROXY_SAI | DEVICE_ABORT_SAI |               */
/*    RCIOMMU_BYPASS_SAI | SAI_Reserved_55 | SAI_Reserved_56 | IE_CSE_SAI |     */
/*    SAI_Reserved_58 | SAI_Reserved_59 | CPM_SAI | OOB_MSM_SAI | XGBE_SAI |    */
/*    DEVICE_UNTRUSTED_SAI                                                      */
/*  Security_WriteAccess_Str:                                                   */
/*    HOSTIA_UCODE_SAI | HOSTIA_SUNPASS_SAI | PM_PCS_SAI |                      */
/*    DFX_INTEL_MANUFACTURING_SAI | DFX_INTEL_PRODUCTION_SAI | HOSTIA_BOOT_SAI  */
/*    | HOSTIA_SMM_SAI | OOB_MSM_SAI                                            */
/*  Security_Read_CP_Secured:                                                   */
/*    0                                                                         */
/* OS_W                                                                         */
/*  Security_ReadAccess_Str:                                                    */
/*    HOSTIA_POSTBOOT_SAI | HOSTIA_UCODE_SAI | HOSTIA_SMM_SAI |                 */
/*    HOSTIA_SUNPASS_SAI | HOSTIA_BOOT_SAI | SAI_Reserved_5 | SAI_Reserved_6 |  */
/*    SAI_Reserved_7 | GT_SAI | PM_PCS_SAI | HW_CPU_SAI | MEM_CPL_SAI | VTD_SAI */
/*    | PM_DIE_TO_DIE_SAI | OOB_MSM_UNTRUSTED_SAI | HOSTCP_PMA_SAI |            */
/*    CSE_INTEL_SAI | CSE_OEM_SAI | FUSE_CTRL_SAI | FUSE_PULLER_SAI |           */
/*    PECI_MSM_SAI | PM_IOSS_SAI | CSE_DNX_SAI | FXR_INTERNAL_SAI |             */
/*    DFX_INTEL_MANUFACTURING_SAI | DFX_UNTRUSTED_SAI | SAI_Reserved_26 |       */
/*    IRC_SAI | NPK_SAI | DISPLAY2_SAI | DISPLAY3_SAI | HW_PCH_SAI |            */
/*    SAI_Reserved_32 | SAI_Reserved_33 | SAI_Reserved_34 | GT_PMA_SAI |        */
/*    HSP_SAI | SAI_Reserved_37 | SAI_Reserved_38 | SAI_Reserved_39 |           */
/*    UNCORE_PMA_SAI | RC_MORPHED_SAI | DFX_INTEL_PRODUCTION_SAI |              */
/*    DFX_THIRDPARTY_SAI | DISPLAY_SAI | SAI_Reserved_45 | SAI_Reserved_46 |    */
/*    DISPLAY_KVM_SAI | GT2_SAI | SAI_Reserved_49 | DEVICE_UNTRUSTED_IAL_SAI |  */
/*    SAI_Reserved_51 | CORE_EVENT_PROXY_SAI | DEVICE_ABORT_SAI |               */
/*    RCIOMMU_BYPASS_SAI | SAI_Reserved_55 | SAI_Reserved_56 | IE_CSE_SAI |     */
/*    SAI_Reserved_58 | SAI_Reserved_59 | CPM_SAI | OOB_MSM_SAI | XGBE_SAI |    */
/*    DEVICE_UNTRUSTED_SAI                                                      */
/*  Security_WriteAccess_Str:                                                   */
/*    HOSTIA_POSTBOOT_SAI | HOSTIA_UCODE_SAI | HOSTIA_SMM_SAI |                 */
/*    HOSTIA_SUNPASS_SAI | HOSTIA_BOOT_SAI | PM_PCS_SAI |                       */
/*    DFX_INTEL_MANUFACTURING_SAI | DFX_INTEL_PRODUCTION_SAI |                  */
/*    DFX_UNTRUSTED_SAI | OOB_MSM_SAI | DFX_THIRDPARTY_SAI                      */
/*  Security_Read_CP_Secured:                                                   */
/*    0                                                                         */
/* P_U_CODE                                                                     */
/*  Security_ReadAccess_Str:                                                    */
/*    HOSTIA_UCODE_SAI | HOSTIA_SUNPASS_SAI | PM_PCS_SAI |                      */
/*    DFX_INTEL_MANUFACTURING_SAI | DFX_INTEL_PRODUCTION_SAI | UNCORE_PMA_SAI | */
/*    OOB_MSM_SAI                                                               */
/*  Security_WriteAccess_Str:                                                   */
/*    HOSTIA_UCODE_SAI | HOSTIA_SUNPASS_SAI | PM_PCS_SAI |                      */
/*    DFX_INTEL_MANUFACTURING_SAI | DFX_INTEL_PRODUCTION_SAI                    */
/*  Security_Read_CP_Secured:                                                   */
/*    0                                                                         */

/* SPRHBMA0 Security Policy Groups:                                             */
/* LB_MCHECK_W                                                                  */
/*  Security_ReadAccess_Str:                                                    */
/*    HOSTIA_POSTBOOT_SAI | HOSTIA_UCODE_SAI | HOSTIA_SMM_SAI |                 */
/*    HOSTIA_SUNPASS_SAI | HOSTIA_BOOT_SAI | SAI_Reserved_5 | SAI_Reserved_6 |  */
/*    SAI_Reserved_7 | GT_SAI | PM_PCS_SAI | HW_CPU_SAI | MEM_CPL_SAI | VTD_SAI */
/*    | PM_DIE_TO_DIE_SAI | OOB_MSM_UNTRUSTED_SAI | HOSTCP_PMA_SAI |            */
/*    CSE_INTEL_SAI | CSE_OEM_SAI | FUSE_CTRL_SAI | FUSE_PULLER_SAI |           */
/*    PECI_MSM_SAI | PM_IOSS_SAI | CSE_DNX_SAI | FXR_INTERNAL_SAI |             */
/*    DFX_INTEL_MANUFACTURING_SAI | DFX_UNTRUSTED_SAI | SAI_Reserved_26 |       */
/*    IRC_SAI | NPK_SAI | DISPLAY2_SAI | DISPLAY3_SAI | HW_PCH_SAI |            */
/*    SAI_Reserved_32 | SAI_Reserved_33 | SAI_Reserved_34 | GT_PMA_SAI |        */
/*    HSP_SAI | SAI_Reserved_37 | SAI_Reserved_38 | SAI_Reserved_39 |           */
/*    UNCORE_PMA_SAI | RC_MORPHED_SAI | DFX_INTEL_PRODUCTION_SAI |              */
/*    DFX_THIRDPARTY_SAI | DISPLAY_SAI | SAI_Reserved_45 | SAI_Reserved_46 |    */
/*    DISPLAY_KVM_SAI | GT2_SAI | SAI_Reserved_49 | DEVICE_UNTRUSTED_IAL_SAI |  */
/*    SAI_Reserved_51 | CORE_EVENT_PROXY_SAI | DEVICE_ABORT_SAI |               */
/*    RCIOMMU_BYPASS_SAI | SAI_Reserved_55 | SAI_Reserved_56 | IE_CSE_SAI |     */
/*    SAI_Reserved_58 | SAI_Reserved_59 | CPM_SAI | OOB_MSM_SAI | XGBE_SAI |    */
/*    DEVICE_UNTRUSTED_SAI                                                      */
/*  Security_WriteAccess_Str:                                                   */
/*    HOSTIA_UCODE_SAI | HOSTIA_SUNPASS_SAI | PM_PCS_SAI |                      */
/*    DFX_INTEL_MANUFACTURING_SAI | DFX_INTEL_PRODUCTION_SAI | HOSTIA_BOOT_SAI  */
/*    | HOSTIA_SMM_SAI | OOB_MSM_SAI                                            */
/*  Security_Read_CP_Secured:                                                   */
/*    0                                                                         */
/* LB_W                                                                         */
/*  Security_ReadAccess_Str:                                                    */
/*    HOSTIA_POSTBOOT_SAI | HOSTIA_UCODE_SAI | HOSTIA_SMM_SAI |                 */
/*    HOSTIA_SUNPASS_SAI | HOSTIA_BOOT_SAI | SAI_Reserved_5 | SAI_Reserved_6 |  */
/*    SAI_Reserved_7 | GT_SAI | PM_PCS_SAI | HW_CPU_SAI | MEM_CPL_SAI | VTD_SAI */
/*    | PM_DIE_TO_DIE_SAI | OOB_MSM_UNTRUSTED_SAI | HOSTCP_PMA_SAI |            */
/*    CSE_INTEL_SAI | CSE_OEM_SAI | FUSE_CTRL_SAI | FUSE_PULLER_SAI |           */
/*    PECI_MSM_SAI | PM_IOSS_SAI | CSE_DNX_SAI | FXR_INTERNAL_SAI |             */
/*    DFX_INTEL_MANUFACTURING_SAI | DFX_UNTRUSTED_SAI | SAI_Reserved_26 |       */
/*    IRC_SAI | NPK_SAI | DISPLAY2_SAI | DISPLAY3_SAI | HW_PCH_SAI |            */
/*    SAI_Reserved_32 | SAI_Reserved_33 | SAI_Reserved_34 | GT_PMA_SAI |        */
/*    HSP_SAI | SAI_Reserved_37 | SAI_Reserved_38 | SAI_Reserved_39 |           */
/*    UNCORE_PMA_SAI | RC_MORPHED_SAI | DFX_INTEL_PRODUCTION_SAI |              */
/*    DFX_THIRDPARTY_SAI | DISPLAY_SAI | SAI_Reserved_45 | SAI_Reserved_46 |    */
/*    DISPLAY_KVM_SAI | GT2_SAI | SAI_Reserved_49 | DEVICE_UNTRUSTED_IAL_SAI |  */
/*    SAI_Reserved_51 | CORE_EVENT_PROXY_SAI | DEVICE_ABORT_SAI |               */
/*    RCIOMMU_BYPASS_SAI | SAI_Reserved_55 | SAI_Reserved_56 | IE_CSE_SAI |     */
/*    SAI_Reserved_58 | SAI_Reserved_59 | CPM_SAI | OOB_MSM_SAI | XGBE_SAI |    */
/*    DEVICE_UNTRUSTED_SAI                                                      */
/*  Security_WriteAccess_Str:                                                   */
/*    HOSTIA_UCODE_SAI | HOSTIA_SUNPASS_SAI | PM_PCS_SAI |                      */
/*    DFX_INTEL_MANUFACTURING_SAI | DFX_INTEL_PRODUCTION_SAI | HOSTIA_BOOT_SAI  */
/*    | HOSTIA_SMM_SAI | OOB_MSM_SAI                                            */
/*  Security_Read_CP_Secured:                                                   */
/*    0                                                                         */
/* OS_W                                                                         */
/*  Security_ReadAccess_Str:                                                    */
/*    HOSTIA_POSTBOOT_SAI | HOSTIA_UCODE_SAI | HOSTIA_SMM_SAI |                 */
/*    HOSTIA_SUNPASS_SAI | HOSTIA_BOOT_SAI | SAI_Reserved_5 | SAI_Reserved_6 |  */
/*    SAI_Reserved_7 | GT_SAI | PM_PCS_SAI | HW_CPU_SAI | MEM_CPL_SAI | VTD_SAI */
/*    | PM_DIE_TO_DIE_SAI | OOB_MSM_UNTRUSTED_SAI | HOSTCP_PMA_SAI |            */
/*    CSE_INTEL_SAI | CSE_OEM_SAI | FUSE_CTRL_SAI | FUSE_PULLER_SAI |           */
/*    PECI_MSM_SAI | PM_IOSS_SAI | CSE_DNX_SAI | FXR_INTERNAL_SAI |             */
/*    DFX_INTEL_MANUFACTURING_SAI | DFX_UNTRUSTED_SAI | SAI_Reserved_26 |       */
/*    IRC_SAI | NPK_SAI | DISPLAY2_SAI | DISPLAY3_SAI | HW_PCH_SAI |            */
/*    SAI_Reserved_32 | SAI_Reserved_33 | SAI_Reserved_34 | GT_PMA_SAI |        */
/*    HSP_SAI | SAI_Reserved_37 | SAI_Reserved_38 | SAI_Reserved_39 |           */
/*    UNCORE_PMA_SAI | RC_MORPHED_SAI | DFX_INTEL_PRODUCTION_SAI |              */
/*    DFX_THIRDPARTY_SAI | DISPLAY_SAI | SAI_Reserved_45 | SAI_Reserved_46 |    */
/*    DISPLAY_KVM_SAI | GT2_SAI | SAI_Reserved_49 | DEVICE_UNTRUSTED_IAL_SAI |  */
/*    SAI_Reserved_51 | CORE_EVENT_PROXY_SAI | DEVICE_ABORT_SAI |               */
/*    RCIOMMU_BYPASS_SAI | SAI_Reserved_55 | SAI_Reserved_56 | IE_CSE_SAI |     */
/*    SAI_Reserved_58 | SAI_Reserved_59 | CPM_SAI | OOB_MSM_SAI | XGBE_SAI |    */
/*    DEVICE_UNTRUSTED_SAI                                                      */
/*  Security_WriteAccess_Str:                                                   */
/*    HOSTIA_POSTBOOT_SAI | HOSTIA_UCODE_SAI | HOSTIA_SMM_SAI |                 */
/*    HOSTIA_SUNPASS_SAI | HOSTIA_BOOT_SAI | PM_PCS_SAI |                       */
/*    DFX_INTEL_MANUFACTURING_SAI | DFX_INTEL_PRODUCTION_SAI |                  */
/*    DFX_UNTRUSTED_SAI | OOB_MSM_SAI | DFX_THIRDPARTY_SAI                      */
/*  Security_Read_CP_Secured:                                                   */
/*    0                                                                         */
/* P_U_CODE                                                                     */
/*  Security_ReadAccess_Str:                                                    */
/*    HOSTIA_UCODE_SAI | HOSTIA_SUNPASS_SAI | PM_PCS_SAI |                      */
/*    DFX_INTEL_MANUFACTURING_SAI | DFX_INTEL_PRODUCTION_SAI | UNCORE_PMA_SAI | */
/*    OOB_MSM_SAI                                                               */
/*  Security_WriteAccess_Str:                                                   */
/*    HOSTIA_UCODE_SAI | HOSTIA_SUNPASS_SAI | PM_PCS_SAI |                      */
/*    DFX_INTEL_MANUFACTURING_SAI | DFX_INTEL_PRODUCTION_SAI                    */
/*  Security_Read_CP_Secured:                                                   */
/*    0                                                                         */

/* SPRC0 Security Policy Groups:                                                */
/* LB_MCHECK_W                                                                  */
/*  Security_ReadAccess_Str:                                                    */
/*    HOSTIA_POSTBOOT_SAI | HOSTIA_UCODE_SAI | HOSTIA_SMM_SAI |                 */
/*    HOSTIA_SUNPASS_SAI | HOSTIA_BOOT_SAI | SAI_Reserved_5 | SAI_Reserved_6 |  */
/*    SAI_Reserved_7 | GT_SAI | PM_PCS_SAI | HW_CPU_SAI | MEM_CPL_SAI | VTD_SAI */
/*    | PM_DIE_TO_DIE_SAI | OOB_MSM_UNTRUSTED_SAI | HOSTCP_PMA_SAI |            */
/*    CSE_INTEL_SAI | CSE_OEM_SAI | FUSE_CTRL_SAI | FUSE_PULLER_SAI |           */
/*    PECI_MSM_SAI | PM_IOSS_SAI | CSE_DNX_SAI | FXR_INTERNAL_SAI |             */
/*    DFX_INTEL_MANUFACTURING_SAI | DFX_UNTRUSTED_SAI | SAI_Reserved_26 |       */
/*    IRC_SAI | NPK_SAI | DISPLAY2_SAI | DISPLAY3_SAI | HW_PCH_SAI |            */
/*    SAI_Reserved_32 | SAI_Reserved_33 | SAI_Reserved_34 | GT_PMA_SAI |        */
/*    HSP_SAI | SAI_Reserved_37 | SAI_Reserved_38 | SAI_Reserved_39 |           */
/*    UNCORE_PMA_SAI | RC_MORPHED_SAI | DFX_INTEL_PRODUCTION_SAI |              */
/*    DFX_THIRDPARTY_SAI | DISPLAY_SAI | SAI_Reserved_45 | SAI_Reserved_46 |    */
/*    DISPLAY_KVM_SAI | GT2_SAI | SAI_Reserved_49 | DEVICE_UNTRUSTED_IAL_SAI |  */
/*    SAI_Reserved_51 | CORE_EVENT_PROXY_SAI | DEVICE_ABORT_SAI |               */
/*    RCIOMMU_BYPASS_SAI | SAI_Reserved_55 | SAI_Reserved_56 | IE_CSE_SAI |     */
/*    SAI_Reserved_58 | SAI_Reserved_59 | CPM_SAI | OOB_MSM_SAI | XGBE_SAI |    */
/*    DEVICE_UNTRUSTED_SAI                                                      */
/*  Security_WriteAccess_Str:                                                   */
/*    HOSTIA_UCODE_SAI | HOSTIA_SUNPASS_SAI | PM_PCS_SAI |                      */
/*    DFX_INTEL_MANUFACTURING_SAI | DFX_INTEL_PRODUCTION_SAI | HOSTIA_BOOT_SAI  */
/*    | HOSTIA_SMM_SAI | OOB_MSM_SAI                                            */
/*  Security_Read_CP_Secured:                                                   */
/*    0                                                                         */
/* LB_W                                                                         */
/*  Security_ReadAccess_Str:                                                    */
/*    HOSTIA_POSTBOOT_SAI | HOSTIA_UCODE_SAI | HOSTIA_SMM_SAI |                 */
/*    HOSTIA_SUNPASS_SAI | HOSTIA_BOOT_SAI | SAI_Reserved_5 | SAI_Reserved_6 |  */
/*    SAI_Reserved_7 | GT_SAI | PM_PCS_SAI | HW_CPU_SAI | MEM_CPL_SAI | VTD_SAI */
/*    | PM_DIE_TO_DIE_SAI | OOB_MSM_UNTRUSTED_SAI | HOSTCP_PMA_SAI |            */
/*    CSE_INTEL_SAI | CSE_OEM_SAI | FUSE_CTRL_SAI | FUSE_PULLER_SAI |           */
/*    PECI_MSM_SAI | PM_IOSS_SAI | CSE_DNX_SAI | FXR_INTERNAL_SAI |             */
/*    DFX_INTEL_MANUFACTURING_SAI | DFX_UNTRUSTED_SAI | SAI_Reserved_26 |       */
/*    IRC_SAI | NPK_SAI | DISPLAY2_SAI | DISPLAY3_SAI | HW_PCH_SAI |            */
/*    SAI_Reserved_32 | SAI_Reserved_33 | SAI_Reserved_34 | GT_PMA_SAI |        */
/*    HSP_SAI | SAI_Reserved_37 | SAI_Reserved_38 | SAI_Reserved_39 |           */
/*    UNCORE_PMA_SAI | RC_MORPHED_SAI | DFX_INTEL_PRODUCTION_SAI |              */
/*    DFX_THIRDPARTY_SAI | DISPLAY_SAI | SAI_Reserved_45 | SAI_Reserved_46 |    */
/*    DISPLAY_KVM_SAI | GT2_SAI | SAI_Reserved_49 | DEVICE_UNTRUSTED_IAL_SAI |  */
/*    SAI_Reserved_51 | CORE_EVENT_PROXY_SAI | DEVICE_ABORT_SAI |               */
/*    RCIOMMU_BYPASS_SAI | SAI_Reserved_55 | SAI_Reserved_56 | IE_CSE_SAI |     */
/*    SAI_Reserved_58 | SAI_Reserved_59 | CPM_SAI | OOB_MSM_SAI | XGBE_SAI |    */
/*    DEVICE_UNTRUSTED_SAI                                                      */
/*  Security_WriteAccess_Str:                                                   */
/*    HOSTIA_UCODE_SAI | HOSTIA_SUNPASS_SAI | PM_PCS_SAI |                      */
/*    DFX_INTEL_MANUFACTURING_SAI | DFX_INTEL_PRODUCTION_SAI | HOSTIA_BOOT_SAI  */
/*    | HOSTIA_SMM_SAI | OOB_MSM_SAI                                            */
/*  Security_Read_CP_Secured:                                                   */
/*    0                                                                         */
/* OS_W                                                                         */
/*  Security_ReadAccess_Str:                                                    */
/*    HOSTIA_POSTBOOT_SAI | HOSTIA_UCODE_SAI | HOSTIA_SMM_SAI |                 */
/*    HOSTIA_SUNPASS_SAI | HOSTIA_BOOT_SAI | SAI_Reserved_5 | SAI_Reserved_6 |  */
/*    SAI_Reserved_7 | GT_SAI | PM_PCS_SAI | HW_CPU_SAI | MEM_CPL_SAI | VTD_SAI */
/*    | PM_DIE_TO_DIE_SAI | OOB_MSM_UNTRUSTED_SAI | HOSTCP_PMA_SAI |            */
/*    CSE_INTEL_SAI | CSE_OEM_SAI | FUSE_CTRL_SAI | FUSE_PULLER_SAI |           */
/*    PECI_MSM_SAI | PM_IOSS_SAI | CSE_DNX_SAI | FXR_INTERNAL_SAI |             */
/*    DFX_INTEL_MANUFACTURING_SAI | DFX_UNTRUSTED_SAI | SAI_Reserved_26 |       */
/*    IRC_SAI | NPK_SAI | DISPLAY2_SAI | DISPLAY3_SAI | HW_PCH_SAI |            */
/*    SAI_Reserved_32 | SAI_Reserved_33 | SAI_Reserved_34 | GT_PMA_SAI |        */
/*    HSP_SAI | SAI_Reserved_37 | SAI_Reserved_38 | SAI_Reserved_39 |           */
/*    UNCORE_PMA_SAI | RC_MORPHED_SAI | DFX_INTEL_PRODUCTION_SAI |              */
/*    DFX_THIRDPARTY_SAI | DISPLAY_SAI | SAI_Reserved_45 | SAI_Reserved_46 |    */
/*    DISPLAY_KVM_SAI | GT2_SAI | SAI_Reserved_49 | DEVICE_UNTRUSTED_IAL_SAI |  */
/*    SAI_Reserved_51 | CORE_EVENT_PROXY_SAI | DEVICE_ABORT_SAI |               */
/*    RCIOMMU_BYPASS_SAI | SAI_Reserved_55 | SAI_Reserved_56 | IE_CSE_SAI |     */
/*    SAI_Reserved_58 | SAI_Reserved_59 | CPM_SAI | OOB_MSM_SAI | XGBE_SAI |    */
/*    DEVICE_UNTRUSTED_SAI                                                      */
/*  Security_WriteAccess_Str:                                                   */
/*    HOSTIA_POSTBOOT_SAI | HOSTIA_UCODE_SAI | HOSTIA_SMM_SAI |                 */
/*    HOSTIA_SUNPASS_SAI | HOSTIA_BOOT_SAI | PM_PCS_SAI |                       */
/*    DFX_INTEL_MANUFACTURING_SAI | DFX_INTEL_PRODUCTION_SAI |                  */
/*    DFX_UNTRUSTED_SAI | OOB_MSM_SAI | DFX_THIRDPARTY_SAI                      */
/*  Security_Read_CP_Secured:                                                   */
/*    0                                                                         */
/* P_U_CODE                                                                     */
/*  Security_ReadAccess_Str:                                                    */
/*    HOSTIA_UCODE_SAI | HOSTIA_SUNPASS_SAI | PM_PCS_SAI |                      */
/*    DFX_INTEL_MANUFACTURING_SAI | DFX_INTEL_PRODUCTION_SAI | UNCORE_PMA_SAI | */
/*    OOB_MSM_SAI                                                               */
/*  Security_WriteAccess_Str:                                                   */
/*    HOSTIA_UCODE_SAI | HOSTIA_SUNPASS_SAI | PM_PCS_SAI |                      */
/*    DFX_INTEL_MANUFACTURING_SAI | DFX_INTEL_PRODUCTION_SAI                    */
/*  Security_Read_CP_Secured:                                                   */
/*    0                                                                         */

/* SPRMCC Security Policy Groups:                                               */
/* LB_MCHECK_W                                                                  */
/*  Security_ReadAccess_Str:                                                    */
/*    HOSTIA_POSTBOOT_SAI | HOSTIA_UCODE_SAI | HOSTIA_SMM_SAI |                 */
/*    HOSTIA_SUNPASS_SAI | HOSTIA_BOOT_SAI | SAI_Reserved_5 | SAI_Reserved_6 |  */
/*    SAI_Reserved_7 | GT_SAI | PM_PCS_SAI | HW_CPU_SAI | MEM_CPL_SAI | VTD_SAI */
/*    | PM_DIE_TO_DIE_SAI | OOB_MSM_UNTRUSTED_SAI | HOSTCP_PMA_SAI |            */
/*    CSE_INTEL_SAI | CSE_OEM_SAI | FUSE_CTRL_SAI | FUSE_PULLER_SAI |           */
/*    PECI_MSM_SAI | PM_IOSS_SAI | CSE_DNX_SAI | FXR_INTERNAL_SAI |             */
/*    DFX_INTEL_MANUFACTURING_SAI | DFX_UNTRUSTED_SAI | SAI_Reserved_26 |       */
/*    IRC_SAI | NPK_SAI | DISPLAY2_SAI | DISPLAY3_SAI | HW_PCH_SAI |            */
/*    SAI_Reserved_32 | SAI_Reserved_33 | SAI_Reserved_34 | GT_PMA_SAI |        */
/*    HSP_SAI | SAI_Reserved_37 | SAI_Reserved_38 | SAI_Reserved_39 |           */
/*    UNCORE_PMA_SAI | RC_MORPHED_SAI | DFX_INTEL_PRODUCTION_SAI |              */
/*    DFX_THIRDPARTY_SAI | DISPLAY_SAI | SAI_Reserved_45 | SAI_Reserved_46 |    */
/*    DISPLAY_KVM_SAI | GT2_SAI | SAI_Reserved_49 | DEVICE_UNTRUSTED_IAL_SAI |  */
/*    SAI_Reserved_51 | CORE_EVENT_PROXY_SAI | DEVICE_ABORT_SAI |               */
/*    RCIOMMU_BYPASS_SAI | SAI_Reserved_55 | SAI_Reserved_56 | IE_CSE_SAI |     */
/*    SAI_Reserved_58 | SAI_Reserved_59 | CPM_SAI | OOB_MSM_SAI | XGBE_SAI |    */
/*    DEVICE_UNTRUSTED_SAI                                                      */
/*  Security_WriteAccess_Str:                                                   */
/*    HOSTIA_UCODE_SAI | HOSTIA_SUNPASS_SAI | PM_PCS_SAI |                      */
/*    DFX_INTEL_MANUFACTURING_SAI | DFX_INTEL_PRODUCTION_SAI | HOSTIA_BOOT_SAI  */
/*    | HOSTIA_SMM_SAI | OOB_MSM_SAI                                            */
/*  Security_Read_CP_Secured:                                                   */
/*    0                                                                         */
/* LB_W                                                                         */
/*  Security_ReadAccess_Str:                                                    */
/*    HOSTIA_POSTBOOT_SAI | HOSTIA_UCODE_SAI | HOSTIA_SMM_SAI |                 */
/*    HOSTIA_SUNPASS_SAI | HOSTIA_BOOT_SAI | SAI_Reserved_5 | SAI_Reserved_6 |  */
/*    SAI_Reserved_7 | GT_SAI | PM_PCS_SAI | HW_CPU_SAI | MEM_CPL_SAI | VTD_SAI */
/*    | PM_DIE_TO_DIE_SAI | OOB_MSM_UNTRUSTED_SAI | HOSTCP_PMA_SAI |            */
/*    CSE_INTEL_SAI | CSE_OEM_SAI | FUSE_CTRL_SAI | FUSE_PULLER_SAI |           */
/*    PECI_MSM_SAI | PM_IOSS_SAI | CSE_DNX_SAI | FXR_INTERNAL_SAI |             */
/*    DFX_INTEL_MANUFACTURING_SAI | DFX_UNTRUSTED_SAI | SAI_Reserved_26 |       */
/*    IRC_SAI | NPK_SAI | DISPLAY2_SAI | DISPLAY3_SAI | HW_PCH_SAI |            */
/*    SAI_Reserved_32 | SAI_Reserved_33 | SAI_Reserved_34 | GT_PMA_SAI |        */
/*    HSP_SAI | SAI_Reserved_37 | SAI_Reserved_38 | SAI_Reserved_39 |           */
/*    UNCORE_PMA_SAI | RC_MORPHED_SAI | DFX_INTEL_PRODUCTION_SAI |              */
/*    DFX_THIRDPARTY_SAI | DISPLAY_SAI | SAI_Reserved_45 | SAI_Reserved_46 |    */
/*    DISPLAY_KVM_SAI | GT2_SAI | SAI_Reserved_49 | DEVICE_UNTRUSTED_IAL_SAI |  */
/*    SAI_Reserved_51 | CORE_EVENT_PROXY_SAI | DEVICE_ABORT_SAI |               */
/*    RCIOMMU_BYPASS_SAI | SAI_Reserved_55 | SAI_Reserved_56 | IE_CSE_SAI |     */
/*    SAI_Reserved_58 | SAI_Reserved_59 | CPM_SAI | OOB_MSM_SAI | XGBE_SAI |    */
/*    DEVICE_UNTRUSTED_SAI                                                      */
/*  Security_WriteAccess_Str:                                                   */
/*    HOSTIA_UCODE_SAI | HOSTIA_SUNPASS_SAI | PM_PCS_SAI |                      */
/*    DFX_INTEL_MANUFACTURING_SAI | DFX_INTEL_PRODUCTION_SAI | HOSTIA_BOOT_SAI  */
/*    | HOSTIA_SMM_SAI | OOB_MSM_SAI                                            */
/*  Security_Read_CP_Secured:                                                   */
/*    0                                                                         */
/* OS_W                                                                         */
/*  Security_ReadAccess_Str:                                                    */
/*    HOSTIA_POSTBOOT_SAI | HOSTIA_UCODE_SAI | HOSTIA_SMM_SAI |                 */
/*    HOSTIA_SUNPASS_SAI | HOSTIA_BOOT_SAI | SAI_Reserved_5 | SAI_Reserved_6 |  */
/*    SAI_Reserved_7 | GT_SAI | PM_PCS_SAI | HW_CPU_SAI | MEM_CPL_SAI | VTD_SAI */
/*    | PM_DIE_TO_DIE_SAI | OOB_MSM_UNTRUSTED_SAI | HOSTCP_PMA_SAI |            */
/*    CSE_INTEL_SAI | CSE_OEM_SAI | FUSE_CTRL_SAI | FUSE_PULLER_SAI |           */
/*    PECI_MSM_SAI | PM_IOSS_SAI | CSE_DNX_SAI | FXR_INTERNAL_SAI |             */
/*    DFX_INTEL_MANUFACTURING_SAI | DFX_UNTRUSTED_SAI | SAI_Reserved_26 |       */
/*    IRC_SAI | NPK_SAI | DISPLAY2_SAI | DISPLAY3_SAI | HW_PCH_SAI |            */
/*    SAI_Reserved_32 | SAI_Reserved_33 | SAI_Reserved_34 | GT_PMA_SAI |        */
/*    HSP_SAI | SAI_Reserved_37 | SAI_Reserved_38 | SAI_Reserved_39 |           */
/*    UNCORE_PMA_SAI | RC_MORPHED_SAI | DFX_INTEL_PRODUCTION_SAI |              */
/*    DFX_THIRDPARTY_SAI | DISPLAY_SAI | SAI_Reserved_45 | SAI_Reserved_46 |    */
/*    DISPLAY_KVM_SAI | GT2_SAI | SAI_Reserved_49 | DEVICE_UNTRUSTED_IAL_SAI |  */
/*    SAI_Reserved_51 | CORE_EVENT_PROXY_SAI | DEVICE_ABORT_SAI |               */
/*    RCIOMMU_BYPASS_SAI | SAI_Reserved_55 | SAI_Reserved_56 | IE_CSE_SAI |     */
/*    SAI_Reserved_58 | SAI_Reserved_59 | CPM_SAI | OOB_MSM_SAI | XGBE_SAI |    */
/*    DEVICE_UNTRUSTED_SAI                                                      */
/*  Security_WriteAccess_Str:                                                   */
/*    HOSTIA_POSTBOOT_SAI | HOSTIA_UCODE_SAI | HOSTIA_SMM_SAI |                 */
/*    HOSTIA_SUNPASS_SAI | HOSTIA_BOOT_SAI | PM_PCS_SAI |                       */
/*    DFX_INTEL_MANUFACTURING_SAI | DFX_INTEL_PRODUCTION_SAI |                  */
/*    DFX_UNTRUSTED_SAI | OOB_MSM_SAI | DFX_THIRDPARTY_SAI                      */
/*  Security_Read_CP_Secured:                                                   */
/*    0                                                                         */
/* P_U_CODE                                                                     */
/*  Security_ReadAccess_Str:                                                    */
/*    HOSTIA_UCODE_SAI | HOSTIA_SUNPASS_SAI | PM_PCS_SAI |                      */
/*    DFX_INTEL_MANUFACTURING_SAI | DFX_INTEL_PRODUCTION_SAI | UNCORE_PMA_SAI | */
/*    OOB_MSM_SAI                                                               */
/*  Security_WriteAccess_Str:                                                   */
/*    HOSTIA_UCODE_SAI | HOSTIA_SUNPASS_SAI | PM_PCS_SAI |                      */
/*    DFX_INTEL_MANUFACTURING_SAI | DFX_INTEL_PRODUCTION_SAI                    */
/*  Security_Read_CP_Secured:                                                   */
/*    0                                                                         */

/* SPRD0 Security Policy Groups:                                                */
/* LB_MCHECK_W                                                                  */
/*  Security_ReadAccess_Str:                                                    */
/*    HOSTIA_POSTBOOT_SAI | HOSTIA_UCODE_SAI | HOSTIA_SMM_SAI |                 */
/*    HOSTIA_SUNPASS_SAI | HOSTIA_BOOT_SAI | SAI_Reserved_5 | SAI_Reserved_6 |  */
/*    SAI_Reserved_7 | GT_SAI | PM_PCS_SAI | HW_CPU_SAI | MEM_CPL_SAI | VTD_SAI */
/*    | PM_DIE_TO_DIE_SAI | OOB_MSM_UNTRUSTED_SAI | HOSTCP_PMA_SAI |            */
/*    CSE_INTEL_SAI | CSE_OEM_SAI | FUSE_CTRL_SAI | FUSE_PULLER_SAI |           */
/*    PECI_MSM_SAI | PM_IOSS_SAI | CSE_DNX_SAI | FXR_INTERNAL_SAI |             */
/*    DFX_INTEL_MANUFACTURING_SAI | DFX_UNTRUSTED_SAI | SAI_Reserved_26 |       */
/*    IRC_SAI | NPK_SAI | DISPLAY2_SAI | DISPLAY3_SAI | HW_PCH_SAI |            */
/*    SAI_Reserved_32 | SAI_Reserved_33 | SAI_Reserved_34 | GT_PMA_SAI |        */
/*    HSP_SAI | SAI_Reserved_37 | SAI_Reserved_38 | SAI_Reserved_39 |           */
/*    UNCORE_PMA_SAI | RC_MORPHED_SAI | DFX_INTEL_PRODUCTION_SAI |              */
/*    DFX_THIRDPARTY_SAI | DISPLAY_SAI | SAI_Reserved_45 | SAI_Reserved_46 |    */
/*    DISPLAY_KVM_SAI | GT2_SAI | SAI_Reserved_49 | DEVICE_UNTRUSTED_IAL_SAI |  */
/*    SAI_Reserved_51 | CORE_EVENT_PROXY_SAI | DEVICE_ABORT_SAI |               */
/*    RCIOMMU_BYPASS_SAI | SAI_Reserved_55 | SAI_Reserved_56 | IE_CSE_SAI |     */
/*    SAI_Reserved_58 | SAI_Reserved_59 | CPM_SAI | OOB_MSM_SAI | XGBE_SAI |    */
/*    DEVICE_UNTRUSTED_SAI                                                      */
/*  Security_WriteAccess_Str:                                                   */
/*    HOSTIA_UCODE_SAI | HOSTIA_SUNPASS_SAI | PM_PCS_SAI |                      */
/*    DFX_INTEL_MANUFACTURING_SAI | DFX_INTEL_PRODUCTION_SAI | HOSTIA_BOOT_SAI  */
/*    | HOSTIA_SMM_SAI | OOB_MSM_SAI                                            */
/*  Security_Read_CP_Secured:                                                   */
/*    0                                                                         */
/* LB_W                                                                         */
/*  Security_ReadAccess_Str:                                                    */
/*    HOSTIA_POSTBOOT_SAI | HOSTIA_UCODE_SAI | HOSTIA_SMM_SAI |                 */
/*    HOSTIA_SUNPASS_SAI | HOSTIA_BOOT_SAI | SAI_Reserved_5 | SAI_Reserved_6 |  */
/*    SAI_Reserved_7 | GT_SAI | PM_PCS_SAI | HW_CPU_SAI | MEM_CPL_SAI | VTD_SAI */
/*    | PM_DIE_TO_DIE_SAI | OOB_MSM_UNTRUSTED_SAI | HOSTCP_PMA_SAI |            */
/*    CSE_INTEL_SAI | CSE_OEM_SAI | FUSE_CTRL_SAI | FUSE_PULLER_SAI |           */
/*    PECI_MSM_SAI | PM_IOSS_SAI | CSE_DNX_SAI | FXR_INTERNAL_SAI |             */
/*    DFX_INTEL_MANUFACTURING_SAI | DFX_UNTRUSTED_SAI | SAI_Reserved_26 |       */
/*    IRC_SAI | NPK_SAI | DISPLAY2_SAI | DISPLAY3_SAI | HW_PCH_SAI |            */
/*    SAI_Reserved_32 | SAI_Reserved_33 | SAI_Reserved_34 | GT_PMA_SAI |        */
/*    HSP_SAI | SAI_Reserved_37 | SAI_Reserved_38 | SAI_Reserved_39 |           */
/*    UNCORE_PMA_SAI | RC_MORPHED_SAI | DFX_INTEL_PRODUCTION_SAI |              */
/*    DFX_THIRDPARTY_SAI | DISPLAY_SAI | SAI_Reserved_45 | SAI_Reserved_46 |    */
/*    DISPLAY_KVM_SAI | GT2_SAI | SAI_Reserved_49 | DEVICE_UNTRUSTED_IAL_SAI |  */
/*    SAI_Reserved_51 | CORE_EVENT_PROXY_SAI | DEVICE_ABORT_SAI |               */
/*    RCIOMMU_BYPASS_SAI | SAI_Reserved_55 | SAI_Reserved_56 | IE_CSE_SAI |     */
/*    SAI_Reserved_58 | SAI_Reserved_59 | CPM_SAI | OOB_MSM_SAI | XGBE_SAI |    */
/*    DEVICE_UNTRUSTED_SAI                                                      */
/*  Security_WriteAccess_Str:                                                   */
/*    HOSTIA_UCODE_SAI | HOSTIA_SUNPASS_SAI | PM_PCS_SAI |                      */
/*    DFX_INTEL_MANUFACTURING_SAI | DFX_INTEL_PRODUCTION_SAI | HOSTIA_BOOT_SAI  */
/*    | HOSTIA_SMM_SAI | OOB_MSM_SAI                                            */
/*  Security_Read_CP_Secured:                                                   */
/*    0                                                                         */
/* OS_W                                                                         */
/*  Security_ReadAccess_Str:                                                    */
/*    HOSTIA_POSTBOOT_SAI | HOSTIA_UCODE_SAI | HOSTIA_SMM_SAI |                 */
/*    HOSTIA_SUNPASS_SAI | HOSTIA_BOOT_SAI | SAI_Reserved_5 | SAI_Reserved_6 |  */
/*    SAI_Reserved_7 | GT_SAI | PM_PCS_SAI | HW_CPU_SAI | MEM_CPL_SAI | VTD_SAI */
/*    | PM_DIE_TO_DIE_SAI | OOB_MSM_UNTRUSTED_SAI | HOSTCP_PMA_SAI |            */
/*    CSE_INTEL_SAI | CSE_OEM_SAI | FUSE_CTRL_SAI | FUSE_PULLER_SAI |           */
/*    PECI_MSM_SAI | PM_IOSS_SAI | CSE_DNX_SAI | FXR_INTERNAL_SAI |             */
/*    DFX_INTEL_MANUFACTURING_SAI | DFX_UNTRUSTED_SAI | SAI_Reserved_26 |       */
/*    IRC_SAI | NPK_SAI | DISPLAY2_SAI | DISPLAY3_SAI | HW_PCH_SAI |            */
/*    SAI_Reserved_32 | SAI_Reserved_33 | SAI_Reserved_34 | GT_PMA_SAI |        */
/*    HSP_SAI | SAI_Reserved_37 | SAI_Reserved_38 | SAI_Reserved_39 |           */
/*    UNCORE_PMA_SAI | RC_MORPHED_SAI | DFX_INTEL_PRODUCTION_SAI |              */
/*    DFX_THIRDPARTY_SAI | DISPLAY_SAI | SAI_Reserved_45 | SAI_Reserved_46 |    */
/*    DISPLAY_KVM_SAI | GT2_SAI | SAI_Reserved_49 | DEVICE_UNTRUSTED_IAL_SAI |  */
/*    SAI_Reserved_51 | CORE_EVENT_PROXY_SAI | DEVICE_ABORT_SAI |               */
/*    RCIOMMU_BYPASS_SAI | SAI_Reserved_55 | SAI_Reserved_56 | IE_CSE_SAI |     */
/*    SAI_Reserved_58 | SAI_Reserved_59 | CPM_SAI | OOB_MSM_SAI | XGBE_SAI |    */
/*    DEVICE_UNTRUSTED_SAI                                                      */
/*  Security_WriteAccess_Str:                                                   */
/*    HOSTIA_POSTBOOT_SAI | HOSTIA_UCODE_SAI | HOSTIA_SMM_SAI |                 */
/*    HOSTIA_SUNPASS_SAI | HOSTIA_BOOT_SAI | PM_PCS_SAI |                       */
/*    DFX_INTEL_MANUFACTURING_SAI | DFX_INTEL_PRODUCTION_SAI |                  */
/*    DFX_UNTRUSTED_SAI | OOB_MSM_SAI | DFX_THIRDPARTY_SAI                      */
/*  Security_Read_CP_Secured:                                                   */
/*    0                                                                         */
/* P_U_CODE                                                                     */
/*  Security_ReadAccess_Str:                                                    */
/*    HOSTIA_UCODE_SAI | HOSTIA_SUNPASS_SAI | PM_PCS_SAI |                      */
/*    DFX_INTEL_MANUFACTURING_SAI | DFX_INTEL_PRODUCTION_SAI | UNCORE_PMA_SAI | */
/*    OOB_MSM_SAI                                                               */
/*  Security_WriteAccess_Str:                                                   */
/*    HOSTIA_UCODE_SAI | HOSTIA_SUNPASS_SAI | PM_PCS_SAI |                      */
/*    DFX_INTEL_MANUFACTURING_SAI | DFX_INTEL_PRODUCTION_SAI                    */
/*  Security_Read_CP_Secured:                                                   */
/*    0                                                                         */

/* SPRHBMB0 Security Policy Groups:                                             */
/* LB_MCHECK_W                                                                  */
/*  Security_ReadAccess_Str:                                                    */
/*    HOSTIA_POSTBOOT_SAI | HOSTIA_UCODE_SAI | HOSTIA_SMM_SAI |                 */
/*    HOSTIA_SUNPASS_SAI | HOSTIA_BOOT_SAI | SAI_Reserved_5 | SAI_Reserved_6 |  */
/*    SAI_Reserved_7 | GT_SAI | PM_PCS_SAI | HW_CPU_SAI | MEM_CPL_SAI | VTD_SAI */
/*    | PM_DIE_TO_DIE_SAI | OOB_MSM_UNTRUSTED_SAI | HOSTCP_PMA_SAI |            */
/*    CSE_INTEL_SAI | CSE_OEM_SAI | FUSE_CTRL_SAI | FUSE_PULLER_SAI |           */
/*    PECI_MSM_SAI | PM_IOSS_SAI | CSE_DNX_SAI | FXR_INTERNAL_SAI |             */
/*    DFX_INTEL_MANUFACTURING_SAI | DFX_UNTRUSTED_SAI | SAI_Reserved_26 |       */
/*    IRC_SAI | NPK_SAI | DISPLAY2_SAI | DISPLAY3_SAI | HW_PCH_SAI |            */
/*    SAI_Reserved_32 | SAI_Reserved_33 | SAI_Reserved_34 | GT_PMA_SAI |        */
/*    HSP_SAI | SAI_Reserved_37 | SAI_Reserved_38 | SAI_Reserved_39 |           */
/*    UNCORE_PMA_SAI | RC_MORPHED_SAI | DFX_INTEL_PRODUCTION_SAI |              */
/*    DFX_THIRDPARTY_SAI | DISPLAY_SAI | SAI_Reserved_45 | SAI_Reserved_46 |    */
/*    DISPLAY_KVM_SAI | GT2_SAI | SAI_Reserved_49 | DEVICE_UNTRUSTED_IAL_SAI |  */
/*    SAI_Reserved_51 | CORE_EVENT_PROXY_SAI | DEVICE_ABORT_SAI |               */
/*    RCIOMMU_BYPASS_SAI | SAI_Reserved_55 | SAI_Reserved_56 | IE_CSE_SAI |     */
/*    SAI_Reserved_58 | SAI_Reserved_59 | CPM_SAI | OOB_MSM_SAI | XGBE_SAI |    */
/*    DEVICE_UNTRUSTED_SAI                                                      */
/*  Security_WriteAccess_Str:                                                   */
/*    HOSTIA_UCODE_SAI | HOSTIA_SUNPASS_SAI | PM_PCS_SAI |                      */
/*    DFX_INTEL_MANUFACTURING_SAI | DFX_INTEL_PRODUCTION_SAI | HOSTIA_BOOT_SAI  */
/*    | HOSTIA_SMM_SAI | OOB_MSM_SAI                                            */
/*  Security_Read_CP_Secured:                                                   */
/*    0                                                                         */
/* LB_W                                                                         */
/*  Security_ReadAccess_Str:                                                    */
/*    HOSTIA_POSTBOOT_SAI | HOSTIA_UCODE_SAI | HOSTIA_SMM_SAI |                 */
/*    HOSTIA_SUNPASS_SAI | HOSTIA_BOOT_SAI | SAI_Reserved_5 | SAI_Reserved_6 |  */
/*    SAI_Reserved_7 | GT_SAI | PM_PCS_SAI | HW_CPU_SAI | MEM_CPL_SAI | VTD_SAI */
/*    | PM_DIE_TO_DIE_SAI | OOB_MSM_UNTRUSTED_SAI | HOSTCP_PMA_SAI |            */
/*    CSE_INTEL_SAI | CSE_OEM_SAI | FUSE_CTRL_SAI | FUSE_PULLER_SAI |           */
/*    PECI_MSM_SAI | PM_IOSS_SAI | CSE_DNX_SAI | FXR_INTERNAL_SAI |             */
/*    DFX_INTEL_MANUFACTURING_SAI | DFX_UNTRUSTED_SAI | SAI_Reserved_26 |       */
/*    IRC_SAI | NPK_SAI | DISPLAY2_SAI | DISPLAY3_SAI | HW_PCH_SAI |            */
/*    SAI_Reserved_32 | SAI_Reserved_33 | SAI_Reserved_34 | GT_PMA_SAI |        */
/*    HSP_SAI | SAI_Reserved_37 | SAI_Reserved_38 | SAI_Reserved_39 |           */
/*    UNCORE_PMA_SAI | RC_MORPHED_SAI | DFX_INTEL_PRODUCTION_SAI |              */
/*    DFX_THIRDPARTY_SAI | DISPLAY_SAI | SAI_Reserved_45 | SAI_Reserved_46 |    */
/*    DISPLAY_KVM_SAI | GT2_SAI | SAI_Reserved_49 | DEVICE_UNTRUSTED_IAL_SAI |  */
/*    SAI_Reserved_51 | CORE_EVENT_PROXY_SAI | DEVICE_ABORT_SAI |               */
/*    RCIOMMU_BYPASS_SAI | SAI_Reserved_55 | SAI_Reserved_56 | IE_CSE_SAI |     */
/*    SAI_Reserved_58 | SAI_Reserved_59 | CPM_SAI | OOB_MSM_SAI | XGBE_SAI |    */
/*    DEVICE_UNTRUSTED_SAI                                                      */
/*  Security_WriteAccess_Str:                                                   */
/*    HOSTIA_UCODE_SAI | HOSTIA_SUNPASS_SAI | PM_PCS_SAI |                      */
/*    DFX_INTEL_MANUFACTURING_SAI | DFX_INTEL_PRODUCTION_SAI | HOSTIA_BOOT_SAI  */
/*    | HOSTIA_SMM_SAI | OOB_MSM_SAI                                            */
/*  Security_Read_CP_Secured:                                                   */
/*    0                                                                         */
/* OS_W                                                                         */
/*  Security_ReadAccess_Str:                                                    */
/*    HOSTIA_POSTBOOT_SAI | HOSTIA_UCODE_SAI | HOSTIA_SMM_SAI |                 */
/*    HOSTIA_SUNPASS_SAI | HOSTIA_BOOT_SAI | SAI_Reserved_5 | SAI_Reserved_6 |  */
/*    SAI_Reserved_7 | GT_SAI | PM_PCS_SAI | HW_CPU_SAI | MEM_CPL_SAI | VTD_SAI */
/*    | PM_DIE_TO_DIE_SAI | OOB_MSM_UNTRUSTED_SAI | HOSTCP_PMA_SAI |            */
/*    CSE_INTEL_SAI | CSE_OEM_SAI | FUSE_CTRL_SAI | FUSE_PULLER_SAI |           */
/*    PECI_MSM_SAI | PM_IOSS_SAI | CSE_DNX_SAI | FXR_INTERNAL_SAI |             */
/*    DFX_INTEL_MANUFACTURING_SAI | DFX_UNTRUSTED_SAI | SAI_Reserved_26 |       */
/*    IRC_SAI | NPK_SAI | DISPLAY2_SAI | DISPLAY3_SAI | HW_PCH_SAI |            */
/*    SAI_Reserved_32 | SAI_Reserved_33 | SAI_Reserved_34 | GT_PMA_SAI |        */
/*    HSP_SAI | SAI_Reserved_37 | SAI_Reserved_38 | SAI_Reserved_39 |           */
/*    UNCORE_PMA_SAI | RC_MORPHED_SAI | DFX_INTEL_PRODUCTION_SAI |              */
/*    DFX_THIRDPARTY_SAI | DISPLAY_SAI | SAI_Reserved_45 | SAI_Reserved_46 |    */
/*    DISPLAY_KVM_SAI | GT2_SAI | SAI_Reserved_49 | DEVICE_UNTRUSTED_IAL_SAI |  */
/*    SAI_Reserved_51 | CORE_EVENT_PROXY_SAI | DEVICE_ABORT_SAI |               */
/*    RCIOMMU_BYPASS_SAI | SAI_Reserved_55 | SAI_Reserved_56 | IE_CSE_SAI |     */
/*    SAI_Reserved_58 | SAI_Reserved_59 | CPM_SAI | OOB_MSM_SAI | XGBE_SAI |    */
/*    DEVICE_UNTRUSTED_SAI                                                      */
/*  Security_WriteAccess_Str:                                                   */
/*    HOSTIA_POSTBOOT_SAI | HOSTIA_UCODE_SAI | HOSTIA_SMM_SAI |                 */
/*    HOSTIA_SUNPASS_SAI | HOSTIA_BOOT_SAI | PM_PCS_SAI |                       */
/*    DFX_INTEL_MANUFACTURING_SAI | DFX_INTEL_PRODUCTION_SAI |                  */
/*    DFX_UNTRUSTED_SAI | OOB_MSM_SAI | DFX_THIRDPARTY_SAI                      */
/*  Security_Read_CP_Secured:                                                   */
/*    0                                                                         */
/* P_U_CODE                                                                     */
/*  Security_ReadAccess_Str:                                                    */
/*    HOSTIA_UCODE_SAI | HOSTIA_SUNPASS_SAI | PM_PCS_SAI |                      */
/*    DFX_INTEL_MANUFACTURING_SAI | DFX_INTEL_PRODUCTION_SAI | UNCORE_PMA_SAI | */
/*    OOB_MSM_SAI                                                               */
/*  Security_WriteAccess_Str:                                                   */
/*    HOSTIA_UCODE_SAI | HOSTIA_SUNPASS_SAI | PM_PCS_SAI |                      */
/*    DFX_INTEL_MANUFACTURING_SAI | DFX_INTEL_PRODUCTION_SAI                    */
/*  Security_Read_CP_Secured:                                                   */
/*    0                                                                         */

/* SPRLCC Security Policy Groups:                                               */
/* LB_MCHECK_W                                                                  */
/*  Security_ReadAccess_Str:                                                    */
/*    HOSTIA_POSTBOOT_SAI | HOSTIA_UCODE_SAI | HOSTIA_SMM_SAI |                 */
/*    HOSTIA_SUNPASS_SAI | HOSTIA_BOOT_SAI | SAI_Reserved_5 | SAI_Reserved_6 |  */
/*    SAI_Reserved_7 | GT_SAI | PM_PCS_SAI | HW_CPU_SAI | MEM_CPL_SAI | VTD_SAI */
/*    | PM_DIE_TO_DIE_SAI | OOB_MSM_UNTRUSTED_SAI | HOSTCP_PMA_SAI |            */
/*    CSE_INTEL_SAI | CSE_OEM_SAI | FUSE_CTRL_SAI | FUSE_PULLER_SAI |           */
/*    PECI_MSM_SAI | PM_IOSS_SAI | CSE_DNX_SAI | FXR_INTERNAL_SAI |             */
/*    DFX_INTEL_MANUFACTURING_SAI | DFX_UNTRUSTED_SAI | SAI_Reserved_26 |       */
/*    IRC_SAI | NPK_SAI | DISPLAY2_SAI | DISPLAY3_SAI | HW_PCH_SAI |            */
/*    SAI_Reserved_32 | SAI_Reserved_33 | SAI_Reserved_34 | GT_PMA_SAI |        */
/*    HSP_SAI | SAI_Reserved_37 | SAI_Reserved_38 | SAI_Reserved_39 |           */
/*    UNCORE_PMA_SAI | RC_MORPHED_SAI | DFX_INTEL_PRODUCTION_SAI |              */
/*    DFX_THIRDPARTY_SAI | DISPLAY_SAI | SAI_Reserved_45 | SAI_Reserved_46 |    */
/*    DISPLAY_KVM_SAI | GT2_SAI | SAI_Reserved_49 | DEVICE_UNTRUSTED_IAL_SAI |  */
/*    SAI_Reserved_51 | CORE_EVENT_PROXY_SAI | DEVICE_ABORT_SAI |               */
/*    RCIOMMU_BYPASS_SAI | SAI_Reserved_55 | SAI_Reserved_56 | IE_CSE_SAI |     */
/*    SAI_Reserved_58 | SAI_Reserved_59 | CPM_SAI | OOB_MSM_SAI | XGBE_SAI |    */
/*    DEVICE_UNTRUSTED_SAI                                                      */
/*  Security_WriteAccess_Str:                                                   */
/*    HOSTIA_UCODE_SAI | HOSTIA_SUNPASS_SAI | PM_PCS_SAI |                      */
/*    DFX_INTEL_MANUFACTURING_SAI | DFX_INTEL_PRODUCTION_SAI | HOSTIA_BOOT_SAI  */
/*    | HOSTIA_SMM_SAI | OOB_MSM_SAI                                            */
/*  Security_Read_CP_Secured:                                                   */
/*    0                                                                         */
/* LB_W                                                                         */
/*  Security_ReadAccess_Str:                                                    */
/*    HOSTIA_POSTBOOT_SAI | HOSTIA_UCODE_SAI | HOSTIA_SMM_SAI |                 */
/*    HOSTIA_SUNPASS_SAI | HOSTIA_BOOT_SAI | SAI_Reserved_5 | SAI_Reserved_6 |  */
/*    SAI_Reserved_7 | GT_SAI | PM_PCS_SAI | HW_CPU_SAI | MEM_CPL_SAI | VTD_SAI */
/*    | PM_DIE_TO_DIE_SAI | OOB_MSM_UNTRUSTED_SAI | HOSTCP_PMA_SAI |            */
/*    CSE_INTEL_SAI | CSE_OEM_SAI | FUSE_CTRL_SAI | FUSE_PULLER_SAI |           */
/*    PECI_MSM_SAI | PM_IOSS_SAI | CSE_DNX_SAI | FXR_INTERNAL_SAI |             */
/*    DFX_INTEL_MANUFACTURING_SAI | DFX_UNTRUSTED_SAI | SAI_Reserved_26 |       */
/*    IRC_SAI | NPK_SAI | DISPLAY2_SAI | DISPLAY3_SAI | HW_PCH_SAI |            */
/*    SAI_Reserved_32 | SAI_Reserved_33 | SAI_Reserved_34 | GT_PMA_SAI |        */
/*    HSP_SAI | SAI_Reserved_37 | SAI_Reserved_38 | SAI_Reserved_39 |           */
/*    UNCORE_PMA_SAI | RC_MORPHED_SAI | DFX_INTEL_PRODUCTION_SAI |              */
/*    DFX_THIRDPARTY_SAI | DISPLAY_SAI | SAI_Reserved_45 | SAI_Reserved_46 |    */
/*    DISPLAY_KVM_SAI | GT2_SAI | SAI_Reserved_49 | DEVICE_UNTRUSTED_IAL_SAI |  */
/*    SAI_Reserved_51 | CORE_EVENT_PROXY_SAI | DEVICE_ABORT_SAI |               */
/*    RCIOMMU_BYPASS_SAI | SAI_Reserved_55 | SAI_Reserved_56 | IE_CSE_SAI |     */
/*    SAI_Reserved_58 | SAI_Reserved_59 | CPM_SAI | OOB_MSM_SAI | XGBE_SAI |    */
/*    DEVICE_UNTRUSTED_SAI                                                      */
/*  Security_WriteAccess_Str:                                                   */
/*    HOSTIA_UCODE_SAI | HOSTIA_SUNPASS_SAI | PM_PCS_SAI |                      */
/*    DFX_INTEL_MANUFACTURING_SAI | DFX_INTEL_PRODUCTION_SAI | HOSTIA_BOOT_SAI  */
/*    | HOSTIA_SMM_SAI | OOB_MSM_SAI                                            */
/*  Security_Read_CP_Secured:                                                   */
/*    0                                                                         */
/* OS_W                                                                         */
/*  Security_ReadAccess_Str:                                                    */
/*    HOSTIA_POSTBOOT_SAI | HOSTIA_UCODE_SAI | HOSTIA_SMM_SAI |                 */
/*    HOSTIA_SUNPASS_SAI | HOSTIA_BOOT_SAI | SAI_Reserved_5 | SAI_Reserved_6 |  */
/*    SAI_Reserved_7 | GT_SAI | PM_PCS_SAI | HW_CPU_SAI | MEM_CPL_SAI | VTD_SAI */
/*    | PM_DIE_TO_DIE_SAI | OOB_MSM_UNTRUSTED_SAI | HOSTCP_PMA_SAI |            */
/*    CSE_INTEL_SAI | CSE_OEM_SAI | FUSE_CTRL_SAI | FUSE_PULLER_SAI |           */
/*    PECI_MSM_SAI | PM_IOSS_SAI | CSE_DNX_SAI | FXR_INTERNAL_SAI |             */
/*    DFX_INTEL_MANUFACTURING_SAI | DFX_UNTRUSTED_SAI | SAI_Reserved_26 |       */
/*    IRC_SAI | NPK_SAI | DISPLAY2_SAI | DISPLAY3_SAI | HW_PCH_SAI |            */
/*    SAI_Reserved_32 | SAI_Reserved_33 | SAI_Reserved_34 | GT_PMA_SAI |        */
/*    HSP_SAI | SAI_Reserved_37 | SAI_Reserved_38 | SAI_Reserved_39 |           */
/*    UNCORE_PMA_SAI | RC_MORPHED_SAI | DFX_INTEL_PRODUCTION_SAI |              */
/*    DFX_THIRDPARTY_SAI | DISPLAY_SAI | SAI_Reserved_45 | SAI_Reserved_46 |    */
/*    DISPLAY_KVM_SAI | GT2_SAI | SAI_Reserved_49 | DEVICE_UNTRUSTED_IAL_SAI |  */
/*    SAI_Reserved_51 | CORE_EVENT_PROXY_SAI | DEVICE_ABORT_SAI |               */
/*    RCIOMMU_BYPASS_SAI | SAI_Reserved_55 | SAI_Reserved_56 | IE_CSE_SAI |     */
/*    SAI_Reserved_58 | SAI_Reserved_59 | CPM_SAI | OOB_MSM_SAI | XGBE_SAI |    */
/*    DEVICE_UNTRUSTED_SAI                                                      */
/*  Security_WriteAccess_Str:                                                   */
/*    HOSTIA_POSTBOOT_SAI | HOSTIA_UCODE_SAI | HOSTIA_SMM_SAI |                 */
/*    HOSTIA_SUNPASS_SAI | HOSTIA_BOOT_SAI | PM_PCS_SAI |                       */
/*    DFX_INTEL_MANUFACTURING_SAI | DFX_INTEL_PRODUCTION_SAI |                  */
/*    DFX_UNTRUSTED_SAI | OOB_MSM_SAI | DFX_THIRDPARTY_SAI                      */
/*  Security_Read_CP_Secured:                                                   */
/*    0                                                                         */
/* P_U_CODE                                                                     */
/*  Security_ReadAccess_Str:                                                    */
/*    HOSTIA_UCODE_SAI | HOSTIA_SUNPASS_SAI | PM_PCS_SAI |                      */
/*    DFX_INTEL_MANUFACTURING_SAI | DFX_INTEL_PRODUCTION_SAI | UNCORE_PMA_SAI | */
/*    OOB_MSM_SAI                                                               */
/*  Security_WriteAccess_Str:                                                   */
/*    HOSTIA_UCODE_SAI | HOSTIA_SUNPASS_SAI | PM_PCS_SAI |                      */
/*    DFX_INTEL_MANUFACTURING_SAI | DFX_INTEL_PRODUCTION_SAI                    */
/*  Security_Read_CP_Secured:                                                   */
/*    0                                                                         */

/* EMRXCC Security Policy Groups:                                               */
/* LB_MCHECK_W                                                                  */
/*  Security_ReadAccess_Str:                                                    */
/*    HOSTIA_POSTBOOT_SAI | HOSTIA_UCODE_SAI | HOSTIA_SMM_SAI |                 */
/*    HOSTIA_SUNPASS_SAI | HOSTIA_BOOT_SAI | SAI_Reserved_5 | SAI_Reserved_6 |  */
/*    SAI_Reserved_7 | GT_SAI | PM_PCS_SAI | HW_CPU_SAI | MEM_CPL_SAI | VTD_SAI */
/*    | PM_DIE_TO_DIE_SAI | OOB_MSM_UNTRUSTED_SAI | HOSTCP_PMA_SAI |            */
/*    CSE_INTEL_SAI | CSE_OEM_SAI | FUSE_CTRL_SAI | FUSE_PULLER_SAI |           */
/*    PECI_MSM_SAI | PM_IOSS_SAI | CSE_DNX_SAI | FXR_INTERNAL_SAI |             */
/*    DFX_INTEL_MANUFACTURING_SAI | DFX_UNTRUSTED_SAI | SAI_Reserved_26 |       */
/*    IRC_SAI | NPK_SAI | DISPLAY2_SAI | DISPLAY3_SAI | HW_PCH_SAI |            */
/*    SAI_Reserved_32 | SAI_Reserved_33 | SAI_Reserved_34 | GT_PMA_SAI |        */
/*    HSP_SAI | SAI_Reserved_37 | SAI_Reserved_38 | SAI_Reserved_39 |           */
/*    UNCORE_PMA_SAI | RC_MORPHED_SAI | DFX_INTEL_PRODUCTION_SAI |              */
/*    DFX_THIRDPARTY_SAI | DISPLAY_SAI | SAI_Reserved_45 | SAI_Reserved_46 |    */
/*    DISPLAY_KVM_SAI | GT2_SAI | SAI_Reserved_49 | DEVICE_UNTRUSTED_IAL_SAI |  */
/*    SAI_Reserved_51 | CORE_EVENT_PROXY_SAI | DEVICE_ABORT_SAI |               */
/*    RCIOMMU_BYPASS_SAI | SAI_Reserved_55 | SAI_Reserved_56 | IE_CSE_SAI |     */
/*    SAI_Reserved_58 | SAI_Reserved_59 | CPM_SAI | OOB_MSM_SAI | XGBE_SAI |    */
/*    DEVICE_UNTRUSTED_SAI                                                      */
/*  Security_WriteAccess_Str:                                                   */
/*    HOSTIA_UCODE_SAI | HOSTIA_SUNPASS_SAI | PM_PCS_SAI |                      */
/*    DFX_INTEL_MANUFACTURING_SAI | DFX_INTEL_PRODUCTION_SAI | HOSTIA_BOOT_SAI  */
/*    | HOSTIA_SMM_SAI | OOB_MSM_SAI                                            */
/*  Security_Read_CP_Secured:                                                   */
/*    0                                                                         */
/* LB_W                                                                         */
/*  Security_ReadAccess_Str:                                                    */
/*    HOSTIA_POSTBOOT_SAI | HOSTIA_UCODE_SAI | HOSTIA_SMM_SAI |                 */
/*    HOSTIA_SUNPASS_SAI | HOSTIA_BOOT_SAI | SAI_Reserved_5 | SAI_Reserved_6 |  */
/*    SAI_Reserved_7 | GT_SAI | PM_PCS_SAI | HW_CPU_SAI | MEM_CPL_SAI | VTD_SAI */
/*    | PM_DIE_TO_DIE_SAI | OOB_MSM_UNTRUSTED_SAI | HOSTCP_PMA_SAI |            */
/*    CSE_INTEL_SAI | CSE_OEM_SAI | FUSE_CTRL_SAI | FUSE_PULLER_SAI |           */
/*    PECI_MSM_SAI | PM_IOSS_SAI | CSE_DNX_SAI | FXR_INTERNAL_SAI |             */
/*    DFX_INTEL_MANUFACTURING_SAI | DFX_UNTRUSTED_SAI | SAI_Reserved_26 |       */
/*    IRC_SAI | NPK_SAI | DISPLAY2_SAI | DISPLAY3_SAI | HW_PCH_SAI |            */
/*    SAI_Reserved_32 | SAI_Reserved_33 | SAI_Reserved_34 | GT_PMA_SAI |        */
/*    HSP_SAI | SAI_Reserved_37 | SAI_Reserved_38 | SAI_Reserved_39 |           */
/*    UNCORE_PMA_SAI | RC_MORPHED_SAI | DFX_INTEL_PRODUCTION_SAI |              */
/*    DFX_THIRDPARTY_SAI | DISPLAY_SAI | SAI_Reserved_45 | SAI_Reserved_46 |    */
/*    DISPLAY_KVM_SAI | GT2_SAI | SAI_Reserved_49 | DEVICE_UNTRUSTED_IAL_SAI |  */
/*    SAI_Reserved_51 | CORE_EVENT_PROXY_SAI | DEVICE_ABORT_SAI |               */
/*    RCIOMMU_BYPASS_SAI | SAI_Reserved_55 | SAI_Reserved_56 | IE_CSE_SAI |     */
/*    SAI_Reserved_58 | SAI_Reserved_59 | CPM_SAI | OOB_MSM_SAI | XGBE_SAI |    */
/*    DEVICE_UNTRUSTED_SAI                                                      */
/*  Security_WriteAccess_Str:                                                   */
/*    HOSTIA_UCODE_SAI | HOSTIA_SUNPASS_SAI | PM_PCS_SAI |                      */
/*    DFX_INTEL_MANUFACTURING_SAI | DFX_INTEL_PRODUCTION_SAI | HOSTIA_BOOT_SAI  */
/*    | HOSTIA_SMM_SAI | OOB_MSM_SAI                                            */
/*  Security_Read_CP_Secured:                                                   */
/*    0                                                                         */
/* OS_W                                                                         */
/*  Security_ReadAccess_Str:                                                    */
/*    HOSTIA_POSTBOOT_SAI | HOSTIA_UCODE_SAI | HOSTIA_SMM_SAI |                 */
/*    HOSTIA_SUNPASS_SAI | HOSTIA_BOOT_SAI | SAI_Reserved_5 | SAI_Reserved_6 |  */
/*    SAI_Reserved_7 | GT_SAI | PM_PCS_SAI | HW_CPU_SAI | MEM_CPL_SAI | VTD_SAI */
/*    | PM_DIE_TO_DIE_SAI | OOB_MSM_UNTRUSTED_SAI | HOSTCP_PMA_SAI |            */
/*    CSE_INTEL_SAI | CSE_OEM_SAI | FUSE_CTRL_SAI | FUSE_PULLER_SAI |           */
/*    PECI_MSM_SAI | PM_IOSS_SAI | CSE_DNX_SAI | FXR_INTERNAL_SAI |             */
/*    DFX_INTEL_MANUFACTURING_SAI | DFX_UNTRUSTED_SAI | SAI_Reserved_26 |       */
/*    IRC_SAI | NPK_SAI | DISPLAY2_SAI | DISPLAY3_SAI | HW_PCH_SAI |            */
/*    SAI_Reserved_32 | SAI_Reserved_33 | SAI_Reserved_34 | GT_PMA_SAI |        */
/*    HSP_SAI | SAI_Reserved_37 | SAI_Reserved_38 | SAI_Reserved_39 |           */
/*    UNCORE_PMA_SAI | RC_MORPHED_SAI | DFX_INTEL_PRODUCTION_SAI |              */
/*    DFX_THIRDPARTY_SAI | DISPLAY_SAI | SAI_Reserved_45 | SAI_Reserved_46 |    */
/*    DISPLAY_KVM_SAI | GT2_SAI | SAI_Reserved_49 | DEVICE_UNTRUSTED_IAL_SAI |  */
/*    SAI_Reserved_51 | CORE_EVENT_PROXY_SAI | DEVICE_ABORT_SAI |               */
/*    RCIOMMU_BYPASS_SAI | SAI_Reserved_55 | SAI_Reserved_56 | IE_CSE_SAI |     */
/*    SAI_Reserved_58 | SAI_Reserved_59 | CPM_SAI | OOB_MSM_SAI | XGBE_SAI |    */
/*    DEVICE_UNTRUSTED_SAI                                                      */
/*  Security_WriteAccess_Str:                                                   */
/*    HOSTIA_POSTBOOT_SAI | HOSTIA_UCODE_SAI | HOSTIA_SMM_SAI |                 */
/*    HOSTIA_SUNPASS_SAI | HOSTIA_BOOT_SAI | PM_PCS_SAI |                       */
/*    DFX_INTEL_MANUFACTURING_SAI | DFX_INTEL_PRODUCTION_SAI |                  */
/*    DFX_UNTRUSTED_SAI | OOB_MSM_SAI | DFX_THIRDPARTY_SAI                      */
/*  Security_Read_CP_Secured:                                                   */
/*    0                                                                         */
/* P_U_CODE                                                                     */
/*  Security_ReadAccess_Str:                                                    */
/*    HOSTIA_UCODE_SAI | HOSTIA_SUNPASS_SAI | PM_PCS_SAI |                      */
/*    DFX_INTEL_MANUFACTURING_SAI | DFX_INTEL_PRODUCTION_SAI | UNCORE_PMA_SAI | */
/*    OOB_MSM_SAI                                                               */
/*  Security_WriteAccess_Str:                                                   */
/*    HOSTIA_UCODE_SAI | HOSTIA_SUNPASS_SAI | PM_PCS_SAI |                      */
/*    DFX_INTEL_MANUFACTURING_SAI | DFX_INTEL_PRODUCTION_SAI                    */
/*  Security_Read_CP_Secured:                                                   */
/*    0                                                                         */

/* SPRE0 Security Policy Groups:                                                */
/* LB_MCHECK_W                                                                  */
/*  Security_ReadAccess_Str:                                                    */
/*    HOSTIA_POSTBOOT_SAI | HOSTIA_UCODE_SAI | HOSTIA_SMM_SAI |                 */
/*    HOSTIA_SUNPASS_SAI | HOSTIA_BOOT_SAI | SAI_Reserved_5 | SAI_Reserved_6 |  */
/*    SAI_Reserved_7 | GT_SAI | PM_PCS_SAI | HW_CPU_SAI | MEM_CPL_SAI | VTD_SAI */
/*    | PM_DIE_TO_DIE_SAI | OOB_MSM_UNTRUSTED_SAI | HOSTCP_PMA_SAI |            */
/*    CSE_INTEL_SAI | CSE_OEM_SAI | FUSE_CTRL_SAI | FUSE_PULLER_SAI |           */
/*    PECI_MSM_SAI | PM_IOSS_SAI | CSE_DNX_SAI | FXR_INTERNAL_SAI |             */
/*    DFX_INTEL_MANUFACTURING_SAI | DFX_UNTRUSTED_SAI | SAI_Reserved_26 |       */
/*    IRC_SAI | NPK_SAI | DISPLAY2_SAI | DISPLAY3_SAI | HW_PCH_SAI |            */
/*    SAI_Reserved_32 | SAI_Reserved_33 | SAI_Reserved_34 | GT_PMA_SAI |        */
/*    HSP_SAI | SAI_Reserved_37 | SAI_Reserved_38 | SAI_Reserved_39 |           */
/*    UNCORE_PMA_SAI | RC_MORPHED_SAI | DFX_INTEL_PRODUCTION_SAI |              */
/*    DFX_THIRDPARTY_SAI | DISPLAY_SAI | SAI_Reserved_45 | SAI_Reserved_46 |    */
/*    DISPLAY_KVM_SAI | GT2_SAI | SAI_Reserved_49 | DEVICE_UNTRUSTED_IAL_SAI |  */
/*    SAI_Reserved_51 | CORE_EVENT_PROXY_SAI | DEVICE_ABORT_SAI |               */
/*    RCIOMMU_BYPASS_SAI | SAI_Reserved_55 | SAI_Reserved_56 | IE_CSE_SAI |     */
/*    SAI_Reserved_58 | SAI_Reserved_59 | CPM_SAI | OOB_MSM_SAI | XGBE_SAI |    */
/*    DEVICE_UNTRUSTED_SAI                                                      */
/*  Security_WriteAccess_Str:                                                   */
/*    HOSTIA_UCODE_SAI | HOSTIA_SUNPASS_SAI | PM_PCS_SAI |                      */
/*    DFX_INTEL_MANUFACTURING_SAI | DFX_INTEL_PRODUCTION_SAI | HOSTIA_BOOT_SAI  */
/*    | HOSTIA_SMM_SAI | OOB_MSM_SAI                                            */
/*  Security_Read_CP_Secured:                                                   */
/*    0                                                                         */
/* LB_W                                                                         */
/*  Security_ReadAccess_Str:                                                    */
/*    HOSTIA_POSTBOOT_SAI | HOSTIA_UCODE_SAI | HOSTIA_SMM_SAI |                 */
/*    HOSTIA_SUNPASS_SAI | HOSTIA_BOOT_SAI | SAI_Reserved_5 | SAI_Reserved_6 |  */
/*    SAI_Reserved_7 | GT_SAI | PM_PCS_SAI | HW_CPU_SAI | MEM_CPL_SAI | VTD_SAI */
/*    | PM_DIE_TO_DIE_SAI | OOB_MSM_UNTRUSTED_SAI | HOSTCP_PMA_SAI |            */
/*    CSE_INTEL_SAI | CSE_OEM_SAI | FUSE_CTRL_SAI | FUSE_PULLER_SAI |           */
/*    PECI_MSM_SAI | PM_IOSS_SAI | CSE_DNX_SAI | FXR_INTERNAL_SAI |             */
/*    DFX_INTEL_MANUFACTURING_SAI | DFX_UNTRUSTED_SAI | SAI_Reserved_26 |       */
/*    IRC_SAI | NPK_SAI | DISPLAY2_SAI | DISPLAY3_SAI | HW_PCH_SAI |            */
/*    SAI_Reserved_32 | SAI_Reserved_33 | SAI_Reserved_34 | GT_PMA_SAI |        */
/*    HSP_SAI | SAI_Reserved_37 | SAI_Reserved_38 | SAI_Reserved_39 |           */
/*    UNCORE_PMA_SAI | RC_MORPHED_SAI | DFX_INTEL_PRODUCTION_SAI |              */
/*    DFX_THIRDPARTY_SAI | DISPLAY_SAI | SAI_Reserved_45 | SAI_Reserved_46 |    */
/*    DISPLAY_KVM_SAI | GT2_SAI | SAI_Reserved_49 | DEVICE_UNTRUSTED_IAL_SAI |  */
/*    SAI_Reserved_51 | CORE_EVENT_PROXY_SAI | DEVICE_ABORT_SAI |               */
/*    RCIOMMU_BYPASS_SAI | SAI_Reserved_55 | SAI_Reserved_56 | IE_CSE_SAI |     */
/*    SAI_Reserved_58 | SAI_Reserved_59 | CPM_SAI | OOB_MSM_SAI | XGBE_SAI |    */
/*    DEVICE_UNTRUSTED_SAI                                                      */
/*  Security_WriteAccess_Str:                                                   */
/*    HOSTIA_UCODE_SAI | HOSTIA_SUNPASS_SAI | PM_PCS_SAI |                      */
/*    DFX_INTEL_MANUFACTURING_SAI | DFX_INTEL_PRODUCTION_SAI | HOSTIA_BOOT_SAI  */
/*    | HOSTIA_SMM_SAI | OOB_MSM_SAI                                            */
/*  Security_Read_CP_Secured:                                                   */
/*    0                                                                         */
/* OS_W                                                                         */
/*  Security_ReadAccess_Str:                                                    */
/*    HOSTIA_POSTBOOT_SAI | HOSTIA_UCODE_SAI | HOSTIA_SMM_SAI |                 */
/*    HOSTIA_SUNPASS_SAI | HOSTIA_BOOT_SAI | SAI_Reserved_5 | SAI_Reserved_6 |  */
/*    SAI_Reserved_7 | GT_SAI | PM_PCS_SAI | HW_CPU_SAI | MEM_CPL_SAI | VTD_SAI */
/*    | PM_DIE_TO_DIE_SAI | OOB_MSM_UNTRUSTED_SAI | HOSTCP_PMA_SAI |            */
/*    CSE_INTEL_SAI | CSE_OEM_SAI | FUSE_CTRL_SAI | FUSE_PULLER_SAI |           */
/*    PECI_MSM_SAI | PM_IOSS_SAI | CSE_DNX_SAI | FXR_INTERNAL_SAI |             */
/*    DFX_INTEL_MANUFACTURING_SAI | DFX_UNTRUSTED_SAI | SAI_Reserved_26 |       */
/*    IRC_SAI | NPK_SAI | DISPLAY2_SAI | DISPLAY3_SAI | HW_PCH_SAI |            */
/*    SAI_Reserved_32 | SAI_Reserved_33 | SAI_Reserved_34 | GT_PMA_SAI |        */
/*    HSP_SAI | SAI_Reserved_37 | SAI_Reserved_38 | SAI_Reserved_39 |           */
/*    UNCORE_PMA_SAI | RC_MORPHED_SAI | DFX_INTEL_PRODUCTION_SAI |              */
/*    DFX_THIRDPARTY_SAI | DISPLAY_SAI | SAI_Reserved_45 | SAI_Reserved_46 |    */
/*    DISPLAY_KVM_SAI | GT2_SAI | SAI_Reserved_49 | DEVICE_UNTRUSTED_IAL_SAI |  */
/*    SAI_Reserved_51 | CORE_EVENT_PROXY_SAI | DEVICE_ABORT_SAI |               */
/*    RCIOMMU_BYPASS_SAI | SAI_Reserved_55 | SAI_Reserved_56 | IE_CSE_SAI |     */
/*    SAI_Reserved_58 | SAI_Reserved_59 | CPM_SAI | OOB_MSM_SAI | XGBE_SAI |    */
/*    DEVICE_UNTRUSTED_SAI                                                      */
/*  Security_WriteAccess_Str:                                                   */
/*    HOSTIA_POSTBOOT_SAI | HOSTIA_UCODE_SAI | HOSTIA_SMM_SAI |                 */
/*    HOSTIA_SUNPASS_SAI | HOSTIA_BOOT_SAI | PM_PCS_SAI |                       */
/*    DFX_INTEL_MANUFACTURING_SAI | DFX_INTEL_PRODUCTION_SAI |                  */
/*    DFX_UNTRUSTED_SAI | OOB_MSM_SAI | DFX_THIRDPARTY_SAI                      */
/*  Security_Read_CP_Secured:                                                   */
/*    0                                                                         */
/* P_U_CODE                                                                     */
/*  Security_ReadAccess_Str:                                                    */
/*    HOSTIA_UCODE_SAI | HOSTIA_SUNPASS_SAI | PM_PCS_SAI |                      */
/*    DFX_INTEL_MANUFACTURING_SAI | DFX_INTEL_PRODUCTION_SAI | UNCORE_PMA_SAI | */
/*    OOB_MSM_SAI                                                               */
/*  Security_WriteAccess_Str:                                                   */
/*    HOSTIA_UCODE_SAI | HOSTIA_SUNPASS_SAI | PM_PCS_SAI |                      */
/*    DFX_INTEL_MANUFACTURING_SAI | DFX_INTEL_PRODUCTION_SAI                    */
/*  Security_Read_CP_Secured:                                                   */
/*    0                                                                         */


#ifndef _UBOX_MISC_h
#define _UBOX_MISC_h
#include <Base.h>

/* VID_0_0_2_UBOX_MISC_REG supported on:                                        */
/*      SPRA0 (0x11e02000)                                                      */
/*      SPRB0 (0x11e02000)                                                      */
/*      SPRHBMA0 (0x11e02000)                                                   */
/*      SPRC0 (0x11e02000)                                                      */
/*      SPRMCC (0x11e02000)                                                     */
/*      SPRD0 (0x11e02000)                                                      */
/*      SPRHBMB0 (0x11e02000)                                                   */
/*      SPRLCC (0x11e02000)                                                     */
/*      EMRXCC (0x11e02000)                                                     */
/*      SPRE0 (0x11e02000)                                                      */
/* Register default value on SPRA0: 0x00008086                                  */
/* Register default value on SPRB0: 0x00008086                                  */
/* Register default value on SPRHBMA0: 0x00008086                               */
/* Register default value on SPRC0: 0x00008086                                  */
/* Register default value on SPRMCC: 0x00008086                                 */
/* Register default value on SPRD0: 0x00008086                                  */
/* Register default value on SPRHBMB0: 0x00008086                               */
/* Register default value on SPRLCC: 0x00008086                                 */
/* Register default value on EMRXCC: 0x00008086                                 */
/* Register default value on SPRE0: 0x00008086                                  */
/* SPRA0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_PCIE_RIDCCR_0_0_2   */
/* SPRB0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_PCIE_RIDCCR_0_0_2   */
/* SPRHBMA0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_PCIE_RIDCCR_0_0_2*/
/* SPRC0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_PCIE_RIDCCR_0_0_2   */
/* SPRMCC Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_PCIE_RIDCCR_0_0_2  */
/* SPRD0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_PCIE_RIDCCR_0_0_2   */
/* SPRHBMB0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_PCIE_RIDCCR_0_0_2*/
/* SPRLCC Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_PCIE_RIDCCR_0_0_2  */
/* EMRXCC Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_PCIE_RIDCCR_0_0_2  */
/* SPRE0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_PCIE_RIDCCR_0_0_2   */
/* Struct generated from SPRA0 BDF: 30_0_2                                      */
/* SPRA0 Security PolicyGroup: OS_W                                             */
/* SPRB0 Security PolicyGroup: OS_W                                             */
/* SPRHBMA0 Security PolicyGroup: OS_W                                          */
/* SPRC0 Security PolicyGroup: OS_W                                             */
/* SPRMCC Security PolicyGroup: OS_W                                            */
/* SPRD0 Security PolicyGroup: OS_W                                             */
/* SPRHBMB0 Security PolicyGroup: OS_W                                          */
/* SPRLCC Security PolicyGroup: OS_W                                            */
/* EMRXCC Security PolicyGroup: OS_W                                            */
/* SPRE0 Security PolicyGroup: OS_W                                             */
/* PCI Vendor ID Register
*/


#define VID_0_0_2_UBOX_MISC_REG 0x13210000

typedef union {
  ///
  /// Individual bit fields
  ///
  struct {
    UINT16 vendor_identification_number : 16;

                            /* Bits[15:0], Access Type=RO, default=0x00008086*/

                            /* The value is assigned by PCI-SIG to Intel. */

  } Bits;
  UINT16 Data;

} VID_0_0_2_UBOX_MISC_STRUCT;

/* DID_0_0_2_UBOX_MISC_REG supported on:                                        */
/*      SPRA0 (0x11e02002)                                                      */
/*      SPRB0 (0x11e02002)                                                      */
/*      SPRHBMA0 (0x11e02002)                                                   */
/*      SPRC0 (0x11e02002)                                                      */
/*      SPRMCC (0x11e02002)                                                     */
/*      SPRD0 (0x11e02002)                                                      */
/*      SPRHBMB0 (0x11e02002)                                                   */
/*      SPRLCC (0x11e02002)                                                     */
/*      EMRXCC (0x11e02002)                                                     */
/*      SPRE0 (0x11e02002)                                                      */
/* Register default value on SPRA0: 0x00003252                                  */
/* Register default value on SPRB0: 0x00003252                                  */
/* Register default value on SPRHBMA0: 0x00003252                               */
/* Register default value on SPRC0: 0x00003252                                  */
/* Register default value on SPRMCC: 0x00003252                                 */
/* Register default value on SPRD0: 0x00003252                                  */
/* Register default value on SPRHBMB0: 0x00003252                               */
/* Register default value on SPRLCC: 0x00003252                                 */
/* Register default value on EMRXCC: 0x00003252                                 */
/* Register default value on SPRE0: 0x00003252                                  */
/* SPRA0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_PCIE_RIDCCR_0_0_2   */
/* SPRB0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_PCIE_RIDCCR_0_0_2   */
/* SPRHBMA0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_PCIE_RIDCCR_0_0_2*/
/* SPRC0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_PCIE_RIDCCR_0_0_2   */
/* SPRMCC Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_PCIE_RIDCCR_0_0_2  */
/* SPRD0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_PCIE_RIDCCR_0_0_2   */
/* SPRHBMB0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_PCIE_RIDCCR_0_0_2*/
/* SPRLCC Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_PCIE_RIDCCR_0_0_2  */
/* EMRXCC Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_PCIE_RIDCCR_0_0_2  */
/* SPRE0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_PCIE_RIDCCR_0_0_2   */
/* Struct generated from SPRA0 BDF: 30_0_2                                      */
/* SPRA0 Security PolicyGroup: OS_W                                             */
/* SPRB0 Security PolicyGroup: OS_W                                             */
/* SPRHBMA0 Security PolicyGroup: OS_W                                          */
/* SPRC0 Security PolicyGroup: OS_W                                             */
/* SPRMCC Security PolicyGroup: OS_W                                            */
/* SPRD0 Security PolicyGroup: OS_W                                             */
/* SPRHBMB0 Security PolicyGroup: OS_W                                          */
/* SPRLCC Security PolicyGroup: OS_W                                            */
/* EMRXCC Security PolicyGroup: OS_W                                            */
/* SPRE0 Security PolicyGroup: OS_W                                             */
/* PCI Device Identification Number
*/


#define DID_0_0_2_UBOX_MISC_REG 0x13210002

typedef union {
  ///
  /// Individual bit fields
  ///
  struct {
    UINT16 device_identification_number : 16;

                            /* Bits[15:0], Access Type=RO, default=0x00003252*/

                            /*
                               The value is assigned by each IP/function owner
                               as a unique identifier.
                            */

  } Bits;
  UINT16 Data;

} DID_0_0_2_UBOX_MISC_STRUCT;

/* PCICMD_0_0_2_UBOX_MISC_REG supported on:                                     */
/*      SPRA0 (0x11e02004)                                                      */
/*      SPRB0 (0x11e02004)                                                      */
/*      SPRHBMA0 (0x11e02004)                                                   */
/*      SPRC0 (0x11e02004)                                                      */
/*      SPRMCC (0x11e02004)                                                     */
/*      SPRD0 (0x11e02004)                                                      */
/*      SPRHBMB0 (0x11e02004)                                                   */
/*      SPRLCC (0x11e02004)                                                     */
/*      EMRXCC (0x11e02004)                                                     */
/*      SPRE0 (0x11e02004)                                                      */
/* Register default value on SPRA0: 0x00000000                                  */
/* Register default value on SPRB0: 0x00000000                                  */
/* Register default value on SPRHBMA0: 0x00000000                               */
/* Register default value on SPRC0: 0x00000000                                  */
/* Register default value on SPRMCC: 0x00000000                                 */
/* Register default value on SPRD0: 0x00000000                                  */
/* Register default value on SPRHBMB0: 0x00000000                               */
/* Register default value on SPRLCC: 0x00000000                                 */
/* Register default value on EMRXCC: 0x00000000                                 */
/* Register default value on SPRE0: 0x00000000                                  */
/* SPRA0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_PCIE_RIDCCR_0_0_2   */
/* SPRB0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_PCIE_RIDCCR_0_0_2   */
/* SPRHBMA0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_PCIE_RIDCCR_0_0_2*/
/* SPRC0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_PCIE_RIDCCR_0_0_2   */
/* SPRMCC Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_PCIE_RIDCCR_0_0_2  */
/* SPRD0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_PCIE_RIDCCR_0_0_2   */
/* SPRHBMB0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_PCIE_RIDCCR_0_0_2*/
/* SPRLCC Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_PCIE_RIDCCR_0_0_2  */
/* EMRXCC Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_PCIE_RIDCCR_0_0_2  */
/* SPRE0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_PCIE_RIDCCR_0_0_2   */
/* Struct generated from SPRA0 BDF: 30_0_2                                      */
/* SPRA0 Security PolicyGroup: OS_W                                             */
/* SPRB0 Security PolicyGroup: OS_W                                             */
/* SPRHBMA0 Security PolicyGroup: OS_W                                          */
/* SPRC0 Security PolicyGroup: OS_W                                             */
/* SPRMCC Security PolicyGroup: OS_W                                            */
/* SPRD0 Security PolicyGroup: OS_W                                             */
/* SPRHBMB0 Security PolicyGroup: OS_W                                          */
/* SPRLCC Security PolicyGroup: OS_W                                            */
/* EMRXCC Security PolicyGroup: OS_W                                            */
/* SPRE0 Security PolicyGroup: OS_W                                             */
/* PCI Command Register
*/


#define PCICMD_0_0_2_UBOX_MISC_REG 0x13210004

typedef union {
  ///
  /// Individual bit fields
  ///
  struct {
    UINT16 io_space_enable : 1;

                            /* Bits[0:0], Access Type=RO, default=0x00000000*/

                            /*
                               Hardwired to 0 since these devices dont decode
                               any IO BARs
                            */
    UINT16 memory_space_enable : 1;

                            /* Bits[1:1], Access Type=RO, default=0x00000000*/

                            /*
                               Hardwired to 0 since these devices dont decode
                               any memory BARs
                            */
    UINT16 bus_master_enable : 1;

                            /* Bits[2:2], Access Type=RO, default=0x00000000*/

                            /*
                               Hardwired to 0 since these devices dont generate
                               any transactions
                            */
    UINT16 special_cycle_enable : 1;

                            /* Bits[3:3], Access Type=RO, default=0x00000000*/

                            /* Not applicable. Hardwired to 0. */
    UINT16 memory_write_and_invalidate_enable : 1;

                            /* Bits[4:4], Access Type=RO, default=0x00000000*/

                            /*
                               Not applicable to internal devices. Hardwired to
                               0.
                            */
    UINT16 vga_palette_snoop_enable : 1;

                            /* Bits[5:5], Access Type=RO, default=0x00000000*/

                            /*
                               Not applicable to internal devices. Hardwired to
                               0.
                            */
    UINT16 parity_error_response : 1;

                            /* Bits[6:6], Access Type=RO, default=0x00000000*/

                            /*
                               This bit has no impact on error reporting from
                               these devices
                            */
    UINT16 idsel_stepping_wait_cycle_control : 1;

                            /* Bits[7:7], Access Type=RO, default=0x00000000*/

                            /*
                               Not applicable to internal devices. Hardwired to
                               0.
                            */
    UINT16 serr_enable : 1;

                            /* Bits[8:8], Access Type=RO, default=0x00000000*/

                            /*
                               This bit has no impact on error reporting from
                               these devices
                            */
    UINT16 fast_back_to_back_enable : 1;

                            /* Bits[9:9], Access Type=RO, default=0x00000000*/

                            /*
                               Not applicable to PCI Express and is hardwired
                               to 0
                            */
    UINT16 intx_disable : 1;

                            /* Bits[10:10], Access Type=RO, default=0x00000000*/

                            /* N/A for these devices */
    UINT16 rsvd : 5;

                            /* Bits[15:11], Access Type=RO, default=None*/

                            /* Reserved */

  } Bits;
  UINT16 Data;

} PCICMD_0_0_2_UBOX_MISC_STRUCT;

/* PCISTS_0_0_2_UBOX_MISC_REG supported on:                                     */
/*      SPRA0 (0x11e02006)                                                      */
/*      SPRB0 (0x11e02006)                                                      */
/*      SPRHBMA0 (0x11e02006)                                                   */
/*      SPRC0 (0x11e02006)                                                      */
/*      SPRMCC (0x11e02006)                                                     */
/*      SPRD0 (0x11e02006)                                                      */
/*      SPRHBMB0 (0x11e02006)                                                   */
/*      SPRLCC (0x11e02006)                                                     */
/*      EMRXCC (0x11e02006)                                                     */
/*      SPRE0 (0x11e02006)                                                      */
/* Register default value on SPRA0: 0x00000010                                  */
/* Register default value on SPRB0: 0x00000010                                  */
/* Register default value on SPRHBMA0: 0x00000010                               */
/* Register default value on SPRC0: 0x00000010                                  */
/* Register default value on SPRMCC: 0x00000010                                 */
/* Register default value on SPRD0: 0x00000010                                  */
/* Register default value on SPRHBMB0: 0x00000010                               */
/* Register default value on SPRLCC: 0x00000010                                 */
/* Register default value on EMRXCC: 0x00000010                                 */
/* Register default value on SPRE0: 0x00000010                                  */
/* SPRA0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_PCIE_RIDCCR_0_0_2   */
/* SPRB0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_PCIE_RIDCCR_0_0_2   */
/* SPRHBMA0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_PCIE_RIDCCR_0_0_2*/
/* SPRC0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_PCIE_RIDCCR_0_0_2   */
/* SPRMCC Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_PCIE_RIDCCR_0_0_2  */
/* SPRD0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_PCIE_RIDCCR_0_0_2   */
/* SPRHBMB0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_PCIE_RIDCCR_0_0_2*/
/* SPRLCC Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_PCIE_RIDCCR_0_0_2  */
/* EMRXCC Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_PCIE_RIDCCR_0_0_2  */
/* SPRE0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_PCIE_RIDCCR_0_0_2   */
/* Struct generated from SPRA0 BDF: 30_0_2                                      */
/* SPRA0 Security PolicyGroup: OS_W                                             */
/* SPRB0 Security PolicyGroup: OS_W                                             */
/* SPRHBMA0 Security PolicyGroup: OS_W                                          */
/* SPRC0 Security PolicyGroup: OS_W                                             */
/* SPRMCC Security PolicyGroup: OS_W                                            */
/* SPRD0 Security PolicyGroup: OS_W                                             */
/* SPRHBMB0 Security PolicyGroup: OS_W                                          */
/* SPRLCC Security PolicyGroup: OS_W                                            */
/* EMRXCC Security PolicyGroup: OS_W                                            */
/* SPRE0 Security PolicyGroup: OS_W                                             */
/* PCI Status Register
*/


#define PCISTS_0_0_2_UBOX_MISC_REG 0x13210006

typedef union {
  ///
  /// Individual bit fields
  ///
  struct {
    UINT16 rsvd : 3;

                            /* Bits[2:0], Access Type=RO, default=None*/

                            /* Reserved */
    UINT16 intx_status : 1;

                            /* Bits[3:3], Access Type=RO, default=0x00000000*/

                            /*
                               Reflects the state of the INTA# signal at the
                               input of the enable/disable circuit. This bit is
                               set by HW to 1 when the INTA# is asserted. This
                               bit is reset by HW to 0 after the interrupt is
                               cleared (independent of the state of the
                               Interrupt Disable bit in the PCICMD register).
                               Hardwired to 0 on the processor
                            */
    UINT16 capabilities_list : 1;

                            /* Bits[4:4], Access Type=RO, default=0x00000001*/

                            /*
                               This bit indicates the presence of a
                               capabilities list structure. When set to 1,
                               indicates the register at 34h provides an offset
                               into the function.
                            */
    UINT16 x66mhz_capable : 1;

                            /* Bits[5:5], Access Type=RO, default=0x00000000*/

                            /* Not applicable to PCI Express. Hardwired to 0. */
    UINT16 reserved : 1;

                            /* Bits[6:6], Access Type=RO, default=0x00000000*/

                            /* Reserved */
    UINT16 fast_back_to_back : 1;

                            /* Bits[7:7], Access Type=RO, default=0x00000000*/

                            /* Not applicable to PCI Express. Hardwired to 0. */
    UINT16 master_data_parity_error : 1;

                            /* Bits[8:8], Access Type=RO, default=0x00000000*/

                            /* Hardwired to 0 */
    UINT16 devsel_timing : 2;

                            /* Bits[10:9], Access Type=RO, default=0x00000000*/

                            /* Not applicable to PCI Express. Hardwired to 0. */
    UINT16 signaled_target_abort : 1;

                            /* Bits[11:11], Access Type=RO, default=0x00000000*/

                            /* Hardwired to 0 */
    UINT16 received_target_abort : 1;

                            /* Bits[12:12], Access Type=RO, default=0x00000000*/

                            /* Hardwired to 0 */
    UINT16 received_master_abort : 1;

                            /* Bits[13:13], Access Type=RO, default=0x00000000*/

                            /* Hardwired to 0 */
    UINT16 signaled_system_error : 1;

                            /* Bits[14:14], Access Type=RO, default=0x00000000*/

                            /* Hardwired to 0 */
    UINT16 detected_parity_error : 1;

                            /* Bits[15:15], Access Type=RO, default=0x00000000*/

                            /*
                               This bit is set when the device receives a
                               packet on the primary side with an uncorrectable
                               data error (including a packet with poison bit
                               set) or an uncorrectable address/control parity
                               error. The setting of this bit is regardless of
                               the Parity Error Response bit (PERRE) in the
                               PCICMD register.
                            */

  } Bits;
  UINT16 Data;

} PCISTS_0_0_2_UBOX_MISC_STRUCT;

/* RID_CCR_0_0_2_UBOX_MISC_REG supported on:                                    */
/*      SPRA0 (0x21e02008)                                                      */
/*      SPRB0 (0x21e02008)                                                      */
/*      SPRHBMA0 (0x21e02008)                                                   */
/*      SPRC0 (0x21e02008)                                                      */
/*      SPRMCC (0x21e02008)                                                     */
/*      SPRD0 (0x21e02008)                                                      */
/*      SPRHBMB0 (0x21e02008)                                                   */
/*      SPRLCC (0x21e02008)                                                     */
/*      EMRXCC (0x21e02008)                                                     */
/*      SPRE0 (0x21e02008)                                                      */
/* Register default value on SPRA0: 0x08800000                                  */
/* Register default value on SPRB0: 0x08800000                                  */
/* Register default value on SPRHBMA0: 0x08800000                               */
/* Register default value on SPRC0: 0x08800000                                  */
/* Register default value on SPRMCC: 0x08800000                                 */
/* Register default value on SPRD0: 0x08800000                                  */
/* Register default value on SPRHBMB0: 0x08800000                               */
/* Register default value on SPRLCC: 0x08800000                                 */
/* Register default value on EMRXCC: 0x08800000                                 */
/* Register default value on SPRE0: 0x08800000                                  */
/* SPRA0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_PCIE_RIDCCR_0_0_2   */
/* SPRB0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_PCIE_RIDCCR_0_0_2   */
/* SPRHBMA0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_PCIE_RIDCCR_0_0_2*/
/* SPRC0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_PCIE_RIDCCR_0_0_2   */
/* SPRMCC Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_PCIE_RIDCCR_0_0_2  */
/* SPRD0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_PCIE_RIDCCR_0_0_2   */
/* SPRHBMB0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_PCIE_RIDCCR_0_0_2*/
/* SPRLCC Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_PCIE_RIDCCR_0_0_2  */
/* EMRXCC Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_PCIE_RIDCCR_0_0_2  */
/* SPRE0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_PCIE_RIDCCR_0_0_2   */
/* Struct generated from SPRA0 BDF: 30_0_2                                      */
/* SPRA0 Security PolicyGroup: OS_W                                             */
/* SPRB0 Security PolicyGroup: OS_W                                             */
/* SPRHBMA0 Security PolicyGroup: OS_W                                          */
/* SPRC0 Security PolicyGroup: OS_W                                             */
/* SPRMCC Security PolicyGroup: OS_W                                            */
/* SPRD0 Security PolicyGroup: OS_W                                             */
/* SPRHBMB0 Security PolicyGroup: OS_W                                          */
/* SPRLCC Security PolicyGroup: OS_W                                            */
/* EMRXCC Security PolicyGroup: OS_W                                            */
/* SPRE0 Security PolicyGroup: OS_W                                             */
/* PCIe header Revision ID register and Class Code register
*/


#define RID_CCR_0_0_2_UBOX_MISC_REG 0x13220008

typedef union {
  ///
  /// Individual bit fields
  ///
  struct {
    UINT32 revision_id : 8;

                            /* Bits[7:0], Access Type=RO/V, default=0x00000000*/

                            /*
                               Reflects the Uncore Revision ID after reset.
                               Reflects the Compatibility Revision ID if BIOS
                               updates.
                            */
    UINT32 register_level_programming_interface : 8;

                            /* Bits[15:8], Access Type=RO, default=0x00000000*/

                            /* Register Level Programming Interface */
    UINT32 sub_class : 8;

                            /* Bits[23:16], Access Type=RO, default=0x00000080*/

                            /* Sub class code */
    UINT32 base_class : 8;

                            /* Bits[31:24], Access Type=RO, default=0x00000008*/

                            /* Base class code */

  } Bits;
  UINT32 Data;

} RID_CCR_0_0_2_UBOX_MISC_STRUCT;

/* CLSR_0_0_2_UBOX_MISC_REG supported on:                                       */
/*      SPRA0 (0x1e0200c)                                                       */
/*      SPRB0 (0x1e0200c)                                                       */
/*      SPRHBMA0 (0x1e0200c)                                                    */
/*      SPRC0 (0x1e0200c)                                                       */
/*      SPRMCC (0x1e0200c)                                                      */
/*      SPRD0 (0x1e0200c)                                                       */
/*      SPRHBMB0 (0x1e0200c)                                                    */
/*      SPRLCC (0x1e0200c)                                                      */
/*      EMRXCC (0x1e0200c)                                                      */
/*      SPRE0 (0x1e0200c)                                                       */
/* Register default value on SPRA0: 0x00000000                                  */
/* Register default value on SPRB0: 0x00000000                                  */
/* Register default value on SPRHBMA0: 0x00000000                               */
/* Register default value on SPRC0: 0x00000000                                  */
/* Register default value on SPRMCC: 0x00000000                                 */
/* Register default value on SPRD0: 0x00000000                                  */
/* Register default value on SPRHBMB0: 0x00000000                               */
/* Register default value on SPRLCC: 0x00000000                                 */
/* Register default value on EMRXCC: 0x00000000                                 */
/* Register default value on SPRE0: 0x00000000                                  */
/* SPRA0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_PCIE_RIDCCR_0_0_2   */
/* SPRB0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_PCIE_RIDCCR_0_0_2   */
/* SPRHBMA0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_PCIE_RIDCCR_0_0_2*/
/* SPRC0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_PCIE_RIDCCR_0_0_2   */
/* SPRMCC Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_PCIE_RIDCCR_0_0_2  */
/* SPRD0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_PCIE_RIDCCR_0_0_2   */
/* SPRHBMB0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_PCIE_RIDCCR_0_0_2*/
/* SPRLCC Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_PCIE_RIDCCR_0_0_2  */
/* EMRXCC Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_PCIE_RIDCCR_0_0_2  */
/* SPRE0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_PCIE_RIDCCR_0_0_2   */
/* Struct generated from SPRA0 BDF: 30_0_2                                      */
/* SPRA0 Security PolicyGroup: OS_W                                             */
/* SPRB0 Security PolicyGroup: OS_W                                             */
/* SPRHBMA0 Security PolicyGroup: OS_W                                          */
/* SPRC0 Security PolicyGroup: OS_W                                             */
/* SPRMCC Security PolicyGroup: OS_W                                            */
/* SPRD0 Security PolicyGroup: OS_W                                             */
/* SPRHBMB0 Security PolicyGroup: OS_W                                          */
/* SPRLCC Security PolicyGroup: OS_W                                            */
/* EMRXCC Security PolicyGroup: OS_W                                            */
/* SPRE0 Security PolicyGroup: OS_W                                             */
/* PCI Cache Line Size Register
*/


#define CLSR_0_0_2_UBOX_MISC_REG 0x1320000C

typedef union {
  ///
  /// Individual bit fields
  ///
  struct {
    UINT8 cacheline_size : 8;

                            /* Bits[7:0], Access Type=RO, default=0x00000000*/

                            /* Size of Cacheline */

  } Bits;
  UINT8 Data;

} CLSR_0_0_2_UBOX_MISC_STRUCT;

/* PLAT_0_0_2_UBOX_MISC_REG supported on:                                       */
/*      SPRA0 (0x1e0200d)                                                       */
/*      SPRB0 (0x1e0200d)                                                       */
/*      SPRHBMA0 (0x1e0200d)                                                    */
/*      SPRC0 (0x1e0200d)                                                       */
/*      SPRMCC (0x1e0200d)                                                      */
/*      SPRD0 (0x1e0200d)                                                       */
/*      SPRHBMB0 (0x1e0200d)                                                    */
/*      SPRLCC (0x1e0200d)                                                      */
/*      EMRXCC (0x1e0200d)                                                      */
/*      SPRE0 (0x1e0200d)                                                       */
/* Register default value on SPRA0: 0x00000000                                  */
/* Register default value on SPRB0: 0x00000000                                  */
/* Register default value on SPRHBMA0: 0x00000000                               */
/* Register default value on SPRC0: 0x00000000                                  */
/* Register default value on SPRMCC: 0x00000000                                 */
/* Register default value on SPRD0: 0x00000000                                  */
/* Register default value on SPRHBMB0: 0x00000000                               */
/* Register default value on SPRLCC: 0x00000000                                 */
/* Register default value on EMRXCC: 0x00000000                                 */
/* Register default value on SPRE0: 0x00000000                                  */
/* SPRA0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_PCIE_RIDCCR_0_0_2   */
/* SPRB0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_PCIE_RIDCCR_0_0_2   */
/* SPRHBMA0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_PCIE_RIDCCR_0_0_2*/
/* SPRC0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_PCIE_RIDCCR_0_0_2   */
/* SPRMCC Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_PCIE_RIDCCR_0_0_2  */
/* SPRD0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_PCIE_RIDCCR_0_0_2   */
/* SPRHBMB0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_PCIE_RIDCCR_0_0_2*/
/* SPRLCC Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_PCIE_RIDCCR_0_0_2  */
/* EMRXCC Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_PCIE_RIDCCR_0_0_2  */
/* SPRE0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_PCIE_RIDCCR_0_0_2   */
/* Struct generated from SPRA0 BDF: 30_0_2                                      */
/* SPRA0 Security PolicyGroup: OS_W                                             */
/* SPRB0 Security PolicyGroup: OS_W                                             */
/* SPRHBMA0 Security PolicyGroup: OS_W                                          */
/* SPRC0 Security PolicyGroup: OS_W                                             */
/* SPRMCC Security PolicyGroup: OS_W                                            */
/* SPRD0 Security PolicyGroup: OS_W                                             */
/* SPRHBMB0 Security PolicyGroup: OS_W                                          */
/* SPRLCC Security PolicyGroup: OS_W                                            */
/* EMRXCC Security PolicyGroup: OS_W                                            */
/* SPRE0 Security PolicyGroup: OS_W                                             */
/* PCI Latency Timer
*/


#define PLAT_0_0_2_UBOX_MISC_REG 0x1320000D

typedef union {
  ///
  /// Individual bit fields
  ///
  struct {
    UINT8 primary_latency_timer : 8;

                            /* Bits[7:0], Access Type=RO, default=0x00000000*/

                            /* Not applicable to PCI-Express. Hardwired to 00h. */

  } Bits;
  UINT8 Data;

} PLAT_0_0_2_UBOX_MISC_STRUCT;

/* HDR_0_0_2_UBOX_MISC_REG supported on:                                        */
/*      SPRA0 (0x1e0200e)                                                       */
/*      SPRB0 (0x1e0200e)                                                       */
/*      SPRHBMA0 (0x1e0200e)                                                    */
/*      SPRC0 (0x1e0200e)                                                       */
/*      SPRMCC (0x1e0200e)                                                      */
/*      SPRD0 (0x1e0200e)                                                       */
/*      SPRHBMB0 (0x1e0200e)                                                    */
/*      SPRLCC (0x1e0200e)                                                      */
/*      EMRXCC (0x1e0200e)                                                      */
/*      SPRE0 (0x1e0200e)                                                       */
/* Register default value on SPRA0: 0x00000080                                  */
/* Register default value on SPRB0: 0x00000080                                  */
/* Register default value on SPRHBMA0: 0x00000080                               */
/* Register default value on SPRC0: 0x00000080                                  */
/* Register default value on SPRMCC: 0x00000080                                 */
/* Register default value on SPRD0: 0x00000080                                  */
/* Register default value on SPRHBMB0: 0x00000080                               */
/* Register default value on SPRLCC: 0x00000080                                 */
/* Register default value on EMRXCC: 0x00000080                                 */
/* Register default value on SPRE0: 0x00000080                                  */
/* SPRA0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_PCIE_RIDCCR_0_0_2   */
/* SPRB0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_PCIE_RIDCCR_0_0_2   */
/* SPRHBMA0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_PCIE_RIDCCR_0_0_2*/
/* SPRC0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_PCIE_RIDCCR_0_0_2   */
/* SPRMCC Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_PCIE_RIDCCR_0_0_2  */
/* SPRD0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_PCIE_RIDCCR_0_0_2   */
/* SPRHBMB0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_PCIE_RIDCCR_0_0_2*/
/* SPRLCC Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_PCIE_RIDCCR_0_0_2  */
/* EMRXCC Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_PCIE_RIDCCR_0_0_2  */
/* SPRE0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_PCIE_RIDCCR_0_0_2   */
/* Struct generated from SPRA0 BDF: 30_0_2                                      */
/* SPRA0 Security PolicyGroup: OS_W                                             */
/* SPRB0 Security PolicyGroup: OS_W                                             */
/* SPRHBMA0 Security PolicyGroup: OS_W                                          */
/* SPRC0 Security PolicyGroup: OS_W                                             */
/* SPRMCC Security PolicyGroup: OS_W                                            */
/* SPRD0 Security PolicyGroup: OS_W                                             */
/* SPRHBMB0 Security PolicyGroup: OS_W                                          */
/* SPRLCC Security PolicyGroup: OS_W                                            */
/* EMRXCC Security PolicyGroup: OS_W                                            */
/* SPRE0 Security PolicyGroup: OS_W                                             */
/* PCI Header Type
*/


#define HDR_0_0_2_UBOX_MISC_REG 0x1320000E

typedef union {
  ///
  /// Individual bit fields
  ///
  struct {
    UINT8 configuration_layout : 7;

                            /* Bits[6:0], Access Type=RO, default=0x00000000*/

                            /* Type 0 header */
    UINT8 multi_function_device : 1;

                            /* Bits[7:7], Access Type=RO, default=0x00000001*/

                            /*
                               This bit defaults to 1b since all these devices
                               are multi-function
                            */

  } Bits;
  UINT8 Data;

} HDR_0_0_2_UBOX_MISC_STRUCT;

/* BIST_0_0_2_UBOX_MISC_REG supported on:                                       */
/*      SPRA0 (0x1e0200f)                                                       */
/*      SPRB0 (0x1e0200f)                                                       */
/*      SPRHBMA0 (0x1e0200f)                                                    */
/*      SPRC0 (0x1e0200f)                                                       */
/*      SPRMCC (0x1e0200f)                                                      */
/*      SPRD0 (0x1e0200f)                                                       */
/*      SPRHBMB0 (0x1e0200f)                                                    */
/*      SPRLCC (0x1e0200f)                                                      */
/*      EMRXCC (0x1e0200f)                                                      */
/*      SPRE0 (0x1e0200f)                                                       */
/* Register default value on SPRA0: 0x00000000                                  */
/* Register default value on SPRB0: 0x00000000                                  */
/* Register default value on SPRHBMA0: 0x00000000                               */
/* Register default value on SPRC0: 0x00000000                                  */
/* Register default value on SPRMCC: 0x00000000                                 */
/* Register default value on SPRD0: 0x00000000                                  */
/* Register default value on SPRHBMB0: 0x00000000                               */
/* Register default value on SPRLCC: 0x00000000                                 */
/* Register default value on EMRXCC: 0x00000000                                 */
/* Register default value on SPRE0: 0x00000000                                  */
/* SPRA0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_PCIE_RIDCCR_0_0_2   */
/* SPRB0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_PCIE_RIDCCR_0_0_2   */
/* SPRHBMA0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_PCIE_RIDCCR_0_0_2*/
/* SPRC0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_PCIE_RIDCCR_0_0_2   */
/* SPRMCC Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_PCIE_RIDCCR_0_0_2  */
/* SPRD0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_PCIE_RIDCCR_0_0_2   */
/* SPRHBMB0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_PCIE_RIDCCR_0_0_2*/
/* SPRLCC Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_PCIE_RIDCCR_0_0_2  */
/* EMRXCC Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_PCIE_RIDCCR_0_0_2  */
/* SPRE0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_PCIE_RIDCCR_0_0_2   */
/* Struct generated from SPRA0 BDF: 30_0_2                                      */
/* SPRA0 Security PolicyGroup: OS_W                                             */
/* SPRB0 Security PolicyGroup: OS_W                                             */
/* SPRHBMA0 Security PolicyGroup: OS_W                                          */
/* SPRC0 Security PolicyGroup: OS_W                                             */
/* SPRMCC Security PolicyGroup: OS_W                                            */
/* SPRD0 Security PolicyGroup: OS_W                                             */
/* SPRHBMB0 Security PolicyGroup: OS_W                                          */
/* SPRLCC Security PolicyGroup: OS_W                                            */
/* EMRXCC Security PolicyGroup: OS_W                                            */
/* SPRE0 Security PolicyGroup: OS_W                                             */
/* PCI BIST Register
*/


#define BIST_0_0_2_UBOX_MISC_REG 0x1320000F

typedef union {
  ///
  /// Individual bit fields
  ///
  struct {
    UINT8 bist_tests : 8;

                            /* Bits[7:0], Access Type=RO, default=0x00000000*/

                            /* Not supported. Hardwired to 00h */

  } Bits;
  UINT8 Data;

} BIST_0_0_2_UBOX_MISC_STRUCT;

/* SVID_0_0_2_UBOX_MISC_REG supported on:                                       */
/*      SPRA0 (0x11e0202c)                                                      */
/*      SPRB0 (0x11e0202c)                                                      */
/*      SPRHBMA0 (0x11e0202c)                                                   */
/*      SPRC0 (0x11e0202c)                                                      */
/*      SPRMCC (0x11e0202c)                                                     */
/*      SPRD0 (0x11e0202c)                                                      */
/*      SPRHBMB0 (0x11e0202c)                                                   */
/*      SPRLCC (0x11e0202c)                                                     */
/*      EMRXCC (0x11e0202c)                                                     */
/*      SPRE0 (0x11e0202c)                                                      */
/* Register default value on SPRA0: 0x00008086                                  */
/* Register default value on SPRB0: 0x00008086                                  */
/* Register default value on SPRHBMA0: 0x00008086                               */
/* Register default value on SPRC0: 0x00008086                                  */
/* Register default value on SPRMCC: 0x00008086                                 */
/* Register default value on SPRD0: 0x00008086                                  */
/* Register default value on SPRHBMB0: 0x00008086                               */
/* Register default value on SPRLCC: 0x00008086                                 */
/* Register default value on EMRXCC: 0x00008086                                 */
/* Register default value on SPRE0: 0x00008086                                  */
/* SPRA0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_PCIE_RIDCCR_0_0_2   */
/* SPRB0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_PCIE_RIDCCR_0_0_2   */
/* SPRHBMA0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_PCIE_RIDCCR_0_0_2*/
/* SPRC0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_PCIE_RIDCCR_0_0_2   */
/* SPRMCC Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_PCIE_RIDCCR_0_0_2  */
/* SPRD0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_PCIE_RIDCCR_0_0_2   */
/* SPRHBMB0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_PCIE_RIDCCR_0_0_2*/
/* SPRLCC Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_PCIE_RIDCCR_0_0_2  */
/* EMRXCC Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_PCIE_RIDCCR_0_0_2  */
/* SPRE0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_PCIE_RIDCCR_0_0_2   */
/* Struct generated from SPRA0 BDF: 30_0_2                                      */
/* SPRA0 Security PolicyGroup: OS_W                                             */
/* SPRB0 Security PolicyGroup: OS_W                                             */
/* SPRHBMA0 Security PolicyGroup: OS_W                                          */
/* SPRC0 Security PolicyGroup: OS_W                                             */
/* SPRMCC Security PolicyGroup: OS_W                                            */
/* SPRD0 Security PolicyGroup: OS_W                                             */
/* SPRHBMB0 Security PolicyGroup: OS_W                                          */
/* SPRLCC Security PolicyGroup: OS_W                                            */
/* EMRXCC Security PolicyGroup: OS_W                                            */
/* SPRE0 Security PolicyGroup: OS_W                                             */
/* Subsystem Vendor ID Register
*/


#define SVID_0_0_2_UBOX_MISC_REG 0x1321002C

typedef union {
  ///
  /// Individual bit fields
  ///
  struct {
    UINT16 subsystem_vendor_identification_number : 16;

                            /* Bits[15:0], Access Type=RW/O, default=0x00008086*/

                            /*
                               The default value specifies Intel but can be set
                               to any value once after reset.
                            */

  } Bits;
  UINT16 Data;

} SVID_0_0_2_UBOX_MISC_STRUCT;

/* SDID_0_0_2_UBOX_MISC_REG supported on:                                       */
/*      SPRA0 (0x11e0202e)                                                      */
/*      SPRB0 (0x11e0202e)                                                      */
/*      SPRHBMA0 (0x11e0202e)                                                   */
/*      SPRC0 (0x11e0202e)                                                      */
/*      SPRMCC (0x11e0202e)                                                     */
/*      SPRD0 (0x11e0202e)                                                      */
/*      SPRHBMB0 (0x11e0202e)                                                   */
/*      SPRLCC (0x11e0202e)                                                     */
/*      EMRXCC (0x11e0202e)                                                     */
/*      SPRE0 (0x11e0202e)                                                      */
/* Register default value on SPRA0: 0x00000000                                  */
/* Register default value on SPRB0: 0x00000000                                  */
/* Register default value on SPRHBMA0: 0x00000000                               */
/* Register default value on SPRC0: 0x00000000                                  */
/* Register default value on SPRMCC: 0x00000000                                 */
/* Register default value on SPRD0: 0x00000000                                  */
/* Register default value on SPRHBMB0: 0x00000000                               */
/* Register default value on SPRLCC: 0x00000000                                 */
/* Register default value on EMRXCC: 0x00000000                                 */
/* Register default value on SPRE0: 0x00000000                                  */
/* SPRA0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_PCIE_RIDCCR_0_0_2   */
/* SPRB0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_PCIE_RIDCCR_0_0_2   */
/* SPRHBMA0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_PCIE_RIDCCR_0_0_2*/
/* SPRC0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_PCIE_RIDCCR_0_0_2   */
/* SPRMCC Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_PCIE_RIDCCR_0_0_2  */
/* SPRD0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_PCIE_RIDCCR_0_0_2   */
/* SPRHBMB0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_PCIE_RIDCCR_0_0_2*/
/* SPRLCC Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_PCIE_RIDCCR_0_0_2  */
/* EMRXCC Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_PCIE_RIDCCR_0_0_2  */
/* SPRE0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_PCIE_RIDCCR_0_0_2   */
/* Struct generated from SPRA0 BDF: 30_0_2                                      */
/* SPRA0 Security PolicyGroup: OS_W                                             */
/* SPRB0 Security PolicyGroup: OS_W                                             */
/* SPRHBMA0 Security PolicyGroup: OS_W                                          */
/* SPRC0 Security PolicyGroup: OS_W                                             */
/* SPRMCC Security PolicyGroup: OS_W                                            */
/* SPRD0 Security PolicyGroup: OS_W                                             */
/* SPRHBMB0 Security PolicyGroup: OS_W                                          */
/* SPRLCC Security PolicyGroup: OS_W                                            */
/* EMRXCC Security PolicyGroup: OS_W                                            */
/* SPRE0 Security PolicyGroup: OS_W                                             */
/* Subsystem ID Register
*/


#define SDID_0_0_2_UBOX_MISC_REG 0x1321002E

typedef union {
  ///
  /// Individual bit fields
  ///
  struct {
    UINT16 subsystem_identification_number : 16;

                            /* Bits[15:0], Access Type=RW/O, default=0x00000000*/

                            /*
                               Assigned by the subsystem vendor to uniquely
                               identify the subsystem
                            */

  } Bits;
  UINT16 Data;

} SDID_0_0_2_UBOX_MISC_STRUCT;

/* CAPPTR_0_0_2_UBOX_MISC_REG supported on:                                     */
/*      SPRA0 (0x1e02034)                                                       */
/*      SPRB0 (0x1e02034)                                                       */
/*      SPRHBMA0 (0x1e02034)                                                    */
/*      SPRC0 (0x1e02034)                                                       */
/*      SPRMCC (0x1e02034)                                                      */
/*      SPRD0 (0x1e02034)                                                       */
/*      SPRHBMB0 (0x1e02034)                                                    */
/*      SPRLCC (0x1e02034)                                                      */
/*      EMRXCC (0x1e02034)                                                      */
/*      SPRE0 (0x1e02034)                                                       */
/* Register default value on SPRA0: 0x00000040                                  */
/* Register default value on SPRB0: 0x00000040                                  */
/* Register default value on SPRHBMA0: 0x00000040                               */
/* Register default value on SPRC0: 0x00000040                                  */
/* Register default value on SPRMCC: 0x00000040                                 */
/* Register default value on SPRD0: 0x00000040                                  */
/* Register default value on SPRHBMB0: 0x00000040                               */
/* Register default value on SPRLCC: 0x00000040                                 */
/* Register default value on EMRXCC: 0x00000040                                 */
/* Register default value on SPRE0: 0x00000040                                  */
/* SPRA0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_PCIE_RIDCCR_0_0_2   */
/* SPRB0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_PCIE_RIDCCR_0_0_2   */
/* SPRHBMA0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_PCIE_RIDCCR_0_0_2*/
/* SPRC0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_PCIE_RIDCCR_0_0_2   */
/* SPRMCC Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_PCIE_RIDCCR_0_0_2  */
/* SPRD0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_PCIE_RIDCCR_0_0_2   */
/* SPRHBMB0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_PCIE_RIDCCR_0_0_2*/
/* SPRLCC Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_PCIE_RIDCCR_0_0_2  */
/* EMRXCC Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_PCIE_RIDCCR_0_0_2  */
/* SPRE0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_PCIE_RIDCCR_0_0_2   */
/* Struct generated from SPRA0 BDF: 30_0_2                                      */
/* SPRA0 Security PolicyGroup: OS_W                                             */
/* SPRB0 Security PolicyGroup: OS_W                                             */
/* SPRHBMA0 Security PolicyGroup: OS_W                                          */
/* SPRC0 Security PolicyGroup: OS_W                                             */
/* SPRMCC Security PolicyGroup: OS_W                                            */
/* SPRD0 Security PolicyGroup: OS_W                                             */
/* SPRHBMB0 Security PolicyGroup: OS_W                                          */
/* SPRLCC Security PolicyGroup: OS_W                                            */
/* EMRXCC Security PolicyGroup: OS_W                                            */
/* SPRE0 Security PolicyGroup: OS_W                                             */
/* PCI Capability Pointer Register
*/


#define CAPPTR_0_0_2_UBOX_MISC_REG 0x13200034

typedef union {
  ///
  /// Individual bit fields
  ///
  struct {
    UINT8 capability_pointer : 8;

                            /* Bits[7:0], Access Type=RO, default=0x00000040*/

                            /*
                               Points to the first capability structure for the
                               device which is the PCIe capability.
                            */

  } Bits;
  UINT8 Data;

} CAPPTR_0_0_2_UBOX_MISC_STRUCT;

/* INTL_0_0_2_UBOX_MISC_REG supported on:                                       */
/*      SPRA0 (0x1e0203c)                                                       */
/*      SPRB0 (0x1e0203c)                                                       */
/*      SPRHBMA0 (0x1e0203c)                                                    */
/*      SPRC0 (0x1e0203c)                                                       */
/*      SPRMCC (0x1e0203c)                                                      */
/*      SPRD0 (0x1e0203c)                                                       */
/*      SPRHBMB0 (0x1e0203c)                                                    */
/*      SPRLCC (0x1e0203c)                                                      */
/*      EMRXCC (0x1e0203c)                                                      */
/*      SPRE0 (0x1e0203c)                                                       */
/* Register default value on SPRA0: 0x00000000                                  */
/* Register default value on SPRB0: 0x00000000                                  */
/* Register default value on SPRHBMA0: 0x00000000                               */
/* Register default value on SPRC0: 0x00000000                                  */
/* Register default value on SPRMCC: 0x00000000                                 */
/* Register default value on SPRD0: 0x00000000                                  */
/* Register default value on SPRHBMB0: 0x00000000                               */
/* Register default value on SPRLCC: 0x00000000                                 */
/* Register default value on EMRXCC: 0x00000000                                 */
/* Register default value on SPRE0: 0x00000000                                  */
/* SPRA0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_PCIE_RIDCCR_0_0_2   */
/* SPRB0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_PCIE_RIDCCR_0_0_2   */
/* SPRHBMA0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_PCIE_RIDCCR_0_0_2*/
/* SPRC0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_PCIE_RIDCCR_0_0_2   */
/* SPRMCC Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_PCIE_RIDCCR_0_0_2  */
/* SPRD0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_PCIE_RIDCCR_0_0_2   */
/* SPRHBMB0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_PCIE_RIDCCR_0_0_2*/
/* SPRLCC Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_PCIE_RIDCCR_0_0_2  */
/* EMRXCC Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_PCIE_RIDCCR_0_0_2  */
/* SPRE0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_PCIE_RIDCCR_0_0_2   */
/* Struct generated from SPRA0 BDF: 30_0_2                                      */
/* SPRA0 Security PolicyGroup: OS_W                                             */
/* SPRB0 Security PolicyGroup: OS_W                                             */
/* SPRHBMA0 Security PolicyGroup: OS_W                                          */
/* SPRC0 Security PolicyGroup: OS_W                                             */
/* SPRMCC Security PolicyGroup: OS_W                                            */
/* SPRD0 Security PolicyGroup: OS_W                                             */
/* SPRHBMB0 Security PolicyGroup: OS_W                                          */
/* SPRLCC Security PolicyGroup: OS_W                                            */
/* EMRXCC Security PolicyGroup: OS_W                                            */
/* SPRE0 Security PolicyGroup: OS_W                                             */
/* PCI Interrupt Line Register
*/


#define INTL_0_0_2_UBOX_MISC_REG 0x1320003C

typedef union {
  ///
  /// Individual bit fields
  ///
  struct {
    UINT8 interrupt_line : 8;

                            /* Bits[7:0], Access Type=RO, default=0x00000000*/

                            /* N/A for these devices */

  } Bits;
  UINT8 Data;

} INTL_0_0_2_UBOX_MISC_STRUCT;

/* INTPIN_0_0_2_UBOX_MISC_REG supported on:                                     */
/*      SPRA0 (0x1e0203d)                                                       */
/*      SPRB0 (0x1e0203d)                                                       */
/*      SPRHBMA0 (0x1e0203d)                                                    */
/*      SPRC0 (0x1e0203d)                                                       */
/*      SPRMCC (0x1e0203d)                                                      */
/*      SPRD0 (0x1e0203d)                                                       */
/*      SPRHBMB0 (0x1e0203d)                                                    */
/*      SPRLCC (0x1e0203d)                                                      */
/*      EMRXCC (0x1e0203d)                                                      */
/*      SPRE0 (0x1e0203d)                                                       */
/* Register default value on SPRA0: 0x00000000                                  */
/* Register default value on SPRB0: 0x00000000                                  */
/* Register default value on SPRHBMA0: 0x00000000                               */
/* Register default value on SPRC0: 0x00000000                                  */
/* Register default value on SPRMCC: 0x00000000                                 */
/* Register default value on SPRD0: 0x00000000                                  */
/* Register default value on SPRHBMB0: 0x00000000                               */
/* Register default value on SPRLCC: 0x00000000                                 */
/* Register default value on EMRXCC: 0x00000000                                 */
/* Register default value on SPRE0: 0x00000000                                  */
/* SPRA0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_PCIE_RIDCCR_0_0_2   */
/* SPRB0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_PCIE_RIDCCR_0_0_2   */
/* SPRHBMA0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_PCIE_RIDCCR_0_0_2*/
/* SPRC0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_PCIE_RIDCCR_0_0_2   */
/* SPRMCC Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_PCIE_RIDCCR_0_0_2  */
/* SPRD0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_PCIE_RIDCCR_0_0_2   */
/* SPRHBMB0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_PCIE_RIDCCR_0_0_2*/
/* SPRLCC Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_PCIE_RIDCCR_0_0_2  */
/* EMRXCC Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_PCIE_RIDCCR_0_0_2  */
/* SPRE0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_PCIE_RIDCCR_0_0_2   */
/* Struct generated from SPRA0 BDF: 30_0_2                                      */
/* SPRA0 Security PolicyGroup: OS_W                                             */
/* SPRB0 Security PolicyGroup: OS_W                                             */
/* SPRHBMA0 Security PolicyGroup: OS_W                                          */
/* SPRC0 Security PolicyGroup: OS_W                                             */
/* SPRMCC Security PolicyGroup: OS_W                                            */
/* SPRD0 Security PolicyGroup: OS_W                                             */
/* SPRHBMB0 Security PolicyGroup: OS_W                                          */
/* SPRLCC Security PolicyGroup: OS_W                                            */
/* EMRXCC Security PolicyGroup: OS_W                                            */
/* SPRE0 Security PolicyGroup: OS_W                                             */
/* PCI Interrupt Pin Register
*/


#define INTPIN_0_0_2_UBOX_MISC_REG 0x1320003D

typedef union {
  ///
  /// Individual bit fields
  ///
  struct {
    UINT8 interrupt_pin : 8;

                            /* Bits[7:0], Access Type=RO, default=0x00000000*/

                            /*
                               N/A since these devices do not generate any
                               interrupt on their own
                            */

  } Bits;
  UINT8 Data;

} INTPIN_0_0_2_UBOX_MISC_STRUCT;

/* MINGNT_0_0_2_UBOX_MISC_REG supported on:                                     */
/*      SPRA0 (0x1e0203e)                                                       */
/*      SPRB0 (0x1e0203e)                                                       */
/*      SPRHBMA0 (0x1e0203e)                                                    */
/*      SPRC0 (0x1e0203e)                                                       */
/*      SPRMCC (0x1e0203e)                                                      */
/*      SPRD0 (0x1e0203e)                                                       */
/*      SPRHBMB0 (0x1e0203e)                                                    */
/*      SPRLCC (0x1e0203e)                                                      */
/*      EMRXCC (0x1e0203e)                                                      */
/*      SPRE0 (0x1e0203e)                                                       */
/* Register default value on SPRA0: 0x00000000                                  */
/* Register default value on SPRB0: 0x00000000                                  */
/* Register default value on SPRHBMA0: 0x00000000                               */
/* Register default value on SPRC0: 0x00000000                                  */
/* Register default value on SPRMCC: 0x00000000                                 */
/* Register default value on SPRD0: 0x00000000                                  */
/* Register default value on SPRHBMB0: 0x00000000                               */
/* Register default value on SPRLCC: 0x00000000                                 */
/* Register default value on EMRXCC: 0x00000000                                 */
/* Register default value on SPRE0: 0x00000000                                  */
/* SPRA0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_PCIE_RIDCCR_0_0_2   */
/* SPRB0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_PCIE_RIDCCR_0_0_2   */
/* SPRHBMA0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_PCIE_RIDCCR_0_0_2*/
/* SPRC0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_PCIE_RIDCCR_0_0_2   */
/* SPRMCC Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_PCIE_RIDCCR_0_0_2  */
/* SPRD0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_PCIE_RIDCCR_0_0_2   */
/* SPRHBMB0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_PCIE_RIDCCR_0_0_2*/
/* SPRLCC Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_PCIE_RIDCCR_0_0_2  */
/* EMRXCC Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_PCIE_RIDCCR_0_0_2  */
/* SPRE0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_PCIE_RIDCCR_0_0_2   */
/* Struct generated from SPRA0 BDF: 30_0_2                                      */
/* SPRA0 Security PolicyGroup: OS_W                                             */
/* SPRB0 Security PolicyGroup: OS_W                                             */
/* SPRHBMA0 Security PolicyGroup: OS_W                                          */
/* SPRC0 Security PolicyGroup: OS_W                                             */
/* SPRMCC Security PolicyGroup: OS_W                                            */
/* SPRD0 Security PolicyGroup: OS_W                                             */
/* SPRHBMB0 Security PolicyGroup: OS_W                                          */
/* SPRLCC Security PolicyGroup: OS_W                                            */
/* EMRXCC Security PolicyGroup: OS_W                                            */
/* SPRE0 Security PolicyGroup: OS_W                                             */
/* PCI Min Grant Register
*/


#define MINGNT_0_0_2_UBOX_MISC_REG 0x1320003E

typedef union {
  ///
  /// Individual bit fields
  ///
  struct {
    UINT8 mgv : 8;

                            /* Bits[7:0], Access Type=RO, default=0x00000000*/

                            /*
                               The device does not burst as a PCI compliant
                               master.
                            */

  } Bits;
  UINT8 Data;

} MINGNT_0_0_2_UBOX_MISC_STRUCT;

/* MAXLAT_0_0_2_UBOX_MISC_REG supported on:                                     */
/*      SPRA0 (0x1e0203f)                                                       */
/*      SPRB0 (0x1e0203f)                                                       */
/*      SPRHBMA0 (0x1e0203f)                                                    */
/*      SPRC0 (0x1e0203f)                                                       */
/*      SPRMCC (0x1e0203f)                                                      */
/*      SPRD0 (0x1e0203f)                                                       */
/*      SPRHBMB0 (0x1e0203f)                                                    */
/*      SPRLCC (0x1e0203f)                                                      */
/*      EMRXCC (0x1e0203f)                                                      */
/*      SPRE0 (0x1e0203f)                                                       */
/* Register default value on SPRA0: 0x00000000                                  */
/* Register default value on SPRB0: 0x00000000                                  */
/* Register default value on SPRHBMA0: 0x00000000                               */
/* Register default value on SPRC0: 0x00000000                                  */
/* Register default value on SPRMCC: 0x00000000                                 */
/* Register default value on SPRD0: 0x00000000                                  */
/* Register default value on SPRHBMB0: 0x00000000                               */
/* Register default value on SPRLCC: 0x00000000                                 */
/* Register default value on EMRXCC: 0x00000000                                 */
/* Register default value on SPRE0: 0x00000000                                  */
/* SPRA0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_PCIE_RIDCCR_0_0_2   */
/* SPRB0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_PCIE_RIDCCR_0_0_2   */
/* SPRHBMA0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_PCIE_RIDCCR_0_0_2*/
/* SPRC0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_PCIE_RIDCCR_0_0_2   */
/* SPRMCC Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_PCIE_RIDCCR_0_0_2  */
/* SPRD0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_PCIE_RIDCCR_0_0_2   */
/* SPRHBMB0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_PCIE_RIDCCR_0_0_2*/
/* SPRLCC Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_PCIE_RIDCCR_0_0_2  */
/* EMRXCC Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_PCIE_RIDCCR_0_0_2  */
/* SPRE0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_PCIE_RIDCCR_0_0_2   */
/* Struct generated from SPRA0 BDF: 30_0_2                                      */
/* SPRA0 Security PolicyGroup: OS_W                                             */
/* SPRB0 Security PolicyGroup: OS_W                                             */
/* SPRHBMA0 Security PolicyGroup: OS_W                                          */
/* SPRC0 Security PolicyGroup: OS_W                                             */
/* SPRMCC Security PolicyGroup: OS_W                                            */
/* SPRD0 Security PolicyGroup: OS_W                                             */
/* SPRHBMB0 Security PolicyGroup: OS_W                                          */
/* SPRLCC Security PolicyGroup: OS_W                                            */
/* EMRXCC Security PolicyGroup: OS_W                                            */
/* SPRE0 Security PolicyGroup: OS_W                                             */
/* PCI Max Latency Register
*/


#define MAXLAT_0_0_2_UBOX_MISC_REG 0x1320003F

typedef union {
  ///
  /// Individual bit fields
  ///
  struct {
    UINT8 mlv : 8;

                            /* Bits[7:0], Access Type=RO, default=0x00000000*/

                            /*
                               The device has no specific requirements for how
                               often it needs to access the PCI bus.
                            */

  } Bits;
  UINT8 Data;

} MAXLAT_0_0_2_UBOX_MISC_STRUCT;

/* PXPCAP_0_0_2_UBOX_MISC_REG supported on:                                     */
/*      SPRA0 (0x21e02040)                                                      */
/*      SPRB0 (0x21e02040)                                                      */
/*      SPRHBMA0 (0x21e02040)                                                   */
/*      SPRC0 (0x21e02040)                                                      */
/*      SPRMCC (0x21e02040)                                                     */
/*      SPRD0 (0x21e02040)                                                      */
/*      SPRHBMB0 (0x21e02040)                                                   */
/*      SPRLCC (0x21e02040)                                                     */
/*      EMRXCC (0x21e02040)                                                     */
/*      SPRE0 (0x21e02040)                                                      */
/* Register default value on SPRA0: 0x00920010                                  */
/* Register default value on SPRB0: 0x00920010                                  */
/* Register default value on SPRHBMA0: 0x00920010                               */
/* Register default value on SPRC0: 0x00920010                                  */
/* Register default value on SPRMCC: 0x00920010                                 */
/* Register default value on SPRD0: 0x00920010                                  */
/* Register default value on SPRHBMB0: 0x00920010                               */
/* Register default value on SPRLCC: 0x00920010                                 */
/* Register default value on EMRXCC: 0x00920010                                 */
/* Register default value on SPRE0: 0x00920010                                  */
/* SPRA0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_PCIE_RIDCCR_0_0_2   */
/* SPRB0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_PCIE_RIDCCR_0_0_2   */
/* SPRHBMA0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_PCIE_RIDCCR_0_0_2*/
/* SPRC0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_PCIE_RIDCCR_0_0_2   */
/* SPRMCC Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_PCIE_RIDCCR_0_0_2  */
/* SPRD0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_PCIE_RIDCCR_0_0_2   */
/* SPRHBMB0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_PCIE_RIDCCR_0_0_2*/
/* SPRLCC Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_PCIE_RIDCCR_0_0_2  */
/* EMRXCC Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_PCIE_RIDCCR_0_0_2  */
/* SPRE0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_PCIE_RIDCCR_0_0_2   */
/* Struct generated from SPRA0 BDF: 30_0_2                                      */
/* SPRA0 Security PolicyGroup: OS_W                                             */
/* SPRB0 Security PolicyGroup: OS_W                                             */
/* SPRHBMA0 Security PolicyGroup: OS_W                                          */
/* SPRC0 Security PolicyGroup: OS_W                                             */
/* SPRMCC Security PolicyGroup: OS_W                                            */
/* SPRD0 Security PolicyGroup: OS_W                                             */
/* SPRHBMB0 Security PolicyGroup: OS_W                                          */
/* SPRLCC Security PolicyGroup: OS_W                                            */
/* EMRXCC Security PolicyGroup: OS_W                                            */
/* SPRE0 Security PolicyGroup: OS_W                                             */
/* PCI Express Capability
*/


#define PXPCAP_0_0_2_UBOX_MISC_REG 0x13220040

typedef union {
  ///
  /// Individual bit fields
  ///
  struct {
    UINT32 capability_id : 8;

                            /* Bits[7:0], Access Type=RO, default=0x00000010*/

                            /*
                               Identifies the PCI Express capability assigned
                               by PCI-SIG.
                            */
    UINT32 next_ptr : 8;

                            /* Bits[15:8], Access Type=RO, default=0x00000000*/

                            /*
                               Pointer to the next capability. Set to 0 to
                               indicate there are no more capability
                               structures.
                            */
    UINT32 capability_version : 4;

                            /* Bits[19:16], Access Type=RO, default=0x00000002*/

                            /*
                               PCI Express Capability is Compliant with Version
                               2.0 of the PCI Express Spec.
                            */
    UINT32 device_port_type : 4;

                            /* Bits[23:20], Access Type=RO, default=0x00000009*/

                            /* Device type is Root Complex Integrated Endpoint */
    UINT32 slot_implemented : 1;

                            /* Bits[24:24], Access Type=RO, default=0x00000000*/

                            /* Not valid for PCIe integrated Endpoints */
    UINT32 interrupt_message_number : 5;

                            /* Bits[29:25], Access Type=RO, default=0x00000000*/

                            /*
                               Not valid for this device, since the device does
                               not generate interrupts
                            */
    UINT32 rsvd : 2;

                            /* Bits[31:30], Access Type=RO, default=None*/

                            /* Reserved */

  } Bits;
  UINT32 Data;

} PXPCAP_0_0_2_UBOX_MISC_STRUCT;

/* PCIE_RSVD0_0_0_2_UBOX_MISC_REG supported on:                                 */
/*      SPRA0 (0x21e02044)                                                      */
/*      SPRB0 (0x21e02044)                                                      */
/*      SPRHBMA0 (0x21e02044)                                                   */
/*      SPRC0 (0x21e02044)                                                      */
/*      SPRMCC (0x21e02044)                                                     */
/*      SPRD0 (0x21e02044)                                                      */
/*      SPRHBMB0 (0x21e02044)                                                   */
/*      SPRLCC (0x21e02044)                                                     */
/*      EMRXCC (0x21e02044)                                                     */
/*      SPRE0 (0x21e02044)                                                      */
/* Register default value on SPRA0: 0x00000000                                  */
/* Register default value on SPRB0: 0x00000000                                  */
/* Register default value on SPRHBMA0: 0x00000000                               */
/* Register default value on SPRC0: 0x00000000                                  */
/* Register default value on SPRMCC: 0x00000000                                 */
/* Register default value on SPRD0: 0x00000000                                  */
/* Register default value on SPRHBMB0: 0x00000000                               */
/* Register default value on SPRLCC: 0x00000000                                 */
/* Register default value on EMRXCC: 0x00000000                                 */
/* Register default value on SPRE0: 0x00000000                                  */
/* SPRA0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_PCIE_RIDCCR_0_0_2   */
/* SPRB0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_PCIE_RIDCCR_0_0_2   */
/* SPRHBMA0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_PCIE_RIDCCR_0_0_2*/
/* SPRC0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_PCIE_RIDCCR_0_0_2   */
/* SPRMCC Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_PCIE_RIDCCR_0_0_2  */
/* SPRD0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_PCIE_RIDCCR_0_0_2   */
/* SPRHBMB0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_PCIE_RIDCCR_0_0_2*/
/* SPRLCC Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_PCIE_RIDCCR_0_0_2  */
/* EMRXCC Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_PCIE_RIDCCR_0_0_2  */
/* SPRE0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_PCIE_RIDCCR_0_0_2   */
/* Struct generated from SPRA0 BDF: 30_0_2                                      */
/* SPRA0 Security PolicyGroup: OS_W                                             */
/* SPRB0 Security PolicyGroup: OS_W                                             */
/* SPRHBMA0 Security PolicyGroup: OS_W                                          */
/* SPRC0 Security PolicyGroup: OS_W                                             */
/* SPRMCC Security PolicyGroup: OS_W                                            */
/* SPRD0 Security PolicyGroup: OS_W                                             */
/* SPRHBMB0 Security PolicyGroup: OS_W                                          */
/* SPRLCC Security PolicyGroup: OS_W                                            */
/* EMRXCC Security PolicyGroup: OS_W                                            */
/* SPRE0 Security PolicyGroup: OS_W                                             */
/* Reserved space for PCIE header registers
*/


#define PCIE_RSVD0_0_0_2_UBOX_MISC_REG 0x13220044

typedef union {
  ///
  /// Individual bit fields
  ///
  struct {
    UINT32 reserved : 32;

                            /* Bits[31:0], Access Type=RO, default=0x00000000*/

                            /* This space is reserved */

  } Bits;
  UINT32 Data;

} PCIE_RSVD0_0_0_2_UBOX_MISC_STRUCT;

/* PCIE_RSVD1_0_0_2_N0_UBOX_MISC_REG supported on:                              */
/*      SPRA0 (0x21e02048)                                                      */
/*      SPRB0 (0x21e02048)                                                      */
/*      SPRHBMA0 (0x21e02048)                                                   */
/*      SPRC0 (0x21e02048)                                                      */
/*      SPRMCC (0x21e02048)                                                     */
/*      SPRD0 (0x21e02048)                                                      */
/*      SPRHBMB0 (0x21e02048)                                                   */
/*      SPRLCC (0x21e02048)                                                     */
/*      EMRXCC (0x21e02048)                                                     */
/*      SPRE0 (0x21e02048)                                                      */
/* Register default value on SPRA0: 0x00000000                                  */
/* Register default value on SPRB0: 0x00000000                                  */
/* Register default value on SPRHBMA0: 0x00000000                               */
/* Register default value on SPRC0: 0x00000000                                  */
/* Register default value on SPRMCC: 0x00000000                                 */
/* Register default value on SPRD0: 0x00000000                                  */
/* Register default value on SPRHBMB0: 0x00000000                               */
/* Register default value on SPRLCC: 0x00000000                                 */
/* Register default value on EMRXCC: 0x00000000                                 */
/* Register default value on SPRE0: 0x00000000                                  */
/* SPRA0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_PCIE_RIDCCR_0_0_2   */
/* SPRB0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_PCIE_RIDCCR_0_0_2   */
/* SPRHBMA0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_PCIE_RIDCCR_0_0_2*/
/* SPRC0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_PCIE_RIDCCR_0_0_2   */
/* SPRMCC Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_PCIE_RIDCCR_0_0_2  */
/* SPRD0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_PCIE_RIDCCR_0_0_2   */
/* SPRHBMB0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_PCIE_RIDCCR_0_0_2*/
/* SPRLCC Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_PCIE_RIDCCR_0_0_2  */
/* EMRXCC Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_PCIE_RIDCCR_0_0_2  */
/* SPRE0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_PCIE_RIDCCR_0_0_2   */
/* Struct generated from SPRA0 BDF: 30_0_2                                      */
/* SPRA0 Security PolicyGroup: OS_W                                             */
/* SPRB0 Security PolicyGroup: OS_W                                             */
/* SPRHBMA0 Security PolicyGroup: OS_W                                          */
/* SPRC0 Security PolicyGroup: OS_W                                             */
/* SPRMCC Security PolicyGroup: OS_W                                            */
/* SPRD0 Security PolicyGroup: OS_W                                             */
/* SPRHBMB0 Security PolicyGroup: OS_W                                          */
/* SPRLCC Security PolicyGroup: OS_W                                            */
/* EMRXCC Security PolicyGroup: OS_W                                            */
/* SPRE0 Security PolicyGroup: OS_W                                             */
/* Reserved space for PCIE header registers
*/


#define PCIE_RSVD1_0_0_2_N0_UBOX_MISC_REG 0x13220048

typedef union {
  ///
  /// Individual bit fields
  ///
  struct {
    UINT32 reserved : 32;

                            /* Bits[31:0], Access Type=RO, default=0x00000000*/

                            /* This space is reserved */

  } Bits;
  UINT32 Data;

} PCIE_RSVD1_0_0_2_N0_UBOX_MISC_STRUCT;

/* PCIE_RSVD1_0_0_2_N1_UBOX_MISC_REG supported on:                              */
/*      SPRA0 (0x21e0204c)                                                      */
/*      SPRB0 (0x21e0204c)                                                      */
/*      SPRHBMA0 (0x21e0204c)                                                   */
/*      SPRC0 (0x21e0204c)                                                      */
/*      SPRMCC (0x21e0204c)                                                     */
/*      SPRD0 (0x21e0204c)                                                      */
/*      SPRHBMB0 (0x21e0204c)                                                   */
/*      SPRLCC (0x21e0204c)                                                     */
/*      EMRXCC (0x21e0204c)                                                     */
/*      SPRE0 (0x21e0204c)                                                      */
/* Register default value on SPRA0: 0x00000000                                  */
/* Register default value on SPRB0: 0x00000000                                  */
/* Register default value on SPRHBMA0: 0x00000000                               */
/* Register default value on SPRC0: 0x00000000                                  */
/* Register default value on SPRMCC: 0x00000000                                 */
/* Register default value on SPRD0: 0x00000000                                  */
/* Register default value on SPRHBMB0: 0x00000000                               */
/* Register default value on SPRLCC: 0x00000000                                 */
/* Register default value on EMRXCC: 0x00000000                                 */
/* Register default value on SPRE0: 0x00000000                                  */
/* SPRA0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_PCIE_RIDCCR_0_0_2   */
/* SPRB0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_PCIE_RIDCCR_0_0_2   */
/* SPRHBMA0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_PCIE_RIDCCR_0_0_2*/
/* SPRC0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_PCIE_RIDCCR_0_0_2   */
/* SPRMCC Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_PCIE_RIDCCR_0_0_2  */
/* SPRD0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_PCIE_RIDCCR_0_0_2   */
/* SPRHBMB0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_PCIE_RIDCCR_0_0_2*/
/* SPRLCC Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_PCIE_RIDCCR_0_0_2  */
/* EMRXCC Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_PCIE_RIDCCR_0_0_2  */
/* SPRE0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_PCIE_RIDCCR_0_0_2   */
/* Struct generated from SPRA0 BDF: 30_0_2                                      */
/* SPRA0 Security PolicyGroup: OS_W                                             */
/* SPRB0 Security PolicyGroup: OS_W                                             */
/* SPRHBMA0 Security PolicyGroup: OS_W                                          */
/* SPRC0 Security PolicyGroup: OS_W                                             */
/* SPRMCC Security PolicyGroup: OS_W                                            */
/* SPRD0 Security PolicyGroup: OS_W                                             */
/* SPRHBMB0 Security PolicyGroup: OS_W                                          */
/* SPRLCC Security PolicyGroup: OS_W                                            */
/* EMRXCC Security PolicyGroup: OS_W                                            */
/* SPRE0 Security PolicyGroup: OS_W                                             */
/* Reserved space for PCIE header registers
*/


#define PCIE_RSVD1_0_0_2_N1_UBOX_MISC_REG 0x1322004C

typedef union {
  ///
  /// Individual bit fields
  ///
  struct {
    UINT32 reserved : 32;

                            /* Bits[31:0], Access Type=RO, default=0x00000000*/

                            /* This space is reserved */

  } Bits;
  UINT32 Data;

} PCIE_RSVD1_0_0_2_N1_UBOX_MISC_STRUCT;

/* PCIE_RSVD2_0_0_2_N0_UBOX_MISC_REG supported on:                              */
/*      SPRA0 (0x21e02050)                                                      */
/*      SPRB0 (0x21e02050)                                                      */
/*      SPRHBMA0 (0x21e02050)                                                   */
/*      SPRC0 (0x21e02050)                                                      */
/*      SPRMCC (0x21e02050)                                                     */
/*      SPRD0 (0x21e02050)                                                      */
/*      SPRHBMB0 (0x21e02050)                                                   */
/*      SPRLCC (0x21e02050)                                                     */
/*      EMRXCC (0x21e02050)                                                     */
/*      SPRE0 (0x21e02050)                                                      */
/* Register default value on SPRA0: 0x00000000                                  */
/* Register default value on SPRB0: 0x00000000                                  */
/* Register default value on SPRHBMA0: 0x00000000                               */
/* Register default value on SPRC0: 0x00000000                                  */
/* Register default value on SPRMCC: 0x00000000                                 */
/* Register default value on SPRD0: 0x00000000                                  */
/* Register default value on SPRHBMB0: 0x00000000                               */
/* Register default value on SPRLCC: 0x00000000                                 */
/* Register default value on EMRXCC: 0x00000000                                 */
/* Register default value on SPRE0: 0x00000000                                  */
/* SPRA0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_PCIE_RIDCCR_0_0_2   */
/* SPRB0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_PCIE_RIDCCR_0_0_2   */
/* SPRHBMA0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_PCIE_RIDCCR_0_0_2*/
/* SPRC0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_PCIE_RIDCCR_0_0_2   */
/* SPRMCC Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_PCIE_RIDCCR_0_0_2  */
/* SPRD0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_PCIE_RIDCCR_0_0_2   */
/* SPRHBMB0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_PCIE_RIDCCR_0_0_2*/
/* SPRLCC Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_PCIE_RIDCCR_0_0_2  */
/* EMRXCC Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_PCIE_RIDCCR_0_0_2  */
/* SPRE0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_PCIE_RIDCCR_0_0_2   */
/* Struct generated from SPRA0 BDF: 30_0_2                                      */
/* SPRA0 Security PolicyGroup: OS_W                                             */
/* SPRB0 Security PolicyGroup: OS_W                                             */
/* SPRHBMA0 Security PolicyGroup: OS_W                                          */
/* SPRC0 Security PolicyGroup: OS_W                                             */
/* SPRMCC Security PolicyGroup: OS_W                                            */
/* SPRD0 Security PolicyGroup: OS_W                                             */
/* SPRHBMB0 Security PolicyGroup: OS_W                                          */
/* SPRLCC Security PolicyGroup: OS_W                                            */
/* EMRXCC Security PolicyGroup: OS_W                                            */
/* SPRE0 Security PolicyGroup: OS_W                                             */
/* Reserved space for PCIE header registers
*/


#define PCIE_RSVD2_0_0_2_N0_UBOX_MISC_REG 0x13220050

typedef union {
  ///
  /// Individual bit fields
  ///
  struct {
    UINT32 reserved : 32;

                            /* Bits[31:0], Access Type=RO, default=0x00000000*/

                            /* This space is reserved */

  } Bits;
  UINT32 Data;

} PCIE_RSVD2_0_0_2_N0_UBOX_MISC_STRUCT;

/* PCIE_RSVD2_0_0_2_N1_UBOX_MISC_REG supported on:                              */
/*      SPRA0 (0x21e02054)                                                      */
/*      SPRB0 (0x21e02054)                                                      */
/*      SPRHBMA0 (0x21e02054)                                                   */
/*      SPRC0 (0x21e02054)                                                      */
/*      SPRMCC (0x21e02054)                                                     */
/*      SPRD0 (0x21e02054)                                                      */
/*      SPRHBMB0 (0x21e02054)                                                   */
/*      SPRLCC (0x21e02054)                                                     */
/*      EMRXCC (0x21e02054)                                                     */
/*      SPRE0 (0x21e02054)                                                      */
/* Register default value on SPRA0: 0x00000000                                  */
/* Register default value on SPRB0: 0x00000000                                  */
/* Register default value on SPRHBMA0: 0x00000000                               */
/* Register default value on SPRC0: 0x00000000                                  */
/* Register default value on SPRMCC: 0x00000000                                 */
/* Register default value on SPRD0: 0x00000000                                  */
/* Register default value on SPRHBMB0: 0x00000000                               */
/* Register default value on SPRLCC: 0x00000000                                 */
/* Register default value on EMRXCC: 0x00000000                                 */
/* Register default value on SPRE0: 0x00000000                                  */
/* SPRA0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_PCIE_RIDCCR_0_0_2   */
/* SPRB0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_PCIE_RIDCCR_0_0_2   */
/* SPRHBMA0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_PCIE_RIDCCR_0_0_2*/
/* SPRC0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_PCIE_RIDCCR_0_0_2   */
/* SPRMCC Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_PCIE_RIDCCR_0_0_2  */
/* SPRD0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_PCIE_RIDCCR_0_0_2   */
/* SPRHBMB0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_PCIE_RIDCCR_0_0_2*/
/* SPRLCC Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_PCIE_RIDCCR_0_0_2  */
/* EMRXCC Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_PCIE_RIDCCR_0_0_2  */
/* SPRE0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_PCIE_RIDCCR_0_0_2   */
/* Struct generated from SPRA0 BDF: 30_0_2                                      */
/* SPRA0 Security PolicyGroup: OS_W                                             */
/* SPRB0 Security PolicyGroup: OS_W                                             */
/* SPRHBMA0 Security PolicyGroup: OS_W                                          */
/* SPRC0 Security PolicyGroup: OS_W                                             */
/* SPRMCC Security PolicyGroup: OS_W                                            */
/* SPRD0 Security PolicyGroup: OS_W                                             */
/* SPRHBMB0 Security PolicyGroup: OS_W                                          */
/* SPRLCC Security PolicyGroup: OS_W                                            */
/* EMRXCC Security PolicyGroup: OS_W                                            */
/* SPRE0 Security PolicyGroup: OS_W                                             */
/* Reserved space for PCIE header registers
*/


#define PCIE_RSVD2_0_0_2_N1_UBOX_MISC_REG 0x13220054

typedef union {
  ///
  /// Individual bit fields
  ///
  struct {
    UINT32 reserved : 32;

                            /* Bits[31:0], Access Type=RO, default=0x00000000*/

                            /* This space is reserved */

  } Bits;
  UINT32 Data;

} PCIE_RSVD2_0_0_2_N1_UBOX_MISC_STRUCT;

/* PCIE_RSVD3_0_0_2_N0_UBOX_MISC_REG supported on:                              */
/*      SPRA0 (0x21e02058)                                                      */
/*      SPRB0 (0x21e02058)                                                      */
/*      SPRHBMA0 (0x21e02058)                                                   */
/*      SPRC0 (0x21e02058)                                                      */
/*      SPRMCC (0x21e02058)                                                     */
/*      SPRD0 (0x21e02058)                                                      */
/*      SPRHBMB0 (0x21e02058)                                                   */
/*      SPRLCC (0x21e02058)                                                     */
/*      EMRXCC (0x21e02058)                                                     */
/*      SPRE0 (0x21e02058)                                                      */
/* Register default value on SPRA0: 0x00000000                                  */
/* Register default value on SPRB0: 0x00000000                                  */
/* Register default value on SPRHBMA0: 0x00000000                               */
/* Register default value on SPRC0: 0x00000000                                  */
/* Register default value on SPRMCC: 0x00000000                                 */
/* Register default value on SPRD0: 0x00000000                                  */
/* Register default value on SPRHBMB0: 0x00000000                               */
/* Register default value on SPRLCC: 0x00000000                                 */
/* Register default value on EMRXCC: 0x00000000                                 */
/* Register default value on SPRE0: 0x00000000                                  */
/* SPRA0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_PCIE_RIDCCR_0_0_2   */
/* SPRB0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_PCIE_RIDCCR_0_0_2   */
/* SPRHBMA0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_PCIE_RIDCCR_0_0_2*/
/* SPRC0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_PCIE_RIDCCR_0_0_2   */
/* SPRMCC Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_PCIE_RIDCCR_0_0_2  */
/* SPRD0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_PCIE_RIDCCR_0_0_2   */
/* SPRHBMB0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_PCIE_RIDCCR_0_0_2*/
/* SPRLCC Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_PCIE_RIDCCR_0_0_2  */
/* EMRXCC Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_PCIE_RIDCCR_0_0_2  */
/* SPRE0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_PCIE_RIDCCR_0_0_2   */
/* Struct generated from SPRA0 BDF: 30_0_2                                      */
/* SPRA0 Security PolicyGroup: OS_W                                             */
/* SPRB0 Security PolicyGroup: OS_W                                             */
/* SPRHBMA0 Security PolicyGroup: OS_W                                          */
/* SPRC0 Security PolicyGroup: OS_W                                             */
/* SPRMCC Security PolicyGroup: OS_W                                            */
/* SPRD0 Security PolicyGroup: OS_W                                             */
/* SPRHBMB0 Security PolicyGroup: OS_W                                          */
/* SPRLCC Security PolicyGroup: OS_W                                            */
/* EMRXCC Security PolicyGroup: OS_W                                            */
/* SPRE0 Security PolicyGroup: OS_W                                             */
/* Reserved space for PCIE header registers
*/


#define PCIE_RSVD3_0_0_2_N0_UBOX_MISC_REG 0x13220058

typedef union {
  ///
  /// Individual bit fields
  ///
  struct {
    UINT32 reserved : 32;

                            /* Bits[31:0], Access Type=RO, default=0x00000000*/

                            /* This space is reserved */

  } Bits;
  UINT32 Data;

} PCIE_RSVD3_0_0_2_N0_UBOX_MISC_STRUCT;

/* PCIE_RSVD3_0_0_2_N1_UBOX_MISC_REG supported on:                              */
/*      SPRA0 (0x21e0205c)                                                      */
/*      SPRB0 (0x21e0205c)                                                      */
/*      SPRHBMA0 (0x21e0205c)                                                   */
/*      SPRC0 (0x21e0205c)                                                      */
/*      SPRMCC (0x21e0205c)                                                     */
/*      SPRD0 (0x21e0205c)                                                      */
/*      SPRHBMB0 (0x21e0205c)                                                   */
/*      SPRLCC (0x21e0205c)                                                     */
/*      EMRXCC (0x21e0205c)                                                     */
/*      SPRE0 (0x21e0205c)                                                      */
/* Register default value on SPRA0: 0x00000000                                  */
/* Register default value on SPRB0: 0x00000000                                  */
/* Register default value on SPRHBMA0: 0x00000000                               */
/* Register default value on SPRC0: 0x00000000                                  */
/* Register default value on SPRMCC: 0x00000000                                 */
/* Register default value on SPRD0: 0x00000000                                  */
/* Register default value on SPRHBMB0: 0x00000000                               */
/* Register default value on SPRLCC: 0x00000000                                 */
/* Register default value on EMRXCC: 0x00000000                                 */
/* Register default value on SPRE0: 0x00000000                                  */
/* SPRA0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_PCIE_RIDCCR_0_0_2   */
/* SPRB0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_PCIE_RIDCCR_0_0_2   */
/* SPRHBMA0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_PCIE_RIDCCR_0_0_2*/
/* SPRC0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_PCIE_RIDCCR_0_0_2   */
/* SPRMCC Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_PCIE_RIDCCR_0_0_2  */
/* SPRD0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_PCIE_RIDCCR_0_0_2   */
/* SPRHBMB0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_PCIE_RIDCCR_0_0_2*/
/* SPRLCC Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_PCIE_RIDCCR_0_0_2  */
/* EMRXCC Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_PCIE_RIDCCR_0_0_2  */
/* SPRE0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_PCIE_RIDCCR_0_0_2   */
/* Struct generated from SPRA0 BDF: 30_0_2                                      */
/* SPRA0 Security PolicyGroup: OS_W                                             */
/* SPRB0 Security PolicyGroup: OS_W                                             */
/* SPRHBMA0 Security PolicyGroup: OS_W                                          */
/* SPRC0 Security PolicyGroup: OS_W                                             */
/* SPRMCC Security PolicyGroup: OS_W                                            */
/* SPRD0 Security PolicyGroup: OS_W                                             */
/* SPRHBMB0 Security PolicyGroup: OS_W                                          */
/* SPRLCC Security PolicyGroup: OS_W                                            */
/* EMRXCC Security PolicyGroup: OS_W                                            */
/* SPRE0 Security PolicyGroup: OS_W                                             */
/* Reserved space for PCIE header registers
*/


#define PCIE_RSVD3_0_0_2_N1_UBOX_MISC_REG 0x1322005C

typedef union {
  ///
  /// Individual bit fields
  ///
  struct {
    UINT32 reserved : 32;

                            /* Bits[31:0], Access Type=RO, default=0x00000000*/

                            /* This space is reserved */

  } Bits;
  UINT32 Data;

} PCIE_RSVD3_0_0_2_N1_UBOX_MISC_STRUCT;

/* PCIE_RSVD4_0_0_2_N0_UBOX_MISC_REG supported on:                              */
/*      SPRA0 (0x21e02060)                                                      */
/*      SPRB0 (0x21e02060)                                                      */
/*      SPRHBMA0 (0x21e02060)                                                   */
/*      SPRC0 (0x21e02060)                                                      */
/*      SPRMCC (0x21e02060)                                                     */
/*      SPRD0 (0x21e02060)                                                      */
/*      SPRHBMB0 (0x21e02060)                                                   */
/*      SPRLCC (0x21e02060)                                                     */
/*      EMRXCC (0x21e02060)                                                     */
/*      SPRE0 (0x21e02060)                                                      */
/* Register default value on SPRA0: 0x00000000                                  */
/* Register default value on SPRB0: 0x00000000                                  */
/* Register default value on SPRHBMA0: 0x00000000                               */
/* Register default value on SPRC0: 0x00000000                                  */
/* Register default value on SPRMCC: 0x00000000                                 */
/* Register default value on SPRD0: 0x00000000                                  */
/* Register default value on SPRHBMB0: 0x00000000                               */
/* Register default value on SPRLCC: 0x00000000                                 */
/* Register default value on EMRXCC: 0x00000000                                 */
/* Register default value on SPRE0: 0x00000000                                  */
/* SPRA0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_PCIE_RIDCCR_0_0_2   */
/* SPRB0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_PCIE_RIDCCR_0_0_2   */
/* SPRHBMA0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_PCIE_RIDCCR_0_0_2*/
/* SPRC0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_PCIE_RIDCCR_0_0_2   */
/* SPRMCC Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_PCIE_RIDCCR_0_0_2  */
/* SPRD0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_PCIE_RIDCCR_0_0_2   */
/* SPRHBMB0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_PCIE_RIDCCR_0_0_2*/
/* SPRLCC Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_PCIE_RIDCCR_0_0_2  */
/* EMRXCC Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_PCIE_RIDCCR_0_0_2  */
/* SPRE0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_PCIE_RIDCCR_0_0_2   */
/* Struct generated from SPRA0 BDF: 30_0_2                                      */
/* SPRA0 Security PolicyGroup: OS_W                                             */
/* SPRB0 Security PolicyGroup: OS_W                                             */
/* SPRHBMA0 Security PolicyGroup: OS_W                                          */
/* SPRC0 Security PolicyGroup: OS_W                                             */
/* SPRMCC Security PolicyGroup: OS_W                                            */
/* SPRD0 Security PolicyGroup: OS_W                                             */
/* SPRHBMB0 Security PolicyGroup: OS_W                                          */
/* SPRLCC Security PolicyGroup: OS_W                                            */
/* EMRXCC Security PolicyGroup: OS_W                                            */
/* SPRE0 Security PolicyGroup: OS_W                                             */
/* Reserved space for PCIE header registers
*/


#define PCIE_RSVD4_0_0_2_N0_UBOX_MISC_REG 0x13220060

typedef union {
  ///
  /// Individual bit fields
  ///
  struct {
    UINT32 reserved : 32;

                            /* Bits[31:0], Access Type=RO, default=0x00000000*/

                            /* This space is reserved */

  } Bits;
  UINT32 Data;

} PCIE_RSVD4_0_0_2_N0_UBOX_MISC_STRUCT;

/* PCIE_RSVD4_0_0_2_N1_UBOX_MISC_REG supported on:                              */
/*      SPRA0 (0x21e02064)                                                      */
/*      SPRB0 (0x21e02064)                                                      */
/*      SPRHBMA0 (0x21e02064)                                                   */
/*      SPRC0 (0x21e02064)                                                      */
/*      SPRMCC (0x21e02064)                                                     */
/*      SPRD0 (0x21e02064)                                                      */
/*      SPRHBMB0 (0x21e02064)                                                   */
/*      SPRLCC (0x21e02064)                                                     */
/*      EMRXCC (0x21e02064)                                                     */
/*      SPRE0 (0x21e02064)                                                      */
/* Register default value on SPRA0: 0x00000000                                  */
/* Register default value on SPRB0: 0x00000000                                  */
/* Register default value on SPRHBMA0: 0x00000000                               */
/* Register default value on SPRC0: 0x00000000                                  */
/* Register default value on SPRMCC: 0x00000000                                 */
/* Register default value on SPRD0: 0x00000000                                  */
/* Register default value on SPRHBMB0: 0x00000000                               */
/* Register default value on SPRLCC: 0x00000000                                 */
/* Register default value on EMRXCC: 0x00000000                                 */
/* Register default value on SPRE0: 0x00000000                                  */
/* SPRA0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_PCIE_RIDCCR_0_0_2   */
/* SPRB0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_PCIE_RIDCCR_0_0_2   */
/* SPRHBMA0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_PCIE_RIDCCR_0_0_2*/
/* SPRC0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_PCIE_RIDCCR_0_0_2   */
/* SPRMCC Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_PCIE_RIDCCR_0_0_2  */
/* SPRD0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_PCIE_RIDCCR_0_0_2   */
/* SPRHBMB0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_PCIE_RIDCCR_0_0_2*/
/* SPRLCC Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_PCIE_RIDCCR_0_0_2  */
/* EMRXCC Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_PCIE_RIDCCR_0_0_2  */
/* SPRE0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_PCIE_RIDCCR_0_0_2   */
/* Struct generated from SPRA0 BDF: 30_0_2                                      */
/* SPRA0 Security PolicyGroup: OS_W                                             */
/* SPRB0 Security PolicyGroup: OS_W                                             */
/* SPRHBMA0 Security PolicyGroup: OS_W                                          */
/* SPRC0 Security PolicyGroup: OS_W                                             */
/* SPRMCC Security PolicyGroup: OS_W                                            */
/* SPRD0 Security PolicyGroup: OS_W                                             */
/* SPRHBMB0 Security PolicyGroup: OS_W                                          */
/* SPRLCC Security PolicyGroup: OS_W                                            */
/* EMRXCC Security PolicyGroup: OS_W                                            */
/* SPRE0 Security PolicyGroup: OS_W                                             */
/* Reserved space for PCIE header registers
*/


#define PCIE_RSVD4_0_0_2_N1_UBOX_MISC_REG 0x13220064

typedef union {
  ///
  /// Individual bit fields
  ///
  struct {
    UINT32 reserved : 32;

                            /* Bits[31:0], Access Type=RO, default=0x00000000*/

                            /* This space is reserved */

  } Bits;
  UINT32 Data;

} PCIE_RSVD4_0_0_2_N1_UBOX_MISC_STRUCT;

/* PCIE_RSVD5_0_0_2_N0_UBOX_MISC_REG supported on:                              */
/*      SPRA0 (0x21e02068)                                                      */
/*      SPRB0 (0x21e02068)                                                      */
/*      SPRHBMA0 (0x21e02068)                                                   */
/*      SPRC0 (0x21e02068)                                                      */
/*      SPRMCC (0x21e02068)                                                     */
/*      SPRD0 (0x21e02068)                                                      */
/*      SPRHBMB0 (0x21e02068)                                                   */
/*      SPRLCC (0x21e02068)                                                     */
/*      EMRXCC (0x21e02068)                                                     */
/*      SPRE0 (0x21e02068)                                                      */
/* Register default value on SPRA0: 0x00000000                                  */
/* Register default value on SPRB0: 0x00000000                                  */
/* Register default value on SPRHBMA0: 0x00000000                               */
/* Register default value on SPRC0: 0x00000000                                  */
/* Register default value on SPRMCC: 0x00000000                                 */
/* Register default value on SPRD0: 0x00000000                                  */
/* Register default value on SPRHBMB0: 0x00000000                               */
/* Register default value on SPRLCC: 0x00000000                                 */
/* Register default value on EMRXCC: 0x00000000                                 */
/* Register default value on SPRE0: 0x00000000                                  */
/* SPRA0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_PCIE_RIDCCR_0_0_2   */
/* SPRB0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_PCIE_RIDCCR_0_0_2   */
/* SPRHBMA0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_PCIE_RIDCCR_0_0_2*/
/* SPRC0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_PCIE_RIDCCR_0_0_2   */
/* SPRMCC Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_PCIE_RIDCCR_0_0_2  */
/* SPRD0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_PCIE_RIDCCR_0_0_2   */
/* SPRHBMB0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_PCIE_RIDCCR_0_0_2*/
/* SPRLCC Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_PCIE_RIDCCR_0_0_2  */
/* EMRXCC Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_PCIE_RIDCCR_0_0_2  */
/* SPRE0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_PCIE_RIDCCR_0_0_2   */
/* Struct generated from SPRA0 BDF: 30_0_2                                      */
/* SPRA0 Security PolicyGroup: OS_W                                             */
/* SPRB0 Security PolicyGroup: OS_W                                             */
/* SPRHBMA0 Security PolicyGroup: OS_W                                          */
/* SPRC0 Security PolicyGroup: OS_W                                             */
/* SPRMCC Security PolicyGroup: OS_W                                            */
/* SPRD0 Security PolicyGroup: OS_W                                             */
/* SPRHBMB0 Security PolicyGroup: OS_W                                          */
/* SPRLCC Security PolicyGroup: OS_W                                            */
/* EMRXCC Security PolicyGroup: OS_W                                            */
/* SPRE0 Security PolicyGroup: OS_W                                             */
/* Reserved space for PCIE header registers
*/


#define PCIE_RSVD5_0_0_2_N0_UBOX_MISC_REG 0x13220068

typedef union {
  ///
  /// Individual bit fields
  ///
  struct {
    UINT32 reserved : 32;

                            /* Bits[31:0], Access Type=RO, default=0x00000000*/

                            /* This space is reserved */

  } Bits;
  UINT32 Data;

} PCIE_RSVD5_0_0_2_N0_UBOX_MISC_STRUCT;

/* PCIE_RSVD5_0_0_2_N1_UBOX_MISC_REG supported on:                              */
/*      SPRA0 (0x21e0206c)                                                      */
/*      SPRB0 (0x21e0206c)                                                      */
/*      SPRHBMA0 (0x21e0206c)                                                   */
/*      SPRC0 (0x21e0206c)                                                      */
/*      SPRMCC (0x21e0206c)                                                     */
/*      SPRD0 (0x21e0206c)                                                      */
/*      SPRHBMB0 (0x21e0206c)                                                   */
/*      SPRLCC (0x21e0206c)                                                     */
/*      EMRXCC (0x21e0206c)                                                     */
/*      SPRE0 (0x21e0206c)                                                      */
/* Register default value on SPRA0: 0x00000000                                  */
/* Register default value on SPRB0: 0x00000000                                  */
/* Register default value on SPRHBMA0: 0x00000000                               */
/* Register default value on SPRC0: 0x00000000                                  */
/* Register default value on SPRMCC: 0x00000000                                 */
/* Register default value on SPRD0: 0x00000000                                  */
/* Register default value on SPRHBMB0: 0x00000000                               */
/* Register default value on SPRLCC: 0x00000000                                 */
/* Register default value on EMRXCC: 0x00000000                                 */
/* Register default value on SPRE0: 0x00000000                                  */
/* SPRA0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_PCIE_RIDCCR_0_0_2   */
/* SPRB0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_PCIE_RIDCCR_0_0_2   */
/* SPRHBMA0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_PCIE_RIDCCR_0_0_2*/
/* SPRC0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_PCIE_RIDCCR_0_0_2   */
/* SPRMCC Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_PCIE_RIDCCR_0_0_2  */
/* SPRD0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_PCIE_RIDCCR_0_0_2   */
/* SPRHBMB0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_PCIE_RIDCCR_0_0_2*/
/* SPRLCC Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_PCIE_RIDCCR_0_0_2  */
/* EMRXCC Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_PCIE_RIDCCR_0_0_2  */
/* SPRE0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_PCIE_RIDCCR_0_0_2   */
/* Struct generated from SPRA0 BDF: 30_0_2                                      */
/* SPRA0 Security PolicyGroup: OS_W                                             */
/* SPRB0 Security PolicyGroup: OS_W                                             */
/* SPRHBMA0 Security PolicyGroup: OS_W                                          */
/* SPRC0 Security PolicyGroup: OS_W                                             */
/* SPRMCC Security PolicyGroup: OS_W                                            */
/* SPRD0 Security PolicyGroup: OS_W                                             */
/* SPRHBMB0 Security PolicyGroup: OS_W                                          */
/* SPRLCC Security PolicyGroup: OS_W                                            */
/* EMRXCC Security PolicyGroup: OS_W                                            */
/* SPRE0 Security PolicyGroup: OS_W                                             */
/* Reserved space for PCIE header registers
*/


#define PCIE_RSVD5_0_0_2_N1_UBOX_MISC_REG 0x1322006C

typedef union {
  ///
  /// Individual bit fields
  ///
  struct {
    UINT32 reserved : 32;

                            /* Bits[31:0], Access Type=RO, default=0x00000000*/

                            /* This space is reserved */

  } Bits;
  UINT32 Data;

} PCIE_RSVD5_0_0_2_N1_UBOX_MISC_STRUCT;

/* PCIE_RSVD6_0_0_2_N0_UBOX_MISC_REG supported on:                              */
/*      SPRA0 (0x21e02070)                                                      */
/*      SPRB0 (0x21e02070)                                                      */
/*      SPRHBMA0 (0x21e02070)                                                   */
/*      SPRC0 (0x21e02070)                                                      */
/*      SPRMCC (0x21e02070)                                                     */
/*      SPRD0 (0x21e02070)                                                      */
/*      SPRHBMB0 (0x21e02070)                                                   */
/*      SPRLCC (0x21e02070)                                                     */
/*      EMRXCC (0x21e02070)                                                     */
/*      SPRE0 (0x21e02070)                                                      */
/* Register default value on SPRA0: 0x00000000                                  */
/* Register default value on SPRB0: 0x00000000                                  */
/* Register default value on SPRHBMA0: 0x00000000                               */
/* Register default value on SPRC0: 0x00000000                                  */
/* Register default value on SPRMCC: 0x00000000                                 */
/* Register default value on SPRD0: 0x00000000                                  */
/* Register default value on SPRHBMB0: 0x00000000                               */
/* Register default value on SPRLCC: 0x00000000                                 */
/* Register default value on EMRXCC: 0x00000000                                 */
/* Register default value on SPRE0: 0x00000000                                  */
/* SPRA0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_PCIE_RIDCCR_0_0_2   */
/* SPRB0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_PCIE_RIDCCR_0_0_2   */
/* SPRHBMA0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_PCIE_RIDCCR_0_0_2*/
/* SPRC0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_PCIE_RIDCCR_0_0_2   */
/* SPRMCC Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_PCIE_RIDCCR_0_0_2  */
/* SPRD0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_PCIE_RIDCCR_0_0_2   */
/* SPRHBMB0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_PCIE_RIDCCR_0_0_2*/
/* SPRLCC Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_PCIE_RIDCCR_0_0_2  */
/* EMRXCC Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_PCIE_RIDCCR_0_0_2  */
/* SPRE0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_PCIE_RIDCCR_0_0_2   */
/* Struct generated from SPRA0 BDF: 30_0_2                                      */
/* SPRA0 Security PolicyGroup: OS_W                                             */
/* SPRB0 Security PolicyGroup: OS_W                                             */
/* SPRHBMA0 Security PolicyGroup: OS_W                                          */
/* SPRC0 Security PolicyGroup: OS_W                                             */
/* SPRMCC Security PolicyGroup: OS_W                                            */
/* SPRD0 Security PolicyGroup: OS_W                                             */
/* SPRHBMB0 Security PolicyGroup: OS_W                                          */
/* SPRLCC Security PolicyGroup: OS_W                                            */
/* EMRXCC Security PolicyGroup: OS_W                                            */
/* SPRE0 Security PolicyGroup: OS_W                                             */
/* Reserved space for PCIE header registers
*/


#define PCIE_RSVD6_0_0_2_N0_UBOX_MISC_REG 0x13220070

typedef union {
  ///
  /// Individual bit fields
  ///
  struct {
    UINT32 reserved : 32;

                            /* Bits[31:0], Access Type=RO, default=0x00000000*/

                            /* This space is reserved */

  } Bits;
  UINT32 Data;

} PCIE_RSVD6_0_0_2_N0_UBOX_MISC_STRUCT;

/* PCIE_RSVD6_0_0_2_N1_UBOX_MISC_REG supported on:                              */
/*      SPRA0 (0x21e02074)                                                      */
/*      SPRB0 (0x21e02074)                                                      */
/*      SPRHBMA0 (0x21e02074)                                                   */
/*      SPRC0 (0x21e02074)                                                      */
/*      SPRMCC (0x21e02074)                                                     */
/*      SPRD0 (0x21e02074)                                                      */
/*      SPRHBMB0 (0x21e02074)                                                   */
/*      SPRLCC (0x21e02074)                                                     */
/*      EMRXCC (0x21e02074)                                                     */
/*      SPRE0 (0x21e02074)                                                      */
/* Register default value on SPRA0: 0x00000000                                  */
/* Register default value on SPRB0: 0x00000000                                  */
/* Register default value on SPRHBMA0: 0x00000000                               */
/* Register default value on SPRC0: 0x00000000                                  */
/* Register default value on SPRMCC: 0x00000000                                 */
/* Register default value on SPRD0: 0x00000000                                  */
/* Register default value on SPRHBMB0: 0x00000000                               */
/* Register default value on SPRLCC: 0x00000000                                 */
/* Register default value on EMRXCC: 0x00000000                                 */
/* Register default value on SPRE0: 0x00000000                                  */
/* SPRA0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_PCIE_RIDCCR_0_0_2   */
/* SPRB0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_PCIE_RIDCCR_0_0_2   */
/* SPRHBMA0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_PCIE_RIDCCR_0_0_2*/
/* SPRC0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_PCIE_RIDCCR_0_0_2   */
/* SPRMCC Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_PCIE_RIDCCR_0_0_2  */
/* SPRD0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_PCIE_RIDCCR_0_0_2   */
/* SPRHBMB0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_PCIE_RIDCCR_0_0_2*/
/* SPRLCC Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_PCIE_RIDCCR_0_0_2  */
/* EMRXCC Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_PCIE_RIDCCR_0_0_2  */
/* SPRE0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_PCIE_RIDCCR_0_0_2   */
/* Struct generated from SPRA0 BDF: 30_0_2                                      */
/* SPRA0 Security PolicyGroup: OS_W                                             */
/* SPRB0 Security PolicyGroup: OS_W                                             */
/* SPRHBMA0 Security PolicyGroup: OS_W                                          */
/* SPRC0 Security PolicyGroup: OS_W                                             */
/* SPRMCC Security PolicyGroup: OS_W                                            */
/* SPRD0 Security PolicyGroup: OS_W                                             */
/* SPRHBMB0 Security PolicyGroup: OS_W                                          */
/* SPRLCC Security PolicyGroup: OS_W                                            */
/* EMRXCC Security PolicyGroup: OS_W                                            */
/* SPRE0 Security PolicyGroup: OS_W                                             */
/* Reserved space for PCIE header registers
*/


#define PCIE_RSVD6_0_0_2_N1_UBOX_MISC_REG 0x13220074

typedef union {
  ///
  /// Individual bit fields
  ///
  struct {
    UINT32 reserved : 32;

                            /* Bits[31:0], Access Type=RO, default=0x00000000*/

                            /* This space is reserved */

  } Bits;
  UINT32 Data;

} PCIE_RSVD6_0_0_2_N1_UBOX_MISC_STRUCT;

/* PCIE_RSVD7_0_0_2_UBOX_MISC_REG supported on:                                 */
/*      SPRA0 (0x21e02078)                                                      */
/*      SPRB0 (0x21e02078)                                                      */
/*      SPRHBMA0 (0x21e02078)                                                   */
/*      SPRC0 (0x21e02078)                                                      */
/*      SPRMCC (0x21e02078)                                                     */
/*      SPRD0 (0x21e02078)                                                      */
/*      SPRHBMB0 (0x21e02078)                                                   */
/*      SPRLCC (0x21e02078)                                                     */
/*      EMRXCC (0x21e02078)                                                     */
/*      SPRE0 (0x21e02078)                                                      */
/* Register default value on SPRA0: 0x00000000                                  */
/* Register default value on SPRB0: 0x00000000                                  */
/* Register default value on SPRHBMA0: 0x00000000                               */
/* Register default value on SPRC0: 0x00000000                                  */
/* Register default value on SPRMCC: 0x00000000                                 */
/* Register default value on SPRD0: 0x00000000                                  */
/* Register default value on SPRHBMB0: 0x00000000                               */
/* Register default value on SPRLCC: 0x00000000                                 */
/* Register default value on EMRXCC: 0x00000000                                 */
/* Register default value on SPRE0: 0x00000000                                  */
/* SPRA0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_PCIE_RIDCCR_0_0_2   */
/* SPRB0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_PCIE_RIDCCR_0_0_2   */
/* SPRHBMA0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_PCIE_RIDCCR_0_0_2*/
/* SPRC0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_PCIE_RIDCCR_0_0_2   */
/* SPRMCC Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_PCIE_RIDCCR_0_0_2  */
/* SPRD0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_PCIE_RIDCCR_0_0_2   */
/* SPRHBMB0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_PCIE_RIDCCR_0_0_2*/
/* SPRLCC Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_PCIE_RIDCCR_0_0_2  */
/* EMRXCC Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_PCIE_RIDCCR_0_0_2  */
/* SPRE0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_PCIE_RIDCCR_0_0_2   */
/* Struct generated from SPRA0 BDF: 30_0_2                                      */
/* SPRA0 Security PolicyGroup: OS_W                                             */
/* SPRB0 Security PolicyGroup: OS_W                                             */
/* SPRHBMA0 Security PolicyGroup: OS_W                                          */
/* SPRC0 Security PolicyGroup: OS_W                                             */
/* SPRMCC Security PolicyGroup: OS_W                                            */
/* SPRD0 Security PolicyGroup: OS_W                                             */
/* SPRHBMB0 Security PolicyGroup: OS_W                                          */
/* SPRLCC Security PolicyGroup: OS_W                                            */
/* EMRXCC Security PolicyGroup: OS_W                                            */
/* SPRE0 Security PolicyGroup: OS_W                                             */
/* Reserved space for PCIE header registers
*/


#define PCIE_RSVD7_0_0_2_UBOX_MISC_REG 0x13220078

typedef union {
  ///
  /// Individual bit fields
  ///
  struct {
    UINT32 reserved : 32;

                            /* Bits[31:0], Access Type=RO, default=0x00000000*/

                            /* This space is reserved */

  } Bits;
  UINT32 Data;

} PCIE_RSVD7_0_0_2_UBOX_MISC_STRUCT;

/* BIOSNONSTICKYSCRATCHPAD8_UBOX_MISC_REG supported on:                         */
/*      SPRA0 (0x21e02080)                                                      */
/*      SPRB0 (0x21e02080)                                                      */
/*      SPRHBMA0 (0x21e02080)                                                   */
/*      SPRC0 (0x21e02080)                                                      */
/*      SPRMCC (0x21e02080)                                                     */
/*      SPRD0 (0x21e02080)                                                      */
/*      SPRHBMB0 (0x21e02080)                                                   */
/*      SPRLCC (0x21e02080)                                                     */
/*      EMRXCC (0x21e02080)                                                     */
/*      SPRE0 (0x21e02080)                                                      */
/* Register default value on SPRA0: 0x00000000                                  */
/* Register default value on SPRB0: 0x00000000                                  */
/* Register default value on SPRHBMA0: 0x00000000                               */
/* Register default value on SPRC0: 0x00000000                                  */
/* Register default value on SPRMCC: 0x00000000                                 */
/* Register default value on SPRD0: 0x00000000                                  */
/* Register default value on SPRHBMB0: 0x00000000                               */
/* Register default value on SPRLCC: 0x00000000                                 */
/* Register default value on EMRXCC: 0x00000000                                 */
/* Register default value on SPRE0: 0x00000000                                  */
/* SPRA0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2             */
/* SPRB0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2             */
/* SPRHBMA0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2          */
/* SPRC0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2             */
/* SPRMCC Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2            */
/* SPRD0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2             */
/* SPRHBMB0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2          */
/* SPRLCC Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2            */
/* EMRXCC Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2            */
/* SPRE0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2             */
/* Struct generated from SPRA0 BDF: 30_0_2                                      */
/* SPRA0 Security PolicyGroup: OS_W                                             */
/* SPRB0 Security PolicyGroup: OS_W                                             */
/* SPRHBMA0 Security PolicyGroup: OS_W                                          */
/* SPRC0 Security PolicyGroup: OS_W                                             */
/* SPRMCC Security PolicyGroup: OS_W                                            */
/* SPRD0 Security PolicyGroup: OS_W                                             */
/* SPRHBMB0 Security PolicyGroup: OS_W                                          */
/* SPRLCC Security PolicyGroup: OS_W                                            */
/* EMRXCC Security PolicyGroup: OS_W                                            */
/* SPRE0 Security PolicyGroup: OS_W                                             */
/* BIOS Scratchpad register
*/


#define BIOSNONSTICKYSCRATCHPAD8_UBOX_MISC_REG 0x13220080

typedef union {
  ///
  /// Individual bit fields
  ///
  struct {
    UINT32 data : 32;

                            /* Bits[31:0], Access Type=RW, default=0x00000000*/

                            /* BIOS Scratchpad register */

  } Bits;
  UINT32 Data;

} BIOSNONSTICKYSCRATCHPAD8_UBOX_MISC_STRUCT;

/* BIOSNONSTICKYSCRATCHPAD9_UBOX_MISC_REG supported on:                         */
/*      SPRA0 (0x21e02084)                                                      */
/*      SPRB0 (0x21e02084)                                                      */
/*      SPRHBMA0 (0x21e02084)                                                   */
/*      SPRC0 (0x21e02084)                                                      */
/*      SPRMCC (0x21e02084)                                                     */
/*      SPRD0 (0x21e02084)                                                      */
/*      SPRHBMB0 (0x21e02084)                                                   */
/*      SPRLCC (0x21e02084)                                                     */
/*      EMRXCC (0x21e02084)                                                     */
/*      SPRE0 (0x21e02084)                                                      */
/* Register default value on SPRA0: 0x00000000                                  */
/* Register default value on SPRB0: 0x00000000                                  */
/* Register default value on SPRHBMA0: 0x00000000                               */
/* Register default value on SPRC0: 0x00000000                                  */
/* Register default value on SPRMCC: 0x00000000                                 */
/* Register default value on SPRD0: 0x00000000                                  */
/* Register default value on SPRHBMB0: 0x00000000                               */
/* Register default value on SPRLCC: 0x00000000                                 */
/* Register default value on EMRXCC: 0x00000000                                 */
/* Register default value on SPRE0: 0x00000000                                  */
/* SPRA0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2             */
/* SPRB0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2             */
/* SPRHBMA0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2          */
/* SPRC0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2             */
/* SPRMCC Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2            */
/* SPRD0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2             */
/* SPRHBMB0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2          */
/* SPRLCC Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2            */
/* EMRXCC Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2            */
/* SPRE0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2             */
/* Struct generated from SPRA0 BDF: 30_0_2                                      */
/* SPRA0 Security PolicyGroup: OS_W                                             */
/* SPRB0 Security PolicyGroup: OS_W                                             */
/* SPRHBMA0 Security PolicyGroup: OS_W                                          */
/* SPRC0 Security PolicyGroup: OS_W                                             */
/* SPRMCC Security PolicyGroup: OS_W                                            */
/* SPRD0 Security PolicyGroup: OS_W                                             */
/* SPRHBMB0 Security PolicyGroup: OS_W                                          */
/* SPRLCC Security PolicyGroup: OS_W                                            */
/* EMRXCC Security PolicyGroup: OS_W                                            */
/* SPRE0 Security PolicyGroup: OS_W                                             */
/* BIOS Scratchpad register
*/


#define BIOSNONSTICKYSCRATCHPAD9_UBOX_MISC_REG 0x13220084

typedef union {
  ///
  /// Individual bit fields
  ///
  struct {
    UINT32 data : 32;

                            /* Bits[31:0], Access Type=RW, default=0x00000000*/

                            /* BIOS Scratchpad register */

  } Bits;
  UINT32 Data;

} BIOSNONSTICKYSCRATCHPAD9_UBOX_MISC_STRUCT;

/* BIOSNONSTICKYSCRATCHPAD10_UBOX_MISC_REG supported on:                        */
/*      SPRA0 (0x21e02088)                                                      */
/*      SPRB0 (0x21e02088)                                                      */
/*      SPRHBMA0 (0x21e02088)                                                   */
/*      SPRC0 (0x21e02088)                                                      */
/*      SPRMCC (0x21e02088)                                                     */
/*      SPRD0 (0x21e02088)                                                      */
/*      SPRHBMB0 (0x21e02088)                                                   */
/*      SPRLCC (0x21e02088)                                                     */
/*      EMRXCC (0x21e02088)                                                     */
/*      SPRE0 (0x21e02088)                                                      */
/* Register default value on SPRA0: 0x00000000                                  */
/* Register default value on SPRB0: 0x00000000                                  */
/* Register default value on SPRHBMA0: 0x00000000                               */
/* Register default value on SPRC0: 0x00000000                                  */
/* Register default value on SPRMCC: 0x00000000                                 */
/* Register default value on SPRD0: 0x00000000                                  */
/* Register default value on SPRHBMB0: 0x00000000                               */
/* Register default value on SPRLCC: 0x00000000                                 */
/* Register default value on EMRXCC: 0x00000000                                 */
/* Register default value on SPRE0: 0x00000000                                  */
/* SPRA0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2             */
/* SPRB0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2             */
/* SPRHBMA0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2          */
/* SPRC0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2             */
/* SPRMCC Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2            */
/* SPRD0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2             */
/* SPRHBMB0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2          */
/* SPRLCC Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2            */
/* EMRXCC Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2            */
/* SPRE0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2             */
/* Struct generated from SPRA0 BDF: 30_0_2                                      */
/* SPRA0 Security PolicyGroup: OS_W                                             */
/* SPRB0 Security PolicyGroup: OS_W                                             */
/* SPRHBMA0 Security PolicyGroup: OS_W                                          */
/* SPRC0 Security PolicyGroup: OS_W                                             */
/* SPRMCC Security PolicyGroup: OS_W                                            */
/* SPRD0 Security PolicyGroup: OS_W                                             */
/* SPRHBMB0 Security PolicyGroup: OS_W                                          */
/* SPRLCC Security PolicyGroup: OS_W                                            */
/* EMRXCC Security PolicyGroup: OS_W                                            */
/* SPRE0 Security PolicyGroup: OS_W                                             */
/* BIOS Scratchpad register
*/


#define BIOSNONSTICKYSCRATCHPAD10_UBOX_MISC_REG 0x13220088

typedef union {
  ///
  /// Individual bit fields
  ///
  struct {
    UINT32 data : 32;

                            /* Bits[31:0], Access Type=RW, default=0x00000000*/

                            /* BIOS Scratchpad register */

  } Bits;
  UINT32 Data;

} BIOSNONSTICKYSCRATCHPAD10_UBOX_MISC_STRUCT;

/* BIOSNONSTICKYSCRATCHPAD11_UBOX_MISC_REG supported on:                        */
/*      SPRA0 (0x21e0208c)                                                      */
/*      SPRB0 (0x21e0208c)                                                      */
/*      SPRHBMA0 (0x21e0208c)                                                   */
/*      SPRC0 (0x21e0208c)                                                      */
/*      SPRMCC (0x21e0208c)                                                     */
/*      SPRD0 (0x21e0208c)                                                      */
/*      SPRHBMB0 (0x21e0208c)                                                   */
/*      SPRLCC (0x21e0208c)                                                     */
/*      EMRXCC (0x21e0208c)                                                     */
/*      SPRE0 (0x21e0208c)                                                      */
/* Register default value on SPRA0: 0x00000000                                  */
/* Register default value on SPRB0: 0x00000000                                  */
/* Register default value on SPRHBMA0: 0x00000000                               */
/* Register default value on SPRC0: 0x00000000                                  */
/* Register default value on SPRMCC: 0x00000000                                 */
/* Register default value on SPRD0: 0x00000000                                  */
/* Register default value on SPRHBMB0: 0x00000000                               */
/* Register default value on SPRLCC: 0x00000000                                 */
/* Register default value on EMRXCC: 0x00000000                                 */
/* Register default value on SPRE0: 0x00000000                                  */
/* SPRA0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2             */
/* SPRB0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2             */
/* SPRHBMA0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2          */
/* SPRC0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2             */
/* SPRMCC Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2            */
/* SPRD0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2             */
/* SPRHBMB0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2          */
/* SPRLCC Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2            */
/* EMRXCC Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2            */
/* SPRE0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2             */
/* Struct generated from SPRA0 BDF: 30_0_2                                      */
/* SPRA0 Security PolicyGroup: OS_W                                             */
/* SPRB0 Security PolicyGroup: OS_W                                             */
/* SPRHBMA0 Security PolicyGroup: OS_W                                          */
/* SPRC0 Security PolicyGroup: OS_W                                             */
/* SPRMCC Security PolicyGroup: OS_W                                            */
/* SPRD0 Security PolicyGroup: OS_W                                             */
/* SPRHBMB0 Security PolicyGroup: OS_W                                          */
/* SPRLCC Security PolicyGroup: OS_W                                            */
/* EMRXCC Security PolicyGroup: OS_W                                            */
/* SPRE0 Security PolicyGroup: OS_W                                             */
/* BIOS Scratchpad register
*/


#define BIOSNONSTICKYSCRATCHPAD11_UBOX_MISC_REG 0x1322008C

typedef union {
  ///
  /// Individual bit fields
  ///
  struct {
    UINT32 data : 32;

                            /* Bits[31:0], Access Type=RW, default=0x00000000*/

                            /* BIOS Scratchpad register */

  } Bits;
  UINT32 Data;

} BIOSNONSTICKYSCRATCHPAD11_UBOX_MISC_STRUCT;

/* BIOSNONSTICKYSCRATCHPAD12_UBOX_MISC_REG supported on:                        */
/*      SPRA0 (0x21e02090)                                                      */
/*      SPRB0 (0x21e02090)                                                      */
/*      SPRHBMA0 (0x21e02090)                                                   */
/*      SPRC0 (0x21e02090)                                                      */
/*      SPRMCC (0x21e02090)                                                     */
/*      SPRD0 (0x21e02090)                                                      */
/*      SPRHBMB0 (0x21e02090)                                                   */
/*      SPRLCC (0x21e02090)                                                     */
/*      EMRXCC (0x21e02090)                                                     */
/*      SPRE0 (0x21e02090)                                                      */
/* Register default value on SPRA0: 0x00000000                                  */
/* Register default value on SPRB0: 0x00000000                                  */
/* Register default value on SPRHBMA0: 0x00000000                               */
/* Register default value on SPRC0: 0x00000000                                  */
/* Register default value on SPRMCC: 0x00000000                                 */
/* Register default value on SPRD0: 0x00000000                                  */
/* Register default value on SPRHBMB0: 0x00000000                               */
/* Register default value on SPRLCC: 0x00000000                                 */
/* Register default value on EMRXCC: 0x00000000                                 */
/* Register default value on SPRE0: 0x00000000                                  */
/* SPRA0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2             */
/* SPRB0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2             */
/* SPRHBMA0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2          */
/* SPRC0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2             */
/* SPRMCC Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2            */
/* SPRD0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2             */
/* SPRHBMB0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2          */
/* SPRLCC Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2            */
/* EMRXCC Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2            */
/* SPRE0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2             */
/* Struct generated from SPRA0 BDF: 30_0_2                                      */
/* SPRA0 Security PolicyGroup: OS_W                                             */
/* SPRB0 Security PolicyGroup: OS_W                                             */
/* SPRHBMA0 Security PolicyGroup: OS_W                                          */
/* SPRC0 Security PolicyGroup: OS_W                                             */
/* SPRMCC Security PolicyGroup: OS_W                                            */
/* SPRD0 Security PolicyGroup: OS_W                                             */
/* SPRHBMB0 Security PolicyGroup: OS_W                                          */
/* SPRLCC Security PolicyGroup: OS_W                                            */
/* EMRXCC Security PolicyGroup: OS_W                                            */
/* SPRE0 Security PolicyGroup: OS_W                                             */
/* BIOS Scratchpad register
*/


#define BIOSNONSTICKYSCRATCHPAD12_UBOX_MISC_REG 0x13220090

typedef union {
  ///
  /// Individual bit fields
  ///
  struct {
    UINT32 data : 32;

                            /* Bits[31:0], Access Type=RW, default=0x00000000*/

                            /* BIOS Scratchpad register */

  } Bits;
  UINT32 Data;

} BIOSNONSTICKYSCRATCHPAD12_UBOX_MISC_STRUCT;

/* BIOSNONSTICKYSCRATCHPAD13_UBOX_MISC_REG supported on:                        */
/*      SPRA0 (0x21e02094)                                                      */
/*      SPRB0 (0x21e02094)                                                      */
/*      SPRHBMA0 (0x21e02094)                                                   */
/*      SPRC0 (0x21e02094)                                                      */
/*      SPRMCC (0x21e02094)                                                     */
/*      SPRD0 (0x21e02094)                                                      */
/*      SPRHBMB0 (0x21e02094)                                                   */
/*      SPRLCC (0x21e02094)                                                     */
/*      EMRXCC (0x21e02094)                                                     */
/*      SPRE0 (0x21e02094)                                                      */
/* Register default value on SPRA0: 0x00000000                                  */
/* Register default value on SPRB0: 0x00000000                                  */
/* Register default value on SPRHBMA0: 0x00000000                               */
/* Register default value on SPRC0: 0x00000000                                  */
/* Register default value on SPRMCC: 0x00000000                                 */
/* Register default value on SPRD0: 0x00000000                                  */
/* Register default value on SPRHBMB0: 0x00000000                               */
/* Register default value on SPRLCC: 0x00000000                                 */
/* Register default value on EMRXCC: 0x00000000                                 */
/* Register default value on SPRE0: 0x00000000                                  */
/* SPRA0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2             */
/* SPRB0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2             */
/* SPRHBMA0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2          */
/* SPRC0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2             */
/* SPRMCC Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2            */
/* SPRD0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2             */
/* SPRHBMB0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2          */
/* SPRLCC Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2            */
/* EMRXCC Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2            */
/* SPRE0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2             */
/* Struct generated from SPRA0 BDF: 30_0_2                                      */
/* SPRA0 Security PolicyGroup: OS_W                                             */
/* SPRB0 Security PolicyGroup: OS_W                                             */
/* SPRHBMA0 Security PolicyGroup: OS_W                                          */
/* SPRC0 Security PolicyGroup: OS_W                                             */
/* SPRMCC Security PolicyGroup: OS_W                                            */
/* SPRD0 Security PolicyGroup: OS_W                                             */
/* SPRHBMB0 Security PolicyGroup: OS_W                                          */
/* SPRLCC Security PolicyGroup: OS_W                                            */
/* EMRXCC Security PolicyGroup: OS_W                                            */
/* SPRE0 Security PolicyGroup: OS_W                                             */
/* BIOS Scratchpad register
*/


#define BIOSNONSTICKYSCRATCHPAD13_UBOX_MISC_REG 0x13220094

typedef union {
  ///
  /// Individual bit fields
  ///
  struct {
    UINT32 data : 32;

                            /* Bits[31:0], Access Type=RW, default=0x00000000*/

                            /* BIOS Scratchpad register */

  } Bits;
  UINT32 Data;

} BIOSNONSTICKYSCRATCHPAD13_UBOX_MISC_STRUCT;

/* BIOSNONSTICKYSCRATCHPAD14_UBOX_MISC_REG supported on:                        */
/*      SPRA0 (0x21e02098)                                                      */
/*      SPRB0 (0x21e02098)                                                      */
/*      SPRHBMA0 (0x21e02098)                                                   */
/*      SPRC0 (0x21e02098)                                                      */
/*      SPRMCC (0x21e02098)                                                     */
/*      SPRD0 (0x21e02098)                                                      */
/*      SPRHBMB0 (0x21e02098)                                                   */
/*      SPRLCC (0x21e02098)                                                     */
/*      EMRXCC (0x21e02098)                                                     */
/*      SPRE0 (0x21e02098)                                                      */
/* Register default value on SPRA0: 0x00000000                                  */
/* Register default value on SPRB0: 0x00000000                                  */
/* Register default value on SPRHBMA0: 0x00000000                               */
/* Register default value on SPRC0: 0x00000000                                  */
/* Register default value on SPRMCC: 0x00000000                                 */
/* Register default value on SPRD0: 0x00000000                                  */
/* Register default value on SPRHBMB0: 0x00000000                               */
/* Register default value on SPRLCC: 0x00000000                                 */
/* Register default value on EMRXCC: 0x00000000                                 */
/* Register default value on SPRE0: 0x00000000                                  */
/* SPRA0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2             */
/* SPRB0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2             */
/* SPRHBMA0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2          */
/* SPRC0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2             */
/* SPRMCC Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2            */
/* SPRD0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2             */
/* SPRHBMB0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2          */
/* SPRLCC Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2            */
/* EMRXCC Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2            */
/* SPRE0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2             */
/* Struct generated from SPRA0 BDF: 30_0_2                                      */
/* SPRA0 Security PolicyGroup: OS_W                                             */
/* SPRB0 Security PolicyGroup: OS_W                                             */
/* SPRHBMA0 Security PolicyGroup: OS_W                                          */
/* SPRC0 Security PolicyGroup: OS_W                                             */
/* SPRMCC Security PolicyGroup: OS_W                                            */
/* SPRD0 Security PolicyGroup: OS_W                                             */
/* SPRHBMB0 Security PolicyGroup: OS_W                                          */
/* SPRLCC Security PolicyGroup: OS_W                                            */
/* EMRXCC Security PolicyGroup: OS_W                                            */
/* SPRE0 Security PolicyGroup: OS_W                                             */
/* BIOS Scratchpad register
*/


#define BIOSNONSTICKYSCRATCHPAD14_UBOX_MISC_REG 0x13220098

typedef union {
  ///
  /// Individual bit fields
  ///
  struct {
    UINT32 data : 32;

                            /* Bits[31:0], Access Type=RW, default=0x00000000*/

                            /* BIOS Scratchpad register */

  } Bits;
  UINT32 Data;

} BIOSNONSTICKYSCRATCHPAD14_UBOX_MISC_STRUCT;

/* BIOSNONSTICKYSCRATCHPAD15_UBOX_MISC_REG supported on:                        */
/*      SPRA0 (0x21e0209c)                                                      */
/*      SPRB0 (0x21e0209c)                                                      */
/*      SPRHBMA0 (0x21e0209c)                                                   */
/*      SPRC0 (0x21e0209c)                                                      */
/*      SPRMCC (0x21e0209c)                                                     */
/*      SPRD0 (0x21e0209c)                                                      */
/*      SPRHBMB0 (0x21e0209c)                                                   */
/*      SPRLCC (0x21e0209c)                                                     */
/*      EMRXCC (0x21e0209c)                                                     */
/*      SPRE0 (0x21e0209c)                                                      */
/* Register default value on SPRA0: 0x00000000                                  */
/* Register default value on SPRB0: 0x00000000                                  */
/* Register default value on SPRHBMA0: 0x00000000                               */
/* Register default value on SPRC0: 0x00000000                                  */
/* Register default value on SPRMCC: 0x00000000                                 */
/* Register default value on SPRD0: 0x00000000                                  */
/* Register default value on SPRHBMB0: 0x00000000                               */
/* Register default value on SPRLCC: 0x00000000                                 */
/* Register default value on EMRXCC: 0x00000000                                 */
/* Register default value on SPRE0: 0x00000000                                  */
/* SPRA0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2             */
/* SPRB0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2             */
/* SPRHBMA0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2          */
/* SPRC0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2             */
/* SPRMCC Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2            */
/* SPRD0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2             */
/* SPRHBMB0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2          */
/* SPRLCC Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2            */
/* EMRXCC Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2            */
/* SPRE0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2             */
/* Struct generated from SPRA0 BDF: 30_0_2                                      */
/* SPRA0 Security PolicyGroup: OS_W                                             */
/* SPRB0 Security PolicyGroup: OS_W                                             */
/* SPRHBMA0 Security PolicyGroup: OS_W                                          */
/* SPRC0 Security PolicyGroup: OS_W                                             */
/* SPRMCC Security PolicyGroup: OS_W                                            */
/* SPRD0 Security PolicyGroup: OS_W                                             */
/* SPRHBMB0 Security PolicyGroup: OS_W                                          */
/* SPRLCC Security PolicyGroup: OS_W                                            */
/* EMRXCC Security PolicyGroup: OS_W                                            */
/* SPRE0 Security PolicyGroup: OS_W                                             */
/* BIOS Scratchpad register
*/


#define BIOSNONSTICKYSCRATCHPAD15_UBOX_MISC_REG 0x1322009C

typedef union {
  ///
  /// Individual bit fields
  ///
  struct {
    UINT32 data : 32;

                            /* Bits[31:0], Access Type=RW, default=0x00000000*/

                            /* BIOS Scratchpad register */

  } Bits;
  UINT32 Data;

} BIOSNONSTICKYSCRATCHPAD15_UBOX_MISC_STRUCT;

/* BIOSSCRATCHPAD0_UBOX_MISC_REG supported on:                                  */
/*      SPRA0 (0x21e020a0)                                                      */
/*      SPRB0 (0x21e020a0)                                                      */
/*      SPRHBMA0 (0x21e020a0)                                                   */
/*      SPRC0 (0x21e020a0)                                                      */
/*      SPRMCC (0x21e020a0)                                                     */
/*      SPRD0 (0x21e020a0)                                                      */
/*      SPRHBMB0 (0x21e020a0)                                                   */
/*      SPRLCC (0x21e020a0)                                                     */
/*      EMRXCC (0x21e020a0)                                                     */
/*      SPRE0 (0x21e020a0)                                                      */
/* Register default value on SPRA0: 0x00000000                                  */
/* Register default value on SPRB0: 0x00000000                                  */
/* Register default value on SPRHBMA0: 0x00000000                               */
/* Register default value on SPRC0: 0x00000000                                  */
/* Register default value on SPRMCC: 0x00000000                                 */
/* Register default value on SPRD0: 0x00000000                                  */
/* Register default value on SPRHBMB0: 0x00000000                               */
/* Register default value on SPRLCC: 0x00000000                                 */
/* Register default value on EMRXCC: 0x00000000                                 */
/* Register default value on SPRE0: 0x00000000                                  */
/* SPRA0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2             */
/* SPRB0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2             */
/* SPRHBMA0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2          */
/* SPRC0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2             */
/* SPRMCC Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2            */
/* SPRD0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2             */
/* SPRHBMB0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2          */
/* SPRLCC Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2            */
/* EMRXCC Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2            */
/* SPRE0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2             */
/* Struct generated from SPRA0 BDF: 30_0_2                                      */
/* SPRA0 Security PolicyGroup: OS_W                                             */
/* SPRB0 Security PolicyGroup: OS_W                                             */
/* SPRHBMA0 Security PolicyGroup: OS_W                                          */
/* SPRC0 Security PolicyGroup: OS_W                                             */
/* SPRMCC Security PolicyGroup: OS_W                                            */
/* SPRD0 Security PolicyGroup: OS_W                                             */
/* SPRHBMB0 Security PolicyGroup: OS_W                                          */
/* SPRLCC Security PolicyGroup: OS_W                                            */
/* EMRXCC Security PolicyGroup: OS_W                                            */
/* SPRE0 Security PolicyGroup: OS_W                                             */
/* BIOS Scratchpad
*/


#define BIOSSCRATCHPAD0_UBOX_MISC_REG 0x132200A0

typedef union {
  ///
  /// Individual bit fields
  ///
  struct {
    UINT32 data : 32;

                            /* Bits[31:0], Access Type=RW/P, default=0x00000000*/

                            /* Set by BIOS, sticky across RESET */

  } Bits;
  UINT32 Data;

} BIOSSCRATCHPAD0_UBOX_MISC_STRUCT;

/* BIOSSCRATCHPAD1_UBOX_MISC_REG supported on:                                  */
/*      SPRA0 (0x21e020a4)                                                      */
/*      SPRB0 (0x21e020a4)                                                      */
/*      SPRHBMA0 (0x21e020a4)                                                   */
/*      SPRC0 (0x21e020a4)                                                      */
/*      SPRMCC (0x21e020a4)                                                     */
/*      SPRD0 (0x21e020a4)                                                      */
/*      SPRHBMB0 (0x21e020a4)                                                   */
/*      SPRLCC (0x21e020a4)                                                     */
/*      EMRXCC (0x21e020a4)                                                     */
/*      SPRE0 (0x21e020a4)                                                      */
/* Register default value on SPRA0: 0x00000000                                  */
/* Register default value on SPRB0: 0x00000000                                  */
/* Register default value on SPRHBMA0: 0x00000000                               */
/* Register default value on SPRC0: 0x00000000                                  */
/* Register default value on SPRMCC: 0x00000000                                 */
/* Register default value on SPRD0: 0x00000000                                  */
/* Register default value on SPRHBMB0: 0x00000000                               */
/* Register default value on SPRLCC: 0x00000000                                 */
/* Register default value on EMRXCC: 0x00000000                                 */
/* Register default value on SPRE0: 0x00000000                                  */
/* SPRA0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2             */
/* SPRB0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2             */
/* SPRHBMA0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2          */
/* SPRC0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2             */
/* SPRMCC Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2            */
/* SPRD0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2             */
/* SPRHBMB0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2          */
/* SPRLCC Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2            */
/* EMRXCC Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2            */
/* SPRE0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2             */
/* Struct generated from SPRA0 BDF: 30_0_2                                      */
/* SPRA0 Security PolicyGroup: OS_W                                             */
/* SPRB0 Security PolicyGroup: OS_W                                             */
/* SPRHBMA0 Security PolicyGroup: OS_W                                          */
/* SPRC0 Security PolicyGroup: OS_W                                             */
/* SPRMCC Security PolicyGroup: OS_W                                            */
/* SPRD0 Security PolicyGroup: OS_W                                             */
/* SPRHBMB0 Security PolicyGroup: OS_W                                          */
/* SPRLCC Security PolicyGroup: OS_W                                            */
/* EMRXCC Security PolicyGroup: OS_W                                            */
/* SPRE0 Security PolicyGroup: OS_W                                             */
/* BIOS Scratchpad
*/


#define BIOSSCRATCHPAD1_UBOX_MISC_REG 0x132200A4

typedef union {
  ///
  /// Individual bit fields
  ///
  struct {
    UINT32 data : 32;

                            /* Bits[31:0], Access Type=RW/P, default=0x00000000*/

                            /* Set by BIOS, sticky across RESET */

  } Bits;
  UINT32 Data;

} BIOSSCRATCHPAD1_UBOX_MISC_STRUCT;

/* BIOSSCRATCHPAD2_UBOX_MISC_REG supported on:                                  */
/*      SPRA0 (0x21e020a8)                                                      */
/*      SPRB0 (0x21e020a8)                                                      */
/*      SPRHBMA0 (0x21e020a8)                                                   */
/*      SPRC0 (0x21e020a8)                                                      */
/*      SPRMCC (0x21e020a8)                                                     */
/*      SPRD0 (0x21e020a8)                                                      */
/*      SPRHBMB0 (0x21e020a8)                                                   */
/*      SPRLCC (0x21e020a8)                                                     */
/*      EMRXCC (0x21e020a8)                                                     */
/*      SPRE0 (0x21e020a8)                                                      */
/* Register default value on SPRA0: 0x00000000                                  */
/* Register default value on SPRB0: 0x00000000                                  */
/* Register default value on SPRHBMA0: 0x00000000                               */
/* Register default value on SPRC0: 0x00000000                                  */
/* Register default value on SPRMCC: 0x00000000                                 */
/* Register default value on SPRD0: 0x00000000                                  */
/* Register default value on SPRHBMB0: 0x00000000                               */
/* Register default value on SPRLCC: 0x00000000                                 */
/* Register default value on EMRXCC: 0x00000000                                 */
/* Register default value on SPRE0: 0x00000000                                  */
/* SPRA0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2             */
/* SPRB0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2             */
/* SPRHBMA0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2          */
/* SPRC0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2             */
/* SPRMCC Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2            */
/* SPRD0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2             */
/* SPRHBMB0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2          */
/* SPRLCC Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2            */
/* EMRXCC Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2            */
/* SPRE0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2             */
/* Struct generated from SPRA0 BDF: 30_0_2                                      */
/* SPRA0 Security PolicyGroup: OS_W                                             */
/* SPRB0 Security PolicyGroup: OS_W                                             */
/* SPRHBMA0 Security PolicyGroup: OS_W                                          */
/* SPRC0 Security PolicyGroup: OS_W                                             */
/* SPRMCC Security PolicyGroup: OS_W                                            */
/* SPRD0 Security PolicyGroup: OS_W                                             */
/* SPRHBMB0 Security PolicyGroup: OS_W                                          */
/* SPRLCC Security PolicyGroup: OS_W                                            */
/* EMRXCC Security PolicyGroup: OS_W                                            */
/* SPRE0 Security PolicyGroup: OS_W                                             */
/* BIOS Scratchpad
*/


#define BIOSSCRATCHPAD2_UBOX_MISC_REG 0x132200A8

typedef union {
  ///
  /// Individual bit fields
  ///
  struct {
    UINT32 data : 32;

                            /* Bits[31:0], Access Type=RW/P, default=0x00000000*/

                            /* Set by BIOS, sticky across RESET */

  } Bits;
  UINT32 Data;

} BIOSSCRATCHPAD2_UBOX_MISC_STRUCT;

/* BIOSSCRATCHPAD3_UBOX_MISC_REG supported on:                                  */
/*      SPRA0 (0x21e020ac)                                                      */
/*      SPRB0 (0x21e020ac)                                                      */
/*      SPRHBMA0 (0x21e020ac)                                                   */
/*      SPRC0 (0x21e020ac)                                                      */
/*      SPRMCC (0x21e020ac)                                                     */
/*      SPRD0 (0x21e020ac)                                                      */
/*      SPRHBMB0 (0x21e020ac)                                                   */
/*      SPRLCC (0x21e020ac)                                                     */
/*      EMRXCC (0x21e020ac)                                                     */
/*      SPRE0 (0x21e020ac)                                                      */
/* Register default value on SPRA0: 0x00000000                                  */
/* Register default value on SPRB0: 0x00000000                                  */
/* Register default value on SPRHBMA0: 0x00000000                               */
/* Register default value on SPRC0: 0x00000000                                  */
/* Register default value on SPRMCC: 0x00000000                                 */
/* Register default value on SPRD0: 0x00000000                                  */
/* Register default value on SPRHBMB0: 0x00000000                               */
/* Register default value on SPRLCC: 0x00000000                                 */
/* Register default value on EMRXCC: 0x00000000                                 */
/* Register default value on SPRE0: 0x00000000                                  */
/* SPRA0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2             */
/* SPRB0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2             */
/* SPRHBMA0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2          */
/* SPRC0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2             */
/* SPRMCC Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2            */
/* SPRD0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2             */
/* SPRHBMB0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2          */
/* SPRLCC Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2            */
/* EMRXCC Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2            */
/* SPRE0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2             */
/* Struct generated from SPRA0 BDF: 30_0_2                                      */
/* SPRA0 Security PolicyGroup: OS_W                                             */
/* SPRB0 Security PolicyGroup: OS_W                                             */
/* SPRHBMA0 Security PolicyGroup: OS_W                                          */
/* SPRC0 Security PolicyGroup: OS_W                                             */
/* SPRMCC Security PolicyGroup: OS_W                                            */
/* SPRD0 Security PolicyGroup: OS_W                                             */
/* SPRHBMB0 Security PolicyGroup: OS_W                                          */
/* SPRLCC Security PolicyGroup: OS_W                                            */
/* EMRXCC Security PolicyGroup: OS_W                                            */
/* SPRE0 Security PolicyGroup: OS_W                                             */
/* BIOS Scratchpad
*/


#define BIOSSCRATCHPAD3_UBOX_MISC_REG 0x132200AC

typedef union {
  ///
  /// Individual bit fields
  ///
  struct {
    UINT32 data : 32;

                            /* Bits[31:0], Access Type=RW/P, default=0x00000000*/

                            /* Set by BIOS, sticky across RESET */

  } Bits;
  UINT32 Data;

} BIOSSCRATCHPAD3_UBOX_MISC_STRUCT;

/* BIOSSCRATCHPAD4_UBOX_MISC_REG supported on:                                  */
/*      SPRA0 (0x21e020b0)                                                      */
/*      SPRB0 (0x21e020b0)                                                      */
/*      SPRHBMA0 (0x21e020b0)                                                   */
/*      SPRC0 (0x21e020b0)                                                      */
/*      SPRMCC (0x21e020b0)                                                     */
/*      SPRD0 (0x21e020b0)                                                      */
/*      SPRHBMB0 (0x21e020b0)                                                   */
/*      SPRLCC (0x21e020b0)                                                     */
/*      EMRXCC (0x21e020b0)                                                     */
/*      SPRE0 (0x21e020b0)                                                      */
/* Register default value on SPRA0: 0x00000000                                  */
/* Register default value on SPRB0: 0x00000000                                  */
/* Register default value on SPRHBMA0: 0x00000000                               */
/* Register default value on SPRC0: 0x00000000                                  */
/* Register default value on SPRMCC: 0x00000000                                 */
/* Register default value on SPRD0: 0x00000000                                  */
/* Register default value on SPRHBMB0: 0x00000000                               */
/* Register default value on SPRLCC: 0x00000000                                 */
/* Register default value on EMRXCC: 0x00000000                                 */
/* Register default value on SPRE0: 0x00000000                                  */
/* SPRA0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2             */
/* SPRB0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2             */
/* SPRHBMA0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2          */
/* SPRC0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2             */
/* SPRMCC Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2            */
/* SPRD0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2             */
/* SPRHBMB0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2          */
/* SPRLCC Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2            */
/* EMRXCC Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2            */
/* SPRE0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2             */
/* Struct generated from SPRA0 BDF: 30_0_2                                      */
/* SPRA0 Security PolicyGroup: OS_W                                             */
/* SPRB0 Security PolicyGroup: OS_W                                             */
/* SPRHBMA0 Security PolicyGroup: OS_W                                          */
/* SPRC0 Security PolicyGroup: OS_W                                             */
/* SPRMCC Security PolicyGroup: OS_W                                            */
/* SPRD0 Security PolicyGroup: OS_W                                             */
/* SPRHBMB0 Security PolicyGroup: OS_W                                          */
/* SPRLCC Security PolicyGroup: OS_W                                            */
/* EMRXCC Security PolicyGroup: OS_W                                            */
/* SPRE0 Security PolicyGroup: OS_W                                             */
/* BIOS Scratchpad
*/


#define BIOSSCRATCHPAD4_UBOX_MISC_REG 0x132200B0

typedef union {
  ///
  /// Individual bit fields
  ///
  struct {
    UINT32 data : 32;

                            /* Bits[31:0], Access Type=RW/P, default=0x00000000*/

                            /* Set by BIOS, sticky across RESET */

  } Bits;
  UINT32 Data;

} BIOSSCRATCHPAD4_UBOX_MISC_STRUCT;

/* BIOSSCRATCHPAD5_UBOX_MISC_REG supported on:                                  */
/*      SPRA0 (0x21e020b4)                                                      */
/*      SPRB0 (0x21e020b4)                                                      */
/*      SPRHBMA0 (0x21e020b4)                                                   */
/*      SPRC0 (0x21e020b4)                                                      */
/*      SPRMCC (0x21e020b4)                                                     */
/*      SPRD0 (0x21e020b4)                                                      */
/*      SPRHBMB0 (0x21e020b4)                                                   */
/*      SPRLCC (0x21e020b4)                                                     */
/*      EMRXCC (0x21e020b4)                                                     */
/*      SPRE0 (0x21e020b4)                                                      */
/* Register default value on SPRA0: 0x00000000                                  */
/* Register default value on SPRB0: 0x00000000                                  */
/* Register default value on SPRHBMA0: 0x00000000                               */
/* Register default value on SPRC0: 0x00000000                                  */
/* Register default value on SPRMCC: 0x00000000                                 */
/* Register default value on SPRD0: 0x00000000                                  */
/* Register default value on SPRHBMB0: 0x00000000                               */
/* Register default value on SPRLCC: 0x00000000                                 */
/* Register default value on EMRXCC: 0x00000000                                 */
/* Register default value on SPRE0: 0x00000000                                  */
/* SPRA0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2             */
/* SPRB0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2             */
/* SPRHBMA0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2          */
/* SPRC0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2             */
/* SPRMCC Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2            */
/* SPRD0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2             */
/* SPRHBMB0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2          */
/* SPRLCC Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2            */
/* EMRXCC Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2            */
/* SPRE0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2             */
/* Struct generated from SPRA0 BDF: 30_0_2                                      */
/* SPRA0 Security PolicyGroup: OS_W                                             */
/* SPRB0 Security PolicyGroup: OS_W                                             */
/* SPRHBMA0 Security PolicyGroup: OS_W                                          */
/* SPRC0 Security PolicyGroup: OS_W                                             */
/* SPRMCC Security PolicyGroup: OS_W                                            */
/* SPRD0 Security PolicyGroup: OS_W                                             */
/* SPRHBMB0 Security PolicyGroup: OS_W                                          */
/* SPRLCC Security PolicyGroup: OS_W                                            */
/* EMRXCC Security PolicyGroup: OS_W                                            */
/* SPRE0 Security PolicyGroup: OS_W                                             */
/* BIOS Scratchpad
*/


#define BIOSSCRATCHPAD5_UBOX_MISC_REG 0x132200B4

typedef union {
  ///
  /// Individual bit fields
  ///
  struct {
    UINT32 data : 32;

                            /* Bits[31:0], Access Type=RW/P, default=0x00000000*/

                            /* Set by BIOS, sticky across RESET */

  } Bits;
  UINT32 Data;

} BIOSSCRATCHPAD5_UBOX_MISC_STRUCT;

/* BIOSSCRATCHPAD6_UBOX_MISC_REG supported on:                                  */
/*      SPRA0 (0x21e020b8)                                                      */
/*      SPRB0 (0x21e020b8)                                                      */
/*      SPRHBMA0 (0x21e020b8)                                                   */
/*      SPRC0 (0x21e020b8)                                                      */
/*      SPRMCC (0x21e020b8)                                                     */
/*      SPRD0 (0x21e020b8)                                                      */
/*      SPRHBMB0 (0x21e020b8)                                                   */
/*      SPRLCC (0x21e020b8)                                                     */
/*      EMRXCC (0x21e020b8)                                                     */
/*      SPRE0 (0x21e020b8)                                                      */
/* Register default value on SPRA0: 0x00000000                                  */
/* Register default value on SPRB0: 0x00000000                                  */
/* Register default value on SPRHBMA0: 0x00000000                               */
/* Register default value on SPRC0: 0x00000000                                  */
/* Register default value on SPRMCC: 0x00000000                                 */
/* Register default value on SPRD0: 0x00000000                                  */
/* Register default value on SPRHBMB0: 0x00000000                               */
/* Register default value on SPRLCC: 0x00000000                                 */
/* Register default value on EMRXCC: 0x00000000                                 */
/* Register default value on SPRE0: 0x00000000                                  */
/* SPRA0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2             */
/* SPRB0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2             */
/* SPRHBMA0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2          */
/* SPRC0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2             */
/* SPRMCC Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2            */
/* SPRD0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2             */
/* SPRHBMB0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2          */
/* SPRLCC Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2            */
/* EMRXCC Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2            */
/* SPRE0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2             */
/* Struct generated from SPRA0 BDF: 30_0_2                                      */
/* SPRA0 Security PolicyGroup: OS_W                                             */
/* SPRB0 Security PolicyGroup: OS_W                                             */
/* SPRHBMA0 Security PolicyGroup: OS_W                                          */
/* SPRC0 Security PolicyGroup: OS_W                                             */
/* SPRMCC Security PolicyGroup: OS_W                                            */
/* SPRD0 Security PolicyGroup: OS_W                                             */
/* SPRHBMB0 Security PolicyGroup: OS_W                                          */
/* SPRLCC Security PolicyGroup: OS_W                                            */
/* EMRXCC Security PolicyGroup: OS_W                                            */
/* SPRE0 Security PolicyGroup: OS_W                                             */
/* BIOS Scratchpad
*/


#define BIOSSCRATCHPAD6_UBOX_MISC_REG 0x132200B8

typedef union {
  ///
  /// Individual bit fields
  ///
  struct {
    UINT32 data : 32;

                            /* Bits[31:0], Access Type=RW/P, default=0x00000000*/

                            /* Set by BIOS, sticky across RESET */

  } Bits;
  UINT32 Data;

} BIOSSCRATCHPAD6_UBOX_MISC_STRUCT;

/* BIOSSCRATCHPAD7_UBOX_MISC_REG supported on:                                  */
/*      SPRA0 (0x21e020bc)                                                      */
/*      SPRB0 (0x21e020bc)                                                      */
/*      SPRHBMA0 (0x21e020bc)                                                   */
/*      SPRC0 (0x21e020bc)                                                      */
/*      SPRMCC (0x21e020bc)                                                     */
/*      SPRD0 (0x21e020bc)                                                      */
/*      SPRHBMB0 (0x21e020bc)                                                   */
/*      SPRLCC (0x21e020bc)                                                     */
/*      EMRXCC (0x21e020bc)                                                     */
/*      SPRE0 (0x21e020bc)                                                      */
/* Register default value on SPRA0: 0x00000000                                  */
/* Register default value on SPRB0: 0x00000000                                  */
/* Register default value on SPRHBMA0: 0x00000000                               */
/* Register default value on SPRC0: 0x00000000                                  */
/* Register default value on SPRMCC: 0x00000000                                 */
/* Register default value on SPRD0: 0x00000000                                  */
/* Register default value on SPRHBMB0: 0x00000000                               */
/* Register default value on SPRLCC: 0x00000000                                 */
/* Register default value on EMRXCC: 0x00000000                                 */
/* Register default value on SPRE0: 0x00000000                                  */
/* SPRA0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2             */
/* SPRB0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2             */
/* SPRHBMA0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2          */
/* SPRC0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2             */
/* SPRMCC Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2            */
/* SPRD0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2             */
/* SPRHBMB0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2          */
/* SPRLCC Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2            */
/* EMRXCC Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2            */
/* SPRE0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2             */
/* Struct generated from SPRA0 BDF: 30_0_2                                      */
/* SPRA0 Security PolicyGroup: OS_W                                             */
/* SPRB0 Security PolicyGroup: OS_W                                             */
/* SPRHBMA0 Security PolicyGroup: OS_W                                          */
/* SPRC0 Security PolicyGroup: OS_W                                             */
/* SPRMCC Security PolicyGroup: OS_W                                            */
/* SPRD0 Security PolicyGroup: OS_W                                             */
/* SPRHBMB0 Security PolicyGroup: OS_W                                          */
/* SPRLCC Security PolicyGroup: OS_W                                            */
/* EMRXCC Security PolicyGroup: OS_W                                            */
/* SPRE0 Security PolicyGroup: OS_W                                             */
/* BIOS Scratchpad
*/


#define BIOSSCRATCHPAD7_UBOX_MISC_REG 0x132200BC

typedef union {
  ///
  /// Individual bit fields
  ///
  struct {
    UINT32 data : 32;

                            /* Bits[31:0], Access Type=RW/P, default=0x00000000*/

                            /* Set by BIOS, sticky across RESET */

  } Bits;
  UINT32 Data;

} BIOSSCRATCHPAD7_UBOX_MISC_STRUCT;

/* BIOSNONSTICKYSCRATCHPAD0_UBOX_MISC_REG supported on:                         */
/*      SPRA0 (0x21e020c0)                                                      */
/*      SPRB0 (0x21e020c0)                                                      */
/*      SPRHBMA0 (0x21e020c0)                                                   */
/*      SPRC0 (0x21e020c0)                                                      */
/*      SPRMCC (0x21e020c0)                                                     */
/*      SPRD0 (0x21e020c0)                                                      */
/*      SPRHBMB0 (0x21e020c0)                                                   */
/*      SPRLCC (0x21e020c0)                                                     */
/*      EMRXCC (0x21e020c0)                                                     */
/*      SPRE0 (0x21e020c0)                                                      */
/* Register default value on SPRA0: 0x00000000                                  */
/* Register default value on SPRB0: 0x00000000                                  */
/* Register default value on SPRHBMA0: 0x00000000                               */
/* Register default value on SPRC0: 0x00000000                                  */
/* Register default value on SPRMCC: 0x00000000                                 */
/* Register default value on SPRD0: 0x00000000                                  */
/* Register default value on SPRHBMB0: 0x00000000                               */
/* Register default value on SPRLCC: 0x00000000                                 */
/* Register default value on EMRXCC: 0x00000000                                 */
/* Register default value on SPRE0: 0x00000000                                  */
/* SPRA0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2             */
/* SPRB0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2             */
/* SPRHBMA0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2          */
/* SPRC0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2             */
/* SPRMCC Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2            */
/* SPRD0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2             */
/* SPRHBMB0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2          */
/* SPRLCC Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2            */
/* EMRXCC Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2            */
/* SPRE0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2             */
/* Struct generated from SPRA0 BDF: 30_0_2                                      */
/* SPRA0 Security PolicyGroup: OS_W                                             */
/* SPRB0 Security PolicyGroup: OS_W                                             */
/* SPRHBMA0 Security PolicyGroup: OS_W                                          */
/* SPRC0 Security PolicyGroup: OS_W                                             */
/* SPRMCC Security PolicyGroup: OS_W                                            */
/* SPRD0 Security PolicyGroup: OS_W                                             */
/* SPRHBMB0 Security PolicyGroup: OS_W                                          */
/* SPRLCC Security PolicyGroup: OS_W                                            */
/* EMRXCC Security PolicyGroup: OS_W                                            */
/* SPRE0 Security PolicyGroup: OS_W                                             */
/* BIOS Scratchpad register
*/


#define BIOSNONSTICKYSCRATCHPAD0_UBOX_MISC_REG 0x132200C0

typedef union {
  ///
  /// Individual bit fields
  ///
  struct {
    UINT32 data : 32;

                            /* Bits[31:0], Access Type=RW, default=0x00000000*/

                            /* BIOS Scratchpad register */

  } Bits;
  UINT32 Data;

} BIOSNONSTICKYSCRATCHPAD0_UBOX_MISC_STRUCT;

/* BIOSNONSTICKYSCRATCHPAD1_UBOX_MISC_REG supported on:                         */
/*      SPRA0 (0x21e020c4)                                                      */
/*      SPRB0 (0x21e020c4)                                                      */
/*      SPRHBMA0 (0x21e020c4)                                                   */
/*      SPRC0 (0x21e020c4)                                                      */
/*      SPRMCC (0x21e020c4)                                                     */
/*      SPRD0 (0x21e020c4)                                                      */
/*      SPRHBMB0 (0x21e020c4)                                                   */
/*      SPRLCC (0x21e020c4)                                                     */
/*      EMRXCC (0x21e020c4)                                                     */
/*      SPRE0 (0x21e020c4)                                                      */
/* Register default value on SPRA0: 0x00000000                                  */
/* Register default value on SPRB0: 0x00000000                                  */
/* Register default value on SPRHBMA0: 0x00000000                               */
/* Register default value on SPRC0: 0x00000000                                  */
/* Register default value on SPRMCC: 0x00000000                                 */
/* Register default value on SPRD0: 0x00000000                                  */
/* Register default value on SPRHBMB0: 0x00000000                               */
/* Register default value on SPRLCC: 0x00000000                                 */
/* Register default value on EMRXCC: 0x00000000                                 */
/* Register default value on SPRE0: 0x00000000                                  */
/* SPRA0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2             */
/* SPRB0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2             */
/* SPRHBMA0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2          */
/* SPRC0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2             */
/* SPRMCC Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2            */
/* SPRD0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2             */
/* SPRHBMB0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2          */
/* SPRLCC Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2            */
/* EMRXCC Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2            */
/* SPRE0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2             */
/* Struct generated from SPRA0 BDF: 30_0_2                                      */
/* SPRA0 Security PolicyGroup: OS_W                                             */
/* SPRB0 Security PolicyGroup: OS_W                                             */
/* SPRHBMA0 Security PolicyGroup: OS_W                                          */
/* SPRC0 Security PolicyGroup: OS_W                                             */
/* SPRMCC Security PolicyGroup: OS_W                                            */
/* SPRD0 Security PolicyGroup: OS_W                                             */
/* SPRHBMB0 Security PolicyGroup: OS_W                                          */
/* SPRLCC Security PolicyGroup: OS_W                                            */
/* EMRXCC Security PolicyGroup: OS_W                                            */
/* SPRE0 Security PolicyGroup: OS_W                                             */
/* BIOS Scratchpad register
*/


#define BIOSNONSTICKYSCRATCHPAD1_UBOX_MISC_REG 0x132200C4

typedef union {
  ///
  /// Individual bit fields
  ///
  struct {
    UINT32 data : 32;

                            /* Bits[31:0], Access Type=RW, default=0x00000000*/

                            /* BIOS Scratchpad register */

  } Bits;
  UINT32 Data;

} BIOSNONSTICKYSCRATCHPAD1_UBOX_MISC_STRUCT;

/* BIOSNONSTICKYSCRATCHPAD7_UBOX_MISC_REG supported on:                         */
/*      SPRA0 (0x21e020c8)                                                      */
/*      SPRB0 (0x21e020c8)                                                      */
/*      SPRHBMA0 (0x21e020c8)                                                   */
/*      SPRC0 (0x21e020c8)                                                      */
/*      SPRMCC (0x21e020c8)                                                     */
/*      SPRD0 (0x21e020c8)                                                      */
/*      SPRHBMB0 (0x21e020c8)                                                   */
/*      SPRLCC (0x21e020c8)                                                     */
/*      EMRXCC (0x21e020c8)                                                     */
/*      SPRE0 (0x21e020c8)                                                      */
/* Register default value on SPRA0: 0x00000000                                  */
/* Register default value on SPRB0: 0x00000000                                  */
/* Register default value on SPRHBMA0: 0x00000000                               */
/* Register default value on SPRC0: 0x00000000                                  */
/* Register default value on SPRMCC: 0x00000000                                 */
/* Register default value on SPRD0: 0x00000000                                  */
/* Register default value on SPRHBMB0: 0x00000000                               */
/* Register default value on SPRLCC: 0x00000000                                 */
/* Register default value on EMRXCC: 0x00000000                                 */
/* Register default value on SPRE0: 0x00000000                                  */
/* SPRA0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2             */
/* SPRB0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2             */
/* SPRHBMA0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2          */
/* SPRC0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2             */
/* SPRMCC Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2            */
/* SPRD0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2             */
/* SPRHBMB0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2          */
/* SPRLCC Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2            */
/* EMRXCC Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2            */
/* SPRE0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2             */
/* Struct generated from SPRA0 BDF: 30_0_2                                      */
/* SPRA0 Security PolicyGroup: OS_W                                             */
/* SPRB0 Security PolicyGroup: OS_W                                             */
/* SPRHBMA0 Security PolicyGroup: OS_W                                          */
/* SPRC0 Security PolicyGroup: OS_W                                             */
/* SPRMCC Security PolicyGroup: OS_W                                            */
/* SPRD0 Security PolicyGroup: OS_W                                             */
/* SPRHBMB0 Security PolicyGroup: OS_W                                          */
/* SPRLCC Security PolicyGroup: OS_W                                            */
/* EMRXCC Security PolicyGroup: OS_W                                            */
/* SPRE0 Security PolicyGroup: OS_W                                             */
/* BIOS Scratchpad register
*/


#define BIOSNONSTICKYSCRATCHPAD7_UBOX_MISC_REG 0x132200C8

typedef union {
  ///
  /// Individual bit fields
  ///
  struct {
    UINT32 data : 32;

                            /* Bits[31:0], Access Type=RW, default=0x00000000*/

                            /* BIOS Scratchpad register */

  } Bits;
  UINT32 Data;

} BIOSNONSTICKYSCRATCHPAD7_UBOX_MISC_STRUCT;

/* CPUBUSNO_UBOX_MISC_REG supported on:                                         */
/*      SPRA0 (0x21e020d0)                                                      */
/*      SPRB0 (0x21e020d0)                                                      */
/*      SPRHBMA0 (0x21e020d0)                                                   */
/*      SPRC0 (0x21e020d0)                                                      */
/*      SPRMCC (0x21e020d0)                                                     */
/*      SPRD0 (0x21e020d0)                                                      */
/*      SPRHBMB0 (0x21e020d0)                                                   */
/*      SPRLCC (0x21e020d0)                                                     */
/*      EMRXCC (0x21e020d0)                                                     */
/*      SPRE0 (0x21e020d0)                                                      */
/* Register default value on SPRA0: 0x00000000                                  */
/* Register default value on SPRB0: 0x00000000                                  */
/* Register default value on SPRHBMA0: 0x00000000                               */
/* Register default value on SPRC0: 0x00000000                                  */
/* Register default value on SPRMCC: 0x00000000                                 */
/* Register default value on SPRD0: 0x00000000                                  */
/* Register default value on SPRHBMB0: 0x00000000                               */
/* Register default value on SPRLCC: 0x00000000                                 */
/* Register default value on EMRXCC: 0x00000000                                 */
/* Register default value on SPRE0: 0x00000000                                  */
/* SPRA0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2             */
/* SPRB0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2             */
/* SPRHBMA0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2          */
/* SPRC0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2             */
/* SPRMCC Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2            */
/* SPRD0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2             */
/* SPRHBMB0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2          */
/* SPRLCC Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2            */
/* EMRXCC Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2            */
/* SPRE0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2             */
/* Struct generated from SPRA0 BDF: 30_0_2                                      */
/* SPRA0 Security PolicyGroup: LB_MCHECK_W                                      */
/* SPRB0 Security PolicyGroup: LB_MCHECK_W                                      */
/* SPRHBMA0 Security PolicyGroup: LB_MCHECK_W                                   */
/* SPRC0 Security PolicyGroup: LB_MCHECK_W                                      */
/* SPRMCC Security PolicyGroup: LB_MCHECK_W                                     */
/* SPRD0 Security PolicyGroup: LB_MCHECK_W                                      */
/* SPRHBMB0 Security PolicyGroup: LB_MCHECK_W                                   */
/* SPRLCC Security PolicyGroup: LB_MCHECK_W                                     */
/* EMRXCC Security PolicyGroup: LB_MCHECK_W                                     */
/* SPRE0 Security PolicyGroup: LB_MCHECK_W                                      */
/* Bus Number Configuration
*/


#define CPUBUSNO_UBOX_MISC_REG 0x132200D0

typedef union {
  ///
  /// Individual bit fields
  ///
  struct {
    UINT32 cpubusno0 : 8;

                            /* Bits[7:0], Access Type=RW, default=0x00000000*/

                            /* Uncore Bus A */
    UINT32 cpubusno1 : 8;

                            /* Bits[15:8], Access Type=RW, default=0x00000000*/

                            /* UNcore Bus B */
    UINT32 segment : 8;

                            /* Bits[23:16], Access Type=RW, default=0x00000000*/

                            /* Segment number of Uncore Bus A & B */
    UINT32 rsvd : 8;

                            /* Bits[31:24], Access Type=RO, default=None*/

                            /* Reserved */

  } Bits;
  UINT32 Data;

} CPUBUSNO_UBOX_MISC_STRUCT;

/* CPUBUSNO_VALID_UBOX_MISC_REG supported on:                                   */
/*      SPRA0 (0x21e020d4)                                                      */
/*      SPRB0 (0x21e020d4)                                                      */
/*      SPRHBMA0 (0x21e020d4)                                                   */
/*      SPRC0 (0x21e020d4)                                                      */
/*      SPRMCC (0x21e020d4)                                                     */
/*      SPRD0 (0x21e020d4)                                                      */
/*      SPRHBMB0 (0x21e020d4)                                                   */
/*      SPRLCC (0x21e020d4)                                                     */
/*      EMRXCC (0x21e020d4)                                                     */
/*      SPRE0 (0x21e020d4)                                                      */
/* Register default value on SPRA0: 0x00000000                                  */
/* Register default value on SPRB0: 0x00000000                                  */
/* Register default value on SPRHBMA0: 0x00000000                               */
/* Register default value on SPRC0: 0x00000000                                  */
/* Register default value on SPRMCC: 0x00000000                                 */
/* Register default value on SPRD0: 0x00000000                                  */
/* Register default value on SPRHBMB0: 0x00000000                               */
/* Register default value on SPRLCC: 0x00000000                                 */
/* Register default value on EMRXCC: 0x00000000                                 */
/* Register default value on SPRE0: 0x00000000                                  */
/* SPRA0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2             */
/* SPRB0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2             */
/* SPRHBMA0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2          */
/* SPRC0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2             */
/* SPRMCC Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2            */
/* SPRD0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2             */
/* SPRHBMB0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2          */
/* SPRLCC Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2            */
/* EMRXCC Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2            */
/* SPRE0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2             */
/* Struct generated from SPRA0 BDF: 30_0_2                                      */
/* SPRA0 Security PolicyGroup: LB_MCHECK_W                                      */
/* SPRB0 Security PolicyGroup: LB_MCHECK_W                                      */
/* SPRHBMA0 Security PolicyGroup: LB_MCHECK_W                                   */
/* SPRC0 Security PolicyGroup: LB_MCHECK_W                                      */
/* SPRMCC Security PolicyGroup: LB_MCHECK_W                                     */
/* SPRD0 Security PolicyGroup: LB_MCHECK_W                                      */
/* SPRHBMB0 Security PolicyGroup: LB_MCHECK_W                                   */
/* SPRLCC Security PolicyGroup: LB_MCHECK_W                                     */
/* EMRXCC Security PolicyGroup: LB_MCHECK_W                                     */
/* SPRE0 Security PolicyGroup: LB_MCHECK_W                                      */
/* Bus Number Configuration Valid
*/


#define CPUBUSNO_VALID_UBOX_MISC_REG 0x132200D4

typedef union {
  ///
  /// Individual bit fields
  ///
  struct {
    UINT32 rsvd : 31;

                            /* Bits[30:0], Access Type=RO, default=None*/

                            /* Reserved */
    UINT32 busno_programmed : 1;

                            /* Bits[31:31], Access Type=RW, default=0x00000000*/

                            /*
                               Set by BIOS when the CSR is written with valid
                               bus numbers. or not
                            */

  } Bits;
  UINT32 Data;

} CPUBUSNO_VALID_UBOX_MISC_STRUCT;

/* UBOX_SMICTRL_UBOX_MISC_REG supported on:                                     */
/*      SPRA0 (0x21e020d8)                                                      */
/*      SPRB0 (0x21e020d8)                                                      */
/*      SPRHBMA0 (0x21e020d8)                                                   */
/*      SPRC0 (0x21e020d8)                                                      */
/*      SPRMCC (0x21e020d8)                                                     */
/*      SPRD0 (0x21e020d8)                                                      */
/*      SPRHBMB0 (0x21e020d8)                                                   */
/*      SPRLCC (0x21e020d8)                                                     */
/*      EMRXCC (0x21e020d8)                                                     */
/*      SPRE0 (0x21e020d8)                                                      */
/* Register default value on SPRA0: 0x04000000                                  */
/* Register default value on SPRB0: 0x04000000                                  */
/* Register default value on SPRHBMA0: 0x04000000                               */
/* Register default value on SPRC0: 0x04000000                                  */
/* Register default value on SPRMCC: 0x04000000                                 */
/* Register default value on SPRD0: 0x04000000                                  */
/* Register default value on SPRHBMB0: 0x04000000                               */
/* Register default value on SPRLCC: 0x04000000                                 */
/* Register default value on EMRXCC: 0x04000000                                 */
/* Register default value on SPRE0: 0x04000000                                  */
/* SPRA0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2             */
/* SPRB0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2             */
/* SPRHBMA0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2          */
/* SPRC0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2             */
/* SPRMCC Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2            */
/* SPRD0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2             */
/* SPRHBMB0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2          */
/* SPRLCC Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2            */
/* EMRXCC Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2            */
/* SPRE0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2             */
/* Struct generated from SPRA0 BDF: 30_0_2                                      */
/* SPRA0 Security PolicyGroup: LB_W                                             */
/* SPRB0 Security PolicyGroup: LB_W                                             */
/* SPRHBMA0 Security PolicyGroup: LB_W                                          */
/* SPRC0 Security PolicyGroup: LB_W                                             */
/* SPRMCC Security PolicyGroup: LB_W                                            */
/* SPRD0 Security PolicyGroup: LB_W                                             */
/* SPRHBMB0 Security PolicyGroup: LB_W                                          */
/* SPRLCC Security PolicyGroup: LB_W                                            */
/* EMRXCC Security PolicyGroup: LB_W                                            */
/* SPRE0 Security PolicyGroup: LB_W                                             */
/* SMI generation control
*/


#define UBOX_SMICTRL_UBOX_MISC_REG 0x132200D8

typedef union {
  ///
  /// Individual bit fields
  ///
  struct {
    UINT32 threshold : 20;

                            /* Bits[19:0], Access Type=RW/P, default=0x00000000*/

                            /*
                               This is the countdown that happens in the
                               hardware before an SMI is generated due to a UMC
                            */
    UINT32 rsvd : 4;

                            /* Bits[23:20], Access Type=RO, default=None*/

                            /* Reserved */
    UINT32 umcsmien : 1;

                            /* Bits[24:24], Access Type=RW/P, default=0x00000000*/

                            /*
                               This is the enable bit that enables SMI
                               generation due to a UMC 1 -> Generate SMI after
                               the threshold counter expires. 0 -> Disable
                               generation of SMI
                            */
    UINT32 smidis : 1;

                            /* Bits[25:25], Access Type=RW/P, default=0x00000000*/

                            /* Disable generation of SMI */
    UINT32 smidis2 : 1;

                            /* Bits[26:26], Access Type=RW/P, default=0x00000001*/

                            /*
                               Disable generation of SMI forlocktimeout, cfg
                               write mis-align access, and cfg read mis-aslign
                               access.
                            */
    UINT32 smidis3 : 1;

                            /* Bits[27:27], Access Type=RW/P, default=0x00000000*/

                            /* Disable Generation of SMI from message channel */
    UINT32 smidis4 : 1;

                            /* Bits[28:28], Access Type=RW/P, default=0x00000000*/

                            /* Disable Generation of SMI from CSMI from MsgCh */
    UINT32 upidisable : 1;

                            /* Bits[29:29], Access Type=RW/P, default=0x00000000*/

                            /* If set, only local SMIs will be logged */
    UINT32 rsvd_30 : 2;

                            /* Bits[31:30], Access Type=RO, default=None*/

                            /* Reserved */

  } Bits;
  UINT32 Data;

} UBOX_SMICTRL_UBOX_MISC_STRUCT;

/* ABORTDEBUG1_UBOX_MISC_REG supported on:                                      */
/*      SPRA0 (0x21e020e0)                                                      */
/*      SPRB0 (0x21e020e0)                                                      */
/*      SPRHBMA0 (0x21e020e0)                                                   */
/*      SPRC0 (0x21e020e0)                                                      */
/*      SPRMCC (0x21e020e0)                                                     */
/*      SPRD0 (0x21e020e0)                                                      */
/*      SPRHBMB0 (0x21e020e0)                                                   */
/*      SPRLCC (0x21e020e0)                                                     */
/*      EMRXCC (0x21e020e0)                                                     */
/*      SPRE0 (0x21e020e0)                                                      */
/* Register default value on SPRA0: 0xFFFFFFFF                                  */
/* Register default value on SPRB0: 0xFFFFFFFF                                  */
/* Register default value on SPRHBMA0: 0xFFFFFFFF                               */
/* Register default value on SPRC0: 0xFFFFFFFF                                  */
/* Register default value on SPRMCC: 0xFFFFFFFF                                 */
/* Register default value on SPRD0: 0xFFFFFFFF                                  */
/* Register default value on SPRHBMB0: 0xFFFFFFFF                               */
/* Register default value on SPRLCC: 0xFFFFFFFF                                 */
/* Register default value on EMRXCC: 0xFFFFFFFF                                 */
/* Register default value on SPRE0: 0xFFFFFFFF                                  */
/* SPRA0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2             */
/* SPRB0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2             */
/* SPRHBMA0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2          */
/* SPRC0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2             */
/* SPRMCC Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2            */
/* SPRD0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2             */
/* SPRHBMB0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2          */
/* SPRLCC Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2            */
/* EMRXCC Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2            */
/* SPRE0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2             */
/* Struct generated from SPRA0 BDF: 30_0_2                                      */
/* SPRA0 Security PolicyGroup: OS_W                                             */
/* SPRB0 Security PolicyGroup: OS_W                                             */
/* SPRHBMA0 Security PolicyGroup: OS_W                                          */
/* SPRC0 Security PolicyGroup: OS_W                                             */
/* SPRMCC Security PolicyGroup: OS_W                                            */
/* SPRD0 Security PolicyGroup: OS_W                                             */
/* SPRHBMB0 Security PolicyGroup: OS_W                                          */
/* SPRLCC Security PolicyGroup: OS_W                                            */
/* EMRXCC Security PolicyGroup: OS_W                                            */
/* SPRE0 Security PolicyGroup: OS_W                                             */
/* Abort debug for aborting accesses
*/


#define ABORTDEBUG1_UBOX_MISC_REG 0x132200E0

typedef union {
  ///
  /// Individual bit fields
  ///
  struct {
    UINT32 data : 32;

                            /* Bits[31:0], Access Type=RO, default=0xFFFFFFFF*/

                            /* Default value for reads. Writes will be dropped. */

  } Bits;
  UINT32 Data;

} ABORTDEBUG1_UBOX_MISC_STRUCT;

/* ABORTDEBUG2_UBOX_MISC_REG supported on:                                      */
/*      SPRA0 (0x21e020e4)                                                      */
/*      SPRB0 (0x21e020e4)                                                      */
/*      SPRHBMA0 (0x21e020e4)                                                   */
/*      SPRC0 (0x21e020e4)                                                      */
/*      SPRMCC (0x21e020e4)                                                     */
/*      SPRD0 (0x21e020e4)                                                      */
/*      SPRHBMB0 (0x21e020e4)                                                   */
/*      SPRLCC (0x21e020e4)                                                     */
/*      EMRXCC (0x21e020e4)                                                     */
/*      SPRE0 (0x21e020e4)                                                      */
/* Register default value on SPRA0: 0xFFFFFFFF                                  */
/* Register default value on SPRB0: 0xFFFFFFFF                                  */
/* Register default value on SPRHBMA0: 0xFFFFFFFF                               */
/* Register default value on SPRC0: 0xFFFFFFFF                                  */
/* Register default value on SPRMCC: 0xFFFFFFFF                                 */
/* Register default value on SPRD0: 0xFFFFFFFF                                  */
/* Register default value on SPRHBMB0: 0xFFFFFFFF                               */
/* Register default value on SPRLCC: 0xFFFFFFFF                                 */
/* Register default value on EMRXCC: 0xFFFFFFFF                                 */
/* Register default value on SPRE0: 0xFFFFFFFF                                  */
/* SPRA0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2             */
/* SPRB0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2             */
/* SPRHBMA0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2          */
/* SPRC0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2             */
/* SPRMCC Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2            */
/* SPRD0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2             */
/* SPRHBMB0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2          */
/* SPRLCC Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2            */
/* EMRXCC Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2            */
/* SPRE0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2             */
/* Struct generated from SPRA0 BDF: 30_0_2                                      */
/* SPRA0 Security PolicyGroup: OS_W                                             */
/* SPRB0 Security PolicyGroup: OS_W                                             */
/* SPRHBMA0 Security PolicyGroup: OS_W                                          */
/* SPRC0 Security PolicyGroup: OS_W                                             */
/* SPRMCC Security PolicyGroup: OS_W                                            */
/* SPRD0 Security PolicyGroup: OS_W                                             */
/* SPRHBMB0 Security PolicyGroup: OS_W                                          */
/* SPRLCC Security PolicyGroup: OS_W                                            */
/* EMRXCC Security PolicyGroup: OS_W                                            */
/* SPRE0 Security PolicyGroup: OS_W                                             */
/* Abort debug for aborting accesses 
*/


#define ABORTDEBUG2_UBOX_MISC_REG 0x132200E4

typedef union {
  ///
  /// Individual bit fields
  ///
  struct {
    UINT32 data : 32;

                            /* Bits[31:0], Access Type=RO, default=0xFFFFFFFF*/

                            /* Default value for reads. Writes will be dropped. */

  } Bits;
  UINT32 Data;

} ABORTDEBUG2_UBOX_MISC_STRUCT;

/* BIOSNONSTICKYSCRATCHPAD3_UBOX_MISC_REG supported on:                         */
/*      SPRA0 (0x21e020e8)                                                      */
/*      SPRB0 (0x21e020e8)                                                      */
/*      SPRHBMA0 (0x21e020e8)                                                   */
/*      SPRC0 (0x21e020e8)                                                      */
/*      SPRMCC (0x21e020e8)                                                     */
/*      SPRD0 (0x21e020e8)                                                      */
/*      SPRHBMB0 (0x21e020e8)                                                   */
/*      SPRLCC (0x21e020e8)                                                     */
/*      EMRXCC (0x21e020e8)                                                     */
/*      SPRE0 (0x21e020e8)                                                      */
/* Register default value on SPRA0: 0x00000000                                  */
/* Register default value on SPRB0: 0x00000000                                  */
/* Register default value on SPRHBMA0: 0x00000000                               */
/* Register default value on SPRC0: 0x00000000                                  */
/* Register default value on SPRMCC: 0x00000000                                 */
/* Register default value on SPRD0: 0x00000000                                  */
/* Register default value on SPRHBMB0: 0x00000000                               */
/* Register default value on SPRLCC: 0x00000000                                 */
/* Register default value on EMRXCC: 0x00000000                                 */
/* Register default value on SPRE0: 0x00000000                                  */
/* SPRA0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2             */
/* SPRB0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2             */
/* SPRHBMA0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2          */
/* SPRC0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2             */
/* SPRMCC Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2            */
/* SPRD0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2             */
/* SPRHBMB0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2          */
/* SPRLCC Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2            */
/* EMRXCC Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2            */
/* SPRE0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2             */
/* Struct generated from SPRA0 BDF: 30_0_2                                      */
/* SPRA0 Security PolicyGroup: OS_W                                             */
/* SPRB0 Security PolicyGroup: OS_W                                             */
/* SPRHBMA0 Security PolicyGroup: OS_W                                          */
/* SPRC0 Security PolicyGroup: OS_W                                             */
/* SPRMCC Security PolicyGroup: OS_W                                            */
/* SPRD0 Security PolicyGroup: OS_W                                             */
/* SPRHBMB0 Security PolicyGroup: OS_W                                          */
/* SPRLCC Security PolicyGroup: OS_W                                            */
/* EMRXCC Security PolicyGroup: OS_W                                            */
/* SPRE0 Security PolicyGroup: OS_W                                             */
/* BIOS Scratchpad register
*/


#define BIOSNONSTICKYSCRATCHPAD3_UBOX_MISC_REG 0x132200E8

typedef union {
  ///
  /// Individual bit fields
  ///
  struct {
    UINT32 data : 32;

                            /* Bits[31:0], Access Type=RW, default=0x00000000*/

                            /* BIOS Scratchpad register */

  } Bits;
  UINT32 Data;

} BIOSNONSTICKYSCRATCHPAD3_UBOX_MISC_STRUCT;

/* BIOSNONSTICKYSCRATCHPAD4_UBOX_MISC_REG supported on:                         */
/*      SPRA0 (0x21e020ec)                                                      */
/*      SPRB0 (0x21e020ec)                                                      */
/*      SPRHBMA0 (0x21e020ec)                                                   */
/*      SPRC0 (0x21e020ec)                                                      */
/*      SPRMCC (0x21e020ec)                                                     */
/*      SPRD0 (0x21e020ec)                                                      */
/*      SPRHBMB0 (0x21e020ec)                                                   */
/*      SPRLCC (0x21e020ec)                                                     */
/*      EMRXCC (0x21e020ec)                                                     */
/*      SPRE0 (0x21e020ec)                                                      */
/* Register default value on SPRA0: 0x00000000                                  */
/* Register default value on SPRB0: 0x00000000                                  */
/* Register default value on SPRHBMA0: 0x00000000                               */
/* Register default value on SPRC0: 0x00000000                                  */
/* Register default value on SPRMCC: 0x00000000                                 */
/* Register default value on SPRD0: 0x00000000                                  */
/* Register default value on SPRHBMB0: 0x00000000                               */
/* Register default value on SPRLCC: 0x00000000                                 */
/* Register default value on EMRXCC: 0x00000000                                 */
/* Register default value on SPRE0: 0x00000000                                  */
/* SPRA0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2             */
/* SPRB0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2             */
/* SPRHBMA0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2          */
/* SPRC0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2             */
/* SPRMCC Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2            */
/* SPRD0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2             */
/* SPRHBMB0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2          */
/* SPRLCC Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2            */
/* EMRXCC Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2            */
/* SPRE0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2             */
/* Struct generated from SPRA0 BDF: 30_0_2                                      */
/* SPRA0 Security PolicyGroup: OS_W                                             */
/* SPRB0 Security PolicyGroup: OS_W                                             */
/* SPRHBMA0 Security PolicyGroup: OS_W                                          */
/* SPRC0 Security PolicyGroup: OS_W                                             */
/* SPRMCC Security PolicyGroup: OS_W                                            */
/* SPRD0 Security PolicyGroup: OS_W                                             */
/* SPRHBMB0 Security PolicyGroup: OS_W                                          */
/* SPRLCC Security PolicyGroup: OS_W                                            */
/* EMRXCC Security PolicyGroup: OS_W                                            */
/* SPRE0 Security PolicyGroup: OS_W                                             */
/* BIOS Scratchpad register
*/


#define BIOSNONSTICKYSCRATCHPAD4_UBOX_MISC_REG 0x132200EC

typedef union {
  ///
  /// Individual bit fields
  ///
  struct {
    UINT32 data : 32;

                            /* Bits[31:0], Access Type=RW, default=0x00000000*/

                            /* BIOS Scratchpad register */

  } Bits;
  UINT32 Data;

} BIOSNONSTICKYSCRATCHPAD4_UBOX_MISC_STRUCT;

/* BIOSNONSTICKYSCRATCHPAD6_UBOX_MISC_REG supported on:                         */
/*      SPRA0 (0x21e020f0)                                                      */
/*      SPRB0 (0x21e020f0)                                                      */
/*      SPRHBMA0 (0x21e020f0)                                                   */
/*      SPRC0 (0x21e020f0)                                                      */
/*      SPRMCC (0x21e020f0)                                                     */
/*      SPRD0 (0x21e020f0)                                                      */
/*      SPRHBMB0 (0x21e020f0)                                                   */
/*      SPRLCC (0x21e020f0)                                                     */
/*      EMRXCC (0x21e020f0)                                                     */
/*      SPRE0 (0x21e020f0)                                                      */
/* Register default value on SPRA0: 0x00000000                                  */
/* Register default value on SPRB0: 0x00000000                                  */
/* Register default value on SPRHBMA0: 0x00000000                               */
/* Register default value on SPRC0: 0x00000000                                  */
/* Register default value on SPRMCC: 0x00000000                                 */
/* Register default value on SPRD0: 0x00000000                                  */
/* Register default value on SPRHBMB0: 0x00000000                               */
/* Register default value on SPRLCC: 0x00000000                                 */
/* Register default value on EMRXCC: 0x00000000                                 */
/* Register default value on SPRE0: 0x00000000                                  */
/* SPRA0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2             */
/* SPRB0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2             */
/* SPRHBMA0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2          */
/* SPRC0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2             */
/* SPRMCC Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2            */
/* SPRD0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2             */
/* SPRHBMB0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2          */
/* SPRLCC Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2            */
/* EMRXCC Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2            */
/* SPRE0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2             */
/* Struct generated from SPRA0 BDF: 30_0_2                                      */
/* SPRA0 Security PolicyGroup: OS_W                                             */
/* SPRB0 Security PolicyGroup: OS_W                                             */
/* SPRHBMA0 Security PolicyGroup: OS_W                                          */
/* SPRC0 Security PolicyGroup: OS_W                                             */
/* SPRMCC Security PolicyGroup: OS_W                                            */
/* SPRD0 Security PolicyGroup: OS_W                                             */
/* SPRHBMB0 Security PolicyGroup: OS_W                                          */
/* SPRLCC Security PolicyGroup: OS_W                                            */
/* EMRXCC Security PolicyGroup: OS_W                                            */
/* SPRE0 Security PolicyGroup: OS_W                                             */
/* BIOS Scratchpad register
*/


#define BIOSNONSTICKYSCRATCHPAD6_UBOX_MISC_REG 0x132200F0

typedef union {
  ///
  /// Individual bit fields
  ///
  struct {
    UINT32 data : 32;

                            /* Bits[31:0], Access Type=RW, default=0x00000000*/

                            /* BIOS Scratchpad register */

  } Bits;
  UINT32 Data;

} BIOSNONSTICKYSCRATCHPAD6_UBOX_MISC_STRUCT;

/* BIOSNONSTICKYSCRATCHPAD5_UBOX_MISC_REG supported on:                         */
/*      SPRA0 (0x21e020f4)                                                      */
/*      SPRB0 (0x21e020f4)                                                      */
/*      SPRHBMA0 (0x21e020f4)                                                   */
/*      SPRC0 (0x21e020f4)                                                      */
/*      SPRMCC (0x21e020f4)                                                     */
/*      SPRD0 (0x21e020f4)                                                      */
/*      SPRHBMB0 (0x21e020f4)                                                   */
/*      SPRLCC (0x21e020f4)                                                     */
/*      EMRXCC (0x21e020f4)                                                     */
/*      SPRE0 (0x21e020f4)                                                      */
/* Register default value on SPRA0: 0x00000000                                  */
/* Register default value on SPRB0: 0x00000000                                  */
/* Register default value on SPRHBMA0: 0x00000000                               */
/* Register default value on SPRC0: 0x00000000                                  */
/* Register default value on SPRMCC: 0x00000000                                 */
/* Register default value on SPRD0: 0x00000000                                  */
/* Register default value on SPRHBMB0: 0x00000000                               */
/* Register default value on SPRLCC: 0x00000000                                 */
/* Register default value on EMRXCC: 0x00000000                                 */
/* Register default value on SPRE0: 0x00000000                                  */
/* SPRA0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2             */
/* SPRB0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2             */
/* SPRHBMA0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2          */
/* SPRC0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2             */
/* SPRMCC Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2            */
/* SPRD0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2             */
/* SPRHBMB0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2          */
/* SPRLCC Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2            */
/* EMRXCC Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2            */
/* SPRE0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2             */
/* Struct generated from SPRA0 BDF: 30_0_2                                      */
/* SPRA0 Security PolicyGroup: OS_W                                             */
/* SPRB0 Security PolicyGroup: OS_W                                             */
/* SPRHBMA0 Security PolicyGroup: OS_W                                          */
/* SPRC0 Security PolicyGroup: OS_W                                             */
/* SPRMCC Security PolicyGroup: OS_W                                            */
/* SPRD0 Security PolicyGroup: OS_W                                             */
/* SPRHBMB0 Security PolicyGroup: OS_W                                          */
/* SPRLCC Security PolicyGroup: OS_W                                            */
/* EMRXCC Security PolicyGroup: OS_W                                            */
/* SPRE0 Security PolicyGroup: OS_W                                             */
/* BIOS Scratchpad register
*/


#define BIOSNONSTICKYSCRATCHPAD5_UBOX_MISC_REG 0x132200F4

typedef union {
  ///
  /// Individual bit fields
  ///
  struct {
    UINT32 data : 32;

                            /* Bits[31:0], Access Type=RW, default=0x00000000*/

                            /* BIOS Scratchpad register */

  } Bits;
  UINT32 Data;

} BIOSNONSTICKYSCRATCHPAD5_UBOX_MISC_STRUCT;

/* BIOSNONSTICKYSCRATCHPAD2_UBOX_MISC_REG supported on:                         */
/*      SPRA0 (0x21e020fc)                                                      */
/*      SPRB0 (0x21e020fc)                                                      */
/*      SPRHBMA0 (0x21e020fc)                                                   */
/*      SPRC0 (0x21e020fc)                                                      */
/*      SPRMCC (0x21e020fc)                                                     */
/*      SPRD0 (0x21e020fc)                                                      */
/*      SPRHBMB0 (0x21e020fc)                                                   */
/*      SPRLCC (0x21e020fc)                                                     */
/*      EMRXCC (0x21e020fc)                                                     */
/*      SPRE0 (0x21e020fc)                                                      */
/* Register default value on SPRA0: 0x00000000                                  */
/* Register default value on SPRB0: 0x00000000                                  */
/* Register default value on SPRHBMA0: 0x00000000                               */
/* Register default value on SPRC0: 0x00000000                                  */
/* Register default value on SPRMCC: 0x00000000                                 */
/* Register default value on SPRD0: 0x00000000                                  */
/* Register default value on SPRHBMB0: 0x00000000                               */
/* Register default value on SPRLCC: 0x00000000                                 */
/* Register default value on EMRXCC: 0x00000000                                 */
/* Register default value on SPRE0: 0x00000000                                  */
/* SPRA0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2             */
/* SPRB0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2             */
/* SPRHBMA0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2          */
/* SPRC0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2             */
/* SPRMCC Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2            */
/* SPRD0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2             */
/* SPRHBMB0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2          */
/* SPRLCC Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2            */
/* EMRXCC Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2            */
/* SPRE0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2             */
/* Struct generated from SPRA0 BDF: 30_0_2                                      */
/* SPRA0 Security PolicyGroup: OS_W                                             */
/* SPRB0 Security PolicyGroup: OS_W                                             */
/* SPRHBMA0 Security PolicyGroup: OS_W                                          */
/* SPRC0 Security PolicyGroup: OS_W                                             */
/* SPRMCC Security PolicyGroup: OS_W                                            */
/* SPRD0 Security PolicyGroup: OS_W                                             */
/* SPRHBMB0 Security PolicyGroup: OS_W                                          */
/* SPRLCC Security PolicyGroup: OS_W                                            */
/* EMRXCC Security PolicyGroup: OS_W                                            */
/* SPRE0 Security PolicyGroup: OS_W                                             */
/* BIOS Scratchpad register
*/


#define BIOSNONSTICKYSCRATCHPAD2_UBOX_MISC_REG 0x132200FC

typedef union {
  ///
  /// Individual bit fields
  ///
  struct {
    UINT32 data : 32;

                            /* Bits[31:0], Access Type=RW, default=0x00000000*/

                            /* BIOS Scratchpad register */

  } Bits;
  UINT32 Data;

} BIOSNONSTICKYSCRATCHPAD2_UBOX_MISC_STRUCT;

/* PXPENHCAP_0_0_2_UBOX_MISC_REG supported on:                                  */
/*      SPRA0 (0x21e02100)                                                      */
/*      SPRB0 (0x21e02100)                                                      */
/*      SPRHBMA0 (0x21e02100)                                                   */
/*      SPRC0 (0x21e02100)                                                      */
/*      SPRMCC (0x21e02100)                                                     */
/*      SPRD0 (0x21e02100)                                                      */
/*      SPRHBMB0 (0x21e02100)                                                   */
/*      SPRLCC (0x21e02100)                                                     */
/*      EMRXCC (0x21e02100)                                                     */
/*      SPRE0 (0x21e02100)                                                      */
/* Register default value on SPRA0: 0x00000000                                  */
/* Register default value on SPRB0: 0x00000000                                  */
/* Register default value on SPRHBMA0: 0x00000000                               */
/* Register default value on SPRC0: 0x00000000                                  */
/* Register default value on SPRMCC: 0x00000000                                 */
/* Register default value on SPRD0: 0x00000000                                  */
/* Register default value on SPRHBMB0: 0x00000000                               */
/* Register default value on SPRLCC: 0x00000000                                 */
/* Register default value on EMRXCC: 0x00000000                                 */
/* Register default value on SPRE0: 0x00000000                                  */
/* SPRA0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_PCIE_RIDCCR_0_0_2   */
/* SPRB0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_PCIE_RIDCCR_0_0_2   */
/* SPRHBMA0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_PCIE_RIDCCR_0_0_2*/
/* SPRC0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_PCIE_RIDCCR_0_0_2   */
/* SPRMCC Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_PCIE_RIDCCR_0_0_2  */
/* SPRD0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_PCIE_RIDCCR_0_0_2   */
/* SPRHBMB0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_PCIE_RIDCCR_0_0_2*/
/* SPRLCC Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_PCIE_RIDCCR_0_0_2  */
/* EMRXCC Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_PCIE_RIDCCR_0_0_2  */
/* SPRE0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_PCIE_RIDCCR_0_0_2   */
/* Struct generated from SPRA0 BDF: 30_0_2                                      */
/* SPRA0 Security PolicyGroup: OS_W                                             */
/* SPRB0 Security PolicyGroup: OS_W                                             */
/* SPRHBMA0 Security PolicyGroup: OS_W                                          */
/* SPRC0 Security PolicyGroup: OS_W                                             */
/* SPRMCC Security PolicyGroup: OS_W                                            */
/* SPRD0 Security PolicyGroup: OS_W                                             */
/* SPRHBMB0 Security PolicyGroup: OS_W                                          */
/* SPRLCC Security PolicyGroup: OS_W                                            */
/* EMRXCC Security PolicyGroup: OS_W                                            */
/* SPRE0 Security PolicyGroup: OS_W                                             */
/* PCI Express Enhanced Capability
*/


#define PXPENHCAP_0_0_2_UBOX_MISC_REG 0x13220100

typedef union {
  ///
  /// Individual bit fields
  ///
  struct {
    UINT32 capability_id : 16;

                            /* Bits[15:0], Access Type=RO, default=0x00000000*/

                            /* There is no capability at this location */
    UINT32 capability_version : 4;

                            /* Bits[19:16], Access Type=RO, default=0x00000000*/

                            /* There is no capability at this location. */
    UINT32 next_capability_offset : 12;

                            /* Bits[31:20], Access Type=RO, default=0x00000000*/

                            /*
                               Pointer to the next capability in the enhanced
                               configuration space. Set to 0 to indicate there
                               are no more capability structures.
                            */

  } Bits;
  UINT32 Data;

} PXPENHCAP_0_0_2_UBOX_MISC_STRUCT;

/* DEVHIDE1_UBOX_MISC_REG supported on:                                         */
/*      SPRA0 (0x21e02108)                                                      */
/*      SPRB0 (0x21e02108)                                                      */
/*      SPRHBMA0 (0x21e02108)                                                   */
/*      SPRC0 (0x21e02108)                                                      */
/*      SPRMCC (0x21e02108)                                                     */
/*      SPRD0 (0x21e02108)                                                      */
/*      SPRHBMB0 (0x21e02108)                                                   */
/*      SPRLCC (0x21e02108)                                                     */
/*      EMRXCC (0x21e02108)                                                     */
/*      SPRE0 (0x21e02108)                                                      */
/* Register default value on SPRA0: 0x00000000                                  */
/* Register default value on SPRB0: 0x00000000                                  */
/* Register default value on SPRHBMA0: 0x00000000                               */
/* Register default value on SPRC0: 0x00000000                                  */
/* Register default value on SPRMCC: 0x00000000                                 */
/* Register default value on SPRD0: 0x00000000                                  */
/* Register default value on SPRHBMB0: 0x00000000                               */
/* Register default value on SPRLCC: 0x00000000                                 */
/* Register default value on EMRXCC: 0x00000000                                 */
/* Register default value on SPRE0: 0x00000000                                  */
/* SPRA0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2             */
/* SPRB0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2             */
/* SPRHBMA0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2          */
/* SPRC0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2             */
/* SPRMCC Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2            */
/* SPRD0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2             */
/* SPRHBMB0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2          */
/* SPRLCC Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2            */
/* EMRXCC Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2            */
/* SPRE0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2             */
/* Struct generated from SPRA0 BDF: 30_0_2                                      */
/* SPRA0 Security PolicyGroup: LB_W                                             */
/* SPRB0 Security PolicyGroup: LB_W                                             */
/* SPRHBMA0 Security PolicyGroup: LB_W                                          */
/* SPRC0 Security PolicyGroup: LB_W                                             */
/* SPRMCC Security PolicyGroup: LB_W                                            */
/* SPRD0 Security PolicyGroup: LB_W                                             */
/* SPRHBMB0 Security PolicyGroup: LB_W                                          */
/* SPRLCC Security PolicyGroup: LB_W                                            */
/* EMRXCC Security PolicyGroup: LB_W                                            */
/* SPRE0 Security PolicyGroup: LB_W                                             */
/* Device Hide Register in CSR space for Bus 0
*/


#define DEVHIDE1_UBOX_MISC_REG 0x13220108

typedef union {
  ///
  /// Individual bit fields
  ///
  struct {
    UINT32 disfn : 32;

                            /* Bits[31:0], Access Type=RW, default=0x00000000*/

                            /*
                               Disable Function(DisFn): A bit set in this
                               register implies that the appropriate device
                               function is not enabled. For instance, if bit 5
                               is set in DEVHIDEuCodeCtrl4, then it means that
                               in device 5, function 4 is disabled.
                            */

  } Bits;
  UINT32 Data;

} DEVHIDE1_UBOX_MISC_STRUCT;

/* DEVHIDE2_UBOX_MISC_REG supported on:                                         */
/*      SPRA0 (0x21e0210c)                                                      */
/*      SPRB0 (0x21e0210c)                                                      */
/*      SPRHBMA0 (0x21e0210c)                                                   */
/*      SPRC0 (0x21e0210c)                                                      */
/*      SPRMCC (0x21e0210c)                                                     */
/*      SPRD0 (0x21e0210c)                                                      */
/*      SPRHBMB0 (0x21e0210c)                                                   */
/*      SPRLCC (0x21e0210c)                                                     */
/*      EMRXCC (0x21e0210c)                                                     */
/*      SPRE0 (0x21e0210c)                                                      */
/* Register default value on SPRA0: 0x00000000                                  */
/* Register default value on SPRB0: 0x00000000                                  */
/* Register default value on SPRHBMA0: 0x00000000                               */
/* Register default value on SPRC0: 0x00000000                                  */
/* Register default value on SPRMCC: 0x00000000                                 */
/* Register default value on SPRD0: 0x00000000                                  */
/* Register default value on SPRHBMB0: 0x00000000                               */
/* Register default value on SPRLCC: 0x00000000                                 */
/* Register default value on EMRXCC: 0x00000000                                 */
/* Register default value on SPRE0: 0x00000000                                  */
/* SPRA0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2             */
/* SPRB0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2             */
/* SPRHBMA0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2          */
/* SPRC0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2             */
/* SPRMCC Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2            */
/* SPRD0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2             */
/* SPRHBMB0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2          */
/* SPRLCC Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2            */
/* EMRXCC Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2            */
/* SPRE0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2             */
/* Struct generated from SPRA0 BDF: 30_0_2                                      */
/* SPRA0 Security PolicyGroup: LB_W                                             */
/* SPRB0 Security PolicyGroup: LB_W                                             */
/* SPRHBMA0 Security PolicyGroup: LB_W                                          */
/* SPRC0 Security PolicyGroup: LB_W                                             */
/* SPRMCC Security PolicyGroup: LB_W                                            */
/* SPRD0 Security PolicyGroup: LB_W                                             */
/* SPRHBMB0 Security PolicyGroup: LB_W                                          */
/* SPRLCC Security PolicyGroup: LB_W                                            */
/* EMRXCC Security PolicyGroup: LB_W                                            */
/* SPRE0 Security PolicyGroup: LB_W                                             */
/* Device Hide Register in CSR space for Bus 0
*/


#define DEVHIDE2_UBOX_MISC_REG 0x1322010C

typedef union {
  ///
  /// Individual bit fields
  ///
  struct {
    UINT32 disfn : 32;

                            /* Bits[31:0], Access Type=RW, default=0x00000000*/

                            /*
                               Disable Function(DisFn): A bit set in this
                               register implies that the appropriate device
                               function is not enabled. For instance, if bit 5
                               is set in DEVHIDEuCodeCtrl4, then it means that
                               in device 5, function 4 is disabled.
                            */

  } Bits;
  UINT32 Data;

} DEVHIDE2_UBOX_MISC_STRUCT;

/* DEVHIDE3_UBOX_MISC_REG supported on:                                         */
/*      SPRA0 (0x21e02110)                                                      */
/*      SPRB0 (0x21e02110)                                                      */
/*      SPRHBMA0 (0x21e02110)                                                   */
/*      SPRC0 (0x21e02110)                                                      */
/*      SPRMCC (0x21e02110)                                                     */
/*      SPRD0 (0x21e02110)                                                      */
/*      SPRHBMB0 (0x21e02110)                                                   */
/*      SPRLCC (0x21e02110)                                                     */
/*      EMRXCC (0x21e02110)                                                     */
/*      SPRE0 (0x21e02110)                                                      */
/* Register default value on SPRA0: 0x00000000                                  */
/* Register default value on SPRB0: 0x00000000                                  */
/* Register default value on SPRHBMA0: 0x00000000                               */
/* Register default value on SPRC0: 0x00000000                                  */
/* Register default value on SPRMCC: 0x00000000                                 */
/* Register default value on SPRD0: 0x00000000                                  */
/* Register default value on SPRHBMB0: 0x00000000                               */
/* Register default value on SPRLCC: 0x00000000                                 */
/* Register default value on EMRXCC: 0x00000000                                 */
/* Register default value on SPRE0: 0x00000000                                  */
/* SPRA0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2             */
/* SPRB0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2             */
/* SPRHBMA0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2          */
/* SPRC0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2             */
/* SPRMCC Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2            */
/* SPRD0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2             */
/* SPRHBMB0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2          */
/* SPRLCC Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2            */
/* EMRXCC Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2            */
/* SPRE0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2             */
/* Struct generated from SPRA0 BDF: 30_0_2                                      */
/* SPRA0 Security PolicyGroup: LB_W                                             */
/* SPRB0 Security PolicyGroup: LB_W                                             */
/* SPRHBMA0 Security PolicyGroup: LB_W                                          */
/* SPRC0 Security PolicyGroup: LB_W                                             */
/* SPRMCC Security PolicyGroup: LB_W                                            */
/* SPRD0 Security PolicyGroup: LB_W                                             */
/* SPRHBMB0 Security PolicyGroup: LB_W                                          */
/* SPRLCC Security PolicyGroup: LB_W                                            */
/* EMRXCC Security PolicyGroup: LB_W                                            */
/* SPRE0 Security PolicyGroup: LB_W                                             */
/* Device Hide Register in CSR space for Bus 0
*/


#define DEVHIDE3_UBOX_MISC_REG 0x13220110

typedef union {
  ///
  /// Individual bit fields
  ///
  struct {
    UINT32 disfn : 32;

                            /* Bits[31:0], Access Type=RW, default=0x00000000*/

                            /*
                               Disable Function(DisFn): A bit set in this
                               register implies that the appropriate device
                               function is not enabled. For instance, if bit 5
                               is set in DEVHIDEuCodeCtrl4, then it means that
                               in device 5, function 4 is disabled.
                            */

  } Bits;
  UINT32 Data;

} DEVHIDE3_UBOX_MISC_STRUCT;

/* DEVHIDE4_UBOX_MISC_REG supported on:                                         */
/*      SPRA0 (0x21e02114)                                                      */
/*      SPRB0 (0x21e02114)                                                      */
/*      SPRHBMA0 (0x21e02114)                                                   */
/*      SPRC0 (0x21e02114)                                                      */
/*      SPRMCC (0x21e02114)                                                     */
/*      SPRD0 (0x21e02114)                                                      */
/*      SPRHBMB0 (0x21e02114)                                                   */
/*      SPRLCC (0x21e02114)                                                     */
/*      EMRXCC (0x21e02114)                                                     */
/*      SPRE0 (0x21e02114)                                                      */
/* Register default value on SPRA0: 0x00000000                                  */
/* Register default value on SPRB0: 0x00000000                                  */
/* Register default value on SPRHBMA0: 0x00000000                               */
/* Register default value on SPRC0: 0x00000000                                  */
/* Register default value on SPRMCC: 0x00000000                                 */
/* Register default value on SPRD0: 0x00000000                                  */
/* Register default value on SPRHBMB0: 0x00000000                               */
/* Register default value on SPRLCC: 0x00000000                                 */
/* Register default value on EMRXCC: 0x00000000                                 */
/* Register default value on SPRE0: 0x00000000                                  */
/* SPRA0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2             */
/* SPRB0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2             */
/* SPRHBMA0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2          */
/* SPRC0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2             */
/* SPRMCC Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2            */
/* SPRD0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2             */
/* SPRHBMB0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2          */
/* SPRLCC Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2            */
/* EMRXCC Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2            */
/* SPRE0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2             */
/* Struct generated from SPRA0 BDF: 30_0_2                                      */
/* SPRA0 Security PolicyGroup: LB_W                                             */
/* SPRB0 Security PolicyGroup: LB_W                                             */
/* SPRHBMA0 Security PolicyGroup: LB_W                                          */
/* SPRC0 Security PolicyGroup: LB_W                                             */
/* SPRMCC Security PolicyGroup: LB_W                                            */
/* SPRD0 Security PolicyGroup: LB_W                                             */
/* SPRHBMB0 Security PolicyGroup: LB_W                                          */
/* SPRLCC Security PolicyGroup: LB_W                                            */
/* EMRXCC Security PolicyGroup: LB_W                                            */
/* SPRE0 Security PolicyGroup: LB_W                                             */
/* Device Hide Register in CSR space for Bus 0
*/


#define DEVHIDE4_UBOX_MISC_REG 0x13220114

typedef union {
  ///
  /// Individual bit fields
  ///
  struct {
    UINT32 disfn : 32;

                            /* Bits[31:0], Access Type=RW, default=0x00000000*/

                            /*
                               Disable Function(DisFn): A bit set in this
                               register implies that the appropriate device
                               function is not enabled. For instance, if bit 5
                               is set in DEVHIDEuCodeCtrl4, then it means that
                               in device 5, function 4 is disabled.
                            */

  } Bits;
  UINT32 Data;

} DEVHIDE4_UBOX_MISC_STRUCT;

/* DEVHIDE5_UBOX_MISC_REG supported on:                                         */
/*      SPRA0 (0x21e02118)                                                      */
/*      SPRB0 (0x21e02118)                                                      */
/*      SPRHBMA0 (0x21e02118)                                                   */
/*      SPRC0 (0x21e02118)                                                      */
/*      SPRMCC (0x21e02118)                                                     */
/*      SPRD0 (0x21e02118)                                                      */
/*      SPRHBMB0 (0x21e02118)                                                   */
/*      SPRLCC (0x21e02118)                                                     */
/*      EMRXCC (0x21e02118)                                                     */
/*      SPRE0 (0x21e02118)                                                      */
/* Register default value on SPRA0: 0x00000000                                  */
/* Register default value on SPRB0: 0x00000000                                  */
/* Register default value on SPRHBMA0: 0x00000000                               */
/* Register default value on SPRC0: 0x00000000                                  */
/* Register default value on SPRMCC: 0x00000000                                 */
/* Register default value on SPRD0: 0x00000000                                  */
/* Register default value on SPRHBMB0: 0x00000000                               */
/* Register default value on SPRLCC: 0x00000000                                 */
/* Register default value on EMRXCC: 0x00000000                                 */
/* Register default value on SPRE0: 0x00000000                                  */
/* SPRA0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2             */
/* SPRB0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2             */
/* SPRHBMA0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2          */
/* SPRC0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2             */
/* SPRMCC Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2            */
/* SPRD0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2             */
/* SPRHBMB0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2          */
/* SPRLCC Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2            */
/* EMRXCC Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2            */
/* SPRE0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2             */
/* Struct generated from SPRA0 BDF: 30_0_2                                      */
/* SPRA0 Security PolicyGroup: LB_W                                             */
/* SPRB0 Security PolicyGroup: LB_W                                             */
/* SPRHBMA0 Security PolicyGroup: LB_W                                          */
/* SPRC0 Security PolicyGroup: LB_W                                             */
/* SPRMCC Security PolicyGroup: LB_W                                            */
/* SPRD0 Security PolicyGroup: LB_W                                             */
/* SPRHBMB0 Security PolicyGroup: LB_W                                          */
/* SPRLCC Security PolicyGroup: LB_W                                            */
/* EMRXCC Security PolicyGroup: LB_W                                            */
/* SPRE0 Security PolicyGroup: LB_W                                             */
/* Device Hide Register in CSR space for Bus 0
*/


#define DEVHIDE5_UBOX_MISC_REG 0x13220118

typedef union {
  ///
  /// Individual bit fields
  ///
  struct {
    UINT32 disfn : 32;

                            /* Bits[31:0], Access Type=RW, default=0x00000000*/

                            /*
                               Disable Function(DisFn): A bit set in this
                               register implies that the appropriate device
                               function is not enabled. For instance, if bit 5
                               is set in DEVHIDEuCodeCtrl4, then it means that
                               in device 5, function 4 is disabled.
                            */

  } Bits;
  UINT32 Data;

} DEVHIDE5_UBOX_MISC_STRUCT;

/* DEVHIDE6_UBOX_MISC_REG supported on:                                         */
/*      SPRA0 (0x21e0211c)                                                      */
/*      SPRB0 (0x21e0211c)                                                      */
/*      SPRHBMA0 (0x21e0211c)                                                   */
/*      SPRC0 (0x21e0211c)                                                      */
/*      SPRMCC (0x21e0211c)                                                     */
/*      SPRD0 (0x21e0211c)                                                      */
/*      SPRHBMB0 (0x21e0211c)                                                   */
/*      SPRLCC (0x21e0211c)                                                     */
/*      EMRXCC (0x21e0211c)                                                     */
/*      SPRE0 (0x21e0211c)                                                      */
/* Register default value on SPRA0: 0x00000000                                  */
/* Register default value on SPRB0: 0x00000000                                  */
/* Register default value on SPRHBMA0: 0x00000000                               */
/* Register default value on SPRC0: 0x00000000                                  */
/* Register default value on SPRMCC: 0x00000000                                 */
/* Register default value on SPRD0: 0x00000000                                  */
/* Register default value on SPRHBMB0: 0x00000000                               */
/* Register default value on SPRLCC: 0x00000000                                 */
/* Register default value on EMRXCC: 0x00000000                                 */
/* Register default value on SPRE0: 0x00000000                                  */
/* SPRA0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2             */
/* SPRB0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2             */
/* SPRHBMA0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2          */
/* SPRC0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2             */
/* SPRMCC Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2            */
/* SPRD0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2             */
/* SPRHBMB0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2          */
/* SPRLCC Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2            */
/* EMRXCC Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2            */
/* SPRE0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2             */
/* Struct generated from SPRA0 BDF: 30_0_2                                      */
/* SPRA0 Security PolicyGroup: LB_W                                             */
/* SPRB0 Security PolicyGroup: LB_W                                             */
/* SPRHBMA0 Security PolicyGroup: LB_W                                          */
/* SPRC0 Security PolicyGroup: LB_W                                             */
/* SPRMCC Security PolicyGroup: LB_W                                            */
/* SPRD0 Security PolicyGroup: LB_W                                             */
/* SPRHBMB0 Security PolicyGroup: LB_W                                          */
/* SPRLCC Security PolicyGroup: LB_W                                            */
/* EMRXCC Security PolicyGroup: LB_W                                            */
/* SPRE0 Security PolicyGroup: LB_W                                             */
/* Device Hide Register in CSR space for Bus 0
*/


#define DEVHIDE6_UBOX_MISC_REG 0x1322011C

typedef union {
  ///
  /// Individual bit fields
  ///
  struct {
    UINT32 disfn : 32;

                            /* Bits[31:0], Access Type=RW, default=0x00000000*/

                            /*
                               Disable Function(DisFn): A bit set in this
                               register implies that the appropriate device
                               function is not enabled. For instance, if bit 5
                               is set in DEVHIDEuCodeCtrl4, then it means that
                               in device 5, function 4 is disabled.
                            */

  } Bits;
  UINT32 Data;

} DEVHIDE6_UBOX_MISC_STRUCT;

/* DEVHIDE7_UBOX_MISC_REG supported on:                                         */
/*      SPRA0 (0x21e02120)                                                      */
/*      SPRB0 (0x21e02120)                                                      */
/*      SPRHBMA0 (0x21e02120)                                                   */
/*      SPRC0 (0x21e02120)                                                      */
/*      SPRMCC (0x21e02120)                                                     */
/*      SPRD0 (0x21e02120)                                                      */
/*      SPRHBMB0 (0x21e02120)                                                   */
/*      SPRLCC (0x21e02120)                                                     */
/*      EMRXCC (0x21e02120)                                                     */
/*      SPRE0 (0x21e02120)                                                      */
/* Register default value on SPRA0: 0x00000000                                  */
/* Register default value on SPRB0: 0x00000000                                  */
/* Register default value on SPRHBMA0: 0x00000000                               */
/* Register default value on SPRC0: 0x00000000                                  */
/* Register default value on SPRMCC: 0x00000000                                 */
/* Register default value on SPRD0: 0x00000000                                  */
/* Register default value on SPRHBMB0: 0x00000000                               */
/* Register default value on SPRLCC: 0x00000000                                 */
/* Register default value on EMRXCC: 0x00000000                                 */
/* Register default value on SPRE0: 0x00000000                                  */
/* SPRA0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2             */
/* SPRB0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2             */
/* SPRHBMA0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2          */
/* SPRC0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2             */
/* SPRMCC Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2            */
/* SPRD0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2             */
/* SPRHBMB0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2          */
/* SPRLCC Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2            */
/* EMRXCC Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2            */
/* SPRE0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2             */
/* Struct generated from SPRA0 BDF: 30_0_2                                      */
/* SPRA0 Security PolicyGroup: LB_W                                             */
/* SPRB0 Security PolicyGroup: LB_W                                             */
/* SPRHBMA0 Security PolicyGroup: LB_W                                          */
/* SPRC0 Security PolicyGroup: LB_W                                             */
/* SPRMCC Security PolicyGroup: LB_W                                            */
/* SPRD0 Security PolicyGroup: LB_W                                             */
/* SPRHBMB0 Security PolicyGroup: LB_W                                          */
/* SPRLCC Security PolicyGroup: LB_W                                            */
/* EMRXCC Security PolicyGroup: LB_W                                            */
/* SPRE0 Security PolicyGroup: LB_W                                             */
/* Device Hide Register in CSR space for Bus 0
*/


#define DEVHIDE7_UBOX_MISC_REG 0x13220120

typedef union {
  ///
  /// Individual bit fields
  ///
  struct {
    UINT32 disfn : 32;

                            /* Bits[31:0], Access Type=RW, default=0x00000000*/

                            /*
                               Disable Function(DisFn): A bit set in this
                               register implies that the appropriate device
                               function is not enabled. For instance, if bit 5
                               is set in DEVHIDEuCodeCtrl4, then it means that
                               in device 5, function 4 is disabled.
                            */

  } Bits;
  UINT32 Data;

} DEVHIDE7_UBOX_MISC_STRUCT;

/* DEVHIDE0_1_UBOX_MISC_REG supported on:                                       */
/*      SPRA0 (0x21e02124)                                                      */
/*      SPRB0 (0x21e02124)                                                      */
/*      SPRHBMA0 (0x21e02124)                                                   */
/*      SPRC0 (0x21e02124)                                                      */
/*      SPRMCC (0x21e02124)                                                     */
/*      SPRD0 (0x21e02124)                                                      */
/*      SPRHBMB0 (0x21e02124)                                                   */
/*      SPRLCC (0x21e02124)                                                     */
/*      EMRXCC (0x21e02124)                                                     */
/*      SPRE0 (0x21e02124)                                                      */
/* Register default value on SPRA0: 0x00000000                                  */
/* Register default value on SPRB0: 0x00000000                                  */
/* Register default value on SPRHBMA0: 0x00000000                               */
/* Register default value on SPRC0: 0x00000000                                  */
/* Register default value on SPRMCC: 0x00000000                                 */
/* Register default value on SPRD0: 0x00000000                                  */
/* Register default value on SPRHBMB0: 0x00000000                               */
/* Register default value on SPRLCC: 0x00000000                                 */
/* Register default value on EMRXCC: 0x00000000                                 */
/* Register default value on SPRE0: 0x00000000                                  */
/* SPRA0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2             */
/* SPRB0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2             */
/* SPRHBMA0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2          */
/* SPRC0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2             */
/* SPRMCC Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2            */
/* SPRD0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2             */
/* SPRHBMB0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2          */
/* SPRLCC Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2            */
/* EMRXCC Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2            */
/* SPRE0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2             */
/* Struct generated from SPRA0 BDF: 30_0_2                                      */
/* SPRA0 Security PolicyGroup: LB_W                                             */
/* SPRB0 Security PolicyGroup: LB_W                                             */
/* SPRHBMA0 Security PolicyGroup: LB_W                                          */
/* SPRC0 Security PolicyGroup: LB_W                                             */
/* SPRMCC Security PolicyGroup: LB_W                                            */
/* SPRD0 Security PolicyGroup: LB_W                                             */
/* SPRHBMB0 Security PolicyGroup: LB_W                                          */
/* SPRLCC Security PolicyGroup: LB_W                                            */
/* EMRXCC Security PolicyGroup: LB_W                                            */
/* SPRE0 Security PolicyGroup: LB_W                                             */
/* Device Hide Register in CSR space for Bus 1
*/


#define DEVHIDE0_1_UBOX_MISC_REG 0x13220124

typedef union {
  ///
  /// Individual bit fields
  ///
  struct {
    UINT32 disfn : 32;

                            /* Bits[31:0], Access Type=RW, default=0x00000000*/

                            /*
                               Disable Function(DisFn): A bit set in this
                               register implies that the appropriate device
                               function is not enabled. For instance, if bit 5
                               is set in DEVHIDEuCodeCtrl4, then it means that
                               in device 5, function 4 is disabled.
                            */

  } Bits;
  UINT32 Data;

} DEVHIDE0_1_UBOX_MISC_STRUCT;

/* DEVHIDE1_1_UBOX_MISC_REG supported on:                                       */
/*      SPRA0 (0x21e02128)                                                      */
/*      SPRB0 (0x21e02128)                                                      */
/*      SPRHBMA0 (0x21e02128)                                                   */
/*      SPRC0 (0x21e02128)                                                      */
/*      SPRMCC (0x21e02128)                                                     */
/*      SPRD0 (0x21e02128)                                                      */
/*      SPRHBMB0 (0x21e02128)                                                   */
/*      SPRLCC (0x21e02128)                                                     */
/*      EMRXCC (0x21e02128)                                                     */
/*      SPRE0 (0x21e02128)                                                      */
/* Register default value on SPRA0: 0x00000000                                  */
/* Register default value on SPRB0: 0x00000000                                  */
/* Register default value on SPRHBMA0: 0x00000000                               */
/* Register default value on SPRC0: 0x00000000                                  */
/* Register default value on SPRMCC: 0x00000000                                 */
/* Register default value on SPRD0: 0x00000000                                  */
/* Register default value on SPRHBMB0: 0x00000000                               */
/* Register default value on SPRLCC: 0x00000000                                 */
/* Register default value on EMRXCC: 0x00000000                                 */
/* Register default value on SPRE0: 0x00000000                                  */
/* SPRA0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2             */
/* SPRB0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2             */
/* SPRHBMA0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2          */
/* SPRC0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2             */
/* SPRMCC Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2            */
/* SPRD0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2             */
/* SPRHBMB0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2          */
/* SPRLCC Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2            */
/* EMRXCC Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2            */
/* SPRE0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2             */
/* Struct generated from SPRA0 BDF: 30_0_2                                      */
/* SPRA0 Security PolicyGroup: LB_W                                             */
/* SPRB0 Security PolicyGroup: LB_W                                             */
/* SPRHBMA0 Security PolicyGroup: LB_W                                          */
/* SPRC0 Security PolicyGroup: LB_W                                             */
/* SPRMCC Security PolicyGroup: LB_W                                            */
/* SPRD0 Security PolicyGroup: LB_W                                             */
/* SPRHBMB0 Security PolicyGroup: LB_W                                          */
/* SPRLCC Security PolicyGroup: LB_W                                            */
/* EMRXCC Security PolicyGroup: LB_W                                            */
/* SPRE0 Security PolicyGroup: LB_W                                             */
/* Device Hide Register in CSR space for Bus 1
*/


#define DEVHIDE1_1_UBOX_MISC_REG 0x13220128

typedef union {
  ///
  /// Individual bit fields
  ///
  struct {
    UINT32 disfn : 32;

                            /* Bits[31:0], Access Type=RW, default=0x00000000*/

                            /*
                               Disable Function(DisFn): A bit set in this
                               register implies that the appropriate device
                               function is not enabled. For instance, if bit 5
                               is set in DEVHIDEuCodeCtrl4, then it means that
                               in device 5, function 4 is disabled.
                            */

  } Bits;
  UINT32 Data;

} DEVHIDE1_1_UBOX_MISC_STRUCT;

/* DEVHIDE2_1_UBOX_MISC_REG supported on:                                       */
/*      SPRA0 (0x21e0212c)                                                      */
/*      SPRB0 (0x21e0212c)                                                      */
/*      SPRHBMA0 (0x21e0212c)                                                   */
/*      SPRC0 (0x21e0212c)                                                      */
/*      SPRMCC (0x21e0212c)                                                     */
/*      SPRD0 (0x21e0212c)                                                      */
/*      SPRHBMB0 (0x21e0212c)                                                   */
/*      SPRLCC (0x21e0212c)                                                     */
/*      EMRXCC (0x21e0212c)                                                     */
/*      SPRE0 (0x21e0212c)                                                      */
/* Register default value on SPRA0: 0x00000000                                  */
/* Register default value on SPRB0: 0x00000000                                  */
/* Register default value on SPRHBMA0: 0x00000000                               */
/* Register default value on SPRC0: 0x00000000                                  */
/* Register default value on SPRMCC: 0x00000000                                 */
/* Register default value on SPRD0: 0x00000000                                  */
/* Register default value on SPRHBMB0: 0x00000000                               */
/* Register default value on SPRLCC: 0x00000000                                 */
/* Register default value on EMRXCC: 0x00000000                                 */
/* Register default value on SPRE0: 0x00000000                                  */
/* SPRA0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2             */
/* SPRB0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2             */
/* SPRHBMA0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2          */
/* SPRC0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2             */
/* SPRMCC Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2            */
/* SPRD0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2             */
/* SPRHBMB0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2          */
/* SPRLCC Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2            */
/* EMRXCC Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2            */
/* SPRE0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2             */
/* Struct generated from SPRA0 BDF: 30_0_2                                      */
/* SPRA0 Security PolicyGroup: LB_W                                             */
/* SPRB0 Security PolicyGroup: LB_W                                             */
/* SPRHBMA0 Security PolicyGroup: LB_W                                          */
/* SPRC0 Security PolicyGroup: LB_W                                             */
/* SPRMCC Security PolicyGroup: LB_W                                            */
/* SPRD0 Security PolicyGroup: LB_W                                             */
/* SPRHBMB0 Security PolicyGroup: LB_W                                          */
/* SPRLCC Security PolicyGroup: LB_W                                            */
/* EMRXCC Security PolicyGroup: LB_W                                            */
/* SPRE0 Security PolicyGroup: LB_W                                             */
/* Device Hide Register in CSR space for Bus 1
*/


#define DEVHIDE2_1_UBOX_MISC_REG 0x1322012C

typedef union {
  ///
  /// Individual bit fields
  ///
  struct {
    UINT32 disfn : 32;

                            /* Bits[31:0], Access Type=RW, default=0x00000000*/

                            /*
                               Disable Function(DisFn): A bit set in this
                               register implies that the appropriate device
                               function is not enabled. For instance, if bit 5
                               is set in DEVHIDEuCodeCtrl4, then it means that
                               in device 5, function 4 is disabled.
                            */

  } Bits;
  UINT32 Data;

} DEVHIDE2_1_UBOX_MISC_STRUCT;

/* DEVHIDE3_1_UBOX_MISC_REG supported on:                                       */
/*      SPRA0 (0x21e02130)                                                      */
/*      SPRB0 (0x21e02130)                                                      */
/*      SPRHBMA0 (0x21e02130)                                                   */
/*      SPRC0 (0x21e02130)                                                      */
/*      SPRMCC (0x21e02130)                                                     */
/*      SPRD0 (0x21e02130)                                                      */
/*      SPRHBMB0 (0x21e02130)                                                   */
/*      SPRLCC (0x21e02130)                                                     */
/*      EMRXCC (0x21e02130)                                                     */
/*      SPRE0 (0x21e02130)                                                      */
/* Register default value on SPRA0: 0x00000000                                  */
/* Register default value on SPRB0: 0x00000000                                  */
/* Register default value on SPRHBMA0: 0x00000000                               */
/* Register default value on SPRC0: 0x00000000                                  */
/* Register default value on SPRMCC: 0x00000000                                 */
/* Register default value on SPRD0: 0x00000000                                  */
/* Register default value on SPRHBMB0: 0x00000000                               */
/* Register default value on SPRLCC: 0x00000000                                 */
/* Register default value on EMRXCC: 0x00000000                                 */
/* Register default value on SPRE0: 0x00000000                                  */
/* SPRA0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2             */
/* SPRB0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2             */
/* SPRHBMA0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2          */
/* SPRC0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2             */
/* SPRMCC Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2            */
/* SPRD0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2             */
/* SPRHBMB0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2          */
/* SPRLCC Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2            */
/* EMRXCC Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2            */
/* SPRE0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2             */
/* Struct generated from SPRA0 BDF: 30_0_2                                      */
/* SPRA0 Security PolicyGroup: LB_W                                             */
/* SPRB0 Security PolicyGroup: LB_W                                             */
/* SPRHBMA0 Security PolicyGroup: LB_W                                          */
/* SPRC0 Security PolicyGroup: LB_W                                             */
/* SPRMCC Security PolicyGroup: LB_W                                            */
/* SPRD0 Security PolicyGroup: LB_W                                             */
/* SPRHBMB0 Security PolicyGroup: LB_W                                          */
/* SPRLCC Security PolicyGroup: LB_W                                            */
/* EMRXCC Security PolicyGroup: LB_W                                            */
/* SPRE0 Security PolicyGroup: LB_W                                             */
/* Device Hide Register in CSR space for Bus 1
*/


#define DEVHIDE3_1_UBOX_MISC_REG 0x13220130

typedef union {
  ///
  /// Individual bit fields
  ///
  struct {
    UINT32 disfn : 32;

                            /* Bits[31:0], Access Type=RW, default=0x00000000*/

                            /*
                               Disable Function(DisFn): A bit set in this
                               register implies that the appropriate device
                               function is not enabled. For instance, if bit 5
                               is set in DEVHIDEuCodeCtrl4, then it means that
                               in device 5, function 4 is disabled.
                            */

  } Bits;
  UINT32 Data;

} DEVHIDE3_1_UBOX_MISC_STRUCT;

/* DEVHIDE4_1_UBOX_MISC_REG supported on:                                       */
/*      SPRA0 (0x21e02134)                                                      */
/*      SPRB0 (0x21e02134)                                                      */
/*      SPRHBMA0 (0x21e02134)                                                   */
/*      SPRC0 (0x21e02134)                                                      */
/*      SPRMCC (0x21e02134)                                                     */
/*      SPRD0 (0x21e02134)                                                      */
/*      SPRHBMB0 (0x21e02134)                                                   */
/*      SPRLCC (0x21e02134)                                                     */
/*      EMRXCC (0x21e02134)                                                     */
/*      SPRE0 (0x21e02134)                                                      */
/* Register default value on SPRA0: 0x00000000                                  */
/* Register default value on SPRB0: 0x00000000                                  */
/* Register default value on SPRHBMA0: 0x00000000                               */
/* Register default value on SPRC0: 0x00000000                                  */
/* Register default value on SPRMCC: 0x00000000                                 */
/* Register default value on SPRD0: 0x00000000                                  */
/* Register default value on SPRHBMB0: 0x00000000                               */
/* Register default value on SPRLCC: 0x00000000                                 */
/* Register default value on EMRXCC: 0x00000000                                 */
/* Register default value on SPRE0: 0x00000000                                  */
/* SPRA0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2             */
/* SPRB0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2             */
/* SPRHBMA0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2          */
/* SPRC0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2             */
/* SPRMCC Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2            */
/* SPRD0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2             */
/* SPRHBMB0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2          */
/* SPRLCC Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2            */
/* EMRXCC Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2            */
/* SPRE0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2             */
/* Struct generated from SPRA0 BDF: 30_0_2                                      */
/* SPRA0 Security PolicyGroup: LB_W                                             */
/* SPRB0 Security PolicyGroup: LB_W                                             */
/* SPRHBMA0 Security PolicyGroup: LB_W                                          */
/* SPRC0 Security PolicyGroup: LB_W                                             */
/* SPRMCC Security PolicyGroup: LB_W                                            */
/* SPRD0 Security PolicyGroup: LB_W                                             */
/* SPRHBMB0 Security PolicyGroup: LB_W                                          */
/* SPRLCC Security PolicyGroup: LB_W                                            */
/* EMRXCC Security PolicyGroup: LB_W                                            */
/* SPRE0 Security PolicyGroup: LB_W                                             */
/* Device Hide Register in CSR space for Bus 1
*/


#define DEVHIDE4_1_UBOX_MISC_REG 0x13220134

typedef union {
  ///
  /// Individual bit fields
  ///
  struct {
    UINT32 disfn : 32;

                            /* Bits[31:0], Access Type=RW, default=0x00000000*/

                            /*
                               Disable Function(DisFn): A bit set in this
                               register implies that the appropriate device
                               function is not enabled. For instance, if bit 5
                               is set in DEVHIDEuCodeCtrl4, then it means that
                               in device 5, function 4 is disabled.
                            */

  } Bits;
  UINT32 Data;

} DEVHIDE4_1_UBOX_MISC_STRUCT;

/* DEVHIDE5_1_UBOX_MISC_REG supported on:                                       */
/*      SPRA0 (0x21e02138)                                                      */
/*      SPRB0 (0x21e02138)                                                      */
/*      SPRHBMA0 (0x21e02138)                                                   */
/*      SPRC0 (0x21e02138)                                                      */
/*      SPRMCC (0x21e02138)                                                     */
/*      SPRD0 (0x21e02138)                                                      */
/*      SPRHBMB0 (0x21e02138)                                                   */
/*      SPRLCC (0x21e02138)                                                     */
/*      EMRXCC (0x21e02138)                                                     */
/*      SPRE0 (0x21e02138)                                                      */
/* Register default value on SPRA0: 0x00000000                                  */
/* Register default value on SPRB0: 0x00000000                                  */
/* Register default value on SPRHBMA0: 0x00000000                               */
/* Register default value on SPRC0: 0x00000000                                  */
/* Register default value on SPRMCC: 0x00000000                                 */
/* Register default value on SPRD0: 0x00000000                                  */
/* Register default value on SPRHBMB0: 0x00000000                               */
/* Register default value on SPRLCC: 0x00000000                                 */
/* Register default value on EMRXCC: 0x00000000                                 */
/* Register default value on SPRE0: 0x00000000                                  */
/* SPRA0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2             */
/* SPRB0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2             */
/* SPRHBMA0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2          */
/* SPRC0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2             */
/* SPRMCC Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2            */
/* SPRD0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2             */
/* SPRHBMB0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2          */
/* SPRLCC Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2            */
/* EMRXCC Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2            */
/* SPRE0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2             */
/* Struct generated from SPRA0 BDF: 30_0_2                                      */
/* SPRA0 Security PolicyGroup: LB_W                                             */
/* SPRB0 Security PolicyGroup: LB_W                                             */
/* SPRHBMA0 Security PolicyGroup: LB_W                                          */
/* SPRC0 Security PolicyGroup: LB_W                                             */
/* SPRMCC Security PolicyGroup: LB_W                                            */
/* SPRD0 Security PolicyGroup: LB_W                                             */
/* SPRHBMB0 Security PolicyGroup: LB_W                                          */
/* SPRLCC Security PolicyGroup: LB_W                                            */
/* EMRXCC Security PolicyGroup: LB_W                                            */
/* SPRE0 Security PolicyGroup: LB_W                                             */
/* Device Hide Register in CSR space for Bus 1
*/


#define DEVHIDE5_1_UBOX_MISC_REG 0x13220138

typedef union {
  ///
  /// Individual bit fields
  ///
  struct {
    UINT32 disfn : 32;

                            /* Bits[31:0], Access Type=RW, default=0x00000000*/

                            /*
                               Disable Function(DisFn): A bit set in this
                               register implies that the appropriate device
                               function is not enabled. For instance, if bit 5
                               is set in DEVHIDEuCodeCtrl4, then it means that
                               in device 5, function 4 is disabled.
                            */

  } Bits;
  UINT32 Data;

} DEVHIDE5_1_UBOX_MISC_STRUCT;

/* DEVHIDE6_1_UBOX_MISC_REG supported on:                                       */
/*      SPRA0 (0x21e0213c)                                                      */
/*      SPRB0 (0x21e0213c)                                                      */
/*      SPRHBMA0 (0x21e0213c)                                                   */
/*      SPRC0 (0x21e0213c)                                                      */
/*      SPRMCC (0x21e0213c)                                                     */
/*      SPRD0 (0x21e0213c)                                                      */
/*      SPRHBMB0 (0x21e0213c)                                                   */
/*      SPRLCC (0x21e0213c)                                                     */
/*      EMRXCC (0x21e0213c)                                                     */
/*      SPRE0 (0x21e0213c)                                                      */
/* Register default value on SPRA0: 0x00000000                                  */
/* Register default value on SPRB0: 0x00000000                                  */
/* Register default value on SPRHBMA0: 0x00000000                               */
/* Register default value on SPRC0: 0x00000000                                  */
/* Register default value on SPRMCC: 0x00000000                                 */
/* Register default value on SPRD0: 0x00000000                                  */
/* Register default value on SPRHBMB0: 0x00000000                               */
/* Register default value on SPRLCC: 0x00000000                                 */
/* Register default value on EMRXCC: 0x00000000                                 */
/* Register default value on SPRE0: 0x00000000                                  */
/* SPRA0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2             */
/* SPRB0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2             */
/* SPRHBMA0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2          */
/* SPRC0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2             */
/* SPRMCC Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2            */
/* SPRD0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2             */
/* SPRHBMB0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2          */
/* SPRLCC Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2            */
/* EMRXCC Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2            */
/* SPRE0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2             */
/* Struct generated from SPRA0 BDF: 30_0_2                                      */
/* SPRA0 Security PolicyGroup: LB_W                                             */
/* SPRB0 Security PolicyGroup: LB_W                                             */
/* SPRHBMA0 Security PolicyGroup: LB_W                                          */
/* SPRC0 Security PolicyGroup: LB_W                                             */
/* SPRMCC Security PolicyGroup: LB_W                                            */
/* SPRD0 Security PolicyGroup: LB_W                                             */
/* SPRHBMB0 Security PolicyGroup: LB_W                                          */
/* SPRLCC Security PolicyGroup: LB_W                                            */
/* EMRXCC Security PolicyGroup: LB_W                                            */
/* SPRE0 Security PolicyGroup: LB_W                                             */
/* Device Hide Register in CSR space for Bus 1
*/


#define DEVHIDE6_1_UBOX_MISC_REG 0x1322013C

typedef union {
  ///
  /// Individual bit fields
  ///
  struct {
    UINT32 disfn : 32;

                            /* Bits[31:0], Access Type=RW, default=0x00000000*/

                            /*
                               Disable Function(DisFn): A bit set in this
                               register implies that the appropriate device
                               function is not enabled. For instance, if bit 5
                               is set in DEVHIDEuCodeCtrl4, then it means that
                               in device 5, function 4 is disabled.
                            */

  } Bits;
  UINT32 Data;

} DEVHIDE6_1_UBOX_MISC_STRUCT;

/* DEVHIDE7_1_UBOX_MISC_REG supported on:                                       */
/*      SPRA0 (0x21e02140)                                                      */
/*      SPRB0 (0x21e02140)                                                      */
/*      SPRHBMA0 (0x21e02140)                                                   */
/*      SPRC0 (0x21e02140)                                                      */
/*      SPRMCC (0x21e02140)                                                     */
/*      SPRD0 (0x21e02140)                                                      */
/*      SPRHBMB0 (0x21e02140)                                                   */
/*      SPRLCC (0x21e02140)                                                     */
/*      EMRXCC (0x21e02140)                                                     */
/*      SPRE0 (0x21e02140)                                                      */
/* Register default value on SPRA0: 0x00000000                                  */
/* Register default value on SPRB0: 0x00000000                                  */
/* Register default value on SPRHBMA0: 0x00000000                               */
/* Register default value on SPRC0: 0x00000000                                  */
/* Register default value on SPRMCC: 0x00000000                                 */
/* Register default value on SPRD0: 0x00000000                                  */
/* Register default value on SPRHBMB0: 0x00000000                               */
/* Register default value on SPRLCC: 0x00000000                                 */
/* Register default value on EMRXCC: 0x00000000                                 */
/* Register default value on SPRE0: 0x00000000                                  */
/* SPRA0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2             */
/* SPRB0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2             */
/* SPRHBMA0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2          */
/* SPRC0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2             */
/* SPRMCC Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2            */
/* SPRD0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2             */
/* SPRHBMB0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2          */
/* SPRLCC Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2            */
/* EMRXCC Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2            */
/* SPRE0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2             */
/* Struct generated from SPRA0 BDF: 30_0_2                                      */
/* SPRA0 Security PolicyGroup: LB_W                                             */
/* SPRB0 Security PolicyGroup: LB_W                                             */
/* SPRHBMA0 Security PolicyGroup: LB_W                                          */
/* SPRC0 Security PolicyGroup: LB_W                                             */
/* SPRMCC Security PolicyGroup: LB_W                                            */
/* SPRD0 Security PolicyGroup: LB_W                                             */
/* SPRHBMB0 Security PolicyGroup: LB_W                                          */
/* SPRLCC Security PolicyGroup: LB_W                                            */
/* EMRXCC Security PolicyGroup: LB_W                                            */
/* SPRE0 Security PolicyGroup: LB_W                                             */
/* Device Hide Register in CSR space for Bus 1
*/


#define DEVHIDE7_1_UBOX_MISC_REG 0x13220140

typedef union {
  ///
  /// Individual bit fields
  ///
  struct {
    UINT32 disfn : 32;

                            /* Bits[31:0], Access Type=RW, default=0x00000000*/

                            /*
                               Disable Function(DisFn): A bit set in this
                               register implies that the appropriate device
                               function is not enabled. For instance, if bit 5
                               is set in DEVHIDEuCodeCtrl4, then it means that
                               in device 5, function 4 is disabled.
                            */

  } Bits;
  UINT32 Data;

} DEVHIDE7_1_UBOX_MISC_STRUCT;

/* DEVHIDE0_UBOX_MISC_REG supported on:                                         */
/*      SPRA0 (0x21e02144)                                                      */
/*      SPRB0 (0x21e02144)                                                      */
/*      SPRHBMA0 (0x21e02144)                                                   */
/*      SPRC0 (0x21e02144)                                                      */
/*      SPRMCC (0x21e02144)                                                     */
/*      SPRD0 (0x21e02144)                                                      */
/*      SPRHBMB0 (0x21e02144)                                                   */
/*      SPRLCC (0x21e02144)                                                     */
/*      EMRXCC (0x21e02144)                                                     */
/*      SPRE0 (0x21e02144)                                                      */
/* Register default value on SPRA0: 0x00000000                                  */
/* Register default value on SPRB0: 0x00000000                                  */
/* Register default value on SPRHBMA0: 0x00000000                               */
/* Register default value on SPRC0: 0x00000000                                  */
/* Register default value on SPRMCC: 0x00000000                                 */
/* Register default value on SPRD0: 0x00000000                                  */
/* Register default value on SPRHBMB0: 0x00000000                               */
/* Register default value on SPRLCC: 0x00000000                                 */
/* Register default value on EMRXCC: 0x00000000                                 */
/* Register default value on SPRE0: 0x00000000                                  */
/* SPRA0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2             */
/* SPRB0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2             */
/* SPRHBMA0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2          */
/* SPRC0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2             */
/* SPRMCC Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2            */
/* SPRD0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2             */
/* SPRHBMB0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2          */
/* SPRLCC Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2            */
/* EMRXCC Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2            */
/* SPRE0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2             */
/* Struct generated from SPRA0 BDF: 30_0_2                                      */
/* SPRA0 Security PolicyGroup: LB_W                                             */
/* SPRB0 Security PolicyGroup: LB_W                                             */
/* SPRHBMA0 Security PolicyGroup: LB_W                                          */
/* SPRC0 Security PolicyGroup: LB_W                                             */
/* SPRMCC Security PolicyGroup: LB_W                                            */
/* SPRD0 Security PolicyGroup: LB_W                                             */
/* SPRHBMB0 Security PolicyGroup: LB_W                                          */
/* SPRLCC Security PolicyGroup: LB_W                                            */
/* EMRXCC Security PolicyGroup: LB_W                                            */
/* SPRE0 Security PolicyGroup: LB_W                                             */
/* Device Hide Register in CSR space for Bus 0
*/


#define DEVHIDE0_UBOX_MISC_REG 0x13220144

typedef union {
  ///
  /// Individual bit fields
  ///
  struct {
    UINT32 disfn : 32;

                            /* Bits[31:0], Access Type=RW, default=0x00000000*/

                            /*
                               Disable Function(DisFn): A bit set in this
                               register implies that the appropriate device
                               function is not enabled. For instance, if bit 5
                               is set in DEVHIDEuCodeCtrl4, then it means that
                               in device 5, function 4 is disabled.
                            */

  } Bits;
  UINT32 Data;

} DEVHIDE0_UBOX_MISC_STRUCT;



/* SBREG_PTE0_UBOX_MISC_REG supported on:                                       */
/*      SPRA0 (0x21e02168)                                                      */
/*      SPRB0 (0x21e02168)                                                      */
/*      SPRHBMA0 (0x21e02168)                                                   */
/*      SPRC0 (0x21e02168)                                                      */
/*      SPRMCC (0x21e02168)                                                     */
/*      SPRD0 (0x21e02168)                                                      */
/*      SPRHBMB0 (0x21e02168)                                                   */
/*      SPRLCC (0x21e02168)                                                     */
/*      EMRXCC (0x21e02168)                                                     */
/*      SPRE0 (0x21e02168)                                                      */
/* Register default value on SPRA0: 0x0000000C                                  */
/* Register default value on SPRB0: 0x0000000C                                  */
/* Register default value on SPRHBMA0: 0x0000000C                               */
/* Register default value on SPRC0: 0x0000000C                                  */
/* Register default value on SPRMCC: 0x0000000C                                 */
/* Register default value on SPRD0: 0x0000000C                                  */
/* Register default value on SPRHBMB0: 0x0000000C                               */
/* Register default value on SPRLCC: 0x0000000C                                 */
/* Register default value on EMRXCC: 0x0000000C                                 */
/* Register default value on SPRE0: 0x0000000C                                  */
/* SPRA0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2             */
/* SPRB0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2             */
/* SPRHBMA0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2          */
/* SPRC0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2             */
/* SPRMCC Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2            */
/* SPRD0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2             */
/* SPRHBMB0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2          */
/* SPRLCC Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2            */
/* EMRXCC Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2            */
/* SPRE0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2             */
/* Struct generated from SPRA0 BDF: 30_0_2                                      */
/* SPRA0 Security PolicyGroup: LB_W                                             */
/* SPRB0 Security PolicyGroup: LB_W                                             */
/* SPRHBMA0 Security PolicyGroup: LB_W                                          */
/* SPRC0 Security PolicyGroup: LB_W                                             */
/* SPRMCC Security PolicyGroup: LB_W                                            */
/* SPRD0 Security PolicyGroup: LB_W                                             */
/* SPRHBMB0 Security PolicyGroup: LB_W                                          */
/* SPRLCC Security PolicyGroup: LB_W                                            */
/* EMRXCC Security PolicyGroup: LB_W                                            */
/* SPRE0 Security PolicyGroup: LB_W                                             */
/* SBREG bar Page Table Entry register
*/


#define SBREG_PTE0_UBOX_MISC_REG 0x13220168

typedef union {
  ///
  /// Individual bit fields
  ///
  struct {
    UINT32 valid : 1;

                            /* Bits[0:0], Access Type=RW, default=0x00000000*/

                            /* PTE Valid */
    UINT32 posted : 1;

                            /* Bits[1:1], Access Type=RO, default=0x00000000*/

                            /* Always non-posted */
    UINT32 address_space : 2;

                            /* Bits[3:2], Access Type=RO, default=0x00000003*/

                            /* Always target CR space */
    UINT32 root_space : 2;

                            /* Bits[5:4], Access Type=RO, default=0x00000000*/

                            /* Always Root Space */
    UINT32 upper_port_id : 2;

                            /* Bits[7:6], Access Type=RW, default=0x00000000*/

                            /* Upper bits of Logical Port ID */
    UINT32 bar_number : 3;

                            /* Bits[10:8], Access Type=RW, default=0x00000000*/

                            /* Always BAR 0 */
    UINT32 rsvd : 1;

                            /* Bits[11:11], Access Type=RO, default=None*/

                            /* Reserved */
    UINT32 reserved : 4;

                            /* Bits[15:12], Access Type=RO, default=0x00000000*/

                            /* Reserved for future offset implementation */
    UINT32 fid : 8;

                            /* Bits[23:16], Access Type=RW, default=0x00000000*/

                            /* Always FID 0 */
    UINT32 lower_portid : 8;

                            /* Bits[31:24], Access Type=RW, default=0x00000000*/

                            /* Lower bits of Logical Port ID */

  } Bits;
  UINT32 Data;

} SBREG_PTE0_UBOX_MISC_STRUCT;

/* LOCALAQUSEMP_0_UBOX_MISC_REG supported on:                                   */
/*      SPRA0 (0x21e02180)                                                      */
/*      SPRB0 (0x21e02180)                                                      */
/*      SPRHBMA0 (0x21e02180)                                                   */
/*      SPRC0 (0x21e02180)                                                      */
/*      SPRMCC (0x21e02180)                                                     */
/*      SPRD0 (0x21e02180)                                                      */
/*      SPRHBMB0 (0x21e02180)                                                   */
/*      SPRLCC (0x21e02180)                                                     */
/*      EMRXCC (0x21e02180)                                                     */
/*      SPRE0 (0x21e02180)                                                      */
/* Register default value on SPRA0: 0x00000000                                  */
/* Register default value on SPRB0: 0x00000000                                  */
/* Register default value on SPRHBMA0: 0x00000000                               */
/* Register default value on SPRC0: 0x00000000                                  */
/* Register default value on SPRMCC: 0x00000000                                 */
/* Register default value on SPRD0: 0x00000000                                  */
/* Register default value on SPRHBMB0: 0x00000000                               */
/* Register default value on SPRLCC: 0x00000000                                 */
/* Register default value on EMRXCC: 0x00000000                                 */
/* Register default value on SPRE0: 0x00000000                                  */
/* SPRA0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2             */
/* SPRB0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2             */
/* SPRHBMA0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2          */
/* SPRC0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2             */
/* SPRMCC Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2            */
/* SPRD0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2             */
/* SPRHBMB0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2          */
/* SPRLCC Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2            */
/* EMRXCC Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2            */
/* SPRE0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2             */
/* Struct generated from SPRA0 BDF: 30_0_2                                      */
/* SPRA0 Security PolicyGroup: OS_W                                             */
/* SPRB0 Security PolicyGroup: OS_W                                             */
/* SPRHBMA0 Security PolicyGroup: OS_W                                          */
/* SPRC0 Security PolicyGroup: OS_W                                             */
/* SPRMCC Security PolicyGroup: OS_W                                            */
/* SPRD0 Security PolicyGroup: OS_W                                             */
/* SPRHBMB0 Security PolicyGroup: OS_W                                          */
/* SPRLCC Security PolicyGroup: OS_W                                            */
/* EMRXCC Security PolicyGroup: OS_W                                            */
/* SPRE0 Security PolicyGroup: OS_W                                             */
/* unCore Semaphore register. Read Only register. Can be read only from FW. Atomically increments the TAIL counter and returns pre-incremented value and ownership indication.  The NCU performs error detection here in case the tail passes the head. 
*/


#define LOCALAQUSEMP_0_UBOX_MISC_REG 0x13220180

typedef union {
  ///
  /// Individual bit fields
  ///
  struct {
    UINT32 sempcurrtail : 16;

                            /* Bits[15:0], Access Type=RO/V, default=0x00000000*/

                            /*
                               Read from this field return pre-incremented
                               value of the Tail counter of the Semaphore. When
                               reading this field, the Tail counter is
                               incremented.
                            */
    UINT32 rsvd : 14;

                            /* Bits[29:16], Access Type=RO, default=None*/

                            /* Reserved */
    UINT32 sempowned : 1;

                            /* Bits[30:30], Access Type=RO/V, default=0x00000000*/

                            /*
                               Indicates that the thread that is currently
                               requesting for Semaphore ownership received it.
                               Aka return '1' if the apre-incremented value of
                               the Tail counter equals to the Head counter. If
                               the pre-incremented value of the tail equals to
                               the Head counter, that means that the order is
                               mess and the HW will signal a machine-check
                            */
    UINT32 rsvd_31 : 1;

                            /* Bits[31:31], Access Type=RO, default=None*/

                            /* Reserved */

  } Bits;
  UINT32 Data;

} LOCALAQUSEMP_0_UBOX_MISC_STRUCT;

/* LOCALAQUSEMP_1_UBOX_MISC_REG supported on:                                   */
/*      SPRA0 (0x21e02184)                                                      */
/*      SPRB0 (0x21e02184)                                                      */
/*      SPRHBMA0 (0x21e02184)                                                   */
/*      SPRC0 (0x21e02184)                                                      */
/*      SPRMCC (0x21e02184)                                                     */
/*      SPRD0 (0x21e02184)                                                      */
/*      SPRHBMB0 (0x21e02184)                                                   */
/*      SPRLCC (0x21e02184)                                                     */
/*      EMRXCC (0x21e02184)                                                     */
/*      SPRE0 (0x21e02184)                                                      */
/* Register default value on SPRA0: 0x00000000                                  */
/* Register default value on SPRB0: 0x00000000                                  */
/* Register default value on SPRHBMA0: 0x00000000                               */
/* Register default value on SPRC0: 0x00000000                                  */
/* Register default value on SPRMCC: 0x00000000                                 */
/* Register default value on SPRD0: 0x00000000                                  */
/* Register default value on SPRHBMB0: 0x00000000                               */
/* Register default value on SPRLCC: 0x00000000                                 */
/* Register default value on EMRXCC: 0x00000000                                 */
/* Register default value on SPRE0: 0x00000000                                  */
/* SPRA0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2             */
/* SPRB0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2             */
/* SPRHBMA0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2          */
/* SPRC0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2             */
/* SPRMCC Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2            */
/* SPRD0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2             */
/* SPRHBMB0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2          */
/* SPRLCC Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2            */
/* EMRXCC Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2            */
/* SPRE0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2             */
/* Struct generated from SPRA0 BDF: 30_0_2                                      */
/* SPRA0 Security PolicyGroup: OS_W                                             */
/* SPRB0 Security PolicyGroup: OS_W                                             */
/* SPRHBMA0 Security PolicyGroup: OS_W                                          */
/* SPRC0 Security PolicyGroup: OS_W                                             */
/* SPRMCC Security PolicyGroup: OS_W                                            */
/* SPRD0 Security PolicyGroup: OS_W                                             */
/* SPRHBMB0 Security PolicyGroup: OS_W                                          */
/* SPRLCC Security PolicyGroup: OS_W                                            */
/* EMRXCC Security PolicyGroup: OS_W                                            */
/* SPRE0 Security PolicyGroup: OS_W                                             */
/* unCore Semaphore register. Read Only register. Can be read only from FW. Atomically increments the TAIL counter and returns pre-incremented value and ownership indication.  The NCU performs error detection here in case the tail passes the head. 
*/


#define LOCALAQUSEMP_1_UBOX_MISC_REG 0x13220184

typedef union {
  ///
  /// Individual bit fields
  ///
  struct {
    UINT32 sempcurrtail : 16;

                            /* Bits[15:0], Access Type=RO/V, default=0x00000000*/

                            /*
                               Read from this field return pre-incremented
                               value of the Tail counter of the Semaphore. When
                               reading this field, the Tail counter is
                               incremented.
                            */
    UINT32 rsvd : 14;

                            /* Bits[29:16], Access Type=RO, default=None*/

                            /* Reserved */
    UINT32 sempowned : 1;

                            /* Bits[30:30], Access Type=RO/V, default=0x00000000*/

                            /*
                               Indicates that the thread that is currently
                               requesting for Semaphore ownership received it.
                               Aka return '1' if the apre-incremented value of
                               the Tail counter equals to the Head counter. If
                               the pre-incremented value of the tail equals to
                               the Head counter, that means that the order is
                               mess and the HW will signal a machine-check
                            */
    UINT32 rsvd_31 : 1;

                            /* Bits[31:31], Access Type=RO, default=None*/

                            /* Reserved */

  } Bits;
  UINT32 Data;

} LOCALAQUSEMP_1_UBOX_MISC_STRUCT;

/* SYSTEMAQUSEMP_0_UBOX_MISC_REG supported on:                                  */
/*      SPRA0 (0x21e02188)                                                      */
/*      SPRB0 (0x21e02188)                                                      */
/*      SPRHBMA0 (0x21e02188)                                                   */
/*      SPRC0 (0x21e02188)                                                      */
/*      SPRMCC (0x21e02188)                                                     */
/*      SPRD0 (0x21e02188)                                                      */
/*      SPRHBMB0 (0x21e02188)                                                   */
/*      SPRLCC (0x21e02188)                                                     */
/*      EMRXCC (0x21e02188)                                                     */
/*      SPRE0 (0x21e02188)                                                      */
/* Register default value on SPRA0: 0x00000000                                  */
/* Register default value on SPRB0: 0x00000000                                  */
/* Register default value on SPRHBMA0: 0x00000000                               */
/* Register default value on SPRC0: 0x00000000                                  */
/* Register default value on SPRMCC: 0x00000000                                 */
/* Register default value on SPRD0: 0x00000000                                  */
/* Register default value on SPRHBMB0: 0x00000000                               */
/* Register default value on SPRLCC: 0x00000000                                 */
/* Register default value on EMRXCC: 0x00000000                                 */
/* Register default value on SPRE0: 0x00000000                                  */
/* SPRA0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2             */
/* SPRB0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2             */
/* SPRHBMA0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2          */
/* SPRC0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2             */
/* SPRMCC Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2            */
/* SPRD0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2             */
/* SPRHBMB0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2          */
/* SPRLCC Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2            */
/* EMRXCC Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2            */
/* SPRE0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2             */
/* Struct generated from SPRA0 BDF: 30_0_2                                      */
/* SPRA0 Security PolicyGroup: OS_W                                             */
/* SPRB0 Security PolicyGroup: OS_W                                             */
/* SPRHBMA0 Security PolicyGroup: OS_W                                          */
/* SPRC0 Security PolicyGroup: OS_W                                             */
/* SPRMCC Security PolicyGroup: OS_W                                            */
/* SPRD0 Security PolicyGroup: OS_W                                             */
/* SPRHBMB0 Security PolicyGroup: OS_W                                          */
/* SPRLCC Security PolicyGroup: OS_W                                            */
/* EMRXCC Security PolicyGroup: OS_W                                            */
/* SPRE0 Security PolicyGroup: OS_W                                             */
/* unCore Semaphore register. Read Only register. Can be read only from FW. Atomically increments the TAIL counter and returns pre-incremented value and ownership indication.  The NCU performs error detection here in case the tail passes the head. 
*/


#define SYSTEMAQUSEMP_0_UBOX_MISC_REG 0x13220188

typedef union {
  ///
  /// Individual bit fields
  ///
  struct {
    UINT32 sempcurrtail : 16;

                            /* Bits[15:0], Access Type=RO/V, default=0x00000000*/

                            /*
                               Read from this field return pre-incremented
                               value of the Tail counter of the Semaphore. When
                               reading this field, the Tail counter is
                               incremented.
                            */
    UINT32 rsvd : 14;

                            /* Bits[29:16], Access Type=RO, default=None*/

                            /* Reserved */
    UINT32 sempowned : 1;

                            /* Bits[30:30], Access Type=RO/V, default=0x00000000*/

                            /*
                               Indicates that the thread that is currently
                               requesting for Semaphore ownership received it.
                               Aka return '1' if the apre-incremented value of
                               the Tail counter equals to the Head counter. If
                               the pre-incremented value of the tail equals to
                               the Head counter, that means that the order is
                               mess and the HW will signal a machine-check
                            */
    UINT32 rsvd_31 : 1;

                            /* Bits[31:31], Access Type=RO, default=None*/

                            /* Reserved */

  } Bits;
  UINT32 Data;

} SYSTEMAQUSEMP_0_UBOX_MISC_STRUCT;

/* SYSTEMAQUSEMP_1_UBOX_MISC_REG supported on:                                  */
/*      SPRA0 (0x21e0218c)                                                      */
/*      SPRB0 (0x21e0218c)                                                      */
/*      SPRHBMA0 (0x21e0218c)                                                   */
/*      SPRC0 (0x21e0218c)                                                      */
/*      SPRMCC (0x21e0218c)                                                     */
/*      SPRD0 (0x21e0218c)                                                      */
/*      SPRHBMB0 (0x21e0218c)                                                   */
/*      SPRLCC (0x21e0218c)                                                     */
/*      EMRXCC (0x21e0218c)                                                     */
/*      SPRE0 (0x21e0218c)                                                      */
/* Register default value on SPRA0: 0x00000000                                  */
/* Register default value on SPRB0: 0x00000000                                  */
/* Register default value on SPRHBMA0: 0x00000000                               */
/* Register default value on SPRC0: 0x00000000                                  */
/* Register default value on SPRMCC: 0x00000000                                 */
/* Register default value on SPRD0: 0x00000000                                  */
/* Register default value on SPRHBMB0: 0x00000000                               */
/* Register default value on SPRLCC: 0x00000000                                 */
/* Register default value on EMRXCC: 0x00000000                                 */
/* Register default value on SPRE0: 0x00000000                                  */
/* SPRA0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2             */
/* SPRB0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2             */
/* SPRHBMA0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2          */
/* SPRC0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2             */
/* SPRMCC Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2            */
/* SPRD0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2             */
/* SPRHBMB0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2          */
/* SPRLCC Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2            */
/* EMRXCC Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2            */
/* SPRE0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2             */
/* Struct generated from SPRA0 BDF: 30_0_2                                      */
/* SPRA0 Security PolicyGroup: OS_W                                             */
/* SPRB0 Security PolicyGroup: OS_W                                             */
/* SPRHBMA0 Security PolicyGroup: OS_W                                          */
/* SPRC0 Security PolicyGroup: OS_W                                             */
/* SPRMCC Security PolicyGroup: OS_W                                            */
/* SPRD0 Security PolicyGroup: OS_W                                             */
/* SPRHBMB0 Security PolicyGroup: OS_W                                          */
/* SPRLCC Security PolicyGroup: OS_W                                            */
/* EMRXCC Security PolicyGroup: OS_W                                            */
/* SPRE0 Security PolicyGroup: OS_W                                             */
/* unCore Semaphore register. Read Only register. Can be read only from FW. Atomically increments the TAIL counter and returns pre-incremented value and ownership indication.  The NCU performs error detection here in case the tail passes the head. 
*/


#define SYSTEMAQUSEMP_1_UBOX_MISC_REG 0x1322018C

typedef union {
  ///
  /// Individual bit fields
  ///
  struct {
    UINT32 sempcurrtail : 16;

                            /* Bits[15:0], Access Type=RO/V, default=0x00000000*/

                            /*
                               Read from this field return pre-incremented
                               value of the Tail counter of the Semaphore. When
                               reading this field, the Tail counter is
                               incremented.
                            */
    UINT32 rsvd : 14;

                            /* Bits[29:16], Access Type=RO, default=None*/

                            /* Reserved */
    UINT32 sempowned : 1;

                            /* Bits[30:30], Access Type=RO/V, default=0x00000000*/

                            /*
                               Indicates that the thread that is currently
                               requesting for Semaphore ownership received it.
                               Aka return '1' if the apre-incremented value of
                               the Tail counter equals to the Head counter. If
                               the pre-incremented value of the tail equals to
                               the Head counter, that means that the order is
                               mess and the HW will signal a machine-check
                            */
    UINT32 rsvd_31 : 1;

                            /* Bits[31:31], Access Type=RO, default=None*/

                            /* Reserved */

  } Bits;
  UINT32 Data;

} SYSTEMAQUSEMP_1_UBOX_MISC_STRUCT;

/* LOCALIMPAQUSEMP_0_UBOX_MISC_REG supported on:                                */
/*      SPRA0 (0x21e02190)                                                      */
/*      SPRB0 (0x21e02190)                                                      */
/*      SPRHBMA0 (0x21e02190)                                                   */
/*      SPRC0 (0x21e02190)                                                      */
/*      SPRMCC (0x21e02190)                                                     */
/*      SPRD0 (0x21e02190)                                                      */
/*      SPRHBMB0 (0x21e02190)                                                   */
/*      SPRLCC (0x21e02190)                                                     */
/*      EMRXCC (0x21e02190)                                                     */
/*      SPRE0 (0x21e02190)                                                      */
/* Register default value on SPRA0: 0x00000000                                  */
/* Register default value on SPRB0: 0x00000000                                  */
/* Register default value on SPRHBMA0: 0x00000000                               */
/* Register default value on SPRC0: 0x00000000                                  */
/* Register default value on SPRMCC: 0x00000000                                 */
/* Register default value on SPRD0: 0x00000000                                  */
/* Register default value on SPRHBMB0: 0x00000000                               */
/* Register default value on SPRLCC: 0x00000000                                 */
/* Register default value on EMRXCC: 0x00000000                                 */
/* Register default value on SPRE0: 0x00000000                                  */
/* SPRA0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2             */
/* SPRB0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2             */
/* SPRHBMA0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2          */
/* SPRC0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2             */
/* SPRMCC Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2            */
/* SPRD0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2             */
/* SPRHBMB0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2          */
/* SPRLCC Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2            */
/* EMRXCC Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2            */
/* SPRE0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2             */
/* Struct generated from SPRA0 BDF: 30_0_2                                      */
/* SPRA0 Security PolicyGroup: OS_W                                             */
/* SPRB0 Security PolicyGroup: OS_W                                             */
/* SPRHBMA0 Security PolicyGroup: OS_W                                          */
/* SPRC0 Security PolicyGroup: OS_W                                             */
/* SPRMCC Security PolicyGroup: OS_W                                            */
/* SPRD0 Security PolicyGroup: OS_W                                             */
/* SPRHBMB0 Security PolicyGroup: OS_W                                          */
/* SPRLCC Security PolicyGroup: OS_W                                            */
/* EMRXCC Security PolicyGroup: OS_W                                            */
/* SPRE0 Security PolicyGroup: OS_W                                             */
/* unCore Semaphore register. Read Only register. Can be read only from FW. In a case that the apre-incremented value of the Tail counter equals to the value in the head counter, the tail counter will be really Atomically incremented and the requesting thread will get the semaphore ownershipe. In a case that the apre-incremented value of the Tail counter does notequal to the value in the head counter the TAIL counter, the thread will not get the ownershipe and the Tail counter valure will not be practically incremented.
*/


#define LOCALIMPAQUSEMP_0_UBOX_MISC_REG 0x13220190

typedef union {
  ///
  /// Individual bit fields
  ///
  struct {
    UINT32 sempcurrtail : 16;

                            /* Bits[15:0], Access Type=RO/V, default=0x00000000*/

                            /*
                               Read from this field return pre-incremented
                               value of the Tail counter of the Semaphore. When
                               reading this field, the Tail counter is
                               incremented only if the requesting thread realy
                               recieved the semaphore ownership.
                            */
    UINT32 rsvd : 14;

                            /* Bits[29:16], Access Type=RO, default=None*/

                            /* Reserved */
    UINT32 sempowned : 1;

                            /* Bits[30:30], Access Type=RO/V, default=0x00000000*/

                            /*
                               Indicates that the thread that is currently
                               requesting for Semaphore ownership received it.
                               Aka return '1' if the apre-incremented value of
                               the Tail counter equals to the Head counter. If
                               the pre-incremented value of the tail equals to
                               the Head counter, that means that the order is
                               mess and the HW will signal a machine-check
                            */
    UINT32 rsvd_31 : 1;

                            /* Bits[31:31], Access Type=RO, default=None*/

                            /* Reserved */

  } Bits;
  UINT32 Data;

} LOCALIMPAQUSEMP_0_UBOX_MISC_STRUCT;

/* LOCALIMPAQUSEMP_1_UBOX_MISC_REG supported on:                                */
/*      SPRA0 (0x21e02194)                                                      */
/*      SPRB0 (0x21e02194)                                                      */
/*      SPRHBMA0 (0x21e02194)                                                   */
/*      SPRC0 (0x21e02194)                                                      */
/*      SPRMCC (0x21e02194)                                                     */
/*      SPRD0 (0x21e02194)                                                      */
/*      SPRHBMB0 (0x21e02194)                                                   */
/*      SPRLCC (0x21e02194)                                                     */
/*      EMRXCC (0x21e02194)                                                     */
/*      SPRE0 (0x21e02194)                                                      */
/* Register default value on SPRA0: 0x00000000                                  */
/* Register default value on SPRB0: 0x00000000                                  */
/* Register default value on SPRHBMA0: 0x00000000                               */
/* Register default value on SPRC0: 0x00000000                                  */
/* Register default value on SPRMCC: 0x00000000                                 */
/* Register default value on SPRD0: 0x00000000                                  */
/* Register default value on SPRHBMB0: 0x00000000                               */
/* Register default value on SPRLCC: 0x00000000                                 */
/* Register default value on EMRXCC: 0x00000000                                 */
/* Register default value on SPRE0: 0x00000000                                  */
/* SPRA0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2             */
/* SPRB0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2             */
/* SPRHBMA0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2          */
/* SPRC0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2             */
/* SPRMCC Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2            */
/* SPRD0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2             */
/* SPRHBMB0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2          */
/* SPRLCC Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2            */
/* EMRXCC Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2            */
/* SPRE0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2             */
/* Struct generated from SPRA0 BDF: 30_0_2                                      */
/* SPRA0 Security PolicyGroup: OS_W                                             */
/* SPRB0 Security PolicyGroup: OS_W                                             */
/* SPRHBMA0 Security PolicyGroup: OS_W                                          */
/* SPRC0 Security PolicyGroup: OS_W                                             */
/* SPRMCC Security PolicyGroup: OS_W                                            */
/* SPRD0 Security PolicyGroup: OS_W                                             */
/* SPRHBMB0 Security PolicyGroup: OS_W                                          */
/* SPRLCC Security PolicyGroup: OS_W                                            */
/* EMRXCC Security PolicyGroup: OS_W                                            */
/* SPRE0 Security PolicyGroup: OS_W                                             */
/* unCore Semaphore register. Read Only register. Can be read only from FW. In a case that the apre-incremented value of the Tail counter equals to the value in the head counter, the tail counter will be really Atomically incremented and the requesting thread will get the semaphore ownershipe. In a case that the apre-incremented value of the Tail counter does notequal to the value in the head counter the TAIL counter, the thread will not get the ownershipe and the Tail counter valure will not be practically incremented.
*/


#define LOCALIMPAQUSEMP_1_UBOX_MISC_REG 0x13220194

typedef union {
  ///
  /// Individual bit fields
  ///
  struct {
    UINT32 sempcurrtail : 16;

                            /* Bits[15:0], Access Type=RO/V, default=0x00000000*/

                            /*
                               Read from this field return pre-incremented
                               value of the Tail counter of the Semaphore. When
                               reading this field, the Tail counter is
                               incremented only if the requesting thread realy
                               recieved the semaphore ownership.
                            */
    UINT32 rsvd : 14;

                            /* Bits[29:16], Access Type=RO, default=None*/

                            /* Reserved */
    UINT32 sempowned : 1;

                            /* Bits[30:30], Access Type=RO/V, default=0x00000000*/

                            /*
                               Indicates that the thread that is currently
                               requesting for Semaphore ownership received it.
                               Aka return '1' if the apre-incremented value of
                               the Tail counter equals to the Head counter. If
                               the pre-incremented value of the tail equals to
                               the Head counter, that means that the order is
                               mess and the HW will signal a machine-check
                            */
    UINT32 rsvd_31 : 1;

                            /* Bits[31:31], Access Type=RO, default=None*/

                            /* Reserved */

  } Bits;
  UINT32 Data;

} LOCALIMPAQUSEMP_1_UBOX_MISC_STRUCT;

/* SYSTEMIMPAQUSEMP_0_UBOX_MISC_REG supported on:                               */
/*      SPRA0 (0x21e02198)                                                      */
/*      SPRB0 (0x21e02198)                                                      */
/*      SPRHBMA0 (0x21e02198)                                                   */
/*      SPRC0 (0x21e02198)                                                      */
/*      SPRMCC (0x21e02198)                                                     */
/*      SPRD0 (0x21e02198)                                                      */
/*      SPRHBMB0 (0x21e02198)                                                   */
/*      SPRLCC (0x21e02198)                                                     */
/*      EMRXCC (0x21e02198)                                                     */
/*      SPRE0 (0x21e02198)                                                      */
/* Register default value on SPRA0: 0x00000000                                  */
/* Register default value on SPRB0: 0x00000000                                  */
/* Register default value on SPRHBMA0: 0x00000000                               */
/* Register default value on SPRC0: 0x00000000                                  */
/* Register default value on SPRMCC: 0x00000000                                 */
/* Register default value on SPRD0: 0x00000000                                  */
/* Register default value on SPRHBMB0: 0x00000000                               */
/* Register default value on SPRLCC: 0x00000000                                 */
/* Register default value on EMRXCC: 0x00000000                                 */
/* Register default value on SPRE0: 0x00000000                                  */
/* SPRA0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2             */
/* SPRB0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2             */
/* SPRHBMA0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2          */
/* SPRC0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2             */
/* SPRMCC Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2            */
/* SPRD0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2             */
/* SPRHBMB0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2          */
/* SPRLCC Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2            */
/* EMRXCC Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2            */
/* SPRE0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2             */
/* Struct generated from SPRA0 BDF: 30_0_2                                      */
/* SPRA0 Security PolicyGroup: OS_W                                             */
/* SPRB0 Security PolicyGroup: OS_W                                             */
/* SPRHBMA0 Security PolicyGroup: OS_W                                          */
/* SPRC0 Security PolicyGroup: OS_W                                             */
/* SPRMCC Security PolicyGroup: OS_W                                            */
/* SPRD0 Security PolicyGroup: OS_W                                             */
/* SPRHBMB0 Security PolicyGroup: OS_W                                          */
/* SPRLCC Security PolicyGroup: OS_W                                            */
/* EMRXCC Security PolicyGroup: OS_W                                            */
/* SPRE0 Security PolicyGroup: OS_W                                             */
/* unCore Semaphore register. Read Only register. Can be read only from FW. In a case that the apre-incremented value of the Tail counter equals to the value in the head counter, the tail counter will be really Atomically incremented and the requesting thread will get the semaphore ownershipe. In a case that the apre-incremented value of the Tail counter does notequal to the value in the head counter the TAIL counter, the thread will not get the ownershipe and the Tail counter valure will not be practically incremented.
*/


#define SYSTEMIMPAQUSEMP_0_UBOX_MISC_REG 0x13220198

typedef union {
  ///
  /// Individual bit fields
  ///
  struct {
    UINT32 sempcurrtail : 16;

                            /* Bits[15:0], Access Type=RO/V, default=0x00000000*/

                            /*
                               Read from this field return pre-incremented
                               value of the Tail counter of the Semaphore. When
                               reading this field, the Tail counter is
                               incremented only if the requesting thread realy
                               recieved the semaphore ownership.
                            */
    UINT32 rsvd : 14;

                            /* Bits[29:16], Access Type=RO, default=None*/

                            /* Reserved */
    UINT32 sempowned : 1;

                            /* Bits[30:30], Access Type=RO/V, default=0x00000000*/

                            /*
                               Indicates that the thread that is currently
                               requesting for Semaphore ownership received it.
                               Aka return '1' if the apre-incremented value of
                               the Tail counter equals to the Head counter. If
                               the pre-incremented value of the tail equals to
                               the Head counter, that means that the order is
                               mess and the HW will signal a machine-check
                            */
    UINT32 rsvd_31 : 1;

                            /* Bits[31:31], Access Type=RO, default=None*/

                            /* Reserved */

  } Bits;
  UINT32 Data;

} SYSTEMIMPAQUSEMP_0_UBOX_MISC_STRUCT;

/* SYSTEMIMPAQUSEMP_1_UBOX_MISC_REG supported on:                               */
/*      SPRA0 (0x21e0219c)                                                      */
/*      SPRB0 (0x21e0219c)                                                      */
/*      SPRHBMA0 (0x21e0219c)                                                   */
/*      SPRC0 (0x21e0219c)                                                      */
/*      SPRMCC (0x21e0219c)                                                     */
/*      SPRD0 (0x21e0219c)                                                      */
/*      SPRHBMB0 (0x21e0219c)                                                   */
/*      SPRLCC (0x21e0219c)                                                     */
/*      EMRXCC (0x21e0219c)                                                     */
/*      SPRE0 (0x21e0219c)                                                      */
/* Register default value on SPRA0: 0x00000000                                  */
/* Register default value on SPRB0: 0x00000000                                  */
/* Register default value on SPRHBMA0: 0x00000000                               */
/* Register default value on SPRC0: 0x00000000                                  */
/* Register default value on SPRMCC: 0x00000000                                 */
/* Register default value on SPRD0: 0x00000000                                  */
/* Register default value on SPRHBMB0: 0x00000000                               */
/* Register default value on SPRLCC: 0x00000000                                 */
/* Register default value on EMRXCC: 0x00000000                                 */
/* Register default value on SPRE0: 0x00000000                                  */
/* SPRA0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2             */
/* SPRB0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2             */
/* SPRHBMA0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2          */
/* SPRC0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2             */
/* SPRMCC Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2            */
/* SPRD0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2             */
/* SPRHBMB0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2          */
/* SPRLCC Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2            */
/* EMRXCC Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2            */
/* SPRE0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2             */
/* Struct generated from SPRA0 BDF: 30_0_2                                      */
/* SPRA0 Security PolicyGroup: OS_W                                             */
/* SPRB0 Security PolicyGroup: OS_W                                             */
/* SPRHBMA0 Security PolicyGroup: OS_W                                          */
/* SPRC0 Security PolicyGroup: OS_W                                             */
/* SPRMCC Security PolicyGroup: OS_W                                            */
/* SPRD0 Security PolicyGroup: OS_W                                             */
/* SPRHBMB0 Security PolicyGroup: OS_W                                          */
/* SPRLCC Security PolicyGroup: OS_W                                            */
/* EMRXCC Security PolicyGroup: OS_W                                            */
/* SPRE0 Security PolicyGroup: OS_W                                             */
/* unCore Semaphore register. Read Only register. Can be read only from FW. In a case that the apre-incremented value of the Tail counter equals to the value in the head counter, the tail counter will be really Atomically incremented and the requesting thread will get the semaphore ownershipe. In a case that the apre-incremented value of the Tail counter does notequal to the value in the head counter the TAIL counter, the thread will not get the ownershipe and the Tail counter valure will not be practically incremented.
*/


#define SYSTEMIMPAQUSEMP_1_UBOX_MISC_REG 0x1322019C

typedef union {
  ///
  /// Individual bit fields
  ///
  struct {
    UINT32 sempcurrtail : 16;

                            /* Bits[15:0], Access Type=RO/V, default=0x00000000*/

                            /*
                               Read from this field return pre-incremented
                               value of the Tail counter of the Semaphore. When
                               reading this field, the Tail counter is
                               incremented only if the requesting thread realy
                               recieved the semaphore ownership.
                            */
    UINT32 rsvd : 14;

                            /* Bits[29:16], Access Type=RO, default=None*/

                            /* Reserved */
    UINT32 sempowned : 1;

                            /* Bits[30:30], Access Type=RO/V, default=0x00000000*/

                            /*
                               Indicates that the thread that is currently
                               requesting for Semaphore ownership received it.
                               Aka return '1' if the apre-incremented value of
                               the Tail counter equals to the Head counter. If
                               the pre-incremented value of the tail equals to
                               the Head counter, that means that the order is
                               mess and the HW will signal a machine-check
                            */
    UINT32 rsvd_31 : 1;

                            /* Bits[31:31], Access Type=RO, default=None*/

                            /* Reserved */

  } Bits;
  UINT32 Data;

} SYSTEMIMPAQUSEMP_1_UBOX_MISC_STRUCT;

/* LOCALHEADSEMP_0_UBOX_MISC_REG supported on:                                  */
/*      SPRA0 (0x21e021a0)                                                      */
/*      SPRB0 (0x21e021a0)                                                      */
/*      SPRHBMA0 (0x21e021a0)                                                   */
/*      SPRC0 (0x21e021a0)                                                      */
/*      SPRMCC (0x21e021a0)                                                     */
/*      SPRD0 (0x21e021a0)                                                      */
/*      SPRHBMB0 (0x21e021a0)                                                   */
/*      SPRLCC (0x21e021a0)                                                     */
/*      EMRXCC (0x21e021a0)                                                     */
/*      SPRE0 (0x21e021a0)                                                      */
/* Register default value on SPRA0: 0x00000000                                  */
/* Register default value on SPRB0: 0x00000000                                  */
/* Register default value on SPRHBMA0: 0x00000000                               */
/* Register default value on SPRC0: 0x00000000                                  */
/* Register default value on SPRMCC: 0x00000000                                 */
/* Register default value on SPRD0: 0x00000000                                  */
/* Register default value on SPRHBMB0: 0x00000000                               */
/* Register default value on SPRLCC: 0x00000000                                 */
/* Register default value on EMRXCC: 0x00000000                                 */
/* Register default value on SPRE0: 0x00000000                                  */
/* SPRA0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2             */
/* SPRB0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2             */
/* SPRHBMA0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2          */
/* SPRC0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2             */
/* SPRMCC Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2            */
/* SPRD0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2             */
/* SPRHBMB0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2          */
/* SPRLCC Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2            */
/* EMRXCC Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2            */
/* SPRE0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2             */
/* Struct generated from SPRA0 BDF: 30_0_2                                      */
/* SPRA0 Security PolicyGroup: OS_W                                             */
/* SPRB0 Security PolicyGroup: OS_W                                             */
/* SPRHBMA0 Security PolicyGroup: OS_W                                          */
/* SPRC0 Security PolicyGroup: OS_W                                             */
/* SPRMCC Security PolicyGroup: OS_W                                            */
/* SPRD0 Security PolicyGroup: OS_W                                             */
/* SPRHBMB0 Security PolicyGroup: OS_W                                          */
/* SPRLCC Security PolicyGroup: OS_W                                            */
/* EMRXCC Security PolicyGroup: OS_W                                            */
/* SPRE0 Security PolicyGroup: OS_W                                             */
/* unCore Semaphore register. Read Only register. Can be read only from FW. Return the value of the Head counter of the Semaphore.
*/


#define LOCALHEADSEMP_0_UBOX_MISC_REG 0x132201A0

typedef union {
  ///
  /// Individual bit fields
  ///
  struct {
    UINT32 sempcurrhead : 16;

                            /* Bits[15:0], Access Type=RO/V, default=0x00000000*/

                            /*
                               Read from this field return the value of the
                               Head counter of the Semaphore.
                            */
    UINT32 rsvd : 16;

                            /* Bits[31:16], Access Type=RO, default=None*/

                            /* Reserved */

  } Bits;
  UINT32 Data;

} LOCALHEADSEMP_0_UBOX_MISC_STRUCT;

/* LOCALHEADSEMP_1_UBOX_MISC_REG supported on:                                  */
/*      SPRA0 (0x21e021a4)                                                      */
/*      SPRB0 (0x21e021a4)                                                      */
/*      SPRHBMA0 (0x21e021a4)                                                   */
/*      SPRC0 (0x21e021a4)                                                      */
/*      SPRMCC (0x21e021a4)                                                     */
/*      SPRD0 (0x21e021a4)                                                      */
/*      SPRHBMB0 (0x21e021a4)                                                   */
/*      SPRLCC (0x21e021a4)                                                     */
/*      EMRXCC (0x21e021a4)                                                     */
/*      SPRE0 (0x21e021a4)                                                      */
/* Register default value on SPRA0: 0x00000000                                  */
/* Register default value on SPRB0: 0x00000000                                  */
/* Register default value on SPRHBMA0: 0x00000000                               */
/* Register default value on SPRC0: 0x00000000                                  */
/* Register default value on SPRMCC: 0x00000000                                 */
/* Register default value on SPRD0: 0x00000000                                  */
/* Register default value on SPRHBMB0: 0x00000000                               */
/* Register default value on SPRLCC: 0x00000000                                 */
/* Register default value on EMRXCC: 0x00000000                                 */
/* Register default value on SPRE0: 0x00000000                                  */
/* SPRA0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2             */
/* SPRB0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2             */
/* SPRHBMA0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2          */
/* SPRC0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2             */
/* SPRMCC Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2            */
/* SPRD0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2             */
/* SPRHBMB0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2          */
/* SPRLCC Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2            */
/* EMRXCC Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2            */
/* SPRE0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2             */
/* Struct generated from SPRA0 BDF: 30_0_2                                      */
/* SPRA0 Security PolicyGroup: OS_W                                             */
/* SPRB0 Security PolicyGroup: OS_W                                             */
/* SPRHBMA0 Security PolicyGroup: OS_W                                          */
/* SPRC0 Security PolicyGroup: OS_W                                             */
/* SPRMCC Security PolicyGroup: OS_W                                            */
/* SPRD0 Security PolicyGroup: OS_W                                             */
/* SPRHBMB0 Security PolicyGroup: OS_W                                          */
/* SPRLCC Security PolicyGroup: OS_W                                            */
/* EMRXCC Security PolicyGroup: OS_W                                            */
/* SPRE0 Security PolicyGroup: OS_W                                             */
/* unCore Semaphore register. Read Only register. Can be read only from FW. Return the value of the Head counter of the Semaphore.
*/


#define LOCALHEADSEMP_1_UBOX_MISC_REG 0x132201A4

typedef union {
  ///
  /// Individual bit fields
  ///
  struct {
    UINT32 sempcurrhead : 16;

                            /* Bits[15:0], Access Type=RO/V, default=0x00000000*/

                            /*
                               Read from this field return the value of the
                               Head counter of the Semaphore.
                            */
    UINT32 rsvd : 16;

                            /* Bits[31:16], Access Type=RO, default=None*/

                            /* Reserved */

  } Bits;
  UINT32 Data;

} LOCALHEADSEMP_1_UBOX_MISC_STRUCT;

/* SYSTEMHEADSEMP_0_UBOX_MISC_REG supported on:                                 */
/*      SPRA0 (0x21e021a8)                                                      */
/*      SPRB0 (0x21e021a8)                                                      */
/*      SPRHBMA0 (0x21e021a8)                                                   */
/*      SPRC0 (0x21e021a8)                                                      */
/*      SPRMCC (0x21e021a8)                                                     */
/*      SPRD0 (0x21e021a8)                                                      */
/*      SPRHBMB0 (0x21e021a8)                                                   */
/*      SPRLCC (0x21e021a8)                                                     */
/*      EMRXCC (0x21e021a8)                                                     */
/*      SPRE0 (0x21e021a8)                                                      */
/* Register default value on SPRA0: 0x00000000                                  */
/* Register default value on SPRB0: 0x00000000                                  */
/* Register default value on SPRHBMA0: 0x00000000                               */
/* Register default value on SPRC0: 0x00000000                                  */
/* Register default value on SPRMCC: 0x00000000                                 */
/* Register default value on SPRD0: 0x00000000                                  */
/* Register default value on SPRHBMB0: 0x00000000                               */
/* Register default value on SPRLCC: 0x00000000                                 */
/* Register default value on EMRXCC: 0x00000000                                 */
/* Register default value on SPRE0: 0x00000000                                  */
/* SPRA0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2             */
/* SPRB0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2             */
/* SPRHBMA0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2          */
/* SPRC0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2             */
/* SPRMCC Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2            */
/* SPRD0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2             */
/* SPRHBMB0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2          */
/* SPRLCC Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2            */
/* EMRXCC Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2            */
/* SPRE0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2             */
/* Struct generated from SPRA0 BDF: 30_0_2                                      */
/* SPRA0 Security PolicyGroup: OS_W                                             */
/* SPRB0 Security PolicyGroup: OS_W                                             */
/* SPRHBMA0 Security PolicyGroup: OS_W                                          */
/* SPRC0 Security PolicyGroup: OS_W                                             */
/* SPRMCC Security PolicyGroup: OS_W                                            */
/* SPRD0 Security PolicyGroup: OS_W                                             */
/* SPRHBMB0 Security PolicyGroup: OS_W                                          */
/* SPRLCC Security PolicyGroup: OS_W                                            */
/* EMRXCC Security PolicyGroup: OS_W                                            */
/* SPRE0 Security PolicyGroup: OS_W                                             */
/* unCore Semaphore register. Read Only register. Can be read only from FW. Return the value of the Head counter of the Semaphore.
*/


#define SYSTEMHEADSEMP_0_UBOX_MISC_REG 0x132201A8

typedef union {
  ///
  /// Individual bit fields
  ///
  struct {
    UINT32 sempcurrhead : 16;

                            /* Bits[15:0], Access Type=RO/V, default=0x00000000*/

                            /*
                               Read from this field return the value of the
                               Head counter of the Semaphore.
                            */
    UINT32 rsvd : 16;

                            /* Bits[31:16], Access Type=RO, default=None*/

                            /* Reserved */

  } Bits;
  UINT32 Data;

} SYSTEMHEADSEMP_0_UBOX_MISC_STRUCT;

/* SYSTEMHEADSEMP_1_UBOX_MISC_REG supported on:                                 */
/*      SPRA0 (0x21e021ac)                                                      */
/*      SPRB0 (0x21e021ac)                                                      */
/*      SPRHBMA0 (0x21e021ac)                                                   */
/*      SPRC0 (0x21e021ac)                                                      */
/*      SPRMCC (0x21e021ac)                                                     */
/*      SPRD0 (0x21e021ac)                                                      */
/*      SPRHBMB0 (0x21e021ac)                                                   */
/*      SPRLCC (0x21e021ac)                                                     */
/*      EMRXCC (0x21e021ac)                                                     */
/*      SPRE0 (0x21e021ac)                                                      */
/* Register default value on SPRA0: 0x00000000                                  */
/* Register default value on SPRB0: 0x00000000                                  */
/* Register default value on SPRHBMA0: 0x00000000                               */
/* Register default value on SPRC0: 0x00000000                                  */
/* Register default value on SPRMCC: 0x00000000                                 */
/* Register default value on SPRD0: 0x00000000                                  */
/* Register default value on SPRHBMB0: 0x00000000                               */
/* Register default value on SPRLCC: 0x00000000                                 */
/* Register default value on EMRXCC: 0x00000000                                 */
/* Register default value on SPRE0: 0x00000000                                  */
/* SPRA0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2             */
/* SPRB0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2             */
/* SPRHBMA0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2          */
/* SPRC0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2             */
/* SPRMCC Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2            */
/* SPRD0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2             */
/* SPRHBMB0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2          */
/* SPRLCC Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2            */
/* EMRXCC Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2            */
/* SPRE0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2             */
/* Struct generated from SPRA0 BDF: 30_0_2                                      */
/* SPRA0 Security PolicyGroup: OS_W                                             */
/* SPRB0 Security PolicyGroup: OS_W                                             */
/* SPRHBMA0 Security PolicyGroup: OS_W                                          */
/* SPRC0 Security PolicyGroup: OS_W                                             */
/* SPRMCC Security PolicyGroup: OS_W                                            */
/* SPRD0 Security PolicyGroup: OS_W                                             */
/* SPRHBMB0 Security PolicyGroup: OS_W                                          */
/* SPRLCC Security PolicyGroup: OS_W                                            */
/* EMRXCC Security PolicyGroup: OS_W                                            */
/* SPRE0 Security PolicyGroup: OS_W                                             */
/* unCore Semaphore register. Read Only register. Can be read only from FW. Return the value of the Head counter of the Semaphore.
*/


#define SYSTEMHEADSEMP_1_UBOX_MISC_REG 0x132201AC

typedef union {
  ///
  /// Individual bit fields
  ///
  struct {
    UINT32 sempcurrhead : 16;

                            /* Bits[15:0], Access Type=RO/V, default=0x00000000*/

                            /*
                               Read from this field return the value of the
                               Head counter of the Semaphore.
                            */
    UINT32 rsvd : 16;

                            /* Bits[31:16], Access Type=RO, default=None*/

                            /* Reserved */

  } Bits;
  UINT32 Data;

} SYSTEMHEADSEMP_1_UBOX_MISC_STRUCT;

/* LOCALTAILSEMP_0_UBOX_MISC_REG supported on:                                  */
/*      SPRA0 (0x21e021b0)                                                      */
/*      SPRB0 (0x21e021b0)                                                      */
/*      SPRHBMA0 (0x21e021b0)                                                   */
/*      SPRC0 (0x21e021b0)                                                      */
/*      SPRMCC (0x21e021b0)                                                     */
/*      SPRD0 (0x21e021b0)                                                      */
/*      SPRHBMB0 (0x21e021b0)                                                   */
/*      SPRLCC (0x21e021b0)                                                     */
/*      EMRXCC (0x21e021b0)                                                     */
/*      SPRE0 (0x21e021b0)                                                      */
/* Register default value on SPRA0: 0x00000000                                  */
/* Register default value on SPRB0: 0x00000000                                  */
/* Register default value on SPRHBMA0: 0x00000000                               */
/* Register default value on SPRC0: 0x00000000                                  */
/* Register default value on SPRMCC: 0x00000000                                 */
/* Register default value on SPRD0: 0x00000000                                  */
/* Register default value on SPRHBMB0: 0x00000000                               */
/* Register default value on SPRLCC: 0x00000000                                 */
/* Register default value on EMRXCC: 0x00000000                                 */
/* Register default value on SPRE0: 0x00000000                                  */
/* SPRA0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2             */
/* SPRB0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2             */
/* SPRHBMA0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2          */
/* SPRC0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2             */
/* SPRMCC Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2            */
/* SPRD0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2             */
/* SPRHBMB0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2          */
/* SPRLCC Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2            */
/* EMRXCC Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2            */
/* SPRE0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2             */
/* Struct generated from SPRA0 BDF: 30_0_2                                      */
/* SPRA0 Security PolicyGroup: OS_W                                             */
/* SPRB0 Security PolicyGroup: OS_W                                             */
/* SPRHBMA0 Security PolicyGroup: OS_W                                          */
/* SPRC0 Security PolicyGroup: OS_W                                             */
/* SPRMCC Security PolicyGroup: OS_W                                            */
/* SPRD0 Security PolicyGroup: OS_W                                             */
/* SPRHBMB0 Security PolicyGroup: OS_W                                          */
/* SPRLCC Security PolicyGroup: OS_W                                            */
/* EMRXCC Security PolicyGroup: OS_W                                            */
/* SPRE0 Security PolicyGroup: OS_W                                             */
/* unCore Semaphore register. Read Only register. Can be read only from FW. Return the value of the Tail counter of the Semaphore.
*/


#define LOCALTAILSEMP_0_UBOX_MISC_REG 0x132201B0

typedef union {
  ///
  /// Individual bit fields
  ///
  struct {
    UINT32 sempcurrtail : 16;

                            /* Bits[15:0], Access Type=RO/V, default=0x00000000*/

                            /*
                               Read from this field return the value of the
                               Tail counter of the Semaphore.
                            */
    UINT32 rsvd : 16;

                            /* Bits[31:16], Access Type=RO, default=None*/

                            /* Reserved */

  } Bits;
  UINT32 Data;

} LOCALTAILSEMP_0_UBOX_MISC_STRUCT;

/* LOCALTAILSEMP_1_UBOX_MISC_REG supported on:                                  */
/*      SPRA0 (0x21e021b4)                                                      */
/*      SPRB0 (0x21e021b4)                                                      */
/*      SPRHBMA0 (0x21e021b4)                                                   */
/*      SPRC0 (0x21e021b4)                                                      */
/*      SPRMCC (0x21e021b4)                                                     */
/*      SPRD0 (0x21e021b4)                                                      */
/*      SPRHBMB0 (0x21e021b4)                                                   */
/*      SPRLCC (0x21e021b4)                                                     */
/*      EMRXCC (0x21e021b4)                                                     */
/*      SPRE0 (0x21e021b4)                                                      */
/* Register default value on SPRA0: 0x00000000                                  */
/* Register default value on SPRB0: 0x00000000                                  */
/* Register default value on SPRHBMA0: 0x00000000                               */
/* Register default value on SPRC0: 0x00000000                                  */
/* Register default value on SPRMCC: 0x00000000                                 */
/* Register default value on SPRD0: 0x00000000                                  */
/* Register default value on SPRHBMB0: 0x00000000                               */
/* Register default value on SPRLCC: 0x00000000                                 */
/* Register default value on EMRXCC: 0x00000000                                 */
/* Register default value on SPRE0: 0x00000000                                  */
/* SPRA0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2             */
/* SPRB0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2             */
/* SPRHBMA0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2          */
/* SPRC0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2             */
/* SPRMCC Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2            */
/* SPRD0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2             */
/* SPRHBMB0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2          */
/* SPRLCC Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2            */
/* EMRXCC Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2            */
/* SPRE0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2             */
/* Struct generated from SPRA0 BDF: 30_0_2                                      */
/* SPRA0 Security PolicyGroup: OS_W                                             */
/* SPRB0 Security PolicyGroup: OS_W                                             */
/* SPRHBMA0 Security PolicyGroup: OS_W                                          */
/* SPRC0 Security PolicyGroup: OS_W                                             */
/* SPRMCC Security PolicyGroup: OS_W                                            */
/* SPRD0 Security PolicyGroup: OS_W                                             */
/* SPRHBMB0 Security PolicyGroup: OS_W                                          */
/* SPRLCC Security PolicyGroup: OS_W                                            */
/* EMRXCC Security PolicyGroup: OS_W                                            */
/* SPRE0 Security PolicyGroup: OS_W                                             */
/* unCore Semaphore register. Read Only register. Can be read only from FW. Return the value of the Tail counter of the Semaphore.
*/


#define LOCALTAILSEMP_1_UBOX_MISC_REG 0x132201B4

typedef union {
  ///
  /// Individual bit fields
  ///
  struct {
    UINT32 sempcurrtail : 16;

                            /* Bits[15:0], Access Type=RO/V, default=0x00000000*/

                            /*
                               Read from this field return the value of the
                               Tail counter of the Semaphore.
                            */
    UINT32 rsvd : 16;

                            /* Bits[31:16], Access Type=RO, default=None*/

                            /* Reserved */

  } Bits;
  UINT32 Data;

} LOCALTAILSEMP_1_UBOX_MISC_STRUCT;

/* SYSTEMTAILSEMP_0_UBOX_MISC_REG supported on:                                 */
/*      SPRA0 (0x21e021b8)                                                      */
/*      SPRB0 (0x21e021b8)                                                      */
/*      SPRHBMA0 (0x21e021b8)                                                   */
/*      SPRC0 (0x21e021b8)                                                      */
/*      SPRMCC (0x21e021b8)                                                     */
/*      SPRD0 (0x21e021b8)                                                      */
/*      SPRHBMB0 (0x21e021b8)                                                   */
/*      SPRLCC (0x21e021b8)                                                     */
/*      EMRXCC (0x21e021b8)                                                     */
/*      SPRE0 (0x21e021b8)                                                      */
/* Register default value on SPRA0: 0x00000000                                  */
/* Register default value on SPRB0: 0x00000000                                  */
/* Register default value on SPRHBMA0: 0x00000000                               */
/* Register default value on SPRC0: 0x00000000                                  */
/* Register default value on SPRMCC: 0x00000000                                 */
/* Register default value on SPRD0: 0x00000000                                  */
/* Register default value on SPRHBMB0: 0x00000000                               */
/* Register default value on SPRLCC: 0x00000000                                 */
/* Register default value on EMRXCC: 0x00000000                                 */
/* Register default value on SPRE0: 0x00000000                                  */
/* SPRA0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2             */
/* SPRB0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2             */
/* SPRHBMA0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2          */
/* SPRC0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2             */
/* SPRMCC Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2            */
/* SPRD0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2             */
/* SPRHBMB0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2          */
/* SPRLCC Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2            */
/* EMRXCC Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2            */
/* SPRE0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2             */
/* Struct generated from SPRA0 BDF: 30_0_2                                      */
/* SPRA0 Security PolicyGroup: OS_W                                             */
/* SPRB0 Security PolicyGroup: OS_W                                             */
/* SPRHBMA0 Security PolicyGroup: OS_W                                          */
/* SPRC0 Security PolicyGroup: OS_W                                             */
/* SPRMCC Security PolicyGroup: OS_W                                            */
/* SPRD0 Security PolicyGroup: OS_W                                             */
/* SPRHBMB0 Security PolicyGroup: OS_W                                          */
/* SPRLCC Security PolicyGroup: OS_W                                            */
/* EMRXCC Security PolicyGroup: OS_W                                            */
/* SPRE0 Security PolicyGroup: OS_W                                             */
/* unCore Semaphore register. Read Only register. Can be read only from FW. Return the value of the Tail counter of the Semaphore.
*/


#define SYSTEMTAILSEMP_0_UBOX_MISC_REG 0x132201B8

typedef union {
  ///
  /// Individual bit fields
  ///
  struct {
    UINT32 sempcurrtail : 16;

                            /* Bits[15:0], Access Type=RO/V, default=0x00000000*/

                            /*
                               Read from this field return the value of the
                               Tail counter of the Semaphore.
                            */
    UINT32 rsvd : 16;

                            /* Bits[31:16], Access Type=RO, default=None*/

                            /* Reserved */

  } Bits;
  UINT32 Data;

} SYSTEMTAILSEMP_0_UBOX_MISC_STRUCT;

/* SYSTEMTAILSEMP_1_UBOX_MISC_REG supported on:                                 */
/*      SPRA0 (0x21e021bc)                                                      */
/*      SPRB0 (0x21e021bc)                                                      */
/*      SPRHBMA0 (0x21e021bc)                                                   */
/*      SPRC0 (0x21e021bc)                                                      */
/*      SPRMCC (0x21e021bc)                                                     */
/*      SPRD0 (0x21e021bc)                                                      */
/*      SPRHBMB0 (0x21e021bc)                                                   */
/*      SPRLCC (0x21e021bc)                                                     */
/*      EMRXCC (0x21e021bc)                                                     */
/*      SPRE0 (0x21e021bc)                                                      */
/* Register default value on SPRA0: 0x00000000                                  */
/* Register default value on SPRB0: 0x00000000                                  */
/* Register default value on SPRHBMA0: 0x00000000                               */
/* Register default value on SPRC0: 0x00000000                                  */
/* Register default value on SPRMCC: 0x00000000                                 */
/* Register default value on SPRD0: 0x00000000                                  */
/* Register default value on SPRHBMB0: 0x00000000                               */
/* Register default value on SPRLCC: 0x00000000                                 */
/* Register default value on EMRXCC: 0x00000000                                 */
/* Register default value on SPRE0: 0x00000000                                  */
/* SPRA0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2             */
/* SPRB0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2             */
/* SPRHBMA0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2          */
/* SPRC0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2             */
/* SPRMCC Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2            */
/* SPRD0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2             */
/* SPRHBMB0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2          */
/* SPRLCC Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2            */
/* EMRXCC Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2            */
/* SPRE0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2             */
/* Struct generated from SPRA0 BDF: 30_0_2                                      */
/* SPRA0 Security PolicyGroup: OS_W                                             */
/* SPRB0 Security PolicyGroup: OS_W                                             */
/* SPRHBMA0 Security PolicyGroup: OS_W                                          */
/* SPRC0 Security PolicyGroup: OS_W                                             */
/* SPRMCC Security PolicyGroup: OS_W                                            */
/* SPRD0 Security PolicyGroup: OS_W                                             */
/* SPRHBMB0 Security PolicyGroup: OS_W                                          */
/* SPRLCC Security PolicyGroup: OS_W                                            */
/* EMRXCC Security PolicyGroup: OS_W                                            */
/* SPRE0 Security PolicyGroup: OS_W                                             */
/* unCore Semaphore register. Read Only register. Can be read only from FW. Return the value of the Tail counter of the Semaphore.
*/


#define SYSTEMTAILSEMP_1_UBOX_MISC_REG 0x132201BC

typedef union {
  ///
  /// Individual bit fields
  ///
  struct {
    UINT32 sempcurrtail : 16;

                            /* Bits[15:0], Access Type=RO/V, default=0x00000000*/

                            /*
                               Read from this field return the value of the
                               Tail counter of the Semaphore.
                            */
    UINT32 rsvd : 16;

                            /* Bits[31:16], Access Type=RO, default=None*/

                            /* Reserved */

  } Bits;
  UINT32 Data;

} SYSTEMTAILSEMP_1_UBOX_MISC_STRUCT;

/* LOCALRELEASESEMP_0_UBOX_MISC_REG supported on:                               */
/*      SPRA0 (0x21e021c0)                                                      */
/*      SPRB0 (0x21e021c0)                                                      */
/*      SPRHBMA0 (0x21e021c0)                                                   */
/*      SPRC0 (0x21e021c0)                                                      */
/*      SPRMCC (0x21e021c0)                                                     */
/*      SPRD0 (0x21e021c0)                                                      */
/*      SPRHBMB0 (0x21e021c0)                                                   */
/*      SPRLCC (0x21e021c0)                                                     */
/*      EMRXCC (0x21e021c0)                                                     */
/*      SPRE0 (0x21e021c0)                                                      */
/* Register default value on SPRA0: 0x00000000                                  */
/* Register default value on SPRB0: 0x00000000                                  */
/* Register default value on SPRHBMA0: 0x00000000                               */
/* Register default value on SPRC0: 0x00000000                                  */
/* Register default value on SPRMCC: 0x00000000                                 */
/* Register default value on SPRD0: 0x00000000                                  */
/* Register default value on SPRHBMB0: 0x00000000                               */
/* Register default value on SPRLCC: 0x00000000                                 */
/* Register default value on EMRXCC: 0x00000000                                 */
/* Register default value on SPRE0: 0x00000000                                  */
/* SPRA0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2             */
/* SPRB0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2             */
/* SPRHBMA0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2          */
/* SPRC0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2             */
/* SPRMCC Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2            */
/* SPRD0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2             */
/* SPRHBMB0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2          */
/* SPRLCC Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2            */
/* EMRXCC Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2            */
/* SPRE0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2             */
/* Struct generated from SPRA0 BDF: 30_0_2                                      */
/* SPRA0 Security PolicyGroup: OS_W                                             */
/* SPRB0 Security PolicyGroup: OS_W                                             */
/* SPRHBMA0 Security PolicyGroup: OS_W                                          */
/* SPRC0 Security PolicyGroup: OS_W                                             */
/* SPRMCC Security PolicyGroup: OS_W                                            */
/* SPRD0 Security PolicyGroup: OS_W                                             */
/* SPRHBMB0 Security PolicyGroup: OS_W                                          */
/* SPRLCC Security PolicyGroup: OS_W                                            */
/* EMRXCC Security PolicyGroup: OS_W                                            */
/* SPRE0 Security PolicyGroup: OS_W                                             */
/* unCore Semaphore register. Write Only register. Can be written only from FW. If a release is requested and the VALUE being released matches the current SEMx_HEAD_VAL (i.e. the release matches the current ownership), the semaphore is released by atomically incrementing the HEAD value.
Any other release request is an error and should signal a machine check.
 
*/


#define LOCALRELEASESEMP_0_UBOX_MISC_REG 0x132201C0

typedef union {
  ///
  /// Individual bit fields
  ///
  struct {
    UINT32 sempreleasevalue : 16;

                            /* Bits[15:0], Access Type=WO, default=0x00000000*/

                            /*
                               The Value which is written to this filed is
                               compared with the current head. If it matches,
                               that means that the release matches the current
                               ownership, and the Head counter value is
                               incremented. If not, the release request is an
                               error and should signal a machine check
                            */
    UINT32 rsvd : 16;

                            /* Bits[31:16], Access Type=RO, default=None*/

                            /* Reserved */

  } Bits;
  UINT32 Data;

} LOCALRELEASESEMP_0_UBOX_MISC_STRUCT;

/* LOCALRELEASESEMP_1_UBOX_MISC_REG supported on:                               */
/*      SPRA0 (0x21e021c4)                                                      */
/*      SPRB0 (0x21e021c4)                                                      */
/*      SPRHBMA0 (0x21e021c4)                                                   */
/*      SPRC0 (0x21e021c4)                                                      */
/*      SPRMCC (0x21e021c4)                                                     */
/*      SPRD0 (0x21e021c4)                                                      */
/*      SPRHBMB0 (0x21e021c4)                                                   */
/*      SPRLCC (0x21e021c4)                                                     */
/*      EMRXCC (0x21e021c4)                                                     */
/*      SPRE0 (0x21e021c4)                                                      */
/* Register default value on SPRA0: 0x00000000                                  */
/* Register default value on SPRB0: 0x00000000                                  */
/* Register default value on SPRHBMA0: 0x00000000                               */
/* Register default value on SPRC0: 0x00000000                                  */
/* Register default value on SPRMCC: 0x00000000                                 */
/* Register default value on SPRD0: 0x00000000                                  */
/* Register default value on SPRHBMB0: 0x00000000                               */
/* Register default value on SPRLCC: 0x00000000                                 */
/* Register default value on EMRXCC: 0x00000000                                 */
/* Register default value on SPRE0: 0x00000000                                  */
/* SPRA0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2             */
/* SPRB0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2             */
/* SPRHBMA0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2          */
/* SPRC0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2             */
/* SPRMCC Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2            */
/* SPRD0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2             */
/* SPRHBMB0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2          */
/* SPRLCC Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2            */
/* EMRXCC Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2            */
/* SPRE0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2             */
/* Struct generated from SPRA0 BDF: 30_0_2                                      */
/* SPRA0 Security PolicyGroup: OS_W                                             */
/* SPRB0 Security PolicyGroup: OS_W                                             */
/* SPRHBMA0 Security PolicyGroup: OS_W                                          */
/* SPRC0 Security PolicyGroup: OS_W                                             */
/* SPRMCC Security PolicyGroup: OS_W                                            */
/* SPRD0 Security PolicyGroup: OS_W                                             */
/* SPRHBMB0 Security PolicyGroup: OS_W                                          */
/* SPRLCC Security PolicyGroup: OS_W                                            */
/* EMRXCC Security PolicyGroup: OS_W                                            */
/* SPRE0 Security PolicyGroup: OS_W                                             */
/* unCore Semaphore register. Write Only register. Can be written only from FW. If a release is requested and the VALUE being released matches the current SEMx_HEAD_VAL (i.e. the release matches the current ownership), the semaphore is released by atomically incrementing the HEAD value.
Any other release request is an error and should signal a machine check.
 
*/


#define LOCALRELEASESEMP_1_UBOX_MISC_REG 0x132201C4

typedef union {
  ///
  /// Individual bit fields
  ///
  struct {
    UINT32 sempreleasevalue : 16;

                            /* Bits[15:0], Access Type=WO, default=0x00000000*/

                            /*
                               The Value which is written to this filed is
                               compared with the current head. If it matches,
                               that means that the release matches the current
                               ownership, and the Head counter value is
                               incremented. If not, the release request is an
                               error and should signal a machine check
                            */
    UINT32 rsvd : 16;

                            /* Bits[31:16], Access Type=RO, default=None*/

                            /* Reserved */

  } Bits;
  UINT32 Data;

} LOCALRELEASESEMP_1_UBOX_MISC_STRUCT;

/* SYSTEMRELEASESEMP_0_UBOX_MISC_REG supported on:                              */
/*      SPRA0 (0x21e021c8)                                                      */
/*      SPRB0 (0x21e021c8)                                                      */
/*      SPRHBMA0 (0x21e021c8)                                                   */
/*      SPRC0 (0x21e021c8)                                                      */
/*      SPRMCC (0x21e021c8)                                                     */
/*      SPRD0 (0x21e021c8)                                                      */
/*      SPRHBMB0 (0x21e021c8)                                                   */
/*      SPRLCC (0x21e021c8)                                                     */
/*      EMRXCC (0x21e021c8)                                                     */
/*      SPRE0 (0x21e021c8)                                                      */
/* Register default value on SPRA0: 0x00000000                                  */
/* Register default value on SPRB0: 0x00000000                                  */
/* Register default value on SPRHBMA0: 0x00000000                               */
/* Register default value on SPRC0: 0x00000000                                  */
/* Register default value on SPRMCC: 0x00000000                                 */
/* Register default value on SPRD0: 0x00000000                                  */
/* Register default value on SPRHBMB0: 0x00000000                               */
/* Register default value on SPRLCC: 0x00000000                                 */
/* Register default value on EMRXCC: 0x00000000                                 */
/* Register default value on SPRE0: 0x00000000                                  */
/* SPRA0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2             */
/* SPRB0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2             */
/* SPRHBMA0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2          */
/* SPRC0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2             */
/* SPRMCC Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2            */
/* SPRD0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2             */
/* SPRHBMB0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2          */
/* SPRLCC Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2            */
/* EMRXCC Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2            */
/* SPRE0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2             */
/* Struct generated from SPRA0 BDF: 30_0_2                                      */
/* SPRA0 Security PolicyGroup: OS_W                                             */
/* SPRB0 Security PolicyGroup: OS_W                                             */
/* SPRHBMA0 Security PolicyGroup: OS_W                                          */
/* SPRC0 Security PolicyGroup: OS_W                                             */
/* SPRMCC Security PolicyGroup: OS_W                                            */
/* SPRD0 Security PolicyGroup: OS_W                                             */
/* SPRHBMB0 Security PolicyGroup: OS_W                                          */
/* SPRLCC Security PolicyGroup: OS_W                                            */
/* EMRXCC Security PolicyGroup: OS_W                                            */
/* SPRE0 Security PolicyGroup: OS_W                                             */
/* unCore Semaphore register. Write Only register. Can be written only from FW. If a release is requested and the VALUE being released matches the current SEMx_HEAD_VAL (i.e. the release matches the current ownership), the semaphore is released by atomically incrementing the HEAD value.
Any other release request is an error and should signal a machine check.
 
*/


#define SYSTEMRELEASESEMP_0_UBOX_MISC_REG 0x132201C8

typedef union {
  ///
  /// Individual bit fields
  ///
  struct {
    UINT32 sempreleasevalue : 16;

                            /* Bits[15:0], Access Type=WO, default=0x00000000*/

                            /*
                               The Value which is written to this filed is
                               compared with the current head. If it matches,
                               that means that the release matches the current
                               ownership, and the Head counter value is
                               incremented. If not, the release request is an
                               error and should signal a machine check
                            */
    UINT32 rsvd : 16;

                            /* Bits[31:16], Access Type=RO, default=None*/

                            /* Reserved */

  } Bits;
  UINT32 Data;

} SYSTEMRELEASESEMP_0_UBOX_MISC_STRUCT;

/* SYSTEMRELEASESEMP_1_UBOX_MISC_REG supported on:                              */
/*      SPRA0 (0x21e021cc)                                                      */
/*      SPRB0 (0x21e021cc)                                                      */
/*      SPRHBMA0 (0x21e021cc)                                                   */
/*      SPRC0 (0x21e021cc)                                                      */
/*      SPRMCC (0x21e021cc)                                                     */
/*      SPRD0 (0x21e021cc)                                                      */
/*      SPRHBMB0 (0x21e021cc)                                                   */
/*      SPRLCC (0x21e021cc)                                                     */
/*      EMRXCC (0x21e021cc)                                                     */
/*      SPRE0 (0x21e021cc)                                                      */
/* Register default value on SPRA0: 0x00000000                                  */
/* Register default value on SPRB0: 0x00000000                                  */
/* Register default value on SPRHBMA0: 0x00000000                               */
/* Register default value on SPRC0: 0x00000000                                  */
/* Register default value on SPRMCC: 0x00000000                                 */
/* Register default value on SPRD0: 0x00000000                                  */
/* Register default value on SPRHBMB0: 0x00000000                               */
/* Register default value on SPRLCC: 0x00000000                                 */
/* Register default value on EMRXCC: 0x00000000                                 */
/* Register default value on SPRE0: 0x00000000                                  */
/* SPRA0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2             */
/* SPRB0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2             */
/* SPRHBMA0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2          */
/* SPRC0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2             */
/* SPRMCC Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2            */
/* SPRD0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2             */
/* SPRHBMB0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2          */
/* SPRLCC Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2            */
/* EMRXCC Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2            */
/* SPRE0 Register File:    sprsp_top/ubox/ncdecs/ncdecs/CFG_UBOX_F2             */
/* Struct generated from SPRA0 BDF: 30_0_2                                      */
/* SPRA0 Security PolicyGroup: OS_W                                             */
/* SPRB0 Security PolicyGroup: OS_W                                             */
/* SPRHBMA0 Security PolicyGroup: OS_W                                          */
/* SPRC0 Security PolicyGroup: OS_W                                             */
/* SPRMCC Security PolicyGroup: OS_W                                            */
/* SPRD0 Security PolicyGroup: OS_W                                             */
/* SPRHBMB0 Security PolicyGroup: OS_W                                          */
/* SPRLCC Security PolicyGroup: OS_W                                            */
/* EMRXCC Security PolicyGroup: OS_W                                            */
/* SPRE0 Security PolicyGroup: OS_W                                             */
/* unCore Semaphore register. Write Only register. Can be written only from FW. If a release is requested and the VALUE being released matches the current SEMx_HEAD_VAL (i.e. the release matches the current ownership), the semaphore is released by atomically incrementing the HEAD value.
Any other release request is an error and should signal a machine check.
 
*/


#define SYSTEMRELEASESEMP_1_UBOX_MISC_REG 0x132201CC

typedef union {
  ///
  /// Individual bit fields
  ///
  struct {
    UINT32 sempreleasevalue : 16;

                            /* Bits[15:0], Access Type=WO, default=0x00000000*/

                            /*
                               The Value which is written to this filed is
                               compared with the current head. If it matches,
                               that means that the release matches the current
                               ownership, and the Head counter value is
                               incremented. If not, the release request is an
                               error and should signal a machine check
                            */
    UINT32 rsvd : 16;

                            /* Bits[31:16], Access Type=RO, default=None*/

                            /* Reserved */

  } Bits;
  UINT32 Data;

} SYSTEMRELEASESEMP_1_UBOX_MISC_STRUCT;

/* NCDECS_CR_SIDEBAND_ABORT_0_UBOX_MISC_REG supported on:                       */
/*      SPRA0 (0x21e021f0)                                                      */
/*      SPRB0 (0x21e021f0)                                                      */
/*      SPRHBMA0 (0x21e021f0)                                                   */
/*      SPRC0 (0x21e021f0)                                                      */
/*      SPRMCC (0x21e021f0)                                                     */
/*      SPRD0 (0x21e021f0)                                                      */
/*      SPRHBMB0 (0x21e021f0)                                                   */
/*      SPRLCC (0x21e021f0)                                                     */
/*      EMRXCC (0x21e021f0)                                                     */
/*      SPRE0 (0x21e021f0)                                                      */
/* Register default value on SPRA0: 0x00000000                                  */
/* Register default value on SPRB0: 0x00000000                                  */
/* Register default value on SPRHBMA0: 0x00000000                               */
/* Register default value on SPRC0: 0x00000000                                  */
/* Register default value on SPRMCC: 0x00000000                                 */
/* Register default value on SPRD0: 0x00000000                                  */
/* Register default value on SPRHBMB0: 0x00000000                               */
/* Register default value on SPRLCC: 0x00000000                                 */
/* Register default value on EMRXCC: 0x00000000                                 */
/* Register default value on SPRE0: 0x00000000                                  */
/* SPRA0 Register File:    sprsp_top/ubox/ncuracu/ncuracu/NCURACU_CFG_UBOX_F2_MSG_UBOX_F2*/
/* SPRB0 Register File:    sprsp_top/ubox/ncuracu/ncuracu/NCURACU_CFG_UBOX_F2_MSG_UBOX_F2*/
/* SPRHBMA0 Register File:    sprsp_top/ubox/ncuracu/ncuracu/NCURACU_CFG_UBOX_F2_MSG_UBOX_F2*/
/* SPRC0 Register File:    sprsp_top/ubox/ncuracu/ncuracu/NCURACU_CFG_UBOX_F2_MSG_UBOX_F2*/
/* SPRMCC Register File:    sprsp_top/ubox/ncuracu/ncuracu/NCURACU_CFG_UBOX_F2_MSG_UBOX_F2*/
/* SPRD0 Register File:    sprsp_top/ubox/ncuracu/ncuracu/NCURACU_CFG_UBOX_F2_MSG_UBOX_F2*/
/* SPRHBMB0 Register File:    sprsp_top/ubox/ncuracu/ncuracu/NCURACU_CFG_UBOX_F2_MSG_UBOX_F2*/
/* SPRLCC Register File:    sprsp_top/ubox/ncuracu/ncuracu/NCURACU_CFG_UBOX_F2_MSG_UBOX_F2*/
/* EMRXCC Register File:    sprsp_top/ubox/ncuracu/ncuracu/NCURACU_CFG_UBOX_F2_MSG_UBOX_F2*/
/* SPRE0 Register File:    sprsp_top/ubox/ncuracu/ncuracu/NCURACU_CFG_UBOX_F2_MSG_UBOX_F2*/
/* Struct generated from SPRA0 BDF: 30_0_2                                      */
/* SPRA0 Security PolicyGroup: LB_W                                             */
/* SPRB0 Security PolicyGroup: LB_W                                             */
/* SPRHBMA0 Security PolicyGroup: LB_W                                          */
/* SPRC0 Security PolicyGroup: LB_W                                             */
/* SPRMCC Security PolicyGroup: LB_W                                            */
/* SPRD0 Security PolicyGroup: LB_W                                             */
/* SPRHBMB0 Security PolicyGroup: LB_W                                          */
/* SPRLCC Security PolicyGroup: LB_W                                            */
/* EMRXCC Security PolicyGroup: LB_W                                            */
/* SPRE0 Security PolicyGroup: LB_W                                             */
/* Register loaded when Unsuccessful response is received
*/


#define NCDECS_CR_SIDEBAND_ABORT_0_UBOX_MISC_REG 0x132201F0

typedef union {
  ///
  /// Individual bit fields
  ///
  struct {
    UINT32 valid : 1;

                            /* Bits[0:0], Access Type=RW/V/P, default=0x00000000*/

                            /* Values captured in the Abort register are valid */
    UINT32 rsp : 2;

                            /* Bits[2:1], Access Type=RO/V, default=0x00000000*/

                            /* Completion Status Received */
    UINT32 rsvd : 5;

                            /* Bits[7:3], Access Type=RO, default=None*/

                            /* Reserved */
    UINT32 source_portid : 10;

                            /* Bits[17:8], Access Type=RO/V, default=0x00000000*/

                            /* Port ID of Sender from Completion */
    UINT32 dest_portid : 10;

                            /* Bits[27:18], Access Type=RO/V, default=0x00000000*/

                            /* Dest PortID of the request */
    UINT32 rsvd_28 : 4;

                            /* Bits[31:28], Access Type=RO, default=None*/

                            /* Reserved */

  } Bits;
  UINT32 Data;

} NCDECS_CR_SIDEBAND_ABORT_0_UBOX_MISC_STRUCT;

/* NCDECS_CR_SIDEBAND_ABORT_1_UBOX_MISC_REG supported on:                       */
/*      SPRA0 (0x21e021f4)                                                      */
/*      SPRB0 (0x21e021f4)                                                      */
/*      SPRHBMA0 (0x21e021f4)                                                   */
/*      SPRC0 (0x21e021f4)                                                      */
/*      SPRMCC (0x21e021f4)                                                     */
/*      SPRD0 (0x21e021f4)                                                      */
/*      SPRHBMB0 (0x21e021f4)                                                   */
/*      SPRLCC (0x21e021f4)                                                     */
/*      EMRXCC (0x21e021f4)                                                     */
/*      SPRE0 (0x21e021f4)                                                      */
/* Register default value on SPRA0: 0x00000000                                  */
/* Register default value on SPRB0: 0x00000000                                  */
/* Register default value on SPRHBMA0: 0x00000000                               */
/* Register default value on SPRC0: 0x00000000                                  */
/* Register default value on SPRMCC: 0x00000000                                 */
/* Register default value on SPRD0: 0x00000000                                  */
/* Register default value on SPRHBMB0: 0x00000000                               */
/* Register default value on SPRLCC: 0x00000000                                 */
/* Register default value on EMRXCC: 0x00000000                                 */
/* Register default value on SPRE0: 0x00000000                                  */
/* SPRA0 Register File:    sprsp_top/ubox/ncuracu/ncuracu/NCURACU_CFG_UBOX_F2_MSG_UBOX_F2*/
/* SPRB0 Register File:    sprsp_top/ubox/ncuracu/ncuracu/NCURACU_CFG_UBOX_F2_MSG_UBOX_F2*/
/* SPRHBMA0 Register File:    sprsp_top/ubox/ncuracu/ncuracu/NCURACU_CFG_UBOX_F2_MSG_UBOX_F2*/
/* SPRC0 Register File:    sprsp_top/ubox/ncuracu/ncuracu/NCURACU_CFG_UBOX_F2_MSG_UBOX_F2*/
/* SPRMCC Register File:    sprsp_top/ubox/ncuracu/ncuracu/NCURACU_CFG_UBOX_F2_MSG_UBOX_F2*/
/* SPRD0 Register File:    sprsp_top/ubox/ncuracu/ncuracu/NCURACU_CFG_UBOX_F2_MSG_UBOX_F2*/
/* SPRHBMB0 Register File:    sprsp_top/ubox/ncuracu/ncuracu/NCURACU_CFG_UBOX_F2_MSG_UBOX_F2*/
/* SPRLCC Register File:    sprsp_top/ubox/ncuracu/ncuracu/NCURACU_CFG_UBOX_F2_MSG_UBOX_F2*/
/* EMRXCC Register File:    sprsp_top/ubox/ncuracu/ncuracu/NCURACU_CFG_UBOX_F2_MSG_UBOX_F2*/
/* SPRE0 Register File:    sprsp_top/ubox/ncuracu/ncuracu/NCURACU_CFG_UBOX_F2_MSG_UBOX_F2*/
/* Struct generated from SPRA0 BDF: 30_0_2                                      */
/* SPRA0 Security PolicyGroup: LB_W                                             */
/* SPRB0 Security PolicyGroup: LB_W                                             */
/* SPRHBMA0 Security PolicyGroup: LB_W                                          */
/* SPRC0 Security PolicyGroup: LB_W                                             */
/* SPRMCC Security PolicyGroup: LB_W                                            */
/* SPRD0 Security PolicyGroup: LB_W                                             */
/* SPRHBMB0 Security PolicyGroup: LB_W                                          */
/* SPRLCC Security PolicyGroup: LB_W                                            */
/* EMRXCC Security PolicyGroup: LB_W                                            */
/* SPRE0 Security PolicyGroup: LB_W                                             */
/* Register loaded when Unsuccessful response is received - Dest port and opcode are loaded here
*/


#define NCDECS_CR_SIDEBAND_ABORT_1_UBOX_MISC_REG 0x132201F4

typedef union {
  ///
  /// Individual bit fields
  ///
  struct {
    UINT32 rsvd : 8;

                            /* Bits[7:0], Access Type=RO, default=None*/

                            /* Reserved */
    UINT32 opcode : 8;

                            /* Bits[15:8], Access Type=RO/V, default=0x00000000*/

                            /* Opcode of request */
    UINT32 tag : 3;

                            /* Bits[18:16], Access Type=RO/V, default=0x00000000*/

                            /* Tag of request */
    UINT32 bar : 3;

                            /* Bits[21:19], Access Type=RO/V, default=0x00000000*/

                            /* Bar of request */
    UINT32 addrlen : 1;

                            /* Bits[22:22], Access Type=RO/V, default=0x00000000*/

                            /* Addrlen of request */
    UINT32 eh : 1;

                            /* Bits[23:23], Access Type=RO/V, default=0x00000000*/

                            /* EH of request */
    UINT32 fbe : 4;

                            /* Bits[27:24], Access Type=RO/V, default=0x00000000*/

                            /* FBE of request */
    UINT32 sbe : 4;

                            /* Bits[31:28], Access Type=RO/V, default=0x00000000*/

                            /* SBE of request */

  } Bits;
  UINT32 Data;

} NCDECS_CR_SIDEBAND_ABORT_1_UBOX_MISC_STRUCT;

/* NCDECS_CR_SIDEBAND_ABORT_2_UBOX_MISC_REG supported on:                       */
/*      SPRA0 (0x21e021f8)                                                      */
/*      SPRB0 (0x21e021f8)                                                      */
/*      SPRHBMA0 (0x21e021f8)                                                   */
/*      SPRC0 (0x21e021f8)                                                      */
/*      SPRMCC (0x21e021f8)                                                     */
/*      SPRD0 (0x21e021f8)                                                      */
/*      SPRHBMB0 (0x21e021f8)                                                   */
/*      SPRLCC (0x21e021f8)                                                     */
/*      EMRXCC (0x21e021f8)                                                     */
/*      SPRE0 (0x21e021f8)                                                      */
/* Register default value on SPRA0: 0x00000000                                  */
/* Register default value on SPRB0: 0x00000000                                  */
/* Register default value on SPRHBMA0: 0x00000000                               */
/* Register default value on SPRC0: 0x00000000                                  */
/* Register default value on SPRMCC: 0x00000000                                 */
/* Register default value on SPRD0: 0x00000000                                  */
/* Register default value on SPRHBMB0: 0x00000000                               */
/* Register default value on SPRLCC: 0x00000000                                 */
/* Register default value on EMRXCC: 0x00000000                                 */
/* Register default value on SPRE0: 0x00000000                                  */
/* SPRA0 Register File:    sprsp_top/ubox/ncuracu/ncuracu/NCURACU_CFG_UBOX_F2_MSG_UBOX_F2*/
/* SPRB0 Register File:    sprsp_top/ubox/ncuracu/ncuracu/NCURACU_CFG_UBOX_F2_MSG_UBOX_F2*/
/* SPRHBMA0 Register File:    sprsp_top/ubox/ncuracu/ncuracu/NCURACU_CFG_UBOX_F2_MSG_UBOX_F2*/
/* SPRC0 Register File:    sprsp_top/ubox/ncuracu/ncuracu/NCURACU_CFG_UBOX_F2_MSG_UBOX_F2*/
/* SPRMCC Register File:    sprsp_top/ubox/ncuracu/ncuracu/NCURACU_CFG_UBOX_F2_MSG_UBOX_F2*/
/* SPRD0 Register File:    sprsp_top/ubox/ncuracu/ncuracu/NCURACU_CFG_UBOX_F2_MSG_UBOX_F2*/
/* SPRHBMB0 Register File:    sprsp_top/ubox/ncuracu/ncuracu/NCURACU_CFG_UBOX_F2_MSG_UBOX_F2*/
/* SPRLCC Register File:    sprsp_top/ubox/ncuracu/ncuracu/NCURACU_CFG_UBOX_F2_MSG_UBOX_F2*/
/* EMRXCC Register File:    sprsp_top/ubox/ncuracu/ncuracu/NCURACU_CFG_UBOX_F2_MSG_UBOX_F2*/
/* SPRE0 Register File:    sprsp_top/ubox/ncuracu/ncuracu/NCURACU_CFG_UBOX_F2_MSG_UBOX_F2*/
/* Struct generated from SPRA0 BDF: 30_0_2                                      */
/* SPRA0 Security PolicyGroup: LB_W                                             */
/* SPRB0 Security PolicyGroup: LB_W                                             */
/* SPRHBMA0 Security PolicyGroup: LB_W                                          */
/* SPRC0 Security PolicyGroup: LB_W                                             */
/* SPRMCC Security PolicyGroup: LB_W                                            */
/* SPRD0 Security PolicyGroup: LB_W                                             */
/* SPRHBMB0 Security PolicyGroup: LB_W                                          */
/* SPRLCC Security PolicyGroup: LB_W                                            */
/* EMRXCC Security PolicyGroup: LB_W                                            */
/* SPRE0 Security PolicyGroup: LB_W                                             */
/* Register loaded when Unsuccessful response is received - Address and fid loaded here
*/


#define NCDECS_CR_SIDEBAND_ABORT_2_UBOX_MISC_REG 0x132201F8

typedef union {
  ///
  /// Individual bit fields
  ///
  struct {
    UINT32 fid : 8;

                            /* Bits[7:0], Access Type=RO/V, default=0x00000000*/

                            /* FID of Request */
    UINT32 address_15_0 : 16;

                            /* Bits[23:8], Access Type=RO/V, default=0x00000000*/

                            /* Address_15_0 of Request */
    UINT32 rsvd : 8;

                            /* Bits[31:24], Access Type=RO, default=None*/

                            /* Reserved */

  } Bits;
  UINT32 Data;

} NCDECS_CR_SIDEBAND_ABORT_2_UBOX_MISC_STRUCT;

/* NCDECS_CR_SIDEBAND_ABORT_3_UBOX_MISC_REG supported on:                       */
/*      SPRA0 (0x21e021fc)                                                      */
/*      SPRB0 (0x21e021fc)                                                      */
/*      SPRHBMA0 (0x21e021fc)                                                   */
/*      SPRC0 (0x21e021fc)                                                      */
/*      SPRMCC (0x21e021fc)                                                     */
/*      SPRD0 (0x21e021fc)                                                      */
/*      SPRHBMB0 (0x21e021fc)                                                   */
/*      SPRLCC (0x21e021fc)                                                     */
/*      EMRXCC (0x21e021fc)                                                     */
/*      SPRE0 (0x21e021fc)                                                      */
/* Register default value on SPRA0: 0x00000000                                  */
/* Register default value on SPRB0: 0x00000000                                  */
/* Register default value on SPRHBMA0: 0x00000000                               */
/* Register default value on SPRC0: 0x00000000                                  */
/* Register default value on SPRMCC: 0x00000000                                 */
/* Register default value on SPRD0: 0x00000000                                  */
/* Register default value on SPRHBMB0: 0x00000000                               */
/* Register default value on SPRLCC: 0x00000000                                 */
/* Register default value on EMRXCC: 0x00000000                                 */
/* Register default value on SPRE0: 0x00000000                                  */
/* SPRA0 Register File:    sprsp_top/ubox/ncuracu/ncuracu/NCURACU_CFG_UBOX_F2_MSG_UBOX_F2*/
/* SPRB0 Register File:    sprsp_top/ubox/ncuracu/ncuracu/NCURACU_CFG_UBOX_F2_MSG_UBOX_F2*/
/* SPRHBMA0 Register File:    sprsp_top/ubox/ncuracu/ncuracu/NCURACU_CFG_UBOX_F2_MSG_UBOX_F2*/
/* SPRC0 Register File:    sprsp_top/ubox/ncuracu/ncuracu/NCURACU_CFG_UBOX_F2_MSG_UBOX_F2*/
/* SPRMCC Register File:    sprsp_top/ubox/ncuracu/ncuracu/NCURACU_CFG_UBOX_F2_MSG_UBOX_F2*/
/* SPRD0 Register File:    sprsp_top/ubox/ncuracu/ncuracu/NCURACU_CFG_UBOX_F2_MSG_UBOX_F2*/
/* SPRHBMB0 Register File:    sprsp_top/ubox/ncuracu/ncuracu/NCURACU_CFG_UBOX_F2_MSG_UBOX_F2*/
/* SPRLCC Register File:    sprsp_top/ubox/ncuracu/ncuracu/NCURACU_CFG_UBOX_F2_MSG_UBOX_F2*/
/* EMRXCC Register File:    sprsp_top/ubox/ncuracu/ncuracu/NCURACU_CFG_UBOX_F2_MSG_UBOX_F2*/
/* SPRE0 Register File:    sprsp_top/ubox/ncuracu/ncuracu/NCURACU_CFG_UBOX_F2_MSG_UBOX_F2*/
/* Struct generated from SPRA0 BDF: 30_0_2                                      */
/* SPRA0 Security PolicyGroup: LB_W                                             */
/* SPRB0 Security PolicyGroup: LB_W                                             */
/* SPRHBMA0 Security PolicyGroup: LB_W                                          */
/* SPRC0 Security PolicyGroup: LB_W                                             */
/* SPRMCC Security PolicyGroup: LB_W                                            */
/* SPRD0 Security PolicyGroup: LB_W                                             */
/* SPRHBMB0 Security PolicyGroup: LB_W                                          */
/* SPRLCC Security PolicyGroup: LB_W                                            */
/* EMRXCC Security PolicyGroup: LB_W                                            */
/* SPRE0 Security PolicyGroup: LB_W                                             */
/* Register loaded when Unsuccessful response is received - SAI loaded here
*/


#define NCDECS_CR_SIDEBAND_ABORT_3_UBOX_MISC_REG 0x132201FC

typedef union {
  ///
  /// Individual bit fields
  ///
  struct {
    UINT32 sai : 16;

                            /* Bits[15:0], Access Type=RO/V, default=0x00000000*/

                            /* SAI of Request */
    UINT32 rs : 4;

                            /* Bits[19:16], Access Type=RO/V, default=0x00000000*/

                            /* RS of Request */
    UINT32 rsvd : 12;

                            /* Bits[31:20], Access Type=RO, default=None*/

                            /* Reserved */

  } Bits;
  UINT32 Data;

} NCDECS_CR_SIDEBAND_ABORT_3_UBOX_MISC_STRUCT;
#endif /* _UBOX_MISC_h */
