﻿#pragma once
#define TARGET_GAMEVERSION "Version 9.7.269.6900 [PUBLIC]"

#define oCastSpell 0x59F3B0             // 9.7 Unconfirmed

/*
	Search for string "DisplayChatMessage"
	goto DATA XREF: .data:off_213F308↓o under aDisplaychatmes db 'DisplayChatMessage',0
	goto DATA XREF: sub_F541C0↑r under dd offset aDisplaychatmes
	subroutine under your current 4 instruction sub it should be fairly long.
	loc at the bottom first mov dword
	ex.) loc_F54217: ; CODE XREF: sub_F541D0+43↑j
.		 mov ecx, oChatClient ; oChatClient = dword_2495054
*/
#define oChatClient 0x1685054           // 9.7

#define oDrawCircle 0x596D40            // 9.7 Unconfirmed
#define oFuncSetModel 0x21D870          // 9.6 Unconfirmed (Same in 9.7?)
#define oGameTime 0x2F22148             // 9.7 Unconfirmed
#define oGameVersion 0x2F4DD50          // 9.6 Unconfirmed (Same in 9.7?)
#define oGetAttackCastDelay 0x5A5FE0    // 9.7 Unconfirmed
#define oGetAttackDelay 0x5A60C0        // 9.7 Unconfirmed
#define oGetBasicAttack 0x1B39C0        // 9.7 Unconfirmed
#define oGetCharacterInfo 0x29E850      // 9.6 Unconfirmed (Same in 9.7?)
#define oGetSpellState 0x5A4EE0         // 9.6 Unconfirmed (Same in 9.7?)
#define oHudInstance 0x168773C          // 9.7 Unconfirmed
#define oIsAlive 0x1E2C30               // 9.7 Unconfirmed
#define oIsBaron 0x215C70               // 9.7 Unconfirmed
#define oIsDragon 0x2150C0              // 9.7 Unconfirmed
#define oIsHero 0x226EC0                // 9.7 Unconfirmed
#define oIsInhib 0x226D40               // 9.7 Unconfirmed
#define oIsMinion 0x226F00              // 9.7 Unconfirmed
#define oIsMissile 0x226F20             // 9.7 Unconfirmed
#define oIsNexus 0x227130               // 9.7 Unconfirmed
#define oIsNotWall 0x748840             // 9.7 Unconfirmed
#define oIssueOrder 0x1BE660            // 9.7 Unconfirmed
#define oIsTargetable 0x21FB80          // 9.7 Unconfirmed
#define oIsTroy 0x2271A0                // 9.7 Unconfirmed
#define oIsTurret 0x2270B0              // 9.7 Unconfirmed
#define oIsWall 0x748840                // 9.7 Unconfirmed

/*
	Search for string "hero"
	goto ; DATA XREF: sub_10DCCB0+2D↑o
	goto ; CODE XREF: sub_10DCCB0+15↑j
	cmp esi, oLocalPlayer ; oLocalPlayer = dword_3D36120;
*/
#define oLocalPlayer 0x2F26120 //  9.7

#define oObjAmmo 0x0458                 // 9.7 Unconfirmed
#define oObjArmor 0x1288                // 9.7 Unconfirmed
#define oObjAtkRange 0x12A8             // 9.7 Unconfirmed
#define oObjBaseAtk 0x1260              // 9.7 Unconfirmed
#define oObjBonusAP 0x11F0              // 9.7 Unconfirmed
#define oObjBonusAtk 0x11E0             // 9.7 Unconfirmed
#define oObjBonusMR 0x1294              // 9.7 Unconfirmed
#define oObjBuffmanager 0x20F0          // 9.7 Unconfirmed
#define oObjChampionName 0x3158         // 9.7 Unconfirmed
#define oObjCombatType 0x21D0           // 9.6 Unconfirmed (Same in 9.7?)
#define oObjCritMod 0x1284              // 9.7 Unconfirmed
#define oObjDirection 0x1B54            // 9.7 Unconfirmed
#define oObjHealth 0x0DE8               // 9.7 Unconfirmed
#define oObjIndex 0x24                  // 9.6 Unconfirmed (Same in 9.7?)
#define oObjInv 0x4C08                  // 9.6 Unconfirmed (Same in 9.7?)
#define oObjLevel 0x4964                // 9.7 Unconfirmed
#define oObjMana 0x03F8                 // 9.7 Unconfirmed
#define oObjManager 0x16466F8           // 9.7 Unconfirmed
#define oObjMaxHealth 0x0DF8            // 9.7 Unconfirmed
#define oObjMaxMana 0x0408              // 9.7 Unconfirmed
#define oObjMoveSpeed 0x12A0            // 9.7 Unconfirmed
#define oObjMR 0x1290                   // 9.7 Unconfirmed
#define oObjName 0x0060                 // 9.7 Unconfirmed
#define oObjNetworkID 0x110             // 9.7 Unconfirmed (perhaps wrong)
#define oObjPos 0x019C                  // 9.7 Unconfirmed
#define oObjRecallState 0xDC8           // 9.7 Unconfirmed
#define oObjSourceIndex 0x24C           // 9.7 Unconfirmed
#define oObjSpellBook 0x28A8            // 9.7 Unconfirmed
#define oObjSpellEndPos 0x270           // 9.7 Unconfirmed
#define oObjSpellStartPos 0x264         // 9.7 Unconfirmed
#define oObjTargetID 0x298              // 9.7 Unconfirmed
#define oObjTeam 0x0044                 // 9.7 Unconfirmed
#define oObjVisibility 0x39C            // 9.7 Unconfirmed
#define oPrintChat 0x5D7C10             // 9.7 Unconfirmed
#define oRenderer 0x2F43C1C             // 9.7 Unconfirmed
#define oUnderMouseObject 0x22E8CEC     // 9.6 Unconfirmed (Same in 9.7?)
#define oUpdateChargeableSpell 0x5A1B10 // 9.7 Unconfirmed
#define oWorld2Screen 0x7D59E0          // 9.7 Unconfirmed
#define oZoomClass 0x2F3F5B8            // 9.6 Unconfirmed (Same in 9.7?)