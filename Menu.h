#include "ImGui/imgui.h"
#include "ImGui/imgui_impl_dx9.h"
#include "ImGui/imgui_impl_win32.h"
#include "d3d9helper.h"
#include "BehaviorManager.h"
#include "MissileManager.h"
#include "ChampionManager.h"
#include "MinionManager.h"
#include "RenderManager.h"
#pragma once
static bool draw_menu = true;
static void MenuInit(HWND Chwnd, IDirect3DDevice9* CDevice) {
	HWND hwnd = Chwnd;
	IDirect3DDevice9* Device = CDevice;
	//IMGUI_CHECKVERSION();
	ImGui::CreateContext();
	ImGuiIO& io = ImGui::GetIO();
	(void) io;
	ImGui::GetIO().ConfigFlags |= ImGuiConfigFlags_NoMouseCursorChange;
	ImGui::StyleColorsDark();
	ImGui_ImplWin32_Init(hwnd);
	ImGui_ImplDX9_Init(Device);

}

//bool endsWith(const std::string& mainStr, const std::string& toMatch) {
//	if(mainStr.size() >= toMatch.size() &&
//		mainStr.compare(mainStr.size() - toMatch.size(), toMatch.size(), toMatch) == 0)
//		return true;
//	else
//		return false;
//}

void DrawGameObjectText(std::vector<GameObject*> obj_vector) {
	int i = 0;
	for(std::vector<GameObject*>::iterator obj = obj_vector.begin(); obj != obj_vector.end(); obj++) {
		if(ImGui::TreeNode((void*) (intptr_t) i, "%s : %d | Dist = %f", (*obj)->GetChampionName(), i, (*obj)->GetDistToMe())) {
			ImGui::Text("bool");
			ImGui::BulletText("IsAttackable() => %d", (*obj)->IsAttackable());
			ImGui::BulletText("IsAlive() => %d", (*obj)->IsAlive());
			ImGui::BulletText("IsEnemy() => %d", (*obj)->IsEnemy());
			ImGui::BulletText("IsTargetable() => %d", (*obj)->IsTargetable());
			//TODO: Implement Minion Type in GameObject.cpp and h
			//ImGui::BulletText("IsCannon() => %d", endsWith((std::string)(*obj)->GetChampionName(), "Siege"));
			//ImGui::BulletText("IsMelee() => %d", endsWith((std::string)(*obj)->GetChampionName(), "Melee"));
			//ImGui::BulletText("IsRanged() => %d", endsWith((std::string)(*obj)->GetChampionName(), "Ranged"));

			ImGui::Text("char*");
			ImGui::BulletText("GetChampionName() => %s", (*obj)->GetChampionName());
			ImGui::BulletText("GetName() => %s", (*obj)->GetName());

			ImGui::Text("DWORD");
			ImGui::BulletText("GetNetworkID() => %lu", (*obj)->GetNetworkID());

			ImGui::Text("float");
			ImGui::BulletText("GetArmor() => %f", (*obj)->GetArmor());
			ImGui::BulletText("GetAttackRange() => %f", (*obj)->GetAttackRange());
			ImGui::BulletText("GetBaseAttackDamage() => %f", (*obj)->GetBaseAttackDamage());
			ImGui::BulletText("GetBonusAttackDamage() => %f", (*obj)->GetBonusAttackDamage());
			ImGui::BulletText("GetDistToMe() => %f", (*obj)->GetDistToMe());
			ImGui::BulletText("GetTotalAttackDamage() => %f", (*obj)->GetTotalAttackDamage());
			ImGui::BulletText("GetBoundingRadius() => %f", (*obj)->GetBoundingRadius());
			ImGui::BulletText("GetHealth() => %f", (*obj)->GetHealth());
			ImGui::BulletText("GetMaxHealth() => %f", (*obj)->GetMaxHealth());

			ImGui::Text("int");
			ImGui::BulletText("GetLevel() => %hu", (*obj)->GetLevel());
			ImGui::BulletText("GetTeam() => %d", (*obj)->GetTeam());

			ImGui::Text("short");
			ImGui::BulletText("GetIndex() => %hu", (*obj)->GetIndex());
			ImGui::BulletText("GetSourceIndex() => %hu", (*obj)->GetSourceIndex());
			ImGui::BulletText("GetTargetIndex() => %hu", (*obj)->GetTargetIndex());

			ImGui::Text("Vector");
			ImGui::BulletText("GetPos() => (%f, %f, %f)", (*obj)->GetPos().X, (*obj)->GetPos().Y, (*obj)->GetPos().Z);
			// TODO: Prediction position.
			ImGui::TreePop();
		}
		i++;
	}
}

