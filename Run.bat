@echo off
call dllCompile.bat
g++ -o KeyboardChanger.exe Main.cpp
start KeyboardChanger.exe