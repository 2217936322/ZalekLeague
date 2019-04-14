#pragma once

#define TARGET_GAMEVERSION "Version 9.7.269.6900 [PUBLIC]"

// Use Binary Search in IDA with the patterns provided.
// If you are getting the wrong value then try checking Find all occurences. 
// Most if not all should be accurate though.

#define FN_GET_BASIC_ATTACK		   0x1B39C0 // 9.7 || E8 ? ? ? ? 8B 8B ? ? ? ? 8B E8 8B 
#define FN_ISSUE_ORDER			   0x1BE660 // 9.7 || E8 ? ? ? ? 8B 84 24 ? ? ? ? 8B CF F3 
#define FN_IS_ALIVE				   0x1E2C30 // 9.7 || E8 ? ? ? ? 84 C0 74 3B 8B 
#define FN_IS_DRAGON		       0x2150C0 // 9.7 || E8 ? ? ? ? 33 DB 84 C0 0F 95 C3 8D 1C 5D ? ? ? ? E9 
#define FN_IS_BARON			       0x215C70 // 9.7 || E8 ? ? ? ? 84 C0 74 0A BB 
#define FN_IS_TARGETABLE		   0x21FB80 // 9.7 || E8 ? ? ? ? 84 C0 74 2E 
#define FN_IS_INHIB				   0x226D40 // 9.7 || E8 ? ? ? ? 83 C4 04 84 C0 75 0B 6A 
#define FN_IS_HERO				   0x226EC0 // 9.7 || E8 ? ? ? ? 84 C0 C7 44 24 ? ? ? ? ? 8D 44 24 30 
#define FN_IS_MINION			   0x226F00 // 9.7 || E8 ? ? ? ? 83 C4 04 84 C0 74 16 8B 0F 
#define FN_IS_MISSILE			   0x226F20 // 9.7 || E8 ? ? ? ? 83 C4 04 84 C0 74 1C FF
#define FN_IS_TURRET			   0x2270B0 // 9.7 || E8 ? ? ? ? 83 C4 04 84 C0 74 10 32 
#define FN_IS_NEXUS				   0x227130 // 9.7 || E8 ? ? ? ? 83 C4 04 85 C0 74 13 F3 
#define FN_IS_TROY				   0x2271A0 // 9.7 || E8 ? ? ? ? 8B F8 83 C4 04 85 FF 74 58 
#define FN_DRAW_FLOAT_TEXT		   0x248500 // 9.7 || E8 ? ? ? ? 8B CB C7 00 ? ? ? ? 8D 44 24 2C 
#define FN_GET_CHARACTER_INFO      0x29E850 // 9.7 || E8 ? ? ? ? 83 C6 24 8B
#define FN_CAST_SPELL			   0x59F3B0 // 9.7 || E8 ? ? ? ? 8B 7C 24 10 5D 
#define FN_UPDATE_CHARGEABLE_SPELL 0x5A1B10 // 9.7 || E8 ? ? ? ? 5E 5F B0 01 5B 83 C4 10  
#define FN_GET_SPELL_STATE         0x5A4EE0 // 9.7 || 57 8B 7C 24 0C 83 7F 04
#define FN_GET_ATTACK_CAST_DELAY   0x5A5FE0 // 9.7 || E8 ? ? ? ? D9 9D ? ? ? ? 53 
#define FN_GET_ATTACK_DELAY		   0x5A60C0 // 9.7 || E8 ? ? ? ? D8 44 24 20 83 
#define FN_PRINT_CHAT			   0x5D7C10 // 9.7 || E8 ? ? ? ? 33 C0 5F C2 
#define FN_IS_WALL				   0x748840 // 9.7 || E8 ? ? ? ? 83 C4 08 84 C0 75 46 33 
#define FN_WORLD_TO_SCREEN		   0x7D59E0 // 9.7 || E8 ? ? ? ? F3 0F 10 44 24 ? 83 C4 10 F3 0F 5C

