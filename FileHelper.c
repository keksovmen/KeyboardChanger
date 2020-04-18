#include "FileHelper.h"

#include <fileapi.h>
#include <stdio.h>
#include "Errors.h"
#include "Util.h"

//for storing keyboard scans
static HANDLE hFile;
static int isFileOpened = 0;


int isDebugFileOpened(){
	return isFileOpened;
}

//File must be created already
void prepareFile(){
	if(isFileOpened == 1 || isFileOpened == -1)
		return;
	
	hFile = CreateFile(
		DEBUG_FILE_PATH,
		GENERIC_WRITE,
		0,
		NULL,
		OPEN_EXISTING,
		FILE_ATTRIBUTE_NORMAL,
		NULL
	);
	if(hFile != INVALID_HANDLE_VALUE){
		isFileOpened = 1;
	}else{
		isFileOpened = -1;
		ShowWindowsError(GetLastError());
	}
}

void closeFile(){
	CloseHandle(hFile);
	isFileOpened = 0;
}

//write at begining of the file
void writeKey(DWORD wParam, LPARAM lParam){
	if(isFileOpened == 0 || isFileOpened == -1)
		return;
	
	char buf[256];
	char secondBuf[256];
	//there should be some error handling
	GetKeyNameText(lParam, secondBuf, 256);
	const int count = snprintf(buf, 256, "KEY - %s\tVK - %X\tSCAN - %X\n", 
		secondBuf,
		wParam, 
		parseScanCode(lParam)
	);
	
	DWORD writed = 0;
	int result = WriteFile(
		hFile,
		buf,
		count,
		&writed,
		NULL
	);
	if(result <= 0)
		ShowWindowsError(GetLastError());
	
}