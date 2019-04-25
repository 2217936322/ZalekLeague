//#include "Offsets.h"
//#include "Vector.h"
//#pragma once
//
//class InputHandler
//{
//public:
//	Vector GetMouseWorld() {
//		DWORD MousePtr = (DWORD) GetModuleHandle(NULL) + DWORD_HUD_INSTANCE;
//		auto aux1 = *(DWORD*) MousePtr;
//		aux1 += 0x14;
//		auto aux2 = *(DWORD*) aux1;
//		aux2 += 0x1C;
//
//		float X = *(float*) (aux2 + 0x0);
//		float Y = *(float*) (aux2 + 0x4);
//		float Z = *(float*) (aux2 + 0x8);
//
//		return Vector{X, Y, Z};
//	}
//};
//
//extern InputHandler * Input;