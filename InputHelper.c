#include "InputHelper.h"

#include "Errors.h"


//display amount of pushed inputs
static int inputLength = 0;

//total (MAX_INPUT_LENGTH / 2) button click, be aware to increase if needed
INPUT inputs[MAX_INPUT_LENGTH];

//wParam is virtual code
//return 0 if can't handle, means there is no such letter, 1 if handled
int handleButton(WPARAM wParam){
	const char letter = translateToChar(wParam);
	//mean there is no russian letter for such key
	if(letter == '\0'){
		return 0;
	}
	switch(letter){
		case 'q' : {
			//©
			clickButton('i');
			clickButton('/');
			clickButton('i');
			break;
		}
		case 'w' : {
			//æ
			presShift();
			clickButton('\\');
			clickButton('-');
			clickButton('\\');
			releaseShift();
			clickButton(',');
			break;
		}
		case 'e' : {
			//ã
			clickButton('y');
			break;
		}
		case 'r' : {
			//ª
			clickButton('k');
			break;
		}
		case 't' : {
			//¥
			clickButton('e');
			break;
		}
		case 'y' : {
			//­
			presShift();
			clickButton('h');
			releaseShift();
			break;
		}
		case 'u' : {
			//£
			clickButton('r');
			break;
		}
		case 'i' : {
			//è
			presShift();
			clickButton('\\');
			clickButton('-');
			clickButton('\\');
			clickButton('-');
			clickButton('\\');
			releaseShift();
			break;
		}
		case 'o' : {
			//é
			presShift();
			clickButton('\\');
			clickButton('-');
			clickButton('\\');
			clickButton('-');
			clickButton('\\');
			releaseShift();
			clickButton(',');
			break;
		}
		case 'p' : {
			//§
			clickButton('3');
			break;
		}
		case '[' : {
			//å
			clickButton('x');
			break;
		}
		case ']' : {
			//ê
			clickButton('`');
			clickButton('b');
			break;
		}
		case 'a' : {
			//ä
			presShift();
			clickButton('8');
			clickButton('\\');
			clickButton('8');
			releaseShift();
			break;
		}
		case 's' : {
			//ë
			clickButton('b');
			clickButton('l');
			break;
		}
		case 'd' : {
			//¢
			presShift();
			clickButton('b');
			releaseShift();
			break;
		}
		case 'f' : {
			// 
			clickButton('a');
			break;
		}
		case 'g' : {
			//¯
			presShift();
			clickButton('\\');
			clickButton('\'');
			clickButton('\'');
			clickButton('\\');
			releaseShift();
			break;
		}
		case 'h' : {
			//à
			clickButton('p');
			break;
		}
		case 'j' : {
			//®
			clickButton('o');
			break;
		}
		case 'k' : {
			//«
			clickButton('/');
			clickButton('\\');
			break;
		}
		case 'l' : {
			//¤
			clickButton('/');
			presShift();
			clickButton('-');
			releaseShift();
			clickButton('\\');
			break;
		}
		case ';' : {
			//¦
			presShift();
			clickButton(']');
			releaseShift();
			clickButton('-');
			presShift();
			clickButton('\\');
			releaseShift();
			clickButton('-');
			presShift();
			clickButton('[');
			releaseShift();
			break;
		}
		case '\'' : {
			//í
			clickButton('3');
			break;
		}
		case 'z' : {
			//ï
			clickButton('9');
			presShift();
			clickButton('\\');
			releaseShift();
			break;
		}
		case 'x' : {
			//ç
			clickButton('4');
			break;
		}
		case 'c' : {
			//á
			clickButton('c');
			break;
		}
		case 'v' : {
			//¬
			clickButton('m');
			break;
		}
		case 'b' : {
			//¨
			presShift();
			clickButton('\\');
			releaseShift();
			clickButton('/');
			presShift();
			clickButton('\\');
			releaseShift();
			break;
		}
		case 'n' : {
			//â
			presShift();
			clickButton('t');
			releaseShift();
			break;
		}
		case 'm' : {
			//ì
			clickButton('b');
			break;
		}
		case ',' : {
			//¡
			clickButton('6');
			break;
		}
		case '.' : {
			//î
			presShift();
			clickButton('i');
			releaseShift();
			clickButton('-');
			presShift();
			clickButton('o');
			releaseShift();
			break;
		}
	}
	sendInput();
	return 1;
}

