#include <Windows.h>
#include "Enums/ESpellSlot.h"
#include "Utils.h"
#pragma once


//class SpellData
//{
//public:
//	char* GetMissileName() {
//		return GetStr((DWORD) this + 0x0058);
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

	//bool SpellSlot::IsReady() {
	//	return this->GetCooldown() <= 0.0f && this->GetLevel() > 0;
	//}

	//bool SpellSlot::HasCharges() {
	//	return this->GetNextCharge() != -1;
	//}

	//char* SpellSlot::GetActorName() {
	//	return GetStr(this->GetSpellInfoAddress() + 0x18);
	//}

	//int GetCharge();
	//int GetNextCharge();
	//int GetSpellInfoAddress();
	int SpellSlot::GetRank() {
		return *(int*) ((DWORD) this + O_SS_RANK);
	}

	//float GetCooldown();
	//float GetTimeUsed() {
	//	return *(float*) ((DWORD) this + 0x28);
	//}
};

class SpellBook
{
public:
	SpellSlot* Get(int slot) {
		return *(SpellSlot * *) ((DWORD) this + 0x508 + (0x4 * slot));
	}
};


/*
	spellbook contains spellslotarray.
	spellslotarray has at 0x10c SpellDataInst (contains name, timestamp, level etc.. at 0x34 it has SpellData)

	If you're using IsMissile, obj + 0x7A0 is the missile width.
	Didn't reverse SpellData for this info tho.
*/

//class SpellData
//{
//public:
//	char* GetMissileName() {
//		return GetStr((DWORD) this + 0x0058);
//	}
//	char* GetSpellName() {
//		return GetStr((DWORD) this + 0x007C);
//	}
//	char* GetDescription() {
//		return GetStr((DWORD) this + 0x0088);
//	}
//	float GetEffectAmount() {
//		return *(float*) ((DWORD) this + 0xD0);
//	}
//	float GetIncreaseDamage() {
//		return *(float*) ((DWORD) this + 0xEC);
//	}
//	float GetSpellDuration() {
//		return *(float*) ((DWORD) this + 0x108);
//	}
//	float GetRootDuration() {
//		return *(float*) ((DWORD) this + 0x15C);
//	}
//	float GetIncreaseDamageBonus() {
//		return *(float*) ((DWORD) this + 0x178);
//	}
//	float GetCoefficient() {
//		return *(float*) ((DWORD) this + 0x200);
//	}
//	float GetCoefficient2() {
//		return *(float*) ((DWORD) this + 0x204);
//	}
//	int GetMaxHighlightTargets() {
//		return *(int*) ((DWORD) this + 0x208);
//	}
//	float GetCooldownTime() {
//		return *(float*) ((DWORD) this + 0x280);
//	}
//	float GetDelayCastOffsetPercent() {
//		return *(float*) ((DWORD) this + 0x29C);
//	}
//	float GetDelayTotalTimePercent() {
//		return *(float*) ((DWORD) this + 0x2A0);
//	}
//	int GetMaxAmmo() {
//		return *(int*) ((DWORD) this + 0x31C);
//	}
//	int GetAmmoUsed() {
//		return *(int*) ((DWORD) this + 0x338);
//	}
//	float GetAmmoRechargeTime() {
//		return *(float*) ((DWORD) this + 0x354);
//	}
//	float GetMissileSpeed() {
//		return *(float*) ((DWORD) this + 0x450);
//	}
//};
//
