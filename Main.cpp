/************************************************************************/
/*						Main file for ZalekLeague						*/
/************************************************************************/

#include "LFunctions.h"
#include "detours.h"
#pragma comment(lib, "detours.lib")

#include "ActorManager.h"
#include "Device.h"
#include "GUI.h"
#pragma once

bool bInitPending = true;
LActorManager* ActorManager;
LFunctions Functions;

/** Prototype_Present
 * Prototype for our Handle Result
 * A 32-bit value that is used to describe an error or warning.
 * https://docs.microsoft.com/en-us/office/client-developer/outlook/mapi/hresult
 */
typedef HRESULT(WINAPI* Prototype_Present)(LPDIRECT3DDEVICE9, CONST RECT*, CONST RECT*, HWND, CONST RGNDATA*);


/** Original_Present
 * Prototype_Present for our Original Handle
 */
Prototype_Present Original_Present;


/** Hooked_Present
 * Main for the Hooked DLL.
 */
HRESULT WINAPI Hooked_Present(LPDIRECT3DDEVICE9  Device, CONST RECT* pSrcRect, CONST RECT* pDestRect, HWND hDestWindow, CONST RGNDATA* pDirtyRegion) {
	if(bInitPending) {
		GUI::CreateContext(Device);
		bInitPending = false;
	}

	GUI::Draw();
	GUI::Poll((PBYTE) Original_Present, (PBYTE) Hooked_Present);

	return Original_Present(Device, pSrcRect, pDestRect, hDestWindow, pDirtyRegion);
}

/** Start
 * DLL Initialization.
 */
void __stdcall Start() {
	//Beep(1000, 100);
	//while(Engine::GetGameTime() < 1.0f || !ME) {
	//	Sleep(1);
	//}

	ActorManager = (LActorManager*) (baseAddr + DWORD_OBJECT_MANAGER);
	//Functions.CastSpell = (Typedefs::fnCastSpell)((DWORD) GetModuleHandle(NULL) + FN_CAST_SPELL);
	//Functions.DrawCircle = (Typedefs::fnDrawCircle)((DWORD) GetModuleHandle(NULL) + FNPTR_DRAW_CIRCLE);
	Functions.GetAttackCastDelay = (Typedefs::fnGetAttackCastDelay)((DWORD) GetModuleHandle(NULL) + FN_GET_ATTACK_CAST_DELAY);
	Functions.GetAttackDelay = (Typedefs::fnGetAttackDelay)((DWORD) GetModuleHandle(NULL) + FN_GET_ATTACK_DELAY);
	//Functions.IsAlive = (Typedefs::fnIsAlive)(baseAddr + FN_IS_ALIVE);
	//Functions.IsBaron = (Typedefs::fnIsBaron)(baseAddr + FN_IS_BARON);
	//Functions.IsDragon = (Typedefs::fnIsDragon)(baseAddr + FN_IS_DRAGON);
	//Functions.IsHero = (Typedefs::fnIsHero)(baseAddr + FN_IS_HERO);
	//Functions.IsInhibitor = (Typedefs::fnIsInhibitor)(baseAddr + FN_IS_INHIB);
	//Functions.IsMinion = (Typedefs::fnIsMinion)(baseAddr + FN_IS_MINION);
	//Functions.IsMissile = (Typedefs::fnIsMissile)(baseAddr + FN_IS_MISSILE);
	//Functions.IsNexus = (Typedefs::fnIsNexus)(baseAddr + FN_IS_NEXUS);
	//Functions.IssueOrder = (Typedefs::fnIssueOrder)((DWORD) GetModuleHandle(NULL) + FN_ISSUE_ORDER);
	Functions.IsTargetable = (Typedefs::fnIsTargetable)(baseAddr + FN_IS_TARGETABLE);
	//Functions.IsTroyEnt = (Typedefs::fnIsTroyEnt)(baseAddr + FN_IS_TROY);
	//Functions.IsTurret = (Typedefs::fnIsTurret)(baseAddr + FN_IS_TURRET);
	//Functions.PrintChat = (Typedefs::fnPrintChat)(baseAddr + FN_PRINT_CHAT);

	//Functions.WorldToScreen = (Typedefs::fnWorldToScreen)(baseAddr + FN_WORLD_TO_SCREEN);

	Original_Present = (Prototype_Present) DetourFunction((PBYTE) GetDX9EndsceneAddress(17), (PBYTE) Hooked_Present);
}


/** DllMain
 * Application Main. Called when the DLL is injected
 */
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