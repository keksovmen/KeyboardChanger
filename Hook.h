#pragma once
#include <Windows.h>

//Actual hook
LRESULT CALLBACK KeybordHook(
		int nCode, WPARAM wParam, LPARAM lParam
	);