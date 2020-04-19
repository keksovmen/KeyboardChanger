#include <Windows.h>
#include <strsafe.h>
#include <iostream>
#include <stdlib>

HOOKPROC hkprcKeybord;
static HINSTANCE hinstDLL;
static HHOOK hHook;

//Test version of what hook is
LRESULT CALLBACK KeybordHook(
		int code, WPARAM wParam, LPARAM lParam
	)
{
	MessageBox(NULL, "Entered", "key pressed", MB_ICONINFORMATION);
	return CallNextHookEx(hHook, code, wParam, lParam);
}

void SetHook()
{
	hinstDLL = LoadLibrary(TEXT("Hook.dll")); 
	if(hinstDLL == NULL){
		std::cout << "There is no such DLL" << std::endl;
		std::exit(1);
	}
	
	hkprcKeybord = (HOOKPROC)GetProcAddress(hinstDLL, "KeybordHook"); 
	if(hkprcKeybord == NULL){
		std::cout << "There is no such FUNCTION" << std::endl;
		std::exit(2);
	}

	hHook = SetWindowsHookEx(WH_GETMESSAGE, hkprcKeybord, hinstDLL, 0);
	if(hHook == NULL){
		std::cout<< "Error with hook binding!" << std::endl;
		DWORD dError = GetLastError();
		if(dError == ERROR_INVALID_HOOK_FILTER){
			std::cout << 1;
		}
		if(dError == ERROR_INVALID_FILTER_PROC){
			std::cout << 2;
		}
		if(dError == ERROR_HOOK_NEEDS_HMOD){
			std::cout << 3;
		}
		if(dError == ERROR_GLOBAL_ONLY_HOOK){
			std::cout << 4;
		}
		if(dError == ERROR_INVALID_PARAMETER){
			std::cout << 5;
		}
		if(dError == ERROR_JOURNAL_HOOK_SET){
			std::cout << 6;
		}
		if(dError == ERROR_MOD_NOT_FOUND){
			std::cout << 7;
		}
		
	}
}

void Unhook(){
	UnhookWindowsHookEx(hHook);
}

int main()
{
	SetHook();
	int id = 0;
	//wait for your input to termenate program
	std::cin >> id;
	Unhook();
}