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

					ImGui::Text("bool");
					ImGui::BulletText("IsAlive() => %d", (*Minion)->IsAlive());
					ImGui::BulletText("IsEnemy() => %d", (*Minion)->IsEnemy());
					ImGui::BulletText("IsTargetable() => %d", (*Minion)->IsTargetable());
					//TODO: Implement Minion Type in GameObject.cpp and h
					ImGui::BulletText("IsCannon() => %d", endsWith((std::string)(*Minion)->GetChampionName(), "Siege"));
					ImGui::BulletText("IsMelee() => %d", endsWith((std::string)(*Minion)->GetChampionName(), "Melee"));
					ImGui::BulletText("IsRanged() => %d", endsWith((std::string)(*Minion)->GetChampionName(), "Ranged"));

					ImGui::Text("char*");
					ImGui::BulletText("GetChampionName() => %s", (*Minion)->GetChampionName());
					ImGui::BulletText("GetName() => %s", (*Minion)->GetName());

					ImGui::Text("DWORD");
					ImGui::BulletText("GetNetworkID() => %lu", (*Minion)->GetNetworkID());

					ImGui::Text("float");
					ImGui::BulletText("GetArmor() => %f", (*Minion)->GetArmor());
					ImGui::BulletText("GetAttackRange() => %f", (*Minion)->GetAttackRange());
					ImGui::BulletText("GetBaseAttackDamage() => %f", (*Minion)->GetBaseAttackDamage());
					ImGui::BulletText("GetBonusAttackDamage() => %f", (*Minion)->GetBonusAttackDamage());
					ImGui::BulletText("GetTotalAttackDamage() => %f", (*Minion)->GetTotalAttackDamage());
					ImGui::BulletText("GetBoundingRadius() => %f", (*Minion)->GetBoundingRadius());
					ImGui::BulletText("GetHealth() => %f", (*Minion)->GetHealth());
					ImGui::BulletText("GetMaxHealth() => %f", (*Minion)->GetMaxHealth());

					ImGui::Text("int");
					ImGui::BulletText("GetLevel() => %hu", (*Minion)->GetLevel());
					ImGui::BulletText("GetTeam() => %d", (*Minion)->GetTeam());

					ImGui::Text("short");
					ImGui::BulletText("GetIndex() => %hu", (*Minion)->GetIndex());
					ImGui::BulletText("GetSourceIndex() => %hu", (*Minion)->GetSourceIndex());
					ImGui::BulletText("GetTargetIndex() => %hu", (*Minion)->GetTargetIndex());

					ImGui::Text("Vector");
					ImGui::BulletText("GetPos() => (%f, %f, %f)", (*Minion)->GetPos().X, (*Minion)->GetPos().Y, (*Minion)->GetPos().Z);
					//ImGui::Text("IsEnemyTo(ME) => %d", (*Minion)->IsEnemyTo(ME));

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