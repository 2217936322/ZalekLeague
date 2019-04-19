#include <vector>
#include "GameObject.h"
#include "Engine.h"
#include "Enums/ETeam.h"
#pragma once

class AIManager;
class Champion;
Champion* Me();


class Champion : GameObject
{
public:
	AIManager* GetAIManager() {
		typedef AIManager* (__thiscall * OriginalFn)(PVOID);
		return CallVirtual<OriginalFn>((GameObject*) this, 147)((GameObject*) this);
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

	//bool IsVisible() {
	//	return *(bool*) ((DWORD) this + PTR_OBJECT_IS_VISIBLE);
	//}

	char* GetActorName() {
		return GetStr((DWORD) this + PTR_OBJECT_ACTOR_NAME);
	}

	char* GetName() {
		return GetStr((DWORD) this + PTR_OBJECT_NAME);
	}

	//DWORD GetNetworkID();

	//float GetAbilityPower();


	float GetArmor() {
		return *(float*) ((DWORD) this + PTR_OBJECT_ARMOR);
	}

	float GetAttackCastDelay() {
		return Functions.GetAttackCastDelay((GameObject*) this);
	}

	float GetAttackDamage() {
		return this->GetBonusAttackDamage() + this->GetBaseAttackDamage();
	}

	float GetAttackDelay() {
		return Functions.GetAttackDelay((GameObject*) this);
	}

	float GetAttackRange() {
		return *(float*) ((DWORD) this + PTR_OBJECT_ATTACK_RANGE);
	}

	float GetAttackSpeed() {
		return 1 / Functions.GetAttackDelay((GameObject*) this);
	}

	float GetBaseAttackDamage() {
		return *(float*) ((DWORD) this + PTR_OBJECT_BASE_ATTACK);
	}

	float GetBonusAttackDamage() {
		return *(float*) ((DWORD) this + PTR_OBJECT_BONUS_ATTACK);
	}

	float GetCollisionRadius() {
		typedef float(__thiscall * OriginalFn)(PVOID);
		return CallVirtual<OriginalFn>((GameObject*) this, 36)((GameObject*) this);
	}

	float GetDistToMe() {
		return this->GetPos().DistTo(Me()->GetPos());
	}

	float GetHealth() {
		return *(float*) ((DWORD) this + PTR_OBJECT_CURRENT_HEALTH);
	}

	float GetMaxHealth() {
		return *(float*) ((DWORD) this + PTR_OBJECT_CURRENT_HEALTH + 0x10);
	}

	int GetLevel() {
		return *(int*) ((DWORD) this + PTR_OBJECT_LEVEL);
	}

	int GetTeam() {
		return *(int*) ((DWORD) this + PTR_OBJECT_TEAM);
	}

	short GetIndex() {
		return *(short*) ((DWORD) this + PTR_OBJECT_INDEX);
	}

	//short GetSourceIndex();
	//short GetTargetIndex() {
	//	return *(short*) ((DWORD) this + PTR_OBJECT_TARGET_INDEX);
	//}

	//SpellBook* GetSpellBook();

	Vector GetPos() {
		return *(Vector*) ((DWORD) this + PTR_OBJECT_POS);
	}

	Vector GetWaypoint() {
		return *(Vector*) ((DWORD) this->GetAIManager() + PTR_OBJECT_AI_WAYPOINT);
	}
	//Vector GetStartPos();
	//Vector GetEndPos();
	//Vector GetVelocity();

};


Champion* Me() {
	return (Champion*)* (DWORD*) (baseAddr + DWORD_LOCAL_PLAYER);
}

//
//std::vector<GameObject*> GetChampions();
//std::vector<GameObject*> GetEnemyChampions();
//std::vector<GameObject*> GetFriendlyChampions();
//
////std::vector<GameObject*> GetBaron();
////std::vector<GameObject*> GetDragon();
//
//std::vector<GameObject*> GetMinions();
//std::vector<GameObject*> GetEnemyMinions();
//std::vector<GameObject*> GetFriendlyMinions();
//
//std::vector<GameObject*> GetMonsters();
//
//std::vector<GameObject*> GetMissiles();
//std::vector<GameObject*> GetEnemyMissiles();
//std::vector<GameObject*> GetFriendlyMissiles();
//
//std::vector<GameObject*> GetTroyEnts();
//std::vector<GameObject*> GetEnemyTroyEnts();
//std::vector<GameObject*> GetFriendlyTroyEnts();