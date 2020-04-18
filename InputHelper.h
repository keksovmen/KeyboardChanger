#pragma once
#include <Windows.h>

#define MAX_INPUT_LENGTH 20


//High level function that presses buttons acording to current
int handleButton(WPARAM);

//Gives you virtual code according to english character
int translateToVirtual(char);

//Gives you english char according to virtual key
char translateToChar(WPARAM);

//Increments inputLength
static void incrementCounter();

//Set inputLength to zero
static void resetCounter();

void presShift();

void releaseShift();

void clickButton(char);

void sendInput();