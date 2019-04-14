#include "Engine.h"
#include "LFunctions.h"
#include "MinionObject.h"
#include "Enums/ETeam.h"
#pragma once

bool MinionObject::IsAlive() {
	return Functions.IsAlive(this) && this->GetHealth() > 0.0f;
};

bool MinionObject::IsEnemy() {
	return (ME->GetTeam() == ETeam::ORDER && this->GetTeam() == ETeam::CHAOS || ME->GetTeam() == ETeam::CHAOS && this->GetTeam() == ETeam::ORDER);
}

bool MinionObject::IsFriendly() {
	return (ME->GetTeam() == ETeam::ORDER && this->GetTeam() == ETeam::ORDER || ME->GetTeam() == ETeam::CHAOS && this->GetTeam() == ETeam::CHAOS);
}

bool MinionObject::IsTargetable() {
	return Functions.IsTargetable(this);
}

bool MinionObject::IsVisible() {
	return *(bool*) ((DWORD) this + PTR_OBJECT_IS_VISIBLE);
}

char* MinionObject::GetName() {
	return GetStr((DWORD) this + PTR_OBJECT_NAME_STRING);
}

char* MinionObject::GetNameWithGUID() {
	return GetStr((DWORD) this + PTR_OBJECT_IDENTIFIER_NAME);
}

DWORD MinionObject::GetNetworkID() {
	return *(DWORD*) ((DWORD) this + PTR_OBJECT_NETWORK_ID);
}

float MinionObject::GetAttackDamage() {
	return (
		*(float*) ((DWORD) this + PTR_OBJECT_BASE_ATTACK)
		+ *(float*) ((DWORD) this + PTR_OBJECT_BONUS_ATTACK)
		);
}

float MinionObject::GetHitboxRadius() {
	typedef float(__thiscall * OriginalFn)(PVOID);
	return CallVirtual<OriginalFn>(this, 36)(this);
}

float MinionObject::GetDistToMe() {
	return this->GetPos().DistTo(ME->GetPos());
}

float MinionObject::GetHealth() {
	return *(float*) ((DWORD) this + PTR_OBJECT_CURRENT_HEALTH);
}

Vector MinionObject::GetPos() {
	return *(Vector*) ((DWORD) this + PTR_OBJECT_POS);
}
