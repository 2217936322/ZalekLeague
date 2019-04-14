#pragma once
#include <Windows.h>
#include "Offsets.h"
#include "Vector.h"
#include "Utils.h"


class AIManager {};
class GameObject
{
public:
	AIManager* GetAIManager();

	bool IsAttackable();
	bool IsAlive();
	bool IsDashing();
	bool IsEnemy();
	bool IsHero();
	bool IsInhibitor();
	bool IsMinion();
	bool IsMissile();
	bool IsMoving();
	bool IsNexus();
	bool IsTargetable();
	bool IsTroyEnt();
	bool IsTurret();
	bool IsVisible();

	char* GetChampionName();
	char* GetName();

	DWORD GetNetworkID();

	float GetArmor();
	float GetAttackRange();
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

	Vector GetPos();
	Vector GetTargetPos();
	Vector GetStartPos();
	Vector GetEndPos();
};

class GameObjectManager
{
public:
	union
	{
		DEFINE_MEMBER_0(void* base, 0x0);
		DEFINE_MEMBER_N(GameObject** objectArray, 0x0 + 0x8);
		DEFINE_MEMBER_N(int MaxObjects, 0x4 + 0x8);
		DEFINE_MEMBER_N(int ObjectsUsed, 0x8 + 0x8);
		DEFINE_MEMBER_N(int HighestObjectID, 0xC + 0x8);
	};
};

extern GameObjectManager* GObjectManager;