void DrawGameObjectTree(char* label, std::vector<GameObject*> obj_vector) {
	if(ImGui::TreeNode(label)) {
		DrawGameObjectText(obj_vector);
		ImGui::TreePop();
	}
}

//void TextTest() {
//	ImGui_ImplDX9_NewFrame();
//	ImGui_ImplWin32_NewFrame();
//	ImGui::NewFrame();
//	////NoTitleBar | NoResize | NoMove | NoScrollbar | NoSavedSettings | NoInputs
//	ImGui::SetNextWindowPos(ImVec2(Engine::GetMouseWorldPosition().X, Engine::GetMouseWorldPosition().Y));
//	ImGui::Begin("test", false, ImGuiWindowFlags_NoTitleBar + ImGuiWindowFlags_NoResize + ImGuiWindowFlags_NoMove + ImGuiWindowFlags_NoScrollbar + ImGuiWindowFlags_NoSavedSettings + ImGuiWindowFlags_NoInputs);
//	//ImGui::GetWindowDrawList()->AddText(ImGui::GetFont(), ImGui::GetFontSize(), ImVec2(100.f, 100.f), ImColor(255, 255, 0, 255), "Hello World", 0, 0.0f, 0);
//	ImGui::End();
//	ImGui::EndFrame();
//	ImGui::Render();
//	ImGui_ImplDX9_RenderDrawData(ImGui::GetDrawData());
//}

