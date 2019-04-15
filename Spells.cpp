#include "Spells.h"
#include "Engine.h"

bool SpellSlot::IsReady() {
	return this->GetCooldown() <= 0.0f;
}

int SpellSlot::GetLevel() {
	return *(int*) ((DWORD) this + 0x20);
}

float SpellSlot::GetCooldown() {
	return *(float*) ((DWORD) this + 0x28) - Engine::GetGameTime();
}

float SpellSlot::GetTimeUsed() {
	return *(float*) ((DWORD) this + 0x28);
}
