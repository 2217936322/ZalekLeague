#include <vector>
#include "GameObject.h"
#include "Engine.h"
#pragma once

std::vector<GameObject*> GetObjects();
std::vector<GameObject*> GetFriendlyObjects();
std::vector<GameObject*> GetEnemyObjects();

std::vector<GameObject*> GetChampions();
std::vector<GameObject*> GetEnemyChampions();
std::vector<GameObject*> GetFriendlyChampions();

std::vector<GameObject*> GetBaron();
std::vector<GameObject*> GetDragon();

std::vector<GameObject*> GetMinions();
std::vector<GameObject*> GetEnemyMinions();
std::vector<GameObject*> GetFriendlyMinions();

std::vector<GameObject*> GetMonster();

std::vector<GameObject*> GetMissiles();
std::vector<GameObject*> GetEnemyMissiles();
std::vector<GameObject*> GetFriendlyMissiles();

std::vector<GameObject*> GetTroyEnts();
std::vector<GameObject*> GetEnemyTroyEnts();
std::vector<GameObject*> GetFriendlyTroyEnts();