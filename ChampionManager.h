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

std::vector<GameObject*> GetEnemyChampions() {
	std::vector<GameObject*> EChampions;
	if(ObjManager) {
		for(int i = 0; i < TRYFOROBJMAX; i++) {
			GameObject* obj = Engine::GetObjectByID(i);
			if(obj && obj->IsHero() && obj->IsEnemy()) {
				EChampions.push_back(obj);
			}
		}
	}
	return EChampions;
}

std::vector<GameObject*> GetAttackableChampions() {
	std::vector<GameObject*> AChampions;
	if(ObjManager) {
		for(int i = 0; i < TRYFOROBJMAX; i++) {
			GameObject* obj = Engine::GetObjectByID(i);
			if(obj && obj->IsHero() && obj->IsAttackable()) {
				AChampions.push_back(obj);
			}
		}
	}
	return AChampions;
}

std::vector<GameObject*> GetFriendlyChampions() {
	std::vector<GameObject*> FChampions;
	if(ObjManager) {
		for(int i = 0; i < TRYFOROBJMAX; i++) {
			GameObject* obj = Engine::GetObjectByID(i);
			if(obj && obj->IsHero() && !obj->IsEnemy()) {
				FChampions.push_back(obj);
			}
		}
	}
	return FChampions;
}