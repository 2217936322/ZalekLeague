#include "Spells.h"
#include "Engine.h"

bool SpellSlot::IsReady() {
	return this->GetCooldown() <= 0.0f && this->GetLevel() > 0;
}

int SpellSlot::GetLevel() {
	return *(int*) ((DWORD) this + 0x20);
}

float SpellSlot::GetCooldown() {
	float cd = *(float*) ((DWORD) this + 0x28) - Engine::GetGameTime();
	if(cd <= 0.0f)
		cd = 0.0f;
	return cd;
}

float SpellSlot::GetTimeUsed() {
	return *(float*) ((DWORD) this + 0x28);
}

SpellSlot* SpellBook::GetQ() {
	return *(SpellSlot * *) ((DWORD) this + 0x508 + (0x4 * (int) ESpellSlot::Q));
}

SpellSlot* SpellBook::GetW() {
	return *(SpellSlot * *) ((DWORD) this + 0x508 + (0x4 * (int) ESpellSlot::W));
}

SpellSlot* SpellBook::GetE() {
	return *(SpellSlot * *) ((DWORD) this + 0x508 + (0x4 * (int) ESpellSlot::E));
}

SpellSlot* SpellBook::GetR() {
	return *(SpellSlot * *) ((DWORD) this + 0x508 + (0x4 * (int) ESpellSlot::R));
}