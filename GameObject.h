#include "Utils.h"
#include "Vector.h"
#include "Spells.h"
#pragma once

class AIManager {};

class GameObject
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

	char* GetName();
	char* GetActorName();

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
		DEFINE_MEMBER_N(GameObject** Objects, 0x4);
		DEFINE_MEMBER_N(int MaxSize, 0x8);
		DEFINE_MEMBER_N(int Size, 0xC);
		DEFINE_MEMBER_N(int HighestIndex, 0x10);
	};
};

extern GameObjectManager* ObjectManager;