//Translate almost whole keybord to virtual key codes
//if no such will return -1
int translateToVirtual(char c){
	switch(c){
		case 'q':
			return 0x51;
		case 'w':
			return 0x57;
		case 'e':
			return 0x45;
		case 'r':
			return 0x52;
		case 't':
			return 0x54;
		case 'y':
			return 0x59;
		case 'u':
			return 0x55;
		case 'i':
			return 0x49;
		case 'o':
			return 0x4F;
		case 'p':
			return 0x50;
		case '[':
			return 0xDB;
		case ']':
			return 0xDD;
		case 'a':
			return 0x41;
		case 's':
			return 0x53;
		case 'd':
			return 0x44;
		case 'f':
			return 0x46;
		case 'g':
			return 0x47;
		case 'h':
			return 0x48;
		case 'j':
			return 0x4A;
		case 'k':
			return 0x4B;
		case 'l':
			return 0x4C;
		case ';':
			return 0xBA;
		case '\'':
			return 0xDE;
		case '\\':
			return 0xDC;
		case 'z':
			return 0x5A;
		case 'x':
			return 0x58;
		case 'c':
			return 0x43;
		case 'v':
			return 0x56;
		case 'b':
			return 0x42;
		case 'n':
			return 0x4E;
		case 'm':
			return 0x4D;
		case ',':
			return 0xBC;
		case '.':
			return 0xBE;
		case '/':
			return 0xBF;
		case '1':
			return 0x31;
		case '2':
			return 0x32;
		case '3':
			return 0x33;
		case '4':
			return 0x34;
		case '5':
			return 0x35;
		case '6':
			return 0x36;
		case '7':
			return 0x37;
		case '8':
			return 0x38;
		case '9':
			return 0x39;
		case '0':
			return 0x30;
		case '-':
			return 0xBD;
		case '=':
			return 0xBB;
		case '`':
			return 0xC0;
	}
	//as error
	return -1;
}

//Accepts virtual key of english letter that have russion under it
//return terminating 0 if russioan letter dosn't exists
char translateToChar(WPARAM wParam){
	switch(wParam){
		case 0x51 :
			return 'q';
		case 0x57 :
			return 'w';
		case 0x45 :
			return 'e';
		case 0x52 :
			return 'r';
		case 0x54 :
			return 't';
		case 0x59 :
			return 'y';
		case 0x55 :
			return 'u';
		case 0x49 :
			return 'i';
		case 0x4F :
			return 'o';
		case 0x50 :
			return 'p';
		case 0xDB :
			return '[';
		case 0xDD :
			return ']';
		case 0x41 :
			return 'a';
		case 0x53 :
			return 's';
		case 0x44 :
			return 'd';
		case 0x46 :
			return 'f';
		case 0x47 :
			return 'g';
		case 0x48 :
			return 'h';
		case 0x4A :
			return 'j';
		case 0x4B :
			return 'k';
		case 0x4C :
			return 'l';
		case 0xBA :
			return ';';
		case 0xDE :
			return '\'';
		case 0x5A :
			return 'z';
		case 0x58 :
			return 'x';
		case 0x43 :
			return 'c';
		case 0x56 :
			return 'v';
		case 0x42 :
			return 'b';
		case 0x4E :
			return 'n';
		case 0x4D :
			return 'm';
		case 0xBC :
			return ',';
		case 0xBE :
			return '.';
	}
	return '\0';
}

//will show error box if length is too big
static void incrementCounter(){
	inputLength++;
	if(inputLength >= MAX_INPUT_LENGTH){
		inputLength = 0;
		ShowMyError(INPUT_LENGTH);
	}
		
}

static void resetCounter(){
	inputLength = 0;
}


void presShift(){
	inputs[inputLength].type = INPUT_KEYBOARD;
	inputs[inputLength].ki.wVk = 0x10;
	inputs[inputLength].ki.wScan = 0;
	inputs[inputLength].ki.dwFlags = 0;
	inputs[inputLength].ki.time = 0;
	inputs[inputLength].ki.dwExtraInfo = GetMessageExtraInfo();
	
	incrementCounter();
}

void releaseShift(){
	inputs[inputLength].type = INPUT_KEYBOARD;
	inputs[inputLength].ki.wVk = 0x10;
	inputs[inputLength].ki.wScan = 0;
	inputs[inputLength].ki.dwFlags = KEYEVENTF_KEYUP;
	inputs[inputLength].ki.time = 0;
	inputs[inputLength].ki.dwExtraInfo = GetMessageExtraInfo();
	
	incrementCounter();
}

//will show error if can't find virtual code for button
void clickButton(char c){
	int vkCode = translateToVirtual(c);
	if(vkCode == -1){
		ShowMyError(NO_SUCH_KEY);
		return;
	}
	inputs[inputLength].type = INPUT_KEYBOARD;
	inputs[inputLength].ki.wVk = vkCode;
	inputs[inputLength].ki.wScan = 0x0;
	inputs[inputLength].ki.dwFlags = 0;
	inputs[inputLength].ki.time = 0;
	inputs[inputLength].ki.dwExtraInfo = GetMessageExtraInfo();
	
	incrementCounter();
	
	inputs[inputLength].type = INPUT_KEYBOARD;
	inputs[inputLength].ki.wVk = vkCode;
	inputs[inputLength].ki.wScan = 0x0;
	inputs[inputLength].ki.dwFlags = KEYEVENTF_KEYUP;
	inputs[inputLength].ki.time = 0;
	inputs[inputLength].ki.dwExtraInfo = GetMessageExtraInfo();
	
	incrementCounter();
}

void sendInput(){
	if(inputLength == 0)
		return;
	const int realAmount = SendInput(inputLength, inputs, sizeof(inputs[0]));
	if(realAmount == 0)
		ShowWindowsError(GetLastError());
	resetCounter();
}