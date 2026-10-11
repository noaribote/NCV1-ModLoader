@echo off
cd %~dp0
:start
echo color="blue">SC-CL Project
set INPUT=
set /P INPUT=Press ENTER to compile or I to compile and inject %=%
If /I "%INPUT%"=="i" goto inject
cls
"../../bin/SC-CL.exe" -platform=PS3 -target=GTAV -out-dir="GTAV/PS3/bin/" -name="ModLoader" ModLoader.c ../../include/common.c -- -I "../../include/"
goto start
:inject
cls
"../../bin/SC-CL.exe" -platform=PS3 -target=GTAV -out-dir="GTAV/PS3/bin/" -name="ModLoader" ModLoader.c ../../include/common.c -- -I "../../include/"
"../../bin/Script Injector.exe" -in="GTAV/PS3/bin/ModLoader.csc" -i-c=192.168.1.105
goto start