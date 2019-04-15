#include <Windows.h>
//#include "Utils.h"
#pragma once


//class CSpellEntry
//{
//public:
//	char* GetSpellName() {
//		auto aux3 = *(DWORD*) ((DWORD) this + 0x4);
//		if(aux3) {
//			auto aux4 = *(DWORD*) (aux3 + 0xC);
//			if(aux4) {
//				if(*(DWORD*) (aux4 + 0x8)) {
//					return (char*) (aux4 + 0x8);
//				}
//			}
//		}
//		return NULL;
//	}
//};

//class SpellData
//{
//public:
//	char* GetMissileName() {
//		return GetStr((DWORD) this + 0x0058);
//	}
//
//	char* GetSpellName() {
//		auto aux3 = *(DWORD*) ((DWORD) this + 0x4);
//		if(aux3) {
//			auto aux4 = *(DWORD*) (aux3 + 0xC);
//			if(aux4) {
//				if(*(DWORD*) (aux4 + 0x8)) {
//					return (char*) (aux4 + 0x8);
//				}
//			}
//		}
//		return NULL;
//	}
//
//	//char* GetSpellName() {
//	//	return GetStr((DWORD) this + 0x007C);
//	//}
//
//	char* GetDescription() {
//		return GetStr((DWORD) this + 0x0088);
//	}
//
//	float GetEffectAmount() {
//		return *(float*) ((DWORD) this + 0xD0);
//	}
//
//	float GetIncreaseDamage() {
//		return *(float*) ((DWORD) this + 0xEC);
//	}
//
//	float GetSpellDuration() {
//		return *(float*) ((DWORD) this + 0x108);
//	}
//
//	float GetRootDuration() {
//		return *(float*) ((DWORD) this + 0x15C);
//	}
//
//	float GetIncreaseDamageBonus() {
//		return *(float*) ((DWORD) this + 0x178);
//	}
//
//	float GetCoefficient() {
//		return *(float*) ((DWORD) this + 0x200);
//	}
//
//	float GetCoefficient2() {
//		return *(float*) ((DWORD) this + 0x204);
//	}
//
//	int GetMaxHighlightTargets() {
//		return *(int*) ((DWORD) this + 0x208);
//	}
//
//	float GetCooldownTime() {
//		return *(float*) ((DWORD) this + 0x280);
//	}
//
//	float GetDelayCastOffsetPercent() {
//		return *(float*) ((DWORD) this + 0x29C);
//	}
//
//	float GetDelayTotalTimePercent() {
//		return *(float*) ((DWORD) this + 0x2A0);
//	}
//
//	int GetMaxAmmo() {
//		return *(int*) ((DWORD) this + 0x31C);
//	}
//
//	int GetAmmoUsed() {
//		return *(int*) ((DWORD) this + 0x338);
//	}
//
//	float GetAmmoRechargeTime() {
//		return *(float*) ((DWORD) this + 0x354);
//	}
//
//	float GetMissileSpeed() {
//		return *(float*) ((DWORD) this + 0x450);
//	}
//};

//class SpellInfo
//{
//public:
//	SpellData* GetSpellData() {
//		return (SpellData*) ((DWORD) this + 0x38);
//	}
//};

class SpellSlot
{
public:
	bool IsReady();

	int GetLevel();

	float GetCooldown();
	float GetTimeUsed();


	//SpellInfo* GetSpellInfo() {
	//	return (SpellInfo*) ((DWORD) this + 0x124);
	//}
};

class CSpellBook
{
public:
	SpellSlot* GetSpellSlotByID(int ID) {
		return *(SpellSlot * *) ((DWORD) this + 0x508 + (0x4 * ID));
	}
};

//
//enum class m_AIBase
//{
//	Spellbook = 0x15F0,
//	HeroInventory = 0xCB4
//	/* ... */
//};
//
//enum class m_SpellData
//{
//	Name = 0x18,
//	Cooldown = 0x2BC,
//	ManaCost = 0x78C,
//	Damage = 0xB4,
//	InternalSpellStringName = 0x1D4,
//	CastFrame = 0x5B0,
//	CastRange = 0x4EC,
//	CastRangeDisplayOverride = 0x508,
//	CastRadius = 0x524,
//	CastRadiusSecondary = 0xA60,
//	LineWidth = 0x650,
//	MissileSpeed = 0x5BC,
//	SpellCastTime = 0x2A0,
//	SpellTotalTime = 0x2A4
//};
//
//enum class m_SpellDataInst
//{
//	Level = 0x10,
//	CooldownExpires = 0x14,
//	Ammo = 0x18,
//	AmmoRechargeStart = 0x24,
//	ToggleState = 0x30,
//	Cooldown = 0x34,
//	SpellData = 0xD8
//};
//
//class SpellSlot
//{
//public:
//	bool IsReady();
//	float GetTime();
//	int GetLevel();
//};
//
//class CSpellEntry
//{
//public:
//	char* GetSpellName();
//};
//
//class CSpellBook
//{
//public:
//	CSpellEntry* GetActiveSpellEntry();
//	SpellSlot* GetSpellSlotByID(int ID);
//};
//
//class SpellData
//{
//public:
//	char* GetMissileName() {
//		return GetStr((DWORD) this + 0x0058);
//	}
//
//	char* GetSpellName() {
//		return GetStr((DWORD) this + 0x007C);
//	}
//
//	char* GetDescription() {
//		return GetStr((DWORD) this + 0x0088);
//	}
//
//	float GetEffectAmount() {
//		return *(float*) ((DWORD) this + 0xD0);
//	}
//
//	float GetIncreaseDamage() {
//		return *(float*) ((DWORD) this + 0xEC);
//	}
//
//	float GetSpellDuration() {
//		return *(float*) ((DWORD) this + 0x108);
//	}
//
//	float GetRootDuration() {
//		return *(float*) ((DWORD) this + 0x15C);
//	}
//
//	float GetIncreaseDamageBonus() {
//		return *(float*) ((DWORD) this + 0x178);
//	}
//
//	float GetCoefficient() {
//		return *(float*) ((DWORD) this + 0x200);
//	}
//
//	float GetCoefficient2() {
//		return *(float*) ((DWORD) this + 0x204);
//	}
//
//	int GetMaxHighlightTargets() {
//		return *(int*) ((DWORD) this + 0x208);
//	}
//
//	float GetCooldownTime() {
//		return *(float*) ((DWORD) this + 0x280);
//	}
//
//	float GetDelayCastOffsetPercent() {
//		return *(float*) ((DWORD) this + 0x29C);
//	}
//
//	float GetDelayTotalTimePercent() {
//		return *(float*) ((DWORD) this + 0x2A0);
//	}
//
//	int GetMaxAmmo() {
//		return *(int*) ((DWORD) this + 0x31C);
//	}
//	int GetAmmoUsed() {
//		return *(int*) ((DWORD) this + 0x338);
//	}
//	float GetAmmoRechargeTime() {
//		return *(float*) ((DWORD) this + 0x354);
//	}
//
//	float GetMissileSpeed() {
//		return *(float*) ((DWORD) this + 0x450);
//	}
//};