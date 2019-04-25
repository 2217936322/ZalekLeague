#include <vector>
#include "Actor.h"
#include "Engine.h"
#include "Enums/ETeam.h"
#pragma once
#include <typeinfo>

class AIManager;
class Champion;
Champion* Me();

class Champion : LActor
{
public:

	DWORD GetAddress() {
		return (DWORD) this;
	}

#pragma region AIManager

	AIManager* GetAIManager() {
		typedef AIManager* (__thiscall * OriginalFn)(PVOID);
		return CallVirtual<OriginalFn>((LActor*) this, 147)((LActor*) this);
	}

#pragma endregion


#pragma region BuffManager
	class Buff
	{
	public:
		bool IsValid() {
			return this->IsAddressValid()
				&& IsBuffPointerValid()
				&& this->GetName() != "NULL";
		}

#pragma region BuffManager Address

		DWORD GetAddress() {
			return (DWORD) this;
		}

		bool IsAddressValid() {
			return this != NULL
				&& this->fAddressValidation() > 65535.0f;
		}

		float fAddressValidation() {
			return *(float*) this->GetAddress();
		}

#pragma endregion

#pragma region BuffPointer

		DWORD GetBuffPointer() {
			if(this->IsAddressValid()) {
				return *(DWORD*) this->GetAddress();
			}
			return 0x00;
		}

		bool IsBuffPointerValid() {
			return this != NULL
				&& this->GetBuffPointer() > 0x7FFFFFF
				&& this->GetBuffPointer() < 0x70000000;
		}

		float fBuffPointerValidation() {
			return *(float*)* (DWORD*) this->GetAddress();
		}

#pragma endregion
		char* GetName() {
			//! Will cause a crash in some cases. Do not use yet'
			if(this->IsBuffPointerValid()) {

				DWORD aux = this->GetBuffPointer();

				if(aux == NULL)
					return "NULL";

				if(*(DWORD*) (aux + O_BUFFMGR_BUFFNAME) == NULL)
					return "NULL";

				char* str = (char*) (aux + O_BUFFMGR_BUFFNAME);

				if(strlen(str) <= 8 || strlen(str) > 128)
					return "NULL";

				// !!! HACK !!!
				// May cause some extra buffs to get filtered out. Rework later.
				if(strlen(str) == 16)
					return "NULL";

				return str;
			}

			return "NULL";
		}
	};

	std::vector<Buff*> GetBuffs() {
		std::vector<Buff*> Buffs;
		DWORD pBuffListStart = this->GetBuffListStart() + 0x04;
		DWORD pBuffListEnd = this->GetBuffListEnd();
		for(DWORD pBuff = pBuffListStart; pBuff != pBuffListEnd; pBuff += 0x04) {
			Buff* buff = (Buff*) pBuff;
			if(buff != NULL && buff->IsValid()) {
				Buffs.push_back(buff);
			}
		}
		return Buffs;
	}

	Buff* GetFirstBuffEntry() {
		return *(Buff * *) this->GetBuffListStart();
	}

	Buff* GetLastBuffEntry() {
		return *(Buff * *) this->GetBuffListEnd();
	}

	DWORD GetBuffArrayAddress() {
		return (DWORD) this + O_BUFF_MGR + 0x10;
	}

	DWORD GetBuffArrayStart() {
		return *(unsigned long*) this->GetBuffArrayAddress();
	}

	DWORD GetBuffListStart() {
		return *(unsigned long*) this->GetBuffArrayStart();
	}

	DWORD GetBuffListEnd() {
		return this->GetBuffArrayEnd() - 0x04;
	}

	DWORD GetBuffArrayEndAddress() {
		return (DWORD) this + O_BUFF_MGR + 0x14;
	}

	DWORD GetBuffArrayEnd() {
		return *(unsigned long*) this->GetBuffArrayEndAddress();
	}

#pragma endregion


#pragma region bool

	bool IsChampion() {
		return Functions.IsHero((LActor*) this);
	}

	bool IsDashing() {
		return *(bool*) ((DWORD) this->GetAIManager() + PTR_OBJECT_AI_IS_DASHING);
	}

	bool IsEnemy() {
		return (Me()->GetTeam() == ETeam::ORDER && this->GetTeam() == ETeam::CHAOS
			|| Me()->GetTeam() == ETeam::CHAOS && this->GetTeam() == ETeam::ORDER);
	}

