#include "Champion.h"
#include "Objects.h"
#include "Enums/ETeam.h"
#include "LFunctions.h"
#include <vector>

#pragma once

DWORD Champion::GetAddress() {
	return (DWORD) this;
}

#pragma region AIManager

AIManager* Champion::GetAIManager() {
	typedef AIManager* (__thiscall * OriginalFn)(PVOID);
	return CallVirtual<OriginalFn>((LActor*) this, 147)((LActor*) this);
}

#pragma endregion


#pragma region BuffManager
//bool Champion::Buff::IsValid() {
//	return this->IsAddressValid()
//		&& IsBuffPointerValid()
//		&& this->GetName() != "NULL";
//}

#pragma region BuffManager Address

//DWORD Champion::Buff::GetAddress() {
//	return (DWORD) this;
//}
//
//bool Champion::Buff::IsAddressValid() {
//	return this != NULL
//		&& this->fAddressValidation() > 65535.0f;
//}
//
//float Champion::Buff::fAddressValidation() {
//	return *(float*) this->GetAddress();
//}

#pragma endregion

#pragma region BuffPointer

//DWORD Champion::Buff::GetBuffPointer() {
//	if(this->IsAddressValid()) {
//		return *(DWORD*) this->GetAddress();
//	}
//	return 0x00;
//}
//
//bool Champion::Buff::IsBuffPointerValid() {
//	return this != NULL
//		&& this->GetBuffPointer() > 0x7FFFFFF
//		&& this->GetBuffPointer() < 0x70000000;
//}
//
//float Champion::Buff::fBuffPointerValidation() {
//	return *(float*)* (DWORD*) this->GetAddress();
//}

#pragma endregion
//char* Champion::Buff::GetName() {
//	! Will cause a crash in some cases. Do not use yet'
//	if(this->IsBuffPointerValid()) {
//
//		DWORD aux = this->GetBuffPointer();
//
//		if(aux == NULL)
//			return "NULL";
//
//		if(*(DWORD*) (aux + O_BUFFMGR_BUFFNAME) == NULL)
//			return "NULL";
//
//		char* str = (char*) (aux + O_BUFFMGR_BUFFNAME);
//
//		if(strlen(str) <= 8 || strlen(str) > 128)
//			return "NULL";
//
//		 !!! HACK !!!
//		 May cause some extra buffs to get filtered out. Rework later.
//		if(strlen(str) == 16)
//			return "NULL";
//
//		return str;
//	}
//
//	return "NULL";
//}

//std::vector<Buff*> Champion::Buff::GetBuffs() {
//	std::vector<Champion::Buff*> Buffs;
//	DWORD pBuffListStart = this->GetBuffListStart() + 0x04;
//	DWORD pBuffListEnd = this->GetBuffListEnd();
//	for(DWORD pBuff = pBuffListStart; pBuff != pBuffListEnd; pBuff += 0x04) {
//		Buff* buff = (Buff*) pBuff;
//		if(buff != NULL && buff->IsValid()) {
//			Buffs.push_back(buff);
//		}
//	}
//	return Buffs;
//}
//
//Buff* Champion::GetFirstBuffEntry() {
//	return *(Buff * *) this->GetBuffListStart();
//}
//
//Buff* Champion::GetLastBuffEntry() {
//	return *(Buff * *) this->GetBuffListEnd();
//}
//
//DWORD Champion::GetBuffArrayAddress() {
//	return (DWORD) this + O_BUFF_MGR + 0x10;
//}
//
//DWORD Champion::GetBuffArrayStart() {
//	return *(unsigned long*) this->GetBuffArrayAddress();
//}
//
//DWORD Champion::GetBuffListStart() {
//	return *(unsigned long*) this->GetBuffArrayStart();
//}
//
//DWORD Champion::GetBuffListEnd() {
//	return this->GetBuffArrayEnd() - 0x04;
//}
//
//DWORD Champion::GetBuffArrayEndAddress() {
//	return (DWORD) this + O_BUFF_MGR + 0x14;
//}
//
//DWORD Champion::GetBuffArrayEnd() {
//	return *(unsigned long*) this->GetBuffArrayEndAddress();
//}

#pragma endregion


#pragma region bool

bool Champion::IsDashing() {
	return *(bool*) ((DWORD) this->GetAIManager() + PTR_OBJECT_AI_IS_DASHING);
}

bool Champion::IsEnemy() {
	return (Me()->GetTeam() == ETeam::ORDER && this->GetTeam() == ETeam::CHAOS
		|| Me()->GetTeam() == ETeam::CHAOS && this->GetTeam() == ETeam::ORDER);
}