void MenuRender() {
	ImGui_ImplDX9_NewFrame();
	ImGui_ImplWin32_NewFrame();
	ImGui::NewFrame();
	if(draw_menu) {
		//ImGui::SetNextWindowPos(ImGui::GetMousePos());
		ImGui::Begin("Zalek League", &draw_menu, ImGuiWindowFlags_AlwaysAutoResize + ImGuiWindowFlags_MenuBar);

		if(ImGui::BeginMenuBar()) {
			if(ImGui::BeginMenu("Drawing")) {
				ImGui::Checkbox("Draw Auto Attack Range Always", &gRenderAttackRange);
				ImGui::Checkbox("Draw Last Hittable Minions In Attack Range", &gRenderLastHit);
				ImGui::EndMenu();
			}
			ImGui::EndMenuBar();
		}



		ImGui::SetNextTreeNodeOpen(true, ImGuiCond_Appearing);
		if(ImGui::TreeNode("Debug & Development")) {
			ImGui::Text("ZalekLeague Compiled at %s %s\n", __DATE__, __TIME__);
			ImGui::SetNextTreeNodeOpen(true, ImGuiCond_Appearing);

			if(ImGui::TreeNode("Globals")) {
				ImGui::Text("gAttackTime => %f", gAttackTime);
				ImGui::Text("gLastAttackTime => %f", gLastAttackTime);
				ImGui::Text("gMoveTime => %f", gMoveTime);
				ImGui::Text("gMoveThreshold => %f", gMoveThreshold);
				ImGui::Text("gLastMoveToTime => %f", gLastMoveTime);
				ImGui::TreePop();
			}

			//if(ImGui::Button("Text Test"))
			//	TextTest();

			ImGui::SetNextTreeNodeOpen(true, ImGuiCond_Appearing);
			if(ImGui::TreeNode("Engine")) {
				ImGui::Text("Engine::GetMouseWorldPosition() => { x = %f, y = %f, z = %f }", Engine::GetMouseWorldPosition().X, Engine::GetMouseWorldPosition().Y, Engine::GetMouseWorldPosition().Z);
				//ImGui::Text("Engine::GetGameVersion() => %s", Engine::GetGameVersion());
				ImGui::Text("Engine::GetGameTime() => %f", Engine::GetGameTime());
				ImGui::TreePop();
			}

			ImGui::SetNextTreeNodeOpen(true, ImGuiCond_Appearing);
			if(ImGui::TreeNode("Functions")) {
				ImGui::Text("Functions.GetAttackCastDelay(ME) => %f", Functions.GetAttackCastDelay(ME));
				ImGui::Text("Functions.GetAttackDelay(ME) => %f", Functions.GetAttackDelay(ME));
				//ImGui::Text("Functions.GetBasicAttack(ME) => %f", Functions.GetBasicAttack(ME));
				ImGui::TreePop();
			}

			DrawGameObjectTree("All Champions", GetChampions());
			DrawGameObjectTree("Attackable Champions", GetAttackableChampions());
			DrawGameObjectTree("Enemy Champions", GetEnemyChampions());
			DrawGameObjectTree("Friendly Champions", GetFriendlyChampions());
			DrawGameObjectTree("All Minions", GetMinions());
			DrawGameObjectTree("Enemy Minions", GetEnemyMinions());
			DrawGameObjectTree("Enemy Minions (Last Hit)", GetLastHitMinions());
			DrawGameObjectTree("Missiles", GetMissiles());
			if(ImGui::TreeNode("Friendly Missles")) {
				int i = 0;
				std::vector<GameObject*> Missles = GetFriendlyMissiles();
				for(std::vector<GameObject*>::iterator obj = Missles.begin(); obj != Missles.end(); obj++) {
					if(ImGui::TreeNode((void*) (intptr_t) i, "%s : %d | Dist = %f", (*obj)->GetName(), i, (*obj)->GetDistToMe())) {

						ImGui::Text("char*");
						//ImGui::BulletText("GetChampionName() => %s", (*obj)->GetChampionName());
						ImGui::BulletText("GetName() => %s", (*obj)->GetName());

						ImGui::Text("DWORD");
						ImGui::BulletText("GetNetworkID() => %lu", (*obj)->GetNetworkID());

						ImGui::Text("float");
						ImGui::BulletText("GetDistToMe() => %f", (*obj)->GetDistToMe());
						ImGui::BulletText("GetBoundingRadius() => %f", (*obj)->GetBoundingRadius());

						ImGui::Text("short");
						ImGui::BulletText("GetIndex() => %hu", (*obj)->GetIndex());
						ImGui::BulletText("GetSourceIndex() => %hu", (*obj)->GetSourceIndex());
						ImGui::BulletText("GetTargetIndex() => %hu", (*obj)->GetTargetIndex());

						ImGui::Text("Vector");
						ImGui::BulletText("GetPos() => (%f, %f, %f)", (*obj)->GetPos().X, (*obj)->GetPos().Y, (*obj)->GetPos().Z);
						ImGui::BulletText("GetStartPos() => (%f, %f, %f)", (*obj)->GetStartPos().X, (*obj)->GetStartPos().Y, (*obj)->GetStartPos().Z);
						ImGui::BulletText("GetEndPos() => (%f, %f, %f)", (*obj)->GetEndPos().X, (*obj)->GetEndPos().Y, (*obj)->GetEndPos().Z);
						// TODO: Prediction position.
						ImGui::TreePop();
					}
					i++;
				}
				ImGui::TreePop();
			}
			//DrawObjectVectorTree("Friendly Minions", gMinions);
			ImGui::TreePop();
		}
		ImGui::End();
	}
	ImGui::EndFrame();
	ImGui::Render();
	ImGui_ImplDX9_RenderDrawData(ImGui::GetDrawData());
}

void OverlayTest(ImVec2 screen_pos, char* text) {
	ImGui_ImplDX9_NewFrame();
	ImGui_ImplWin32_NewFrame();
	ImGui::NewFrame();
	ImGui::Begin("Overlay Test", false, ImGuiWindowFlags_NoTitleBar + ImGuiWindowFlags_NoResize + ImGuiWindowFlags_NoMove + ImGuiWindowFlags_NoScrollbar);
	ImGui::SetWindowSize(ImGui::CalcTextSize(text, "1"));
	ImGui::SetWindowPos(
		ImVec2(
		(screen_pos.x - (ImGui::GetWindowSize().x / 2) - 1),
			(screen_pos.y - ImGui::GetWindowSize().y / -.5))

	);
	ImGui::Text(text);
	ImGui::End();
	ImGui::EndFrame();
	ImGui::Render();
	ImGui_ImplDX9_RenderDrawData(ImGui::GetDrawData());

}