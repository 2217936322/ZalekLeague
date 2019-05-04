#pragma once

/*
	9.9 Offsets
	++ Functions
	#define fnBuyItem 0x1ABE50
	#define fnIssueOrder 0x1BF5B0
	#define fnGetBasicAttack 0x1B4690
	#define fnGetAttackCastDelay 0x5A40C0
	#define fnGetAttackDelay 0x5A41A0
	#define oDrawCircle 0x595ED0
	#define fnCastSpell 0x59DC80
	#define fnWorld2Screen 0x7DA1E0
	#define fnGetSpellState 0x5923E0
	#define fnIsAlive 0x1E3A20
	#define fnIsTurret 0x227F50
	#define fnIsNexus 0x227FD0
	#define fnIsDragon 0x215DE0
	#define fnIsBaron 0x216990
	#define fnIsInhib 0x227BE0
	#define fnIsHero 0x227D60
	#define fnIsMinion 0x227DA0
	#define fnIsMissile 0x227DC0
	#define fnPrintChat 0x5D7A20
	#define fnGetPing 0x3598A0

	++ Offsets
	#define oChatClientPtr 0x1689AB8
	#define oHudInstance 0x168C1A4
	#define oNetClient 0x2F312B0
	#define oObjManager 0x164C528
	#define oGameTime 0x2F26BA8
	#define oRenderer 0x2F49E14
	#define oObjLevel 0x4964
	#define oObjMaxMana 0x408
	#define oObjMana 0x3F8
	#define oObjHealth 0xDE8
	#define ooObjMaxHP 0xDF8


	BuyItem((DWORD)((DWORD)PLAYER + (DWORD)0x4998), 3135, -1); // 3135 = Void Staff
*/

//#define TARGET_GAMEVERSION "Version 9.8.270.9450 [PUBLIC]{WIP}"


#define FN_CAST_SPELL			   0x59DC80 // 9.9 || E8 ? ? ? ? 8B 7C 24 10 5D
#define FN_DRAW_CIRCLE			   0x595ED0 // 9.9 || E8 ? ? ? ? 83 C4 1C 8B 44 24 18 
#define FN_GET_ATTACK_CAST_DELAY   0x5A40C0 // 9.9 || E8 ? ? ? ? D9 9E ? ? ? ? 57
#define FN_GET_ATTACK_DELAY		   0x5A41A0 // 9.9 || E8 ? ? ? ? 8B 44 24 30 83 C4 0C 8B CE 66
#define FN_GET_SPELL_STATE         0x5937E0 // 9.9 || E8 ? ? ? ? 8B F0 8B 0E 85 C9 74 03 FF 41 18 8B 4F 7C || 57 8B 7C 24 0C 83 7F 04
#define FN_ISSUE_ORDER			   0x1BF5B0 // 9.9 || E8 ? ? ? ? 8B 84 24 ? ? ? ? 8B CF F3
#define FN_IS_ALIVE				   0x1E3A20 // 9.9 || E8 ? ? ? ? 84 C0 74 3B 8B
#define FN_IS_HERO				   0x227D60 // 9.9 || E8 ? ? ? ? 84 C0 C7 44 24 ? ? ? ? ? 8D 44 24 30
#define FN_IS_MINION			   0x227DA0 // 9.9 || E8 ? ? ? ? 83 C4 04 84 C0 74 16 8B 0F
#define FN_IS_MISSILE			   0x227DC0 // 9.9 || E8 ? ? ? ? 83 C4 04 84 C0 74 1C FF
#define FN_IS_TARGETABLE		   0x180850 // 9.9 || E8 ? ? ? ? 84 C0 74 2E 68 ? ? ? ? 8B 
#define FN_IS_TROY				   0x2178F0 // 9.9 || E8 ? ? ? ? 8B F8 83 C4 04 85 FF 0F 84 ? ? ? ? 39 
#define FN_IS_TURRET			   0x227F50 // 9.9 || E8 ? ? ? ? 83 C4 04 84 C0 74 10 32
#define FN_UPDATE_CHARGEABLE_SPELL 0x5A0470 // 9.9 || E8 ? ? ? ? 5E 5F B0 01 5B 83 C4 10
#define FN_WORLD_TO_SCREEN		   0x7DA1E0 // 9.9 || E8 ? ? ? ? F3 0F 10 44 24 ? 83 C4 10 F3 0F 5C

