#pragma once

#define TARGET_GAMEVERSION "Version 9.8.270.9450 [PUBLIC]{WIP}"


#define FN_ISSUE_ORDER			   0x1BEE10 // 9.8 || E8 ? ? ? ? 8B 84 24 ? ? ? ? 8B CF F3 
#define FN_IS_ALIVE				   0x1E3D80 // 9.8 || E8 ? ? ? ? 84 C0 74 3B 8B 
#define FN_IS_TARGETABLE		   0x220A80 // 9.8 || E8 ? ? ? ? 84 C0 74 2E 
#define FN_IS_HERO				   0x2280E0 // 9.8 || E8 ? ? ? ? 84 C0 C7 44 24 ? ? ? ? ? 8D 44 24 30 
#define FN_IS_MINION			   0x228120 // 9.8 || E8 ? ? ? ? 83 C4 04 84 C0 74 16 8B 0F 
#define FN_IS_MISSILE			   0x228140 // 9.8 || E8 ? ? ? ? 83 C4 04 84 C0 74 1C FF
#define FN_IS_TURRET			   0x2282D0 // 9.8 || E8 ? ? ? ? 83 C4 04 84 C0 74 10 32 
//#define FN_IS_TROY				   0x217BE0 // 9.8T || E8 ? ? ? ? 8B F8 83 C4 04 85 FF 74 ?? 
#define FN_CAST_SPELL			   0x5B6AD0 // 9.8 || E8 ? ? ? ? 8B 7C 24 10 5D 
#define FN_UPDATE_CHARGEABLE_SPELL 0x5B9280 // 9.8 || E8 ? ? ? ? 5E 5F B0 01 5B 83 C4 10  
#define FN_GET_SPELL_STATE         0x5AC000 // 9.8 || 57 8B 7C 24 0C 83 7F 04
#define FN_GET_ATTACK_CAST_DELAY   0x5BD270 // 9.8 || 83 EC 0C 56 57 8B 7C 24 18 8B CF 
#define FN_GET_ATTACK_DELAY		   0x5BD350 // 9.8 || E8 ? ? ? ? D8 44 24 20 83 
#define FN_WORLD_TO_SCREEN		   0x7F2EE0 // 9.8 || E8 ? ? ? ? F3 0F 10 44 24 ? 83 C4 10 F3 0F 5C
#define FNPTR_DRAW_CIRCLE		   0x5AE700 // 9.8 || E8 ? ? ? ? 83 C4 1C 8B 44 24 18 

#define DWORD_OBJECT_MANAGER	 0x16656F8 // 9.8 || B9 ? ? ? ? E8 ? ? ? ? 8B C8 8B 10 8B 82 
#define DWORD_CHAT_CLIENT		 0x16A42E0 // 9.8 || 8B 0D ? ? ? ? 6A 00 50 E8 ? ? ? ? 33 
#define DWORD_HUD_INSTANCE		 0x16A6AA4 // 9.8 || 8B 35 ? ? ? ? FF 70 1C 
#define DWORD_OBJECT_UNDER_MOUSE 0x2D4725C // 9.8 || C7 05 ? ? ? ? ? ? ? ? E8 ? ? ? ? 83 C4 04 FF B4

#define DWORD_GAME_TIME			 0x2F41498 // 9.8 || F3 0F 5C 0D ? ? ? ? 0F 2F C1 F3 
#define DWORD_LOCAL_PLAYER		 0x2F457FC // 9.8 || A1 ? ? ? ? 85 C0 0F 84 ? ? ? ? 56 8B B0 
#define DWORD_RENDERER			 0x2F62FF4 // 9.8 || 8B 15 ? ? ? ? 83 EC 08 F3 
#define DWORD_ZOOM_CLASS		 0x2F5E9A0 // 9.8 || B9 ? ? ? ? 89 84 24 ? ? ? ? 8D 44 

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
#define O_INDEX			0x1C	// 28
#define O_TEAM			0x0044	// 68
#define O_NAME			0x0060	// 96
#define O_NETWORK_ID	0x110	// 272
#define O_POS			0x019C	// 412
#define O_RECALL_NAME	0xDB8	// 3512
#define O_RECALL_STATE	0xDC8	// 3528
#define O_MANA			0x03F8	// 1016
#define O_MAX_MANA		0x0408	// 1032
#define O_HEALTH		0x0DE8	// 3560
#define O_MAX_HEALTH	0x0DF8	// 3576
#define O_BONUS_AD		0x11E0	// 4576
#define O_BONUS_AP		0x11F0	// 4592
#define O_BASE_AD	    0x1260	// 4704
#define O_CRIT_RATE		0x1284  // 4740
#define O_ARMOR			0x1288	// 4744
#define O_MAGIC_RESIST	0x1290	// 4752
#define O_MOVE_SPEED	0x12A0	// 4768
#define O_ATTACK_RANGE	0x12A8	// 4776
#define O_BUFF_MGR		0x20F0	// 8432
#define O_SPELLBOOK		0x28A8	// 10480
#define O_ACTOR_NAME	0x3158	// 12632
#define O_LEVEL			0x4964	// 18788

