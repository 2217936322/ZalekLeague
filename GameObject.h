#pragma once
#include <Windows.h>
#include "Offsets.h"
#include "Vector.h"
#include "Utils.h"


class AIManager {};

enum class m_AIBase
{
	Spellbook = 0x15F0,
	HeroInventory = 0xCB4
	/* ... */
};

enum class m_SpellData
{
	Name = 0x18,
	Cooldown = 0x2BC,
	ManaCost = 0x78C,
	Damage = 0xB4,
	InternalSpellStringName = 0x1D4,
	CastFrame = 0x5B0,
	CastRange = 0x4EC,
	CastRangeDisplayOverride = 0x508,
	CastRadius = 0x524,
	CastRadiusSecondary = 0xA60,
	LineWidth = 0x650,
	MissileSpeed = 0x5BC,
	SpellCastTime = 0x2A0,
	SpellTotalTime = 0x2A4
};

enum class m_SpellDataInst
{
	Level = 0x10,
	CooldownExpires = 0x14,
	Ammo = 0x18,
	AmmoRechargeStart = 0x24,
	ToggleState = 0x30,
	Cooldown = 0x34,
	SpellData = 0xD8
};

class SpellSlot
{
public:
	float GetTime();
	int GetLevel();
};

class CSpellEntry
{
public:
	char* GetSpellName();
};

class CSpellBook
{
public:
	CSpellEntry* GetActiveSpellEntry();
	SpellSlot* GetSpellSlotByID(int ID);
};

class SpellData
{
public:
	char* GetMissileName() {
		return GetStr((DWORD) this + 0x0058);
	}

	char* GetSpellName() {
		return GetStr((DWORD) this + 0x007C);
	}

	char* GetDescription() {
		return GetStr((DWORD) this + 0x0088);
	}

	float GetEffectAmount() {
		return *(float*) ((DWORD) this + 0xD0);
	}

	float GetIncreaseDamage() {
		return *(float*) ((DWORD) this + 0xEC);
	}

	float GetSpellDuration() {
		return *(float*) ((DWORD) this + 0x108);
	}

	float GetRootDuration() {
		return *(float*) ((DWORD) this + 0x15C);
	}

	float GetIncreaseDamageBonus() {
		return *(float*) ((DWORD) this + 0x178);
	}

	float GetCoefficient() {
		return *(float*) ((DWORD) this + 0x200);
	}

	float GetCoefficient2() {
		return *(float*) ((DWORD) this + 0x204);
	}

	int GetMaxHighlightTargets() {
		return *(int*) ((DWORD) this + 0x208);
	}

	float GetCooldownTime() {
		return *(float*) ((DWORD) this + 0x280);
	}

	float GetDelayCastOffsetPercent() {
		return *(float*) ((DWORD) this + 0x29C);
	}

	float GetDelayTotalTimePercent() {
		return *(float*) ((DWORD) this + 0x2A0);
	}

	int GetMaxAmmo() {
		return *(int*) ((DWORD) this + 0x31C);
	}
	int GetAmmoUsed() {
		return *(int*) ((DWORD) this + 0x338);
	}
	float GetAmmoRechargeTime() {
		return *(float*) ((DWORD) this + 0x354);
	}

	float GetMissileSpeed() {
		return *(float*) ((DWORD) this + 0x450);
	}
};

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
	bool IsInhibitor();
	bool IsMinion();
	bool IsMissile();
	bool IsMoving();
	bool IsNexus();
	bool IsNeutral();
	bool IsTargetable();
	bool IsTroyEnt();
	bool IsTurret();
	bool IsVisible();

	char* GetName();
	char* GetUniqueName();

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
		DEFINE_MEMBER_0(void* base, 0x0);
		DEFINE_MEMBER_N(GameObject** objectArray, 0x0 + 0x8);
		DEFINE_MEMBER_N(int MaxObjects, 0x4 + 0x8);
		DEFINE_MEMBER_N(int ObjectsUsed, 0x8 + 0x8);
		DEFINE_MEMBER_N(int HighestObjectID, 0xC + 0x8);
	};
};

extern GameObjectManager* GObjectManager;