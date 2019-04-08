#define ZBUILD "0.1"
#include <time.h>
#include "stdafx.h"
#include "Console.h"
#include "Engine.h"
#include "Hooks.h"
#include "detours.h"
#include <string>
#pragma comment(lib, "detours.lib")

//#include "..//ImGui//imgui.h"
#include "ImGui/imgui.h"
#include "ImGui/imgui_impl_dx9.h"
#include "ImGui/imgui_impl_win32.h"
#include "d3d9helper.h"
#include "Menu.h"
//#include "..//ImGui//imgui_impl_dx9.h"
//#include "..//ImGui//imgui_impl_win32.h"


CObjectManager* ObjManager;
CConsole Console;
CFunctions Functions;

clock_t lastmove = NULL;

bool b_init = false;
bool b_last_hit = false;

extern LRESULT ImGui_ImplWin32_WndProcHandler(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);

//typedef LRESULT(CALLBACK* WNDPROC)(HWND, UINT, WPARAM, LPARAM);
typedef HRESULT(WINAPI* Prototype_Present)(LPDIRECT3DDEVICE9, CONST RECT*, CONST RECT*, HWND, CONST RGNDATA*);

Prototype_Present Original_Present;
WNDPROC oWndProc;

LRESULT __stdcall WndProc(const HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {

	if (ImGui_ImplWin32_WndProcHandler(hWnd, uMsg, wParam, lParam))
		return true;

	//if (true) // If we want input to imgui return true // replace with a bool // if league locks up then go back to https://youtu.be/b_1a3Wmi76U?t=1198
	//	return ImGui_ImplWin32_WndProcHandler(hWnd, uMsg, wParam, lParam);

	return CallWindowProc(oWndProc, hWnd, uMsg, wParam, lParam);
}

//static bool show_demo_window = false;
//static bool show_another_window = false;
//static ImVec4 clear_color = ImVec4(0.45f, 0.55f, 0.60f, 1.00f);

HRESULT WINAPI Hooked_Present(LPDIRECT3DDEVICE9  Device, CONST RECT* pSrcRect, CONST RECT* pDestRect, HWND hDestWindow, CONST RGNDATA* pDirtyRegion)
{
	//HWND window = FindWindow(NULL, "League of Legends");
	//oWndProc = (WNDPROC)SetWindowLongPtr(FindWindowA(0, "League of Legends (TM) Client"), GWL_WNDPROC, (LONG_PTR)WndProc);

	if (ME)
	{
		if (!b_init)
		{
			system("CLS");
			//Console.print("-------------------------------------------------------------------------------------\n");
			//Console.print(" ZalekLeague Initialized build # %s\n * Current Version = %s\n", ZBUILD, TARGET_GAMEVERSION);
			//Console.print(" * Summoner Name = %s\n * Champion Name = %s\n", ME->GetName(), ME->GetChampionName());
			//Console.print("-------------------------------------------------------------------------------------");
			Functions.PrintChat(*(DWORD*)(baseAddr + oChatClient), "<font color='#40c1ff'>[Zalek]:</font><font color='#C1FFAF'> Initialized</font>", 1);
			HWND hwnd = FindWindow(NULL, "League of Legends (TM) Client");
			oWndProc = (WNDPROC)SetWindowLongPtr(hwnd, GWL_WNDPROC, (LONG_PTR)WndProc);
			MenuInit(hwnd, Device);
			b_init = true;
		}

		if (GetKeyState(VK_SPACE) & 0x8000)
		{
			auto color = createRGB(0, 128, 0);
			Functions.DrawCircle(&ME->GetPos(), ME->GetAttackRange() + ME->GetBoundingRadius(), &color, 0, 0.0f, 0, 0.5f);
			if (lastmove != NULL)
				Console.print("%f\n", lastmove);
			if (lastmove == NULL || clock() - lastmove > 300.0f);
			{
				lastmove = clock();
				Engine::MoveTo(&Engine::GetMouseWorldPosition());
				//Engine::MoveClick();
			}
		}

		//if (GetKeyState(VK_ADD) & 0x8000)
		//	exit(0);

		//// 0x58 = X Key
		//if (GetKeyState(0x58) & 0x8000) {
		//	//auto color = createRGB(128, 128, 128);
		//	//Functions.DrawCircle(&me->GetPos(), me->GetAttackRange() + me->GetBoundingRadius(), &color, 0, 0.0f, 0, 0.5f);
		//	bLastHit = true;
		//}
		//else {
		//	bLastHit = false;
		//}

		//if (ObjManager)
		//{
		//	for (int i = 0; i < 10000; i++)
		//	{
		//		CObject* obj = Engine::GetObjectByID(i);
		//		if (obj)
		//		{
		//			if (obj->IsHero())
		//			{
		//				if (obj->IsAlive() && obj->IsVisible() && obj->GetTeam() != me->GetTeam())
		//				{
		//					auto color = createRGB(255, 0, 0);
		//					Functions.DrawCircle(&obj->GetPos(), obj->GetAttackRange() + obj->GetBoundingRadius(), &color, 0, 0.0f, 0, 0.5f);
		//				}
		//			}

		//			//? Last Hit Marker
		//			if (obj->IsMinion())
		//			{
		//				if (obj->IsAlive()
		//					&& obj->GetTeam() != me->GetTeam() // Ignore friendly creeps
		//					&& obj->IsEnemyTo(me) // Prevent usage on jungle camps.
		//					&& obj->GetHealth() <= me->GetTotalAttackDamage() + 15 // Last hit range with a 15 damage buffer.
		//					&& obj->IsTargetable() // Prevent attacking things like zyra plant seeds.
		//					&& me->GetPos().DistTo(obj->GetPos()) <= // Ensure that we are already within aa range.
		//					(me->GetAttackRange() + me->GetBoundingRadius()))
		//				{
		//					auto color = createRGB(255, 233, 0);
		//					Functions.DrawCircle(&obj->GetPos(), me->GetAttackRange() + me->GetBoundingRadius(), &color, 0, 0.0f, 0, 0.5f);

		//					if (bLastHit)
		//						Console.print("Last Hit Creep.\n");
		//				}
		//			}
		//		}
		//	}
		//}
	}
	MenuRender();

	return Original_Present(Device, pSrcRect, pDestRect, hDestWindow, pDirtyRegion);
}

DWORD FindDevice(DWORD Len)
{
	DWORD dwObjBase = 0;

	dwObjBase = (DWORD)LoadLibrary("d3d9.dll");
	while (dwObjBase++ < dwObjBase + Len)
	{
		if ((*(WORD*)(dwObjBase + 0x00)) == 0x06C7 && (*(WORD*)(dwObjBase + 0x06)) == 0x8689 && (*(WORD*)(dwObjBase + 0x0C)) == 0x8689)
		{
			dwObjBase += 2;
			break;
		}
	}
	return (dwObjBase);
}

DWORD GetDeviceAddress(int VTableIndex)
{
	PDWORD VTable;
	*(DWORD*)& VTable = *(DWORD*)FindDevice(0x128000);
	return VTable[VTableIndex];
}

void __stdcall Start()
{
	//Console.startConsoleWin(60, 10, NULL);

	while (Engine::GetGameTime() < 1.0f || !ME)
	{
		//const char* v = Engine::GetGameVersion();
		//std::string vstr = v;
		//for (int i = 0; i < 3; i++)
		//{
		//	Console.print("ZalekLeague is updated for %s Waiting for League to load...\n", TARGET_GAMEVERSION);
		//  Sleep(333);
		//}
		//system("CLS");
		Sleep(1);
	}

	ObjManager = (CObjectManager*)(baseAddr + oObjManager);

	Functions.PrintChat = (Typedefs::fnPrintChat)(baseAddr + oPrintChat);

	Functions.IsTargetable = (Typedefs::fnIsTargetable)(baseAddr + oIsTargetable);
	Functions.IsAlive = (Typedefs::fnIsAlive)(baseAddr + oIsAlive);

	Functions.IsMinion = (Typedefs::fnIsMinion)(baseAddr + oIsMinion);
	Functions.IsTurret = (Typedefs::fnIsTurret)(baseAddr + oIsTurret);
	Functions.IsHero = (Typedefs::fnIsHero)(baseAddr + oIsHero);
	Functions.IsMissile = (Typedefs::fnIsMissile)(baseAddr + oIsMissile);
	Functions.IsNexus = (Typedefs::fnIsNexus)(baseAddr + oIsNexus);
	Functions.IsInhibitor = (Typedefs::fnIsInhibitor)(baseAddr + oIsInhib);
	Functions.IsTroyEnt = (Typedefs::fnIsTroyEnt)(baseAddr + oIsTroy);

	//Functions.CastSpell = (Typedefs::fnCastSpell)((DWORD)GetModuleHandle(NULL) + oCastSpell);
	Functions.IssueOrder = (Typedefs::fnIssueOrder)((DWORD)GetModuleHandle(NULL) + oIssueOrder);
	Functions.DrawCircle = (Typedefs::fnDrawCircle)((DWORD)GetModuleHandle(NULL) + oDrawCircle);

	Functions.GetAttackCastDelay = (Typedefs::fnGetAttackCastDelay)((DWORD)GetModuleHandle(NULL) + oGetAttackCastDelay);
	Functions.GetAttackDelay = (Typedefs::fnGetAttackDelay)((DWORD)GetModuleHandle(NULL) + oGetAttackDelay);

	Original_Present = (Prototype_Present)DetourFunction((PBYTE)GetDeviceAddress(17), (PBYTE)Hooked_Present);
}

BOOL APIENTRY DllMain(HMODULE hModule,
	DWORD ul_reason_for_call,
	LPVOID lpReserved)
{

	if (ul_reason_for_call == DLL_PROCESS_ATTACH)
	{
		CreateThread(0, 0, (LPTHREAD_START_ROUTINE)Start, 0, 0, 0);
		return TRUE;
	}

	else if (ul_reason_for_call == DLL_PROCESS_DETACH)
	{
		return TRUE;
	}
	return FALSE;
}