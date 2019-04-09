#pragma once
#include "ImGui/imgui.h"
#include "ImGui/imgui_impl_dx9.h"
#include "ImGui/imgui_impl_win32.h"
#include "d3d9helper.h"

static bool draw_menu = true;

static void MenuInit(HWND Chwnd, IDirect3DDevice9* CDevice) {
	HWND hwnd = Chwnd;
	IDirect3DDevice9* Device = CDevice;
	IMGUI_CHECKVERSION();
	ImGui::CreateContext();
	ImGuiIO& io = ImGui::GetIO();
	(void) io;
	ImGui::GetIO().ConfigFlags |= ImGuiConfigFlags_NoMouseCursorChange;
	ImGui::StyleColorsDark();
	ImGui_ImplWin32_Init(hwnd);
	ImGui_ImplDX9_Init(Device);
}

static void MenuRender() {
	ImGui_ImplDX9_NewFrame();
	ImGui_ImplWin32_NewFrame();
	ImGui::NewFrame();
	if(draw_menu) {
		ImGui::Begin("Zalek League", &draw_menu);
		ImGui::Text("ZalekLeague Compiled at %s %s\n", __DATE__, __TIME__);

		if(ImGui::Button("Crash League"))
			exit(0);

		ImGui::SetNextTreeNodeOpen(true, ImGuiCond_Appearing);
		if(ImGui::TreeNode("Engine")) {
			ImGui::Text("Engine::GetMouseWorldPosition() => { x = %f, y = %f, z = %f }", Engine::GetMouseWorldPosition().X, Engine::GetMouseWorldPosition().Y, Engine::GetMouseWorldPosition().Z);
			ImGui::Text("Engine::GetGameVersion() => %s", GetStr(oGameVersion));
			ImGui::Text("Engine::GetGameTime() => %f", Engine::GetGameTime());
			ImGui::TreePop();
		}

		if(ImGui::TreeNode("Object Manager")) {
			if(ObjManager) {
				ImGui::Text("%d", ObjManager->HighestObjectID);
				for(int i = 0; i < ObjManager->HighestObjectID; i++) {
					CObject* obj = Engine::GetObjectByID(i);
					if(obj) {
						ImGui::Text("%d", i);
					}
				}
			}
			ImGui::TreePop();
		}

		ImGui::End();
	}
	ImGui::EndFrame();
	ImGui::Render();
	ImGui_ImplDX9_RenderDrawData(ImGui::GetDrawData());
}