//*********************************************************************************
// Generated by SmartRF Studio version 2.7.0 (build #21)
// Tested for SimpleLink SDK version: No known SDK for this device
// Device: CC2650 Rev. 2.2
// 
//*********************************************************************************


//*********************************************************************************
// Parameter summary
// IEEE Channel: 11 
// Frequency: 2405 MHz
// SFD: 0 
// Preamble (32 bit): 01010101... 
// TX Power: 5 dBm 

#include <ti/devices/DeviceFamily.h>
#include DeviceFamily_constructPath(driverlib/rf_mailbox.h)
#include DeviceFamily_constructPath(driverlib/rf_common_cmd.h)
#include DeviceFamily_constructPath(driverlib/rf_ieee_cmd.h)
#include <ti/drivers/rf/RF.h>
#include DeviceFamily_constructPath(rf_patches/rf_patch_cpe_ieee.h)
#include "smartrf_settings_15_4_0.h"


// TI-RTOS RF Mode Object
RF_Mode Ieee154_0_mode =
{
    .rfMode = RF_MODE_IEEE_15_4,
    .cpePatchFxn = &rf_patch_cpe_ieee,
    .mcePatchFxn = 0,
    .rfePatchFxn = 0,
};

// Overrides for CMD_RADIO_SETUP
static uint32_t pOverrides[] =
{
    // override_synth_ieee_15_4.xml
    // Synth: Set recommended RTRIM to 5
    HW_REG_OVERRIDE(0x4038,0x0035),
    // Synth: Set Fref to 3.43 MHz
    (uint32_t)0x000784A3,
    // Synth: Set loop bandwidth after lock to 80 kHz
    (uint32_t)0xA47E0583,
    // Synth: Set loop bandwidth after lock to 80 kHz
    (uint32_t)0xEAE00603,
    // Synth: Set loop bandwidth after lock to 80 kHz
    (uint32_t)0x00010623,
    // Synth: Configure PLL bias
    HW32_ARRAY_OVERRIDE(0x405C,1),
    // Synth: Configure PLL bias
    (uint32_t)0x1801F800,
    // Synth: Configure PLL latency
    HW32_ARRAY_OVERRIDE(0x402C,1),
    // Synth: Configure PLL latency
    (uint32_t)0x00608402,
    // Synth: Use 24 MHz XOSC as synth clock, enable extra PLL filtering
    (uint32_t)0x02010403,
    // Synth: Configure extra PLL filtering
    HW32_ARRAY_OVERRIDE(0x4034,1),
    // Synth: Configure extra PLL filtering
    (uint32_t)0x177F0408,
    // Synth: Configure extra PLL filtering
    (uint32_t)0x38000463,
    // override_phy_ieee_15_4.xml
    // Synth: Increase synth programming timeout
    (uint32_t)0x05000243,
    // Rx: Adjust Rx FIFO threshold to avoid overflow
    (uint32_t)0x002082C3,
    // override_frontend_id.xml
    // Rx: Set RSSI offset to adjust reported RSSI by -2 dB
    (uint32_t)0x000288A3,
    // Rx: Configure LNA bias current trim offset
    (uint32_t)0x000F8883,
    // Rx: Adjust AGC DC filter 
    HW_REG_OVERRIDE(0x50DC,0x002B),
    // Disable pointer check in RF Core to allow for using GPRAM for buffers
    (uint32_t)0x00018063,
    (uint32_t)0xFFFFFFFF,
};


// CMD_RADIO_SETUP
// Radio Setup Command for Pre-Defined Schemes
rfc_CMD_RADIO_SETUP_t Ieee154_0_cmdRadioSetup =
{
    .commandNo = 0x0802,
    .status = 0x0000,
    .pNextOp = 0, // INSERT APPLICABLE POINTER: (uint8_t*)&xxx
    .startTime = 0x00000000,
    .startTrigger.triggerType = 0x0,
    .startTrigger.bEnaCmd = 0x0,
    .startTrigger.triggerNo = 0x0,
    .startTrigger.pastTrig = 0x0,
    .condition.rule = 0x1,
    .condition.nSkip = 0x0,
    .mode = 0x01,
    .__dummy0 = 0x00,
    .config.frontEndMode = 0x0,
    .config.biasMode = 0x0,
    .config.analogCfgMode = 0x0,
    .config.bNoFsPowerUp = 0x0,
    .txPower = 0x9330,
    .pRegOverride = pOverrides,
};

// CMD_FS
// Frequency Synthesizer Programming Command
rfc_CMD_FS_t Ieee154_0_cmdFs =
{
    .commandNo = 0x0803,
    .status = 0x0000,
    .pNextOp = 0, // INSERT APPLICABLE POINTER: (uint8_t*)&xxx
    .startTime = 0x00000000,
    .startTrigger.triggerType = 0x0,
    .startTrigger.bEnaCmd = 0x0,
    .startTrigger.triggerNo = 0x0,
    .startTrigger.pastTrig = 0x0,
    .condition.rule = 0x1,
    .condition.nSkip = 0x0,
    .frequency = 0x0965,
    .fractFreq = 0x0000,
    .synthConf.bTxMode = 0x1,
    .synthConf.refFreq = 0x0,
    .__dummy0 = 0x00,
    .__dummy1 = 0x00,
    .__dummy2 = 0x00,
    .__dummy3 = 0x0000,
};

