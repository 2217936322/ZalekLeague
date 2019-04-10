#include "GameObject.h"
#include "Engine.h"
#include <vector>
#pragma once

std::vector<GameObject*> gMinions;

std::vector<GameObject*> PopulateGlobalMinionsVector() {
	gMinions.clear();
	if(ObjManager) {
		for(int i = 0; i < TRYFOROBJMAX; i++) {
			GameObject* obj = Engine::GetObjectByID(i);
			if(obj
				&& obj->IsMinion()
				//&& obj->IsEnemyTo(ME)
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