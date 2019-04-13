#pragma once
#include <Windows.h>
#include "Offsets.h"
#include "Vector.h"
#include "Utils.h"

class GameObject
{
public:
	bool IsAttackable();
	bool IsAlive();
	bool IsEnemy();
	bool IsHero();
	bool IsInhibitor();
	bool IsMinion();
	bool IsMissile();
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
	Vector GetStartPos();
	Vector GetEndPos();
};