#include "ImGui/imgui.h"
#include "ImGui/imgui_impl_dx9.h"
#include "ImGui/imgui_impl_win32.h"
#include "WndProc.h"
#include <vector>
#include "Objects.h"
#pragma once

bool bDrawGUI = true;

static void InitializeImGuiContext(HWND Chwnd, IDirect3DDevice9* CDevice) {
	HWND hwnd = Chwnd;
	IDirect3DDevice9* Device = CDevice;
	//IMGUI_CHECKVERSION();
	ImGui::CreateContext();
	ImGuiIO& io = ImGui::GetIO();
	(void) io;
	ImGui::GetIO().ConfigFlags |= ImGuiConfigFlags_NoMouseCursorChange;
	ImGui_ImplWin32_Init(hwnd);
	ImGui_ImplDX9_Init(Device);

}

void DrawGameObjectText(std::vector<GameObject*> obj_vector) {
	int i = 0;
	for(std::vector<GameObject*>::iterator obj = obj_vector.begin(); obj != obj_vector.end(); obj++) {
		if(ImGui::TreeNode((void*) (intptr_t) i, "%s : %d | Dist = %f", (*obj)->GetActorName(), i, (*obj)->GetDistToMe())) {

			if((*obj)->IsHero()) {
				if(ImGui::TreeNode("SpellBook")) {
					SpellSlot* Q = (*obj)->GetSpellBook()->GetQ();
					ImGui::Separator();
					ImGui::Text("Q->IsReady() => %d", Q->IsReady());
					ImGui::Text("Q->GetLevel() => %d", Q->GetLevel());
					ImGui::Text("Q->GetCooldown() => %f", Q->GetCooldown());
					ImGui::Text("Q->GetTimeUsed() => %f", Q->GetTimeUsed());

					SpellSlot* W = (*obj)->GetSpellBook()->GetW();
					ImGui::Separator();
					ImGui::Text("W->IsReady() => %d", W->IsReady());
					ImGui::Text("W->GetLevel() => %d", W->GetLevel());
					ImGui::Text("W->GetCooldown() => %f", W->GetCooldown());
					ImGui::Text("W->GetTimeUsed() => %f", W->GetTimeUsed());

					SpellSlot* E = (*obj)->GetSpellBook()->GetE();
					ImGui::Separator();
					ImGui::Text("E->IsReady() => %d", E->IsReady());
					ImGui::Text("E->GetLevel() => %d", E->GetLevel());
					ImGui::Text("E->GetCooldown() => %f", E->GetCooldown());
					ImGui::Text("E->GetTimeUsed() => %f", E->GetTimeUsed());

					SpellSlot* R = (*obj)->GetSpellBook()->GetR();
					ImGui::Separator();
					ImGui::Text("R->IsReady() => %d", R->IsReady());
					ImGui::Text("R->GetLevel() => %d", R->GetLevel());
					ImGui::Text("R->GetCooldown() => %f", R->GetCooldown());
					ImGui::Text("R->GetTimeUsed() => %f", R->GetTimeUsed());
					ImGui::TreePop();
				}
			}

			ImGui::Text("bool");
			ImGui::BulletText("IsAttackable() => %d", (*obj)->IsAttackable());
			ImGui::BulletText("IsAlive() => %d", (*obj)->IsAlive());
			ImGui::BulletText("IsDashing() => %d", (*obj)->IsDashing());
			ImGui::BulletText("IsEnemy() => %d", (*obj)->IsEnemy());
			ImGui::BulletText("IsFriendly() => %d", (*obj)->IsFriendly());
			ImGui::BulletText("IsHero() => %d", (*obj)->IsHero());
			ImGui::BulletText("IsInhibitor() => %d", (*obj)->IsInhibitor());
			ImGui::BulletText("IsMinion() => %d", (*obj)->IsMinion());
			ImGui::BulletText("IsMissile() => %d", (*obj)->IsMissile());
			ImGui::BulletText("IsMoving() => %d", (*obj)->IsMoving());
			ImGui::BulletText("IsNexus() => %d", (*obj)->IsNexus());
			ImGui::BulletText("IsNeutral() => %d", (*obj)->IsNeutral());
			ImGui::BulletText("IsTargetable() => %d", (*obj)->IsTargetable());
			ImGui::BulletText("IsTroyEnt() => %d", (*obj)->IsTroyEnt());
			ImGui::BulletText("IsTurret() => %d", (*obj)->IsTurret());
			ImGui::BulletText("IsVisible() => %d", (*obj)->IsVisible());

			ImGui::Text("char*");
			ImGui::BulletText("GetName() => %s", (*obj)->GetName());
			ImGui::BulletText("GetUniqueName() => %s", (*obj)->GetActorName());

			ImGui::Text("DWORD");
			ImGui::BulletText("GetNetworkID() => %lu", (*obj)->GetNetworkID());

			ImGui::Text("float");
			ImGui::BulletText("GetArmor() => %f", (*obj)->GetArmor());
			ImGui::BulletText("GetAttackRange() => %f", (*obj)->GetAttackRange());
			ImGui::BulletText("GetAttackSpeed() => %f", (*obj)->GetAttackSpeed());
			ImGui::BulletText("GetBaseAttackDamage() => %f", (*obj)->GetBaseAttackDamage());
			ImGui::BulletText("GetBonusAttackDamage() => %f", (*obj)->GetBonusAttackDamage());
			ImGui::BulletText("GetBoundingRadius() => %f", (*obj)->GetBoundingRadius());
			ImGui::BulletText("GetHealth() => %f", (*obj)->GetHealth());
			ImGui::BulletText("GetMaxHealth() => %f", (*obj)->GetMaxHealth());
			ImGui::BulletText("GetTotalAttackDamage() => %f", (*obj)->GetTotalAttackDamage());

			ImGui::Text("int");
			ImGui::BulletText("GetLevel() => %hu", (*obj)->GetLevel());
			ImGui::BulletText("GetTeam() => %d", (*obj)->GetTeam());

			ImGui::Text("short");
			ImGui::BulletText("GetIndex() => %hu", (*obj)->GetIndex());
			ImGui::BulletText("GetSourceIndex() => %hu", (*obj)->GetSourceIndex());
			ImGui::BulletText("GetTargetIndex() => %hu", (*obj)->GetTargetIndex());

			ImGui::Text("Vector");
			ImGui::BulletText("GetPos() => (%f, %f, %f)",
				(*obj)->GetPos().X, (*obj)->GetPos().Y, (*obj)->GetPos().Z);
			ImGui::BulletText("GetTargetPos() => (%f, %f, %f)",
				(*obj)->GetTargetPos().X, (*obj)->GetTargetPos().Y, (*obj)->GetTargetPos().Z);
			ImGui::BulletText("GetStartPos() => (%f, %f, %f)",
				(*obj)->GetStartPos().X, (*obj)->GetStartPos().Y, (*obj)->GetStartPos().Z);
			ImGui::BulletText("GetEndPos() => (%f, %f, %f)",
				(*obj)->GetEndPos().X, (*obj)->GetEndPos().Y, (*obj)->GetEndPos().Z);
			ImGui::BulletText("GetVelocity() => (%f, %f, %f)",
				(*obj)->GetVelocity().X, (*obj)->GetVelocity().Y, (*obj)->GetVelocity().Z);
			ImGui::BulletText("GetVelocity().Normalize() => (%f, %f, %f)",
				(*obj)->GetVelocity().Normalize().X, (*obj)->GetVelocity().Normalize().Y, (*obj)->GetVelocity().Normalize().Z);
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

void Overlay(ImVec2 screen_pos, char* text) {
	if(!bDrawGUI) {
		ImGui_ImplDX9_NewFrame();
		ImGui_ImplWin32_NewFrame();
		ImGui::NewFrame();
		ImGui::Begin("Overlay",
			false,
			ImGuiWindowFlags_NoTitleBar
			+ ImGuiWindowFlags_NoResize
			+ ImGuiWindowFlags_NoMove
			+ ImGuiWindowFlags_NoScrollbar
			+ ImGuiWindowFlags_NoBackground);
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
}

void ClassicOverlay(ImVec2 screen_pos, char* text) {
	if(!bDrawGUI) {
		ImGui_ImplDX9_NewFrame();
		ImGui_ImplWin32_NewFrame();
		ImGui::NewFrame();
		ImGui::StyleColorsClassic();
		ImGui::Begin("Overlay",
			false,
			ImGuiWindowFlags_NoTitleBar
			+ ImGuiWindowFlags_NoResize
			+ ImGuiWindowFlags_NoMove
			+ ImGuiWindowFlags_NoScrollbar);
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
}

void DarkOverlay(ImVec2 screen_pos, char* text) {
	if(!bDrawGUI) {
		ImGui_ImplDX9_NewFrame();
		ImGui_ImplWin32_NewFrame();
		ImGui::NewFrame();
		ImGui::StyleColorsDark();
		ImGui::Begin("Overlay",
			false,
			ImGuiWindowFlags_NoTitleBar
			+ ImGuiWindowFlags_NoResize
			+ ImGuiWindowFlags_NoMove
			+ ImGuiWindowFlags_NoScrollbar);
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
}

void DevelopmentGUI() {
	ImGui_ImplDX9_NewFrame();
	ImGui_ImplWin32_NewFrame();
	ImGui::NewFrame();
	if(bDrawGUI) {

		ImGui::Begin("Zalek League", &bDrawGUI, ImGuiWindowFlags_AlwaysAutoResize);

		ImGui::Text("ZalekLeague Compiled at %s %s\n", __DATE__, __TIME__);

		RECT rect;
		if(GetWindowRect(FindWindow(NULL, "League of Legends (TM) Client"), &rect)) {
			int width = rect.right - rect.left;
			int height = rect.bottom - rect.top;
			ImGui::Text("Window Dimensions = (%d, %d)", width, height);
		}

		Vector vecWorld = Vector(ME->GetPos().X, ME->GetPos().Y, ME->GetPos().Z);
		Vector vecScreen = Vector();
		bool w2sResult = Functions.WorldToScreen(&vecWorld, &vecScreen);
		ImVec2 testVec = ImVec2(vecScreen.X, vecScreen.Y);

		ImGui::Text("World To Screen (%f, %f)",
			vecScreen.X,
			vecScreen.Y);

		ImGui::Text("Mouse (%f, %f)",
			ImGui::GetMousePos().x,
			ImGui::GetMousePos().y);

		ImGui::Text("Base Address: %X", baseAddr);
		ImGui::Text("ME Address: %X", baseAddr + DWORD_LOCAL_PLAYER);
		ImGui::Text("ObjectManager Address: %X", baseAddr + DWORD_OBJECT_MANAGER);

		std::vector<GameObject*> Me;
		Me.push_back(ME);

		DrawGameObjectTree("My Champion", Me);

		DrawGameObjectTree("All Champions", GetChampions());
		DrawGameObjectTree("Enemy Champions", GetEnemyChampions());
		DrawGameObjectTree("Friendly Champions", GetFriendlyChampions());

		DrawGameObjectTree("All Minions", GetMinions());
		DrawGameObjectTree("Enemy Minions", GetEnemyMinions());
		DrawGameObjectTree("Friendly Minions", GetFriendlyMinions());

		DrawGameObjectTree("Monsters", GetMonsters());


		ImGui::End();
	}
	ImGui::EndFrame();
	ImGui::Render();
	ImGui_ImplDX9_RenderDrawData(ImGui::GetDrawData());
}