#define FNPTR_DRAW_CIRCLE			  0x596D40 // 9.7 || E8 ? ? ? ? 83 C4 1C 8B 44 24 18 
#define FNPTR_DRAW_ELLIPSE			  0x5973E0 // 9.7 || E8 ? ? ? ? 83 C4 14 83 7E 10 00 8D 
#define FNPTR_DRAW_PATH				  0x597670 // 9.7 || E8 ? ? ? ? 83 C4 0C 8B 0D ? ? ? ? 8D 
#define FNPTR_DRAW_RECT				  0x5976C0 // 9.7 || E8 ? ? ? ? 83 C4 14 E9 ? ? ? ? F3 0F 7E 
#define FNPTR_DRAW_ROUND_RECT		  0x5977B0 // 9.7 || E8 ? ? ? ? F3 0F 10 44 24 ? 8D 44 24 30 83 C4 
#define FNPTR_DRAW_ROUND_RECT_COMPLEX 0x597DD0 // 9.7 || E8 ? ? ? ? 83 C4 18 5F 5E 83 C4 1C 

#define DWORD_OBJECT_MANAGER	 0x16466F8 // 9.7 || B9 ? ? ? ? E8 ? ? ? ? 8B 4F 0E 
#define DWORD_CHAT_CLIENT		 0x1685054 // 9.7 || 8B 0D ? ? ? ? 6A 00 50 E8 ? ? ? ? 33 
#define DWORD_HUD_INSTANCE		 0x168773C // 9.7 || 8B 0D ? ? ? ? FF 73 1C 8B 49 
#define DWORD_OBJECT_UNDER_MOUSE 0x22D7F4C // 9.7 || C7 05 ? ? ? ? ? ? ? ? E8 ? ? ? ? 83 C4 04 FF B4
#define DWORD_GAME_TIME			 0x2F22148 // 9.7 || F3 0F 5C 0D ? ? ? ? 0F 2F C1 F3 
#define DWORD_LOCAL_PLAYER		 0x2F26120 // 9.7 || A1 ? ? ? ? 85 C0 0F 84 ? ? ? ? 56 8B B0 
#define DWORD_RENDERER			 0x2F43C1C // 9.7 || 83 3D ? ? ? ? ? 8B F0 89
#define DWORD_ZOOM_CLASS		 0x2F3F5B8 // 9.7 || B9 ? ? ? ? 89 84 24 ? ? ? ? 8D 44 

// Finding object ptrs
// Find a Related String like "ArmorTotal" (Do not have it prefixed with m)
// GoTo the first LocalPlayer above your string.
// Look underneath that LocalPlayer for a dword ptr [eax+1288h] 1288 = ptr of ArmorTotal.
//AI Manager offsets
#define PTR_OBJECT_AI_TARGETPOS    0x10
#define PTR_OBJECT_AI_IS_MOVING    0x198
#define PTR_OBJECT_AI_IS_DASHING   0x1E8
#define PTR_OBJECT_INDEX		   0x24
#define PTR_OBJECT_NETWORK_ID	   0x110
#define PTR_OBJECT_SOURCE_INDEX    0x24C
#define PTR_OBJECT_SPELL_START_POS 0x264
#define PTR_OBJECT_SPELL_END_POS   0x270
#define PTR_OBJECT_TARGET_ID	   0x298
#define PTR_OBJECT_IS_VISIBLE	   0x39C
#define PTR_OBJECT_RECALL_STATE    0xDC8
#define PTR_OBJECT_TEAM			   0x0044
#define PTR_OBJECT_NAME			   0x0060
#define PTR_OBJECT_POS			   0x019C
#define PTR_OBJECT_CURRENT_MANA	   0x03F8
#define PTR_OBJECT_MAX_MANA		   0x0408
#define PTR_OBJECT_AMMO			   0x0458
#define PTR_OBJECT_CURRENT_HEALTH  0x0DE8
#define PTR_OBJECT_MAX_HEALTH	   0x0DF8
#define PTR_OBJECT_BONUS_ATTACK    0x11E0
#define PTR_OBJECT_ABILITY_POWER   0x11F0
#define PTR_OBJECT_BASE_ATTACK	   0x1260
#define PTR_OBJECT_CRIT_CHANCE	   0x1284
#define PTR_OBJECT_ARMOR		   0x1288
#define PTR_OBJECT_MOVE_SPEED	   0x12A0
#define PTR_OBJECT_ATTACK_RANGE	   0x12A8
#define PTR_OBJECT_MAGIC_RESIST    0x1290
#define PTR_OBJECT_DIRECTION	   0x1B54
#define PTR_OBJECT_BUFFS		   0x20F0
#define PTR_OBJECT_COMBAT_TYPE	   0x21D0
#define PTR_OBJECT_SPELLBOOK	   0x28A8
#define PTR_OBJECT_NAME_STRING	   0x3158
#define PTR_OBJECT_INVENTORY	   0x4C08
#define PTR_OBJECT_LEVEL		   0x4964