	bool IsFriendly() {
		return (Me()->GetTeam() == ETeam::ORDER && this->GetTeam() == ETeam::ORDER
			|| Me()->GetTeam() == ETeam::CHAOS && this->GetTeam() == ETeam::CHAOS);
	}

	bool IsMoving() {
		return *(bool*) ((DWORD) this->GetAIManager() + PTR_OBJECT_AI_IS_MOVING);
	}

	bool IsTargetable() {
		return Functions.IsTargetable((LActor*) this);
	}


#pragma endregion


#pragma region char*

	char* GetActorName() {
		return GetStr((DWORD) this + O_ACTOR_NAME);
	}

	char* GetName() {
		return GetStr((DWORD) this + O_CONTROLLER_NAME);
	}

	char* GetRecallName() {
		return GetStr((DWORD) this + O_RECALL_NAME);
	}

#pragma endregion


#pragma region DWORD

	DWORD GetNetworkID() {
		return *(DWORD*) ((DWORD) this + O_NETWORK_ID);
	}

#pragma endregion


#pragma region float
	float GetArmor() {
		return *(float*) ((DWORD) this + O_ARMOR);
	}

	float GetAttackCastDelay() {
		return Functions.GetAttackCastDelay((LActor*) this);
	}

	float GetAttackDamage() {
		return this->GetBonusAttackDamage() + this->GetBaseAttackDamage();
	}

	float GetAbilityPower() {
		return *(float*) ((DWORD) this + O_BONUS_AP);
	}

	float GetAttackDelay() {
		return Functions.GetAttackDelay((LActor*) this);
	}

	float GetAttackRange() {
		return *(float*) ((DWORD) this + O_ATTACK_RANGE);
	}

	float GetAttackSpeed() {
		return 1 / Functions.GetAttackDelay((LActor*) this);
	}

	float GetBaseAttackDamage() {
		return *(float*) ((DWORD) this + O_BASE_AD);
	}

	float GetBonusAttackDamage() {
		return *(float*) ((DWORD) this + O_BONUS_AD);
	}

	float GetCollisionRadius() {
		typedef float(__thiscall * OriginalFn)(PVOID);
		return CallVirtual<OriginalFn>((LActor*) this, 36)((LActor*) this);
	}

	//float GetCooldownReduction() {
	//	return *(float*) ((DWORD) this + O_CRIT_RATE) * 100;
	//}

	float GetCritChance() {
		return *(float*) ((DWORD) this + O_CRIT_RATE) * 100;
	}

	float GetDistToMe() {
		return this->GetPos().DistTo(Me()->GetPos());
	}

	float GetHealth() {
		return *(float*) ((DWORD) this + O_HEALTH);
	}

	float GetMaxHealth() {
		return *(float*) ((DWORD) this + O_MAX_HEALTH);
	}

	float GetHealthPercent() {
		return (this->GetHealth() / this->GetMaxHealth()) * 100;
	}

	float GetMagicResist() {
		return *(float*) ((DWORD) this + O_MAGIC_RESIST);
	}

	float GetMana() {
		return *(float*) ((DWORD) this + O_MANA);
	}

	float GetMaxMana() {
		return *(float*) ((DWORD) this + O_MAX_MANA);
	}

	float GetManaPercent() {
		return (this->GetMana() / this->GetMaxMana()) * 100;
	}

	float GetMoveSpeed() {
		return *(float*) ((DWORD) this + O_MOVE_SPEED);
	}

#pragma endregion


#pragma region int32

	int GetLevel() {
		return *(int*) ((DWORD) this + O_LEVEL);
	}

	int GetTeam() {
		return *(int*) ((DWORD) this + O_TEAM);
	}

	int GetRecallState() {
		return *(int*) ((DWORD) this + O_RECALL_STATE);
	}

#pragma endregion


#pragma region int16

	short GetIndex() {
		return *(short*) ((DWORD) this + O_INDEX);
	}

#pragma endregion


#pragma region SpellBook

	SpellBook* GetSpellBook() {
		return (SpellBook*) ((DWORD) this + O_SPELLBOOK);
	}

#pragma endregion


#pragma region Vector

	Vector GetPos() {
		return *(Vector*) ((DWORD) this + O_POS);
	}

	Vector GetWaypoint() {
		return *(Vector*) ((DWORD) this->GetAIManager() + PTR_OBJECT_AI_WAYPOINT);
	}

#pragma endregion

};


Champion* Me() {
	return (Champion*)* (DWORD*) (baseAddr + DWORD_LOCAL_PLAYER);
}