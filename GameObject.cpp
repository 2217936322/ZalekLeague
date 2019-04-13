#include "GameObject.h"
#include "Hooks.h"
#include "Engine.h"

bool GameObject::IsAttackable() { return this->GetDistToMe() <= ME->GetAttackRange() + (this->GetBoundingRadius() * 2.0f) && this->IsTargetable(); }
bool GameObject::IsAlive() { return Functions.IsAlive(this) && this->GetHealth() > 0.0f; }
bool GameObject::IsEnemy() { return (ME->GetTeam() == 100 && this->GetTeam() == 200 || ME->GetTeam() == 200 && this->GetTeam() == 100); }
bool GameObject::IsHero() { return Functions.IsHero(this); }
bool GameObject::IsInhibitor() { return Functions.IsInhibitor(this); }
bool GameObject::IsMinion() { return Functions.IsMinion(this); }
bool GameObject::IsMissile() { return Functions.IsMissile(this); }
bool GameObject::IsNexus() { return Functions.IsNexus(this); }
bool GameObject::IsTargetable() { return Functions.IsTargetable(this); }
bool GameObject::IsTroyEnt() { return Functions.IsTroyEnt(this); }
bool GameObject::IsTurret() { return Functions.IsTurret(this); }
bool GameObject::IsVisible() { return *(bool*) ((DWORD) this + PTR_OBJECT_IS_VISIBLE); }

char* GameObject::GetChampionName() { return GetStr((DWORD) this + PTR_OBJECT_NAME_STRING); }
char* GameObject::GetName() { return GetStr((DWORD) this + PTR_OBJECT_NAME); };

DWORD GameObject::GetNetworkID() { return *(DWORD*) ((DWORD) this + PTR_OBJECT_NETWORK_ID); }

float GameObject::GetArmor() { return *(float*) ((DWORD) this + PTR_OBJECT_ARMOR); }
float GameObject::GetAttackRange() { return *(float*) ((DWORD) this + PTR_OBJECT_ATTACK_RANGE); }
float GameObject::GetBaseAttackDamage() { return *(float*) ((DWORD) this + PTR_OBJECT_BASE_ATTACK); }
float GameObject::GetBonusAttackDamage() { return *(float*) ((DWORD) this + PTR_OBJECT_BONUS_ATTACK); }
float GameObject::GetBoundingRadius() { typedef float(__thiscall * OriginalFn)(PVOID); return CallVirtual<OriginalFn>(this, 36)(this); }
float GameObject::GetDistToMe() { return this->GetPos().DistTo(ME->GetPos()); }
float GameObject::GetHealth() { return *(float*) ((DWORD) this + PTR_OBJECT_CURRENT_HEALTH); }
float GameObject::GetMaxHealth() { return *(float*) ((DWORD) this + PTR_OBJECT_CURRENT_HEALTH + 0x10); }
float GameObject::GetTotalAttackDamage() { return this->GetBonusAttackDamage() + this->GetBaseAttackDamage(); }

int GameObject::GetLevel() { return *(int*) ((DWORD) this + PTR_OBJECT_LEVEL); }
int GameObject::GetTeam() { return *(int*) ((DWORD) this + PTR_OBJECT_TEAM); }

short GameObject::GetIndex() { return *(short*) ((DWORD) this + PTR_OBJECT_INDEX); }
short GameObject::GetSourceIndex() { return *(short*) ((DWORD) this + PTR_OBJECT_SOURCE_INDEX); }
short GameObject::GetTargetIndex() { return *(short*) ((DWORD) this + PTR_OBJECT_TARGET_ID); }

Vector GameObject::GetPos() { return *(Vector*) ((DWORD) this + PTR_OBJECT_POS); }
Vector GameObject::GetStartPos() { return *(Vector*) ((DWORD) this + PTR_OBJECT_SPELL_START_POS); }
Vector GameObject::GetEndPos() { return *(Vector*) ((DWORD) this + PTR_OBJECT_SPELL_END_POS); }
