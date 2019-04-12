#include "GameObject.h"
#include "Engine.h"
#include <vector>
#include "RenderManager.h"
#pragma once

std::vector<GameObject*> GetMinions() {
	std::vector<GameObject*> Minions;
	if(ObjManager) {
		for(int i = 0; i < TRYFOROBJMAX; i++) {
			GameObject* obj = Engine::GetObjectByID(i);
			if(obj
				&& obj->IsMinion()
				&& obj->IsAlive()
				&& obj->IsTargetable()
				&& obj->IsVisible()) {
				Minions.push_back(obj);
			}
		}
	}
	return Minions;
}

std::vector<GameObject*> GetEnemyMinions() {
	std::vector<GameObject*> EMinions;
	if(ObjManager) {
		for(int i = 0; i < TRYFOROBJMAX; i++) {
			GameObject* obj = Engine::GetObjectByID(i);
			if(obj
				&& obj->IsMinion()
				&& obj->IsAlive()
				&& obj->IsEnemy()
				&& obj->IsTargetable()
				&& obj->IsVisible()) {
				EMinions.push_back(obj);
			}
		}
	}
	return EMinions;
}

std::vector<GameObject*> GetLastHitMinions() {
	// TODO: Calculate Incoming Minion Damage
	// TODO: Order Minions by Gold earned. (Cannon > Melee > Ranged);
	std::vector<GameObject*> LHMinions;
	if(ObjManager) {
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
				LHMinions.push_back(obj);
			}
		}
	}
	return LHMinions;
}