#include "Utils.h"
#include "Vector.h"
#include "Spells.h"
#pragma once

class AIManager {};

class Actor
{
public:
	AIManager* GetAIManager();

	bool IsAttackable();
	bool IsAlive();
	//bool IsBaron();
	bool IsDashing();
	//bool IsDragon();
	bool IsEnemy();
	bool IsFriendly();
	bool IsHero();
	//bool IsInhibitor();
	bool IsMinion();
	bool IsMissile();
	bool IsMoving();
	//bool IsNexus();
	bool IsNeutral();
	bool IsTargetable();
	//bool IsTroyEnt();
	//bool IsTurret();
	bool IsVisible();

	char* GetControllerName();
	char* GetName();

	DWORD GetNetworkID();

	float GetArmor();
	float GetAttackRange();
	float GetAttackSpeed();
	float GetBaseAttackDamage();
	float GetBonusAttackDamage();
	float GetBoundingRadius();
	float GetDistToMe();
	float GetHealth();
	float GetMaxHealth();
	float GetTotalAttackDamage();


	int GetLevel();
	int GetTeam();

	short GetIndex();
	short GetSourceIndex();
	short GetTargetIndex();

	SpellBook* GetSpellBook();

	Vector GetPos();
	Vector GetTargetPos();
	Vector GetStartPos();
	Vector GetEndPos();
	Vector GetVelocity();
};

class GameObjectManager
{
public:
	union
	{
		DEFINE_MEMBER_0(void* Base, 0x0);
		DEFINE_MEMBER_N(Actor** Objects, 0x4);
		DEFINE_MEMBER_N(int MaxSize, 0x8);
		DEFINE_MEMBER_N(int Size, 0xC);
		DEFINE_MEMBER_N(int HighestIndex, 0x10);
	};
};

extern GameObjectManager* ObjectManager;

#pragma region Old

//AIManager* GameObject::GetAIManager() {
//	{
//		typedef AIManager* (__thiscall * OriginalFn)(PVOID);
//		return CallVirtual<OriginalFn>(this, 147)(this); // 147?
//	};
//}

//bool GameObject::IsAttackable() {
//	return this->GetDistToMe() <= (ME->GetAttackRange() + this->GetBoundingRadius())
//		&& this->IsTargetable();
//
//}

//bool GameObject::IsAlive() {
//	return Functions.IsAlive(this)
//		&& this->GetHealth() > 0.0f;
//}

//bool GameObject::IsBaron() {
//	return Functions.IsBaron(this);
//}

//bool GameObject::IsDashing() {
//	return *(bool*) ((DWORD) this->GetAIManager() + PTR_OBJECT_AI_IS_DASHING);
//}

//bool GameObject::IsDragon() {
//	return Functions.IsDragon(this);
//}

//bool GameObject::IsEnemy() {
//	return (ME->GetTeam() == ETeam::ORDER && this->GetTeam() == ETeam::CHAOS || ME->GetTeam() == ETeam::CHAOS && this->GetTeam() == ETeam::ORDER);
//}

//bool GameObject::IsFriendly() {
//	return (ME->GetTeam() == ETeam::ORDER && this->GetTeam() == ETeam::ORDER || ME->GetTeam() == ETeam::CHAOS && this->GetTeam() == ETeam::CHAOS);
//}

//bool GameObject::IsHero() {
//	return Functions.IsHero(this);
//}
//
//bool GameObject::IsInhibitor() {
//	return Functions.IsInhibitor(this);
//}

//bool GameObject::IsMinion() {
//	return Functions.IsMinion(this);
//}

//bool GameObject::IsMissile() {
//	return Functions.IsMissile(this);
//}

//bool GameObject::IsMoving() {
//	return *(bool*) ((DWORD) this->GetAIManager() + PTR_OBJECT_AI_IS_MOVING);
//}

//bool GameObject::IsNexus() {
//	return Functions.IsNexus(this);
//}

//bool GameObject::IsNeutral() {
//	return this->GetTeam() == ETeam::NEUTRAL;
//}

