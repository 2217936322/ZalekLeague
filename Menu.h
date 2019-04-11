#pragma once
#include "ImGui/imgui.h"
#include "ImGui/imgui_impl_dx9.h"
#include "ImGui/imgui_impl_win32.h"
#include "d3d9helper.h"
#include "ChampionManager.h"
#include "MinionManager.h"

static bool draw_menu = true;
static bool draw_attack_range = true;
static float gAttackTime = 0.0f;
static float gLastAttackTime = 0.0f;
static float gMoveTime = 0.0f;
static float gLastMoveTime = 0.0f;


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

void DrawObjectVectorText(std::vector<GameObject*> obj_vector) {
	int i = 0;
	for(std::vector<GameObject*>::iterator obj = obj_vector.begin(); obj != obj_vector.end(); obj++) {
		if(ImGui::TreeNode((void*) (intptr_t) i, "%s : %d", (*obj)->GetChampionName(), i)) {
			ImGui::Text("bool");
			ImGui::BulletText("IsAttackable() => %d", (*obj)->IsAttackable());
			ImGui::BulletText("IsAlive() => %d", (*obj)->IsAlive());
			ImGui::BulletText("IsEnemy() => %d", (*obj)->IsEnemy());
			ImGui::BulletText("IsTargetable() => %d", (*obj)->IsTargetable());
			//TODO: Implement Minion Type in GameObject.cpp and h
			ImGui::BulletText("IsCannon() => %d", endsWith((std::string)(*obj)->GetChampionName(), "Siege"));
			ImGui::BulletText("IsMelee() => %d", endsWith((std::string)(*obj)->GetChampionName(), "Melee"));
			ImGui::BulletText("IsRanged() => %d", endsWith((std::string)(*obj)->GetChampionName(), "Ranged"));

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

void DrawObjectVectorTree(char* label, std::vector<GameObject*> obj_vector) {
	if(ImGui::TreeNode(label)) {
		DrawObjectVectorText(obj_vector);
		ImGui::TreePop();
	}
}

static void MenuRender() {
	ImGui_ImplDX9_NewFrame();
	ImGui_ImplWin32_NewFrame();
	ImGui::NewFrame();
	if(draw_menu) {
		ImGui::Begin("Zalek League", &draw_menu, ImGuiWindowFlags_AlwaysAutoResize + ImGuiWindowFlags_MenuBar);

		if(ImGui::BeginMenuBar()) {
			if(ImGui::BeginMenu("Drawing")) {
				ImGui::Checkbox("Draw Auto Attack Range Always", &draw_attack_range);
				ImGui::EndMenu();
			}

			if(ImGui::BeginMenu("Zalek's Utilities")) {
				if(ImGui::MenuItem("Crash League"))
					exit(0);
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
				ImGui::Text("gLastMoveToTime => %f", gLastMoveTime);
				ImGui::TreePop();
			}

			if(ImGui::Button("Crash League"))
				exit(0);
			ImGui::SetNextTreeNodeOpen(true, ImGuiCond_Appearing);
			if(ImGui::TreeNode("Engine")) {
				ImGui::Text("Engine::GetMouseWorldPosition() => { x = %f, y = %f, z = %f }", Engine::GetMouseWorldPosition().X, Engine::GetMouseWorldPosition().Y, Engine::GetMouseWorldPosition().Z);
				ImGui::Text("Engine::GetGameVersion() => %s", Engine::GetGameVersion());
				ImGui::Text("Engine::GetGameTime() => %f", Engine::GetGameTime());
				ImGui::TreePop();
			}

			DrawObjectVectorTree("All Champions", gChampions);
			DrawObjectVectorTree("Attackable Champions", gAttackableChampions);
			DrawObjectVectorTree("Enemy Champions", gEnemyChampions);
			DrawObjectVectorTree("Friendly Champions", gFriendlyChampions);
			DrawObjectVectorTree("All Minions", gMinions);
			DrawObjectVectorTree("Enemy Minions", gEnemyMinions);
			DrawObjectVectorTree("Enemy Minions (Last Hit)", gLastHitMinions);
			//DrawObjectVectorTree("Friendly Minions", gMinions);
			ImGui::TreePop();
		}
		ImGui::End();
	}
	ImGui::EndFrame();
	ImGui::Render();
	ImGui_ImplDX9_RenderDrawData(ImGui::GetDrawData());
}