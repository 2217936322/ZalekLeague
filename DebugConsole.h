#pragma once
#include <Windows.h>

class DebugConsole
{
public:
	void Init(char* title, int width, int height, char* fname);
	int Print(char* fmt, ...);
};