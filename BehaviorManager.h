#include <random>
#include <vector>
#include "ChampionManager.h"
#include "MinionManager.h"
#include "MissileManager.h"
#pragma once

static float gAttackThreshold = 0.0f;
static float gAttackTime = 0.0f;
static float gLastAttackTime = 0.0f;
static float gLastMoveTime = 0.0f;
static float gMoveThreshold = 0.0f;
static float gMoveTime = 0.0f;

bool MovementManager() {
	gLastMoveTime = Engine::GetGameTime() - gMoveTime;
	if(!gRenderAttackRange) {
		auto color = createRGB(0, 128, 0);
		Functions.DrawCircle(&ME->GetPos(), ME->GetAttackRange() + ME->GetBoundingRadius(), &color, 0, 0.0f, 0, 0.5f);
	}
	gLastMoveTime = Engine::GetGameTime() - gMoveTime;
	srand(rand() * (rand() * 11)); // 5th prime
	float random = ((float) rand()) / (float) RAND_MAX;
	float min = 0.25f;
	float max = 0.30f;
	float difference = max - min;
	float result = random * difference;
	gMoveThreshold = min + result;
	if(gLastMoveTime > gMoveThreshold) {
		Engine::MoveTo(&Engine::GetMouseWorldPosition());
		gMoveTime = Engine::GetGameTime();
		return true;
	}
	return false;
}

void LastHitManager() {
	// TODO: Last hit with spells.
	gLastAttackTime = Engine::GetGameTime() - gAttackTime;
	if(GetKeyState(0x58) & 0x8000) { // x key
		MovementManager();
		gLastAttackTime = Engine::GetGameTime() - gAttackTime;
		//srand(rand() * (rand() * 23)); // 4th prime from 5th prime (9th prime)
		//float random = ((float) rand()) / (float) RAND_MAX;
		//float min = 0.05f;
		//float max = 0.1f;
		//float difference = max - min;
		//float result = random * difference;
		gAttackThreshold = 1.1f / Functions.GetAttackDelay(ME); //Functions.GetAttackCastDelay(ME) + min + result;
		std::vector<GameObject*> LHMinions = GetLastHitMinions();
		if(!LHMinions.empty() && gLastAttackTime > gAttackThreshold) {
			Functions.IssueOrder(ME, 3, &(*LHMinions.begin())->GetPos(), (*LHMinions.begin()), false, true, false);
			gAttackTime = Engine::GetGameTime();
			return;
		}
	}
}

void OrbWalkManager() {
	if(GetKeyState(VK_SPACE) & 0x8000) {
		gLastAttackTime = Engine::GetGameTime() - gAttackTime;
		gAttackThreshold = 1.1f / Functions.GetAttackDelay(ME); //Functions.GetAttackCastDelay(ME) + min + result;
		std::vector<GameObject*> AChampions = GetAttackableChampions();
		if(!AChampions.empty() && gLastAttackTime > gAttackThreshold) {
			Functions.IssueOrder(ME, 3, &(*AChampions.begin())->GetPos(), (*AChampions.begin()), true, false, false);
			gAttackTime = Engine::GetGameTime();
			return;
		}
	}
}