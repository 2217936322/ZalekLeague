#pragma once
#include "Utils.h"
#include "GameObject.h"
const int TRYFOROBJMAX = 10000;
class GameObjectManager
{
public:
	union
	{
		DEFINE_MEMBER_0(void* base, 0x0);
		DEFINE_MEMBER_N(GameObject** objectArray, 0x0 + 0x8);
		DEFINE_MEMBER_N(int MaxObjects, 0x4 + 0x8);
		DEFINE_MEMBER_N(int ObjectsUsed, 0x8 + 0x8);
		DEFINE_MEMBER_N(int HighestObjectID, 0xC + 0x8);
	};
};
extern GameObjectManager* GObjectManager;