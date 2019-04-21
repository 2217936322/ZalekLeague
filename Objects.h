#include <vector>
#include "GameObject.h"
#include "Engine.h"
#include "Enums/ETeam.h"
#pragma once

class AIManager;
class BuffManager;
class Champion;
Champion* Me();


class Champion : GameObject
{
public:
	DWORD GetAddress() {
		return (DWORD) this;
	}

	//int SpellSlot::GetSpellInfoAddress() {
	//	return *(int*) ((DWORD) this + 0x12C);
	//}

#pragma region AIManager

	AIManager* GetAIManager() {
		typedef AIManager* (__thiscall * OriginalFn)(PVOID);
		return CallVirtual<OriginalFn>((GameObject*) this, 147)((GameObject*) this);
	}

#pragma endregion


#pragma region BuffManager
	// 'ASSETS/Perks/Styles/Sorcery/ManaflowBand/PerkManaflowBandBuff.lu'
	// 50 65 72 6b 4d 61 6e 61 66 6c 6f 77 42 61 6e 64 42 75 66 66
	// veigarphenomenalevilpower 
	// 76 65 69 67 61 72 70 68 65 6e 6f 6d 65 6e 61 6c 65 76 69 6c 70 6f 77 65 72

	DWORD GetBuffArrayAddress() {
		return (DWORD) this + O_BUFF_MGR + 0x10;
	}

	unsigned long GetBuffArrayStart() {
		return *(unsigned long*) this->GetBuffArrayAddress();
	}

	unsigned long GetBuffListStart() {
		return *(unsigned long*) this->GetBuffArrayStart();
	}

	unsigned long GetBuffListEnd() {
		return this->GetBuffArrayEnd() - 0x04;
	}

	DWORD GetBuffArrayEndAddress() {
		return (DWORD) this + O_BUFF_MGR + 0x14;
	}

	unsigned long GetBuffArrayEnd() {
		return *(unsigned long*) this->GetBuffArrayEndAddress();
	}

#pragma endregion


#pragma region bool

	bool IsChampion() {
		return Functions.IsHero((GameObject*) this);
	}

	bool IsDashing() {
		return *(bool*) ((DWORD) this->GetAIManager() + PTR_OBJECT_AI_IS_DASHING);
	}

	bool IsEnemy() {
		return (Me()->GetTeam() == ETeam::ORDER && this->GetTeam() == ETeam::CHAOS
			|| Me()->GetTeam() == ETeam::CHAOS && this->GetTeam() == ETeam::ORDER);
	}

	bool IsFriendly() {
		return (Me()->GetTeam() == ETeam::ORDER && this->GetTeam() == ETeam::ORDER
			|| Me()->GetTeam() == ETeam::CHAOS && this->GetTeam() == ETeam::CHAOS);
	}

	bool IsMoving() {
		return *(bool*) ((DWORD) this->GetAIManager() + PTR_OBJECT_AI_IS_MOVING);
	}

	bool IsTargetable() {
		return Functions.IsTargetable((GameObject*) this);
	}


#pragma endregion


#pragma region char*

	char* GetActorName() {
		return GetStr((DWORD) this + O_ACTOR_NAME);
	}

	char* GetName() {
		return GetStr((DWORD) this + O_NAME);
	}

	char* GetRecallName() {
		return GetStr((DWORD) this + O_RECALL_NAME);
	}

#pragma endregion


#pragma region DWORD

	DWORD GetNetworkID() {
		return *(DWORD*) ((DWORD) this + O_NETWORK_ID);
	}

#pragma endregion


#pragma region float
	float GetArmor() {
		return *(float*) ((DWORD) this + O_ARMOR);
	}

	float GetAttackCastDelay() {
		return Functions.GetAttackCastDelay((GameObject*) this);
	}

	float GetAttackDamage() {
		return this->GetBonusAttackDamage() + this->GetBaseAttackDamage();
	}

	float GetAbilityPower() {
		return *(float*) ((DWORD) this + O_BONUS_AP);
	}

	float GetAttackDelay() {
		return Functions.GetAttackDelay((GameObject*) this);
	}

	float GetAttackRange() {
		return *(float*) ((DWORD) this + O_ATTACK_RANGE);
	}

	float GetAttackSpeed() {
		return 1 / Functions.GetAttackDelay((GameObject*) this);
	}

	float GetBaseAttackDamage() {
		return *(float*) ((DWORD) this + O_BASE_AD);
	}

	float GetBonusAttackDamage() {
		return *(float*) ((DWORD) this + O_BONUS_AD);
	}

	float GetCollisionRadius() {
		typedef float(__thiscall * OriginalFn)(PVOID);
		return CallVirtual<OriginalFn>((GameObject*) this, 36)((GameObject*) this);
	}

	//float GetCooldownReduction() {
	//	return *(float*) ((DWORD) this + O_CRIT_RATE) * 100;
	//}

	float GetCritChance() {
		return *(float*) ((DWORD) this + O_CRIT_RATE) * 100;
	}

	float GetDistToMe() {
		return this->GetPos().DistTo(Me()->GetPos());
	}

	float GetHealth() {
		return *(float*) ((DWORD) this + O_HEALTH);
	}

	float GetMaxHealth() {
		return *(float*) ((DWORD) this + O_MAX_HEALTH);
	}

	float GetHealthPercent() {
		return (this->GetHealth() / this->GetMaxHealth()) * 100;
	}

	float GetMagicResist() {
		return *(float*) ((DWORD) this + O_MAGIC_RESIST);
	}

	float GetMana() {
		return *(float*) ((DWORD) this + O_MANA);
	}

	float GetMaxMana() {
		return *(float*) ((DWORD) this + O_MAX_MANA);
	}

	float GetManaPercent() {
		return (this->GetMana() / this->GetMaxMana()) * 100;
	}

	float GetMoveSpeed() {
		return *(float*) ((DWORD) this + O_MOVE_SPEED);
	}

#pragma endregion


#pragma region int32

	int GetLevel() {
		return *(int*) ((DWORD) this + O_LEVEL);
	}

	int GetTeam() {
		return *(int*) ((DWORD) this + O_TEAM);
	}

	int GetRecallState() {
		return *(int*) ((DWORD) this + O_RECALL_STATE);
	}

#pragma endregion


#pragma region int16

	short GetIndex() {
		return *(short*) ((DWORD) this + O_INDEX);
	}

#pragma endregion


#pragma region SpellBook

	SpellBook* GetSpellBook() {
		return (SpellBook*) ((DWORD) this + O_SPELLBOOK);
	}

#pragma endregion


#pragma region Vector

	Vector GetPos() {
		return *(Vector*) ((DWORD) this + O_POS);
	}

	Vector GetWaypoint() {
		return *(Vector*) ((DWORD) this->GetAIManager() + PTR_OBJECT_AI_WAYPOINT);
	}

#pragma endregion

};


Champion* Me() {
	return (Champion*)* (DWORD*) (baseAddr + DWORD_LOCAL_PLAYER);
}