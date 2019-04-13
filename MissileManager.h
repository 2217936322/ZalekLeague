#pragma once
#pragma once
#include "GameObject.h"
#include "Engine.h"
#include <vector>
#pragma once

std::vector<GameObject*> GetMissiles() {
	std::vector<GameObject*> Missiles;
	if(ObjManager) {
		for(int i = 0; i < TRYFOROBJMAX; i++) {
			GameObject* obj = Engine::GetObjectByID(i);
			if(obj && obj->IsMissile() && obj->GetDistToMe() < 2500.0f) {
				Missiles.push_back(obj);
			}
		}
	}
	return Missiles;
}

std::vector<GameObject*> GetEnemyMissiles() {
	std::vector<GameObject*> EMissiles;
	if(ObjManager) {
		for(int i = 0; i < TRYFOROBJMAX; i++) {
			GameObject* obj = Engine::GetObjectByID(i);
			if(obj
				&& obj->IsMissile()
				&& obj->GetDistToMe() < 2500.0f
				&& obj->IsEnemy()
				//&& !endsWith("Attack", (std::string)(obj->GetName()))
				//&& !endsWith("Attack2", (std::string)(obj->GetName()))
				) {
				auto color = createRGB(255, 64, 128);
				Functions.DrawCircle(&obj->GetPos(), 25.0f, &color, 0, 0.0f, 0, 255.0f);
				Functions.DrawCircle(&obj->GetPos(), 25.5f, &color, 0, 0.0f, 0, 255.0f);
				Functions.DrawCircle(&obj->GetPos(), 26.0f, &color, 0, 0.0f, 0, 255.0f);
				Functions.DrawCircle(&obj->GetPos(), 26.5f, &color, 0, 0.0f, 0, 255.0f);
				Functions.DrawCircle(&obj->GetPos(), 27.0f, &color, 0, 0.0f, 0, 255.0f);
				Functions.DrawCircle(&obj->GetPos(), 27.5f, &color, 0, 0.0f, 0, 255.0f);
				Functions.DrawCircle(&obj->GetPos(), 28.0f, &color, 0, 0.0f, 0, 255.0f);
				Functions.DrawCircle(&obj->GetPos(), 28.5f, &color, 0, 0.0f, 0, 255.0f);
				Functions.DrawCircle(&obj->GetPos(), 29.0f, &color, 0, 0.0f, 0, 255.0f);
				Functions.DrawCircle(&obj->GetPos(), 29.5f, &color, 0, 0.0f, 0, 255.0f);
				Functions.DrawCircle(&obj->GetPos(), 30.0f, &color, 0, 0.0f, 0, 255.0f);
				Functions.DrawCircle(&obj->GetPos(), 30.5f, &color, 0, 0.0f, 0, 255.0f);

				color = createRGB(255, 0, 0);
				Functions.DrawCircle(&obj->GetEndPos(), 45.0f, &color, 0, 0.0f, 0, 255.0f);
				Functions.DrawCircle(&obj->GetEndPos(), 45.5f, &color, 0, 0.0f, 0, 255.0f);
				Functions.DrawCircle(&obj->GetEndPos(), 46.0f, &color, 0, 0.0f, 0, 255.0f);
				Functions.DrawCircle(&obj->GetEndPos(), 46.5f, &color, 0, 0.0f, 0, 255.0f);
				Functions.DrawCircle(&obj->GetEndPos(), 47.0f, &color, 0, 0.0f, 0, 255.0f);
				Functions.DrawCircle(&obj->GetEndPos(), 47.5f, &color, 0, 0.0f, 0, 255.0f);
				Functions.DrawCircle(&obj->GetEndPos(), 48.0f, &color, 0, 0.0f, 0, 255.0f);
				Functions.DrawCircle(&obj->GetEndPos(), 48.5f, &color, 0, 0.0f, 0, 255.0f);
				Functions.DrawCircle(&obj->GetEndPos(), 49.0f, &color, 0, 0.0f, 0, 255.0f);
				Functions.DrawCircle(&obj->GetEndPos(), 49.5f, &color, 0, 0.0f, 0, 255.0f);
				Functions.DrawCircle(&obj->GetEndPos(), 50.0f, &color, 0, 0.0f, 0, 255.0f);
				Functions.DrawCircle(&obj->GetEndPos(), 50.5f, &color, 0, 0.0f, 0, 255.0f);
				EMissiles.push_back(obj);
			}
		}
	}
	return EMissiles;
}
std::vector<GameObject*> GetFriendlyMissiles() {
	std::vector<GameObject*> EMissiles;
	if(ObjManager) {
		for(int i = 0; i < TRYFOROBJMAX; i++) {
			GameObject* obj = Engine::GetObjectByID(i);
			if(obj
				&& obj->IsMissile()
				&& obj->GetDistToMe() < 2500.0f
				&& !obj->IsEnemy()
				//&& !endsWith("Attack", (std::string)(obj->GetName()))
				//&& !endsWith("Attack2", (std::string)(obj->GetName()))
				) {
				auto color = createRGB(1, 1, 1);
				Functions.DrawCircle(&obj->GetPos(), 25.0f, &color, 0, 0.0f, 0, 255.0f);
				Functions.DrawCircle(&obj->GetPos(), 25.5f, &color, 0, 0.0f, 0, 255.0f);
				Functions.DrawCircle(&obj->GetPos(), 26.0f, &color, 0, 0.0f, 0, 255.0f);
				Functions.DrawCircle(&obj->GetPos(), 26.5f, &color, 0, 0.0f, 0, 255.0f);
				Functions.DrawCircle(&obj->GetPos(), 27.0f, &color, 0, 0.0f, 0, 255.0f);
				Functions.DrawCircle(&obj->GetPos(), 27.5f, &color, 0, 0.0f, 0, 255.0f);
				Functions.DrawCircle(&obj->GetPos(), 28.0f, &color, 0, 0.0f, 0, 255.0f);
				Functions.DrawCircle(&obj->GetPos(), 28.5f, &color, 0, 0.0f, 0, 255.0f);
				Functions.DrawCircle(&obj->GetPos(), 29.0f, &color, 0, 0.0f, 0, 255.0f);
				Functions.DrawCircle(&obj->GetPos(), 29.5f, &color, 0, 0.0f, 0, 255.0f);
				Functions.DrawCircle(&obj->GetPos(), 30.0f, &color, 0, 0.0f, 0, 255.0f);
				Functions.DrawCircle(&obj->GetPos(), 30.5f, &color, 0, 0.0f, 0, 255.0f);

				color = createRGB(0, 255, 0);
				Functions.DrawCircle(&obj->GetEndPos(), 45.0f, &color, 0, 0.0f, 0, 255.0f);
				Functions.DrawCircle(&obj->GetEndPos(), 45.5f, &color, 0, 0.0f, 0, 255.0f);
				Functions.DrawCircle(&obj->GetEndPos(), 46.0f, &color, 0, 0.0f, 0, 255.0f);
				Functions.DrawCircle(&obj->GetEndPos(), 46.5f, &color, 0, 0.0f, 0, 255.0f);
				Functions.DrawCircle(&obj->GetEndPos(), 47.0f, &color, 0, 0.0f, 0, 255.0f);
				Functions.DrawCircle(&obj->GetEndPos(), 47.5f, &color, 0, 0.0f, 0, 255.0f);
				Functions.DrawCircle(&obj->GetEndPos(), 48.0f, &color, 0, 0.0f, 0, 255.0f);
				Functions.DrawCircle(&obj->GetEndPos(), 48.5f, &color, 0, 0.0f, 0, 255.0f);
				Functions.DrawCircle(&obj->GetEndPos(), 49.0f, &color, 0, 0.0f, 0, 255.0f);
				Functions.DrawCircle(&obj->GetEndPos(), 49.5f, &color, 0, 0.0f, 0, 255.0f);
				Functions.DrawCircle(&obj->GetEndPos(), 50.0f, &color, 0, 0.0f, 0, 255.0f);
				Functions.DrawCircle(&obj->GetEndPos(), 50.5f, &color, 0, 0.0f, 0, 255.0f);
				//Bresenham 3D
				//float x0 = obj->GetStartPos().X;
				//float y0 = obj->GetStartPos().Y;
				//float z0 = obj->GetStartPos().Z;

				//float x1 = obj->GetEndPos().X;
				//float y1 = obj->GetEndPos().Y;
				//float z1 = obj->GetEndPos().Z;

				//float dx = x1 - x0;
				//float dy = y1 - y0;
				//float dz = z1 - z0;

				//float xk = x0;
				//float yk = y0;
				//float zk = z0;

				//float py0 = 2 * dy - dx;
				//float pz0 = 2 * dz - dx;

				//float pyk = py0;
				//float pzk = pz0;

				//while(xk < x1) {
				//	if(pyk < 0 && pzk < 0) {
				//		Functions.DrawCircle(new Vector(xk + 1, yk, zk), 25.0f, &color, 0, 0.0f, 0, 255.0f);
				//		pyk = (pyk + 1) + (2 * dy);
				//		pzk = (pzk + 1) + (2 * dz);
				//	} else if(pyk > 0 && pzk < 0) {
				//		Functions.DrawCircle(new Vector(xk + 1, yk + 1, zk), 25.0f, &color, 0, 0.0f, 0, 255.0f);
				//		pyk = (pyk + 1) + (2 * dy) - (2 * dx);
				//		pzk = (pzk + 1) + (2 * dz);
				//	} else if(pyk == 0) {
				//		Functions.DrawCircle(new Vector(xk + 1, yk, zk + 1), 25.0f, &color, 0, 0.0f, 0, 255.0f);
				//		pyk = (pyk + 1) + (2 * dy);
				//		pzk = (pzk + 1) + (2 * dz) - (2 * dx);
				//	} else {
				//		Functions.DrawCircle(new Vector(xk + 1, yk + 1, zk + 1), 25.0f, &color, 0, 0.0f, 0, 255.0f);
				//		pyk = (pyk + 1) + (2 * dy) - (2 * dx);
				//		pzk = (pzk + 1) + (2 * dz) - (2 * dx);
				//	}

					//if(p >= 0) {
					//	Functions.DrawCircle(new Vector(x, y, obj->GetStartPos().Z), 25.0f, &color, 0, 0.0f, 0, 255.0f);
					//	y = y + 1;
					//	p = p + 2 * dy - 2 * dx;
					//} else {
					//	Functions.DrawCircle(new Vector(x, y, obj->GetEndPos().Z), 50.0f, &color, 0, 0.0f, 0, 255.0f);
					//	p = p + 2 * dy;
					//}
					//x = x + 1;
				//}
				//Functions.DrawCircle(&obj->GetPos(), 10.0f, &color, 0, 0.0f, 0, 255.0f);
				//Functions.DrawCircle(&obj->GetStartPos(), 5.0f, &color, 0, 0.0f, 0, 255.0f);
				//Functions.DrawCircle(&obj->GetEndPos(), 25.0f, &color, 0, 0.0f, 0, 255.0f);
				//Functions.DrawCircle(&obj->GetEndPos(), 26.0f, &color, 0, 0.0f, 0, 255.0f);
				//Functions.DrawCircle(&obj->GetEndPos(), 27.0f, &color, 0, 0.0f, 0, 255.0f);
				//Functions.DrawCircle(&obj->GetEndPos(), 28.0f, &color, 0, 0.0f, 0, 255.0f);
				//Functions.DrawCircle(&obj->GetEndPos(), 29.0f, &color, 0, 0.0f, 0, 255.0f);
				//Functions.DrawCircle(&obj->GetEndPos(), 30.0f, &color, 0, 0.0f, 0, 255.0f);
				EMissiles.push_back(obj);
			}
		}
	}
	return EMissiles;
}
//
//std::vector<GameObject*> GetEnemyMisslesTowardsPos(Vector pos, float hitbox_radius) {
//	std::vector<GameObject*> EMissiles;
//	if(ObjManager) {
//		for(int i = 0; i < TRYFOROBJMAX; i++) {
//			GameObject* obj = Engine::GetObjectByID(i);
//			if(obj && obj->IsMissile() && obj->GetDistToMe() < 1500.0f && obj->IsEnemy()) {
//				if(obj->GetEndPos().DistTo(pos) <= hitbox_radius)
//					EMissiles.push_back(obj);
//			}
//		}
//	}
//	return EMissiles;
//}