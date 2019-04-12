#include <time.h>
#include "stdafx.h"
//#include "Console.h"
#include "Engine.h"
#include "Hooks.h"
#include "detours.h"
#include <string>
#pragma comment(lib, "detours.lib")

#include "Menu.h"
#include "WndProc.h"
#include "RenderManager.h"
#include "ChampionManager.h"
#include "InputManager.h"
#pragma once

bool do_init = true;

void init(HWND hwnd, LPDIRECT3DDEVICE9 Device) {
	if(do_init) {
		oWndProc = (WNDPROC) SetWindowLongPtr(hwnd, GWL_WNDPROC, (LONG_PTR) WndProc);
		MenuInit(hwnd, Device);
		do_init = false;
	}
}

int main(HWND hwnd, LPDIRECT3DDEVICE9 Device) {
	init(hwnd, Device);
	handleInput();
	LastHitManager();
	MenuRender();
	RenderManager();
	return 0;
}

GameObjectManager* ObjManager;
//CConsole Console;
CFunctions Functions;

typedef HRESULT(WINAPI* Prototype_Present)(LPDIRECT3DDEVICE9, CONST RECT*, CONST RECT*, HWND, CONST RGNDATA*);
Prototype_Present Original_Present;

LRESULT __stdcall WndProc(const HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {

	if(ImGui_ImplWin32_WndProcHandler(hWnd, uMsg, wParam, lParam))
		return true;

	return CallWindowProc(oWndProc, hWnd, uMsg, wParam, lParam);
}

HRESULT WINAPI Hooked_Present(LPDIRECT3DDEVICE9  Device, CONST RECT* pSrcRect, CONST RECT* pDestRect, HWND hDestWindow, CONST RGNDATA* pDirtyRegion) {
	if(ME) { main(FindWindow(NULL, "League of Legends (TM) Client"), Device); }
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
	//Console.startConsoleWin(60, 10, NULL);
	Beep(1000, 100);
	while(Engine::GetGameTime() < 1.0f || !ME) {
		/*	for(int i = 0; i < 3; i++) {
				Console.print("ZalekLeague Compiled at %s %s\n", __DATE__, __TIME__);
				Console.print("updated for %s Waiting for League to load...\n", TARGET_GAMEVERSION);
				Sleep(333);
			}
			system("CLS");*/
		Sleep(1);
	}

	ObjManager = (GameObjectManager*) (baseAddr + DWORD_OBJECT_MANAGER);

	Functions.PrintChat = (Typedefs::fnPrintChat)(baseAddr + FN_PRINT_CHAT);

	Functions.IsTargetable = (Typedefs::fnIsTargetable)(baseAddr + FN_IS_TARGETABLE);
	Functions.IsAlive = (Typedefs::fnIsAlive)(baseAddr + FN_IS_ALIVE);

	Functions.IsMinion = (Typedefs::fnIsMinion)(baseAddr + FN_IS_MINION);
	//Functions.IsTurret = (Typedefs::fnIsTurret)(baseAddr + oIsTurret);
	Functions.IsHero = (Typedefs::fnIsHero)(baseAddr + FN_IS_HERO);
	Functions.IsMissile = (Typedefs::fnIsMissile)(baseAddr + FN_IS_MISSILE);
	//Functions.IsNexus = (Typedefs::fnIsNexus)(baseAddr + oIsNexus);
	//Functions.IsInhibitor = (Typedefs::fnIsInhibitor)(baseAddr + oIsInhib);
	//Functions.IsTroyEnt = (Typedefs::fnIsTroyEnt)(baseAddr + oIsTroy);

	//Functions.CastSpell = (Typedefs::fnCastSpell)((DWORD)GetModuleHandle(NULL) + oCastSpell);
	Functions.IssueOrder = (Typedefs::fnIssueOrder)((DWORD) GetModuleHandle(NULL) + FN_ISSUE_ORDER);
	Functions.DrawCircle = (Typedefs::fnDrawCircle)((DWORD) GetModuleHandle(NULL) + FN_DRAW_CIRCLE);

	Functions.GetAttackCastDelay = (Typedefs::fnGetAttackCastDelay)((DWORD) GetModuleHandle(NULL) + FN_GET_ATTACK_CAST_DELAY);
	Functions.GetAttackDelay = (Typedefs::fnGetAttackDelay)((DWORD) GetModuleHandle(NULL) + FN_GET_ATTACK_DELAY);
	//DetourFunction((PBYTE) dwFunc, (PBYTE) orgFunc);

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