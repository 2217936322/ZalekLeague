#include "LFunctions.h"
#include "detours.h"
#pragma comment(lib, "detours.lib")

#include <d3d9.h>
#include "Engine.h"
#include "Menu.h"
#pragma once

#define DEVELOPMENT_MODE true

bool bUninitialized = true;
LFunctions Functions;
GameObjectManager* GObjectManager;

int Main() {
	if(ME) {
		if(DEVELOPMENT_MODE) {
			DevelopmentGUI();
		}

		if(GetAsyncKeyState(VK_INSERT) & 1)
			bDrawGUI = !bDrawGUI;

		Vector vecWorld = Vector(ME->GetPos().X, ME->GetPos().Y, ME->GetPos().Z); // &vecIn->SwitchYZ();
		Vector vecScreen = Vector();
		bool w2sResult = Functions.WorldToScreen(&vecWorld, &vecScreen);
		ImVec2 testVec = ImVec2(vecScreen.X, vecScreen.Y);
		Overlay(testVec, "Very Useful Overlay");

		return 1;
	} else {
		DarkOverlay(ImGui::GetMousePos(), "ZalekLeague is up to date for 9.7.269.6900[PUBLIC]");
		return 0;
	}
}

typedef HRESULT(WINAPI* Prototype_Present)(LPDIRECT3DDEVICE9, CONST RECT*, CONST RECT*, HWND, CONST RGNDATA*);
Prototype_Present Original_Present;

LRESULT __stdcall WndProc(const HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {

	if(ImGui_ImplWin32_WndProcHandler(hWnd, uMsg, wParam, lParam))
		return true;

	return CallWindowProc(gWNDPROC, hWnd, uMsg, wParam, lParam);
}

HRESULT WINAPI Hooked_Present(LPDIRECT3DDEVICE9  Device, CONST RECT* pSrcRect, CONST RECT* pDestRect, HWND hDestWindow, CONST RGNDATA* pDirtyRegion) {
	if(bUninitialized) {
		HWND hwnd = FindWindow(NULL, "League of Legends (TM) Client");
		gWNDPROC = (WNDPROC)
			SetWindowLongPtr(hwnd, GWL_WNDPROC, (LONG_PTR) WndProc);
		InitializeImGuiContext(hwnd, Device);
		bUninitialized = false;
	}

	Main();

	// Shutdown Scripts on end key press.
	if(GetAsyncKeyState(VK_END) & 1) {
		ImGui_ImplDX9_Shutdown();
		ImGui_ImplWin32_Shutdown();
		ImGui::DestroyContext();
		DetourRemove((PBYTE) Original_Present, (PBYTE) Hooked_Present);
	}
	return Original_Present(Device, pSrcRect, pDestRect, hDestWindow, pDirtyRegion);
}

DWORD FindDevice(DWORD Len) {
	DWORD dwObjBase = 0;

	dwObjBase = (DWORD) LoadLibrary("d3d9.dll");
	while(dwObjBase++ < dwObjBase + Len) {
		if((*(WORD*) (dwObjBase + 0x00)) == 0x06C7 && (*(WORD*) (dwObjBase + 0x06)) == 0x8689 && (*(WORD*) (dwObjBase + 0x0C)) == 0x8689) {
			dwObjBase += 2;
			break;
		}
	}
	return (dwObjBase);
}

DWORD GetDeviceAddress(int VTableIndex) {
	PDWORD VTable;
	*(DWORD*) & VTable = *(DWORD*) FindDevice(0x128000);
	return VTable[VTableIndex];
}

void __stdcall Start() {
	//Beep(1000, 100);
	//while(Engine::GetGameTime() < 1.0f || !ME) {
	//	Sleep(1);
	//}

	GObjectManager = (GameObjectManager*) (baseAddr + DWORD_OBJECT_MANAGER);
	Functions.CastSpell = (Typedefs::fnCastSpell)((DWORD) GetModuleHandle(NULL) + FN_CAST_SPELL);
	Functions.DrawCircle = (Typedefs::fnDrawCircle)((DWORD) GetModuleHandle(NULL) + FNPTR_DRAW_CIRCLE);
	Functions.GetAttackCastDelay = (Typedefs::fnGetAttackCastDelay)((DWORD) GetModuleHandle(NULL) + FN_GET_ATTACK_CAST_DELAY);
	Functions.GetAttackDelay = (Typedefs::fnGetAttackDelay)((DWORD) GetModuleHandle(NULL) + FN_GET_ATTACK_DELAY);
	Functions.IsAlive = (Typedefs::fnIsAlive)(baseAddr + FN_IS_ALIVE);
	//Functions.IsBaron = (Typedefs::fnIsBaron)(baseAddr + FN_IS_BARON);
	//Functions.IsDragon = (Typedefs::fnIsDragon)(baseAddr + FN_IS_DRAGON);
	Functions.IsHero = (Typedefs::fnIsHero)(baseAddr + FN_IS_HERO);
	Functions.IsInhibitor = (Typedefs::fnIsInhibitor)(baseAddr + FN_IS_INHIB);
	Functions.IsMinion = (Typedefs::fnIsMinion)(baseAddr + FN_IS_MINION);
	Functions.IsMissile = (Typedefs::fnIsMissile)(baseAddr + FN_IS_MISSILE);
	Functions.IsNexus = (Typedefs::fnIsNexus)(baseAddr + FN_IS_NEXUS);
	Functions.IssueOrder = (Typedefs::fnIssueOrder)((DWORD) GetModuleHandle(NULL) + FN_ISSUE_ORDER);
	Functions.IsTargetable = (Typedefs::fnIsTargetable)(baseAddr + FN_IS_TARGETABLE);
	Functions.IsTroyEnt = (Typedefs::fnIsTroyEnt)(baseAddr + FN_IS_TROY);
	Functions.IsTurret = (Typedefs::fnIsTurret)(baseAddr + FN_IS_TURRET);
	Functions.PrintChat = (Typedefs::fnPrintChat)(baseAddr + FN_PRINT_CHAT);

	Functions.WorldToScreen = (Typedefs::fnWorldToScreen)(baseAddr + FN_WORLD_TO_SCREEN);

	Original_Present = (Prototype_Present) DetourFunction((PBYTE) GetDeviceAddress(17), (PBYTE) Hooked_Present);
}

BOOL APIENTRY DllMain(HMODULE hModule,
	DWORD ul_reason_for_call,
	LPVOID lpReserved) {

	if(ul_reason_for_call == DLL_PROCESS_ATTACH) {
		CreateThread(0, 0, (LPTHREAD_START_ROUTINE) Start, 0, 0, 0);
		return TRUE;
	}

	else if(ul_reason_for_call == DLL_PROCESS_DETACH) {
		return TRUE;
	}
	return FALSE;
}

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