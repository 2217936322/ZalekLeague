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

					SpellSlot* Spell = (*obj)->GetSpellBook()->GetQ();
					ImGui::Separator();

					ImGui::Text("Q->GetActorName() => %s", Spell->GetActorName());
					ImGui::Text("Q->HasCharges() => %d", Spell->HasCharges());
					if(Spell->HasCharges()) {
						ImGui::Text("Q->GetCharge() => %d", Spell->GetCharge());
						ImGui::Text("Q->GetNextCharge() => %d", Spell->GetNextCharge());
					}
					ImGui::Text("Q->IsReady() => %d", Spell->IsReady());
					ImGui::Text("Q->GetLevel() => %d", Spell->GetLevel());
					ImGui::Text("Q->GetCooldown() => %f", Spell->GetCooldown());
					ImGui::Text("Q->GetTimeUsed() => %f", Spell->GetTimeUsed());

					Spell = (*obj)->GetSpellBook()->GetW();
					ImGui::Separator();

					ImGui::Text("W->GetActorName() => %s", Spell->GetActorName());
					ImGui::Text("W->HasCharges() => %d", Spell->HasCharges());
					if(Spell->HasCharges()) {
						ImGui::Text("W->GetCharge() => %d", Spell->GetCharge());
						ImGui::Text("W->GetNextCharge() => %d", Spell->GetNextCharge());
					}
					ImGui::Text("W->IsReady() => %d", Spell->IsReady());
					ImGui::Text("W->GetLevel() => %d", Spell->GetLevel());
					ImGui::Text("W->GetCooldown() => %f", Spell->GetCooldown());
					ImGui::Text("W->GetTimeUsed() => %f", Spell->GetTimeUsed());

					Spell = (*obj)->GetSpellBook()->GetE();
					ImGui::Separator();

					ImGui::Text("E->GetActorName() => %s", Spell->GetActorName());
					ImGui::Text("E->HasCharges() => %d", Spell->HasCharges());
					if(Spell->HasCharges()) {
						ImGui::Text("E->GetCharge() => %d", Spell->GetCharge());
						ImGui::Text("E->GetNextCharge() => %d", Spell->GetNextCharge());
					}
					ImGui::Text("E->IsReady() => %d", Spell->IsReady());
					ImGui::Text("E->GetLevel() => %d", Spell->GetLevel());
					ImGui::Text("E->GetCooldown() => %f", Spell->GetCooldown());
					ImGui::Text("E->GetTimeUsed() => %f", Spell->GetTimeUsed());

					Spell = (*obj)->GetSpellBook()->GetR();
					ImGui::Separator();

					ImGui::Text("R->GetActorName() => %s", Spell->GetActorName());
					ImGui::Text("R->HasCharges() => %d", Spell->HasCharges());
					if(Spell->HasCharges()) {
						ImGui::Text("R->GetCharge() => %d", Spell->GetCharge());
						ImGui::Text("R->GetNextCharge() => %d", Spell->GetNextCharge());
					}
					ImGui::Text("R->IsReady() => %d", Spell->IsReady());
					ImGui::Text("R->GetLevel() => %d", Spell->GetLevel());
					ImGui::Text("R->GetCooldown() => %f", Spell->GetCooldown());
					ImGui::Text("R->GetTimeUsed() => %f", Spell->GetTimeUsed());

					Spell = (*obj)->GetSpellBook()->GetD();
					ImGui::Separator();

					ImGui::Text("D->GetActorName() => %s", Spell->GetActorName());
					ImGui::Text("D->HasCharges() => %d", Spell->HasCharges());
					if(Spell->HasCharges()) {
						ImGui::Text("D->GetCharge() => %d", Spell->GetCharge());
						ImGui::Text("D->GetNextCharge() => %d", Spell->GetNextCharge());
					}
					ImGui::Text("D->IsReady() => %d", Spell->IsReady());
					ImGui::Text("D->GetLevel() => %d", Spell->GetLevel());
					ImGui::Text("D->GetCooldown() => %f", Spell->GetCooldown());
					ImGui::Text("D->GetTimeUsed() => %f", Spell->GetTimeUsed());

					Spell = (*obj)->GetSpellBook()->GetF();
					ImGui::Separator();

					ImGui::Text("F->GetActorName() => %s", Spell->GetActorName());
					ImGui::Text("F->HasCharges() => %d", Spell->HasCharges());
					if(Spell->HasCharges()) {
						ImGui::Text("F->GetCharge() => %d", Spell->GetCharge());
						ImGui::Text("F->GetNextCharge() => %d", Spell->GetNextCharge());
					}
					ImGui::Text("F->IsReady() => %d", Spell->IsReady());
					ImGui::Text("F->GetLevel() => %d", Spell->GetLevel());
					ImGui::Text("F->GetCooldown() => %f", Spell->GetCooldown());
					ImGui::Text("F->GetTimeUsed() => %f", Spell->GetTimeUsed());

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

	ImGui_ImplDX9_NewFrame();
	ImGui_ImplWin32_NewFrame();
	ImGui::NewFrame();
	ImGui::StyleColorsDark();
	ImGui::Begin("Overlay",
		false,
		ImGuiWindowFlags_NoTitleBar
		+ ImGuiWindowFlags_AlwaysAutoResize
		+ ImGuiWindowFlags_NoInputs
		+ ImGuiWindowFlags_NoMouseInputs
		+ ImGuiWindowFlags_NoMove
		+ ImGuiWindowFlags_NoScrollbar
	);
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
		ImGui::Text("ObjectManager Address: %X", baseAddr + DWORD_OBJECT_MANAGER);
		ImGui::Text("ME Address: %X", baseAddr + DWORD_LOCAL_PLAYER);

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


	std::vector<GameObject*> Champions = GetChampions();

	for(std::vector<GameObject*>::iterator Champion = Champions.begin(); Champion != Champions.end(); Champion++) {
		GameObject* obj = (*Champion);
		Vector vecWorld = Vector(obj->GetPos().X, obj->GetPos().Y, obj->GetPos().Z);
		Vector vecScreen = Vector();
		bool w2sResult = Functions.WorldToScreen(&vecWorld, &vecScreen);
		ImVec2 testVec = ImVec2(vecScreen.X, vecScreen.Y);

		ImGui::Begin(obj->GetName(),
			false,
			ImGuiWindowFlags_AlwaysAutoResize
			+ ImGuiWindowFlags_NoInputs
			+ ImGuiWindowFlags_NoMove
			+ ImGuiWindowFlags_NoScrollbar
			+ ImGuiWindowFlags_NoTitleBar);

		ImGui::SetWindowPos(
			ImVec2(
			(testVec.x - (ImGui::GetWindowSize().x / 2.0f)),
				(testVec.y - ImGui::GetWindowSize().y / -0.75f))

		);

		SpellBook * sb = obj->GetSpellBook();
		SpellSlot * Q = sb->GetQ();
		SpellSlot * W = sb->GetW();
		SpellSlot * E = sb->GetE();
		SpellSlot * R = sb->GetR();
		SpellSlot * D = sb->GetD();
		SpellSlot * F = sb->GetF();

		ImGui::Text("%s : %s", obj->GetActorName(), obj->GetName());
		//ImGui::Text("Test() => %s", Q->GetSpellInfo()->GetSpellData()->GetMissileName());


		if(Q->GetLevel() != 0 && !Q->IsReady())
			ImGui::Text("Q: %f", Q->GetCooldown());

		if(W->GetLevel() != 0 && !W->IsReady())
			ImGui::Text("W: %f", W->GetCooldown());

		if(E->GetLevel() != 0 && !E->IsReady())
			ImGui::Text("E: %f", E->GetCooldown());

		if(R->GetLevel() != 0 && !R->IsReady())
			ImGui::Text("R: %f", R->GetCooldown());

		if(D->GetLevel() != 0 && !D->IsReady())
			ImGui::Text("%s: %f", D->GetActorName(), D->GetCooldown());

		if(F->GetLevel() != 0 && !F->IsReady())
			ImGui::Text("%s: %f", F->GetActorName(), F->GetCooldown());

		ImGui::End();

	}


	//Vector vecWorld = Vector(ME->GetPos().X, ME->GetPos().Y, ME->GetPos().Z);
	//Vector vecScreen = Vector();
	//bool w2sResult = Functions.WorldToScreen(&vecWorld, &vecScreen);
	//ImVec2 testVec = ImVec2(vecScreen.X, vecScreen.Y);

	//ImGui::Begin("TestCharacterOverlay",
	//	false,
	//	ImGuiWindowFlags_AlwaysAutoResize
	//	+ ImGuiWindowFlags_NoInputs
	//	+ ImGuiWindowFlags_NoMove
	//	+ ImGuiWindowFlags_NoScrollbar
	//	+ ImGuiWindowFlags_NoTitleBar);
	//ImGui::SetWindowPos(
	//	ImVec2(
	//	(testVec.x - (ImGui::GetWindowSize().x / 2.0f)),
	//		(testVec.y - ImGui::GetWindowSize().y / -0.75f))

	//);

	//SpellBook * sb = ME->GetSpellBook();
	//SpellSlot * Q = sb->GetQ();
	//SpellSlot * W = sb->GetW();
	//SpellSlot * E = sb->GetE();
	//SpellSlot * R = sb->GetR();
	//SpellSlot * D = sb->GetD();
	//SpellSlot * F = sb->GetF();

	//ImGui::Text("%s : %s", ME->GetActorName(), ME->GetName());
	////ImGui::Text("Test() => %s", Q->GetSpellInfo()->GetSpellData()->GetMissileName());


	//if(Q->GetLevel() != 0 && !Q->IsReady())
	//	ImGui::Text("Q: %f", Q->GetCooldown());

	//if(W->GetLevel() != 0 && !W->IsReady())
	//	ImGui::Text("W: %f", W->GetCooldown());

	//if(E->GetLevel() != 0 && !E->IsReady())
	//	ImGui::Text("E: %f", E->GetCooldown());

	//if(R->GetLevel() != 0 && !R->IsReady())
	//	ImGui::Text("R: %f", R->GetCooldown());

	//if(D->GetLevel() != 0 && !D->IsReady())
	//	ImGui::Text("%s: %f", D->GetActorName(), D->GetCooldown());

	//if(F->GetLevel() != 0 && !F->IsReady())
	//	ImGui::Text("%s: %f", F->GetActorName(), F->GetCooldown());

	//ImGui::End();

	ImGui::EndFrame();
	ImGui::Render();
	ImGui_ImplDX9_RenderDrawData(ImGui::GetDrawData());
}