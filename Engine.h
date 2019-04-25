#pragma once
#include "Utils.h"
#include "Vector.h"
#include "LFunctions.h"
#include "Actor.h"

#define ME Engine::GetLocalObject()

constexpr auto HOLDPOSITION = 1;
constexpr auto MOVE = 2;
constexpr auto ATTACK_UNIT = 3;
constexpr auto ATTACK_PET = 4;
constexpr auto AUTO_ATTACK = 5;
constexpr auto MOVE_PET = 6;
constexpr auto ATTACK_TOWER = 7;
constexpr auto STOP = 10;

class Engine
{
public:
	static Vector GetMouseWorldPosition() {
		DWORD MousePtr = (DWORD) GetModuleHandle(NULL) + DWORD_HUD_INSTANCE;
		auto aux1 = *(DWORD*) MousePtr;
		aux1 += 0x14;
		auto aux2 = *(DWORD*) aux1;
		aux2 += 0x1C;

		float X = *(float*) (aux2 + 0x0);
		float Y = *(float*) (aux2 + 0x4);
		float Z = *(float*) (aux2 + 0x8);

		return Vector{X, Y, Z};
	}

	static float GetGameTime() {
		return *(float*) (baseAddr + DWORD_GAME_TIME);
	}

	static LActor* GetLocalObject() {
		auto retaddr = *(DWORD*) (baseAddr + DWORD_LOCAL_PLAYER);
		if(retaddr == NULL)
			return NULL;

		return (LActor*) retaddr;
	}

	//static GameObject * GetObjectByID(int ID) {
	//	if(GObjectManager != NULL && ID >= 0 && ID <= 10000) {
	//		return GObjectManager->objectArray[ID];
	//	}
	//	return NULL;
	//}

	static void Attack(LActor * obj) {
		Functions.IssueOrder(ME, 3, &obj->GetPos(), obj, true, false, false);
	}

	static void MoveTo(Vector * pos) {
		Functions.IssueOrder(ME, 2, pos, NULL, false, false, false);
	}

	static void LastHit(LActor * obj) {
		Functions.IssueOrder(ME, 3, &obj->GetPos(), obj, true, true, false);
	}
};