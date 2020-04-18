#include <Windows.h>
#include <stdio.h>
#include <fileapi.h>
#include "Hook.h"
#include "Error.h"
#include "Util.h"
#include "FileHelper.h"
#include "InputHelper.h"

//Variables
//
//Current translate state 0 false, 1 true
static int isOn = 0;

//Util functions
//
//Changes translate state
static void swapOn();


//Actual hook
LRESULT CALLBACK KeybordHook(
		int nCode, WPARAM wParam, LPARAM lParam
	)
{
	if (nCode < 0)
		return CallNextHookEx(0, nCode, wParam, lParam);
	
	MSG* pMsg = (MSG*)lParam;
	//your messages have scan code = 0
	if(pMsg->message == WM_KEYDOWN && parseScanCode(pMsg->lParam) != 0){
		
		//Must be first 'couse there is some return erly statements
		//Will write inly if file is openned
		writeKey(pMsg->wParam, pMsg->lParam);
		
		//F6 turns keybord mode on or off
		if(pMsg->wParam == VK_F6){
			swapOn();
			return CallNextHookEx(0, nCode, wParam, lParam);
		}
		/*
		F7 tries to open file where 
		will be placed actual key 
		it's virtual and scan codes
		see Output.txt
		*/
		if(pMsg->wParam == VK_F7){
			if(isDebugFileOpened() == 0){
				prepareFile();
			}else if (isDebugFileOpened() == 1){
				closeFile();
			}else{
				//error case
			}
			return CallNextHookEx(0, nCode, wParam, lParam);
		}
		
		if(isDebugFileOpened() == 1){
			
		}
		
		//button clicks go here
		if(isOn){
			if(handleButton(pMsg->wParam)){
				//if such russion key exists
				//will modify actual MSG key to KEY UP
				//system will see 2 events of KEY UP
				//will privent your actual key to being typed
				pMsg->lParam = changeToKeyUp(pMsg->lParam);
				pMsg->message = WM_KEYUP;
			}
		}
	}
	return CallNextHookEx(0, nCode, wParam, lParam);
}


static void swapOn(){
	if(isOn == 0)
		isOn = 1;
	else
		isOn = 0;
}




