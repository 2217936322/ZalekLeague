#include "Spells.h"
#include "Engine.h"

bool SpellSlot::IsReady() {
	return this->GetCooldown() <= 0.0f && this->GetLevel() > 0;
}

bool SpellSlot::HasCharges() {
	return this->GetNextCharge() != -1;
}

char* SpellSlot::GetActorName() {
	return GetStr(this->GetSpellInfoAddress() + 0x18);
}


int SpellSlot::GetCharge() {
	return *(int*) ((DWORD) this + 0x50);
}

int SpellSlot::GetNextCharge() {
	return *(int*) ((DWORD) this + 0x58);
}

int SpellSlot::GetSpellInfoAddress() {
	return *(int*) ((DWORD) this + 0x12C);
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

SpellSlot* SpellBook::Get(int slot) { // 508?
	return *(SpellSlot * *) ((DWORD) this + 0x50C + (0x4 * slot));
}

SpellSlot* SpellBook::GetQ() {
	return *(SpellSlot * *) ((DWORD) this + 0x50C + (0x4 * (int) ESpellSlot::Q));
}

SpellSlot* SpellBook::GetW() {
	return *(SpellSlot * *) ((DWORD) this + 0x50C + (0x4 * (int) ESpellSlot::W));
}

SpellSlot* SpellBook::GetE() {
	return *(SpellSlot * *) ((DWORD) this + 0x50C + (0x4 * (int) ESpellSlot::E));
}

SpellSlot* SpellBook::GetR() {
	return *(SpellSlot * *) ((DWORD) this + 0x50C + (0x4 * (int) ESpellSlot::R));
}

SpellSlot* SpellBook::GetD() {
	return *(SpellSlot * *) ((DWORD) this + 0x50C + (0x4 * (int) ESpellSlot::D));
}

SpellSlot* SpellBook::GetF() {
	return *(SpellSlot * *) ((DWORD) this + 0x50C + (0x4 * (int) ESpellSlot::F));
}