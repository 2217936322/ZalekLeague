#include <vector>
#include "Actor.h"
#include "Engine.h"
#include "Enums/ETeam.h"
#pragma once
#include <typeinfo>

class AIManager;
class Champion;
Champion* Me();

class Champion : Actor
{
public:
	DWORD GetAddress() {
		return (DWORD) this;
	}

	//int SpellSlot::GetSpellInfoAddress() {
	//	return *(int*) ((DWORD) this + 0x12C);
	//}

#pragma region AIManager

	AIManager* GetAIManager() {
		typedef AIManager* (__thiscall * OriginalFn)(PVOID);
		return CallVirtual<OriginalFn>((Actor*) this, 147)((Actor*) this);
	}

#pragma endregion


#pragma region BuffManager
	class Buff
	{
	public:
		bool IsValid() {
			return this->GetBuffPointer() > 0x7FFFFFF
				&& this->GetBuffPointer() < 0x70000000;
			//&& this->GetName() != "NULL";
		}

		const char* GetNameType() {
			DWORD pName = *(DWORD*) this->GetBuffPointer() + O_BUFF_NAME;
			return typeid(pName).name();
		}

		DWORD GetAddress() {
			return (DWORD) this;
		}

		bool IsAddressValid() {
			return this->fAddressValidiation() > 65535.0f;
		}

		float fAddressValidiation() {
			return *(float*) this->GetAddress();
		}

		DWORD GetBuffPointer() {
			if(this->IsAddressValid())
				return *(DWORD*) this->GetAddress();

			return 0x00;
		}

		float fBuffPointerValid() {
			return *(float*)* (DWORD*) this->GetAddress();
		}

		char* GetName() {
			DWORD aux = this->GetBuffPointer() + 0x08;
			if(aux == NULL)
				return "NULL";

			if(*(DWORD*) (aux + O_BUFFMGR_BUFFNAME) == NULL)
				return "NULL";
			// TODO: more null checks to prevent crashing.
			//return (char*) (aux + O_BUFFMGR_BUFFNAME);
		}


		//char* GetName() {
		//	if(this->IsValid()) {
		//		DWORD pName = this->GetBuffPointer() + 0x08;
		//		if(pName != NULL)
		//			return GetStr(pName);
		//	}
		//	return "NULL";
		//}

		//char* GetName() {
		//	DWORD aux = this->GetBuffPointer() + 0x9C;
		//	if(aux == NULL)
		//		return "NULL";

		//	if(*(DWORD*) (aux + O_BUFFMGR_BUFFNAME) == NULL)
		//		return "NULL2";

		//	return "PLACEHOLDER" /*(char*) (aux + O_BUFFMGR_BUFFNAME)*/;
		//}


		//const char* GetNameType() {
		//	return typeid((aux + 0x08)).name();
		//}


		//char* GetName() {
		//	DWORD aux = *(DWORD*) ((DWORD) this + O_BUFFMGR_BUFFNAME);
		//	if(aux == NULL)
		//		return "NULL";

		//	if(*(DWORD*) (aux + O_BUFFMGR_BUFFNAME) == NULL)
		//		return "NULL2";

		//	return (char*) (aux + O_BUFFMGR_BUFFNAME);
		//}

		//char* GetName() {
		//	return GetStr(this->GetBuffPointer() + O_BUFF_NAME);
		//}

		//float GetBuffStartTime() {
		//	return *(float*) ((DWORD) this + O_BUFF_START_TIME);
		//}

		//float GetBuffEndTime() {
		//	return *(float*) ((DWORD) this + O_BUFF_END_TIME);
		//}

		//bool IsActive() {
		//	auto time = Engine::GetGameTime();
		//	return this->GetBuffStartTime() < time&& time < this->GetBuffEndTime();
		//}

#pragma region Tests
		//bool IsActive() {
//	auto time = Engine::GetGameTime();
//	return this->GetBuffStartTime() < time&& time < this->GetBuffEndTime();
//}

//bool IsValid() {
//	if(this == NULL || (DWORD) this <= 0x1000)
//		return false;

//	return strcmp(GetBuffName(), "NULL");
//}

//float GetBuffStartTime() {
//	return *(float*) ((DWORD) this + O_BUFFMGR_STARTTIME);
//}

//float GetBuffEndTime() {
//}

//int GetBuffCountAlt() {
//	return (*(int*) ((DWORD) this + 0x20) - *(int*) ((DWORD) this + 0x1c)) >> 3;
//}

//float GetBuffCountFloat() {
//	return *(float*) ((DWORD) this + O_BUFFMGR_flBUFFCOUNT);
//}

//int GetBuffCountInt() {
//	return *(int*) ((DWORD) this + O_BUFFMGR_iBUFFCOUNT);
//}

//char* GetBuffName() {
//	DWORD aux = *(DWORD*) ((DWORD) this + O_BUFFMGR_BUFFNAME);
//	if(aux == NULL)
//		return "NULL";

//	if(*(DWORD*) (aux + O_BUFFMGR_BUFFNAME) == NULL)
//		return "NULL";

//	return (char*) (aux + O_BUFFMGR_BUFFNAME);
//}


#pragma endregion

	};

	std::vector<Buff*> GetBuffs() {
		std::vector<Buff*> Buffs;
		// TODO: Buff List validation.
		DWORD pBuffListStart = this->GetBuffListStart();
		DWORD pBuffListEnd = this->GetBuffListEnd();
		for(DWORD pBuff = pBuffListStart; pBuff != pBuffListEnd; pBuff += 0x04) {
			Buff* buff = (Buff*) pBuff;
			if(buff != NULL && buff->IsValid())
				Buffs.push_back(buff);
		}
		Buffs.shrink_to_fit();
		return Buffs;
	}

	Buff* GetFirstBuff() {
		return *(Buff * *) this->GetBuffListStart();
	}

	Buff* GetLastBuff() {
		return *(Buff * *) this->GetBuffListEnd();
	}



	// 'ASSETS/Perks/Styles/Sorcery/ManaflowBand/PerkManaflowBandBuff.lu'
	// 50 65 72 6b 4d 61 6e 61 66 6c 6f 77 42 61 6e 64 42 75 66 66
	// veigarphenomenalevilpower 
	// 76 65 69 67 61 72 70 68 65 6e 6f 6d 65 6e 61 6c 65 76 69 6c 70 6f 77 65 72

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
		return Functions.IsHero((Actor*) this);
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
		return Functions.IsTargetable((Actor*) this);
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
		return Functions.GetAttackCastDelay((Actor*) this);
	}

	float GetAttackDamage() {
		return this->GetBonusAttackDamage() + this->GetBaseAttackDamage();
	}

	float GetAbilityPower() {
		return *(float*) ((DWORD) this + O_BONUS_AP);
	}

	float GetAttackDelay() {
		return Functions.GetAttackDelay((Actor*) this);
	}

	float GetAttackRange() {
		return *(float*) ((DWORD) this + O_ATTACK_RANGE);
	}

	float GetAttackSpeed() {
		return 1 / Functions.GetAttackDelay((Actor*) this);
	}

	float GetBaseAttackDamage() {
		return *(float*) ((DWORD) this + O_BASE_AD);
	}

	float GetBonusAttackDamage() {
		return *(float*) ((DWORD) this + O_BONUS_AD);
	}

	float GetCollisionRadius() {
		typedef float(__thiscall * OriginalFn)(PVOID);
		return CallVirtual<OriginalFn>((Actor*) this, 36)((Actor*) this);
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