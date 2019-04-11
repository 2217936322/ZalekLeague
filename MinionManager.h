#include "GameObject.h"
#include "Engine.h"
#include <vector>
#pragma once

static std::vector<GameObject*> gMinions;
static std::vector<GameObject*> gEnemyMinions;
static std::vector<GameObject*> gLastHitMinions;
static std::vector<GameObject*> GetMinions() { return gMinions; }
static std::vector<GameObject*> GetEnemyMinions() { return gEnemyMinions; }
static std::vector<GameObject*> GetLastHitMinions() { return gLastHitMinions; }

static std::vector<GameObject*> SetMinions() {
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
}

static std::vector<GameObject*> SetEnemyMinions() {
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

static std::vector<GameObject*> SetLastHitMinions() {
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
				&& obj->GetHealth() <= ME->GetTotalAttackDamage()) {
				auto color = createRGB(255, 255, 255);
				Functions.DrawCircle(&obj->GetPos(), obj->GetBoundingRadius(), &color, 0, 0.0f, 0, 1.0f);
				gEnemyMinions.push_back(obj);
			}
		}
	}
	gLastHitMinions.shrink_to_fit();
}


static void PopulateMinionVectors() {
	SetMinions();
	SetEnemyMinions();
	SetLastHitMinions();
}