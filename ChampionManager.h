#pragma once
#include "GameObject.h"
#include "Engine.h"
#include <vector>
#pragma once

static std::vector<GameObject*> gChampions;
static std::vector<GameObject*> gEnemyChampions;
static std::vector<GameObject*> gFriendlyChampions;

static std::vector<GameObject*> GetChampions() {
	gChampions.clear();
	if(ObjManager) {
		for(int i = 0; i < TRYFOROBJMAX; i++) {
			GameObject* obj = Engine::GetObjectByID(i);
			if(obj && obj->IsHero()) {
				gChampions.push_back(obj);
			}
		}
	}
	gChampions.shrink_to_fit();
	return gChampions;
}

static std::vector<GameObject*> GetEnemyChampions() {
	gEnemyChampions.clear();
	if(ObjManager) {
		for(int i = 0; i < TRYFOROBJMAX; i++) {
			GameObject* obj = Engine::GetObjectByID(i);
			if(obj && obj->IsHero() && obj->IsEnemy()) {
				gEnemyChampions.push_back(obj);
			}
		}
	}
	gEnemyChampions.shrink_to_fit();
	return gEnemyChampions;
}

static std::vector<GameObject*> GetFriendlyChampions() {
	gFriendlyChampions.clear();
	if(ObjManager) {
		for(int i = 0; i < TRYFOROBJMAX; i++) {
			GameObject* obj = Engine::GetObjectByID(i);
			if(obj && obj->IsHero() && obj->IsEnemy()) {
				gFriendlyChampions.push_back(obj);
			}
		}
	}
	gFriendlyChampions.shrink_to_fit();
	return gFriendlyChampions;
}

static void PopulateChampionVectors() {
	GetChampions();
	GetEnemyChampions();
	GetFriendlyChampions();
}