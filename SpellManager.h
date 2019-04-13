#pragma once
#include <Windows.h>
#include "Offsets.h"
#include "Vector.h"
#include "Utils.h"
//#include "CSpellInfo.h"

enum class SpellSlot
{
	Q = 0,
	W = 1,
	E = 2,
	R = 3,
	SummonerSpell1 = 4,
	SummonerSpell2 = 5,
	Item1 = 6,
	Item2 = 7,
	Item3 = 8,
	Item4 = 9,
	Item5 = 10,
	Item6 = 11,
};

//class CSpellSlot
//{
//public:
//	int GetLevel() {
//		return *(int*) ((DWORD) this + 0x20);
//	}
//
//	float GetTime() {
//		return *(float*) ((DWORD) this + 0x28);
//	}
//
//	float GetCD() {
//		return *(float*) ((DWORD) this + 0x18);
//	}
//
//	//CSpellInfo* GetSpellInfo() {
//	//	return *(CSpellInfo * *) ((DWORD) this + 0x124);
//	//}
//};