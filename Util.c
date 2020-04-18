#include "Util.h"


int parseScanCode(LPARAM lParam){
	return (lParam >> 16) & 0xFF;
}

//sets the higher bit to 1, mean key is up
LPARAM changeToKeyUp(LPARAM lParam){
	return lParam = lParam | 0x80000000;
}