bool Champion::IsFriendly() {
	return (Me()->GetTeam() == ETeam::ORDER && this->GetTeam() == ETeam::ORDER
		|| Me()->GetTeam() == ETeam::CHAOS && this->GetTeam() == ETeam::CHAOS);
}

bool Champion::IsMoving() {
	return *(bool*) ((DWORD) this->GetAIManager() + PTR_OBJECT_AI_IS_MOVING);
}

bool Champion::IsTargetable() {
	return Functions.IsTargetable((LActor*) this);
}


#pragma endregion


#pragma region char*

char* Champion::GetActorName() {
	return GetStr((DWORD) this + O_ACTOR_NAME);
}

char* Champion::GetName() {
	return GetStr((DWORD) this + O_CONTROLLER_NAME);
}

char* Champion::GetRecallName() {
	return GetStr((DWORD) this + O_RECALL_NAME);
}

#pragma endregion


#pragma region DWORD

DWORD Champion::GetNetworkID() {
	return *(DWORD*) ((DWORD) this + O_NETWORK_ID);
}

#pragma endregion


#pragma region float
float Champion::GetArmor() {
	return *(float*) ((DWORD) this + O_ARMOR);
}

float Champion::GetAttackCastDelay() {
	return Functions.GetAttackCastDelay((LActor*) this);
}

float Champion::GetAttackDamage() {
	return this->GetBonusAttackDamage() + this->GetBaseAttackDamage();
}

float Champion::GetAbilityPower() {
	return *(float*) ((DWORD) this + O_BONUS_AP);
}

float Champion::GetAttackDelay() {
	return Functions.GetAttackDelay((LActor*) this);
}

float Champion::GetAttackRange() {
	return *(float*) ((DWORD) this + O_ATTACK_RANGE);
}

float Champion::GetAttackSpeed() {
	return 1 / Functions.GetAttackDelay((LActor*) this);
}

float Champion::GetBaseAttackDamage() {
	return *(float*) ((DWORD) this + O_BASE_AD);
}

float Champion::GetBonusAttackDamage() {
	return *(float*) ((DWORD) this + O_BONUS_AD);
}

float Champion::GetCollisionRadius() {
	typedef float(__thiscall * OriginalFn)(PVOID);
	return CallVirtual<OriginalFn>((LActor*) this, 36)((LActor*) this);
}

float Champion::GetCritChance() {
	return *(float*) ((DWORD) this + O_CRIT_RATE) * 100;
}

float Champion::GetDistToMe() {
	return this->GetPos().DistTo(Me()->GetPos());
}

float Champion::GetHealth() {
	return *(float*) ((DWORD) this + O_HEALTH);
}

float Champion::GetMaxHealth() {
	return *(float*) ((DWORD) this + O_MAX_HEALTH);
}

float Champion::GetHealthPercent() {
	return (this->GetHealth() / this->GetMaxHealth()) * 100;
}

float Champion::GetMagicResist() {
	return *(float*) ((DWORD) this + O_MAGIC_RESIST);
}

float Champion::GetMana() {
	return *(float*) ((DWORD) this + O_MANA);
}

float Champion::GetMaxMana() {
	return *(float*) ((DWORD) this + O_MAX_MANA);
}

float Champion::GetManaPercent() {
	return (this->GetMana() / this->GetMaxMana()) * 100;
}

float Champion::GetMoveSpeed() {
	return *(float*) ((DWORD) this + O_MOVE_SPEED);
}

#pragma endregion


#pragma region int32

int Champion::GetLevel() {
	return *(int*) ((DWORD) this + O_LEVEL);
}

int Champion::GetTeam() {
	return *(int*) ((DWORD) this + O_TEAM);
}

int Champion::GetRecallState() {
	return *(int*) ((DWORD) this + O_RECALL_STATE);
}

#pragma endregion


#pragma region int16

short Champion::GetIndex() {
	return *(short*) ((DWORD) this + O_INDEX);
}

#pragma endregion


#pragma region SpellBook

SpellBook* Champion::GetSpellBook() {
	return (SpellBook*) ((DWORD) this + O_SPELLBOOK);
}

#pragma endregion


#pragma region Vector

Vector Champion::GetPos() {
	return *(Vector*) ((DWORD) this + O_POS);
}

Vector Champion::GetWaypoint() {
	return *(Vector*) ((DWORD) this->GetAIManager() + PTR_OBJECT_AI_WAYPOINT);
}

#pragma endregion