// Buff Offesets
#define O_BUFFMGR_BUFFNAME 0x08
#define O_BUFFMGR_STARTTIME 0xC
#define O_BUFFMGR_ENDTIME 0x10
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

#pragma region Old

#pragma region 9.7

//#define TARGET_GAMEVERSION "Version 9.7.269.6900 [PUBLIC]"
//
//#define FN_GET_BASIC_ATTACK		   0x1B39C0 // 9.7 || E8 ? ? ? ? 8B 8B ? ? ? ? 8B E8 8B 
//#define FN_ISSUE_ORDER			   0x1BE660 // 9.7 || E8 ? ? ? ? 8B 84 24 ? ? ? ? 8B CF F3 
//#define FN_IS_ALIVE				   0x1E2C30 // 9.7 || E8 ? ? ? ? 84 C0 74 3B 8B 
//#define FN_IS_DRAGON		       0x2150C0 // 9.7 || E8 ? ? ? ? 33 DB 84 C0 0F 95 C3 8D 1C 5D ? ? ? ? E9 
//#define FN_IS_BARON			       0x215C70 // 9.7 || E8 ? ? ? ? 84 C0 74 0A BB 
//#define FN_IS_TARGETABLE		   0x21FB80 // 9.7 || E8 ? ? ? ? 84 C0 74 2E 
//#define FN_IS_INHIB				   0x226D40 // 9.7 || E8 ? ? ? ? 83 C4 04 84 C0 75 0B 6A 
//#define FN_IS_HERO				   0x226EC0 // 9.7 || E8 ? ? ? ? 84 C0 C7 44 24 ? ? ? ? ? 8D 44 24 30 
//#define FN_IS_MINION			   0x226F00 // 9.7 || E8 ? ? ? ? 83 C4 04 84 C0 74 16 8B 0F 
//#define FN_IS_MISSILE			   0x226F20 // 9.7 || E8 ? ? ? ? 83 C4 04 84 C0 74 1C FF
//#define FN_IS_TURRET			   0x2270B0 // 9.7 || E8 ? ? ? ? 83 C4 04 84 C0 74 10 32 
//#define FN_IS_NEXUS				   0x227130 // 9.7 || E8 ? ? ? ? 83 C4 04 85 C0 74 13 F3 
//#define FN_IS_TROY				   0x2271A0 // 9.7 || E8 ? ? ? ? 8B F8 83 C4 04 85 FF 74 58 
//#define FN_DRAW_FLOAT_TEXT		   0x248500 // 9.7 || E8 ? ? ? ? 8B CB C7 00 ? ? ? ? 8D 44 24 2C 
//#define FN_GET_CHARACTER_INFO      0x29E850 // 9.7 || E8 ? ? ? ? 83 C6 24 8B
//#define FN_CAST_SPELL			   0x59F3B0 // 9.7 || E8 ? ? ? ? 8B 7C 24 10 5D 
//#define FN_UPDATE_CHARGEABLE_SPELL 0x5A1B10 // 9.7 || E8 ? ? ? ? 5E 5F B0 01 5B 83 C4 10  
//#define FN_GET_SPELL_STATE         0x5A4EE0 // 9.7 || 57 8B 7C 24 0C 83 7F 04
//#define FN_GET_ATTACK_CAST_DELAY   0x5A5FE0 // 9.7 || E8 ? ? ? ? D9 9D ? ? ? ? 53 
//#define FN_GET_ATTACK_DELAY		   0x5A60C0 // 9.7 || E8 ? ? ? ? D8 44 24 20 83 
//#define FN_PRINT_CHAT			   0x5D7C10 // 9.7 || E8 ? ? ? ? 33 C0 5F C2 
//#define FN_IS_WALL				   0x748840 // 9.7 || E8 ? ? ? ? 83 C4 08 84 C0 75 46 33 
//#define FN_WORLD_TO_SCREEN		   0x7D59E0 // 9.7 || E8 ? ? ? ? F3 0F 10 44 24 ? 83 C4 10 F3 0F 5C
//
//#define FNPTR_DRAW_CIRCLE			  0x596D40 // 9.7 || E8 ? ? ? ? 83 C4 1C 8B 44 24 18 
//#define FNPTR_DRAW_ELLIPSE			  0x5973E0 // 9.7 || E8 ? ? ? ? 83 C4 14 83 7E 10 00 8D 
//#define FNPTR_DRAW_PATH				  0x597670 // 9.7 || E8 ? ? ? ? 83 C4 0C 8B 0D ? ? ? ? 8D 
//#define FNPTR_DRAW_RECT				  0x5976C0 // 9.7 || E8 ? ? ? ? 83 C4 14 E9 ? ? ? ? F3 0F 7E 
//#define FNPTR_DRAW_ROUND_RECT		  0x5977B0 // 9.7 || E8 ? ? ? ? F3 0F 10 44 24 ? 8D 44 24 30 83 C4 
//#define FNPTR_DRAW_ROUND_RECT_COMPLEX 0x597DD0 // 9.7 || E8 ? ? ? ? 83 C4 18 5F 5E 83 C4 1C 
//
//#define DWORD_OBJECT_MANAGER	 0x16466F8 // 9.7 || B9 ? ? ? ? E8 ? ? ? ? 8B 4F 0E 
//#define DWORD_CHAT_CLIENT		 0x1685054 // 9.7 || 8B 0D ? ? ? ? 6A 00 50 E8 ? ? ? ? 33 
//#define DWORD_HUD_INSTANCE		 0x168773C // 9.7 || 8B 0D ? ? ? ? FF 73 1C 8B 49 
//#define DWORD_OBJECT_UNDER_MOUSE 0x22D7F4C // 9.7 || C7 05 ? ? ? ? ? ? ? ? E8 ? ? ? ? 83 C4 04 FF B4
//#define DWORD_GAME_TIME			 0x2F22148 // 9.7 || F3 0F 5C 0D ? ? ? ? 0F 2F C1 F3 
//#define DWORD_LOCAL_PLAYER		 0x2F26120 // 9.7 || A1 ? ? ? ? 85 C0 0F 84 ? ? ? ? 56 8B B0 
//#define DWORD_RENDERER			 0x2F43C1C // 9.7 || 83 3D ? ? ? ? ? 8B F0 89
//#define DWORD_ZOOM_CLASS		 0x2F3F5B8 // 9.7 || B9 ? ? ? ? 89 84 24 ? ? ? ? 8D 44 

