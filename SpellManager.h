#pragma once
#include "GameObject.h"
#include "Engine.h"
#include <vector>
#pragma once

std::vector<GameObject*> GetChampions() {
	std::vector<GameObject*> Champions;
	if(ObjManager) {
		for(int i = 0; i < TRYFOROBJMAX; i++) {
			GameObject* obj = Engine::GetObjectByID(i);
			if(obj && obj->IsHero()) {
				Champions.push_back(obj);
			}
		}
	}
	return Champions;
}