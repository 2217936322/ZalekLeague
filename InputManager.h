#include <Windows.h>
#include "Utils.h"
#include "Engine.h"
#include "Menu.h"
#pragma once

auto gColor = createRGB(0, 128, 0);

void moveToMouse() {
	gLastMoveTime = Engine::GetGameTime() - gMoveTime;
	if(gLastMoveTime > 0.21f) {
		Engine::MoveTo(&Engine::GetMouseWorldPosition());
		gMoveTime = Engine::GetGameTime();
	}
}

//void attackHero() {
//	gLastAttackTime = Engine::GetGameTime() - gAttackTime;
//	if(gLastAttackTime > 1.0f) {
//		Engine::Attack(&Engine::GetMouseWorldPosition());
//		gMoveTime = Engine::GetGameTime();
//	}
//}


void handleInput() {
	if(GetKeyState(VK_SPACE) & 0x8000) {
		if(!draw_attack_range) {
			auto color = createRGB(0, 128, 0);
			Functions.DrawCircle(&ME->GetPos(), ME->GetAttackRange() + ME->GetBoundingRadius(), &color, 0, 0.0f, 0, 0.5f);
		}
		moveToMouse();
	}

	if(GetAsyncKeyState(VK_INSERT) & 1) {
		draw_menu = !draw_menu;
		//Functions.PrintChat(*(DWORD*) (baseAddr + oChatClient), "<font color='#FF0000'>[Riot Games]:</font><font color='#00CED1'> Austin is a faggot.</font>", 1);
	}
}