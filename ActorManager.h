#include "Actor.h"
#pragma once

class LActorManager
{
public:
	union
	{
		DEFINE_MEMBER_0(void* Base, 0x0);
		DEFINE_MEMBER_N(LActor** Objects, 0x4);
		DEFINE_MEMBER_N(int MaxSize, 0x8);
		DEFINE_MEMBER_N(int Size, 0xC);
		DEFINE_MEMBER_N(int HighestIndex, 0x10);
	};
};

extern LActorManager* ActorManager;