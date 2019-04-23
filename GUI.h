#include <d3d9.h>
#include "Objects.h"
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
	void BuffText(Champion::Buff* buff) {
		//if(ImGui::TreeNode(
		//	(void*) (intptr_t) (spell_slot->GetActorName()),
		//	"%s", spell_slot->GetActorName())) {

		//ImGui::BulletText("GetName() => %s", buff->GetName());
		//ImGui::TreePop();
		/*	}*/
	}

	void SpellText(SpellSlot* spell_slot) {
		if(ImGui::TreeNode(
			(void*) (intptr_t) (spell_slot->GetActorName()),
			"%s", spell_slot->GetActorName())) {

			ImGui::BulletText("IsMultiChargeSpell() => %d", spell_slot->IsMultiChargeSpell());
			ImGui::BulletText("IsReady() => %d", spell_slot->IsReady());
			ImGui::BulletText("GetActorName() => %d", spell_slot->GetActorName());
			ImGui::BulletText("GetRank() => %d", spell_slot->GetRank());
			ImGui::BulletText("GetCooldown() => %f", spell_slot->GetCooldown());
			ImGui::BulletText("GetTimeUsed() => %f", spell_slot->GetTimeUsed());
			ImGui::BulletText("GetCharge() => %d", spell_slot->GetCharge());
			ImGui::BulletText("GetNextCharge() => %d", spell_slot->GetNextCharge());
			ImGui::TreePop();
		}
	}

	void ChampionText(Champion* champion) {
		ImGui::Text("GetNetworkID() => %X", champion->GetNetworkID());
		ImGui::Text("GetIndex() => %hu", champion->GetIndex());

		ImGui::Indent();
		if(ImGui::CollapsingHeader("Buffs")) {
			std::vector<Champion::Buff*> Buffs = champion->GetBuffs();
			int iBuffCount = Buffs.size();
			if(!Buffs.empty())
				ImGui::Text("Buff Count: %d", iBuffCount);
			else
				ImGui::Text("Buff Count: 0");

			for(std::vector<Champion::Buff*>::iterator buff = Buffs.begin();
				buff != Buffs.end(); buff++) {
				Champion::Buff* _buff = (*buff);

				if(ImGui::TreeNode(
					(void*) (intptr_t) _buff->GetAddress(),
					"%X : %X", _buff->GetAddress(), _buff->GetBuffPointer())) {
					ImGui::BulletText("fAddressValid() => %f", _buff->fAddressValidiation());
					//ImGui::BulletText("fBuffPointerValid() => %f", _buff->fBuffPointerValid());
					//ImGui::BulletText("IsValid() => %d", _buff->IsValid());
					//ImGui::BulletText("GetNameType() => %s", _buff->GetNameType());
					ImGui::BulletText("GetName() => %s", _buff->GetName());
					ImGui::TreePop();
				}
			}

			if(iBuffCount > 500)
				Buffs.clear();


			//ImGui::Text("First Buff %X", champion->GetFirstBuff()->GetAddress());
			//ImGui::Text("Last Buff %X", champion->GetLastBuff()->GetAddress());

		}

		if(ImGui::CollapsingHeader("SpellBook")) {
			SpellBook* SpellBook = champion->GetSpellBook();
			SpellText(SpellBook->Get((int) ESpellSlot::Q));
			SpellText(SpellBook->Get((int) ESpellSlot::W));
			SpellText(SpellBook->Get((int) ESpellSlot::E));
			SpellText(SpellBook->Get((int) ESpellSlot::R));
			SpellText(SpellBook->Get((int) ESpellSlot::D));
			SpellText(SpellBook->Get((int) ESpellSlot::F));
		}
		ImGui::Unindent();

		ImGui::SetNextTreeNodeOpen(true, ImGuiCond_Appearing);
		if(ImGui::TreeNode("Strings")) {
			ImGui::BulletText("GetActorName() => %s", champion->GetActorName());
			ImGui::BulletText("GetName() => %s", champion->GetName());
			ImGui::BulletText("GetRecallName() => %s", champion->GetRecallName());
			ImGui::TreePop();
		}

		ImGui::SetNextTreeNodeOpen(true, ImGuiCond_Appearing);
		if(ImGui::TreeNode("Booleans")) {
			ImGui::BulletText("IsDashing() => %d", champion->IsDashing());
			ImGui::BulletText("IsEnemy() => %d", champion->IsEnemy());
			ImGui::BulletText("IsFriendly() => %d", champion->IsFriendly());
			ImGui::BulletText("IsMoving() => %d", champion->IsMoving());
			ImGui::BulletText("IsTargetable() => %d", champion->IsTargetable());
			//ImGui::BulletText("IsVisible() => %d", champion->IsVisible());
			ImGui::TreePop();
		}

		ImGui::SetNextTreeNodeOpen(true, ImGuiCond_Appearing);
		if(ImGui::TreeNode("Ints")) {
			ImGui::BulletText("GetLevel() => %d", champion->GetLevel());
			ImGui::BulletText("GetTeam() => %d", champion->GetTeam());
			ImGui::BulletText("GetRecallState() => %d", champion->GetRecallState());
			ImGui::TreePop();
		}

		ImGui::SetNextTreeNodeOpen(true, ImGuiCond_Appearing);
		if(ImGui::TreeNode("Floats")) {

			ImGui::SetNextTreeNodeOpen(true, ImGuiCond_Appearing);
			if(ImGui::TreeNode(
				(void*) (intptr_t) (champion->GetIndex() * champion->GetAttackDamage()),
				"Attack Damage Stats %s : %d", champion->GetActorName(), champion->GetIndex())) {

				ImGui::BulletText("GetAttackDamage() => %f", champion->GetAttackDamage());
				ImGui::BulletText("GetBaseAttackDamage() => %f", champion->GetBaseAttackDamage());
				ImGui::BulletText("GetBonusAttackDamage() => %f", champion->GetBonusAttackDamage());

				ImGui::BulletText("GetAttackRange() => %f", champion->GetAttackRange());
				ImGui::BulletText("GetAttackCastDelay() => %f", champion->GetAttackCastDelay());
				ImGui::BulletText("GetAttackDelay() => %f", champion->GetAttackDelay());
				ImGui::BulletText("GetAttackSpeed() => %f", champion->GetAttackSpeed());

				ImGui::BulletText("GetCritChance() => %f", champion->GetCritChance());
				ImGui::TreePop();
			}

			ImGui::SetNextTreeNodeOpen(true, ImGuiCond_Appearing);
			if(ImGui::TreeNode(
				(void*) (intptr_t) (champion->GetIndex() * champion->GetHealth()),
				"Tank Stats %s : %d", champion->GetActorName(), champion->GetIndex())) {
				ImGui::BulletText("GetArmor() => %f", champion->GetArmor());
				ImGui::BulletText("GetMagicResist() => %f", champion->GetMagicResist());

				ImGui::BulletText("GetHealth() => %f", champion->GetHealth());
				ImGui::BulletText("GetMaxHealth() => %f", champion->GetMaxHealth());
				ImGui::BulletText("GetHealthPercent() => %f", champion->GetHealthPercent());

				ImGui::BulletText("GetMana() => %f", champion->GetMana());
				ImGui::BulletText("GetMaxMana() => %f", champion->GetMaxMana());
				ImGui::BulletText("GetManaPercent() => %f", champion->GetManaPercent());

				ImGui::TreePop();
			}

			ImGui::BulletText("GetAbilityPower() => %f", champion->GetAbilityPower());
			ImGui::BulletText("GetCollisionRadius() => %f", champion->GetCollisionRadius());
			ImGui::BulletText("GetDistToMe() => %f", champion->GetDistToMe());
			ImGui::BulletText("GetMoveSpeed() => %f", champion->GetMoveSpeed());

			ImGui::TreePop();
		}

		ImGui::SetNextTreeNodeOpen(true, ImGuiCond_Appearing);
		if(ImGui::TreeNode("Vectors")) {
			Vector Pos = champion->GetPos();
			ImGui::BulletText("GetPos() => Vector\nx = %f\n y = %f\n z = %f", Pos.X, Pos.Y, Pos.Z);
			Pos = champion->GetWaypoint();
			ImGui::BulletText("GetWaypoint() => Vector\nx = %f\n y = %f\n z = %f", Pos.X, Pos.Y, Pos.Z);
			ImGui::TreePop();
		}
	}

	void DebugOverlay() {
		if(ME && DEVELOPMENT_INTERFACES) {
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

	void ClientInformationTree() {
		ImGui::SetNextTreeNodeOpen(true, ImGuiCond_Appearing);
		if(ImGui::CollapsingHeader("Client Information")) {
			ImGui::Indent();
			ImGui::SetNextTreeNodeOpen(true, ImGuiCond_Appearing);
			if(ImGui::CollapsingHeader("ReClass Addresses")) {
				ImGui::PushItemWidth(64);

				char _base[16]; sprintf_s(_base, "%X", baseAddr);
				ImGui::InputText("Base", _base, 16, ImGuiInputTextFlags_ReadOnly);

				char _om[16]; sprintf_s(_om, "%X", baseAddr + DWORD_OBJECT_MANAGER);
				ImGui::InputText("Object Manager", _om, 16, ImGuiInputTextFlags_ReadOnly);

				//unsigned long me = baseAddr + DWORD_LOCAL_PLAYER;

				char _me[16]; sprintf_s(_me, "%X", Me()->GetAddress());
				ImGui::InputText("My Player", _me, 16, ImGuiInputTextFlags_ReadOnly);

				//char _me_bm[16]; sprintf_s(_me_bm, "%X", Me()->GetBuffManager());
				//ImGui::InputText("Buff Manager", _me_bm, 16, ImGuiInputTextFlags_ReadOnly);

				char _me_basa[16]; sprintf_s(_me_basa, "%X", Me()->GetBuffArrayAddress());
				ImGui::InputText("Buff Array Address", _me_basa, 16, ImGuiInputTextFlags_ReadOnly);

				char _me_bas[16]; sprintf_s(_me_bas, "%X", Me()->GetBuffArrayStart());
				ImGui::InputText("Buff Array Start", _me_bas, 16, ImGuiInputTextFlags_ReadOnly);

				char _me_bls[16]; sprintf_s(_me_bls, "%X", Me()->GetBuffListStart());
				ImGui::InputText("Buff List Start", _me_bls, 16, ImGuiInputTextFlags_ReadOnly);

				char _me_ble[16]; sprintf_s(_me_ble, "%X", Me()->GetBuffListEnd());
				ImGui::InputText("Buff List End", _me_ble, 16, ImGuiInputTextFlags_ReadOnly);

				char _me_baea[16]; sprintf_s(_me_baea, "%X", Me()->GetBuffArrayEndAddress());
				ImGui::InputText("Buff Array End Address", _me_baea, 16, ImGuiInputTextFlags_ReadOnly);

				char _me_bae[16]; sprintf_s(_me_bae, "%X", Me()->GetBuffArrayEnd());
				ImGui::InputText("Buff Array End", _me_bae, 16, ImGuiInputTextFlags_ReadOnly);

				//char _me_baepp[16]; sprintf_s(_me_baepp, "%X", Me()->GetBuffArrayEndPtr());
				//ImGui::InputText("Buff Array End Pointer Pointer", _me_baepp, 16, ImGuiInputTextFlags_ReadOnly);

				//char _barr_s[16]; sprintf_s(_barr_s, "%X",
				//	baseAddr + me + O_BUFF_MGR);
				//ImGui::InputText("Buff Array Start", _barr_s, 16, ImGuiInputTextFlags_ReadOnly);

				//char _me_sb[16]; sprintf_s(_me_sb, "%X", baseAddr + DWORD_LOCAL_PLAYER + O_SPELLBOOK);
				//ImGui::InputText("My SpellBook", _me_sb, 16, ImGuiInputTextFlags_ReadOnly);


				ImGui::PopItemWidth();
			}

			if(ImGui::CollapsingHeader("Input")) {
				ImGui::Text("InputHandler* Input = new InputHandler;");
				Vector mw = Input->GetMouseWorld();
				ImGui::BulletText("Input->GetMouseWorld() =>\n x = %f,\n y = %f,\n z = %f", mw.X, mw.Y, mw.Z);
			}
			ImGui::Unindent();
		}
	}

	void Devkit() {
		if(Me() && Engine::GetGameTime() > 1.0f && DEVELOPMENT_INTERFACES) {
			if(bShowDevkit) {
				DebugOverlay();
				ImGui::Begin("Zalek Devkit", &bShowDevkit, ImGuiWindowFlags_AlwaysAutoResize);
				{
					ClientInformationTree();

					if(ImGui::CollapsingHeader("Object Manager##ObjManagerTreeNode")) {
						ImGui::Text("GameObjectManager* ObjectManager;");
						ImGui::BulletText("ObjectManager->HighestIndex => %d", ObjectManager->HighestIndex);
						ImGui::BulletText("ObjectManager->Size => %d", ObjectManager->Size);
						ImGui::BulletText("ObjectManager->MaxSize => %d", ObjectManager->MaxSize);
					}

					ImGui::SetNextTreeNodeOpen(true, ImGuiCond_Appearing);
					if(ImGui::CollapsingHeader("Champions")) {
						ImGui::SetNextTreeNodeOpen(true, ImGuiCond_Appearing);
						ImGui::Indent();
						if(ImGui::CollapsingHeader("Me")) {
							ChampionText(Me());
						}
						ImGui::Unindent();
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