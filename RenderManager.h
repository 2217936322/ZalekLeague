#include "Utils.h"
#include "Engine.h"
#pragma once
void RenderManager() {
	if(draw_attack_range) {
		auto color = createRGB(0, 128, 0);
		Functions.DrawCircle(&ME->GetPos(), ME->GetAttackRange() + ME->GetBoundingRadius(), &color, 0, 0.0f, 0, 0.5f);
	}
}