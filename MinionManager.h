#include "GameObject.h"
#include "Engine.h"
#include <vector>
#include "RenderManager.h"
#pragma once

// Vectors for Minion Data
static std::vector<GameObject*> gMinions;
static std::vector<GameObject*> gEnemyMinions;
static std::vector<GameObject*> gLastHitMinions;

// Getters for Minion Data
static std::vector<GameObject*> GetMinions() { return gMinions; }
static std::vector<GameObject*> GetEnemyMinions() { return gEnemyMinions; }
static std::vector<GameObject*> GetLastHitMinions() { return gLastHitMinions; }

// Setter for static std::vector<GameObject*> gMinions;
void SetMinions() {
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
	return;
}

// Setter for static std::vector<GameObject*> gEnemyMinions;
void SetEnemyMinions() {
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
	return;
}

// Setter for static std::vector<GameObject*> gLastHitMinions;
void SetLastHitMinions() {
	gLastHitMinions.clear();
	if(ObjManager) {
		//FIXME: Push cannons>melee>ranged to end and change last hit logic to last hit last vector element.
		for(int i = 0; i < TRYFOROBJMAX; i++) {
			GameObject* obj = Engine::GetObjectByID(i);
			if(obj
				&& obj->IsMinion()
				&& obj->IsAlive()
				&& obj->IsAttackable()
				&& obj->IsEnemy()
				&& obj->IsVisible()
				&& obj->GetHealth() <= ME->GetTotalAttackDamage() + 5.0f) {
				if(gRenderLastHit) {
					auto color = createRGB(255, 255, 255);
					Functions.DrawCircle(&obj->GetPos(), obj->GetBoundingRadius(), &color, 0, 0.0f, 0, 1.0f);
				}
				gLastHitMinions.push_back(obj);
			}
		}
	}
	gLastHitMinions.shrink_to_fit();
	return;
}

// Call all minion setters.
void SetMinionData() {
	SetMinions();
	SetEnemyMinions();
	SetLastHitMinions();
	return;
}