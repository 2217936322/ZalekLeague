#pragma once
#include <Windows.h>
#include "Offsets.h"
#include "Vector.h"
#include "Utils.h"

class CObject {
public:
	bool IsTurret();
	bool IsMinion();
	bool IsAlive();
	bool IsHero();
	bool IsMissile();
	bool IsNexus();

	bool IsInhibitor();
	bool IsTroyEnt();
	bool IsTargetable();

	//short GetIndex() {
	//	return *(short*)((DWORD)this + oObjIndex);
	//}

	short GetTargetIndex() {
		return *(short*)((DWORD)this + oObjTargetID);
	}

	short GetSourceIndex() {
		return *(short*)((DWORD)this + oObjSourceIndex);
	}

	DWORD GetNetworkID() {
		return *(DWORD*)((DWORD)this + oObjNetworkID);
	}

	Vector GetPos() {
		return *(Vector*)((DWORD)this + oObjPos);
	}

	int GetLevel() {
		return *(int*)((DWORD)this + oObjLevel);
	}

	float GetHealth() {
		return *(float*)((DWORD)this + oObjHealth);
	}

	float GetBaseAttackDamage() {
		return *(float*)((DWORD)this + oObjBaseAtk);
	}

	float GetBonusAttackDamage() {
		return *(float*)((DWORD)this + oObjBonusAtk);
	}

	float GetTotalAttackDamage() {
		return this->GetBonusAttackDamage() + this->GetBaseAttackDamage();
	}

	float GetArmor() {
		return *(float*)((DWORD)this + oObjArmor);
	}

	float GetMaxHealth() {
		return *(float*)((DWORD)this + oObjHealth + 0x10);
	}

	float GetAttackRange() {
		return *(float*)((DWORD)this + oObjAtkRange);
	}

	bool IsVisible() {
		return *(bool*)((DWORD)this + oObjVisibility);
	}

	float GetBoundingRadius() {
		typedef float(__thiscall * OriginalFn)(PVOID);
		return CallVirtual<OriginalFn>(this, 36)(this);
	}

	//float GetBoundingRadius() {
	//	typedef float(__thiscall * OriginalFn)(PVOID);
	//	return CallVirtual<OriginalFn>(this, 37)(this);
	//}

	bool IsEnemyTo(CObject * Obj) {
		if (Obj->GetTeam() == 100 && this->GetTeam() == 200)
			return true;

		else if (Obj->GetTeam() == 200 && this->GetTeam() == 100)
			return true;

		return false;
	}

	char* GetName() {
		return GetStr((DWORD)this + oObjName);
	}

	char* GetChampionName() {
		return GetStr((DWORD)this + oObjChampionName);
	}

	int GetTeam() {
		return *(int*)((DWORD)this + oObjTeam);
	}
};