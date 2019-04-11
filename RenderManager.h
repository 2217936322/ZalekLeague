#include "Utils.h"
#include "Engine.h"
#pragma once

static bool gRenderAttackRange = true;
static bool gRenderLastHit = true;
void RenderManager() {
	if(gRenderAttackRange) {
		auto color = createRGB(0, 128, 0);
		Functions.DrawCircle(&ME->GetPos(), ME->GetAttackRange() + (ME->GetBoundingRadius() * 1.5f), &color, 0, 0.0f, 0, 0.5f);
	}
}