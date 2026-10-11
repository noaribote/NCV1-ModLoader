@echo off
cd %~dp0
:start
echo SC-CL ModLoader.c
echo Press ENTER to launch
pause > nul
cls
"../../bin/SC-CL.exe" -emit-asm -platform=PS3 -target=GTAV -out-dir="GTAV/PS3/bin/" ModLoader.c ../../include/common.c -- -I "../../include/"
goto start
