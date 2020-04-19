@echo off
setlocal
REM source files add as needed
set SOURCE_FILES=Hook.c InputHelper.c Errors.c FileHelper.c Util.c
REM Set path to your mingw compiler
set COMPILER_PATH="D:\Program Files\mingw-w64\x86_64-8.1.0-posix-seh-rt_v6-rev0\mingw64\bin"
%COMPILER_PATH%\gcc -shared -o Hook.dll %SOURCE_FILES%
endlocal
