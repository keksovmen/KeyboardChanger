@echo off
call dllCompile.bat
setlocal
REM set your mingw compler path
set COMPILER_PATH="D:\Program Files\mingw-w64\x86_64-8.1.0-posix-seh-rt_v6-rev0\mingw64\bin"
%COMPILER_PATH%\g++ -o KeyboardChanger.exe Main.cpp
endlocal
start KeyboardChanger.exe