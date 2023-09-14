#ifndef __TI84PCEG_H__
#define __TI84PCEG_H__
// Generated from ti84pceg.inc
// TI-84 Plus CE Include File
// Various Parts Contributed by
// - BrandonW
// - calc84
// - MateoConLechuga
// - Runer112
// - tr1p1ea
// - Kerm Martian
// - Texas Instruments (ti83plus.inc)
//  Included for Assembler Compatibility
// ------------------------------------
//  Hardware Defines
// ------------------------------
#define TI_lcdWidth 0x320
#define TI_lcdHeight 0x240
//  System Calls
//  Jump Table located at 020104h
// --------------------------------
#define TI_OSSize 0x20104 //  not a routine; jump location is end of OS
#define TI_BootOS 0x20108
#define TI_InterruptHandler 0x2010c
#define TI_Rst10Handler 0x20110
#define TI_Rst18Handler 0x20114
#define TI_Rst20Handler 0x20118
#define TI_Rst28Handler 0x2011c
#define TI_Rst30Handler 0x20120
//                           equ 0020124h
//                           equ 0020128h
#define TI_JErrorNo 0x2012c
#define TI_CallFontHook 0x20130
#define TI_CallLocalizeHook 0x20134
#define TI_LoadHLInd_s 0x20138
#define TI_CpHLDE 0x2013c
#define TI_DivHLBy10_s 0x20140
#define TI_DivHLByA_s 0x20144
#define TI_KbdScan 0x20148
#define TI_GetCSC 0x2014c
#define TI_CoorMon 0x20150
#define TI_Mon 0x20154
#define TI_MonForceKey 0x20158
#define TI_SendKPress 0x2015c
#define TI_JForceCmdNoChar 0x20160
#define TI_JForceCmd 0x20164
#define TI_SysErrHandler 0x20168
#define TI_NewContext 0x2016c
#define TI_NewContext0 0x20170
#define TI_PPutawayPrompt 0x20174
#define TI_PPutAway 0x20178
#define TI_PutAway 0x2017c
#define TI_SizeWind 0x20180
#define TI_ErrorEP 0x20184
#define TI_CallMain 0x20188
#define TI_MonErrHand 0x2018c
#define TI_AppInit 0x20190
#define TI_Initialize 0x20194
#define TI_Min 0x20198
#define TI_Max 0x2019c
#define TI_AbsO1PAbsO2 0x201a0
#define TI_Intgr 0x201a4
#define TI_TRunc 0x201a8
#define TI_InvSub 0x201ac
#define TI_Times2 0x201b0
#define TI_Plus1 0x201b4
#define TI_Minus1 0x201b8
#define TI_FPSub 0x201bc
#define TI_FPAdd 0x201c0
#define TI_DToR 0x201c4
#define TI_RToD 0x201c8
#define TI_Cube 0x201cc
#define TI_TimesPT5 0x201d0
#define TI_FPSquare 0x201d4
#define TI_FPMult 0x201d8
#define TI_LJRnd 0x201dc
#define TI_InvOP1Sc 0x201e0
#define TI_InvOP1S 0x201e4
#define TI_InvOP2S 0x201e8
#define TI_Frac 0x201ec
#define TI_FPRecip 0x201f0
#define TI_FPDiv 0x201f4
#define TI_SqRoot 0x201f8
#define TI_RndGuard 0x201fc
#define TI_Rnfx 0x20200
#define TI_Int 0x20204
#define TI_Round 0x20208
#define TI_LnX 0x2020c
#define TI_LogX 0x20210
#define TI_LJNoRnd 0x20214
#define TI_EToX 0x20218
#define TI_TenX 0x2021c
#define TI_SinCosRad 0x20220
#define TI_Sin 0x20224
#define TI_Cos 0x20228
#define TI_Tan 0x2022c
#define TI_SinhCosh 0x20230
#define TI_Tanh 0x20234
#define TI_Cosh 0x20238
#define TI_Sinh 0x2023c
#define TI_ACosRad 0x20240
#define TI_ATanRad 0x20244
#define TI_ATan2Rad 0x20248
#define TI_ASinRad 0x2024c
#define TI_ACos 0x20250
#define TI_ATan 0x20254
#define TI_ASin 0x20258
#define TI_ATan2 0x2025c
#define TI_ATanh 0x20260
#define TI_ASinh 0x20264
#define TI_ACosh 0x20268
#define TI_PToR 0x2026c
#define TI_RToP 0x20270
#define TI_HLTimes9 0x20274
#define TI_CkOP1Cplx 0x20278
#define TI_CkOP1Real 0x2027c
#define TI_Angle 0x20280
#define TI_COP1Set0 0x20284
#define TI_Cpop4OP3 0x20288
#define TI_Mov9OP2Cp 0x2028c
#define TI_AbsO1O2Cp 0x20290
#define TI_CpOP1OP2 0x20294
#define TI_OP3ToOP4 0x20298
#define TI_OP1ToOP4 0x2029c
#define TI_OP2ToOP4 0x202a0
#define TI_OP4ToOP2 0x202a4
#define TI_OP3ToOP2 0x202a8
#define TI_OP1ToOP3 0x202ac
#define TI_OP5ToOP2 0x202b0
#define TI_OP5ToOP6 0x202b4
#define TI_OP5ToOP4 0x202b8
#define TI_OP1ToOP2 0x202bc
#define TI_OP6ToOP2 0x202c0
#define TI_OP6ToOP1 0x202c4
#define TI_OP4ToOP1 0x202c8
#define TI_OP5ToOP1 0x202cc
#define TI_OP3ToOP1 0x202d0
#define TI_OP6ToOP5 0x202d4
#define TI_OP4ToOP5 0x202d8
#define TI_OP3ToOP5 0x202dc
#define TI_OP2ToOP5 0x202e0
#define TI_OP2ToOP6 0x202e4
#define TI_OP1ToOP6 0x202e8
#define TI_OP1ToOP5 0x202ec
#define TI_OP2ToOP1 0x202f0
#define TI_Mov11b 0x202f4
#define TI_Mov10b 0x202f8
#define TI_Mov9b 0x202fc
#define TI_Mov9b_ 0x20300
#define TI_Mov8b 0x20304
#define TI_Mov7b 0x20308
#define TI_Mov7b_ 0x2030c
#define TI_OP2ToOP3 0x20310
#define TI_OP4ToOP3 0x20314
#define TI_OP5ToOP3 0x20318
#define TI_OP4ToOP6 0x2031c
#define TI_Mov9ToOP1 0x20320
#define TI_Mov9OP1OP2 0x20324
#define TI_Mov9ToOP2 0x20328
#define TI_MovFrOP1 0x2032c
#define TI_OP4Set1 0x20330
#define TI_OP3Set1 0x20334
#define TI_OP2Set8 0x20338
#define TI_OP2Set5 0x2033c
#define TI_OP2SetA 0x20340
#define TI_OP2Set4 0x20344
#define TI_OP2Set3 0x20348
#define TI_OP1Set1 0x2034c
#define TI_OP1Set4 0x20350
#define TI_OP1Set3 0x20354
#define TI_OP3Set2 0x20358
#define TI_OP1Set2 0x2035c
#define TI_OP2Set2 0x20360
#define TI_OP2Set1 0x20364
#define TI_Zero16D 0x20368
#define TI_OP5Set0 0x2036c
#define TI_OP4Set0 0x20370
#define TI_OP3Set0 0x20374
#define TI_OP2Set0 0x20378
#define TI_OP1Set0 0x2037c
#define TI_SetNum0 0x20380
#define TI_ZeroOP1 0x20384
#define TI_ZeroOP2 0x20388
#define TI_ZeroOP3 0x2038c
#define TI_ZeroOP 0x20390
#define TI_ClrLP 0x20394
#define TI_ShrACC 0x20398
#define TI_ShlACC 0x2039c
#define TI_Shr18 0x203a0
#define TI_Shr18a 0x203a4
#define TI_Shr16 0x203a8
#define TI_Shr14 0x203ac
#define TI_Shl16 0x203b0
#define TI_Shl14 0x203b4
#define TI_Srdo1 0x203b8
#define TI_ShrdRnd 0x203bc
#define TI_MantPa 0x203c0
#define TI_AddPrOP 0x203c4
#define TI_AddPrOPlP 0x203c8
//                           equ 00203CCh
//                           equ 00203D0h
#define TI_Sub16d 0x203d4
#define TI_Sub14d 0x203d8
#define TI_OP2ExOP6 0x203dc
#define TI_OP5ExOP6 0x203e0
#define TI_OP1ExOP5 0x203e4
#define TI_OP1ExOP6 0x203e8
#define TI_OP2ExOP4 0x203ec
#define TI_OP2ExOP5 0x203f0
#define TI_OP1ExOP3 0x203f4
#define TI_OP1ExOP4 0x203f8
#define TI_OP1ExOP2 0x203fc
#define TI_ExLP 0x20400
#define TI_CkOP10 0x20404
#define TI_CkOP1FP0 0x20408
#define TI_CkOP2FP0 0x2040c
#define TI_PosNo0Int 0x20410
#define TI_CkPosInt 0x20414
#define TI_CkInt 0x20418
#define TI_CkOdd 0x2041c
#define TI_CkOP1EX 0x20420
#define TI_GetCon1 0x20424
#define TI_GetCon 0x20428
#define TI_PiDiv2 0x2042c
#define TI_PiDiv4 0x20430
#define TI_TwoPi 0x20434
#define TI_PiCon 0x20438
#define TI_ExpToHex 0x2043c
#define TI_OP1ExpToDec 0x20440
#define TI_CkOP2Pos 0x20444
#define TI_CkOP1Pos 0x20448
#define TI_ClrOP2S 0x2044c
#define TI_ClrOP1S 0x20450
#define TI_FDiv100 0x20454
#define TI_FDiv10 0x20458
#define TI_DecO1Exp 0x2045c
#define TI_IncO1exp 0x20460
#define TI_IncExp 0x20464
#define TI_CkValidNum 0x20468
#define TI_GetExp 0x2046c
#define TI_HtimesL 0x20470
#define TI_EOP1NotReal 0x20474
#define TI_ThetaName 0x20478
#define TI_RName 0x2047c
#define TI_RegEqName 0x20480
#define TI_RecurNName 0x20484
#define TI_XName 0x20488
#define TI_YName 0x2048c
#define TI_TName 0x20490
#define TI_RealName 0x20494
#define TI_SetEStoFPS 0x20498
#define TI_ChkTempDirt 0x2049c
#define TI_OP1ExOP2Exp 0x204a0
#define TI_OP1ExpMinusE 0x204a4
#define TI_ChkErrBreak 0x204a8
#define TI_Isa2ByteTok 0x204ac
#define TI_GetLastEntry 0x204b0
#define TI_GetLastEntryPtr 0x204b4
#define TI_RegRclrChng 0x204b8
#define TI_ResetWinTop 0x204bc
#define TI_IsO1NonTLstOrProg 0x204c0
#define TI_IsO1NonTempLst 0x204c4
#define TI_Is_A_LstOrCLst 0x204c8
#define TI_Chk_HL_999 0x204cc
#define TI_Equ_Or_NewEqu 0x204d0
#define TI_Errd_OP1NotPos 0x204d4
#define TI_Errd_OP1Not_R 0x204d8
#define TI_Errd_OP1NotPosInt 0x204dc
#define TI_Errd_OP1_le_0 0x204e0
#define TI_Errd_OP1_0 0x204e4
#define TI_ChkFindSym_Get_Size 0x204e8
#define TI_Sto_StatVar 0x204ec
#define TI_Rcl_StatVar 0x204f0
#define TI_CkOP2Real 0x204f4
#define TI_Get_X_Indirect 0x204f8
#define TI_MemChk 0x204fc
#define TI_CmpPrgNamLen1 0x20500
#define TI_CmpPrgNamLen 0x20504
#define TI_FindProgSym 0x20508
#define TI_ChkFindSym 0x2050c
#define TI_FindSym 0x20510
#define TI_InsertMem 0x20514
#define TI_InsertMemA 0x20518
#define TI_EnoughMem 0x2051c
#define TI_CmpMemNeed 0x20520
#define TI_CreatePVar4 0x20524
#define TI_CreatePVar3 0x20528
#define TI_CreateVar3 0x2052c
#define TI_CreateCplx 0x20530
#define TI_CreateReal 0x20534
#define TI_CreateTRList 0x20538
#define TI_CreateRList 0x2053c
#define TI_CreateTCList 0x20540
#define TI_CreateCList 0x20544
#define TI_CreateTRMat 0x20548
#define TI_CreateRMat 0x2054c
#define TI_CreateTStrng 0x20550
#define TI_CreateStrng 0x20554
#define TI_Create0Equ 0x20558
#define TI_CreatetEqu 0x2055c
#define TI_CreateEqu 0x20560
#define TI_CreateGDB 0x20564
#define TI_CreateProg 0x20568
#define TI_ChkDel 0x2056c
#define TI_ChkDelA 0x20570
#define TI_AdjParser 0x20574
#define TI_AdjMath 0x20578
#define TI_AdjM7 0x2057c
#define TI_DelMemA 0x20580
#define TI_Get_Form_Num 0x20584
#define TI_DelVar 0x20588
#define TI_DelVarIO 0x2058c
#define TI_DelMem 0x20590
#define TI_DelVar3D 0x20594
#define TI_DelVar3C 0x20598
#define TI_DelVar3DC 0x2059c
#define TI_Sym_Prog_non_t_Lst 0x205a0
#define TI_AdjSymPtrs 0x205a4
#define TI_DataSizeA 0x205a8
#define TI_DataSize 0x205ac
#define TI_PopMCplxO1 0x205b0
#define TI_PopMCplx 0x205b4
#define TI_MovCplx 0x205b8
#define TI_PopOP5 0x205bc
#define TI_PopOP3 0x205c0
#define TI_PopOP1 0x205c4
#define TI_PopRealO6 0x205c8
#define TI_PopRealO5 0x205cc
#define TI_PopRealO4 0x205d0
#define TI_PopRealO3 0x205d4
#define TI_PopRealO2 0x205d8
#define TI_PopRealO1 0x205dc
#define TI_PopReal 0x205e0
#define TI_FPopCplx 0x205e4
#define TI_FPopReal 0x205e8
#define TI_FPopFPS 0x205ec
#define TI_DeallocFPS 0x205f0
#define TI_DeallocFPS1 0x205f4
#define TI_AllocFPS 0x205f8
#define TI_AllocFPS1 0x205fc
#define TI_PushRealO6 0x20600
#define TI_PushRealO5 0x20604
#define TI_PushRealO4 0x20608
#define TI_PushRealO3 0x2060c
#define TI_PushRealO2 0x20610
#define TI_PushRealO1 0x20614
#define TI_PushReal 0x20618
#define TI_PushOP5 0x2061c
#define TI_PushOP3 0x20620
#define TI_PushMCplxO3 0x20624
#define TI_PushOP1 0x20628
#define TI_PushMCplxO1 0x2062c
#define TI_PushMCplx 0x20630
#define TI_ExMCplxO1 0x20634
#define TI_Exch9 0x20638
#define TI_CpyTo1FPS11 0x2063c
#define TI_CpyTo2FPS5 0x20640
#define TI_CpyTo1FPS5 0x20644
#define TI_CpyTo2FPS6 0x20648
#define TI_CpyTo1FPS6 0x2064c
#define TI_CpyTo2FPS7 0x20650
#define TI_CpyTo1FPS7 0x20654
#define TI_CpyTo1FPS8 0x20658
#define TI_CpyTo2FPS8 0x2065c
#define TI_CpyTo1FPS10 0x20660
#define TI_CpyTo1FPS9 0x20664
#define TI_CpyTo2FPS4 0x20668
#define TI_CpyTo6FPS3 0x2066c
#define TI_CpyTo6FPS2 0x20670
#define TI_CpyTo2FPS3 0x20674
#define TI_Cpycto1FPS3 0x20678
#define TI_CpyTo1FPS3 0x2067c
#define TI_CpyFPS3 0x20680
#define TI_CpyTo1FPS4 0x20684
#define TI_CpyTo3FPS2 0x20688
#define TI_CpyTo5FPST 0x2068c
#define TI_CpyTo6FPST 0x20690
#define TI_CpyTo4FPST 0x20694
#define TI_CpyTo3FPST 0x20698
#define TI_CpyTo2FPST 0x2069c
#define TI_CpyTo1FPST 0x206a0
#define TI_CpyFPST 0x206a4
#define TI_CpyStack 0x206a8
#define TI_CpyTo3FPS1 0x206ac
#define TI_CpyTo2FPS1 0x206b0
#define TI_CpyTo1FPS1 0x206b4
#define TI_CpyFPS1 0x206b8
#define TI_CpyTo2FPS2 0x206bc
#define TI_CpyTo1FPS2 0x206c0
#define TI_CpyFPS2 0x206c4
#define TI_CpyO3ToFPST 0x206c8
#define TI_CpyO2ToFPST 0x206cc
#define TI_CpyO6ToFPST 0x206d0
#define TI_CpyO1ToFPST 0x206d4
#define TI_CpyToFPST 0x206d8
#define TI_CpyToStack 0x206dc
#define TI_CpyO3ToFPS1 0x206e0
#define TI_CpyO5ToFPS1 0x206e4
#define TI_CpyO2ToFPS1 0x206e8
#define TI_CpyO1ToFPS1 0x206ec
#define TI_CpyToFPS1 0x206f0
#define TI_CpyO2ToFPS2 0x206f4
#define TI_CpyO3ToFPS2 0x206f8
#define TI_CpyO6ToFPS2 0x206fc
#define TI_CpyO1ToFPS2 0x20700
#define TI_CpyToFPS2 0x20704
#define TI_CpyO5ToFPS3 0x20708
#define TI_CpyO2ToFPS3 0x2070c
#define TI_CpyO1ToFPS3 0x20710
#define TI_CpyToFPS3 0x20714
#define TI_CpyO1ToFPS6 0x20718
#define TI_CpyO1ToFPS7 0x2071c
#define TI_CpyO1ToFPS5 0x20720
#define TI_CpyO2ToFPS4 0x20724
#define TI_CpyO1ToFPS4 0x20728
#define TI_ErrNotEnoughMem 0x2072c
#define TI_FPSMinus9 0x20730
#define TI_HLMinus9 0x20734
#define TI_ErrOverflow 0x20738
#define TI_ErrDivBy0 0x2073c
#define TI_ErrSingularMat 0x20740
#define TI_ErrDomain 0x20744
#define TI_ErrIncrement 0x20748
#define TI_ErrNon_Real 0x2074c
#define TI_ErrSyntax 0x20750
#define TI_ErrDataType 0x20754
#define TI_ErrArgument 0x20758
#define TI_ErrDimMismatch 0x2075c
#define TI_ErrDimension 0x20760
#define TI_ErrUndefined 0x20764
#define TI_ErrMemory 0x20768
#define TI_ErrInvalid 0x2076c
#define TI_ErrBreak 0x20770
#define TI_ErrStat 0x20774
#define TI_ErrSignChange 0x20778
#define TI_ErrIterations 0x2077c
#define TI_ErrBadGuess 0x20780
#define TI_ErrTolTooSmall 0x20784
#define TI_ErrStatPlot 0x20788
#define TI_ErrLinkXmit 0x2078c
#define TI_JError 0x20790
#define TI_NoErrorEntry 0x20794
#define TI_PushErrorHandler 0x20798
#define TI_PopErrorHandler 0x2079c
#define TI_StrCopy 0x207a0
#define TI_StrngCat 0x207a4
#define TI_IsInSet 0x207a8
#define TI_GEQNameA 0x207ac
#define TI_RecName 0x207b0
#define TI_PutMap 0x207b4
#define TI_PutC 0x207b8
#define TI_DispHL_s 0x207bc
#define TI_PutS 0x207c0
#define TI_PutPSB 0x207c4
#define TI_PutPS 0x207c8
#define TI_WPutPS 0x207cc
#define TI_PutBuf 0x207d0
#define TI_PutBuf1 0x207d4
#define TI_WPutC 0x207d8
#define TI_WPutS 0x207dc
#define TI_WPutSEOL 0x207e0
#define TI_WDispEOL 0x207e4
#define TI_WHomeUp 0x207e8
#define TI_SetNumWindow 0x207ec
#define TI_NewLine 0x207f0
#define TI_MoveDown 0x207f4
#define TI_ScrollUp 0x207f8
#define TI_ShrinkWindow 0x207fc
#define TI_MoveUp 0x20800
#define TI_ScrollDown 0x20804
#define TI_ClrLCDFull 0x20808
#define TI_ClrLCD 0x2080c
#define TI_ClrScrnFull 0x20810
#define TI_ClrScrn 0x20814
#define TI_ClrTxtShd 0x20818
#define TI_ClrWindow 0x2081c
#define TI_EraseEOL 0x20820
#define TI_EraseEOW 0x20824
#define TI_HomeUp 0x20828
#define TI_GetCurloc 0x2082c
#define TI_VPutMap 0x20830
#define TI_VPutS 0x20834
#define TI_VPutSN 0x20838
#define TI_VPutSNG 0x2083c
#define TI_VPutSNT 0x20840
#define TI_RunIndicOn 0x20844
#define TI_RunIndicOff 0x20848
#define TI_SaveCmdShadow 0x2084c
#define TI_SaveShadow 0x20850
#define TI_RStrShadow 0x20854
#define TI_RStrPartial 0x20858
#define TI_RStrCurRow 0x2085c
#define TI_RStrUnderMenu 0x20860
#define TI_RStrbotRow 0x20864
#define TI_GetKeypress 0x20868
#define TI_GetTokLen 0x2086c
#define TI_Get_Tok_Strng 0x20870
#define TI_GetTokString 0x20874
#define TI_PutBPatBuf2 0x20878
#define TI_PutBPatBuf 0x2087c
#define TI_PutBPat 0x20880
#define TI_PutcChkScroll 0x20884
#define TI_DispEOL 0x20888
#define TI_FDispEOL 0x2088c
#define TI_MakeRowCmd 0x20890
#define TI_ToToStrp 0x20894
#define TI_SetVarName 0x20898
#define TI_DispDone 0x2089c
#define TI_FinishOutput 0x208a0
#define TI_CurBlink 0x208a4
#define TI_CursorOff 0x208a8
#define TI_HideCursor 0x208ac
#define TI_CursorOn 0x208b0
#define TI_ShowCursor 0x208b4
#define TI_KeyToString 0x208b8
#define TI_PullDownChk 0x208bc
#define TI_MenuCatCommon 0x208c0
#define TI_LoadCurCat 0x208c4
#define TI_NCIFPrgmedMode 0x208c8
#define TI_LoadMenuNum 0x208cc
#define TI_LoadMenuNuml 0x208d0
#define TI_MenuEdKey 0x208d4
#define TI_MenCatRet 0x208d8
#define TI_NotAlphNum 0x208dc
#define TI_SetMenuFlags 0x208e0
#define TI_ResetSomeFlags 0x208e4
//                           equ 00208E8h
//                           equ 00208ECh
#define TI_DispListName 0x208f0
#define TI_DispLAlphaName 0x208f4
#define TI_AbortPrgmode 0x208f8
#define TI_IsFullCntx 0x208fc
#define TI_AdrMRow 0x20900
#define TI_AdrmeLE 0x20904
#define TI_GetmatOP1A 0x20908
#define TI_Getm1toOP1 0x2090c
#define TI_Getm1tOP1A 0x20910
#define TI_GetMToOP1 0x20914
#define TI_PutToM1A 0x20918
#define TI_PutToMA1 0x2091c
#define TI_PutToMat 0x20920
#define TI_MatELDiv 0x20924
#define TI_CMatFun 0x20928
#define TI_RowEchPoly 0x2092c
#define TI_RowEchelon 0x20930
#define TI_AdrLELE 0x20934
#define TI_Getl1ToOP1 0x20938
#define TI_Getl1TOP1A 0x2093c
#define TI_GetlToOP1 0x20940
#define TI_Getl1ToOP2 0x20944
#define TI_Getl1TOP2A 0x20948
#define TI_Getl2TOP1A 0x2094c
#define TI_PutTola1 0x20950
#define TI_PutToL 0x20954
#define TI_MaxMinLst 0x20958
#define TI_LLow 0x2095c
#define TI_LHigh 0x20960
#define TI_LSum 0x20964
#define TI_CumSum 0x20968
#define TI_ToFrac 0x2096c
#define TI_SeqSet 0x20970
#define TI_SeqSolve 0x20974
#define TI_CmpNumInit 0x20978
#define TI_BinopExec 0x2097c
#define TI_ExMeanL 0x20980
#define TI_Set2MVLPtrs 0x20984
#define TI_SetMat1 0x20988
#define TI_CreateTLIst 0x2098c
#define TI_UnopExec 0x20990
#define TI_ThreeExec 0x20994
#define TI_RestoreErrNo 0x20998
#define TI_FourExec 0x2099c
#define TI_FiveExec 0x209a0
#define TI_CpyTo2ES1 0x209a4
#define TI_CpyTo6ES1 0x209a8
#define TI_CpyTo1ES1 0x209ac
#define TI_CpyTo3ES1 0x209b0
#define TI_CpyTo3ES2 0x209b4
#define TI_CpyTo2ES2 0x209b8
#define TI_CpyTo1ES2 0x209bc
#define TI_CpyTo2ES3 0x209c0
#define TI_CpyTo1ES3 0x209c4
#define TI_CpyTo3ES4 0x209c8
#define TI_CpyTo6ES3 0x209cc
#define TI_CpyTo2ES4 0x209d0
#define TI_CpyTo1ES4 0x209d4
#define TI_CpyTo2ES5 0x209d8
#define TI_CpyTo1ES5 0x209dc
#define TI_CpyTo4ESt 0x209e0
#define TI_CpyTo2ESt 0x209e4
#define TI_CpyTo1ESt 0x209e8
#define TI_CpyTo2ES6 0x209ec
#define TI_CpyTo1ES6 0x209f0
#define TI_CpyTo2ES7 0x209f4
#define TI_CpyTo1ES7 0x209f8
#define TI_CpyTo2ES8 0x209fc
#define TI_CpyTo1ES8 0x20a00
#define TI_CpyTo1ES9 0x20a04
#define TI_CpyTo2ES9 0x20a08
#define TI_CpyTo2ES10 0x20a0c
#define TI_CpyTo1ES10 0x20a10
#define TI_CpyTo2ES11 0x20a14
#define TI_CpyTo1ES11 0x20a18
#define TI_CpyTo2ES12 0x20a1c
#define TI_CpyTo1ES12 0x20a20
#define TI_CpyTo2ES13 0x20a24
#define TI_CpyTo1ES13 0x20a28
#define TI_CpyTo1ES14 0x20a2c
#define TI_CpyTo1ES16 0x20a30
#define TI_CpyTo1ES17 0x20a34
#define TI_CpyTo1ES18 0x20a38
#define TI_CpyTo1ES15 0x20a3c
#define TI_CpyTo2ES15 0x20a40
#define TI_CpyO1ToESt 0x20a44
#define TI_CpyO1ToES1 0x20a48
#define TI_CpyO6ToES1 0x20a4c
#define TI_CpyO6ToES3 0x20a50
#define TI_CpyO1ToES2 0x20a54
#define TI_CpyO2ToES2 0x20a58
#define TI_CpyO1ToES3 0x20a5c
#define TI_CpyO1ToES4 0x20a60
#define TI_CpyO1ToES5 0x20a64
#define TI_CpyO1ToES6 0x20a68
#define TI_CpyO1ToES7 0x20a6c
#define TI_CpyO2ToES4 0x20a70
#define TI_CpyO2ToES5 0x20a74
#define TI_CpyO2ToES6 0x20a78
#define TI_CpyO2ToES7 0x20a7c
#define TI_CpyO2ToES8 0x20a80
#define TI_CpyO2ToES9 0x20a84
#define TI_CpyO1ToES8 0x20a88
#define TI_CpyO1ToES9 0x20a8c
#define TI_CpyO1ToES10 0x20a90
#define TI_CpyO1ToES11 0x20a94
#define TI_CpyO1ToES12 0x20a98
#define TI_CpyO1ToES13 0x20a9c
#define TI_CpyO1ToES14 0x20aa0
#define TI_EvalF3A 0x20aa4
#define TI_GetK 0x20aa8
#define TI_SetTitle 0x20aac
#define TI_DispVarVal 0x20ab0
#define TI_RecallEd 0x20ab4
#define TI_SetUpBuffer 0x20ab8
#define TI_CreateNumEditBuf 0x20abc
#define TI_CallCommon 0x20ac0
#define TI_CommonKeys 0x20ac4
#define TI_LeftMore 0x20ac8
#define TI_FDel 0x20acc
#define TI_FClear 0x20ad0
#define TI_FInsDisp 0x20ad4
#define TI_FInsDispNoConv 0x20ad8
#define TI_SetIndicator 0x20adc
#define TI_CloseEditBufNoR 0x20ae0
#define TI_ReleaseBuffer 0x20ae4
#define TI_VarNameToOP1HL 0x20ae8
#define TI_NameToOP1 0x20aec
#define TI_NumpPutAway 0x20af0
#define TI_NumReDisp 0x20af4
#define TI_NumError02 0x20af8
#define TI_Load_Sfont 0x20afc
#define TI_Sfont_Len 0x20b00
#define TI_InitNumVec 0x20b04
#define TI_SetxxOP1 0x20b08
#define TI_SetxxOP2 0x20b0c
#define TI_SetxxxxOP2 0x20b10
#define TI_UCLines 0x20b14
#define TI_CLine 0x20b18
#define TI_CLines 0x20b1c
#define TI_XrootY 0x20b20
#define TI_YtoX 0x20b24
#define TI_ZmStats 0x20b28
#define TI_PointStatHelp 0x20b2c
#define TI_DrawSPlot 0x20b30
#define TI_InitNewTraceP 0x20b34
#define TI_SPlotCoord 0x20b38
#define TI_SPlotRight 0x20b3c
#define TI_SPlotLeft 0x20b40
#define TI_CmpBoxInfo 0x20b44
#define TI_NextPlot 0x20b48
#define TI_PrevPlot 0x20b4c
#define TI_ClrPrevPlot 0x20b50
#define TI_PutIndexList 0x20b54
#define TI_GetIndexList 0x20b58
#define TI_HeapSort 0x20b5c
#define TI_StoGDB2 0x20b60
#define TI_RclGDB2 0x20b64
#define TI_CircCmd 0x20b68
#define TI_GrphCirc 0x20b6c
#define TI_Mov18b 0x20b70
#define TI_DarkLine 0x20b74
#define TI_ILine 0x20b78
#define TI_IPoint 0x20b7c
#define TI_XYRndBoth 0x20b80
#define TI_XYRnd 0x20b84
#define TI_CheckTOP 0x20b88
#define TI_CheckXY 0x20b8c
#define TI_DarkPnt 0x20b90
#define TI_CPointS 0x20b94
#define TI_WToV 0x20b98
#define TI_VtoWHLDE 0x20b9c
#define TI_Xitof 0x20ba0
#define TI_YftoI 0x20ba4
#define TI_XftoI 0x20ba8
#define TI_TraceOff 0x20bac
#define TI_GrRedisp 0x20bb0
#define TI_GDispToken 0x20bb4
#define TI_GrdeCoda 0x20bb8
#define TI_LabCoor 0x20bbc
#define TI_CoorDisp 0x20bc0
#define TI_TmpEquNoSrc 0x20bc4
#define TI_GrLabels 0x20bc8
#define TI_YPixSet 0x20bcc
#define TI_XPixSet 0x20bd0
#define TI_CopyRng 0x20bd4
#define TI_ValCur 0x20bd8
#define TI_GrPutAway 0x20bdc
#define TI_RstGFlags 0x20be0
#define TI_GrReset 0x20be4
#define TI_XYCent 0x20be8
#define TI_ZoomXYCmd 0x20bec
#define TI_CptDelY 0x20bf0
#define TI_CptDelX 0x20bf4
#define TI_SetFuncM 0x20bf8
#define TI_SetSeqM 0x20bfc
#define TI_SetPolM 0x20c00
#define TI_SetParM 0x20c04
#define TI_ZmInt 0x20c08
#define TI_ZmDecml 0x20c0c
#define TI_ZmPrev 0x20c10
#define TI_ZmUsr 0x20c14
#define TI_SetUZM 0x20c18
#define TI_ZmFit 0x20c1c
#define TI_ZmSquare 0x20c20
#define TI_ZmTrig 0x20c24
#define TI_SetXMinMax 0x20c28
#define TI_ZooDefault 0x20c2c
#define TI_GrBufCpy 0x20c30
#define TI_DrawSplitLine 0x20c34
//                           equ 0020C38h
//                           equ 0020C3Ch
//                           equ 0020C40h
//                           equ 0020C44h
//                           equ 0020C48h
//                           equ 0020C4Ch
//                           equ 0020C50h
//                           equ 0020C54h
#define TI_ChkTextCurs 0x20c58
#define TI_Regraph 0x20c5c
#define TI_DoRefFlags02 0x20c60
#define TI_InitNSeq 0x20c64
#define TI_YRes 0x20c68
#define TI_Ceiling 0x20c6c
#define TI_PutXY 0x20c70
#define TI_PutEquNo 0x20c74
#define TI_PDspGrph 0x20c78
#define TI_HorizCmd 0x20c7c
#define TI_VertCmd 0x20c80
#define TI_LineCmd 0x20c84
#define TI_UnLineCmd 0x20c88
#define TI_PointCmd 0x20c8c
#define TI_PixelTest 0x20c90
#define TI_PixelCmd 0x20c94
#define TI_TanLnF 0x20c98
#define TI_DrawCmdInit 0x20c9c
#define TI_DrawCmd 0x20ca0
#define TI_ShadeCmd 0x20ca4
#define TI_InvCmd 0x20ca8
#define TI_StatShade 0x20cac
#define TI_DspMatTable 0x20cb0
#define TI_DspLsts 0x20cb4
#define TI_CloseEditBuf 0x20cb8
#define TI_ParseEditBuf 0x20cbc
#define TI_PutSM 0x20cc0
#define TI_DspCurTbl 0x20cc4
#define TI_DspGrTbl 0x20cc8
#define TI_ZeroTemplate 0x20ccc
#define TI_SetTblRefs 0x20cd0
#define TI_DispTblBot 0x20cd4
#define TI_DispTblTop 0x20cd8
#define TI_DispTblBody 0x20cdc
#define TI_VPutBlank 0x20ce0
#define TI_TblTrace 0x20ce4
#define TI_DispListNameY 0x20ce8
#define TI_CurNameLength 0x20cec
#define TI_NameToBuf 0x20cf0
#define TI_JPromptCursor 0x20cf4
#define TI_BufLeft 0x20cf8
#define TI_BufRight 0x20cfc
#define TI_BufInsert 0x20d00
#define TI_BufQueueChar 0x20d04
#define TI_BufReplace 0x20d08
#define TI_BufDelete 0x20d0c
#define TI_BufPeek 0x20d10
#define TI_BufPeek1 0x20d14
#define TI_BufPeek2 0x20d18
#define TI_BufPeek3 0x20d1c
#define TI_BufToBtm 0x20d20
#define TI_SetupEditEqu 0x20d24
#define TI_BufToTop 0x20d28
#define TI_IsEditFull 0x20d2c
#define TI_IsEditEmpty 0x20d30
#define TI_IsAtTop 0x20d34
#define TI_IsAtBtm 0x20d38
#define TI_BufClear 0x20d3c
#define TI_JCursorFirst 0x20d40
#define TI_JCursorLast 0x20d44
#define TI_CursorLeft 0x20d48
#define TI_CursorRight 0x20d4c
#define TI_CursorUp 0x20d50
#define TI_CursorDown 0x20d54
#define TI_CursorToOffset 0x20d58
#define TI_InsDisp 0x20d5c
#define TI_FDispBOL1 0x20d60
#define TI_FDispBOL 0x20d64
#define TI_DispEOW 0x20d68
#define TI_DispHead 0x20d6c
#define TI_DispTail 0x20d70
#define TI_PutTokString 0x20d74
#define TI_SetUpEditCmd 0x20d78
#define TI_SetEmptyeditEqu 0x20d7c
#define TI_SetEmptyEditPtr 0x20d80
#define TI_CloseEditEqu 0x20d84
#define TI_GetPrevTok 0x20d88
#define TI_GetKey 0x20d8c
#define TI_CanIndic 0x20d90
#define TI_DFMin 0x20d94
#define TI_FormDisp 0x20d98
#define TI_FormMatrix 0x20d9c
#define TI_WScrollLeft 0x20da0
#define TI_WScrollUp 0x20da4
#define TI_WScrollDown 0x20da8
#define TI_WScrollRight 0x20dac
#define TI_FormEReal 0x20db0
#define TI_FormERealTok 0x20db4
#define TI_FormDCplx 0x20db8
#define TI_FormReal 0x20dbc
#define TI_SetWinAbove 0x20dc0
#define TI_DisarmScroll 0x20dc4
#define TI_MinToEdit 0x20dc8
#define TI_RclVarToEdit 0x20dcc
#define TI_RclVarToEditPtr 0x20dd0
#define TI_RclEntryToEdit 0x20dd4
#define TI_RclToQueue 0x20dd8
#define TI_FormToTok 0x20ddc
#define TI_DispInterval 0x20de0
#define TI_DispLstName 0x20de4
#define TI_DispSLstNameHL 0x20de8
#define TI_EditEqu 0x20dec
#define TI_CloseEquField 0x20df0
#define TI_AutoSelect 0x20df4
#define TI_DispYEOS 0x20df8
#define TI_DispNumEOS 0x20dfc
#define TI_SetupDispEq 0x20e00
#define TI_DispForward 0x20e04
#define TI_DispYPrompt2 0x20e08
#define TI_StringWidth 0x20e0c
#define TI_DispErrorScreen 0x20e10
#define TI_PopCX 0x20e14
#define TI_LoadNoEEntry 0x20e18
#define TI_SaveScreen 0x20e1c
#define TI_RetScreen 0x20e20
#define TI_RetScreenErr 0x20e24
#define TI_CheckSplitFlag 0x20e28
#define TI_SolveRedisp 0x20e2c
#define TI_SolveDisp 0x20e30
#define TI_ItemName 0x20e34
#define TI_SetNorm_Vals 0x20e38
#define TI_SetYOffset 0x20e3c
#define TI_ConvKeyToTok 0x20e40
#define TI_ConvFCKeyToTok 0x20e44
#define TI_ConvFEKeyToTok 0x20e48
#define TI_TokToKey 0x20e4c
#define TI_GetVarCmdUSB 0x20e50
//                           equ 0020E54h
#define TI_DeselectAllVars 0x20e58
#define TI_DelRes 0x20e5c
#define TI_ConvLcToLr 0x20e60
#define TI_RedimMat 0x20e64
#define TI_IncLstSize 0x20e68
#define TI_InsertList 0x20e6c
#define TI_DelListEl 0x20e70
#define TI_EditProg 0x20e74
#define TI_CloseProg 0x20e78
#define TI_ClrGraphRef 0x20e7c
#define TI_FixTempCnt 0x20e80
#define TI_SaveData 0x20e84
#define TI_RestoreData 0x20e88
#define TI_FindAlphaUp 0x20e8c
#define TI_FindAlphaDn 0x20e90
#define TI_CmpSyms 0x20e94
#define TI_CreateTemp 0x20e98
#define TI_CleanAll 0x20e9c
#define TI_MoveToNextSym 0x20ea0
#define TI_ConvLrToLc 0x20ea4
#define TI_TblScreenDown 0x20ea8
#define TI_TblScreenUp 0x20eac
#define TI_ScreenScrollPixelsUp 0x20eb0
// ;_ret                     equ 0020EB4h
#define TI_ZIfRclHandler 0x20eb8
#define TI_ZIfRclKApp 0x20ebc
//                           equ 0020EC0h
//                           equ 0020EC4h
#define TI_InitNamePrompt 0x20ec8
#define TI_InitNamePrompt_ 0x20ecc
#define TI_CatalogChk 0x20ed0
#define TI_ClrTR 0x20ed4
//                           equ 0020ED8h
//                           equ 0020EDCh
//                           equ 0020EE0h
//                           equ 0020EE4h
#define TI_ErrNonReal_FPST_FPS1 0x20ee8
#define TI_ErrNonReal 0x20eec
#define TI_WriteText 0x20ef0
//                           equ 0020EF4h
#define TI_GraphPars 0x20ef8
#define TI_PlotPars 0x20efc
#define TI_ParseInp 0x20f00
#define TI_ParseOn 0x20f04
#define TI_ParseScan 0x20f08
#define TI_GetParse 0x20f0c
#define TI_SaveParse 0x20f10
#define TI_InitPFlgs 0x20f14
#define TI_CkEndLineRR 0x20f18
#define TI_OP2Set60 0x20f1c
#define TI_GetStatPtr 0x20f20
#define TI_CmpStatPtr 0x20f24
#define TI_VarSysAdr 0x20f28
#define TI_StoSysTok 0x20f2c
#define TI_StoAns 0x20f30
#define TI_StoTheta 0x20f34
#define TI_StoR 0x20f38
#define TI_StoY 0x20f3c
#define TI_StoN 0x20f40
#define TI_StoT 0x20f44
#define TI_StoX 0x20f48
#define TI_StoOther 0x20f4c
#define TI_RclAns 0x20f50
#define TI_RclY 0x20f54
#define TI_RclN 0x20f58
#define TI_RclX 0x20f5c
#define TI_RclVarSym 0x20f60
#define TI_RclsyStok 0x20f64
#define TI_StMatel 0x20f68
#define TI_StLstvecel 0x20f6c
#define TI_ConvOP1 0x20f70
#define TI_FindParseFormula 0x20f74
#define TI_ParseFormula 0x20f78
#define TI_StrngEnt1 0x20f7c
#define TI_Prgrdlp 0x20f80
#define TI_VarEnt 0x20f84
#define TI_ParseOnC 0x20f88
#define TI_ParseOn_ 0x20f8c
#define TI_ParseCmd 0x20f90
#define TI_StoType 0x20f94
#define TI_CreatePair 0x20f98
#define TI_PushNum 0x20f9c
#define TI_IncCurPCErrEnd 0x20fa0
#define TI_ErrEnd 0x20fa4
#define TI_CommaErrF 0x20fa8
#define TI_CommaErr 0x20fac
#define TI_StEQArg2 0x20fb0
#define TI_StEQArg 0x20fb4
#define TI_InpArg 0x20fb8
#define TI_StEQArg3 0x20fbc
#define TI_NxtFetch 0x20fc0
#define TI_CkFetchVar 0x20fc4
#define TI_FetchVarA 0x20fc8
#define TI_FetchVar 0x20fcc
#define TI_CkEndLin 0x20fd0
#define TI_CkEndExp 0x20fd4
#define TI_CkParsEnd 0x20fd8
#define TI_StoTypeArg 0x20fdc
#define TI_ConvDim 0x20fe0
#define TI_ConvDim00 0x20fe4
#define TI_AheadEqual 0x20fe8
#define TI_ParseHeads 0x20fec
#define TI_ParseHead 0x20ff0
#define TI_AnsName 0x20ff4
#define TI_StoCmpReals 0x20ff8
#define TI_GetDEPtr 0x20ffc
#define TI_Push2BOper 0x21000
#define TI_Push3BOper 0x21004
#define TI_Pop2BOper 0x21008
#define TI_Pop3BOper 0x2100c
#define TI_PushOper 0x21010
#define TI_PopOper 0x21014
#define TI_FindEUndef 0x21018
#define TI_SttmpEQ 0x2101c
#define TI_FindEOL 0x21020
#define TI_BrkInc 0x21024
#define TI_IncFetch 0x21028
#define TI_CurFetch 0x2102c
#define TI_Random 0x21030
#define TI_StoRand 0x21034
#define TI_RandInit 0x21038
#define TI_ResetStacks 0x2103c
#define TI_Factorial 0x21040
#define TI_YEquOnOff 0x21044
#define TI_EquSelUnsel 0x21048
#define TI_ITSolver 0x2104c
#define TI_GRITSolver 0x21050
#define TI_ITSolverB 0x21054
#define TI_ITSolverNB 0x21058
#define TI_ExTestInt 0x2105c
#define TI_DistFun 0x21060
#define TI_LogGamma 0x21064
#define TI_OneVar 0x21068
#define TI_OneVars0 0x2106c
#define TI_OrdStat 0x21070
#define TI_InitStatAns 0x21074
#define TI_AnovaSpec 0x21078
#define TI_OutputExpr 0x2107c
#define TI_CentCursor 0x21080
//                           equ 0021084h
//                           equ 0021088h
//                           equ 002108Ch
//                           equ 0021090h
#define TI_CkValDeltaX 0x21094
#define TI_CkValDelta 0x21098
#define TI_GrBufClr 0x2109c
#define TI_GrBufCpyV 0x210a0
#define TI_FndSelEQ 0x210a4
#define TI_ClrGraphXY 0x210a8
#define TI_NEDXTYStyle 0x210ac
#define TI_PlotPt 0x210b0
#define TI_NewWindEP 0x210b4
#define TI_DrawAxes 0x210b8
#define TI_SetPenX 0x210bc
#define TI_SetPenY 0x210c0
#define TI_SetPenT 0x210c4
#define TI_TanEquDisp 0x210c8
#define TI_PutAns 0x210cc
#define TI_DispOP1A 0x210d0
//                           equ 00210D4h
#define TI_SetTblGraphDraw 0x210d8
#define TI_MemClear 0x210dc
#define TI_MemSet 0x210e0
#define TI_PointOn 0x210e4
#define TI_ExecuteNewPrgm 0x210e8
#define TI_StrLength 0x210ec
#define TI_VPutMapRec 0x210f0
#define TI_FindAppUp 0x210f4
#define TI_FindAppDown 0x210f8
#define TI_FindApp 0x210fc
#define TI_os_FindAppStart 0x21100
#define TI_SkipAppHeader 0x21104
#define TI_FindAppStart 0x21108
#define TI_IBounds 0x2110c
#define TI_IOffset 0x21110
#define TI_DrawCirc 0x21114
#define TI_CanAlphIns 0x21118
#define TI_CxReDisp 0x2111c
#define TI_GetBaseVer 0x21120
#define TI_OPSet0 0x21124
#define TI_AppGetCBLUSB 0x21128
#define TI_SetIgnoreKey 0x2112c
#define TI_SetSendThisKeyBack 0x21130
#define TI_DisableAPD 0x21134
#define TI_EnableAPD 0x21138
#define TI_Set2IY34 0x2113c
#define TI_ForceCmd 0x21140
#define TI_ApdSetup 0x21144
#define TI_AppSetup 0x21148
//                           equ 002114Ch
#define TI_ReleaseSedit 0x21150
#define TI_InitSmallEditLine 0x21154
#define TI_StartSmallEdit 0x21158
//                           equ 002115Ch
#define TI_SGetTokString 0x21160
#define TI_LoadPattern 0x21164
#define TI_SStringLength 0x21168
#define TI_RestorePenCol 0x2116c
//                           equ 0021170h
#define TI_EmptyHook 0x21174
#define TI_ForceSmallEditReturn 0x21178
#define TI_SaveContext 0x2117c
//                           equ 0021180h
#define TI_ClearRow 0x21184
//                           equ 0021188h
//                           equ 002118Ch
//                           equ 0021190h
//                           equ 0021194h
//                           equ 0021198h
//                           equ 002119Ch
//                           equ 00211A0h
//                           equ 00211A4h
//                           equ 00211A8h
//                           equ 00211ACh
//                           equ 00211B0h
//                           equ 00211B4h
//                           equ 00211B8h
//                           equ 00211BCh
//                           equ 00211C0h
//                           equ 00211C4h
//                           equ 00211C8h
//                           equ 00211CCh
//                           equ 00211D0h
//                           equ 00211D4h
//                           equ 00211D8h
//                           equ 00211DCh
//                           equ 00211E0h
//                           equ 00211E4h
//                           equ 00211E8h
//                           equ 00211ECh
// ;_ret                     equ 00211F0h
//                           equ 00211F4h
#define TI_InitSmallEditLineVar 0x211f8
#define TI_InitSmallEditLineOP1 0x211fc
#define TI_InitSmallEditBoxVar 0x21200
#define TI_InitSmallEditBoxOP1 0x21204
#define TI_RclEntryToEditA 0x21208
#define TI_ErrCustom1 0x2120c
#define TI_ErrCustom2 0x21210
// ;_ret                     equ 0021214h
#define TI_ClearRect 0x21218
#define TI_InvertRect 0x2121c
#define TI_FillRect 0x21220
#define TI_RestoreTextFlags 0x21224
#define TI_InitCellBox 0x21228
#define TI_DrawCell 0x2122c
//                           equ 0021230h
#define TI_InvertCell 0x21234
#define TI_SetCellOverride 0x21238
#define TI_DrawRectBorder 0x2123c
#define TI_ClearCell 0x21240
#define TI_CoverCell 0x21244
#define TI_EraseRectBorder 0x21248
#define TI_FillRectPattern 0x2124c
#define TI_DrawRectBorderClear 0x21250
//                           equ 0021254h
#define TI_VerticalLine 0x21258
#define TI_IBoundsFull 0x2125c
//                           equ 0021260h
//                           equ 0021264h
#define TI_CPoint 0x21268
#define TI_DeleteApp 0x2126c
#define TI_GetModeCellFlagOR 0x21270
#define TI_ResetModeCellFlag 0x21274
#define TI_IsModeCellSet 0x21278
#define TI_GetModeCellFlag 0x2127c
//                           equ 0021280h
#define TI_SetCurCellBoxManager 0x21284
//                           equ 0021288h
#define TI_CellBoxManager 0x2128c
#define TI_StartNewCell 0x21290
#define TI_RunInCellOveride 0x21294
#define TI_RunCellOveride 0x21298
#define TI_ClearCurCell 0x2129c
#define TI_DrawCurCell 0x212a0
#define TI_InvertCurCell 0x212a4
#define TI_CoverCurCell 0x212a8
#define TI_BlinkCell 0x212ac
#define TI_BlinkCellNoLookUp 0x212b0
#define TI_BlinkCurCell 0x212b4
#define TI_BlinkCellToOn 0x212b8
#define TI_BlinkCellToOnNoLookUp 0x212bc
#define TI_BlinkCurCellToOn 0x212c0
#define TI_BlinkCellToOff 0x212c4
#define TI_BlinkCellToOffNoLookUp 0x212c8
#define TI_BlinkCurCellToOff 0x212cc
#define TI_GetCurModeCellFlag 0x212d0
//                           equ 00212D4h
#define TI_StartSmallEditReturn 0x212d8
//                           equ 00212DCh
//                           equ 00212E0h
#define TI_CellKeyHandle 0x212e4
//                           equ 00212E8h
//                           equ 00212ECh
//                           equ 00212F0h
//                           equ 00212F4h
//                           equ 00212F8h
#define TI_EraseAllCells 0x212fc
#define TI_IsCurModeCellSet 0x21300
//                           equ 0021304h
//                           equ 0021308h
//                           equ 002130Ch
//                           equ 0021310h
#define TI_DrawBlnkCell 0x21314
#define TI_ClearBlnkCell 0x21318
#define TI_InvertBlnkCell 0x2131c
#define TI_GetStringInput 0x21320
#define TI_GetStringInput2 0x21324
#define TI_WaitEnterKeyValue 0x21328
#define TI_HorizontalLine 0x2132c
#define TI_CreateAppVar 0x21330
#define TI_CreateProtProg 0x21334
#define TI_CreateVar 0x21338
#define TI_AsmComp 0x2133c
#define TI_GetAsmSize 0x21340
#define TI_SquishPrgm 0x21344
#define TI_ExecutePrgm 0x21348
#define TI_ChkFindSymAsm 0x2134c
#define TI_ParsePrgmName 0x21350
#define TI_CSub 0x21354
#define TI_CAdd 0x21358
#define TI_CSquare 0x2135c
#define TI_CMult 0x21360
#define TI_CRecip 0x21364
#define TI_CDiv 0x21368
#define TI_CAbs 0x2136c
#define TI_AddSquares 0x21370
#define TI_CSqRoot 0x21374
#define TI_CLN 0x21378
#define TI_CLog 0x2137c
#define TI_CTenX 0x21380
#define TI_CEtoX 0x21384
#define TI_CXrootY 0x21388
//                           equ 002138Ch
#define TI_CYtoX 0x21390
#define TI_InvertNonReal 0x21394
#define TI_CTrunc 0x21398
#define TI_CFrac 0x2139c
#define TI_CFloor 0x213a0
#define TI_SrchVLstUp 0x213a4
#define TI_SrchVLstDn 0x213a8
#define TI_FlashWriteDisable 0x213ac
#define TI_Disp 0x213b0
#define TI_GetBytePaged 0x213b4
#define TI_RunCursorHook 0x213b8
#define TI_RunLibraryHook 0x213bc
#define TI_RunRawKeyHook 0x213c0
#define TI_SetCursorHook 0x213c4
#define TI_SetLibraryHook 0x213c8
#define TI_SetGetKeyHook 0x213cc
#define TI_ClrCursorHook 0x213d0
#define TI_ClrLibraryHook 0x213d4
#define TI_ClrRawKeyHook 0x213d8
#define TI_GetKeyHook 0x213dc
#define TI_SetGetCSCHook 0x213e0
#define TI_ClrGetKeyHook 0x213e4
#define TI_SetCatalog2Hook 0x213e8
#define TI_ClrCatalog2Hook 0x213ec
#define TI_SetLocalizeHook 0x213f0
#define TI_ClrLocalizeHook 0x213f4
#define TI_SetTokenHook 0x213f8
#define TI_ClrTokenHook 0x213fc
//                           equ 0021400h
//                           equ 0021404h
#define TI_DispListElementOffLA 0x21408
#define TI_BitVertSplit 0x2140c
#define TI_SetHomescreenHook 0x21410
#define TI_ClrHomescreenHook 0x21414
#define TI_SetWindowHook 0x21418
#define TI_ClrWindowHook 0x2141c
#define TI_SetGraphModeHook 0x21420
#define TI_ClrGraphModeHook 0x21424
#define TI_ParseAndStoreSysVar 0x21428
#define TI_DisplayEditSysVar 0x2142c
#define TI_JForceWIndowSettings 0x21430
#define TI_DelVarArc 0x21434
#define TI_DelVarNoArc 0x21438
#define TI_SetAllPlots 0x2143c
#define TI_SetYeditHook 0x21440
#define TI_ClrYeditHook 0x21444
#define TI_Arc_Unarc 0x21448
#define TI_ArchiveVar 0x2144c
#define TI_UnarchiveVar 0x21450
#define TI_SetFontHook 0x21454
#define TI_ClrFontHook 0x21458
#define TI_SetRegraphHook 0x2145c
#define TI_ClrRegraphHook 0x21460
#define TI_RunGraphingHook 0x21464
#define TI_SetTraceHook 0x21468
#define TI_ClrTraceHook 0x2146c
#define TI_RunTraceHook 0x21470
#define TI_NDeriv 0x21474
#define TI_PolarDerivative 0x21478
#define TI_JForceGraphNoKey 0x2147c
#define TI_JForceGraphKey 0x21480
#define TI_PowerOff 0x21484
#define TI_GetKeyRetOff 0x21488
#define TI_FindGroupSym 0x2148c
#define TI_LoadDEIndPaged 0x21490
#define TI_SetUpPagedPtr 0x21494
#define TI_PagedGet 0x21498
#define TI_SetParserHook 0x2149c
#define TI_ClrParserHook 0x214a0
#define TI_SetAppChangeHook 0x214a4
#define TI_ClrAppChangeHook 0x214a8
#define TI_SetGraphicsHook 0x214ac
#define TI_ClrGraphicsHook 0x214b0
#define TI_ILineNoGraphicsHook 0x214b4
#define TI_ILineNoHook 0x214b8
//                           equ 00214BCh
#define TI_DeleteTempPrograms 0x214c0
#define TI_SetCatalog1Hook 0x214c4
#define TI_ClrCatalog1Hook 0x214c8
#define TI_SetHelpHook 0x214cc
#define TI_ClrHelpHook 0x214d0
#define TI_DispCatalogEnd 0x214d4
#define TI_GetMenuKeypress 0x214d8
#define TI_GetCatalogItem 0x214dc
#define TI_RunCatalog2Hook 0x214e0
#define TI_RunCatalog1Hook 0x214e4
//                           equ 00214E8h
//                           equ 00214ECh
#define TI_DispMenuTitle 0x214f0
//                           equ 00214F4h
#define TI_SetCxReDispHook 0x214f8
#define TI_ClrCxReDispHook 0x214fc
#define TI_DrawStatusBarMode 0x21500
#define TI_BufClr 0x21504
#define TI_UnOPExec2 0x21508
#define TI_BinOPExec2 0x2150c
#define TI_LoadMenuB 0x21510
#define TI_DisplayVarInfo 0x21514
#define TI_SetMenuHook 0x21518
#define TI_ClrMenuHook 0x2151c
#define TI_GetBCOffSetIX 0x21520
#define TI_GetBCOffSetIX_ 0x21524
#define TI_ForceFullScreen 0x21528
#define TI_HLMinus5 0x2152c
// ;_ret                     equ 0021530h
//                           equ 0021534h
//                           equ 0021538h
#define TI_Arc_Unarc_ 0x2153c
#define TI_RclExit 0x21540
#define TI_SetSilentLinkHook 0x21544
#define TI_ClrSilentLinkHook 0x21548
#define TI_TwoVarSet 0x2154c
#define TI_ExecClassCToken 0x21550
#define TI_ExecClass3Token 0x21554
#define TI_GetSysInfo 0x21558
#define TI_RunChkCTenX 0x2155c
#define TI_TenXNoClr 0x21560
//                           equ 0021564h
//                           equ 0021568h
#define TI_GetVarVersion 0x2156c
#define TI_ParseGraphCmdToken 0x21570
//                           equ 0021574h
#define TI_DeleteTempEditEqu 0x21578
#define TI_PromptMoveBackLeft 0x2157c
#define TI_WPutSEOLRes10E 0x21580
#define TI_InvertTextInsMode 0x21584
//                           equ 0021588h
#define TI_ResetDefaults 0x2158c
#define TI_ZeroFinanceVars 0x21590
#define TI_DispHeader 0x21594
#define TI_JForceGroup 0x21598
//                           equ 002159Ch
//                           equ 00215A0h
#define TI_DispCoords 0x215a4
//                           equ 00215A8h
//                           equ 00215ACh
#define TI_ChkTmr 0x215b0
#define TI_ClockOff 0x215b4
#define TI_ClockOn 0x215b8
//                           equ 00215BCh
#define TI_GetDate 0x215c0
#define TI_GetDateString 0x215c4
#define TI_GetDtFmt 0x215c8
#define TI_GetDtStr 0x215cc
#define TI_GetTime 0x215d0
#define TI_FormTime 0x215d4
#define TI_GetTmFmt 0x215d8
#define TI_GetTmStr 0x215dc
#define TI_SetZeroOne 0x215e0
#define TI_SetDate 0x215e4
#define TI_IsOneTwoThree 0x215e8
#define TI_SetTime 0x215ec
#define TI_IsOP112or24 0x215f0
#define TI_ChkTimer0 0x215f4
#define TI_TimeCnv 0x215f8
#define TI_ClrWindowAndFlags 0x215fc
#define TI_ResetAllLists 0x21600
#define TI_DispValue 0x21604
//                           equ 0021608h
//                           equ 002160Ch
//                           equ 0021610h
#define TI_CpOP1OP2Rounded 0x21614
#define TI_CpOP1OP2Rounded2 0x21618
//                           equ 002161Ch
//                           equ 0021620h
#define TI_ResetIOPrompt 0x21624
//                           equ 0021628h
#define TI_SetUpEditor 0x2162c
#define TI_SortA 0x21630
#define TI_SortD 0x21634
//                           equ 0021638h
#define TI_IsOP1ResID 0x2163c
//                           equ 0021640h
//                           equ 0021644h
//                           equ 0021648h
#define TI_ForceModeKeypress 0x2164c
#define TI_DispAboutScreen 0x21650
#define TI_ChkHelpHookVer 0x21654
#define TI_Draw32 0x21658
//                           equ 002165Ch
//                           equ 0021660h
//                           equ 0021664h
#define TI_DrawPlotStatus 0x21668
#define TI_DrawTableEditor 0x2166c
#define TI_DisplayListNameEquals 0x21670
#define TI_DisplayListHeader 0x21674
#define TI_DispMatrixDimensions 0x21678
#define TI_HighlightListEdItem 0x2167c
//                           equ 0021680h
//                           equ 0021684h
#define TI_MatrixName 0x21688
//                           equ 002168Ch
//                           equ 0021690h
//                           equ 0021694h
//                           equ 0021698h
//                           equ 002169Ch
#define TI_ChkCxMainPtr 0x216a0
#define TI_NumError02_ 0x216a4
//                           equ 00216A8h
#define TI_SetupEmptyEditTempEqu 0x216ac
#define TI_Res1IY0E 0x216b0
#define TI_RestoreBuffer 0x216b4
//                           equ 00216B8h
//                           equ 00216BCh
//                           equ 00216C0h
//                           equ 00216C4h
//                           equ 00216C8h
//                           equ 00216CCh
#define TI_DisplayListEquals 0x216d0
#define TI_GetCurPlotListOffset 0x216d4
#define TI_GoToLastRow 0x216d8
#define TI_DrawRectBorder_ 0x216dc
//                           equ 00216E0h
//                           equ 00216E4h
//                           equ 00216E8h
//                           equ 00216ECh
#define TI_NamedListToOP1 0x216f0
//                           equ 00216F4h
//                           equ 00216F8h
//                           equ 00216FCh
#define TI_InitUSBDeviceCallback 0x21700
#define TI_KillUSBDevice 0x21704
#define TI_SetUSBConfiguration 0x21708
#define TI_RequestUSBData 0x2170c
#define TI_StopReceivingUSBData 0x21710
#define TI_SetVertGraphActive 0x21714
#define TI_ClrVertGraphActive 0x21718
#define TI_SetUSBActivityHook 0x2171c
#define TI_ClrUSBActivityHook 0x21720
// ;_ret                     equ 0021724h
#define TI_GetCurPlotOffsetPrev 0x21728
#define TI_SplitUpdateStatPlotLists 0x2172c
#define TI_GraphLine 0x21730
//                           equ 0021734h
//                           equ 0021738h
//                           equ 002173Ch
//                           equ 0021740h
//                           equ 0021744h
//                           equ 0021748h
#define TI_ZIfInTblEditor 0x2174c
//                           equ 0021750h
#define TI_GetCurPlotOffset 0x21754
//                           equ 0021758h
//                           equ 002175Ch
//                           equ 0021760h
//                           equ 0021764h
//                           equ 0021768h
#define TI_UpdateStatPlotLists 0x2176c
#define TI_ChkSomethingElseFPS5 0x21770
#define TI_ChkSomethingFPS5 0x21774
#define TI_VDispRealOP1 0x21778
#define TI_DispXEqualsNum 0x2177c
#define TI_ResetGraphSettings 0x21780
#define TI_InitializeVariables 0x21784
// ;_ret                     equ 0021788h
#define TI_DelVarSym 0x2178c
#define TI_FindAppUpNoCase 0x21790
#define TI_FindAppDnNoCase 0x21794
#define TI_SetupHome 0x21798
#define TI_GrPutawayFull 0x2179c
// ;_ret                     equ 00217A0h
#define TI_ToggleUSBSmartPadInput 0x217a4
#define TI_IsUSBDeviceConnected 0x217a8
#define TI_PolarEquToOP1 0x217ac
#define TI_ParamXEquToOP1 0x217b0
#define TI_ParamYEquToOP1 0x217b4
#define TI_DispTestModeResetComplete 0x217b8
#define TI_PTTReset 0x217bc
#define TI_FindAppCustom 0x217c0
#define TI_ClearGraphStyles 0x217c4
#define TI_BufToNextBASICSeparator 0x217c8
//                           equ 00217CCh
//                           equ 00217D0h
#define TI_ZooStandard 0x217d4
//                           equ 00217D8h
//                           equ 00217DCh
//                           equ 00217E0h
//                           equ 00217E4h
//                           equ 00217E8h
//                           equ 00217ECh
//                           equ 00217F0h
//                           equ 00217F4h
//                           equ 00217F8h
//                           equ 00217FCh
//                           equ 0021800h
//                           equ 0021804h
//                           equ 0021808h
//                           equ 002180Ch
#define TI_AddHistoryEntryString 0x21810
#define TI_CurrEntryToPrevEntry 0x21814
//                           equ 0021818h
//                           equ 002181Ch
//                           equ 0021820h
//                           equ 0021824h
//                           equ 0021828h
//                           equ 002182Ch
//                           equ 0021830h
//                           equ 0021834h
//                           equ 0021838h
//                           equ 002183Ch
//                           equ 0021840h
//                           equ 0021844h
//                           equ 0021848h
//                           equ 002184Ch
//                           equ 0021850h
//                           equ 0021854h
//                           equ 0021858h
//                           equ 002185Ch
//                           equ 0021860h
//                           equ 0021864h
//                           equ 0021868h
//                           equ 002186Ch
//                           equ 0021870h
//                           equ 0021874h
//                           equ 0021878h
//                           equ 002187Ch
//                           equ 0021880h
//                           equ 0021884h
//                           equ 0021888h
//                           equ 002188Ch
//                           equ 0021890h
//                           equ 0021894h
//                           equ 0021898h
//                           equ 002189Ch
//                           equ 00218A0h
//                           equ 00218A4h
//                           equ 00218A8h
//                           equ 00218ACh
//                           equ 00218B0h
//                           equ 00218B4h
//                           equ 00218B8h
//                           equ 00218BCh
//                           equ 00218C0h
//                           equ 00218C4h
//                           equ 00218C8h
//                           equ 00218CCh
//                           equ 00218D0h
//                           equ 00218D4h
//                           equ 00218D8h
//                           equ 00218DCh
//                           equ 00218E0h
//                           equ 00218E4h
//                           equ 00218E8h
//                           equ 00218ECh
#define TI_RunInitialBootMenu 0x218f0
//                           equ 00218F4h
//                           equ 00218F8h
//                           equ 00218FCh
#define TI_Clr05RclFlags 0x21900
//                           equ 0021904h
//                           equ 0021908h
//                           equ 002190Ch
//                           equ 0021910h
#define TI_DeleteHistoryEntry 0x21914
//                           equ 0021918h
//                           equ 002191Ch
//                           equ 0021920h
//                           equ 0021924h
//                           equ 0021928h
//                           equ 002192Ch
//                           equ 0021930h
//                           equ 0021934h
//                           equ 0021938h
//                           equ 002193Ch
#define TI_CommonKeys_ 0x21940
//                           equ 0021944h
//                           equ 0021948h
//                           equ 002194Ch
//                           equ 0021950h
//                           equ 0021954h
//                           equ 0021958h
//                           equ 002195Ch
//                           equ 0021960h
//                           equ 0021964h
//                           equ 0021968h
//                           equ 002196Ch
//                           equ 0021970h
//                           equ 0021974h
//                           equ 0021978h
//                           equ 002197Ch
//                           equ 0021980h
//                           equ 0021984h
//                           equ 0021988h
//                           equ 002198Ch
//                           equ 0021990h
//                           equ 0021994h
#define TI_ResetLastEntryStack 0x21998
//                           equ 002199Ch
//                           equ 00219A0h
#define TI_jp_JForceCmdNoChar 0x219a4
#define TI_Load_LFont 0x219a8
//                           equ 00219ACh
//                           equ 00219B0h
//                           equ 00219B4h
//                           equ 00219B8h
//                           equ 00219BCh
//                           equ 00219C0h
//                           equ 00219C4h
//                           equ 00219C8h
//                           equ 00219CCh
//                           equ 00219D0h
//                           equ 00219D4h
//                           equ 00219D8h
#define TI_EnterSelfTest 0x219dc
#define TI_DrawEntrySepLine 0x219e0
//                           equ 00219E4h
#define TI_GetGraphModeProperties 0x219e8
//                           equ 00219ECh
//                           equ 00219F0h
//                           equ 00219F4h
//                           equ 00219F8h
//                           equ 00219FCh
//                           equ 0021A00h
//                           equ 0021A04h
//                           equ 0021A08h
//                           equ 0021A0Ch
#define TI_ClrLCDAll 0x21a10
#define TI_BufIPoint 0x21a14
//                           equ 0021A18h
//                           equ 0021A1Ch
//                           equ 0021A20h
//                           equ 0021A24h
#define TI_SetDrawFGColorA 0x21a28
//                           equ 0021A2Ch
//                           equ 0021A30h
//                           equ 0021A34h
#define TI_DrawGraphBackground 0x21a38
#define TI_DrawStatusBar 0x21a3c
//                           equ 0021A40h
//                           equ 0021A44h
//                           equ 0021A48h
//                           equ 0021A4Ch
#define TI_DrawBatteryIndicator 0x21a50
#define TI_DrawBatteryStatus 0x21a54
#define TI_VDispHL 0x21a58
#define TI_PDspGrphNoColorReload 0x21a5c
//                           equ 0021A60h
//                           equ 0021A64h
//                           equ 0021A68h
//                           equ 0021A6Ch
//                           equ 0021A70h
//                           equ 0021A74h
//                           equ 0021A78h
//                           equ 0021A7Ch
//                           equ 0021A80h
//                           equ 0021A84h
//                           equ 0021A88h
//                           equ 0021A8Ch
//                           equ 0021A90h
//                           equ 0021A94h
//                           equ 0021A98h
//                           equ 0021A9Ch
//                           equ 0021AA0h
//                           equ 0021AA4h
//                           equ 0021AA8h
//                           equ 0021AACh
//                           equ 0021AB0h
#define TI_DrawStatusBarInfo 0x21ab4
#define TI_RestoreLCDBrightness 0x21ab8
#define TI_RestoreLCDBrightness_ 0x21abc
#define TI_DimLCDSlow 0x21ac0
//                           equ 0021AC4h
//                           equ 0021AC8h
//                           equ 0021ACCh
//                           equ 0021AD0h
//                           equ 0021AD4h
//                           equ 0021AD8h
//                           equ 0021ADCh
#define TI_SetTextFGBGcolors 0x21ae0
#define TI_SetTextFGBGcolors_ 0x21ae4
#define TI_SetTextBGcolor 0x21ae8
#define TI_VPutPS 0x21aec
//                           equ 0021AF0h
//                           equ 0021AF4h
//                           equ 0021AF8h
//                           equ 0021AFCh
#define TI_DrawTILogo 0x21b00
#define TI_DrawThickRectBorder 0x21b04
//                           equ 0021B08h
#define TI_DrawStatusBarTextClr 0x21b0c
//                           equ 0021B10h
//                           equ 0021B14h
//                           equ 0021B18h
//                           equ 0021B1Ch
#define TI_VPutPSN 0x21b20
//                           equ 0021B24h
//                           equ 0021B28h
//                           equ 0021B2Ch
//                           equ 0021B30h
#define TI_RStrGraphFlags 0x21b34
//                           equ 0021B38h
//                           equ 0021B3Ch
#define TI_VPutMapSpecial 0x21b40
//                           equ 0021B44h
//                           equ 0021B48h
//                           equ 0021B4Ch
//                           equ 0021B50h
//                           equ 0021B54h
//                           equ 0021B58h
//                           equ 0021B5Ch
//                           equ 0021B60h
#define TI_DrawSprite16bpp 0x21b64
//                           equ 0021B68h
//                           equ 0021B6Ch
//                           equ 0021B70h
//                           equ 0021B74h
//                           equ 0021B78h
//                           equ 0021B7Ch
//                           equ 0021B80h
//                           equ 0021B84h
//                           equ 0021B88h
//                           equ 0021B8Ch
//                           equ 0021B90h
//                           equ 0021B94h
//                           equ 0021B98h
//                           equ 0021B9Ch
//                           equ 0021BA0h
//                           equ 0021BA4h
//                           equ 0021BA8h
#define TI_GetColorValue 0x21bac
//                           equ 0021BB0h
//                           equ 0021BB4h
//                           equ 0021BB8h
//                           equ 0021BBCh
//                           equ 0021BC0h
#define TI_GraphBGColorToDrawBGColor 0x21bc4
#define TI_SetWhiteDrawBGColor 0x21bc8
//                           equ 0021BCCh
#define TI_ChkResAppTextSave 0x21bd0
#define TI_ChkCxMain 0x21bd4
//                           equ 0021BD8h
//                           equ 0021BDCh
#define TI_DrawRectBorder__ 0x21be0
//                           equ 0021BE4h
//                           equ 0021BE8h
//                           equ 0021BECh
//                           equ 0021BF0h
//                           equ 0021BF4h
//                           equ 0021BF8h
//                           equ 0021BFCh
//                           equ 0021C00h
//                           equ 0021C04h
//                           equ 0021C08h
//                           equ 0021C0Ch
//                           equ 0021C10h
//                           equ 0021C14h
//                           equ 0021C18h
//                           equ 0021C1Ch
//                           equ 0021C20h
//                           equ 0021C24h
//                           equ 0021C28h
//                           equ 0021C2Ch
//                           equ 0021C30h
//                           equ 0021C34h
//                           equ 0021C38h
//                           equ 0021C3Ch
//                           equ 0021C40h
//                           equ 0021C44h
#define TI_DrawLineEndEntry 0x21c48
//                           equ 0021C4Ch
//                           equ 0021C50h
// ;_ret                     equ 0021C54h
//                           equ 0021C58h
//                           equ 0021C5Ch
//                           equ 0021C60h
//                           equ 0021C64h
//                           equ 0021C68h
#define TI_BitGrfFuncM 0x21c6c
// ;_ret                     equ 0021C70h
#define TI_GetScrollPxlAmount 0x21c74
#define TI_os_PushErrorHandler 0x21c78
#define TI_os_PopErrorHandler 0x21c7c
#define TI_os_ThrowError 0x21c80
#define TI_os_RealCopy 0x21c84
#define TI_os_RealAcosRad 0x21c88
#define TI_os_RealAsinRad 0x21c8c
#define TI_os_RealAtanRad 0x21c90
#define TI_os_RealAdd 0x21c94
#define TI_os_CplxAdd 0x21c98
#define TI_os_RealCompare 0x21c9c
#define TI_os_RealCosRad 0x21ca0
#define TI_os_RealRadToDeg 0x21ca4
#define TI_os_RealDiv 0x21ca8
#define TI_os_RealExp 0x21cac
#define TI_os_RealFloor 0x21cb0
#define TI_os_RealToStr 0x21cb4
#define TI_os_RealFrac 0x21cb8
#define TI_os_RealGcd 0x21cbc
#define TI_os_RealRoundInt 0x21cc0
#define TI_os_RealLcm 0x21cc4
#define TI_os_RealLog 0x21cc8
#define TI_os_RealMax 0x21ccc
#define TI_os_RealMin 0x21cd0
#define TI_os_RealMul 0x21cd4
#define TI_os_RealNcr 0x21cd8
#define TI_os_RealNeg 0x21cdc
#define TI_os_RealNpr 0x21ce0
#define TI_os_RealPow 0x21ce4
#define TI_os_RealDegToRad 0x21ce8
#define TI_os_RealRandInt 0x21cec
#define TI_os_RealInv 0x21cf0
#define TI_os_RealMod 0x21cf4
#define TI_os_RealRound 0x21cf8
#define TI_os_RealSinRad 0x21cfc
#define TI_os_RealSqrt 0x21d00
#define TI_os_RealSub 0x21d04
#define TI_os_RealTanRad 0x21d08
#define TI_os_StrToReal 0x21d0c
#define TI_os_RealTrunc 0x21d10
#define TI_os_SetFlagBits 0x21d14
#define TI_os_ResetFlagBits 0x21d18
#define TI_os_TestFlagBits 0x21d1c
#define TI_os_SetFlagByte 0x21d20
#define TI_os_GetFlagByte 0x21d24
#define TI_os_GetCursorPos 0x21d28
#define TI_os_PutStrFull 0x21d2c
#define TI_os_PutStrLine 0x21d30
#define TI_os_SetCursorPos 0x21d34
#define TI_os_GetKey 0x21d38
#define TI_os_GetCSC 0x21d3c
#define TI_os_AppInit 0x21d40
//                           equ 0021D44h
#define TI_ChkBCIs0 0x21d48
#define TI_ChkDEIs0 0x21d4c
#define TI_ChkHLIs0 0x21d50
#define TI_SetAToBCU 0x21d54
#define TI_SetAToDEU 0x21d58
#define TI_SetAToHLU 0x21d5c
#define TI_SetBCUToA 0x21d60
#define TI_SetBCUToB 0x21d64
#define TI_SetDEUToA 0x21d68
#define TI_SetDEUToB 0x21d6c
#define TI_SetHLUToA 0x21d70
#define TI_SetHLUToB 0x21d74
#define TI_SignExtendBC 0x21d78
#define TI_SignExtendDE 0x21d7c
#define TI_SignExtendHL 0x21d80
#define TI_SetBCUTo0 0x21d84
#define TI_SetDEUTo0 0x21d88
#define TI_SetHLUTo0 0x21d8c
#define TI_DivHLByA 0x21d90
#define TI_CpHLDE_s 0x21d94
#define TI_CpHLDE_ 0x21d98
#define TI_LoadDEInd_s 0x21d9c
#define TI_LoadDEInd 0x21da0
#define TI_CpHLDEBC 0x21da4
#define TI_NegBC 0x21da8
#define TI_NegDE 0x21dac
#define TI_StrCmpre 0x21db0
#define TI_AddHLAndA 0x21db4
#define TI_NextFlashPage 0x21db8
#define TI_PrevFlashPage 0x21dbc
#define TI_SwapEndianHL_s 0x21dc0
#define TI_ReloadAppEntryVecs 0x21dc4
//                           equ 0021DC8h
//                           equ 0021DCCh
//                           equ 0021DD0h
//                           equ 0021DD4h
//                           equ 0021DD8h
//                           equ 0021DDCh
#define TI_os_ClearVRAMLines 0x21de0
#define TI_os_DisableCursor 0x21de4
#define TI_os_EnableCursor 0x21de8
//                           equ 0021DECh
//                           equ 0021DF0h
//                           equ 0021DF4h
//                           equ 0021DF8h
//                           equ 0021DFCh
#define TI_os_FontDrawText 0x21e00
//                           equ 0021E04h
//                           equ 0021E08h
//                           equ 0021E0Ch
//                           equ 0021E10h
#define TI_os_FontGetHeight 0x21e14
#define TI_os_FontGetWidth 0x21e18
#define TI_os_InitDrawing 0x21e1c
#define TI_os_SetDrawBGColor 0x21e20
#define TI_os_SetDrawFGColor 0x21e24
#define TI_os_FontSelect 0x21e28
//                           equ 0021E2Ch
//                           equ 0021E30h
#define TI_tolower 0x21e34
#define TI_toupper 0x21e38
//                           equ 0021E3Ch
//                           equ 0021E40h
//                           equ 0021E44h
//                           equ 0021E48h
//                           equ 0021E4Ch
//                           equ 0021E50h
//                           equ 0021E54h
//                           equ 0021E58h
//                           equ 0021E5Ch
//                           equ 0021E60h
//                           equ 0021E64h
#define TI_ChkACplx 0x21e68
//                           equ 0021E6Ch
#define TI_os_RclAns 0x21e70
//                           equ 0021E74h
//                           equ 0021E78h
//                           equ 0021E7Ch
//                           equ 0021E80h
//                           equ 0021E84h
//                           equ 0021E88h
#define TI_SetPolarEquToOP1 0x21e8c
//                           equ 0021E90h
//                           equ 0021E94h
//                           equ 0021E98h
//                           equ 0021E9Ch
//                           equ 0021EA0h
//                           equ 0021EA4h
//                           equ 0021EA8h
//                           equ 0021EACh
//                           equ 0021EB0h
//                           equ 0021EB4h
//                           equ 0021EB8h
//                           equ 0021EBCh
//                           equ 0021EC0h
//                           equ 0021EC4h
#define TI_os_SetTimer1 0x21ec8
#define TI_os_DisableTimer1 0x21ecc
#define TI_os_SetKbdKey 0x21ed0
#define TI_os_GetSystemInfo 0x21ed4
//                           equ 0021ED8h
//                           equ 0021EDCh
#define TI_DispHL 0x21ee0
#define TI_os_GetDrawBGColor_BROKEN 0x21ee4 //  fixed in OS 5.2
#define TI_os_GetDrawFGColor 0x21ee8
#define TI_os_FontGetID 0x21eec
//                           equ 0021EF0h
#define TI_os_RealToInt24 0x21ef4
#define TI_os_Int24ToReal 0x21ef8
#define TI_GetOpenLibPtr 0x21efc
#define TI_RestoreColCoordinates 0x21f00
//                           equ 0021F04h
//                           equ 0021F08h
//                           equ 0021F0Ch
//                           equ 0021F10h
//                           equ 0021F14h
//                           equ 0021F18h
//                           equ 0021F1Ch
//                           equ 0021F20h
//                           equ 0021F24h
//                           equ 0021F28h
//                           equ 0021F2Ch
//                           equ 0021F30h
//                           equ 0021F34h
//                           equ 0021F38h
//                           equ 0021F3Ch
//                           equ 0021F40h
#define TI_VPutMapNoReset0IY23 0x21f44
//                           equ 0021F48h
//                           equ 0021F4Ch
#define TI_BufCpy 0x21f50
//                           equ 0021F54h
//                           equ 0021F58h
//                           equ 0021F5Ch
#define TI_DrawStandardEntrySepLine 0x21f60
#define TI_DrawHomeNewSepLine 0x21f64
#define TI_DrawStatusBarText 0x21f68
//                           equ 0021F6Ch
//                           equ 0021F70h
//                           equ 0021F74h
//                           equ 0021F78h
//                           equ 0021F7Ch
#define TI_MovFrOP1OP2 0x21f80
//                           equ 0021F84h
//                           equ 0021F88h
//                           equ 0021F8Ch
//                           equ 0021F90h
//                           equ 0021F94h
#define TI_ChkInRam 0x21f98
//                           equ 0021F9Ch
//                           equ 0021FA0h
#define TI_FontGetWidth 0x21fa4
#define TI_os_ForceCmdNoChar 0x21fa8
#define TI_os_DelVarEntry 0x21fac
#define TI_os_GetSymTablePtr 0x21fb0
#define TI_os_NextSymEntry 0x21fb4
#define TI_os_ChkFindSym 0x21fb8
#define TI_os_GetVarSize 0x21fbc
#define TI_os_GetVarSizeBytes 0x21fc0
//                           equ 0021FC4h
#define TI_os_GetRealListElement 0x21fc8
#define TI_os_GetRealVar 0x21fcc
#define TI_os_ResizeList 0x21fd0
#define TI_os_ResizeMatrix 0x21fd4
//                           equ 0021FD8h
#define TI_os_SetRealListElement 0x21fdc
#define TI_os_SetRealVar 0x21fe0
#define TI_os_GetAppVersionString 0x21fe4
//                           equ 0021FE8h
//                           equ 0021FECh
#define TI_os_MemChk 0x21ff0
//                           equ 0021FF4h
//                           equ 0021FF8h
//                           equ 0021FFCh
//                           equ 0022000h
//                           equ 0022004h
//                           equ 0022008h
//                           equ 002200Ch
//                           equ 0022010h
//                           equ 0022014h
//                           equ 0022018h
//                           equ 002201Ch
//                           equ 0022020h
//                           equ 0022024h
//                           equ 0022028h
//                           equ 002202Ch
//                           equ 0022030h
//                           equ 0022034h
//                           equ 0022038h
//                           equ 002203Ch
#define TI_ArcChk 0x22040
#define TI_LoadDEIndFlash 0x22044
#define TI_ChkInRamB 0x22048
//                           equ 002204Ch
//                           equ 0022050h
//                           equ 0022054h
#define TI_os_InitUSBDeviceCallback 0x22058
#define TI_os_KillUSBDevice 0x2205c
#define TI_os_SetUSBConfiguration 0x22060
#define TI_os_RequestUSBData 0x22064
#define TI_os_StopReceivingUSBData 0x22068
//                           equ 002206Ch
//                           equ 0022070h
#define TI_Mov11ToOP1 0x22074
#define TI_FindFreeArcSpot 0x22078
//                           equ 002207Ch
#define TI_os_SetTimer2 0x22080
#define TI_os_DisableTimer2 0x22084
//                           equ 0022088h
// ;_ret                     equ 002208Ch
#define TI_os_GetYDrawLocation 0x22090
#define TI_os_SetYDrawLocation 0x22094
#define TI_RunLocalizeHook 0x22098
#define TI_os_IntSize 0x2209c
#define TI_os_ClearStatusBarLow 0x220a0
//                           equ 00220A4h
#define TI_NMIHandler 0x220a8
//                           equ 00220ACh
//                           equ 00220B0h
//                           equ 00220B4h
//                           equ 00220B8h
//                           equ 00220BCh
//                           equ 00220C0h
//                           equ 00220C4h
//                           equ 00220C8h
//                           equ 00220CCh
//                           equ 00220D0h
//                           equ 00220D4h
//                           equ 00220D8h
//                           equ 00220DCh
//                           equ 00220E0h
//                           equ 00220E4h
//                           equ 00220E8h
//                           equ 00220ECh
//                           equ 00220F0h
//                           equ 00220F4h
//                           equ 00220F8h
//                           equ 00220FCh
//                           equ 0022100h
//                           equ 0022104h
//                           equ 0022108h
//                           equ 002210Ch
//                           equ 0022110h
//                           equ 0022114h
//                           equ 0022118h
//                           equ 002211Ch
//                           equ 0022120h
//                           equ 0022124h
//                           equ 0022128h
//                           equ 002212Ch
//                           equ 0022130h
//                           equ 0022134h
//                           equ 0022138h
//                           equ 002213Ch
//                           equ 0022140h
//                           equ 0022144h
//                           equ 0022148h
//                           equ 002214Ch
//                           equ 0022150h
//                           equ 0022154h
//                           equ 0022158h
//                           equ 002215Ch
//                           equ 0022160h
#define TI_os_RToP 0x22164
#define TI_os_PToR 0x22168
#define TI_os_ResetEditOpen 0x2216c
#define TI_os_FloatToReal 0x22170
#define TI_os_RealToFloat 0x22174
#define TI_os_FontDrawTransText 0x22178
#define TI_os_DelAppVar 0x2217c
#define TI_os_GetAppVarData 0x22180
#define TI_os_CreateAppVar 0x22184
//                           equ 0022188h
//                           equ 002218Ch
//                           equ 0022190h
//                           equ 0022194h
#define TI_os_CreateString 0x22198
#define TI_os_GetStringData 0x2219c
//                           equ 00221A0h
//                           equ 00221A4h
//                           equ 00221A8h
//                           equ 00221ACh
//                           equ 00221B0h
//                           equ 00221B4h
//                           equ 00221B8h
//                           equ 00221BCh
//                           equ 00221C0h
//                           equ 00221C4h
//                           equ 00221C8h
//                           equ 00221CCh
//                           equ 00221D0h
//                           equ 00221D4h
//                           equ 00221D8h
//                           equ 00221DCh
//                           equ 00221E0h
//                           equ 00221E4h
//                           equ 00221E8h
//                           equ 00221ECh
//                           equ 00221F0h
//                           equ 00221F4h
//                           equ 00221F8h
//                           equ 00221FCh
//                           equ 0022200h
//                           equ 0022204h
//                           equ 0022208h
//                           equ 002220Ch
//                           equ 0022210h
//                           equ 0022214h
//                           equ 0022218h
//                           equ 002221Ch
//                           equ 0022220h
//                           equ 0022224h
//                           equ 0022228h
//                           equ 002222Ch
//                           equ 0022230h
//                           equ 0022234h
//                           equ 0022238h
//                           equ 002223Ch
#define TI_os_CreateEquation 0x22240
#define TI_os_GetEquationData 0x22244
//  Boot Calls
// -----------------------------------
#define TI_boot_GetHardwareVers 0x84
#define TI_boot_GetKeyID 0x88
#define TI_boot_GetBootVerMinor 0x8c
#define TI_boot_GetBootVerBuild 0x90
#define TI_dbgout 0x94
#define TI__longjmp 0x98
#define TI__memchr 0x9c
#define TI__memcmp 0xa0
#define TI__memcpy 0xa4
#define TI__memmove 0xa8
#define TI__memset 0xac
#define TI__memclear 0xb0
#define TI_printf 0xb4
#define TI__setjmp 0xb8
#define TI_sprintf 0xbc
#define TI__strcat 0xc0
#define TI__strchr 0xc4
#define TI__strcmp 0xc8
#define TI__strcpy 0xcc
#define TI__strcspn 0xd0
#define TI__strlen 0xd4
#define TI__strncat 0xd8
#define TI__strncmp 0xdc
#define TI__strncpy 0xe0
#define TI__strpbrk 0xe4
#define TI__strrchr 0xe8
#define TI__strspn 0xec
#define TI__strstr 0xf0
#define TI_strtok 0xf4
#define TI_ret 0xf8
#define TI__bldiy 0xfc
#define TI__bshl 0x100
#define TI__bshru 0x104
#define TI__bstiy 0x108
#define TI__bstix 0x10c
#define TI__case 0x110
#define TI__case16 0x114
#define TI__case16D 0x118
#define TI__case24 0x11c
#define TI__case24D 0x120
#define TI__case8 0x124
#define TI__case8D 0x128
#define TI__frameset 0x12c
#define TI__frameset0 0x130
#define TI__iand 0x134
#define TI__icmpzero 0x138
#define TI__idivs 0x13c
#define TI__idivu 0x140
#define TI__idvrmu 0x144
#define TI__ildix 0x148
#define TI__ildiy 0x14c
#define TI__imul_b 0x150
#define TI__imulu 0x154
#define TI__imuls 0x158
#define TI__indcall 0x15c
#define TI__ineg 0x160
#define TI__inot 0x164
#define TI__ior 0x168
#define TI__irems 0x16c
#define TI__iremu 0x170
#define TI__ishl 0x174
#define TI__ishl_b 0x178
#define TI__ishrs 0x17c
#define TI__ishrs_b 0x180
#define TI__ishru 0x184
#define TI__ishru_b 0x188
#define TI__istix 0x18c
#define TI__istiy 0x190
#define TI__itol 0x194
#define TI__ixor 0x198
#define TI__ladd 0x19c
#define TI__ladd_b 0x1a0
#define TI__land 0x1a4
#define TI__lcmps 0x1a8
#define TI__lcmpu 0x1ac
#define TI__lcmpzero 0x1b0
#define TI__ldivs 0x1b4
#define TI__ldivu 0x1b8
#define TI__ldvrmu 0x1bc
#define TI__lldix 0x1c0
#define TI__lldiy 0x1c4
#define TI__lmuls 0x1c8
#define TI__lmulu 0x1cc
#define TI__lneg 0x1d0
#define TI__lnot 0x1d4
#define TI__lor 0x1d8
#define TI__lrems 0x1dc
#define TI__lremu 0x1e0
#define TI__lshl 0x1e4
#define TI__lshrs 0x1e8
#define TI__lshru 0x1ec
#define TI__lstix 0x1f0
#define TI__lstiy 0x1f4
#define TI__lsub 0x1f8
#define TI__lxor 0x1fc
#define TI__sand 0x200
#define TI__scmpzero 0x204
#define TI__sdivs 0x208
#define TI__sdivu 0x20c
#define TI__seqcase 0x210
#define TI__seqcaseD 0x214
#define TI__setflag 0x218
#define TI__sldix 0x21c
#define TI__sldiy 0x220
#define TI__smuls 0x224
#define TI__smulu 0x228
#define TI__sneg 0x22c
#define TI__snot 0x230
#define TI__sor 0x234
#define TI__srems 0x238
#define TI__sremu 0x23c
#define TI__sshl 0x240
#define TI__sshl_b 0x244
#define TI__sshrs 0x248
#define TI__sshrs_b 0x24c
#define TI__sshru 0x250
#define TI__sshru_b 0x254
#define TI__sstix 0x258
#define TI__sstiy 0x25c
#define TI__stoi 0x260
#define TI__stoiu 0x264
#define TI__sxor 0x268
#define TI__fppack 0x26c
#define TI__fadd 0x270
#define TI__fcmp 0x274
#define TI__fdiv 0x278
#define TI__ftol 0x27c
#define TI__ultof 0x280
#define TI__ltof 0x284
#define TI__fmul 0x288
#define TI__fneg 0x28c
#define TI__fsub 0x290
#define TI_FLTMAX 0x294
#define TI_sqrtf 0x298
#define TI__frbtof 0x29c
#define TI__frftob 0x2a0
#define TI__frftoub 0x2a4
#define TI__frftoi 0x2a8
#define TI__frftoui 0x2ac
#define TI__frftos 0x2b0
#define TI__frftous 0x2b4
#define TI__fritof 0x2b8
#define TI__fruitof 0x2bc
#define TI__frstof 0x2c0
#define TI__frubtof 0x2c4
#define TI__frustof 0x2c8
#define TI_ResetPorts 0x2cc
#define TI_ChkIfOSInterruptAvailable 0x2d0
#define TI_WriteFlashByte 0x2d4
#define TI_EraseFlash 0x2d8
#define TI_EraseFlashSector 0x2dc
#define TI_WriteFlash 0x2e0
#define TI_WriteFlashByteDuplicate 0x2e4
#define TI_WriteFlashA 0x2e8
#define TI_CleanupCertificate 0x2ec
#define TI_ClrHeap 0x2f0
#define TI_CpyToHeap 0x2f4
#define TI_ChkHeapTop 0x2f8
#define TI_ExecuteInRAM 0x2fc
#define TI_ExecuteInRAMDup 0x300
#define TI_ExecuteInRAMDup2 0x304
#define TI_ChkCertSpace 0x308
#define TI_GetFieldSizeFromType 0x30c
#define TI_FindFirstCertField 0x310
#define TI_FindField 0x314
#define TI_FindNextField 0x318
#define TI_GetCertificateEnd 0x31c
#define TI_GetFieldSizeFromType_ 0x320
#define TI_GetFieldFromSize 0x324
#define TI_NextFieldFromSize 0x328
#define TI_NextFieldFromType 0x32c
#define TI_GetOffsetToNextField 0x330
#define TI_WriteFlashUnsafe 0x334
#define TI_boot_GetCertCalcString 0x338
#define TI_boot_GetCertCalcID 0x33c
#define TI_GetSerial 0x340
//                           equ 0000344h
#define TI_Mult16By8 0x348
#define TI_Div16By8 0x34c
#define TI_Div16By16 0x350
#define TI_Div32By16 0x354
#define TI_CmpStr 0x358
#define TI_boot_Sha256Init 0x35c
#define TI_boot_Sha256Part 0x360
#define TI_boot_Sha256Hash 0x364
#define TI_FindAppHeaderSubField 0x368
//                           equ 000036Ch
#define TI_FindAppHeaderTimestamp 0x370
#define TI_boot_ClearVRAM 0x374
#define TI_boot_PutS 0x378
#define TI_PutSpinner 0x37c
#define TI_boot_GetLFontPtr 0x380
#define TI_boot_InitializeHardware 0x384
#define TI_boot_TurnOffHardware 0x388
#define TI_MakeColCmd 0x38c
#define TI_boot_NewLine 0x390
#define TI_PutBootVersion 0x394
#define TI_DrawSectorProtectionTable 0x398
#define TI_boot_Set6MHzMode 0x39c
#define TI_boot_Set48MHzMode 0x3a0
#define TI_boot_Set6MHzModeI 0x3a4
#define TI_boot_Set48MHzModeI 0x3a8
#define TI_CheckHardware 0x3ac
#define TI_GetBatteryStatus 0x3b0
#define TI_Delay10ms 0x3b4
#define TI_DelayTenTimesAms 0x3b8
//                           equ 00003BCh
//                           equ 00003C0h
//                           equ 00003C4h
//                           equ 00003C8h
#define TI_usb_IsBusPowered 0x3cc
#define TI_KeypadScan 0x3d0
#define TI_KeypadScanFull 0x3d4
// _ret                      equ 00003D8h
// _ret                      equ 00003DCh
#define TI_MarkOSInvalid 0x3e0
#define TI_usb_BusPowered 0x3e4
#define TI_usb_SelfPowered 0x3e8
//                           equ 00003ECh
//                           equ 00003F0h
//                           equ 00003F4h
//                           equ 00003F8h
#define TI_usb_SetDeviceB 0x3fc
//                           equ 0000400h
#define TI_usb_DMACXReadNext 0x404
#define TI_usb_DMACXWrite 0x408
#define TI_usb_DMACXRead 0x40c
#define TI_usb_DMACXWriteNext 0x410
#define TI_usb_DMACXWriteCheck 0x414
//                           equ 0000418h
//                           equ 000041Ch
//                           equ 0000420h
//                           equ 0000424h
//                           equ 0000428h
//                           equ 000042Ch
//                           equ 0000430h
//                           equ 0000434h
//                           equ 0000438h
//                           equ 000043Ch
//                           equ 0000440h
//                           equ 0000444h
//                           equ 0000448h
//                           equ 000044Ch
//                           equ 0000450h
//                           equ 0000454h
//                           equ 0000458h
//                           equ 000045Ch
#define TI_MarkOSValid 0x460
//                           equ 0000464h
//                           equ 0000468h
//                           equ 000046Ch
//                           equ 0000470h
//                           equ 0000474h
//                           equ 0000478h
//                           equ 000047Ch
//                           equ 0000480h
//                           equ 0000484h
//                           equ 0000488h
//                           equ 000048Ch
//                           equ 0000490h
//                           equ 0000494h
//                           equ 0000498h
//                           equ 000049Ch
//                           equ 00004A0h
//                           equ 00004A4h
#define TI_usb_SetDMAState 0x4a8
#define TI_usb_DMATransfer 0x4ac
#define TI_usb_DMACXTransferWait 0x4b0
//                           equ 00004B4h
//                           equ 00004B8h
#define TI_usb_ResetFIFOS 0x4bc
//                           equ 00004C0h
//                           equ 00004C4h
//                           equ 00004C8h
//                           equ 00004CCh
//                           equ 00004D0h
//                           equ 00004D4h
//                           equ 00004D8h
//                           equ 00004DCh
//                           equ 00004E0h
//                           equ 00004E4h
//                           equ 00004E8h
//                           equ 00004ECh
#define TI_usb_ResetTimer 0x4f0
#define TI_usb_DisableTimer 0x4f4
#define TI_usb_EnableTimer 0x4f8
//                           equ 00004FCh
//                           equ 0000500h
//                           equ 0000504h
//                           equ 0000508h
//                           equ 000050Ch
//                           equ 0000510h
//                           equ 0000514h
//                           equ 0000518h
//                           equ 000051Ch
#define TI_boot_SetTimersControl 0x520
#define TI_boot_GetTimersControl 0x524
#define TI_boot_SetTimersInterrupt 0x528
#define TI_boot_GetTimersInterrupt 0x52c
#define TI_boot_SetTimersInterruptM 0x530
#define TI_boot_GetTimersInterruptM 0x534
#define TI_boot_SetTimer1Counter 0x538
#define TI_boot_GetTimer1Counter 0x53c
#define TI_boot_SetTimer1ReloadValue 0x540
#define TI_boot_GetTimer1ReloadValue 0x544
#define TI_boot_SetTimer1MatchValue1 0x548
#define TI_boot_GetTimer1MatchValue1 0x54c
#define TI_boot_SetTimer1MatchValue2 0x550
#define TI_boot_GetTimer1MatchValue2 0x554
#define TI_boot_SetTimer2Counter 0x558
#define TI_boot_GetTimer2Counter 0x55c
#define TI_boot_SetTimer2ReloadValue 0x560
#define TI_boot_GetTimer2ReloadValue 0x564
#define TI_boot_SetTimer2MatchValue1 0x568
#define TI_boot_GetTimer2MatchValue1 0x56c
#define TI_boot_SetTimer2MatchValue2 0x570
#define TI_boot_GetTimer2MatchValue2 0x574
#define TI_CheckIfEmulated 0x578
#define TI_boot_GetOnInt 0x57c
#define TI_boot_RTCIntHandler 0x580
#define TI_boot_RTCInitialize 0x584
#define TI_boot_RTCGetInitStatus 0x588
#define TI_boot_RTCEnable 0x58c
#define TI_boot_RTCDisable 0x590
#define TI_boot_RTCSet24Hours 0x594
//                           equ 0000598h
//                           equ 000059Ch
#define TI_boot_RTCAckAlarmInt 0x5a0
//                           equ 00005A4h
#define TI_boot_RTCWriteTime 0x5a8
#define TI_boot_RTCGetTime12Hour 0x5ac
#define TI_boot_RTCGetTime 0x5b0
#define TI_boot_RTCSetTime 0x5b4
#define TI_boot_RTCGetAlarm 0x5b8
#define TI_boot_RTCSetAlarmSafe 0x5bc
#define TI_boot_RTCCheckAlarmInt 0x5c0
#define TI_boot_RTCSetAlarmInt 0x5c4
#define TI_boot_RTCIsAfternoon 0x5c8
#define TI_boot_RTCGetDay 0x5cc
#define TI_boot_RTCSetAlarmIntSafe 0x5d0
#define TI_boot_RTCSetAlarm 0x5d4
#define TI_boot_RTCEnableInt 0x5d8
#define TI_boot_RTCDisableInt 0x5dc
#define TI_boot_RTCSetCallback 0x5e0
#define TI_boot_RTCResetTimeStruct 0x5e4
//                           equ 00005E8h
#define TI_boot_RTCSetFlags 0x5ec
//                           equ 00005F0h
#define TI_CheckEmulationBit 0x5f4
#define TI_usb_SetDMAAddress 0x5f8
//                           equ 00005FCh
#define TI_boot_SectorsBegin 0x600
//                           equ 0000604h
#define TI_usb_InEndpointClrStall 0x608
#define TI_usb_InEndpointSetStall 0x60c
#define TI_usb_InEndpointClrReset 0x610
#define TI_usb_InEndpointSetReset 0x614
#define TI_usb_InEndpointSendZlp 0x618
#define TI_usb_OutEndpointClrStall 0x61c
#define TI_usb_OutEndpointSetStall 0x620
#define TI_usb_OutEndpointClrReset 0x624
#define TI_usb_OutEndpointSetReset 0x628
#define TI_usb_SetFifoMap 0x62c
#define TI_usb_SetEndpointConfig 0x630
#define TI_usb_ClrEndpointConfig 0x634
#define TI_usb_SetFifoConfig 0x638
//                           equ 000063Ch
// RAM Equates
// --------------------------------
#define TI_ramStart 0xd00000
#define TI_flags 0xd00080 //  location of OS Flags (+-80h)
#define TI_textFlagsLoc 0xd00085 //  location of Text Flags
#define TI_apdFlagsLoc 0xd00088 //  location of APD Flags
#define TI_appFlagsLoc 0xd0008d //  location of App Flags
#define TI_rclFlagsLoc 0xd0008e //  location of RCLQueue Flags
#define TI_shiftFlagsLoc 0xd00092 //  location of Shifting Flags
#define TI_mathprintFlagsLoc 0xd000c4 //  location of MathPrint Flags
#define TI_strtokPtr 0xd000ff //  location of pointer used by C strtok
#define TI_printRoutine 0xd00108 //  stores pointer to printing routines (3 scrap)
#define TI_flashByte 0xd00125 //  used for writing to flash
#define TI_cellOverrideAddr 0xd00166
#define TI_curCell 0xd0016e //  selected list cell
#define TI_SmallEditCancelParse 0xd001a4
#define TI_curRowBackup 0xd0033c //  backup of curRow
#define TI_shiftFlagsLocBackup 0xd00358 //  backup of shiftFlagsLoc
#define TI_appFlagsLocBackup 0xd00366 //  backup of appFlagsLoc
#define TI_penRowBackup 0xd003e3 //  backup of penRow
#define TI_mathprintBackup 0xd003e6 //  backup of mathprint flags
#define TI_winLeftEdgeBackup 0xd003d2 //  backup of winLeftEdge
#define TI_catalogCurrentBackup 0xd003d3 //  backup of catalogCurrent
#define TI_menuCurrentSubBackup 0xd003d6 //  backup of menuCurrentSub
#define TI_menuNumMenusBackup 0xd003d8 //  backup of menuNumMenus
#define TI_menuCurrentBackup 0xd003da //  backup of menuCurrent
#define TI_cxCurAppBackup 0xd003dd //  backup of cxCurApp
#define TI_curUnderBackup 0xd003e8 //  backup of curUnder
#define TI_appData 0xd00429 //  formerly used for OFFSCRPT and ONSCRPT
#define TI_arcPtrEnd 0xd0052f
#define TI_tempSP 0xd0053f //  3 byte scrap
#define TI_arcInfo 0xd00543
#define TI_savedArcInfo 0xd0055b
#define TI_appBank_jump 0xd00584
#define TI_kbdScanCode 0xd00587 //  scancode returned by GetCSC
#define TI_kbdLGSC 0xd00588
#define TI_kbdPSC 0xd00589
#define TI_kbdWUR 0xd0058a
#define TI_kbdDebncCnt 0xd0058b
#define TI_kbdKey 0xd0058c
#define TI_kbdGetKy 0xd0058d
#define TI_keyExtend 0xd0058e
#define TI_brightness 0xd0058f
#define TI_apdSubTimer 0xd00590
#define TI_apdTimer 0xd00591
#define TI_curTime 0xd00594
#define TI_curRow 0xd00595
#define TI_curCol 0xd00596
#define TI_curOffset 0xd00598
#define TI_curUnder 0xd00599
#define TI_curYCol 0xd0059c
#define TI_curType 0xd0059f
#define TI_curXRow 0xd005a0
#define TI_prevDData 0xd005a1
#define TI_lFont_record 0xd005a4
#define TI_sFont_record 0xd005c5
#define TI_tokVarPtr 0xd005e9
#define TI_tokLen 0xd005ec
#define TI_indicCounter 0xd005f6
#define TI_OP1 0xd005f8
#define TI_OP1M 0xd005fa
#define TI_OP2 0xd00603
#define TI_OP2M 0xd00605
#define TI_OP2EXT 0xd0060c
#define TI_OP3 0xd0060e
#define TI_OP3M 0xd00610
#define TI_OP4 0xd00619
#define TI_OP4M 0xd0061b
#define TI_OP5 0xd00624
#define TI_OP5M 0xd00626
#define TI_OP6 0xd0062f
#define TI_OP6M 0xd00631
#define TI_OP6EXT 0xd00638
#define TI_progToEdit 0xd0065b
#define TI_nameBuff 0xd00663
#define TI_equ_edit_save 0xd0066e
#define TI_iMathPtr1 0xd0066f
#define TI_iMathPtr2 0xd00672
#define TI_iMathPtr3 0xd00675
#define TI_iMathPtr4 0xd00678
#define TI_iMathPtr5 0xd0067b
#define TI_asm_data_ptr1 0xd0067e
#define TI_asm_data_ptr2 0xd00681
#define TI_asm_ram 0xd00687
#define TI_textShadow 0xd006c0
#define TI_textShadCur 0xd007c4
#define TI_textShadTop 0xd007c7
#define TI_textShadAlph 0xd007c8
#define TI_textShadIns 0xd007c9
#define TI_cxMain 0xd007ca
#define TI_cxPPutAway 0xd007cd
#define TI_cxPutAway 0xd007d0
#define TI_cxReDisp 0xd007d3
#define TI_cxErrorEP 0xd007d6
#define TI_cxSizeWind 0xd007d9
#define TI_cxPage 0xd007dc
#define TI_cxCurApp 0xd007e0
#define TI_cxPrev 0xd007e2 //  23 bytes are shadows of cxMain through cxCurApp and appFlags
#define TI_cxAppReturn 0xd007eb
#define TI_onSP 0xd007fa
#define TI_promptRow 0xd00800
#define TI_promptCol 0xd00801
#define TI_promptIns 0xd00802
#define TI_promptShift 0xd00803
#define TI_promptRet 0xd00804
#define TI_promptValid 0xd00807
#define TI_varType 0xd00813
#define TI_varCurrent 0xd00814
#define TI_varClass 0xd0081c
#define TI_catalogCurrent 0xd0081d //  word at this location starting with 6007h corresponds to what is highlighted in catalog
#define TI_catalogCurrentBackupM 0xd00820 //  backup of catalogCurrent for menus
#define TI_menuAppDepth 0xd00823
#define TI_menuCurrent 0xd00824
#define TI_menuCurrentSub 0xd00825 //  holds current submenu index
#define TI_menuSelected 0xd00826 //  holds currently selected item in current submenu
#define TI_menuNumMenus 0xd00827 //  holds number of submenus for this menu
#define TI_menuNumItems 0xd00828 //  holds number of items in this submenu
#define TI_appFlagsBackup 0xd00829 //  iy+appFlags backup for menu stuff
#define TI_cursorFlagsBackup 0xd0082a //  iy+cursorFlags backup for menu stuff
#define TI_curGStyleBackup 0xd0082b //  curGStyle backup for menu stuff
#define TI_graphFlagsBackup 0xd0082c //  iy+graphFlags backup for menu stuff
#define TI_progCurrent 0xd0082d
// D0082E	; something used to execute apps with _NewContext0
#define TI_userMenuSA 0xd00838
#define TI_tempErrorMessage 0xd00842
#define TI_ioPrompt 0xd00879
#define TI_ioFlag 0xd00894
#define TI_sndRecState 0xd00896
#define TI_ioErrState 0xd00897
#define TI_ioData 0xd008a1
#define TI_penCol 0xd008d2
#define TI_penRow 0xd008d5
#define TI_rclQueue 0xd008d6
#define TI_rclQueueEnd 0xd008d9
#define TI_errNo 0xd008df
#define TI_errSP 0xd008e0
#define TI_errOffset 0xd008e3
#define TI_entryString 0xd008e6
#define TI_entryResult 0xd008ea
#define TI_statVarsOffset 0xd0117f
#define TI_asm_prgm_size 0xd0118c
#define TI_bstCounter 0xd0118f
#define TI_statVars 0xd01191
#define TI_infVars 0xd013a4
#define TI_infVar1 0xd013ad
#define TI_infVar2 0xd013b6
#define TI_infVar3 0xd013bf
#define TI_infVar4 0xd013c8
#define TI_infVar5 0xd013d1
#define TI_infVar6 0xd013da
#define TI_infVar7 0xd013e3
#define TI_infVar8 0xd013ec
#define TI_infVar9 0xd013f5
#define TI_infVar10 0xd013fe
#define TI_infVar11 0xd01407
#define TI_infVar12 0xd01410
#define TI_infVar13 0xd01419
#define TI_infVar14 0xd01422
#define TI_infVar15 0xd0142b
#define TI_infVar16 0xd01434
#define TI_infVar17 0xd0143d
#define TI_infVar18 0xd01446
#define TI_infVar19 0xd0144f
#define TI_infVar20 0xd01458
#define TI_curGStyle 0xd0146d
#define TI_curGY 0xd0146e
#define TI_curGY2 0xd01470
#define TI_curGX2 0xd01471 //  currently selected equation while graphing
#define TI_freeSaveY 0xd01472
#define TI_freeSaveX 0xd01474
#define TI_XOffset 0xd014fa
#define TI_YOffset 0xd014fc
#define TI_lcdTallP 0xd014fd
#define TI_pixWideP 0xd014fe
#define TI_pixWide_m_1 0xd014ff
#define TI_pixWide_m_2 0xd01501
#define TI_lastEntryStkPtr 0xd01508
#define TI_lastEntryStk 0xd0150b
#define TI_numLastEntries 0xd01d0b
#define TI_currLastEntry 0xd01d0c
#define TI_curPlotNumber 0xd01d45
#define TI_curInc 0xd01d49
#define TI_uXmin 0xd01d61
#define TI_uXmax 0xd01d6a
#define TI_uXscl 0xd01d73
#define TI_uYmin 0xd01d7c
#define TI_uYmax 0xd01d85
#define TI_uYscl 0xd01d8e
#define TI_uThetMin 0xd01d97
#define TI_uThetMax 0xd01da0
#define TI_uThetStep 0xd01da9
#define TI_uTmin 0xd01db2
#define TI_uTmax 0xd01dbb
#define TI_uTStep 0xd01dc4
#define TI_uPlotStart 0xd01dcd
#define TI_unMax 0xd01dd6
#define TI_uu0 0xd01ddf
#define TI_uv0 0xd01de8
#define TI_unMin 0xd01df1
#define TI_uu02 0xd01dfa
#define TI_uv02 0xd01e03
#define TI_uw0 0xd01e0c
#define TI_uPlotStep 0xd01e15
#define TI_uXres 0xd01e1e
#define TI_uw02 0xd01e27
#define TI_Xmin 0xd01e33
#define TI_Xmax 0xd01e3c
#define TI_Xscl 0xd01e45
#define TI_Ymin 0xd01e4e
#define TI_Ymax 0xd01e57
#define TI_Yscl 0xd01e60
#define TI_ThetaMin 0xd01e69
#define TI_ThetaMax 0xd01e72
#define TI_ThetaStep 0xd01e7b
#define TI_TminPar 0xd01e84
#define TI_TmaxPar 0xd01e8d
#define TI_Tstep 0xd01e96
#define TI_PlotStart 0xd01e9f
#define TI_nMax 0xd01ea8
#define TI_u0 0xd01eb1
#define TI_v0 0xd01eba
#define TI_nMin 0xd01ec3
#define TI_u02 0xd01ecc
#define TI_v02 0xd01ed5
#define TI_w0 0xd01ede
#define TI_PlotStep 0xd01ee7
#define TI_XresO 0xd01ef0
#define TI_w02 0xd01ef9
#define TI_un1 0xd01f02
#define TI_un2 0xd01f0b
#define TI_vn1 0xd01f14
#define TI_vn2 0xd01f1d
#define TI_wn1 0xd01f26
#define TI_wn2 0xd01f2f
#define TI_fin_N 0xd01f38
#define TI_fin_I 0xd01f41
#define TI_fin_PV 0xd01f4a
#define TI_fin_PMT 0xd01f53
#define TI_fin_FV 0xd01f5c
#define TI_fin_PY 0xd01f65
#define TI_fin_CY 0xd01f6e
#define TI_cal_N 0xd01f77
#define TI_cal_I 0xd01f80
#define TI_cal_PV 0xd01f89
#define TI_cal_PMT 0xd01f92
#define TI_cal_FV 0xd01f9b
#define TI_cal_PY 0xd01fa4
#define TI_DeltaX 0xd01fae
#define TI_DeltaY 0xd01fb7
#define TI_TraceStep 0xd0203d
#define TI_TblStart 0xd02267
#define TI_DeltaTbl 0xd02270
#define TI_Plot1MarkType 0xd0227e
#define TI_Plot1List1 0xd0227f
#define TI_Plot1List2 0xd02284
#define TI_Plot1FreqList 0xd02289
#define TI_Plot1XYOnOff 0xd0228e
#define TI_Plot1Color 0xd0228f
#define TI_Plot2MarkType 0xd02290
#define TI_Plot2List1 0xd02291
#define TI_Plot2List2 0xd02296
#define TI_Plot2FreqList 0xd0229b
#define TI_Plot2XYOnOff 0xd022a0
#define TI_Plot2Color 0xd022a1
#define TI_Plot3MarkType 0xd022a2
#define TI_Plot3List1 0xd022a3
#define TI_Plot3List2 0xd022a8
#define TI_Plot3FreqList 0xd022ad
#define TI_Plot3XYOnOff 0xd022b2
#define TI_Plot3Color 0xd022b3
#define TI_ES 0xd022ba
#define TI_seed1 0xd022fc
#define TI_seed2 0xd02305
#define TI_basic_prog 0xd0230e
#define TI_begPC 0xd02317
#define TI_curPC 0xd0231a
#define TI_endPC 0xd0231d
#define TI_numArguments 0xd02320
#define TI_cmdShadow 0xd0232d
#define TI_cmdShadCur 0xd02431
#define TI_cmdShadAlph 0xd02433
#define TI_cmdShadIns 0xd02435
#define TI_cmdCursor 0xd02434
#define TI_editTop 0xd02437
#define TI_editCursor 0xd0243a
#define TI_editTail 0xd0243d
#define TI_editBtm 0xd02440
#define TI_currListHighlight 0xd0244b //  word, this is offset into list for currently-highlighted element in list editor
#define TI_editSym 0xd0244e //  pointer to vat of variable being edited
#define TI_editDat 0xd02451 //  pointer to data of variable being edited
#define TI_currListPageOffset 0xd02457
#define TI_currList 0xd02458
#define TI_listName1 0xd02459
#define TI_listName2 0xd0245e
#define TI_listName3 0xd02463
#define TI_listName4 0xd02468
#define TI_listName5 0xd0246d
#define TI_listName6 0xd02472
#define TI_listName7 0xd02477
#define TI_listName8 0xd0247c
#define TI_listName9 0xd02481
#define TI_listName10 0xd02486
#define TI_listName11 0xd0248b
#define TI_listName12 0xd02490
#define TI_listName13 0xd02495
#define TI_listName14 0xd0249a
#define TI_listName15 0xd0249f
#define TI_listName16 0xd024a4
#define TI_listName17 0xd024a9
#define TI_listName18 0xd024ae
#define TI_listName19 0xd024b3
#define TI_listName20 0xd024b8
#define TI_currGrphStyle 0xd024be
#define TI_y1LineType 0xd024bf
#define TI_y2LineType 0xd024c0
#define TI_y3LineType 0xd024c1
#define TI_y4LineType 0xd024c2
#define TI_y5LineType 0xd024c3
#define TI_y6LineType 0xd024c4
#define TI_y7LineType 0xd024c5
#define TI_y8LineType 0xd024c6
#define TI_y9LineType 0xd024c7
#define TI_y0LineType 0xd024c8
#define TI_para1LineType 0xd024c9
#define TI_para2LineType 0xd024ca
#define TI_para3LineType 0xd024cb
#define TI_para4LineType 0xd024cc
#define TI_para5LineType 0xd024cd
#define TI_para6LineType 0xd024ce
#define TI_polar1LineType 0xd024cf
#define TI_polar2LineType 0xd024d0
#define TI_polar3LineType 0xd024d1
#define TI_polar4LineType 0xd024d2
#define TI_polar5LineType 0xd024d3
#define TI_polar6LineType 0xd024d4
#define TI_secULineType 0xd024d5
#define TI_secVLineType 0xd024d6
#define TI_secWLineType 0xd024d7
#define TI_y1LineColor 0xd024d8
#define TI_y2LineColor 0xd024d9
#define TI_y3LineColor 0xd024da
#define TI_y4LineColor 0xd024db
#define TI_y5LineColor 0xd024dc
#define TI_y6LineColor 0xd024dd
#define TI_y7LineColor 0xd024de
#define TI_y8LineColor 0xd024df
#define TI_y9LineColor 0xd024e0
#define TI_y0LineColor 0xd024e1
#define TI_para1LineColor 0xd024e2
#define TI_para2LineColor 0xd024e3
#define TI_para3LineColor 0xd024e4
#define TI_para4LineColor 0xd024e5
#define TI_para5LineColor 0xd024e6
#define TI_para6LineColor 0xd024e7
#define TI_polar1LineColor 0xd024e8
#define TI_polar2LineColor 0xd024e9
#define TI_polar3LineColor 0xd024ea
#define TI_polar4LineColor 0xd024eb
#define TI_polar5LineColor 0xd024ec
#define TI_polar6LineColor 0xd024ed
#define TI_secULineColor 0xd024ee
#define TI_secVLineColor 0xd024ef
#define TI_secWLineColor 0xd024f0
#define TI_winTop 0xd02504
#define TI_winBtm 0xd02505
#define TI_winLeftEdge 0xd02506
#define TI_winLeft 0xd02507
#define TI_winAbove 0xd02509
#define TI_winRow 0xd0250b
#define TI_winCol 0xd0250d
#define TI_fmtDigits 0xd0250f
#define TI_fmtString 0xd02510
#define TI_fmtLeft 0xd02561
#define TI_fmtIndex 0xd02564
#define TI_fmtMatSym 0xd02567
#define TI_fmtMatMem 0xd0256a
#define TI_tSymPtr1 0xd0257b
#define TI_tSymPtr2 0xd0257e
#define TI_chkDelPtr3 0xd02581
#define TI_chkDelPtr4 0xd02584
#define TI_tempMem 0xd02587
#define TI_FPSbase 0xd0258a
#define TI_FPS 0xd0258d
#define TI_OPBase 0xd02590
#define TI_OPS 0xd02593
#define TI_pTempCnt 0xd02596
#define TI_cleanTmp 0xd02598
#define TI_pTemp 0xd0259a
#define TI_progPtr 0xd0259d
#define TI_newDataPtr 0xd025a0
#define TI_pagedGetPtr 0xd025a3 //  3 byte scrap (unstable)
#define TI_pagedPutPtr 0xd025a6
#define TI_appErr1 0xd025a9 //  use with _ErrCustom1
#define TI_appErr2 0xd025b6 //  use with _ErrCustom2
#define TI_arcPtr 0xd025c8
#define TI_appRawKeyHandle 0xd025cb
#define TI_customHeight 0xd025ce
#define TI_localLanguage 0xd025cf
#define TI_hookExecTemp 0xd025d2
#define TI_cursorHookPtr 0xd025d5
#define TI_libraryHookPtr 0xd025d8
#define TI_rawKeyHookPtr 0xd025db
#define TI_getKeyHookPtr 0xd025de
#define TI_homescreenHookPtr 0xd025e1
#define TI_windowHookPtr 0xd025e4
#define TI_graphHookPtr 0xd025e7
#define TI_yEqualsHookPtr 0xd025ea
#define TI_fontHookPtr 0xd025ed
#define TI_regraphHookPtr 0xd025f0
#define TI_graphicsHookPtr 0xd025f3
#define TI_traceHookPtr 0xd025f6
#define TI_parserHookPtr 0xd025f9
#define TI_appChangeHookPtr 0xd025fc
#define TI_catalog1HookPtr 0xd025ff
#define TI_helpHookPtr 0xd02602
#define TI_cxRedispHookPtr 0xd02605
#define TI_menuHookPtr 0xd02608
#define TI_catalog2HookPtr 0xd0260b
#define TI_tokenHookPtr 0xd0260e
#define TI_localizeHookPtr 0xd02611
#define TI_silentLinkHookPtr 0xd02614
#define TI_USBActivityHookPtr 0xd0261a
#define TI_tempFreeArc 0xd02655 //  set after _ArcChk call
#define TI_textFGColor 0xd02688
#define TI_textBGColor 0xd0268a
#define TI_drawBGColor 0xd026aa
#define TI_drawFGColor 0xd026ac
#define TI_drawColorCode 0xd026ae
#define TI_keyToStrRam 0xd026ea
#define TI_sEditMonSp 0xd02706
#define TI_bpSave 0xd02709
#define TI_batteryStatus 0xd02a86
#define TI_graphBGColor 0xd02a98
#define TI_errorLineY 0xd02a1b
#define TI_errorLineX 0xd02a23
#define TI_fillRectColor 0xd02ac0
#define TI_statusBarBGColor 0xd02acc
#define TI_scrapMem 0xd02ad7 //  3 byte scrap (unstable)
#define TI_TempOP2ToOP6 0xd02b39 //  55 bytes where OP2 to OP6 are temporary saved
#define TI_gCurYLoc 0xd02fd6 //  current y pixel location for C functions
// safeRAM Locations
// ---------------------------------------------
// appData		equ 0D00429h ; 256 bytes
// textShadow		equ 0D006C0h ; 260 bytes	; Call _ClrTxtShdw to put spaces in here
// cmdShadow		equ 0D0232Dh ; 260 bytes
#define TI_pixelShadow 0xd031f6 //  8400 bytes
#define TI_pixelShadow2 0xd052c6 //  8400 bytes
#define TI_cmdPixelShadow 0xd07396 //  8400 bytes
#define TI_plotSScreen 0xd09466 //  21945 bytes	; Set GraphDraw Flag to redraw graph if used
#define TI_saveSScreen 0xd0ea1f //  21945 bytes	; Set GraphDraw Flag to redraw graph if used
#define TI_cursorImage 0xe30800 //  1020 bytes
// semiSafeRAM Locations
// ---------------------------------------------
#define TI_usbArea 0xd13fd8 //  14306 bytes used for usb, probably need to disable timer3/usb interrupts to use
#define TI_usbHandleKeys 0xd14091 //  zero this byte while using usbArea to keep GetCSC from affecting other parts of usbArea
#define TI_usbInited 0xd177b7 //  zero this byte while using usbArea and to reset the usb stack when interrupts are re-enabled
#define TI_heapBot 0xd1887c //  1024 bytes used for flash ram routines, rest used rarely
#define TI_ramCodeTop 0xd18c7c
#define TI_heapTop 0xd1987c
#define TI_stackBot 0xd1987e
#define TI_stackTop 0xd1a87e
// RAM Equates Continued
// ---------------------------------------------
#define TI_userMem 0xd1a881
#define TI_symTable 0xd3ffff
#define TI_vRam 0xd40000
#define TI_vRamEnd 0xd65800
// Ports
// --------------------------------
#define TI_pCpuSpeed 0x1
#define TI_pHardwareId 0x3
// SHA256 Ports
// --------------------------------
#define TI_pShaRange 0x2000
#define TI_mpShaRange 0xe10000
#define TI_shaCtrl 0x0 //  1 byte
#define TI_pShaCtrl 0x0
#define TI_mpShaCtrl 0x0
#define TI_shaData 0x10 //  40h bytes
#define TI_pShaData 0x0
#define TI_mpShaData 0x0
#define TI_shaState 0x60 //  20h bytes
#define TI_pShaState 0x0
#define TI_mpShaState 0x0
// USB Ports
// --------------------------------
#define TI_pUsbRange 0x3000
#define TI_mpUsbRange 0xe20000
#define TI_usbCapLen 0x0
#define TI_pUsbCapLen 0x0
#define TI_mpUsbCapLen 0x0
#define TI_usbHciVer 0x2
#define TI_pUsbHciVer 0x0
#define TI_mpUsbHciVer 0x0
#define TI_usbHcsParams 0x4
#define TI_pUsbHcsParams 0x0
#define TI_mpUsbHcsParams 0x0
#define TI_bUsbNumPorts 0x0
#define TI_bmUsbNumPorts (0Fh << TI_bUsbNumPorts)
#define TI_bUsbPortPwrCtrl 0x4
#define TI_bmUsbPortPwrCtrl (1 << TI_bUsbPortPwrCtrl)
#define TI_bUsbPortRoutRules 0x7
#define TI_bmUsbPortRoutRules (1 << TI_bUsbPortRoutRules)
#define TI_bUsbNumPortsPerCC 0x8
#define TI_bmUsbNumPortsPerCC (0Fh << TI_bUsbNumPortsPerCC)
#define TI_bUsbNumCC 0x12
#define TI_bmUsbNumCC (0Fh << TI_bUsbNumCC)
#define TI_bUsbPortIndics 0x16
#define TI_bmUsbPortIndics (1 << TI_bUsbPortIndics)
#define TI_bUsbDebugPortNum 0x20
#define TI_bmUsbDebugPortNum (0Fh << TI_bUsbDebugPortNum)
#define TI_usbHccParams 0x8
#define TI_pUsbHccParams 0x0
#define TI_mpUsbHccParams 0x0
#define TI_bUsb64Bit 0x0
#define TI_bmUsb64Bit (1 << TI_bUsb64Bit)
#define TI_bUsbProgFrameList 0x1
#define TI_bmUsbProgFrameList (1 << TI_bUsbProgFrameList)
#define TI_bUsbAsyncSchedParkCap 0x2
#define TI_bmUsbAsyncSchedParkCap (1 << TI_bUsbAsyncSchedParkCap)
#define TI_bUsbIsochSchedThresh 0x4
#define TI_bmUsbIsochSchedThresh (0Fh << TI_bUsbIsochSchedThresh)
#define TI_bUsbEhciExtendCap 0x8
#define TI_bmUsbEhciExtendCap (0FFh << TI_bUsbEhciExtendCap)
#define TI_usbHcspPortRout 0xc
#define TI_pUsbHcspPortRout 0x0
#define TI_mpUsbHcspPortRout 0x0
#define TI_usbCmd 0x10
#define TI_pUsbCmd 0x0
#define TI_mpUsbCmd 0x0
#define TI_bUsbRunStop 0x0
#define TI_bmUsbRunStop (1 << TI_bUsbRunStop)
#define TI_bUsbHcReset 0x1
#define TI_bmUsbHcReset (1 << TI_bUsbHcReset)
#define TI_bUsbFrameListSize 0x2
#define TI_bmUsbFrameListSize (3 << TI_bUsbFrameListSize)
#define TI_bUsbPeriodicSchedEn 0x4
#define TI_bmUsbPeriodicSchedEn (1 << TI_bUsbPeriodicSchedEn)
#define TI_bUsbAsyncSchedEn 0x5
#define TI_bmUsbAsyncSchedEn (1 << TI_bUsbAsyncSchedEn)
#define TI_bUsbIntAsyncAdvDrbl 0x6
#define TI_bmUsbIntAsyncAdvDrbl (1 << TI_bUsbIntAsyncAdvDrbl)
#define TI_bUsbLightHcReset 0x7
#define TI_bmUsbLightHcReset (1 << TI_bUsbLightHcReset)
#define TI_bUsbAsyncSchedParkCnt 0x8
#define TI_bmUsbAsyncSchedParkCnt (3 << TI_bUsbAsyncSchedParkCnt)
#define TI_bUsbAsyncSchedParkEn 0x11
#define TI_bmUsbAsyncSchedParkEn (1 << TI_bUsbAsyncSchedParkEn)
#define TI_bUsbIntThreshCtrl 0x16
#define TI_bmUsbIntThreshCtrl (0FFh << TI_bUsbIntThreshCtrl)
#define TI_usbSts 0x14
#define TI_pUsbSts 0x0
#define TI_mpUsbSts 0x0
#define TI_usbIntEn 0x18
#define TI_pUsbIntEn 0x0
#define TI_mpUsbIntEn 0x0
#define TI_bUsbInt 0x0
#define TI_bmUsbInt (1 << TI_bUsbInt)
#define TI_bUsbIntErr 0x1
#define TI_bmUsbIntErr (1 << TI_bUsbIntErr)
#define TI_bUsbIntPortChgDetect 0x2
#define TI_bmUsbIntPortChgDetect (1 << TI_bUsbIntPortChgDetect)
#define TI_bUsbIntFrameListOver 0x3
#define TI_bmUsbIntFrameListOver (1 << TI_bUsbIntFrameListOver)
#define TI_bUsbIntHostSysErr 0x4
#define TI_bmUsbIntHostSysErr (1 << TI_bUsbIntHostSysErr)
#define TI_bUsbIntAsyncAdv 0x5
#define TI_bmUsbIntAsyncAdv (1 << TI_bUsbIntAsyncAdv)
#define TI_bUsbHcHalted 0x12
#define TI_bmUsbHcHalted (1 << TI_bUsbHcHalted)
#define TI_bUsbReclamation 0x13
#define TI_bmUsbReclamation (1 << TI_bUsbReclamation)
#define TI_bUsbPeriodicSchedSts 0x14
#define TI_bmUsbPeriodicSchedSts (1 << TI_bUsbPeriodicSchedSts)
#define TI_bUsbAsyncSchedSts 0x15
#define TI_bmUsbAsyncSchedSts (1 << TI_bUsbAsyncSchedSts)
#define TI_usbFrameIdx 0x1c
#define TI_pUsbFrameIdx 0x0
#define TI_mpUsbFrameIdx 0x0
#define TI_bUsbFrameIdx 0x0
#define TI_bmUsbFrameIdx (03FFFh << TI_bUsbFrameIdx)
#define TI_usbCtrlDsSeg 0x20
#define TI_pUsbCtrlDsSeg 0x0
#define TI_mpUsbCtrlDsSeg 0x0
#define TI_usbPeriodicListBase 0x24
#define TI_pUsbPeriodicListBase 0x0
#define TI_mpUsbPeriodicListBase 0x0
#define TI_bUsbPeriodicListBase 0x12
#define TI_bmUsbPeriodicListBase (0FFFFFh << TI_bUsbPeriodicListBase)
#define TI_usbAsyncListAddr 0x28
#define TI_pUsbAsyncListAddr 0x0
#define TI_mpUsbAsyncListAddr 0x0
#define TI_bUsbAsyncListAddr 0x5
#define TI_bmUsbAsyncListAddr (07FFFFFFh << TI_bUsbAsyncListAddr)
#define TI_usbPortStsCtrl 0x30
#define TI_pUsbPortStsCtrl 0x0
#define TI_mpUsbPortStsCtrl 0x0
#define TI_bUsbCurConnSts 0x0
#define TI_bmUsbCurConnSts (1 << TI_bUsbCurConnSts)
#define TI_bUsbConnStsChg 0x1
#define TI_bmUsbConnStsChg (1 << TI_bUsbConnStsChg)
#define TI_bUsbPortEn 0x2
#define TI_bmUsbPortEn (1 << TI_bUsbPortEn)
#define TI_bUsbPortEnChg 0x3
#define TI_bmUsbPortEnChg (1 << TI_bUsbPortEnChg)
#define TI_bUsbOvercurrActive 0x4
#define TI_bmUsbOvercurrActive (1 << TI_bUsbOvercurrActive)
#define TI_bUsbOvercurrChg 0x5
#define TI_bmUsbOvercurrChg (1 << TI_bUsbOvercurrChg)
#define TI_bUsbForcePortResume 0x6
#define TI_bmUsbForcePortResume (1 << TI_bUsbForcePortResume)
#define TI_bUsbPortSuspended 0x7
#define TI_bmUsbPortSuspended (1 << TI_bUsbPortSuspended)
#define TI_bUsbPortReset 0x8
#define TI_bmUsbPortReset (1 << TI_bUsbPortReset)
#define TI_bUsbLineSts 0x10
#define TI_bmUsbLineSts (3 << TI_bUsbLineSts)
#define TI_bUsbPortPwr 0x12
#define TI_bmUsbPortPwr (1 << TI_bUsbPortPwr)
#define TI_bUsbPortOwner 0x13
#define TI_bmUsbPortOwner (1 << TI_bUsbPortOwner)
#define TI_bUsbPortIndicCtrl 0x14
#define TI_bmUsbPortIndicCtrl (3 << TI_bUsbPortIndicCtrl)
#define TI_bUsbPortTestCtrl 0x16
#define TI_bmUsbPortTestCtrl (0Fh << TI_bUsbPortTestCtrl)
#define TI_bUsbWakeConnEn 0x20
#define TI_bmUsbWakeConnEn (1 << TI_bUsbWakeConnEn)
#define TI_bUsbWakeDiscEn 0x21
#define TI_bmUsbWakeDiscEn (1 << TI_bUsbWakeDiscEn)
#define TI_bUsbWakeOvercurrEn 0x22
#define TI_bmUsbWakeOvercurrEn (1 << TI_bUsbWakeOvercurrEn)
#define TI_usbMisc 0x40
#define TI_pUsbMisc 0x0
#define TI_mpUsbMisc 0x0
#define TI_bUsbAsyncSchedSleepTmr 0x0
#define TI_bmUsbAsyncSchedSleepTmr (3 << TI_bUsbAsyncSchedSleepTmr)
#define TI_bUsbEof1Timing 0x2
#define TI_bmUsbEof1Timing (3 << TI_bUsbEof1Timing)
#define TI_bUsbEof2Timing 0x4
#define TI_bmUsbEof2Timing (3 << TI_bUsbEof2Timing)
#define TI_bUsbHostSuspend 0x6
#define TI_bmUsbHostSuspend (1 << TI_bUsbHostSuspend)
#define TI_usbOtgCsr 0x80
#define TI_pUsbOtgCsr 0x0
#define TI_mpUsbOtgCsr 0x0
#define TI_bUsbBBusReq 0x0
#define TI_bmUsbBBusReq (1 << TI_bUsbBBusReq)
#define TI_bUsbBHnp 0x1
#define TI_bmUsbBHnp (1 << TI_bUsbBHnp)
#define TI_bUsbBVbusDisc 0x2
#define TI_bmUsbBVbusDisc (1 << TI_bUsbBVbusDisc)
#define TI_bUsbABusReq 0x4
#define TI_bmUsbABusReq (1 << TI_bUsbABusReq)
#define TI_bUsbABusDrop 0x5
#define TI_bmUsbABusDrop (1 << TI_bUsbABusDrop)
#define TI_bUsbAHnp 0x6
#define TI_bmUsbAHnp (1 << TI_bUsbAHnp)
#define TI_bUsbASrpEn 0x7
#define TI_bmUsbASrpEn (1 << TI_bUsbASrpEn)
#define TI_bUsbASrpMode 0x8
#define TI_usbASrpModeVbus (0 << TI_bUsbASrpMode)
#define TI_usbASrpModeData (1 << TI_bUsbASrpMode)
#define TI_bmUsbASrpMode (1 << TI_bUsbASrpMode)
#define TI_bUsbIdFilt 0x9
#define TI_usbIdFiltShort (0 << TI_bUsbIdFilt)
#define TI_usbIdFiltLong (1 << TI_bUsbIdFilt)
#define TI_bmUsbIdFilt (1 << TI_bUsbIdFilt)
#define TI_bUsbVbusFilt 0x10
#define TI_usbVbusFiltShort (0 << TI_bUsbVbusFilt)
#define TI_usbVbusFiltLong (1 << TI_bUsbVbusFilt)
#define TI_bmUsbVbusFilt (1 << TI_bUsbVbusFilt)
#define TI_bUsbHdiscFilt 0x11
#define TI_usbHdiscFiltShort (0 << TI_bUsbHdiscFilt)
#define TI_usbHdiscFiltLong (1 << TI_bUsbHdiscFilt)
#define TI_bmUsbHdiscFilt (1 << TI_bUsbHdiscFilt)
#define TI_bUsbBSessEnd 0x16
#define TI_bmUsbBSessEnd (1 << TI_bUsbBSessEnd)
#define TI_bUsbBSessVld 0x17
#define TI_bmUsbBSessVld (1 << TI_bUsbBSessVld)
#define TI_bUsbASessVld 0x18
#define TI_bmUsbASessVld (1 << TI_bUsbASessVld)
#define TI_bUsbAVbusVld 0x19
#define TI_bmUsbAVbusVld (1 << TI_bUsbAVbusVld)
#define TI_bUsbRole 0x20
#define TI_usbRoleHost (0 << TI_bUsbRole)
#define TI_usbRoleDev (1 << TI_bUsbRole)
#define TI_bmUsbRole (1 << TI_bUsbRole)
#define TI_bUsbId 0x21
#define TI_usbIdA (0 << TI_bUsbId)
#define TI_usbIdB (1 << TI_bUsbId)
#define TI_bmUsbId (1 << TI_bUsbId)
#define TI_bUsbSpd 0x22
#define TI_usbSpdFull (0 << TI_bUsbSpd)
#define TI_usbSpdLow (1 << TI_bUsbSpd)
#define TI_usbSpdHigh (2 << TI_bUsbSpd)
#define TI_bmUsbSpd (3 << TI_bUsbSpd)
#define TI_usbOtgIsr 0x84
#define TI_pUsbOtgIsr 0x0
#define TI_mpUsbOtgIsr 0x0
#define TI_usbOtgIer 0x88
#define TI_pUsbOtgIer 0x0
#define TI_mpUsbOtgIer 0x0
#define TI_bUsbIntBSrpComplete 0x0
#define TI_bmUsbIntBSrpComplete (1 << TI_bUsbIntBSrpComplete)
#define TI_bUsbIntASrpDetect 0x4
#define TI_bmUsbIntASrpDetect (1 << TI_bUsbIntASrpDetect)
#define TI_bUsbIntAVbusErr 0x5
#define TI_bmUsbIntAVbusErr (1 << TI_bUsbIntAVbusErr)
#define TI_bUsbIntBSessEnd 0x6
#define TI_bmUsbIntBSessEnd (1 << TI_bUsbIntBSessEnd)
#define TI_bUsbIntRoleChg 0x8
#define TI_bmUsbIntRoleChg (1 << TI_bUsbIntRoleChg)
#define TI_bUsbIntIdChg 0x9
#define TI_bmUsbIntIdChg (1 << TI_bUsbIntIdChg)
#define TI_bUsbIntOvercurr 0x10
#define TI_bmUsbIntOvercurr (1 << TI_bUsbIntOvercurr)
#define TI_bUsbIntBPlugRemoved 0x11
#define TI_bmUsbIntBPlugRemoved (1 << TI_bUsbIntBPlugRemoved)
#define TI_bUsbIntAPlugRemoved 0x12
#define TI_bmUsbIntAPlugRemoved (1 << TI_bUsbIntAPlugRemoved)
#define TI_usbIsr 0xc0
#define TI_pUsbIsr 0x0
#define TI_mpUsbIsr 0x0
#define TI_usbImr 0xc4
#define TI_pUsbImr 0x0
#define TI_mpUsbImr 0x0
#define TI_bUsbIntDev 0x0
#define TI_bmUsbIntDev (1 << TI_bUsbIntDev)
#define TI_bUsbIntOtg 0x1
#define TI_bmUsbIntOtg (1 << TI_bUsbIntOtg)
#define TI_bUsbIntHost 0x2
#define TI_bmUsbIntHost (1 << TI_bUsbIntHost)
#define TI_bUsbIntLevel 0x3
#define TI_usbIntLevelLow (0 << TI_bUsbIntLevel)
#define TI_usbIntLevelHigh (1 << TI_bUsbIntLevel)
#define TI_bmUsbIntLevel (1 << TI_bUsbIntLevel)
#define TI_usbDevCtrl 0x100
#define TI_pUsbDevCtrl 0x0
#define TI_mpUsbDevCtrl 0x0
#define TI_bUsbRemoteWake 0x0
#define TI_bmUsbRemoteWake (1 << TI_bUsbRemoteWake)
#define TI_bUsbHalfSpd 0x1
#define TI_bmUsbHalfSpd (1 << TI_bUsbHalfSpd)
#define TI_bUsbGirqEn 0x2
#define TI_bmUsbGirqEn (1 << TI_bUsbGirqEn)
#define TI_bUsbDevSuspend 0x3
#define TI_bmUsbDevSuspend (1 << TI_bUsbDevSuspend)
#define TI_bUsbDevReset 0x4
#define TI_bmUsbDevReset (1 << TI_bUsbDevReset)
#define TI_bUsbDevEn 0x5
#define TI_bmUsbDevEn (1 << TI_bUsbDevEn)
#define TI_bUsbDevSpd 0x6
#define TI_bmUsbDevSpd (1 << TI_bUsbDevSpd)
#define TI_bUsbDevForceFullSpd 0x9
#define TI_bmUsbDevForceFullSpd (1 << TI_bUsbDevForceFullSpd)
#define TI_usbDevAddr 0x104
#define TI_pUsbDevAddr 0x0
#define TI_mpUsbDevAddr 0x0
#define TI_bUsbDevAddr 0x0
#define TI_bmUsbDevAddr (07Fh << TI_bUsbDevAddr)
#define TI_bUsbDevConf 0x7
#define TI_bmUsbDevConf (1 << TI_bUsbDevConf)
#define TI_usbDevTest 0x108
#define TI_pUsbDevTest 0x0
#define TI_mpUsbDevTest 0x0
#define TI_bUsbTstClrFifo 0x0
#define TI_bmUsbTstClrFifo (1 << TI_bUsbTstClrFifo)
#define TI_bUsbTstCxLp 0x1
#define TI_bmUsbTstCxLp (1 << TI_bUsbTstCxLp)
#define TI_bUsbTstClrEa 0x2
#define TI_bmUsbTstClrEa (1 << TI_bUsbTstClrEa)
#define TI_bUsbTstNoCrc 0x3
#define TI_bmUsbTstNoCrc (1 << TI_bUsbTstNoCrc)
#define TI_bUsbTstNoTs 0x4
#define TI_bmUsbTstNoTs (1 << TI_bUsbTstNoTs)
#define TI_bUsbTstMode 0x5
#define TI_bmUsbTstMode (1 << TI_bUsbTstMode)
#define TI_bUsbNoSof 0x6
#define TI_bmUsbNoSof (1 << TI_bUsbNoSof)
#define TI_usbSofFrNum 0x10c
#define TI_pUsbSofFrNum 0x0
#define TI_mpUsbSofFrNum 0x0
#define TI_bUsbSofFrNum 0x0
#define TI_bmUsbSofFrNum (07FFh << TI_bUsbSofFrNum)
#define TI_bUsbSofUFrNum 0x11
#define TI_bmUsbSofUFrNum (7 << TI_bUsbSofUFrNum)
#define TI_usbSofMtr 0x110
#define TI_pUsbSofMtr 0x0
#define TI_mpUsbSofMtr 0x0
#define TI_bUsbSofMtrTmr 0x0
#define TI_bmUsbSofMtrTmr (0FFFFh << TI_bUsbSofMtrTmr)
#define TI_usbPhyTmsr 0x114
#define TI_pUsbPhyTmsr 0x0
#define TI_mpUsbPhyTmsr 0x0
#define TI_bUsbUnplug 0x0
#define TI_bmUsbUnplug (1 << TI_bUsbUnplug)
#define TI_bUsbTstJState 0x1
#define TI_bmUsbTstJState (1 << TI_bUsbTstJState)
#define TI_bUsbTstKState 0x2
#define TI_bmUsbTstKState (1 << TI_bUsbTstKState)
#define TI_bUsbTstSe0Nak 0x3
#define TI_bmUsbTstSe0Nak (1 << TI_bUsbTstSe0Nak)
#define TI_bUsbTstPkt 0x4
#define TI_bmUsbTstPkt (1 << TI_bUsbTstPkt)
#define TI_usbCxsr 0x11c
#define TI_pUsbCxsr 0x0
#define TI_mpUsbCxsr 0x0
#define TI_usbCxFifo 0x120
#define TI_pUsbCxFifo 0x0
#define TI_mpUsbCxFifo 0x0
#define TI_bCxFifoFin 0x0
#define TI_bmCxFifoFin (1 << TI_bCxFifoFin)
#define TI_bTstPktFin 0x1
#define TI_bmTstPktFin (1 << TI_bTstPktFin)
#define TI_bCxFifoStall 0x2
#define TI_bmCxFifoStall (1 << TI_bCxFifoStall)
#define TI_bCxFifoClr 0x3
#define TI_bmCxFifoClr (1 << TI_bCxFifoClr)
#define TI_bCxFifoFull 0x4
#define TI_bmCxFifoFull (1 << TI_bCxFifoFull)
#define TI_bCxFifoEmpty 0x5
#define TI_bmCxFifoEmpty (1 << TI_bCxFifoEmpty)
#define TI_bFifo0Empty 0x8
#define TI_bmFifo0Empty (1 << TI_bFifo0Empty)
#define TI_bFifo1Empty 0x9
#define TI_bmFifo1Empty (1 << TI_bFifo1Empty)
#define TI_bFifo2Empty 0x10
#define TI_bmFifo2Empty (1 << TI_bFifo2Empty)
#define TI_bFifo3Empty 0x11
#define TI_bmFifo3Empty (1 << TI_bFifo3Empty)
#define TI_bFifoEmpty 0x8
#define TI_bmFifoEmpty (0Fh << TI_bFifoEmpty)
#define TI_usbCxFifoBytes 0x123
#define TI_pUsbCxFifoBytes 0x0
#define TI_mpUsbCxFifoBytes 0x0
#define TI_bUsbCxFifoBytes 0x0
#define TI_bmUsbCxFifoBytes 0x7f
#define TI_usbIdle 0x124
#define TI_pUsbIdle 0x0
#define TI_mpUsbIdle 0x0
#define TI_bUsbIdleMs 0x0
#define TI_bmUsbIdleMs (7 << TI_bUsbIdleMs)
#define TI_usbGimr 0x130
#define TI_pUsbGimr 0x0
#define TI_mpUsbGimr 0x0
#define TI_usbGisr 0x140
#define TI_pUsbGisr 0x0
#define TI_mpUsbGisr 0x0
#define TI_bUsbDevIntCx 0x0
#define TI_bmUsbDevIntCx (1 << TI_bUsbDevIntCx)
#define TI_bUsbDevIntFifo 0x1
#define TI_bmUsbDevIntFifo (1 << TI_bUsbDevIntFifo)
#define TI_bUsbDevIntDev 0x2
#define TI_bmUsbDevIntDev (1 << TI_bUsbDevIntDev)
#define TI_usbCxImr 0x134
#define TI_pUsbCxImr 0x0
#define TI_mpUsbCxImr 0x0
#define TI_usbCxIsr 0x144
#define TI_pUsbCxIsr 0x0
#define TI_mpUsbCxIsr 0x0
#define TI_bUsbIntCxSetup 0x0
#define TI_bmUsbIntCxSetup (1 << TI_bUsbIntCxSetup)
#define TI_bUsbIntCxIn 0x1
#define TI_bmUsbIntCxIn (1 << TI_bUsbIntCxIn)
#define TI_bUsbIntCxOut 0x2
#define TI_bmUsbIntCxOut (1 << TI_bUsbIntCxOut)
#define TI_bUsbIntCxEnd 0x3
#define TI_bmUsbIntCxEnd (1 << TI_bUsbIntCxEnd)
#define TI_bUsbIntCxErr 0x4
#define TI_bmUsbIntCxErr (1 << TI_bUsbIntCxErr)
#define TI_bUsbIntCxAbort 0x5
#define TI_bmUsbIntCxAbort (1 << TI_bUsbIntCxAbort)
#define TI_bUsbIntCx 0x0
#define TI_bmUsbIntCx (01Fh << TI_bUsbIntCx)
#define TI_usbFifoRxImr 0x138
#define TI_pUsbFifoRxImr 0x0
#define TI_mpUsbFifoRxImr 0x0
#define TI_usbFifoRxIsr 0x148
#define TI_pUsbFifoRxIsr 0x0
#define TI_mpUsbFifoRxIsr 0x0
#define TI_bUsbIntFifo0Out 0x0
#define TI_bmUsbIntFifo0Out (1 << TI_bUsbIntFifo0Out)
#define TI_bUsbIntFifo0Spk 0x1
#define TI_bmUsbIntFifo0Spk (1 << TI_bUsbIntFifo0Spk)
#define TI_bUsbIntFifo1Out 0x2
#define TI_bmUsbIntFifo1Out (1 << TI_bUsbIntFifo1Out)
#define TI_bUsbIntFifo1Spk 0x3
#define TI_bmUsbIntFifo1Spk (1 << TI_bUsbIntFifo1Spk)
#define TI_bUsbIntFifo2Out 0x4
#define TI_bmUsbIntFifo2Out (1 << TI_bUsbIntFifo2Out)
#define TI_bUsbIntFifo2Spk 0x5
#define TI_bmUsbIntFifo2Spk (1 << TI_bUsbIntFifo2Spk)
#define TI_bUsbIntFifo3Out 0x6
#define TI_bmUsbIntFifo3Out (1 << TI_bUsbIntFifo3Out)
#define TI_bUsbIntFifo3Spk 0x7
#define TI_bmUsbIntFifo3Spk (1 << TI_bUsbIntFifo3Spk)
#define TI_bUsbFifoRxInts 0x0
#define TI_bmUsbFifoRxInts (0FFh << TI_bUsbFifoRxInts)
#define TI_usbFifoTxImr 0x13a
#define TI_pUsbFifoTxImr 0x0
#define TI_mpUsbFifoTxImr 0x0
#define TI_usbFifoTxIsr 0x14a
#define TI_pUsbFifoTxIsr 0x0
#define TI_mpUsbFifoTxIsr 0x0
#define TI_bUsbIntFifo0In 0x0
#define TI_bmUsbIntFifo0In (1 << TI_bUsbIntFifo0In)
#define TI_bUsbIntFifo1In 0x1
#define TI_bmUsbIntFifo1In (1 << TI_bUsbIntFifo1In)
#define TI_bUsbIntFifo2In 0x2
#define TI_bmUsbIntFifo2In (1 << TI_bUsbIntFifo2In)
#define TI_bUsbIntFifo3In 0x3
#define TI_bmUsbIntFifo3In (1 << TI_bUsbIntFifo3In)
#define TI_bUsbFifoTxInts 0x0
#define TI_bmUsbFifoTxInts (0Fh << TI_bUsbFifoTxInts)
#define TI_usbDevImr 0x13c
#define TI_pUsbDevImr 0x0
#define TI_mpUsbDevImr 0x0
#define TI_usbDevIsr 0x14c
#define TI_pUsbDevIsr 0x0
#define TI_mpUsbDevIsr 0x0
#define TI_bUsbIntDevReset 0x0
#define TI_bmUsbIntDevReset (1 << TI_bUsbIntDevReset)
#define TI_bUsbIntDevSuspend 0x1
#define TI_bmUsbIntDevSuspend (1 << TI_bUsbIntDevSuspend)
#define TI_bUsbIntDevResume 0x2
#define TI_bmUsbIntDevResume (1 << TI_bUsbIntDevResume)
#define TI_bUsbIntDevIsocErr 0x3
#define TI_bmUsbIntDevIsocErr (1 << TI_bUsbIntDevIsocErr)
#define TI_bUsbIntDevIsocAbt 0x4
#define TI_bmUsbIntDevIsocAbt (1 << TI_bUsbIntDevIsocAbt)
#define TI_bUsbIntDevZlpTx 0x5
#define TI_bmUsbIntDevZlpTx (1 << TI_bUsbIntDevZlpTx)
#define TI_bUsbIntDevZlpRx 0x6
#define TI_bmUsbIntDevZlpRx (1 << TI_bUsbIntDevZlpRx)
#define TI_bUsbIntDevDmaFin 0x7
#define TI_bmUsbIntDevDmaFin (1 << TI_bUsbIntDevDmaFin)
#define TI_bUsbIntDevDmaErr 0x8
#define TI_bmUsbIntDevDmaErr (1 << TI_bUsbIntDevDmaErr)
#define TI_bUsbIntDevIdle 0x9
#define TI_bmUsbIntDevIdle (1 << TI_bUsbIntDevIdle)
#define TI_bUsbIntDevWakeup 0x10
#define TI_bmUsbIntDevWakeup (1 << TI_bUsbIntDevWakeup)
#define TI_bUsbDevInts 0x0
#define TI_bmUsbDevInts (07FFh << TI_bUsbDevInts)
#define TI_usbRxZlp 0x150
#define TI_pUsbRxZlp 0x0
#define TI_mpUsbRxZlp 0x0
#define TI_usbTxZlp 0x154
#define TI_pUsbTxZlp 0x0
#define TI_mpUsbTxZlp 0x0
#define TI_bUsbEp1Zlp 0x0
#define TI_bmUsbEp1Zlp (1 << TI_bUsbEp1Zlp)
#define TI_bUsbEp2Zlp 0x1
#define TI_bmUsbEp2Zlp (1 << TI_bUsbEp2Zlp)
#define TI_bUsbEp3Zlp 0x2
#define TI_bmUsbEp3Zlp (1 << TI_bUsbEp3Zlp)
#define TI_bUsbEp4Zlp 0x3
#define TI_bmUsbEp4Zlp (1 << TI_bUsbEp4Zlp)
#define TI_bUsbEp5Zlp 0x4
#define TI_bmUsbEp5Zlp (1 << TI_bUsbEp5Zlp)
#define TI_bUsbEp6Zlp 0x5
#define TI_bmUsbEp6Zlp (1 << TI_bUsbEp6Zlp)
#define TI_bUsbEp7Zlp 0x6
#define TI_bmUsbEp7Zlp (1 << TI_bUsbEp7Zlp)
#define TI_bUsbEp8Zlp 0x7
#define TI_bmUsbEp8Zlp (1 << TI_bUsbEp8Zlp)
#define TI_bUsbZlp 0x0
#define TI_bmUsbZlp (0FFh << TI_bUsbZlp)
#define TI_usbIsoEasr 0x158
#define TI_pUsbIsoEasr 0x0
#define TI_mpUsbIsoEasr 0x0
#define TI_bUsbEp1IsocAbort 0x0
#define TI_bmUsbEp1IsocAbort (1 << TI_bUsbEp1IsocAbort)
#define TI_bUsbEp2IsocAbort 0x1
#define TI_bmUsbEp2IsocAbort (1 << TI_bUsbEp2IsocAbort)
#define TI_bUsbEp3IsocAbort 0x2
#define TI_bmUsbEp3IsocAbort (1 << TI_bUsbEp3IsocAbort)
#define TI_bUsbEp4IsocAbort 0x3
#define TI_bmUsbEp4IsocAbort (1 << TI_bUsbEp4IsocAbort)
#define TI_bUsbEp5IsocAbort 0x4
#define TI_bmUsbEp5IsocAbort (1 << TI_bUsbEp5IsocAbort)
#define TI_bUsbEp6IsocAbort 0x5
#define TI_bmUsbEp6IsocAbort (1 << TI_bUsbEp6IsocAbort)
#define TI_bUsbEp7IsocAbort 0x6
#define TI_bmUsbEp7IsocAbort (1 << TI_bUsbEp7IsocAbort)
#define TI_bUsbEp8IsocAbort 0x7
#define TI_bmUsbEp8IsocAbort (1 << TI_bUsbEp8IsocAbort)
#define TI_bUsbEp1IsocErr 0x16
#define TI_bmUsbEp1IsocErr (1 << TI_bUsbEp1IsocErr)
#define TI_bUsbEp2IsocErr 0x17
#define TI_bmUsbEp2IsocErr (1 << TI_bUsbEp2IsocErr)
#define TI_bUsbEp3IsocErr 0x18
#define TI_bmUsbEp3IsocErr (1 << TI_bUsbEp3IsocErr)
#define TI_bUsbEp4IsocErr 0x19
#define TI_bmUsbEp4IsocErr (1 << TI_bUsbEp4IsocErr)
#define TI_bUsbEp5IsocErr 0x20
#define TI_bmUsbEp5IsocErr (1 << TI_bUsbEp5IsocErr)
#define TI_bUsbEp6IsocErr 0x21
#define TI_bmUsbEp6IsocErr (1 << TI_bUsbEp6IsocErr)
#define TI_bUsbEp7IsocErr 0x22
#define TI_bmUsbEp7IsocErr (1 << TI_bUsbEp7IsocErr)
#define TI_bUsbEp8IsocErr 0x23
#define TI_bmUsbEp8IsocErr (1 << TI_bUsbEp8IsocErr)
#define TI_usbInEp1 0x160
#define TI_pUsbInEp1 0x0
#define TI_mpUsbInEp1 0x0
#define TI_usbInEp2 0x164
#define TI_pUsbInEp2 0x0
#define TI_mpUsbInEp2 0x0
#define TI_usbInEp3 0x168
#define TI_pUsbInEp3 0x0
#define TI_mpUsbInEp3 0x0
#define TI_usbInEp4 0x16c
#define TI_pUsbInEp4 0x0
#define TI_mpUsbInEp4 0x0
#define TI_usbInEp5 0x170
#define TI_pUsbInEp5 0x0
#define TI_mpUsbInEp5 0x0
#define TI_usbInEp6 0x174
#define TI_pUsbInEp6 0x0
#define TI_mpUsbInEp6 0x0
#define TI_usbInEp7 0x178
#define TI_pUsbInEp7 0x0
#define TI_mpUsbInEp7 0x0
#define TI_usbInEp8 0x17c
#define TI_pUsbInEp8 0x0
#define TI_mpUsbInEp8 0x0
#define TI_usbOutEp1 0x180
#define TI_pUsbOutEp1 0x0
#define TI_mpUsbOutEp1 0x0
#define TI_usbOutEp2 0x184
#define TI_pUsbOutEp2 0x0
#define TI_mpUsbOutEp2 0x0
#define TI_usbOutEp3 0x188
#define TI_pUsbOutEp3 0x0
#define TI_mpUsbOutEp3 0x0
#define TI_usbOutEp4 0x18c
#define TI_pUsbOutEp4 0x0
#define TI_mpUsbOutEp4 0x0
#define TI_usbOutEp5 0x190
#define TI_pUsbOutEp5 0x0
#define TI_mpUsbOutEp5 0x0
#define TI_usbOutEp6 0x194
#define TI_pUsbOutEp6 0x0
#define TI_mpUsbOutEp6 0x0
#define TI_usbOutEp7 0x198
#define TI_pUsbOutEp7 0x0
#define TI_mpUsbOutEp7 0x0
#define TI_usbOutEp8 0x19c
#define TI_pUsbOutEp8 0x0
#define TI_mpUsbOutEp8 0x0
#define TI_bUsbEpMaxPktSz 0x0
#define TI_bmUsbEpMaxPktSz (07FFh << TI_bUsbEpMaxPktSz)
#define TI_bUsbEpStall 0x11
#define TI_bmUsbEpStall (1 << TI_bUsbEpStall)
#define TI_bUsbEpReset 0x12
#define TI_bmUsbEpReset (1 << TI_bUsbEpReset)
#define TI_bUsbInEpTxNum 0x13
#define TI_bmUsbInEpTxNum (3 << TI_bUsbInEpTxNum)
#define TI_bUsbInEpSendZlp 0x15
#define TI_bmUsbInEpSendZlp (1 << TI_bUsbInEpSendZlp)
#define TI_usbEp1Map 0x1a0
#define TI_pUsbEp1Map 0x0
#define TI_mpUsbEp1Map 0x0
#define TI_usbEp2Map 0x1a1
#define TI_pUsbEp2Map 0x0
#define TI_mpUsbEp2Map 0x0
#define TI_usbEp3Map 0x1a2
#define TI_pUsbEp3Map 0x0
#define TI_mpUsbEp3Map 0x0
#define TI_usbEp4Map 0x1a3
#define TI_pUsbEp4Map 0x0
#define TI_mpUsbEp4Map 0x0
#define TI_usbEp5Map 0x1a4
#define TI_pUsbEp5Map 0x0
#define TI_mpUsbEp5Map 0x0
#define TI_usbEp6Map 0x1a5
#define TI_pUsbEp6Map 0x0
#define TI_mpUsbEp6Map 0x0
#define TI_usbEp7Map 0x1a6
#define TI_pUsbEp7Map 0x0
#define TI_mpUsbEp7Map 0x0
#define TI_usbEp8Map 0x1a7
#define TI_pUsbEp8Map 0x0
#define TI_mpUsbEp8Map 0x0
#define TI_bUsbEpMapIn 0x0
#define TI_bmUsbEpMapIn (0Fh << TI_bUsbEpMapIn)
#define TI_bUsbEpMapOut 0x4
#define TI_bmUsbEpMapOut (0Fh << TI_bUsbEpMapOut)
#define TI_usbFifo0Map 0x1a8
#define TI_pUsbFifo0Map 0x0
#define TI_mpUsbFifo0Map 0x0
#define TI_usbFifo1Map 0x1a9
#define TI_pUsbFifo1Map 0x0
#define TI_mpUsbFifo1Map 0x0
#define TI_usbFifo2Map 0x1aa
#define TI_pUsbFifo2Map 0x0
#define TI_mpUsbFifo2Map 0x0
#define TI_usbFifo3Map 0x1ab
#define TI_pUsbFifo3Map 0x0
#define TI_mpUsbFifo3Map 0x0
#define TI_bUsbFifoEp 0x0
#define TI_bmUsbFifoEp (0Fh << TI_bUsbFifoEp)
#define TI_bUsbFifoDir 0x4
#define TI_usbFifoOut (0 << TI_bUsbFifoDir)
#define TI_usbFifoIn (1 << TI_bUsbFifoDir)
#define TI_usbFifoBi (2 << TI_bUsbFifoDir)
#define TI_bmUsbFifoDir (3 << TI_bUsbFifoDir)
#define TI_usbFifo0Cfg 0x1ac
#define TI_pUsbFifo0Cfg 0x0
#define TI_mpUsbFifo0Cfg 0x0
#define TI_usbFifo1Cfg 0x1ad
#define TI_pUsbFifo1Cfg 0x0
#define TI_mpUsbFifo1Cfg 0x0
#define TI_usbFifo2Cfg 0x1ae
#define TI_pUsbFifo2Cfg 0x0
#define TI_mpUsbFifo2Cfg 0x0
#define TI_usbFifo3Cfg 0x1af
#define TI_pUsbFifo3Cfg 0x0
#define TI_mpUsbFifo3Cfg 0x0
#define TI_bUsbFifoType 0x0
#define TI_usbFifoIsoc (1 << TI_bUsbFifoType)
#define TI_usbFifoBulk (2 << TI_bUsbFifoType)
#define TI_usbFifoIntr (3 << TI_bUsbFifoType)
#define TI_bmUsbFifoType (3 << TI_bUsbFifoType)
#define TI_bUsbFifoNumBlks 0x2
#define TI_usbFifo1Blk (0 << TI_bUsbFifoNumBlks)
#define TI_usbFifo2Blks (1 << TI_bUsbFifoNumBlks)
#define TI_usbFifo3Blks (2 << TI_bUsbFifoNumBlks)
#define TI_bmUsbFifoNumBlks (3 << TI_bUsbFifoNumBlks)
#define TI_bUsbFifoBlkSz 0x4
#define TI_usbFifoBlkSz512 (0 << TI_bUsbFifoBlkSz)
#define TI_usbFifoBlkSz1024 (1 << TI_bUsbFifoBlkSz)
#define TI_bmUsbFifoBlkSz (1 << TI_bUsbFifoBlkSz)
#define TI_bUsbFifoEn 0x5
#define TI_bmUsbFifoEn (1 << TI_bUsbFifoEn)
#define TI_usbFifo0Csr 0x1b0
#define TI_pUsbFifo0Csr 0x0
#define TI_mpUsbFifo0Csr 0x0
#define TI_usbFifo1Csr 0x1b4
#define TI_pUsbFifo1Csr 0x0
#define TI_mpUsbFifo1Csr 0x0
#define TI_usbFifo2Csr 0x1b8
#define TI_pUsbFifo2Csr 0x0
#define TI_mpUsbFifo2Csr 0x0
#define TI_usbFifo3Csr 0x1bc
#define TI_pUsbFifo3Csr 0x0
#define TI_mpUsbFifo3Csr 0x0
#define TI_bUsbFifoLen 0x0
#define TI_bmUsbFifoLen (07FFh << TI_bUsbFifoLen)
#define TI_bUsbFifoReset 0x12
#define TI_bmUsbFifoReset (1 << TI_bUsbFifoReset)
#define TI_usbDmaFifo 0x1c0
#define TI_pUsbDmaFifo 0x0
#define TI_mpUsbDmaFifo 0x0
#define TI_bUsbDmaFifo0 0x0
#define TI_bmUsbDmaFifo0 (1 << TI_bUsbDmaFifo0)
#define TI_bUsbDmaFifo1 0x1
#define TI_bmUsbDmaFifo1 (1 << TI_bUsbDmaFifo1)
#define TI_bUsbDmaFifo2 0x2
#define TI_bmUsbDmaFifo2 (1 << TI_bUsbDmaFifo2)
#define TI_bUsbDmaFifo3 0x3
#define TI_bmUsbDmaFifo3 (1 << TI_bUsbDmaFifo3)
#define TI_bUsbDmaCxFifo 0x4
#define TI_bmUsbDmaCxFifo (1 << TI_bUsbDmaCxFifo)
#define TI_bUsbDmaFifo 0x0
#define TI_bmUsbDmaNoFifo (0 << TI_bUsbDmaFifo)
#define TI_bmUsbDmaFifo (01Fh << TI_bUsbDmaFifo)
#define TI_usbDmaCtrl 0x1c8
#define TI_pUsbDmaCtrl 0x0
#define TI_mpUsbDmaCtrl 0x0
#define TI_bUsbDmaStart 0x0
#define TI_bmUsbDmaStart (1 << TI_bUsbDmaStart)
#define TI_bUsbDmaDir 0x1
#define TI_usbDmaFifo2Mem (0 << TI_bUsbDmaDir)
#define TI_usbDmaMem2Fifo (1 << TI_bUsbDmaDir)
#define TI_usbDmaFifo2Fifo (2 << TI_bUsbDmaDir)
#define TI_bmUsbDmaDir (3 << TI_bUsbDmaDir)
#define TI_bUsbDmaAbort 0x3
#define TI_bmUsbDmaAbort (1 << TI_bUsbDmaAbort)
#define TI_bUsbDmaClrFifo 0x4
#define TI_bmUsbDmaClrFifo (1 << TI_bUsbDmaClrFifo)
#define TI_usbDmaLen 0x1c9
#define TI_pUsbDmaLen 0x0
#define TI_mpUsbDmaLen 0x0
#define TI_bUsbDmaLen 0x0
#define TI_bmUsbDmaLen (01FFFFh << TI_bUsbDmaLen)
#define TI_usbDmaAddr 0x1cc
#define TI_pUsbDmaAddr 0x0
#define TI_mpUsbDmaAddr 0x0
#define TI_bUsbDmaAddr 0x0
#define TI_bmUsbDmaAddr (07FFFFh << TI_bUsbDmaAddr)
#define TI_usbEp0Data 0x1d0
#define TI_pUsbEp0Data 0x0
#define TI_mpUsbEp0Data 0x0
#define TI_bUsbEp0Data 0x0
#define TI_bmUsbEp0Data (0FFFFFFFFh << TI_bUsbEp0Data)
// LCD Ports
// --------------------------------
#define TI_pLcdRange 0x4000
#define TI_mpLcdRange 0xe30000
#define TI_lcdTiming0 0x0
#define TI_pLcdTiming0 0x0
#define TI_mpLcdTiming0 0x0
#define TI_lcdTiming1 0x4
#define TI_pLcdTiming1 0x0
#define TI_mpLcdTiming1 0x0
#define TI_lcdTiming2 0x8
#define TI_pLcdTiming2 0x0
#define TI_mpLcdTiming2 0x0
#define TI_lcdTiming3 0xc
#define TI_pLcdTiming3 0x0
#define TI_mpLcdTiming3 0x0
#define TI_lcdBase 0x10
#define TI_pLcdBase 0x0
#define TI_mpLcdBase 0x0
#define TI_lcdUpbase 0x10
#define TI_pLcdUpbase 0x0
#define TI_mpLcdUpbase 0x0
#define TI_lcdLpbase 0x14
#define TI_pLcdLpbase 0x0
#define TI_mpLcdLpbase 0x0
#define TI_lcdCtrl 0x18
#define TI_pLcdCtrl 0x0
#define TI_mpLcdCtrl 0x0
#define TI_lcdEn 0x1
#define TI_lcdTft 0x20
#define TI_lcdBpp1 0xb
#define TI_lcdBpp2 0x10b
#define TI_lcdBpp4 0x100b
#define TI_lcdBpp8 0x110b
#define TI_lcdBpp16Alt 0x1000b
#define TI_lcdBpp24 0x1010b
#define TI_lcdBpp16 0x1100b //  Default LCD mode
#define TI_lcdBpp12 0x1110b
#define TI_lcdBgr 0x100
#define TI_lcdBigEndian 0x200
#define TI_lcdBigEndianPixels 0x400
#define TI_lcdPwr 0x800
#define TI_lcdIntVSync 0x0
#define TI_lcdIntBack 0x1000
#define TI_lcdIntActiveVideo 0x2000
#define TI_lcdIntFront 0x3000
#define TI_lcdWatermark 0x10000
#define TI_lcdNormalMode 0x0
#define TI_lcdImsc 0x1c
#define TI_pLcdImsc 0x0
#define TI_mpLcdImsc 0x0
#define TI_lcdRis 0x20
#define TI_pLcdRis 0x0
#define TI_mpLcdRis 0x0
#define TI_lcdMis 0x24
#define TI_pLcdMis 0x0
#define TI_mpLcdMis 0x0
#define TI_lcdIcr 0x28
#define TI_pLcdIcr 0x0
#define TI_mpLcdIcr 0x0
#define TI_bLcdIntFuf 0x1
#define TI_lcdIntFuf (1 << TI_bLcdIntFuf)
#define TI_bLcdIntLNBU 0x2
#define TI_lcdIntLNBU (1 << TI_bLcdIntLNBU)
#define TI_bLcdIntVcomp 0x3
#define TI_lcdIntVcomp (1 << TI_bLcdIntVcomp)
#define TI_bLcdIntMbErr 0x4
#define TI_lcdIntMbErr (1 << TI_bLcdIntMbErr)
#define TI_lcdCurr 0x2c
#define TI_pLcdCurr 0x0
#define TI_mpLcdCurr 0x0
#define TI_lcdUpcurr 0x2c
#define TI_pLcdUpcurr 0x0
#define TI_mpLcdUpcurr 0x0
#define TI_lcdLpcurr 0x30
#define TI_pLcdLpcurr 0x0
#define TI_mpLcdLpcurr 0x0
#define TI_lcdPalette 0x200
#define TI_pLcdPalette 0x0
#define TI_mpLcdPalette 0x0
#define TI_lcdCrsrImage 0x800
#define TI_pLcdCrsrImage 0x0
#define TI_mpLcdCrsrImage 0x0
#define TI_lcdCrsrCtrl 0xc00
#define TI_pLcdCrsrCtrl 0x0
#define TI_mpLcdCrsrCtrl 0x0
#define TI_lcdCrsrConfig 0xc04
#define TI_pLcdCrsrConfig 0x0
#define TI_mpLcdCrsrConfig 0x0
#define TI_lcdCrsrPalette0 0xc08
#define TI_pLcdCrsrPalette0 0x0
#define TI_mpLcdCrsrPalette0 0x0
#define TI_lcdCrsrPalette1 0xc0c
#define TI_pLcdCrsrPalette1 0x0
#define TI_mpLcdCrsrPalette1 0x0
#define TI_lcdCrsrXY 0xc10
#define TI_pLcdCrsrXY 0x0
#define TI_mpLcdCrsrXY 0x0
#define TI_lcdCrsrClip 0xc14
#define TI_pLcdCrsrClip 0x0
#define TI_mpLcdCrsrClip 0x0
#define TI_lcdCrsrImsc 0xc20
#define TI_pLcdCrsrImsc 0x0
#define TI_mpLcdCrsrImsc 0x0
#define TI_lcdCrsrIcr 0xc24
#define TI_pLcdCrsrIcr 0x0
#define TI_mpLcdCrsrIcr 0x0
#define TI_lcdCrsrRis 0xc28
#define TI_pLcdCrsrRis 0x0
#define TI_mpLcdCrsrRis 0x0
#define TI_lcdCrsrMis 0xc2c
#define TI_pLcdCrsrMis 0x0
#define TI_mpLcdCrsrMis 0x0
// Interrupt Ports
// -----------------------------------
#define TI_pIntRange 0x5000
#define TI_mpIntRange 0xf00000
#define TI_intStat 0x0
#define TI_pIntStat 0x0
#define TI_mpIntStat 0x0
#define TI_intMask 0x4
#define TI_pIntMask 0x0
#define TI_mpIntMask 0x0
#define TI_intAck 0x8
#define TI_pIntAck 0x0
#define TI_mpIntAck 0x0
#define TI_intLatch 0x12
#define TI_pIntLatch 0x0
#define TI_mpIntLatch 0x0
#define TI_intInvert 0x16
#define TI_pIntInvert 0x0
#define TI_mpIntInvert 0x0
#define TI_intMasked 0x20
#define TI_pIntMasked 0x0
#define TI_mpIntMasked 0x0
#define TI_bIntOn 0x0
#define TI_intOn (1 << TI_bIntOn)
#define TI_bIntTmr1 0x1
#define TI_intTmr1 (1 << TI_bIntTmr1)
#define TI_bIntTmr2 0x2
#define TI_intTmr2 (1 << TI_bIntTmr2)
#define TI_bIntTmr3 0x3
#define TI_intTmr3 (1 << TI_bIntTmr3)
#define TI_bIntOSTmr 0x4
#define TI_intOSTmr (1 << TI_bIntOSTmr)
#define TI_bIntKey 0x10
#define TI_intKey (1 << TI_bIntKey)
#define TI_bIntLcd 0x11
#define TI_intLcd (1 << TI_bIntLcd)
#define TI_bIntRtc 0x12
#define TI_intRtc (1 << TI_bIntRtc)
#define TI_bIntUsb 0x13
#define TI_intUsb (1 << TI_bIntUsb)
#define TI_intDefaultMask 0x0
// Timer Ports
// -----------------------------------
#define TI_tmrRange 0x0
#define TI_pTmrRange 0x7000
#define TI_mpTmrRange 0xf20000
#define TI_tmr1Counter 0x0
#define TI_pTmr1Counter 0x7000
#define TI_mpTmr1Counter 0xf20000
#define TI_tmr1Load 0x4
#define TI_pTmr1Load 0x7004
#define TI_mpTmr1Load 0xf20004
#define TI_tmr1Match1 0x8
#define TI_pTmr1Match1 0x7008
#define TI_mpTmr1Match1 0xf20008
#define TI_tmr1Match2 0xc
#define TI_pTmr1Match2 0x700c
#define TI_mpTmr1Match2 0xf2000c
#define TI_tmr2Counter 0x10
#define TI_pTmr2Counter 0x7010
#define TI_mpTmr2Counter 0xf20010
#define TI_tmr2Load 0x14
#define TI_pTmr2Load 0x7014
#define TI_mpTmr2Load 0xf20014
#define TI_tmr2Match1 0x18
#define TI_pTmr2Match1 0x7018
#define TI_mpTmr2Match1 0xf20018
#define TI_tmr2Match2 0x1c
#define TI_pTmr2Match2 0x701c
#define TI_mpTmr2Match2 0xf2001c
#define TI_tmr3Counter 0x20
#define TI_pTmr3Counter 0x7020
#define TI_mpTmr3Counter 0xf20020
#define TI_tmr3Load 0x24
#define TI_pTmr3Load 0x7024
#define TI_mpTmr3Load 0xf20024
#define TI_tmr3Match1 0x28
#define TI_pTmr3Match1 0x7028
#define TI_mpTmr3Match1 0xf20028
#define TI_tmr3Match2 0x2c
#define TI_pTmr3Match2 0x702c
#define TI_mpTmr3Match2 0xf2002c
#define TI_tmrCtrl 0x30
#define TI_pTmrCtrl 0x7030
#define TI_mpTmrCtrl 0xf20030
#define TI_bTmr1Enable 0x0
#define TI_tmr1Enable (1 << TI_bTmr1Enable)
#define TI_bTmr1Crystal 0x1
#define TI_tmr1Crystal (1 << TI_bTmr1Crystal)
#define TI_bTmr1Overflow 0x2
#define TI_tmr1Overflow (1 << TI_bTmr1Overflow)
#define TI_bTmr2Enable 0x3
#define TI_tmr2Enable (1 << TI_bTmr2Enable)
#define TI_bTmr2Crystal 0x4
#define TI_tmr2Crystal (1 << TI_bTmr2Crystal)
#define TI_bTmr2Overflow 0x5
#define TI_tmr2Overflow (1 << TI_bTmr2Overflow)
#define TI_bTmr3Enable 0x6
#define TI_tmr3Enable (1 << TI_bTmr3Enable)
#define TI_bTmr3Crystal 0x7
#define TI_tmr3Crystal (1 << TI_bTmr3Crystal)
#define TI_bTmr3Overflow 0x8
#define TI_tmr3Overflow (1 << TI_bTmr3Overflow)
#define TI_bTmr1CountUp 0x9
#define TI_tmr1CountUp (1 << TI_bTmr1CountUp)
#define TI_bTmr2CountUp 0x10
#define TI_tmr2CountUp (1 << TI_bTmr2CountUp)
#define TI_bTmr3CountUp 0x11
#define TI_tmr3CountUp (1 << TI_bTmr3CountUp)
#define TI_tmrIntStatus 0x34
#define TI_pTmrIntStatus 0x7034
#define TI_mpTmrIntStatus 0xf20034
#define TI_bTmr1IntMatch1 0x0
#define TI_tmr1IntMatch1 (1 << TI_bTmr1IntMatch1)
#define TI_bTmr1IntMatch2 0x1
#define TI_tmr1IntMatch2 (1 << TI_bTmr1IntMatch2)
#define TI_bTmr1IntOverflow 0x2
#define TI_tmr1IntOverflow (1 << TI_bTmr1IntOverflow)
#define TI_bTmr2IntMatch1 0x3
#define TI_tmr2IntMatch1 (1 << TI_bTmr2IntMatch1)
#define TI_bTmr2IntMatch2 0x4
#define TI_tmr2IntMatch2 (1 << TI_bTmr2IntMatch2)
#define TI_bTmr2IntOverflow 0x5
#define TI_tmr2IntOverflow (1 << TI_bTmr2IntOverflow)
#define TI_bTmr3IntMatch1 0x6
#define TI_tmr3IntMatch1 (1 << TI_bTmr3IntMatch1)
#define TI_bTmr3IntMatch2 0x7
#define TI_tmr3IntMatch2 (1 << TI_bTmr3IntMatch2)
#define TI_bTmr3IntOverflow 0x8
#define TI_tmr3IntOverflow (1 << TI_bTmr3IntOverflow)
#define TI_tmrIntMask 0x38
#define TI_pTmrIntMask 0x7038
#define TI_mpTmrIntMask 0xf20038
#define TI_tmrRevision 0x3c
#define TI_pTmrRevision 0x703c
#define TI_mpTmrRevision 0xf2003c
// RTC Ports
// -----------------------------------
#define TI_pRtcRange 0x8000
#define TI_mpRtcRange 0xf30000
// Keypad Ports
// -----------------------------------
#define TI_pKeyRange 0xa000
#define TI_mpKeyRange 0xf50000
#define TI_keyMode 0x0
#define TI_pKeyMode 0x0
#define TI_mpKeyMode 0x0
#define TI_keyRows 0x4
#define TI_pKeyRows 0x0
#define TI_mpKeyRows 0x0
#define TI_keyCols 0x5
#define TI_pKeyCols 0x0
#define TI_mpKeyCols 0x0
#define TI_keyIntStat 0x8
#define TI_pKeyIntStat 0x0
#define TI_mpKeyIntStat 0x0
#define TI_keyIntAck 0x8
#define TI_pKeyIntAck 0x0
#define TI_mpKeyIntAck 0x0
#define TI_keyIntMask 0x12
#define TI_pKeyIntMask 0x0
#define TI_mpKeyIntMask 0x0
#define TI_keyData 0x16
#define TI_pKeyData 0x0
#define TI_mpKeyData 0x0
#define TI_keyGpio 0x48
#define TI_pKeyGpio 0x0
#define TI_mpKeyGpio 0x0
#define TI_bKeyIntScanDone 0x0
#define TI_keyIntScanDone (1 << TI_bKeyIntScanDone)
#define TI_bKeyIntKeyChange 0x1
#define TI_keyIntKeyChange (1 << TI_bKeyIntKeyChange)
#define TI_bKeyIntKeyPress 0x2
#define TI_keyIntKeyPress (1 << TI_bKeyIntKeyPress)
#define TI_keyModeIdle 0x0
#define TI_keyModeAny 0x1
#define TI_keyModeScanOnce 0x2
#define TI_keyModeScan 0x3
// Backlight Ports
// -----------------------------------
#define TI_pBlLevel 0xb024
#define TI_mpBlLevel 0xf60024
// SPI Ports
// -----------------------------------
#define TI_pSpiRange 0xd000
#define TI_mpSpiRange 0xf80000
#define TI_spiCtrl0 0x0
#define TI_pSpiCtrl0 0x0
#define TI_mpSpiCtrl0 0x0
#define TI_bSpiClkPolarity 0x0
#define TI_bmSpiClkPolarity (1 << TI_bSpiClkPolarity)
#define TI_bSpiClkPhase 0x1
#define TI_bmSpiClkPhase (1 << TI_bSpiClkPhase)
#define TI_bSpiOpMode 0x2
#define TI_bmSpiSlave (0 << TI_bSpiOpMode)
#define TI_bmSpiMaster (3 << TI_bSpiOpMode)
#define TI_bmSpiSlaveMono (0 << TI_bSpiOpMode)
#define TI_bmSpiSlaveStereo (1 << TI_bSpiOpMode)
#define TI_bmSpiMasterMono (2 << TI_bSpiOpMode)
#define TI_bmSpiMasterStereo (3 << TI_bSpiOpMode)
#define TI_bmSpiOpMode (3 << TI_bSpiOpMode)
#define TI_bSpiFsJustify 0x4
#define TI_bmSpiFsJustify (1 << TI_bSpiFsJustify)
#define TI_bSpiFsPolarity 0x5
#define TI_bmSpiFsPolarity (1 << TI_bSpiFsPolarity)
#define TI_bSpiLsb 0x6
#define TI_bmSpiLsb (1 << TI_bSpiLsb)
#define TI_bSpiLoopback 0x7
#define TI_bmSpiLoopback (1 << TI_bSpiLoopback)
#define TI_bSpiFsDist 0x8
#define TI_bmSpiFsDist (3 << TI_bSpiFsDist)
#define TI_bSpiFlash 0x11
#define TI_bmSpiFlash (1 << TI_bSpiFlash)
#define TI_bSpiFrFmt 0x12
#define TI_spiSspFrFmt (0 << TI_bSpiFrFmt)
#define TI_spiSpiFrFmt (1 << TI_bSpiFrFmt)
#define TI_spiMicrowaveFrFmt (2 << TI_bSpiFrFmt)
#define TI_spiI2sFrFmt (3 << TI_bSpiFrFmt)
#define TI_bmSpiFrFmt (3 << TI_bSpiFrFmt)
#define TI_spiCtrl1 0x4
#define TI_pSpiCtrl1 0x0
#define TI_mpSpiCtrl1 0x0
#define TI_spiClkDiv 0x0
#define TI_pSpiClkDiv 0x0
#define TI_mpSpiClkDiv 0x0
#define TI_bSpiClkDiv 0x0
#define TI_bmSpiClkDiv (0FFFFh << TI_bSpiClkDiv)
#define TI_spiDataWidth 0x0
#define TI_pSpiDataWidth 0x0
#define TI_mpSpiDataWidth 0x0
#define TI_bSpiDataWidth 0x0
#define TI_bmSpiDataWidth (01Fh << TI_bSpiDataWidth)
#define TI_spiPadWidth 0x0
#define TI_pSpiPadWidth 0x0
#define TI_mpSpiPadWidth 0x0
#define TI_bSpiPadWidth 0x0
#define TI_bmSpiPadWidth (0FFh << TI_bSpiPadWidth)
#define TI_spiCtrl2 0x8
#define TI_pSpiCtrl2 0x0
#define TI_mpSpiCtrl2 0x0
#define TI_bSpiChipEn 0x0
#define TI_bmSpiChipEn (1 << TI_bSpiChipEn)
#define TI_bSpiTxDataOutEn 0x1
#define TI_bmSpiTxDataOutEn (1 << TI_bSpiTxDataOutEn)
#define TI_bSpiRxClr 0x2
#define TI_bmSpiRxClr (1 << TI_bSpiRxClr)
#define TI_bSpiTxClr 0x3
#define TI_bmSpiTxClr (1 << TI_bSpiTxClr)
#define TI_bSpiChipReset 0x6
#define TI_bmSpiChipReset (1 << TI_bSpiChipReset)
#define TI_bSpiRxEn 0x7
#define TI_bmSpiRxEn (1 << TI_bSpiRxEn)
#define TI_bSpiTxEn 0x8
#define TI_bmSpiTxEn (1 << TI_bSpiTxEn)
#define TI_bSpiFs 0x9
#define TI_bmSpiFs (1 << TI_bSpiFs)
#define TI_bSpiCs 0x10
#define TI_bmSpiCs (3 << TI_bSpiCs)
#define TI_spiStatus 0xc
#define TI_pSpiStatus 0x0
#define TI_mpSpiStatus 0x0
#define TI_bSpiRxFifoFull 0x0
#define TI_bmSpiRxFifoFull (1 << TI_bSpiRxFifoFull)
#define TI_bSpiTxFifoNotFull 0x1
#define TI_bmSpiTxFifoNotFull (1 << TI_bSpiTxFifoNotFull)
#define TI_bSpiChipBusy 0x2
#define TI_bmSpiChipBusy (1 << TI_bSpiChipBusy)
#define TI_bSpiRxFifoBytes 0x4
#define TI_bmSpiRxFifoBytes (01Fh << TI_bSpiRxFifoBytes)
#define TI_bSpiTxFifoBytes 0x12
#define TI_bmSpiTxFifoBytes (01Fh << TI_bSpiTxFifoBytes)
#define TI_spiIntCtrl 0x10
#define TI_pSpiIntCtrl 0x0
#define TI_mpSpiIntCtrl 0x0
#define TI_spiIntStatus 0x14
#define TI_pSpiIntStatus 0x0
#define TI_mpSpiIntStatus 0x0
#define TI_spiData 0x18
#define TI_pSpiData 0x0
#define TI_mpSpiData 0x0
#define TI_bSpiData 0x0
#define TI_bmSpiData 0xffffffff
// Character Font Equates
// -------------------------------------
#define TI_LrecurN 0x1
#define TI_LrecurU 0x2
#define TI_LrecurV 0x3
#define TI_LrecurW 0x4
#define TI_Lconvert 0x5
#define TI_LsqUp 0x6
#define TI_LsqDown 0x7
#define TI_Lintegral 0x8
#define TI_Lcross 0x9
#define TI_LboxIcon 0xa
#define TI_LcrossIcon 0xb
#define TI_LdotIcon 0xc
#define TI_LsubT 0xd // small capital T for parametric mode.
#define TI_LcubeR 0xe // slightly different 3 for cubed root.
#define TI_LhexF 0xf
#define TI_Lroot 0x10
#define TI_Linverse 0x11
#define TI_Lsquare 0x12
#define TI_Langle 0x13
#define TI_Ldegree 0x14
#define TI_Lradian 0x15
#define TI_Ltranspose 0x16
#define TI_LLE 0x17
#define TI_LNE 0x18
#define TI_LGE 0x19
#define TI_Lneg 0x1a
#define TI_Lexponent 0x1b
#define TI_Lstore 0x1c
#define TI_Lten 0x1d
#define TI_LupArrow 0x1e
#define TI_LdownArrow 0x1f
#define TI_Lspace 0x20
#define TI_Lexclam 0x21
#define TI_Lquote 0x22
#define TI_Lpound 0x23
#define TI_Lfourth 0x24
#define TI_Lpercent 0x25
#define TI_Lampersand 0x26
#define TI_Lapostrophe 0x27
#define TI_LlParen 0x28
#define TI_LrParen 0x29
#define TI_Lasterisk 0x2a
#define TI_LplusSign 0x2b
#define TI_Lcomma 0x2c
#define TI_Ldash 0x2d
#define TI_Lperiod 0x2e
#define TI_Lslash 0x2f
#define TI_L0 0x30
#define TI_L1 0x31
#define TI_L2 0x32
#define TI_L3 0x33
#define TI_L4 0x34
#define TI_L5 0x35
#define TI_L6 0x36
#define TI_L7 0x37
#define TI_L8 0x38
#define TI_L9 0x39
#define TI_Lcolon 0x3a
#define TI_Lsemicolon 0x3b
#define TI_LLT 0x3c
#define TI_LEQ 0x3d
#define TI_LGT 0x3e
#define TI_Lquestion 0x3f
#define TI_LatSign 0x40
#define TI_LcapA 0x41
#define TI_LcapB 0x42
#define TI_LcapC 0x43
#define TI_LcapD 0x44
#define TI_LcapE 0x45
#define TI_LcapF 0x46
#define TI_LcapG 0x47
#define TI_LcapH 0x48
#define TI_LcapI 0x49
#define TI_LcapJ 0x4a
#define TI_LcapK 0x4b
#define TI_LcapL 0x4c
#define TI_LcapM 0x4d
#define TI_LcapN 0x4e
#define TI_LcapO 0x4f
#define TI_LcapP 0x50
#define TI_LcapQ 0x51
#define TI_LcapR 0x52
#define TI_LcapS 0x53
#define TI_LcapT 0x54
#define TI_LcapU 0x55
#define TI_LcapV 0x56
#define TI_LcapW 0x57
#define TI_LcapX 0x58
#define TI_LcapY 0x59
#define TI_LcapZ 0x5a
#define TI_Ltheta 0x5b
#define TI_Lbackslash 0x5c
#define TI_LrBrack 0x5d
#define TI_Lcaret 0x5e
#define TI_Lunderscore 0x5f
#define TI_Lbackquote 0x60
#define TI_La 0x61
#define TI_Lb 0x62
#define TI_Lc 0x63
#define TI_Ld 0x64
#define TI_Le 0x65
#define TI_Lf 0x66
#define TI_Lg 0x67
#define TI_Lh 0x68
#define TI_Li 0x69
#define TI_Lj 0x6a
#define TI_Lk 0x6b
#define TI_Ll 0x6c
#define TI_Lm 0x6d
#define TI_Ln 0x6e
#define TI_Lo 0x6f
#define TI_Lp 0x70
#define TI_Lq 0x71
#define TI_Lr 0x72
#define TI_Ls 0x73
#define TI_Lt 0x74
#define TI_Lu 0x75
#define TI_Lv 0x76
#define TI_Lw 0x77
#define TI_Lx 0x78
#define TI_Ly 0x79
#define TI_Lz 0x7a
#define TI_LlBrace 0x7b
#define TI_Lbar 0x7c
#define TI_LrBrace 0x7d
#define TI_Ltilde 0x7e
#define TI_LinvEQ 0x7f
#define TI_Lsub0 0x80
#define TI_Lsub1 0x81
#define TI_Lsub2 0x82
#define TI_Lsub3 0x83
#define TI_Lsub4 0x84
#define TI_Lsub5 0x85
#define TI_Lsub6 0x86
#define TI_Lsub7 0x87
#define TI_Lsub8 0x88
#define TI_Lsub9 0x89
#define TI_LcapAAcute 0x8a
#define TI_LcapAGrave 0x8b
#define TI_LcapACaret 0x8c
#define TI_LcapADier 0x8d
#define TI_LaAcute 0x8e
#define TI_LaGrave 0x8f
#define TI_LaCaret 0x90
#define TI_LaDier 0x91
#define TI_LcapEAcute 0x92
#define TI_LcapEGrave 0x93
#define TI_LcapECaret 0x94
#define TI_LcapEDier 0x95
#define TI_LeAcute 0x96
#define TI_LeGrave 0x97
#define TI_LeCaret 0x98
#define TI_LeDier 0x99
#define TI_LcapIAcute 0x9a
#define TI_LcapIGrave 0x9b
#define TI_LcapICaret 0x9c
#define TI_LcapIDier 0x9d
#define TI_LiAcute 0x9e
#define TI_LiGrave 0x9f
#define TI_LiCaret 0xa0
#define TI_LiDier 0xa1
#define TI_LcapOAcute 0xa2
#define TI_LcapOGrave 0xa3
#define TI_LcapOCaret 0xa4
#define TI_LcapODier 0xa5
#define TI_LoAcute 0xa6
#define TI_LoGrave 0xa7
#define TI_LoCaret 0xa8
#define TI_LoDier 0xa9
#define TI_LcapUAcute 0xaa
#define TI_LcapUGrave 0xab
#define TI_LcapUCaret 0xac
#define TI_LcapUDier 0xad
#define TI_LuAcute 0xae
#define TI_LuGrave 0xaf
#define TI_LuCaret 0xb0
#define TI_LuDier 0xb1
#define TI_LcapCCed 0xb2
#define TI_LcCed 0xb3
#define TI_LcapNTilde 0xb4
#define TI_LnTilde 0xb5
#define TI_Laccent 0xb6
#define TI_Lgrave 0xb7
#define TI_Ldieresis 0xb8
#define TI_LquesDown 0xb9
#define TI_LexclamDown 0xba
#define TI_Lalpha 0xbb
#define TI_Lbeta 0xbc
#define TI_Lgamma 0xbd
#define TI_LcapDelta 0xbe
#define TI_Ldelta 0xbf
#define TI_Lepsilon 0xc0
#define TI_LlBrack 0xc1
#define TI_Llambda 0xc2
#define TI_Lmu 0xc3
#define TI_Lpi 0xc4
#define TI_Lrho 0xc5
#define TI_LcapSigma 0xc6
#define TI_Lsigma 0xc7
#define TI_Ltau 0xc8
#define TI_Lphi 0xc9
#define TI_LcapOmega 0xca
#define TI_LxMean 0xcb
#define TI_LyMean 0xcc
#define TI_LsupX 0xcd
#define TI_Lellipsis 0xce
#define TI_Lleft 0xcf
#define TI_Lblock 0xd0
#define TI_Lper 0xd1
#define TI_Lhyphen 0xd2
#define TI_Larea 0xd3
#define TI_Ltemp 0xd4
#define TI_Lcube 0xd5
#define TI_Lenter 0xd6
#define TI_LimagI 0xd7
#define TI_Lphat 0xd8
#define TI_Lchi 0xd9
#define TI_LstatF 0xda
#define TI_Llne 0xdb
#define TI_LlistL 0xdc
#define TI_LfinanN 0xdd
#define TI_L2_r_paren 0xde
#define TI_LblockArrow 0xdf
#define TI_LcurO 0xe0
#define TI_LcurO2 0xe1
#define TI_LcurOcapA 0xe2
#define TI_LcurOa 0xe3
#define TI_LcurI 0xe4
#define TI_LcurI2 0xe5
#define TI_LcurIcapA 0xe6
#define TI_LcurIa 0xe7
#define TI_LGline 0xe8 //  = 0
#define TI_LGthick 0xe9 //  = 1
#define TI_LGabove 0xea //  = 2
#define TI_LGbelow 0xeb //  = 3
#define TI_LGpath 0xec //  = 4
#define TI_LGanimate 0xed //  = 5
#define TI_LGdot 0xee //  = 6
#define TI_LUpBlk 0xef // Up arrow and Block in solver
#define TI_LDnBlk 0xf0 // Down arrow and Block in solver
#define TI_LcurFull 0xf1 // note: must be last char (PutMap checks)
// (MenuCurrent) Values
// -----------------------------------
#define TI_mConfirmation 0x1
#define TI_mApps 0x2
#define TI_mProgramHome 0x3
#define TI_mPrgm_Run 0x0
#define TI_mPrgm_Edit 0x1
#define TI_mPrgm_New 0x2
#define TI_mZoom 0x4
#define TI_mZoom_Zoom 0x0
#define TI_mZoom_Memory 0x1
#define TI_mDraw 0x5
#define TI_mDraw_Draw 0x0
#define TI_mDraw_Points 0x1
#define TI_mDraw_Store 0x2
#define TI_mDraw_Background 0x3
#define TI_mStatPlots 0x6
#define TI_mStat 0x7
#define TI_mStat_Edit 0x0
#define TI_mStat_Calc 0x1
#define TI_mStat_Tests 0x2
#define TI_mMath 0x8
#define TI_mMath_Math 0x0
#define TI_mMath_Number 0x1
#define TI_mMath_Complex 0x2
#define TI_mMath_Prob 0x3
#define TI_mMath_Frac 0x4
#define TI_mTest 0x9
#define TI_mTest_Test 0x0
#define TI_mTest_Logic 0x1
#define TI_mVars 0xb
#define TI_mVars_Vars 0x0
#define TI_mVars_YVars 0x1
#define TI_mVars_Colors 0x2
#define TI_mMemory 0xc
#define TI_mMatrix 0xd
#define TI_mMatrix_Name 0x0
#define TI_mMatrix_Math 0x1
#define TI_mMatrix_Edit 0x2
#define TI_mDistr 0xe
#define TI_mDistr_Distr 0x0
#define TI_mDistr_Draw 0x1
#define TI_mAngle 0xf
#define TI_mList 0x10
#define TI_mList_Names 0x0
#define TI_mList_Ops 0x1
#define TI_mList_Math 0x2
#define TI_mCalculate 0x11
#define TI_mVarsWin 0x15
#define TI_mVarsWin_XY 0x0
#define TI_mVarsWin_TTh 0x1
#define TI_mVarsWin_UVW 0x2
#define TI_mVarsZoom 0x16
#define TI_mVarsZoom_ZXY 0x0
#define TI_mVarsZoom_ZT 0x1
#define TI_mVarsZoom_UVW 0x2
#define TI_mVarsGDB 0x17
#define TI_mVarsPics 0x18
#define TI_mVarsPics_Pics 0x1
#define TI_mVarsPics_Bckgrnds 0x1
#define TI_mVarsStrings 0x19
#define TI_mVarsStat 0x1a
#define TI_mVarsStat_XY 0x0
#define TI_mVarsStat_Sigma 0x1
#define TI_mVarsStat_EQ 0x2
#define TI_mVarsStat_Test 0x3
#define TI_mVarsStat_Pts 0x4
#define TI_mVarsTable 0x1b
#define TI_mVarsYequ 0x1c
#define TI_mVarsParametric 0x1d
#define TI_mVarsPolar 0x1e
#define TI_mVarsFnOnOff 0x1f
#define TI_mMemReset 0x20
#define TI_mMemReset_RAM 0x0
#define TI_mMemReset_ROM 0x1
#define TI_mMemReset_All 0x2
#define TI_mMemMgmtDel 0x21
#define TI_mMemResetDefaults 0x22
#define TI_mMemResetRAMAll 0x24
#define TI_mMemResetROMVars 0x25
#define TI_mMemResetROMApps 0x26
#define TI_mMemResetROMAll 0x27
#define TI_mMemResetAll 0x28
#define TI_mGroup 0x29
#define TI_mGroup_New 0x0
#define TI_mGroup_Ungroup 0x1
#define TI_mGroupVars 0x2a
#define TI_mProgramEdit 0x2b
#define TI_mPrgmEd_Ctrl 0x0
#define TI_mPrgmEd_IO 0x1
#define TI_mPrgmEd_Color 0x2
#define TI_mPrgmEd_Exec 0x3
#define TI_mPrgmZoom 0x2c
#define TI_mPrgmZoom_Zoom 0x0
#define TI_mPrgmZoom_Mem 0x1
#define TI_mPrgmDraw 0x2d
#define TI_mPrgmDraw_Draw 0x0
#define TI_mPrgmDraw_Pt 0x1
#define TI_mPrgmDraw_Store 0x2
#define TI_mPrgmDraw_Bckgrnd 0x3
#define TI_mPrgmStatPlot 0x2e
#define TI_mPrgmSP_Plots 0x0
#define TI_mPrgmSP_Type 0x1
#define TI_mPrgmSP_Mark 0x2
#define TI_mPrgmStat 0x2f
#define TI_mPrgmStat_Edit 0x0
#define TI_mPrgmStat_Calc 0x1
#define TI_mPrgmStat_Tests 0x2
#define TI_mPrgmMath 0x30
#define TI_mPrgmMath_Math 0x0
#define TI_mPrgmMath_Num 0x1
#define TI_mPrgmMath_Cplx 0x2
#define TI_mPrgmMath_Prob 0x3
#define TI_mPrgmMath_Frac 0x4
#define TI_mLink 0x31
#define TI_mLink_Send 0x0
#define TI_mLink_Recieve 0x1
#define TI_mLinkTrasmit 0x32
#define TI_mLinkXmit_Xmit 0x1
#define TI_mGarbageCollect 0x40
#define TI_mSelectGroupVars 0x41
#define TI_mSelGrpVars_Sel 0x0
#define TI_mSelGrpVars_Grp 0x1
#define TI_mDuplicateName 0x43
#define TI_mCatalog 0x46
#define TI_mFinance 0x22
#define TI_mFinance_Calc 0x0
#define TI_mFinance_Vars 0x1
// Keypress Equates
// -----------------------------------
#define TI_kRight 0x1
#define TI_kLeft 0x2
#define TI_kUp 0x3
#define TI_kDown 0x4
#define TI_kEnter 0x5
#define TI_kAlphaEnter 0x6
#define TI_kAlphaUp 0x7
#define TI_kAlphaDown 0x8
#define TI_kClear 0x9
#define TI_kDel 0xa
#define TI_kIns 0xb
#define TI_kRecall 0xc
#define TI_kLastEnt 0xd
#define TI_kBOL 0xe
#define TI_kEOL 0xf
#define TI_kSelAll 0x10
#define TI_kUnselAll 0x11
#define TI_kLtoTI82 0x12
#define TI_kBackup 0x13
#define TI_kRecieve 0x14
#define TI_kLnkQuit 0x15
#define TI_kTrans 0x16
#define TI_kRename 0x17
#define TI_kOverw 0x18
#define TI_kOmit 0x19
#define TI_kCont 0x1a
#define TI_kSendID 0x1b
#define TI_kSendSW 0x1c
#define TI_kYes 0x1d
#define TI_kNoWay 0x1e
#define TI_kvSendType 0x1f
#define TI_kOverWAll 0x20
#define TI_kNo 0x25
#define TI_kKReset 0x26
#define TI_kApp 0x27
#define TI_kDoug 0x28
#define TI_kListflag 0x29
#define TI_menuStart 0x2b
#define TI_kAreYouSure 0x2b
#define TI_kAppsMenu 0x2c
#define TI_kPrgm 0x2d
#define TI_kZoom 0x2e
#define TI_kDraw 0x2f
#define TI_kSPlot 0x30
#define TI_kStat 0x31
#define TI_kMath 0x32
#define TI_kTest 0x33
#define TI_kChar 0x34
#define TI_kVars 0x35
#define TI_kMem 0x36
#define TI_kMatrix 0x37
#define TI_kDist 0x38
#define TI_kAngle 0x39
#define TI_kList 0x3a
#define TI_kCalc 0x3b
#define TI_kFin 0x3c
#define TI_menuEnd 0x0
#define TI_kCatalog 0x3e
#define TI_kInputDone 0x3f
#define TI_kOff 0x0
#define TI_kQuit 0x40
#define TI_appStart 0x0
#define TI_kLinkIO 0x41
#define TI_kMatrixEd 0x42
#define TI_kStatEd 0x43
#define TI_kGraph 0x44
#define TI_kMode 0x45
#define TI_kPrgmEd 0x46 // PROGRAM EDIT
#define TI_kPrgmCr 0x47 // PROGRAM CREATE
#define TI_kWindow 0x48 // RANGE EDITOR
#define TI_kYequ 0x49 // EQUATION EDITOR
#define TI_kTable 0x4a // TABLE EDITOR
#define TI_kTblSet 0x4b // TABLE SET
#define TI_kChkRAM 0x4c // CHECK RAM (About screen)
#define TI_kDelMem 0x4d // DELETE MEM
#define TI_kResetMem 0x4e // RESET MEM
#define TI_kResetDef 0x4f // RESET DEFAULT
#define TI_kPrgmInput 0x50 // PROGRAM INPUT
#define TI_kZFactEd 0x51 // ZOOM FACTOR EDITOR
#define TI_kError 0x52 // ERROR
#define TI_kSolveTVM 0x53 // TVM SOLVER
#define TI_kSolveRoot 0x54 // SOLVE EDITOR
#define TI_kStatP 0x55 // stat plot
#define TI_kInfStat 0x56 // Inferential Statistic
#define TI_kFormat 0x57 // FORMAT
#define TI_kExtApps 0x58 // External Applications.		NEW
#define TI_kNewApps 0x59 // New Apps for Cerberus.
#define TI_append 0x0
#define TI_echoStart1 0x5a
#define TI_kTrace 0x5a
#define TI_kZFit 0x5b
#define TI_kZIn 0x5c
#define TI_kZOut 0x5d
#define TI_kZPrev 0x5e
#define TI_kBox 0x5f
#define TI_kDecml 0x60
#define TI_kSetZm 0x61
#define TI_kSquar 0x62
#define TI_kStd 0x63
#define TI_kTrig 0x64
#define TI_kUsrZm 0x65
#define TI_kZSto 0x66
#define TI_kZInt 0x67
#define TI_kZStat 0x68
#define TI_echoStart2 0x69
#define TI_kSelect 0x69
#define TI_kCircl 0x6a
#define TI_kClDrw 0x6b
#define TI_kLine 0x6c
#define TI_kPen 0x6d
#define TI_kPtChg 0x6e
#define TI_kPtOff 0x6f
#define TI_kPtOn 0x70
#define TI_kVert 0x71
#define TI_kHoriz 0x72
#define TI_kText 0x73
#define TI_kTanLn 0x74
#define TI_kEval 0x75
#define TI_kInters 0x76
#define TI_kDYDX 0x77
#define TI_kFnIntg 0x78
#define TI_kRootG 0x79
#define TI_kDYDT 0x7a
#define TI_kDXDT 0x7b
#define TI_kDRDo 0x7c
#define TI_KGFMin 0x7d
#define TI_KGFMax 0x7e
#define TI_EchoStart 0x7f
#define TI_kListName 0x7f
#define TI_kAdd 0x80
#define TI_kSub 0x81
#define TI_kMul 0x82
#define TI_kDiv 0x83
#define TI_kExpon 0x84
#define TI_kLParen 0x85
#define TI_kRParen 0x86
#define TI_kLBrack 0x87
#define TI_kRBrack 0x88
#define TI_kShade 0x89
#define TI_kStore 0x8a
#define TI_kComma 0x8b
#define TI_kChs 0x8c
#define TI_kDecPnt 0x8d
#define TI_k0 0x8e
#define TI_k1 0x8f
#define TI_k2 0x90
#define TI_k3 0x91
#define TI_k4 0x92
#define TI_k5 0x93
#define TI_k6 0x94
#define TI_k7 0x95
#define TI_k8 0x96
#define TI_k9 0x97
#define TI_kEE 0x98
#define TI_kSpace 0x99
#define TI_kCapA 0x9a
#define TI_kCapB 0x9b
#define TI_kCapC 0x9c
#define TI_kCapD 0x9d
#define TI_kCapE 0x9e
#define TI_kCapF 0x9f
#define TI_kCapG 0xa0
#define TI_kCapH 0xa1
#define TI_kCapI 0xa2
#define TI_kCapJ 0xa3
#define TI_kCapK 0xa4
#define TI_kCapL 0xa5
#define TI_kCapM 0xa6
#define TI_kCapN 0xa7
#define TI_kCapO 0xa8
#define TI_kCapP 0xa9
#define TI_kCapQ 0xaa
#define TI_kCapR 0xab
#define TI_kCapS 0xac
#define TI_kCapT 0xad
#define TI_kCapU 0xae
#define TI_kCapV 0xaf
#define TI_kCapW 0xb0
#define TI_kCapX 0xb1
#define TI_kCapY 0xb2
#define TI_kCapZ 0xb3
#define TI_kVarx 0xb4
#define TI_kPi 0xb5
#define TI_kInv 0xb6
#define TI_kSin 0xb7
#define TI_kASin 0xb8
#define TI_kCos 0xb9
#define TI_kACos 0xba
#define TI_kTan 0xbb
#define TI_kATan 0xbc
#define TI_kSquare 0xbd
#define TI_kSqrt 0xbe
#define TI_kLn 0xbf
#define TI_kExp 0xc0
#define TI_kLog 0xc1
#define TI_kALog 0xc2
#define TI_kToABC 0xc3
#define TI_kClrTbl 0xc4
#define TI_kAns 0xc5
#define TI_kColon 0xc6
#define TI_kNDeriv 0xc7
#define TI_kFnInt 0xc8
#define TI_kRoot 0xc9
#define TI_kQuest 0xca
#define TI_kQuote 0xcb
#define TI_kTheta 0xcc
#define TI_kIf 0xcd
#define TI_kThen 0xce
#define TI_kElse 0xcf
#define TI_kFor 0xd0
#define TI_kWhile 0xd1
#define TI_kRepeat 0xd2
#define TI_kEnd 0xd3
#define TI_kPause 0xd4
#define TI_kLbl 0xd5
#define TI_kGoto 0xd6
#define TI_kISG 0xd7
#define TI_kDSL 0xd8
#define TI_kMenu 0xd9
#define TI_kExec 0xda
#define TI_kReturn 0xdb
#define TI_kStop 0xdc
#define TI_kInput 0xdd
#define TI_kPrompt 0xde
#define TI_kDisp 0xdf
#define TI_kDispG 0xe0
#define TI_kDispT 0xe1
#define TI_kOutput 0xe2
#define TI_kGetKey 0xe3
#define TI_kClrHome 0xe4
#define TI_kPrtScr 0xe5
#define TI_kSinH 0xe6
#define TI_kCosH 0xe7
#define TI_kTanH 0xe8
#define TI_kASinH 0xe9
#define TI_kACosH 0xea
#define TI_kATanH 0xeb
#define TI_kLBrace 0xec
#define TI_kRBrace 0xed
#define TI_kI 0xee
#define TI_kCONSTeA 0xef
#define TI_kPlot3 0xf0
#define TI_kFMin 0xf1
#define TI_kFMax 0xf2
#define TI_kL1A 0xf3
#define TI_kL2A 0xf4
#define TI_kL3A 0xf5
#define TI_kL4A 0xf6
#define TI_kL5A 0xf7
#define TI_kL6A 0xf8
#define TI_kunA 0xf9
#define TI_kvnA 0xfa
#define TI_kwnA 0xfb
//  THIS KEY MEANS THAT THE KEY PRESS IS ONE THAT ECHOS
//  INTO A BUFFER, AND IT IS A 2 BYTE KEY CODE, GO LOOK AT
//  (EXTECHO) FOR THE KEY VALUE
// --------------------------------------------------------
#define TI_kExtendEcho 0xfe
#define TI_kE1BT 0x0
#define TI_kDrawInv 0x0
#define TI_kDrawF 0x0
#define TI_kPixelOn 0x0
#define TI_kPixelOff 0x0
#define TI_kPxlTest 0x0
#define TI_kRCGDB 0x0
#define TI_kRCPic 0x0
#define TI_kSTGDB 0x0
#define TI_kSTPic 0x0
#define TI_kAbs 0x0
#define TI_kTequ 0x0 // ==
#define TI_kTNoteQ 0x0 // <>
#define TI_kTGT 0x0 // >
#define TI_kTGTE 0x0 // >=
#define TI_kTLT 0x0 // <
#define TI_kTLTE 0x0 // <=
#define TI_kAnd 0x0
#define TI_kOr 0x0
#define TI_kXor 0x0
#define TI_kNot 0x0
#define TI_kLR1 0x0
#define TI_kXRoot 0x0
#define TI_kCube 0x0
#define TI_kCbRt 0x0 // Cube ROOT
#define TI_kToDec 0x0
#define TI_kCubicR 0x0
#define TI_kQuartR 0x0
#define TI_kPlot1 0x0
#define TI_kPlot2 0x0
#define TI_kRound 0x0
#define TI_kIPart 0x0
#define TI_kFPart 0x0
#define TI_kInt 0x0
#define TI_kRand 0x0
#define TI_kNPR 0x0
#define TI_kNCR 0x0
#define TI_kXFactorial 0x0
#define TI_kRad 0x0
#define TI_kDegr 0x0 // DEGREES CONV
#define TI_kAPost 0x0
#define TI_kToDMS 0x0
#define TI_kRToPo 0x0 // R
#define TI_kRToPr 0x0
#define TI_kPToRx 0x0
#define TI_kPToRy 0x0
#define TI_kRowSwap 0x0
#define TI_kRowPlus 0x0
#define TI_kTimRow 0x0
#define TI_kTRowP 0x0
#define TI_kSortA 0x0
#define TI_kSortD 0x0
#define TI_kSeq 0x0
#define TI_kMin 0x0
#define TI_kMax 0x0
#define TI_kMean 0x0
#define TI_kMedian 0x0
#define TI_kSum 0x0
#define TI_kProd 0x0
#define TI_kDet 0x0
#define TI_kTransp 0x0
#define TI_kDim 0x0
#define TI_kFill 0x0
#define TI_kIdent 0x0
#define TI_kRandm 0x0
#define TI_kAug 0x0
#define TI_kOneVar 0x0
#define TI_kTwoVar 0x0
#define TI_kLR 0x0
#define TI_kLRExp 0x0
#define TI_kLRLn 0x0
#define TI_kLRPwr 0x0
#define TI_kMedMed 0x0
#define TI_kQuad 0x0
#define TI_kClrLst 0x0
#define TI_kHist 0x0
#define TI_kxyLine 0x0
#define TI_kScatter 0x0
#define TI_kmRad 0x0
#define TI_kmDeg 0x0
#define TI_kmNormF 0x0
#define TI_kmSci 0x0
#define TI_kmEng 0x0
#define TI_kmFloat 0x0
#define TI_kFix 0x0
#define TI_kSplitOn 0x0
#define TI_kFullScreen 0x0
#define TI_kStndrd 0x0
#define TI_kParam 0x0
#define TI_kPolar 0x0
#define TI_kSeqG 0x0
#define TI_kAFillOn 0x0
#define TI_kAFillOff 0x0
#define TI_kACalcOn 0x0
#define TI_kACalcOff 0x0
#define TI_kFNOn 0x0
#define TI_kFNOff 0x0
#define TI_kPlotsOn 0x0
#define TI_kPlotsOff 0x0
#define TI_kPixelChg 0x0
#define TI_kSendMBL 0x0
#define TI_kRecvMBL 0x0
#define TI_kBoxPlot 0x0
#define TI_kBoxIcon 0x0
#define TI_kCrossIcon 0x0
#define TI_kDotIcon 0x0
#define TI_kE2BT 0x0
#define TI_kSeqential 0x0
#define TI_kSimulG 0x0
#define TI_kPolarG 0x0
#define TI_kRectG 0x0
#define TI_kCoordOn 0x0
#define TI_kCoordOff 0x0
#define TI_kDrawLine 0x0
#define TI_kDrawDot 0x0
#define TI_kAxisOn 0x0
#define TI_kAxisOff 0x0
#define TI_kGridOn 0x0
#define TI_kGridOff 0x0
#define TI_kLblOn 0x0
#define TI_kLblOff 0x0
#define TI_kL1 0x0
#define TI_kL2 0x0
#define TI_kL3 0x0
#define TI_kL4 0x0
#define TI_kL5 0x0
#define TI_kL6 0x0
// These keys are laid on top of existing keys to
// enable localization in the inferential stats editor.
// ----------------------------------------------------
#define TI_kinfData 0x0
#define TI_kinfStats 0x0
#define TI_kinfYes 0x0
#define TI_kinfNo 0x0
#define TI_kinfCalc 0x0
#define TI_kinfDraw 0x0
#define TI_kinfAlt1ne 0x0
#define TI_kinfAlt1lt 0x0
#define TI_kinfAlt1gt 0x0
#define TI_kinfAlt2ne 0x0
#define TI_kinfAlt2lt 0x0
#define TI_kinfAlt2gt 0x0
#define TI_kinfAlt3ne 0x0
#define TI_kinfAlt3lt 0x0
#define TI_kinfAlt3gt 0x0
#define TI_kinfAlt4ne 0x0
#define TI_kinfAlt4lt 0x0
#define TI_kinfAlt4gt 0x0
#define TI_kinfAlt5ne 0x0
#define TI_kinfAlt5lt 0x0
#define TI_kinfAlt5gt 0x0
#define TI_kinfAlt6ne 0x0
#define TI_kinfAlt6lt 0x0
#define TI_kinfAlt6gt 0x0
#define TI_kMatA 0x0
#define TI_kMatB 0x0
#define TI_kMatC 0x0
#define TI_kMatD 0x0
#define TI_kMatE 0x0
#define TI_kXmin 0x0
#define TI_kXmax 0x0
#define TI_kXscl 0x0
#define TI_kYmin 0x0
#define TI_kYmax 0x0
#define TI_kYscl 0x0
#define TI_kTmin 0x0
#define TI_kTmax 0x0
#define TI_kTStep 0x0
#define TI_kOmin 0x0
#define TI_kOmax 0x0
#define TI_kOStep 0x0
#define TI_ku0 0x0
#define TI_kv0 0x0
#define TI_knMin 0x0
#define TI_knMax 0x0
#define TI_kDeltaY 0x0
#define TI_kDeltaX 0x0
#define TI_kZXmin 0x0
#define TI_kZXmax 0x0
#define TI_kZXscl 0x0
#define TI_kZYmin 0x0
#define TI_kZYmax 0x0
#define TI_kZYscl 0x0
#define TI_kZTmin 0x0
#define TI_kZTmax 0x0
#define TI_kZTStep 0x0
#define TI_kZOmin 0x0
#define TI_kZOmax 0x0
#define TI_kZOStep 0x0
#define TI_kZu0 0x0
#define TI_kZv0 0x0
#define TI_kZnMin 0x0
#define TI_kZnMax 0x0
#define TI_kDelLast 0x0
#define TI_kSinReg 0x0
#define TI_kConstE 0x0
#define TI_kPic1 0x0
#define TI_kPic2 0x0
#define TI_kPic3 0x0
#define TI_kDelVar 0x0
#define TI_kGetCalc 0x0
#define TI_kRealM 0x0
#define TI_kPolarM 0x0
#define TI_kRectM 0x0
#define TI_kuv 0x0 // U vs V
#define TI_kvw 0x0 // V vs W
#define TI_kuw 0x0 // U vs W
#define TI_kFinPMTend 0x0
#define TI_kFinPMTbeg 0x0
#define TI_kGraphStyle 0x0
#define TI_kExprOn 0x0
#define TI_kExprOff 0x0
#define TI_kStatA 0x0
#define TI_kStatB 0x0
#define TI_kStatC 0x0
#define TI_kCorr 0x0
#define TI_kStatD 0x0
#define TI_kStatE 0x0
#define TI_kRegEq 0x0
#define TI_kMinX 0x0
#define TI_kQ1 0x0
#define TI_kMD 0x0
#define TI_kQ3 0x0
#define TI_kMaxX 0x0
#define TI_kStatX1 0x0
#define TI_kStatY1 0x0
#define TI_kStatX2 0x0
#define TI_kStatY2 0x0
#define TI_kStatX3 0x0
#define TI_kStatY3 0x0
#define TI_kTblMin 0x0
#define TI_kTblStep 0x0
#define TI_kSetupLst 0x0
#define TI_kClrAllLst 0x0
#define TI_kLogistic 0x0
#define TI_kZTest 0x0
#define TI_kTTest 0x0
#define TI_k2SampZTest 0x0
#define TI_k2SampTTest 0x0
#define TI_k1PropZTest 0x0
#define TI_k2PropZTest 0x0
#define TI_kChiTest 0x0
#define TI_k2SampFTest 0x0
#define TI_kZIntVal 0x0
#define TI_kTIntVal 0x0
#define TI_k2SampTInt 0x0
#define TI_k2SampZInt 0x0
#define TI_k1PropZInt 0x0
#define TI_k2PropZInt 0x0
#define TI_kDNormal 0x0
#define TI_kInvNorm 0x0
#define TI_kDT 0x0
#define TI_kChi 0x0
#define TI_kDF 0x0
#define TI_kBinPDF 0x0
#define TI_kBinCDF 0x0
#define TI_kPoiPDF 0x0
#define TI_kPoiCDF 0x0
#define TI_kun 0x0
#define TI_kvn 0x0
#define TI_kwn 0x0
#define TI_kRecn 0x0
#define TI_kPlotStart 0x0
#define TI_kZPlotStart 0x0 // recursion n
#define TI_kXFact 0x0 // PlotStart
#define TI_kYFact 0x0 // ZPlotStart
#define TI_kANOVA 0x0 // XFact
#define TI_kMaxY 0x0 // YFact
#define TI_kWebOn 0x0 // MinY
#define TI_kWebOff 0x0 // MaxY
#define TI_kTblInput 0x0 // WEB ON
#define TI_kGeoPDF 0x0 // WEB OFF
#define TI_kGeoCDF 0x0 // WEB OFF
#define TI_kShadeNorm 0x0
#define TI_kShadeT 0x0
#define TI_kShadeChi 0x0
#define TI_kShadeF 0x0
#define TI_kPlotStep 0x0
#define TI_kZPlotStep 0x0
#define TI_kLinRegtTest 0x0
#define TI_KMGT 0x0 // VERT SPLIT
#define TI_kSelectA 0x0
#define TI_kZFitA 0x0
#define TI_kE2BT_End 0x0
//  THIS KEY MEANS THAT IT IS A 2 BYTE KEYCODE
//  THERE ARE 3 OF THESE KEYS; BE CAREFUL WITH USAGE
// --------------------------------------------------------
#define TI_kExtendEcho2 0xfc
// More 2 Byte Keys
// -------------------------------------
#define TI_kE2BT2 0x0
#define TI_kGDB1 0x0
#define TI_kGDB2 0x0
#define TI_kGDB3 0x0
#define TI_kY1 0x0
#define TI_kY2 0x0
#define TI_kY3 0x0
#define TI_kY4 0x0
#define TI_kY5 0x0
#define TI_kY6 0x0
#define TI_kY7 0x0
#define TI_kY8 0x0
#define TI_kY9 0x0
#define TI_kY0 0x0
#define TI_kX1T 0x0
#define TI_kY1T 0x0
#define TI_kX2T 0x0
#define TI_kY2T 0x0
#define TI_kX3T 0x0
#define TI_kY3T 0x0
#define TI_kX4T 0x0
#define TI_kY4T 0x0
#define TI_kX5T 0x0
#define TI_kY5T 0x0
#define TI_kX6T 0x0
#define TI_kY6T 0x0
#define TI_kR1 0x0
#define TI_kR2 0x0
#define TI_kR3 0x0
#define TI_kR4 0x0
#define TI_kR5 0x0
#define TI_kR6 0x0
#define TI_kGDB4 0x0
#define TI_kGDB5 0x0
#define TI_kGDB6 0x0
#define TI_kPic4 0x0
#define TI_kPic5 0x0
#define TI_kPic6 0x0
#define TI_kGDB7 0x0
#define TI_kGDB8 0x0
#define TI_kGDB9 0x0
#define TI_kGDB0 0x0
#define TI_kPic7 0x0
#define TI_kPic8 0x0
#define TI_kPic9 0x0
#define TI_kPic0 0x0
#define TI_kStatN 0x0
#define TI_kXMean 0x0
#define TI_kConj 0x0
#define TI_kReal 0x0
#define TI_kFAngle 0x0
#define TI_kLCM 0x0
#define TI_kGCD 0x0
#define TI_kRandInt 0x0
#define TI_kRandNorm 0x0
#define TI_kToPolar 0x0
#define TI_kToRect 0x0
#define TI_kYMean 0x0
#define TI_kStdX 0x0
#define TI_kStdX1 0x0
#define TI_kw0 0x0
#define TI_kMatF 0x0
#define TI_kMatG 0x0
#define TI_kMatRH 0x0
#define TI_kMatI 0x0
#define TI_kMatJ 0x0
#define TI_kYMean1 0x0
#define TI_kStdY 0x0
#define TI_kStdY1 0x0
#define TI_kMatToLst 0x0
#define TI_kLstToMat 0x0
#define TI_kCumSum 0x0
#define TI_kDeltaLst 0x0
#define TI_kStdDev 0x0
#define TI_kVariance 0x0
#define TI_kLength 0x0
#define TI_kEquToStrng 0x0
#define TI_kStrngToequ 0x0
#define TI_kExpr 0x0
#define TI_kSubStrng 0x0
#define TI_kInStrng 0x0
#define TI_kStr1 0x0
#define TI_kStr2 0x0
#define TI_kStr3 0x0
#define TI_kStr4 0x0
#define TI_kStr5 0x0
#define TI_kStr6 0x0
#define TI_kStr7 0x0
#define TI_kStr8 0x0
#define TI_kStr9 0x0
#define TI_kStr0 0x0
#define TI_kFinN 0x0
#define TI_kFinI 0x0
#define TI_kFinPV 0x0
#define TI_kFinPMT 0x0
#define TI_kFinFV 0x0
#define TI_kFinPY 0x0
#define TI_kFinCY 0x0
#define TI_kFinFPMT 0x0
#define TI_kFinFI 0x0
#define TI_kFinFPV 0x0
#define TI_kFinFN 0x0
#define TI_kFinFFV 0x0
#define TI_kFinNPV 0x0
#define TI_kFinIRR 0x0
#define TI_kFinBAL 0x0
#define TI_kFinPRN 0x0
#define TI_kFinINT 0x0
#define TI_kSumX 0x0
#define TI_kSumX2 0x0
#define TI_kFinToNom 0x0
#define TI_kFinToEff 0x0
#define TI_kFinDBD 0x0
#define TI_kStatVP 0x0
#define TI_kStatZ 0x0
#define TI_kStatT 0x0
#define TI_kStatChi 0x0
#define TI_kStatF 0x0
#define TI_kStatDF 0x0
#define TI_kStatPhat 0x0
#define TI_kStatPhat1 0x0
#define TI_kStatPhat2 0x0
#define TI_kStatMeanX1 0x0
#define TI_kStatMeanX2 0x0
#define TI_kStatStdX1 0x0
#define TI_kStatStdX2 0x0
#define TI_kStatStdXP 0x0
#define TI_kStatN1 0x0
#define TI_kStatN2 0x0
#define TI_kStatLower 0x0
#define TI_kStatUpper 0x0
#define TI_kuw0 0x0
#define TI_kImag 0x0
#define TI_kSumY 0x0
#define TI_kXres 0x0
#define TI_kStat_s 0x0
#define TI_kSumY2 0x0
#define TI_kSumXY 0x0
#define TI_kuXres 0x0
#define TI_kModBox 0x0
#define TI_kNormProb 0x0
#define TI_kNormalPDF 0x0
#define TI_kTPDF 0x0
#define TI_kChiPDF 0x0
#define TI_kFPDF 0x0
#define TI_kMinY 0x0 // MinY
#define TI_kRandBin 0x0
#define TI_kRef 0x0
#define TI_kRRef 0x0
#define TI_kLRSqr 0x0
#define TI_kBRSqr 0x0
#define TI_kDiagOn 0x0
#define TI_kDiagOff 0x0
#define TI_kun1 0x0 // FOR RCL USE WHEN GOTTEN FROM 82
#define TI_kvn1 0x0 // FOR RCL USE WHEN GOTTEN FROM 82
#define TI_k83_00End 0x0 // end of original keys...
#define TI_kArchive 0x0
#define TI_kUnarchive 0x0
#define TI_kAsm 0x0 // Asm(
#define TI_kAsmPrgm 0x0 // AsmPrgm
#define TI_kAsmComp 0x0 // AsmComp(
#define TI_kcapAAcute 0x0
#define TI_kcapAGrave 0x0
#define TI_kcapACaret 0x0
#define TI_kcapADier 0x0
#define TI_kaAcute 0x0
#define TI_kaGrave 0x0
#define TI_kaCaret 0x0
#define TI_kaDier 0x0
#define TI_kcapEAcute 0x0
#define TI_kcapEGrave 0x0
#define TI_kcapECaret 0x0
#define TI_kcapEDier 0x0
#define TI_keAcute 0x0
#define TI_keGrave 0x0
#define TI_keCaret 0x0
#define TI_keDier 0x0
#define TI_kcapIAcute 0x0
#define TI_kcapIGrave 0x0
#define TI_kcapICaret 0x0
#define TI_kcapIDier 0x0
#define TI_kiAcute 0x0
#define TI_kiGrave 0x0
#define TI_kiCaret 0x0
#define TI_kiDier 0x0
#define TI_kcapOAcute 0x0
#define TI_kcapOGrave 0x0
#define TI_kcapOCaret 0x0
#define TI_kcapODier 0x0
#define TI_koAcute 0x0
#define TI_koGrave 0x0
#define TI_koCaret 0x0
#define TI_koDier 0x0
#define TI_kcapUAcute 0x0
#define TI_kcapUGrave 0x0
#define TI_kcapUCaret 0x0
#define TI_kcapUDier 0x0
#define TI_kuAcute 0x0
#define TI_kuGrave 0x0
#define TI_kuCaret 0x0
#define TI_kuDier 0x0
#define TI_kcapCCed 0x0
#define TI_kcCed 0x0
#define TI_kcapNTilde 0x0
#define TI_knTilde 0x0
#define TI_kaccent 0x0
#define TI_kgrave 0x0
#define TI_kdieresis 0x0
#define TI_kquesDown 0x0
#define TI_kexclamDown 0x0
#define TI_kalpha 0x0
#define TI_kbeta 0x0
#define TI_kgamma 0x0
#define TI_kcapDelta 0x0
#define TI_kdelta 0x0
#define TI_kepsilon 0x0
#define TI_klambda 0x0
#define TI_kmu 0x0
#define TI_kpi2 0x0
#define TI_krho 0x0
#define TI_kcapSigma 0x0
#define TI_ksigma 0x0
#define TI_ktau 0x0
#define TI_kphi 0x0
#define TI_kcapOmega 0x0
#define TI_kphat 0x0
#define TI_kchi2 0x0
#define TI_kstatF2 0x0
#define TI_kLa 0x0
#define TI_kLb 0x0
#define TI_kLc 0x0
#define TI_kLd 0x0
#define TI_kLe 0x0
#define TI_kLf 0x0
#define TI_kLg 0x0
#define TI_kLh 0x0
#define TI_kLi 0x0
#define TI_kLj 0x0
#define TI_kLk 0x0
#define TI_kLl 0x0
#define TI_kLm 0x0
#define TI_kLsmalln 0x0
#define TI_kLo 0x0
#define TI_kLp 0x0
#define TI_kLq 0x0
#define TI_kLsmallr 0x0
#define TI_kLs 0x0
#define TI_kLt 0x0
#define TI_kLu 0x0
#define TI_kLv 0x0
#define TI_kLw 0x0
#define TI_kLx 0x0
#define TI_kLy 0x0
#define TI_kLz 0x0
#define TI_kGarbageC 0x0 // GarbageCollect
#define TI_kE2BT2_End 0x0
//  THIS KEY MEANS THAT IT IS A 2 BYTE KEYCODE
//  UNLESS (EXTECHO) IS 0 THEN IT IS AN OLD 1 BYTE KEYCODE
//  THERE ARE 3 OF THESE KEYS; BE CAREFUL WITH USAGE
// --------------------------------------------------------
#define TI_kExtendEcho3 0xfb
// Even More 2 Byte Keys
// -------------------------------------
#define TI_kE2BT3 0x0
#define TI_kSingleQuote 0x0
#define TI_kAt 0x0
#define TI_kHash 0x0
#define TI_kDollar 0x0
#define TI_kAmp 0x0
#define TI_kBackquote 0x0
#define TI_kSemicolon 0x0
#define TI_kBackslash 0x0
#define TI_kBar 0x0
#define TI_kUnderscore 0x0
#define TI_kTilde 0x0
#define TI_kPercent 0x0
#define TI_kEllipsis 0x0
#define TI_kAng 0x0
#define TI_kSS 0x0
#define TI_kSupX 0x0
#define TI_kSubT 0x0
#define TI_kSub0 0x0
#define TI_kSub1 0x0
#define TI_kSub2 0x0
#define TI_kSub3 0x0
#define TI_kSub4 0x0
#define TI_kSub5 0x0
#define TI_kSub6 0x0
#define TI_kSub7 0x0
#define TI_kSub8 0x0
#define TI_kSub9 0x0
#define TI_kSub10 0x0
// TI-83 Plus Context Equates
// --------------------------------------------------------------
#define TI_cxCmd 0x0 // home screen
#define TI_cxMatEdit 0x0 // matrix editor
#define TI_cxPrgmEdit 0x0 // program editor
#define TI_cxEquEdit 0x0 // equation editor
#define TI_cxGrRange 0x0 // graph range editor
#define TI_cxGrZfact 0x0 // graph zoom factors editor
#define TI_cxGraph 0x0 // graph mode
#define TI_cxStatEdit 0x0 // statistics list editor
#define TI_cxPrgmInput 0x0 // programmed input
#define TI_cxError 0x0 // error handler
#define TI_cxLinkIO 0x0 // LINK I/O interface
#define TI_cxMem 0x0 // reset memory
#define TI_cxDefMem 0x0 // reset default
#define TI_cxRAMApp 0x0 // RAM usage screen
#define TI_cxMode 0x0 // mode settings screen
#define TI_cxErase 0x0 // memory erase
#define TI_cxPrgmCreate 0x0 // PROGRAM CREATE
#define TI_cxTableEditor 0x0 // TABLE EDITOR
#define TI_cxTableSet 0x0 // TABLE SET UP
#define TI_cxStatPlot 0x0 // STAT PLOTS
#define TI_cxInfStat 0x0 // Inferential Statistic
#define TI_cxFormat 0x0 // FORMAT CONTEXT
#define TI_cxSolveTVM 0x0 // Solve TVM
#define TI_cxSolveRoot 0x0 // Solve Root
#define TI_lastOldApp 0x0 // external applications
#define TI_cxextapps 0x0
#define TI_cxNewApps 0x0 // new cerberus applications
#define TI_cxGroup 0xc // 1st new app.
#define TI_cxUnGroup 0xc // 2nd new app.
#define TI_lastNewApp 0xc // last new app for this ver
// Scan Code Equates
// ------------------------------
#define TI_skDown 0x1
#define TI_skLeft 0x2
#define TI_skRight 0x3
#define TI_skUp 0x4
#define TI_skEnter 0x9
#define TI_skAdd 0xa
#define TI_skSub 0xb
#define TI_skMul 0xc
#define TI_skDiv 0xd
#define TI_skPower 0xe
#define TI_skClear 0xf
#define TI_skChs 0x11
#define TI_sk3 0x12
#define TI_sk6 0x13
#define TI_sk9 0x14
#define TI_skRParen 0x15
#define TI_skTan 0x16
#define TI_skVars 0x17
#define TI_skDecPnt 0x19
#define TI_sk2 0x1a
#define TI_sk5 0x1b
#define TI_sk8 0x1c
#define TI_skLParen 0x1d
#define TI_skCos 0x1e
#define TI_skPrgm 0x1f
#define TI_skStat 0x20
#define TI_sk0 0x21
#define TI_sk1 0x22
#define TI_sk4 0x23
#define TI_sk7 0x24
#define TI_skComma 0x25
#define TI_skSin 0x26
#define TI_skMatrix 0x27
#define TI_skGraphvar 0x28
#define TI_skStore 0x2a
#define TI_skLn 0x2b
#define TI_skLog 0x2c
#define TI_skSquare 0x2d
#define TI_skRecip 0x2e
#define TI_skMath 0x2f
#define TI_skAlpha 0x30
#define TI_skGraph 0x31
#define TI_skTrace 0x32
#define TI_skZoom 0x33
#define TI_skWindow 0x34
#define TI_skYequ 0x35
#define TI_sk2nd 0x36
#define TI_skMode 0x37
#define TI_skDel 0x38
//  DI Keyboard Equates
// ---------------------------
#define TI_DI_Mode 0xf50000
#define TI_DI_Cntrl 0xf50004
#define TI_DI_Int 0xf50008
#define TI_DI_IntMask 0xf5000c
#define TI_kbdG1 0xf50012
// ----------------------------
#define TI_kbdGraph 0x1b
#define TI_kbdTrace 0x10b
#define TI_kbdZoom 0x100b
#define TI_kbdWindow 0x1000b
#define TI_kbdYequ 0x10000b
#define TI_kbd2nd 0x100000b
#define TI_kbdMode 0x1000000b
#define TI_kbdDel 0x10000000b
#define TI_kbitGraph 0x0
#define TI_kbitTrace 0x1
#define TI_kbitZoom 0x2
#define TI_kbitWindow 0x3
#define TI_kbitYequ 0x4
#define TI_kbit2nd 0x5
#define TI_kbitMode 0x6
#define TI_kbitDel 0x7
#define TI_kbdG2 0xf50014
// ----------------------------
#define TI_kbdStore 0x10b
#define TI_kbdLn 0x100b
#define TI_kbdLog 0x1000b
#define TI_kbdSquare 0x10000b
#define TI_kbdRecip 0x100000b
#define TI_kbdMath 0x1000000b
#define TI_kbdAlpha 0x10000000b
#define TI_kbitStore 0x1
#define TI_kbitLn 0x2
#define TI_kbitLog 0x3
#define TI_kbitSquare 0x4
#define TI_kbitRecip 0x5
#define TI_kbitMath 0x6
#define TI_kbitAlpha 0x7
#define TI_kbdG3 0xf50016
// ----------------------------
#define TI_kbd0 0x1b
#define TI_kbd1 0x10b
#define TI_kbd4 0x100b
#define TI_kbd7 0x1000b
#define TI_kbdComma 0x10000b
#define TI_kbdSin 0x100000b
#define TI_kbdApps 0x1000000b
#define TI_kbdGraphVar 0x10000000b
#define TI_kbit0 0x0
#define TI_kbit1 0x1
#define TI_kbit4 0x2
#define TI_kbit7 0x3
#define TI_kbitComma 0x4
#define TI_kbitSin 0x5
#define TI_kbitApps 0x6
#define TI_kbitGraphVar 0x7
#define TI_kbdG4 0xf50018
// ----------------------------
#define TI_kbdDecPnt 0x1b
#define TI_kbd2 0x10b
#define TI_kbd5 0x100b
#define TI_kbd8 0x1000b
#define TI_kbdLParen 0x10000b
#define TI_kbdCos 0x100000b
#define TI_kbdPgrm 0x1000000b
#define TI_kbdStat 0x10000000b
#define TI_kbitDecPnt 0x0
#define TI_kbit2 0x1
#define TI_kbit5 0x2
#define TI_kbit8 0x3
#define TI_kbitLParen 0x4
#define TI_kbitCos 0x5
#define TI_kbitPgrm 0x6
#define TI_kbitStat 0x7
#define TI_kbdG5 0xf5001a
// ----------------------------
#define TI_kbdChs 0x1b
#define TI_kbd3 0x10b
#define TI_kbd6 0x100b
#define TI_kbd9 0x1000b
#define TI_kbdRParen 0x10000b
#define TI_kbdTan 0x100000b
#define TI_kbdVars 0x1000000b
#define TI_kbitChs 0x0
#define TI_kbit3 0x1
#define TI_kbit6 0x2
#define TI_kbit9 0x3
#define TI_kbitRParen 0x4
#define TI_kbitTan 0x5
#define TI_kbitVars 0x6
#define TI_kbdG6 0xf5001c
// ----------------------------
#define TI_kbdEnter 0x1b
#define TI_kbdAdd 0x10b
#define TI_kbdSub 0x100b
#define TI_kbdMul 0x1000b
#define TI_kbdDiv 0x10000b
#define TI_kbdPower 0x100000b
#define TI_kbdClear 0x1000000b
#define TI_kbitEnter 0x0
#define TI_kbitAdd 0x1
#define TI_kbitSub 0x2
#define TI_kbitMul 0x3
#define TI_kbitDiv 0x4
#define TI_kbitPower 0x5
#define TI_kbitClear 0x6
#define TI_kbdG7 0xf5001e
// ----------------------------
#define TI_kbdDown 0x1b
#define TI_kbdLeft 0x10b
#define TI_kbdRight 0x100b
#define TI_kbdUp 0x1000b
#define TI_kbitDown 0x0
#define TI_kbitLeft 0x1
#define TI_kbitRight 0x2
#define TI_kbitUp 0x3
// Tokens
// -----------------------------------------------------
#define TI_EOSSTART 0x0
// DISPLAY CONVERSIONS COME IMMEDIATELY BEFORE 'TSTORE'
// 
#define TI_DCONV 0x1
// 
#define TI_tToDMS 0xdc // 01h
#define TI_tToDEC 0xdc // 02h
#define TI_tToAbc 0xdc // 03h > A b/c
// 
#define TI_tStore 0xdc // 04h Lstore 01
// 
#define TI_tBoxPlot 0x5
// 
#define TI_BRACKS 0x6
// 
#define TI_tLBrack 0xb // 06h '['
#define TI_tRBrack 0xb // 07h ']'
#define TI_tLBrace 0xb // 08h '{'
#define TI_tRBrace 0xb // 09h '}'
// 
#define TI_tPOST1 0xb
// 
#define TI_tFromRad 0x0 // 0Ah Lradian
#define TI_tFromDeg 0x0 // 0Bh Ldegree
#define TI_tRecip 0x0 // 0Ch Linverse
#define TI_tSqr 0x0 // 0Dh Lsquare
#define TI_tTrnspos 0x0 // 0Eh Ltranspose
#define TI_tCube 0x0 // 0Fh ' xor 3'
// 
#define TI_tLParen 0x10 // 10h '('
#define TI_tRParen 0x11 // 11h ')'
// 
#define TI_IMUN 0x12
// 
#define TI_tRound 0x0 // 12h 'round'
#define TI_tPxTst 0x0 // 13h 'PXL-TEST'
#define TI_tAug 0x0 // 14h 'aug'
#define TI_tRowSwap 0x0 // 15h 'rSwap'
#define TI_tRowPlus 0x0 // 16h 'rAdd'
#define TI_tmRow 0x0 // 17h 'multR'
#define TI_tmRowPlus 0x0 // 18h 'mRAdd'
#define TI_tMax 0x0 // 19h 'max'
#define TI_tMin 0x0 // 1Ah 'min'
#define TI_tRToPr 0x0 // 1Bh 'R>Pr
#define TI_tRToPo 0x0 // 1Ch 'R>Po
#define TI_tPToRx 0x0 // 1Dh 'P>Rx
#define TI_tPToRy 0x0 // 1Eh 'P>Ry
#define TI_tMedian 0x0 // 1Fh 'MEDIAN
#define TI_tRandM 0x0 // 20h 'randM'
#define TI_tMean 0x0 // 21h
#define TI_tRoot 0x0 // 22h 'ROOT'
#define TI_tSeries 0x0 // 23h 'seq'
#define TI_tFnInt 0x0 // 24h 'fnInt'
#define TI_tNDeriv 0x0 // 25h 'fnIr'
#define TI_tEvalF 0x0 // 26h
#define TI_tFmin 0x0 // 27h
#define TI_tFmax 0x0 // 28h
// 
#define TI_tEOSEL 0x0
// 
#define TI_tSpace 0x0 // 29h ' '
#define TI_tString 0x0 // 2Ah '"'
#define TI_tComma 0x0 // 2Bh ','
// 
#define TI_tii 0x2c // i
// Postfix Functions
// -----------------------------------------
#define TI_tPost 0x2d
// 
#define TI_tFact 0x0 // 2Dh '!'
// 
#define TI_tCubicR 0x2e
#define TI_tQuartR 0x2f
// Number Tokens
// ---------------------------------------
#define TI_NUMS 0x30
// 
#define TI_t0 0x0 // 30h
#define TI_t1 0x0 // 31h
#define TI_t2 0x0 // 32h
#define TI_t3 0x0 // 33h
#define TI_t4 0x0 // 34h
#define TI_t5 0x0 // 35h
#define TI_t6 0x0 // 36h
#define TI_t7 0x0 // 37h
#define TI_t8 0x0 // 38h
#define TI_t9 0x0 // 39h
#define TI_tDecPt 0x0 // 3Ah
#define TI_tee 0x0 // 3Bh
// Binary OP
// -------------------------------------------
#define TI_tOr 0x3c // 3Ch '_or_'
#define TI_tXor 0x3d // 3Dh
// 
#define TI_tColon 0x3e // 3Eh ':'
#define TI_tEnter 0x3f // 3Fh Lenter
// 
#define TI_tAnd 0x40 // 40h '_and_'
// Letter Tokens
// --------------------------------------
#define TI_LET 0x41
#define TI_tA 0x0 // 41h
#define TI_tB 0x0 // 42h
#define TI_tC 0x0 // 43h
#define TI_tD 0x0 // 44h
#define TI_tE 0x0 // 45h
#define TI_tF 0x0 // 46h
#define TI_tG 0x0 // 47h
#define TI_tH 0x0 // 48h
#define TI_tI 0x0 // 49h
#define TI_tJ 0x0 // 4Ah
#define TI_tK 0x0 // 4Bh
#define TI_tL 0x0 // 4Ch
#define TI_tM 0x0 // 4Dh
#define TI_tN 0x0 // 4Eh
#define TI_tO 0x0 // 4Fh
#define TI_tP 0x0 // 50h
#define TI_tQ 0x0 // 51h
#define TI_tR 0x0 // 52h
#define TI_tS 0x0 // 53h
#define TI_tT 0x0 // 54h
#define TI_tU 0x0 // 55h
#define TI_tV 0x0 // 56h
#define TI_tW 0x0 // 57h
#define TI_tX 0x0 // 58h
#define TI_tY 0x0 // 59h
#define TI_tZ 0x0 // 5Ah
#define TI_tTheta 0x0 // 5Bh
//  Extended Tokens
// ---------------------------
#define TI_tExtTok 0xef
#define TI_tSetDate 0x0
#define TI_tSetTime 0x1
#define TI_tCheckTmr 0x2
#define TI_tSetDtFmt 0x3
#define TI_tSetTmFmt 0x4
#define TI_tTimeCnv 0x5
#define TI_tDayOfWk 0x6
#define TI_tGetDtStr 0x7
#define TI_tGetTmStr 0x8
#define TI_tGetDate 0x9
#define TI_tGetTime 0xa
#define TI_tStartTmr 0xb
#define TI_tGtDtFmt 0xc
#define TI_tGetTmFmt 0xd
#define TI_tIsClockOn 0xe
#define TI_tClockOff 0xf
#define TI_tClockOn 0x10
#define TI_tOpenLib 0x11
#define TI_tExecLib 0x12
#define TI_tInvT 0x13
#define TI_tChiSquaredGofTest 0x14
#define TI_tLinRegTInt 0x15
#define TI_tManualFit 0x16
//  MathPrint
#define TI_tZQuadrant 0x17
#define TI_tZFracHalf 0x18
#define TI_tZFracThird 0x19
#define TI_tZFracFourth 0x1a
#define TI_tZFracFifth 0x1b
#define TI_tZFracEighth 0x1c
#define TI_tZFracTenth 0x1d
#define TI_tFracSlash 0x2e
#define TI_tFracMixedNum 0x2f
#define TI_tSwapImProper 0x30
#define TI_tSwapFracDec 0x31
#define TI_tRemainder 0x32
#define TI_tSummationSigma 0x33
#define TI_tLogBase 0x34
#define TI_tRandIntNoRep 0x35
#define TI_tMathPrint 0x37
#define TI_tClassic 0x38
#define TI_tAutoAnswer 0x3b
#define TI_tDecAnswer 0x3c
#define TI_tFracAnswer 0x3d
//  TI-84+CSE/CE
#define TI_tBlue 0x41
#define TI_tRed 0x42
#define TI_tBlack 0x43
#define TI_tMagenta 0x44
#define TI_tGreen 0x45
#define TI_tOrange 0x46
#define TI_tBrown 0x47
#define TI_tNavy 0x48
#define TI_tLtBlue 0x49
#define TI_tYellow 0x4a
#define TI_tWhite 0x4b
#define TI_tLtGray 0x4c
#define TI_tMedGray 0x4d
#define TI_tGray 0x4e
#define TI_tDarkGray 0x4f
#define TI_tGraphColor 0x65
#define TI_tTextColor 0x67
#define TI_tBackgroundOn 0x5b
#define TI_tBackgroundOff 0x64
#define TI_tThin 0x74
// tThick - 0x7E 0x06 (was "Connected"?)
#define TI_tAsm84CPrgm 0x68
#define TI_tAsm84CCmp 0x69
#define TI_tBorderColor 0x6c
#define TI_tAsm84CeCmp 0x7b
#define TI_tAsm84CePrgm 0x7a
//  OS 5.2+ only
#define TI_tLEFT 0x92
#define TI_tCENTER 0x93
#define TI_tRIGHT 0x94
#define TI_tInvBinom 0x95
#define TI_tWait 0x96
#define TI_tToString 0x97
#define TI_tEval 0x98
// These Var Tokens Are 1st Of A Double Token
// -----------------------------------------------
#define TI_vToks 0x0
// User Matrix Token, 2nd Token Needed For Name
// 
#define TI_tVarMat 0x0 // 5Ch
// 
// User List Token, 2nd Token Needed For Name
// 
#define TI_tVarLst 0x0 // 5Dh
// 
// User Equation Token, 2nd Token Needed For Name
// 
#define TI_tVarequ 0x0 // 5Eh
#define TI_tProg 0x0 // 5Fh
// 
// User Pict Token, 2nd Token Needed For Name
// 
#define TI_tVarPict 0x0 // 60h
// 
// User GDB Token, 2nd Token Needed For Name
// 
#define TI_tVarGDB 0x0 // 61h
#define TI_tVarOut 0x0 // 62h
#define TI_tVarSys 0x0 // 63h
// Mode Setting Commands
// -------------------------------------------------
#define TI_MODESA 0x0 // 64h
#define TI_tRad 0x0 // 64h 'Radian'
#define TI_tDeg 0x0 // 65h 'Degree'
#define TI_tNormF 0x0 // 66h 'Normal'
#define TI_tSci 0x0 // 67h 'Sci'
#define TI_tEng 0x0 // 68h 'Eng'
#define TI_tFloat 0x0 // 69h 'Float'
#define TI_CMPS 0x6a
#define TI_tEQ 0xc // 6Ah '=='
#define TI_tLT 0xc // 6Bh '<'
#define TI_tGT 0xc // 6Ch '>'
#define TI_tLE 0xc // 6Dh LLE
#define TI_tGE 0xc // 6Eh LGE
#define TI_tNE 0xc // 6Fh LNE
// Binary OP
// ---------------------------------------
#define TI_tAdd 0x70 // 70h '+'
#define TI_tSub 0x71 // 71h '-'
#define TI_tAns 0x72 // 72h
// Mode Setting Commands
// ------------------------------------------------------
#define TI_MODES 0x73
#define TI_tFix 0x0 // 73h 'Fix_'
#define TI_tSplitOn 0x0 // 74h
#define TI_tFullScreen 0x0 // 75h
#define TI_tStndrd 0x0 // 76h 'Func'
#define TI_tParam 0x0 // 77h 'Param'
#define TI_tPolar 0x0 // 78h 'Pol'
#define TI_tSeqG 0x0 // 79h
#define TI_tAFillOn 0x0 // 7Ah 'AUTO FILL ON'
#define TI_tAFillOff 0x0 // 7Bh
#define TI_tACalcOn 0x0 // 7Ch
#define TI_tACalcOff 0x0 // 7Dh 'AutoFill OFF'
// Graph Format Tokens Are 2 Byte Tokens
// ----------------------------------------
#define TI_tGFormat 0x0 // 7Eh
#define TI_tBoxIcon 0x7f
#define TI_tCrossIcon 0x80
#define TI_tDotIcon 0x81
// (More) Binary OP
// ---------------------------------------
#define TI_tMul 0x82 // 82h '*'
#define TI_tDiv 0x83 // 83h '/'
// Some Graph Commands
// -----------------------------------------------------
#define TI_GRCMDS 0x84
#define TI_tTrace 0x0 //  84h 'Trace'
#define TI_tClDrw 0x0 //  85h 'ClDrw'
#define TI_tZoomStd 0x0 //  86h 'ZStd'
#define TI_tZoomtrg 0x0 //  87h 'Ztrg'
#define TI_tZoomBox 0x0 //  88h 'ZBOX'
#define TI_tZoomIn 0x0 //  89h 'ZIn'
#define TI_tZoomOut 0x0 //  8Ah 'ZOut'
#define TI_tZoomSqr 0x0 //  8Bh 'ZSqr'
#define TI_tZoomInt 0x0 //  8Ch 'ZInt'
#define TI_tZoomPrev 0x0 //  8Dh 'ZPrev'
#define TI_tZoomDec 0x0 //  8Eh 'ZDecm'
#define TI_tZoomStat 0x0 //  8Fh 'ZStat
#define TI_tUsrZm 0x0 //  90h 'ZRcl'
#define TI_tPrtScrn 0x0 //  91h 'PrtScrn'
#define TI_tZoomSto 0x0 //  92h  ZOOM STORE
#define TI_tText 0x0 //  93h
// Binary OP (Combination and Permutation)
// -------------------------------------------------
#define TI_tnPr 0x0 // 94h '_nPr_'
#define TI_tnCr 0x0 // 95h '_nCr_'
// More Graph Commands
// --------------------------------------------------
#define TI_tYOn 0x0 // 96h 'FnOn_'
#define TI_tYOff 0x0 // 97h 'FnOff_'
#define TI_tStPic 0x0 // 98h 'StPic_'
#define TI_tRcPic 0x0 // 99h 'RcPic_'
#define TI_tStoDB 0x0 // 9Ah 'StGDB_'
#define TI_tRclDB 0x0 // 9Bh 'RcGDB_'
#define TI_tLine 0x0 // 9Ch 'Line'
#define TI_tVert 0x0 // 9Dh 'Vert_'
#define TI_tPtOn 0x0 // 9Eh 'PtOn'
#define TI_tPtOff 0x0 // 9Fh 'PtOff'
// Token A0 Cannot Be An EOS Function Since Low MULT=A0 Already
// -----------------------------------------------------
#define TI_tPtChg 0x0 // A0h 'PtChg'
#define TI_tPXOn 0x0 // A1h
#define TI_tPXOff 0x0 // A2h
#define TI_tPXChg 0x0 // A3h
#define TI_tShade 0x0 // A4h 'Shade'
#define TI_tCircl 0x0 // A5h 'Circl'
#define TI_tHorz 0x0 // A6h 'HORIZONTAL'
#define TI_tTanLn 0x0 // A7h 'TanLn'
#define TI_tDrInv 0x0 // A8h 'DrInv_'
#define TI_tDrawF 0x0 // A9h 'DrawF_'
#define TI_tVarStrng 0xaa
// Functions with No Arguments
// --------------------------------------------------
#define TI_NOARG 0xab
#define TI_tRand 0x0 // ABh 'rand'
#define TI_tPi 0x0 // ACh  Lpi
#define TI_tGetKey 0x0 // ADh 'getKy'
#define TI_tAPost 0x0 // APOSTROPHY
#define TI_tQuest 0x0 // QUESTION MARK
#define TI_UNARY 0x0 // B0h
#define TI_tChs 0x0 // B0h
#define TI_tInt 0x0 // B1h
#define TI_tAbs 0x0 // B2h
#define TI_tDet 0x0 // B3h
#define TI_tIdent 0x0 // B4h
#define TI_tDim 0x0 // B5h
#define TI_tSum 0x0 // B6h
#define TI_tProd 0x0 // B7h
#define TI_tNot 0x0 // B8h
#define TI_tIPart 0x0 // B9h
#define TI_tFPart 0x0 // BAh
// New 2 Byte Tokens
// ------------------------------------------
#define TI_t2ByteTok 0xbb
#define TI_UNARYLR 0x0
#define TI_tSqrt 0x0 // BCh
#define TI_tCubRt 0x0 // BDh
#define TI_tLn 0x0 // BEh
#define TI_tExp 0x0 // BFh
#define TI_tLog 0x0 // C0h
#define TI_tALog 0x0 // C1h
#define TI_tSin 0x0 // C2h
#define TI_tASin 0x0 // C3h
#define TI_tCos 0x0 // C4h
#define TI_tACos 0x0 // C5h
#define TI_tTan 0x0 // C6h
#define TI_tATan 0x0 // C7h
#define TI_tSinH 0x0 // C8h
#define TI_tASinH 0x0 // C9h
#define TI_tCoshH 0x0 // CAh
#define TI_tACosH 0x0 // CBh
#define TI_tTanH 0x0 // CCh
#define TI_tATanH 0x0 // CDh
// Some Programming Commands
// ---------------------------------------------------
#define TI_PROGTOK 0x0
#define TI_tIf 0x0 // CEh
#define TI_tThen 0x0 // CFh
#define TI_tElse 0x0 // D0h
#define TI_tWhile 0x0 // D1h
#define TI_tRepeat 0x0 // D2h
#define TI_tFor 0x0 // D3h
#define TI_tEnd 0x0 // D4h
#define TI_tReturn 0x0 // D5h
#define TI_tLbl 0x0 // D6h 'Lbl_'
#define TI_tGoto 0x0 // D7h 'Goto_'
#define TI_tPause 0x0 // D8h 'Pause_'
#define TI_tStop 0x0 // D9h 'Stop'
#define TI_tISG 0x0 // DAh 'IS>'
#define TI_tDSL 0x0 // DBh 'DS<'
#define TI_tInput 0x0 // DCh 'Input_'
#define TI_tPrompt 0x0 // DDh 'Prompt_'
#define TI_tDisp 0x0 // DEh 'Disp_'
#define TI_tDispG 0x0 // DFh 'DispG'
#define TI_tOutput 0x0 // E0h 'Outpt'
#define TI_tClLCD 0x0 // E1h 'ClLCD'
#define TI_tConst 0x0 // E2h 'Fill'
#define TI_tSortA 0x0 // E3h 'sortA_'
#define TI_tSortD 0x0 // E4h 'sortD_'
#define TI_tDispTab 0x0 // E5h 'Disp Table
#define TI_tMenu 0x0 // E6h 'Menu'
#define TI_tSendMBL 0x0 // E7h 'SEND'
#define TI_tGetMBL 0x0 // E8h 'GET'
// Stat Plot Commands
// -----------------------------------------------------
#define TI_statPCmd 0x0
#define TI_tPlotOn 0x0 // E9h ' PLOTSON'
#define TI_tPlotOff 0x0 // EAh ' PLOTSOFF
#define TI_tListName 0xeb // LIST DESignATOR
#define TI_tPlot1 0xec
#define TI_tPlot2 0xed
#define TI_tPlot3 0xee
#define TI_tUnused01 0xef // available?
#define TI_tPower 0xf0 // ' xor '
#define TI_tXRoot 0xf1 // LsupX,Lroot
#define TI_STATCMD 0xf2
#define TI_tOneVar 0x0 // F2h 'OneVar_'
#define TI_tTwoVar 0x0 // F3h
#define TI_tLR 0x0 // F4h 'LinR(A+BX
#define TI_tLRExp 0x0 // F5h 'ExpR_'
#define TI_tLRLn 0x0 // F6h 'LnR_'
#define TI_tLRPwr 0x0 // F7h 'PwrR_'
#define TI_tMedMed 0x0 // F8h
#define TI_tQuad 0x0 // F9h
#define TI_tClrLst 0x0 // FAh 'CLEAR LIST
#define TI_tClrTbl 0x0 // FBh CLEAR TABLE
#define TI_tHist 0x0 // FCh 'Hist_'
#define TI_txyLine 0x0 // FDh 'xyline_'
#define TI_tScatter 0x0 // FEh 'Scatter_'
#define TI_tLR1 0x0 // FFh 'LINR(AX+B
// 2nd Half Of Graph Format Tokens
// Format settings commands
// ---------------------------------------------
#define TI_GFMT 0x0
#define TI_tSeq 0x0 //  'SeqG'
#define TI_tSimulG 0x0 //  'SimulG'
#define TI_tPolarG 0x0 //  'PolarGC'
#define TI_tRectG 0x0 //  'RectGC'
#define TI_tCoordOn 0x0 //  'CoordOn'
#define TI_tCoordOff 0x0 //  'CoordOff'
#define TI_tDrawLine 0x0 //  'DrawLine'
#define TI_tDrawDot 0x0 //  'DrawDot'
#define TI_tAxisOn 0x0 //  'AxesOn'
#define TI_tAxisOff 0x0 //  'AxesOff'
#define TI_tGridOn 0x0 //  'GridOn'
#define TI_tGridOff 0x0 //  'GridOff'
#define TI_tLblOn 0x0 //  'LabelOn'
#define TI_tLblOff 0x0 //  'LabelOff'
#define TI_tWebOn 0x0 //  'WebOn'
#define TI_tWebOff 0x0 //  'WebOFF'
#define TI_tuv 0x0 //  U vs V
#define TI_tvw 0x0 //  V vs W
#define TI_tuw 0x0 //  U vs W
// 2nd Half Of User Matrix Tokens
// -------------------------------------
#define TI_tMatA 0x0 // MAT A
#define TI_tMatB 0x1 // MAT B
#define TI_tMatC 0x2 // MAT C
#define TI_tMatD 0x3 // MAT D
#define TI_tMatE 0x4 // MAT E
#define TI_tMatF 0x5 // MAT F
#define TI_tMatG 0x6 // MAT G
#define TI_tMatH 0x7 // MAT H
#define TI_tMatI 0x8 // MAT I
#define TI_tMatJ 0x9 // MAT J
// 2nd Half Of User List Tokens
// --------------------------------------
#define TI_tL1 0x0 // LIST 1
#define TI_tL2 0x1 // LIST 2
#define TI_tL3 0x2 // LIST 3
#define TI_tL4 0x3 // LIST 4
#define TI_tL5 0x4 // LIST 5
#define TI_tL6 0x5 // LIST 6
// 2nd Half Of User Equation Tokens
// ----------------------------------
//   "Y" EQUATIONS HAVE BIT 4 SET
// 
#define TI_tY1 0x10 // Y1
#define TI_tY2 0x11 // Y2
#define TI_tY3 0x12 // Y3
#define TI_tY4 0x13 // Y4
#define TI_tY5 0x14 // Y5
#define TI_tY6 0x15 // Y6
#define TI_tY7 0x16 // Y7
#define TI_tY8 0x17 // Y8
#define TI_tY9 0x18 // Y9
#define TI_tY0 0x19 // Y0
// Param Equations Have Bit 5 Set
// -----------------------------------
#define TI_tX1T 0x20 // X1t
#define TI_tY1T 0x21 // Y1t
#define TI_tX2T 0x22 // X2t
#define TI_tY2T 0x23 // Y2t
#define TI_tX3T 0x24 // X3t
#define TI_tY3T 0x25 // Y3t
#define TI_tX4T 0x26 // X4t
#define TI_tY4T 0x27 // Y4t
#define TI_tX5T 0x28 // X5t
#define TI_tY5T 0x29 // Y5t
#define TI_tX6T 0x2a // X6t
#define TI_tY6T 0x2b // Y6t
// Polar Equations Have Bit 6 Set
// ----------------------------------
#define TI_tR1 0x40 // R1
#define TI_tR2 0x41 // R2
#define TI_tR3 0x42 // R3
#define TI_tR4 0x43 // R4
#define TI_tR5 0x44 // R5
#define TI_tR6 0x45 // R6
// Recursion Equations Have Bit 7 Set
// ----------------------------------
#define TI_tun 0x80 // Un
#define TI_tvn 0x81 // Vn
#define TI_twn 0x82 // Wn
// 2nd Half User Picture Tokens
// ------------------------------------
#define TI_tPic1 0x0 // PIC1
#define TI_tPic2 0x1 // PIC2
#define TI_tPic3 0x2 // PIC3
#define TI_tPic4 0x3 // PIC4
#define TI_tPic5 0x4 // PIC5
#define TI_tPic6 0x5 // PIC6
#define TI_tPic7 0x6 // PIC7
#define TI_tPic8 0x7 // PIC8
#define TI_tPic9 0x8 // PIC9
#define TI_tPic0 0x9 // PIC0
// 2nd Half User Graph Database Tokens
// ------------------------------------
#define TI_tGDB1 0x0 // GDB1
#define TI_tGDB2 0x1 // GDB2
#define TI_tGDB3 0x2 // GDB3
#define TI_tGDB4 0x3 // GDB4
#define TI_tGDB5 0x4 // GDB5
#define TI_tGDB6 0x5 // GDB6
#define TI_tGDB7 0x6 // GDB7
#define TI_tGDB8 0x7 // GDB8
#define TI_tGDB9 0x8 // GDB9
#define TI_tGDB0 0x9 // GDB0
// 2nd Half Of String Vars
// ------------------------------
#define TI_tStr1 0x0
#define TI_tStr2 0x1
#define TI_tStr3 0x2
#define TI_tStr4 0x3
#define TI_tStr5 0x4
#define TI_tStr6 0x5
#define TI_tStr7 0x6
#define TI_tStr8 0x7
#define TI_tStr9 0x8
#define TI_tStr0 0x9
// 2nd Half Of System Output Only Variables
// ----------------------------------------------------------------
// OPEN			equ 00h
#define TI_tRegEq 0x1 // REGRESSION EQUATION
#define TI_tStatN 0x2 // STATISTICS N
#define TI_tXMean 0x3 // X MEAN
#define TI_tSumX 0x4 // SUM(X)
#define TI_tSumXSqr 0x5 // SUM(X xor 2)
#define TI_tStdX 0x6 // STANDARD DEV X
#define TI_tStdPX 0x7 // STANDARD DEV POP X
#define TI_tMinX 0x8 // Min X VALUE
#define TI_tMaxX 0x9 // Max X VALUE
#define TI_tMinY 0xa // Min Y VALUE
#define TI_tMaxY 0xb // Max Y VALUE
#define TI_tYmean 0xc // Y MEAN
#define TI_tSumY 0xd // SUM(Y)
#define TI_tSumYSqr 0xe // SUM(Y xor 2)
#define TI_tStdY 0xf // STANDARD DEV Y
#define TI_tStdPY 0x10 // STANDARD DEV POP Y
#define TI_tSumXY 0x11 // SUM(XY)
#define TI_tCorr 0x12 // CORRELATION
#define TI_tMedX 0x13 // MED(X)
#define TI_tQ1 0x14 // 1ST QUADRANT OF X
#define TI_tQ3 0x15 // 3RD QUADRANT OF X
#define TI_tQuadA 0x16 // 1ST TERM OF QUAD POLY REG/ Y-INT
#define TI_tQuadB 0x17 // 2ND TERM OF QUAD POLY REG/ SLOPE
#define TI_tQuadC 0x18 // 3RD TERM OF QUAD POLY REG
#define TI_tCubeD 0x19 // 4TH TERM OF CUBIC POLY REG
#define TI_tQuartE 0x1a // 5TH TERM OF QUART POLY REG
#define TI_tMedX1 0x1b // x1 FOR MED-MED
#define TI_tMedX2 0x1c // x2 FOR MED-MED
#define TI_tMedX3 0x1d // x3 FOR MED-MED
#define TI_tMedY1 0x1e // y1 FOR MED-MED
#define TI_tMedY2 0x1f // y2 FOR MED-MED
#define TI_tMedY3 0x20 // y3 FOR MED-MED
#define TI_tRecurn 0x21 // RECURSION N
#define TI_tStatP 0x22
#define TI_tStatZ 0x23
#define TI_tStatT 0x24
#define TI_tStatChi 0x25
#define TI_tStatF 0x26
#define TI_tStatDF 0x27
#define TI_tStatPhat 0x28
#define TI_tStatPhat1 0x29
#define TI_tStatPhat2 0x2a
#define TI_tStatMeanX1 0x2b
#define TI_tStatStdX1 0x2c
#define TI_tStatN1 0x2d
#define TI_tStatMeanX2 0x2e
#define TI_tStatStdX2 0x2f
#define TI_tStatN2 0x30
#define TI_tStatStdXP 0x31
#define TI_tStatLower 0x32
#define TI_tStatUpper 0x33
#define TI_tStat_s 0x34
#define TI_tLRSqr 0x35 // r xor 2
#define TI_tBRSqr 0x36 // R xor 2
// These next tokens are only used to access the data
// they are display only and the user cannot access them at all
// ------------------------------------------------------------
#define TI_tF_DF 0x37 // ANOFAV FACTOR DF
#define TI_tF_SS 0x38 // ANOFAV FACTOR SS
#define TI_tF_MS 0x39 // ANOFAV FACTOR MS
#define TI_tE_DF 0x3a // ANOFAV ERROR DF
#define TI_tE_SS 0x3b // ANOFAV ERROR SS
#define TI_tE_MS 0x3c // ANOFAV ERROR MS
// 2nd Half Of System Input/Output Variables
// ------------------------------------------------
// 		SYSTEM VARIABLE EQUATES
// 
#define TI_tuXscl 0x0
#define TI_tuYscl 0x1
#define TI_tXscl 0x2
#define TI_tYscl 0x3
#define TI_tRecuru0 0x4 // U 1ST INITIAL COND
#define TI_tRecurv0 0x5 // V 1ST INITIAL COND
#define TI_tun1 0x6 // U(N-1); NOT USED
#define TI_tvn1 0x7 // V(N-1); NOT USED
#define TI_tuRecuru0 0x8 // 
#define TI_tuRecurv0 0x9 // 
#define TI_tXmin 0xa
#define TI_tXmax 0xb
#define TI_tYmin 0xc
#define TI_tYmax 0xd
#define TI_tTmin 0xe
#define TI_tTmax 0xf
#define TI_tThetaMin 0x10
#define TI_tThetaMax 0x11
#define TI_tuXmin 0x12
#define TI_tuXmax 0x13
#define TI_tuYmin 0x14
#define TI_tuYmax 0x15
#define TI_tuThetMin 0x16
#define TI_tuThetMax 0x17
#define TI_tuTmin 0x18
#define TI_tuTmax 0x19
#define TI_tTblMin 0x1a
#define TI_tPlotStart 0x1b
#define TI_tuPlotStart 0x1c
#define TI_tnMax 0x1d
#define TI_tunMax 0x1e
#define TI_tnMin 0x1f
#define TI_tunMin 0x20
#define TI_tTblStep 0x21
#define TI_tTStep 0x22
#define TI_tThetaStep 0x23
#define TI_tuTStep 0x24
#define TI_tuThetStep 0x25
#define TI_tDeltaX 0x26
#define TI_tDeltaY 0x27
#define TI_tXFact 0x28
#define TI_tYFact 0x29
#define TI_tTblInput 0x2a
#define TI_tFinN 0x2b
#define TI_tFinI 0x2c
#define TI_tFinPV 0x2d
#define TI_tFinPMT 0x2e
#define TI_tFinFV 0x2f
#define TI_tFinPY 0x30
#define TI_tFinCY 0x31
#define TI_tRecurw0 0x32 // w0(1)
#define TI_tuRecurw0 0x33
#define TI_tPlotStep 0x34
#define TI_tuPlotStep 0x35
#define TI_tXres 0x36
#define TI_tuXres 0x37
#define TI_tRecuru02 0x38 // u0(2)
#define TI_tuRecuru02 0x39
#define TI_tRecurv02 0x3c // v0(2)
#define TI_tuRecurv02 0x3d
#define TI_tRecurw02 0x3e // w0(2)
#define TI_tuRecurw02 0x3f
// 2nd Byte Of t2ByteTok Tokens
// ------------------------------
#define TI_tFinNPV 0x0
#define TI_tFinIRR 0x1
#define TI_tFinBAL 0x2
#define TI_tFinPRN 0x3
#define TI_tFinINT 0x4
#define TI_tFinToNom 0x5
#define TI_tFinToEff 0x6
#define TI_tFinDBD 0x7
#define TI_tLCM 0x8
#define TI_tGCD 0x9
#define TI_tRandInt 0xa
#define TI_tRandBin 0xb
#define TI_tSubStrng 0xc
#define TI_tStdDev 0xd
#define TI_tVariance 0xe
#define TI_tInStrng 0xf
#define TI_tDNormal 0x10
#define TI_tInvNorm 0x11
#define TI_tDT 0x12
#define TI_tChI 0x13
#define TI_tDF 0x14
#define TI_tBINPDF 0x15
#define TI_tBINCDF 0x16
#define TI_tPOIPDF 0x17
#define TI_tPOICDF 0x18
#define TI_tGEOPDF 0x19
#define TI_tGEOCDF 0x1a
#define TI_tNormalPDF 0x1b
#define TI_tTPDF 0x1c
#define TI_tChiPDF 0x1d
#define TI_tFPDF 0x1e
#define TI_tRandNorm 0x1f
#define TI_tFinFPMT 0x20
#define TI_tFinFI 0x21
#define TI_tFinFPV 0x22
#define TI_tFinFN 0x23
#define TI_tFinFFV 0x24
#define TI_tConj 0x25
#define TI_tReal 0x26
#define TI_tImag 0x27
#define TI_tAngle 0x28
#define TI_tCumSum 0x29
#define TI_tExpr 0x2a
#define TI_tLength 0x2b
#define TI_tDeltaLst 0x2c
#define TI_tRef 0x2d
#define TI_tRRef 0x2e
#define TI_tToRect 0x2f
#define TI_tToPolar 0x30
#define TI_tConste 0x31
#define TI_tSinReg 0x32
#define TI_tLogistic 0x33
#define TI_tLinRegTTest 0x34
#define TI_tShadeNorm 0x35
#define TI_tShadeT 0x36
#define TI_tShadeChi 0x37
#define TI_tShadeF 0x38
#define TI_tMatToLst 0x39
#define TI_tLstToMat 0x3a
#define TI_tZTest 0x3b
#define TI_tTTest 0x3c
#define TI_t2SampZTest 0x3d
#define TI_t1PropZTest 0x3e
#define TI_t2PropZTest 0x3f
#define TI_tChiTest 0x40
#define TI_tZIntVal 0x41
#define TI_t2SampZInt 0x42
#define TI_t1PropZInt 0x43
#define TI_t2PropZInt 0x44
#define TI_tGraphStyle 0x45
#define TI_t2SampTTest 0x46
#define TI_t2SampFTest 0x47
#define TI_tTIntVal 0x48
#define TI_t2SampTInt 0x49
#define TI_tSetupLst 0x4a
#define TI_tFinPMTend 0x4b
#define TI_tFinPMTbeg 0x4c
#define TI_tRealM 0x4d
#define TI_tPolarM 0x4e
#define TI_tRectM 0x4f
#define TI_tExprOn 0x50
#define TI_tExprOff 0x51
#define TI_tClrAllLst 0x52
#define TI_tGetCalc 0x53
#define TI_tDelVar 0x54
#define TI_tEquToStrng 0x55
#define TI_tStrngToequ 0x56
#define TI_tDelLast 0x57
#define TI_tSelect 0x58
#define TI_tANOVA 0x59
#define TI_tModBox 0x5a
#define TI_tNormProb 0x5b
#define TI_tMGT 0x64 // VERTICAL SPLIT
#define TI_tZFit 0x65 // ZOOM FIT
#define TI_tDiag_on 0x66 // DIANOSTIC DISPLAY ON
#define TI_tDiag_off 0x67 // DIANOSTIC DISPLAY OFF
#define TI_tOkEnd2v0 0x67 // end of 2byte tokens for version 0.
#define TI_tArchive 0x68 // archive
#define TI_tUnarchive 0x69 // unarchive
#define TI_tasm 0x6a
#define TI_tasmComp 0x6b // asm compile
#define TI_tasmPrgm 0x6c // Signifies a program is asm
#define TI_tasmCmp 0x6d // asm program is compiled
#define TI_tLcapAAcute 0x6e
#define TI_tLcapAGrave 0x6f
#define TI_tLcapACaret 0x70
#define TI_tLcapADier 0x71
#define TI_tLaAcute 0x72
#define TI_tLaGrave 0x73
#define TI_tLaCaret 0x74
#define TI_tLaDier 0x75
#define TI_tLcapEAcute 0x76
#define TI_tLcapEGrave 0x77
#define TI_tLcapECaret 0x78
#define TI_tLcapEDier 0x79
#define TI_tLeAcute 0x7a
#define TI_tLeGrave 0x7b
#define TI_tLeCaret 0x7c
#define TI_tLeDier 0x7d
#define TI_tLcapIGrave 0x7f
#define TI_tLcapICaret 0x80
#define TI_tLcapIDier 0x81
#define TI_tLiAcute 0x82
#define TI_tLiGrave 0x83
#define TI_tLiCaret 0x84
#define TI_tLiDier 0x85
#define TI_tLcapOAcute 0x86
#define TI_tLcapOGrave 0x87
#define TI_tLcapOCaret 0x88
#define TI_tLcapODier 0x89
#define TI_tLoAcute 0x8a
#define TI_tLoGrave 0x8b
#define TI_tLoCaret 0x8c
#define TI_tLoDier 0x8d
#define TI_tLcapUAcute 0x8e
#define TI_tLcapUGrave 0x8f
#define TI_tLcapUCaret 0x90
#define TI_tLcapUDier 0x91
#define TI_tLuAcute 0x92
#define TI_tLuGrave 0x93
#define TI_tLuCaret 0x94
#define TI_tLuDier 0x95
#define TI_tLcapCCed 0x96
#define TI_tLcCed 0x97
#define TI_tLcapNTilde 0x98
#define TI_tLnTilde 0x99
#define TI_tLaccent 0x9a
#define TI_tLgrave 0x9b
#define TI_tLdieresis 0x9c
#define TI_tLquesDown 0x9d
#define TI_tLexclamDown 0x9e
#define TI_tLalpha 0x9f
#define TI_tLbeta 0xa0
#define TI_tLgamma 0xa1
#define TI_tLcapDelta 0xa2
#define TI_tLdelta 0xa3
#define TI_tLepsilon 0xa4
#define TI_tLlambda 0xa5
#define TI_tLmu 0xa6
#define TI_tLpi 0xa7
#define TI_tLrho 0xa8
#define TI_tLcapSigma 0xa9
#define TI_tLphi 0xab
#define TI_tLcapOmega 0xac
#define TI_tLphat 0xad
#define TI_tLchi 0xae
#define TI_tLstatF 0xaf
#define TI_tLa 0xb0
#define TI_tLb 0xb1
#define TI_tLc 0xb2
#define TI_tLd 0xb3
#define TI_tLsmalle 0xb4
#define TI_tLf 0xb5
#define TI_tLsmallg 0xb6
#define TI_tLh 0xb7
#define TI_tLi 0xb8
#define TI_tLj 0xb9
#define TI_tLk 0xba
#define TI_tLl 0xbc
#define TI_tLm 0xbd
#define TI_tLsmalln 0xbe
#define TI_tLo 0xbf
#define TI_tLp 0xc0
#define TI_tLq 0xc1
#define TI_tLsmallr 0xc2
#define TI_tLs 0xc3
#define TI_tLsmallt 0xc4
#define TI_tLu 0xc5
#define TI_tLv 0xc6
#define TI_tLw 0xc7
#define TI_tLx 0xc8
#define TI_tLy 0xc9
#define TI_tLz 0xca
#define TI_tLsigma 0xcb
#define TI_tLtau 0xcc
#define TI_tLcapIAcute 0xcd
#define TI_tGarbagec 0xce
#define TI_LastToken 0xce // tLAST TOKEN IN THIS VERSION...
// Data Type Equates
// ---------------------------------------------------------------------
#define TI_RealObj 0x0
#define TI_ListObj 0x1
#define TI_MatObj 0x2
#define TI_EquObj 0x3
#define TI_StrngObj 0x4
#define TI_ProgObj 0x5
#define TI_ProtProgObj 0x6
#define TI_PictObj 0x7
#define TI_GDBObj 0x8
#define TI_UnknownObj 0x9
#define TI_UnknownEquObj 0xa
#define TI_NewEquObj 0xb
#define TI_CplxObj 0xc
#define TI_CListObj 0xd
#define TI_UndefObj 0xe
#define TI_WindowObj 0xf
#define TI_ZStoObj 0x10
#define TI_TblRngObj 0x11
#define TI_LCDObj 0x12
#define TI_BackupObj 0x13
#define TI_AppObj 0x14 // application, only used in menus/link
#define TI_AppVarObj 0x15 // application variable
#define TI_TempProgObj 0x16 // program, home deletes when finished
#define TI_GroupObj 0x17 // group.
// System Error Codes
// -----------------------------------------------------------
#define TI_E_EDITF 0x7 // allow re-entering application
#define TI_E_EDIT (1 << TI_E_EDITF)
#define TI_E_Mask 0x7f
#define TI_E_Overflow 0x1
#define TI_E_DivBy0 0x2
#define TI_E_SingularMat 0x3
#define TI_E_Domain 0x4
#define TI_E_Increment 0x5
#define TI_E_Break 0x6
#define TI_E_NonReal 0x7
#define TI_E_Syntax 0x8
#define TI_E_DataType 0x9
#define TI_E_Argument 0x10
#define TI_E_DimMismatch 0x11
#define TI_E_Dimension 0x12
#define TI_E_Undefined 0x13
#define TI_E_Memory 0x14 //  142
#define TI_E_Invalid 0x15 //  143
#define TI_E_IllegalNest 0x16 //  144
#define TI_E_Bound 0x17 //  145
#define TI_E_GraphRange 0x18 //  146
#define TI_E_Zoom 0x19 //  147
#define TI_E_Label 0x20 //  148
#define TI_E_Stat 0x21 //  149
#define TI_E_Solver 0x22
#define TI_E_Singularity 0x23
#define TI_E_SignChange 0x24
#define TI_E_Iterations 0x25
#define TI_E_BadGuess 0x26
#define TI_E_StatPlo 0x27
#define TI_E_TolTooSmall 0x28
#define TI_E_Reserved 0x29
#define TI_E_Mode 0x30
#define TI_E_LnkErr 0x31
#define TI_E_LnkMemErr 0x32
#define TI_E_LnkTransErr 0x33
#define TI_E_LnkDupErr 0x34
#define TI_E_LnkMemFull 0x35
#define TI_E_Unknown 0x36
#define TI_E_Scale 0x37
#define TI_E_IdNotFound 0x38
#define TI_E_NoMode 0x39
#define TI_E_Validation 0x40
#define TI_E_Length 0x41
#define TI_E_Application 0x42
#define TI_E_AppErr1 0x43
#define TI_E_AppErr2 0x44
#define TI_E_ExpiredApp 0x45
#define TI_E_BadAdd 0x46
#define TI_E_Archived 0x47
#define TI_E_Version 0x48
#define TI_E_ArchFull 0x49
#define TI_E_Variable 0x50
#define TI_E_Duplicate 0x51
// System Variable Equates
// ------------------------------
#define TI_XSCLt 0x2
#define TI_YSCLt 0x3
#define TI_XMINt 0xa
#define TI_XMAXt 0xb
#define TI_YMINt 0xc
#define TI_YMAXt 0xd
#define TI_TMINt 0xe
#define TI_TMAXt 0xf
#define TI_THETMINt 0x10
#define TI_THETMAXt 0x11
#define TI_TBLMINt 0x1a
#define TI_PLOTSTARTt 0x1b
#define TI_NMAXt 0x1d
#define TI_NMINt 0x1f
#define TI_TBLSTEPt 0x21
#define TI_TSTEPt 0x22
#define TI_THETSTEPt 0x23
#define TI_DELTAXt 0x26
#define TI_DELTAYt 0x27
#define TI_XFACTt 0x28
#define TI_YFACTt 0x29
#define TI_FINNt 0x2b
#define TI_FINIt 0x2c
#define TI_FINPVt 0x2d
#define TI_FINPMTt 0x2e
#define TI_FINFVt 0x2f
#define TI_FINPYt 0x30
#define TI_FINCYt 0x31
#define TI_PLOTSTEPt 0x34
#define TI_XRESt 0x36
// Equates To RAM Locations For Stat Vars
// ----------------------------------------------------------------
#define TI_FPLEN 0x9 // Length of a floating-point number.
#define TI_StatN 0x0
#define TI_XMean 0x0
#define TI_SumX 0x0
#define TI_SumXSqr 0x0
#define TI_StdX 0x0
#define TI_StdPX 0x0
#define TI_MinX 0x0
#define TI_MaxX 0x0
#define TI_MinY 0x0
#define TI_MaxY 0x0
#define TI_YMean 0x0
#define TI_SumY 0x0
#define TI_SumYSqr 0x0
#define TI_StdY 0x0
#define TI_StdPY 0x0
#define TI_SumXY 0x0
#define TI_Corr 0x0
#define TI_MedX 0xc
#define TI_Q1 0x0
#define TI_Q3 0x0
#define TI_QuadA 0x0
#define TI_QuadB 0x0
#define TI_QuadC 0x0
#define TI_CubeD 0x0
#define TI_QuartE 0xc
#define TI_MedX1 0x0
#define TI_MedX2 0x0
#define TI_MedX3 0x0
#define TI_MedY1 0x0
#define TI_MedY2 0x0
#define TI_MedY3 0x0
#define TI_PStat 0x0
#define TI_ZStat 0x0
#define TI_TStat 0x0
#define TI_ChiStat 0x0
#define TI_FStat 0xc
#define TI_DF 0xf
#define TI_Phat 0xdf
#define TI_Phat1 0x0
#define TI_Phat2 0x0
#define TI_MeanX1 0x0
#define TI_StdX1 0x0
#define TI_StatN1 0x0
#define TI_MeanX2 0x0
#define TI_StdX2 0x0
#define TI_StatN2 0x0
#define TI_StdXP2 0x0
#define TI_SLower 0x0
#define TI_SUpper 0x0
#define TI_SStat 0x0
#define TI_anovaf_vars 0x0
#define TI_F_DF 0xa
#define TI_F_SS 0xf
#define TI_F_MS 0xf
#define TI_E_DF 0xf
#define TI_E_SS 0xe
#define TI_E_MS 0xe
// System Flags
// ----------------------------------------------------------------------
#define TI_ioDelFlag 0x0
#define TI_inDelete 0x0 // 1 = DELETE SCREEN
#define TI_trigFlags 0x0 // Trigonometry mode settings
#define TI_trigDeg 0x2 // 1 = degrees, 0=radians
#define TI_kbdFlags 0x0 // Keyboard scan
#define TI_kbdSCR 0x3 // 1=scan code ready
#define TI_kbdKeyPress 0x4 // 1=key has been pressed
#define TI_doneFlags 0x0 // display "Done"
#define TI_donePrgm 0x5 // 1=display "Done" after prgm
// ----------------------------------------------------------------------
#define TI_editFlags 0x1
#define TI_editOpen 0x2 // 1=edit buffer is open
#define TI_ansFlags 0x1
#define TI_AnsScroll 0x3 // 1=answer can scroll, seems must be reset in order to move about edit buffer
#define TI_monFlags 0x1 // monitor flags
#define TI_monAbandon 0x4 // 1=don't start any long process in put away (#715)
// ----------------------------------------------------------------------
#define TI_plotFlags 0x2 // plot generation flags
#define TI_plotLoc 0x1 // 0=bkup and display, 1=display only
#define TI_plotDisp 0x2 // 1=plot is in display, 0=text in display, this also indicates whether graph is being shown or not
#define TI_grfModeFlags 0x2 // graph mode settings
#define TI_grfFuncM 0x4 // 1=function graph
#define TI_grfPolarM 0x5 // 1=polar graph
#define TI_grfParamM 0x6 // 1=parametric graph
#define TI_grfRecurM 0x7 // 1=RECURSION graph
// ----------------------------------------------------------------------
#define TI_graphFlags 0x3
#define TI_graphDraw 0x0 // 0=graph is valid, 1=redraw graph(dirty)
#define TI_graphCursor 0x2
// ----------------------------------------------------------------------
#define TI_grfDBFlags 0x4
#define TI_grfDot 0x0 // 0=line, 1=dot
#define TI_grfSimul 0x1 // 0=sequential, 1=simultaneous
#define TI_grfGrid 0x2 // 0=no grid, 1=grid
#define TI_grfPolar 0x3 // 0=rectangular, 1=polar coordinates
#define TI_grfNoCoord 0x4 // 0=display coordinates, 1=off
#define TI_grfNoAxis 0x5 // 0=axis, 1=no axis
#define TI_grfLabel 0x6 // 0=off, 1=axis label
// ----------------------------------------------------------------------
#define TI_textFlags 0x5 // Text output flags
#define TI_textEraseBelow 0x1 // 1=erase line below small char
#define TI_textScrolled 0x2 // 1=screen scrolled
#define TI_textInverse 0x3 // 1=display inverse bit-map
#define TI_textInsMode 0x4 // 0=overstrike, 1=insert mode
// ----------------------------------------------------------------------
#define TI_ParsFlag 0x6 // PARSER flags
#define TI_listOpen 0x5 //  {...}
#define TI_matrixOpen1 0x6 //  [[...]]
#define TI_matrixOpen2 0x7 //  [...]
// ----------------------------------------------------------------------
#define TI_ParsFlag2 0x7 // PARSER flags
#define TI_numOP1 0x0 // 1=RESULT IN OP1, 0=NO RESULT
// ----------------------------------------------------------------------
#define TI_newDispF 0x8 // Derivative mode flags
#define TI_preClrForMode 0x0 // 1=HELP BLINK ON MODE SCREEN
#define TI_allowProgTokens 0x1 // 1=allow programming tokens to be parsed in BASIC programs
#define TI_progExecuting 0x1
#define TI_apdFlags 0x8 // Automatic power-down
#define TI_apdAble 0x2 // 1=APD enabled
#define TI_apdRunning 0x3 // 1=APD clock running
#define TI_apdWarmStart 0x4 // 1=calculator is turning on from APD or power loss
// ----------------------------------------------------------------------
#define TI_web_err_mask 0x60
// ----------------------------------------------------------------------
#define TI_onFlags 0x9 // on key flags
#define TI_parseInput 0x1 // 1=parse input when done
#define TI_onRunning 0x3 // 1=calculator is running
#define TI_onInterrupt 0x4 // 1=on key interrupt request
#define TI_statFlags 0x9 // statistics flags
// unknown		equ 5		;unknown
#define TI_statsValid 0x6 // 1=stats are valid
// unknown		equ 7		;unknown
// ----------------------------------------------------------------------
#define TI_fmtFlags 0xa // numeric format flags
#define TI_fmtExponent 0x0 // 1=show exponent, 0=no exponent
#define TI_fmtEng 0x1 // 1=engineering notion, 0=scientific
#define TI_numMode 0xa
#define TI_fmtReal 0x5
#define TI_fmtRect 0x6
#define TI_fmtPolar 0x7
#define TI_realMode 0x5
#define TI_rectMode 0x6
#define TI_polarMode 0x7
#define TI_fmtBaseMask 0x11100b //  mask to base flags
#define TI_fmtBaseShift 0x2 //  offset to base flags
// ----------------------------------------------------------------------
#define TI_fmtOverride 0xb // copy of fmtFlags with conversion override
// ----------------------------------------------------------------------
#define TI_fmtEditFlags 0xc // numeric editing flags
#define TI_fmtEdit 0x0 // 1=format number for editing
#define TI_curFlags 0xc // Cursor
#define TI_curAble 0x2 // 1=cursor flash is enabled
#define TI_curOn 0x3 // 1=cursor is showing
#define TI_curLock 0x4 // 1=cursor is locked off
#define TI_cmdFlags 0xc // command editor flags
#define TI_cmdVirgin 0x5 // 1=nothing has been typed in cmd bfr
#define TI_cmdExec 0x6 // 1=need to execute a command
// ----------------------------------------------------------------------
#define TI_appFlags 0xd // application flags
#define TI_appWantIntrpt 0x0 // 1=want ON key interrupts
#define TI_appTextSave 0x1 // 1=save characters in textShadow
#define TI_appAutoScroll 0x2 // 1=auto-scroll text on last line
#define TI_appMenus 0x3 // 1=process keys that bring up menus, 0=check Lock menu flag
#define TI_appLockMenus 0x4 // 1=ignore menu keys, 0=switch to home screen and bring up menu
#define TI_appCurGraphic 0x5 // 1=graphic cursor
#define TI_appCurWord 0x6 // 1=text cursor covers entire word
#define TI_appExit 0x7 // 1=application handles [EXIT] key itself
#define TI_appWantIntrptF (1 << TI_appWantIntrpt)
#define TI_appTextSaveF (1 << TI_appTextSave)
#define TI_appAutoScrollF (1 << TI_appAutoScroll)
#define TI_appMenusF (1 << TI_appMenus)
#define TI_appLockMenusF (1 << TI_appLockMenus)
#define TI_appCurGraphicF (1 << TI_appCurGraphic)
#define TI_appCurWordF (1 << TI_appCurWord)
#define TI_appExitF (1 << TI_appExit)
// ----------------------------------------------------------------------
#define TI_rclFlag 0xe // OS recall queue flags
#define TI_enableQueue 0x7 // 1 = enable recall queue
// ----------------------------------------------------------------------
#define TI_seqFlags 0xf // Sequential Graph flags
#define TI_webMode 0x0 // 0 = NORMAL SEQ MODE, 1 = WEB MODE
#define TI_webVert 0x1
#define TI_sequv 0x2 // U vs V
#define TI_seqvw 0x3 // V vs W
#define TI_sequw 0x4 // U vs W
// ----------------------------------------------------------------------
#define TI_promptFlags 0x11 // prompt line flags
#define TI_promptEdit 0x0 // 1=editing in prompt buffer
// unknown		equ 7		;unknown
// ----------------------------------------------------------------------
#define TI_indicFlags 0x12 // Indicator flags
#define TI_indicRun 0x0 // 1=run indicator ON
#define TI_indicInUse 0x1 // indicator save area in use=1, free=0 ;resetting will disable 2nd while in _getkey
#define TI_shiftFlags 0x12 // [2nd] and [ALPHA] flags
#define TI_shift2nd 0x3 // 1=[2nd] has been pressed
#define TI_shiftAlpha 0x4 // 1=[ALPHA] has been pressed
#define TI_shiftLwrAlph 0x5 // 1=lower case, 0=upper case
#define TI_shiftALock 0x6 // 1=alpha lock has been pressed
#define TI_shiftKeepAlph 0x7 // 1=cannot cancel alpha shift
// ----------------------------------------------------------------------
#define TI_tblFlags 0x13 // table flags.
#define TI_autoFill 0x4 // 1=prompt, 0=fillAuto
#define TI_autoCalc 0x5 // 1=prompt, 0=CalcAuto
#define TI_reTable 0x6 // 0=table is okay, 1=must recompute table.
// ----------------------------------------------------------------------
#define TI_sGrFlags 0x14
#define TI_grfSplit 0x0 // 1=Split Graph, 0=Normal
#define TI_vertSplit 0x1 // 1=Vertical (left-right) Split
#define TI_grfSChanged 0x2 // 1=Graph just changed Split <-> normal
#define TI_grfSplitOverride 0x3 // 1 = ignore graph split flag if set
#define TI_write_on_graph 0x4 // 1 = TEXT OR EQU WRITING TO GRAPH SCREEN
#define TI_g_style_active 0x5 // 1 = GRAPH STYLES ARE ENABLED, USE THEM
#define TI_cmp_mod_box 0x6 // 1 = DOING MOD BOX PLOT COMPUTATION
#define TI_textWrite 0x7
// ----------------------------------------------------------------------
#define TI_newIndicFlags 0x15
#define TI_extraIndic 0x0
#define TI_saIndic 0x1
// 3 has something to do with stat/list editor
// ----------------------------------------------------------------------
#define TI_interruptFlags 0x16
#define TI_secondTimerEnabled 0x0 // 1 = second hardware timer enabled
// ----------------------------------------------------------------------
#define TI_smartFlags 0x17
#define TI_smarter_mask 0x3
#define TI_smarter_test 0x1
#define TI_smartGraph 0x0
#define TI_smartGraph_inv 0x1
// ----------------------------------------------------------------------
#define TI_traceFlags 0x18
#define TI_grfExpr 0x0 // set to hide expression while tracing
// ----------------------------------------------------------------------
// There is a flag 19h.
// ----------------------------------------------------------------------
#define TI_statFlags2 0x1a
#define TI_statDiagnosticsOn 0x0 // 1 = stat diagnostics on
#define TI_noDelStat 0x2 // 1 = don't delete stats
// ----------------------------------------------------------------------
#define TI_apdFlags2 0x1b
#define TI_warmStartInt 0x6 // 1 = a warm start is occurning before the next interrupt
// ----------------------------------------------------------------------
// There is a flag 1Ch (stats-related).
// ----------------------------------------------------------------------
// There is a flag 1Dh.
// ----------------------------------------------------------------------
// There is a flag 1Eh.
// ----------------------------------------------------------------------
#define TI_varTypeMask 0x1f // is this a flag byte? yes
#define TI_varGraphRef 0x6
// ----------------------------------------------------------------------
#define TI_graphFlags2 0x1f
#define TI_splitOverride 0x3 // 0 = force full screen with ParseInp, or something
// ----------------------------------------------------------------------
#define TI_asm_Flag1 0x21 // ASM CODING
#define TI_asm_Flag2 0x22 // ASM CODING
#define TI_asm_Flag3 0x23 // NO LONGER AVAILABLE
// ----------------------------------------------------------------------
#define TI_arcFlag 0x24
#define TI_checkBatteryLevelFirst 0x0 // 1 = check battery levels in Arc_Unarc first and throw error if low
#define TI_getSendFlg 0x24
#define TI_comFailed 0x1 // 1 = Get/Send Communication Failed
#define TI_selfTestFlag 0x24
#define TI_resetOnPowerOn 0x2 // 1 = Force RAM reset when APD disabled on next power on
#define TI_appLwrCaseFlag 0x24
#define TI_lwrCaseActive 0x3
// ----------------------------------------------------------------------
#define TI_contextFlags 0x25
#define TI_nocxPutAway 0x5 // 1 = do not call cxPutAway routine
// ----------------------------------------------------------------------
#define TI_groupFlags 0x26 // used temporarily in Arc_Unarc
#define TI_inGroup 0x1 // 1 = IN GROUP CONTEXT
#define TI_noCompletionByte 0x2 // 1 = do not write 0FCh when calling Arc_Unarc, leave as 0FEh
#define TI_noDataWrite 0x3 // 1 = do not write data when calling Arc_Unarc, nor size bytes
#define TI_writeSizeBytesOnly 0x5 // 1 = only write size bytes when calling Arc_Unarc
// ----------------------------------------------------------------------
#define TI_statusBarFlags 0x27
#define TI_noStatusBarMode 0x7 //  1 = abort drawing of statusbar mode, like "TEST MODE ENABLED"
// ----------------------------------------------------------------------
#define TI_APIFlg 0x28
#define TI_appAllowContext 0x0 // app wants context changes to happen
#define TI_appRunning 0x4 // app is currently running
#define TI_appRetKeyOff 0x7 // 1 = GetKey returns kOff when [2nd]+[ON] pressed
// ----------------------------------------------------------------------
#define TI_apiFlg2 0x29
// ----------------------------------------------------------------------
#define TI_apiFlg3 0x2a
// ----------------------------------------------------------------------
#define TI_apiFlg4 0x2b
#define TI_cellOverride 0x1 // use cell override
#define TI_fullScrnDraw 0x2 // DRAW INTO LAST ROW/COL OF SCREEN
// ----------------------------------------------------------------------
#define TI_xapFlag0 0x2e // external app flags, do not use 0,(iy+2Eh) (used by mouse routines)
#define TI_xapFlag1 0x2f
#define TI_xapFlag2 0x30
#define TI_xapFlag3 0x31
// ----------------------------------------------------------------------
#define TI_fontFlags 0x32
#define TI_fracDrawLFont 0x2
#define TI_fracTallLFont 0x3
#define TI_customFont 0x7
// ----------------------------------------------------------------------
#define TI_hookflags1 0x33 // also scriptFlag, rclFlag2, backGroundLink
#define TI_alt_On 0x0 // run ONSCRPT at startup
#define TI_alt_Off 0x1 // run OFFSCRPT at shutdown
#define TI_useRclQueueEnd 0x2 // 1 = external mode
#define TI_ignoreBPLink 0x3 // 1 = override flag for link activity hook
#define TI_bPLinkOn 0x4 // 1 = link activity hook active
#define TI_enableKeyEcho 0x5 // 1 = sends keypresses back to connected calc as remote control packets (with GetCSC vs. GetKey codes...really dumb, TI)
#define TI_noTempDelete 0x6 // 1 = do not delete temporary programs at homescreen
// ----------------------------------------------------------------------
#define TI_hookflags2 0x34 // also sysHookFlg
#define TI_getCSCHookActive 0x0 // 1 = GetCSC hook active
#define TI_libraryHookActive 0x1 // 1 = library hook active
#define TI_noHookActive 0x2 // 1 = same as 0; never used by OS
#define TI_homescreenHookActive 0x4 // 1 = homescreen hook active
#define TI_rawKeyHookActive 0x5 // 1 = raw key hook active
#define TI_catalog2HookActive 0x6 // 1 = catalog 2 hook active
#define TI_cursorHookActive 0x7 // 1 = cursor hook active
// ----------------------------------------------------------------------
#define TI_hookflags3 0x35 // also sysHookFlg1
#define TI_tokenHookActive 0x0 // 1 = token hook active
#define TI_localizeHookActive 0x1 // 1 = localize hook active
#define TI_windowHookActive 0x2 // 1 = window hook active
#define TI_graphHookActive 0x3 // 1 = graph hook active
#define TI_yEquHookActive 0x4 // 1 = Y= hook active
#define TI_fontHookActive 0x5 // 1 = font hook active
#define TI_regraphHookActive 0x6 // 1 = regraph hook active
#define TI_drawingHookActive 0x7 // 1 = drawing hook active
// ----------------------------------------------------------------------
#define TI_hookflags4 0x36 // also sysHookFlag2
#define TI_traceHookActive 0x0 // 1 = trace hook active
#define TI_parserHookActive 0x1 // 1 = parser hook active
#define TI_appChangeHookActive 0x2 // 1 = app change hook active
#define TI_catalog1HookActive 0x3 // 1 = catalog 1 hook active
#define TI_helpHookActive 0x4 // 1 = help hook active
#define TI_cxRedispHookActive 0x5 // 1 = cxRedisp hook active
#define TI_menuHookActive 0x6 // 1 = menu hook active
#define TI_silentLinkHookActive 0x7 // 1 = silent link hook active
// ----------------------------------------------------------------------
// hookflags2Override	equ 37h		;set corresponding bit to kill iy+35h hook when executing app
// ----------------------------------------------------------------------
// hookflags3Override	equ 38h		;set corresponding bit to kill iy+36h hook when executing app
// ----------------------------------------------------------------------
// hookflags4Override	equ 39h		;set corresponding bit to kill iy+37h hook when executing app
// ----------------------------------------------------------------------
#define TI_hookflags5 0x3a
#define TI_usbActivityHookActive 0x0 // 1 = USB activity hook active
// ----------------------------------------------------------------------
#define TI_plotFlag3 0x3c
#define TI_bufferOnly 0x0
#define TI_useFastCirc 0x4
// ----------------------------------------------------------------------
#define TI_dBKeyFlags 0x3d
#define TI_keyDefaultsF 0x6 // 1 = GetKey returns extended keycodes with TI-Keyboard
// ----------------------------------------------------------------------
#define TI_silentLinkFlags 0x3e
#define TI_silentLinkActive 0x0 // 1 = SE/84+ silent link is active
#define TI_extraHookFlags 0x3e
#define TI_checkCatalog2HookVer 0x3 // 1 = check catalog 2 hook's version before executing it (and error or take other action if so)
#define TI_openLibActive 0x4 // 1 = OpenLib( was successfully called on a Flash application (ExecLib will error if zero)
// ----------------------------------------------------------------------
#define TI_clockFlags 0x3f
#define TI_notMDYMode 0x0 // 0 = M/D/Y format
#define TI_isYMDMode 0x1 // 1 = Y/M/D format
#define TI_is24Hour 0x2 // 1 = clock in 24 hour mode
#define TI_inAfternoon 0x3 // 1 = current time is in afternoon (PM) (I think)
#define TI_useTokensInString 0x4 // 1 = use tokens instead of characters when displaying clock as string (for getTmStr and getDtStr vs. MODE screen) (keep this reset)
#define TI_displayClock 0x5 // 1 = display clock (this is set every second, reset otherwise)
#define TI_clockOn 0x6 // 1 = clock on
// ----------------------------------------------------------------------
#define TI_mathprintFlags 0x44
#define TI_mathprintEnabled 0x5 // 1 = use mathprint styling
// ----------------------------------------------------------------------
#define TI_InitialBootMenuFlags 0x45
#define TI_dispinitialBootMenu 0x4 //  1 = don't display the initial boot menu
// ----------------------------------------------------------------------
#define TI_backlightFlags 0x46
#define TI_restoreBrightness 0x0 // 1 = restore lcd brightness when needed
// ----------------------------------------------------------------------
#define TI_grFlags 0x4a
#define TI_drawGrLbls 0x0 // 1 = don't draw Graph Labels (this is usually reset anyway)
#define TI_putMapFlags 0x4a
#define TI_usePixelShadow2 0x3 // 1 = use pixelshadow2, not pixelshadow
#define TI_putMapUseColor 0x4 // 1 = use custom color
// ----------------------------------------------------------------------
#define TI_graphDispFlags 0x4b
#define TI_backgroundValid 0x4 // 1 = items in graph background are still valid
// ----------------------------------------------------------------------
#endif