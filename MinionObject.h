#include <Windows.h>
#include "Offsets.h"
#include "Vector.h"
#include "Utils.h"
#include "GameObject.h"
#pragma once

class MinionObject : GameObject
{
public:
	bool IsAlive();
	bool IsEnemy();
	bool IsFriendly();
	bool IsTargetable();
	bool IsVisible();

	char* GetName();
	char* GetNameWithGUID();

	DWORD GetNetworkID();

	float GetAttackDamage();
	float GetHitboxRadius();
	float GetDistToMe();
	float GetHealth();

	Vector GetPos();
};