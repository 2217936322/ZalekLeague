#include "Engine.h"
#include "LFunctions.h"
#include "MinionObject.h"
#pragma once

bool MinionObject::IsAlive() {
	return Functions.IsAlive(this) && this->GetHealth() > 0.0f;
};

bool MinionObject::IsEnemy() {
	return (ME->GetTeam() == 100 && this->GetTeam() == 200 || ME->GetTeam() == 200 && this->GetTeam() == 100);
}

bool MinionObject::IsFriendly() {
	return (ME->GetTeam() == 100 && this->GetTeam() == 100 || ME->GetTeam() == 200 && this->GetTeam() == 200);
}

bool MinionObject::IsTargetable() {
	return false;
}

bool MinionObject::IsVisible() {
	return false;
}

char* MinionObject::GetName() {
	return nullptr;
}

char* MinionObject::GetNameWithGUID() {
	return nullptr;
}

DWORD MinionObject::GetNetworkID() {
	return 0;
}

float MinionObject::GetAttackDamage() {
	return 0.0f;
}

float MinionObject::GetHitboxRadius() {
	return 0.0f;
}

float MinionObject::GetDistToMe() {
	return 0.0f;
}

float MinionObject::GetHealth() {
	return 0.0f;
}

Vector MinionObject::GetPos() {
	return Vector();
}
