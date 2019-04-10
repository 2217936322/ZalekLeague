#include "GameObject.h"
#include "Engine.h"
#include <vector>
#pragma once

std::vector<GameObject*> gMinions;
std::vector<GameObject*> gEnemyMinions;
std::vector<GameObject*> gLastHitMinions;

std::vector<GameObject*> PopulateGlobalMinionsVector() {
	gMinions.clear();
	if(ObjManager) {
		for(int i = 0; i < TRYFOROBJMAX; i++) {
			GameObject* obj = Engine::GetObjectByID(i);
			if(obj
				&& obj->IsMinion()
				&& obj->IsAlive()
				&& obj->IsTargetable()
				&& obj->IsVisible()) {
				gMinions.push_back(obj);
			}
		}
	}
	gMinions.shrink_to_fit();
	return gMinions;
}

std::vector<GameObject*> GetEnemyMinions() {
	gEnemyMinions.clear();
	if(ObjManager) {
		for(int i = 0; i < TRYFOROBJMAX; i++) {
			GameObject* obj = Engine::GetObjectByID(i);
			if(obj
				&& obj->IsMinion()
				&& obj->IsAlive()
				&& obj->IsEnemy()
				&& obj->IsTargetable()
				&& obj->IsVisible()) {
				gEnemyMinions.push_back(obj);
			}
		}
	}
	gEnemyMinions.shrink_to_fit();
	return gEnemyMinions;
}

std::vector<GameObject*> GetLastHitMinions() {
	gLastHitMinions.clear();
	if(ObjManager) {
		for(int i = 0; i < TRYFOROBJMAX; i++) {
			GameObject* obj = Engine::GetObjectByID(i);
			if(obj
				&& obj->IsMinion()
				&& obj->IsAlive()
				&& obj->IsEnemy()
				&& obj->IsTargetable()
				&& obj->IsVisible()
				&& obj->GetPos().DistTo(ME->GetPos()) <= ME->GetAttackRange()
				&& obj->GetHealth() <= ME->GetTotalAttackDamage()) {
				auto color = createRGB(255, 255, 255);
				Functions.DrawCircle(&obj->GetPos(), obj->GetBoundingRadius(), &color, 0, 0.0f, 0, 1.0f);
				gEnemyMinions.push_back(obj);
			}
		}
	}
	gLastHitMinions.shrink_to_fit();
	return gLastHitMinions;
}