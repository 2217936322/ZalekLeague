/************************************************************************/
/*					Champion Object Type : Declarations					*/
/************************************************************************/

#pragma once
#include "Actor.h"

class Champion : LActor
{
public:

	/* Return the Base address of this Champion */
	DWORD GetAddress();

	/* Return the Base address of this Champion's AI Manager */
	AIManager* GetAIManager();

	/* Return the Base address of this Champion's Buff Manager */
	BuffManager* GetBuffManager();

	/* Return the Base address of this Champion's SpellBook */
	SpellBook* GetSpellBook();

	/* Return the IsDashing state inside AI Manager */
	bool IsDashing();

	/* Return the team is Order/Chaos and does not match your players team */
	bool IsEnemy();

	/* Return the team is Order/Chaos and does match your players team */
	bool IsFriendly();

	/* Return the IsMoving state inside AI Manager */
	bool IsMoving();

	/* Return the IsTargetable state */
	bool IsTargetable();

	/* Return the Actor Name */
	char* GetActorName();

	/* Return the Summoner (Controller) Name */
	char* GetName();

	/* Return the Name of your currently channeled recall spell. Empty string if not channeling. */
	char* GetRecallName();

	/* Return the Network Identifier */
	DWORD GetNetworkID();

	/* Return the Armor amount */
	float GetArmor();

	/* Return the Amount of time it takes to wind up your Auto Attack */
	float GetAttackCastDelay();

	/* Return the Total Attack Damage amount */
	float GetAttackDamage();

	/* Return the Total Ability Power amount */
	float GetAbilityPower();

	/* Return the Amount of time it takes for you to be able to Auto Attack after your last Auto Attack */
	float GetAttackDelay();

	/* Return the Attack Range amount */
	float GetAttackRange();

	/* Return the Attack Speed amount */
	float GetAttackSpeed();

	/* Return the Base Attack Damage amount */
	float GetBaseAttackDamage();

	/* Return the Bonus Attack Damage amount */
	float GetBonusAttackDamage();

	/* Return the Collision Radius size */
	float GetCollisionRadius();

	/* Return the Critical Chance percent */
	float GetCritChance();

	/* Return the Distance to your player */
	float GetDistToMe();

	/* Return the Current Health amount */
	float GetHealth();

	/* Return the Maximum Health amount */
	float GetMaxHealth();

	/* Return the Current Health percent */
	float GetHealthPercent();

	/* Return the Magic Resist amount */
	float GetMagicResist();

	/* Return the Current Mana amount */
	float GetMana();

	/* Return the Maximum Mana amount */
	float GetMaxMana();

	/* Return the Current Mana percent */
	float GetManaPercent();

	/* Return the Current Movement Speed amount */
	float GetMoveSpeed();

	/* Return the Current Level amount */
	int GetLevel();

	/* Return the Current Team ID */
	int GetTeamID();

	/* Return the Current Recall State */
	int GetRecallState();

	/* Return the Current Index of this actor inside of ActorManager */
	short GetIndex();

	/* Return the Position of this actor */
	Vector GetPos();

	/* Return the Waypoint Position of this actor inside of AI Manager */
	Vector GetWaypoint();

};