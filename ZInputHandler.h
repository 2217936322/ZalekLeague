#include <Windows.h>
#include "Utils.h"
#include "Engine.h"
#include "Minions.h"
#pragma once


void handleInput() {
	if (GetKeyState(VK_SPACE) & 0x8000)
	{
		auto color = createRGB(0, 128, 0);
		Functions.DrawCircle(&ME->GetPos(), ME->GetAttackRange() + ME->GetBoundingRadius(), &color, 0, 0.0f, 0, 0.5f);
		Engine::MoveTo(&Engine::GetMouseWorldPosition());

	}

	if (GetKeyState(0x5A) & 0x8000) // Z Key
		GetEnemyMinions();

	//if (GetKeyState(0x58) & 0x8000) // X Key
	//	Engine::LastHit(GetLastHitMinion());

	if (GetKeyState(VK_INSERT) & 0x8000)
		Functions.PrintChat(*(DWORD*)(baseAddr + oChatClient), "<font color='#FF0000'>[Riot Games]:</font><font color='#00CED1'> Austin is a faggot.</font>", 1);
}