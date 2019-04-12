#pragma once

#define TARGET_GAMEVERSION "Version 9.7.269.6900 [PUBLIC]"

#define FN_ISSUE_ORDER			 0x1BE660 // 9.7 || E8 ? ? ? ? 8B 84 24 ? ? ? ? 8B CF F3 
#define FN_IS_ALIVE				 0x1E2C30 // 9.7 || 56 8B F1 8B 06 8B 80 ? ? ? ? FF D0 84 C0 74 19 
#define FN_IS_TARGETABLE		 0x21FB80 // 9.7 || 56 8B F1 E8 ? ? ? ? 84 C0 74 2E 
#define FN_IS_HERO				 0x226EC0 // 9.7 || E8 ? ? ? ? 84 C0 C7 44 24 ? ? ? ? ? 8D 44 24 30 
#define FN_IS_MINION			 0x226F00 // 9.7 || E8 ? ? ? ? 83 C4 04 84 C0 74 16 8B 0F 
#define FN_IS_MISSILE			 0x226F20 // 9.7 || E8 ? ? ? ? 83 C4 04 84 C0 74 1C FF Unconfirmed
#define FN_DRAW_CIRCLE			 0x596D40 // 9.7 || E8 ? ? ? ? 83 C4 1C 8B 44 24 18 
#define FN_GET_ATTACK_CAST_DELAY 0x5A5FE0 // 9.7 || 83 EC 0C 56 57 8B 7C 24 18 8B CF 
#define FN_GET_ATTACK_DELAY		 0x5A60C0 // 9.7 || E8 ? ? ? ? D8 44 24 20 83 
#define FN_PRINT_CHAT			 0x5D7C10 // 9.7 || E8 ? ? ? ? 33 C0 5F C2 
#define DWORD_OBJECT_MANAGER	 0x16466F8 // 9.7 || B9 ? ? ? ? E8 ? ? ? ? 8B 4F 0E 
#define DWORD_CHAT_CLIENT		 0x1685054 // 9.7 || 8B 0D ? ? ? ? 6A 00 50 E8 ? ? ? ? 33 
#define DWORD_HUD_INSTANCE		 0x168773C // 9.7 || 8B 0D ? ? ? ? FF 73 1C 8B 49 
#define DWORD_GAME_TIME			 0x2F22148 // 9.7 || F3 0F 5C 0D ? ? ? ? 0F 2F C1 F3 
#define DWORD_LOCAL_PLAYER		 0x2F26120 // 9.7 || A1 ? ? ? ? 85 C0 0F 84 ? ? ? ? 56 8B B0 

//#define oObjAmmo 0x0458                 // 9.7 Unconfirmed
#define oObjArmor 0x1288                // 9.7
#define oObjAtkRange 0x12A8             // 9.7 Unconfirmed
#define oObjBaseAtk 0x1260              // 9.7 Unconfirmed
#define oObjBonusAP 0x11F0              // 9.7 Unconfirmed
#define oObjBonusAtk 0x11E0             // 9.7 Unconfirmed
#define oObjBonusMR 0x1294              // 9.7 Unconfirmed
#define oObjBuffmanager 0x20F0          // 9.7 Unconfirmed
#define oObjChampionName 0x3158         // 9.7 Unconfirmed
//#define oObjCombatType 0x21D0           // 9.6 Unconfirmed (Same in 9.7?)
//#define oObjCritMod 0x1284              // 9.7 Unconfirmed
//#define oObjDirection 0x1B54            // 9.7 Unconfirmed
#define oObjHealth 0x0DE8               // 9.7 Unconfirmed
#define oObjIndex 0x24                  // 9.6 Unconfirmed (Same in 9.7?)
#define oObjInv 0x4C08                  // 9.6 Unconfirmed (Same in 9.7?)
#define oObjLevel 0x4964                // 9.7 Unconfirmed
#define oObjMana 0x03F8                 // 9.7 Unconfirmed
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
#define oRenderer 0x2F43C1C             // 9.7 Unconfirmed
//#define oUnderMouseObject 0x22E8CEC     // 9.6 Unconfirmed (Same in 9.7?)
#define oUpdateChargeableSpell 0x5A1B10 // 9.7 Unconfirmed
#define oWorld2Screen 0x7D59E0          // 9.7 Unconfirmed
//#define oZoomClass 0x2F3F5B8            // 9.6 Unconfirmed (Same in 9.7?)
#define oUnderMouseObject = 0x22D7F4C   // 9.7 Unconfirmed || C7 05 ? ? ? ? ? ? ? ? E8 ? ? ? ? 83 C4 04 FF B4
//#define oCastSpell 0x59F3B0           // 9.7 Unconfirmed
//#define oGetBasicAttack 0x1B39C0        // 9.7 Unconfirmed
//#define oGetCharacterInfo 0x29E850      // 9.6 Unconfirmed (Same in 9.7?)
//#define oGetSpellState 0x5A4EE0         // 9.6 Unconfirmed (Same in 9.7?)
//#define oIsBaron 0x215C70               // 9.7 Unconfirmed
//#define oIsDragon 0x2150C0              // 9.7 Unconfirmed
//#define oIsInhib 0x226D40               // 9.7 Unconfirmed
//#define oIsNexus 0x227130               // 9.7 Unconfirmed
//#define oIsNotWall 0x748840             // 9.7 Unconfirmed
//#define oIsTroy 0x2271A0                // 9.7 Unconfirmed
//#define oIsTurret 0x2270B0              // 9.7 Unconfirmed
//#define oIsWall 0x748840                // 9.7 Unconfirmed
