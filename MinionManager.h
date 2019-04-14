#include "GameObject.h"
#include "Engine.h"
#include <vector>
#include "MissileManager.h"
#include "RenderManager.h"
#pragma once

std::vector<GameObject*> GetMinions() {
	std::vector<GameObject*> Minions;
	if(GObjectManager) {
		for(int i = 0; i < 10000; i++) {
			GameObject* obj = Engine::GetObjectByID(i);
			if(obj
				&& obj->IsMinion()
				&& obj->IsAlive()
				&& obj->IsTargetable()
				&& obj->IsVisible()
				&& obj->GetDistToMe() < 2000.0f) {
				Minions.push_back(obj);
			}
		}
	}
	return Minions;
}

std::vector<GameObject*> GetEnemyMinions() {
	std::vector<GameObject*> EMinions;
	if(GObjectManager) {
		for(int i = 0; i < 10000; i++) {
			GameObject* obj = Engine::GetObjectByID(i);
			if(obj
				&& obj->IsMinion()
				&& obj->IsAlive()
				&& obj->IsEnemy()
				&& obj->IsTargetable()
				&& obj->IsVisible()
				&& obj->GetDistToMe() < 2000.0f) {
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
	if(GObjectManager) {
		for(int i = 0; i < 10000; i++) {
			GameObject* obj = Engine::GetObjectByID(i);
			if(obj
				&& obj->IsMinion()
				&& obj->IsAlive()
				&& obj->IsAttackable()
				&& obj->IsEnemy()
				&& obj->IsVisible()
				&& obj->GetHealth() <= (ME->GetTotalAttackDamage() * 1.5)) {
				// TODO: Populate a global vector to monitor current minion dps taken. Use Network ID to ensure it is the same minion.
				if(obj->GetHealth() <= (ME->GetTotalAttackDamage() * 1.066)) {
					auto color = createRGB(255, 233, 0);
					Functions.DrawCircle(&obj->GetPos(), obj->GetBoundingRadius(), &color, 0, 0.0f, 0, 255.0f);
					LHMinions.push_back(obj);
				} else {
					auto color = createRGB(255, 255, 255);
					Functions.DrawCircle(&obj->GetPos(), obj->GetBoundingRadius(), &color, 0, 0.0f, 0, 255.0f);
				}


				/*	int buffer = GetEnemyMisslesTowardsPos(obj->GetPos(), 250.0f).size();
					if(buffer < 1) { buffer = 1; }
					if(obj->GetHealth() <= buffer * obj->GetTotalAttackDamage()) {
						if(gRenderLastHit) {
							auto color = createRGB(255, 233, 0);
							Functions.DrawCircle(&obj->GetPos(), obj->GetBoundingRadius(), &color, 0, 0.0f, 0, 1.0f);
						}
						LHMinions.push_back(obj);
					} else {
						if(gRenderLastHit) {
							auto color = createRGB(255, 255, 255);
							Functions.DrawCircle(&obj->GetPos(), obj->GetBoundingRadius(), &color, 0, 0.0f, 0, 1.0f);
						}
					}*/
			}
		}
	}
	return LHMinions;
}