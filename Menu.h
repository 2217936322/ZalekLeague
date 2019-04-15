#include "ImGui/imgui.h"
#include "ImGui/imgui_impl_dx9.h"
#include "ImGui/imgui_impl_win32.h"
#include "d3d9helper.h"
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

//bool endsWith(const std::string& mainStr, const std::string& toMatch) {
//	if(mainStr.size() >= toMatch.size() &&
//		mainStr.compare(mainStr.size() - toMatch.size(), toMatch.size(), toMatch) == 0)
//		return true;
//	else
//		return false;
//}

			//TODO: Implement Minion Type in GameObject.cpp and h
			//ImGui::BulletText("IsCannon() => %d", endsWith((std::string)(*obj)->GetChampionName(), "Siege"));
			//ImGui::BulletText("IsMelee() => %d", endsWith((std::string)(*obj)->GetChampionName(), "Melee"));
			//ImGui::BulletText("IsRanged() => %d", endsWith((std::string)(*obj)->GetChampionName(), "Ranged"));

void DrawGameObjectText(std::vector<GameObject*> obj_vector) {
	int i = 0;
	for(std::vector<GameObject*>::iterator obj = obj_vector.begin(); obj != obj_vector.end(); obj++) {
		if(ImGui::TreeNode((void*) (intptr_t) i, "%s : %d | Dist = %f", (*obj)->GetUniqueName(), i, (*obj)->GetDistToMe())) {
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
			ImGui::BulletText("GetUniqueName() => %s", (*obj)->GetUniqueName());

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

void ClassicOverlay(ImVec2 screen_pos, char* text) {
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

void DarkOverlay(ImVec2 screen_pos, char* text) {
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

void LightOverlay(ImVec2 screen_pos, char* text) {
	ImGui_ImplDX9_NewFrame();
	ImGui_ImplWin32_NewFrame();
	ImGui::NewFrame();
	ImGui::StyleColorsLight();
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

void DevelopmentGUI() {
	ImGui_ImplDX9_NewFrame();
	ImGui_ImplWin32_NewFrame();
	ImGui::NewFrame();
	if(bDrawGUI) {
		//ImGui::SetNextWindowPos(ImGui::GetMousePos());
		ImGui::Begin("Zalek League", false, ImGuiWindowFlags_AlwaysAutoResize);

		ImGui::Text("ZalekLeague Compiled at %s %s\n", __DATE__, __TIME__);
		auto Q = ME->GetSpellBook()->GetQ();


		ImGui::Text("Q->IsReady() => %d", Q->IsReady());
		ImGui::Text("Q->GetLevel() => %d", Q->GetLevel());
		ImGui::Text("Q->GetCooldown() => %f", Q->GetCooldown());
		ImGui::Text("Q->GetTimeUsed() => %f", Q->GetTimeUsed());
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
	} else {
		ClassicOverlay(
			ImGui::GetMousePos(),
			"ZalekLeague is in Development Mode."
		);
	}
	ImGui::EndFrame();
	ImGui::Render();
	ImGui_ImplDX9_RenderDrawData(ImGui::GetDrawData());
}

/*
enum class SpellDataInst
{
	//
	fEffect1 = 0x80,
	fEffect2 = fEffect1 + 0x4,
	fEffect3 = fEffect2 + 0x4,
	fEffect4 = fEffect3 + 0x4,
	fEffect5 = fEffect4 + 0x4,
	fEffect6 = fEffect5 + 0x4,
	fEffect7 = fEffect6 + 0x4,
	fEffect8 = fEffect7 + 0x4,
	fEffect9 = fEffect8 + 0x4,
	fEffect10 = fEffect9 + 0x4,
	fEffect11 = fEffect10 + 0x4,
	SpellData = 0x124,
};

enum class SpellData
{
	//
	Resource = 0x38,
};

enum class SpellDataResource
{
	//
	eEffect1 = 0xD0,
	eEffect2 = eEffect1 + 0x1C,
	eEffect3 = eEffect2 + 0x1C,
	eEffect4 = eEffect3 + 0x1C,
	eEffect5 = eEffect4 + 0x1C,
	eEffect6 = eEffect5 + 0x1C,
	eEffect7 = eEffect6 + 0x1C,
	eEffect8 = eEffect7 + 0x1C,
	eEffect9 = eEffect8 + 0x1C,
	eEffect10 = eEffect9 + 0x1C,
	eEffect11 = eEffect10 + 0x1C,
	//
};


DEFINE_MEMBER_N(float eEffect1[7], Offsets::SpellDataResource::eEffect1);
DEFINE_MEMBER_N(float eEffect2[7], Offsets::SpellDataResource::eEffect2);
DEFINE_MEMBER_N(float eEffect3[7], Offsets::SpellDataResource::eEffect3);
DEFINE_MEMBER_N(float eEffect4[7], Offsets::SpellDataResource::eEffect4);
DEFINE_MEMBER_N(float eEffect5[7], Offsets::SpellDataResource::eEffect5);
DEFINE_MEMBER_N(float eEffect6[7], Offsets::SpellDataResource::eEffect6);
DEFINE_MEMBER_N(float eEffect7[7], Offsets::SpellDataResource::eEffect7);
DEFINE_MEMBER_N(float eEffect8[7], Offsets::SpellDataResource::eEffect8);
DEFINE_MEMBER_N(float eEffect9[7], Offsets::SpellDataResource::eEffect9);
DEFINE_MEMBER_N(float eEffect10[7], Offsets::SpellDataResource::eEffect10);
DEFINE_MEMBER_N(float eEffect11[7], Offsets::SpellDataResource::eEffect11);

Annie grants herself and Tibbers {{ e1 }}% damage reduction for {{ e3 }} seconds.<br><br>While the shield is active, enemies who basic attack it take {{ e2 }} <span class=\"color99FF99\">(+{{ a1 }})</span> magic damage.
*/