//bool GameObject::IsTargetable() {
//	return Functions.IsTargetable(this);
//}

//bool GameObject::IsTroyEnt() {
//	return Functions.IsTroyEnt(this);
//}

//bool GameObject::IsTurret() {
//	return Functions.IsTurret(this);
//}

//bool GameObject::IsVisible() {
//	return *(bool*) ((DWORD) this + PTR_OBJECT_IS_VISIBLE);
//}

//char* GameObject::GetName() {
//	return GetStr((DWORD) this + PTR_OBJECT_NAME);
//};
//
//char* GameObject::GetActorName() {
//	return GetStr((DWORD) this + PTR_OBJECT_ACTOR_NAME);
//}
//
//DWORD GameObject::GetNetworkID() {
//	return *(DWORD*) ((DWORD) this + PTR_OBJECT_NETWORK_ID);
//}
//
//float GameObject::GetArmor() {
//	return *(float*) ((DWORD) this + PTR_OBJECT_ARMOR);
//}
//
//float GameObject::GetAttackRange() {
//	return *(float*) ((DWORD) this + PTR_OBJECT_ATTACK_RANGE);
//}
//
//float GameObject::GetAttackSpeed() {
//	return 1 / Functions.GetAttackDelay(this);
//}
//
//float GameObject::GetBaseAttackDamage() {
//	return *(float*) ((DWORD) this + PTR_OBJECT_BASE_ATTACK);
//}
//
//float GameObject::GetBonusAttackDamage() {
//	return *(float*) ((DWORD) this + PTR_OBJECT_BONUS_ATTACK);
//}
//
//float GameObject::GetBoundingRadius() {
//	typedef float(__thiscall * OriginalFn)(PVOID);
//	return CallVirtual<OriginalFn>(this, 36)(this);
//}
//
//float GameObject::GetDistToMe() {
//	return this->GetPos().DistTo(ME->GetPos());
//}
//
//float GameObject::GetHealth() {
//	return *(float*) ((DWORD) this + PTR_OBJECT_CURRENT_HEALTH);
//}
//
//float GameObject::GetMaxHealth() {
//	return *(float*) ((DWORD) this + PTR_OBJECT_CURRENT_HEALTH + 0x10);
//}
//
//float GameObject::GetTotalAttackDamage() {
//	return this->GetBonusAttackDamage() + this->GetBaseAttackDamage();
//}
//
//int GameObject::GetLevel() {
//	return *(int*) ((DWORD) this + PTR_OBJECT_LEVEL);
//}
//int GameObject::GetTeam() {
//	return *(int*) ((DWORD) this + PTR_OBJECT_TEAM);
//}
//
//short GameObject::GetIndex() {
//	return *(short*) ((DWORD) this + PTR_OBJECT_INDEX);
//}
//
//short GameObject::GetSourceIndex() {
//	return *(short*) ((DWORD) this + PTR_OBJECT_SOURCE_INDEX);
//}
//
//short GameObject::GetTargetIndex() {
//	return *(short*) ((DWORD) this + PTR_OBJECT_TARGET_ID);
//}
//
//SpellBook* GameObject::GetSpellBook() {
//	return (SpellBook*) ((DWORD) this + PTR_OBJECT_SPELLBOOK);
//}
//
//Vector GameObject::GetPos() {
//	return *(Vector*) ((DWORD) this + PTR_OBJECT_POS);
//}
//
//Vector GameObject::GetTargetPos() {
//	return *(Vector*) ((DWORD) this->GetAIManager() + PTR_OBJECT_AI_TARGETPOS);
//}
//
//Vector GameObject::GetStartPos() {
//	return *(Vector*) ((DWORD) this + PTR_OBJECT_SPELL_START_POS);
//}
//
//Vector GameObject::GetEndPos() {
//	return *(Vector*) ((DWORD) this + PTR_OBJECT_SPELL_END_POS);
//}
//
//Vector GameObject::GetVelocity() {
//	return *(Vector*) ((DWORD) this->GetAIManager() + PTR_OBJECT_AI_VELOCITY);
//}

#pragma endregion
