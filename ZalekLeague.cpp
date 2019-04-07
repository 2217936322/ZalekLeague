#define BUILD_NUM "4"
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
//#include "..//ImGui//imgui_impl_dx9.h"
//#include "..//ImGui//imgui_impl_win32.h"


CObjectManager* ObjManager;
CConsole Console;
CFunctions Functions;

clock_t lastmove = NULL;

bool b_init = false;
bool b_last_hit = false;
typedef HRESULT(WINAPI* Prototype_Present)(LPDIRECT3DDEVICE9, CONST RECT*, CONST RECT*, HWND, CONST RGNDATA*);
Prototype_Present Original_Present;

static void MenuInit(HWND Chwnd, IDirect3DDevice9* CDevice)
{
	HWND hwnd = Chwnd;
	IDirect3DDevice9* Device = CDevice;
	IMGUI_CHECKVERSION();
	ImGui::CreateContext();
	ImGuiIO& io = ImGui::GetIO();
	(void)io;
	ImGui::StyleColorsDark();
	ImGui_ImplWin32_Init(hwnd);
	ImGui_ImplDX9_Init(Device);
	Console.print("init()\n");
}

static bool show_demo_window = false;
static bool show_another_window = false;
static ImVec4 clear_color = ImVec4(0.45f, 0.55f, 0.60f, 1.00f);

static void MenuRender() {
	ImGui_ImplDX9_NewFrame();
	ImGui_ImplWin32_NewFrame();
	ImGui::NewFrame();

	Console.print("render()\n");

	{
		static float f = 0.0f;
		static int counter = 0;

		ImGui::Begin("Hello, world!");                          // Create a window called "Hello, world!" and append into it.

		ImGui::Text("This is some useful text.");               // Display some text (you can use a format strings too)
		ImGui::Checkbox("Demo Window", &show_demo_window);      // Edit bools storing our window open/close state
		ImGui::Checkbox("Another Window", &show_another_window);

		ImGui::SliderFloat("float", &f, 0.0f, 1.0f);            // Edit 1 float using a slider from 0.0f to 1.0f
		ImGui::ColorEdit3("clear color", (float*)& clear_color); // Edit 3 floats representing a color

		if (ImGui::Button("Button"))                            // Buttons return true when clicked (most widgets return true when edited/activated)
			counter++;
		ImGui::SameLine();
		ImGui::Text("counter = %d", counter);

		ImGui::Text("Application average %.3f ms/frame (%.1f FPS)", 1000.0f / ImGui::GetIO().Framerate, ImGui::GetIO().Framerate);
		ImGui::End();
	}

	ImGui::EndFrame();
	ImGui::Render();
	ImGui_ImplDX9_RenderDrawData(ImGui::GetDrawData());
}

HRESULT WINAPI Hooked_Present(LPDIRECT3DDEVICE9  Device, CONST RECT* pSrcRect, CONST RECT* pDestRect, HWND hDestWindow, CONST RGNDATA* pDirtyRegion)
{
	if (me)
	{
		if (!b_init)
		{
			system("CLS");
			Console.print("-------------------------------------------------------------------------------------\n");
			Console.print(" ZalekLeague Initialized build # %s\n * Current Version = %s\n", BUILD_NUM, TARGET_GAMEVERSION);
			Console.print(" * Summoner Name = %s\n * Champion Name = %s\n", me->GetName(), me->GetChampionName());
			Console.print("-------------------------------------------------------------------------------------");
			//Functions.PrintChat(oChatClient, "Hello from Zalek", 1);
			//Console.print(GetStr((DWORD)+oGameTime));

			//long number = 322323l;
			//char buffer[128];
			//int ret = snprintf(buffer, sizeof(buffer), "%ld", number);
			//char* num_string = buffer; //String terminator is added by snprintf
			//Console.print(num_string);
			//ImGui::CreateContext();
			//ImGuiIO& io = ImGui::GetIO();

			//ImGui_ImplWin32_Init(hDestWindow);
			//ImGui_ImplDX9_Init(Device)
			HWND hwnd = FindWindow(NULL, "League of Legends (TM) Client");
			MenuInit(hwnd, Device);
			b_init = true;
		}

		if (GetKeyState(VK_SPACE) & 0x8000)
		{
			auto color = createRGB(0, 128, 0);
			Functions.DrawCircle(&me->GetPos(), me->GetAttackRange() + me->GetBoundingRadius(), &color, 0, 0.0f, 0, 0.5f);
			if (lastmove == NULL || clock() - lastmove > 30.0f)
			{
				lastmove = clock();
				Engine::MoveTo(&Engine::GetMouseWorldPosition());
			}
		}

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
	Console.startConsoleWin(60, 10, NULL);

	while (Engine::GetGameTime() < 1.0f || !me)
	{
		const char* v = Engine::GetGameVersion();
		std::string vstr = v;
		for (int i = 0; i < 10; i++)
		{
			Console.print("ZalekLeague is updated for %s Waiting for League to load...\n", TARGET_GAMEVERSION);
			Sleep(10);
		}
		system("CLS");
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
