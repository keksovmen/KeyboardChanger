@echo off
setlocal
set SOURCE_FILES=Hook.c InputHelper.c Errors.c FileHelper.c Util.c
gcc -shared -o Hook.dll %SOURCE_FILES%
endlocal
