#pragma once
#include "Console.h"
#include "Engine.h"

//static CObject EnemyMinions[];

static CObject* GetEnemyMinions()
{
	if (ObjManager)
	{
		for (int i = 0; i < ObjManager->HighestObjectID; i++)
		{
			CObject* obj = Engine::GetObjectByID(i);
			if (obj
				&& obj->IsMinion()
				&& obj->IsEnemyTo(ME)
				&& obj->IsAlive()
				&& obj->IsTargetable()
				&& obj->IsVisible()) {
				auto color = createRGB(255, 233, 0);
				Functions.DrawCircle(&obj->GetPos(), ME->GetAttackRange() + ME->GetBoundingRadius(), &color, 0, 0.0f, 0, 0.5f);
			}
		}
	}
	return NULL;
}

static CObject* GetLastHitMinion()
{
	if (ObjManager)
	{
		for (int i = 0; i < ObjManager->HighestObjectID; i++)
		{
			CObject* obj = Engine::GetObjectByID(i);
			if (obj
				&& obj->IsMinion()
				&& obj->IsEnemyTo(ME)
				&& obj->IsAlive()
				&& obj->IsTargetable()
				&& obj->IsVisible()
				&& obj->GetHealth() <= ME->GetTotalAttackDamage() + obj->GetTotalAttackDamage()) { // Last hit if we have enough ad with a buffer of one minion AA.
				auto color = createRGB(255, 233, 0);
				Functions.DrawCircle(&obj->GetPos(), ME->GetAttackRange() + ME->GetBoundingRadius(), &color, 0, 0.0f, 0, 0.5f);
			}
		}
	}
	return NULL;
}