#pragma endregion


//#define PTR_OBJECT_INVENTORY	   0x4C08
//#define PTR_OBJECT_AMMO			   0x0458
//#define PTR_OBJECT_DIRECTION	   0x1B54
//#define PTR_OBJECT_BUFFS		   0x20F0
//#define PTR_OBJECT_COMBAT_TYPE	   0x21D0
//#define PTR_OBJECT_SOURCE_INDEX    0x24C
//#define PTR_OBJECT_SPELL_START_POS 0x264
//#define PTR_OBJECT_SPELL_END_POS   0x270
//#define PTR_OBJECT_TARGET_INDEX	   0x298
//#define PTR_OBJECT_IS_VISIBLE	   0x39C

#pragma endregion

#pragma region Chalkboard


/*
	["LocalPlayer", "8B ? ? ? ? ? 83 F8 01 8A 5C 24 10 0F 94 C7 85 C9 74 28", 1],
	["ObjManager", "B9 ? ? ? ? E8 ? ? ? ? 8B F8 85 FF 75 E3", 1],
	["ChatClientPtr", "B9 ? ? ? ? 50 E8 ? ? ? ? 8B 0D ? ? ? ? 6A 03", 1],
	["GameTime", "F3 0F 5C 0D ? ? ? ? 0F 2F C1", 1],
	["Renderer", "8B 0D ? ? ? ? 85 C9 74 14 8B 46 28", 1],
	["ZoomBase", "A3 ? ? ? ? 8D 4C 24 20", 0],# "Globals/CameraConfig_CLASSIC"
	["UnderMouseObj", "C7 05 ? ? ? ? ? ? ? ? E8 ? ? ? ? 83 C4 04 FF B4 24 ? ? ? ?", 0],
	["NetClient", "C7 05 ? ? ? ? ? ? ? ? 85 C9 74 05", 0],
	["MissionInfo", "89 35 ? ? ? ? C7 06 ? ? ? ? C7 46 ? ? ? ? ? C7 46 ? ? ? ? ? C7 46 ? ? ? ? ?", 0],##might be incorrect use TM to get correct
	["GameState", "A1 ? ? ? ? 8B 70 08 E8 ? ? ? ? ", 1],# "Demacia event failed."; "game.gameState"
	["Version", "68 ? ? ? ? E8 ? ? ? ? 83 C4 20 8D 4C 24 04", 0],# "Version %s (%s/%s) [%s] <%s>%s"
	["MousePointer", "8B 35 ? ? ? ? FF 75 08", 1],# use fnIssueOrder
	#Textures
	["TexturePack", "A1 ? ? ? ? 85 C0 74 13 50 E8 ? ? ? ? 83 C4 04 C7 05 ? ? ? ? ? ? ? ? 8D 04 24", 1]

	namespace LoLCore
{
	class CBaseObjectHandle;
	class CSpellCastInfo;
	class CBaseObject;
}

typedef float(__fastcall* fnGetBoundingRadius)(LoLCore::CBaseObject* thisPtr, double* result);

typedef int(__thiscall* fnGetHPBarV3D)(LoLCore::CBaseObject* pObj, Vector3D* pVec);

typedef bool(__cdecl* fnWorld2Screen)(Vector3D* vIn, Vector3D* vOut);
typedef int(__cdecl* fnScreen2World)(float a1, float a2, Vector3D* vIn, Vector3D* vOut);

typedef bool(__thiscall* fnWorld2Map)(void* thisPtr, Vector3D* vIn, float *fXOut, float *fYOut);
typedef int(__thiscall* fnMap2World)(void* thisPtr, unsigned int a2, int a3, int a4, int *a5);
typedef void*(__cdecl* fnGetTacticalMap)();
typedef char(__stdcall* fnUseObject)(LoLCore::CBaseObject* pObj);

typedef bool(__cdecl* fnIsWall)(Vector3D* position, unsigned __int16 uk);

typedef cTexturePTR(__thiscall* fnLoadTexture)(DWORD *rendererPtr, std::string* strTextureFileName, DWORD* dwSharedMemory, int a4, int a5, int a6);

typedef char(__thiscall* fnPrintChat)(DWORD* ChatClientPtr, const char* cMessage, unsigned int iColor);

typedef int(__thiscall* fnSendChat)(DWORD* ChatClientPtr, char* a2);

typedef void(__thiscall* fnIssueOrder) (LoLCore::CBaseObject* thisPtr, DWORD dwOrder, Vector3D* TargetPos, LoLCore::CBaseObject* TargetPtr, bool attackLoc, bool isPassive, DWORD isNetworked);

typedef char(__thiscall* fnDrawTurretRange) (LoLCore::CBaseObject* objPtr);

typedef void(__thiscall* fnDrawHUD) (int a1);

typedef int(__thiscall* fnOnAFK)(BYTE* thisPtr);

typedef int(__thiscall* fnLevelUp)(void* thisPtr, float a2, signed int nLevel, int a4);

typedef int(__thiscall* fnOnTeleport) (LoLCore::CBaseObject* thisPtr, std::string* a1, std::string* a2);

typedef char(__thiscall* fnOnSurrenderVote)(void* thisPtr, int nNetworkID, int nSurrenderType, char a4, char a5);

typedef int (__thiscall* fnAssignNetworkID)(LoLCore::CBaseObject* thisPtr, int nNetworkID);
typedef int(__thiscall* fnDeleteObject)(void* thisPtr, LoLCore::CBaseObject* pObject);

typedef char(__thiscall* fnOnProcessSpellW)(void* spellbookPtr, LoLCore::CSpellCastInfo* pSpellInfo);
typedef void(__thiscall* fnUpdateChargeableSpell)(void* spellbookPtr, SpellInfo* pSpellInfo, signed int spell_slot, Vector3D* vPos, bool ReleaseCast);

typedef int(__cdecl* fnOnLoadChampion)(const char *player_name, const char *champion_name, unsigned int skin_id, int a4, int a5, int a6, int a7, int a8, int a9);

typedef void(__thiscall* fnCastSpell)(void* spellbook, SpellInfo* a2, signed int spell_slot, Vector3D* target_position, Vector3D* startPos, int target_network_id);
typedef signed int(__thiscall* fnGetSpellState)(void *spellbook, signed int spellslot, DWORD *a3);
typedef float(__cdecl* fnGetAttackCastDelay)(LoLCore::CBaseObject* pObj, int index);
typedef float(__cdecl* fnGetAttackDelay)(LoLCore::CBaseObject* pObj, int index);
typedef char(__stdcall* fnDoEmote)(unsigned __int8 nId);
typedef void(__cdecl* fnDrawCircle) (Vector3D* a1, float a2, D3DCOLOR* a3, int a4, float a5, int a6, float a7);

typedef void(__cdecl* fnDrawCircleIndicator) (D3DCOLOR* a1, Vector3D* a2, float a3, cTexturePTR a4, float a5, float a6, int a7);


typedef uint8_t(__stdcall* fnOnProcessPacket)(GameNetPacket* packetPtr);

typedef int(__cdecl* fnOnProcessSpell)(void* spellbookPtr, signed int spellslot, int a3, SpellData* pSpellData, char IsBasicAttack, char a6);
typedef char(__thiscall* fnEventHandler) (void* thisPtr, event_t * pEvent, IEventArgs& pArgs);
typedef int(__thiscall* fnPlaySound)(void *thisPtr, int a2, int a3, std::string const & soundFile, int a5, int a6, float fVolume, int IEventFinishedCallback);
typedef int(__thiscall* fnSetPath)(void* thisPtr, int a2);
typedef int(__cdecl* fnApplySkin) (int a1, const char *a2, const char *a3, int a4, int a5, int a6, int a7, int a8, int a9);
typedef int(__cdecl* fnFloatingText) (int a1, int a2, int a3, int a4, char a5);
//D3D
typedef HRESULT (WINAPI* fnD3DPresent)(LPDIRECT3DDEVICE9 pDevice, CONST RECT *pSourceRect, CONST RECT *pDestRect, HWND hDestWindowOverride, CONST RGNDATA *pDR);
typedef HRESULT (WINAPI* fnD3DBeginScene)(LPDIRECT3DDEVICE9 pDevice);
typedef HRESULT (WINAPI* fnD3DEndScene)(LPDIRECT3DDEVICE9 pDevice);
typedef HRESULT (WINAPI* fnD3DReset)(LPDIRECT3DDEVICE9 pDevice, D3DPRESENT_PARAMETERS* Para1);

using System;

namespace LoLBinaryLoader
{
	class Program
	{
		static void Main(string[] args)
		{
			Console.WriteLine("Starting Load!");
			int counter = 0;
			string line;
			const string strBaseURL = "http://l3cdn.riotgames.com/releases/live/projects/lol_game_client/releases/";
			const string strListFileName = @"releaselisting_EUW";
			System.Net.WebClient wc = new System.Net.WebClient();
			try
			{
				wc.DownloadFile(new System.Uri(strBaseURL + strListFileName), strListFileName);
			}
			catch (System.Net.WebException ex)
			{
				System.Console.WriteLine("ListNotFound:" + strBaseURL + strListFileName);
				return;
			}
			System.IO.StreamReader file = new System.IO.StreamReader(strListFileName);
			while ((line = file.ReadLine()) != null)
			{
				if (line == "")
					continue;
				string strUrl = strBaseURL + line + "/files/League of Legends.exe.compressed";
				string strFileName = @"Target\\" + line + "_League of Legends.exe.compressed";
				System.Console.WriteLine("Downloading file:" + strUrl + "->" + strFileName);
				try
				{
					wc.DownloadFile(new System.Uri(strUrl), strFileName);
				} catch(System.Net.WebException ex)
				{
					System.Console.WriteLine("No File In Release:" + strUrl);
					continue;
				}

				if(!System.IO.File.Exists(strFileName))
				{
					System.Console.WriteLine("FileNotFound:" + strFileName);
					continue;
				}
				byte[] fileInBytes = System.IO.File.ReadAllBytes(strFileName);
				if(fileInBytes[0] != 0x78 || fileInBytes[1] != 0x9C)
				{
					System.Console.WriteLine("File:" + strFileName+ "-HeaderInvalid:" + fileInBytes[0].ToString() + "," + fileInBytes[1].ToString());
					continue;
				}
				System.IO.Stream byteStreamOriginal = new System.IO.MemoryStream(fileInBytes, 2, fileInBytes.Length - 2);
				using (System.IO.Compression.DeflateStream decompressionStream = new System.IO.Compression.DeflateStream(byteStreamOriginal, System.IO.Compression.CompressionMode.Decompress))
				{
					string currentFileName = strFileName;
					string newFileName = currentFileName.Remove(currentFileName.Length - ".compressed".Length);
					using (System.IO.FileStream decompressedFileStream = System.IO.File.Create(newFileName))
					{
						decompressionStream.CopyTo(decompressedFileStream);
						Console.WriteLine("Decompressed: {0}", strFileName);
					}
				}
				System.IO.File.Delete(strFileName);//Delete Compressed File!
				counter++;
			}
			file.Close();
			System.Console.WriteLine("There were {0} Files downloaded.", counter);
		}
	}
}

class SpellData
{
public:
	char* GetMissileName()
	{
		return GetStr((DWORD)this + 0x0058);
	}
	char* GetSpellName()
	{
		return GetStr((DWORD)this + 0x007C);
	}
	char* GetDescription()
	{
		return GetStr((DWORD)this + 0x0088);
	}
	float GetEffectAmount()
	{
		return *(float*)((DWORD)this + 0xD0);
	}
	float GetIncreaseDamage()
	{
		return *(float*)((DWORD)this + 0xEC);
	}
	float GetSpellDuration()
	{
		return *(float*)((DWORD)this + 0x108);
	}

	float GetRootDuration()
	{
		return *(float*)((DWORD)this + 0x15C);
	}
	float GetIncreaseDamageBonus()
	{
		return *(float*)((DWORD)this + 0x178);
	}
	float GetCoefficient()
	{
		return *(float*)((DWORD)this + 0x200);
	}
	float GetCoefficient2()
	{
		return *(float*)((DWORD)this + 0x204);
	}
	int GetMaxHighlightTargets()
	{
		return *(int*)((DWORD)this + 0x208);
	}
	float GetCooldownTime()
	{
		return *(float*)((DWORD)this + 0x280);
	}

	float GetDelayCastOffsetPercent()
	{
		return *(float*)((DWORD)this + 0x29C);
	}

	float GetDelayTotalTimePercent()
	{
		return *(float*)((DWORD)this + 0x2A0);
	}

	int GetMaxAmmo()
	{
		return *(int*)((DWORD)this + 0x31C);
	}
	int GetAmmoUsed()
	{
		return *(int*)((DWORD)this + 0x338);
	}
	float GetAmmoRechargeTime()
	{
		return *(float*)((DWORD)this + 0x354);
	}

	float GetMissileSpeed() {
		return *(float*)((DWORD)this + 0x450);
	}
};

class SpellInfo
{
public:
	SpellData* GetSpellData()
	{
		return (SpellData*)((DWORD)this + 0x38);
	}
};

class SpellSlot {
public:
	int GetLevel()
	{
		return *(int*)((DWORD)this + 0x20);
	}

	float GetTime()
	{
		return *(float*)((DWORD)this + 0x28);
	}

	float GetCD()
	{
		return *(float*)((DWORD)this + 0x18);
	}

	bool IsReady()
	{
		if (GetSpellInfo()->GetSpellData()->GetCooldownTime() == 0) return true;
		return false;
	}

	SpellInfo* GetSpellInfo()
	{
		return (SpellInfo*)((DWORD)this + 0x124);
	}
};

class SpellBook
{
public:

	SpellSlot* GetSpellSlotByID(int ID) {
		return *(SpellSlot**)((DWORD)this + 0x508 + (0x4 * ID));
	}
};

#define InventoryPtr 0x4BE0
*/

// 9.8
//#define oBuyItem 0x1ABDF0
//DWORD* pPlayerShop = (DWORD*) ((DWORD) pLocalPlayer + 0x4998)
//typedef char(__thiscall * _BuyItem)(DWORD * pPlayerShop, int ItemID, int minusone);

#pragma endregion
