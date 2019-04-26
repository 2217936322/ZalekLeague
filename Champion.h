#include "Actor.h"
#pragma once
class Champion : LActor
{
public:

	DWORD GetAddress();

#pragma region AIManager

	AIManager* GetAIManager();

#pragma endregion


#pragma region BuffManager
	//class Buff
	//{
	//public:
	//	bool IsValid();

#pragma region BuffManager Address

		//DWORD GetAddress();

		//bool IsAddressValid();

		//float fAddressValidation();

#pragma endregion

#pragma region BuffPointer

		//DWORD GetBuffPointer();

		//bool IsBuffPointerValid();

		//float fBuffPointerValidation();

#pragma endregion
		//char* GetName();

		//std::vector<Buff*> GetBuffs();

		//Buff* GetFirstBuffEntry();

		//Buff* GetLastBuffEntry();

		//DWORD GetBuffArrayAddress();

		//DWORD GetBuffArrayStart();

		//DWORD GetBuffListStart();

		//DWORD GetBuffListEnd();

		//DWORD GetBuffArrayEndAddress();

		//DWORD GetBuffArrayEnd();
//};
#pragma endregion


#pragma region bool

	bool IsChampion();

	bool IsDashing();

	bool IsEnemy();

	bool IsFriendly();

	bool IsMoving();

	bool IsTargetable();


#pragma endregion


#pragma region char*

	char* GetActorName();

	char* GetName();

	char* GetRecallName();

#pragma endregion


#pragma region DWORD

	DWORD GetNetworkID();

#pragma endregion


#pragma region float
	float GetArmor();

	float GetAttackCastDelay();

	float GetAttackDamage();

	float GetAbilityPower();

	float GetAttackDelay();

	float GetAttackRange();

	float GetAttackSpeed();

	float GetBaseAttackDamage();

	float GetBonusAttackDamage();

	float GetCollisionRadius();

	float GetCritChance();

	float GetDistToMe();

	float GetHealth();

	float GetMaxHealth();

	float GetHealthPercent();

	float GetMagicResist();

	float GetMana();

	float GetMaxMana();

	float GetManaPercent();

	float GetMoveSpeed();

#pragma endregion


#pragma region int32

	int GetLevel();

	int GetTeam();

	int GetRecallState();

#pragma endregion


#pragma region int16

	short GetIndex();

#pragma endregion


#pragma region SpellBook

	SpellBook* GetSpellBook();

#pragma endregion


#pragma region Vector

	Vector GetPos();

	Vector GetWaypoint();

#pragma endregion

};