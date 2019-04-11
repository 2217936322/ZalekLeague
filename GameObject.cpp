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
bool GameObject::IsVisible() { return *(bool*) ((DWORD) this + oObjVisibility); }

char* GameObject::GetChampionName() { return GetStr((DWORD) this + oObjChampionName); }
char* GameObject::GetName() { return GetStr((DWORD) this + oObjName); };

DWORD GameObject::GetNetworkID() { return *(DWORD*) ((DWORD) this + oObjNetworkID); }

float GameObject::GetArmor() { return *(float*) ((DWORD) this + oObjArmor); }
float GameObject::GetAttackRange() { return *(float*) ((DWORD) this + oObjAtkRange); }
float GameObject::GetBaseAttackDamage() { return *(float*) ((DWORD) this + oObjBaseAtk); }
float GameObject::GetBonusAttackDamage() { return *(float*) ((DWORD) this + oObjBonusAtk); }
float GameObject::GetBoundingRadius() { typedef float(__thiscall * OriginalFn)(PVOID); return CallVirtual<OriginalFn>(this, 36)(this); }
float GameObject::GetDistToMe() { return this->GetPos().DistTo(ME->GetPos()); }
float GameObject::GetHealth() { return *(float*) ((DWORD) this + oObjHealth); }
float GameObject::GetMaxHealth() { return *(float*) ((DWORD) this + oObjHealth + 0x10); }
float GameObject::GetTotalAttackDamage() { return this->GetBonusAttackDamage() + this->GetBaseAttackDamage(); }

int GameObject::GetLevel() { return *(int*) ((DWORD) this + oObjLevel); }
int GameObject::GetTeam() { return *(int*) ((DWORD) this + oObjTeam); }

short GameObject::GetIndex() { return *(short*) ((DWORD) this + oObjIndex); }
short GameObject::GetSourceIndex() { return *(short*) ((DWORD) this + oObjSourceIndex); }
short GameObject::GetTargetIndex() { return *(short*) ((DWORD) this + oObjTargetID); }

Vector GameObject::GetPos() { return *(Vector*) ((DWORD) this + oObjPos); }
