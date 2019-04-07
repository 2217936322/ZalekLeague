#pragma once
#include "Offsets.h"
#include "Utils.h"
#include "Vector.h"
#include "Hooks.h"
#include "CObjectManager.h"

#define me Engine::GetLocalObject()

class Engine
{
public:
	static Vector GetMouseWorldPosition()
	{
		DWORD MousePtr = (DWORD)GetModuleHandle(NULL) + oHudInstance;
		auto aux1 = *(DWORD*)MousePtr;
		aux1 += 0x14;
		auto aux2 = *(DWORD*)aux1;
		aux2 += 0x1C;

		float X = *(float*)(aux2 + 0x0);
		float Y = *(float*)(aux2 + 0x4);
		float Z = *(float*)(aux2 + 0x8);

		return Vector{ X, Y, Z };
	}

	static char* GetGameVersion()
	{
		return (char*)(baseAddr + oGameVersion);
	}

	static float GetGameTime()
	{
		return *(float*)(baseAddr + oGameTime);
	}

	static CObject* GetLocalObject()
	{
		auto retaddr = *(DWORD*)(baseAddr + oLocalPlayer);
		if (retaddr == NULL)
			return NULL;

		return (CObject*)retaddr;
	}

	static CObject * GetObjectByID(int ID)
	{
		if (ObjManager != NULL && ID >= 0 && ID <= 10000)
		{
			return ObjManager->objectArray[ID];
		}
		return NULL;
	}

	static void Attack(CObject * obj)
	{
		Functions.IssueOrder(me, 3, &obj->GetPos(), obj, true, false, false);
	}

	static void MoveTo(Vector * pos)
	{
		Functions.IssueOrder(GetLocalObject(), 2, pos, NULL, false, false, false);
	}
};