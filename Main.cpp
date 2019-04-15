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
			//DevelopmentMenu();
			ClassicOverlay(
				ImGui::GetMousePos(),
				"ZalekLeague is in Development Mode."
			);
		}
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