#include "Errors.h"

#include <stdio.h>

void ShowWindowsError(DWORD code){
	ShowError("Windows error ü", code);
}

void ShowMyError(DWORD code){
	ShowError("My error ü", code);
}

void ShowError(const char* szMessage, DWORD code){
	char buf[512];
	const int count = snprintf(buf, 512, "%s %d", szMessage, code);
	MessageBox(NULL, buf, "Error", MB_ICONERROR);
}

void showMessage(const char* message){
	MessageBox(NULL, message, "Message", MB_ICONINFORMATION);
}