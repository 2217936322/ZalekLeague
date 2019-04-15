#include "GameObject.h"
#include "LFunctions.h"
#include "Engine.h"
#include "Enums/ETeam.h"
#pragma once

AIManager* GameObject::GetAIManager() {
	{
		typedef AIManager* (__thiscall * OriginalFn)(PVOID);
		return CallVirtual<OriginalFn>(this, 147)(this); // 147?
	};
}

bool GameObject::IsAttackable() {
	return this->GetDistToMe() <= (ME->GetAttackRange() + this->GetBoundingRadius())
		&& this->IsTargetable();

}

bool GameObject::IsAlive() {
	return Functions.IsAlive(this)
		&& this->GetHealth() > 0.0f;
}

//bool GameObject::IsBaron() {
//	return Functions.IsBaron(this);
//}

bool GameObject::IsDashing() {
	return *(bool*) ((DWORD) this->GetAIManager() + PTR_OBJECT_AI_IS_MOVING);
}

//bool GameObject::IsDragon() {
//	return Functions.IsDragon(this);
//}

bool GameObject::IsEnemy() {
	return (ME->GetTeam() == ETeam::ORDER && this->GetTeam() == ETeam::CHAOS || ME->GetTeam() == ETeam::CHAOS && this->GetTeam() == ETeam::ORDER);
}

bool GameObject::IsFriendly() {
	return (ME->GetTeam() == ETeam::ORDER && this->GetTeam() == ETeam::ORDER || ME->GetTeam() == ETeam::CHAOS && this->GetTeam() == ETeam::CHAOS);
}

bool GameObject::IsHero() {
	return Functions.IsHero(this);
}

bool GameObject::IsInhibitor() {
	return Functions.IsInhibitor(this);
}

bool GameObject::IsMinion() {
	return Functions.IsMinion(this);
}

bool GameObject::IsMissile() {
	return Functions.IsMissile(this);
}

bool GameObject::IsMoving() {
	return *(bool*) ((DWORD) this->GetAIManager() + PTR_OBJECT_AI_IS_MOVING);
}

bool GameObject::IsNexus() {
	return Functions.IsNexus(this);
}

bool GameObject::IsNeutral() {
	return this->GetTeam() == ETeam::NEUTRAL;
}

bool GameObject::IsTargetable() {
	return Functions.IsTargetable(this);
}

bool GameObject::IsTroyEnt() {
	return Functions.IsTroyEnt(this);
}

bool GameObject::IsTurret() {
	return Functions.IsTurret(this);
}

bool GameObject::IsVisible() {
	return *(bool*) ((DWORD) this + PTR_OBJECT_IS_VISIBLE);
}

char* GameObject::GetName() {
	return GetStr((DWORD) this + PTR_OBJECT_NAME);
};

char* GameObject::GetUniqueName() {
	return GetStr((DWORD) this + PTR_OBJECT_UNIQUE_NAME);
}

DWORD GameObject::GetNetworkID() {
	return *(DWORD*) ((DWORD) this + PTR_OBJECT_NETWORK_ID);
}

float GameObject::GetArmor() {
	return *(float*) ((DWORD) this + PTR_OBJECT_ARMOR);
}

float GameObject::GetAttackRange() {
	return *(float*) ((DWORD) this + PTR_OBJECT_ATTACK_RANGE);
}

float GameObject::GetAttackSpeed() {
	return 1 / Functions.GetAttackDelay(this);
}

float GameObject::GetBaseAttackDamage() {
	return *(float*) ((DWORD) this + PTR_OBJECT_BASE_ATTACK);
}

float GameObject::GetBonusAttackDamage() {
	return *(float*) ((DWORD) this + PTR_OBJECT_BONUS_ATTACK);
}

float GameObject::GetBoundingRadius() {
	typedef float(__thiscall * OriginalFn)(PVOID);
	return CallVirtual<OriginalFn>(this, 36)(this); //36?
}

float GameObject::GetDistToMe() {
	return this->GetPos().DistTo(ME->GetPos());
}

float GameObject::GetHealth() {
	return *(float*) ((DWORD) this + PTR_OBJECT_CURRENT_HEALTH);
}

float GameObject::GetMaxHealth() {
	return *(float*) ((DWORD) this + PTR_OBJECT_CURRENT_HEALTH + 0x10);
}

float GameObject::GetTotalAttackDamage() {
	return this->GetBonusAttackDamage() + this->GetBaseAttackDamage();
}

int GameObject::GetLevel() {
	return *(int*) ((DWORD) this + PTR_OBJECT_LEVEL);
}
int GameObject::GetTeam() {
	return *(int*) ((DWORD) this + PTR_OBJECT_TEAM);
}

short GameObject::GetIndex() {
	return *(short*) ((DWORD) this + PTR_OBJECT_INDEX);
}

short GameObject::GetSourceIndex() {
	return *(short*) ((DWORD) this + PTR_OBJECT_SOURCE_INDEX);
}

short GameObject::GetTargetIndex() {
	return *(short*) ((DWORD) this + PTR_OBJECT_TARGET_ID);
}

Vector GameObject::GetPos() {
	return *(Vector*) ((DWORD) this + PTR_OBJECT_POS);
}

Vector GameObject::GetTargetPos() {
	return *(Vector*) ((DWORD) this->GetAIManager() + PTR_OBJECT_AI_TARGETPOS);
}

Vector GameObject::GetStartPos() {
	return *(Vector*) ((DWORD) this + PTR_OBJECT_SPELL_START_POS);
}

Vector GameObject::GetEndPos() {
	return *(Vector*) ((DWORD) this + PTR_OBJECT_SPELL_END_POS);
}

Vector GameObject::GetVelocity() {
	return *(Vector*) ((DWORD) this->GetAIManager() + PTR_OBJECT_AI_VELOCITY);
}