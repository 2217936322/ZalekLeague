#include "Objects.h"
#include "ImGui/imgui.h"
#include "ImGui/imgui_impl_win32.h"
#include "ImGui/imgui_impl_dx9.h"
#include "WndProc.h"
#pragma once

#define DEVELOPMENT_INTERFACES true

class GUI
{
private:

	void DebugOverlay() {
		if(ME && DEVELOPMENT_INTERFACES) {
			char* text = "ZalekLeague Debug Overlay {Work in Progress}";
			ImGui::Begin("DebugOverlay##DebugOverlay_", false, ImGuiWindowFlags_NoTitleBar + ImGuiWindowFlags_AlwaysAutoResize + ImGuiWindowFlags_NoScrollbar);
			ImGui::SetWindowSize(ImGui::CalcTextSize(text, "1"));
			ImGui::SetWindowPos(ImVec2((ImGui::GetMousePos().x - (ImGui::GetWindowSize().x / 2.0f) - 1.0f), (ImGui::GetMousePos().y - ImGui::GetWindowSize().y / -0.5f)));
			ImGui::Text(text);
			ImGui::End();
		}
	}

	void DevkitInterface() {
		if(Me() && DEVELOPMENT_INTERFACES) {
			ImGui::Begin("Zalek Devkit");
			{
				if(ImGui::TreeNode("Object Manager")) {
					ImGui::Text("GameObjectManager* GObjectManager");
					ImGui::BulletText("GObjectManager->MaxObjects => %d", GObjectManager->MaxObjects);
					ImGui::BulletText("GObjectManager->ObjectsUsed => %d", GObjectManager->ObjectsUsed);
					ImGui::BulletText("GObjectManager->HighestObjectID => %d", GObjectManager->HighestObjectID);
					ImGui::TreePop();
				}
			}
			ImGui::End();
		}
	}

	void LoadingScreen() {
		if(!ME) {
			char* text = "ZalekLeague 9.8.270.9450 {Work in Progress}";
			ImGui::Begin("LoadingScreenOverlay##LoadingScreenOverlay_", false, ImGuiWindowFlags_NoTitleBar + ImGuiWindowFlags_AlwaysAutoResize + ImGuiWindowFlags_NoScrollbar);
			ImGui::SetWindowSize(ImGui::CalcTextSize(text, "1"));
			ImGui::SetWindowPos(ImVec2((ImGui::GetMousePos().x - (ImGui::GetWindowSize().x / 2.0f) - 1.0f), (ImGui::GetMousePos().y - ImGui::GetWindowSize().y / -0.5f)));
			ImGui::Text(text);
			ImGui::End();
		}
	}

	//inline GUI(void) {};
public:
	void CreateContext(HWND hwnd, IDirect3DDevice9 * device) {
		IDirect3DDevice9* Device = device;
		//IMGUI_CHECKVERSION();
		ImGui::CreateContext();
		ImGuiIO& io = ImGui::GetIO();
		(void) io;
		ImGui::GetIO().ConfigFlags |= ImGuiConfigFlags_NoMouseCursorChange;
		ImGui_ImplWin32_Init(hwnd);
		ImGui_ImplDX9_Init(Device);
	}

	void Draw() {
		ImGui_ImplDX9_NewFrame();
		ImGui_ImplWin32_NewFrame();
		ImGui::NewFrame();
		{
			{ LoadingScreen(); }
			{ DevkitInterface(); }
			{ DebugOverlay(); }
		}
		ImGui::EndFrame();
		ImGui::Render();
		ImGui_ImplDX9_RenderDrawData(ImGui::GetDrawData());
	}
};