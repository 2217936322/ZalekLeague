#pragma once
#pragma once
#include "GameObject.h"
#include "Engine.h"
#include <vector>
#pragma once

std::vector<GameObject*> GetMissiles() {
	std::vector<GameObject*> Missiles;
	if(ObjManager) {
		for(int i = 0; i < TRYFOROBJMAX; i++) {
			GameObject* obj = Engine::GetObjectByID(i);
			if(obj && obj->IsMissile() && obj->GetDistToMe() < 2500.0f) {
				Missiles.push_back(obj);
			}
		}
	}
	return Missiles;
}

std::vector<GameObject*> GetEnemyMissiles() {
	std::vector<GameObject*> EMissiles;
	if(ObjManager) {
		for(int i = 0; i < TRYFOROBJMAX; i++) {
			GameObject* obj = Engine::GetObjectByID(i);
			if(obj && obj->IsMissile() && obj->GetDistToMe() < 2500.0f && obj->IsEnemy()) {
				auto color = createRGB(255, 0, 0);
				Functions.DrawCircle(&obj->GetPos(), 50.0f, &color, 0, 0.0f, 0, 1.0f);
				EMissiles.push_back(obj);
			}
		}
	}
	return EMissiles;
}
std::vector<GameObject*> GetFriendlyMissles() {
	std::vector<GameObject*> EMissiles;
	if(ObjManager) {
		for(int i = 0; i < TRYFOROBJMAX; i++) {
			GameObject* obj = Engine::GetObjectByID(i);
			if(obj && obj->IsMissile() && obj->GetDistToMe() < 2500.0f && !obj->IsEnemy()) {
				auto color = createRGB(0, 255, 0);
				Functions.DrawCircle(&obj->GetPos(), 50.0f, &color, 0, 0.0f, 0, 1.0f);
				EMissiles.push_back(obj);
			}
		}
	}
	return EMissiles;
}
//
//std::vector<GameObject*> GetEnemyMisslesTowardsPos(Vector pos, float hitbox_radius) {
//	std::vector<GameObject*> EMissiles;
//	if(ObjManager) {
//		for(int i = 0; i < TRYFOROBJMAX; i++) {
//			GameObject* obj = Engine::GetObjectByID(i);
//			if(obj && obj->IsMissile() && obj->GetDistToMe() < 1500.0f && obj->IsEnemy()) {
//				if(obj->GetEndPos().DistTo(pos) <= hitbox_radius)
//					EMissiles.push_back(obj);
//			}
//		}
//	}
//	return EMissiles;
//}