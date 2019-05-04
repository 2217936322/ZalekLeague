/************************************************************************/
/*				  Champion Object Type : Implementations				*/
/************************************************************************/

#include "Champion.h"
#include "Objects.h"
#include "Enums/ETeam.h"
#include "LFunctions.h"
#include <vector>


/* Return the Base address of this Champion */
DWORD Champion::GetAddress() {
	return (DWORD) this;
}


/* Return the Base address of this Champion's AI Manager */
Champion::AIManager* Champion::GetAIManager() {
	typedef AIManager* (__thiscall * OriginalFn)(PVOID);
	return CallVirtual<OriginalFn>((LActor*) this, 147)((LActor*) this);
}


/* Return the Base address of this Champion's Buff Manager */
Champion::BuffManager* Champion::GetBuffManager() {
	return (BuffManager*) ((DWORD) this + O_BUFF_MGR + 0x10);
}


/* Return the Base address of this Champion's SpellBook */
SpellBook* Champion::GetSpellBook() {
	return (SpellBook*) ((DWORD) this + O_SPELLBOOK);
}

// Add this fix: the bool is set to true when a character is dashing e.g Graves E, Lucian E, Galio E (and will remain true until the character moves again so you have to fix that yourself by checking if the character is moving & dashing)
/* Return the IsDashing state inside AI Manager */
bool Champion::IsDashing() {
	return *(bool*) ((DWORD) this->GetAIManager() + PTR_OBJECT_AI_IS_DASHING);
}


/* Return the team is Order/Chaos and does not match your players team */
bool Champion::IsEnemy() {
	return (Me()->GetTeamID() == ETeam::ORDER && this->GetTeamID() == ETeam::CHAOS
		|| Me()->GetTeamID() == ETeam::CHAOS && this->GetTeamID() == ETeam::ORDER);
}


/* Return the team is Order/Chaos and does match your players team */
bool Champion::IsFriendly() {
	return (Me()->GetTeamID() == ETeam::ORDER && this->GetTeamID() == ETeam::ORDER
		|| Me()->GetTeamID() == ETeam::CHAOS && this->GetTeamID() == ETeam::CHAOS);
}


/* Return the IsMoving state inside AI Manager */
bool Champion::IsMoving() {
	return *(bool*) ((DWORD) this->GetAIManager() + PTR_OBJECT_AI_IS_MOVING);
}


/* Return the IsTargetable state */
bool Champion::IsTargetable() {
	return Functions.IsTargetable((LActor*) this);
}


/* Return the Actor Name */
char* Champion::GetActorName() {
	return GetStr((DWORD) this + O_ACTOR_NAME);
}


/* Return the Summoner (Controller) Name */
char* Champion::GetName() {
	return GetStr((DWORD) this + O_CONTROLLER_NAME);
}


/* Return the Name of your currently channeled recall spell. Empty string if not channeling. */
char* Champion::GetRecallName() {
	return GetStr((DWORD) this + O_RECALL_NAME);
}


/* Return the Network Identifier */
DWORD Champion::GetNetworkID() {
	return *(DWORD*) ((DWORD) this + O_NETWORK_ID);
}


/* Return the Armor amount */
float Champion::GetArmor() {
	return *(float*) ((DWORD) this + O_ARMOR);
}


/* Return the Amount of time it takes to wind up your Auto Attack */
float Champion::GetAttackCastDelay() {
	return Functions.GetAttackCastDelay((LActor*) this);
}


/* Return the Total Attack Damage amount */
float Champion::GetAttackDamage() {
	return this->GetBonusAttackDamage() + this->GetBaseAttackDamage();
}


/* Return the Total Ability Power amount */
float Champion::GetAbilityPower() {
	return *(float*) ((DWORD) this + O_BONUS_AP);
}


/* Return the Amount of time it takes for you to be able to Auto Attack after your last Auto Attack */
float Champion::GetAttackDelay() {
	return Functions.GetAttackDelay((LActor*) this);
}


/* Return the Attack Range amount */
float Champion::GetAttackRange() {
	return *(float*) ((DWORD) this + O_ATTACK_RANGE);
}


/* Return the Attack Speed amount */
float Champion::GetAttackSpeed() {
	return 1 / Functions.GetAttackDelay((LActor*) this);
}


/* Return the Base Attack Damage amount */
float Champion::GetBaseAttackDamage() {
	return *(float*) ((DWORD) this + O_BASE_AD);
}


/* Return the Bonus Attack Damage amount */
float Champion::GetBonusAttackDamage() {
	return *(float*) ((DWORD) this + O_BONUS_AD);
}


/* Return the Collision Radius size */
float Champion::GetCollisionRadius() {
	typedef float(__thiscall * OriginalFn)(PVOID);
	return CallVirtual<OriginalFn>((LActor*) this, 36)((LActor*) this);
}


/* Return the Critical Chance percent */
float Champion::GetCritChance() {
	return *(float*) ((DWORD) this + O_CRIT_RATE) * 100;
}


/* Return the Distance to your player */
float Champion::GetDistToMe() {
	return this->GetPos().DistTo(Me()->GetPos());
}


/* Return the Current Health amount */
float Champion::GetHealth() {
	return *(float*) ((DWORD) this + O_HEALTH);
}


/* Return the Maximum Health amount */
float Champion::GetMaxHealth() {
	return *(float*) ((DWORD) this + O_MAX_HEALTH);
}


/* Return the Current Health percent */
float Champion::GetHealthPercent() {
	return (this->GetHealth() / this->GetMaxHealth()) * 100;
}


/* Return the Magic Resist amount */
float Champion::GetMagicResist() {
	return *(float*) ((DWORD) this + O_MAGIC_RESIST);
}


/* Return the Current Mana amount */
float Champion::GetMana() {
	return *(float*) ((DWORD) this + O_MANA);
}


/* Return the Maximum Mana amount */
float Champion::GetMaxMana() {
	return *(float*) ((DWORD) this + O_MAX_MANA);
}


/* Return the Current Mana percent */
float Champion::GetManaPercent() {
	return (this->GetMana() / this->GetMaxMana()) * 100;
}


/* Return the Current Movement Speed amount */
float Champion::GetMoveSpeed() {
	return *(float*) ((DWORD) this + O_MOVE_SPEED);
}


/* Return the Current Level amount */
int Champion::GetLevel() {
	return *(int*) ((DWORD) this + O_LEVEL);
}


/* Return the Current Team ID */
int Champion::GetTeamID() {
	return *(int*) ((DWORD) this + O_TEAM);
}


/* Return the Current Recall State*/
int Champion::GetRecallState() {
	return *(int*) ((DWORD) this + O_RECALL_STATE);
}


/* Return the Current Index of this actor inside of ActorManager */
short Champion::GetIndex() {
	return *(short*) ((DWORD) this + O_INDEX);
}


/* Return the Position of this actor */
Vector Champion::GetPos() {
	return *(Vector*) ((DWORD) this + O_POS);
}



/* Return the Waypoint Position of this actor inside of AI Manager */
Vector Champion::GetWaypoint() {
	return *(Vector*) ((DWORD) this->GetAIManager() + PTR_OBJECT_AI_WAYPOINT);
}



#pragma region Buff Manager Tests


//bool Champion::Buff::IsValid() {
//	return this->IsAddressValid()
//		&& IsBuffPointerValid()
//		&& this->GetName() != "NULL";
//}


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