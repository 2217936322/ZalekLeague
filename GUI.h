#include <d3d9.h>
#include "InputHandler.h"

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
			ImGui::SetWindowPos(ImVec2((ImGui::GetMousePos().x - (ImGui::GetWindowSize().x / 2.0f) - 1.0f), (ImGui::GetMousePos().y - ImGui::GetWindowSize().y / -0.5f)));
			ImGui::Begin("DebugOverlay##DebugOverlay_",
				false,
				ImGuiWindowFlags_NoTitleBar + ImGuiWindowFlags_AlwaysAutoResize + ImGuiWindowFlags_NoScrollbar);
			{
				ImGui::SetWindowPos(ImVec2((ImGui::GetMousePos().x - (ImGui::GetWindowSize().x / 2.0f) - 1.0f), (ImGui::GetMousePos().y - ImGui::GetWindowSize().y / -0.5f)));
				ImGui::Text("ZalekLeague Debug Overlay {Work in Progress}");
			}
			ImGui::End();
		}
	}

	void Devkit() {
		if(Me() && DEVELOPMENT_INTERFACES) {
			if(bShowDevkit) {
				DebugOverlay();
				ImGui::Begin("Zalek Devkit", &bShowDevkit, ImGuiWindowFlags_AlwaysAutoResize);
				{
					if(ImGui::TreeNode("Input")) {
						ImGui::Text("InputHandler* Input = new InputHandler;");
						Vector mw = Input->GetMouseWorld();
						ImGui::BulletText("Input->GetMouseWorld() =>\n x = %f,\n y = %f,\n z = %f", mw.X, mw.Y, mw.Z);
						ImGui::TreePop();
					}

					if(ImGui::TreeNode("Game Object Manager")) {
						ImGui::BulletText("GObjectManager->HighestObjectID => %d", GObjectManager->HighestObjectID);
						ImGui::BulletText("GObjectManager->ObjectsUsed => %d", GObjectManager->ObjectsUsed);
						ImGui::BulletText("GObjectManager->MaxObjects => %d", GObjectManager->MaxObjects);
						ImGui::TreePop();
					}

					// TODO: Champion Vector
					// TODO: Minion Vector
					// TODO: Monster Vector
					// TODO: Missile Vector
					// TODO: Troy Ent Vector
				}
				ImGui::End();
			} else {
				if(GetAsyncKeyState(VK_OEM_3) & 1) // Re-enable Devkit via ~ when it is not open.
					bShowDevkit = true;
			}
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

protected:
	bool bShowDevkit = DEVELOPMENT_INTERFACES;

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
			{ Devkit(); }
		}
		ImGui::EndFrame();
		ImGui::Render();
		ImGui_ImplDX9_RenderDrawData(ImGui::GetDrawData());
	}

	bool ShutdownEventListener() {
		if(GetAsyncKeyState(VK_END) & 1) {
			ImGui_ImplDX9_Shutdown();
			ImGui_ImplWin32_Shutdown();
			ImGui::DestroyContext();
			return true;
		}
		return false;
	}
};