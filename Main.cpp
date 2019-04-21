#include "LFunctions.h"
#include "detours.h"
#pragma comment(lib, "detours.lib")

#include "Engine.h"
#include "GUI.h"
#pragma once

bool __INIT__ = true;
LFunctions Functions;
InputHandler* Input;
GameObjectManager* ObjectManager;
GUI Interface;


//int Main() {
//
//
//
//	//if(ME) {
//	//	//	/*if(DEVELOPMENT_MODE) {
//	//	//		DevelopmentGUI();
//	//	//	}
//
//	//	//	if(GetAsyncKeyState(VK_INSERT) & 1)
//	//	//		bDrawGUI = !bDrawGUI;*/
//
//	//	//		//Vector vecWorld = Vector(ME->GetPos().X, ME->GetPos().Y, ME->GetPos().Z);
//	//	//		//Vector vecScreen = Vector();
//	//	//		//bool w2sResult = Functions.WorldToScreen(&vecWorld, &vecScreen);
//	//	//		//ImVec2 testVec = ImVec2(vecScreen.X, vecScreen.Y);
//	//	//		//Overlay(testVec, "Very Useful Overlay");
//
//	//	return 1;
//	//} else {
//	//	//Loading Screen
//	//	char* text = TARGET_GAMEVERSION;
//	//	ImGui_ImplDX9_NewFrame();
//	//	ImGui_ImplWin32_NewFrame();
//	//	ImGui::NewFrame();
//	//	ImGui::Begin("LoadingScreenOverlay##LoadingScreenOverlay_", false, ImGuiWindowFlags_NoTitleBar + ImGuiWindowFlags_AlwaysAutoResize + ImGuiWindowFlags_NoScrollbar);
//	//	ImGui::SetWindowSize(ImGui::CalcTextSize(text, "1"));
//	//	ImGui::SetWindowPos(ImVec2((ImGui::GetMousePos().x - (ImGui::GetWindowSize().x / 2.0f) - 1.0f), (ImGui::GetMousePos().y - ImGui::GetWindowSize().y / -0.5f)));
//	//	ImGui::Text(text);
//	//	ImGui::End();
//	//	ImGui::EndFrame();
//	//	ImGui::Render();
//	//	ImGui_ImplDX9_RenderDrawData(ImGui::GetDrawData());
//	//	return 2;
//	//}
//	return 0;
//}

typedef HRESULT(WINAPI* Prototype_Present)(LPDIRECT3DDEVICE9, CONST RECT*, CONST RECT*, HWND, CONST RGNDATA*);
Prototype_Present Original_Present;

LRESULT __stdcall WndProc(const HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {

	if(ImGui_ImplWin32_WndProcHandler(hWnd, uMsg, wParam, lParam))
		return true;

	return CallWindowProc(gWNDPROC, hWnd, uMsg, wParam, lParam);
}

HRESULT WINAPI Hooked_Present(LPDIRECT3DDEVICE9  Device, CONST RECT* pSrcRect, CONST RECT* pDestRect, HWND hDestWindow, CONST RGNDATA* pDirtyRegion) {
	if(__INIT__) {
		HWND hwnd = FindWindow(NULL, "League of Legends (TM) Client");
		gWNDPROC = (WNDPROC)
			SetWindowLongPtr(hwnd, GWL_WNDPROC, (LONG_PTR) WndProc);
		Interface.CreateContext(hwnd, Device);
		__INIT__ = false;
	}

	Interface.Draw();

	if(Interface.ShutdownEventListener())
		DetourRemove((PBYTE) Original_Present, (PBYTE) Hooked_Present);

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

	ObjectManager = (GameObjectManager*) (baseAddr + DWORD_OBJECT_MANAGER);
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