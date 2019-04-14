#include <vector>
#include "GameObject.h"
#include "Engine.h"
#pragma once

std::vector<GameObject*> GetMinions() {
	std::vector<GameObject*> Minions;
	if(GObjectManager) {
		for(int i = 0; i < 10000; i++) {
			GameObject* obj = Engine::GetObjectByID(i);
			if(obj
				&& obj->IsMinion()
				&& obj->IsAlive()) {
				Minions.push_back(obj);
			}
		}
	}
	return Minions;
}


extern GameObjectManager* MinionManager;