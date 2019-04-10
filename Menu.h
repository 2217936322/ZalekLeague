#pragma once
#include "ImGui/imgui.h"
#include "ImGui/imgui_impl_dx9.h"
#include "ImGui/imgui_impl_win32.h"
#include "d3d9helper.h"
#include "MinionManager.h"

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

bool endsWith(const std::string& mainStr, const std::string& toMatch) {
	if(mainStr.size() >= toMatch.size() &&
		mainStr.compare(mainStr.size() - toMatch.size(), toMatch.size(), toMatch) == 0)
		return true;
	else
		return false;
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

		/*		if(ImGui::TreeNode("Object Manager")) {
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
				}	*/


		if(ImGui::TreeNode("Minion Manager")) {
			PopulateGlobalMinionsVector();

			int i = 0;
			for(std::vector<GameObject*>::iterator Minion = gMinions.begin(); Minion != gMinions.end(); Minion++) {

				if(ImGui::TreeNode((void*) (intptr_t) i, "%s : %d", (*Minion)->GetChampionName(), i)) {

					ImGui::Text("GetArmor() => %f", (*Minion)->GetArmor());
					ImGui::Text("GetAttackRange() => %f", (*Minion)->GetAttackRange());
					ImGui::Text("GetBaseAttackDamage() => %f", (*Minion)->GetBaseAttackDamage());
					ImGui::Text("GetBonusAttackDamage() => %f", (*Minion)->GetBonusAttackDamage());
					ImGui::Text("GetBoundingRadius() => %f", (*Minion)->GetBoundingRadius());
					ImGui::Text("GetChampionName() => %s", (*Minion)->GetChampionName());
					ImGui::Text("GetHealth() => %f", (*Minion)->GetHealth());
					ImGui::Text("GetIndex() => %hu", (*Minion)->GetIndex());
					ImGui::Text("GetLevel() => %hu", (*Minion)->GetLevel());
					ImGui::Text("GetMaxHealth() => %f", (*Minion)->GetMaxHealth());
					ImGui::Text("GetName() => %s", (*Minion)->GetName());
					ImGui::Text("GetNetworkID() => %lu", (*Minion)->GetNetworkID());
					ImGui::Text("GetPos() => (%f, %f, %f)", (*Minion)->GetPos().X, (*Minion)->GetPos().Y, (*Minion)->GetPos().Z);
					ImGui::Text("GetSourceIndex() => %hu", (*Minion)->GetSourceIndex());
					ImGui::Text("GetTargetIndex() => %hu", (*Minion)->GetTargetIndex());
					ImGui::Text("GetTotalAttackDamage() => %f", (*Minion)->GetTotalAttackDamage());
					ImGui::Text("IsAlive() => %d", (*Minion)->IsAlive());
					ImGui::Text("IsCannon() => %d", endsWith((std::string)(*Minion)->GetChampionName(), "Siege"));
					ImGui::Text("IsMelee() => %d", endsWith((std::string)(*Minion)->GetChampionName(), "Melee"));
					ImGui::Text("IsRanged() => %d", endsWith((std::string)(*Minion)->GetChampionName(), "Ranged"));
					ImGui::Text("IsEnemyTo(ME) => %d", (*Minion)->IsEnemyTo(ME));
					ImGui::Text("IsTargetable() => %d", (*Minion)->IsTargetable());
					ImGui::TreePop();
				}
				i++;
			}
			ImGui::TreePop();
		}

		ImGui::End();
	}
	ImGui::EndFrame();
	ImGui::Render();
	ImGui_ImplDX9_RenderDrawData(ImGui::GetDrawData());
}