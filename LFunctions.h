#pragma once
#include "GameObject.h"

class Typedefs
{
public:
	typedef void(__thiscall* tPrintChat)(DWORD ChatClient, const char* Message, int Color);
	typedef int* (__thiscall* fnIssueOrder)(void* thisPtr, int Order, Vector* Loc, GameObject* Target, bool IsAttackMove, bool IsMinion, DWORD Unknown);
	typedef float(__cdecl* fnGetAttackCastDelay)(GameObject* pObj);
	typedef float(__cdecl* fnGetAttackDelay)(GameObject* pObj);
	//typedef float(__cdecl* fnGetBasicAttack)(GameObject* pObj);

	typedef bool(__cdecl* fnWorldToScreen)(Vector* vIn, Vector* vOut);

	typedef void(__cdecl* fnDrawCircle)(Vector* position, float range, int* color, int a4, float a5, int a6, float alpha);
	//typedef void(__cdecl* fnDrawFloatText)(GameObject* startpos, char* text);

	typedef int* (__thiscall* fnCastSpell)(DWORD spellbook_addr, int* spellslot, int SlotID, Vector* targetpos, Vector* startpos, DWORD NetworkID);
	typedef void(__thiscall* fnPrintChat)(DWORD ChatClient, const char* Message, int Color);

	//typedef bool(__cdecl* fnIsBaron)(GameObject* pObj);
	//typedef bool(__cdecl* fnIsDragon)(GameObject* pObj);
	typedef bool(__cdecl* fnIsHero)(GameObject* pObj);
	typedef bool(__cdecl* fnIsMissile)(GameObject* pObj);
	typedef bool(__cdecl* fnIsMinion)(GameObject* pObj);
	typedef bool(__cdecl* fnIsTurret)(GameObject* pObj);
	typedef bool(__cdecl* fnIsInhibitor)(GameObject* pObj);
	typedef bool(__cdecl* fnIsTroyEnt)(GameObject* pObj);
	typedef bool(__cdecl* fnIsNexus)(GameObject* pObj);

	typedef bool(__thiscall* fnIsAlive)(GameObject* pObj);
	typedef bool(__thiscall* fnIsTargetable)(GameObject* pObj);
};

class LFunctions
{
public:
	//Typedefs::fnIsBaron IsBaron;
	//Typedefs::fnIsDragon IsDragon;
	Typedefs::fnIsTurret IsTurret;
	Typedefs::fnIsMinion IsMinion;
	Typedefs::fnIsHero IsHero;
	Typedefs::fnIsMissile IsMissile;
	Typedefs::fnIsTroyEnt IsTroyEnt;
	Typedefs::fnIsNexus IsNexus;
	Typedefs::fnIsInhibitor IsInhibitor;

	Typedefs::fnIsTargetable IsTargetable;
	Typedefs::fnIsAlive IsAlive;

	Typedefs::fnIssueOrder IssueOrder;
	Typedefs::fnGetAttackCastDelay GetAttackCastDelay;
	Typedefs::fnGetAttackDelay GetAttackDelay;
	//Typedefs::fnGetBasicAttack GetBasicAttack;
	Typedefs::fnDrawCircle DrawCircle;
	Typedefs::fnWorldToScreen WorldToScreen;
	//Typedefs::fnDrawFloatText DrawFloatText;
	Typedefs::fnCastSpell CastSpell;
	Typedefs::fnPrintChat PrintChat;
};

extern LFunctions Functions;