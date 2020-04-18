#pragma once
#include <Windows.h>

enum MyErrors {INPUT_LENGTH, NO_SUCH_KEY};

//Error display functions
//
//For windows errors call with GetLastError();
void ShowWindowsError(DWORD);

//Define your own id's for errors
void ShowMyError(DWORD);

//if you want other message
void ShowError(const char[], DWORD);

//to display something for debug
void showMessage(const char*);