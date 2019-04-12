#include <random>
#include <vector>
#include "MinionManager.h"
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
	float min = 0.15f;
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
		gLastAttackTime = Engine::GetGameTime() - gAttackTime;
		srand(rand() * (rand() * 23)); // 4th prime from 5th prime (9th prime)
		float random = ((float) rand()) / (float) RAND_MAX;
		float min = 0.05f;
		float max = 0.1f;
		float difference = max - min;
		float result = random * difference;
		gAttackThreshold = Functions.GetAttackCastDelay(ME) + min + result;
		if(!GetLastHitMinions().empty() && gLastAttackTime > gAttackThreshold) {
			Functions.IssueOrder(ME, 3, &(*GetLastHitMinions().begin())->GetPos(), (*GetLastHitMinions().begin()), false, true, false);
			gAttackTime = Engine::GetGameTime();
			return;
		}

		srand(rand() * (rand() * 37)); // 3rd prime from 4th prime from 5th prime (12th prime)
		random = ((float) rand()) / (float) RAND_MAX;
		min = 1.25f;
		max = 1.5f;
		difference = max - min;
		result = random * difference;
		// FIXME: Use Detect AA Projectile then allow move instead of using 0.5f
		if(GetLastHitMinions().empty() || gLastAttackTime > (Functions.GetAttackCastDelay(ME) * min + result)) {
			MovementManager();
			return;
		}
	}
}