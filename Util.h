#pragma once
#include <Windows.h>

//Gives you scan code from LPARAM
int parseScanCode(LPARAM);

//Change state of key to button up
LPARAM changeToKeyUp(LPARAM lParam);