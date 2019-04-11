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
	srand(time(NULL) * ((int64_t) rand() * 29) / ((int64_t) rand() * 7));
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
	// FIXME: Figure out how to get rid of the crash from holding x for too long. Probably need to rework the globals / static funcs.
	gLastAttackTime = Engine::GetGameTime() - gAttackTime;
	if(GetAsyncKeyState(0x58) && 1) { // x key
		gLastAttackTime = Engine::GetGameTime() - gAttackTime;
		srand(time(NULL) * ((int64_t) rand() * 29) / ((int64_t) rand() * 7));
		float random = ((float) rand()) / (float) RAND_MAX;
		float min = 0.05f;
		float max = 0.1f;
		float difference = max - min;
		float result = random * difference;
		gAttackThreshold = Functions.GetAttackCastDelay(ME) + min + result;
		if(!GetLastHitMinions().empty() && gLastAttackTime > gAttackThreshold) {
			Functions.IssueOrder(ME, 3, &(*GetLastHitMinions().begin())->GetPos(), (*GetLastHitMinions().begin()), true, false, false);
			gAttackTime = Engine::GetGameTime();
			return;
		}
	}
}