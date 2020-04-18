#pragma once
#include <Windows.h>

#define DEBUG_FILE_PATH TEXT("D:\\Users\\Roma\\Desktop\\KeyboardHook\\Output.txt")


//0 false, 1 true, -1 error
int isDebugFileOpened();


//Tries to open DEBUG_FILE_PATH, changes isFileOpened
void prepareFile();

//Tries to close DEBUG_FILE_PATH, changes isFileOpened
void closeFile();

//Tries to write key info in to DEBUG_FILE_PATH
void writeKey(DWORD wParam, LPARAM lParam);