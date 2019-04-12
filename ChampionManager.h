#pragma once
#include "GameObject.h"
#include "Engine.h"
#include <vector>
#pragma once

static std::vector<GameObject*> gChampions;
static std::vector<GameObject*> gAttackableChampions;
static std::vector<GameObject*> gEnemyChampions;
static std::vector<GameObject*> gFriendlyChampions;

static std::vector<GameObject*> GetChampions() { return gChampions; }
static std::vector<GameObject*> GetAttackableChampions() { return gAttackableChampions; }
static std::vector<GameObject*> GetEnemyChampions() { return gEnemyChampions; }
static std::vector<GameObject*> GetFriendlyChampions() { return gFriendlyChampions; }

void SetChampions() {
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
}

void SetEnemyChampions() {
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
}

void SetAttackableChampions() {
	gEnemyChampions.clear();
	if(ObjManager) {
		for(int i = 0; i < TRYFOROBJMAX; i++) {
			GameObject* obj = Engine::GetObjectByID(i);
			if(obj && obj->IsHero() && obj->IsAttackable()) {
				gEnemyChampions.push_back(obj);
			}
		}
	}
	gEnemyChampions.shrink_to_fit();
}

void SetFriendlyChampions() {
	gFriendlyChampions.clear();
	if(ObjManager) {
		for(int i = 0; i < TRYFOROBJMAX; i++) {
			GameObject* obj = Engine::GetObjectByID(i);
			if(obj && obj->IsHero() && !obj->IsEnemy()) {
				gFriendlyChampions.push_back(obj);
			}
		}
	}
	gFriendlyChampions.shrink_to_fit();
}

static void PopulateChampionVectors() {
	SetChampions();
	SetAttackableChampions();
	SetEnemyChampions();
	SetFriendlyChampions();
}