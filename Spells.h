#include <Windows.h>
#include "Enums/ESpellSlot.h"
//#include "Utils.h"
#pragma once

class SpellSlot
{
public:
	bool IsReady();
	int GetLevel();
	float GetCooldown();
	float GetTimeUsed();
};

class SpellBook
{
public:
	SpellSlot* GetQ();
	SpellSlot* GetW();
	SpellSlot* GetE();
	SpellSlot* GetR();
};