// CMD_IEEE_TX
// The command ID number 0x2C01
rfc_CMD_IEEE_TX_t Ieee154_0_cmdIeeeTx =
{
    .commandNo = 0x2C01,
    .status = 0x0000,
    .pNextOp = 0, // INSERT APPLICABLE POINTER: (uint8_t*)&xxx
    .startTime = 0x00000000,
    .startTrigger.triggerType = 0x0,
    .startTrigger.bEnaCmd = 0x0,
    .startTrigger.triggerNo = 0x0,
    .startTrigger.pastTrig = 0x0,
    .condition.rule = 0x1,
    .condition.nSkip = 0x0,
    .txOpt.bIncludePhyHdr = 0x0,
    .txOpt.bIncludeCrc = 0x0,
    .txOpt.payloadLenMsb = 0x0,
    .payloadLen = 0x1E,
    .pPayload = 0, // INSERT APPLICABLE POINTER: (uint8_t*)&xxx
    .timeStamp = 0x00000000,
};

// CMD_IEEE_RX
// The command ID number 0x2801
rfc_CMD_IEEE_RX_t Ieee154_0_cmdIeeeRx =
{
    .commandNo = 0x2801,
    .status = 0x0000,
    .pNextOp = 0, // INSERT APPLICABLE POINTER: (uint8_t*)&xxx
    .startTime = 0x00000000,
    .startTrigger.triggerType = 0x0,
    .startTrigger.bEnaCmd = 0x0,
    .startTrigger.triggerNo = 0x0,
    .startTrigger.pastTrig = 0x0,
    .condition.rule = 0x1,
    .condition.nSkip = 0x0,
    .channel = 0x00,
    .rxConfig.bAutoFlushCrc = 0x0,
    .rxConfig.bAutoFlushIgn = 0x0,
    .rxConfig.bIncludePhyHdr = 0x0,
    .rxConfig.bIncludeCrc = 0x0,
    .rxConfig.bAppendRssi = 0x1,
    .rxConfig.bAppendCorrCrc = 0x1,
    .rxConfig.bAppendSrcInd = 0x0,
    .rxConfig.bAppendTimestamp = 0x0,
    .pRxQ = 0, // INSERT APPLICABLE POINTER: (dataQueue_t*)&xxx
    .pOutput = 0, // INSERT APPLICABLE POINTER: (uint8_t*)&xxx
    .frameFiltOpt.frameFiltEn = 0x0,
    .frameFiltOpt.frameFiltStop = 0x0,
    .frameFiltOpt.autoAckEn = 0x0,
    .frameFiltOpt.slottedAckEn = 0x0,
    .frameFiltOpt.autoPendEn = 0x0,
    .frameFiltOpt.defaultPend = 0x0,
    .frameFiltOpt.bPendDataReqOnly = 0x0,
    .frameFiltOpt.bPanCoord = 0x0,
    .frameFiltOpt.maxFrameVersion = 0x3,
    .frameFiltOpt.fcfReservedMask = 0x0,
    .frameFiltOpt.modifyFtFilter = 0x0,
    .frameFiltOpt.bStrictLenFilter = 0x0,
    .frameTypes.bAcceptFt0Beacon = 0x1,
    .frameTypes.bAcceptFt1Data = 0x1,
    .frameTypes.bAcceptFt2Ack = 0x1,
    .frameTypes.bAcceptFt3MacCmd = 0x1,
    .frameTypes.bAcceptFt4Reserved = 0x1,
    .frameTypes.bAcceptFt5Reserved = 0x1,
    .frameTypes.bAcceptFt6Reserved = 0x1,
    .frameTypes.bAcceptFt7Reserved = 0x1,
    .ccaOpt.ccaEnEnergy = 0x0,
    .ccaOpt.ccaEnCorr = 0x0,
    .ccaOpt.ccaEnSync = 0x0,
    .ccaOpt.ccaCorrOp = 0x1,
    .ccaOpt.ccaSyncOp = 0x1,
    .ccaOpt.ccaCorrThr = 0x0,
    .ccaRssiThr = 0x64,
    .__dummy0 = 0x00,
    .numExtEntries = 0x00,
    .numShortEntries = 0x00,
    .pExtEntryList = 0, // INSERT APPLICABLE POINTER: (uint32_t*)&xxx
    .pShortEntryList = 0, // INSERT APPLICABLE POINTER: (uint32_t*)&xxx
    .localExtAddr = 0x0000000012345678,
    .localShortAddr = 0xABBA,
    .localPanID = 0x0000,
    .__dummy1 = 0x000000,
    .endTrigger.triggerType = 0x1,
    .endTrigger.bEnaCmd = 0x0,
    .endTrigger.triggerNo = 0x0,
    .endTrigger.pastTrig = 0x0,
    .endTime = 0x00000000,
};