#define CHAT_CLIENT				0x1689AB8 // 9.9 || 8B 0D ? ? ? ? 6A 00 50 E8 ? ? ? ? 33
#define GAME_TIME				0x2F26BA8 // 9.9 || F3 0F 5C 0D ? ? ? ? 0F 2F C1 F3
#define HUD_INSTANCE			0x168C1A4 // 9.9 || A1 ? ? ? ? F3 0F 10 44 24 ? F3 0F 11 
#define LOCAL_PLAYER			0x2F2AFA4 // 9.9 || A1 ? ? ? ? 85 C0 0F 84 ? ? ? ? 56 8B B0
#define OBJECT_MANAGER			0x164C528 // 9.9 || B9 ? ? ? ? E8 ? ? ? ? 8B C8 8B 10 8B 82
#define OBJECT_UNDER_MOUSE		0x22DCA04 // 9.9 || C7 05 ? ? ? ? ? ? ? ? E8 ? ? ? ? 83 C4 04 FF B4
#define RENDERER				0x2F49E14 // 9.9 || 8B 15 ? ? ? ? 83 EC 08 F3
#define ZOOM_CLASS				0x2F457C8 // 9.9 || B9 ? ? ? ? 89 84 24 ? ? ? ? 8D 44 


//AI Manager offsets
#define PTR_OBJECT_AI_WAYPOINT    0x10
#define PTR_OBJECT_AI_IS_MOVING    0x198
#define PTR_OBJECT_AI_NAV_START	   0x1BC
#define PTR_OBJECT_AI_NAV_END	   0x1C0
#define PTR_OBJECT_AI_HAS_NAV_PATH 0x19C 
#define PTR_OBJECT_AI_CURRENT_POS  0x2BC 
#define PTR_OBJECT_AI_VELOCITY	   0x2C8
#define PTR_OBJECT_AI_IS_DASHING   0x394

// Game Object Offsets
#define O_INDEX				0x1C	// 28
#define O_TEAM				0x0044	// 68
#define O_CONTROLLER_NAME	0x0060	// 96
#define O_NETWORK_ID		0x110	// 272
#define O_POS				0x019C	// 412
#define O_RECALL_NAME		0xDB8	// 3512
#define O_RECALL_STATE		0xDC8	// 3528
#define O_MANA				0x03F8	// 1016
#define O_MAX_MANA			0x0408	// 1032
#define O_HEALTH			0x0DE8	// 3560
#define O_MAX_HEALTH		0x0DF8	// 3576
#define O_BONUS_AD			0x11E0	// 4576
#define O_BONUS_AP			0x11F0	// 4592
#define O_BASE_AD			0x1260	// 4704
#define O_CRIT_RATE			0x1284  // 4740
#define O_ARMOR				0x1288	// 4744
#define O_MAGIC_RESIST		0x1290	// 4752
#define O_MOVE_SPEED		0x12A0	// 4768
#define O_ATTACK_RANGE		0x12A8	// 4776
#define O_BUFF_MGR			0x20F0	// 8432
#define O_SPELLBOOK			0x28A8	// 10480
#define O_ACTOR_NAME		0x3158	// 12632
#define O_LEVEL				0x4964	// 18788

// Buff Offsets
#define O_BUFF_START_TIME	0x0C // 12
#define O_BUFF_END_TIME		0x10 // 16
#define O_BUFF_NAME			0x9C // 156

#define O_BUFFMGR_BUFFNAME 0x08
#define O_BUFFMGR_flBUFFCOUNT 0x2C
#define O_BUFFMGR_iBUFFCOUNT 0x70


// SpellSlot Offsets
#define O_SS_RANK		0x20	// 32
#define O_SS_TIME_USED	0x28	// 40
#define O_SS_CHARGE		0x58	// 88
#define O_SS_NEXT_CHARGE 0x60	// 96
#define O_SS_INFO		0x134	// 308

// SpellInfo Offsets
#define SI_NAME			0x18 // 24