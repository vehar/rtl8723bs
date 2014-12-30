//===========================================
// The following is for 8188C 2Ant BT Co-exist definition
//===========================================
#define		BTC_RSSI_COEX_THRESH_TOL_8188C_2ANT		6

typedef enum _BT_INFO_SRC_8188C_2ANT{
	BT_INFO_SRC_8188C_2ANT_WIFI_FW			= 0x0,
	BT_INFO_SRC_8188C_2ANT_BT_RSP				= 0x1,
	BT_INFO_SRC_8188C_2ANT_BT_ACTIVE_SEND		= 0x2,
	BT_INFO_SRC_8188C_2ANT_MAX
}BT_INFO_SRC_8188C_2ANT,*PBT_INFO_SRC_8188C_2ANT;

typedef enum _BT_8188C_2ANT_BT_STATUS{
	BT_8188C_2ANT_BT_STATUS_IDLE				= 0x0,
	BT_8188C_2ANT_BT_STATUS_CONNECTED_IDLE	= 0x1,
	BT_8188C_2ANT_BT_STATUS_NON_IDLE			= 0x2,
	BT_8188C_2ANT_BT_STATUS_MAX
}BT_8188C_2ANT_BT_STATUS,*PBT_8188C_2ANT_BT_STATUS;

typedef enum _BT_8188C_2ANT_COEX_ALGO{
	BT_8188C_2ANT_COEX_ALGO_UNDEFINED			= 0x0,
	BT_8188C_2ANT_COEX_ALGO_SCO					= 0x1,
	BT_8188C_2ANT_COEX_ALGO_HID					= 0x2,
	BT_8188C_2ANT_COEX_ALGO_A2DP				= 0x3,
	BT_8188C_2ANT_COEX_ALGO_PAN					= 0x4,
	BT_8188C_2ANT_COEX_ALGO_HID_A2DP			= 0x5,
	BT_8188C_2ANT_COEX_ALGO_HID_PAN				= 0x6,
	BT_8188C_2ANT_COEX_ALGO_PAN_A2DP			= 0x7,
	BT_8188C_2ANT_COEX_ALGO_MAX
}BT_8188C_2ANT_COEX_ALGO,*PBT_8188C_2ANT_COEX_ALGO;

typedef struct _COEX_DM_8188C_2ANT{
	// fw mechanism
	bool		bPreBalanceOn;
	bool		bCurBalanceOn;

	// diminishWifi
	bool		bPreDacOn;
	bool		bCurDacOn;
	bool 	bPreInterruptOn;
	bool		bCurInterruptOn;
	u1Byte		preFwDacSwingLvl;
	u1Byte		curFwDacSwingLvl;
	bool 	bPreNavOn;
	bool		bCurNavOn;

	// sw mechanism
	bool		bPreRfRxLpfShrink;
	bool		bCurRfRxLpfShrink;
	u4Byte		btRf0x1eBackup;
	bool 	bPreLowPenaltyRa;
	bool		bCurLowPenaltyRa;
	bool		bPreDacSwingOn;
	u4Byte		preDacSwingLvl;
	bool		bCurDacSwingOn;
	u4Byte		curDacSwingLvl;
	bool		bPreAdcBackOff;
	bool		bCurAdcBackOff;
	bool 	bPreAgcTableEn;
	bool		bCurAgcTableEn;
	//u4Byte		preVal0x6c0;
	//u4Byte		curVal0x6c0;
	u4Byte		preVal0x6c4;
	u4Byte		curVal0x6c4;
	u4Byte		preVal0x6c8;
	u4Byte		curVal0x6c8;
	u4Byte		preVal0x6cc;
	u4Byte		curVal0x6cc;
	//bool		bLimitedDig;

	// algorithm related
	u1Byte		preAlgorithm;
	u1Byte		curAlgorithm;
	//u1Byte		btStatus;
	//u1Byte		wifiChnlInfo[3];
} COEX_DM_8188C_2ANT, *PCOEX_DM_8188C_2ANT;

typedef struct _COEX_STA_8188C_2ANT{
	u1Byte					preWifiRssiState[4];
	bool					bBtBusy;
	bool					bBtUplink;
	bool					bBtDownLink;
	bool					bA2dpBusy;
}COEX_STA_8188C_2ANT, *PCOEX_STA_8188C_2ANT;

//===========================================
// The following is interface which will notify coex module.
//===========================================
void
EXhalbtc8188c2ant_PowerOnSetting(
	IN	PBTC_COEXIST		pBtCoexist
	);
void
EXhalbtc8188c2ant_InitHwConfig(
	IN	PBTC_COEXIST		pBtCoexist,
	IN	bool				bWifiOnly
	);
void
EXhalbtc8188c2ant_InitCoexDm(
	IN	PBTC_COEXIST		pBtCoexist
	);
void
EXhalbtc8188c2ant_IpsNotify(
	IN	PBTC_COEXIST		pBtCoexist,
	IN	u1Byte			type
	);
void
EXhalbtc8188c2ant_LpsNotify(
	IN	PBTC_COEXIST		pBtCoexist,
	IN	u1Byte			type
	);
void
EXhalbtc8188c2ant_ScanNotify(
	IN	PBTC_COEXIST		pBtCoexist,
	IN	u1Byte			type
	);
void
EXhalbtc8188c2ant_ConnectNotify(
	IN	PBTC_COEXIST		pBtCoexist,
	IN	u1Byte			type
	);
void
EXhalbtc8188c2ant_MediaStatusNotify(
	IN	PBTC_COEXIST			pBtCoexist,
	IN	u1Byte				type
	);
void
EXhalbtc8188c2ant_SpecialPacketNotify(
	IN	PBTC_COEXIST			pBtCoexist,
	IN	u1Byte				type
	);
void
EXhalbtc8188c2ant_HaltNotify(
	IN	PBTC_COEXIST			pBtCoexist
	);
void
EXhalbtc8188c2ant_Periodical(
	IN	PBTC_COEXIST			pBtCoexist
	);
void
EXhalbtc8188c2ant_BtInfoNotify(
	IN	PBTC_COEXIST		pBtCoexist,
	IN	pu1Byte			tmpBuf,
	IN	u1Byte			length
	);
void
EXhalbtc8188c2ant_DisplayCoexInfo(
	IN	PBTC_COEXIST		pBtCoexist
	);
