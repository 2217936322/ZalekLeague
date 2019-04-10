#include "GameObject.h"
#include "Hooks.h"
#include "Engine.h"

bool GameObject::IsAlive() {
	return Functions.IsAlive(this) && this->GetHealth() > 0.0f;
}

bool GameObject::IsMinion() {
	return Functions.IsMinion(this);
}

bool GameObject::IsTurret() {
	return Functions.IsTurret(this);
}

bool GameObject::IsHero() {
	return Functions.IsHero(this);
}

bool GameObject::IsMissile() {
	return Functions.IsMissile(this);
}

bool GameObject::IsTargetable() {
	return Functions.IsTargetable(this);
}

bool GameObject::IsNexus() {
	return Functions.IsNexus(this);
}

bool GameObject::IsInhibitor() {
	return Functions.IsInhibitor(this);
}

bool GameObject::IsTroyEnt() {
	return Functions.IsTroyEnt(this);
}